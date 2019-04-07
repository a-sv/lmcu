#pragma once

namespace detail {

template<typename _module>
ADC_TypeDef *inst()
{
  switch(_module::module_id)
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
void enable()
{
  auto inst = detail::inst<_module>();

  inst->CR2 |= ADC_CR2_ADON;
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

template<data_align _data_align, typename _cr2>
void set_data_align(_cr2&& cr2)
{
  if constexpr(_data_align == data_align::right) {
    cr2 &= ~ADC_CR2_ALIGN;
  }
  else {
    cr2 |=  ADC_CR2_ALIGN;
  }
}

template<typename _module, data_align _data_align>
void set_data_align() { set_data_align<_data_align>(detail::inst<_module>()->CR2); }

template<typename _module>
data_align get_data_align()
{
  if((detail::inst<_module>()->CR2 & ADC_CR2_ALIGN) == 0) { return data_align::right; }
  return data_align::left;
}

template<scan _scan, typename _cr1>
void set_scan(_cr1&& cr1)
{
  if constexpr(_scan == scan::disable) {
    cr1 &= ~ADC_CR1_SCAN;
  }
  else {
    cr1 |=  ADC_CR1_SCAN;
  }
}

template<typename _module, scan _scan>
void set_scan() { set_scan<_scan>(detail::inst<_module>()->CR1); }

template<typename _module>
scan get_scan()
{
  if((detail::inst<_module>()->CR1 & ADC_CR1_SCAN) == 0) { return scan::disable; }
  return scan::enable;
}

template<disc_mode _disc_mode, typename _cr1, typename _cr2>
void set_disc_mode(_cr1&& cr1, _cr2&& cr2)
{
  if constexpr(_disc_mode == disc_mode::regular) {
    cr1 |=  ADC_CR1_DISCEN;
  }
  else {
    cr1 &= ~ADC_CR1_DISCEN;
  }

  if constexpr(_disc_mode == disc_mode::injected) {
    cr1 |=  ADC_CR1_JDISCEN;
  }
  else {
    cr1 &= ~ADC_CR1_JDISCEN;
  }

  if constexpr(_disc_mode == disc_mode::disable) {
    cr2 |=  ADC_CR2_CONT;
  }
  else {
    cr2 &= ~ADC_CR2_CONT;
  }
}

template<typename _module, disc_mode _disc_mode>
void set_disc_mode()
{
  auto inst = detail::inst<_module>();
  uint32_t cr1 = inst->CR1, cr2 = inst->CR2;
  set_disc_mode<_disc_mode>(cr1, cr2);
  inst->CR1 = cr1;
  inst->CR2 = cr2;
}

template<typename _module>
disc_mode get_disc_mode()
{
  auto inst = detail::inst<_module>();

  const uint32_t cr1 = inst->CR1;

  if(cr1 & ADC_CR1_DISCEN)  { return disc_mode::regular;  }
  if(cr1 & ADC_CR1_JDISCEN) { return disc_mode::injected; }

  return disc_mode::disable;
}

template<reg_discnum _reg_discnum, typename _cr1>
void set_reg_discnum(_cr1&& cr1)
{
  cr1 &= ~ADC_CR1_DISCNUM;
  cr1 |= (uint32_t(_reg_discnum) << ADC_CR1_DISCNUM_Pos);
}

template<typename _module, reg_discnum _reg_discnum>
void set_reg_discnum()
{
  auto inst = detail::inst<_module>();
  uint32_t cr1 = inst->CR1;
  set_reg_discnum<_reg_discnum>(cr1);
  inst->CR1 = cr1;
}

template<typename _module>
reg_discnum get_reg_discnum()
{
  return reg_discnum( (detail::inst<_module>()->CR1 & ADC_CR1_DISCNUM) >> ADC_CR1_DISCNUM_Pos );
}

template<typename _module>
constexpr void reg_trig_check()
{
#if defined(ADC1)
    if constexpr(
      _module::reg_trig == reg_trig::tim1_cc1          ||
      _module::reg_trig == reg_trig::tim1_cc2          ||
      _module::reg_trig == reg_trig::tim1_cc3          ||
      _module::reg_trig == reg_trig::tim2_cc2          ||
      _module::reg_trig == reg_trig::tim3_trgo         ||
      _module::reg_trig == reg_trig::tim4_cc4          ||
      _module::reg_trig == reg_trig::exti11__tim8_trgo
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
      _module::reg_trig == reg_trig::tim5_cc3
    ) {
      static_assert(_module::module_id == module_id::adc3);
    }
#endif
}

template<reg_trig _reg_trig, typename _cr2>
void set_reg_trig(_cr2&& cr2)
{
  if constexpr(_reg_trig == reg_trig::disable) {
    cr2 &= ~ADC_CR2_EXTTRIG;
  }
  else {
    cr2 |=  ADC_CR2_EXTTRIG;
    cr2 &= ~ADC_CR2_EXTSEL;
    switch(_reg_trig) {
#if defined(ADC1)
    case reg_trig::tim1_cc2:          cr2 |= (1 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim1_cc3:          cr2 |= (2 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim2_cc2:          cr2 |= (3 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim3_trgo:         cr2 |= (4 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim4_cc4:          cr2 |= (5 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::exti11__tim8_trgo: cr2 |= (6 << ADC_CR2_EXTSEL_Pos); break;
#endif

#if defined(ADC3)
    case reg_trig::tim2_cc3:          cr2 |= (1 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim1_cc3:          cr2 |= (2 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim8_cc1:          cr2 |= (3 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim8_trgo:         cr2 |= (4 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim5_cc1:          cr2 |= (5 << ADC_CR2_EXTSEL_Pos); break;
    case reg_trig::tim5_cc3:          cr2 |= (6 << ADC_CR2_EXTSEL_Pos); break;
#endif
    case reg_trig::sw_start:          cr2 |= (7 << ADC_CR2_EXTSEL_Pos); break;
    default : break;
    }
  }
}

template<typename _module, reg_trig _reg_trig>
void set_reg_trig()
{
  reg_trig_check<_module>();

  auto inst = detail::inst<_module>();
  uint32_t cr2 = inst->CR2;
  set_reg_trig<_reg_trig>(cr2);
  inst->CR2 = cr2;
}

template<typename _module>
reg_trig get_reg_trig()
{
  const uint32_t cr2 = detail::inst<_module>()->CR2;

  if((cr2 & ADC_CR2_EXTTRIG) == 0) { return reg_trig::disable; }

  constexpr auto adc_1_2 = []
  {
#if defined(ADC1)
    if constexpr(_module::module_id == module_id::adc1) { return true; }
#endif

#if defined(ADC2)
    if constexpr(_module::module_id == module_id::adc2) { return true; }
#endif

    return false;
  }();

  if constexpr(adc_1_2) {
    switch(cr2 & ADC_CR2_EXTSEL) {
    case (1 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim1_cc2;
    case (2 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim1_cc3;
    case (3 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim2_cc2;
    case (4 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim3_trgo;
    case (5 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim4_cc4;
    case (6 << ADC_CR2_EXTSEL_Pos): return reg_trig::exti11__tim8_trgo;
    default: break;
    }
  }

#if defined(ADC3)
  if constexpr(_module::module_id == module_id::adc3) {
    switch(cr2 & ADC_CR2_EXTSEL) {
    case (1 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim2_cc3;
    case (2 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim1_cc3;
    case (3 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim8_cc1;
    case (4 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim8_trgo;
    case (5 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim5_cc1;
    case (6 << ADC_CR2_EXTSEL_Pos): return reg_trig::tim5_cc3;
    default: break;
    }
  }
#endif

  if((cr2 & (7 << ADC_CR2_EXTSEL_Pos)) != 0) { return reg_trig::sw_start; }
  return reg_trig::disable;
}

template<typename _module>
constexpr void inj_trig_check()
{
#if defined(ADC1)
    if constexpr(
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
      _module::inj_trig == inj_trig::tim4_cc3  ||
      _module::inj_trig == inj_trig::tim8_cc2  ||
      _module::inj_trig == inj_trig::tim8_cc4  ||
      _module::inj_trig == inj_trig::tim5_trgo ||
      _module::inj_trig == inj_trig::tim5_cc4
    ) {
      static_assert(_module::module_id == module_id::adc3);
    }
#endif
}

template<inj_trig _inj_trig, typename _cr2>
void set_inj_trig(_cr2&& cr2)
{
  if constexpr(_inj_trig == inj_trig::disable) {
    cr2 &= ~ADC_CR2_JEXTTRIG;
  }
  else {
    cr2 |=  ADC_CR2_JEXTTRIG;
    cr2 &= ~ADC_CR2_JEXTSEL;
    switch(_inj_trig) {
    case inj_trig::tim1_cc4:         cr2 |= (1 << ADC_CR2_JEXTSEL_Pos); break;

#if defined(ADC1)
    case inj_trig::tim2_trgo:        cr2 |= (2 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::tim2_cc1:         cr2 |= (3 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::tim3_cc4:         cr2 |= (4 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::tim4_trgo:        cr2 |= (5 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::exti15__tim8_cc4: cr2 |= (6 << ADC_CR2_JEXTSEL_Pos); break;
#endif

#if defined(ADC3)
    case inj_trig::tim4_cc3:         cr2 |= (2 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::tim8_cc2:         cr2 |= (3 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::tim8_cc4:         cr2 |= (4 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::tim5_trgo:        cr2 |= (5 << ADC_CR2_JEXTSEL_Pos); break;
    case inj_trig::tim5_cc4:         cr2 |= (6 << ADC_CR2_JEXTSEL_Pos); break;
#endif
    case inj_trig::jsw_start:        cr2 |= (7 << ADC_CR2_JEXTSEL_Pos); break;
    default: break;
    }
  }
}

template<typename _module, inj_trig _inj_trig>
void set_inj_trig()
{
  inj_trig_check<_module>();

  auto inst = detail::inst<_module>();
  uint32_t cr2 = inst->CR2;
  set_inj_trig<_inj_trig>(cr2);
  inst->CR2 = cr2;
}

template<typename _module>
inj_trig get_inj_trig()
{
  const uint32_t cr2 = detail::inst<_module>()->CR2;

  if((cr2 & ADC_CR2_JEXTTRIG) == 0) { return inj_trig::disable; }

  constexpr auto adc_1_2 = []
  {
#if defined(ADC1)
    if constexpr(_module::module_id == module_id::adc1) { return true; }
#endif

#if defined(ADC2)
    if constexpr(_module::module_id == module_id::adc2) { return true; }
#endif

    return false;
  }();

  if constexpr(adc_1_2) {
    switch(cr2 & ADC_CR2_JEXTSEL) {
    case (2 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim2_trgo;
    case (3 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim2_cc1;
    case (4 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim3_cc4;
    case (5 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim4_trgo;
    case (6 << ADC_CR2_JEXTSEL_Pos): return inj_trig::exti15__tim8_cc4;
    default: break;
    }
  }

#if defined(ADC3)
  if constexpr(_module::module_id == module_id::adc3) {
    switch(cr2 & ADC_CR2_JEXTSEL) {
    case (2 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim4_cc3;
    case (3 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim8_cc2;
    case (4 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim8_cc4;
    case (5 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim5_trgo;
    case (6 << ADC_CR2_JEXTSEL_Pos): return inj_trig::tim5_cc4;
    default: break;
    }
  }
#endif

  if((cr2 & (1 << ADC_CR2_JEXTSEL_Pos)) != 0) { return inj_trig::tim1_cc4;  }
  if((cr2 & (7 << ADC_CR2_JEXTSEL_Pos)) != 0) { return inj_trig::jsw_start; }

  return inj_trig::disable;
}

template<inj_auto _inj_auto, typename _cr1>
void set_inj_auto(_cr1&& cr1)
{
  if constexpr(_inj_auto == inj_auto::disable) {
    cr1 &= ~ADC_CR1_JAUTO;
  }
  else {
    cr1 |=  ADC_CR1_JAUTO;
  }
}

template<typename _module, inj_auto _inj_auto>
void set_inj_auto() { set_inj_auto<_inj_auto>(detail::inst<_module>()->CR1); }

template<typename _module>
inj_auto get_inj_auto()
{
  if((detail::inst<_module>()->CR1 & ADC_CR1_JAUTO) == 0) { return inj_auto::disable; }
  return inj_auto::enable;
}

template<dma _dma, typename _cr2>
void set_dma(_cr2&& cr2)
{
  if constexpr(_dma == dma::disable) {
    cr2 &= ~ADC_CR2_DMA;
  }
  else {
    cr2 |=  ADC_CR2_DMA;
  }
}

template<typename _module, dma _dma>
void set_dma() { set_dma<_dma>(detail::inst<_module>()->CR2); }

template<typename _module>
dma get_dma()
{
  if((detail::inst<_module>()->CR2 & ADC_CR2_DMA) == 0) { return dma::disable; }
  return dma::enable;
}

template<dual_mode _dual_mode, typename _cr1>
void set_dual_mode(_cr1&& cr1)
{
  cr1 &= ~ADC_CR1_DUALMOD;
  switch(_dual_mode)
  {
  case dual_mode::regular_and_injected:    cr1 |= (1 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::regular_and_trigger:     cr1 |= (2 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::injected_and_fast_inter: cr1 |= (3 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::injected_and_slow_inter: cr1 |= (4 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::injected_only:           cr1 |= (5 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::regular_only:            cr1 |= (6 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::fast_inter_only:         cr1 |= (7 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::slow_inter_only:         cr1 |= (8 << ADC_CR1_DUALMOD_Pos); break;
  case dual_mode::trigger_only:            cr1 |= (9 << ADC_CR1_DUALMOD_Pos); break;
  default: break;
  }
}

template<typename _module, dual_mode _dual_mode>
void set_dual_mode()
{
  auto inst = detail::inst<_module>();
  uint32_t cr1 = inst->CR1;
  set_dual_mode<_dual_mode>(cr1);
  inst->CR1 = cr1;
}

template<typename _module>
dual_mode get_dual_mode()
{
  const uint32_t cr1 = detail::inst<_module>()->CR1;

  switch(cr1 & ADC_CR1_DUALMOD) {
  case (1 << ADC_CR1_DUALMOD_Pos): return dual_mode::regular_and_injected;
  case (2 << ADC_CR1_DUALMOD_Pos): return dual_mode::regular_and_trigger;
  case (3 << ADC_CR1_DUALMOD_Pos): return dual_mode::injected_and_fast_inter;
  case (4 << ADC_CR1_DUALMOD_Pos): return dual_mode::injected_and_slow_inter;
  case (5 << ADC_CR1_DUALMOD_Pos): return dual_mode::injected_only;
  case (6 << ADC_CR1_DUALMOD_Pos): return dual_mode::regular_only;
  case (7 << ADC_CR1_DUALMOD_Pos): return dual_mode::fast_inter_only;
  case (8 << ADC_CR1_DUALMOD_Pos): return dual_mode::slow_inter_only;
  case (9 << ADC_CR1_DUALMOD_Pos): return dual_mode::trigger_only;
  default: break;
  }

  return dual_mode::independent;
}

template<temp_refint _temp_refint, typename _cr2>
void set_temp_refint(_cr2&& cr2)
{
  if constexpr(_temp_refint == temp_refint::disable) {
    cr2 &= ~ADC_CR2_TSVREFE;
  }
  else
  if((cr2 & ADC_CR2_TSVREFE) == 0) {
    cr2 |=  ADC_CR2_TSVREFE;
    delay::us(10);
  }
}

template<typename _module, temp_refint _temp_refint>
void set_temp_refint()
{
  auto inst = detail::inst<_module>();
  uint32_t cr2 = inst->CR2;
  set_temp_refint<_module, _temp_refint>(cr2);
  inst->CR2 = cr2;
}

template<typename _module>
temp_refint get_temp_refint()
{
  if((detail::inst<_module>()->CR2 & ADC_CR2_TSVREFE) == 0) { return temp_refint::disable; }
  return temp_refint::enable;
}

template<awd_mode _awd_mode, typename _cr1>
void set_awd_mode(_cr1&& cr1)
{
  cr1 &= ~(ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN);
  switch(_awd_mode) {
  case awd_mode::all_injected:
    cr1 |= ADC_CR1_JAWDEN;
    break;
  case awd_mode::all_regular:
    cr1 |= ADC_CR1_AWDEN;
    break;
  case awd_mode::all_injected_and_regular:
    cr1 |= (ADC_CR1_AWDEN | ADC_CR1_JAWDEN);
    break;
  case awd_mode::single_injected:
    cr1 |= (ADC_CR1_AWDSGL | ADC_CR1_JAWDEN);
    break;
  case awd_mode::single_regular:
    cr1 |= (ADC_CR1_AWDSGL | ADC_CR1_AWDEN);
    break;
  case awd_mode::single_regular_or_injected:
    cr1 |= (ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN);
    break;
  default: break;
  }
}

template<typename _module, awd_mode _awd_mode>
void set_awd_mode() { set_awd_mode<_awd_mode>(detail::inst<_module>()->CR1); }

template<typename _module>
awd_mode get_awd_mode()
{
  const uint32_t cr1 = detail::inst<_module>()->CR1;

  switch(cr1 & (ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN)) {
  case ADC_CR1_JAWDEN:
    return awd_mode::all_injected;
  case ADC_CR1_AWDEN:
    return awd_mode::all_regular;
  case (ADC_CR1_AWDEN | ADC_CR1_JAWDEN):
    return awd_mode::all_injected_and_regular;
  case (ADC_CR1_AWDSGL | ADC_CR1_JAWDEN):
    return awd_mode::single_injected;
  case (ADC_CR1_AWDSGL | ADC_CR1_AWDEN):
    return awd_mode::single_regular;
  case (ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN):
    return awd_mode::single_regular_or_injected;
  default: break;
  }

  return awd_mode::disable;
}

template<awd_channel _awd_channel, typename _cr1>
void set_awd_channel(_cr1&& cr1)
{
  cr1 &= ~(ADC_CR1_AWDCH);
  cr1 |= (uint32_t(_awd_channel) << ADC_CR1_AWDCH_Pos);
}

template<typename _module, awd_channel _awd_channel>
void set_awd_channel()
{
  auto inst = detail::inst<_module>();
  uint32_t cr1 = inst->CR1;
  set_awd_channel<_awd_channel>(cr1);
  inst->CR1 = cr1;
}

template<typename _module>
awd_channel get_awd_channel()
{
  const uint32_t cr1 = detail::inst<_module>()->CR1;
  return awd_channel( (cr1 & ADC_CR1_AWDCH) >> ADC_CR1_AWDCH_Pos );
}

template<typename _module>
void set_awd_low(uint16_t val) { detail::inst<_module>()->LTR = val & 0xFFF; }

template<typename _module>
uint16_t get_awd_low() { return detail::inst<_module>()->LTR & 0xFFF; }

template<typename _module>
void set_awd_high(uint16_t val) { detail::inst<_module>()->HTR = val & 0xFFF; }

template<typename _module>
uint16_t get_awd_high() { return detail::inst<_module>()->HTR & 0xFFF; }

template<typename _module>
void adc_configure()
{
  auto inst = detail::inst<_module>();

  detail::disable<_module>();

  reg_trig_check<_module>();
  inj_trig_check<_module>();

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

  if constexpr(_module::awd_mode != awd_mode::disable) {
    set_awd_low<_module>(_module::awd_low);
    set_awd_high<_module>(_module::awd_high);
  }

  uint32_t cr1 = inst->CR1;
  uint32_t cr2 = inst->CR2;

  set_dual_mode<_module::dual_mode>(cr1);
  set_disc_mode<_module::disc_mode>(cr1, cr2);
  set_reg_discnum<_module::reg_discnum>(cr1);
  set_inj_auto<_module::inj_auto>(cr1);
  set_scan<_module::scan>(cr1);
  set_awd_mode<_module::awd_mode>(cr1);
  set_awd_channel<_module::awd_channel>(cr1);
  set_temp_refint<_module::temp_refint>(cr2);
  set_reg_trig<_module::reg_trig>(cr2);
  set_inj_trig<_module::inj_trig>(cr2);
  set_data_align<_module::data_align>(cr2);
  set_dma<_module::dma>(cr2);

  inst->CR1 = cr1;
  inst->CR2 = cr2;

  if constexpr(_module::irq.irq_type != nvic::irq_type::disable) {
#ifdef _LMCU_DEVICE_STM32F1_
    nvic::enable_irq<decltype(_module::irq), ADC1_2_IRQn>();
#endif

#ifdef _LMCU_DEVICE_STM32F4_
    nvic::enable_irq<decltype(_module::irq), ADC_IRQn>();
#endif
  }
}

template<
  uint32_t _mask_1,
  uint32_t _bits_1,
  uint32_t _mask_2,
  uint32_t _bits_2,
  uint32_t _mask_3,
  uint32_t _bits_3,
  typename _module,
  uint8_t _rank,
  typename _chconf,
  typename ..._chconfs
>
constexpr void reg_seqence_configure()
{
  static_assert(_chconf::dev_class == dev_class::adc_reg_channel ||
                _chconf::dev_class == dev_class::adc_inj_channel, "config is not a channel");
  static_assert(_chconf::module.module_id == _module::module_id, "invalid channel module id");

  constexpr auto match = _chconf::dev_class == dev_class::adc_reg_channel;

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
    reg_seqence_configure<mask_1, bits_1, mask_2, bits_2, mask_3, bits_3, _module,
                          match? _rank + 1 : _rank, _chconfs...>();
  }
  else
  if constexpr(match) {
    [[maybe_unused]] auto inst = detail::inst<_module>();

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
  typename _module,
  uint8_t _rank,
  typename _chconf,
  typename ..._chconfs
>
constexpr void inj_seqence_configure()
{
  static_assert(_chconf::dev_class == dev_class::adc_reg_channel ||
                _chconf::dev_class == dev_class::adc_inj_channel, "config is not a channel");
  static_assert(_chconf::module.module_id == _module::module_id, "invalid channel module id");

  constexpr auto match = _chconf::dev_class == dev_class::adc_inj_channel;

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
    inj_seqence_configure<jofr_1, jofr_2, jofr_3, jofr_4, jsqr, _module, rank, _chconfs...>();
  }
  else
  if constexpr(match) {
    auto inst = detail::inst<_module>();
    inst->JSQR = jsqr | (_rank << ADC_JSQR_JL_Pos);
    switch(_rank) {
    case 3: inst->JOFR1 = jofr_1;
    case 2: inst->JOFR2 = jofr_2;
    case 1: inst->JOFR3 = jofr_3;
    case 0: inst->JOFR4 = jofr_4;
    }
  }
}

template<typename _module, uint8_t _low, uint8_t _high, typename _chconf>
constexpr bool channel_in_range()
{
  if constexpr(
    _chconf::dev_class == dev_class::adc_reg_channel ||
    _chconf::dev_class == dev_class::adc_inj_channel
  ) {
    return _chconf::module.module_id == _module::module_id && _chconf::chan_num >= _low &&
           _chconf::chan_num <= _high;
  }
  return false;
}

template<typename _module, uint8_t _low, uint8_t _high, typename _chconf, typename ..._chconfs>
constexpr uint32_t smpr_mask()
{
  constexpr auto r = []() -> uint32_t
  {
    if constexpr(channel_in_range<_module, _low, _high, _chconf>()) {
      return uint32_t(0x7) << ((_chconf::chan_num - _low) * 3);
    }
    return 0;
  }();

  if constexpr(sizeof...(_chconfs) > 0) {
    return r | smpr_mask<_module, _low, _high, _chconfs...>();
  }
  return r;
}

template<typename _module, uint8_t _low, uint8_t _high, typename _chconf, typename ..._chconfs>
constexpr uint32_t smpr_bits()
{
  constexpr auto r = []() -> uint32_t
  {
    if constexpr(channel_in_range<_module, _low, _high, _chconf>()) {
      return uint32_t(_chconf::sample_time) << ((_chconf::chan_num - _low) * 3);
    }
    return 0;
  }();

  if constexpr(sizeof...(_chconfs) > 0) {
    return r | smpr_bits<_module, _low, _high, _chconfs...>();
  }
  return r;
}

template<typename _module, typename ..._chconfs>
void sample_rate_conf()
{
  [[maybe_unused]] auto inst = detail::inst<_module>();

  {
    constexpr auto mask = smpr_mask<_module, 0, 9, _chconfs...>();
    if constexpr(mask != 0) {
      uint32_t r = inst->SMPR2;
      r &= ~mask;
      r |= smpr_bits<_module, 0, 9, _chconfs...>();
      inst->SMPR2 = r;
    }
  }

  {
    constexpr auto mask = smpr_mask<_module, 10, 17, _chconfs...>();
    if constexpr(mask != 0) {
      uint32_t r = inst->SMPR1;
      r &= ~mask;
      r |= smpr_bits<_module, 10, 17, _chconfs...>();
      inst->SMPR1 = r;
    }
  }
}

template<typename _module, typename ..._chconfs>
void reg_chan_configure()
{
  reg_seqence_configure<0, 0, 0, 0, 0, 0, _module, 0, _chconfs...>();
  sample_rate_conf<_module, _chconfs...>();
}

template<typename _module, typename ..._chconfs>
void inj_chan_configure()
{
  inj_seqence_configure<0, 0, 0, 0, 0, _module, 0, _chconfs...>();
  sample_rate_conf<_module, _chconfs...>();
}

template<typename _module, typename ..._modules>
void calibrate()
{
  auto inst = detail::inst<_module>();

  detail::disable<_module>();

  // wait 2 ADC cycles
  delay::cyc((rcc::hardware_clock() / rcc::adc_clock()) * 2);

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

template<typename _module, event ..._events>
event get_flags() { return flags::from_value<event>(detail::inst<_module>()->SR); }

template<typename _module, event ..._events>
void clear_flags()
{
  auto inst = detail::inst<_module>();

  constexpr auto events = (_events + ...);
  static_assert(flags::none(events, event::eoc), "use 'read' function for clear EOC event");

  uint32_t r = 0;
  if constexpr(flags::all(events, event::awd))    { r |= ADC_SR_AWD;   }
  if constexpr(flags::all(events, event::jeoc))   { r |= ADC_SR_JEOC;  }
  if constexpr(flags::all(events, event::jstart)) { r |= ADC_SR_JSTRT; }
  if constexpr(flags::all(events, event::start))  { r |= ADC_SR_STRT;  }
  inst->SR = ~r;
}

template<typename _module, event ..._events>
void enable_events()
{
  auto inst = detail::inst<_module>();

  constexpr auto events = (_events + ...);

  static_assert(flags::none(events, event::start, event::jstart), "events 'start' and 'jstart' "
                                                                  "cannot be enabled");

  uint32_t r = inst->CR1;
  if constexpr(flags::all(events, event::awd))  { r |= ADC_CR1_AWDIE;  }
  if constexpr(flags::all(events, event::eoc))  { r |= ADC_CR1_EOCIE;  }
  if constexpr(flags::all(events, event::jeoc)) { r |= ADC_CR1_JEOCIE; }
  inst->CR1 = r;
}

template<typename _module, event ..._events>
void disable_events()
{
  auto inst = detail::inst<_module>();

  constexpr auto events = (_events + ...);

  static_assert(flags::none(events, event::start, event::jstart), "events 'start' and 'jstart' "
                                                                  "cannot be disabled");

  uint32_t r = inst->CR1;
  if constexpr(flags::all(events, event::awd))  { r &= ~ADC_CR1_AWDIE;  }
  if constexpr(flags::all(events, event::eoc))  { r &= ~ADC_CR1_EOCIE;  }
  if constexpr(flags::all(events, event::jeoc)) { r &= ~ADC_CR1_JEOCIE; }
  inst->CR1 = r;
}

template<typename _module>
event irq_source() { return flags::from_value<event>(detail::inst<_module>()->SR & 0x7); }

template<typename _module>
uint32_t dma_address() { return uint32_t(&detail::inst<_module>()->DR); }

} // namespace detail
