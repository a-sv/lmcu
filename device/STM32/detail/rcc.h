#pragma once

namespace detail {

extern uint32_t system_clock;
extern uint32_t hardware_clock;
extern uint32_t apb1_clock;
extern uint32_t apb2_clock;
extern uint32_t adc_clock;
extern uint32_t apb1_timer_clock;
extern uint32_t apb2_timer_clock;

template<bool _on>
void set_bkp_write_acces()
{
  if constexpr(_on) {
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_DBP;
    while((PWR->CR & PWR_CR_DBP) == 0)
      ;
  }
  else {
    PWR->CR &= ~PWR_CR_DBP;
    while((PWR->CR & PWR_CR_DBP) != 0)
      ;
    RCC->APB1ENR &= ~RCC_APB1ENR_PWREN;
  }
}

template<sysclk_mux _sysclk_mux>
void switch_sysclk()
{
  uint32_t r = RCC->CFGR;
  r &= ~RCC_CFGR_SW;
  switch(_sysclk_mux) {
  case sysclk_mux::hse:    r |= RCC_CFGR_SW_HSE; break;
  case sysclk_mux::pllclk: r |= RCC_CFGR_SW_PLL; break;
  default : break;
  }
  RCC->CFGR = r;

  switch(_sysclk_mux) {
  case sysclk_mux::hsi:
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
      ;
    break;
  case sysclk_mux::hse:
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE)
      ;
    break;
  case sysclk_mux::pllclk:
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
      ;
    break;
  }
}

template<osc_type _osc_type, uint32_t _hsi_cal, rtcclk_mux _rtcclk_mux>
void osc_configure()
{
  static_assert(_hsi_cal <= 0x1f);
  static_assert(!((_osc_type & osc_type::hse) && (_osc_type & osc_type::hse_bypass)),
                "unable to enable hse and hse_bypass mode together");
  static_assert(!((_osc_type & osc_type::lse) && (_osc_type & osc_type::lse_bypass)),
                "unable to enable lse and lse_bypass mode together");
  static_assert(
    !(((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass)) &&
      (_osc_type & osc_type::lsi)),
    "unable to enable lse* and lsi mode together"
  );
  static_assert(
    (_osc_type & osc_type::hse) ||
    (_osc_type & osc_type::hse_bypass) ||
    (_osc_type & osc_type::hsi),
    "you must select at least one of high speed generators"
  );
  if constexpr(_osc_type & osc_type::lsi) {
    static_assert(_rtcclk_mux == rtcclk_mux::lsi, "LSI generator turned on, but not used");
  }
  if constexpr(_rtcclk_mux == rtcclk_mux::lsi) {
    static_assert(_osc_type & osc_type::lsi, "RTC clock source connected to LSI, but LSI "
                                             "turned off");
  }
  if constexpr((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass)) {
    static_assert(_rtcclk_mux == rtcclk_mux::lse, "LSE generator turned on, but not used");
  }
  if constexpr(_rtcclk_mux == rtcclk_mux::lse) {
    static_assert((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass),
                  "RTC clock source connected to LSE, but LSE turned off");
  }
  if constexpr(_rtcclk_mux == rtcclk_mux::hse) {
    static_assert(
      (_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass),
      "HSE generator selected as RTC clock, but HSE is disabled"
    );
  }

  dwt::enable_cyccnt();

  //
  // HSI
  //

  if constexpr(_osc_type & osc_type::hsi) {
    uint32_t r = RCC->CR;
    r &= ~RCC_CR_HSITRIM;
    if constexpr(_hsi_cal != 0) { r |= (_hsi_cal << RCC_CR_HSITRIM_Pos); }
    RCC->CR = r;
  }

  RCC->CR |= RCC_CR_HSION;
  while((RCC->CR & RCC_CR_HSIRDY) == 0)
    ;
  switch_sysclk<sysclk_mux::hsi>();

  //
  // HSE
  //

  if constexpr((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) {
    uint32_t r = RCC->CR;
    if constexpr(_osc_type & osc_type::hse_bypass) {
      r |= RCC_CR_HSEBYP;
    }
    else {
      r &= ~RCC_CR_HSEBYP;
    }
    r |= RCC_CR_HSEON;
    RCC->CR = r;
    while((RCC->CR & RCC_CR_HSERDY) == 0)
      ;
  }

  set_bkp_write_acces<true>();

  //
  // LSE
  //

  if constexpr((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass)) {
    uint32_t r = RCC->BDCR;
    if constexpr(_osc_type & osc_type::lse_bypass) {
      r |= RCC_BDCR_LSEBYP;
    }
    else {
      r &= ~RCC_BDCR_LSEBYP;
    }
    r |= RCC_BDCR_LSEON;
    RCC->BDCR = r;

    while((RCC->BDCR & RCC_BDCR_LSERDY) == 0)
      ;
  }

  //
  // LSI
  //

  if constexpr(_osc_type & osc_type::lsi) {
    RCC->CSR |= RCC_CSR_LSION;
    while((RCC->CSR & RCC_CSR_LSIRDY) == 0)
      ;
  }

  //
  // select RTC clock source
  //

  {
    uint32_t r = RCC->BDCR;
    r &= ~RCC_BDCR_RTCSEL;
    switch (_rtcclk_mux) {
    case rtcclk_mux::lse: r |= (1 << RCC_BDCR_RTCSEL_Pos); break;
    case rtcclk_mux::lsi: r |= (2 << RCC_BDCR_RTCSEL_Pos); break;
    case rtcclk_mux::hse: r |= (3 << RCC_BDCR_RTCSEL_Pos); break;
    default : break;
    }
    RCC->BDCR = r;
  }
}

template<osc_type _osc_type, rtcclk_mux _rtcclk_mux>
void osc_deconfigure()
{
  //
  // HSI
  //

  if constexpr(!(_osc_type & osc_type::hsi)) {
    RCC->CR &= ~RCC_CR_HSION;
    while((RCC->CR & RCC_CR_HSIRDY) != 0)
      ;
  }

  //
  // HSE
  //

  if constexpr(!((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass))) {
    RCC->CR &= ~(RCC_CR_HSEON | RCC_CR_HSEBYP);
    while((RCC->CR & RCC_CR_HSERDY) != 0)
      ;
  }

  //
  // LSI
  //

  if constexpr(!(_osc_type & osc_type::lsi)) {
    RCC->CSR &= ~RCC_CSR_LSION;
    while((RCC->CSR & RCC_CSR_LSIRDY) != 0)
      ;
  }

  //
  // LSE
  //

  if constexpr(!((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass))) {
    RCC->BDCR &= ~(RCC_BDCR_LSEON | RCC_BDCR_LSEBYP);
    while((RCC->BDCR & RCC_BDCR_LSERDY) != 0)
      ;
  }

  if constexpr(_rtcclk_mux == rtcclk_mux::disable || _rtcclk_mux == rtcclk_mux::lsi) {
    set_bkp_write_acces<false>();
  }
}

template<ahb_prediv _ahb_prediv, apb1_prediv _apb1_prediv, apb2_prediv _apb2_prediv>
void set_hw_clocks()
{
  uint32_t r = RCC->CFGR;
  r &= ~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2);

  switch(_ahb_prediv) {
  case ahb_prediv::div_2:   r |= RCC_CFGR_HPRE_DIV2;   break;
  case ahb_prediv::div_4:   r |= RCC_CFGR_HPRE_DIV4;   break;
  case ahb_prediv::div_8:   r |= RCC_CFGR_HPRE_DIV8;   break;
  case ahb_prediv::div_16:  r |= RCC_CFGR_HPRE_DIV16;  break;
  case ahb_prediv::div_64:  r |= RCC_CFGR_HPRE_DIV64;  break;
  case ahb_prediv::div_128: r |= RCC_CFGR_HPRE_DIV128; break;
  case ahb_prediv::div_256: r |= RCC_CFGR_HPRE_DIV256; break;
  case ahb_prediv::div_512: r |= RCC_CFGR_HPRE_DIV512; break;
  default : break;
  }

  switch(_apb1_prediv) {
  case apb1_prediv::div_2:  r |= RCC_CFGR_PPRE1_DIV2;  break;
  case apb1_prediv::div_4:  r |= RCC_CFGR_PPRE1_DIV4;  break;
  case apb1_prediv::div_8:  r |= RCC_CFGR_PPRE1_DIV8;  break;
  case apb1_prediv::div_16: r |= RCC_CFGR_PPRE1_DIV16; break;
  default : break;
  }

  switch(_apb2_prediv) {
  case apb2_prediv::div_2:  r |= RCC_CFGR_PPRE2_DIV2;  break;
  case apb2_prediv::div_4:  r |= RCC_CFGR_PPRE2_DIV4;  break;
  case apb2_prediv::div_8:  r |= RCC_CFGR_PPRE2_DIV8;  break;
  case apb2_prediv::div_16: r |= RCC_CFGR_PPRE2_DIV16; break;
  default : break;
  }

  RCC->CFGR = r;
}

} // namespace detail
