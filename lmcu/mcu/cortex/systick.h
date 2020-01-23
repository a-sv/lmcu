#pragma once
#include <lmcu/hwi/common>
#include <lmcu/rcc>
#include <lmcu/irq>
#include <lmcu/dev/mcu>
#include <lmcu/dev/nvic>

namespace lmcu::systick {

struct irq : nvic::irq_config {};

struct freq
{
  uint32_t
  ip = 1000, // Integer part
  fp = 0     // Fract part
  ;
};

enum class reload : uint32_t {};

template<auto ..._args>
struct module
{
  struct config
  {
    // Counting frequency
    // NOTICE:
    //   (systick_clock * 1000) / (freq.ip * 1000 + freq.fp) - 1 must be <= 0xffffff
    static constexpr auto freq = option::get<systick::freq, _args...>(systick::freq{});
    // SysTick reload value (if given will be used instead 'freq')
    static constexpr auto reload = option::get_u<systick::reload, _args...>();
    // Enable SysTick interrupt
    static constexpr auto irq = option::get<systick::irq, _args...>();

    static_assert(option::check<
      std::tuple<systick::freq, systick::reload, systick::irq>,
      _args...
    >());
  };

  /**
   * @brief Return current counter value
  */
  static inline uint32_t value();
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
template<typename _module>
void configure()
{
  using namespace device;
  using cfg = typename _module::config;

  if constexpr(!option::is_null<cfg::irq>()) {
    nvic::set_priority<device::irqn::sys_tick, cfg::irq>();
  }

  const uint32_t r = []
  {
    if constexpr(option::is_null<cfg::reload>()) {
      if constexpr(cfg::freq.fp == 0) {
        return rcc::detail::systick_clock / cfg::freq.ip - 1;
      }
      else {
        return (uint64_t(rcc::detail::systick_clock) * 1000) /
               (uint64_t(cfg::freq.ip) * 1000 + cfg::freq.fp) - 1;
      }
    }
    else {
      return cfg::reload;
    }
  }();

  NVIC::STRVR::set(r & NVIC::STRVR::RELOAD_MASK);
  NVIC::STCVR::set(r & NVIC::STCVR::CURRENT_MASK);
  NVIC::STCSR::set_b(option::is_null<cfg::irq>()? 0 : NVIC::STCSR::TICKINT);
}

template<auto ..._args>
uint32_t module<_args...>::value() { return device::NVIC::STCVR::get(); }

} // namespace lmcu::systick
