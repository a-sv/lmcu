#pragma once
#include <lmcu/rcc>
#include "../../common/delay/expirable.h"
#include "../../common/def.h"

namespace lmcu {
namespace delay {

lmcu_force_inline uint32_t start() { return (0xffffffff - DWT->CYCCNT) + 1; }

/**
 * @brief Constant delay in cycles.
 * @param _cyc: cycles to wait
*/
template<uint32_t _cyc>
lmcu_force_inline void cyc()
{
  const uint32_t ovf = start();
  while(_cyc > (DWT->CYCCNT + ovf))
    ;
}

/**
 * @brief Dynamic delay in cycles.
 * @param cyc: cycles to wait
*/
lmcu_force_inline void cyc(const uint32_t cyc)
{
  const uint32_t ovf = start();
  while(cyc > (DWT->CYCCNT + ovf))
    ;
}

/**
 * @brief Constant delay in microseconds.
 * @param _us: microsecond to wait
 *
 * @note  More precisely than the dynamic version.
 *        IMPORTANT: max_delay = (0xffffffff / f_cpu) * 1e6
*/
template<uint32_t _us>
lmcu_force_inline void us() { cyc((rcc::detail::system_clock / 1_MHz) * _us - 8); }

/**
 * @brief Dynamic delay in microseconds.
 * @param us: microseconds to wait
 *
 * @note  IMPORTANT: for max_delay see constant version.
*/
lmcu_force_inline void us(const uint32_t us) { cyc((rcc::detail::system_clock / 1_MHz) * us - 8); }

/**
 * @brief Delay in millisecond.
 * @param ms: milliseconds to wait
*/
lmcu_force_inline void ms(const uint32_t ms)
{
  for(uint32_t n = 0; n < ms; n++) { us<1000>(); }
}

/**
 * @brief Delay in seconds.
 * @param sec: seconds to wait
*/
lmcu_force_inline void sec(const uint32_t sec)
{
  for(uint32_t n = 0; n < sec; n++) { us<1000000>(); }
}

namespace dwt {

class timer : public expirable
{
public:
  enum units { cyc, us, ms, sec };

  template<units _units>
  lmcu_force_inline void start(uint32_t t)
  {
    if constexpr(_units == units::cyc) {
      expire_ = t;
    }
    else
    if constexpr(_units == units::us) {
      expire_ = (rcc::detail::system_clock / 1_MHz) * t - 8;
    }
    else
    if constexpr(_units == units::ms) {
      expire_ = (rcc::detail::system_clock / 1_MHz) * t * 1000 - 8;
    }
    else {
      expire_ = (rcc::detail::system_clock / 1_MHz) * t * 1000000 - 8;
    }
    start_ = delay::start();
  }

  lmcu_force_inline bool expired() const final { return (DWT->CYCCNT + start_) >= expire_; }

  template<units _units>
  lmcu_force_inline uint32_t elapsed() const
  {
    const uint32_t _cyc = DWT->CYCCNT + start_;
    if constexpr(_units == units::cyc) { return _cyc; }
    const uint32_t _us = _cyc / (rcc::detail::system_clock / 1_MHz);
    if constexpr(_units == units::us) { return _us;        }
    if constexpr(_units == units::ms) { return _us / 1000; }
    return _us / 1000000;
  }

  template<units _units>
  lmcu_force_inline uint32_t remain() const
  {
    const uint32_t _cyc = DWT->CYCCNT + start_;
    if(_cyc >= expire_) { return 0; }
    if constexpr(_units == units::cyc) { return expire_ - _cyc; }
    const uint32_t _us = (expire_ - _cyc) / (rcc::detail::system_clock / 1_MHz);
    if constexpr(_units == units::us) { return _us;        }
    if constexpr(_units == units::ms) { return _us / 1000; }
    return _us / 1000000;
  }
private:
  uint32_t start_ = 0, expire_ = 0;
};

} // namespace dwt

} // namespace delay
} // namespace lmcu
