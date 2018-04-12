#pragma once
#include <lmcu/device>
#include "../../common/units.h"
#include "../../common/round.h"

namespace lmcu {
namespace rcc {

enum class osc_type
{
  hse        = 1 << 0,
  hse_bypass = 1 << 1,
  hsi        = 1 << 2,
  lse        = 1 << 3,
  lse_bypass = 1 << 4,
  lsi        = 1 << 5
};

// clock security system
enum class css { disabled, enabled };

enum class sysclk_mux { hsi, hse, pllclk };

enum class rtcclk_mux { disabled, hse, lse, lsi };

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

constexpr osc_type operator |(osc_type lhs, osc_type rhs)
{
  return static_cast<osc_type>( static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs) );
}

constexpr bool operator &(osc_type lhs, osc_type rhs)
{
  return (static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs)) != 0;
}

#include "detail/rcc.h"

inline uint32_t system_clock() { return detail::system_clock; }
inline uint32_t hardware_clock() { return detail::hardware_clock; }
inline uint32_t apb1_clock() { return detail::apb1_clock; }
inline uint32_t apb2_clock() { return detail::apb2_clock; }
inline uint32_t adc_clock() { return detail::adc_clock; }

} // namespace rcc
} // namespace lmcu
