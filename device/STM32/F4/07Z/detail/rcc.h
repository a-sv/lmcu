#pragma once

namespace detail {

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
  pll_q _pll_q,
  rtcclk_mux _rtcclk_mux,
  rtchse_prediv _rtchse_prediv,
  mco1_mux _mco1_mux,
  mco1_prediv _mco1_prediv,
  mco2_mux _mco2_mux,
  mco2_prediv _mco2_prediv,
  i2sclk_mux _i2sclk_mux,
  plli2s_n _plli2s_n,
  plli2s_r _plli2s_r,
  uint32_t _hsi_cal
>
void configure()
{
  osc_configure<_osc_type, _hsi_cal, _rtcclk_mux>();

  if constexpr(
    ((_osc_type & osc_type::hse) || (_osc_type & osc_type::hse_bypass)) &&
    (_sysclk_mux == sysclk_mux::hse || (_pll_mux == pll_mux::hse &&
                                        _sysclk_mux == sysclk_mux::pllclk)) &&
    (_css == css::enable)
  ) {
    RCC->CR |= RCC_CR_CSSON;
  }
  else {
    RCC->CR &= ~RCC_CR_CSSON;
  }

    // disable PLL's
  RCC->CR &= ~(RCC_CR_PLLI2SON | RCC_CR_PLLON);
  while((RCC->CR & (RCC_CR_PLLI2SRDY | RCC_CR_PLLRDY)) != 0)
    ;

  configure<_apb1_prediv, _apb2_prediv, _ahb_prediv, _sysclk_mux, _pll_m, _pll_n, _pll_p, _pll_q,
            _pll_mux, _rtcclk_mux, _rtchse_prediv, _mco1_mux, _mco1_prediv, _mco2_mux, _mco2_prediv,
            _i2sclk_mux>();

  //
  // configure PLL's
  //

  if constexpr(_i2sclk_mux == i2sclk_mux::plli2s) {
    uint32_t r = RCC->PLLI2SCFGR;

    r &= ~(RCC_PLLI2SCFGR_PLLI2SN | RCC_PLLI2SCFGR_PLLI2SR);
    r |= (uint32_t(_plli2s_n) << RCC_PLLI2SCFGR_PLLI2SN_Pos);
    r |= (uint32_t(_plli2s_r) << RCC_PLLI2SCFGR_PLLI2SR_Pos);

    RCC->PLLI2SCFGR = r;

    RCC->CR |= RCC_CR_PLLI2SON;
    while((RCC->CR & RCC_CR_PLLI2SRDY) == 0)
      ;
  }

  switch_sysclk<_sysclk_mux>();
  osc_deconfigure<_osc_type, _rtcclk_mux>();
}

} // namespace detail
