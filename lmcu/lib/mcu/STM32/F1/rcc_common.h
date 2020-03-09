#pragma once
#include "../rcc.h"

namespace lmcu::rcc {

enum class adc_div
{
  disable, // ADC not used
  _2 = 2,
  _4 = 4,
  _6 = 6,
  _8 = 8
};

namespace detail {

extern uint32_t
  mco_clock,
  apb1_timers_clock,
  apb2_timers_clock,
  usb_clock,
  i2s2_clock,
  i2s3_clock
;

} // namespace detail

namespace clock {

lmcu_inline uint32_t mco() { return detail::mco_clock; }

lmcu_inline uint32_t apb1_timers() { return detail::apb1_timers_clock; }

lmcu_inline uint32_t apb2_timers() { return detail::apb2_timers_clock; }

#if !defined(LMCU_STM32F100) && !defined(LMCU_STM32F101)

lmcu_inline uint32_t usb() { return detail::usb_clock; }

#endif

#if defined(LMCU_STM32F1_HIGH_DENSITY) || defined(LMCU_STM32F1_XL_DENSITY) || \
    defined(LMCU_STM32F1_CONNECTIVITY)

lmcu_inline uint32_t i2s2() { return detail::i2s2_clock; }

lmcu_inline uint32_t i2s3() { return detail::i2s3_clock; }

#endif

} // namespace clock

} // namespace lmcu::rcc
