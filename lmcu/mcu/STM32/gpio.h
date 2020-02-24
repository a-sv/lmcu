#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/gpio>
#include <lmcu/common>

namespace lmcu::gpio {

enum class port { A, B, C, D, E, F, G, H, I, J, K };

enum class mode
{
  input,
  output_open_drain,
  output_push_pull,
  analog,
  af_input,
  af_open_drain,
  af_push_pull
};

enum class pull { no_pull, up, down };

enum class speed { low, medium, high, very_high };

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
  static constexpr auto port      = option::get<gpio::port, _args...>();
  static constexpr auto n         = option::get_u<gpio::pin_n, _args...>();
  static constexpr auto mask      = 1UL << n;
  static constexpr auto mode      = option::get<gpio::mode, _args...>(gpio::mode::analog);
  static constexpr auto pull      = option::get<gpio::pull, _args...>(gpio::pull::no_pull);
  static constexpr auto speed     = option::get<gpio::speed, _args...>(gpio::speed::low);
  static constexpr auto af        = option::get<_af, _args...>();
  static constexpr auto nc        = false;

  static_assert(!option::is_null<port>() && !option::is_null<n>(), "options 'port' and 'pin_n' is "
                                                                   "required!");

  static_assert(option::check<
    std::tuple<gpio::port, gpio::pin_n, gpio::mode, gpio::pull, gpio::speed, _af>,
    _args...
  >());
};

/**
 * @brief Returns 'true' if ports exists on current device
 *
 * @tparam _ports - port list
*/
template <port ..._ports>
constexpr bool port_exists() noexcept;

// ------------------------------------------------------------------------------------------------
namespace detail {
// ------------------------------------------------------------------------------------------------

template<port _port>
struct inst;

template<port _port>
using inst_t = typename inst<_port>::type;

template<port _port, typename ..._pins>
constexpr uint32_t pin_mask()
{
  auto bits = [](auto pin) -> uint32_t
  {
    return pin.port == _port? pin.mask : 0;
  };
  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
lmcu_inline void set([[maybe_unused]] bool val)
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    inst_t<_port>::BSRR::set(val? msk : msk << 16);
  }
}

template<port _port, typename ..._pins>
lmcu_inline void toggle()
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    inst_t<_port>::ODR::ref() ^= msk;
  }
}

// ------------------------------------------------------------------------------------------------
} // namespace detail
// ------------------------------------------------------------------------------------------------

/**
 * @brief Set pin's output state
 *
 * @tparam _pins - list of pins
 * @param  val   - pin state (true == 1, false == 0)
*/
template<typename ..._pins>
lmcu_inline void set(bool val)
{
  detail::set<port::A, _pins...>(val);
  detail::set<port::B, _pins...>(val);
  detail::set<port::C, _pins...>(val);
  detail::set<port::D, _pins...>(val);
  detail::set<port::E, _pins...>(val);
  detail::set<port::F, _pins...>(val);
  detail::set<port::G, _pins...>(val);
  detail::set<port::H, _pins...>(val);
  detail::set<port::I, _pins...>(val);
  detail::set<port::J, _pins...>(val);
  detail::set<port::K, _pins...>(val);
}

/**
 * @brief Toggle pin's output state
 *
 * @tparam _pins - list of pins
*/
template<typename ..._pins>
lmcu_inline void toggle()
{
  detail::toggle<port::A, _pins...>();
  detail::toggle<port::B, _pins...>();
  detail::toggle<port::C, _pins...>();
  detail::toggle<port::D, _pins...>();
  detail::toggle<port::E, _pins...>();
  detail::toggle<port::F, _pins...>();
  detail::toggle<port::G, _pins...>();
  detail::toggle<port::H, _pins...>();
  detail::toggle<port::I, _pins...>();
  detail::toggle<port::J, _pins...>();
  detail::toggle<port::K, _pins...>();
}

/**
 * @brief Set port output state
 *
 * @tparam _port - GPIO port
 * @param  val   - bits to set on port
*/
template<port _port>
lmcu_inline void set(uint32_t val) { detail::inst_t<_port>::ODR::set(val); }

/**
 * @brief Toggle port output state
 *
 * @tparam _port - GPIO port
*/
template<port _port>
lmcu_inline void toggle() { detail::inst_t<_port>::ODR::ref() ^= 0xffff; }

/**
 * @brief Returns current port or pin output state (ODR).
 *
 * @tparam _p - gpio port or pin
*/
template<typename _p>
lmcu_inline auto get()
{
  if constexpr(std::is_same_v<_p, port>) {
    return detail::inst_t<_p{}>::ODR::get();
  }
  else {
    return (detail::inst_t<_p::port>::ODR::get() & _p::mask) != 0;
  }
}

/**
 * @brief Reads input signal on the port or pin (IDR).
 *
 * @tparam _p - gpio port or pin
*/
template<typename _p>
lmcu_inline auto read()
{
  if constexpr(std::is_same_v<_p, port>) {
    return detail::inst_t<_p{}>::IDR::get();
  }
  else {
    return (detail::inst_t<_p::port>::IDR::get() & _p::mask) != 0;
  }
}

} // namespace lmcu::gpio
