
namespace detail {

template<module_id _module_id>
ADC_TypeDef *inst()
{
  switch(_module_id)
  {
#if defined(ADC1)
  case module_id::adc1: return ADC1;
#endif

#if defined(ADC2)
  case module_id::adc2: return ADC2;
#endif

#if defined(ADC3)
  case module_id::adc3: return ADC3;
#endif

#if defined(ADC4)
  case module_id::adc4: return ADC4;
#endif
  }
}

template<typename _conf>
void enable()
{
  constexpr auto m = _conf();
  auto inst = detail::inst<m.module_id>();

  inst->CR2 |=  ADC_CR2_ADON;
  while((inst->CR2 & ADC_CR2_ADON) == 0)
    ;
}

template<typename _conf>
void disable()
{
  constexpr auto m = _conf();
  auto inst = detail::inst<m.module_id>();

  inst->CR2 &= ~ADC_CR2_ADON;
  while((inst->CR2 & ADC_CR2_ADON) != 0)
    ;
}

template<typename _conf, typename ...args>
void adc_configure()
{
  constexpr auto m = _conf();
  if constexpr(m.conf == conf::adc) {
    auto inst = detail::inst<m.module_id>();

    detail::disable<_conf>();

#if defined(ADC1)
    if constexpr(
      m.reg_trig == reg_trig::tim1_cc1          ||
      m.reg_trig == reg_trig::tim1_cc2          ||
      m.reg_trig == reg_trig::tim1_cc3          ||
      m.reg_trig == reg_trig::tim2_cc2          ||
      m.reg_trig == reg_trig::tim3_trgo         ||
      m.reg_trig == reg_trig::tim4_cc4          ||
      m.reg_trig == reg_trig::exti11__tim8_trgo ||
      m.inj_trig == inj_trig::tim2_trgo         ||
      m.inj_trig == inj_trig::tim2_cc1          ||
      m.inj_trig == inj_trig::tim3_cc4          ||
      m.inj_trig == inj_trig::tim4_trgo         ||
      m.inj_trig == inj_trig::exti15__tim8_cc4
    ) {
      static_assert(
        m.module_id == module_id::adc1
  #if defined(ADC2)
        || m.module_id == module_id::adc2
  #endif
      );
    }
#endif

#if defined(ADC3)
    if constexpr(
      m.reg_trig == reg_trig::tim3_cc1  ||
      m.reg_trig == reg_trig::tim2_cc3  ||
      m.reg_trig == reg_trig::tim1_cc3  ||
      m.reg_trig == reg_trig::tim8_cc1  ||
      m.reg_trig == reg_trig::tim8_trgo ||
      m.reg_trig == reg_trig::tim5_cc1  ||
      m.reg_trig == reg_trig::tim5_cc3  ||
      m.inj_trig == inj_trig::tim4_cc3  ||
      m.inj_trig == inj_trig::tim8_cc2  ||
      m.inj_trig == inj_trig::tim8_cc4  ||
      m.inj_trig == inj_trig::tim5_trgo ||
      m.inj_trig == inj_trig::tim5_cc4
    ) {
      static_assert(m.module_id == module_id::adc3);
    }
#endif

    switch(m.module_id)
    {
#if defined(ADC1)
    case module_id::adc1:
      RCC->APB2ENR  |=  RCC_APB2ENR_ADC1EN;
      RCC->APB2RSTR |=  RCC_APB2RSTR_ADC1RST;
      RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC1RST;
      break;
#endif

#if defined(ADC2)
    case module_id::adc2:
      RCC->APB2ENR  |=  RCC_APB2ENR_ADC2EN;
      RCC->APB2RSTR |=  RCC_APB2RSTR_ADC2RST;
      RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC2RST;
      break;
#endif

#if defined(ADC3)
    case module_id::adc3:
      break;
#endif

#if defined(ADC4)
    case module_id::adc4:
      break;
#endif
    }

    {
      auto r = inst->CR1;

      r &= ~ADC_CR1_DUALMOD;
      switch(m.dual_mode)
      {
      case dual_mode::regular_and_injected:    r |= (1 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::regular_and_trigger:     r |= (2 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::injected_and_fast_inter: r |= (3 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::injected_and_slow_inter: r |= (4 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::injected_only:           r |= (5 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::regular_only:            r |= (6 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::fast_inter_only:         r |= (7 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::slow_inter_only:         r |= (8 << ADC_CR1_DUALMOD_Pos); break;
      case dual_mode::trigger_only:            r |= (9 << ADC_CR1_DUALMOD_Pos); break;
      default : break;
      }

      if constexpr(m.disc_mode == disc_mode::regular ||
                   m.disc_mode == disc_mode::regular_and_injected) {
        r |=  ADC_CR1_DISCEN;
      }
      else {
        r &= ~ADC_CR1_DISCEN;
      }

      if constexpr(m.disc_mode == disc_mode::injected ||
                   m.disc_mode == disc_mode::regular_and_injected) {
        r |=  ADC_CR1_JDISCEN;
      }
      else {
        r &= ~ADC_CR1_JDISCEN;
      }

      r &= ~ADC_CR1_DISCNUM;
      r |=  uint32_t(m.disc_num) << ADC_CR1_DISCNUM_Pos;

      if constexpr(m.inj_auto == inj_auto::disable) {
        r &= ~ADC_CR1_JAUTO;
      }
      else {
        r |=  ADC_CR1_JAUTO;
      }

      if constexpr(m.scan == scan::disable) {
        r &= ~ADC_CR1_SCAN;
      }
      else {
        r |=  ADC_CR1_SCAN;
      }

      inst->CR1 = r;
    }

    {
      auto r = inst->CR2;

      if constexpr(m.temp_sensor == temp_sensor::disable) {
        r &= ~ADC_CR2_TSVREFE;
      }
      else {
        r |=  ADC_CR2_TSVREFE;
        delay::us<10>();
      }

      if constexpr(m.reg_trig == reg_trig::disable) {
        r &= ~ADC_CR2_EXTTRIG;
      }
      else {
        r |=  ADC_CR2_EXTTRIG;
        r &= ~ADC_CR2_EXTSEL;
        switch(m.reg_trig) {
#if defined(ADC1)
        case reg_trig::tim1_cc2:          r |= (1 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim1_cc3:          r |= (2 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim2_cc2:          r |= (3 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim3_trgo:         r |= (4 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim4_cc4:          r |= (5 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::exti11__tim8_trgo: r |= (6 << ADC_CR2_EXTSEL_Pos); break;
#endif

#if defined(ADC3)
        case reg_trig::tim2_cc3:          r |= (1 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim1_cc3:          r |= (2 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim8_cc1:          r |= (3 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim8_trgo:         r |= (4 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim5_cc1:          r |= (5 << ADC_CR2_EXTSEL_Pos); break;
        case reg_trig::tim5_cc3:          r |= (6 << ADC_CR2_EXTSEL_Pos); break;
#endif
        case reg_trig::sw_start:          r |= (7 << ADC_CR2_EXTSEL_Pos); break;
        default : break;
        }
      }

      if constexpr(m.inj_trig == inj_trig::disable) {
        r &= ~ADC_CR2_JEXTTRIG;
      }
      else {
        r |=  ADC_CR2_JEXTTRIG;
        r &= ~ADC_CR2_JEXTSEL;
        switch(m.inj_trig) {
        case inj_trig::tim1_cc4:         r |= (1 << ADC_CR2_JEXTTRIG_Pos); break;

#if defined(ADC1)
        case inj_trig::tim2_trgo:        r |= (2 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::tim2_cc1:         r |= (3 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::tim3_cc4:         r |= (4 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::tim4_trgo:        r |= (5 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::exti15__tim8_cc4: r |= (6 << ADC_CR2_JEXTTRIG_Pos); break;
#endif

#if defined(ADC3)
        case inj_trig::tim4_cc3:         r |= (2 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::tim8_cc2:         r |= (3 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::tim8_cc4:         r |= (4 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::tim5_trgo:        r |= (5 << ADC_CR2_JEXTTRIG_Pos); break;
        case inj_trig::tim5_cc4:         r |= (6 << ADC_CR2_JEXTTRIG_Pos); break;
#endif
        case inj_trig::jsw_start:        r |= (7 << ADC_CR2_JEXTTRIG_Pos); break;
        default : break;
        }
      }

      if constexpr(m.data_align == data_align::right) {
        r &= ~ADC_CR2_ALIGN;
      }
      else {
        r |=  ADC_CR2_ALIGN;
      }

      if constexpr(m.disc_mode == disc_mode::disable) {
        r |=  ADC_CR2_CONT;
      }
      else {
        r &= ~ADC_CR2_CONT;
      }

      if constexpr(m.dma == dma::disable) {
        r &= ~ADC_CR2_DMA;
      }
      else {
        r |=  ADC_CR2_DMA;
      }

      inst->CR2 = r;
    }
  }

  if constexpr(sizeof...(args) > 0) { adc_configure<args...>(); }
}

template<
  uint32_t _mask_1,
  uint32_t _bits_1,
  uint32_t _mask_2,
  uint32_t _bits_2,
  uint32_t _mask_3,
  uint32_t _bits_3,
  module_id _module_id,
  uint8_t _rank,
  typename _conf,
  typename ...args
>
constexpr void reg_seqence_configure()
{
  constexpr auto m = _conf();

  constexpr auto match = [m]
  {
    if constexpr(m.conf == conf::reg_chan) { return m.module.module_id == _module_id; }
    return false;
  }();

  [[maybe_unused]] constexpr auto mask_1 = [m]() -> uint32_t
  {
    if constexpr(match && _rank >= 12 && _rank <= 15) {
      return _mask_1 | (0x1f << ((_rank - 12) * 5));
    }
    return _mask_1;
  }();

  [[maybe_unused]] constexpr auto bits_1 = [m]() -> uint32_t
  {
    if constexpr(match && _rank >= 12 && _rank <= 15) {
      return _bits_1 | (m.chan_num << ((_rank - 12) * 5));
    }
    return _bits_1;
  }();

  [[maybe_unused]] constexpr auto mask_2 = [m]() -> uint32_t
  {
    if constexpr(match && _rank >= 6 && _rank <= 11) {
      return _mask_2 | (0x1f << ((_rank - 6) * 5));
    }
    return _mask_2;
  }();

  [[maybe_unused]] constexpr auto bits_2 = [m]() -> uint32_t
  {
    if constexpr(match && _rank >= 6 && _rank <= 11) {
      return _bits_2 | (m.chan_num << ((_rank - 6) * 5));
    }
    return _bits_2;
  }();

  [[maybe_unused]] constexpr auto mask_3 = [m]() -> uint32_t
  {
    if constexpr(match && _rank <= 5) {
      return _mask_3 | (0x1f << (_rank * 5));
    }
    return _mask_3;
  }();

  [[maybe_unused]] constexpr auto bits_3 = [m]() -> uint32_t
  {
    if constexpr(match && _rank <= 5) {
      return _bits_3 | (m.chan_num << (_rank * 5));
    }
    return _bits_3;
  }();

  if constexpr(sizeof...(args) > 0) {
    reg_seqence_configure<mask_1, bits_1, mask_2, bits_2, mask_3, bits_3, _module_id,
                          match? _rank + 1 : _rank, args...>();
  }
  else
  if constexpr(match) {
    [[maybe_unused]] auto inst = detail::inst<_module_id>();

    if constexpr(mask_3) {
      auto r = inst->SQR3;
      r &= ~mask_3;
      r |=  bits_3;
      inst->SQR3 = r;
    }

    if constexpr(mask_2) {
      auto r = inst->SQR2;
      r &= ~mask_2;
      r |=  bits_2;
      inst->SQR2 = r;
    }

    if constexpr(mask_1 || mask_2 || mask_3) {
      auto r = inst->SQR1;

      if constexpr(mask_1) {
        r &= ~mask_1;
        r |=  bits_1;
      }

      r &= ~ADC_SQR1_L;
      r |= _rank << ADC_SQR1_L_Pos;

      inst->SQR1 = r;
    }
  }
}

template<module_id _module_id, uint8_t _low, uint8_t _high, typename _conf>
constexpr bool is_reg_chan_in_range()
{
  constexpr auto m = _conf();
  if constexpr(m.conf == conf::reg_chan) {
    return m.module.module_id == _module_id && m.chan_num >= _low && m.chan_num <= _high;
  }
  return false;
}

template<uint32_t _r, module_id _module_id, uint8_t _low, uint8_t _high, typename _conf,
         typename ...args>
constexpr uint32_t smpr_mask()
{
  if constexpr(is_reg_chan_in_range<_module_id, _low, _high, _conf>()) {
    return _r | (0x7 << ((_conf().chan_num - _low) * 3));
  }
  if constexpr(sizeof...(args) > 0) { return smpr_mask<_r, _module_id, _low, _high, args...>(); }
  return _r;
}

template<uint32_t _r, module_id _module_id, uint8_t _low, uint8_t _high, typename _conf,
         typename ...args>
constexpr uint32_t smpr_bits()
{
  if constexpr(is_reg_chan_in_range<_module_id, _low, _high, _conf>()) {
    return _r | (uint32_t(_conf().sample_time) << ((_conf().chan_num - _low) * 3));
  }
  if constexpr(sizeof...(args) > 0) { return smpr_bits<_r, _module_id, _low, _high, args...>(); }
  return _r;
}

template<module_id _module_id, typename ...args>
void reg_chan_configure()
{
  [[maybe_unused]] auto inst = detail::inst<_module_id>();

  reg_seqence_configure<0, 0, 0, 0, 0, 0, _module_id, 0, args...>();

  {
    constexpr auto mask = smpr_mask<0, _module_id, 0, 9, args...>();
    if constexpr(mask != 0) {
      auto r = inst->SMPR2;
      r &= ~mask;
      r |= smpr_bits<0, _module_id, 0, 9, args...>();
      inst->SMPR2 = r;
    }
  }


  {
    constexpr auto mask = smpr_mask<0, _module_id, 10, 17, args...>();
    if constexpr(mask != 0) {
      auto r = inst->SMPR1;
      r &= ~mask;
      r |= smpr_bits<0, _module_id, 10, 17, args...>();
      inst->SMPR1 = r;
    }
  }
}

template<typename _arg1, typename ...args>
void calibrate()
{
  constexpr auto m = _arg1();
  auto inst = detail::inst<m.module_id>();

  detail::disable<_arg1>();

  // wait 2 ADC cycles
  delay::cyc((rcc::system_clock() / rcc::adc_clock()) * 2);

  detail::enable<_arg1>();

  // reset calibration
  inst->CR2 |= ADC_CR2_RSTCAL;
  while((inst->CR2 & ADC_CR2_RSTCAL) != 0)
    ;

  // start calibration
  inst->CR2 |= ADC_CR2_CAL;
  while((inst->CR2 & ADC_CR2_CAL) != 0)
    ;

  if constexpr(sizeof...(args) > 0) { calibrate<args...>(); }
}

template<typename _conf, typename ...args>
void regular_soft_start()
{
  detail::inst<_conf().module_id>()->CR2 |= ADC_CR2_SWSTART;
  if constexpr(sizeof...(args) > 0) { regular_soft_start<args...>(); }
}

template<typename _conf>
uint32_t read()
{
  constexpr auto m = _conf();
  if constexpr(m.conf == conf::adc) { return detail::inst<m.module_id>()->DR; }
  return 0;
}

} // namespace detail
