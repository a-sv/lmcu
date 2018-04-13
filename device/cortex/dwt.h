#pragma once

namespace dwt {

/**
 * @brief Enables cortex DWT cycles counter
*/
inline void enable_cyccnt()
{
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL        |= DWT_CTRL_CYCCNTENA_Msk;
}

} // namespace dwt
