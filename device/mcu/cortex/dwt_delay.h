#pragma once
#include <type_traits>
#include <lmcu/delay>

namespace lmcu::delay {

lmcu_force_inline uint32_t start() { return (0xffffffff - DWT->CYCCNT) + 1; }

/**
 * @brief Delay in cycles.
 * @param cyc: cycles to wait
*/
lmcu_force_inline void cyc(const uint32_t cyc)
{
  const uint32_t ovf = start();
  while(cyc > (DWT->CYCCNT + ovf))
    ;
}

/**
 * @brief Delay in cycles with timeout.
 * @param cyc: cycles to wait
 * @param t  : timeout
 *
 * @return 'false' if timeout occured, else 'true'
*/
lmcu_force_inline bool cyc(const uint32_t cyc, const expirable &t)
{
  const uint32_t ovf = start();
  while(cyc > (DWT->CYCCNT + ovf)) {
    if(t.expired()) { return false; }
  }
  return true;
}

/**
 * @brief Delay in nanoseconds.
 * @param ns: nanoseconds to wait
*/
lmcu_force_inline void ns(const uint32_t ns)
{
  uint32_t n = to_cycles<units::ns>(ns);
  if(!__builtin_usubl_overflow(n, 8, &n)) { cyc(n); }
}

/**
 * @brief Delay in nanoseconds with timeout.
 * @param ns: nanoseconds to wait
 * @param t : timeout
 *
 * @return 'false' if timeout occured, else 'true'
*/
lmcu_force_inline bool ns(const uint32_t ns, const expirable &t)
{
  uint32_t n = to_cycles<units::ns>(ns);
  if(!__builtin_usubl_overflow(n, 8, &n)) {
    if(!cyc(n, t)) { return false; }
  }
  return true;
}

/**
 * @brief Delay in microseconds.
 * @param us: microsecond to wait
 *
 * @note IMPORTANT: max_delay = (0xffffffff / f_cpu) * 1e6
*/
lmcu_force_inline void us(const uint32_t us)
{
  uint32_t n = to_cycles<units::us>(us);
  if(!__builtin_usubl_overflow(n, 8, &n)) { cyc(n); }
}

/**
 * @brief Delay in microseconds with timeout.
 * @param us: microsecond to wait
 * @param t : timeout
 *
 * @return 'false' if timeout occured, else 'true'
*/
lmcu_force_inline bool us(const uint32_t us, const expirable &t)
{
  uint32_t n = to_cycles<units::us>(us);
  if(!__builtin_usubl_overflow(n, 8, &n)) {
    if(!cyc(n, t)) { return false; }
  }
  return true;
}

/**
 * @brief Delay in millisecond.
 * @param ms: milliseconds to wait
*/
lmcu_force_inline void ms(const uint32_t ms)
{
  for(uint32_t n = 0; n < ms; n++) { us(1000); }
}

/**
 * @brief Delay in millisecond with timeout.
 * @param ms: milliseconds to wait
 * @param t : timeout
 *
 * @return 'false' if timeout occured, else 'true'
*/
lmcu_force_inline bool ms(const uint32_t ms, const expirable &t)
{
  for(uint32_t n = 0; n < ms; n++) {
    if(!us(1000, t)) { return false; }
  }
  return true;
}

/**
 * @brief Delay in seconds.
 * @param sec: seconds to wait
*/
lmcu_force_inline void sec(const uint32_t sec)
{
  for(uint32_t n = 0; n < sec; n++) { us(1000000); }
}

/**
 * @brief Delay in seconds with timeout.
 * @param sec: seconds to wait
 * @param t : timeout
 *
 * @return 'false' if timeout occured, else 'true'
*/
lmcu_force_inline bool sec(const uint32_t sec, const expirable &t)
{
  for(uint32_t n = 0; n < sec; n++) {
    if(!us(1000000, t)) { return false; }
  }
  return true;
}

namespace dwt {

class timer : public expirable
{
public:
  template<units _units>
  void start(uint32_t t)
  {
    if constexpr(_units == units::cyc) {
      expire_ = t;
    }
    else {
      expire_ = to_cycles<_units>(t);
      if(__builtin_usubl_overflow(expire_, 8, &expire_)) { expire_ = 0; }
    }
    start_ = delay::start();
  }

  inline bool expired() const final
  {
    if((DWT->CYCCNT + start_) >= expire_) { return true; }
    yield();
    return false;
  }

  template<units _units>
  uint32_t elapsed() const
  {
    const uint32_t _cyc = DWT->CYCCNT + start_;
    if constexpr(_units == units::cyc) { return _cyc; }
    const uint32_t _us = _cyc / (rcc::system_clock() / 1_MHz);
    if constexpr(_units == units::us) { return _us;        }
    if constexpr(_units == units::ms) { return _us / 1000; }
    return _us / 1000000;
  }

  template<units _units>
  uint32_t remain() const
  {
    const uint32_t _cyc = DWT->CYCCNT + start_;
    if(_cyc >= expire_) { return 0; }
    if constexpr(_units == units::cyc) { return expire_ - _cyc; }
    const uint32_t _us = (expire_ - _cyc) / (rcc::system_clock() / 1_MHz);
    if constexpr(_units == units::us) { return _us;        }
    if constexpr(_units == units::ms) { return _us / 1000; }
    return _us / 1000000;
  }
private:
  uint32_t start_ = 0, expire_ = 0;
};

} // namespace dwt

} // namespace lmcu::delay
