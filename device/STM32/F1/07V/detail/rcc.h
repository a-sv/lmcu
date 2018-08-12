#pragma once

namespace detail {

template<
  apb1_prediv _apb1_prediv,
  apb2_prediv _apb2_prediv,
  ahb_prediv _ahb_prediv,
  sysclk_mux _sysclk_mux,
  css _css,
  pll_mul _pll_mul,
  pll_mux _pll_mux,
  osc_type _osc_type,
  prediv1 _prediv1,
  prediv1_mux _prediv1_mux,
  prediv2 _prediv2,
  pll2_mul _pll2_mul,
  adc_prediv _adc_prediv,
  usb_prediv _usb_prediv,
  mco_mux _mco_mux,
  pll3_mul _pll3_mul,
  i2s2_clk_mux _i2s2_clk_mux,
  i2s3_clk_mux _i2s3_clk_mux
>
void configure()
{
  if constexpr(
    ((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) &&
    (_sysclk_mux == sysclk_mux::hse || (_pll_mux == pll_mux::prediv1 &&
                                        _sysclk_mux == sysclk_mux::pllclk)) &&
    (_css == css::enable)
  ) {
    RCC->CR |= RCC_CR_CSSON;
  }
  else {
    RCC->CR &= ~RCC_CR_CSSON;
  }

  if constexpr(_sysclk_mux == sysclk_mux::hse) {
    configure_periph_clocks<HSE_VALUE, _ahb_prediv, _apb1_prediv, _apb2_prediv, _adc_prediv>();
  }

  if constexpr(_sysclk_mux == sysclk_mux::hsi) {
    configure_periph_clocks<8_MHz, _ahb_prediv, _apb1_prediv, _apb2_prediv, _adc_prediv>();
  }

  //
  // configure MCO mux
  //

  {
    uint32_t r = RCC->CFGR;
    r &= ~RCC_CFGR_MCO;
    switch(_mco_mux) {
    case mco_mux::sysclk:       r |= RCC_CFGR_MCOSEL_SYSCLK;    break;
    case mco_mux::hsi:          r |= RCC_CFGR_MCOSEL_HSI;       break;
    case mco_mux::hse:          r |= RCC_CFGR_MCOSEL_HSE;       break;
    case mco_mux::pllclk_div2:  r |= RCC_CFGR_MCOSEL_PLL_DIV2;  break;
    case mco_mux::pll2clk:      r |= RCC_CFGR_MCOSEL_PLL2;      break;
    case mco_mux::pll3clk_div2: r |= RCC_CFGR_MCOSEL_PLL3_DIV2; break;
    case mco_mux::xt1:          r |= RCC_CFGR_MCOSEL_EXT_HSE;   break;
    case mco_mux::pll3clk:      r |= RCC_CFGR_MCOSEL_PLL3CLK;   break;
    default : break;
    }
    RCC->CFGR = r;
  }

  //
  // configure PLL's
  //

  // PLL, PLL2, PLL3 disable
  RCC->CR &= ~(RCC_CR_PLLON | RCC_CR_PLL2ON | RCC_CR_PLL3ON);
  while((RCC->CR & (RCC_CR_PLLRDY | RCC_CR_PLL2RDY | RCC_CR_PLL3RDY)) != 0)
    ;

  {
    uint32_t r = RCC->CFGR;

    if constexpr(_sysclk_mux == sysclk_mux::pllclk) {
      if constexpr(_pll_mux == pll_mux::hsi) {
        r &= ~RCC_CFGR_PLLSRC;
      }
      else {
        // set PLL clock source to PREDIV1
        r |= RCC_CFGR_PLLSRC;
      }
      r &= ~RCC_CFGR_PLLMULL;
      switch(_pll_mul) {
      case pll_mul::mul_4:   r |= RCC_CFGR_PLLMULL4;   break;
      case pll_mul::mul_5:   r |= RCC_CFGR_PLLMULL5;   break;
      case pll_mul::mul_6:   r |= RCC_CFGR_PLLMULL6;   break;
      case pll_mul::mul_6_5: r |= RCC_CFGR_PLLMULL6_5; break;
      case pll_mul::mul_7:   r |= RCC_CFGR_PLLMULL7;   break;
      case pll_mul::mul_8:   r |= RCC_CFGR_PLLMULL8;   break;
      case pll_mul::mul_9:   r |= RCC_CFGR_PLLMULL9;   break;
      }
    }

    if constexpr(_usb_prediv == usb_prediv::div_3) {
      r &= ~RCC_CFGR_OTGFSPRE;
    }
    else {
      r |= RCC_CFGR_OTGFSPRE;
    }

    RCC->CFGR = r;
  }

  if constexpr((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) {
    {
      uint32_t r = RCC->CFGR2;

      if constexpr(_prediv1_mux == prediv1_mux::hse) {
        r &= ~RCC_CFGR2_PREDIV1SRC;
      }
      else {
        // set PREDIV1 source to PLL2CLK
        r |= RCC_CFGR2_PREDIV1SRC;
      }

      // set PREDIV1 value
      r &= ~RCC_CFGR2_PREDIV1;
      r |= (static_cast<uint32_t>(_prediv1) - 1) << RCC_CFGR2_PREDIV1_Pos;

      // set PREDIV2 value
      r &= ~RCC_CFGR2_PREDIV2;
      r |= (static_cast<uint32_t>(_prediv2) - 1) << RCC_CFGR2_PREDIV2_Pos;

      if constexpr(_prediv1_mux == prediv1_mux::pll2clk) {
        // set PLL2 multiplication factor
        r &= ~RCC_CFGR2_PLL2MUL;
        switch(_pll2_mul) {
        case pll2_mul::mul_8:  r |= RCC_CFGR2_PLL2MUL8;  break;
        case pll2_mul::mul_9:  r |= RCC_CFGR2_PLL2MUL9;  break;
        case pll2_mul::mul_10: r |= RCC_CFGR2_PLL2MUL10; break;
        case pll2_mul::mul_11: r |= RCC_CFGR2_PLL2MUL11; break;
        case pll2_mul::mul_12: r |= RCC_CFGR2_PLL2MUL12; break;
        case pll2_mul::mul_13: r |= RCC_CFGR2_PLL2MUL13; break;
        case pll2_mul::mul_14: r |= RCC_CFGR2_PLL2MUL14; break;
        case pll2_mul::mul_16: r |= RCC_CFGR2_PLL2MUL16; break;
        case pll2_mul::mul_20: r |= RCC_CFGR2_PLL2MUL20; break;
        }
      }

      if constexpr(_i2s2_clk_mux != i2s2_clk_mux::sysclk || _i2s3_clk_mux != i2s3_clk_mux::sysclk) {
        // set PLL3 multiplication factor
        r &= ~RCC_CFGR2_PLL3MUL;
        switch(_pll3_mul) {
        case pll3_mul::mul_8:  r |= RCC_CFGR2_PLL3MUL8;  break;
        case pll3_mul::mul_9:  r |= RCC_CFGR2_PLL3MUL9;  break;
        case pll3_mul::mul_10: r |= RCC_CFGR2_PLL3MUL10; break;
        case pll3_mul::mul_11: r |= RCC_CFGR2_PLL3MUL11; break;
        case pll3_mul::mul_12: r |= RCC_CFGR2_PLL3MUL12; break;
        case pll3_mul::mul_13: r |= RCC_CFGR2_PLL3MUL13; break;
        case pll3_mul::mul_14: r |= RCC_CFGR2_PLL3MUL14; break;
        case pll3_mul::mul_16: r |= RCC_CFGR2_PLL3MUL16; break;
        case pll3_mul::mul_20: r |= RCC_CFGR2_PLL3MUL20; break;
        }
      }

      if constexpr(_i2s2_clk_mux == i2s2_clk_mux::pll3vco) {
        r |= RCC_CFGR2_I2S2SRC;
      }
      else {
        r &= ~RCC_CFGR2_I2S2SRC;
      }

      if constexpr(_i2s3_clk_mux == i2s3_clk_mux::pll3vco) {
        r |= RCC_CFGR2_I2S3SRC;
      }
      else {
        r &= ~RCC_CFGR2_I2S3SRC;
      }

      RCC->CFGR2 = r;
    }

    if constexpr(_prediv1_mux == prediv1_mux::pll2clk) {
      // PLL2 enable
      RCC->CR |= RCC_CR_PLL2ON;
      while((RCC->CR & RCC_CR_PLL2RDY) == 0)
        ;
    }

    if constexpr(_i2s2_clk_mux != i2s2_clk_mux::sysclk || _i2s3_clk_mux != i2s3_clk_mux::sysclk) {
      // PLL3 enable
      RCC->CR |= RCC_CR_PLL3ON;
      while((RCC->CR & RCC_CR_PLL3RDY) == 0)
        ;
    }
  }

  if constexpr(_sysclk_mux == sysclk_mux::pllclk || _usb_prediv != usb_prediv::disable) {
    // PLL enable
    RCC->CR |= RCC_CR_PLLON;
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
      ;
  }
}

} // namespace detail
