#pragma once
#include <lmcu/math>
#include "rcc_common.h"

namespace lmcu::rcc {

enum class prediv1_mux { hse, pll2clk };

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

enum class prediv2
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

enum class pll_mux { hsi, prediv1 };

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
  _8 = 8,
  _9,
  _10,
  _11,
  _12,
  _13,
  _14,
  _16,
  _20
};

enum class pll3_mul
{
  _8 = 8,
  _9,
  _10,
  _11,
  _12,
  _13,
  _14,
  _16,
  _20
};

enum class i2s2_clk_mux { sysclk, pll3_vco };

enum class i2s3_clk_mux { sysclk, pll3_vco };

enum class usb_div
{
  disable, // USB not used
  _2 = 2,
  _3 = 3
};

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

template <auto ..._args>
struct config
{
  static constexpr uint32_t hsi_freq = 8_MHz;

  static constexpr uint32_t lsi_freq = 40_kHz;

  static constexpr auto hse_freq = option::get_u<rcc::hse_freq, _args...>(rcc::hse_freq(8_MHz));

  static constexpr auto lse_freq = option::get_u<rcc::lse_freq, _args...>(rcc::lse_freq(32768));

  static constexpr auto osc_type = option::get<rcc::osc_type, _args...>(rcc::osc_type::hsi);

  static constexpr auto css = option::get<rcc::css, _args...>(rcc::css::disable);

  static constexpr auto sysclk_mux = option::get<rcc::sysclk_mux, _args...>(rcc::sysclk_mux::hsi);

  static constexpr auto rtcclk_mux = option::get<rcc::rtcclk_mux, _args...>(rcc::rtcclk_mux::
                                                                            disable);

  static constexpr auto ahb_div = option::get<rcc::ahb_div, _args...>(rcc::ahb_div::_1);

  static constexpr auto apb1_div = option::get<rcc::apb1_div, _args...>(rcc::apb1_div::_1);

  static constexpr auto apb2_div = option::get<rcc::apb2_div, _args...>(rcc::apb2_div::_1);

  static constexpr auto systick_div = option::get<rcc::systick_div, _args...>(rcc::systick_div::
                                                                                _1);

  static constexpr auto adc_div = option::get<rcc::adc_div, _args...>(rcc::adc_div::disable);

  static constexpr auto prediv1_mux = option::get<rcc::prediv1_mux, _args...>(rcc::prediv1_mux::
                                                                              hse);

  static constexpr auto prediv1 = option::get<rcc::prediv1, _args...>(rcc::prediv1::_1);

  static constexpr auto prediv2 = option::get<rcc::prediv2, _args...>(rcc::prediv2::_1);

  static constexpr auto pll_mul = option::get<rcc::pll_mul, _args...>(rcc::pll_mul::_4);

  static constexpr auto pll_mux = option::get<rcc::pll_mux, _args...>(rcc::pll_mux::hsi);

  static constexpr auto pll2_mul = option::get<rcc::pll2_mul, _args...>(rcc::pll2_mul::_8);

  static constexpr auto pll3_mul = option::get<rcc::pll3_mul, _args...>(rcc::pll3_mul::_8);

  static constexpr auto i2s2_clk_mux = option::get<rcc::i2s2_clk_mux, _args...>(rcc::i2s2_clk_mux::
                                                                                sysclk);

  static constexpr auto i2s3_clk_mux = option::get<rcc::i2s3_clk_mux, _args...>(rcc::i2s3_clk_mux::
                                                                                sysclk);

  static constexpr auto usb_div = option::get<rcc::usb_div, _args...>(rcc::usb_div::disable);

  static constexpr auto mco_mux = option::get<rcc::mco_mux, _args...>(rcc::mco_mux::disable);

  static constexpr auto hsi_cal = option::get_u<rcc::hsi_cal, _args...>(rcc::hsi_cal::defval);

  static constexpr auto allow_overclock = option::get<rcc::allow_overclock, _args...>(
                                            rcc::allow_overclock::no);

  static_assert(option::check<
    std::tuple<rcc::hse_freq, rcc::lse_freq, rcc::osc_type, rcc::css, rcc::sysclk_mux,
               rcc::rtcclk_mux, rcc::ahb_div, rcc::apb1_div, rcc::apb2_div, rcc::systick_div,
               rcc::adc_div, rcc::prediv1_mux, rcc::prediv1, rcc::prediv2, rcc::pll_mul,
               rcc::pll_mux, rcc::pll2_mul, rcc::pll3_mul, rcc::i2s2_clk_mux, rcc::i2s3_clk_mux,
               rcc::usb_div, rcc::mco_mux, rcc::hsi_cal, rcc::allow_overclock>,
    _args...
  >());
};

template<typename _config>
void configure()
{
  using namespace device;
  using cfg = _config;

  irq::ctl ic;
  ic.disable();

  {
    if constexpr(cfg::css == css::enable) {
      static_assert(
        flags::any(cfg::osc_type, osc_type::hse, osc_type::hse_bypass) &&
        (cfg::sysclk_mux == sysclk_mux::hse || cfg::pll_mux == pll_mux::prediv1),
        "for CSS working clock source must be HSE"
      );
    }

    if constexpr(cfg::sysclk_mux == sysclk_mux::pllclk && cfg::pll_mux == pll_mux::prediv1) {
      static_assert(flags::any(cfg::osc_type, osc_type::hse), "system clock source uses HSE, but "
                                                              "HSE generator is disabled");
    }

    constexpr auto vco_in2 = double(cfg::hse_freq) / uint32_t(cfg::prediv2);

    constexpr auto pll2_out = vco_in2 * double(cfg::pll2_mul);

    if constexpr(cfg::prediv1_mux == prediv1_mux::pll2clk && cfg::allow_overclock ==
                                                             allow_overclock::no) {
      static_assert(pll2_out >= 40_MHz && pll2_out <= 74_MHz, "pll2_out clock must be >= 40MHz and "
                                                              "<= 74MHz");
    }

    if constexpr(
      (
        cfg::prediv1_mux == prediv1_mux::pll2clk ||
        cfg::i2s2_clk_mux == i2s2_clk_mux::pll3_vco ||
        cfg::i2s3_clk_mux == i2s3_clk_mux::pll3_vco
      ) &&
      cfg::allow_overclock == allow_overclock::no
    ) {
      static_assert(vco_in2 >= 3_MHz && vco_in2 <= 5_MHz, "vco_in2 clock must be >= 3MHz and <= "
                                                          "5MHz");
    }

    constexpr auto pll3_out = vco_in2 * double(cfg::pll3_mul);
    [[maybe_unused]] constexpr auto pll3_vco = pll3_out * 2;

    if constexpr(
      (cfg::i2s2_clk_mux == i2s2_clk_mux::pll3_vco || cfg::i2s3_clk_mux == i2s3_clk_mux::
                                                                           pll3_vco) &&
      cfg::allow_overclock == allow_overclock::no
    ) {
      static_assert(pll3_vco >= 80_MHz && pll3_vco <= 148_MHz, "pll3_vco clock must be >= 80MHz "
                                                               "and <= 148MHz");
    }

    constexpr auto prediv1_out =
      double(cfg::prediv1_mux == prediv1_mux::hse? cfg::hse_freq : pll2_out) /
        uint32_t(cfg::prediv1)
    ;

    constexpr auto vco_in = double(cfg::pll_mux == pll_mux::hsi? (cfg::hsi_freq / 2) : prediv1_out);

    if constexpr(cfg::allow_overclock == allow_overclock::no) {
      static_assert(vco_in >= 3_MHz && vco_in <= 12_MHz, "vco_in clock must be >= 3MHz and <= "
                                                         "12MHz");
    }

    constexpr auto pll_out = vco_in * (double(cfg::pll_mul) / 10);

    if constexpr(cfg::sysclk_mux == sysclk_mux::pllclk && cfg::allow_overclock ==
                                                          allow_overclock::no) {
      static_assert(pll_out >= 18_MHz && pll_out <= 72_MHz, "pll_out clock must be >= 18MHz and "
                                                            "<= 72MHz");
    }

    if constexpr(cfg::usb_div != usb_div::disable) {
      constexpr auto pll_vco = pll_out * 2;
      constexpr auto usb_clk = pll_vco / uint32_t(cfg::usb_div);
      static_assert(usb_clk >= 47.88_MHz && usb_clk <= 48.12_MHz, "USB frequency must be >= "
                                                                  "47.88MHz and <= 48.12MHz");
      detail::usb_clock = round<uint32_t>(usb_clk);
    }
    else {
      detail::usb_clock = 0;
    }

    constexpr auto sysclk = []() -> double
    {
      switch(cfg::sysclk_mux)
      {
      case sysclk_mux::hsi: return cfg::hsi_freq;
      case sysclk_mux::hse: return cfg::hse_freq;
      default:              return pll_out;
      }
    }();

    if constexpr(cfg::i2s2_clk_mux == i2s2_clk_mux::pll3_vco) {
      detail::i2s2_clock = round<uint32_t>(pll3_vco);
    }
    else {
      detail::i2s2_clock = round<uint32_t>(sysclk);
    }

    if constexpr(cfg::i2s3_clk_mux == i2s3_clk_mux::pll3_vco) {
      detail::i2s3_clock = round<uint32_t>(pll3_vco);
    }
    else {
      detail::i2s3_clock = round<uint32_t>(sysclk);
    }

    constexpr auto hwclk = sysclk / uint32_t(cfg::ahb_div);
    detail::hardware_clock = round<uint32_t>(hwclk);

    constexpr auto apb1_clk = hwclk / uint32_t(cfg::apb1_div);
    constexpr auto apb2_clk = hwclk / uint32_t(cfg::apb2_div);

    if constexpr(cfg::allow_overclock == allow_overclock::no) {
      static_assert(sysclk <= 72_MHz, "sysclk freqency must be <= 72MHz");
      static_assert(apb1_clk <= 36_MHz, "APB1 clock must be <= 36MHz");
      static_assert(apb2_clk <= 72_MHz, "APB1 clock must be <= 72MHz");
    }

    detail::apb1_clock = round<uint32_t>(apb1_clk);
    detail::apb2_clock = round<uint32_t>(apb2_clk);

    if constexpr(cfg::adc_div != adc_div::disable) {
      constexpr auto adc_clk = apb2_clk / uint32_t(cfg::adc_div);
      static_assert(adc_clk <= 14_MHz, "ADC clock must be <= 14MHz");
      detail::adc_clock = round<uint32_t>(adc_clk);
    }
    else {
      detail::adc_clock = 0;
    }

    detail::systick_clock = round<uint32_t>(hwclk / uint32_t(cfg::systick_div));

    if constexpr(cfg::apb1_div >= apb1_div::_2) {
      detail::apb1_timers_clock = round<uint32_t>(apb1_clk * 2);
    }
    else {
      detail::apb1_timers_clock = round<uint32_t>(apb1_clk);
    }

    if constexpr(cfg::apb2_div >= apb2_div::_2) {
      detail::apb2_timers_clock = round<uint32_t>(apb2_clk * 2);
    }
    else {
      detail::apb2_timers_clock = round<uint32_t>(apb2_clk);
    }

    switch(cfg::mco_mux)
    {
    case mco_mux::hse:          detail::mco_clock = cfg::hse_freq;                 break;
    case mco_mux::hsi:          detail::mco_clock = cfg::hsi_freq;                 break;
    case mco_mux::sysclk:       detail::mco_clock = round<uint32_t>(sysclk);       break;
    case mco_mux::pllclk_div2:  detail::mco_clock = round<uint32_t>(pll_out / 2);  break;
    case mco_mux::pll2clk:      detail::mco_clock = round<uint32_t>(pll2_out);     break;
    case mco_mux::pll3clk:      detail::mco_clock = round<uint32_t>(pll3_out);     break;
    case mco_mux::pll3clk_div2: detail::mco_clock = round<uint32_t>(pll3_out / 2); break;
    case mco_mux::xt1:          detail::mco_clock = cfg::hse_freq;                 break;
    default:                    detail::mco_clock = 0;                             break;
    }
  }

  // Disable MCO before change clocks.
  RCC::CFGR::clr_b(RCC::CFGR::MCO_MASK);

  detail::pre_configure<cfg>();

  // PLL disable
  RCC::CR::clr_b(RCC::CR::PLLON | RCC::CR::PLL2ON | RCC::CR::PLL3ON);
  while(RCC::CR::is_set(RCC::CR::PLLRDY | RCC::CR::PLL2RDY | RCC::CR::PLL3RDY))
    ;

  {
    auto r = RCC::CFGR::get();

    if constexpr(cfg::usb_div == usb_div::_2) {
      r |= RCC::CFGR::OTGFSPRE;
    }
    else {
      r &= ~RCC::CFGR::OTGFSPRE;
    }

    r &= ~RCC::CFGR::PLLMUL_MASK;
    switch(cfg::pll_mul)
    {
    case pll_mul::_4:   r |= RCC::CFGR::PLLMUL_MUL4;   break;
    case pll_mul::_5:   r |= RCC::CFGR::PLLMUL_MUL5;   break;
    case pll_mul::_6:   r |= RCC::CFGR::PLLMUL_MUL6;   break;
    case pll_mul::_6_5: r |= RCC::CFGR::PLLMUL_MUL6_5; break;
    case pll_mul::_7:   r |= RCC::CFGR::PLLMUL_MUL7;   break;
    case pll_mul::_8:   r |= RCC::CFGR::PLLMUL_MUL8;   break;
    case pll_mul::_9:   r |= RCC::CFGR::PLLMUL_MUL9;   break;
    default: break;
    }

    if constexpr(cfg::pll_mux == pll_mux::hsi) {
      r &= ~RCC::CFGR::PLLSRC;
    }
    else {
      r |= RCC::CFGR::PLLSRC;
    }

    r &= ~RCC::CFGR::ADCPRE_MASK;
    switch(cfg::adc_div)
    {
    case adc_div::_2: r |= RCC::CFGR::ADCPRE_DIV2; break;
    case adc_div::_4: r |= RCC::CFGR::ADCPRE_DIV4; break;
    case adc_div::_6: r |= RCC::CFGR::ADCPRE_DIV6; break;
    case adc_div::_8: r |= RCC::CFGR::ADCPRE_DIV8; break;
    default: break;
    }

    RCC::CFGR::set(r);
  }

  {
    auto r = RCC::CFGR2::get();

    if constexpr(cfg::i2s2_clk_mux == i2s2_clk_mux::sysclk) {
      r &= ~RCC::CFGR2::I2S2SRC;
    }
    else {
      r |= RCC::CFGR2::I2S2SRC;
    }

    if constexpr(cfg::i2s3_clk_mux == i2s3_clk_mux::sysclk) {
      r &= ~RCC::CFGR2::I2S3SRC;
    }
    else {
      r |= RCC::CFGR2::I2S3SRC;
    }

    if constexpr(cfg::prediv1_mux == prediv1_mux::hse) {
      r &= ~RCC::CFGR2::PREDIV1SRC;
    }
    else {
      r |= RCC::CFGR2::PREDIV1SRC;
    }

    r &= ~RCC::CFGR2::PLL3MUL_MASK;
    switch(cfg::pll3_mul)
    {
    case pll3_mul::_8:  r |= RCC::CFGR2::PLL3MUL_MUL8;  break;
    case pll3_mul::_9:  r |= RCC::CFGR2::PLL3MUL_MUL9;  break;
    case pll3_mul::_10: r |= RCC::CFGR2::PLL3MUL_MUL10; break;
    case pll3_mul::_11: r |= RCC::CFGR2::PLL3MUL_MUL11; break;
    case pll3_mul::_12: r |= RCC::CFGR2::PLL3MUL_MUL12; break;
    case pll3_mul::_13: r |= RCC::CFGR2::PLL3MUL_MUL13; break;
    case pll3_mul::_14: r |= RCC::CFGR2::PLL3MUL_MUL14; break;
    case pll3_mul::_16: r |= RCC::CFGR2::PLL3MUL_MUL16; break;
    case pll3_mul::_20: r |= RCC::CFGR2::PLL3MUL_MUL20; break;
    default: break;
    }

    r &= ~RCC::CFGR2::PLL2MUL_MASK;
    switch(cfg::pll2_mul)
    {
    case pll2_mul::_8:  r |= RCC::CFGR2::PLL2MUL_MUL8;  break;
    case pll2_mul::_9:  r |= RCC::CFGR2::PLL2MUL_MUL9;  break;
    case pll2_mul::_10: r |= RCC::CFGR2::PLL2MUL_MUL10; break;
    case pll2_mul::_11: r |= RCC::CFGR2::PLL2MUL_MUL11; break;
    case pll2_mul::_12: r |= RCC::CFGR2::PLL2MUL_MUL12; break;
    case pll2_mul::_13: r |= RCC::CFGR2::PLL2MUL_MUL13; break;
    case pll2_mul::_14: r |= RCC::CFGR2::PLL2MUL_MUL14; break;
    case pll2_mul::_16: r |= RCC::CFGR2::PLL2MUL_MUL16; break;
    case pll2_mul::_20: r |= RCC::CFGR2::PLL2MUL_MUL20; break;
    default: break;
    }

    r &= ~RCC::CFGR2::PREDIV2_MASK;
    switch(cfg::prediv2)
    {
    case prediv2::_2:  r |= RCC::CFGR2::PREDIV2_DIV2;  break;
    case prediv2::_3:  r |= RCC::CFGR2::PREDIV2_DIV3;  break;
    case prediv2::_4:  r |= RCC::CFGR2::PREDIV2_DIV4;  break;
    case prediv2::_5:  r |= RCC::CFGR2::PREDIV2_DIV5;  break;
    case prediv2::_6:  r |= RCC::CFGR2::PREDIV2_DIV6;  break;
    case prediv2::_7:  r |= RCC::CFGR2::PREDIV2_DIV7;  break;
    case prediv2::_8:  r |= RCC::CFGR2::PREDIV2_DIV8;  break;
    case prediv2::_9:  r |= RCC::CFGR2::PREDIV2_DIV9;  break;
    case prediv2::_10: r |= RCC::CFGR2::PREDIV2_DIV10; break;
    case prediv2::_11: r |= RCC::CFGR2::PREDIV2_DIV11; break;
    case prediv2::_12: r |= RCC::CFGR2::PREDIV2_DIV12; break;
    case prediv2::_13: r |= RCC::CFGR2::PREDIV2_DIV13; break;
    case prediv2::_14: r |= RCC::CFGR2::PREDIV2_DIV14; break;
    case prediv2::_15: r |= RCC::CFGR2::PREDIV2_DIV15; break;
    case prediv2::_16: r |= RCC::CFGR2::PREDIV2_DIV16; break;
    default: break;
    }

    r &= ~RCC::CFGR2::PREDIV1_MASK;
    switch(cfg::prediv1)
    {
    case prediv1::_2:  r |= RCC::CFGR2::PREDIV1_DIV2;  break;
    case prediv1::_3:  r |= RCC::CFGR2::PREDIV1_DIV3;  break;
    case prediv1::_4:  r |= RCC::CFGR2::PREDIV1_DIV4;  break;
    case prediv1::_5:  r |= RCC::CFGR2::PREDIV1_DIV5;  break;
    case prediv1::_6:  r |= RCC::CFGR2::PREDIV1_DIV6;  break;
    case prediv1::_7:  r |= RCC::CFGR2::PREDIV1_DIV7;  break;
    case prediv1::_8:  r |= RCC::CFGR2::PREDIV1_DIV8;  break;
    case prediv1::_9:  r |= RCC::CFGR2::PREDIV1_DIV9;  break;
    case prediv1::_10: r |= RCC::CFGR2::PREDIV1_DIV10; break;
    case prediv1::_11: r |= RCC::CFGR2::PREDIV1_DIV11; break;
    case prediv1::_12: r |= RCC::CFGR2::PREDIV1_DIV12; break;
    case prediv1::_13: r |= RCC::CFGR2::PREDIV1_DIV13; break;
    case prediv1::_14: r |= RCC::CFGR2::PREDIV1_DIV14; break;
    case prediv1::_15: r |= RCC::CFGR2::PREDIV1_DIV15; break;
    case prediv1::_16: r |= RCC::CFGR2::PREDIV1_DIV16; break;
    default: break;
    }

    RCC::CFGR2::set(r);
  }

  if constexpr(cfg::prediv1_mux == prediv1_mux::pll2clk) {
    RCC::CR::set_b(RCC::CR::PLL2ON);
    while(!RCC::CR::is_set(RCC::CR::PLL2RDY))
      ;
  }

  if constexpr(
    cfg::i2s2_clk_mux == i2s2_clk_mux::pll3_vco ||
    cfg::i2s3_clk_mux == i2s3_clk_mux::pll3_vco
  ) {
    RCC::CR::set_b(RCC::CR::PLL3ON);
    while(!RCC::CR::is_set(RCC::CR::PLL3RDY))
      ;
  }

  if constexpr(cfg::pll_mux == pll_mux::prediv1) {
    RCC::CR::set_b(RCC::CR::PLLON);
    while(!RCC::CR::is_set(RCC::CR::PLLRDY))
      ;
  }

  detail::post_configure<cfg>();

  {
    auto r = RCC::CFGR::get();
    switch(cfg::mco_mux)
    {
    case mco_mux::hse:          r |= RCC::CFGR::MCO_HSE;       break;
    case mco_mux::hsi:          r |= RCC::CFGR::MCO_HSI;       break;
    case mco_mux::sysclk:       r |= RCC::CFGR::MCO_SYSCLK;    break;
    case mco_mux::pllclk_div2:  r |= RCC::CFGR::MCO_PLL_DIV2;  break;
    case mco_mux::pll2clk:      r |= RCC::CFGR::MCO_PLL2;      break;
    case mco_mux::pll3clk:      r |= RCC::CFGR::MCO_PLL3;      break;
    case mco_mux::pll3clk_div2: r |= RCC::CFGR::MCO_PLL3_DIV2; break;
    case mco_mux::xt1:          r |= RCC::CFGR::MCO_XT1;       break;
    default: break;
    }
    RCC::CFGR::set(r);
  }
}

} // namespace lmcu::rcc
