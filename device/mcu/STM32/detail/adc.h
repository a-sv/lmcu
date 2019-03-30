#pragma once

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
  return nullptr;
}

template<typename _module>
ADC_TypeDef *inst() { return detail::inst<_module::module_id>(); }

template<typename _module>
void enable()
{
  auto inst = detail::inst<_module>();

  inst->CR2 |=  ADC_CR2_ADON;
  while((inst->CR2 & ADC_CR2_ADON) == 0)
    ;
}

template<typename _module>
void disable()
{
  auto inst = detail::inst<_module>();

  inst->CR2 &= ~ADC_CR2_ADON;
  while((inst->CR2 & ADC_CR2_ADON) != 0)
    ;
}

template<typename _module, typename ..._modules>
void adc_configure()
{
  if constexpr(_module::dev_class == lmcu::dev_class::adc) {
    auto inst = detail::inst<_module>();

    detail::disable<_module>();

#if defined(ADC1)
    if constexpr(
      _module::reg_trig == reg_trig::tim1_cc1          ||
      _module::reg_trig == reg_trig::tim1_cc2          ||
      _module::reg_trig == reg_trig::tim1_cc3          ||
      _module::reg_trig == reg_trig::tim2_cc2          ||
      _module::reg_trig == reg_trig::tim3_trgo         ||
      _module::reg_trig == reg_trig::tim4_cc4          ||
      _module::reg_trig == reg_trig::exti11__tim8_trgo ||
      _module::inj_trig == inj_trig::tim2_trgo         ||
      _module::inj_trig == inj_trig::tim2_cc1          ||
      _module::inj_trig == inj_trig::tim3_cc4          ||
      _module::inj_trig == inj_trig::tim4_trgo         ||
      _module::inj_trig == inj_trig::exti15__tim8_cc4
    ) {
      static_assert(
        _module::module_id == module_id::adc1
  #if defined(ADC2)
        || _module::module_id == module_id::adc2
  #endif
      );
    }
#endif

#if defined(ADC3)
    if constexpr(
      _module::reg_trig == reg_trig::tim3_cc1  ||
      _module::reg_trig == reg_trig::tim2_cc3  ||
      _module::reg_trig == reg_trig::tim1_cc3  ||
      _module::reg_trig == reg_trig::tim8_cc1  ||
      _module::reg_trig == reg_trig::tim8_trgo ||
      _module::reg_trig == reg_trig::tim5_cc1  ||
      _module::reg_trig == reg_trig::tim5_cc3  ||
      _module::inj_trig == inj_trig::tim4_cc3  ||
      _module::inj_trig == inj_trig::tim8_cc2  ||
      _module::inj_trig == inj_trig::tim8_cc4  ||
      _module::inj_trig == inj_trig::tim5_trgo ||
      _module::inj_trig == inj_trig::tim5_cc4
    ) {
      static_assert(_module::module_id == module_id::adc3);
    }
#endif

    switch(_module::module_id)
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
      RCC->APB2ENR  |=  RCC_APB2ENR_ADC3EN;
      RCC->APB2RSTR |=  RCC_APB2RSTR_ADC3RST;
      RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC3RST;
      break;
#endif

#if defined(ADC4)
    case module_id::adc4:
      RCC->APB2ENR  |=  RCC_APB2ENR_ADC4EN;
      RCC->APB2RSTR |=  RCC_APB2RSTR_ADC4RST;
      RCC->APB2RSTR &= ~RCC_APB2RSTR_ADC4RST;
      break;
#endif
    }

    {
      uint32_t r = inst->CR1;

      r &= ~ADC_CR1_DUALMOD;
      switch(_module::dual_mode)
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

      if constexpr(_module::disc_mode == disc_mode::regular ||
                   _module::disc_mode == disc_mode::regular_and_injected) {
        r |=  ADC_CR1_DISCEN;
      }
      else {
        r &= ~ADC_CR1_DISCEN;
      }

      if constexpr(_module::disc_mode == disc_mode::injected ||
                   _module::disc_mode == disc_mode::regular_and_injected) {
        r |=  ADC_CR1_JDISCEN;
      }
      else {
        r &= ~ADC_CR1_JDISCEN;
      }

      r &= ~ADC_CR1_DISCNUM;
      r |=  uint32_t(_module::disc_num) << ADC_CR1_DISCNUM_Pos;

      if constexpr(_module::inj_auto == inj_auto::disable) {
        r &= ~ADC_CR1_JAUTO;
      }
      else {
        r |=  ADC_CR1_JAUTO;
      }

      if constexpr(_module::scan == scan::disable) {
        r &= ~ADC_CR1_SCAN;
      }
      else {
        r |=  ADC_CR1_SCAN;
      }

      inst->CR1 = r;
    }

    {
      uint32_t r = inst->CR2;

      if constexpr(_module::temp_refint == temp_refint::disable) {
        r &= ~ADC_CR2_TSVREFE;
      }
      else {
        r |=  ADC_CR2_TSVREFE;
        delay::us(10);
      }

      if constexpr(_module::reg_trig == reg_trig::disable) {
        r &= ~ADC_CR2_EXTTRIG;
      }
      else {
        r |=  ADC_CR2_EXTTRIG;
        r &= ~ADC_CR2_EXTSEL;
        switch(_module::reg_trig) {
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

      if constexpr(_module::inj_trig == inj_trig::disable) {
        r &= ~ADC_CR2_JEXTTRIG;
      }
      else {
        r |=  ADC_CR2_JEXTTRIG;
        r &= ~ADC_CR2_JEXTSEL;
        switch(_module::inj_trig) {
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

      if constexpr(_module::data_align == data_align::right) {
        r &= ~ADC_CR2_ALIGN;
      }
      else {
        r |=  ADC_CR2_ALIGN;
      }

      if constexpr(_module::disc_mode == disc_mode::disable) {
        r |=  ADC_CR2_CONT;
      }
      else {
        r &= ~ADC_CR2_CONT;
      }

      if constexpr(_module::dma == dma::disable) {
        r &= ~ADC_CR2_DMA;
      }
      else {
        r |=  ADC_CR2_DMA;
      }

      inst->CR2 = r;
    }
  }

  if constexpr(sizeof...(_modules) > 0) { adc_configure<_modules...>(); }
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
  typename _chconf,
  typename ..._chconfs
>
constexpr void reg_seqence_configure()
{
  constexpr auto match = []
  {
    if constexpr(_chconf::dev_class == lmcu::dev_class::adc_reg_channel) {
      return _chconf::module.module_id == _module_id;
    }
    return false;
  }();

  [[maybe_unused]] constexpr auto mask_1 = []() -> uint32_t
  {
    if constexpr(match && _rank >= 12 && _rank <= 15) {
      return _mask_1 | (0x1f << ((_rank - 12) * 5));
    }
    return _mask_1;
  }();

  [[maybe_unused]] constexpr auto bits_1 = []() -> uint32_t
  {
    if constexpr(match && _rank >= 12 && _rank <= 15) {
      return _bits_1 | (_chconf::chan_num << ((_rank - 12) * 5));
    }
    return _bits_1;
  }();

  [[maybe_unused]] constexpr auto mask_2 = []() -> uint32_t
  {
    if constexpr(match && _rank >= 6 && _rank <= 11) {
      return _mask_2 | (0x1f << ((_rank - 6) * 5));
    }
    return _mask_2;
  }();

  [[maybe_unused]] constexpr auto bits_2 = []() -> uint32_t
  {
    if constexpr(match && _rank >= 6 && _rank <= 11) {
      return _bits_2 | (_chconf::chan_num << ((_rank - 6) * 5));
    }
    return _bits_2;
  }();

  [[maybe_unused]] constexpr auto mask_3 = []() -> uint32_t
  {
    if constexpr(match && _rank <= 5) {
      return _mask_3 | (0x1f << (_rank * 5));
    }
    return _mask_3;
  }();

  [[maybe_unused]] constexpr auto bits_3 = []() -> uint32_t
  {
    if constexpr(match && _rank <= 5) {
      return _bits_3 | (_chconf::chan_num << (_rank * 5));
    }
    return _bits_3;
  }();

  if constexpr(sizeof...(_chconfs) > 0) {
    reg_seqence_configure<mask_1, bits_1, mask_2, bits_2, mask_3, bits_3, _module_id,
                          match? _rank + 1 : _rank, _chconfs...>();
  }
  else
  if constexpr(match) {
    [[maybe_unused]] auto inst = detail::inst<_module_id>();

    if constexpr(mask_3) {
      uint32_t r = inst->SQR3;
      r &= ~mask_3;
      r |=  bits_3;
      inst->SQR3 = r;
    }

    if constexpr(mask_2) {
      uint32_t r = inst->SQR2;
      r &= ~mask_2;
      r |=  bits_2;
      inst->SQR2 = r;
    }

    if constexpr(mask_1 || mask_2 || mask_3) {
      uint32_t r = inst->SQR1;

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

template<
  uint32_t _jofr_1,
  uint32_t _jofr_2,
  uint32_t _jofr_3,
  uint32_t _jofr_4,
  uint32_t _jsqr,
  module_id _module_id,
  uint8_t _rank,
  typename _chconf,
  typename ..._chconfs
>
constexpr void inj_seqence_configure()
{
  constexpr auto match = []
  {
    if constexpr(_chconf::dev_class == lmcu::dev_class::adc_inj_channel) {
      return _chconf::module.module_id == _module_id;
    }
    return false;
  }();

  [[maybe_unused]] constexpr auto jofr_1 = []() -> uint32_t
  {
    if constexpr(match && _rank == 0) { return _chconf::data_offset; }
    return _jofr_1;
  }();

  [[maybe_unused]] constexpr auto jofr_2 = []() -> uint32_t
  {
    if constexpr(match && _rank == 1) { return _chconf::data_offset; }
    return _jofr_2;
  }();

  [[maybe_unused]] constexpr auto jofr_3 = []() -> uint32_t
  {
    if constexpr(match && _rank == 2) { return _chconf::data_offset; }
    return _jofr_3;
  }();

  [[maybe_unused]] constexpr auto jofr_4 = []() -> uint32_t
  {
    if constexpr(match && _rank == 3) { return _chconf::data_offset; }
    return _jofr_4;
  }();

  [[maybe_unused]] constexpr auto jsqr = []() -> uint32_t
  {
    if constexpr(match) { return (_jsqr >> 5) | (uint32_t(_chconf::chan_num) << 15); }
    return _jsqr;
  }();

  if constexpr(sizeof...(_chconfs) > 0) {
    constexpr auto rank = match? _rank + 1 : _rank;
    static_assert(rank <= 3, "injected sequence must not have more than 4 channels");
    inj_seqence_configure<jofr_1, jofr_2, jofr_3, jofr_4, jsqr, _module_id, rank, _chconfs...>();
  }
  else
  if constexpr(match) {
    [[maybe_unused]] auto inst = detail::inst<_module_id>();
    inst->JSQR = jsqr | (_rank << ADC_JSQR_JL_Pos);
    switch(_rank) {
    case 3: inst->JOFR1 = jofr_1;
    case 2: inst->JOFR2 = jofr_2;
    case 1: inst->JOFR3 = jofr_3;
    case 0: inst->JOFR4 = jofr_4;
    }
  }
}

template<module_id _module_id, uint8_t _low, uint8_t _high, typename _chconf>
constexpr bool is_reg_chan_in_range()
{
  if constexpr(_chconf::dev_class == lmcu::dev_class::adc_reg_channel) {
    return _chconf::module.module_id == _module_id && _chconf::chan_num >= _low &&
           _chconf::chan_num <= _high;
  }
  return false;
}

template<module_id _module_id, uint8_t _low, uint8_t _high, typename _chconf,
         typename ..._chconfs>
constexpr uint32_t smpr_mask()
{
  constexpr auto r = []() -> uint32_t
  {
    if constexpr(is_reg_chan_in_range<_module_id, _low, _high, _chconf>()) {
      return uint32_t(0x7) << ((_chconf::chan_num - _low) * 3);
    }
    return 0;
  }();

  if constexpr(sizeof...(_chconfs) > 0) {
    return r | smpr_mask<_module_id, _low, _high, _chconfs...>();
  }
  return r;
}

template<module_id _module_id, uint8_t _low, uint8_t _high, typename _chconf,
         typename ..._chconfs>
constexpr uint32_t smpr_bits()
{
  constexpr auto r = []() -> uint32_t
  {
    if constexpr(is_reg_chan_in_range<_module_id, _low, _high, _chconf>()) {
      return uint32_t(_chconf::sample_time) << ((_chconf::chan_num - _low) * 3);
    }
    return 0;
  }();

  if constexpr(sizeof...(_chconfs) > 0) {
    return r | smpr_bits<_module_id, _low, _high, _chconfs...>();
  }
  return r;
}

template<module_id _module_id, typename ..._chconfs>
void sample_rate_conf()
{
  [[maybe_unused]] auto inst = detail::inst<_module_id>();

  {
    constexpr auto mask = smpr_mask<_module_id, 0, 9, _chconfs...>();
    if constexpr(mask != 0) {
      uint32_t r = inst->SMPR2;
      r &= ~mask;
      r |= smpr_bits<_module_id, 0, 9, _chconfs...>();
      inst->SMPR2 = r;
    }
  }

  {
    constexpr auto mask = smpr_mask<_module_id, 10, 17, _chconfs...>();
    if constexpr(mask != 0) {
      uint32_t r = inst->SMPR1;
      r &= ~mask;
      r |= smpr_bits<_module_id, 10, 17, _chconfs...>();
      inst->SMPR1 = r;
    }
  }
}

template<module_id _module_id, typename ..._chconfs>
void reg_chan_configure()
{
  reg_seqence_configure<0, 0, 0, 0, 0, 0, _module_id, 0, _chconfs...>();
  sample_rate_conf<_module_id, _chconfs...>();
}

template<module_id _module_id, typename ..._chconfs>
void inj_chan_configure()
{
  inj_seqence_configure<0, 0, 0, 0, 0, _module_id, 0, _chconfs...>();
  sample_rate_conf<_module_id, _chconfs...>();
}

template<typename _module, typename ..._modules>
void calibrate()
{
  auto inst = detail::inst<_module>();

  detail::disable<_module>();

  // wait 2 ADC cycles
  delay::cyc((rcc::system_clock() / rcc::adc_clock()) * 2);

  detail::enable<_module>();

  // reset calibration
  inst->CR2 |= ADC_CR2_RSTCAL;
  while((inst->CR2 & ADC_CR2_RSTCAL) != 0)
    ;

  // start calibration
  inst->CR2 |= ADC_CR2_CAL;
  while((inst->CR2 & ADC_CR2_CAL) != 0)
    ;

  if constexpr(sizeof...(_modules) > 0) { calibrate<_modules...>(); }
}

template<typename _module, typename ..._modules>
void regular_soft_start()
{
  detail::inst<_module>()->CR2 |= ADC_CR2_SWSTART;
  if constexpr(sizeof...(_modules) > 0) { regular_soft_start<_modules...>(); }
}

template<typename _module, typename ..._modules>
void injected_soft_start()
{
  detail::inst<_module>()->CR2 |= ADC_CR2_JSWSTART;
  if constexpr(sizeof...(_modules) > 0) { injected_soft_start<_modules...>(); }
}

template<typename _module>
uint32_t read() { return detail::inst<_module>()->DR; }

template<typename _module, uint8_t _jrank>
uint32_t read()
{
  static_assert(_jrank >= 1 && _jrank <= 4, "rank must be >= 1 and <= 4");

  auto inst = detail::inst<_module>();

  switch(_jrank) {
  case 1: return inst->JDR1;
  case 2: return inst->JDR2;
  case 3: return inst->JDR3;
  case 4: return inst->JDR4;
  default: break;
  }

  return 0;
}

template<typename _module>
uint32_t dma_address() { return uint32_t(&detail::inst<_module>()->DR); }

} // namespace detail
