#include <lmcu/device>
#include "sysinit.h"

#if defined(_LMCU_DEVICE_STM32_)

namespace lmcu::detail {

void read_device_signature();

void sysinit_low_freq_stage()
{
  // read device unique id and flash size (uid.cc)
  read_device_signature();

  // enable cortex DWT cycles counter
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL        |= DWT_CTRL_CYCCNTENA_Msk;

  //
  // NVIC config
  //

  NVIC_SetPriorityGrouping(3);
  auto ip = NVIC_EncodePriority(3, 0, 0);

  // MemoryManagement_IRQn interrupt configuration
  NVIC_SetPriority(MemoryManagement_IRQn, ip);
  // BusFault_IRQn interrupt configuration
  NVIC_SetPriority(BusFault_IRQn, ip);
  // UsageFault_IRQn interrupt configuration
  NVIC_SetPriority(UsageFault_IRQn, ip);
  // SVCall_IRQn interrupt configuration
  NVIC_SetPriority(SVCall_IRQn, ip);
  // DebugMonitor_IRQn interrupt configuration
  NVIC_SetPriority(DebugMonitor_IRQn, ip);
  // PendSV_IRQn interrupt configuration
  NVIC_SetPriority(PendSV_IRQn, ip);
}

} // namespace lmcu::detail

#endif // _LMCU_DEVICE_STM32_
