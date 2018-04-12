#pragma once

namespace detail {

extern uint32_t system_clock;
extern uint32_t hardware_clock;
extern uint32_t apb1_clock;
extern uint32_t apb2_clock;
extern uint32_t adc_clock;

inline void preinit()
{
  // enable DWT for delay support
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
}

} // namespace detail
