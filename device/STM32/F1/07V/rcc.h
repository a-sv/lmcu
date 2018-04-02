#pragma once
#include "../rcc.h"

namespace lmcu {
namespace rcc {

enum class prediv1_mux { hse, pll2clk };

enum class pll_mux { hsi, prediv1 };

enum class sysclk_mux { hsi, hse, pllclk };

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

enum class ahb_prediv
{
  div_1   = 1,
  div_2   = 2,
  div_4   = 4,
  div_8   = 8,
  div_16  = 16,
  div_64  = 64,
  div_128 = 128,
  div_256 = 256,
  div_512 = 512
};

enum class apb1_prediv
{
  div_1  = 1,
  div_2  = 2,
  div_4  = 4,
  div_8  = 8,
  div_16 = 16
};
using apb2_prediv = apb1_prediv;

enum class adc_prediv
{
  disabled, // ADC not used
  div_2 = 2,
  div_4 = 4,
  div_6 = 6,
  div_8 = 8
};

enum class usb_prediv
{
  disabled, // USB not used
  div_1   = 2,
  div_1_5 = 3
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

namespace detail {

template<auto _sysclk>
constexpr void set_flash_latency()
{
  auto r = FLASH->ACR;
  r &= ~FLASH_ACR_LATENCY;
  if constexpr(_sysclk > 24_MHz && _sysclk <= 48_MHz) { r |= 1 << FLASH_ACR_LATENCY_Pos; }
  if constexpr(_sysclk > 48_MHz) { r |= 2 << FLASH_ACR_LATENCY_Pos; }
  FLASH->ACR = r;
}

template<auto _sysclk, ahb_prediv _ahb_prediv, apb1_prediv _apb1_prediv, apb2_prediv _apb2_prediv,
         adc_prediv _adc_prediv, mco_mux _mco_mux>
constexpr void configure_periph_clocks()
{
  if constexpr(_mco_mux == mco_mux::sysclk) {
    static_assert(_sysclk <= 50_MHz, "sysclk MCO must be <= 50MHz");
  }

  detail::set_flash_latency<_sysclk>();

  constexpr auto hclk = _sysclk / static_cast<uint32_t>(_ahb_prediv);

  detail::system_clock = _sysclk;
  detail::hardware_clock = hclk;

  constexpr auto pclk1 = hclk / static_cast<uint32_t>(_apb1_prediv);
  static_assert(pclk1 <= 36_MHz, "APB1 peripheral clocks must be <= 36MHz");
  apb1_clock = pclk1;

  constexpr auto pclk2 = hclk / static_cast<uint32_t>(_apb2_prediv);
  apb2_clock = pclk2;

  if constexpr(_adc_prediv != adc_prediv::disabled) {
    constexpr auto adc_clk = pclk2 / static_cast<uint32_t>(_adc_prediv);
    static_assert(adc_clk <= 14_MHz, "ADC clock must be <= 14MHz");
    adc_clock = adc_clk;
  }
  else {
    adc_clock = 0;
  }

  auto r = RCC->CFGR;

  r &= ~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2 | RCC_CFGR_MCO);

  switch(_ahb_prediv) {
  case ahb_prediv::div_2:        r |= RCC_CFGR_HPRE_DIV2;        break;
  case ahb_prediv::div_4:        r |= RCC_CFGR_HPRE_DIV4;        break;
  case ahb_prediv::div_8:        r |= RCC_CFGR_HPRE_DIV8;        break;
  case ahb_prediv::div_16:       r |= RCC_CFGR_HPRE_DIV16;       break;
  case ahb_prediv::div_64:       r |= RCC_CFGR_HPRE_DIV64;       break;
  case ahb_prediv::div_128:      r |= RCC_CFGR_HPRE_DIV128;      break;
  case ahb_prediv::div_256:      r |= RCC_CFGR_HPRE_DIV256;      break;
  case ahb_prediv::div_512:      r |= RCC_CFGR_HPRE_DIV512;      break;
  default : break;
  }

  switch(_apb1_prediv) {
  case apb1_prediv::div_2:       r |= RCC_CFGR_PPRE1_DIV2;       break;
  case apb1_prediv::div_4:       r |= RCC_CFGR_PPRE1_DIV4;       break;
  case apb1_prediv::div_8:       r |= RCC_CFGR_PPRE1_DIV8;       break;
  case apb1_prediv::div_16:      r |= RCC_CFGR_PPRE1_DIV16;      break;
  default : break;
  }

  switch(_apb2_prediv) {
  case apb2_prediv::div_2:       r |= RCC_CFGR_PPRE2_DIV2;       break;
  case apb2_prediv::div_4:       r |= RCC_CFGR_PPRE2_DIV4;       break;
  case apb2_prediv::div_8:       r |= RCC_CFGR_PPRE2_DIV8;       break;
  case apb2_prediv::div_16:      r |= RCC_CFGR_PPRE2_DIV16;      break;
  default : break;
  }

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

template<
  osc_type _osc_type,
  prediv2 _prediv2,
  pll2_mul _pll2_mul,
  pll3_mul _pll3_mul,
  prediv1_mux _prediv1_mux,
  prediv1 _prediv1,
  pll_mux _pll_mux,
  pll_mul _pll_mul,
  sysclk_mux _sysclk_mux,
  ahb_prediv _ahb_prediv,
  apb1_prediv _apb1_prediv,
  apb2_prediv _apb2_prediv,
  adc_prediv _adc_prediv = adc_prediv::disabled,
  usb_prediv _usb_prediv = usb_prediv::disabled,
  rtc_clk_mux _rtc_clk_mux = rtc_clk_mux::lsi,
  i2s2_clk_mux _i2s2_clk_mux = i2s2_clk_mux::sysclk,
  i2s3_clk_mux _i2s3_clk_mux = i2s3_clk_mux::sysclk,
  mco_mux _mco_mux = mco_mux::disabled,
  css _css = css::disabled,
  uint32_t _hsi_cal = 0
>
void configure()
{
  detail::osc_config<_osc_type, _hsi_cal>();

  if constexpr(
    ((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) &&
    (_sysclk_mux == sysclk_mux::hse || _pll_mux == pll_mux::prediv1)
  ) {
    RCC->CR |= RCC_CR_CSSON;
  }
  else {
    RCC->CR &= ~RCC_CR_CSSON;
  }

  static_assert(
    (_osc_type & osc_type::hse) ||
    (_osc_type & osc_type::hse_bypass) ||
    (_osc_type & osc_type::hsi),
    "you must select at least one of high speed generators"
  );
  if constexpr((_osc_type & osc_type::lse) || (_osc_type & osc_type::lse_bypass)) {
    static_assert(_rtc_clk_mux == rtc_clk_mux::lse, "LSE generator turned on, but not used");
  }
  if constexpr(_rtc_clk_mux == rtc_clk_mux::hse) {
    static_assert(
      (_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass),
      "HSE generator selected as RTC clock, but HSE is disabled"
    );
  }

  if constexpr((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) {
    constexpr auto vco_in2 = HSE_VALUE / static_cast<uint32_t>(_prediv2);

    if constexpr(
      _prediv1_mux == prediv1_mux::pll2clk ||
      _i2s2_clk_mux != i2s2_clk_mux::sysclk ||
      _i2s3_clk_mux != i2s3_clk_mux::sysclk
    ) {
      static_assert(!(vco_in2 < 3_MHz || vco_in2 > 5_MHz), "PLL2/PLL3 VCO input must be >= 3Mhz "
                                                           "and <= 5MHz");
    }

    constexpr auto pll2clk = vco_in2 * static_cast<uint32_t>(_pll2_mul);
    static_assert(!(pll2clk < 40_MHz || vco_in2 > 74_MHz), "PLL2CLK must be >= 40Mhz and <= "
                                                           "74MHz");

    if constexpr(_i2s2_clk_mux != i2s2_clk_mux::sysclk || _i2s3_clk_mux != i2s3_clk_mux::sysclk) {
      constexpr auto pll3vco = vco_in2 * static_cast<uint32_t>(_pll3_mul) * 2;
      static_assert(!(pll3vco < 80_MHz || pll3vco > 148_MHz), "PLL2CLK must be >= 40Mhz and "
                                                              "<= 74MHz");
    }

    constexpr auto vco_in1 = (_prediv1_mux == prediv1_mux::hse)?
      (HSE_VALUE / static_cast<uint32_t>(_prediv1)) : (pll2clk / static_cast<uint32_t>(_prediv1));
    static_assert(!(vco_in1 < 3_MHz || vco_in1 > 12_MHz), "PLL VCO input must be >= 3Mhz and "
                                                          "<= 12MHz");

    constexpr auto pllclk = (vco_in1 * static_cast<uint32_t>(_pll_mul)) / 10;
    static_assert(!(pllclk < 18_MHz || pllclk > 72_MHz), "PLLCLK must be >= 18Mhz and <= "
                                                           "72MHz");

    if constexpr(_usb_prediv != usb_prediv::disabled) {
      constexpr auto usbclk = (pllclk * 2) / static_cast<uint32_t>(_usb_prediv);
      static_assert(usbclk == 48_MHz, "USB clock must be = 48MHz");
    }

    if constexpr(_sysclk_mux == sysclk_mux::pllclk && _pll_mux == pll_mux::prediv1) {
      detail::configure_periph_clocks<pllclk, _ahb_prediv, _apb1_prediv, _apb2_prediv,
                                     _adc_prediv, _mco_mux>();
    }
  }

  if constexpr((_osc_type & osc_type::hsi) && _sysclk_mux == sysclk_mux::pllclk &&
               _pll_mux == pll_mux::hsi) {
    constexpr auto vco_in1 = 8_MHz / 2;

    constexpr auto pllclk = (vco_in1 * static_cast<uint32_t>(_pll_mul)) / 10;
    static_assert(!(pllclk < 18_MHz || pllclk > 72_MHz), "PLLCLK must be >= 18Mhz and <= "
                                                           "72MHz");

    if constexpr(_usb_prediv != usb_prediv::disabled) {
      constexpr auto usbclk = (pllclk * 2) / static_cast<uint32_t>(_usb_prediv);
      static_assert(usbclk == 48_MHz, "USB clock must be = 48MHz");
    }

    detail::configure_periph_clocks<pllclk, _ahb_prediv, _apb1_prediv, _apb2_prediv,
                                    _adc_prediv, _mco_mux>();
  }

  if constexpr(_sysclk_mux == sysclk_mux::hse) {
    detail::configure_periph_clocks<HSE_VALUE, _ahb_prediv, _apb1_prediv, _apb2_prediv,
                                    _adc_prediv, _mco_mux>();
  }

  if constexpr(_sysclk_mux == sysclk_mux::hsi) {
    detail::configure_periph_clocks<8_MHz, _ahb_prediv, _apb1_prediv, _apb2_prediv, _adc_prediv,
                                    _mco_mux>();
  }

  //
  // configure PLL's
  //

  // PLL, PLL2, PLL3 disable
  RCC->CR &= ~(RCC_CR_PLLON | RCC_CR_PLL2ON | RCC_CR_PLL3ON);
  while((RCC->CR & (RCC_CR_PLLRDY | RCC_CR_PLL2RDY | RCC_CR_PLL3RDY)) != 0)
    ;

  {
    auto r = RCC->CFGR;

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

    if constexpr(_usb_prediv == usb_prediv::div_1_5) {
      r &= ~RCC_CFGR_OTGFSPRE;
    }
    else {
      r |= RCC_CFGR_OTGFSPRE;
    }

    RCC->CFGR = r;
  }

  if constexpr((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) {
    {
      auto r = RCC->CFGR2;

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

      if constexpr(
        _i2s2_clk_mux != i2s2_clk_mux::sysclk || _i2s3_clk_mux != i2s3_clk_mux::sysclk
      ) {
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

    if constexpr(_sysclk_mux == sysclk_mux::pllclk || _usb_prediv != usb_prediv::disabled) {
      // PLL enable
      RCC->CR |= RCC_CR_PLLON;
      while((RCC->CR & RCC_CR_PLLRDY) == 0)
        ;
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

  //
  // select RTC clock source
  //

  {
    auto r = RCC->BDCR;
    r &= ~RCC_BDCR_RTCSEL;
    switch (_rtc_clk_mux) {
    case rtc_clk_mux::lse: r |= RCC_BDCR_RTCSEL_LSE; break;
    case rtc_clk_mux::lsi: r |= RCC_BDCR_RTCSEL_LSI; break;
    case rtc_clk_mux::hse: r |= RCC_BDCR_RTCSEL_HSE; break;
    default : break;
    }
    RCC->BDCR = r;
  }

  //
  // switch system clock
  //

  {
    auto r = RCC->CFGR;
    r &= ~RCC_CFGR_SW;
    switch(_sysclk_mux) {
    case sysclk_mux::hse:    r |= RCC_CFGR_SW_HSE; break;
    case sysclk_mux::pllclk: r |= RCC_CFGR_SW_PLL; break;
    default : break;
    }
    RCC->CFGR = r;

    switch(_sysclk_mux) {
    case sysclk_mux::hsi:
      while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
        ;
      break;
    case sysclk_mux::hse:
      while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE)
        ;
      break;
    case sysclk_mux::pllclk:
      while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
        ;
      break;
    }
  }

  // disable HSI if not used
  if constexpr(!(_osc_type & osc_type::hsi)) { RCC->CR &= ~RCC_CR_HSION; }
}

} // namespace rcc
} // namespace lmcu
