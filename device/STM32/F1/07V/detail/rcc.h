#pragma once

namespace detail {

template<mco_mux _mco_mux>
void set_mco_mux()
{
  auto r = RCC->CFGR;
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

} // namespace detail
