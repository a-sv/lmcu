#pragma once
#include <lmcu/hwi/math>
#include "rcc_common.h"

namespace lmcu::rcc {

enum class hse_pll_div { _1 = 1, _2 = 2 };

enum class usb_div
{
  disable, // USB not used
  _1,
  _1_5
};

enum class pll_mux { hse, hsi };

enum class pll_mul
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
  _15,
  _16
};

enum class mco_mux
{
  disable,
  hse,
  hsi,
  sysclk,
  pllclk_div2
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

  static constexpr auto pll_mul = option::get<rcc::pll_mul, _args...>(rcc::pll_mul::_2);

  static constexpr auto pll_mux = option::get<rcc::pll_mux, _args...>(rcc::pll_mux::hsi);

  static constexpr auto hse_pll_div = option::get<rcc::hse_pll_div, _args...>(rcc::hse_pll_div::_1);

  static constexpr auto usb_div = option::get<rcc::usb_div, _args...>(rcc::usb_div::disable);

  static constexpr auto mco_mux = option::get<rcc::mco_mux, _args...>(rcc::mco_mux::disable);

  static constexpr auto hsi_cal = option::get_u<rcc::hsi_cal, _args...>(rcc::hsi_cal::defval);

  static constexpr auto allow_overclock = option::get<rcc::allow_overclock, _args...>(
                                            rcc::allow_overclock::no);

  static_assert(option::check<
    std::tuple<rcc::hse_freq, rcc::lse_freq, rcc::osc_type, rcc::css, rcc::sysclk_mux,
               rcc::rtcclk_mux, rcc::ahb_div, rcc::apb1_div, rcc::apb2_div, rcc::systick_div,
               rcc::adc_div, rcc::pll_mul, rcc::pll_mux, rcc::hse_pll_div, rcc::usb_div,
               rcc::mco_mux, rcc::hsi_cal, rcc::allow_overclock>,
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
        (
          cfg::sysclk_mux == sysclk_mux::hse ||
          (cfg::pll_mux == pll_mux::hse && cfg::sysclk_mux == sysclk_mux::pllclk)
        ),
        "for CSS working clock source must be HSE"
      );
    }

    constexpr auto pll_in = (cfg::pll_mux == pll_mux::hsi)?
        double(cfg::hsi_freq) / 2 : double(cfg::hse_freq) / uint32_t(cfg::hse_pll_div);
    if constexpr(cfg::allow_overclock == allow_overclock::no) {
      static_assert(pll_in >= 1_MHz && pll_in <= 25_MHz, "VCO input must be >= 1MHz and <= 25MHz");
    }

    constexpr auto pll_m = double(cfg::pll_mul);
    constexpr auto pll_out = pll_in * pll_m;

    constexpr auto sysclk = []() -> double
    {
      switch(cfg::sysclk_mux)
      {
      case sysclk_mux::hse:    return cfg::hse_freq;
      case sysclk_mux::pllclk: return pll_out;
      default:                 return cfg::hsi_freq;
      }
    }();
    if constexpr(cfg::allow_overclock == allow_overclock::no) {
      static_assert(sysclk <= 72_MHz, "SYSCLK must be <= 72MHz");
    }

    if constexpr(cfg::allow_overclock == allow_overclock::no && cfg::mco_mux == mco_mux::sysclk) {
      static_assert(sysclk <= 50_MHz, "MCO must be <= 50MHz");
    }

    if constexpr(cfg::mco_mux == mco_mux::hsi) {
      static_assert(flags::all(cfg::osc_type, rcc::osc_type::hsi), "MCO mux set to HSI, but HSI "
                                                                   "generator is disabled");
    }

    constexpr auto hwclk = sysclk / uint32_t(cfg::ahb_div);
    detail::hardware_clock = round<uint32_t>(hwclk);

    if constexpr(cfg::usb_div != usb_div::disable) {
      constexpr auto usb_d = (cfg::usb_div == usb_div::_1_5)? 1.5f : 1.0f;
      constexpr auto usbclk = pll_out / usb_d;
      static_assert(usbclk >= 47.88_MHz && usbclk <= 48.12_MHz, "USB frequency must be >= 47.88MHz "
                                                                "and <= 48.12MHz");
      detail::usb_clock = round<uint32_t>(usbclk);
    }
    else {
      detail::usb_clock = 0;
    }

    constexpr auto apb1_clk = hwclk / uint32_t(cfg::apb1_div);
    constexpr auto apb2_clk = hwclk / uint32_t(cfg::apb2_div);

    if constexpr(cfg::allow_overclock == allow_overclock::no) {
      static_assert(apb1_clk <= 36_MHz, "APB1 clock must be <= 36MHz");
      static_assert(apb2_clk <= 72_MHz, "APB2 clock must be <= 72MHz");
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
    case mco_mux::hse:         detail::mco_clock = cfg::hse_freq;                break;
    case mco_mux::hsi:         detail::mco_clock = cfg::hsi_freq;                break;
    case mco_mux::pllclk_div2: detail::mco_clock = round<uint32_t>(pll_out / 2); break;
    case mco_mux::sysclk:      detail::mco_clock = round<uint32_t>(sysclk);      break;
    default:                   detail::mco_clock = 0;                            break;
    }
  }

  // Disable MCO before change clocks.
  RCC::CFGR::clr_b(RCC::CFGR::MCO_MASK);

  detail::pre_configure<cfg>();

  // PLL disable
  RCC::CR::clr_b(RCC::CR::PLLON);
  while(RCC::CR::is_set(RCC::CR::PLLRDY))
    ;

  {
    auto r = RCC::CFGR::get();

    if constexpr(cfg::sysclk_mux == sysclk_mux::pllclk) {
      if constexpr(cfg::pll_mux == pll_mux::hsi) {
        r &= ~RCC::CFGR::PLLSRC;
      }
      else {
        // set PLL clock source to PREDIV
        r |= RCC::CFGR::PLLSRC;
      }

      if constexpr(cfg::hse_pll_div == hse_pll_div::_2) {
        r |= RCC::CFGR::PLLXTPRE;
      }
      else {
        r &= ~RCC::CFGR::PLLXTPRE;
      }

      r &= ~RCC::CFGR::PLLMUL_MASK;
      r |= ((uint32_t(cfg::pll_mul) - 2) << RCC::CFGR::PLLMUL_POS);
    }

    r &= ~RCC::CFGR::ADCPRE_MASK;
    switch(cfg::adc_div)
    {
    case adc_div::_4: r |= RCC::CFGR::ADCPRE_DIV4; break;
    case adc_div::_6: r |= RCC::CFGR::ADCPRE_DIV6; break;
    case adc_div::_8: r |= RCC::CFGR::ADCPRE_DIV8; break;
    default: break;
    }

    if constexpr(cfg::usb_div == usb_div::_1_5) {
      r &= ~RCC::CFGR::USBPRE;
    }
    else {
      r |= RCC::CFGR::USBPRE;
    }

    RCC::CFGR::set(r);
  }

  if constexpr(cfg::sysclk_mux == sysclk_mux::pllclk || cfg::usb_div != usb_div::disable) {
    // PLL enable
    RCC::CR::set_b(RCC::CR::PLLON);
    while(!RCC::CR::is_set(RCC::CR::PLLRDY))
      ;
  }

  detail::post_configure<cfg>();

  {
    auto r = RCC::CFGR::get();
    switch(cfg::mco_mux)
    {
    case mco_mux::sysclk:      r |= RCC::CFGR::MCO_SYSCLK;   break;
    case mco_mux::hsi:         r |= RCC::CFGR::MCO_HSI;      break;
    case mco_mux::hse:         r |= RCC::CFGR::MCO_HSE;      break;
    case mco_mux::pllclk_div2: r |= RCC::CFGR::MCO_PLL_DIV2; break;
    default: break;
    }
    RCC::CFGR::set(r);
  }
}

} // namespace lmcu::rcc
