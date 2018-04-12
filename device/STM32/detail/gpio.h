#pragma once

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

template<port _port, typename ...args>
void configure(GPIO_TypeDef *inst);

} // namespace detail
