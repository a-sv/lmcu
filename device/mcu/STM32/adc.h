#pragma once
#include <lmcu/hwi/common>
#include <lmcu/rcc>
#include <lmcu/delay>

namespace lmcu::adc {

enum class module_id
{
#if defined(ADC1)
  adc1,
#endif

#if defined(ADC2)
  adc2,
#endif

#if defined(ADC3)
  adc3,
#endif

#if defined(ADC4)
  adc4
#endif
};

enum class dual_mode
{
  independent,
  regular_and_injected,
  regular_and_trigger,
  injected_and_fast_inter,
  injected_and_slow_inter,
  injected_only,
  regular_only,
  fast_inter_only,
  slow_inter_only,
  trigger_only
};

enum class inj_discont_mode { enable, disable };

enum class reg_discont_mode { enable, disable };

enum class inj_auto { enable, disable };

enum class scan { enable, disable };

enum class temp_refint { enable, disable };

enum class reg_trig
{
  disable,

#if defined(ADC1)
  tim1_cc1,
  tim1_cc2,
  tim1_cc3,
  tim2_cc2,
  tim3_trgo,
  tim4_cc4,
  exti11__tim8_trgo,
#endif

  sw_start,

#if defined(ADC3)
  tim3_cc1,
  tim2_cc3,
  tim1_cc3,
  tim8_cc1,
  tim8_trgo,
  tim5_cc1,
  tim5_cc3
#endif
};

enum class inj_trig
{
  disable,

  tim1_trgo,
  tim1_cc4,

#if defined(ADC1)
  tim2_trgo,
  tim2_cc1,
  tim3_cc4,
  tim4_trgo,
  exti15__tim8_cc4,
#endif

  jsw_start,

#if defined(ADC3)
  tim4_cc3,
  tim8_cc2,
  tim8_cc4,
  tim5_trgo,
  tim5_cc4
#endif
};

enum class data_align { left, right };

enum class disc_mode { enable, disable, regular, injected, regular_and_injected };

enum class disc_num { _1ch, _2ch, _3ch, _4ch, _5ch, _6ch, _7ch, _8ch };

enum class dma { enable, disable };

enum class sample_time
{
  _1_5cyc,
  _7_5cyc,
  _13_5cyc,
  _28_5cyc,
  _41_5cyc,
  _55_5cyc,
  _71_5cyc,
  _239_5cyc
};

namespace nvic {

enum class irq_type { disable, adci };

constexpr auto default_prio_group = 3;

} // namespace nvic
#include "../cortex/nvic.h"

template<
  module_id _module_id,
  data_align _data_align,
  scan _scan,
  disc_mode _disc_mode,
  disc_num _disc_num = disc_num::_1ch,
  reg_trig _reg_trig = reg_trig::sw_start,
  inj_trig _inj_trig = inj_trig::disable,
  inj_auto _inj_auto = inj_auto::disable,
  dma _dma = dma::disable,
  dual_mode _dual_mode = dual_mode::independent,
  temp_refint _temp_refint = temp_refint::disable,
  typename _irq = nvic::irq<nvic::irq_type::disable>
>
struct module
{
  static constexpr auto dev_class   = lmcu::dev_class::adc;
  static constexpr auto module_id   = _module_id;
  static constexpr auto data_align  = _data_align;
  static constexpr auto scan        = _scan;
  static constexpr auto disc_mode   = _disc_mode;
  static constexpr auto disc_num    = _disc_num;
  static constexpr auto reg_trig    = _reg_trig;
  static constexpr auto inj_trig    = _inj_trig;
  static constexpr auto inj_auto    = _inj_auto;
  static constexpr auto dma         = _dma;
  static constexpr auto dual_mode   = _dual_mode;
  static constexpr auto temp_refint = _temp_refint;
  static constexpr auto irq         = _irq();
};

template<typename _module, uint8_t _chan_num, sample_time _sample_time>
struct rchannel_conf
{
  static constexpr auto dev_class   = lmcu::dev_class::adc_reg_channel;
  static constexpr auto module      = _module();
  static constexpr auto chan_num    = _chan_num;
  static constexpr auto sample_time = _sample_time;
};

template<typename _module, uint8_t _chan_num, sample_time _sample_time, uint16_t _data_offset = 0>
struct jchannel_conf
{
  static constexpr auto dev_class   = lmcu::dev_class::adc_inj_channel;
  static constexpr auto module      = _module();
  static constexpr auto chan_num    = _chan_num;
  static constexpr auto sample_time = _sample_time;
  static constexpr auto data_offset = _data_offset;
};

enum class event : uint32_t
{
  lmcu_flags_object,

  awd    = 1 << 0, // analog watchdog
  eoc    = 1 << 1, // regular end of conversion
  jeoc   = 1 << 2, // injected channels end of conversion
  jstart = 1 << 3, // injected channel start flag
  start  = 1 << 4  // regular channel start flag
};

#include "detail/adc.h"

template<typename ..._args>
void configure()
{
  detail::adc_configure<_args...>();

#if defined(ADC1)
  detail::reg_chan_configure<module_id::adc1, _args...>();
  detail::inj_chan_configure<module_id::adc1, _args...>();
#endif

#if defined(ADC2)
  detail::reg_chan_configure<module_id::adc2, _args...>();
  detail::inj_chan_configure<module_id::adc2, _args...>();
#endif

#if defined(ADC3)
  detail::reg_chan_configure<module_id::adc3, _args...>();
  detail::inj_chan_configure<module_id::adc3, _args...>();
#endif

#if defined(ADC4)
  detail::reg_chan_configure<module_id::adc4, _args...>();
  detail::inj_chan_configure<module_id::adc4, _args...>();
#endif
}

template<typename _module, typename ..._modules>
void enable()
{
  detail::enable<_module>();
  if constexpr(sizeof...(_modules) > 0) { enable<_modules...>(); }
}

template<typename _module, typename ..._modules>
void disable()
{
  detail::disable<_module>();
  if constexpr(sizeof...(_modules) > 0) { disable<_modules...>(); }
}

template<typename ..._modules>
void calibrate() { detail::calibrate<_modules...>(); }

template<typename ..._modules>
void regular_soft_start() { detail::regular_soft_start<_modules...>(); }

template<typename ..._modules>
void injected_soft_start() { detail::injected_soft_start<_modules...>(); }

template<typename _module>
uint32_t read() { return detail::read<_module>(); }

template<typename _module, uint8_t _jrank>
uint32_t read() { return detail::read<_module, _jrank>(); }

template<typename _module, event ..._events>
event get_flags() { return detail::get_flags<_module, _events...>(); }

template<typename _module, event ..._events>
void clear_flags() { detail::clear_flags<_module, _events...>(); }

template<typename _module, event ..._events>
void enable_events() { detail::enable_events<_module, _events...>(); }

template<typename _module, event ..._events>
void disable_events() { detail::disable_events<_module, _events...>(); }

template<typename _module>
event irq_source() { return detail::irq_source<_module>(); }

template<typename _module, event ..._events>
void irq_clear() { detail::clear_flags<_module, _events...>(); }

template<typename _module>
uint32_t dma_address() { return detail::dma_address<_module>(); }

} // namespace lmcu::adc
