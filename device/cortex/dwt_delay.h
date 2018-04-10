#pragma once
#include <lmcu/rcc>

namespace lmcu {
namespace delay {

// IMPORTANT: max_delay = (0xffffffff / f_cpu) * 1e6

template<uint32_t _us>
void us()
{
  const uint32_t delay = ((rcc::detail::system_clock / 1_MHz) * _us) - 8;
  const uint32_t ovf   = (0xffffffff - DWT->CYCCNT) + 1;
  while(delay > (DWT->CYCCNT + ovf))
    ;
}

template<uint32_t _ms>
void ms()
{
  for(uint32_t n = 0; n < _ms; n++) { us<1000>(); }
}

} // namespace delay
} // namespace lmcu
