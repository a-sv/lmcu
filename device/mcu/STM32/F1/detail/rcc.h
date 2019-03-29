#pragma once

namespace detail {

template<auto _sysclk>
constexpr void set_flash_latency()
{
  uint32_t r = FLASH->ACR;
  r &= ~FLASH_ACR_LATENCY;
  if constexpr(_sysclk > 24_MHz && _sysclk <= 48_MHz) { r |= 1 << FLASH_ACR_LATENCY_Pos; }
  if constexpr(_sysclk > 48_MHz) { r |= 2 << FLASH_ACR_LATENCY_Pos; }
  FLASH->ACR = r;
}

template<uint32_t _sysclk, ahb_prediv _ahb_prediv, apb1_prediv _apb1_prediv,
         apb2_prediv _apb2_prediv, adc_prediv _adc_prediv>
constexpr void configure_periph_clocks()
{
  set_flash_latency<_sysclk>();

  constexpr auto hclk = double(_sysclk) / static_cast<uint32_t>(_ahb_prediv);
  static_assert(hclk <= 72_MHz, "HCLK must be <= 72MHz");

  system_clock = _sysclk;
  hardware_clock = round<uint32_t>(hclk);

  constexpr auto pclk1 = hclk / static_cast<uint32_t>(_apb1_prediv);
  static_assert(pclk1 <= 36_MHz, "APB1 peripheral clocks must be <= 36MHz");
  apb1_clock = round<uint32_t>(pclk1);

  constexpr auto pclk2 = hclk / static_cast<uint32_t>(_apb2_prediv);
  apb2_clock = round<uint32_t>(pclk2);

  uint32_t r = RCC->CFGR;
  r &= ~RCC_CFGR_ADCPRE;

  if constexpr(_adc_prediv != adc_prediv::disable) {
    constexpr auto adc_clk = pclk2 / static_cast<uint32_t>(_adc_prediv);
    static_assert(adc_clk <= 14_MHz, "ADC clock must be <= 14MHz");
    adc_clock = round<uint32_t>(adc_clk);

    switch(_adc_prediv) {
    case adc_prediv::_4: r |= RCC_CFGR_ADCPRE_DIV4; break;
    case adc_prediv::_6: r |= RCC_CFGR_ADCPRE_DIV6; break;
    case adc_prediv::_8: r |= RCC_CFGR_ADCPRE_DIV8; break;
    }
  }
  else {
    adc_clock = 0;
  }

  RCC->CFGR = r;

  apb1_timer_clock = (_apb1_prediv == apb1_prediv::_1)? apb1_clock : apb1_clock * 2;
  apb2_timer_clock = (_apb2_prediv == apb2_prediv::_1)? apb2_clock : apb2_clock * 2;

  set_hw_clocks<_ahb_prediv, _apb1_prediv, _apb2_prediv>();
}

} // namespace detail
