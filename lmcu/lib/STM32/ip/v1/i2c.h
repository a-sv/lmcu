#pragma once
#include <lmcu/dev/i2c>
#include <lmcu/rcc>
#include <lmcu/gpio>
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

enum class direction { read, write };

template<typename _scl, typename _sda, auto ..._args>
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

  using scl_pin = _scl;
  using sda_pin = _sda;

  static_assert(!option::is_null<id>());

  static_assert(option::check<
    std::tuple<
      i2c::id,
      i2c::freq,
      i2c::dutycycle,
      i2c::addr_mode,
      i2c::addr_1,
      i2c::addr_2,
      i2c::general_call,
      i2c::no_stretch,
      i2c::allow_overclock
    >,
    _args...
  >());
};

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
  using inst = detail::inst_t<_cfg::id>;
  inst::CR1::set_b(inst::CR1::PE);
}

template<typename _cfg>
lmcu_inline void disable()
{
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
    inst::OAR1::set(
      (_cfg::addr_1 << inst::OAR1::ADD_POS) |
      (_cfg::addr_mode == addr_mode::_7bit? 0 : inst::OAR1::ADDMODE)
    );

    if constexpr(dual_addr) {
      inst::OAR2::set((_cfg::addr_2 << inst::OAR2::ADD2_POS) | inst::OAR2::ENDUAL);
    }
    else {
      inst::OAR2::set(0);
    }
  }

  inst::CR1::set_b(inst::CR1::PE);
}

template<typename _cfg>
lmcu_inline void reconfigure()
{
  using scl_input = gpio::pin<option::null, _cfg::scl_pin::port, gpio::pin_n{_cfg::scl_pin::n},
                              gpio::mode::input, gpio::pull::up>;
  using sda_input = gpio::pin<option::null, _cfg::sda_pin::port, gpio::pin_n{_cfg::sda_pin::n},
                              gpio::mode::input, gpio::pull::up>;
  using scl_out = gpio::pin<option::null, _cfg::scl_pin::port, gpio::pin_n{_cfg::scl_pin::n},
                            gpio::mode::output_open_drain, gpio::pull::up, gpio::speed::high>;

  gpio::configure<scl_input, sda_input>();

  if(gpio::read<scl_input>() && !gpio::read<sda_input>()) {
    // slave stuck detected
    gpio::configure<scl_out>();
    // generate 9 clocks for unlock SDA line
    for(uint32_t i = 0; i < 9; i++) {
      gpio::set<scl_out>(false);
      delay::us(5);
      gpio::set<scl_out>(true);
      delay::us(5);
    }
  }

  gpio::configure<typename _cfg::scl_pin, typename _cfg::sda_pin>();

  reset<_cfg::id>();
  configure<_cfg>();
}

template<typename _cfg>
lmcu_inline int wait_ready(const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  while((inst::SR2::get() & inst::SR2::BUSY) != 0) {
    if(t.expired()) { return etimedout; }
  }

  return success;
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

template<typename _cfg, direction _dir>
lmcu_inline int tx_addr(uint16_t addr, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  auto f_wait = [&t](uint32_t f)
  {
    while((inst::SR1::get() & f) == 0) {
      if(t.expired()) {
        return etimedout;
      }

      if(ack_failure<_cfg>()) {
        stop<_cfg>(t);
        return eio;
      }
    }
    return success;
  };

  if constexpr(_cfg::addr_mode == addr_mode::_7bit) {
    inst::DR::set( ((addr << 1) & 0xFE) | (_dir == direction::read) );
  }
  else { // 10 bit address
    inst::DR::set( ((addr & 0x300) >> 7) | (_dir == direction::write? 0xF0 : 0xF1) );

    if(auto r = f_wait(inst::SR1::ADD10); r != success) { return r; }

    inst::DR::set(addr & 0xFF);
  }

  if(auto r = f_wait(inst::SR1::ADDR); r != success) { return r; }

  // clear ADDR flag
  inst::SR1::get();
  inst::SR2::get();

  return success;
}

template<typename _cfg>
lmcu_inline void clr_addr_flag()
{
  using inst = detail::inst_t<_cfg::id>;

  inst::SR1::get();
  inst::SR2::get();
}

template<typename _cfg>
static inline int wait_rxne(const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  while((inst::SR1::get() & inst::SR1::RXNE) == 0) {
    if(t.expired()) { return etimedout; }
    if((inst::SR1::get() & inst::SR1::STOPF) != 0) { return eio; }
  }

  return success;
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

/**
 * @brief Configure periph.
 *
 * @tparam _id - periph id list.
*/
template<typename ..._cfg>
void configure()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::configure<_cfg>(), ...);
}

template<typename ..._cfg>
void reconfigure()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::reconfigure<_cfg>(), ...);
}

template<typename _cfg>
int start(const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  inst::CR1::set_b(inst::CR1::START);

  while((inst::SR1::get() & inst::SR1::SB) == 0) {
    if(t.expired()) { return etimedout; }
  }

  return success;
}

template<typename _cfg>
int stop(const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  inst::CR1::set_b(inst::CR1::STOP);
  while((inst::SR2::get() & inst::SR2::MSL) != 0) {
    if(t.expired()) { return etimedout; }
  }

  return success;
}

template<typename _cfg, direction _dir = direction::write>
int ping(uint16_t addr, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  if(auto r = detail::wait_ready<_cfg>(t); r != success) {
    detail::reconfigure<_cfg>(); return r;
  }

  inst::CR1::clr_b(inst::CR1::POS);

  if constexpr(_dir == direction::read) {
    inst::CR1::clr_b(inst::CR1::ACK);
  }

  if(auto r = start<_cfg>(t); r != success) {
    detail::reconfigure<_cfg>(); return r;
  }

  auto r = detail::tx_addr<_cfg, _dir>(addr, t);

  detail::clr_addr_flag<_cfg>();

  if(r == success) { stop<_cfg>(t); }

  return r;
}

template<typename _cfg>
int master_read(uint16_t addr, void *data, uint32_t size, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  if(auto r = detail::wait_ready<_cfg>(t); r != success) {
    detail::reconfigure<_cfg>(); return r;
  }

  lmcu_defer([] { inst::CR1::clr_b(inst::CR1::ACK); });

  uint32_t r = inst::CR1::get();
  r &= ~inst::CR1::POS;
  r |= inst::CR1::ACK;
  inst::CR1::set(r);

  if(auto r = start<_cfg>(t); r != success) { return r; }

  if(auto r = detail::tx_addr<_cfg>(addr); r != success) {
    inst::CR1::set_b(inst::CR1::STOP); return r;
  }

  auto p = static_cast<uint8_t*>(data);

  auto rx_last = [&p, &t](uint32_t size)
  {
    switch(size) {
    case 0: {
      detail::clr_addr_flag<_cfg>();
      inst::CR1::set_b(inst::CR1::STOP);
    } return success;

    case 1: {
      inst::CR1::clr_b(inst::CR1::ACK);

      irq::ctl ic;
      ic.disable();

      detail::clr_addr_flag<_cfg>();
      inst::CR1::set_b(inst::CR1::STOP);

      if(auto r = detail::wait_rxne<_cfg>(t); r != success) { return r; }
      *p = inst::DR::get();
    } return success;

    case 2: {
      inst::CR1::set_b(inst::CR1::POS);

      {
        irq::ctl ic;
        ic.disable();

        detail::clr_addr_flag<_cfg>();
        inst::CR1::clr_b(inst::CR1::ACK);
      }

      if((inst::SR1::get() & inst::SR1::BTF) == 0) {
        if(t.expired()) { return etimedout; }
      }

      {
        irq::ctl ic;
        ic.disable();

        inst::CR1::set_b(inst::CR1::STOP);
        *p++ = inst::DR::get();
      }

      *p = inst::DR::get();
    } return success;

    case 3: {
      detail::clr_addr_flag<_cfg>();

      if((inst::SR1::get() & inst::SR1::BTF) == 0) {
        if(t.expired()) { return etimedout; }
      }

      inst::CR1::clr_b(inst::CR1::ACK);

      irq::ctl ic;
      ic.disable();

      *p++ = inst::DR::get();

      if((inst::SR1::get() & inst::SR1::BTF) == 0) {
        if(t.expired()) { return etimedout; }
      }

      inst::CR1::set_b(inst::CR1::STOP);

      *p++ = inst::DR::get();
      *p++ = inst::DR::get();
    } return success;

    default:
      return einval;
    }
  };

  if(auto r = rx_last(size); r != einval) { return r; }

  detail::clr_addr_flag<_cfg>();

  const auto end = p + size;

  while((end - p) > 3) {
    if(auto r = detail::wait_rxne<_cfg>(t); r != success) { return r; }
    *p++ = inst::DR::get();
    if((inst::SR1::get() & inst::SR1::BTF) != 0) { *p++ = inst::DR::get(); }
  }

  return rx_last(end - p);
}

template<typename _cfg>
int master_tx_begin(uint16_t addr, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  if(auto r = detail::wait_ready<_cfg>(t); r != success) { return r; }

  inst::CR1::clr_b(inst::CR1::POS);
  inst::CR1::clr_b(inst::CR1::ACK);

  if(auto r = start<_cfg>(t); r != success) { stop<_cfg>(t); return r; }

  if(auto r = detail::tx_addr<_cfg, direction::write>(addr, t); r != success) {
    stop<_cfg>(t);
    return r;
  }

  return success;
}

template<typename _cfg>
int master_tx_end(const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  lmcu_defer([&t] { stop<_cfg>(t); });

  do {
    if(detail::ack_failure<_cfg>()) { return eio; }
    if(t.expired()) { return etimedout; }
  } while((inst::SR1::get() & inst::SR1::BTF) == 0);

  return success;
}

template<typename _cfg>
int master_tx(uint8_t data, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  do {
    if(detail::ack_failure<_cfg>()) { return eio; }
    if(t.expired()) { return etimedout; }
  } while((inst::SR1::get() & inst::SR1::TXE) == 0);

  inst::DR::set(data);

  return success;
}

template<typename _cfg>
int master_write(const void *data, size_t sz, const delay::expirable &t)
{
  using inst = detail::inst_t<_cfg::id>;

  auto b = static_cast<const uint8_t*>(data), e = b + sz;

  while(b < e) {
    do {
      if(detail::ack_failure<_cfg>()) { return eio; }
      if(t.expired()) { return etimedout; }
    } while((inst::SR1::get() & inst::SR1::TXE) == 0);

    inst::DR::set(*b++);
  }

  return success;
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::i2c
// ------------------------------------------------------------------------------------------------
