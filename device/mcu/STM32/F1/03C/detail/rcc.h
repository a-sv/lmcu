#pragma once

namespace detail {

template<
  sysclk_mux _sysclk_mux,
  css _css,
  pll_mul _pll_mul,
  pll_mux _pll_mux,
  osc_type _osc_type,
  hse_pll_prediv _hse_pll_prediv,
  usb_prediv _usb_prediv,
  mco_mux _mco_mux
>
void configure()
{
  if constexpr(
    flags::any(_osc_type, osc_type::hse, osc_type::hse_bypass) &&
    (_sysclk_mux == sysclk_mux::hse || (_pll_mux == pll_mux::hse &&
                                        _sysclk_mux == sysclk_mux::pllclk)) &&
    (_css == css::enable)
  ) {
    RCC->CR |= RCC_CR_CSSON;
  }
  else {
    RCC->CR &= ~RCC_CR_CSSON;
  }

  //
  // configure MCO mux
  //

  {
    uint32_t r = RCC->CFGR;
    r &= ~RCC_CFGR_MCO;
    switch(_mco_mux) {
    case mco_mux::sysclk:      r |= RCC_CFGR_MCOSEL_SYSCLK;   break;
    case mco_mux::hsi:         r |= RCC_CFGR_MCOSEL_HSI;      break;
    case mco_mux::hse:         r |= RCC_CFGR_MCOSEL_HSE;      break;
    case mco_mux::pllclk_div2: r |= RCC_CFGR_MCOSEL_PLL_DIV2; break;
    default : break;
    }
    RCC->CFGR = r;
  }

  //
  // configure PLL
  //

  // PLL disable
  RCC->CR &= ~RCC_CR_PLLON;
  while((RCC->CR & RCC_CR_PLLRDY) != 0)
    ;

  {
    uint32_t r = RCC->CFGR;

    if constexpr(_sysclk_mux == sysclk_mux::pllclk) {
      if constexpr(_pll_mux == pll_mux::hsi) {
        r &= ~RCC_CFGR_PLLSRC;
      }
      else {
        // set PLL clock source to PREDIV
        r |= RCC_CFGR_PLLSRC;
      }

      if constexpr(_hse_pll_prediv == hse_pll_prediv::div_2) {
        r |= RCC_CFGR_PLLXTPRE;
      }
      else {
        r &= ~RCC_CFGR_PLLXTPRE;
      }

      r &= ~RCC_CFGR_PLLMULL;
      switch(_pll_mul) {
      case pll_mul::mul_2:  r |= RCC_CFGR_PLLMULL2;  break;
      case pll_mul::mul_3:  r |= RCC_CFGR_PLLMULL3;  break;
      case pll_mul::mul_4:  r |= RCC_CFGR_PLLMULL4;  break;
      case pll_mul::mul_5:  r |= RCC_CFGR_PLLMULL5;  break;
      case pll_mul::mul_6:  r |= RCC_CFGR_PLLMULL6;  break;
      case pll_mul::mul_7:  r |= RCC_CFGR_PLLMULL7;  break;
      case pll_mul::mul_8:  r |= RCC_CFGR_PLLMULL8;  break;
      case pll_mul::mul_9:  r |= RCC_CFGR_PLLMULL9;  break;
      case pll_mul::mul_10: r |= RCC_CFGR_PLLMULL10; break;
      case pll_mul::mul_11: r |= RCC_CFGR_PLLMULL11; break;
      case pll_mul::mul_12: r |= RCC_CFGR_PLLMULL12; break;
      case pll_mul::mul_13: r |= RCC_CFGR_PLLMULL13; break;
      case pll_mul::mul_14: r |= RCC_CFGR_PLLMULL14; break;
      case pll_mul::mul_15: r |= RCC_CFGR_PLLMULL15; break;
      case pll_mul::mul_16: r |= RCC_CFGR_PLLMULL16; break;
      }
    }

    if constexpr(_usb_prediv == usb_prediv::div_1_5) {
      r &= ~RCC_CFGR_USBPRE;
    }
    else {
      r |= RCC_CFGR_USBPRE;
    }

    RCC->CFGR = r;
  }

  if constexpr(_sysclk_mux == sysclk_mux::pllclk || _usb_prediv != usb_prediv::disable) {
    // PLL enable
    RCC->CR |= RCC_CR_PLLON;
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
      ;
  }
}

} // namespace detail
