#pragma once

namespace detail {

template<port _port, bool _low, typename _pin, typename ..._pins>
constexpr auto cr_bits()
{
  constexpr auto cr_cnf = []() -> uint32_t
  {
    if constexpr(_pin::mode == mode::analog) { return 0; }

    if constexpr(_pin::mode == mode::input) {
      if constexpr(_pin::pull == pull::no_pull) { return 0b01; }
      if constexpr(_pin::pull == pull::down || _pin::pull == pull::up) { return 0b10;}
    }

    if constexpr(_pin::mode == mode::output_push_pull) { return 0; }
    if constexpr(_pin::mode == mode::output_open_drain) { return 0b01; }
    if constexpr(_pin::mode == mode::af_push_pull) { return 0b10; }
    if constexpr(_pin::mode == mode::af_open_drain) { return 0b11; }
  };

  constexpr auto cr_mode = []() -> uint32_t
  {
    if constexpr(_pin::mode == mode::input || _pin::mode == mode::analog) { return 0; }
    if constexpr(_pin::speed == speed::low) { return 0b10; }
    if constexpr(_pin::speed == speed::medium) { return 0b01; }
    if constexpr(_pin::speed == speed::high || _pin::speed == speed::very_high) { return 0b11; }
  };

  [[maybe_unused]] constexpr auto cr = (cr_cnf() << 2) | cr_mode();

  constexpr auto bit = []() -> uint32_t
  {
    if constexpr(_pin::port == _port) {
      if constexpr(_low) {
        if constexpr(_pin::bit < 8) { return cr << (_pin::bit * 4); }
      }
      else {
        if constexpr(_pin::bit >= 8) { return cr << ((_pin::bit - 8) * 4); }
      }
    }
    return 0;
  };

  if constexpr(sizeof...(_pins) > 0) { return bit() | cr_bits<_port, _low, _pins...>(); }
  return bit();
}

template<port _port, typename _pin, typename ..._pins>
constexpr auto pull_bits()
{
  if constexpr(_pin::pull != pull::no_pull) {
    static_assert(_pin::mode == mode::input || _pin::mode == mode::analog,
                  "pull's supported only in input pin mode");
  }

  constexpr auto bit = []() -> uint32_t
  {
    if constexpr(_pin::port == _port && _pin::pull != pull::no_pull) {
      return _pin::pull == pull::up? (1 << _pin::bit) : (0x10000 << _pin::bit);
    }
    return 0;
  };

  if constexpr(sizeof...(_pins) > 0) { return bit() | pull_bits<_port, _pins...>(); }
  return bit();
}

template<port _port, typename ..._pins>
void configure_port(GPIO_TypeDef *inst)
{
  if constexpr(!pins_in_port<_port, _pins...>()) { return; }

  if constexpr(pin_in_range<_port, 0, 7, _pins...>()) {
    constexpr auto mask4 = ~mask<_port, 4, 0, 0, 7, _pins...>();
    inst->CRL = (inst->CRL & mask4) | cr_bits<_port, true, _pins...>();
  }

  if constexpr(pin_in_range<_port, 8, 15, _pins...>()) {
    constexpr auto mask4 = ~mask<_port, 4, 8, 8, 15, _pins...>();
    inst->CRH = (inst->CRH & mask4) | cr_bits<_port, false, _pins...>();
  }

  constexpr auto pb = pull_bits<_port, _pins...>();
  if constexpr(pb != 0) { inst->BSRR = pb; }
}

template<port _port, port ..._ports>
constexpr auto rcc_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
#if defined(RCC_APB2ENR_IOPAEN)
    if constexpr(_port == port::A) { return RCC_APB2ENR_IOPAEN; }
#endif

#if defined(RCC_APB2ENR_IOPBEN)
    if constexpr(_port == port::B) { return RCC_APB2ENR_IOPBEN; }
#endif

#if defined(RCC_APB2ENR_IOPCEN)
    if constexpr(_port == port::C) { return RCC_APB2ENR_IOPCEN; }
#endif

#if defined(RCC_APB2ENR_IOPDEN)
    if constexpr(_port == port::D) { return RCC_APB2ENR_IOPDEN; }
#endif

#if defined(RCC_APB2ENR_IOPEEN)
    if constexpr(_port == port::E) { return RCC_APB2ENR_IOPEEN; }
#endif

#if defined(RCC_APB2ENR_IOPFEN)
    if constexpr(_port == port::F) { return RCC_APB2ENR_IOPFEN; }
#endif

#if defined(RCC_APB2ENR_IOPGEN)
    if constexpr(_port == port::G) { return RCC_APB2ENR_IOPGEN; }
#endif

#if defined(RCC_APB2ENR_IOPHEN)
    if constexpr(_port == port::H) { return RCC_APB2ENR_IOPHEN; }
#endif

#if defined(RCC_APB2ENR_IOPIEN)
    if constexpr(_port == port::I) { return RCC_APB2ENR_IOPIEN; }
#endif

#if defined(RCC_APB2ENR_IOPJEN)
    if constexpr(_port == port::J) { return RCC_APB2ENR_IOPJEN; }
#endif

#if defined(RCC_APB2ENR_IOPKEN)
    if constexpr(_port == port::K) { return RCC_APB2ENR_IOPKEN; }
#endif
    return 0;
  };

  if constexpr(sizeof...(_ports) > 0) { return bit() | rcc_bits<_ports...>(); }
  return bit();
}

template<port ..._ports>
void enable(bool afio_on)
{
  constexpr auto rcc_bits = []() -> uint32_t
  {
    if constexpr(sizeof...(_ports) > 0) { return detail::rcc_bits<_ports...>(); }
    return 0;
  }();

  RCC->APB2ENR |= rcc_bits | (afio_on? RCC_APB2ENR_AFIOEN : 0);
}

template<port ..._ports>
void disable(bool afio_off)
{
  constexpr auto rcc_bits = []() -> uint32_t
  {
    if constexpr(sizeof...(_ports) > 0) { return detail::rcc_bits<_ports...>(); }
    return 0;
  }();

  RCC->APB2ENR &= ~(rcc_bits | (afio_off? RCC_APB2ENR_AFIOEN : 0));
}

constexpr uint32_t mapr_mask_table[] = {
  //
  // MAPR
  //

  1 << 30, // PTP_PPS_REMAP
  1 << 30, // PTP_PPS_REMAP

  1 << 29, // TIM2ITR1_IREMAP
  1 << 29, // TIM2ITR1_IREMAP

  1 << 28, // SPI3_REMAP
  1 << 28, // SPI3_REMAP

  7 << 24, // SWJ_CFG
  7 << 24, // SWJ_CFG
  7 << 24, // SWJ_CFG
  7 << 24, // SWJ_CFG

  1 << 23, // MII_RMII_SEL
  1 << 23, // MII_RMII_SEL

  1 << 22, // CAN2_REMAP
  1 << 22, // CAN2_REMAP

  1 << 21, // ETH_REMAP
  1 << 21, // ETH_REMAP

  1 << 20, // ADC2_ETRGREG_REMAP
  1 << 20, // ADC2_ETRGREG_REMAP
  1 << 19, // ADC2_ETRGINJ_REMAP
  1 << 19, // ADC2_ETRGINJ_REMAP

  1 << 18, // ADC1_ETRGREG_REMAP
  1 << 18, // ADC1_ETRGREG_REMAP
  1 << 17, // ADC1_ETRGINJ_REMAP
  1 << 17, // ADC1_ETRGINJ_REMAP

  1 << 16, // TIM5CH4_IREMAP
  1 << 16, // TIM5CH4_IREMAP

  1 << 15, // PD01_REMAP
  1 << 15, // PD01_REMAP

  3 << 13, // CAN_REMAP
  3 << 13, // CAN_REMAP
  3 << 13, // CAN_REMAP

  1 << 12, // TIM4_REMAP
  1 << 12, // TIM4_REMAP

  3 << 10, // TIM3_REMAP
  3 << 10, // TIM3_REMAP
  3 << 10, // TIM3_REMAP

  3 << 8,  // TIM2_REMAP
  3 << 8,  // TIM2_REMAP
  3 << 8,  // TIM2_REMAP
  3 << 8,  // TIM2_REMAP

  3 << 6,  // TIM1_REMAP
  3 << 6,  // TIM1_REMAP
  3 << 6,  // TIM1_REMAP

  3 << 4,  // USART3_REMAP
  3 << 4,  // USART3_REMAP
  3 << 4,  // USART3_REMAP

  1 << 3,  // USART2_REMAP
  1 << 3,  // USART2_REMAP

  1 << 2,  // USART1_REMAP
  1 << 2,  // USART1_REMAP

  1 << 1,  // I2C1_REMAP
  1 << 1,  // I2C1_REMAP

  1 << 0,  // SPI1_REMAP
  1 << 0,  // SPI1_REMAP

  //
  // MAPR2
  //

  1 << 10, // FSMC_NADV
  1 << 10, // FSMC_NADV

  1 << 9,  // TIM14_REMAP
  1 << 9,  // TIM14_REMAP

  1 << 8,  // TIM13_REMAP
  1 << 8,  // TIM13_REMAP

  1 << 7,  // TIM11_REMAP
  1 << 7,  // TIM11_REMAP

  1 << 6,  // TIM10_REMAP
  1 << 6,  // TIM10_REMAP

  1 << 5,  // TIM9_REMAP
  1 << 5   // TIM9_REMAP
};

constexpr uint32_t mapr_bits_table[] = {
  //
  // MAPR
  //

  0,       // ptp_pps__not_output_on_PB5
  1 << 30, // ptp_pps__output_on_PB5

  0,       // tim2_itr1__ptp
  1 << 29, // tim2_itr1__usb_otg_sof

  0,       // spi3_i2s3__no_remap
  1 << 28, // spi3_i2s3__remap

  0,       // jtag__full_swj
  1 << 24, // jtag__full_swj_without_njtrst
  2 << 24, // jtag__dp_disabled_and_sw_dp_enabled
  4 << 24, // jtag__dp_and_sw_dp_disabled

  0,       // eth__mii_phy
  1 << 23, // eth__rmii_phy

  0,       // can2__no_remap
  1 << 22, // can2__remap

  0,       // eth__no_remap
  1 << 21, // eth__remap

  0,       // adc2__etrgreg_exti11
  1 << 20, // adc2__etrgreg_tim8_trgo

  0,       // adc2__etrginj_exti15
  1 << 19, // adc2__etrginj_tim8_channel4

  0,       // adc1__etrgreg_exti11
  1 << 18, // adc1__etrgreg_tim8_trgo

  0,       // adc1__etrginj_exti15
  1 << 17, // adc1__etrginj_tim8_channel4

  0,       // tim5__ch4_PA3
  1 << 16, // tim5__ch4_lsiclk

  0,       // PD0_no_remap__PD1_no_remap
  1 << 15, // PD0_osc_in__PD1_osc_out

  0,       // can1__no_remap
  2 << 13, // can1__remap_1
  3 << 13, // can1__remap_2

  0,       // tim4__no_remap
  1 << 12, // tim4__full_remap

  0,       // tim3__no_remap
  2 << 10, // tim3__partial_remap
  3 << 10, // tim3__full_remap

  0,       // tim2__no_remap
  1 << 8,  // tim2__partial_remap_1
  2 << 8,  // tim2__partial_remap_2
  3 << 8,  // tim2__full_remap

  0,       // tim1__no_remap
  1 << 6,  // tim1__partial_remap
  3 << 6,  // tim1__full_remap

  0,       // usart3__no_remap
  1 << 4,  // usart3__partial_remap
  3 << 4,  // usart3__full_remap

  0,       // usart2__no_remap
  1 << 3,  // usart2__remap

  0,       // usart1__no_remap
  1 << 2,  // usart1__remap

  0,       // i2c1__no_remap
  1 << 1,  // i2c1__remap

  0,       // spi1__no_remap
  1,       // spi1__remap

  //
  // MAPR2
  //

  0,       // fsmc__nadv_connected
  1 << 10, // fsmc__nadv_not_connected

  0,       // tim14__no_remap
  1 << 9,  // tim14__remap

  0,       // tim13__no_remap
  1 << 8,  // tim13__remap

  0,       // tim11__no_remap
  1 << 7,  // tim11__remap

  0,       // tim10__no_remap
  1 << 6,  // tim10__remap

  0,       // tim9__no_remap
  1 << 5,  // tim9__remap
};

constexpr auto mapr2_index = 54;

template<remap _remap, remap ..._remaps>
constexpr uint32_t mapr_mask()
{
  constexpr auto idx = uint32_t(_remap);
  constexpr auto r   = (idx < mapr2_index)? mapr_mask_table[idx] : 0;
  if constexpr(sizeof...(_remaps) > 0) { return r | mapr_mask<_remaps...>(); }
  return r;
}

template<remap _remap, remap ..._remaps>
constexpr uint32_t mapr2_mask()
{
  constexpr auto idx = uint32_t(_remap);
  constexpr auto r   = (idx >= mapr2_index)? mapr_mask_table[idx] : 0;
  if constexpr(sizeof...(_remaps) > 0) { return r | mapr2_mask<_remaps...>(); }
  return r;
}

template<remap _remap, remap ..._remaps>
constexpr uint32_t mapr_bits()
{
  constexpr auto idx = uint32_t(_remap);
  constexpr auto r   = (idx < mapr2_index)? mapr_bits_table[idx] : 0;
  if constexpr(sizeof...(_remaps) > 0) { return r | mapr_bits<_remaps...>(); }
  return r;
}

template<remap _remap, remap ..._remaps>
constexpr uint32_t mapr2_bits()
{
  constexpr auto idx = uint32_t(_remap);
  constexpr auto r   = (idx >= mapr2_index)? mapr_bits_table[idx] : 0;
  if constexpr(sizeof...(_remaps) > 0) { return r | mapr2_bits<_remaps...>(); }
  return r;
}

template<remap ..._remaps>
void remap()
{
  {
    constexpr auto mask = mapr_mask<_remaps...>();
    if constexpr(mask != 0) {
      uint32_t r = AFIO->MAPR;
      r &= ~mask;
      r |=  mapr_bits<_remaps...>();
      AFIO->MAPR = r;
    }
  }

  {
    constexpr auto mask = mapr2_mask<_remaps...>();
    if constexpr(mask != 0) {
      uint32_t r = AFIO->MAPR2;
      r &= ~mask;
      r |=  mapr2_bits<0, _remaps...>();
      AFIO->MAPR2 = r;
    }
  }
}

} // namespace detail
