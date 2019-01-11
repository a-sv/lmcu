#pragma once
#include "../rcc.h"

namespace lmcu::rcc {

enum class adc_prediv
{
  disable, // ADC not used
  _2 = 2,
  _4 = 4,
  _6 = 6,
  _8 = 8
};

#include "detail/rcc.h"

} // namespace lmcu::rcc
