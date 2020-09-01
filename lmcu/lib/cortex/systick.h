#pragma once
#include <lmcu/dev/mcu>
#include <lmcu/dev/cortex/nvic>
#include <lmcu/common>
#include <lmcu/rcc>
#include <lmcu/irq>

// ------------------------------------------------------------------------------------------------
namespace lmcu::systick {
// ------------------------------------------------------------------------------------------------
#include <lmcu/private/irq_id.h>

template<auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();

struct freq
{
  uint32_t
  ip = 1000, // Integer part
  fp = 0     // Fract part
  ;
};

enum class reload : uint32_t {};

template<auto ..._args>
struct config
{
  // Counting frequency
  // NOTICE:
  //   (systick_clock * 1000) / (freq.ip * 1000 + freq.fp) - 1 must be <= 0xffffff
  static constexpr auto freq = option::get<systick::freq, _args...>(systick::freq{});
  // SysTick reload value (if given will be used instead 'freq')
  static constexpr auto reload = option::get_u<systick::reload, _args...>();
  // Enable SysTick interrupt
  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(option::check<
    std::tuple<
      systick::freq,
      systick::reload,
      irq_id::_0
    >,
    _args...
  >());
};

/**
 * @brief Enable module clock
*/
void on() { device::NVIC::STCSR::set_b(device::NVIC::STCSR::ENABLE); }

/**
 * @brief Disable module clock
*/
void off() { device::NVIC::STCSR::clr_b(device::NVIC::STCSR::ENABLE); }

/**
 * @brief Apply module config
*/
template<typename _cfg>
void configure()
{
  using namespace device;

  if constexpr(!option::is_null<_cfg::irq>()) {
    nvic::set_encoded_priority<device::irqn::sys_tick, _cfg::irq>();
  }

  const uint32_t r = []
  {
    if constexpr(option::is_null<_cfg::reload>()) {
      if constexpr(_cfg::freq.fp == 0) {
        return rcc::clock::systick() / _cfg::freq.ip - 1;
      }
      else {
        return (uint64_t(rcc::clock::systick()) * 1000) /
               (uint64_t(_cfg::freq.ip) * 1000 + _cfg::freq.fp) - 1;
      }
    }
    else {
      return _cfg::reload;
    }
  }();

  NVIC::STRVR::set(r & NVIC::STRVR::RELOAD_MASK);
  NVIC::STCVR::set(r & NVIC::STCVR::CURRENT_MASK);
  NVIC::STCSR::set_b(option::is_null<_cfg::irq>()? 0 : NVIC::STCSR::TICKINT);
}

lmcu_static_inline uint32_t value() { return device::NVIC::STCVR::get(); }

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::systick
// ------------------------------------------------------------------------------------------------
