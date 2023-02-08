#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/gpio>
#include <lmcu/common>


// ------------------------------------------------------------------------------------------------
namespace lmcu::gpio {
// ------------------------------------------------------------------------------------------------

enum class port { A, B, C, D, E, F };

enum class mode
{
  input,
  output_open_drain,
  output_push_pull,
  quasi_bidir
};

enum class mfp { disable, enable };



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

    static constexpr auto mfp = option::get<gpio::mfp, _args...>(gpio::mfp::disable);


    static_assert(!option::is_null<port>() && !option::is_null<n>(), "options 'port' and 'pin_n' is "
                                                                     "required!");

    static_assert(option::check<
      std::tuple<gpio::port, gpio::pin_n, gpio::mfp, gpio::mode>,
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

template<typename _pin>
constexpr bool is_input(_pin&& pin) noexcept
{
  return pin.mode == mode::input;
}

template<port _port, typename ..._pins>
constexpr uint32_t mode_bits()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if((p.port == _port)&&(p.mfp == mfp::disable)) {
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

template<port _port, typename ..._pins>
constexpr uint32_t mfp_mask()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port) {
      return 0x1UL << p.n;
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
constexpr uint32_t mfp_bits()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port) {
      uint32_t m = 0;
      if(p.mfp == mfp::enable) { m = 1; }
      return (m << p.n);
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}


template<port _port, typename ..._pins>
void configure_port()
{
  using namespace device;

  constexpr auto md_msk = clr_mode_mask<_port, _pins...>();
  if constexpr(md_msk != 0) {
    inst_t<_port>::PMD::clr_b(md_msk);
    inst_t<_port>::PMD::set_b(mode_bits<_port, _pins...>());
  }

  constexpr auto mfp_msk = mfp_mask<_port, _pins...>();
  if constexpr(mfp_msk != 0) {
    switch(_port)
    {
    case port::A:
      GCR::GPA_MFP::clr_b(mfp_msk);
      GCR::GPA_MFP::set_b(mfp_bits<_port, _pins...>());
      break;
    case port::B:
      GCR::GPB_MFP::clr_b(mfp_msk);
      GCR::GPB_MFP::set_b(mfp_bits<_port, _pins...>());
      break;
    case port::C:
      GCR::GPC_MFP::clr_b(mfp_msk);
      GCR::GPC_MFP::set_b(mfp_bits<_port, _pins...>());
      break;
    case port::D:
      GCR::GPD_MFP::clr_b(mfp_msk);
      GCR::GPD_MFP::set_b(mfp_bits<_port, _pins...>());
      break;
    case port::E:
      GCR::GPE_MFP::clr_b(mfp_msk);
      GCR::GPE_MFP::set_b(mfp_bits<_port, _pins...>());
      break;
    case port::F:
      GCR::GPF_MFP::clr_b(mfp_msk);
      GCR::GPF_MFP::set_b(mfp_bits<_port, _pins...>());
      break;
    default: break;
    }
  }

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
}



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

template<port _port, typename ..._pins>
lmcu_inline void toggle()
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    using DOUT = typename inst_t<_port>::DOUT;
    DOUT::set(DOUT::get() ^ msk);
  }
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
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::gpio
// ------------------------------------------------------------------------------------------------
