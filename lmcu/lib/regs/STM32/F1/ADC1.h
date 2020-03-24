/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Analog to digital converter
// ------------------------------------------------------------------------------------------------
struct ADC1
{
  static constexpr std::uintptr_t base = 0x40012400UL;

  // ADC status register
  struct SR : reg<base + 0x0>
  {
    static constexpr type
    // Analog watchdog flag (bits: 0)
     AWD_MASK = 0x00000001
    ,AWD_POS = 0
    ,AWD = 0x00000001
    // End of conversion (bits: 1)
    ,EOC_MASK = 0x00000002
    ,EOC_POS = 1
    ,EOC = 0x00000002
    // Injected channel end of conversion (bits: 2)
    ,JEOC_MASK = 0x00000004
    ,JEOC_POS = 2
    ,JEOC = 0x00000004
    // Injected channel Start flag (bits: 3)
    ,JSTRT_MASK = 0x00000008
    ,JSTRT_POS = 3
    ,JSTRT = 0x00000008
    // Regular channel Start flag (bits: 4)
    ,STRT_MASK = 0x00000010
    ,STRT_POS = 4
    ,STRT = 0x00000010
    ,SR_MASK = 0x0000001F
    ;
  };
  // ADC control register 1
  struct CR1 : reg<base + 0x4>
  {
    static constexpr type
    // Analog watchdog channel select bits (bits: 4-0)
     AWDCH_MASK = 0x0000001F
    ,AWDCH_POS = 0
    ,AWDCH_0 = 0x00000000 // ADC analog Channel0
    ,AWDCH_1 = 0x00000001 // ADC analog Channel1
    ,AWDCH_2 = 0x00000002 // ADC analog Channel2
    ,AWDCH_3 = 0x00000003 // ADC analog Channel3
    ,AWDCH_4 = 0x00000004 // ADC analog Channel4
    ,AWDCH_5 = 0x00000005 // ADC analog Channel5
    ,AWDCH_6 = 0x00000006 // ADC analog Channel6
    ,AWDCH_7 = 0x00000007 // ADC analog Channel7
    ,AWDCH_8 = 0x00000008 // ADC analog Channel8
    ,AWDCH_9 = 0x00000009 // ADC analog Channel9
    ,AWDCH_10 = 0x0000000A // ADC analog Channel10
    ,AWDCH_11 = 0x0000000B // ADC analog Channel11
    ,AWDCH_12 = 0x0000000C // ADC analog Channel12
    ,AWDCH_13 = 0x0000000D // ADC analog Channel13
    ,AWDCH_14 = 0x0000000E // ADC analog Channel14
    ,AWDCH_15 = 0x0000000F // ADC analog Channel15
    ,AWDCH_16 = 0x00000010 // ADC analog Channel16
    ,AWDCH_17 = 0x00000011 // ADC analog Channel17
    // Interrupt enable for EOC (bits: 5)
    ,EOCIE_MASK = 0x00000020
    ,EOCIE_POS = 5
    ,EOCIE = 0x00000020
    // Analog watchdog interrupt enable (bits: 6)
    ,AWDIE_MASK = 0x00000040
    ,AWDIE_POS = 6
    ,AWDIE = 0x00000040
    // Interrupt enable for injected channels (bits: 7)
    ,JEOCIE_MASK = 0x00000080
    ,JEOCIE_POS = 7
    ,JEOCIE = 0x00000080
    // Scan mode (bits: 8)
    ,SCAN_MASK = 0x00000100
    ,SCAN_POS = 8
    ,SCAN = 0x00000100
    // Enable the watchdog on a single channel in scan mode (bits: 9)
    ,AWDSGL_MASK = 0x00000200
    ,AWDSGL_POS = 9
    ,AWDSGL = 0x00000200
    // Automatic Injected Group conversion (bits: 10)
    ,JAUTO_MASK = 0x00000400
    ,JAUTO_POS = 10
    ,JAUTO = 0x00000400
    // Discontinuous mode on regular channels (bits: 11)
    ,DISCEN_MASK = 0x00000800
    ,DISCEN_POS = 11
    ,DISCEN = 0x00000800
    // Discontinuous mode on injected channels (bits: 12)
    ,JDISCEN_MASK = 0x00001000
    ,JDISCEN_POS = 12
    ,JDISCEN = 0x00001000
    // Discontinuous mode channel count (bits: 15-13)
    ,DISCNUM_MASK = 0x0000E000
    ,DISCNUM_POS = 13
    // Dual mode selection (bits: 19-16)
    ,DUALMOD_MASK = 0x000F0000
    ,DUALMOD_POS = 16
    ,DUALMOD_INDEPENDED = 0x00000000 // Independent mode
    ,DUALMOD_REG_INJ = 0x00010000 // Combined regular simultaneous + injected simultaneous mode
    ,DUALMOD_REG_ALT_TRIG = 0x00020000 // Combined regular simultaneous + alternate trigger mode
    ,DUALMOD_INJ_FAST_INTER = 0x00030000 // Combined injected simultaneous + fast interleaved mode
    ,DUALMOD_INJ_SLOW_INTER = 0x00040000 // Combined injected simultaneous + slow Interleaved mode
    ,DUALMOD_INJ_ONLY = 0x00050000 // Injected simultaneous mode only
    ,DUALMOD_REG_ONLY = 0x00060000 // Regular simultaneous mode only
    ,DUALMOD_FAST_INTER = 0x00070000 // Fast interleaved mode only
    ,DUALMOD_SLOW_INTER = 0x00080000 // Slow interleaved mode only
    ,DUALMOD_ALT_TRIG = 0x00090000 // Alternate trigger mode only
    // Analog watchdog enable on injected channels (bits: 22)
    ,JAWDEN_MASK = 0x00400000
    ,JAWDEN_POS = 22
    ,JAWDEN = 0x00400000
    // Analog watchdog enable on regular channels (bits: 23)
    ,AWDEN_MASK = 0x00800000
    ,AWDEN_POS = 23
    ,AWDEN = 0x00800000
    ,CR1_MASK = 0x00CFFFFF
    ;
  };
  // ADC control register 2
  struct CR2 : reg<base + 0x8>
  {
    static constexpr type
    // A/D converter ON / OFF (bits: 0)
     ADON_MASK = 0x00000001
    ,ADON_POS = 0
    ,ADON = 0x00000001
    // Continuous conversion (bits: 1)
    ,CONT_MASK = 0x00000002
    ,CONT_POS = 1
    ,CONT = 0x00000002
    // A/D Calibration (bits: 2)
    ,CAL_MASK = 0x00000004
    ,CAL_POS = 2
    ,CAL = 0x00000004
    // Reset calibration (bits: 3)
    ,RSTCAL_MASK = 0x00000008
    ,RSTCAL_POS = 3
    ,RSTCAL = 0x00000008
    // Direct memory access mode (bits: 8)
    ,DMA_MASK = 0x00000100
    ,DMA_POS = 8
    ,DMA = 0x00000100
    // Data alignment (bits: 11)
    ,ALIGN_MASK = 0x00000800
    ,ALIGN_POS = 11
    ,ALIGN = 0x00000800
    // External event select for injected group (bits: 14-12)
    ,JEXTSEL_MASK = 0x00007000
    ,JEXTSEL_POS = 12
    // External trigger conversion mode for injected channels (bits: 15)
    ,JEXTTRIG_MASK = 0x00008000
    ,JEXTTRIG_POS = 15
    ,JEXTTRIG = 0x00008000
    // External event select for regular group (bits: 19-17)
    ,EXTSEL_MASK = 0x000E0000
    ,EXTSEL_POS = 17
    // External trigger conversion mode for regular channels (bits: 20)
    ,EXTTRIG_MASK = 0x00100000
    ,EXTTRIG_POS = 20
    ,EXTTRIG = 0x00100000
    // Start conversion of injected channels (bits: 21)
    ,JSWSTART_MASK = 0x00200000
    ,JSWSTART_POS = 21
    ,JSWSTART = 0x00200000
    // Start conversion of regular channels (bits: 22)
    ,SWSTART_MASK = 0x00400000
    ,SWSTART_POS = 22
    ,SWSTART = 0x00400000
    // Temperature sensor and VREFINT enable (bits: 23)
    ,TSVREFE_MASK = 0x00800000
    ,TSVREFE_POS = 23
    ,TSVREFE = 0x00800000
    ,CR2_MASK = 0x00FEF90F
    ;
  };
  // ADC control register 1
  struct SMPR1 : reg<base + 0xC>
  {
    static constexpr type
    // Channel x Sample time selection (bits: 2-0)
     SMP10_MASK = 0x00000007
    ,SMP10_POS = 0
    ,SMP10_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP10_7_5CYC = 0x00000001 // 7.5 cycles
    ,SMP10_13_5CYC = 0x00000002 // 13.5 cycles
    ,SMP10_28_5CYC = 0x00000003 // 28.5 cycles
    ,SMP10_41_5CYC = 0x00000004 // 41.5 cycles
    ,SMP10_55_5CYC = 0x00000005 // 55.5 cycles
    ,SMP10_71_5CYC = 0x00000006 // 71.5 cycles
    ,SMP10_239_5CYC = 0x00000007 // 239.5 cycles
    // Channel x Sample time selection (bits: 5-3)
    ,SMP11_MASK = 0x00000038
    ,SMP11_POS = 3
    ,SMP11_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP11_7_5CYC = 0x00000008 // 7.5 cycles
    ,SMP11_13_5CYC = 0x00000010 // 13.5 cycles
    ,SMP11_28_5CYC = 0x00000018 // 28.5 cycles
    ,SMP11_41_5CYC = 0x00000020 // 41.5 cycles
    ,SMP11_55_5CYC = 0x00000028 // 55.5 cycles
    ,SMP11_71_5CYC = 0x00000030 // 71.5 cycles
    ,SMP11_239_5CYC = 0x00000038 // 239.5 cycles
    // Channel x Sample time selection (bits: 8-6)
    ,SMP12_MASK = 0x000001C0
    ,SMP12_POS = 6
    ,SMP12_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP12_7_5CYC = 0x00000040 // 7.5 cycles
    ,SMP12_13_5CYC = 0x00000080 // 13.5 cycles
    ,SMP12_28_5CYC = 0x000000C0 // 28.5 cycles
    ,SMP12_41_5CYC = 0x00000100 // 41.5 cycles
    ,SMP12_55_5CYC = 0x00000140 // 55.5 cycles
    ,SMP12_71_5CYC = 0x00000180 // 71.5 cycles
    ,SMP12_239_5CYC = 0x000001C0 // 239.5 cycles
    // Channel x Sample time selection (bits: 11-9)
    ,SMP13_MASK = 0x00000E00
    ,SMP13_POS = 9
    ,SMP13_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP13_7_5CYC = 0x00000200 // 7.5 cycles
    ,SMP13_13_5CYC = 0x00000400 // 13.5 cycles
    ,SMP13_28_5CYC = 0x00000600 // 28.5 cycles
    ,SMP13_41_5CYC = 0x00000800 // 41.5 cycles
    ,SMP13_55_5CYC = 0x00000A00 // 55.5 cycles
    ,SMP13_71_5CYC = 0x00000C00 // 71.5 cycles
    ,SMP13_239_5CYC = 0x00000E00 // 239.5 cycles
    // Channel x Sample time selection (bits: 14-12)
    ,SMP14_MASK = 0x00007000
    ,SMP14_POS = 12
    ,SMP14_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP14_7_5CYC = 0x00001000 // 7.5 cycles
    ,SMP14_13_5CYC = 0x00002000 // 13.5 cycles
    ,SMP14_28_5CYC = 0x00003000 // 28.5 cycles
    ,SMP14_41_5CYC = 0x00004000 // 41.5 cycles
    ,SMP14_55_5CYC = 0x00005000 // 55.5 cycles
    ,SMP14_71_5CYC = 0x00006000 // 71.5 cycles
    ,SMP14_239_5CYC = 0x00007000 // 239.5 cycles
    // Channel x Sample time selection (bits: 17-15)
    ,SMP15_MASK = 0x00038000
    ,SMP15_POS = 15
    ,SMP15_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP15_7_5CYC = 0x00008000 // 7.5 cycles
    ,SMP15_13_5CYC = 0x00010000 // 13.5 cycles
    ,SMP15_28_5CYC = 0x00018000 // 28.5 cycles
    ,SMP15_41_5CYC = 0x00020000 // 41.5 cycles
    ,SMP15_55_5CYC = 0x00028000 // 55.5 cycles
    ,SMP15_71_5CYC = 0x00030000 // 71.5 cycles
    ,SMP15_239_5CYC = 0x00038000 // 239.5 cycles
    // Channel x Sample time selection (bits: 20-18)
    ,SMP16_MASK = 0x001C0000
    ,SMP16_POS = 18
    ,SMP16_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP16_7_5CYC = 0x00040000 // 7.5 cycles
    ,SMP16_13_5CYC = 0x00080000 // 13.5 cycles
    ,SMP16_28_5CYC = 0x000C0000 // 28.5 cycles
    ,SMP16_41_5CYC = 0x00100000 // 41.5 cycles
    ,SMP16_55_5CYC = 0x00140000 // 55.5 cycles
    ,SMP16_71_5CYC = 0x00180000 // 71.5 cycles
    ,SMP16_239_5CYC = 0x001C0000 // 239.5 cycles
    // Channel x Sample time selection (bits: 23-21)
    ,SMP17_MASK = 0x00E00000
    ,SMP17_POS = 21
    ,SMP17_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP17_7_5CYC = 0x00200000 // 7.5 cycles
    ,SMP17_13_5CYC = 0x00400000 // 13.5 cycles
    ,SMP17_28_5CYC = 0x00600000 // 28.5 cycles
    ,SMP17_41_5CYC = 0x00800000 // 41.5 cycles
    ,SMP17_55_5CYC = 0x00A00000 // 55.5 cycles
    ,SMP17_71_5CYC = 0x00C00000 // 71.5 cycles
    ,SMP17_239_5CYC = 0x00E00000 // 239.5 cycles
    ,SMPR1_MASK = 0x00FFFFFF
    ;
  };
  // ADC control register 2
  struct SMPR2 : reg<base + 0x10>
  {
    static constexpr type
    // Channel x Sample time selection (bits: 2-0)
     SMP0_MASK = 0x00000007
    ,SMP0_POS = 0
    ,SMP0_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP0_7_5CYC = 0x00000001 // 7.5 cycles
    ,SMP0_13_5CYC = 0x00000002 // 13.5 cycles
    ,SMP0_28_5CYC = 0x00000003 // 28.5 cycles
    ,SMP0_41_5CYC = 0x00000004 // 41.5 cycles
    ,SMP0_55_5CYC = 0x00000005 // 55.5 cycles
    ,SMP0_71_5CYC = 0x00000006 // 71.5 cycles
    ,SMP0_239_5CYC = 0x00000007 // 239.5 cycles
    // Channel x Sample time selection (bits: 5-3)
    ,SMP1_MASK = 0x00000038
    ,SMP1_POS = 3
    ,SMP1_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP1_7_5CYC = 0x00000008 // 7.5 cycles
    ,SMP1_13_5CYC = 0x00000010 // 13.5 cycles
    ,SMP1_28_5CYC = 0x00000018 // 28.5 cycles
    ,SMP1_41_5CYC = 0x00000020 // 41.5 cycles
    ,SMP1_55_5CYC = 0x00000028 // 55.5 cycles
    ,SMP1_71_5CYC = 0x00000030 // 71.5 cycles
    ,SMP1_239_5CYC = 0x00000038 // 239.5 cycles
    // Channel x Sample time selection (bits: 8-6)
    ,SMP2_MASK = 0x000001C0
    ,SMP2_POS = 6
    ,SMP2_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP2_7_5CYC = 0x00000040 // 7.5 cycles
    ,SMP2_13_5CYC = 0x00000080 // 13.5 cycles
    ,SMP2_28_5CYC = 0x000000C0 // 28.5 cycles
    ,SMP2_41_5CYC = 0x00000100 // 41.5 cycles
    ,SMP2_55_5CYC = 0x00000140 // 55.5 cycles
    ,SMP2_71_5CYC = 0x00000180 // 71.5 cycles
    ,SMP2_239_5CYC = 0x000001C0 // 239.5 cycles
    // Channel x Sample time selection (bits: 11-9)
    ,SMP3_MASK = 0x00000E00
    ,SMP3_POS = 9
    ,SMP3_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP3_7_5CYC = 0x00000200 // 7.5 cycles
    ,SMP3_13_5CYC = 0x00000400 // 13.5 cycles
    ,SMP3_28_5CYC = 0x00000600 // 28.5 cycles
    ,SMP3_41_5CYC = 0x00000800 // 41.5 cycles
    ,SMP3_55_5CYC = 0x00000A00 // 55.5 cycles
    ,SMP3_71_5CYC = 0x00000C00 // 71.5 cycles
    ,SMP3_239_5CYC = 0x00000E00 // 239.5 cycles
    // Channel x Sample time selection (bits: 14-12)
    ,SMP4_MASK = 0x00007000
    ,SMP4_POS = 12
    ,SMP4_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP4_7_5CYC = 0x00001000 // 7.5 cycles
    ,SMP4_13_5CYC = 0x00002000 // 13.5 cycles
    ,SMP4_28_5CYC = 0x00003000 // 28.5 cycles
    ,SMP4_41_5CYC = 0x00004000 // 41.5 cycles
    ,SMP4_55_5CYC = 0x00005000 // 55.5 cycles
    ,SMP4_71_5CYC = 0x00006000 // 71.5 cycles
    ,SMP4_239_5CYC = 0x00007000 // 239.5 cycles
    // Channel x Sample time selection (bits: 17-15)
    ,SMP5_MASK = 0x00038000
    ,SMP5_POS = 15
    ,SMP5_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP5_7_5CYC = 0x00008000 // 7.5 cycles
    ,SMP5_13_5CYC = 0x00010000 // 13.5 cycles
    ,SMP5_28_5CYC = 0x00018000 // 28.5 cycles
    ,SMP5_41_5CYC = 0x00020000 // 41.5 cycles
    ,SMP5_55_5CYC = 0x00028000 // 55.5 cycles
    ,SMP5_71_5CYC = 0x00030000 // 71.5 cycles
    ,SMP5_239_5CYC = 0x00038000 // 239.5 cycles
    // Channel x Sample time selection (bits: 20-18)
    ,SMP6_MASK = 0x001C0000
    ,SMP6_POS = 18
    ,SMP6_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP6_7_5CYC = 0x00040000 // 7.5 cycles
    ,SMP6_13_5CYC = 0x00080000 // 13.5 cycles
    ,SMP6_28_5CYC = 0x000C0000 // 28.5 cycles
    ,SMP6_41_5CYC = 0x00100000 // 41.5 cycles
    ,SMP6_55_5CYC = 0x00140000 // 55.5 cycles
    ,SMP6_71_5CYC = 0x00180000 // 71.5 cycles
    ,SMP6_239_5CYC = 0x001C0000 // 239.5 cycles
    // Channel x Sample time selection (bits: 23-21)
    ,SMP7_MASK = 0x00E00000
    ,SMP7_POS = 21
    ,SMP7_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP7_7_5CYC = 0x00200000 // 7.5 cycles
    ,SMP7_13_5CYC = 0x00400000 // 13.5 cycles
    ,SMP7_28_5CYC = 0x00600000 // 28.5 cycles
    ,SMP7_41_5CYC = 0x00800000 // 41.5 cycles
    ,SMP7_55_5CYC = 0x00A00000 // 55.5 cycles
    ,SMP7_71_5CYC = 0x00C00000 // 71.5 cycles
    ,SMP7_239_5CYC = 0x00E00000 // 239.5 cycles
    // Channel x Sample time selection (bits: 26-24)
    ,SMP8_MASK = 0x07000000
    ,SMP8_POS = 24
    ,SMP8_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP8_7_5CYC = 0x01000000 // 7.5 cycles
    ,SMP8_13_5CYC = 0x02000000 // 13.5 cycles
    ,SMP8_28_5CYC = 0x03000000 // 28.5 cycles
    ,SMP8_41_5CYC = 0x04000000 // 41.5 cycles
    ,SMP8_55_5CYC = 0x05000000 // 55.5 cycles
    ,SMP8_71_5CYC = 0x06000000 // 71.5 cycles
    ,SMP8_239_5CYC = 0x07000000 // 239.5 cycles
    // Channel x Sample time selection (bits: 29-27)
    ,SMP9_MASK = 0x38000000
    ,SMP9_POS = 27
    ,SMP9_1_5CYC = 0x00000000 // 1.5 cycles
    ,SMP9_7_5CYC = 0x08000000 // 7.5 cycles
    ,SMP9_13_5CYC = 0x10000000 // 13.5 cycles
    ,SMP9_28_5CYC = 0x18000000 // 28.5 cycles
    ,SMP9_41_5CYC = 0x20000000 // 41.5 cycles
    ,SMP9_55_5CYC = 0x28000000 // 55.5 cycles
    ,SMP9_71_5CYC = 0x30000000 // 71.5 cycles
    ,SMP9_239_5CYC = 0x38000000 // 239.5 cycles
    ,SMPR2_MASK = 0x3FFFFFFF
    ;
  };
  // ADC injected channel data offset register 1
  struct JOFR1 : reg<base + 0x14>
  {
    static constexpr type
    // Data offset for injected channel x (bits: 11-0)
     JOFFSET_MASK = 0x00000FFF
    ,JOFFSET_POS = 0
    ,JOFR1_MASK = 0x00000FFF
    ;
  };
  // ADC injected channel data offset register 2
  struct JOFR2 : reg<base + 0x18>
  {
    static constexpr type
    // Data offset for injected channel x (bits: 11-0)
     JOFFSET_MASK = 0x00000FFF
    ,JOFFSET_POS = 0
    ,JOFR2_MASK = 0x00000FFF
    ;
  };
  // ADC injected channel data offset register 3
  struct JOFR3 : reg<base + 0x1C>
  {
    static constexpr type
    // Data offset for injected channel x (bits: 11-0)
     JOFFSET_MASK = 0x00000FFF
    ,JOFFSET_POS = 0
    ,JOFR3_MASK = 0x00000FFF
    ;
  };
  // ADC injected channel data offset register 4
  struct JOFR4 : reg<base + 0x20>
  {
    static constexpr type
    // Data offset for injected channel x (bits: 11-0)
     JOFFSET_MASK = 0x00000FFF
    ,JOFFSET_POS = 0
    ,JOFR4_MASK = 0x00000FFF
    ;
  };
  // ADC watchdog high threshold register
  struct HTR : reg<base + 0x24>
  {
    static constexpr type
    // Analog watchdog high threshold (bits: 11-0)
     HT_MASK = 0x00000FFF
    ,HT_POS = 0
    ,HTR_MASK = 0x00000FFF
    ;
  };
  // ADC watchdog low threshold register
  struct LTR : reg<base + 0x28>
  {
    static constexpr type
    // Analog watchdog low threshold (bits: 11-0)
     LT_MASK = 0x00000FFF
    ,LT_POS = 0
    ,LTR_MASK = 0x00000FFF
    ;
  };
  // ADC regular sequence register 1
  struct SQR1 : reg<base + 0x2C>
  {
    static constexpr type
    // 13 conversion in regular sequence (bits: 4-0)
     SQ13_MASK = 0x0000001F
    ,SQ13_POS = 0
    // 14 conversion in regular sequence (bits: 9-5)
    ,SQ14_MASK = 0x000003E0
    ,SQ14_POS = 5
    // 15 conversion in regular sequence (bits: 14-10)
    ,SQ15_MASK = 0x00007C00
    ,SQ15_POS = 10
    // 16 conversion in regular sequence (bits: 19-15)
    ,SQ16_MASK = 0x000F8000
    ,SQ16_POS = 15
    // Regular channel sequence length (bits: 23-20)
    ,L_MASK = 0x00F00000
    ,L_POS = 20
    ,SQR1_MASK = 0x00FFFFFF
    ;
  };
  // ADC regular sequence register 2
  struct SQR2 : reg<base + 0x30>
  {
    static constexpr type
    // 7 conversion in regular sequence (bits: 4-0)
     SQ7_MASK = 0x0000001F
    ,SQ7_POS = 0
    // 8 conversion in regular sequence (bits: 9-5)
    ,SQ8_MASK = 0x000003E0
    ,SQ8_POS = 5
    // 9 conversion in regular sequence (bits: 14-10)
    ,SQ9_MASK = 0x00007C00
    ,SQ9_POS = 10
    // 10 conversion in regular sequence (bits: 19-15)
    ,SQ10_MASK = 0x000F8000
    ,SQ10_POS = 15
    // 11 conversion in regular sequence (bits: 24-20)
    ,SQ11_MASK = 0x01F00000
    ,SQ11_POS = 20
    // 12 conversion in regular sequence (bits: 29-25)
    ,SQ12_MASK = 0x3E000000
    ,SQ12_POS = 25
    ,SQR2_MASK = 0x3FFFFFFF
    ;
  };
  // ADC regular sequence register 3
  struct SQR3 : reg<base + 0x34>
  {
    static constexpr type
    // 1 conversion in regular sequence (bits: 4-0)
     SQ1_MASK = 0x0000001F
    ,SQ1_POS = 0
    // 2 conversion in regular sequence (bits: 9-5)
    ,SQ2_MASK = 0x000003E0
    ,SQ2_POS = 5
    // 3 conversion in regular sequence (bits: 14-10)
    ,SQ3_MASK = 0x00007C00
    ,SQ3_POS = 10
    // 4 conversion in regular sequence (bits: 19-15)
    ,SQ4_MASK = 0x000F8000
    ,SQ4_POS = 15
    // 5 conversion in regular sequence (bits: 24-20)
    ,SQ5_MASK = 0x01F00000
    ,SQ5_POS = 20
    // 6 conversion in regular sequence (bits: 29-25)
    ,SQ6_MASK = 0x3E000000
    ,SQ6_POS = 25
    ,SQR3_MASK = 0x3FFFFFFF
    ;
  };
  // ADC injected sequence register
  struct JSQR : reg<base + 0x38>
  {
    static constexpr type
    // first conversion in injected sequence (when JL[1:0] = 3) (bits: 4-0)
     JSQ1_MASK = 0x0000001F
    ,JSQ1_POS = 0
    // second conversion in injected sequence (when JL[1:0] = 3) (bits: 9-5)
    ,JSQ2_MASK = 0x000003E0
    ,JSQ2_POS = 5
    // third conversion in injected sequence (when JL[1:0] = 3) (bits: 14-10)
    ,JSQ3_MASK = 0x00007C00
    ,JSQ3_POS = 10
    // fourth conversion in injected sequence (when JL[1:0] = 3) (bits: 19-15)
    ,JSQ4_MASK = 0x000F8000
    ,JSQ4_POS = 15
    // Injected sequence length (bits: 21-20)
    ,JL_MASK = 0x00300000
    ,JL_POS = 20
    ,JSQR_MASK = 0x003FFFFF
    ;
  };
  // ADC injected data register 1
  struct JDR1 : reg<base + 0x3C>
  {
    static constexpr type
    // Injected data (bits: 15-0)
     JDATA_MASK = 0x0000FFFF
    ,JDATA_POS = 0
    ,JDR1_MASK = 0x0000FFFF
    ;
  };
  // ADC injected data register 2
  struct JDR2 : reg<base + 0x40>
  {
    static constexpr type
    // Injected data (bits: 15-0)
     JDATA_MASK = 0x0000FFFF
    ,JDATA_POS = 0
    ,JDR2_MASK = 0x0000FFFF
    ;
  };
  // ADC injected data register 3
  struct JDR3 : reg<base + 0x44>
  {
    static constexpr type
    // Injected data (bits: 15-0)
     JDATA_MASK = 0x0000FFFF
    ,JDATA_POS = 0
    ,JDR3_MASK = 0x0000FFFF
    ;
  };
  // ADC injected data register 4
  struct JDR4 : reg<base + 0x48>
  {
    static constexpr type
    // Injected data (bits: 15-0)
     JDATA_MASK = 0x0000FFFF
    ,JDATA_POS = 0
    ,JDR4_MASK = 0x0000FFFF
    ;
  };
  // ADC regular data register
  struct DR : reg<base + 0x4C>
  {
    static constexpr type
    // Regular data (bits: 15-0)
     DATA_MASK = 0x0000FFFF
    ,DATA_POS = 0
    // ADC2 data (bits: 31-16)
    ,ADC2DATA_MASK = 0xFFFF0000
    ,ADC2DATA_POS = 16
    ,DR_MASK = 0xFFFFFFFF
    ;
  };
}; // struct ADC1

} // namespace lmcu::device

