#pragma once
#include "../rcc.h"

namespace lmcu {
namespace rcc {

enum class hse_pll_prediv { div_1 = 1, div_2 = 2 };

enum class usb_prediv
{
  disable, // USB not used
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
  disable,
  hse,
  hsi,
  sysclk,
  pllclk_div2
};

#include "detail/rcc.h"

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
  adc_prediv _adc_prediv = adc_prediv::disable,
  usb_prediv _usb_prediv = usb_prediv::disable,
  rtcclk_mux _rtcclk_mux = rtcclk_mux::disable,
  mco_mux _mco_mux = mco_mux::disable,
  uint32_t _hsi_cal = 16
>
void configure()
{
  detail::osc_configure<_osc_type, _hsi_cal, _rtcclk_mux>();

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

    if constexpr(_usb_prediv != usb_prediv::disable) {
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

  detail::configure<_sysclk_mux, _css, _pll_mul, _pll_mux, _osc_type, _hse_pll_prediv, _usb_prediv,
                    _mco_mux>();

  detail::switch_sysclk<_sysclk_mux>();
  detail::osc_deconfigure<_osc_type, _rtcclk_mux>();
}

} // namespace lmcu
} // namespace rcc
