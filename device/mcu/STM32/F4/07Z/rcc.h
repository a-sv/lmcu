#pragma once
#include "../rcc.h"

namespace lmcu::rcc {

#include "detail/rcc.h"

template<
  apb1_prediv _apb1_prediv,
  apb2_prediv _apb2_prediv,
  ahb_prediv _ahb_prediv,
  sysclk_mux _sysclk_mux,
  css _css,
  pll_m _pll_m,
  pll_n _pll_n,
  pll_p _pll_p,
  pll_mux _pll_mux,
  osc_type _osc_type,
  pll_q _pll_q = pll_q::disable,
  rtcclk_mux _rtcclk_mux = rtcclk_mux::disable,
  rtchse_prediv _rtchse_prediv = rtchse_prediv::div_2,
  mco1_mux _mco1_mux = mco1_mux::disable,
  mco1_prediv _mco1_prediv = mco1_prediv::div_1,
  mco2_mux _mco2_mux = mco2_mux::disable,
  mco2_prediv _mco2_prediv = mco2_prediv::div_1,
  i2sclk_mux _i2sclk_mux = i2sclk_mux::extclk,
  plli2s_n _plli2s_n = plli2s_n::mul_192,
  plli2s_r _plli2s_r = plli2s_r::div_2,
  uint32_t _hsi_cal = 16
>
void configure()
{
  constexpr auto pll_m_out = ((_pll_mux == pll_mux::hsi)? double(16_MHz) : double(HSE_VALUE)) /
                              double(_pll_m);
  static_assert(pll_m_out >= 0.95_MHz && pll_m_out <= 2.1_MHz, "PLLM output frequency must be >= "
                                                               "0.95MHz and <= 2.1MHz");
  constexpr auto pll_n_out = pll_m_out * double(_pll_n);
  constexpr auto pll_p_out = pll_n_out / double(_pll_p);
  static_assert(pll_p_out >= 24_MHz && pll_p_out <= 175_MHz, "PLLP output frequency must be >= "
                                                             "24MHz and <= 175MHz");
  if constexpr(_pll_q != pll_q::disable) {
    constexpr auto pll_q_out = pll_n_out / double(_pll_q);
    static_assert(pll_q_out <= 75_MHz, "PLLQ output frequency must be <= 75MHz");
  }

  constexpr auto sysclk = []() -> double
  {
    switch(_sysclk_mux)
    {
    case sysclk_mux::hsi   : return 16_MHz;
    case sysclk_mux::hse   : return HSE_VALUE;
    case sysclk_mux::pllclk: return pll_p_out;
    }
  }();
  static_assert(sysclk <= 168_MHz, "system clock frequency must be <= 168MHz");

  constexpr auto hclk = sysclk / double(_ahb_prediv);
  static_assert(hclk >= 14.2_MHz && hclk <= 168_MHz, "AHB clock must be >= 14.2MHz and <= 168MHz");

  constexpr auto apb1clk = hclk / double(_apb1_prediv);
  static_assert(apb1clk <= 42_MHz, "APB1 clock must be <= 42MHz");

  constexpr auto apb2clk = hclk / double(_apb2_prediv);
  static_assert(apb2clk <= 84_MHz, "APB1 clock must be <= 84MHz");

  if constexpr(_i2sclk_mux != i2sclk_mux::extclk) {
    constexpr auto plli2s_n_out = pll_m_out * double(_plli2s_n);
    static_assert(plli2s_n_out >= 100_MHz && plli2s_n_out <= 432_MHz, "PLLI2S_N output frequency "
                                                                      "must be >= 100MHz and <= "
                                                                      "432MHz");
    constexpr auto plli2s_r_out = plli2s_n_out / double(_plli2s_r);
    static_assert(plli2s_r_out <= 216_MHz, "PLLI2S_R output frequency must be <= 216MHz");
  }

  if constexpr(_mco1_mux != mco1_mux::disable) {
    if constexpr(_mco1_mux == mco1_mux::lse) {
      static_assert(flags::any(_osc_type, osc_type::lse, osc_type::lse_bypass),
                    "MCO1 set to LSE, but LSE generator turned off");
    }
    if constexpr(_mco1_mux == mco1_mux::hse) {
      static_assert(flags::any(_osc_type, osc_type::hse, osc_type::hse_bypass),
                    "MCO1 set to HSE, but HSE generator turned off");
    }
  }

  detail::configure<_apb1_prediv, _apb2_prediv, _ahb_prediv, _sysclk_mux, _css, _pll_m, _pll_n,
                    _pll_p, _pll_mux, _osc_type, _pll_q, _rtcclk_mux, _rtchse_prediv, _mco1_mux,
                    _mco1_prediv, _mco2_mux, _mco2_prediv, _i2sclk_mux, _plli2s_n, _plli2s_r,
                    _hsi_cal>();

  detail::system_clock   = round<uint32_t>(sysclk);
  detail::hardware_clock = round<uint32_t>(hclk);
  detail::apb1_clock     = round<uint32_t>(apb1clk);
  detail::apb2_clock     = round<uint32_t>(apb2clk);
  detail::adc_clock      = round<uint32_t>(apb2clk);
}

} // namespace lmcu::rcc
