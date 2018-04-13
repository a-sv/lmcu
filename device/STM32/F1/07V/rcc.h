#pragma once
#include "../rcc.h"

namespace lmcu {
namespace rcc {

enum class prediv1_mux { hse, pll2clk };

enum class pll_mux { hsi, prediv1 };

enum class i2s2_clk_mux { sysclk, pll3vco };
using i2s3_clk_mux = i2s2_clk_mux;

enum class mco_mux
{
  disabled,
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
  div_1 = 1,
  div_2,
  div_3,
  div_4,
  div_5,
  div_6,
  div_7,
  div_8,
  div_9,
  div_10,
  div_11,
  div_12,
  div_13,
  div_14,
  div_15,
  div_16
};
using prediv2 = prediv1;

enum class usb_prediv
{
  disabled, // USB not used
  div_2 = 2,
  div_3 = 3
};

enum class pll_mul
{
  mul_4   = 40,
  mul_5   = 50,
  mul_6   = 60,
  mul_6_5 = 65,
  mul_7   = 70,
  mul_8   = 80,
  mul_9   = 90
};

enum class pll2_mul
{
  mul_8  = 8,
  mul_9  = 9,
  mul_10 = 10,
  mul_11 = 11,
  mul_12 = 12,
  mul_13 = 13,
  mul_14 = 14,
  mul_16 = 16,
  mul_20 = 20
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
  prediv1 _prediv1 = prediv1::div_1,
  prediv1_mux _prediv1_mux = prediv1_mux::hse,
  prediv2 _prediv2 = prediv2::div_1,
  pll2_mul _pll2_mul = pll2_mul::mul_8,
  adc_prediv _adc_prediv = adc_prediv::disabled,
  usb_prediv _usb_prediv = usb_prediv::disabled,
  rtcclk_mux _rtc_clk_mux = rtcclk_mux::disabled,
  mco_mux _mco_mux = mco_mux::disabled,
  pll3_mul _pll3_mul = pll3_mul::mul_8,
  i2s2_clk_mux _i2s2_clk_mux = i2s2_clk_mux::sysclk,
  i2s3_clk_mux _i2s3_clk_mux = i2s3_clk_mux::sysclk,
  uint32_t _hsi_cal = 16
>
void configure()
{
  detail::osc_configure<_osc_type, _hsi_cal, _rtc_clk_mux>();

  if constexpr((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) {
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

    if constexpr(_usb_prediv != usb_prediv::disabled) {
      constexpr auto usbclk = (pllclk * 2) / uint32_t(_usb_prediv);
      static_assert(round<uint32_t>(usbclk) == 48_MHz, "USB clock must be = 48MHz");
    }

    if constexpr(_sysclk_mux == sysclk_mux::pllclk && _pll_mux == pll_mux::prediv1) {
      detail::configure_periph_clocks<round<uint32_t>(pllclk), _ahb_prediv, _apb1_prediv,
                                      _apb2_prediv, _adc_prediv>();
    }
  }

  if constexpr((_osc_type & osc_type::hsi) && _sysclk_mux == sysclk_mux::pllclk &&
               _pll_mux == pll_mux::hsi) {
    constexpr auto vco_in1 = double(8_MHz / 2);

    constexpr auto pllclk = (vco_in1 * uint32_t(_pll_mul)) / 10;
    static_assert(!(pllclk < 18_MHz || pllclk > 72_MHz), "PLLCLK must be >= 18Mhz and <= 72MHz");

    if constexpr(_usb_prediv != usb_prediv::disabled) {
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
  detail::osc_deconfigure<_osc_type, _rtc_clk_mux>();
}

} // namespace rcc
} // namespace lmcu
