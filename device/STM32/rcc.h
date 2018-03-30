#pragma once
#include <lmcu/device>
#include <lmcu/units>

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
enum class css
{
  disabled,
  enabled
};

constexpr osc_type operator |(osc_type lhs, osc_type rhs)
{
  return static_cast<osc_type>( static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs) );
}

constexpr bool operator &(osc_type lhs, osc_type rhs)
{
  return (static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs)) != 0;
}

namespace detail {

extern uint32_t system_clock;
extern uint32_t hardware_clock;
extern uint32_t apb1_clock;
extern uint32_t apb2_clock;
extern uint32_t adc_clock;

} // namespace detail

} // namespace rcc
} // namespace lmcu
