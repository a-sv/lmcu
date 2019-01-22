#pragma once
#include <lmcu/rcc>
#include "expirable.h"

namespace lmcu::delay {

enum class units { cyc, ns, us, ms, sec };

template<units _units>
lmcu_force_inline uint32_t to_cycles(uint32_t val)
{
  static_assert(_units != units::cyc, "invalid param: units::cyc");

  const uint32_t cyc_per_us = rcc::system_clock() / 1_MHz;

  if constexpr(_units == units::ns) {
    const uint32_t ns_per_cycle = ((10000 / cyc_per_us) + 5) / 10;
    return (((val * 10) / ns_per_cycle) + 5) / 10;
  }

  if constexpr(_units == units::us) { return cyc_per_us * val; }

  if constexpr(_units == units::ms) { return cyc_per_us * val * 1000; }

  return cyc_per_us * val * 1000000;
}

class timer : public expirable
{
public:
  inline void start(uint32_t delay)
  {
    start_  = (0xffffffff - counter_) + 1;
    expire_ = delay;
  }

  inline bool expired() const final
  {
    if((counter_ + start_) >= expire_) { return true; }
    yield();
    return false;
  }

  inline uint32_t elapsed() const { return counter_ + start_; }

  inline uint32_t remain() const { return expire_ - elapsed(); }

  static inline void tick() { counter_++; }
private:
  uint32_t start_ = 0, expire_ = 0;
  static volatile uint32_t counter_;
};

} // namespace lmcu::delay
