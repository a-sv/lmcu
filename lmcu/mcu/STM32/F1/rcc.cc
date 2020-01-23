#include <lmcu/dev/mcu>

#if defined(LMCU_STM32F1)

#include <lmcu/hwi/common>

namespace lmcu::rcc::detail {

uint32_t
  hardware_clock = 8_MHz
 ,apb1_clock = 8_MHz
 ,apb2_clock = 8_MHz
 ,systick_clock = 8_MHz
 ,adc_clock = 8_MHz / 2
 ,apb1_timers_clock = 8_MHz
 ,apb2_timers_clock = 8_MHz
 ,usb_clock = 8_MHz
 ,mco_clock = 0
 ,rtc_clock = 0
 ,i2s2_clock = 8_MHz
 ,i2s3_clock = 8_MHz
;

} // namespace lmcu::rcc::detail

#endif // defined(LMCU_STM32F1)
