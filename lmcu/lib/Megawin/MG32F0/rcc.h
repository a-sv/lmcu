#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/flash>
#include <lmcu/dev/cortex/nvic>
#include <lmcu/irq>
#include <lmcu/pwr>

// ------------------------------------------------------------------------------------------------
namespace lmcu::rcc {
// ------------------------------------------------------------------------------------------------

// for c++17 and higher:
template <auto val>
constexpr void static_print() {
    #if !defined(__GNUC__) || defined(__clang__)
        int static_print_is_implemented_only_for_gcc = 0;
    #else
        int unused = 0;
    #endif
}

extern uint32_t
  hardware_clock,
  ihrco_clock,
  systick_clock,
  apb_clock,
  ahb_clock
;

#if defined(LMCU_MG32F0_1ST)
  static constexpr uint8_t CSC_STA_VER = 0;
  static constexpr uint8_t PLL_VER = 0;
  static constexpr uint8_t PLLI_VER = 0;
  static constexpr uint8_t HS_SEL_VER = 0;
#elif defined(LMCU_MG32F0_2ND)
  static constexpr uint8_t CSC_STA_VER = 1;
  static constexpr uint8_t PLL_VER = 0;
  static constexpr uint8_t PLLI_VER = 0;
  static constexpr uint8_t HS_SEL_VER = 0;
#elif defined(LMCU_MG32F0_3RD)
  static constexpr uint8_t CSC_STA_VER = 2
  static constexpr uint8_t PLL_VER = 1;
  static constexpr uint8_t PLLI_VER = 1;
  static constexpr uint8_t HS_SEL_VER = 0;
  static constexpr uint8_t HS2_SEL_VER = 0;
#elif defined(LMCU_MG32F0_4TH)
  static constexpr uint8_t CSC_STA_VER = 3;
  static constexpr uint8_t PLL_VER = 1;
  static constexpr uint8_t PLLI_VER = 1;
  static constexpr uint8_t HS_SEL_VER = 0;
  static constexpr uint8_t HS2_SEL_VER = 0;
#endif

enum class xosc_freq : uint32_t { };

enum class hs_sel : uint32_t
{
  lmcu_flags,

  ihirco     = 1 << 0, // 12MHz or 11.059MHz internal high speed RC oscillator
  xosc       = 1 << 1, // external crystal
  ilrco      = 1 << 2, // 32 kHz internal low speed RC oscillator
  ext        = 1 << 3, // PLL output clock frequency
};

enum class main_sel
{
  pllo,
  plli,
  hs
};

enum class ihirco_sel { _12MHz, _11MHz };

enum class mcd_sel
{
  _125us,
  _250us,
  _500us,
  _1ms
};

enum class xosc_gn { normal, medium, lowest };

enum class mcd { enable, disable };

enum class ahb_div
{
  _1   = 1,
  _2   = 2,
  _4   = 4,
  _8   = 8,
  _16  = 16,
  _32  = 32,
  _64  = 64,
  _128 = 128,
  _256 = 256,
  _512 = 512
};

enum class apb_div
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

enum class plli_div
{
  _1  = 1,
  _2  = 2,
  _4  = 4,
  _6  = 6
};

enum class pllo_div
{
  _1  = 1,
  _2  = 2,
  _3  = 3,
  _4  = 4
};

enum class ut_div
{
  _8  = 8,
  _16  = 16,
  _32  = 32,
  _128  = 128
};

enum class pll_mul
{
  _16  = 16,
  _24  = 24,
};

template<typename _cfg>
lmcu_inline uint32_t enable_ihrco()
{
  using namespace device;
  uint32_t freq = 12_MHz;

  if constexpr(_cfg::ihirco_sel == ihirco_sel::_11MHz) {
    CSC::CR0::set_b(CSC::CR0::IHRCO_SEL_11);
    freq = 11.059_MHz;
  }
  else {
    CSC::CR0::clr_b(CSC::CR0::IHRCO_SEL_MASK);
  }

  if(!(CSC::CR0::get()&CSC::CR0::IHRCO_EN_ENABLE)) {
    CSC::CR0::set_b(CSC::CR0::IHRCO_EN_ENABLE);
  }

  if constexpr(CSC_STA_VER == 0) {
    // Wait IHRCO ready
    while((CSC::STA::get()&CSC::STA::IHRCOF_HAPPENED) == 0);
  }

  if constexpr(CSC_STA_VER == 1) {
    while((CSC::STA::get()&CSC::STA::ILRCO_STA_READY) == 0);
  }

  CSC::STA::clr_b(CSC::STA::ILRCOF_HAPPENED);
  return freq;
}

template<typename _cfg>
lmcu_inline uint32_t enable_xosc()
{
  using namespace device;
  uint32_t freq = 0;

  // Enable PC clock
  CSC::AHB::set_b(CSC::AHB::IOPC_EN_ENABLE);
  // Set PC13 and PC14 analog IO and AFS is XOSC pin
  PC::CR::clr_b(13, PC::CR::IOM_MASK);
  PC::CR::clr_b(14, PC::CR::IOM_MASK);

  if constexpr(CSC_STA_VER == 0) {
    // Wait XOSC ready
    while((CSC::STA::get()&CSC::STA::XOSCF_HAPPENED) == 0);
  }

  if constexpr((CSC_STA_VER == 1) || (CSC_STA_VER == 2)) {
    // Wait XOSC ready
    while((CSC::STA::get()&CSC::STA::XOSC_STA_READY) == 0);
  }

  // Clear XOSCF
  CSC::STA::set_b(CSC::STA::XOSCF_HAPPENED);

  return freq;
}

template <auto ..._args>
struct config
{
  static constexpr uint32_t ihirco_freq = 12_MHz;

  static constexpr uint32_t ilrco_freq = 32_kHz;

  static constexpr uint32_t xosc_freq = option::get_u<rcc::xosc_freq, _args...>(rcc::xosc_freq(12_MHz)); // 1-36MHz

  static constexpr auto hs_sel = option::get<rcc::hs_sel, _args...>(rcc::hs_sel::ihirco);

  static constexpr auto ihirco_sel = option::get<rcc::ihirco_sel, _args...>(rcc::ihirco_sel::_12MHz);

  static constexpr auto ahb_div = option::get<rcc::ahb_div, _args...>(rcc::ahb_div::_1);

  static constexpr auto apb_div = option::get<rcc::apb_div, _args...>(rcc::apb_div::_1);

  static constexpr auto pllo_div = option::get<rcc::pllo_div, _args...>(rcc::pllo_div::_1);

  static constexpr auto plli_div = option::get<rcc::plli_div, _args...>(rcc::plli_div::_1);

  static constexpr auto systick_div = option::get<rcc::systick_div, _args...>(rcc::systick_div::_1);

  static constexpr auto ut_div = option::get<rcc::ut_div, _args...>(rcc::ut_div::_32);

  static constexpr auto pll_mul = option::get<rcc::pll_mul, _args...>(rcc::pll_mul::_16);

  static constexpr auto mcd_sel = option::get<rcc::mcd_sel, _args...>(rcc::mcd_sel::_125us);

  static constexpr auto xosc_gn = option::get<rcc::xosc_gn, _args...>(rcc::xosc_gn::normal);

  static constexpr auto mcd = option::get<rcc::mcd, _args...>(rcc::mcd::enable);

  static_assert(option::check<
    std::tuple<
      rcc::xosc_freq,
      rcc::hs_sel,
      rcc::ihirco_sel,
      rcc::ahb_div,
      rcc::apb_div,
      rcc::pllo_div,
      rcc::plli_div,
      rcc::systick_div,
      rcc::ut_div,
      rcc::pll_mul,
      rcc::xosc_gn,
      rcc::mcd
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

  // Flash wait state setting
  MEM::KEY::set(0xA217);
  MEM::CR0::clr_b(MEM::CR0::FWAIT_MASK);
#if defined(LMCU_MG32F0_3RD) || defined(LMCU_MG32F0_4TH)
  MEM::CR0::set_b(MEM::CR0::FWAIT_ONE);
#endif
  MEM::KEY::set(0);

  // Unprotect CSC module
  CSC::KEY::set(0xA217);

  uint32_t div = 0;
  { // configure PLLI_DIV
    switch (cfg::plli_div) {
    case plli_div::_2: div |= CSC::DIV::PLLI_DIV_DIV2; break;
    case plli_div::_4: div |= CSC::DIV::PLLI_DIV_DIV4; break;
    case plli_div::_6: div |= CSC::DIV::PLLI_DIV_DIV6; break;
    default: break;
    }
  }

  { // configure PLLO_DIV
    switch (cfg::pllo_div) {
    case pllo_div::_1: div |= CSC::DIV::PLLO_DIV_DIV1; break;
    case pllo_div::_2: div |= CSC::DIV::PLLO_DIV_DIV2; break;
    case pllo_div::_3: div |= CSC::DIV::PLLO_DIV_DIV3; break;
    default: break;
    }
  }

  { // configure AHB_DIV
    switch (cfg::ahb_div) {
    case ahb_div::_2: div |= CSC::DIV::AHB_DIV_DIV2; break;
    case ahb_div::_4: div |= CSC::DIV::AHB_DIV_DIV4; break;
    case ahb_div::_8: div |= CSC::DIV::AHB_DIV_DIV8; break;
    case ahb_div::_16: div |= CSC::DIV::AHB_DIV_DIV16; break;
    case ahb_div::_32: div |= CSC::DIV::AHB_DIV_DIV32; break;
    case ahb_div::_64: div |= CSC::DIV::AHB_DIV_DIV64; break;
    case ahb_div::_128: div |= CSC::DIV::AHB_DIV_DIV128; break;
    case ahb_div::_256: div |= CSC::DIV::AHB_DIV_DIV256; break;
    case ahb_div::_512: div |= CSC::DIV::AHB_DIV_DIV512; break;
    default: break;
    }
  }

  { // configure APB_DIV
    switch (cfg::apb_div) {
    case apb_div::_2: div |= CSC::DIV::APB_DIV_DIV2; break;
    case apb_div::_4: div |= CSC::DIV::APB_DIV_DIV4; break;
    case apb_div::_8: div |= CSC::DIV::APB_DIV_DIV8; break;
    case apb_div::_16: div |= CSC::DIV::APB_DIV_DIV16; break;
    default: break;
    }
  }

  { } // configure USB_DIV

  { // configure UT_DIV
    switch (cfg::ut_div) {
    case ut_div::_8: div |= CSC::DIV::UT_DIV_DIV8; break;
    case ut_div::_16: div |= CSC::DIV::UT_DIV_DIV16; break;
    case ut_div::_128: div |= CSC::DIV::UT_DIV_DIV128; break;
    default: break;
    }
  }
  CSC::DIV::set(div);

  uint32_t pll = CSC::PLL::get();
  { } // configure PLL_MDS

  { } // configure PLLI_SEL

  { } // configure PLL_VCOS

  { // configure PLL_MUL
    div &= CSC::PLL::PLL_MUL_MASK;
    switch (cfg::pll_mul) {
    case pll_mul::_24: div |= CSC::PLL::PLL_MUL_24; break;
    default: break;
    }
  }

  { } // configure PLL_MULX

  { } // configure XOSC_GN

  CSC::PLL::set(pll);

  { // Missing clock detect select 125us / 250us / 500us / 1ms
    CSC::CR0::clr_b(CSC::CR0::MCD_SEL_MASK);
    switch (cfg::mcd_sel) {
    case mcd_sel::_250us: CSC::CR0::set_b(CSC::CR0::MCD_SEL_250US); break;
    case mcd_sel::_500us: CSC::CR0::set_b(CSC::CR0::MCD_SEL_500US); break;
    case mcd_sel::_1ms:   CSC::CR0::set_b(CSC::CR0::MCD_SEL_1MS); break;
    default: break;
    }
  }

  // When XOSC gain is lowest or normal low gain, will disable "miss clock detect"
  if constexpr((cfg::xosc_gn == xosc_gn::normal) || (cfg::xosc_gn == xosc_gn::lowest)) {
    CSC::CR0::set_b(CSC::CR0::MCD_DIS_DISABLE);
  }
  else { // When XOSC is medium gain, and configuration enables "miss clock detect", will enable "miss clock detect"
      if constexpr(cfg::mcd == mcd::enable) { CSC::CR0::clr_b(CSC::CR0::MCD_DIS_MASK); }
  }


  if constexpr(cfg::hs_sel != hs_sel::xosc) {
      ihrco_clock = enable_ihrco<cfg>();
  }

  // Switch clock select

  if constexpr(cfg::hs_sel == hs_sel::xosc) {
    static_assert((cfg::xosc_freq >= 1_MHz)&&(cfg::xosc_freq <= 25_MHz), "XOSC clock must be from 1 to 25 MHz");
    CSC::CR0::set_b(CSC::CR0::HS_SEL_XOSC);
    while((CSC::STA::get()&CSC::STA::XOSC_STA_READY) != 0);
  }
  else if constexpr(cfg::hs_sel == hs_sel::ilrco) {
    CSC::CR0::set_b(CSC::CR0::HS_SEL_ILRCO);
  }
  else if constexpr(cfg::hs_sel == hs_sel::ext) {
    CSC::CR0::set_b(CSC::CR0::HS_SEL_CK_EXT);
  }

  constexpr auto plli_freq = cfg::xosc_freq / uint32_t(cfg::plli_div);
  static_assert((plli_freq >= 5_MHz)&&(plli_freq <= 7_MHz), "PLLI clock must be from 5 to 7 MHz");

  constexpr auto pll_freq = plli_freq * uint32_t(cfg::pll_mul);
  static_assert((pll_freq >= 96_MHz)&&(pll_freq <= 144_MHz), "PLL clock must be from 96 to 144 MHz");


 // static_print<pll_freq>();

  CSC::KEY::set(0);
}

// ------------------------------------------------------------------------------------------------
namespace clock {
// ------------------------------------------------------------------------------------------------

lmcu_inline uint32_t hardware() { return hardware_clock; }

lmcu_inline uint32_t ihrco() { return ihrco_clock; }

lmcu_inline uint32_t systick() { return systick_clock; }

lmcu_inline uint32_t apb() { return apb_clock; }

lmcu_inline uint32_t ahb() { return ahb_clock; }

// ------------------------------------------------------------------------------------------------
} // namespace clock
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::rcc
// ------------------------------------------------------------------------------------------------
