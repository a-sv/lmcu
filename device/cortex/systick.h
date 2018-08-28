#pragma once
#include <lmcu/rcc>

namespace lmcu::systick {

enum class clk_source { cpu, ext };

//enum class interrupt { disable, enable };

namespace nvic {

enum class irq_type { disable, sysi };

constexpr auto default_prio_group = 3;

} // namespace nvic
#include "nvic.h"

#include "detail/systick.h"

template<
  uint32_t _freq = 1000,
  clk_source _clk_source = clk_source::cpu,
  typename _irq = nvic::irq<nvic::irq_type::sysi>
>
void configure() { detail::configure<_freq, _irq, _clk_source>(); }

static inline void enable() { detail::enable(); }

static inline void disable() { detail::disable(); }

static inline uint32_t value() { return detail::value(); }

} // namespace lmcu::systick
