#pragma once
#include <type_traits>
#include <limits>
#include <lmcu/rcc>
#include "expirable.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::delay {
// ------------------------------------------------------------------------------------------------

enum class units { cyc, ns, us, ms, sec };

/**
 * @brief Convert value in selected time units to count of CPU cycles
 *
 * @tparam _units  - value units
 * @tparam __value - value type
 *
 * @param clk      - clock (Hz)
 * @param val      - value in selected units to convert
 *
 * @return clock cycles
*/
template<units _units, typename _value>
lmcu_inline constexpr _value to_cycles(_value clk, _value val)
{
  static_assert(_units != units::cyc, "invalid param: units::cyc");
  static_assert(std::is_unsigned_v<_value>, "result type must be unsigned");

  const _value cyc_per_us = clk / 1_MHz;

  if constexpr(_units == units::ns) {
    const _value ns_per_cycle = ((10000 / cyc_per_us) + 5) / 10;
    return (((val * 10) / ns_per_cycle) + 5) / 10;
  }

  if constexpr(_units == units::us) { return cyc_per_us * val; }

  if constexpr(_units == units::ms) { return cyc_per_us * val * 1000; }

  return cyc_per_us * val * 1000000;
}

template <typename _counter_t = uint32_t>
class timer : public expirable
{
  static_assert(std::is_unsigned_v<_counter_t>, "timer counter type must be unsigned");
public:
  inline void start(uint32_t delay)
  {
    start_  = (std::numeric_limits<_counter_t>::max() - counter_) + 1;
    expire_ = delay;
  }

  inline bool expired() const final { return (counter_ + start_) >= expire_; }

  inline uint32_t elapsed() const { return counter_ + start_; }

  inline uint32_t remaining() const { return expire_ - elapsed(); }

  static inline void tick()
  {
    _counter_t cnt = counter_;
    counter_ = cnt + 1;
  }

  static inline _counter_t counter() { return counter_; }
private:
  _counter_t start_ = 0, expire_ = 0;
  static volatile _counter_t counter_;
};

using timer8  = timer<uint8_t>;
using timer16 = timer<uint16_t>;
using timer32 = timer<uint32_t>;
using timer64 = timer<uint64_t>;

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::delay
// ------------------------------------------------------------------------------------------------
