#include "rcc.h"

namespace lmcu {
namespace rcc {

namespace detail {

uint32_t system_clock   = 0;
uint32_t hardware_clock = 0;
uint32_t apb1_clock     = 0;
uint32_t apb2_clock     = 0;
uint32_t adc_clock      = 0;

} // namespace detail

} // namespace rcc
} // namespace lmcu

extern "C" {

uint32_t lmcu_system_clock()   {  return lmcu::rcc::detail::system_clock;  }
uint32_t lmcu_hardware_clock() { return lmcu::rcc::detail::hardware_clock; }
uint32_t lmcu_apb1_clock()     { return lmcu::rcc::detail::apb1_clock;     }
uint32_t lmcu_apb2_clock()     { return lmcu::rcc::detail::apb2_clock;     }
uint32_t lmcu_adc_clock()      { return lmcu::rcc::detail::adc_clock;      }

} // extern "C"
