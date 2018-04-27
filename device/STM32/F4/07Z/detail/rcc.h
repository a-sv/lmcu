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

  set_hw_clocks<_ahb_prediv, _apb1_prediv, _apb2_prediv>();

  {
    auto r = RCC->CFGR;
    r &= ~(RCC_CFGR_MCO1 | RCC_CFGR_MCO2 | RCC_CFGR_MCO1PRE | RCC_CFGR_MCO2PRE);

    //
    // configure MCO1
    //

    switch(_mco1_mux) {
    case mco1_mux::lse:      r |= (1 << RCC_CFGR_MCO1_Pos);        break;
    case mco1_mux::hse:      r |= (2 << RCC_CFGR_MCO1_Pos);        break;
    case mco1_mux::pllclk:   r |= (3 << RCC_CFGR_MCO1_Pos);        break;
    default : break;
    }

    switch(_mco1_prediv) {
    case mco1_prediv::div_2: r |= (0b100 << RCC_CFGR_MCO1PRE_Pos); break;
    case mco1_prediv::div_3: r |= (0b101 << RCC_CFGR_MCO1PRE_Pos); break;
    case mco1_prediv::div_4: r |= (0b110 << RCC_CFGR_MCO1PRE_Pos); break;
    case mco1_prediv::div_5: r |= (0b111 << RCC_CFGR_MCO1PRE_Pos); break;
    default : break;
    }

    //
    // configure MCO2
    //

    switch(_mco2_mux) {
    case mco2_mux::plli2s:   r |= (1 << RCC_CFGR_MCO2_Pos);        break;
    case mco2_mux::hse:      r |= (2 << RCC_CFGR_MCO2_Pos);        break;
    case mco2_mux::pllclk:   r |= (3 << RCC_CFGR_MCO2_Pos);        break;
    default : break;
    }

    switch(_mco2_prediv) {
    case mco2_prediv::div_2: r |= (0b100 << RCC_CFGR_MCO2PRE_Pos); break;
    case mco2_prediv::div_3: r |= (0b101 << RCC_CFGR_MCO2PRE_Pos); break;
    case mco2_prediv::div_4: r |= (0b110 << RCC_CFGR_MCO2PRE_Pos); break;
    case mco2_prediv::div_5: r |= (0b111 << RCC_CFGR_MCO2PRE_Pos); break;
    default : break;
    }

    if constexpr(_i2sclk_mux == i2sclk_mux::extclk) {
      r |=  RCC_CFGR_I2SSRC;
    }
    else {
      r &= ~RCC_CFGR_I2SSRC;
    }

    r &= ~RCC_CFGR_RTCPRE;
    if constexpr(_rtcclk_mux == rtcclk_mux::hse) {
      r |= (uint32_t(_rtchse_prediv) << RCC_CFGR_RTCPRE_Pos);
    }

    RCC->CFGR = r;
  }

  //
  // configure PLL's
  //

  // disable PLL's
  RCC->CR &= ~(RCC_CR_PLLI2SON | RCC_CR_PLLON);
  while((RCC->CR & (RCC_CR_PLLI2SRDY | RCC_CR_PLLRDY)) != 0)
    ;

  if constexpr(_sysclk_mux == sysclk_mux::pllclk || _pll_q != pll_q::disable) {
    auto r = RCC->PLLCFGR;

    r &= ~RCC_PLLCFGR_PLLQ;
    if constexpr(_pll_q != pll_q::disable) { r |= (uint32_t(_pll_q) << RCC_PLLCFGR_PLLQ_Pos); }

    if constexpr(_pll_mux == pll_mux::hse) {
      r |= RCC_PLLCFGR_PLLSRC;
    }
    else {
      r &= ~RCC_PLLCFGR_PLLSRC;
    }

    r &= ~RCC_PLLCFGR_PLLP;
    switch(_pll_p) {
    case pll_p::div_4: r |= (1 << RCC_PLLCFGR_PLLP_Pos); break;
    case pll_p::div_6: r |= (2 << RCC_PLLCFGR_PLLP_Pos); break;
    case pll_p::div_8: r |= (3 << RCC_PLLCFGR_PLLP_Pos); break;
    default : break;
    }

    r &= ~(RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLM);
    r |= (uint32_t(_pll_n) << RCC_PLLCFGR_PLLN_Pos);
    r |= (uint32_t(_pll_m) << RCC_PLLCFGR_PLLM_Pos);

    RCC->PLLCFGR = r;

    RCC->CR |= RCC_CR_PLLON;
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
      ;
  }

  if constexpr(_i2sclk_mux == i2sclk_mux::plli2s) {
    auto r = RCC->PLLI2SCFGR;

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
