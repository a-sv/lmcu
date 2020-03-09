#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/nvic>
#include <lmcu/irq>
#include <lmcu/pwr>

namespace lmcu::rcc {

enum class hse_freq : uint32_t { };

enum class lse_freq : uint32_t { };

enum class osc_type : uint32_t
{
  lmcu_flags,

  hse        = 1 << 0,
  hse_bypass = 1 << 1,
  hsi        = 1 << 2,
  lse        = 1 << 3,
  lse_bypass = 1 << 4,
  lsi        = 1 << 5
};

// clock security system
enum class css { disable, enable };

enum class sysclk_mux { hsi, hse, pllclk };

enum class rtcclk_mux { disable, hse, lse, lsi };

enum class ahb_div
{
  _1   = 1,
  _2   = 2,
  _4   = 4,
  _8   = 8,
  _16  = 16,
  _64  = 64,
  _128 = 128,
  _256 = 256,
  _512 = 512
};

enum class apb1_div
{
  _1  = 1,
  _2  = 2,
  _4  = 4,
  _8  = 8,
  _16 = 16
};

enum class apb2_div
{
  _1  = 1,
  _2  = 2,
  _4  = 4,
  _8  = 8,
  _16 = 16
};

enum class systick_div
{
  _1 = 1,
  _8 = 8
};

enum class hsi_cal : uint32_t { defval = 16 };

enum class allow_overclock { yes, no };

// ------------------------------------------------------------------------------------------------
namespace detail {
// ------------------------------------------------------------------------------------------------

extern uint32_t
  hardware_clock,
  apb1_clock,
  apb2_clock,
  systick_clock,
  adc_clock,
  rtc_clock
;

template<sysclk_mux _sysclk_mux>
static inline void switch_sysclk()
{
  using namespace device;

  auto r = RCC::CFGR::get();
  r &= ~RCC::CFGR::SW_MASK;
  switch(_sysclk_mux)
  {
  case sysclk_mux::hse: r |= RCC::CFGR::SW_HSE; break;
  case sysclk_mux::pllclk: r |= RCC::CFGR::SW_PLL; break;
  default: break;
  }
  RCC::CFGR::set(r);

  while(true) {
    const auto sws = RCC::CFGR::get() & RCC::CFGR::SWS_MASK;

    if constexpr(_sysclk_mux == sysclk_mux::hsi) {
      if(sws == RCC::CFGR::SWS_HSI) { break; }
    }
    else
    if constexpr(_sysclk_mux == sysclk_mux::hse) {
      if(sws == RCC::CFGR::SWS_HSE) { break; }
    }
    else {
      if(sws == RCC::CFGR::SWS_PLL) { break; }
    }
  }
}

template<typename _cfg>
static inline void pre_configure()
{
  static_assert(_cfg::hsi_cal <= 0x1f);
  static_assert(!flags::all(_cfg::osc_type, osc_type::hse, osc_type::hse_bypass),
                "unable to enable hse and hse_bypass mode together");
  static_assert(!flags::all(_cfg::osc_type, osc_type::lse, osc_type::lse_bypass),
                "unable to enable lse and lse_bypass mode together");
  static_assert(
    !(
      flags::any(_cfg::osc_type, osc_type::lse, osc_type::lse_bypass) &&
      flags::all(_cfg::osc_type, osc_type::lsi)
    ),
    "unable to enable lse* and lsi mode together"
  );
  static_assert(
    flags::any(_cfg::osc_type, osc_type::hse, osc_type::hse_bypass, osc_type::hsi),
    "you must select at least one of high speed generators"
  );
  if constexpr(flags::all(_cfg::osc_type, osc_type::lsi)) {
    static_assert(_cfg::rtcclk_mux == rtcclk_mux::lsi, "LSI generator turned on, but not used");
  }
  if constexpr(_cfg::rtcclk_mux == rtcclk_mux::lsi) {
    static_assert(flags::all(_cfg::osc_type, osc_type::lsi), "RTC clock source connected to LSI, "
                                                             "but LSI turned off");
  }
  if constexpr(flags::any(_cfg::osc_type, osc_type::lse, osc_type::lse_bypass)) {
    static_assert(_cfg::rtcclk_mux == rtcclk_mux::lse, "LSE generator turned on, but not used");
  }
  if constexpr(_cfg::rtcclk_mux == rtcclk_mux::lse) {
    static_assert(flags::any(_cfg::osc_type, osc_type::lse, osc_type::lse_bypass),
                  "RTC clock source connected to LSE, but LSE turned off");
  }
  if constexpr(_cfg::rtcclk_mux == rtcclk_mux::hse) {
    static_assert(flags::any(_cfg::osc_type, osc_type::hse, osc_type::hse_bypass),
                  "HSE generator selected as RTC clock, but HSE is disabled");
  }

  using namespace device;

  //
  // HSI
  //

  {
    auto r = RCC::CR::get();
    r &= ~RCC::CR::HSITRIM_MASK;
    if constexpr(_cfg::hsi_cal != 0) {
      r |= (_cfg::hsi_cal << RCC::CR::HSITRIM_POS) & RCC::CR::HSITRIM_MASK;
    }
    r |= RCC::CR::HSION;
    RCC::CR::set(r);
  }
  while(!RCC::CR::is_set(RCC::CR::HSIRDY))
    ;

  switch_sysclk<sysclk_mux::hsi>();

  //
  // HSE
  //

  if constexpr(flags::any(_cfg::osc_type, osc_type::hse, osc_type::hse_bypass)) {
    auto r = RCC::CR::get();
    if constexpr(flags::all(_cfg::osc_type, osc_type::hse_bypass)) {
      r |= RCC::CR::HSEBYP;
    }
    else {
      r &= ~RCC::CR::HSEBYP;
    }
    r |= RCC::CR::HSEON;
    RCC::CR::set(r);
    while(!RCC::CR::is_set(RCC::CR::HSERDY))
      ;
  }

  //
  // LSI
  //

  if constexpr(flags::all(_cfg::osc_type, osc_type::lsi)) {
    RCC::CSR::set_b(RCC::CSR::LSION);
    while(!RCC::CSR::is_set(RCC::CSR::LSIRDY))
      ;
  }

  //
  // LSE, RTC clock mux
  //

  if constexpr(flags::any(_cfg::osc_type, osc_type::lse, osc_type::lse_bypass)) {
    pwr::bkp_write([]
    {
      auto r = RCC::BDCR::get();
      if constexpr(flags::all(_cfg::osc_type, osc_type::lse_bypass)) {
        r |= RCC::BDCR::LSEBYP;
      }
      else {
        r &= ~RCC::BDCR::LSEBYP;
      }

      r &= ~RCC::BDCR::RTCSEL_MASK;
      switch(_cfg::rtcclk_mux)
      {
      case rtcclk_mux::lse:
        r |= RCC::BDCR::RTCSEL_LSE;
        detail::rtc_clock = _cfg::lse_freq;
        break;
      case rtcclk_mux::lsi:
        r |= RCC::BDCR::RTCSEL_LSI;
        detail::rtc_clock = _cfg::lsi_freq;
        break;
      case rtcclk_mux::hse:
        r |= RCC::BDCR::RTCSEL_HSE;
        detail::rtc_clock = _cfg::lse_freq / 128;
        break;
      default:
        detail::rtc_clock = 0;
        break;
      }

      r |= RCC::BDCR::LSEON;
      RCC::BDCR::set(r);
    });

    while(!RCC::BDCR::is_set(RCC::BDCR::LSERDY))
      ;
  }

  //
  // BUS clocks
  //

  {
    auto r = RCC::CFGR::get();
    r &= ~(RCC::CFGR::HPRE_MASK | RCC::CFGR::PPRE1_MASK | RCC::CFGR::PPRE2_MASK);

    switch(_cfg::ahb_div)
    {
    case ahb_div::_2:   r |= RCC::CFGR::HPRE_DIV2;   break;
    case ahb_div::_4:   r |= RCC::CFGR::HPRE_DIV4;   break;
    case ahb_div::_8:   r |= RCC::CFGR::HPRE_DIV8;   break;
    case ahb_div::_16:  r |= RCC::CFGR::HPRE_DIV16;  break;
    case ahb_div::_64:  r |= RCC::CFGR::HPRE_DIV64;  break;
    case ahb_div::_128: r |= RCC::CFGR::HPRE_DIV128; break;
    case ahb_div::_256: r |= RCC::CFGR::HPRE_DIV256; break;
    case ahb_div::_512: r |= RCC::CFGR::HPRE_DIV512; break;
    default: break;
    }

    switch(_cfg::apb1_div)
    {
    case apb1_div::_2:  r |= RCC::CFGR::PPRE1_DIV2;  break;
    case apb1_div::_4:  r |= RCC::CFGR::PPRE1_DIV4;  break;
    case apb1_div::_8:  r |= RCC::CFGR::PPRE1_DIV8;  break;
    case apb1_div::_16: r |= RCC::CFGR::PPRE1_DIV16; break;
    default: break;
    }

    switch(_cfg::apb2_div)
    {
    case apb2_div::_2:  r |= RCC::CFGR::PPRE2_DIV2;  break;
    case apb2_div::_4:  r |= RCC::CFGR::PPRE2_DIV4;  break;
    case apb2_div::_8:  r |= RCC::CFGR::PPRE2_DIV8;  break;
    case apb2_div::_16: r |= RCC::CFGR::PPRE2_DIV16; break;
    default: break;
    }

    RCC::CFGR::set(r);
  }
}

template<typename _cfg>
static inline void post_configure()
{
  using namespace device;

  if constexpr(_cfg::css == css::enable) {
    RCC::CR::set_b(RCC::CR::CSSON);
  }
  else {
    RCC::CR::clr_b(RCC::CR::CSSON);
  }

  //
  // HSE
  //

  if constexpr(flags::none(_cfg::osc_type, osc_type::hse, osc_type::hse_bypass)) {
    RCC::CR::clr_b(RCC::CR::HSEON | RCC::CR::HSEBYP);
    while(RCC::CR::is_set(RCC::CR::HSERDY))
      ;
  }

  //
  // LSI
  //

  if constexpr(flags::all(_cfg::osc_type, osc_type::lsi)) {
    RCC::CSR::clr_b(RCC::CSR::LSION);
    while(RCC::CSR::is_set(RCC::CSR::LSIRDY))
      ;
  }

  //
  // LSE
  //

  if constexpr(flags::any(_cfg::osc_type, osc_type::lse, osc_type::lse_bypass)) {
    pwr::bkp_write([]
    {
      RCC::BDCR::clr_b(RCC::BDCR::LSEON | RCC::BDCR::LSEBYP);
    });

    while(RCC::BDCR::is_set(RCC::BDCR::LSERDY))
      ;
  }

  if constexpr(_cfg::systick_div == systick_div::_1) {
    NVIC::STCSR::set_b(NVIC::STCSR::CLKSOURCE);
  }
  else {
    NVIC::STCSR::clr_b(NVIC::STCSR::CLKSOURCE);
  }

  switch_sysclk<_cfg::sysclk_mux>();

  //
  // HSI
  //

  if constexpr(flags::none(_cfg::osc_type, osc_type::hsi)) {
    RCC::CR::clr_b(RCC::CR::HSION);
    while(RCC::CR::is_set(RCC::CR::HSIRDY))
      ;
  }
}

// ------------------------------------------------------------------------------------------------
} // namespace detail
// ------------------------------------------------------------------------------------------------

namespace clock {

lmcu_inline uint32_t hardware() { return detail::hardware_clock; }

lmcu_inline uint32_t apb1() { return detail::apb1_clock; }

lmcu_inline uint32_t apb2() { return detail::apb2_clock; }

lmcu_inline uint32_t systick() { return detail::systick_clock; }

lmcu_inline uint32_t adc() { return detail::adc_clock; }

lmcu_inline uint32_t rtc() { return detail::rtc_clock; }

} // namespace clock

} // namespace lmcu::rcc
