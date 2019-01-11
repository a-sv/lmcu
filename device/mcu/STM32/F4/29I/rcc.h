#pragma once
#include "../rcc.h"

namespace lmcu::rcc {

using plli2s_q = pll_q;

enum class plli2s_div_q
{
  _1 = 0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13,
  _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25,
  _26, _27, _28, _29, _30, _31, _32
};

using pllsai_n = pll_n;

enum class pllsai_q
{
  _2 = 2,
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
  _15
};

enum class pllsai_r
{
  disable = 1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7
};

using pllsai_div_q = plli2s_div_q;

enum class pllsai_div_r
{
  _2,
  _4,
  _8,
  _16
};

enum class sai1_a_mux { pllsai, plli2s, extclk };
using sai1_b_mux = sai1_a_mux;

enum class timpre
{
  /* If the APB prescaler (PPRE1, PPRE2 in the RCC_CFGR register) is configured to a
   * division factor of 1, TIMxCLK = PCLKx. Otherwise, the timer clock frequencies are set to
   * twice to the frequency of the APB domain to which the timers are connected:
   * TIMxCLK = 2xPCLKx.
  */
  pre_0,

  /* If the APB prescaler (PPRE1, PPRE2 in the RCC_CFGR register) is configured to a
   * division factor of 1, 2 or 4, TIMxCLK = HCLK. Otherwise, the timer clock frequencies are set
   * to four times to the frequency of the APB domain to which the timers are connected:
   * TIMxCLK = 4xPCLKx.
  */
  pre_1
};

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
  timpre _timpre = timpre::pre_0,
  rtcclk_mux _rtcclk_mux = rtcclk_mux::disable,
  rtchse_prediv _rtchse_prediv = rtchse_prediv::_2,
  mco1_mux _mco1_mux = mco1_mux::disable,
  mco1_prediv _mco1_prediv = mco1_prediv::_1,
  mco2_mux _mco2_mux = mco2_mux::disable,
  mco2_prediv _mco2_prediv = mco2_prediv::_1,
  i2sclk_mux _i2sclk_mux = i2sclk_mux::extclk,
  plli2s_n _plli2s_n = plli2s_n::_192,
  plli2s_r _plli2s_r = plli2s_r::_2,
  plli2s_q _plli2s_q = plli2s_q::_2,
  plli2s_div_q _plli2s_div_q = plli2s_div_q::_1,
  pllsai_n _pllsai_n = pllsai_n::_50,
  pllsai_q _pllsai_q = pllsai_q::_2,
  pllsai_r _pllsai_r = pllsai_r::disable,
  pllsai_div_q _pllsai_div_q = pllsai_div_q::_1,
  pllsai_div_r _pllsai_div_r = pllsai_div_r::_2,
  sai1_a_mux _sai1_a_mux = sai1_a_mux::pllsai,
  sai1_b_mux _sai1_b_mux = sai1_b_mux::pllsai,
  uint32_t _hsi_cal = 16
>
void configure()
{
  constexpr auto pll_m_out = ((_pll_mux == pll_mux::hsi)? double(16_MHz) : double(HSE_VALUE)) /
                              double(_pll_m);
  static_assert(pll_m_out >= 0.95_MHz && pll_m_out <= 2.1_MHz, "PLLM output frequency must be >= "
                                                               "0.95MHz and <= 2.1MHz");
  constexpr auto pll_n_out = pll_m_out * double(_pll_n);
  static_assert(pll_n_out >= 100_MHz && pll_n_out <= 432_MHz, "PLLN output frequency must be >= "
                                                              "100MHz and <= 432MHz");
  constexpr auto pll_p_out = pll_n_out / double(_pll_p);
  static_assert(pll_p_out >= 24_MHz && pll_p_out <= 180_MHz, "PLLP output frequency must be >= "
                                                             "24MHz and <= 180MHz");
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
  static_assert(sysclk <= 180_MHz, "system clock frequency must be <= 180MHz");

  constexpr auto hclk = sysclk / double(_ahb_prediv);
  static_assert(hclk >= 14.2_MHz && hclk <= 180_MHz, "AHB clock must be >= 14.2MHz and <= 180MHz");

  constexpr auto apb1clk = hclk / double(_apb1_prediv);
  static_assert(apb1clk >= 0.128_MHz && apb1clk <= 45_MHz, "APB1 clock must be >= 0.128MHz and <= "
                                                           "45MHz");

  constexpr auto apb2clk = hclk / double(_apb2_prediv);
  static_assert(apb2clk <= 90_MHz, "APB1 clock must be <= 90MHz");


  constexpr auto plli2s_n_out = pll_m_out * double(_plli2s_n);
  constexpr auto plli2s_r_out = plli2s_n_out / double(_plli2s_r);
  constexpr auto plli2s_q_out = plli2s_n_out / double(_plli2s_q);

  if constexpr(
    _i2sclk_mux == i2sclk_mux::plli2s ||
    _sai1_a_mux == sai1_a_mux::plli2s ||
    _sai1_b_mux == sai1_b_mux::plli2s
  ) {
    static_assert(plli2s_n_out >= 100_MHz && plli2s_n_out <= 432_MHz, "PLLI2S_N output frequency "
                                                                      "must be >= 100MHz and <= "
                                                                      "432MHz");
    if constexpr(_i2sclk_mux == i2sclk_mux::plli2s) {
      static_assert(plli2s_r_out <= 216_MHz, "PLLI2S_R output frequency must be <= 216MHz");
    }

    if constexpr(_sai1_a_mux == sai1_a_mux::plli2s || _sai1_b_mux == sai1_b_mux::plli2s) {
      static_assert(plli2s_q_out <= 216_MHz, "PLLI2S_Q output frequency must be <= 216MHz");
    }
  }

  constexpr auto pllsai_n_out = pll_m_out * double(_pllsai_n);
  constexpr auto pllsai_q_out = pllsai_n_out / double(_pllsai_q);
  constexpr auto pllsai_r_out = pllsai_n_out / double(_pllsai_r);

  if constexpr(
    _sai1_a_mux == sai1_a_mux::pllsai ||
    _sai1_b_mux == sai1_b_mux::pllsai ||
    _pllsai_r != pllsai_r::disable
  ) {
    static_assert(pllsai_n_out >= 100_MHz && pllsai_n_out <= 432_MHz, "PLLSAI_N output frequency "
                                                                      "must be >= 100MHz and <= "
                                                                      "432MHz");
    if constexpr(_sai1_a_mux == sai1_a_mux::pllsai || _sai1_b_mux == sai1_b_mux::pllsai) {
      static_assert(pllsai_q_out <= 216_MHz, "PLLSAI_Q output frequency must be <= 216MHz");
    }

    if constexpr(_pllsai_r != pllsai_r::disable) {
      static_assert(pllsai_r_out <= 216_MHz, "PLLSAI_R output frequency must be <= 216MHz");
    }
  }

  if constexpr(_mco1_mux == mco1_mux::pllclk) {
    static_assert(pll_p_out <= 100_MHz, "MCO1 output frequency must be <= 100MHz");
  }

  constexpr auto mco2_out = []() -> double
  {
    switch(_mco2_mux) {
    case mco2_mux::sysclk: return sysclk;
    case mco2_mux::plli2s: return plli2s_r_out;
    case mco2_mux::hse:    return HSE_VALUE;
    case mco2_mux::pllclk: return pll_p_out;
    default : break;
    }
    return 0;
  }();
  static_assert(mco2_out < 100_MHz, "MCO2 output frequency must be <= 100MHz");

  detail::configure<_apb1_prediv, _apb2_prediv, _ahb_prediv, _sysclk_mux, _css, _pll_m, _pll_n,
                    _pll_p, _pll_mux, _osc_type, _pll_q, _timpre, _rtcclk_mux, _rtchse_prediv,
                    _mco1_mux, _mco1_prediv, _mco2_mux, _mco2_prediv, _i2sclk_mux, _plli2s_n,
                    _plli2s_r, _plli2s_q, _plli2s_div_q, _pllsai_n, _pllsai_q, _pllsai_r,
                    _pllsai_div_q, _pllsai_div_r, _sai1_a_mux, _sai1_b_mux, _hsi_cal>();

  detail::system_clock   = round<uint32_t>(sysclk);
  detail::hardware_clock = round<uint32_t>(hclk);
  detail::apb1_clock     = round<uint32_t>(apb1clk);
  detail::apb2_clock     = round<uint32_t>(apb2clk);
  detail::adc_clock      = round<uint32_t>(apb2clk);

  if constexpr(_timpre == timpre::pre_0) {
    detail::apb1_timer_clock = round<uint32_t>((_apb1_prediv == apb1_prediv::_1)?
                                                apb1clk : apb1clk * 2);
    detail::apb2_timer_clock = round<uint32_t>((_apb2_prediv == apb2_prediv::_1)?
                                                apb2clk : apb2clk * 2);
  }
  else {
    if constexpr(_apb1_prediv < apb1_prediv::_8) {
      detail::apb1_timer_clock = round<uint32_t>(hclk);
    }
    else {
      detail::apb1_timer_clock = round<uint32_t>(apb1clk * 4);
    }

    if constexpr(_apb2_prediv < apb2_prediv::_8) {
      detail::apb2_timer_clock = round<uint32_t>(hclk);
    }
    else {
      detail::apb2_timer_clock = round<uint32_t>(apb2clk * 4);
    }
  }
}

} // namespace lmcu::rcc
