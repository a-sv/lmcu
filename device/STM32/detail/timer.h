#pragma once

namespace detail {

constexpr uint32_t cce[]  = {TIM_CCER_CC1E,  TIM_CCER_CC2E,  TIM_CCER_CC3E, TIM_CCER_CC4E};
constexpr uint32_t ccne[] = {TIM_CCER_CC1NE, TIM_CCER_CC2NE, TIM_CCER_CC3NE};

template<typename _module>
TIM_TypeDef *inst()
{
  switch(_module::module_id)
  {
#if defined(TIM1)
  case module_id::tim1: return TIM1;
#endif

#if defined(TIM2)
  case module_id::tim2: return TIM2;
#endif

#if defined(TIM3)
  case module_id::tim3: return TIM3;
#endif

#if defined(TIM4)
  case module_id::tim4: return TIM4;
#endif

#if defined(TIM5)
  case module_id::tim5: return TIM5;
#endif

#if defined(TIM6)
  case module_id::tim6: return TIM6;
#endif

#if defined(TIM7)
  case module_id::tim7: return TIM7;
#endif

#if defined(TIM8)
  case module_id::tim8: return TIM8;
#endif

#if defined(TIM9)
  case module_id::tim9: return TIM9;
#endif

#if defined(TIM10)
  case module_id::tim10: return TIM10;
#endif

#if defined(TIM11)
  case module_id::tim11: return TIM11;
#endif

#if defined(TIM12)
  case module_id::tim12: return TIM12;
#endif

#if defined(TIM13)
  case module_id::tim13: return TIM13;
#endif

#if defined(TIM14)
  case module_id::tim14: return TIM14;
#endif
  }
}

template<typename _module>
constexpr tim_type get_tim_type()
{
  switch(_module::module_id)
  {
#if defined(TIM1)
  case module_id::tim1: return tim_type::advanced;
#endif

#if defined(TIM2)
  case module_id::tim2: return tim_type::general;
#endif

#if defined(TIM3)
  case module_id::tim3: return tim_type::general;
#endif

#if defined(TIM4)
  case module_id::tim4: return tim_type::general;
#endif

#if defined(TIM5)
  case module_id::tim5: return tim_type::general;
#endif

#if defined(TIM6)
  case module_id::tim6: return tim_type::basic;
#endif

#if defined(TIM7)
  case module_id::tim7: return tim_type::basic;
#endif

#if defined(TIM8)
  case module_id::tim8: return tim_type::advanced;
#endif

#if defined(TIM9)
  case module_id::tim9: return tim_type::general;
#endif

#if defined(TIM10)
  case module_id::tim10: return tim_type::general;
#endif

#if defined(TIM11)
  case module_id::tim11: return tim_type::general;
#endif

#if defined(TIM12)
  case module_id::tim12: return tim_type::general;
#endif

#if defined(TIM13)
  case module_id::tim13: return tim_type::general;
#endif

#if defined(TIM14)
  case module_id::tim14: return tim_type::general;
#endif
  }
}

template<typename _module>
void set_prescaler(uint16_t val) { detail::inst<_module>()->PSC = val; }

template<typename _module>
void set_period(uint16_t val) { detail::inst<_module>()->ARR = val; }

template<typename _module>
void emit_update_event() { detail::inst<_module>()->EGR = TIM_EGR_UG; }

template<typename _module_oc>
void set_pulse(uint16_t val)
{
  auto inst = detail::inst<decltype(_module_oc::module)>();

  switch(_module_oc::oc_channel)
  {
    case oc_channel::oc_1: inst->CCR1 = val; break;
    case oc_channel::oc_2: inst->CCR2 = val; break;
    case oc_channel::oc_3: inst->CCR3 = val; break;
    case oc_channel::oc_4: inst->CCR4 = val; break;
  }
}

template<typename ..._modules>
void enable() { ((detail::inst<_modules>()->CR1 |= TIM_CR1_CEN), ...); }

template<typename ..._modules>
void disable() { ((detail::inst<_modules>()->CR1 &= ~TIM_CR1_CEN), ...); }

template<typename _module>
void tim_configure()
{
  auto inst = detail::inst<_module>();

  switch(_module::module_id)
  {
#if defined(TIM1)
  case module_id::tim1:
    RCC->APB2ENR  |=  RCC_APB2ENR_TIM1EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM1RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST;
    break;
#endif

#if defined(TIM2)
  case module_id::tim2:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM2EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST;
    break;
#endif

#if defined(TIM3)
  case module_id::tim3:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM3EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM3RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST;
    break;
#endif

#if defined(TIM4)
  case module_id::tim4:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM4EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM4RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST;
    break;
#endif

#if defined(TIM5)
  case module_id::tim5:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM5EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM5RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM5RST;
    break;
#endif

#if defined(TIM6)
  case module_id::tim6:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM6EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM6RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST;
    break;
#endif

#if defined(TIM7)
  case module_id::tim7:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM7EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM7RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM7RST;
    break;
#endif

#if defined(TIM8)
  case module_id::tim8:
    RCC->APB2ENR  |=  RCC_APB2ENR_TIM8EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM8RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM8RST;
    break;
#endif

#if defined(TIM9)
  case module_id::tim9:
    RCC->APB2ENR  |=  RCC_APB2ENR_TIM9EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM9RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM9RST;
    break;
#endif

#if defined(TIM10)
  case module_id::tim10:
    RCC->APB2ENR  |=  RCC_APB2ENR_TIM10EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM10RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM10RST;
    break;
#endif

#if defined(TIM11)
  case module_id::tim11:
    RCC->APB2ENR  |=  RCC_APB2ENR_TIM11EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM11RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM11RST;
    break;
#endif

#if defined(TIM12)
  case module_id::tim12:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM12EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM12RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM12RST;
    break;
#endif

#if defined(TIM13)
  case module_id::tim13:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM13EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM13RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM13RST;
    break;
#endif

#if defined(TIM14)
  case module_id::tim14:
    RCC->APB1ENR  |=  RCC_APB1ENR_TIM14EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM14RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM14RST;
    break;
#endif
  }

  disable<_module>();

  {
    uint32_t r = inst->CR1;

    r &= ~(TIM_CR1_DIR | TIM_CR1_CMS);
    switch(_module::counter_mode)
    {
    case counter_mode::down:             r |= TIM_CR1_DIR;            break;
    case counter_mode::center_aligned_1: r |= (1 << TIM_CR1_CMS_Pos); break;
    case counter_mode::center_aligned_2: r |= (2 << TIM_CR1_CMS_Pos); break;
    case counter_mode::center_aligned_3: r |= (3 << TIM_CR1_CMS_Pos); break;
    default : break;
    }

    r &= ~TIM_CR1_CKD;
    switch(_module::clock_prediv)
    {
    case clock_prediv::div_2: r |= (1 << TIM_CR1_CKD_Pos);
    case clock_prediv::div_4: r |= (2 << TIM_CR1_CKD_Pos);
    default : break;
    }

    if constexpr(_module::one_pulse == one_pulse::enable) {
      r |=  TIM_CR1_OPM;
    }
    else {
      r &= ~TIM_CR1_OPM;
    }

    inst->CR1 = r;
  }

  inst->SMCR = 0; // disable slave mode

  if constexpr(get_tim_type<_conf>() == tim_type::advanced) { inst->RCR = _module::rep_count; }
}

template<typename _module_oc>
void oc_configure()
{
  auto inst = detail::inst<decltype(_module_oc::module)>();

  constexpr auto oc_channel = uint32_t(_module_oc::oc_channel);
  constexpr auto tim_type   = get_tim_type<decltype(_module_oc::module)>();

  {
    uint32_t r = inst->CCER;
    r &= ~cce[oc_channel];
    if constexpr(tim_type == tim_type::advanced && oc_channel < 3) { r &= ~ccne[oc_channel]; }
    inst->CCER = r;
  }

  auto set_ocm = [](auto&& r)
  {
    constexpr auto ocm_pos = []() -> uint32_t
    {
      switch(_module_oc::oc_channel)
      {
        case oc_channel::oc_1: return TIM_CCMR1_OC1M_Pos;
        case oc_channel::oc_2: return TIM_CCMR1_OC2M_Pos;
        case oc_channel::oc_3: return TIM_CCMR2_OC3M_Pos;
        case oc_channel::oc_4: return TIM_CCMR2_OC4M_Pos;
      }
    }();

    switch(_module_oc::oc_mode) {
    case oc_mode::active:          r |= (1 << ocm_pos); break;
    case oc_mode::inactive:        r |= (2 << ocm_pos); break;
    case oc_mode::toggle:          r |= (3 << ocm_pos); break;
    case oc_mode::forced_inactive: r |= (4 << ocm_pos); break;
    case oc_mode::forced_active:   r |= (5 << ocm_pos); break;
    case oc_mode::pwm1_fast:
    case oc_mode::pwm1:            r |= (6 << ocm_pos); break;
    case oc_mode::pwm2_fast:
    case oc_mode::pwm2:            r |= (7 << ocm_pos); break;
    default : break;
    }
  };

  {
    constexpr uint32_t
      ocm[]  = {TIM_CCMR1_OC1M,  TIM_CCMR1_OC2M,  TIM_CCMR2_OC3M,  TIM_CCMR2_OC4M },
      ccs[]  = {TIM_CCMR1_CC1S,  TIM_CCMR1_CC2S,  TIM_CCMR2_CC3S,  TIM_CCMR2_CC4S },
      ocfe[] = {TIM_CCMR1_OC1FE, TIM_CCMR1_OC2FE, TIM_CCMR2_OC3FE, TIM_CCMR2_OC4FE},
      ocpe[] = {TIM_CCMR1_OC1PE, TIM_CCMR1_OC2PE, TIM_CCMR2_OC3PE, TIM_CCMR2_OC4PE}
    ;

    uint32_t r = (oc_channel < 2)? inst->CCMR1 : inst->CCMR2;

    r &= ~(ocm[oc_channel] | ccs[oc_channel]);
    set_ocm(r);

    if constexpr(_module_oc::oc_mode == oc_mode::pwm1 || _module_oc::oc_mode == oc_mode::pwm2) {
      r |=  ocpe[oc_channel];
    }

    if constexpr(_module_oc::oc_mode == oc_mode::pwm1_fast ||
                 _module_oc::oc_mode == oc_mode::pwm2_fast) {
      r |=  ocfe[oc_channel];
      r |=  ocpe[oc_channel];
    }
    else {
      r &= ~ocfe[oc_channel];
    }

    if constexpr(oc_channel < 2) { inst->CCMR1 = r; } else { inst->CCMR2 = r; }
  }

  {
    constexpr uint32_t
      ccp[]  = {TIM_CCER_CC1P,  TIM_CCER_CC2P,  TIM_CCER_CC3P, TIM_CCER_CC4P},
      ccnp[] = {TIM_CCER_CC1NP, TIM_CCER_CC2NP, TIM_CCER_CC3NP}
    ;

    uint32_t r = inst->CCER;

    if constexpr(_module_oc::oc_polarity == oc_polarity::low) {
      r |=  ccp[oc_channel];
    }
    else {
      r &= ~ccp[oc_channel];
    }

    if constexpr(tim_type == tim_type::advanced && oc_channel < 3) {
      if constexpr(_module_oc::oc_polarity == oc_polarity::low) {
        r |=  ccnp[oc_channel];
      }
      else {
        r &= ~ccnp[oc_channel];
      }
    }

    inst->CCER = r;
  }

  {
    constexpr uint32_t
      ois[]  = {TIM_CR2_OIS1,  TIM_CR2_OIS2,  TIM_CR2_OIS3, TIM_CR2_OIS4},
      oisn[] = {TIM_CR2_OIS1N, TIM_CR2_OIS2N, TIM_CR2_OIS3N}
    ;

    uint32_t r = inst->CR2;

    if constexpr(_module_oc::oc_idle_state == oc_idle_state::set) {
      r |=  ois[oc_channel];
    }
    else {
      r &= ~ois[oc_channel];
    }

    if constexpr(tim_type == tim_type::advanced && oc_channel < 3) {
      if constexpr(_module_oc::oc_n_idle_state == oc_idle_state::set) {
        r |=  oisn[oc_channel];
      }
      else {
        r &= ~oisn[oc_channel];
      }
    }

    inst->CR2 = r;
  }
}

template<typename _module, typename ..._modules>
void configure()
{
  if constexpr(_module::conf == conf::tim) { tim_configure<_conf>(); }
  if constexpr(_module::conf == conf::oc)  { oc_configure<_conf>();  }

  if constexpr(sizeof...(_modules) > 0) { configure<_modules...>(); }
}

template<typename ..._modules>
void main_output_enable()  { ((detail::inst<_modules::module_id>()->BDTR |=  TIM_BDTR_MOE), ...); }

template<typename ..._modules>
void main_output_disable() { ((detail::inst<_modules::module_id>()->BDTR &= ~TIM_BDTR_MOE), ...); }

template<typename _module_oc, oc_type _oc_type>
constexpr void timer_type_check()
{
  if constexpr(_oc_type & oc_type::comp) {
    constexpr auto tim_type = get_tim_type<decltype(_module_oc::module)>();

    static_assert(tim_type == tim_type::advanced, "complementary outputs support only for advanced "
                                                  "timers");
    static_assert(_module_oc::oc_channel < 3, "complementary outputs support only for 1 - 3 main "
                                              "channels");
  }
}

template<typename _module_oc, oc_type _oc_type>
void channel_enable()
{
  auto inst = detail::inst<decltype(_module_oc::module)>();

  constexpr auto oc_channel = uint32_t(_module_oc::oc_channel);

  timer_type_check<_module_oc, _oc_type>();

  uint32_t r = inst->CCER;
  if constexpr(_oc_type & oc_type::main) { r |= cce[oc_channel];  }
  if constexpr(_oc_type & oc_type::comp) { r |= ccne[oc_channel]; }
  inst->CCER = r;
}

template<typename _module_oc, oc_type _oc_type>
void channel_disable()
{
  auto inst = detail::inst<decltype(_module_oc::module)>();

  constexpr auto oc_channel = uint32_t(_module_oc::oc_channel);

  timer_type_check<_module_oc, _oc_type>();

  uint32_t r = inst->CCER;
  if constexpr(_oc_type & oc_type::main) { r &= ~cce[oc_channel];  }
  if constexpr(_oc_type & oc_type::comp) { r &= ~ccne[oc_channel]; }
  inst->CCER = r;
}

} // namespace detail
