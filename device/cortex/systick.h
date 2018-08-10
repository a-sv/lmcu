#pragma once
#include <lmcu/rcc>

namespace lmcu {
namespace systick {

enum class clk_source { cpu, ext };

enum class interrupt { disable, enable };

#include "detail/systick.h"

template<
  uint32_t _freq = 1000,
  interrupt _interrupt = interrupt::enable,
  clk_source _clk_source = clk_source::cpu
>
void configure() { detail::configure<_freq, _interrupt, _clk_source>(); }

static inline void enable() { detail::enable(); }

static inline void disable() { detail::disable(); }

static inline uint32_t value() { return detail::value(); }

} // namespace systick
} // namespace lmcu
