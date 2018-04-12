#pragma once
#include "../rcc.h"

namespace lmcu {
namespace rcc {

enum class hse_pll_prediv { div_1 = 1, div_2 = 2 };

enum class usb_prediv
{
  disabled, // USB not used
  div_1   = 10,
  div_1_5 = 15
};

enum class pll_mul
{
  mul_2  = 2,
  mul_3  = 3,
  mul_4  = 4,
  mul_5  = 5,
  mul_6  = 6,
  mul_7  = 7,
  mul_8  = 8,
  mul_9  = 9,
  mul_10 = 10,
  mul_11 = 11,
  mul_12 = 12,
  mul_13 = 13,
  mul_14 = 14,
  mul_15 = 15,
  mul_16 = 16
};

enum class pll_mux { hse, hsi };

enum class mco_mux
{
  disabled,
  hse,
  hsi,
  sysclk,
  pllclk_div2
};

namespace detail {

template<mco_mux _mco_mux>
void set_mco_mux()
{
  auto r = RCC->CFGR;
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

} // namespace detail

template<
  apb1_prediv _apb1_prediv,
  apb2_prediv _apb2_prediv,
  ahb_prediv _ahb_prediv,
  sysclk_mux _sysclk_mux,
  css _css,
  pll_mul _pll_mul,
  pll_mux _pll_mux,
  osc_type _osc_type,
  hse_pll_prediv _hse_pll_prediv = hse_pll_prediv::div_1,
  adc_prediv _adc_prediv = adc_prediv::disabled,
  usb_prediv _usb_prediv = usb_prediv::disabled,
  rtcclk_mux _rtc_clk_mux = rtcclk_mux::disabled,
  mco_mux _mco_mux = mco_mux::disabled,
  uint32_t _hsi_cal = 16
>
void configure()
{
  detail::osc_configure<_osc_type, _hsi_cal, _rtc_clk_mux>();

  if constexpr(
    ((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) &&
    (_sysclk_mux == sysclk_mux::hse || (_pll_mux == pll_mux::hse &&
                                        _sysclk_mux == sysclk_mux::pllclk)) &&
    (_css == css::enabled)
  ) {
    RCC->CR |= RCC_CR_CSSON;
  }
  else {
    RCC->CR &= ~RCC_CR_CSSON;
  }

  {
    constexpr auto vco_in = (_pll_mux == pll_mux::hsi)?
        double(8_MHz / 2) : double(HSE_VALUE) / uint32_t(_hse_pll_prediv);
    static_assert(vco_in >= 1_MHz && vco_in <= 25_MHz, "VCO input must be >= 1MHz and <= 25MHz");

    constexpr auto pllclk = vco_in * uint32_t(_pll_mul);

    constexpr auto sysclk = []() -> double
    {
      switch(_sysclk_mux) {
      case sysclk_mux::hse: return HSE_VALUE;
      case sysclk_mux::pllclk: return pllclk;
      default: return 8_MHz;
      }
    }();

    if constexpr(_usb_prediv != usb_prediv::disabled) {
      constexpr auto usbclk = (pllclk * 10) / uint32_t(_usb_prediv);
      static_assert(round<uint32_t>(usbclk) == 48_MHz, "USB clock must be = 48MHz");
    }

    if constexpr(_mco_mux == mco_mux::pllclk_div2) {
      static_assert(pllclk / 2 <= 50_MHz, "MCO freq must be <= 50MHz");
    }

    if constexpr(_mco_mux == mco_mux::sysclk) {
      static_assert(sysclk <= 50_MHz, "MCO freq must be <= 50MHz");
    }

    detail::configure_periph_clocks<round<uint32_t>(sysclk), _ahb_prediv, _apb1_prediv,
                                    _apb2_prediv, _adc_prediv>();
  }

  detail::set_mco_mux<_mco_mux>();

  //
  // configure PLL
  //

  // PLL disable
  RCC->CR &= ~RCC_CR_PLLON;
  while((RCC->CR & RCC_CR_PLLRDY) != 0)
    ;

  {
    auto r = RCC->CFGR;

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

  if constexpr(_sysclk_mux == sysclk_mux::pllclk || _usb_prediv != usb_prediv::disabled) {
    // PLL enable
    RCC->CR |= RCC_CR_PLLON;
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
      ;
  }

  detail::switch_sysclk<_sysclk_mux>();
  detail::osc_deconfigure<_osc_type, _rtc_clk_mux>();
}

} // namespace lmcu
} // namespace rcc
