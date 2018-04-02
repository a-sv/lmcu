#pragma once
#include "../rcc.h"

namespace lmcu {
namespace rcc {

namespace detail {

template<osc_type _osc_type, uint32_t _hsi_cal, rtcclk_mux _rtc_clk_mux>
void osc_config()
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
  if constexpr((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass)) {
    static_assert(_rtc_clk_mux == rtcclk_mux::lse, "LSE generator turned on, but not used");
  }
  if constexpr(_rtc_clk_mux == rtcclk_mux::hse) {
    static_assert(
      (_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass),
      "HSE generator selected as RTC clock, but HSE is disabled"
    );
  }

  // switch system clock to HSI
  RCC->CR |= RCC_CR_HSION;
  while((RCC->CR & RCC_CR_HSIRDY) == 0)
    ;
  RCC->CFGR &= ~RCC_CFGR_SW;
  while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
    ;

  //
  // HSE
  //

  if constexpr((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) {
    auto r = RCC->CR;
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
  else {
    RCC->CR &= ~(RCC_CR_HSEON | RCC_CR_HSEBYP);
    while((RCC->CR & RCC_CR_HSERDY) != 0)
      ;
  }

  //
  // HSI
  //

  if constexpr(_osc_type & osc_type::hsi) {
    auto r = RCC->CR;
    r &= ~RCC_CR_HSITRIM;
    if constexpr(_hsi_cal != 0) { r |= (_hsi_cal << RCC_CR_HSITRIM_Pos); }
    RCC->CR = r;
  }

  //
  // LSE
  //

  if constexpr((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass)) {
    // enable power clock
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    // enable write access to backup domain
    PWR->CR |= PWR_CR_DBP;
    while((PWR->CR & PWR_CR_DBP) == 0)
      ;

    auto r = RCC->BDCR;
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
  else {
    RCC->BDCR &= ~(RCC_BDCR_LSEON | RCC_BDCR_LSEBYP);
    while((RCC->BDCR & RCC_BDCR_LSERDY) != 0)
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
  else {
    RCC->CSR &= ~RCC_CSR_LSION;
    while((RCC->CSR & RCC_CSR_LSIRDY) != 0)
      ;
  }

  //
  // select RTC clock source
  //

  {
    auto r = RCC->BDCR;
    r &= ~RCC_BDCR_RTCSEL;
    switch (_rtc_clk_mux) {
    case rtcclk_mux::lse: r |= RCC_BDCR_RTCSEL_LSE; break;
    case rtcclk_mux::lsi: r |= RCC_BDCR_RTCSEL_LSI; break;
    case rtcclk_mux::hse: r |= RCC_BDCR_RTCSEL_HSE; break;
    default : break;
    }
    RCC->BDCR = r;
  }
}

} // namespace detail

} // namespace rcc
} // namespace lmcu
