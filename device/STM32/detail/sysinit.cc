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
}

} // namespace lmcu::detail

#endif // _LMCU_DEVICE_STM32_
