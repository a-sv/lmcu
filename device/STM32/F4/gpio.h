#pragma once
#include "../gpio.h"

namespace lmcu::gpio {

#include "detail/gpio.h"

template<port ...args>
void enable() { RCC->AHB1ENR |= detail::rcc_bits<0, args...>(); }

template<port ...args>
void disable() { RCC->AHB1ENR &= ~detail::rcc_bits<0, args...>(); }

} // namespace lmcu::gpio
