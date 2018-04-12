#pragma once

namespace detail {

template<uint32_t r, port arg1, port ...args>
constexpr auto rcc_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(arg1 == port::A) { return r | RCC_AHB1ENR_GPIOAEN; }
    if constexpr(arg1 == port::B) { return r | RCC_AHB1ENR_GPIOBEN; }
    if constexpr(arg1 == port::C) { return r | RCC_AHB1ENR_GPIOCEN; }
    if constexpr(arg1 == port::D) { return r | RCC_AHB1ENR_GPIODEN; }
    if constexpr(arg1 == port::E) { return r | RCC_AHB1ENR_GPIOEEN; }
    if constexpr(arg1 == port::F) { return r | RCC_AHB1ENR_GPIOFEN; }
    if constexpr(arg1 == port::G) { return r | RCC_AHB1ENR_GPIOGEN; }
    if constexpr(arg1 == port::H) { return r | RCC_AHB1ENR_GPIOHEN; }
    if constexpr(arg1 == port::I) { return r | RCC_AHB1ENR_GPIOIEN; }
    if constexpr(arg1 == port::J) { return r | RCC_AHB1ENR_GPIOJEN; }
    if constexpr(arg1 == port::K) { return r | RCC_AHB1ENR_GPIOKEN; }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return rcc_bits<bits(), args...>(); }
  return bits();
}

} // namespace detail
