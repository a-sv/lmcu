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

enum class disc_mode { disable, single, regular, injected };

enum class reg_discnum { _1ch, _2ch, _3ch, _4ch, _5ch, _6ch, _7ch, _8ch };

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

enum class awd_mode
{
  disable,
  all_injected,
  all_regular,
  all_injected_and_regular,
  single_injected,
  single_regular,
  single_regular_or_injected
};

enum class awd_channel
{
  _0ch, _1ch,  _2ch,  _3ch,  _4ch,  _5ch,  _6ch,  _7ch,  _8ch,
  _9ch, _10ch, _11ch, _12ch, _13ch, _14ch, _15ch, _16ch, _17ch
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
  reg_discnum _reg_discnum = reg_discnum::_1ch,
  reg_trig _reg_trig = reg_trig::sw_start,
  inj_trig _inj_trig = inj_trig::disable,
  inj_auto _inj_auto = inj_auto::disable,
  dma _dma = dma::disable,
  dual_mode _dual_mode = dual_mode::independent,
  temp_refint _temp_refint = temp_refint::disable,
  awd_mode _awd_mode = awd_mode::disable,
  awd_channel _awd_channel = awd_channel::_0ch,
  uint16_t _awd_low = 0x0,
  uint16_t _awd_high = 0xFFF,
  typename _irq = nvic::irq<nvic::irq_type::disable>
>
struct module
{
  static constexpr auto dev_class    = lmcu::dev_class::adc;
  static constexpr auto module_id    = _module_id;
  static constexpr auto data_align   = _data_align;
  static constexpr auto scan         = _scan;
  static constexpr auto disc_mode    = _disc_mode;
  static constexpr auto reg_discnum  = _reg_discnum;
  static constexpr auto reg_trig     = _reg_trig;
  static constexpr auto inj_trig     = _inj_trig;
  static constexpr auto inj_auto     = _inj_auto;
  static constexpr auto dma          = _dma;
  static constexpr auto dual_mode    = _dual_mode;
  static constexpr auto temp_refint  = _temp_refint;
  static constexpr auto awd_mode     = _awd_mode;
  static constexpr auto awd_channel  = _awd_channel;
  static constexpr auto awd_low      = _awd_low;
  static constexpr auto awd_high     = _awd_high;
  static constexpr auto irq          = _irq();

  static_assert(_awd_high <= 0xFFF && _awd_low <= 0xFFF, "max value for '_awd_high' and '_awd_low' "
                                                         "is 0xFFF");
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

template<typename _module, data_align _data_align>
void set_data_align() { detail::set_data_align<_module, _data_align>(); }

template<typename _module>
data_align get_data_align() { return detail::get_data_align<_module>(); }

template<typename _module, scan _scan>
void set_scan() { detail::set_scan<_module, _scan>(); }

template<typename _module>
scan get_scan() { return detail::get_scan<_module>(); }

template<typename _module, disc_mode _disc_mode>
void set_disc_mode() { detail::set_disc_mode<_module, _disc_mode>(); }

template<typename _module>
disc_mode get_disc_mode() { return detail::get_disc_mode<_module>(); }

template<typename _module, reg_discnum _reg_discnum>
void set_reg_discnum() { detail::set_reg_discnum<_module, _reg_discnum>(); }

template<typename _module>
reg_discnum get_reg_discnum() { return detail::get_reg_discnum<_module>(); }

template<typename _module, reg_trig _reg_trig>
void set_reg_trig() { detail::set_reg_trig<_module, _reg_trig>(); }

template<typename _module>
reg_trig get_reg_trig() { return detail::get_reg_trig<_module>(); }

template<typename _module, inj_trig _inj_trig>
void set_inj_trig() { detail::set_inj_trig<_module, _inj_trig>(); }

template<typename _module>
inj_trig get_inj_trig() { return detail::get_inj_trig<_module>(); }

template<typename _module, inj_auto _inj_auto>
void set_inj_auto() { detail::set_inj_auto<_module, _inj_auto>(); }

template<typename _module>
inj_auto get_inj_auto() { return detail::get_inj_auto<_module>(); }

template<typename _module, dma _dma>
void set_dma() { detail::set_dma<_module, _dma>(); }

template<typename _module>
dma get_dma() { return detail::get_dma<_module>(); }

template<typename _module, dual_mode _dual_mode>
void set_dual_mode() { detail::set_dual_mode<_module, _dual_mode>(); }

template<typename _module>
dual_mode get_dual_mode() { return detail::get_dual_mode<_module>(); }

template<typename _module, temp_refint _temp_refint>
void set_temp_refint() { detail::set_temp_refint<_module, _temp_refint>(); }

template<typename _module>
temp_refint get_temp_refint() { return detail::get_temp_refint<_module>(); }

template<typename _module, awd_mode _awd_mode>
void set_awd_mode() { detail::set_awd_mode<_module, _awd_mode>(); }

template<typename _module>
awd_mode get_awd_mode() { return detail::get_awd_mode<_module>(); }

template<typename _module, awd_channel _awd_channel>
void set_awd_channel() { detail::set_awd_channel<_module, _awd_channel>(); }

template<typename _module>
awd_channel get_awd_channel() { return detail::get_awd_channel<_module>(); }

template<typename _module>
void set_awd_low(uint16_t val) { detail::set_awd_low<_module>(val); }

template<typename _module>
uint16_t get_awd_low() { return detail::get_awd_low<_module>(); }

template<typename _module>
void set_awd_high(uint16_t val) { detail::set_awd_high<_module>(val); }

template<typename _module>
uint16_t get_awd_high() { return detail::get_awd_high<_module>(); }

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
