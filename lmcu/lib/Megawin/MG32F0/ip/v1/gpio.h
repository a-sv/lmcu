#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/gpio>
#include <lmcu/common>

// ------------------------------------------------------------------------------------------------
namespace lmcu::gpio {
// ------------------------------------------------------------------------------------------------

template<uint32_t _val>
struct debug;

enum class port { A, B, C, D };

enum class mode
{
  input,
  output_open_drain,
  output_push_pull,
  quasi_bidir,
  analog
};

enum class afs {
  _0 = 0,
  _1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7,
  _8,
  _9,
  _10
};

// Pin input deglitch filter clock divider select
enum class fdiv {
  bypass,
  _1,
  _4,
  _16
};

enum class fclock {
  ahb,
  ahb_8,
  ilrco,
  tm00_trgo,
  ck_ut
};

// Pin output drive strength select
enum class odc_level {
  full,
  _1,
  _2,
  _3
};

enum class in_inv {
  disable,
  enable
};

enum class pu {
  disable,
  enable
};

enum class speed {
  disable,
  enable
};

enum class pin_n : uint32_t { };

// not connected pin
struct not_connected
{
  static constexpr auto dev_class = lmcu::dev_class::gpio_pin;
  static constexpr auto nc        = true;
};

template<typename _af, auto ..._args>
struct pin
{
  static constexpr auto dev_class = lmcu::dev_class::gpio_pin;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto port = option::get<gpio::port, _args...>();

  static constexpr auto n = option::get_u<gpio::pin_n, _args...>();

  static constexpr auto mask = 1UL << n;

  static constexpr auto mode = option::get<gpio::mode, _args...>(gpio::mode::input);

  static constexpr auto fdiv = option::get<gpio::fdiv, _args...>(gpio::fdiv::bypass);

  static constexpr auto fclock = option::get<gpio::fclock, _args...>(gpio::fclock::ahb);

  static constexpr auto odc_level = option::get<gpio::odc_level, _args...>(gpio::odc_level::full);

  static constexpr auto in_inv = option::get<gpio::in_inv, _args...>(gpio::in_inv::disable);

  static constexpr auto pu = option::get<gpio::pu, _args...>(gpio::pu::disable);

  static constexpr auto speed = option::get<gpio::speed, _args...>(gpio::speed::disable);

  static constexpr auto afs = option::get<gpio::afs, _args...>(gpio::afs::_0);

  static_assert(!option::is_null<port>() && !option::is_null<n>(), "options 'port' and 'pin_n' is "
                                                                         "required!");

  static_assert(option::check<
    std::tuple<
      gpio::afs,
      gpio::port,
      gpio::pin_n,
      gpio::mode,
      gpio::fdiv,
      gpio::fclock,
      gpio::odc_level,
      gpio::in_inv,
      gpio::pu,
      gpio::speed
    >,
    _args...
  >());
};

template <port ..._ports>
constexpr bool port_exists() noexcept;

template<port _port>
struct inst;


template<>
struct inst<port::A> { using type = device::IOPA; };

template<>
struct inst<port::B> { using type = device::IOPB; };

template<>
struct inst<port::C> { using type = device::IOPC; };

template<>
struct inst<port::D> { using type = device::IOPD; };

template<port _port>
using inst_t = typename inst<_port>::type;

template<port _port, typename ..._pins>
constexpr uint32_t pin_mask()
{
  auto bits = [](auto pin) -> uint32_t
  {
    return pin.port == _port ? pin.mask : 0;
  };
  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
lmcu_inline void set([[maybe_unused]] bool val)
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    inst_t<_port>::SC::set(val ? msk : (msk<<16));
  }
}

template<port _port, typename ..._pins>
lmcu_inline void toggle()
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    using OUT = typename inst_t<_port>::OUT;
    OUT::set(OUT::get() ^ msk);
  }
}

/**
 * @brief I/O ports clock enable
*/
template<port ..._ports>
void on()
{
  using namespace device;

  static_assert(port_exists<_ports...>(), "port does not exists in this device");

  device::CSC::KEY::set(0xA217);
  auto port_on = [](auto val)
  {
    switch(val)
    {
    case port::A: CSC::AHB::set_b(CSC::AHB::IOPA_EN_ENABLE); break;
    case port::B: CSC::AHB::set_b(CSC::AHB::IOPB_EN_ENABLE); break;
    case port::C: CSC::AHB::set_b(CSC::AHB::IOPC_EN_ENABLE); break;
    case port::D: CSC::AHB::set_b(CSC::AHB::IOPD_EN_ENABLE); break;
    default: break;
    }
  };

  (port_on(_ports), ...);
  device::CSC::KEY::set(0x1111);
}

template<typename _reg>
constexpr inline void afs_conf(afs val, _reg&& r)
{
  using namespace device;
  r &= ~(PA::CR::AFS_MASK);
  switch(val) {
  case afs::_1: r |= PA::CR::AFS_AF1; break;
  case afs::_2: r |= PA::CR::AFS_AF2; break;
  case afs::_3: r |= PA::CR::AFS_AF3; break;
  case afs::_4: r |= PA::CR::AFS_AF4; break;
  case afs::_5: r |= PA::CR::AFS_AF5; break;
  case afs::_6: r |= PA::CR::AFS_AF6; break;
  case afs::_7: r |= PA::CR::AFS_AF7; break;
  case afs::_8: r |= PA::CR::AFS_AF8; break;
  case afs::_9: r |= PA::CR::AFS_AF9; break;
  case afs::_10: r |= PA::CR::AFS_AF10; break;
  default:
    break;
  }
}

template<typename _reg>
constexpr inline void fdiv_conf(fdiv val, _reg&& r)
{
   using namespace device;
   r &= ~(PA::CR::FDIV_MASK);
   if(val == fdiv::_1) { r |= PA::CR::FDIV_DIV1; }
   else if(val == fdiv::_4) { r |= PA::CR::FDIV_DIV4; }
   else if(val == fdiv::_16) { r |= PA::CR::FDIV_DIV16; }
}

template<typename _reg>
constexpr inline void odc_conf(odc_level val, _reg&& r)
{
  using namespace device;
  r &= ~(PA::CR::ODC_MASK);
  if(val == odc_level::_1) r |= PA::CR::ODC_LEVEL1;
  else if(val == odc_level::_2) { r |= PA::CR::ODC_LEVEL2; }
  else if(val == odc_level::_3) { r |= PA::CR::ODC_LEVEL3; }
}

template<typename _reg>
constexpr inline void inv_conf(in_inv val, _reg&& r)
{
  using namespace device;
  r &= ~(PA::CR::INV_MASK);
  if(val == in_inv::enable) r |= PA::CR::INV_ENABLE;
}

template<typename _reg>
constexpr inline void pu_conf(pu val, _reg&& r)
{
  using namespace device;
  r &= ~(PA::CR::PU_MASK);
  if(val == pu::enable) r |= PA::CR::PU_ENABLE;
}

template<typename _reg>
constexpr inline void speed_conf(speed val, _reg&& r)
{
  using namespace device;
  r &= ~(PA::CR::HS_MASK);
  if(val == speed::enable) r |= PA::CR::HS_ENABLE;
}

template<typename _reg>
constexpr inline void mode_conf(mode val, _reg&& r)
{
  using namespace device;
  r &= ~(PA::CR::IOM_MASK);
  if(val == mode::input) { r |= PA::CR::IOM_DIN; }
  else if(val == mode::output_push_pull) { r |= PA::CR::IOM_PPO; }
  else if(val == mode::output_open_drain) { r |= PA::CR::IOM_ODO; }
  else if(val == mode::quasi_bidir) { r |= 0; } //TODO: quasi_bidir
}

template<port _port, typename ..._pins>
void configure_port()
{
  using namespace device;

  static auto _cr = [](auto pin)
  {
     using p = decltype(pin);
     if constexpr(p::port == _port) {
       constexpr auto r = [] {
         struct {
          uint32_t cr = 0, flt = 0;
         } r;

         afs_conf(p::afs, r.cr);
         fdiv_conf(p::fdiv, r.cr);
         odc_conf(p::odc_level, r.cr);
         inv_conf(p::in_inv, r.cr);
         pu_conf(p::pu, r.cr);
         speed_conf(p::speed, r.cr);
         mode_conf(p::mode, r.cr);

         return r;
       }();

       //debug<r.cr>();
       switch(_port)
       {
       case port::A: PA::CR::set(p::n, r.cr); break;
       case port::B: PB::CR::set(p::n, r.cr); break;
       case port::C: PC::CR::set(p::n, r.cr); break;
       case port::D: PD::CR::set(p::n, r.cr); break;
       default: break;
       }
     };
  };

  (_cr(_pins{}), ...);
}

template<typename ..._pins>
void configure()
{
  static_assert(port_exists<_pins::port...>(), "port does not exists in this device");

  configure_port<port::A, _pins...>();
  configure_port<port::B, _pins...>();
  configure_port<port::C, _pins...>();
  configure_port<port::D, _pins...>();
}

/**
 * @brief Set pin's output state
 *
 * @tparam _pins - list of pins
 * @param  val   - pin state (true == 1, false == 0)
*/
template<typename ..._pins>
lmcu_inline void set(bool val)
{
  set<port::A, _pins...>(val);
  set<port::B, _pins...>(val);
  set<port::C, _pins...>(val);
  set<port::D, _pins...>(val);
}

/**
 * @brief Toggle pin's output state
 *
 * @tparam _pins - list of pins
*/
template<typename ..._pins>
lmcu_inline void toggle()
{
  toggle<port::A, _pins...>();
  toggle<port::B, _pins...>();
  toggle<port::C, _pins...>();
  toggle<port::D, _pins...>();
}

/**
 * @brief Toggle port output state
 *
 * @tparam _port - GPIO port
*/
template<port _port>
lmcu_inline void toggle()
{
  using OUT = typename inst_t<_port>::OUT;
  OUT::set(OUT::get() ^ 0xFFFF);
}

/**
 * @brief Read input signal on the port or pin
 *
 * @tparam _p - GPIO port or pin
*/
template<typename _p>
lmcu_inline auto read() { return (inst_t<_p::port>::IN::get() & _p::mask) != 0; }

template <port _p>
lmcu_inline auto read() { return inst_t<_p>::IN::get(); }

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::gpio
// ------------------------------------------------------------------------------------------------
