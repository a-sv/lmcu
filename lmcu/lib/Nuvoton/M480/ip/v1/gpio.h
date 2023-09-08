#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/gpio>
#include <lmcu/irq>
#include <lmcu/common>


// ------------------------------------------------------------------------------------------------
namespace lmcu::gpio {
// ------------------------------------------------------------------------------------------------
#include "../../../../irq_id.h"

enum class port { A, B, C, D, E, F, G, H };

enum class mode
{
  input,
  output_open_drain,
  output_push_pull,
  quasi_bidir
};

enum class path { disable, enable };

enum class debounce { disable, enable };

enum class slew_rate {
  normal,  // maximum 40 MHz at 2.7V
  high,    // maximum 80 MHz at 2.7V
  fast     // maximum 100 MHz at 2.7V
};

enum class mfp {
  _0,
  _1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7,
  _8,
  _9,
  _10,
  _11,
  _12,
  _13,
  _14,
  _15,
};

enum class event { disabled, rising, falling, all };

enum class pin_n : uint32_t { };

template <auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();

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

    static constexpr auto path = option::get<gpio::path, _args...>(gpio::path::enable);

    static constexpr auto debounce = option::get<gpio::debounce, _args...>(gpio::debounce::disable);

    static constexpr auto slew_rate = option::get<gpio::slew_rate, _args...>(gpio::slew_rate::normal);

    static constexpr auto mfp = option::get<gpio::mfp, _args...>(gpio::mfp::_0);

    static constexpr auto event = option::get<gpio::event, _args...>(gpio::event::disabled);

    static constexpr auto irq = option::get<irq_id::_0, _args...>();


    static_assert(!option::is_null<port>() && !option::is_null<n>(), "options 'port' and 'pin_n' is "
                                                                     "required!");
    static_assert(option::check<
      std::tuple<
        gpio::mfp,
        gpio::port,
        gpio::pin_n,
        gpio::mode,
        gpio::event,
        irq_id::_0
      >,
      _args...
    >());
};

template <port ..._ports>
constexpr bool port_exists() noexcept;

template<port _port>
struct inst;


template<>
struct inst<port::A> { using type = device::GPIOA; };

template<>
struct inst<port::B> { using type = device::GPIOB; };

template<>
struct inst<port::C> { using type = device::GPIOC; };

template<>
struct inst<port::D> { using type = device::GPIOD; };

template<>
struct inst<port::E> { using type = device::GPIOE; };

template<>
struct inst<port::F> { using type = device::GPIOF; };

template<>
struct inst<port::G> { using type = device::GPIOG; };

template<>
struct inst<port::H> { using type = device::GPIOH; };

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
      auto c = inst_t<_port>::DOUT::get();
      inst_t<_port>::DOUT::set(val ? (c | msk) : (c & ~msk));
  }
}

template<port _port, typename ..._pins>
constexpr uint32_t clr_mode_mask()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port) {
      const uint32_t m_ofs = 0x3<<(p.n<<1);
      return m_ofs;
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<bool _low, port _port, typename ..._pins>
constexpr uint32_t mfp_mask()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port && ((_low && p.n <= 7) || (!_low && p.n >= 8))) {
      const uint32_t m_ofs = (_low? p.n : p.n - 8) * 4;
      return 0xfUL << m_ofs;
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<bool _low, port _port, typename ..._pins>
constexpr uint32_t mfp_bits()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port && ((_low && p.n <= 7) || (!_low && p.n >= 8))) {
      const uint32_t m_ofs = (_low? p.n : p.n - 8) * 4;
      uint32_t m = 0;
      switch(p.mfp)
      {
      case mfp::_1:  m = 1; break;
      case mfp::_2:  m = 2; break;
      case mfp::_3:  m = 3; break;
      case mfp::_4:  m = 4; break;
      case mfp::_5:  m = 5; break;
      case mfp::_6:  m = 6; break;
      case mfp::_7:  m = 7; break;
      case mfp::_8:  m = 8; break;
      case mfp::_9:  m = 9; break;
      case mfp::_10: m = 10; break;
      case mfp::_11: m = 11; break;
      case mfp::_12: m = 12; break;
      case mfp::_13: m = 13; break;
      case mfp::_14: m = 14; break;
      case mfp::_15: m = 15; break;
      default: break;
      }
      return (m << m_ofs);
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

/*
template<bool _low, port _port, typename ..._pins>
constexpr uint32_t set_mfp()
{
    if(_low) {

    }else {

    }
}*/

template<port _port, typename ..._pins>
constexpr uint32_t mode_bits()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if((p.port == _port)&&(p.mfp == mfp::_0)) {
      const uint32_t m_ofs = p.n * 2;

      if(is_input(p)) {

      }
      else {
        uint32_t m = 0;

        switch(p.mode)
        {
        case mode::output_push_pull: m = 1; break;
        case mode::output_open_drain: m = 2; break;
        case mode::quasi_bidir: m = 3; break;
        default: break;
        }

        return (m << m_ofs);
      }
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
constexpr uint32_t event_mask()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port) {
      uint32_t e = 0;
      if(p.event == event::falling) { e |= 0x00000001; }
      if(p.event == event::rising) { e |= 0x00010000; }
      if(p.event == event::all) { e |= 0x00010001; }
      return (e << p.n);
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
lmcu_inline void toggle()
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    using DOUT = typename inst_t<_port>::DOUT;
    DOUT::set(DOUT::get() ^ msk);
  }
}

template<typename _pin>
constexpr bool is_input(_pin&& pin) noexcept
{
  return pin.mode == mode::input;
}

template<port _port, typename ..._pins>
void configure_port()
{
  using namespace device;

  constexpr auto md_msk = clr_mode_mask<_port, _pins...>();
  if constexpr(md_msk != 0) {
    inst_t<_port>::MODE::clr_b(md_msk);
    inst_t<_port>::MODE::set_b(mode_bits<_port, _pins...>());
  }

  constexpr auto mfpl_msk = mfp_mask<true, _port, _pins...>();
  if constexpr(mfpl_msk != 0) {
    switch(_port)
    {
    case port::A:
      SYS::GPA_MFPL::clr_b(mfpl_msk);
      SYS::GPA_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    case port::B:
      SYS::GPB_MFPL::clr_b(mfpl_msk);
      SYS::GPB_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    case port::C:
      SYS::GPC_MFPL::clr_b(mfpl_msk);
      SYS::GPC_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    case port::D:
      SYS::GPD_MFPL::clr_b(mfpl_msk);
      SYS::GPD_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    case port::E:
      SYS::GPE_MFPL::clr_b(mfpl_msk);
      SYS::GPE_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    case port::F:
      SYS::GPF_MFPL::clr_b(mfpl_msk);
      SYS::GPF_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    case port::G:
      SYS::GPG_MFPL::clr_b(mfpl_msk);
      SYS::GPG_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    case port::H:
      SYS::GPH_MFPL::clr_b(mfpl_msk);
      SYS::GPH_MFPL::set_b(mfp_bits<true, _port, _pins...>());
      break;
    default: break;
    }
  }

  constexpr auto mfph_msk = mfp_mask<false, _port, _pins...>();
  if constexpr(mfph_msk != 0) {
    switch(_port)
    {
    case port::A:
      SYS::GPA_MFPH::clr_b(mfph_msk);
      SYS::GPA_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    case port::B:
      SYS::GPB_MFPH::clr_b(mfph_msk);
      SYS::GPB_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    case port::C:
      SYS::GPC_MFPH::clr_b(mfph_msk);
      SYS::GPC_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    case port::D:
      SYS::GPD_MFPH::clr_b(mfph_msk);
      SYS::GPD_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    case port::E:
      SYS::GPE_MFPH::clr_b(mfph_msk);
      SYS::GPE_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    case port::F:
      SYS::GPF_MFPH::clr_b(mfph_msk);
      SYS::GPF_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    case port::G:
      SYS::GPG_MFPH::clr_b(mfph_msk);
      SYS::GPG_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    case port::H:
      SYS::GPH_MFPH::clr_b(mfph_msk);
      SYS::GPH_MFPH::set_b(mfp_bits<false, _port, _pins...>());
      break;
    default: break;
    }
  }

  constexpr auto event_msk = event_mask<_port, _pins...>();
  if constexpr(event_msk != 0) {
    inst_t<_port>::INTEN::set_b(event_msk);
  }

  // irq
/*  {
    if constexpr(!option::is_null<_cfg::irq>()) {
      constexpr auto irqn = []
      {
        switch(_port)
        {
        case port::A: return device::find_irqn("gpa");
        case port::B: return device::find_irqn("gpb");
        case port::C: return device::find_irqn("gpc");
        case port::D: return device::find_irqn("gpd");
        case port::E: return device::find_irqn("gpe");
        case port::F: return device::find_irqn("gpf");
        default: break;
        }
        return device::irqn::invalid_irqn;
      }();

      nvic::set_encoded_priority<irqn, _port::irq>();
      nvic::enable_irq<irqn>();
    }
  }*/
}

/**
 * @brief I/O ports reset
*/
template<port ..._ports>
void reset()
{
  using namespace device;

  static_assert(port_exists<_ports...>(), "port does not exists in this device");


  //  (port_rst(_ports), ...);
}

template<typename ..._pins>
void configure()
{
  static_assert(port_exists<_pins::port...>(), "port does not exists in this device");

  configure_port<port::A, _pins...>();
  configure_port<port::B, _pins...>();
  configure_port<port::C, _pins...>();
  configure_port<port::D, _pins...>();
  configure_port<port::E, _pins...>();
  configure_port<port::F, _pins...>();
  configure_port<port::G, _pins...>();
  configure_port<port::H, _pins...>();
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
  set<port::E, _pins...>(val);
  set<port::F, _pins...>(val);
  set<port::G, _pins...>(val);
  set<port::H, _pins...>(val);
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
  toggle<port::E, _pins...>();
  toggle<port::F, _pins...>();
  toggle<port::G, _pins...>();
  toggle<port::H, _pins...>();
}

/**
 * @brief Set port output state
 *
 * @tparam _port - GPIO port
 * @param  val   - bits to set on port
*/
//template<port _port>
//lmcu_inline void set(uint32_t val) { inst_t<_port>::DOUT::set(val); }

/**
 * @brief Toggle port output state
 *
 * @tparam _port - GPIO port
*/
template<port _port>
lmcu_inline void toggle()
{
  using DOUT = typename inst_t<_port>::DOUT;
  DOUT::set(DOUT::get() ^ 0xFFFF);
}

template<typename _p>
lmcu_inline void clearEvent() { inst_t<_p::port>::INTSRC::set_b(_p::mask); }

template<typename _p>
lmcu_inline auto getEvent() { return (inst_t<_p::port>::INTSRC::get() & _p::mask) != 0; }

template<typename _p>
lmcu_inline void enableEvent(event e) {
    uint32_t mask = 0;
    if(e == event::falling) { mask |= 0x00000001; }
    if(e == event::rising) { mask |= 0x00010000; }
    if(e == event::all) { mask |= 0x00010001; }
    inst_t<_p::port>::INTEN::set_b(mask << _p::n);
}

template<typename _p>
lmcu_inline void disableEvents()
{
    constexpr uint32_t mask = 0x00010001;
    inst_t<_p::port>::INTEN::clr_b(mask << _p::n);
}


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::gpio
// ------------------------------------------------------------------------------------------------
