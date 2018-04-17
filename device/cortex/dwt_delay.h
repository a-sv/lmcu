#pragma once
#include <lmcu/rcc>
#include "../../common/def.h"

namespace lmcu {
namespace delay {

/**
 * @brief Constant delay in cycles.
 * @param _cyc: cycles to wait
*/
template<uint32_t _cyc>
lmcu_force_inline void cyc()
{
  const uint32_t ovf = (0xffffffff - DWT->CYCCNT) + 1;
  while(_cyc > (DWT->CYCCNT + ovf))
    ;
}

/**
 * @brief Dynamic delay in cycles.
 * @param cyc: cycles to wait
*/
lmcu_force_inline void cyc(const uint32_t cyc)
{
  const uint32_t ovf = (0xffffffff - DWT->CYCCNT) + 1;
  while(cyc > (DWT->CYCCNT + ovf))
    ;
}

/**
 * @brief Constant delay in microseconds.
 * @param _us: microsecond to wait
 *
 * @note  More precisely than the dynamic version.
 *        IMPORTANT: max_delay = (0xffffffff / f_cpu) * 1e6
*/
template<uint32_t _us>
lmcu_force_inline void us() { cyc((rcc::detail::system_clock / 1_MHz) * _us - 8); }

/**
 * @brief Dynamic delay in microseconds.
 * @param us: microseconds to wait
 *
 * @note  IMPORTANT: for max_delay see constant version.
*/
lmcu_force_inline void us(const uint32_t us) { cyc((rcc::detail::system_clock / 1_MHz) * us - 8); }

/**
 * @brief Delay in millisecond.
 * @param ms: milliseconds to wait
*/
lmcu_force_inline void ms(const uint32_t ms)
{
  for(uint32_t n = 0; n < ms; n++) { us<1000>(); }
}

/**
 * @brief Delay in seconds.
 * @param sec: seconds to wait
*/
lmcu_force_inline void sec(const uint32_t sec)
{
  for(uint32_t n = 0; n < sec; n++) { us<1000000>(); }
}

} // namespace delay
} // namespace lmcu
