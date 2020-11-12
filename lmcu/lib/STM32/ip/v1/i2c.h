#pragma once
#include <lmcu/dev/i2c>
#include <lmcu/rcc>
#include <lmcu/common>
#include <lmcu/delay>

// ------------------------------------------------------------------------------------------------
namespace lmcu::i2c {
// ------------------------------------------------------------------------------------------------

enum class id { i2c1, i2c2 };

enum class freq : uint32_t { defval = 100_kHz };

enum class dutycycle { _2, _16_9 };

enum class addr_mode { _7bit, _10bit };

enum class addr_1 : uint32_t {};

enum class addr_2 : uint32_t {};

enum class general_call { enable, disable };

enum class no_stretch { enable, disable };

enum class allow_overclock { yes, no };

template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::i2c;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto id = option::get<i2c::id, _args...>();

  static constexpr auto freq = option::get_u<i2c::freq, _args...>(i2c::freq::defval);

  static constexpr auto dutycycle = option::get<i2c::dutycycle, _args...>(i2c::dutycycle::_2);

  static constexpr auto addr_mode = option::get<i2c::addr_mode, _args...>(i2c::addr_mode::_7bit);

  static constexpr auto addr_1 = option::get_u<i2c::addr_1, _args...>();

  static constexpr auto addr_2 = option::get_u<i2c::addr_2, _args...>();

  static constexpr auto general_call = option::get<i2c::general_call, _args...>(i2c::general_call::
                                                                                disable);

  static constexpr auto no_stretch = option::get<i2c::no_stretch, _args...>(i2c::no_stretch::
                                                                            disable);

  static constexpr auto allow_overclock = option::get<i2c::allow_overclock, _args...>(
                                            i2c::allow_overclock::no);

  static_assert(!option::is_null<id>());

  static_assert(option::check<
    std::tuple<
      i2c::id,
      i2c::dutycycle,
      i2c::addr_mode,
      i2c::addr_1,
      i2c::addr_2
    >,
    _args...
  >());
};

template<typename _cfg>
lmcu_inline io::result start(const delay::expirable &t = delay::inf());

template<typename _cfg>
lmcu_inline io::result stop(const delay::expirable &t = delay::inf());

// ------------------------------------------------------------------------------------------------
namespace detail {
// ------------------------------------------------------------------------------------------------

template<id _id>
struct inst;

template<id _id>
using inst_t = typename inst<_id>::type;

template<>
struct inst<id::i2c1> { using type = device::I2C1; };

template<>
struct inst<id::i2c2> { using type = device::I2C2; };

template<id _id>
lmcu_inline void on()
{
  using namespace device;

  switch(_id)
  {
  case id::i2c1: RCC::APB1ENR::set_b(RCC::APB1ENR::I2C1EN); break;
  case id::i2c2: RCC::APB1ENR::set_b(RCC::APB1ENR::I2C2EN); break;
  default: break;
  }
}

template<id _id>
lmcu_inline void off()
{
  using namespace device;

  switch(_id)
  {
  case id::i2c1: RCC::APB1ENR::clr_b(RCC::APB1ENR::I2C1EN); break;
  case id::i2c2: RCC::APB1ENR::clr_b(RCC::APB1ENR::I2C2EN); break;
  default: break;
  }
}

template<id _id>
lmcu_inline void reset()
{
  using namespace device;

  switch(_id)
  {
  case id::i2c1:
    RCC::APB1RSTR::set_b(RCC::APB1RSTR::I2C1RST);
    RCC::APB1RSTR::clr_b(RCC::APB1RSTR::I2C1RST);
    break;
  case id::i2c2:
    RCC::APB1RSTR::set_b(RCC::APB1RSTR::I2C2RST);
    RCC::APB1RSTR::clr_b(RCC::APB1RSTR::I2C2RST);
    break;
  default: break;
  }
}

template<typename _cfg>
lmcu_inline void enable()
{
  static_assert(_cfg::dev_class == dev_class::i2c);

  using inst = detail::inst_t<_cfg::id>;
  inst::CR1::set_b(inst::CR1::PE);
}

template<typename _cfg>
lmcu_inline void disable()
{
  static_assert(_cfg::dev_class == dev_class::i2c);

  using inst = inst_t<_cfg::id>;
  inst::CR1::clr_b(inst::CR1::PE);
}

template<typename _cfg>
void configure()
{
  if constexpr(_cfg::allow_overclock == allow_overclock::no) {
    static_assert(_cfg::freq <= 400_kHz, "i2c clock must be <= 400kHz");
  }

  constexpr bool dual_addr = !option::is_null<_cfg::addr_1>() && !option::is_null<_cfg::addr_2>();

  if constexpr(!option::is_null<_cfg::addr_1>()) {
    if constexpr(_cfg::addr_mode == addr_mode::_7bit) {
      static_assert(_cfg::addr_1 <= 127, "in 7bit mode own address 1 must be <= 127");
    }
    else {
      static_assert(_cfg::addr_1 <= 1023, "in 10bit mode own address 1 must be <= 1023");
    }

    if constexpr(dual_addr) {
      static_assert(_cfg::addr_2 <= 127, "own address 2 must be <= 127");
    }
  }

  disable<_cfg>();

  using inst = inst_t<_cfg::id>;

  const uint32_t i2c_clock = rcc::clock::apb1() / 1_MHz;

  inst::CR2::set(i2c_clock);
  inst::TRISE::set((_cfg::freq <= 100_kHz)? i2c_clock + 1 : ((i2c_clock * 300) / 1000) + 1);

  uint32_t r = rcc::clock::apb1() / _cfg::freq;

  if constexpr(_cfg::freq <= 100_kHz) {
    // duty cycle 50% / 50%
    r /= 2;
    inst::CCR::set((r < 4)? 4 : r);
  }
  else {
    if constexpr(_cfg::dutycycle == dutycycle::_16_9) {
      // T_high = 9 * CCR * T_pclk1
      // T_low  = 16 * CCR * T_pclk1
      r /= 25;
      r |= inst::CCR::DUTY;
    }
    else {
      // T_high = CCR * T_pclk1
      // T_low  = 2 * T_high
      r /= 3;
    }
    inst::CCR::set(inst::CCR::F_S | (r < 1? 1 : r));
  }

  inst::CR1::set((_cfg::general_call == general_call::enable? inst::CR1::ENGC : 0) |
                 (_cfg::no_stretch == no_stretch::enable? inst::CR1::NOSTRETCH : 0));

  if constexpr(!option::is_null<_cfg::addr_1>()) {
    inst::OAR1::set((_cfg::addr_1 << 1) | (_cfg::addr_mode == addr_mode::_7bit? 0 : inst::OAR1::
                                                                                    ADDMODE));
    if constexpr(dual_addr) {
      inst::OAR2::set((_cfg::addr_2 << 1) | inst::OAR2::ENDUAL);
    }
    else {
      inst::OAR2::clr_b(inst::OAR2::ENDUAL);
    }
  }

  inst::CR1::set_b(inst::CR1::PE);
}

template<typename _cfg>
void reconfigure()
{
  reset<_cfg::id>();
  configure<_cfg>();
}

template<typename _cfg>
lmcu_inline bool ack_failure()
{
  using inst = detail::inst_t<_cfg::id>;

  if((inst::SR1::get() & inst::SR1::AF) != 0) {
    inst::SR1::clr_b(inst::SR1::AF);
    return true;
  }

  return false;
}

template<typename _cfg>
lmcu_inline io::result wait_bus_ready(const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  while((inst::SR2::get() & inst::SR2::BUSY) != 0) {
    if(t.expired()) { return io::result::busy; }
  }

  return io::result::success;
}

template<typename _cfg, bool _rd>
lmcu_inline io::result tx_addr(uint16_t addr, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  if constexpr(_cfg::addr_mode == addr_mode::_7bit) {
    inst::DR::set( ((addr << 1) & 0xFE) | _rd );
  }

  while((inst::SR1::get() & inst::SR1::ADDR) == 0) {
    if(t.expired()) { return io::result::busy; }

    if(ack_failure<_cfg>()) {
      stop<_cfg>(t);
      return io::result::error;
    }
  }

  // clear ADDR flag
  inst::SR1::get();
  inst::SR2::get();

  return io::result::success;
}

// ------------------------------------------------------------------------------------------------
} // namespace detail
// ------------------------------------------------------------------------------------------------

/**
 * @brief Enable clock on periph.
 *
 * @tparam _id - periph id list.
*/
template<id ..._id>
lmcu_inline void on()
{
  static_assert(sizeof...(_id) > 0);
  (detail::on<_id>(), ...);
}

/**
 * @brief Disable clock on periph.
 *
 * @tparam _id - periph id list.
*/
template<id ..._id>
lmcu_inline void off()
{
  static_assert(sizeof...(_id) > 0);
  (detail::off<_id>(), ...);
}

/**
 * @brief Reset periph.
 *
 * @tparam _id - periph id list.
*/
template<id ..._id>
lmcu_inline void reset()
{
  static_assert(sizeof...(_id) > 0);
  (detail::reset<_id>(), ...);
}

template<typename ..._cfg>
lmcu_inline void configure()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::configure<_cfg>(), ...);
}

template<typename _cfg>
lmcu_inline io::result start(const delay::expirable &t)
{
  static_assert(_cfg::dev_class == dev_class::i2c);

  using inst = detail::inst_t<_cfg::id>;

  inst::CR1::set_b(inst::CR1::START);

  while((inst::SR1::get() & inst::SR1::SB) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  return io::result::success;
}

template<typename _cfg>
lmcu_inline io::result stop(const delay::expirable &t)
{
  static_assert(_cfg::dev_class == dev_class::i2c);

  using inst = detail::inst_t<_cfg::id>;

  inst::CR1::set_b(inst::CR1::STOP);

  while((inst::SR2::get() & inst::SR2::MSL) != 0) {
    if(t.expired()) { return io::result::busy; }
  }

  return io::result::success;
}

template<typename _cfg, bool _rd = false>
io::result ping(uint16_t addr, const delay::expirable &t)
{
  static_assert(_cfg::dev_class == dev_class::i2c);

  using inst = detail::inst_t<_cfg::id>;

  if(auto r = detail::wait_bus_ready<_cfg>(t); r != io::result::success) {
    detail::reconfigure<_cfg>(); return r;
  }

  inst::CR1::clr_b(inst::CR1::POS);

  if constexpr(_rd) { inst::CR1::clr_b(inst::CR1::ACK); }

  if(auto r = start<_cfg>(t); r != io::result::success) {
    detail::reconfigure<_cfg>(); return r;
  }

  auto r = detail::tx_addr<_cfg, _rd>(addr, t);

  if(r == io::result::success) { stop<_cfg>(t); }

  return r;
}

template<typename _cfg>
io::result master_tx_begin(uint16_t addr, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  if(auto r = detail::wait_bus_ready<_cfg>(t); r != io::result::success) { return r; }

  inst::CR1::clr_b(inst::CR1::POS);
  inst::CR1::clr_b(inst::CR1::ACK);

  lmcu_defer([&t] { stop<_cfg>(t); });
  if(auto r = start<_cfg>(t); r != io::result::success) { return r; }

  if(auto r = detail::tx_addr<_cfg, false>(addr, t); r != io::result::success) { return r; }

  return io::result::success;
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::i2c
// ------------------------------------------------------------------------------------------------
