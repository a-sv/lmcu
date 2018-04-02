#pragma once
#include "../rcc.h"

namespace lmcu {
namespace rcc {

enum class hse_pll_prediv { div_1 = 1, div_2 = 2 };

enum class pll_mux { hse, hsi };

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

template<
  osc_type _osc_type,
  hse_pll_prediv _hse_pll_prediv,
  pll_mux _pll_mux,
  pll_mul _pll_mul,
  sysclk_mux _sysclk_mux,
  ahb_prediv _ahb_prediv,
  apb1_prediv _apb1_prediv,
  apb2_prediv _apb2_prediv,
  rtcclk_mux _rtc_clk_mux = rtcclk_mux::disabled,
  css _css = css::disabled,
  uint32_t _hsi_cal = 0
>
void configure()
{
  detail::osc_config<_osc_type, _hsi_cal, _rtc_clk_mux>();

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
    constexpr auto pllclk =
      ((_pll_mux == pll_mux::hsi)? 8_MHz / 2 : HSE_VALUE / static_cast<uint32_t>(_hse_pll_prediv))
        * static_cast<uint32_t>(_pll_mul)
    ;

    constexpr auto sysclk = []() -> uint32_t
    {
      switch(_sysclk_mux) {
      case sysclk_mux::hse: return HSE_VALUE;
      case sysclk_mux::pllclk: return pllclk;
      default: return 8_MHz;
      }
    }();

    detail::system_clock = sysclk;

    constexpr auto hclk = sysclk / static_cast<uint32_t>(_ahb_prediv);
    static_assert(hclk <= 72_MHz, "HCLK must be <= 72MHz");

    detail::hardware_clock = hclk;
  }

}

} // namespace lmcu
} // namespace rcc
