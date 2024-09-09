#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/flash>
#include <lmcu/dev/cortex/nvic>
#include <lmcu/irq>
#include <lmcu/pwr>

#include "sys.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::rcc {
// ------------------------------------------------------------------------------------------------

extern uint32_t
  hardware_clock,
  pclk0_clock,
  pclk1_clock,
  systick_clock,
  hirc_clock,
  lxt_clock,
  hxt_clock,
  pll_clock,
  rtc_clock,
  usb_clock
;

enum class hxt_freq : uint32_t { };

enum class lxt_freq : uint32_t { };

enum class pll_freq : uint32_t { };

enum class osc_type : uint32_t
{
  lmcu_flags,
  
  hirc       = 1 << 0, // 12 MHz internal high speed RC oscillator
  lirc       = 1 << 1, // 10 kHz internal low speed RC oscillator
  pll        = 1 << 2, // PLL output clock frequency
  lxt        = 1 << 3, // 32.768 kHz external low speed crystal oscillator
  hxt        = 1 << 4, // external high speed crystal oscillator
  hirc48m 	 = 1 << 5, // 48 MHz internal high speed RC oscillator
  hclk       = 1 << 6,
  hirc_div2  = 1 << 7,
  hclk_div2  = 1 << 8,
  hxt_div2   = 1 << 9,
  pclk0      = 1 << 10,
  pclk1      = 1 << 11
};	

enum class pclk_div
{
  _1  = 1,
  _2  = 2,
  _4  = 4,
  _8  = 8,
  _16 = 16
};

//enum class hxt { disable, enable };

enum class hclk_mux { hirc, lirc, pll, lxt, hxt };

enum class pll_mux { hirc, hxt };

enum class wdtclk_mux { lirc, hclk, lxt };

enum class wwdtclk_mux { lirc, hclk };

enum class sysclk_mux { hirc_div2, hclk_div2, hxt_div2, lxt, hxt };

enum class rtcclk_mux { lirc, lxt };

// QSPI0 + SPI1
enum class spiclk1_mux { hirc, pclk0, pll, hxt };

// QSPI1 + SPI0 + SPI2
enum class spiclk2_mux { hirc, pclk1, pll, hxt };

enum class uartclk_mux { hirc, lxt, pll, hxt };

enum class usb_mux { hirc, pll };

enum class usb_div
{
  _1   = 1,
  _2   = 2,
  _3   = 3,
  _4   = 4,
  _5   = 5,
  _6   = 6,
  _7   = 7,
  _8   = 8,
  _9   = 9,
  _10  = 10,
  _11  = 11,
  _12  = 12,
  _13  = 13,
  _14  = 14,
  _15  = 15,
  _16  = 16,
};

template<typename _cfg>
lmcu_inline uint32_t enable_pll()
{
  using namespace device;

  uint32_t pll_src_clk, nr, nf, no, pll_clk, clk_src;
  uint32_t tmp, tmp2, tmp3, min, min_nf, min_nr, min_no, bas_freq;
  uint32_t pll_freq = _cfg::pll_freq;

  // disable PLL
  CLK::PLLCTL::set_b(CLK::PLLCTL::PD_MASK);

  if(_cfg::pll_mux == pll_mux::hxt) {
    // enable HXT clock
    //CLK::PWRCTL::set_b(CLK::PWRCTL::HXTEN_1);

    // wait for HXT clock ready
    //while(!CLK::STATUS::is_set(CLK::STATUS::HXTSTB_1));

    // select PLL source clock from HXT
    clk_src = CLK::PLLCTL::PLLSRC_0;
    pll_src_clk = _cfg::hxt_freq;

    // NR start from 2
    nr = 2;
  }
  else if(_cfg::pll_mux == pll_mux::hirc) {
    // enable HIRC clock
    //CLK::PWRCTL::set_b(CLK::PWRCTL::HIRCEN_1);

    // wait for HIRC clock ready
    //while(!CLK::STATUS::is_set(CLK::STATUS::HXTSTB_1));

    // Select PLL source clock from HIRC
    clk_src = CLK::PLLCTL::PLLSRC_1;
    pll_src_clk = _cfg::hirc_freq;

    // NR start from 4 when FIN = 22.1184MHz to avoid calculation overflow
    nr = 4;
  }

  if((pll_freq <= 500_MHz) && (pll_freq >= 50_MHz)) {
    // find best solution
    min = (uint32_t) - 1;
    min_nr = 0uL;
    min_nf = 0uL;
    min_no = 0uL;
    bas_freq = pll_freq;

    for(no = 1uL; no <= 4uL; no++) {
      // Break when get good results
      if(min == 0) {
        break;
      }

      if(no != 3uL) {
        if(no == 4uL) {
          pll_freq = bas_freq << 2;
        }
        else if(no == 2uL) {
          pll_freq = bas_freq << 1;
        }

        for(nr = 2uL; nr <= 32uL; nr++) {
          // Break when get good results
          if (min == 0uL) {
            break;
          }

          tmp = pll_src_clk / nr;
          if((tmp >= 4000000uL) && (tmp <= 8000000uL)) {
            for(nf = 2UL; nf <= 513UL; nf++) {
              // u32Tmp2 is shifted 2 bits to avoid overflow
              tmp2 = (((tmp * 2uL) >> 2) * nf);

              if((tmp2 >= 50_MHz) && (tmp2 <= 125_MHz)) {
                tmp3 = (tmp2 > (pll_freq>>2)) ? tmp2 - (pll_freq>>2) : (pll_freq>>2) - tmp2;
                if(tmp3 < min) {
                  min = tmp3;
                  min_nr = nr;
                  min_nf = nf;
                  min_no = no;

                  // Break when get good results
                  if(min == 0uL) {
                    break;
                  }
                }
              }
            }
          }
        }
      }
    }

    // Enable and apply new PLL setting
    CLK::PLLCTL::set(clk_src | ((min_no - 1uL) << 14) | ((min_nr - 1uL) << 9) | (min_nf - 2uL));
    CLK::PLLCTL::clr_b(CLK::PLLCTL::PD_1);

    // wait for PLL clock stable
    while(!CLK::STATUS::is_set(CLK::STATUS::PLLSTB_1));

    // actual PLL output clock frequency
    pll_clk = pll_src_clk / (min_no * (min_nr)) * (min_nf) * 2uL;
  }


  /*else {
    // Wrong frequency request. Just return default setting
    // Apply default PLL setting and return



    if(_cfg::pll_mux == pll_mux::hxt) {
      //  CLK_PLLCTL_PLLSRC_HXT  | CLK_PLLCTL_NR(2UL) | CLK_PLLCTL_NF( 32UL) | CLK_PLLCTL_NO_2)

      CLK::PLLCTL::set(CLK::PLLCTL::PLLSRC_0 | ;
    }
    else if(_cfg::pll_mux == pll_mux::hirc) {

    }
  }*/


  return pll_clk;
}

template <auto ..._args>
struct config
{
  static constexpr uint32_t hirc_freq = 12_MHz;

  static constexpr uint32_t lirc_freq = 10_kHz;

  static constexpr uint32_t hirc48m_freq = 48_MHz;

  static constexpr uint32_t hxt_freq = option::get_u<rcc::hxt_freq, _args...>(rcc::hxt_freq(16_MHz));

  static constexpr uint32_t lxt_freq = option::get_u<rcc::lxt_freq, _args...>(rcc::lxt_freq(32768));

//  static constexpr auto hxt = option::get<rcc::hxt, _args...>(rcc::hxt::enable); //disable

  static constexpr auto osc_type = option::get<rcc::osc_type, _args...>(rcc::osc_type::hirc);

  static constexpr auto pll_mux = option::get<rcc::pll_mux, _args...>(rcc::pll_mux::hxt);

  static constexpr uint32_t pll_freq = option::get_u<rcc::pll_freq, _args...>(rcc::pll_freq(192_MHz));

  static constexpr auto hclk_mux = option::get<rcc::hclk_mux, _args...>(rcc::hclk_mux::hxt);

  static constexpr auto sysclk_mux = option::get<rcc::sysclk_mux, _args...>(rcc::sysclk_mux::hxt);

  static constexpr auto usb_mux = option::get<rcc::usb_mux, _args...>(rcc::usb_mux::hirc);

  static constexpr auto usb_div = option::get<rcc::usb_div, _args...>(rcc::usb_div(1)); // 1-16

  static_assert(option::check<
    std::tuple<
      rcc::hxt_freq,
      rcc::lxt_freq,
      rcc::osc_type,
      rcc::pll_mux,
      rcc::hclk_mux,
      rcc::sysclk_mux,
      rcc::usb_mux,
      rcc::usb_div
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

  // read HIRC clock source stable flag
  if(!(CLK::STATUS::get() & CLK::STATUS::HIRCSTB_1)) {
    // switch HCLK clock source to HIRC clock for safe
    CLK::PWRCTL::set_b(CLK::PWRCTL::HIRCEN_1);
    while(!CLK::STATUS::is_set(CLK::STATUS::HIRCSTB_1));
  }

  CLK::CLKSEL0::set_b(CLK::CLKSEL0::HCLKSEL_7);
  CLK::CLKDIV0::clr_b(CLK::CLKDIV0::HCLKDIV_MASK);

  // enable HXT clock
  {
    switch (cfg::osc_type) {
    case osc_type::hxt:
      if(!(CLK::STATUS::is_set(CLK::STATUS::HXTSTB_1))) {
        CLK::PWRCTL::set_b(CLK::PWRCTL::HXTEN_1);
        while(!CLK::STATUS::is_set(CLK::STATUS::HXTSTB_1));
      }
      break;
    default: break;
    }
  }

  static_assert(!(cfg::pll_mux == pll_mux::hxt && cfg::osc_type != osc_type::hxt), "PLL clock source is HXT, but HXT not enabled");

  // configure PLL clock
  {
    switch (cfg::pll_mux) {
    case pll_mux::hirc: CLK::PLLCTL::set_b(CLK::PLLCTL::PLLSRC_1); break;
    case pll_mux::hxt: CLK::PLLCTL::clr_b(CLK::PLLCTL::PLLSRC_MASK); break;
    default: break;
    }
  }

  // congigure HCLK
  {
    static_assert(!(cfg::pll_freq > 192_MHz), "PLL frequency must be less or equal 192 MHz");

    // set access cycle for CPU @ 192MHz
    FMC::CYCCTL::clr_b(FMC::CYCCTL::CYCLE_MASK);
    FMC::CYCCTL::set(FMC::CYCCTL::CYCLE_8);

    // configure PLL clock
    pll_clock = enable_pll<cfg>();

    switch (cfg::hclk_mux) {
    case hclk_mux::hxt:
      CLK::PCLKDIV::set((1<<CLK::PCLKDIV::APB0DIV_POS) | (1<<CLK::PCLKDIV::APB1DIV_POS));
      CLK::CLKSEL0::clr_b(CLK::CLKSEL0::HCLKSEL_MASK);
      hardware_clock = cfg::hxt_freq;
      break;
    case hclk_mux::lxt:
      CLK::PCLKDIV::set((1<<CLK::PCLKDIV::APB0DIV_POS) | (1<<CLK::PCLKDIV::APB1DIV_POS));
      CLK::CLKSEL0::set(CLK::CLKSEL0::HCLKSEL_1);
      hardware_clock = cfg::lxt_freq;
      break;
    case hclk_mux::pll:
      CLK::PCLKDIV::set((2<<CLK::PCLKDIV::APB0DIV_POS) | (2<<CLK::PCLKDIV::APB1DIV_POS));
      CLK::CLKDIV0::set(0); // 1<<CLK::CLKDIV0::HCLKDIV_POS
      CLK::CLKSEL0::set((CLK::CLKSEL0::get() & (~CLK::CLKSEL0::HCLKSEL_MASK)) | CLK::CLKSEL0::HCLKSEL_2);
      hardware_clock = pll_clock;
      pclk0_clock = hardware_clock/2;
      pclk1_clock = hardware_clock/2;
      break;
    case hclk_mux::lirc:
      CLK::PCLKDIV::set((1<<CLK::PCLKDIV::APB0DIV_POS) | (1<<CLK::PCLKDIV::APB1DIV_POS));
      CLK::CLKSEL0::set(CLK::CLKSEL0::HCLKSEL_3);
      hardware_clock = cfg::lirc_freq;
      break;
    case hclk_mux::hirc:
      CLK::PCLKDIV::set((1<<CLK::PCLKDIV::APB0DIV_POS) | (1<<CLK::PCLKDIV::APB1DIV_POS));
      CLK::CLKSEL0::set(CLK::CLKSEL0::HCLKSEL_7);
      hardware_clock = cfg::hirc_freq;
      break;
    default: break;
    }

    //
    //CLK::CLKDIV0::clr_b(CLK::CLKDIV0::HCLKDIV_MASK);  CLKSEL0: 0x00F3013A  0x00F30107

    //if(hirc_state == 0) {
    //    CLK::STATUS::set_b(CLK::STATUS::HIRCSTB_1);
    //}

    CLK::CLKSEL0::clr_b(CLK::CLKSEL0::STCLKSEL_MASK);
    //NVIC::STCSR::set_b(NVIC::STCSR::CLKSOURCE);
    //systick_clock = hardware_clock;
    systick_clock = uint32_t(cfg::hxt_freq);
    //hardware_clock = uint32_t(cfg::hxt_freq);

    CLK::AHBCLK::set_b(CLK::AHBCLK::ISPCKEN_MASK);
    FMC::ISPCTL::set_b(FMC::ISPCTL::ISPEN_MASK | FMC::ISPCTL::LDUEN_1);

    CLK::CLKDIV0::clr_b(CLK::CLKDIV0::USBDIV_MASK);
    CLK::CLKDIV0::set_b((uint32_t(cfg::usb_div)-1)<<CLK::CLKDIV0::USBDIV_POS);
    if(cfg::usb_mux == usb_mux::pll) { CLK::CLKSEL0::set_b(CLK::CLKSEL0::USBSEL_1); }

    //auto r = CLK::CLKSEL0::get();

    hirc_clock = cfg::hirc_freq;

    lxt_clock = cfg::lxt_freq;

    hxt_clock = uint32_t(cfg::hxt_freq);

//hardware_clock


  }

  sys::lock();

}


// ------------------------------------------------------------------------------------------------
namespace clock {
// ------------------------------------------------------------------------------------------------

lmcu_inline uint32_t hardware() { return hardware_clock; }

lmcu_inline uint32_t pclk0() { return pclk0_clock; }

lmcu_inline uint32_t pclk1() { return pclk1_clock; }

lmcu_inline uint32_t systick() { return systick_clock; }

lmcu_inline uint32_t hirc() { return hirc_clock; }

lmcu_inline uint32_t hxt() { return hxt_clock; }

lmcu_inline uint32_t lxt() { return lxt_clock; }

lmcu_inline uint32_t pll() { return pll_clock; }

lmcu_inline uint32_t rtc() { return rtc_clock; }

lmcu_inline uint32_t usb() { return usb_clock; }

// ------------------------------------------------------------------------------------------------
} // namespace clock
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::rcc
// ------------------------------------------------------------------------------------------------ 
