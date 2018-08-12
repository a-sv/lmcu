#pragma once
#include <lmcu/device>

namespace lmcu::timer {

enum class module_id
{
#if defined(TIM1)
  tim1,
#endif

#if defined(TIM2)
  tim2,
#endif

#if defined(TIM3)
  tim3,
#endif

#if defined(TIM4)
  tim4,
#endif

#if defined(TIM5)
  tim5,
#endif

#if defined(TIM6)
  tim6,
#endif

#if defined(TIM7)
  tim7,
#endif

#if defined(TIM8)
  tim8,
#endif

#if defined(TIM9)
  tim9,
#endif

#if defined(TIM10)
  tim10,
#endif

#if defined(TIM11)
  tim11,
#endif

#if defined(TIM12)
  tim12,
#endif

#if defined(TIM13)
  tim13,
#endif

#if defined(TIM14)
  tim14
#endif
};

enum class counter_mode
{
  up,
  down,
  center_aligned_1,
  center_aligned_2,
  center_aligned_3
};

enum class clock_prediv { div_1, div_2, div_4 };

enum class auto_reload_buffer { enable, disable };

enum class one_pulse { enable, disable };

enum class update_request_src
{
  // - counter overflow/underflow
  // - setting the UG bit
  // - update generation through the slave mode controller
  any,

  // - only counter overflow/underflow
  ovf_udf
};

enum class update_evt { enable, disable };

enum class tim_type { basic, general, advanced };

enum class conf { tim, oc };

template<
  module_id _module_id,
  counter_mode _counter_mode = counter_mode::up,
  clock_prediv _clock_prediv = clock_prediv::div_1,
  uint32_t _rep_count = 0,
  one_pulse _one_pulse = one_pulse::disable
>
struct module
{
  static constexpr auto conf         = timer::conf::tim;
  static constexpr auto module_id    = _module_id;
  static constexpr auto counter_mode = _counter_mode;
  static constexpr auto clock_prediv = _clock_prediv;
  static constexpr auto rep_count    = _rep_count;
  static constexpr auto one_pulse    = _one_pulse;
};

enum class oc_channel { oc_1 = 0, oc_2, oc_3, oc_4 };

enum class oc_mode
{
  timing,
  active,
  inactive,
  toggle,
  pwm1,
  pwm2,
  pwm1_fast,
  pwm2_fast,
  forced_active,
  forced_inactive
};

enum class oc_polarity { low, high };
using oc_n_polarity = oc_polarity;

enum class oc_idle_state { set, reset };
using oc_n_idle_state = oc_idle_state;

template<
  typename _module,
  oc_channel _oc_channel,
  oc_mode _oc_mode,
  oc_polarity _oc_polarity = oc_polarity::low,
  oc_idle_state _oc_idle_state = oc_idle_state::reset,
  oc_n_polarity _oc_n_polarity = oc_n_polarity::low,
  oc_n_idle_state _oc_n_idle_state = oc_n_idle_state::reset
>
struct oc_conf
{
  static constexpr auto conf            = timer::conf::oc;
  static constexpr auto module          = _module();
  static constexpr auto oc_channel      = _oc_channel;
  static constexpr auto oc_mode         = _oc_mode;
  static constexpr auto oc_polarity     = _oc_polarity;
  static constexpr auto oc_idle_state   = _oc_idle_state;
  static constexpr auto oc_n_polarity   = _oc_n_polarity;
  static constexpr auto oc_n_idle_state = _oc_n_idle_state;
};

enum class oc_type { main = 1, comp = 2 };
lmcu_enum_class_flags_impl(oc_type)

#include "detail/timer.h"

template<typename ...args>
void configure() { detail::configure<args...>(); }

template<typename _module>
void set_prescaler(uint16_t val) { detail::set_prescaler<_module>(val); }

template<typename _module>
void set_period(uint16_t val) { detail::set_period<_module>(val); }

template<typename _conf>
void set_pulse(uint16_t val) { detail::set_pulse<_conf>(val); }

template<typename _conf>
void emit_update_event() { detail::emit_update_event<_conf>(); }

template<typename _conf, bool _enable>
void enable() { detail::enable<_conf, _enable>(); }

template<typename _module>
constexpr tim_type get_tim_type() { return detail::get_tim_type<_module>(); }

template<typename _conf, bool _enable>
void main_output_ctrl() { detail::main_output_ctrl<_conf, _enable>(); }

template<typename _conf, oc_type _oc_type, bool _enable>
void channel_ctrl() { detail::channel_ctrl<_conf, _oc_type, _enable>(); }

} // namespace lmcu::timer
