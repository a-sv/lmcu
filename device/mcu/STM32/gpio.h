#pragma once
#include <lmcu/device>
#include <lmcu/hwi/common>

namespace lmcu::gpio {

enum class port {
#if defined(GPIOA)
  A,
#endif

#if defined(GPIOB)
  B,
#endif

#if defined(GPIOC)
  C,
#endif

#if defined(GPIOD)
  D,
#endif

#if defined(GPIOE)
  E,
#endif

#if defined(GPIOF)
  F,
#endif

#if defined(GPIOG)
  G,
#endif

#if defined(GPIOH)
  H,
#endif

#if defined(GPIOI)
  I,
#endif

#if defined(GPIOJ)
  J,
#endif

#if defined(GPIOK)
  K
#endif
};

enum class mode
{
  input,
  output_open_drain,
  output_push_pull,
  analog,
#if defined(_LMCU_DEVICE_STM32F4_)
  af_input,
#endif
  af_open_drain,
  af_push_pull
};

enum class pull
{
  no_pull,
  up,
  down
};

enum class speed
{
  low,
  medium,
  high,
  very_high
};

// not connected pin
struct not_connected
{
  static constexpr auto module_type = lmcu::module_type::gpio_pin;
  static constexpr auto nc          = true;
};

template<port _port, uint16_t _bit, mode _mode, pull _pull, speed _speed>
struct pin
{
  static constexpr auto module_type = lmcu::module_type::gpio_pin;
  static constexpr auto port        = _port;
  static constexpr auto bit         = _bit;
  static constexpr auto mask        = 1 << _bit;
  static constexpr auto mode        = _mode;
  static constexpr auto pull        = _pull;
  static constexpr auto speed       = _speed;
  static constexpr auto nc          = false;
};

#include "detail/gpio.h"

template<typename ..._pins>
void configure()
{
  static_assert(sizeof...(_pins), "requires at least 1 argument");
  detail::configure<_pins...>();
}

template<bool _val, typename ..._pins>
void set() { detail::set<_val, _pins...>(); }

template<typename ..._pins>
void set(bool val) { detail::set<_pins...>(val); }

template<port _port>
auto &get() { return detail::get<_port>(); }

template<port _port, uint8_t _first, uint8_t ..._bits>
auto get() { return get<_port>() & detail::mask<_first, _bits...>(); }

template<typename _pin, typename = decltype(_pin::port, _pin::mask)>
bool get() { return (get<_pin::port>() & _pin::mask) != 0; }

template<port _port>
auto &read() { return detail::read<_port>(); }

template<port _port, uint8_t _first, uint8_t ..._bits>
auto read() { return read<_port>() & detail::mask<_first, _bits...>(); }

template<typename _pin, typename = decltype(_pin::port, _pin::mask)>
bool read()
{
  static_assert(_pin::mode == mode::input, "pin must be configured as input");
  return (read<_pin::port>() & _pin::mask) != 0;
}

template<port _port, uint8_t _first, uint8_t ..._pins>
void toggle() { get<_port>() ^= detail::mask<_first, _pins...>(); }

template<typename ..._pins>
void toggle() { detail::toggle<_pins...>(); }

} // namespace lmcu::gpio
