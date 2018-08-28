#pragma once

namespace detail {

template<uint32_t _freq, typename _irq, clk_source _clk_source>
inline void configure()
{
  if constexpr(_irq::irq_type != nvic::irq_type::disable) {
    nvic::enable_irq<_irq, SysTick_IRQn>();
  }

  if constexpr(_clk_source == clk_source::cpu) {
    const auto r = rcc::system_clock() / _freq - 1;
    SysTick->LOAD = r;
    SysTick->VAL  = r;
  }
  else {
    SysTick->LOAD = _freq;
    SysTick->VAL  = _freq;
  }

  SysTick->CTRL =
    (_irq::irq_type != nvic::irq_type::disable? SysTick_CTRL_TICKINT_Msk : 0) |
    (_clk_source == clk_source::cpu? SysTick_CTRL_CLKSOURCE_Msk : 0)
  ;
}

lmcu_force_inline void enable() { SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; }

lmcu_force_inline void disable() { SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; }

lmcu_force_inline uint32_t value() { return SysTick->VAL; }

} // namespace detail
