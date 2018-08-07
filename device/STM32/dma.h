#pragma once
#include <lmcu/device>
#include "../../common/def.h"

namespace lmcu {
namespace dma {

enum class module_id
{
#if defined(DMA1)
  dma1,
#endif

#if defined(DMA2)
  dma2
#endif
};

enum class mode { mem_mem, mem_periph };

enum class prio { low, medium, high, very_high };

enum class mem_word { _8bit, _16bit, _32bit };

enum class periph_word { _8bit, _16bit, _32bit };

enum class mem_inc { enable, disable };

enum class periph_inc { enable, disable };

enum class circular { enable, disable };

enum class dir { read_periph, read_mem };

enum class channel { ch1, ch2, ch3, ch4, ch5, ch6, ch7 };

namespace nvic {

enum class irq_type { disable, chi };

constexpr auto default_prio_group = 5;

} // namespace nvic
#include "../cortex/nvic.h"

enum class event
{
  cte = 1 << 0, // Channel transfer error
  cht = 1 << 1, // Channel half transfer
  cct = 1 << 2, // Channel complete transfer
  cgi = 1 << 3, // Channel global int
};
lmcu_enum_class_flags_impl(event)

template<
  module_id _module_id,
  channel _channel,
  mode _mode = mode::mem_periph,
  mem_word _mem_word = mem_word::_8bit,
  periph_word _periph_word = periph_word::_8bit,
  mem_inc _mem_inc = mem_inc::enable,
  periph_inc _periph_inc = periph_inc::disable,
  dir _dir = dir::read_periph,
  circular _circular = circular::disable,
  prio _prio = prio::low,
  typename _irq = nvic::irq<nvic::irq_type::disable>
>
struct module
{
  static constexpr auto module_id   = _module_id;
  static constexpr auto channel     = _channel;
  static constexpr auto mode        = _mode;
  static constexpr auto mem_word    = _mem_word;
  static constexpr auto periph_word = _periph_word;
  static constexpr auto mem_inc     = _mem_inc;
  static constexpr auto periph_inc  = _periph_inc;
  static constexpr auto dir         = _dir;
  static constexpr auto circular    = _circular;
  static constexpr auto prio        = _prio;
  static constexpr auto irq         = _irq();
};

#include "detail/dma.h"

template<typename ..._modules>
void configure() { detail::configure<_modules...>(); }

template<typename _module>
void stop() { detail::stop<_module>(); }

template<typename _module, typename _src, typename _dst>
void start(_src&& src, _dst&& dst, uint16_t size) { detail::start<_module>(src, dst, size); }

template<typename _module, event ..._events>
void enable_events() { detail::enable_events<_module, _events...>(); }

template<typename _module, event ..._events>
void disable_events() { detail::disable_events<_module, _events...>(); }

template<typename _module>
event irq_source() { return detail::irq_source<_module>(); }

} // namespace dma
} // namespace lmcu
