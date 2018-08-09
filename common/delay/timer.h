#pragma once
#include <lmcu/device>
#include "expirable.h"
#include "../def.h"

namespace lmcu {
namespace delay {

class timer : public expirable
{
public:
  lmcu_force_inline void start(uint32_t delay)
  {
    start_  = (0xffffffff - counter_) + 1;
    expire_ = delay;
  }

  lmcu_force_inline bool expired() const final { return (counter_ + start_) >= expire_; }

  lmcu_force_inline uint32_t elapsed() const { return counter_ + start_; }

  lmcu_force_inline uint32_t remain() const { return expire_ - elapsed(); }

  static inline void tick() { counter_++; }
private:
  uint32_t start_ = 0, expire_ = 0;
  static volatile uint32_t counter_;
};

} // namespace delay
} // namespace lmcu
