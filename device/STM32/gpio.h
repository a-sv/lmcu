#pragma once

namespace gpio {

enum class port { A, B, C, D, E, F, G, H, I, J, K };

enum class mode
{
  input,
  output_open_drain,
  output_push_pull,
  analog,
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

#define lmcu_gpio_pin(name, n, ...) \
enum class P##name##n##_af : uint32_t { __VA_ARGS__ }; \
template< \
  mode _mode, \
  pull _pull = pull::no_pull, \
  speed _speed = speed::low, \
  P##name##n##_af _af = static_cast<P##name##n##_af>(0) \
> \
struct P##name##n : pin<port::name, n, _mode, _pull, _speed> \
{ \
  static constexpr auto af = _af; \
}

namespace detail {

template<port _port, typename pin, typename ...args>
constexpr bool has_port()
{
  if constexpr(sizeof...(args) > 0) {
    return (pin().port == _port)? true : has_port<_port, args...>();
  }
  return pin().port == _port;
}

template<port _port, uint8_t min_bit, uint8_t max_bit, typename pin, typename ...args>
constexpr bool pin_in_range()
{
  constexpr auto check = []
  {
    return (pin().port == _port) && (pin().bit >= min_bit) && (pin().bit <= max_bit);
  };

  if constexpr(sizeof...(args) > 0) {
    return check()? true : pin_in_range<_port, min_bit, max_bit, args...>();
  }

  return check();
}

template<uint32_t r, uint8_t n, port _port, uint8_t bit_ofs, uint8_t min_bit, uint8_t max_bit,
         typename pin, typename ...args>
constexpr auto mask()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr((pin().port == _port) && (pin().bit >= min_bit) && (pin().bit <= max_bit)) {
      return r | ((0xFFFFFFFF >> (32 - n)) << ((pin().bit - bit_ofs) * n));
    }
    return r;
  };

  if constexpr(sizeof...(args) > 0) {
    return mask<bits(), n, _port, bit_ofs, min_bit, max_bit, args...>();
  }

  return bits();
}

template<uint32_t r, uint8_t bit, uint8_t ...args>
constexpr auto mask()
{
  if constexpr(sizeof...(args) > 0) { return mask<r | (1 << bit), args...>(); }
  return r | (1 << bit);
}

} // namespace detail

template<bool val, typename ...args>
void set()
{
  if constexpr(detail::has_port<port::A, args...>()) {
    GPIOA->BSRR = detail::mask<0, 1, port::A, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::B, args...>()) {
    GPIOB->BSRR = detail::mask<0, 1, port::B, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::C, args...>()) {
    GPIOC->BSRR = detail::mask<0, 1, port::C, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::D, args...>()) {
    GPIOD->BSRR = detail::mask<0, 1, port::D, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::E, args...>()) {
    GPIOE->BSRR = detail::mask<0, 1, port::E, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::F, args...>()) {
    GPIOF->BSRR = detail::mask<0, 1, port::F, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::G, args...>()) {
    GPIOG->BSRR = detail::mask<0, 1, port::G, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::H, args...>()) {
    GPIOH->BSRR = detail::mask<0, 1, port::H, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::I, args...>()) {
    GPIOI->BSRR = detail::mask<0, 1, port::I, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::J, args...>()) {
    GPIOJ->BSRR = detail::mask<0, 1, port::J, 0, 0, 15, args...>() << (val? 0 : 16);
  }

  if constexpr(detail::has_port<port::K, args...>()) {
    GPIOK->BSRR = detail::mask<0, 1, port::K, 0, 0, 15, args...>() << (val? 0 : 16);
  }
}

template<port _port>
auto &get()
{
  if constexpr(_port == port::A) { return GPIOA->ODR; }
  if constexpr(_port == port::B) { return GPIOB->ODR; }
  if constexpr(_port == port::C) { return GPIOC->ODR; }
  if constexpr(_port == port::D) { return GPIOD->ODR; }
  if constexpr(_port == port::E) { return GPIOE->ODR; }
  if constexpr(_port == port::F) { return GPIOF->ODR; }
  if constexpr(_port == port::G) { return GPIOG->ODR; }
  if constexpr(_port == port::H) { return GPIOH->ODR; }
  if constexpr(_port == port::I) { return GPIOI->ODR; }
  if constexpr(_port == port::J) { return GPIOJ->ODR; }
  if constexpr(_port == port::K) { return GPIOK->ODR; }
}

template<port _port, uint8_t bit, uint8_t ...bits>
auto get() { return get<_port>() & detail::mask<0, bit, bits...>(); }

template<typename pin>
bool get() { return (get<pin().port>() & pin().mask) != 0; }

template<port _port>
auto &read()
{
  if constexpr(_port == port::A) { return GPIOA->IDR; }
  if constexpr(_port == port::B) { return GPIOB->IDR; }
  if constexpr(_port == port::C) { return GPIOC->IDR; }
  if constexpr(_port == port::D) { return GPIOD->IDR; }
  if constexpr(_port == port::E) { return GPIOE->IDR; }
  if constexpr(_port == port::F) { return GPIOF->IDR; }
  if constexpr(_port == port::G) { return GPIOG->IDR; }
  if constexpr(_port == port::H) { return GPIOH->IDR; }
  if constexpr(_port == port::I) { return GPIOI->IDR; }
  if constexpr(_port == port::J) { return GPIOJ->IDR; }
  if constexpr(_port == port::K) { return GPIOK->IDR; }
}

template<port _port, uint8_t bit, uint8_t ...bits>
auto read() { return read<_port>() & detail::mask<0, bit, bits...>(); }

template<typename pin>
bool read() {
  static_assert(pin().mode == mode::input, "pin must be configured as input");
  return (read<pin().port>() & pin().mask) != 0;
}

template<port _port, uint8_t bit, uint8_t ...bits>
void toggle() { get<_port>() ^= detail::mask<0, bit, bits...>(); }

template<typename ...args>
void toggle()
{
  if constexpr(detail::has_port<port::A, args...>()) {
    get<port::A>() ^= detail::mask<0, 1, port::A, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::B, args...>()) {
    get<port::B>() ^= detail::mask<0, 1, port::B, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::C, args...>()) {
    get<port::C>() ^= detail::mask<0, 1, port::C, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::D, args...>()) {
    get<port::D>() ^= detail::mask<0, 1, port::D, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::E, args...>()) {
    get<port::E>() ^= detail::mask<0, 1, port::E, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::F, args...>()) {
    get<port::F>() ^= detail::mask<0, 1, port::F, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::G, args...>()) {
    get<port::G>() ^= detail::mask<0, 1, port::G, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::H, args...>()) {
    get<port::H>() ^= detail::mask<0, 1, port::H, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::I, args...>()) {
    get<port::I>() ^= detail::mask<0, 1, port::I, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::J, args...>()) {
    get<port::J>() ^= detail::mask<0, 1, port::J, 0, 0, 15, args...>();
  }

  if constexpr(detail::has_port<port::K, args...>()) {
    get<port::K>() ^= detail::mask<0, 1, port::K, 0, 0, 15, args...>();
  }
}

} // namespace gpio
