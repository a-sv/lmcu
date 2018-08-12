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
  timpre _timpre,
  rtcclk_mux _rtcclk_mux,
  rtchse_prediv _rtchse_prediv,
  mco1_mux _mco1_mux,
  mco1_prediv _mco1_prediv,
  mco2_mux _mco2_mux,
  mco2_prediv _mco2_prediv,
  i2sclk_mux _i2sclk_mux,
  plli2s_n _plli2s_n,
  plli2s_r _plli2s_r,
  plli2s_q _plli2s_q,
  plli2s_div_q _plli2s_div_q,
  pllsai_n _pllsai_n,
  pllsai_q _pllsai_q,
  pllsai_r _pllsai_r,
  pllsai_div_q _pllsai_div_q,
  pllsai_div_r _pllsai_div_r,
  sai1_a_mux _sai1_a_mux,
  sai1_b_mux _sai1_b_mux,
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
  RCC->CR &= ~(RCC_CR_PLLSAION | RCC_CR_PLLI2SON | RCC_CR_PLLON);
  while((RCC->CR & (RCC_CR_PLLSAIRDY | RCC_CR_PLLI2SRDY | RCC_CR_PLLRDY)) != 0)
    ;

  configure<_apb1_prediv, _apb2_prediv, _ahb_prediv, _sysclk_mux, _pll_m, _pll_n, _pll_p, _pll_q,
            _pll_mux, _rtcclk_mux, _rtchse_prediv, _mco1_mux, _mco1_prediv, _mco2_mux, _mco2_prediv,
            _i2sclk_mux>();

  {
    uint32_t r = RCC->DCKCFGR;

    if constexpr(_timpre == timpre::pre_0) {
      r &= ~RCC_DCKCFGR_TIMPRE;
    }
    else {
      r |=  RCC_DCKCFGR_TIMPRE;
    }

    r &= ~(RCC_DCKCFGR_PLLI2SDIVQ | RCC_DCKCFGR_PLLSAIDIVQ | RCC_DCKCFGR_PLLSAIDIVR |
           RCC_DCKCFGR_SAI1ASRC | RCC_DCKCFGR_SAI1BSRC);

    if constexpr(_sai1_a_mux == sai1_a_mux::plli2s || _sai1_b_mux == sai1_b_mux::plli2s) {
      r |= (uint32_t(_plli2s_div_q) << RCC_DCKCFGR_PLLI2SDIVQ_Pos);
    }

    if constexpr(_sai1_a_mux == sai1_a_mux::pllsai || _sai1_b_mux == sai1_b_mux::pllsai) {
      r |= (uint32_t(_pllsai_div_q) << RCC_DCKCFGR_PLLSAIDIVQ_Pos);
    }

    if constexpr(_pllsai_r != pllsai_r::disable) {
      switch(_pllsai_div_r)
      {
      case pllsai_div_r::div_4:  r |= (1 << RCC_DCKCFGR_PLLSAIDIVR_Pos); break;
      case pllsai_div_r::div_8:  r |= (2 << RCC_DCKCFGR_PLLSAIDIVR_Pos); break;
      case pllsai_div_r::div_16: r |= (3 << RCC_DCKCFGR_PLLSAIDIVR_Pos); break;
      default : break;
      }
    }

    r |= (uint32_t(_sai1_a_mux) << RCC_DCKCFGR_SAI1ASRC_Pos);
    r |= (uint32_t(_sai1_b_mux) << RCC_DCKCFGR_SAI1BSRC_Pos);

    RCC->DCKCFGR = r;
  }

  //
  // configure PLL's
  //

  if constexpr(
    _i2sclk_mux == i2sclk_mux::plli2s ||
    _sai1_a_mux == sai1_a_mux::plli2s ||
    _sai1_b_mux == sai1_b_mux::plli2s
  ) {
    uint32_t r = RCC->PLLI2SCFGR;

    r &= ~(RCC_PLLI2SCFGR_PLLI2SN | RCC_PLLI2SCFGR_PLLI2SR | RCC_PLLI2SCFGR_PLLI2SQ);
    r |= (uint32_t(_plli2s_n) << RCC_PLLI2SCFGR_PLLI2SN_Pos);

    if constexpr(_i2sclk_mux == i2sclk_mux::plli2s) {
      r |= (uint32_t(_plli2s_r) << RCC_PLLI2SCFGR_PLLI2SR_Pos);
    }

    if constexpr(_sai1_a_mux == sai1_a_mux::plli2s || _sai1_b_mux == sai1_b_mux::plli2s) {
      r |= (uint32_t(_plli2s_q) << RCC_PLLI2SCFGR_PLLI2SQ_Pos);
    }

    RCC->PLLI2SCFGR = r;

    RCC->CR |= RCC_CR_PLLI2SON;
    while((RCC->CR & RCC_CR_PLLI2SRDY) == 0)
      ;
  }

  if constexpr(
    _sai1_a_mux == sai1_a_mux::pllsai ||
    _sai1_b_mux == sai1_b_mux::pllsai ||
    _pllsai_r != pllsai_r::disable
  ) {
    uint32_t r = RCC->PLLSAICFGR;

    r &= ~(RCC_PLLSAICFGR_PLLSAIN | RCC_PLLSAICFGR_PLLSAIR | RCC_PLLSAICFGR_PLLSAIQ);
    r |= (uint32_t(_pllsai_n) << RCC_PLLSAICFGR_PLLSAIN_Pos);

    if constexpr(_pllsai_r != pllsai_r::disable) {
      r |= (uint32_t(_pllsai_r) << RCC_PLLSAICFGR_PLLSAIR_Pos);
    }

    if constexpr(_sai1_a_mux == sai1_a_mux::pllsai || _sai1_b_mux == sai1_b_mux::pllsai) {
      r |= (uint32_t(_pllsai_q) << RCC_PLLSAICFGR_PLLSAIQ_Pos);
    }

    RCC->PLLSAICFGR = r;

    RCC->CR |= RCC_CR_PLLSAION;
    while((RCC->CR & RCC_CR_PLLSAIRDY) == 0)
      ;
  }

  switch_sysclk<_sysclk_mux>();
  osc_deconfigure<_osc_type, _rtcclk_mux>();
}

} // namespace detail
