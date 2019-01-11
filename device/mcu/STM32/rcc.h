#pragma once
#include <lmcu/device>
#include <lmcu/hwi/common>
#include "detail/sysinit.h"

namespace lmcu::rcc {

enum class osc_type : uint32_t
{
  lmcu_flags_object,

  hse        = 1 << 0,
  hse_bypass = 1 << 1,
  hsi        = 1 << 2,
  lse        = 1 << 3,
  lse_bypass = 1 << 4,
  lsi        = 1 << 5
};

// clock security system
enum class css { disable, enable };

enum class sysclk_mux { hsi, hse, pllclk };

enum class rtcclk_mux { disable, hse, lse, lsi };

enum class ahb_prediv
{
  div_1   = 1,
  div_2   = 2,
  div_4   = 4,
  div_8   = 8,
  div_16  = 16,
  div_64  = 64,
  div_128 = 128,
  div_256 = 256,
  div_512 = 512
};

enum class apb1_prediv
{
  div_1  = 1,
  div_2  = 2,
  div_4  = 4,
  div_8  = 8,
  div_16 = 16
};
using apb2_prediv = apb1_prediv;

#include "detail/rcc.h"

static inline uint32_t system_clock() { return detail::system_clock; }
static inline uint32_t hardware_clock() { return detail::hardware_clock; }
static inline uint32_t apb1_clock() { return detail::apb1_clock; }
static inline uint32_t apb2_clock() { return detail::apb2_clock; }
static inline uint32_t adc_clock() { return detail::adc_clock; }
static inline uint32_t apb1_timer_clock() { return detail::apb1_timer_clock; }
static inline uint32_t apb2_timer_clock() { return detail::apb2_timer_clock; }

} // namespace lmcu::rcc

