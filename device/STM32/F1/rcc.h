#pragma once
#include "../rcc.h"

namespace lmcu {
namespace rcc {

enum class adc_prediv
{
  disabled, // ADC not used
  div_2 = 2,
  div_4 = 4,
  div_6 = 6,
  div_8 = 8
};

#include "detail/rcc.h"

} // namespace rcc
} // namespace lmcu
