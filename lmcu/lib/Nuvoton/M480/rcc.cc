#include <lmcu/dev/mcu>

#if defined(LMCU_M480)

#include <lmcu/common>

// ------------------------------------------------------------------------------------------------
namespace lmcu::rcc {
// ------------------------------------------------------------------------------------------------

uint32_t
  hardware_clock = 16_MHz
 ,pclk0_clock = 12_MHz
 ,pclk1_clock = 12_MHz
 ,systick_clock = 16_MHz
// ,adc_clock = 12_MHz
 ,pclk0_timers_clock = 12_MHz
 ,pclk1_timers_clock = 12_MHz
// ,usb_clock = 48_MHz
 ,hirc_clock = 12_MHz
 ,lxt_clock = 0
 ,hxt_clock = 0
 ,rtc_clock = 0
 ,pll_clock = 0
// ,i2s2_clock = 12_MHz
;

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::rcc
// ------------------------------------------------------------------------------------------------

#endif // defined(LMCU_M480)
