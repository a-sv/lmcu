#pragma once
#include <lmcu/device>

namespace lmcu {
namespace gpio {

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

template<port _port, uint16_t _bit, mode _mode, pull _pull, speed _speed>
struct pin
{
  static constexpr auto port  = _port;
  static constexpr auto bit   = _bit;
  static constexpr auto mask  = 1 << _bit;
  static constexpr auto mode  = _mode;
  static constexpr auto pull  = _pull;
  static constexpr auto speed = _speed;
};

#include "detail/gpio.h"

template<typename ...args>
void configure()
{
  static_assert(sizeof...(args), "requires at least 1 argument");
  detail::configure<args...>();
}

template<bool val, typename ...args>
void set() { detail::set<val, args...>(); }

template<port _port>
auto &get() { return detail::get<_port>(); }

template<port _port, uint8_t first, uint8_t ...bits>
auto get() { return get<_port>() & detail::mask<first, bits...>(); }

template<typename pin, typename = decltype(pin::port, pin::mask)>
bool get() { return (get<pin().port>() & pin().mask) != 0; }

template<port _port>
auto &read() { return detail::read<_port>(); }

template<port _port, uint8_t first, uint8_t ...bits>
auto read() { return read<_port>() & detail::mask<first, bits...>(); }

template<typename pin, typename = decltype(pin::port, pin::mask)>
bool read() {
  static_assert(pin().mode == mode::input, "pin must be configured as input");
  return (read<pin().port>() & pin().mask) != 0;
}

template<port _port, uint8_t first, uint8_t ...bits>
void toggle() { get<_port>() ^= detail::mask<first, bits...>(); }

template<typename ...args>
void toggle() { detail::toggle<args...>(); }

} // namespace gpio
} // namespace lmcu
