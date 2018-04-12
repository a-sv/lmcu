#pragma once
#include "../gpio.h"

namespace lmcu {
namespace gpio {

#include "detail/gpio.h"

template<port ...args>
void enable(bool afio = false)
{
  constexpr auto rcc_bits = []() -> uint32_t
  {
    if constexpr(sizeof...(args) > 0) { return detail::rcc_bits<0, args...>(); }
    return 0;
  }();

  RCC->APB2ENR |= rcc_bits | (afio? RCC_APB2ENR_AFIOEN : 0);
}

template<port ...args>
void disable(bool afio = true)
{
  constexpr auto rcc_bits = []() -> uint32_t
  {
    if constexpr(sizeof...(args) > 0) { return detail::rcc_bits<0, args...>(); }
    return 0;
  }();

  RCC->APB2ENR &= ~(rcc_bits | (afio? RCC_APB2ENR_AFIOEN : 0));
}

} // namespace gpio
} // namespace lmcu
