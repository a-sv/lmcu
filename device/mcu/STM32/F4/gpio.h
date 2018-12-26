#pragma once
#include "../gpio.h"

namespace lmcu::gpio {

#include "detail/gpio.h"

template<port ..._ports>
void enable() { RCC->AHB1ENR  |=  detail::rcc_bits<_ports...>(); }

template<port ..._ports>
void disable() { RCC->AHB1ENR &= ~detail::rcc_bits<_ports...>(); }

} // namespace lmcu::gpio
