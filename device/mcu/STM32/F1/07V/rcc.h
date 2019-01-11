#pragma once
#include "../rcc.h"

namespace lmcu::rcc {

enum class prediv1_mux { hse, pll2clk };

enum class pll_mux { hsi, prediv1 };

enum class i2s2_clk_mux { sysclk, pll3vco };
using i2s3_clk_mux = i2s2_clk_mux;

enum class mco_mux
{
  disable,
  hse,
  hsi,
  sysclk,
  pllclk_div2,
  pll2clk,
  pll3clk,
  pll3clk_div2,
  xt1
};

enum class prediv1
{
  _1 = 1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7,
  _8,
  _9,
  _10,
  _11,
  _12,
  _13,
  _14,
  _15,
  _16
};
using prediv2 = prediv1;

enum class usb_prediv
{
  disable, // USB not used
  _2 = 2,
  _3 = 3
};

enum class pll_mul
{
  _4   = 40,
  _5   = 50,
  _6   = 60,
  _6_5 = 65,
  _7   = 70,
  _8   = 80,
  _9   = 90
};

enum class pll2_mul
{
  _8  = 8,
  _9  = 9,
  _10 = 10,
  _11 = 11,
  _12 = 12,
  _13 = 13,
  _14 = 14,
  _16 = 16,
  _20 = 20
};
using pll3_mul = pll2_mul;

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
  prediv1 _prediv1 = prediv1::_1,
  prediv1_mux _prediv1_mux = prediv1_mux::hse,
  prediv2 _prediv2 = prediv2::_1,
  pll2_mul _pll2_mul = pll2_mul::_8,
  adc_prediv _adc_prediv = adc_prediv::disable,
  usb_prediv _usb_prediv = usb_prediv::disable,
  rtcclk_mux _rtcclk_mux = rtcclk_mux::disable,
  mco_mux _mco_mux = mco_mux::disable,
  pll3_mul _pll3_mul = pll3_mul::_8,
  i2s2_clk_mux _i2s2_clk_mux = i2s2_clk_mux::sysclk,
  i2s3_clk_mux _i2s3_clk_mux = i2s3_clk_mux::sysclk,
  uint32_t _hsi_cal = 16
>
void configure()
{
  detail::osc_configure<_osc_type, _hsi_cal, _rtcclk_mux>();

  if constexpr(flags::any(_osc_type, osc_type::hse, osc_type::hse_bypass)) {
    constexpr auto vco_in2 = double(HSE_VALUE) / uint32_t(_prediv2);

    if constexpr(
      _prediv1_mux == prediv1_mux::pll2clk ||
      _i2s2_clk_mux != i2s2_clk_mux::sysclk ||
      _i2s3_clk_mux != i2s3_clk_mux::sysclk
    ) {
      static_assert(!(vco_in2 < 3_MHz || vco_in2 > 5_MHz), "PLL2 / PLL3 VCO input must be >= 3Mhz "
                                                           "and <= 5MHz");
    }

    constexpr auto pll2clk = vco_in2 * uint32_t(_pll2_mul);
    if constexpr(_prediv1_mux == prediv1_mux::pll2clk) {
      static_assert(!(pll2clk < 40_MHz || vco_in2 > 74_MHz), "PLL2CLK must be >= 40Mhz and <= "
                                                             "74MHz");
    }

    if constexpr(_i2s2_clk_mux != i2s2_clk_mux::sysclk || _i2s3_clk_mux != i2s3_clk_mux::sysclk) {
      constexpr auto pll3vco = vco_in2 * uint32_t(_pll3_mul) * 2;
      static_assert(!(pll3vco < 80_MHz || pll3vco > 148_MHz), "PLL2CLK must be >= 40Mhz and "
                                                              "<= 74MHz");
    }

    constexpr auto vco_in1 = (_prediv1_mux == prediv1_mux::hse)?
      (double(HSE_VALUE) / uint32_t(_prediv1)) : (pll2clk / uint32_t(_prediv1));
    if constexpr(_pll_mux == pll_mux::prediv1) {
      static_assert(!(vco_in1 < 3_MHz || vco_in1 > 12_MHz), "PLL VCO input must be >= 3Mhz and "
                                                            "<= 12MHz");
    }

    constexpr auto pllclk = (vco_in1 * uint32_t(_pll_mul)) / 10;
    if constexpr(_pll_mux == pll_mux::prediv1) {
      static_assert(!(pllclk < 18_MHz || pllclk > 72_MHz), "PLLCLK must be >= 18Mhz and <= 72MHz");
    }

    if constexpr(_usb_prediv != usb_prediv::disable) {
      constexpr auto usbclk = (pllclk * 2) / uint32_t(_usb_prediv);
      static_assert(round<uint32_t>(usbclk) == 48_MHz, "USB clock must be = 48MHz");
    }

    if constexpr(_sysclk_mux == sysclk_mux::pllclk && _pll_mux == pll_mux::prediv1) {
      detail::configure_periph_clocks<round<uint32_t>(pllclk), _ahb_prediv, _apb1_prediv,
                                      _apb2_prediv, _adc_prediv>();
    }
  }

  if constexpr(flags::all(_osc_type, osc_type::hsi) && _sysclk_mux == sysclk_mux::pllclk &&
               _pll_mux == pll_mux::hsi) {
    constexpr auto vco_in1 = double(8_MHz / 2);

    constexpr auto pllclk = (vco_in1 * uint32_t(_pll_mul)) / 10;
    static_assert(!(pllclk < 18_MHz || pllclk > 72_MHz), "PLLCLK must be >= 18Mhz and <= 72MHz");

    if constexpr(_usb_prediv != usb_prediv::disable) {
      constexpr auto usbclk = (pllclk * 2) / uint32_t(_usb_prediv);
      static_assert(round<uint32_t>(usbclk) == 48_MHz, "USB clock must be = 48MHz");
    }

    detail::configure_periph_clocks<round<uint32_t>(pllclk), _ahb_prediv, _apb1_prediv,
                                    _apb2_prediv, _adc_prediv>();
  }

  detail::configure<_apb1_prediv, _apb2_prediv, _ahb_prediv, _sysclk_mux, _css, _pll_mul, _pll_mux,
                    _osc_type, _prediv1, _prediv1_mux, _prediv2, _pll2_mul, _adc_prediv,
                    _usb_prediv, _mco_mux, _pll3_mul, _i2s2_clk_mux, _i2s3_clk_mux>();

  detail::switch_sysclk<_sysclk_mux>();
  detail::osc_deconfigure<_osc_type, _rtcclk_mux>();
}

} // namespace lmcu::rcc
