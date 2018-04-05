#pragma once
#include <lmcu/rcc>

namespace lmcu {
namespace delay {

template<uint32_t _us>
void us()
{
  const uint32_t cyccnt = (rcc::detail::system_clock / 1000000) * _us;

  CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk; // enable DWT
  DWT->CTRL        &= ~DWT_CTRL_CYCCNTENA_Msk; // stop DWT
  DWT->CYCCNT       =  0;
  DWT->CTRL        |=  DWT_CTRL_CYCCNTENA_Msk; // start

  while(DWT->CYCCNT < cyccnt)
    ;
}

template<uint32_t _ms>
void ms()
{
  for(uint32_t n = 0; n < _ms; n++) { us<1000>(); }
}

} // namespace delay
} // namespace lmcu
