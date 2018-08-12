#pragma once
#include "../rcc.h"

namespace lmcu::rcc {

enum class adc_prediv
{
  disable, // ADC not used
  div_2 = 2,
  div_4 = 4,
  div_6 = 6,
  div_8 = 8
};

#include "detail/rcc.h"

} // namespace lmcu::rcc
