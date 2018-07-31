#pragma once

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

template<port _port, typename ...args>
void configure_port(GPIO_TypeDef *inst);

/**
 * Checks if one or more pins belongs to port
 *
 * @param _port - gpio port
 * @param _pin  - first pin in arglist
 * @param _pins - other pin's
 */
template<port _port, typename _pin, typename ..._pins>
constexpr bool pins_in_port()
{
  if constexpr(sizeof...(_pins) > 0) {
    return (_pin().port == _port) || pins_in_port<_port, _pins...>();
  }
  return _pin().port == _port;
}

/**
 * Checks the occurrence of a pin in the range
 *
 * @param _port    - gpio port
 * @param _min_bit - min pin bit
 * @param _max_bit - max pin bit
 * @param _pin     - first pin in arglist
 * @param _pins    - other pin's
 */
template<port _port, uint8_t _min_bit, uint8_t _max_bit, typename _pin, typename ..._pins>
constexpr bool pin_in_range()
{
  constexpr auto check = []
  {
    return (_pin().port == _port) && (_pin().bit >= _min_bit) && (_pin().bit <= _max_bit);
  };

  if constexpr(sizeof...(_pins) > 0) {
    return check() || pin_in_range<_port, _min_bit, _max_bit, _pins...>();
  }

  return check();
}

/**
 * Calc bit mask for port
 *
 * @param _port    - gpio port
 * @param _n       - bit field width
 * @param _bit_ofs - offset of port pin bit
 * @param _min_bit - min pin bit
 * @param _max_bit - max pin bit
 * @param _pin     - first pin in arglist
 * @param _pins    - other pin's
 *
 * @return bit mask
 */
template<port _port, uint8_t _n, uint8_t _bit_ofs, uint8_t _min_bit, uint8_t _max_bit,
         typename _pin, typename ..._pins>
constexpr auto mask()
{
  constexpr auto bits = []() -> uint32_t
  {
    if constexpr((_pin().port == _port) && (_pin().bit >= _min_bit) && (_pin().bit <= _max_bit)) {
      return (0xFFFFFFFF >> (32 - _n)) << ((_pin().bit - _bit_ofs) * _n);
    }
    return 0;
  };

  if constexpr(sizeof...(_pins) > 0) {
    return bits() | mask<_port, _n, _bit_ofs, _min_bit, _max_bit, _pins...>();
  }

  return bits();
}

template<uint8_t ...args>
constexpr auto mask() { return ((1 << args) | ...); }

template<typename ...args>
void configure()
{
#if defined(GPIOA)
  configure_port<port::A, args...>(GPIOA);
#endif

#if defined(GPIOB)
  configure_port<port::B, args...>(GPIOB);
#endif

#if defined(GPIOC)
  configure_port<port::C, args...>(GPIOC);
#endif

#if defined(GPIOD)
  configure_port<port::D, args...>(GPIOD);
#endif

#if defined(GPIOE)
  configure_port<port::E, args...>(GPIOE);
#endif

#if defined(GPIOF)
  configure_port<port::F, args...>(GPIOF);
#endif

#if defined(GPIOG)
  configure_port<port::G, args...>(GPIOG);
#endif

#if defined(GPIOH)
  configure_port<port::H, args...>(GPIOH);
#endif

#if defined(GPIOI)
  configure_port<port::I, args...>(GPIOI);
#endif

#if defined(GPIOJ)
  configure_port<port::J, args...>(GPIOJ);
#endif

#if defined(GPIOK)
  configure_port<port::K, args...>(GPIOK);
#endif
}

template<bool val, typename ...args>
void set()
{
#if defined(GPIOA)
  if constexpr(pins_in_port<port::A, args...>()) {
    GPIOA->BSRR = mask<port::A, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOB)
  if constexpr(pins_in_port<port::B, args...>()) {
    GPIOB->BSRR = mask<port::B, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOC)
  if constexpr(pins_in_port<port::C, args...>()) {
    GPIOC->BSRR = mask<port::C, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOD)
  if constexpr(pins_in_port<port::D, args...>()) {
    GPIOD->BSRR = mask<port::D, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOE)
  if constexpr(pins_in_port<port::E, args...>()) {
    GPIOE->BSRR = mask<port::E, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOF)
  if constexpr(pins_in_port<port::F, args...>()) {
    GPIOF->BSRR = mask<port::F, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOG)
  if constexpr(pins_in_port<port::G, args...>()) {
    GPIOG->BSRR = mask<port::G, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOH)
  if constexpr(pins_in_port<port::H, args...>()) {
    GPIOH->BSRR = mask<port::H, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOI)
  if constexpr(pins_in_port<port::I, args...>()) {
    GPIOI->BSRR = mask<port::I, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOJ)
  if constexpr(pins_in_port<port::J, args...>()) {
    GPIOJ->BSRR = mask<port::J, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOK)
  if constexpr(pins_in_port<port::K, args...>()) {
    GPIOK->BSRR = mask<port::K, 1, 0, 0, 15, args...>() << (val? 0 : 16);
  }
#endif
}

template<port _port>
auto &get()
{
#if defined(GPIOA)
  if constexpr(_port == port::A) { return GPIOA->ODR; }
#endif

#if defined(GPIOB)
  if constexpr(_port == port::B) { return GPIOB->ODR; }
#endif

#if defined(GPIOC)
  if constexpr(_port == port::C) { return GPIOC->ODR; }
#endif

#if defined(GPIOD)
  if constexpr(_port == port::D) { return GPIOD->ODR; }
#endif

#if defined(GPIOE)
  if constexpr(_port == port::E) { return GPIOE->ODR; }
#endif

#if defined(GPIOF)
  if constexpr(_port == port::F) { return GPIOF->ODR; }
#endif

#if defined(GPIOG)
  if constexpr(_port == port::G) { return GPIOG->ODR; }
#endif

#if defined(GPIOH)
  if constexpr(_port == port::H) { return GPIOH->ODR; }
#endif

#if defined(GPIOI)
  if constexpr(_port == port::I) { return GPIOI->ODR; }
#endif

#if defined(GPIOJ)
  if constexpr(_port == port::J) { return GPIOJ->ODR; }
#endif

#if defined(GPIOK)
  if constexpr(_port == port::K) { return GPIOK->ODR; }
#endif
}

template<port _port>
auto &read()
{
#if defined(GPIOA)
  if constexpr(_port == port::A) { return GPIOA->IDR; }
#endif

#if defined(GPIOB)
  if constexpr(_port == port::B) { return GPIOB->IDR; }
#endif

#if defined(GPIOC)
  if constexpr(_port == port::C) { return GPIOC->IDR; }
#endif

#if defined(GPIOD)
  if constexpr(_port == port::D) { return GPIOD->IDR; }
#endif

#if defined(GPIOE)
  if constexpr(_port == port::E) { return GPIOE->IDR; }
#endif

#if defined(GPIOF)
  if constexpr(_port == port::F) { return GPIOF->IDR; }
#endif

#if defined(GPIOG)
  if constexpr(_port == port::G) { return GPIOG->IDR; }
#endif

#if defined(GPIOH)
  if constexpr(_port == port::H) { return GPIOH->IDR; }
#endif

#if defined(GPIOI)
  if constexpr(_port == port::I) { return GPIOI->IDR; }
#endif

#if defined(GPIOJ)
  if constexpr(_port == port::J) { return GPIOJ->IDR; }
#endif

#if defined(GPIOK)
  if constexpr(_port == port::K) { return GPIOK->IDR; }
#endif
}

template<typename ...args>
void toggle()
{
#if defined(GPIOA)
  if constexpr(pins_in_port<port::A, args...>()) {
    get<port::A>() ^= mask<port::A, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOB)
  if constexpr(pins_in_port<port::B, args...>()) {
    get<port::B>() ^= mask<port::B, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOC)
  if constexpr(pins_in_port<port::C, args...>()) {
    get<port::C>() ^= mask<port::C, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOD)
  if constexpr(pins_in_port<port::D, args...>()) {
    get<port::D>() ^= mask<port::D, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOE)
  if constexpr(pins_in_port<port::E, args...>()) {
    get<port::E>() ^= mask<port::E, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOF)
  if constexpr(pins_in_port<port::F, args...>()) {
    get<port::F>() ^= mask<port::F, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOG)
  if constexpr(pins_in_port<port::G, args...>()) {
    get<port::G>() ^= mask<port::G, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOH)
  if constexpr(pins_in_port<port::H, args...>()) {
    get<port::H>() ^= mask<port::H, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOI)
  if constexpr(pins_in_port<port::I, args...>()) {
    get<port::I>() ^= mask<port::I, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOJ)
  if constexpr(pins_in_port<port::J, args...>()) {
    get<port::J>() ^= mask<port::J, 1, 0, 0, 15, args...>();
  }
#endif

#if defined(GPIOK)
  if constexpr(pins_in_port<port::K, args...>()) {
    get<port::K>() ^= mask<port::K, 1, 0, 0, 15, args...>();
  }
#endif
}

} // namespace detail
