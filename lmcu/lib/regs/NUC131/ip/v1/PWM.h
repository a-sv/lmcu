/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// PWM Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct PWM
{
  static constexpr auto ip_ver = ip_version::_1;

  // PWM Control Register 0
  struct CTL0 : reg<ip_ver, base + 0x0>
  {
    static constexpr typename CTL0::type
    // Center Re-Load Each bit n controls the corresponding PWM channel n. In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the center point of a period. (bits: 5-0)
     CTRLDN_MASK = 0x0000003F
    ,CTRLDN_POS = 0
    // Immediately Load Enable control Each bit n controls the corresponding PWM channel n. Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid. (bits: 21-16)
    ,IMMLDENN_MASK = 0x003F0000
    ,IMMLDENN_POS = 16
    ,IMMLDENN_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDENN_1 = 0x00010000 // PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT
    // ICE Debug Mode Counter Halt (Write Protect) If counter halt is enabled, PWM all counters will keep current value until exit ICE debug mode. Note: This register is write protected. Refer to REGWRPROT register. (bits: 30)
    ,DBGHALT_MASK = 0x40000000
    ,DBGHALT_POS = 30
    ,DBGHALT_0 = 0x00000000 // ICE debug mode counter halt Disabled
    ,DBGHALT_1 = 0x40000000 // ICE debug mode counter halt Enabled
    // ICE Debug Mode Acknowledge Disable (Write Protect) PWM pin will keep output no matter ICE debug mode acknowledged or not. Note: This register is write protected. Refer to REGWRPROT register. (bits: 31)
    ,DBGTRIOFF_MASK = 0x80000000
    ,DBGTRIOFF_POS = 31
    ,DBGTRIOFF_0 = 0x00000000 // ICE debug mode acknowledgement effects PWM output
    ,DBGTRIOFF_1 = 0x80000000 // ICE debug mode acknowledgement Disabled
    ,CTL0_MASK = 0xC03F003F
    ;
  };
  // PWM Control Register 1
  struct CTL1 : reg<ip_ver, base + 0x4>
  {
    static constexpr typename CTL1::type
    // PWM Counter Behavior Type 0 Each bit n controls corresponding PWM channel n. (bits: 1-0)
     CNTTYPE0_MASK = 0x00000003
    ,CNTTYPE0_POS = 0
    ,CNTTYPE0_0 = 0x00000000 // Up counter type (supports in capture mode)
    ,CNTTYPE0_1 = 0x00000001 // Down count type (supports in capture mode)
    ,CNTTYPE0_2 = 0x00000002 // Up-down counter type
    ,CNTTYPE0_3 = 0x00000003 // Reserved
    // PWM Counter Behavior Type 2 Each bit n controls corresponding PWM channel n. (bits: 5-4)
    ,CNTTYPE2_MASK = 0x00000030
    ,CNTTYPE2_POS = 4
    ,CNTTYPE2_0 = 0x00000000 // Up counter type (supports in capture mode)
    ,CNTTYPE2_1 = 0x00000010 // Down count type (supports in capture mode)
    ,CNTTYPE2_2 = 0x00000020 // Up-down counter type
    ,CNTTYPE2_3 = 0x00000030 // Reserved
    // PWM Counter Behavior Type 4 Each bit n controls corresponding PWM channel n. (bits: 9-8)
    ,CNTTYPE4_MASK = 0x00000300
    ,CNTTYPE4_POS = 8
    ,CNTTYPE4_0 = 0x00000000 // Up counter type (supports in capture mode)
    ,CNTTYPE4_1 = 0x00000100 // Down count type (supports in capture mode)
    ,CNTTYPE4_2 = 0x00000200 // Up-down counter type
    ,CNTTYPE4_3 = 0x00000300 // Reserved
    // PWM Mode Each bit n controls the corresponding PWM channel n. Note: When operating in group function, these bits must all set to the same mode. (bits: 26-24)
    ,PWMMODEN_MASK = 0x07000000
    ,PWMMODEN_POS = 24
    ,PWMMODEN_0 = 0x00000000 // PWM independent mode
    ,PWMMODEN_1 = 0x01000000 // PWM complementary mode
    ,CTL1_MASK = 0x07000333
    ;
  };
  // PWM Clock Source Register
  struct CLKSRC : reg<ip_ver, base + 0x10>
  {
    static constexpr typename CLKSRC::type
    // PWM_CH01 External Clock Source Select (bits: 2-0)
     ECLKSRC0_MASK = 0x00000007
    ,ECLKSRC0_POS = 0
    ,ECLKSRC0_0 = 0x00000000 // PWMx_CLK, x denotes 0 or 1
    ,ECLKSRC0_1 = 0x00000001 // TIMER0 overflow
    ,ECLKSRC0_2 = 0x00000002 // TIMER1 overflow
    ,ECLKSRC0_3 = 0x00000003 // TIMER2 overflow
    ,ECLKSRC0_4 = 0x00000004 // TIMER3 overflow
    // PWM_CH23 External Clock Source Select (bits: 10-8)
    ,ECLKSRC2_MASK = 0x00000700
    ,ECLKSRC2_POS = 8
    ,ECLKSRC2_0 = 0x00000000 // PWMx_CLK, x denotes 0 or 1
    ,ECLKSRC2_1 = 0x00000100 // TIMER0 overflow
    ,ECLKSRC2_2 = 0x00000200 // TIMER1 overflow
    ,ECLKSRC2_3 = 0x00000300 // TIMER2 overflow
    ,ECLKSRC2_4 = 0x00000400 // TIMER3 overflow
    // PWM_CH45 External Clock Source Select (bits: 18-16)
    ,ECLKSRC4_MASK = 0x00070000
    ,ECLKSRC4_POS = 16
    ,ECLKSRC4_0 = 0x00000000 // PWMx_CLK, x denotes 0 or 1
    ,ECLKSRC4_1 = 0x00010000 // TIMER0 overflow
    ,ECLKSRC4_2 = 0x00020000 // TIMER1 overflow
    ,ECLKSRC4_3 = 0x00030000 // TIMER2 overflow
    ,ECLKSRC4_4 = 0x00040000 // TIMER3 overflow
    ,CLKSRC_MASK = 0x00070707
    ;
  };
  // PWM Clock Pre-scale Register 0_1
  struct CLKPSC0_1 : reg<ip_ver, base + 0x14>
  {
    static constexpr typename CLKPSC0_1::type
    // PWM Counter Clock Pre-Scale The clock of PWM counter is decided by clock prescaler. Each PWM pair share one PWM counter clock prescaler. The clock of PWM counter is divided by (CLKPSC+ 1). (bits: 11-0)
     CLKPSC_MASK = 0x00000FFF
    ,CLKPSC_POS = 0
    ,CLKPSC0_1_MASK = 0x00000FFF
    ;
  };
  // PWM Clock Pre-scale Register 2_3
  using CLKPSC2_3 = reg<ip_ver, base + 0x18>;
  // PWM Clock Pre-scale Register 4_5
  using CLKPSC4_5 = reg<ip_ver, base + 0x1C>;
  // PWM Counter Enable Register
  struct CNTEN : reg<ip_ver, base + 0x20>
  {
    static constexpr typename CNTEN::type
    // PWM Counter Enable 0 (bits: 0)
     CNTEN0_MASK = 0x00000001
    ,CNTEN0_POS = 0
    ,CNTEN0_0 = 0x00000000 // PWM Counter and clock prescaler Stop Running
    ,CNTEN0_1 = 0x00000001 // PWM Counter and clock prescaler Start Running
    // PWM Counter Enable 2 (bits: 2)
    ,CNTEN2_MASK = 0x00000004
    ,CNTEN2_POS = 2
    ,CNTEN2_0 = 0x00000000 // PWM Counter and clock prescaler Stop Running
    ,CNTEN2_1 = 0x00000004 // PWM Counter and clock prescaler Start Running
    // PWM Counter Enable 4 (bits: 4)
    ,CNTEN4_MASK = 0x00000010
    ,CNTEN4_POS = 4
    ,CNTEN4_0 = 0x00000000 // PWM Counter and clock prescaler Stop Running
    ,CNTEN4_1 = 0x00000010 // PWM Counter and clock prescaler Start Running
    ,CNTEN_MASK = 0x00000015
    ;
  };
  // PWM Clear Counter Register
  struct CNTCLR : reg<ip_ver, base + 0x24>
  {
    static constexpr typename CNTCLR::type
    // Clear PWM Counter Control Bit 0 It is automatically cleared by hardware. (bits: 0)
     CNTCLR0_MASK = 0x00000001
    ,CNTCLR0_POS = 0
    ,CNTCLR0_0 = 0x00000000 // No effect
    ,CNTCLR0_1 = 0x00000001 // Clear 16-bit PWM counter to 0000H
    // Clear PWM Counter Control Bit 2 It is automatically cleared by hardware. (bits: 2)
    ,CNTCLR2_MASK = 0x00000004
    ,CNTCLR2_POS = 2
    ,CNTCLR2_0 = 0x00000000 // No effect
    ,CNTCLR2_1 = 0x00000004 // Clear 16-bit PWM counter to 0000H
    // Clear PWM Counter Control Bit 4 It is automatically cleared by hardware. (bits: 4)
    ,CNTCLR4_MASK = 0x00000010
    ,CNTCLR4_POS = 4
    ,CNTCLR4_0 = 0x00000000 // No effect
    ,CNTCLR4_1 = 0x00000010 // Clear 16-bit PWM counter to 0000H
    ,CNTCLR_MASK = 0x00000015
    ;
  };
  // PWM Period Register 0
  struct PERIOD0 : reg<ip_ver, base + 0x30>
  {
    static constexpr typename PERIOD0::type
    // PWM Period Register Up-Count mode: In this mode, PWM counter counts from 0 to PERIOD, and restarts from 0. Down-Count mode: In this mode, PWM counter counts from PERIOD to 0, and restarts from PERIOD. (bits: 15-0)
     PERIOD_MASK = 0x0000FFFF
    ,PERIOD_POS = 0
    ,PERIOD0_MASK = 0x0000FFFF
    ;
  };
  // PWM Period Register 2
  using PERIOD2 = reg<ip_ver, base + 0x38>;
  // PWM Period Register 4
  using PERIOD4 = reg<ip_ver, base + 0x40>;
  // PWM Comparator Register 0
  struct CMPDAT0 : reg<ip_ver, base + 0x50>
  {
    static constexpr typename CMPDAT0::type
    // PWM Comparator Register CMP use to compare with CNT to generate PWM waveform, interrupt and trigger ADC. In independent mode, PWM_CMPDAT0~5 denote as 6 independent PWM_CH0~5 compared point. In complementary mode, PWM_CMPDAT0, 2, 4 denote as first compared point, and PWM_CMPDAT1, 3, 5 denote as second compared point for the corresponding 3 complementary pairs PWM_CH0 and PWM_CH1, PWM_CH2 and PWM_CH3, PWM_CH4 and PWM_CH5. (bits: 15-0)
     CMP_MASK = 0x0000FFFF
    ,CMP_POS = 0
    ,CMPDAT0_MASK = 0x0000FFFF
    ;
  };
  // PWM Comparator Register 1
  using CMPDAT1 = reg<ip_ver, base + 0x54>;
  // PWM Comparator Register 2
  using CMPDAT2 = reg<ip_ver, base + 0x58>;
  // PWM Comparator Register 3
  using CMPDAT3 = reg<ip_ver, base + 0x5C>;
  // PWM Comparator Register 4
  using CMPDAT4 = reg<ip_ver, base + 0x60>;
  // PWM Comparator Register 5
  using CMPDAT5 = reg<ip_ver, base + 0x64>;
  // PWM Dead-time Control Register 0_1
  struct DTCTL0_1 : reg<ip_ver, base + 0x70>
  {
    static constexpr typename DTCTL0_1::type
    // Dead-Time Counter (Write Protect) The dead-time can be calculated from the following formula: Note: This register is write protected. Refer to REGWRPROT register. (bits: 11-0)
     DTCNT_MASK = 0x00000FFF
    ,DTCNT_POS = 0
    // Enable Dead-Time Insertion For PWM Pair (PWM_CH0, PWM_CH1) (PWM_CH2, PWM_CH3) (PWM_CH4, PWM_CH5) (Write Protect) Dead-time insertion is only active when this pair of complementary PWM is enabled. If dead- time insertion is inactive, the outputs of pin pair are complementary without any delay. Note: This register is write protected. Refer to REGWRPROT register. (bits: 16)
    ,DTEN_MASK = 0x00010000
    ,DTEN_POS = 16
    ,DTEN_0 = 0x00000000 // Dead-time insertion Disabled on the pin pair
    ,DTEN_1 = 0x00010000 // Dead-time insertion Enabled on the pin pair
    // Dead-Time Clock Select (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 24)
    ,DTCKSEL_MASK = 0x01000000
    ,DTCKSEL_POS = 24
    ,DTCKSEL_0 = 0x00000000 // Dead-time clock source from PWM_CLK
    ,DTCKSEL_1 = 0x01000000 // Dead-time clock source from prescaler output
    ,DTCTL0_1_MASK = 0x01010FFF
    ;
  };
  // PWM Dead-time Control Register 2_3
  using DTCTL2_3 = reg<ip_ver, base + 0x74>;
  // PWM Dead-time Control Register 4_5
  using DTCTL4_5 = reg<ip_ver, base + 0x78>;
  // PWM Counter Register 0
  struct CNT0 : reg<ip_ver, base + 0x90>
  {
    static constexpr typename CNT0::type
    // PWM Data Register (Read Only) User can monitor CNT to know the current value in 16-bit period counter. (bits: 15-0)
     CNT_MASK = 0x0000FFFF
    ,CNT_POS = 0
    // PWM Direction Indicator Flag (Read Only) (bits: 16)
    ,DIRF_MASK = 0x00010000
    ,DIRF_POS = 16
    ,DIRF_0 = 0x00000000 // Counter is Down count
    ,DIRF_1 = 0x00010000 // Counter is UP count
    ,CNT0_MASK = 0x0001FFFF
    ;
  };
  // PWM Counter Register 2
  using CNT2 = reg<ip_ver, base + 0x98>;
  // PWM Counter Register 4
  using CNT4 = reg<ip_ver, base + 0xA0>;
  // PWM Generation Register 0
  struct WGCTL0 : reg<ip_ver, base + 0xB0>
  {
    static constexpr typename WGCTL0::type
    // PWM Zero Point Control Each bit n controls the corresponding PWM channel n. PWM can control output level when PWM counter count to zero. (bits: 11-0)
     ZPCTLN_MASK = 0x00000FFF
    ,ZPCTLN_POS = 0
    ,ZPCTLN_0 = 0x00000000 // Do nothing
    ,ZPCTLN_1 = 0x00000001 // PWM zero point output Low
    ,ZPCTLN_10 = 0x0000000A // PWM zero point output High
    ,ZPCTLN_11 = 0x0000000B // PWM zero point output Toggle
    // PWM Period (Center) Point Control Each bit n controls the corresponding PWM channel n. PWM can control output level when PWM counter count to (PERIODn+1). Note: This bit is center point control when PWM counter operating in up-down counter type. (bits: 27-16)
    ,PRDPCTLN_MASK = 0x0FFF0000
    ,PRDPCTLN_POS = 16
    ,PRDPCTLN_0 = 0x00000000 // Do nothing
    ,PRDPCTLN_1 = 0x00010000 // PWM period (center) point output Low
    ,PRDPCTLN_10 = 0x000A0000 // PWM period (center) point output High
    ,PRDPCTLN_11 = 0x000B0000 // PWM period (center) point output Toggle
    ,WGCTL0_MASK = 0x0FFF0FFF
    ;
  };
  // PWM Generation Register 1
  struct WGCTL1 : reg<ip_ver, base + 0xB4>
  {
    static constexpr typename WGCTL1::type
    // PWM Compare Up Point Control Each bit n controls the corresponding PWM channel n. PWM can control output level when PWM counter up count to CMPDAT. Note: In complementary mode, CMPUCTL1, 3, 5 use as another CMPUCTL for channel 0, 2, 4. (bits: 11-0)
     CMPUCTLN_MASK = 0x00000FFF
    ,CMPUCTLN_POS = 0
    ,CMPUCTLN_0 = 0x00000000 // Do nothing
    ,CMPUCTLN_1 = 0x00000001 // PWM compare up point output Low
    ,CMPUCTLN_10 = 0x0000000A // PWM compare up point output High
    ,CMPUCTLN_11 = 0x0000000B // PWM compare up point output Toggle
    // PWM Compare Down Point Control Each bit n controls the corresponding PWM channel n. PWM can control output level when PWM counter down count to CMPDAT. Note: In complementary mode, CMPDCTL1, 3, 5 use as another CMPDCTL for channel 0, 2, 4. (bits: 27-16)
    ,CMPDCTLN_MASK = 0x0FFF0000
    ,CMPDCTLN_POS = 16
    ,CMPDCTLN_0 = 0x00000000 // Do nothing
    ,CMPDCTLN_1 = 0x00010000 // PWM compare down point output Low
    ,CMPDCTLN_10 = 0x000A0000 // PWM compare down point output High
    ,CMPDCTLN_11 = 0x000B0000 // PWM compare down point output Toggle
    ,WGCTL1_MASK = 0x0FFF0FFF
    ;
  };
  // PWM Mask Enable Register
  struct MSKEN : reg<ip_ver, base + 0xB8>
  {
    static constexpr typename MSKEN::type
    // PWM Mask Enable Control Each bit n controls the corresponding PWM channel n. The PWM output signal will be masked when this bit is enabled. The corresponding PWM channel n will output MSKDATn (PWM_MSK[5:0]) data. (bits: 5-0)
     MSKENN_MASK = 0x0000003F
    ,MSKENN_POS = 0
    ,MSKENN_0 = 0x00000000 // PWM output signal is non-masked
    ,MSKENN_1 = 0x00000001 // PWM output signal is masked and output MSKDATn data
    ,MSKEN_MASK = 0x0000003F
    ;
  };
  // PWM Mask Data Register
  struct MSK : reg<ip_ver, base + 0xBC>
  {
    static constexpr typename MSK::type
    // PWM Mask Data Bit This data bit control the state of PWMn output pin, if corresponding mask function is enabled. Each bit n controls the corresponding PWM channel n. (bits: 5-0)
     MSKDATN_MASK = 0x0000003F
    ,MSKDATN_POS = 0
    ,MSKDATN_0 = 0x00000000 // Output logic low to PWMn
    ,MSKDATN_1 = 0x00000001 // Output logic high to PWMn
    ,MSK_MASK = 0x0000003F
    ;
  };
  // PWM Brake Noise Filter Register
  struct BNF : reg<ip_ver, base + 0xC0>
  {
    static constexpr typename BNF::type
    // PWM Brake 0 Noise Filter Enable Control (bits: 0)
     BRK0FEN_MASK = 0x00000001
    ,BRK0FEN_POS = 0
    ,BRK0FEN_0 = 0x00000000 // Noise filter of PWM Brake 0 Disabled
    ,BRK0FEN_1 = 0x00000001 // Noise filter of PWM Brake 0 Enabled
    // Brake 0 Edge Detector Filter Clock Selection (bits: 3-1)
    ,BRK0FCS_MASK = 0x0000000E
    ,BRK0FCS_POS = 1
    ,BRK0FCS_0 = 0x00000000 // Filter clock is HCLK
    ,BRK0FCS_1 = 0x00000002 // Filter clock is HCLK/2
    ,BRK0FCS_2 = 0x00000004 // Filter clock is HCLK/4
    ,BRK0FCS_3 = 0x00000006 // Filter clock is HCLK/8
    ,BRK0FCS_4 = 0x00000008 // Filter clock is HCLK/16
    ,BRK0FCS_5 = 0x0000000A // Filter clock is HCLK/32
    ,BRK0FCS_6 = 0x0000000C // Filter clock is HCLK/64
    ,BRK0FCS_7 = 0x0000000E // Filter clock is HCLK/128
    // Brake 0 Edge Detector Filter Count The register bits control the Brake0 filter counter to count from 0 to BRK1FCNT. (bits: 6-4)
    ,BRK0FCNT_MASK = 0x00000070
    ,BRK0FCNT_POS = 4
    // Brake 0 Pin Inverse (bits: 7)
    ,BRK0PINV_MASK = 0x00000080
    ,BRK0PINV_POS = 7
    ,BRK0PINV_0 = 0x00000000 // The state of pin PWMx_BRAKE0 is passed to the negative edge detector
    ,BRK0PINV_1 = 0x00000080 // The inversed state of pin PWMx_BRAKE10 is passed to the negative edge detector
    // PWM Brake 1 Noise Filter Enable Control (bits: 8)
    ,BRK1FEN_MASK = 0x00000100
    ,BRK1FEN_POS = 8
    ,BRK1FEN_0 = 0x00000000 // Noise filter of PWM Brake 1 Disabled
    ,BRK1FEN_1 = 0x00000100 // Noise filter of PWM Brake 1 Enabled
    // Brake 1 Edge Detector Filter Clock Selection (bits: 11-9)
    ,BRK1FCS_MASK = 0x00000E00
    ,BRK1FCS_POS = 9
    ,BRK1FCS_0 = 0x00000000 // Filter clock = HCLK
    ,BRK1FCS_1 = 0x00000200 // Filter clock = HCLK/2
    ,BRK1FCS_2 = 0x00000400 // Filter clock = HCLK/4
    ,BRK1FCS_3 = 0x00000600 // Filter clock = HCLK/8
    ,BRK1FCS_4 = 0x00000800 // Filter clock = HCLK/16
    ,BRK1FCS_5 = 0x00000A00 // Filter clock = HCLK/32
    ,BRK1FCS_6 = 0x00000C00 // Filter clock = HCLK/64
    ,BRK1FCS_7 = 0x00000E00 // Filter clock = HCLK/128
    // Brake 1 Edge Detector Filter Count The register bits control the Brake1 filter counter to count from 0 to BRK1FCNT. (bits: 14-12)
    ,BRK1FCNT_MASK = 0x00007000
    ,BRK1FCNT_POS = 12
    // Brake 1 Pin Inverse (bits: 15)
    ,BRK1PINV_MASK = 0x00008000
    ,BRK1PINV_POS = 15
    ,BRK1PINV_0 = 0x00000000 // The state of pin PWMx_BRAKE1 is passed to the negative edge detector
    ,BRK1PINV_1 = 0x00008000 // The inversed state of pin PWMx_BRAKE1 is passed to the negative edge detector
    // Brake 0 Pin Source Select For PWM0 setting: (bits: 16)
    ,BK0SRC_MASK = 0x00010000
    ,BK0SRC_POS = 16
    ,BK0SRC_0 = 0x00000000 // Brake 0 pin source come from PWM0_BRAKE0. Brake 0 pin source come from PWM1_BRAKE0
    ,BK0SRC_1 = 0x00010000 // Brake 0 pin source come from PWM1_BRAKE0. Brake 0 pin source come from PWM0_BRAKE0
    // Brake 1 Pin Source Select For PWM0 setting: (bits: 24)
    ,BK1SRC_MASK = 0x01000000
    ,BK1SRC_POS = 24
    ,BK1SRC_0 = 0x00000000 // Brake 1 pin source come from PWM0_BRAKE1. Brake 1 pin source come from PWM1_BRAKE1
    ,BK1SRC_1 = 0x01000000 // Brake 1 pin source come from PWM1_BRAKE1. Brake 1 pin source come from PWM0_BRAKE1
    ,BNF_MASK = 0x0101FFFF
    ;
  };
  // PWM System Fail Brake Control Register
  struct FAILBRK : reg<ip_ver, base + 0xC4>
  {
    static constexpr typename FAILBRK::type
    // Clock Security System Detection Trigger PWM Brake Function 0 Enable Control (bits: 0)
     CSSBRKEN_MASK = 0x00000001
    ,CSSBRKEN_POS = 0
    ,CSSBRKEN_0 = 0x00000000 // Brake Function triggered by CSS detection Disabled
    ,CSSBRKEN_1 = 0x00000001 // Brake Function triggered by CSS detection Enabled
    // Brown-Out Detection Trigger PWM Brake Function 0 Enable Control (bits: 1)
    ,BODBRKEN_MASK = 0x00000002
    ,BODBRKEN_POS = 1
    ,BODBRKEN_0 = 0x00000000 // Brake Function triggered by BOD Disabled
    ,BODBRKEN_1 = 0x00000002 // Brake Function triggered by BOD Enabled
    // Core Lockup Detection Trigger PWM Brake Function 0 Enable Control (bits: 3)
    ,CORBRKEN_MASK = 0x00000008
    ,CORBRKEN_POS = 3
    ,CORBRKEN_0 = 0x00000000 // Brake Function triggered by Core lockup detection Disabled
    ,CORBRKEN_1 = 0x00000008 // Brake Function triggered by Core lockup detection Enabled
    ,FAILBRK_MASK = 0x0000000B
    ;
  };
  // PWM Brake Edge Detect Control Register 0_1
  struct BRKCTL0_1 : reg<ip_ver, base + 0xC8>
  {
    static constexpr typename BRKCTL0_1::type
    // Enable PWMx_BRAKE0 Pin As Edge-Detect Brake Source (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 4)
     BRKP0EEN_MASK = 0x00000010
    ,BRKP0EEN_POS = 4
    ,BRKP0EEN_0 = 0x00000000 // BKP0 pin as edge-detect brake source Disabled
    ,BRKP0EEN_1 = 0x00000010 // BKP0 pin as edge-detect brake source Enabled
    // Enable PWMx_BRAKE1 Pin As Edge-Detect Brake Source (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 5)
    ,BRKP1EEN_MASK = 0x00000020
    ,BRKP1EEN_POS = 5
    ,BRKP1EEN_0 = 0x00000000 // BKP1 pin as edge-detect brake source Disabled
    ,BRKP1EEN_1 = 0x00000020 // BKP1 pin as edge-detect brake source Enabled
    // Enable System Fail As Edge-Detect Brake Source (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 7)
    ,SYSEEN_MASK = 0x00000080
    ,SYSEEN_POS = 7
    ,SYSEEN_0 = 0x00000000 // System Fail condition as edge-detect brake source Disabled
    ,SYSEEN_1 = 0x00000080 // System Fail condition as edge-detect brake source Enabled
    // Enable BKP0 Pin As Level-Detect Brake Source (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 12)
    ,BRKP0LEN_MASK = 0x00001000
    ,BRKP0LEN_POS = 12
    ,BRKP0LEN_0 = 0x00000000 // PWMx_BRAKE0 pin as level-detect brake source Disabled
    ,BRKP0LEN_1 = 0x00001000 // PWMx_BRAKE0 pin as level-detect brake source Enabled
    // Enable BKP1 Pin As Level-Detect Brake Source (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 13)
    ,BRKP1LEN_MASK = 0x00002000
    ,BRKP1LEN_POS = 13
    ,BRKP1LEN_0 = 0x00000000 // PWMx_BRAKE1 pin as level-detect brake source Disabled
    ,BRKP1LEN_1 = 0x00002000 // PWMx_BRAKE1 pin as level-detect brake source Enabled
    // Enable System Fail As Level-Detect Brake Source (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 15)
    ,SYSLEN_MASK = 0x00008000
    ,SYSLEN_POS = 15
    ,SYSLEN_0 = 0x00000000 // System Fail condition as level-detect brake source Disabled
    ,SYSLEN_1 = 0x00008000 // System Fail condition as level-detect brake source Enabled
    // PWM Brake Action Select For Even Channel (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 17-16)
    ,BRKAEVEN_MASK = 0x00030000
    ,BRKAEVEN_POS = 16
    ,BRKAEVEN_0 = 0x00000000 // PWM even channel level-detect brake function not affect channel output
    ,BRKAEVEN_1 = 0x00010000 // PWM even channel output tri-state when level-detect brake happened
    ,BRKAEVEN_2 = 0x00020000 // PWM even channel output low level when level-detect brake happened
    ,BRKAEVEN_3 = 0x00030000 // PWM even channel output high level when level-detect brake happened
    // PWM Brake Action Select For Odd Channel (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 19-18)
    ,BRKAODD_MASK = 0x000C0000
    ,BRKAODD_POS = 18
    ,BRKAODD_0 = 0x00000000 // PWM odd channel level-detect brake function not affect channel output
    ,BRKAODD_1 = 0x00040000 // PWM odd channel output tri-state when level-detect brake happened
    ,BRKAODD_2 = 0x00080000 // PWM odd channel output low level when level-detect brake happened
    ,BRKAODD_3 = 0x000C0000 // PWM odd channel output high level when level-detect brake happened
    ,BRKCTL0_1_MASK = 0x000FB0B0
    ;
  };
  // PWM Brake Edge Detect Control Register 2_3
  using BRKCTL2_3 = reg<ip_ver, base + 0xCC>;
  // PWM Brake Edge Detect Control Register 4_5
  using BRKCTL4_5 = reg<ip_ver, base + 0xD0>;
  // PWM Pin Polar Inverse Register
  struct POLCTL : reg<ip_ver, base + 0xD4>
  {
    static constexpr typename POLCTL::type
    // PWM PIN Polar Inverse Control The register controls polarity state of PWM output. Each bit n controls the corresponding PWM channel n. (bits: 5-0)
     PINVN_MASK = 0x0000003F
    ,PINVN_POS = 0
    ,PINVN_0 = 0x00000000 // PWM output polar inverse Disabled
    ,PINVN_1 = 0x00000001 // PWM output polar inverse Enabled
    ,POLCTL_MASK = 0x0000003F
    ;
  };
  // PWM Output Enable Register
  struct POEN : reg<ip_ver, base + 0xD8>
  {
    static constexpr typename POEN::type
    // PWM Pin Output Enable Control Each bit n controls the corresponding PWM channel n. (bits: 5-0)
     POENN_MASK = 0x0000003F
    ,POENN_POS = 0
    ,POENN_0 = 0x00000000 // PWM pin at tri-state
    ,POENN_1 = 0x00000001 // PWM pin in output mode
    ,POEN_MASK = 0x0000003F
    ;
  };
  // PWM Software Brake Control Register
  struct SWBRK : reg<ip_ver, base + 0xDC>
  {
    static constexpr typename SWBRK::type
    // PWM Edge Brake Software Trigger (Write Only) (Write Protect) Each bit n controls the corresponding PWM pair n. Write 1 to this bit will trigger Edge brake, and set BRKEIFn to 1 in PWM_INTSTS1 register. Note: This register is write protected. Refer to REGWRPROT register. (bits: 2-0)
     BRKETRGN_MASK = 0x00000007
    ,BRKETRGN_POS = 0
    // PWM Level Brake Software Trigger (Write Only) (Write Protect) Each bit n controls the corresponding PWM pair n. Write 1 to this bit will trigger level brake, and set BRKLIFn to 1 in PWM_INTSTS1 register. Note: This register is write protected. Refer to REGWRPROT register. (bits: 10-8)
    ,BRKLTRGN_MASK = 0x00000700
    ,BRKLTRGN_POS = 8
    ,SWBRK_MASK = 0x00000707
    ;
  };
  // PWM Interrupt Enable Register 0
  struct INTEN0 : reg<ip_ver, base + 0xE0>
  {
    static constexpr typename INTEN0::type
    // PWM Zero Point Interrupt Enable 0 Note: Odd channels will read always 0 at complementary mode. (bits: 0)
     ZIEN0_MASK = 0x00000001
    ,ZIEN0_POS = 0
    ,ZIEN0_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN0_1 = 0x00000001 // Zero point interrupt Enabled
    // PWM Zero Point Interrupt Enable 2 Note: Odd channels will read always 0 at complementary mode. (bits: 2)
    ,ZIEN2_MASK = 0x00000004
    ,ZIEN2_POS = 2
    ,ZIEN2_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN2_1 = 0x00000004 // Zero point interrupt Enabled
    // PWM Zero Point Interrupt Enable 4 Note: Odd channels will read always 0 at complementary mode. (bits: 4)
    ,ZIEN4_MASK = 0x00000010
    ,ZIEN4_POS = 4
    ,ZIEN4_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN4_1 = 0x00000010 // Zero point interrupt Enabled
    // PWM Period Point Interrupt Enable 0 Note: When up-down counter type period point means center point. (bits: 8)
    ,PIEN0_MASK = 0x00000100
    ,PIEN0_POS = 8
    ,PIEN0_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN0_1 = 0x00000100 // Period point interrupt Enabled
    // PWM Period Point Interrupt Enable 2 Note: When up-down counter type period point means center point. (bits: 10)
    ,PIEN2_MASK = 0x00000400
    ,PIEN2_POS = 10
    ,PIEN2_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN2_1 = 0x00000400 // Period point interrupt Enabled
    // PWM Period Point Interrupt Enable 4 Note: When up-down counter type period point means center point. (bits: 12)
    ,PIEN4_MASK = 0x00001000
    ,PIEN4_POS = 12
    ,PIEN4_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN4_1 = 0x00001000 // Period point interrupt Enabled
    // PWM Compare Up Count Interrupt Enable Control Each bit n controls the corresponding PWM channel n. Note: In complementary mode, CMPUIEN1, 3, 5 use as another CMPUIEN for channel 0, 2, 4. (bits: 21-16)
    ,CMPUIENN_MASK = 0x003F0000
    ,CMPUIENN_POS = 16
    ,CMPUIENN_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIENN_1 = 0x00010000 // Compare up count interrupt Enabled
    // PWM Compare Down Count Interrupt Enable Control Each bit n controls the corresponding PWM channel n. Note: In complementary mode, CMPDIEN1, 3, 5 use as another CMPDIEN for channel 0, 2, 4. (bits: 29-24)
    ,CMPDIENN_MASK = 0x3F000000
    ,CMPDIENN_POS = 24
    ,CMPDIENN_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIENN_1 = 0x01000000 // Compare down count interrupt Enabled
    ,INTEN0_MASK = 0x3F3F1515
    ;
  };
  // PWM Interrupt Enable Register 1
  struct INTEN1 : reg<ip_ver, base + 0xE4>
  {
    static constexpr typename INTEN1::type
    // PWM Edge-Detect Brake Interrupt Enable For Channel0/1 (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 0)
     BRKEIEN0_1_MASK = 0x00000001
    ,BRKEIEN0_1_POS = 0
    ,BRKEIEN0_1_0 = 0x00000000 // Edge-detect Brake interrupt for channel0/1 Disabled
    ,BRKEIEN0_1_1 = 0x00000001 // Edge-detect Brake interrupt for channel0/1 Enabled
    // PWM Edge-Detect Brake Interrupt Enable For Channel2/3 (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 1)
    ,BRKEIEN2_3_MASK = 0x00000002
    ,BRKEIEN2_3_POS = 1
    ,BRKEIEN2_3_0 = 0x00000000 // Edge-detect Brake interrupt for channel2/3 Disabled
    ,BRKEIEN2_3_1 = 0x00000002 // Edge-detect Brake interrupt for channel2/3 Enabled
    // PWM Edge-Detect Brake Interrupt Enable For Channel4/5 (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 2)
    ,BRKEIEN4_5_MASK = 0x00000004
    ,BRKEIEN4_5_POS = 2
    ,BRKEIEN4_5_0 = 0x00000000 // Edge-detect Brake interrupt for channel4/5 Disabled
    ,BRKEIEN4_5_1 = 0x00000004 // Edge-detect Brake interrupt for channel4/5 Enabled
    // PWM Level-Detect Brake Interrupt Enable For Channel0/1 (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 8)
    ,BRKLIEN0_1_MASK = 0x00000100
    ,BRKLIEN0_1_POS = 8
    ,BRKLIEN0_1_0 = 0x00000000 // Level-detect Brake interrupt for channel0/1 Disabled
    ,BRKLIEN0_1_1 = 0x00000100 // Level-detect Brake interrupt for channel0/1 Enabled
    // PWM Level-Detect Brake Interrupt Enable For Channel2/3 (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 9)
    ,BRKLIEN2_3_MASK = 0x00000200
    ,BRKLIEN2_3_POS = 9
    ,BRKLIEN2_3_0 = 0x00000000 // Level-detect Brake interrupt for channel2/3 Disabled
    ,BRKLIEN2_3_1 = 0x00000200 // Level-detect Brake interrupt for channel2/3 Enabled
    // PWM Level-Detect Brake Interrupt Enable For Channel4/5 (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 10)
    ,BRKLIEN4_5_MASK = 0x00000400
    ,BRKLIEN4_5_POS = 10
    ,BRKLIEN4_5_0 = 0x00000000 // Level-detect Brake interrupt for channel4/5 Disabled
    ,BRKLIEN4_5_1 = 0x00000400 // Level-detect Brake interrupt for channel4/5 Enabled
    ,INTEN1_MASK = 0x00000707
    ;
  };
  // PWM Interrupt Flag Register 0
  struct INTSTS0 : reg<ip_ver, base + 0xE8>
  {
    static constexpr typename INTSTS0::type
    // PWM Zero Point Interrupt Flag 0 This bit is set by hardware when PWM_CH0 counter reaches zero, software can write 1 to clear this bit to zero. (bits: 0)
     ZIF0_MASK = 0x00000001
    ,ZIF0_POS = 0
    ,ZIF0 = 0x00000001
    // PWM Zero Point Interrupt Flag 2 This bit is set by hardware when PWM_CH2 counter reaches zero, software can write 1 to clear this bit to zero. (bits: 2)
    ,ZIF2_MASK = 0x00000004
    ,ZIF2_POS = 2
    ,ZIF2 = 0x00000004
    // PWM Zero Point Interrupt Flag 4 This bit is set by hardware when PWM_CH4 counter reaches zero, software can write 1 to clear this bit to zero. (bits: 4)
    ,ZIF4_MASK = 0x00000010
    ,ZIF4_POS = 4
    ,ZIF4 = 0x00000010
    // PWM Period Point Interrupt Flag 0 This bit is set by hardware when PWM_CH0 counter reaches PWM_PERIOD0, software can write 1 to clear this bit to zero. (bits: 8)
    ,PIF0_MASK = 0x00000100
    ,PIF0_POS = 8
    ,PIF0 = 0x00000100
    // PWM Period Point Interrupt Flag 2 This bit is set by hardware when PWM_CH2 counter reaches PWM_PERIOD2, software can write 1 to clear this bit to zero. (bits: 10)
    ,PIF2_MASK = 0x00000400
    ,PIF2_POS = 10
    ,PIF2 = 0x00000400
    // PWM Period Point Interrupt Flag 4 This bit is set by hardware when PWM_CH4 counter reaches PWM_PERIOD4, software can write 1 to clear this bit to zero. (bits: 12)
    ,PIF4_MASK = 0x00001000
    ,PIF4_POS = 12
    ,PIF4 = 0x00001000
    // PWM Compare Up Count Interrupt Flag Flag is set by hardware when PWM counter up count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it. Each bit n controls the corresponding PWM channel n. Note1: If CMPDAT equal to PERIOD, this flag is not working in up counter type selection. Note2: In complementary mode, CMPUIF1, 3, 5 use as another CMPUIF for channel 0, 2, 4. (bits: 21-16)
    ,CMPUIFN_MASK = 0x003F0000
    ,CMPUIFN_POS = 16
    // PWM Compare Down Count Interrupt Flag Each bit n controls the corresponding PWM channel n. Flag is set by hardware when PWM counter down count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it. Note1: If CMPDAT equal to PERIOD, this flag is not working in down counter type selection. Note2: In complementary mode, CMPDIF1, 3, 5 use as another CMPDIF for channel 0, 2, 4. (bits: 29-24)
    ,CMPDIFN_MASK = 0x3F000000
    ,CMPDIFN_POS = 24
    ,INTSTS0_MASK = 0x3F3F1515
    ;
  };
  // PWM Interrupt Flag Register 1
  struct INTSTS1 : reg<ip_ver, base + 0xEC>
  {
    static constexpr typename INTSTS1::type
    // PWM Channel0 Edge-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 0)
     BRKEIF0_MASK = 0x00000001
    ,BRKEIF0_POS = 0
    ,BRKEIF0_0 = 0x00000000 // PWM channel0 edge-detect brake event do not happened
    ,BRKEIF0_1 = 0x00000001 // When PWM channel0 edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel1 Edge-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 1)
    ,BRKEIF1_MASK = 0x00000002
    ,BRKEIF1_POS = 1
    ,BRKEIF1_0 = 0x00000000 // PWM channel1 edge-detect brake event do not happened
    ,BRKEIF1_1 = 0x00000002 // When PWM channel1 edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel2 Edge-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 2)
    ,BRKEIF2_MASK = 0x00000004
    ,BRKEIF2_POS = 2
    ,BRKEIF2_0 = 0x00000000 // PWM channel2 edge-detect brake event do not happened
    ,BRKEIF2_1 = 0x00000004 // When PWM channel2 edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel3 Edge-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 3)
    ,BRKEIF3_MASK = 0x00000008
    ,BRKEIF3_POS = 3
    ,BRKEIF3_0 = 0x00000000 // PWM channel3 edge-detect brake event do not happened
    ,BRKEIF3_1 = 0x00000008 // When PWM channel3 edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel4 Edge-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 4)
    ,BRKEIF4_MASK = 0x00000010
    ,BRKEIF4_POS = 4
    ,BRKEIF4_0 = 0x00000000 // PWM channel4 edge-detect brake event do not happened
    ,BRKEIF4_1 = 0x00000010 // When PWM channel4 edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel5 Edge-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 5)
    ,BRKEIF5_MASK = 0x00000020
    ,BRKEIF5_POS = 5
    ,BRKEIF5_0 = 0x00000000 // PWM channel5 edge-detect brake event do not happened
    ,BRKEIF5_1 = 0x00000020 // When PWM channel5 edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel0 Level-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 8)
    ,BRKLIF0_MASK = 0x00000100
    ,BRKLIF0_POS = 8
    ,BRKLIF0_0 = 0x00000000 // PWM channel0 level-detect brake event do not happened
    ,BRKLIF0_1 = 0x00000100 // When PWM channel0 level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel1 Level-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 9)
    ,BRKLIF1_MASK = 0x00000200
    ,BRKLIF1_POS = 9
    ,BRKLIF1_0 = 0x00000000 // PWM channel1 level-detect brake event do not happened
    ,BRKLIF1_1 = 0x00000200 // When PWM channel1 level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel2 Level-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 10)
    ,BRKLIF2_MASK = 0x00000400
    ,BRKLIF2_POS = 10
    ,BRKLIF2_0 = 0x00000000 // PWM channel2 level-detect brake event do not happened
    ,BRKLIF2_1 = 0x00000400 // When PWM channel2 level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel3 Level-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 11)
    ,BRKLIF3_MASK = 0x00000800
    ,BRKLIF3_POS = 11
    ,BRKLIF3_0 = 0x00000000 // PWM channel3 level-detect brake event do not happened
    ,BRKLIF3_1 = 0x00000800 // When PWM channel3 level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel4 Level-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 12)
    ,BRKLIF4_MASK = 0x00001000
    ,BRKLIF4_POS = 12
    ,BRKLIF4_0 = 0x00000000 // PWM channel4 level-detect brake event do not happened
    ,BRKLIF4_1 = 0x00001000 // When PWM channel4 level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel5 Level-Detect Brake Interrupt Flag (Write Protect) Note: This register is write protected. Refer to REGWRPROT register. (bits: 13)
    ,BRKLIF5_MASK = 0x00002000
    ,BRKLIF5_POS = 13
    ,BRKLIF5_0 = 0x00000000 // PWM channel5 level-detect brake event do not happened
    ,BRKLIF5_1 = 0x00002000 // When PWM channel5 level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // PWM Channel0 Edge-Detect Brake Status (bits: 16)
    ,BRKESTS0_MASK = 0x00010000
    ,BRKESTS0_POS = 16
    ,BRKESTS0_0 = 0x00000000 // PWM channel0 edge-detect brake state is released
    ,BRKESTS0_1 = 0x00010000 // When PWM channel0 edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel0 at brake state, writing 1 to clear
    // PWM Channel1 Edge-Detect Brake Status (bits: 17)
    ,BRKESTS1_MASK = 0x00020000
    ,BRKESTS1_POS = 17
    ,BRKESTS1_0 = 0x00000000 // PWM channel1 edge-detect brake state is released
    ,BRKESTS1_1 = 0x00020000 // When PWM channel1 edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel1 at brake state, writing 1 to clear
    // PWM Channel2 Edge-Detect Brake Status (bits: 18)
    ,BRKESTS2_MASK = 0x00040000
    ,BRKESTS2_POS = 18
    ,BRKESTS2_0 = 0x00000000 // PWM channel2 edge-detect brake state is released
    ,BRKESTS2_1 = 0x00040000 // When PWM channel2 edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel2 at brake state, writing 1 to clear
    // PWM Channel3 Edge-Detect Brake Status (bits: 19)
    ,BRKESTS3_MASK = 0x00080000
    ,BRKESTS3_POS = 19
    ,BRKESTS3_0 = 0x00000000 // PWM channel3 edge-detect brake state is released
    ,BRKESTS3_1 = 0x00080000 // When PWM channel3 edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel3 at brake state, writing 1 to clear
    // PWM Channel4 Edge-Detect Brake Status (bits: 20)
    ,BRKESTS4_MASK = 0x00100000
    ,BRKESTS4_POS = 20
    ,BRKESTS4_0 = 0x00000000 // PWM channel4 edge-detect brake state is released
    ,BRKESTS4_1 = 0x00100000 // When PWM channel4 edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel4 at brake state, writing 1 to clear
    // PWM Channel5 Edge-Detect Brake Status (bits: 21)
    ,BRKESTS5_MASK = 0x00200000
    ,BRKESTS5_POS = 21
    ,BRKESTS5_0 = 0x00000000 // PWM channel5 edge-detect brake state is released
    ,BRKESTS5_1 = 0x00200000 // When PWM channel5 edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel5 at brake state, writing 1 to clear
    // PWM Channel0 Level-Detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, PWM will release brake state until current PWM period finished. The PWM waveform will start output from next full PWM period. (bits: 24)
    ,BRKLSTS0_MASK = 0x01000000
    ,BRKLSTS0_POS = 24
    ,BRKLSTS0_0 = 0x00000000 // PWM channel0 level-detect brake state is released
    ,BRKLSTS0_1 = 0x01000000 // When PWM channel0 level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel0 at brake state
    // PWM Channel1 Level-Detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, PWM will release brake state until current PWM period finished. The PWM waveform will start output from next full PWM period. (bits: 25)
    ,BRKLSTS1_MASK = 0x02000000
    ,BRKLSTS1_POS = 25
    ,BRKLSTS1_0 = 0x00000000 // PWM channel1 level-detect brake state is released
    ,BRKLSTS1_1 = 0x02000000 // When PWM channel1 level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel1 at brake state
    // PWM Channel2 Level-Detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, PWM will release brake state until current PWM period finished. The PWM waveform will start output from next full PWM period. (bits: 26)
    ,BRKLSTS2_MASK = 0x04000000
    ,BRKLSTS2_POS = 26
    ,BRKLSTS2_0 = 0x00000000 // PWM channel2 level-detect brake state is released
    ,BRKLSTS2_1 = 0x04000000 // When PWM channel2 level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel2 at brake state
    // PWM Channel3 Level-Detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, PWM will release brake state until current PWM period finished. The PWM waveform will start output from next full PWM period. (bits: 27)
    ,BRKLSTS3_MASK = 0x08000000
    ,BRKLSTS3_POS = 27
    ,BRKLSTS3_0 = 0x00000000 // PWM channel3 level-detect brake state is released
    ,BRKLSTS3_1 = 0x08000000 // When PWM channel3 level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel3 at brake state
    // PWM Channel4 Level-Detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, PWM will release brake state until current PWM period finished. The PWM waveform will start output from next full PWM period. (bits: 28)
    ,BRKLSTS4_MASK = 0x10000000
    ,BRKLSTS4_POS = 28
    ,BRKLSTS4_0 = 0x00000000 // PWM channel4 level-detect brake state is released
    ,BRKLSTS4_1 = 0x10000000 // When PWM channel4 level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel4 at brake state
    // PWM Channel5 Level-Detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, PWM will release brake state until current PWM period finished. The PWM waveform will start output from next full PWM period. (bits: 29)
    ,BRKLSTS5_MASK = 0x20000000
    ,BRKLSTS5_POS = 29
    ,BRKLSTS5_0 = 0x00000000 // PWM channel5 level-detect brake state is released
    ,BRKLSTS5_1 = 0x20000000 // When PWM channel5 level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel5 at brake state
    ,INTSTS1_MASK = 0x3F3F3F3F
    ;
  };
  // PWM Trigger ADC Source Select Register 0
  struct ADCTS0 : reg<ip_ver, base + 0xF8>
  {
    static constexpr typename ADCTS0::type
    // PWM_CH0 Trigger ADC Source Select (bits: 3-0)
     TRGSEL0_MASK = 0x0000000F
    ,TRGSEL0_POS = 0
    ,TRGSEL0_0 = 0x00000000 // PWM_CH0 zero point
    ,TRGSEL0_1 = 0x00000001 // PWM_CH0 period point
    ,TRGSEL0_2 = 0x00000002 // PWM_CH0 zero or period point
    ,TRGSEL0_3 = 0x00000003 // PWM_CH0 up-count CMPDAT point
    ,TRGSEL0_4 = 0x00000004 // PWM_CH0 down-count CMPDAT point
    ,TRGSEL0_5 = 0x00000005 // Reserved
    ,TRGSEL0_6 = 0x00000006 // Reserved
    ,TRGSEL0_7 = 0x00000007 // Reserved
    ,TRGSEL0_8 = 0x00000008 // PWM_CH1 up-count CMPDAT point
    ,TRGSEL0_9 = 0x00000009 // PWM_CH1 down-count CMPDAT point
    // PWM_CH0 Trigger ADC Enable Control (bits: 7)
    ,TRGEN0_MASK = 0x00000080
    ,TRGEN0_POS = 7
    ,TRGEN0 = 0x00000080
    // PWM_CH1 Trigger ADC Source Select (bits: 11-8)
    ,TRGSEL1_MASK = 0x00000F00
    ,TRGSEL1_POS = 8
    ,TRGSEL1_0 = 0x00000000 // PWM_CH0 zero point
    ,TRGSEL1_1 = 0x00000100 // PWM_CH0 period point
    ,TRGSEL1_2 = 0x00000200 // PWM_CH0 zero or period point
    ,TRGSEL1_3 = 0x00000300 // PWM_CH0 up-count CMPDAT point
    ,TRGSEL1_4 = 0x00000400 // PWM_CH0 down-count CMPDAT point
    ,TRGSEL1_5 = 0x00000500 // Reserved
    ,TRGSEL1_6 = 0x00000600 // Reserved
    ,TRGSEL1_7 = 0x00000700 // Reserved
    ,TRGSEL1_8 = 0x00000800 // PWM_CH1 up-count CMPDAT point
    ,TRGSEL1_9 = 0x00000900 // PWM_CH1 down-count CMPDAT point
    // PWM_CH1 Trigger ADC Enable Control (bits: 15)
    ,TRGEN1_MASK = 0x00008000
    ,TRGEN1_POS = 15
    ,TRGEN1 = 0x00008000
    // PWM_CH2 Trigger ADC Source Select (bits: 19-16)
    ,TRGSEL2_MASK = 0x000F0000
    ,TRGSEL2_POS = 16
    ,TRGSEL2_0 = 0x00000000 // PWM_CH2 zero point
    ,TRGSEL2_1 = 0x00010000 // PWM_CH2 period point
    ,TRGSEL2_2 = 0x00020000 // PWM_CH2 zero or period point
    ,TRGSEL2_3 = 0x00030000 // PWM_CH2 up-count CMPDAT point
    ,TRGSEL2_4 = 0x00040000 // PWM_CH2 down-count CMPDAT point
    ,TRGSEL2_5 = 0x00050000 // Reserved
    ,TRGSEL2_6 = 0x00060000 // Reserved
    ,TRGSEL2_7 = 0x00070000 // Reserved
    ,TRGSEL2_8 = 0x00080000 // PWM_CH3 up-count CMPDAT point
    ,TRGSEL2_9 = 0x00090000 // PWM_CH3 down-count CMPDAT point
    // PWM_CH2 Trigger ADC Enable Control (bits: 23)
    ,TRGEN2_MASK = 0x00800000
    ,TRGEN2_POS = 23
    ,TRGEN2 = 0x00800000
    // PWM_CH3 Trigger ADC Source Select (bits: 27-24)
    ,TRGSEL3_MASK = 0x0F000000
    ,TRGSEL3_POS = 24
    ,TRGSEL3_0 = 0x00000000 // PWM_CH2 zero point
    ,TRGSEL3_1 = 0x01000000 // PWM_CH2 period point
    ,TRGSEL3_2 = 0x02000000 // PWM_CH2 zero or period point
    ,TRGSEL3_3 = 0x03000000 // PWM_CH2 up-count CMPDAT point
    ,TRGSEL3_4 = 0x04000000 // PWM_CH2 down-count CMPDAT point
    ,TRGSEL3_5 = 0x05000000 // Reserved
    ,TRGSEL3_6 = 0x06000000 // Reserved
    ,TRGSEL3_7 = 0x07000000 // Reserved
    ,TRGSEL3_8 = 0x08000000 // PWM_CH3 up-count CMPDAT point
    ,TRGSEL3_9 = 0x09000000 // PWM_CH3 down-count CMPDAT point
    // PWM_CH3 Trigger ADC Enable Control (bits: 31)
    ,TRGEN3_MASK = 0x80000000
    ,TRGEN3_POS = 31
    ,TRGEN3 = 0x80000000
    ,ADCTS0_MASK = 0x8F8F8F8F
    ;
  };
  // PWM Trigger ADC Source Select Register 1
  struct ADCTS1 : reg<ip_ver, base + 0xFC>
  {
    static constexpr typename ADCTS1::type
    // PWM_CH4 Trigger ADC Source Select (bits: 3-0)
     TRGSEL4_MASK = 0x0000000F
    ,TRGSEL4_POS = 0
    ,TRGSEL4_0 = 0x00000000 // PWM_CH4 zero point
    ,TRGSEL4_1 = 0x00000001 // PWM_CH4 period point
    ,TRGSEL4_2 = 0x00000002 // PWM_CH4 zero or period point
    ,TRGSEL4_3 = 0x00000003 // PWM_CH4 up-count CMPDAT point
    ,TRGSEL4_4 = 0x00000004 // PWM_CH4 down-count CMPDAT point
    ,TRGSEL4_5 = 0x00000005 // Reserved
    ,TRGSEL4_6 = 0x00000006 // Reserved
    ,TRGSEL4_7 = 0x00000007 // Reserved
    ,TRGSEL4_8 = 0x00000008 // PWM_CH5 up-count CMPDAT point
    ,TRGSEL4_9 = 0x00000009 // PWM_CH5 down-count CMPDAT point
    // PWM_CH4 Trigger ADC Enable Control (bits: 7)
    ,TRGEN4_MASK = 0x00000080
    ,TRGEN4_POS = 7
    ,TRGEN4 = 0x00000080
    // PWM_CH5 Trigger ADC Source Select (bits: 11-8)
    ,TRGSEL5_MASK = 0x00000F00
    ,TRGSEL5_POS = 8
    ,TRGSEL5_0 = 0x00000000 // PWM_CH4 zero point
    ,TRGSEL5_1 = 0x00000100 // PWM_CH4 period point
    ,TRGSEL5_2 = 0x00000200 // PWM_CH4 zero or period point
    ,TRGSEL5_3 = 0x00000300 // PWM_CH4 up-count CMPDAT point
    ,TRGSEL5_4 = 0x00000400 // PWM_CH4 down-count CMPDAT point
    ,TRGSEL5_5 = 0x00000500 // Reserved
    ,TRGSEL5_6 = 0x00000600 // Reserved
    ,TRGSEL5_7 = 0x00000700 // Reserved
    ,TRGSEL5_8 = 0x00000800 // PWM_CH5 up-count CMPDAT point
    ,TRGSEL5_9 = 0x00000900 // PWM_CH5 down-count CMPDAT point
    // PWM_CH5 Trigger ADC Enable Control (bits: 15)
    ,TRGEN5_MASK = 0x00008000
    ,TRGEN5_POS = 15
    ,TRGEN5 = 0x00008000
    ,ADCTS1_MASK = 0x00008F8F
    ;
  };
  // PWM Synchronous Start Control Register
  struct SSCTL : reg<ip_ver, base + 0x110>
  {
    static constexpr typename SSCTL::type
    // PWM Synchronous Start Function Enable 0 When synchronous start function is enabled, the PWM_CH0 counter enable bit (CNTEN0) can be enabled by writing PWM synchronous start trigger bit (CNTSEN). (bits: 0)
     SSEN0_MASK = 0x00000001
    ,SSEN0_POS = 0
    ,SSEN0_0 = 0x00000000 // PWM synchronous start function Disabled
    ,SSEN0_1 = 0x00000001 // PWM synchronous start function Enabled
    // PWM Synchronous Start Function Enable 2 When synchronous start function is enabled, the PWM_CH2 counter enable bit (CNTEN2) can be enabled by writing PWM synchronous start trigger bit (CNTSEN). (bits: 2)
    ,SSEN2_MASK = 0x00000004
    ,SSEN2_POS = 2
    ,SSEN2_0 = 0x00000000 // PWM synchronous start function Disabled
    ,SSEN2_1 = 0x00000004 // PWM synchronous start function Enabled
    // PWM Synchronous Start Function Enable 4 When synchronous start function is enabled, the PWM_CH4 counter enable bit (CNTEN4) can be enabled by writing PWM synchronous start trigger bit (CNTSEN). (bits: 4)
    ,SSEN4_MASK = 0x00000010
    ,SSEN4_POS = 4
    ,SSEN4_0 = 0x00000000 // PWM synchronous start function Disabled
    ,SSEN4_1 = 0x00000010 // PWM synchronous start function Enabled
    // PWM Synchronous Start Source Select (bits: 9-8)
    ,SSRC_MASK = 0x00000300
    ,SSRC_POS = 8
    ,SSRC_0 = 0x00000000 // Synchronous start source come from PWM0
    ,SSRC_1 = 0x00000100 // Synchronous start source come from PWM1
    ,SSRC_2 = 0x00000200 // Synchronous start source come from BPWM0
    ,SSRC_3 = 0x00000300 // Synchronous start source come from BPWM1
    ,SSCTL_MASK = 0x00000315
    ;
  };
  // PWM Synchronous Start Trigger Register
  struct SSTRG : reg<ip_ver, base + 0x114>
  {
    static constexpr typename SSTRG::type
    // PWM Counter Synchronous Start Enable (Write Only) PMW counter synchronous enable function is used to make selected PWM channels (include PWM0_CHx and PWM1_CHx) start counting at the same time. Writing this bit to 1 will also set the counter enable bit (CNTENn, n denotes channel 0 to 5) if correlated PWM channel counter synchronous start function is enabled. Note: This bit only present in PWM0_BA. (bits: 0)
     CNTSEN_MASK = 0x00000001
    ,CNTSEN_POS = 0
    ,CNTSEN = 0x00000001
    ,SSTRG_MASK = 0x00000001
    ;
  };
  // PWM Status Register
  struct STATUS : reg<ip_ver, base + 0x120>
  {
    static constexpr typename STATUS::type
    // Time-Base Counter 0 Equal To 0xFFFF Latched Status (bits: 0)
     CNTMAX0_MASK = 0x00000001
    ,CNTMAX0_POS = 0
    ,CNTMAX0_0 = 0x00000000 // indicates the time-base counter never reached its maximum value 0xFFFF
    ,CNTMAX0_1 = 0x00000001 // indicates the time-base counter reached its maximum value, software can write 1 to clear this bit
    // Time-Base Counter 2 Equal To 0xFFFF Latched Status (bits: 2)
    ,CNTMAX2_MASK = 0x00000004
    ,CNTMAX2_POS = 2
    ,CNTMAX2_0 = 0x00000000 // indicates the time-base counter never reached its maximum value 0xFFFF
    ,CNTMAX2_1 = 0x00000004 // indicates the time-base counter reached its maximum value, software can write 1 to clear this bit
    // Time-Base Counter 4 Equal To 0xFFFF Latched Status (bits: 4)
    ,CNTMAX4_MASK = 0x00000010
    ,CNTMAX4_POS = 4
    ,CNTMAX4_0 = 0x00000000 // indicates the time-base counter never reached its maximum value 0xFFFF
    ,CNTMAX4_1 = 0x00000010 // indicates the time-base counter reached its maximum value, software can write 1 to clear this bit
    // ADC Start Of Conversion Status Each bit n controls the corresponding PWM channel n. (bits: 21-16)
    ,ADCTRGN_MASK = 0x003F0000
    ,ADCTRGN_POS = 16
    ,ADCTRGN_0 = 0x00000000 // Indicates no ADC start of conversion trigger event has occurred
    ,ADCTRGN_1 = 0x00010000 // Indicates an ADC start of conversion trigger event has occurred, software can write 1 to clear this bit
    ,STATUS_MASK = 0x003F0015
    ;
  };
  // PWM Capture Input Enable Register
  struct CAPINEN : reg<ip_ver, base + 0x200>
  {
    static constexpr typename CAPINEN::type
    // Capture Input Enable Each bit n controls the corresponding PWM channel n. (bits: 5-0)
     CAPINENN_MASK = 0x0000003F
    ,CAPINENN_POS = 0
    ,CAPINENN_0 = 0x00000000 // PWM Channel capture input path Disabled. The input of PWM channel capture function is always regarded as 0
    ,CAPINENN_1 = 0x00000001 // PWM Channel capture input path Enabled. The input of PWM channel capture function comes from correlative multifunction pin
    ,CAPINEN_MASK = 0x0000003F
    ;
  };
  // PWM Capture Control Register
  struct CAPCTL : reg<ip_ver, base + 0x204>
  {
    static constexpr typename CAPCTL::type
    // Capture Function Enable Control Each bit n controls the corresponding PWM channel n. (bits: 5-0)
     CAPENN_MASK = 0x0000003F
    ,CAPENN_POS = 0
    ,CAPENN_0 = 0x00000000 // Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated
    ,CAPENN_1 = 0x00000001 // Capture function Enabled. Capture latched the PWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Inverter Enable Control Each bit n controls the corresponding PWM channel n. (bits: 13-8)
    ,CAPINVN_MASK = 0x00003F00
    ,CAPINVN_POS = 8
    ,CAPINVN_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINVN_1 = 0x00000100 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Rising Capture Reload Enable Control Each bit n controls the corresponding PWM channel n. (bits: 21-16)
    ,RCRLDENN_MASK = 0x003F0000
    ,RCRLDENN_POS = 16
    ,RCRLDENN_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDENN_1 = 0x00010000 // Rising capture reload counter Enabled
    // Falling Capture Reload Enable Control Each bit n controls the corresponding PWM channel n. (bits: 29-24)
    ,FCRLDENN_MASK = 0x3F000000
    ,FCRLDENN_POS = 24
    ,FCRLDENN_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDENN_1 = 0x01000000 // Falling capture reload counter Enabled
    ,CAPCTL_MASK = 0x3F3F3F3F
    ;
  };
  // PWM Capture Status Register
  struct CAPSTS : reg<ip_ver, base + 0x208>
  {
    static constexpr typename CAPSTS::type
    // Capture Rising Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CRLIF is 1. Each bit n controls the corresponding PWM channel n. Note: This bit will be cleared automatically when user clear corresponding CRLIF. (bits: 5-0)
     CRLIFOVN_MASK = 0x0000003F
    ,CRLIFOVN_POS = 0
    // Capture Falling Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CFLIF is 1. Each bit n controls the corresponding PWM channel n. Note: This bit will be cleared automatically when user clear corresponding CFLIF. (bits: 13-8)
    ,CFLIFOVN_MASK = 0x00003F00
    ,CFLIFOVN_POS = 8
    ,CAPSTS_MASK = 0x00003F3F
    ;
  };
  // PWM Rising Capture Data Register 0
  struct RCAPDAT0 : reg<ip_ver, base + 0x20C>
  {
    static constexpr typename RCAPDAT0::type
    // PWM Rising Capture Data Register (Read Only) When rising capture condition happened, the PWM counter value will be saved in this register. (bits: 15-0)
     RCAPDAT_MASK = 0x0000FFFF
    ,RCAPDAT_POS = 0
    ,RCAPDAT0_MASK = 0x0000FFFF
    ;
  };
  // PWM Falling Capture Data Register 0
  struct FCAPDAT0 : reg<ip_ver, base + 0x210>
  {
    static constexpr typename FCAPDAT0::type
    // PWM Falling Capture Data Register (Read Only) When falling capture condition happened, the PWM counter value will be saved in this register. (bits: 15-0)
     FCAPDAT_MASK = 0x0000FFFF
    ,FCAPDAT_POS = 0
    ,FCAPDAT0_MASK = 0x0000FFFF
    ;
  };
  // PWM Rising Capture Data Register 1
  using RCAPDAT1 = reg<ip_ver, base + 0x214>;
  // PWM Falling Capture Data Register 1
  using FCAPDAT1 = reg<ip_ver, base + 0x218>;
  // PWM Rising Capture Data Register 2
  using RCAPDAT2 = reg<ip_ver, base + 0x21C>;
  // PWM Falling Capture Data Register 2
  using FCAPDAT2 = reg<ip_ver, base + 0x220>;
  // PWM Rising Capture Data Register 3
  using RCAPDAT3 = reg<ip_ver, base + 0x224>;
  // PWM Falling Capture Data Register 3
  using FCAPDAT3 = reg<ip_ver, base + 0x228>;
  // PWM Rising Capture Data Register 4
  using RCAPDAT4 = reg<ip_ver, base + 0x22C>;
  // PWM Falling Capture Data Register 4
  using FCAPDAT4 = reg<ip_ver, base + 0x230>;
  // PWM Rising Capture Data Register 5
  using RCAPDAT5 = reg<ip_ver, base + 0x234>;
  // PWM Falling Capture Data Register 5
  using FCAPDAT5 = reg<ip_ver, base + 0x238>;
  // PWM Capture Interrupt Enable Register
  struct CAPIEN : reg<ip_ver, base + 0x250>
  {
    static constexpr typename CAPIEN::type
    // PWM Capture Rising Latch Interrupt Enable Control Each bit n controls the corresponding PWM channel n. (bits: 5-0)
     CAPRIENN_MASK = 0x0000003F
    ,CAPRIENN_POS = 0
    ,CAPRIENN_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIENN_1 = 0x00000001 // Capture rising edge latch interrupt Enabled
    // PWM Capture Falling Latch Interrupt Enable Control Each bit n controls the corresponding PWM channel n. (bits: 13-8)
    ,CAPFIENN_MASK = 0x00003F00
    ,CAPFIENN_POS = 8
    ,CAPFIENN_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIENN_1 = 0x00000100 // Capture falling edge latch interrupt Enabled
    ,CAPIEN_MASK = 0x00003F3F
    ;
  };
  // PWM Capture Interrupt Flag Register
  struct CAPIF : reg<ip_ver, base + 0x254>
  {
    static constexpr typename CAPIF::type
    // PWM Capture Rising Latch Interrupt Flag This bit is writing 1 to clear. Each bit n controls the corresponding PWM channel n. (bits: 5-0)
     CRLIFN_MASK = 0x0000003F
    ,CRLIFN_POS = 0
    ,CRLIFN_0 = 0x00000000 // No capture rising latch condition happened
    ,CRLIFN_1 = 0x00000001 // Capture rising latch condition happened, this flag will be set to high
    // PWM Capture Falling Latch Interrupt Flag This bit is writing 1 to clear. Each bit n controls the corresponding PWM channel n. (bits: 13-8)
    ,CFLIFN_MASK = 0x00003F00
    ,CFLIFN_POS = 8
    ,CFLIFN_0 = 0x00000000 // No capture falling latch condition happened
    ,CFLIFN_1 = 0x00000100 // Capture falling latch condition happened, this flag will be set to high
    ,CAPIF_MASK = 0x00003F3F
    ;
  };
  // PWM PERIOD0 Buffer
  struct PBUF0 : reg<ip_ver, base + 0x304>
  {
    static constexpr typename PBUF0::type
    // PWM Period Register Buffer (Read Only) Used as PERIOD active register. (bits: 15-0)
     PBUF_MASK = 0x0000FFFF
    ,PBUF_POS = 0
    ,PBUF0_MASK = 0x0000FFFF
    ;
  };
  // PWM PERIOD2 Buffer
  using PBUF2 = reg<ip_ver, base + 0x30C>;
  // PWM PERIOD4 Buffer
  using PBUF4 = reg<ip_ver, base + 0x314>;
  // PWM CMPDAT0 Buffer
  struct CMPBUF0 : reg<ip_ver, base + 0x31C>
  {
    static constexpr typename CMPBUF0::type
    // PWM Comparator Register Buffer (Read Only) Used as CMP active register. (bits: 15-0)
     CMPBUF_MASK = 0x0000FFFF
    ,CMPBUF_POS = 0
    ,CMPBUF0_MASK = 0x0000FFFF
    ;
  };
  // PWM CMPDAT1 Buffer
  using CMPBUF1 = reg<ip_ver, base + 0x320>;
  // PWM CMPDAT2 Buffer
  using CMPBUF2 = reg<ip_ver, base + 0x324>;
  // PWM CMPDAT3 Buffer
  using CMPBUF3 = reg<ip_ver, base + 0x328>;
  // PWM CMPDAT4 Buffer
  using CMPBUF4 = reg<ip_ver, base + 0x32C>;
  // PWM CMPDAT5 Buffer
  using CMPBUF5 = reg<ip_ver, base + 0x330>;
}; // struct PWM

} // namespace lmcu::device::ip::v1

