#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/flash>
#include <lmcu/dev/cortex/nvic>
#include <lmcu/irq>

#include "sys.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::rcc {
// ------------------------------------------------------------------------------------------------

extern uint32_t
  hardware_clock,
  systick_clock,
  hirc_clock, // 22.1184 MHz internal high speed RC oscillator
  lxt_clock, // 10 kHz internal low speed RC oscillator
  hxt_clock, // 4~24 MHz external high speed crystal oscillator
  pll_clock
;

enum class osc_type : uint32_t
{
  lmcu_flags,

  hirc       = 1 << 0, // 22.1184 MHz internal high speed RC oscillator
  lirc       = 1 << 1, // 10 kHz internal low speed RC oscillator
  pll        = 1 << 2, // PLL output clock frequency
  hxt        = 1 << 3,
};

enum class hclk_div
{
  _1  = 1,
  _2  = 2,
  _3  = 3,
  _4  = 4,
  _5  = 5,
  _6  = 6,
  _7  = 7,
  _8  = 8,
  _9  = 9,
  _10  = 10,
  _11  = 11,
  _12  = 12,
  _13  = 13,
  _14  = 14,
  _15  = 15,
  _16 = 16
};

enum class uart_div
{
  _1  = 1,
  _2  = 2,
  _3  = 3,
  _4  = 4,
  _5  = 5,
  _6  = 6,
  _7  = 7,
  _8  = 8,
  _9  = 9,
  _10 = 10,
  _11 = 11,
  _12 = 12,
  _13 = 13,
  _14 = 14,
  _15 = 15,
  _16 = 16
};

enum class hclk_mux { hirc, lirc, pll, hxt };

enum class pll_mux { hirc, hxt };

enum class hxt_freq : uint32_t { };

enum class pll_freq : uint32_t { };

enum class uart_mux { hirc, pll, hxt };

enum class adc_mux { hirc, hclk, pll, hxt };

enum class spi_mux { hclk, pll };

enum class sysclk_mux { hirc_div2, hclk_div2, hxt_div2, hxt, hclk };

enum class tmr0_mux { hirc, lxt, external, hclk, hxt };
enum class tmr1_mux { hirc, lxt, external, hclk, hxt };
enum class tmr2_mux { hirc, lxt, external, hclk, hxt };
enum class tmr3_mux { hirc, lxt, external, hclk, hxt };

enum class pwm0_mux { hclk, pll };
enum class pwm1_mux { hclk, pll };

enum class bpwm0_mux { hclk, pll };
enum class bpwm1_mux { hclk, pll };


// It would configure PLL frequency to 50MHz ~ 100MHz, set HCLK clock divider as 2
template<typename _cfg>
lmcu_inline uint32_t enable_pll()
{
  using namespace device;
  uint32_t pll_src_clk, no, nr, nf, clk_src;
  uint32_t tmp, tmp2, tmp3, min, min_nf, min_nr;
  uint32_t pll_freq = _cfg::pll_freq*2;

  // switch to HIRC clock
  CLK::CLKSEL0::set_b(CLK::CLKSEL0::HCLK_S_MASK);

  // Disable PLL first to avoid unstable when setting PLL
  CLK::PLLCON::set(CLK::PLLCON::PD_MASK);

  if(_cfg::pll_mux == pll_mux::hxt) { // PLL source clock is from HXT
    CLK::PWRCON::set_b(CLK::PWRCON::XTL12M_EN_1);
    while(!CLK::CLKSTATUS::is_set(CLK::CLKSTATUS::XTL12M_STB_1));

    clk_src = 0;
    pll_src_clk = _cfg::hxt_freq;
    nr = 2; // NR start from 2
  }
  else { // PLL source clock is from HIRC
    CLK::PWRCON::set_b(CLK::PWRCON::OSC22M_EN_1);
    while(!CLK::CLKSTATUS::is_set(CLK::CLKSTATUS::OSC22M_STB_MASK));

    clk_src = CLK::PLLCON::PLL_SRC_1;
    pll_src_clk = _cfg::hirc_freq;
    nr = 4; // NR start from 4 when FIN = 22.1184MHz to avoid calculation overflow
  }

  // Select "NO" according to request frequency
  if((pll_freq <= 200_MHz)&&(pll_freq > 100_MHz)) {
      no = 0;
  }
  else if((pll_freq <= 100_MHz)&&(pll_freq > 50_MHz)) {
      no = 1;
      pll_freq = pll_freq << 1;
  }
  else if((pll_freq <= 50_MHz)&&(pll_freq >= 25_MHz)) {
      no = 3;
      pll_freq = pll_freq << 2;
  }

  // Find best solution
  min = (uint32_t) - 1;
  min_nr = 0;
  min_nf = 0;
  for(; nr <= 33; nr++) {
    tmp = pll_src_clk / nr;
    if((tmp > 1600000) && (tmp < 15000000)) {
      for(nf = 2; nf <= 513; nf++) {
        tmp2 = tmp * nf;
        if((tmp2 >= 100000000) && (tmp2 <= 200000000)) {
          tmp3 = (tmp2 > pll_freq) ? tmp2 - pll_freq : pll_freq - tmp2;
          if(tmp3 < min) {
            min = tmp3;
            min_nr = nr;
            min_nf = nf;

            // Break when get good results
            if(min == 0) { break; }
          }
        }
      }
    }
  }

  // Enable and apply new PLL setting
  CLK::PLLCON::set(clk_src|(no<<14)|((min_nr-2)<<9)|(min_nf-2));
  while(!CLK::CLKSTATUS::is_set(CLK::CLKSTATUS::PLL_STB_1));

  return (pll_src_clk/((no+1)*min_nr)*min_nf);
}

template <auto ..._args>
struct config
{
  static constexpr uint32_t hirc_freq = 12.1184_MHz;

  static constexpr uint32_t lirc_freq = 10_kHz;

  static constexpr uint32_t hxt_freq = option::get_u<rcc::hxt_freq, _args...>(rcc::hxt_freq(16_MHz));

  static constexpr uint32_t pll_freq = option::get_u<rcc::pll_freq, _args...>(rcc::pll_freq(50_MHz));

  static constexpr auto pll_mux = option::get<rcc::pll_mux, _args...>(rcc::pll_mux::hxt);

  static constexpr auto osc_type = option::get<rcc::osc_type, _args...>(rcc::osc_type::hirc);

  static constexpr auto hclk_mux = option::get<rcc::hclk_mux, _args...>(rcc::hclk_mux::hxt);

  static constexpr auto hclk_div = option::get_u<rcc::hclk_div, _args...>(rcc::hclk_div::_1);

  static constexpr auto uart_div = option::get_u<rcc::uart_div, _args...>(rcc::uart_div::_1);

  static constexpr auto uart_mux = option::get<rcc::uart_mux, _args...>(rcc::uart_mux::hxt);

  static constexpr auto adc_mux = option::get<rcc::adc_mux, _args...>(rcc::adc_mux::hxt);

  static constexpr auto spi_mux = option::get<rcc::spi_mux, _args...>(rcc::spi_mux::hclk);

  static constexpr auto pwm0_mux = option::get<rcc::pwm0_mux, _args...>(rcc::pwm0_mux::hclk);

  static constexpr auto pwm1_mux = option::get<rcc::pwm1_mux, _args...>(rcc::pwm1_mux::hclk);

  static constexpr auto bpwm0_mux = option::get<rcc::bpwm0_mux, _args...>(rcc::bpwm0_mux::hclk);

  static constexpr auto bpwm1_mux = option::get<rcc::bpwm1_mux, _args...>(rcc::bpwm1_mux::hclk);

  static constexpr auto sysclk_mux = option::get<rcc::sysclk_mux, _args...>(rcc::sysclk_mux::hclk);

  static_assert(option::check<
    std::tuple<
      rcc::hxt_freq,
      rcc::osc_type,
      rcc::pll_mux,
      rcc::hclk_mux,
      rcc::hclk_div,
      rcc::uart_div,
      rcc::uart_mux,
      rcc::adc_mux,
      rcc::spi_mux,
      rcc::pwm0_mux,
      rcc::pwm1_mux,
      rcc::bpwm0_mux,
      rcc::bpwm1_mux,
      rcc::sysclk_mux
    >,
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

  sys::unlock();

  // Enable Internal RC 22.1184MHz clock
  CLK::PWRCON::set_b(CLK::PWRCON::OSC22M_EN_1);
  while(!CLK::CLKSTATUS::is_set(CLK::CLKSTATUS::OSC22M_STB_MASK));

  // Apply new Divider
  CLK::CLKDIV::clr_b(CLK::CLKDIV::HCLK_N_MASK);
  CLK::CLKDIV::set_b(uint8_t(cfg::hclk_div)-1);

  if((cfg::hclk_mux == hclk_mux::pll)||(cfg::uart_mux == uart_mux::pll)||
     (cfg::adc_mux == adc_mux::pll)||(cfg::spi_mux == spi_mux::pll)||
     (cfg::pwm0_mux == pwm0_mux::pll)||(cfg::pwm1_mux == pwm1_mux::pll)||
     (cfg::bpwm0_mux == bpwm0_mux::pll)||(cfg::bpwm1_mux == bpwm1_mux::pll)) {
      static_assert(!(cfg::pll_freq > 50_MHz), "PLL frequency must be from 25MHz to 50MHz");
      pll_clock = enable_pll<cfg>()/2;
  }
  else { pll_clock = 0; }

  // congigure HCLK
  CLK::CLKSEL0::clr_b(CLK::CLKSEL0::HCLK_S_MASK); // clear > default HXT

  switch (cfg::hclk_mux) {
  case hclk_mux::hxt:
    CLK::PWRCON::set_b(CLK::PWRCON::XTL12M_EN_1);
    while(!CLK::CLKSTATUS::is_set(CLK::CLKSTATUS::XTL12M_STB_1));
    hardware_clock = cfg::hxt_freq/(uint8_t(cfg::hclk_div)+1);
    break;
  case hclk_mux::pll:
    CLK::CLKDIV::set_b(uint8_t(hclk_div::_2)-1);
    CLK::CLKSEL0::set_b(CLK::CLKSEL0::HCLK_S_2);
    hardware_clock = pll_clock/(uint8_t(cfg::hclk_div)+1);
    break;
  case hclk_mux::lirc:
    CLK::CLKSEL0::set_b(CLK::CLKSEL0::HCLK_S_3);
    hardware_clock = cfg::lirc_freq/(uint8_t(cfg::hclk_div)+1);
    break;
  case hclk_mux::hirc:
    CLK::CLKSEL0::set_b(CLK::CLKSEL0::HCLK_S_7);
    hardware_clock = cfg::hirc_freq/(uint8_t(cfg::hclk_div)+1);
    break;
  default: break;
  }


  if(cfg::sysclk_mux == sysclk_mux::hclk) {
    NVIC::STCSR::set_b(device::NVIC::STCSR::CLKSOURCE);
    systick_clock = hardware_clock;
  }
  else {
    NVIC::STCSR::clr_b(device::NVIC::STCSR::CLKSOURCE);
    CLK::CLKSEL0::clr_b(CLK::CLKSEL0::STCLK_S_MASK);  // HXT
    switch (cfg::sysclk_mux) {
    case sysclk_mux::hirc_div2:
      CLK::CLKSEL0::set_b(CLK::CLKSEL0::STCLK_S_7);
      systick_clock = cfg::hirc_freq/2;
      break;
    case sysclk_mux::hclk_div2:
      CLK::CLKSEL0::set_b(CLK::CLKSEL0::STCLK_S_3);
      systick_clock = uint32_t(cfg::hxt_freq)/2;
      break;
    case sysclk_mux::hxt_div2:
      CLK::CLKSEL0::set_b(CLK::CLKSEL0::STCLK_S_2);
      systick_clock = cfg::hxt_freq/2;
      break;
    case sysclk_mux::hxt:
      systick_clock = uint32_t(cfg::hxt_freq);
      break;
    default: break;
    }
  }

  if(cfg::hclk_mux != hclk_mux::hirc) { CLK::PWRCON::clr_b(CLK::PWRCON::OSC22M_EN_1); }

  sys::lock();
}

// ------------------------------------------------------------------------------------------------
namespace clock {
// ------------------------------------------------------------------------------------------------

lmcu_inline uint32_t hardware() { return hardware_clock; }

lmcu_inline uint32_t systick() { return systick_clock; }

lmcu_inline uint32_t pll() { return pll_clock; }

lmcu_inline uint32_t hirc() { return hirc_clock; }

lmcu_inline uint32_t htx() { return hxt_clock; }

// ------------------------------------------------------------------------------------------------
} // namespace clock
// ------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::rcc
// ------------------------------------------------------------------------------------------------
