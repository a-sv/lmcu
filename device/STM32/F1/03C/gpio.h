#pragma once
#include "../gpio.h"

namespace lmcu {
namespace gpio {

lmcu_gpio_pin(A,0, );
lmcu_gpio_pin(A,1, );
lmcu_gpio_pin(A,2, );
lmcu_gpio_pin(A,3, );
lmcu_gpio_pin(A,4, );
lmcu_gpio_pin(A,5, );
lmcu_gpio_pin(A,6, );
lmcu_gpio_pin(A,7, );
lmcu_gpio_pin(A,8, );
lmcu_gpio_pin(A,9, );
lmcu_gpio_pin(A,10,);
lmcu_gpio_pin(A,11,);
lmcu_gpio_pin(A,12,);
lmcu_gpio_pin(A,13,);
lmcu_gpio_pin(A,14,);
lmcu_gpio_pin(A,15,);

lmcu_gpio_pin(B,0, );
lmcu_gpio_pin(B,1, );
lmcu_gpio_pin(B,2, );
lmcu_gpio_pin(B,3, );
lmcu_gpio_pin(B,4, );
lmcu_gpio_pin(B,5, );
lmcu_gpio_pin(B,6, );
lmcu_gpio_pin(B,7, );
lmcu_gpio_pin(B,8, );
lmcu_gpio_pin(B,9, );
lmcu_gpio_pin(B,10,);
lmcu_gpio_pin(B,11,);
lmcu_gpio_pin(B,12,);
lmcu_gpio_pin(B,13,);
lmcu_gpio_pin(B,14,);
lmcu_gpio_pin(B,15,);

lmcu_gpio_pin(C,13,);
lmcu_gpio_pin(C,14,);
lmcu_gpio_pin(C,15,);

namespace detail {

template<uint32_t r, port arg1, port ...args>
constexpr auto rcc_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(arg1 == port::A) { return r | RCC_APB2ENR_IOPAEN; }
    if constexpr(arg1 == port::B) { return r | RCC_APB2ENR_IOPBEN; }
    if constexpr(arg1 == port::C) { return r | RCC_APB2ENR_IOPCEN; }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return rcc_bits<bits(), args...>(); }
  return bits();
}

} // namespace detail

template<port ...args>
void enable() { RCC->APB2ENR |= detail::rcc_bits<0, args...>(); }

template<port ...args>
void disable() { RCC->APB2ENR &= ~detail::rcc_bits<0, args...>(); }

} // namespace gpio
} // namespace lmcu
