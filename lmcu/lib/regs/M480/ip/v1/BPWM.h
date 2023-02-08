/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// BPWM Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct BPWM
{
  static constexpr auto ip_ver = ip_version::_1;

  // BPWM Control Register 0
  struct CTL0 : reg<ip_ver, base + 0x0>
  {
    static constexpr typename CTL0::type
    // Center Re-load Each bit n controls the corresponding BPWM channel n. In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the center point of a period. (bits: 0)
     CTRLD0_MASK = 0x00000001
    ,CTRLD0_POS = 0
    ,CTRLD0 = 0x00000001
    // Center Re-load Each bit n controls the corresponding BPWM channel n. In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the center point of a period. (bits: 1)
    ,CTRLD1_MASK = 0x00000002
    ,CTRLD1_POS = 1
    ,CTRLD1 = 0x00000002
    // Center Re-load Each bit n controls the corresponding BPWM channel n. In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the center point of a period. (bits: 2)
    ,CTRLD2_MASK = 0x00000004
    ,CTRLD2_POS = 2
    ,CTRLD2 = 0x00000004
    // Center Re-load Each bit n controls the corresponding BPWM channel n. In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the center point of a period. (bits: 3)
    ,CTRLD3_MASK = 0x00000008
    ,CTRLD3_POS = 3
    ,CTRLD3 = 0x00000008
    // Center Re-load Each bit n controls the corresponding BPWM channel n. In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the center point of a period. (bits: 4)
    ,CTRLD4_MASK = 0x00000010
    ,CTRLD4_POS = 4
    ,CTRLD4 = 0x00000010
    // Center Re-load Each bit n controls the corresponding BPWM channel n. In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the center point of a period. (bits: 5)
    ,CTRLD5_MASK = 0x00000020
    ,CTRLD5_POS = 5
    ,CTRLD5 = 0x00000020
    // Immediately Load Enable Bit(S) Each bit n controls the corresponding BPWM channel n. Note: If IMMLDENn is Enabled, CTRLDn will be invalid. (bits: 16)
    ,IMMLDEN0_MASK = 0x00010000
    ,IMMLDEN0_POS = 16
    ,IMMLDEN0_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN0_1 = 0x00010000 // PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT
    // Immediately Load Enable Bit(S) Each bit n controls the corresponding BPWM channel n. Note: If IMMLDENn is Enabled, CTRLDn will be invalid. (bits: 17)
    ,IMMLDEN1_MASK = 0x00020000
    ,IMMLDEN1_POS = 17
    ,IMMLDEN1_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN1_1 = 0x00020000 // PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT
    // Immediately Load Enable Bit(S) Each bit n controls the corresponding BPWM channel n. Note: If IMMLDENn is Enabled, CTRLDn will be invalid. (bits: 18)
    ,IMMLDEN2_MASK = 0x00040000
    ,IMMLDEN2_POS = 18
    ,IMMLDEN2_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN2_1 = 0x00040000 // PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT
    // Immediately Load Enable Bit(S) Each bit n controls the corresponding BPWM channel n. Note: If IMMLDENn is Enabled, CTRLDn will be invalid. (bits: 19)
    ,IMMLDEN3_MASK = 0x00080000
    ,IMMLDEN3_POS = 19
    ,IMMLDEN3_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN3_1 = 0x00080000 // PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT
    // Immediately Load Enable Bit(S) Each bit n controls the corresponding BPWM channel n. Note: If IMMLDENn is Enabled, CTRLDn will be invalid. (bits: 20)
    ,IMMLDEN4_MASK = 0x00100000
    ,IMMLDEN4_POS = 20
    ,IMMLDEN4_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN4_1 = 0x00100000 // PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT
    // Immediately Load Enable Bit(S) Each bit n controls the corresponding BPWM channel n. Note: If IMMLDENn is Enabled, CTRLDn will be invalid. (bits: 21)
    ,IMMLDEN5_MASK = 0x00200000
    ,IMMLDEN5_POS = 21
    ,IMMLDEN5_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN5_1 = 0x00200000 // PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT
    // ICE Debug Mode Counter Halt (Write Protect) If counter halt is enabled, BPWM all counters will keep current value until exit ICE debug mode. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 30)
    ,DBGHALT_MASK = 0x40000000
    ,DBGHALT_POS = 30
    ,DBGHALT_0 = 0x00000000 // ICE debug mode counter halt Disabled
    ,DBGHALT_1 = 0x40000000 // ICE debug mode counter halt Enabled
    // ICE Debug Mode Acknowledge Disable (Write Protect) BPWM pin will keep output no matter ICE debug mode acknowledged or not. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 31)
    ,DBGTRIOFF_MASK = 0x80000000
    ,DBGTRIOFF_POS = 31
    ,DBGTRIOFF_0 = 0x00000000 // ICE debug mode acknowledgement effects BPWM output
    ,DBGTRIOFF_1 = 0x80000000 // ICE debug mode acknowledgement Disabled
    ,CTL0_MASK = 0xC03F003F
    ;
  };
  // BPWM Control Register 1
  struct CTL1 : reg<ip_ver, base + 0x4>
  {
    static constexpr typename CTL1::type
    // BPWM Counter Behavior Type 0 Each bit n controls corresponding BPWM channel n. (bits: 1-0)
     CNTTYPE0_MASK = 0x00000003
    ,CNTTYPE0_POS = 0
    ,CNTTYPE0_0 = 0x00000000 // Up counter type (supports in capture mode)
    ,CNTTYPE0_1 = 0x00000001 // Down count type (supports in capture mode)
    ,CNTTYPE0_2 = 0x00000002 // Up-down counter type
    ,CNTTYPE0_3 = 0x00000003 // Reserved.
    ,CTL1_MASK = 0x00000003
    ;
  };
  // BPWM Clock Source Register
  struct CLKSRC : reg<ip_ver, base + 0x10>
  {
    static constexpr typename CLKSRC::type
    // BPWM_CH01 External Clock Source Select (bits: 2-0)
     ECLKSRC0_MASK = 0x00000007
    ,ECLKSRC0_POS = 0
    ,ECLKSRC0_0 = 0x00000000 // BPWMx_CLK, x denotes 0 or 1
    ,ECLKSRC0_1 = 0x00000001 // TIMER0 overflow
    ,ECLKSRC0_2 = 0x00000002 // TIMER1 overflow
    ,ECLKSRC0_3 = 0x00000003 // TIMER2 overflow
    ,ECLKSRC0_4 = 0x00000004 // TIMER3 overflow
    ,CLKSRC_MASK = 0x00000007
    ;
  };
  // BPWM Clock Prescale Register
  struct CLKPSC : reg<ip_ver, base + 0x14>
  {
    static constexpr typename CLKPSC::type
    // BPWM Counter Clock Prescale The clock of BPWM counter is decided by clock prescaler. Each BPWM pair share one BPWM counter clock prescaler. The clock of BPWM counter is divided by (CLKPSC+ 1). (bits: 11-0)
     CLKPSCVAL_MASK = 0x00000FFF
    ,CLKPSCVAL_POS = 0
    ,CLKPSC_MASK = 0x00000FFF
    ;
  };
  // BPWM Counter Enable Register
  struct CNTEN : reg<ip_ver, base + 0x20>
  {
    static constexpr typename CNTEN::type
    // BPWM Counter 0 Enable Bit (bits: 0)
     CNTEN0_MASK = 0x00000001
    ,CNTEN0_POS = 0
    ,CNTEN0_0 = 0x00000000 // BPWM Counter and clock prescaler stop running
    ,CNTEN0_1 = 0x00000001 // BPWM Counter and clock prescaler start running
    ,CNTEN_MASK = 0x00000001
    ;
  };
  // BPWM Clear Counter Register
  struct CNTCLR : reg<ip_ver, base + 0x24>
  {
    static constexpr typename CNTCLR::type
    // Clear BPWM Counter Control Bit 0 It is automatically cleared by hardware. (bits: 0)
     CNTCLR0_MASK = 0x00000001
    ,CNTCLR0_POS = 0
    ,CNTCLR0_0 = 0x00000000 // No effect
    ,CNTCLR0_1 = 0x00000001 // Clear 16-bit BPWM counter to 0000H
    ,CNTCLR_MASK = 0x00000001
    ;
  };
  // BPWM Period Register
  struct PERIOD : reg<ip_ver, base + 0x30>
  {
    static constexpr typename PERIOD::type
    // BPWM Period Register Up-Count mode: In this mode, BPWM counter counts from 0 to PERIOD, and restarts from 0. Down-Count mode: In this mode, BPWM counter counts from PERIOD to 0, and restarts from PERIOD. (bits: 15-0)
     PERIODVAL_MASK = 0x0000FFFF
    ,PERIODVAL_POS = 0
    ,PERIOD_MASK = 0x0000FFFF
    ;
  };
  // BPWM Comparator Register 0
  struct CMPDAT0 : reg<ip_ver, base + 0x50>
  {
    static constexpr typename CMPDAT0::type
    // BPWM Comparator Register CMPDAT use to compare with CNT to generate BPWM waveform, interrupt and trigger EADC0/1. In independent mode, CMPDAT0~5 denote as 6 independent BPWM_CH0~5 compared point. (bits: 15-0)
     CMPDAT_MASK = 0x0000FFFF
    ,CMPDAT_POS = 0
    ,CMPDAT0_MASK = 0x0000FFFF
    ;
  };
  // BPWM Comparator Register 1
  using CMPDAT1 = reg<ip_ver, base + 0x54>;
  // BPWM Comparator Register 2
  using CMPDAT2 = reg<ip_ver, base + 0x58>;
  // BPWM Comparator Register 3
  using CMPDAT3 = reg<ip_ver, base + 0x5C>;
  // BPWM Comparator Register 4
  using CMPDAT4 = reg<ip_ver, base + 0x60>;
  // BPWM Comparator Register 5
  using CMPDAT5 = reg<ip_ver, base + 0x64>;
  // BPWM Counter Register
  struct CNT : reg<ip_ver, base + 0x90>
  {
    static constexpr typename CNT::type
    // BPWM Data Register (Read Only) User can monitor CNT to know the current value in 16-bit period counter. (bits: 15-0)
     CNTVAL_MASK = 0x0000FFFF
    ,CNTVAL_POS = 0
    // BPWM Direction Indicator Flag (Read Only) (bits: 16)
    ,DIRF_MASK = 0x00010000
    ,DIRF_POS = 16
    ,DIRF_0 = 0x00000000 // Counter is Down count
    ,DIRF_1 = 0x00010000 // Counter is UP count
    ,CNT_MASK = 0x0001FFFF
    ;
  };
  // BPWM Generation Register 0
  struct WGCTL0 : reg<ip_ver, base + 0xB0>
  {
    static constexpr typename WGCTL0::type
    // BPWM Zero Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to zero. (bits: 1-0)
     ZPCTL0_MASK = 0x00000003
    ,ZPCTL0_POS = 0
    ,ZPCTL0_0 = 0x00000000 // Do nothing
    ,ZPCTL0_1 = 0x00000001 // BPWM zero point output Low
    ,ZPCTL0_2 = 0x00000002 // BPWM zero point output High
    ,ZPCTL0_3 = 0x00000003 // BPWM zero point output Toggle
    // BPWM Zero Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to zero. (bits: 3-2)
    ,ZPCTL1_MASK = 0x0000000C
    ,ZPCTL1_POS = 2
    ,ZPCTL1_0 = 0x00000000 // Do nothing
    ,ZPCTL1_1 = 0x00000004 // BPWM zero point output Low
    ,ZPCTL1_2 = 0x00000008 // BPWM zero point output High
    ,ZPCTL1_3 = 0x0000000C // BPWM zero point output Toggle
    // BPWM Zero Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to zero. (bits: 5-4)
    ,ZPCTL2_MASK = 0x00000030
    ,ZPCTL2_POS = 4
    ,ZPCTL2_0 = 0x00000000 // Do nothing
    ,ZPCTL2_1 = 0x00000010 // BPWM zero point output Low
    ,ZPCTL2_2 = 0x00000020 // BPWM zero point output High
    ,ZPCTL2_3 = 0x00000030 // BPWM zero point output Toggle
    // BPWM Zero Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to zero. (bits: 7-6)
    ,ZPCTL3_MASK = 0x000000C0
    ,ZPCTL3_POS = 6
    ,ZPCTL3_0 = 0x00000000 // Do nothing
    ,ZPCTL3_1 = 0x00000040 // BPWM zero point output Low
    ,ZPCTL3_2 = 0x00000080 // BPWM zero point output High
    ,ZPCTL3_3 = 0x000000C0 // BPWM zero point output Toggle
    // BPWM Zero Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to zero. (bits: 9-8)
    ,ZPCTL4_MASK = 0x00000300
    ,ZPCTL4_POS = 8
    ,ZPCTL4_0 = 0x00000000 // Do nothing
    ,ZPCTL4_1 = 0x00000100 // BPWM zero point output Low
    ,ZPCTL4_2 = 0x00000200 // BPWM zero point output High
    ,ZPCTL4_3 = 0x00000300 // BPWM zero point output Toggle
    // BPWM Zero Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to zero. (bits: 11-10)
    ,ZPCTL5_MASK = 0x00000C00
    ,ZPCTL5_POS = 10
    ,ZPCTL5_0 = 0x00000000 // Do nothing
    ,ZPCTL5_1 = 0x00000400 // BPWM zero point output Low
    ,ZPCTL5_2 = 0x00000800 // BPWM zero point output High
    ,ZPCTL5_3 = 0x00000C00 // BPWM zero point output Toggle
    // BPWM Period (Center) Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to (PERIOD+1). Note: This bit is center point control when BPWM counter operating in up-down counter type. (bits: 17-16)
    ,PRDPCTL0_MASK = 0x00030000
    ,PRDPCTL0_POS = 16
    ,PRDPCTL0_0 = 0x00000000 // Do nothing
    ,PRDPCTL0_1 = 0x00010000 // BPWM period (center) point output Low
    ,PRDPCTL0_2 = 0x00020000 // BPWM period (center) point output High
    ,PRDPCTL0_3 = 0x00030000 // BPWM period (center) point output Toggle
    // BPWM Period (Center) Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to (PERIOD+1). Note: This bit is center point control when BPWM counter operating in up-down counter type. (bits: 19-18)
    ,PRDPCTL1_MASK = 0x000C0000
    ,PRDPCTL1_POS = 18
    ,PRDPCTL1_0 = 0x00000000 // Do nothing
    ,PRDPCTL1_1 = 0x00040000 // BPWM period (center) point output Low
    ,PRDPCTL1_2 = 0x00080000 // BPWM period (center) point output High
    ,PRDPCTL1_3 = 0x000C0000 // BPWM period (center) point output Toggle
    // BPWM Period (Center) Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to (PERIOD+1). Note: This bit is center point control when BPWM counter operating in up-down counter type. (bits: 21-20)
    ,PRDPCTL2_MASK = 0x00300000
    ,PRDPCTL2_POS = 20
    ,PRDPCTL2_0 = 0x00000000 // Do nothing
    ,PRDPCTL2_1 = 0x00100000 // BPWM period (center) point output Low
    ,PRDPCTL2_2 = 0x00200000 // BPWM period (center) point output High
    ,PRDPCTL2_3 = 0x00300000 // BPWM period (center) point output Toggle
    // BPWM Period (Center) Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to (PERIOD+1). Note: This bit is center point control when BPWM counter operating in up-down counter type. (bits: 23-22)
    ,PRDPCTL3_MASK = 0x00C00000
    ,PRDPCTL3_POS = 22
    ,PRDPCTL3_0 = 0x00000000 // Do nothing
    ,PRDPCTL3_1 = 0x00400000 // BPWM period (center) point output Low
    ,PRDPCTL3_2 = 0x00800000 // BPWM period (center) point output High
    ,PRDPCTL3_3 = 0x00C00000 // BPWM period (center) point output Toggle
    // BPWM Period (Center) Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to (PERIOD+1). Note: This bit is center point control when BPWM counter operating in up-down counter type. (bits: 25-24)
    ,PRDPCTL4_MASK = 0x03000000
    ,PRDPCTL4_POS = 24
    ,PRDPCTL4_0 = 0x00000000 // Do nothing
    ,PRDPCTL4_1 = 0x01000000 // BPWM period (center) point output Low
    ,PRDPCTL4_2 = 0x02000000 // BPWM period (center) point output High
    ,PRDPCTL4_3 = 0x03000000 // BPWM period (center) point output Toggle
    // BPWM Period (Center) Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter count to (PERIOD+1). Note: This bit is center point control when BPWM counter operating in up-down counter type. (bits: 27-26)
    ,PRDPCTL5_MASK = 0x0C000000
    ,PRDPCTL5_POS = 26
    ,PRDPCTL5_0 = 0x00000000 // Do nothing
    ,PRDPCTL5_1 = 0x04000000 // BPWM period (center) point output Low
    ,PRDPCTL5_2 = 0x08000000 // BPWM period (center) point output High
    ,PRDPCTL5_3 = 0x0C000000 // BPWM period (center) point output Toggle
    ,WGCTL0_MASK = 0x0FFF0FFF
    ;
  };
  // BPWM Generation Register 1
  struct WGCTL1 : reg<ip_ver, base + 0xB4>
  {
    static constexpr typename WGCTL1::type
    // BPWM Compare Up Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter up count to CMPDAT. (bits: 1-0)
     CMPUCTL0_MASK = 0x00000003
    ,CMPUCTL0_POS = 0
    ,CMPUCTL0_0 = 0x00000000 // Do nothing
    ,CMPUCTL0_1 = 0x00000001 // BPWM compare up point output Low
    ,CMPUCTL0_2 = 0x00000002 // BPWM compare up point output High
    ,CMPUCTL0_3 = 0x00000003 // BPWM compare up point output Toggle
    // BPWM Compare Up Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter up count to CMPDAT. (bits: 3-2)
    ,CMPUCTL1_MASK = 0x0000000C
    ,CMPUCTL1_POS = 2
    ,CMPUCTL1_0 = 0x00000000 // Do nothing
    ,CMPUCTL1_1 = 0x00000004 // BPWM compare up point output Low
    ,CMPUCTL1_2 = 0x00000008 // BPWM compare up point output High
    ,CMPUCTL1_3 = 0x0000000C // BPWM compare up point output Toggle
    // BPWM Compare Up Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter up count to CMPDAT. (bits: 5-4)
    ,CMPUCTL2_MASK = 0x00000030
    ,CMPUCTL2_POS = 4
    ,CMPUCTL2_0 = 0x00000000 // Do nothing
    ,CMPUCTL2_1 = 0x00000010 // BPWM compare up point output Low
    ,CMPUCTL2_2 = 0x00000020 // BPWM compare up point output High
    ,CMPUCTL2_3 = 0x00000030 // BPWM compare up point output Toggle
    // BPWM Compare Up Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter up count to CMPDAT. (bits: 7-6)
    ,CMPUCTL3_MASK = 0x000000C0
    ,CMPUCTL3_POS = 6
    ,CMPUCTL3_0 = 0x00000000 // Do nothing
    ,CMPUCTL3_1 = 0x00000040 // BPWM compare up point output Low
    ,CMPUCTL3_2 = 0x00000080 // BPWM compare up point output High
    ,CMPUCTL3_3 = 0x000000C0 // BPWM compare up point output Toggle
    // BPWM Compare Up Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter up count to CMPDAT. (bits: 9-8)
    ,CMPUCTL4_MASK = 0x00000300
    ,CMPUCTL4_POS = 8
    ,CMPUCTL4_0 = 0x00000000 // Do nothing
    ,CMPUCTL4_1 = 0x00000100 // BPWM compare up point output Low
    ,CMPUCTL4_2 = 0x00000200 // BPWM compare up point output High
    ,CMPUCTL4_3 = 0x00000300 // BPWM compare up point output Toggle
    // BPWM Compare Up Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter up count to CMPDAT. (bits: 11-10)
    ,CMPUCTL5_MASK = 0x00000C00
    ,CMPUCTL5_POS = 10
    ,CMPUCTL5_0 = 0x00000000 // Do nothing
    ,CMPUCTL5_1 = 0x00000400 // BPWM compare up point output Low
    ,CMPUCTL5_2 = 0x00000800 // BPWM compare up point output High
    ,CMPUCTL5_3 = 0x00000C00 // BPWM compare up point output Toggle
    // BPWM Compare Down Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter down count to CMPDAT. (bits: 17-16)
    ,CMPDCTL0_MASK = 0x00030000
    ,CMPDCTL0_POS = 16
    ,CMPDCTL0_0 = 0x00000000 // Do nothing
    ,CMPDCTL0_1 = 0x00010000 // BPWM compare down point output Low
    ,CMPDCTL0_2 = 0x00020000 // BPWM compare down point output High
    ,CMPDCTL0_3 = 0x00030000 // BPWM compare down point output Toggle
    // BPWM Compare Down Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter down count to CMPDAT. (bits: 19-18)
    ,CMPDCTL1_MASK = 0x000C0000
    ,CMPDCTL1_POS = 18
    ,CMPDCTL1_0 = 0x00000000 // Do nothing
    ,CMPDCTL1_1 = 0x00040000 // BPWM compare down point output Low
    ,CMPDCTL1_2 = 0x00080000 // BPWM compare down point output High
    ,CMPDCTL1_3 = 0x000C0000 // BPWM compare down point output Toggle
    // BPWM Compare Down Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter down count to CMPDAT. (bits: 21-20)
    ,CMPDCTL2_MASK = 0x00300000
    ,CMPDCTL2_POS = 20
    ,CMPDCTL2_0 = 0x00000000 // Do nothing
    ,CMPDCTL2_1 = 0x00100000 // BPWM compare down point output Low
    ,CMPDCTL2_2 = 0x00200000 // BPWM compare down point output High
    ,CMPDCTL2_3 = 0x00300000 // BPWM compare down point output Toggle
    // BPWM Compare Down Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter down count to CMPDAT. (bits: 23-22)
    ,CMPDCTL3_MASK = 0x00C00000
    ,CMPDCTL3_POS = 22
    ,CMPDCTL3_0 = 0x00000000 // Do nothing
    ,CMPDCTL3_1 = 0x00400000 // BPWM compare down point output Low
    ,CMPDCTL3_2 = 0x00800000 // BPWM compare down point output High
    ,CMPDCTL3_3 = 0x00C00000 // BPWM compare down point output Toggle
    // BPWM Compare Down Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter down count to CMPDAT. (bits: 25-24)
    ,CMPDCTL4_MASK = 0x03000000
    ,CMPDCTL4_POS = 24
    ,CMPDCTL4_0 = 0x00000000 // Do nothing
    ,CMPDCTL4_1 = 0x01000000 // BPWM compare down point output Low
    ,CMPDCTL4_2 = 0x02000000 // BPWM compare down point output High
    ,CMPDCTL4_3 = 0x03000000 // BPWM compare down point output Toggle
    // BPWM Compare Down Point Control Each bit n controls the corresponding BPWM channel n. BPWM can control output level when BPWM counter down count to CMPDAT. (bits: 27-26)
    ,CMPDCTL5_MASK = 0x0C000000
    ,CMPDCTL5_POS = 26
    ,CMPDCTL5_0 = 0x00000000 // Do nothing
    ,CMPDCTL5_1 = 0x04000000 // BPWM compare down point output Low
    ,CMPDCTL5_2 = 0x08000000 // BPWM compare down point output High
    ,CMPDCTL5_3 = 0x0C000000 // BPWM compare down point output Toggle
    ,WGCTL1_MASK = 0x0FFF0FFF
    ;
  };
  // BPWM Mask Enable Register
  struct MSKEN : reg<ip_ver, base + 0xB8>
  {
    static constexpr typename MSKEN::type
    // BPWM Mask Enable Bits Each bit n controls the corresponding BPWM channel n. The BPWM output signal will be masked when this bit is enabled. The corresponding BPWM channel n will output MSKDATn (BPWM_MSK[5:0]) data. (bits: 0)
     MSKEN0_MASK = 0x00000001
    ,MSKEN0_POS = 0
    ,MSKEN0_0 = 0x00000000 // BPWM output signal is non-masked
    ,MSKEN0_1 = 0x00000001 // BPWM output signal is masked and output MSKDATn data
    // BPWM Mask Enable Bits Each bit n controls the corresponding BPWM channel n. The BPWM output signal will be masked when this bit is enabled. The corresponding BPWM channel n will output MSKDATn (BPWM_MSK[5:0]) data. (bits: 1)
    ,MSKEN1_MASK = 0x00000002
    ,MSKEN1_POS = 1
    ,MSKEN1_0 = 0x00000000 // BPWM output signal is non-masked
    ,MSKEN1_1 = 0x00000002 // BPWM output signal is masked and output MSKDATn data
    // BPWM Mask Enable Bits Each bit n controls the corresponding BPWM channel n. The BPWM output signal will be masked when this bit is enabled. The corresponding BPWM channel n will output MSKDATn (BPWM_MSK[5:0]) data. (bits: 2)
    ,MSKEN2_MASK = 0x00000004
    ,MSKEN2_POS = 2
    ,MSKEN2_0 = 0x00000000 // BPWM output signal is non-masked
    ,MSKEN2_1 = 0x00000004 // BPWM output signal is masked and output MSKDATn data
    // BPWM Mask Enable Bits Each bit n controls the corresponding BPWM channel n. The BPWM output signal will be masked when this bit is enabled. The corresponding BPWM channel n will output MSKDATn (BPWM_MSK[5:0]) data. (bits: 3)
    ,MSKEN3_MASK = 0x00000008
    ,MSKEN3_POS = 3
    ,MSKEN3_0 = 0x00000000 // BPWM output signal is non-masked
    ,MSKEN3_1 = 0x00000008 // BPWM output signal is masked and output MSKDATn data
    // BPWM Mask Enable Bits Each bit n controls the corresponding BPWM channel n. The BPWM output signal will be masked when this bit is enabled. The corresponding BPWM channel n will output MSKDATn (BPWM_MSK[5:0]) data. (bits: 4)
    ,MSKEN4_MASK = 0x00000010
    ,MSKEN4_POS = 4
    ,MSKEN4_0 = 0x00000000 // BPWM output signal is non-masked
    ,MSKEN4_1 = 0x00000010 // BPWM output signal is masked and output MSKDATn data
    // BPWM Mask Enable Bits Each bit n controls the corresponding BPWM channel n. The BPWM output signal will be masked when this bit is enabled. The corresponding BPWM channel n will output MSKDATn (BPWM_MSK[5:0]) data. (bits: 5)
    ,MSKEN5_MASK = 0x00000020
    ,MSKEN5_POS = 5
    ,MSKEN5_0 = 0x00000000 // BPWM output signal is non-masked
    ,MSKEN5_1 = 0x00000020 // BPWM output signal is masked and output MSKDATn data
    ,MSKEN_MASK = 0x0000003F
    ;
  };
  // BPWM Mask Data Register
  struct MSK : reg<ip_ver, base + 0xBC>
  {
    static constexpr typename MSK::type
    // BPWM Mask Data Bit This data bit control the state of BPWMn output pin, if corresponding mask function is enabled. Each bit n controls the corresponding BPWM channel n. (bits: 0)
     MSKDAT0_MASK = 0x00000001
    ,MSKDAT0_POS = 0
    ,MSKDAT0_0 = 0x00000000 // Output logic low to BPWMn
    ,MSKDAT0_1 = 0x00000001 // Output logic high to BPWMn
    // BPWM Mask Data Bit This data bit control the state of BPWMn output pin, if corresponding mask function is enabled. Each bit n controls the corresponding BPWM channel n. (bits: 1)
    ,MSKDAT1_MASK = 0x00000002
    ,MSKDAT1_POS = 1
    ,MSKDAT1_0 = 0x00000000 // Output logic low to BPWMn
    ,MSKDAT1_1 = 0x00000002 // Output logic high to BPWMn
    // BPWM Mask Data Bit This data bit control the state of BPWMn output pin, if corresponding mask function is enabled. Each bit n controls the corresponding BPWM channel n. (bits: 2)
    ,MSKDAT2_MASK = 0x00000004
    ,MSKDAT2_POS = 2
    ,MSKDAT2_0 = 0x00000000 // Output logic low to BPWMn
    ,MSKDAT2_1 = 0x00000004 // Output logic high to BPWMn
    // BPWM Mask Data Bit This data bit control the state of BPWMn output pin, if corresponding mask function is enabled. Each bit n controls the corresponding BPWM channel n. (bits: 3)
    ,MSKDAT3_MASK = 0x00000008
    ,MSKDAT3_POS = 3
    ,MSKDAT3_0 = 0x00000000 // Output logic low to BPWMn
    ,MSKDAT3_1 = 0x00000008 // Output logic high to BPWMn
    // BPWM Mask Data Bit This data bit control the state of BPWMn output pin, if corresponding mask function is enabled. Each bit n controls the corresponding BPWM channel n. (bits: 4)
    ,MSKDAT4_MASK = 0x00000010
    ,MSKDAT4_POS = 4
    ,MSKDAT4_0 = 0x00000000 // Output logic low to BPWMn
    ,MSKDAT4_1 = 0x00000010 // Output logic high to BPWMn
    // BPWM Mask Data Bit This data bit control the state of BPWMn output pin, if corresponding mask function is enabled. Each bit n controls the corresponding BPWM channel n. (bits: 5)
    ,MSKDAT5_MASK = 0x00000020
    ,MSKDAT5_POS = 5
    ,MSKDAT5_0 = 0x00000000 // Output logic low to BPWMn
    ,MSKDAT5_1 = 0x00000020 // Output logic high to BPWMn
    ,MSK_MASK = 0x0000003F
    ;
  };
  // BPWM Pin Polar Inverse Register
  struct POLCTL : reg<ip_ver, base + 0xD4>
  {
    static constexpr typename POLCTL::type
    // BPWM PIN Polar Inverse Control The register controls polarity state of BPWM output. Each bit n controls the corresponding BPWM channel n. (bits: 0)
     PINV0_MASK = 0x00000001
    ,PINV0_POS = 0
    ,PINV0_0 = 0x00000000 // BPWM output polar inverse Disabled
    ,PINV0_1 = 0x00000001 // BPWM output polar inverse Enabled
    // BPWM PIN Polar Inverse Control The register controls polarity state of BPWM output. Each bit n controls the corresponding BPWM channel n. (bits: 1)
    ,PINV1_MASK = 0x00000002
    ,PINV1_POS = 1
    ,PINV1_0 = 0x00000000 // BPWM output polar inverse Disabled
    ,PINV1_1 = 0x00000002 // BPWM output polar inverse Enabled
    // BPWM PIN Polar Inverse Control The register controls polarity state of BPWM output. Each bit n controls the corresponding BPWM channel n. (bits: 2)
    ,PINV2_MASK = 0x00000004
    ,PINV2_POS = 2
    ,PINV2_0 = 0x00000000 // BPWM output polar inverse Disabled
    ,PINV2_1 = 0x00000004 // BPWM output polar inverse Enabled
    // BPWM PIN Polar Inverse Control The register controls polarity state of BPWM output. Each bit n controls the corresponding BPWM channel n. (bits: 3)
    ,PINV3_MASK = 0x00000008
    ,PINV3_POS = 3
    ,PINV3_0 = 0x00000000 // BPWM output polar inverse Disabled
    ,PINV3_1 = 0x00000008 // BPWM output polar inverse Enabled
    // BPWM PIN Polar Inverse Control The register controls polarity state of BPWM output. Each bit n controls the corresponding BPWM channel n. (bits: 4)
    ,PINV4_MASK = 0x00000010
    ,PINV4_POS = 4
    ,PINV4_0 = 0x00000000 // BPWM output polar inverse Disabled
    ,PINV4_1 = 0x00000010 // BPWM output polar inverse Enabled
    // BPWM PIN Polar Inverse Control The register controls polarity state of BPWM output. Each bit n controls the corresponding BPWM channel n. (bits: 5)
    ,PINV5_MASK = 0x00000020
    ,PINV5_POS = 5
    ,PINV5_0 = 0x00000000 // BPWM output polar inverse Disabled
    ,PINV5_1 = 0x00000020 // BPWM output polar inverse Enabled
    ,POLCTL_MASK = 0x0000003F
    ;
  };
  // BPWM Output Enable Register
  struct POEN : reg<ip_ver, base + 0xD8>
  {
    static constexpr typename POEN::type
    // BPWM Pin Output Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 0)
     POEN0_MASK = 0x00000001
    ,POEN0_POS = 0
    ,POEN0_0 = 0x00000000 // BPWM pin at tri-state
    ,POEN0_1 = 0x00000001 // BPWM pin in output mode
    // BPWM Pin Output Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 1)
    ,POEN1_MASK = 0x00000002
    ,POEN1_POS = 1
    ,POEN1_0 = 0x00000000 // BPWM pin at tri-state
    ,POEN1_1 = 0x00000002 // BPWM pin in output mode
    // BPWM Pin Output Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 2)
    ,POEN2_MASK = 0x00000004
    ,POEN2_POS = 2
    ,POEN2_0 = 0x00000000 // BPWM pin at tri-state
    ,POEN2_1 = 0x00000004 // BPWM pin in output mode
    // BPWM Pin Output Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 3)
    ,POEN3_MASK = 0x00000008
    ,POEN3_POS = 3
    ,POEN3_0 = 0x00000000 // BPWM pin at tri-state
    ,POEN3_1 = 0x00000008 // BPWM pin in output mode
    // BPWM Pin Output Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 4)
    ,POEN4_MASK = 0x00000010
    ,POEN4_POS = 4
    ,POEN4_0 = 0x00000000 // BPWM pin at tri-state
    ,POEN4_1 = 0x00000010 // BPWM pin in output mode
    // BPWM Pin Output Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 5)
    ,POEN5_MASK = 0x00000020
    ,POEN5_POS = 5
    ,POEN5_0 = 0x00000000 // BPWM pin at tri-state
    ,POEN5_1 = 0x00000020 // BPWM pin in output mode
    ,POEN_MASK = 0x0000003F
    ;
  };
  // BPWM Interrupt Enable Register
  struct INTEN : reg<ip_ver, base + 0xE0>
  {
    static constexpr typename INTEN::type
    // BPWM Zero Point Interrupt 0 Enable Bit (bits: 0)
     ZIEN0_MASK = 0x00000001
    ,ZIEN0_POS = 0
    ,ZIEN0_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN0_1 = 0x00000001 // Zero point interrupt Enabled
    // BPWM Period Point Interrupt 0 Enable Bit Note: When up-down counter type period point means center point. (bits: 8)
    ,PIEN0_MASK = 0x00000100
    ,PIEN0_POS = 8
    ,PIEN0_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN0_1 = 0x00000100 // Period point interrupt Enabled
    // BPWM Compare Up Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 16)
    ,CMPUIEN0_MASK = 0x00010000
    ,CMPUIEN0_POS = 16
    ,CMPUIEN0_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN0_1 = 0x00010000 // Compare up count interrupt Enabled
    // BPWM Compare Up Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 17)
    ,CMPUIEN1_MASK = 0x00020000
    ,CMPUIEN1_POS = 17
    ,CMPUIEN1_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN1_1 = 0x00020000 // Compare up count interrupt Enabled
    // BPWM Compare Up Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 18)
    ,CMPUIEN2_MASK = 0x00040000
    ,CMPUIEN2_POS = 18
    ,CMPUIEN2_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN2_1 = 0x00040000 // Compare up count interrupt Enabled
    // BPWM Compare Up Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 19)
    ,CMPUIEN3_MASK = 0x00080000
    ,CMPUIEN3_POS = 19
    ,CMPUIEN3_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN3_1 = 0x00080000 // Compare up count interrupt Enabled
    // BPWM Compare Up Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 20)
    ,CMPUIEN4_MASK = 0x00100000
    ,CMPUIEN4_POS = 20
    ,CMPUIEN4_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN4_1 = 0x00100000 // Compare up count interrupt Enabled
    // BPWM Compare Up Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 21)
    ,CMPUIEN5_MASK = 0x00200000
    ,CMPUIEN5_POS = 21
    ,CMPUIEN5_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN5_1 = 0x00200000 // Compare up count interrupt Enabled
    // BPWM Compare Down Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 24)
    ,CMPDIEN0_MASK = 0x01000000
    ,CMPDIEN0_POS = 24
    ,CMPDIEN0_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN0_1 = 0x01000000 // Compare down count interrupt Enabled
    // BPWM Compare Down Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 25)
    ,CMPDIEN1_MASK = 0x02000000
    ,CMPDIEN1_POS = 25
    ,CMPDIEN1_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN1_1 = 0x02000000 // Compare down count interrupt Enabled
    // BPWM Compare Down Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 26)
    ,CMPDIEN2_MASK = 0x04000000
    ,CMPDIEN2_POS = 26
    ,CMPDIEN2_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN2_1 = 0x04000000 // Compare down count interrupt Enabled
    // BPWM Compare Down Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 27)
    ,CMPDIEN3_MASK = 0x08000000
    ,CMPDIEN3_POS = 27
    ,CMPDIEN3_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN3_1 = 0x08000000 // Compare down count interrupt Enabled
    // BPWM Compare Down Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 28)
    ,CMPDIEN4_MASK = 0x10000000
    ,CMPDIEN4_POS = 28
    ,CMPDIEN4_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN4_1 = 0x10000000 // Compare down count interrupt Enabled
    // BPWM Compare Down Count Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 29)
    ,CMPDIEN5_MASK = 0x20000000
    ,CMPDIEN5_POS = 29
    ,CMPDIEN5_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN5_1 = 0x20000000 // Compare down count interrupt Enabled
    ,INTEN_MASK = 0x3F3F0101
    ;
  };
  // BPWM Interrupt Flag Register
  struct INTSTS : reg<ip_ver, base + 0xE8>
  {
    static constexpr typename INTSTS::type
    // BPWM Zero Point Interrupt Flag 0 This bit is set by hardware when BPWM_CH0 counter reaches 0, software can write 1 to clear this bit to 0. (bits: 0)
     ZIF0_MASK = 0x00000001
    ,ZIF0_POS = 0
    ,ZIF0 = 0x00000001
    // BPWM Period Point Interrupt Flag 0 This bit is set by hardware when BPWM_CH0 counter reaches BPWM_PERIOD0, software can write 1 to clear this bit to 0. (bits: 8)
    ,PIF0_MASK = 0x00000100
    ,PIF0_POS = 8
    ,PIF0 = 0x00000100
    // BPWM Compare Up Count Interrupt Flag Flag is set by hardware when BPWM counter up count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Each bit n controls the corresponding BPWM channel n. Note: If CMPDAT equal to PERIOD, this flag is not working in up counter type selection. (bits: 16)
    ,CMPUIF0_MASK = 0x00010000
    ,CMPUIF0_POS = 16
    ,CMPUIF0 = 0x00010000
    // BPWM Compare Up Count Interrupt Flag Flag is set by hardware when BPWM counter up count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Each bit n controls the corresponding BPWM channel n. Note: If CMPDAT equal to PERIOD, this flag is not working in up counter type selection. (bits: 17)
    ,CMPUIF1_MASK = 0x00020000
    ,CMPUIF1_POS = 17
    ,CMPUIF1 = 0x00020000
    // BPWM Compare Up Count Interrupt Flag Flag is set by hardware when BPWM counter up count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Each bit n controls the corresponding BPWM channel n. Note: If CMPDAT equal to PERIOD, this flag is not working in up counter type selection. (bits: 18)
    ,CMPUIF2_MASK = 0x00040000
    ,CMPUIF2_POS = 18
    ,CMPUIF2 = 0x00040000
    // BPWM Compare Up Count Interrupt Flag Flag is set by hardware when BPWM counter up count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Each bit n controls the corresponding BPWM channel n. Note: If CMPDAT equal to PERIOD, this flag is not working in up counter type selection. (bits: 19)
    ,CMPUIF3_MASK = 0x00080000
    ,CMPUIF3_POS = 19
    ,CMPUIF3 = 0x00080000
    // BPWM Compare Up Count Interrupt Flag Flag is set by hardware when BPWM counter up count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Each bit n controls the corresponding BPWM channel n. Note: If CMPDAT equal to PERIOD, this flag is not working in up counter type selection. (bits: 20)
    ,CMPUIF4_MASK = 0x00100000
    ,CMPUIF4_POS = 20
    ,CMPUIF4 = 0x00100000
    // BPWM Compare Up Count Interrupt Flag Flag is set by hardware when BPWM counter up count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Each bit n controls the corresponding BPWM channel n. Note: If CMPDAT equal to PERIOD, this flag is not working in up counter type selection. (bits: 21)
    ,CMPUIF5_MASK = 0x00200000
    ,CMPUIF5_POS = 21
    ,CMPUIF5 = 0x00200000
    // BPWM Compare Down Count Interrupt Flag Each bit n controls the corresponding BPWM channel n. Flag is set by hardware when BPWM counter down count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: If CMPDAT equal to PERIOD, this flag is not working in down counter type selection. (bits: 24)
    ,CMPDIF0_MASK = 0x01000000
    ,CMPDIF0_POS = 24
    ,CMPDIF0 = 0x01000000
    // BPWM Compare Down Count Interrupt Flag Each bit n controls the corresponding BPWM channel n. Flag is set by hardware when BPWM counter down count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: If CMPDAT equal to PERIOD, this flag is not working in down counter type selection. (bits: 25)
    ,CMPDIF1_MASK = 0x02000000
    ,CMPDIF1_POS = 25
    ,CMPDIF1 = 0x02000000
    // BPWM Compare Down Count Interrupt Flag Each bit n controls the corresponding BPWM channel n. Flag is set by hardware when BPWM counter down count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: If CMPDAT equal to PERIOD, this flag is not working in down counter type selection. (bits: 26)
    ,CMPDIF2_MASK = 0x04000000
    ,CMPDIF2_POS = 26
    ,CMPDIF2 = 0x04000000
    // BPWM Compare Down Count Interrupt Flag Each bit n controls the corresponding BPWM channel n. Flag is set by hardware when BPWM counter down count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: If CMPDAT equal to PERIOD, this flag is not working in down counter type selection. (bits: 27)
    ,CMPDIF3_MASK = 0x08000000
    ,CMPDIF3_POS = 27
    ,CMPDIF3 = 0x08000000
    // BPWM Compare Down Count Interrupt Flag Each bit n controls the corresponding BPWM channel n. Flag is set by hardware when BPWM counter down count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: If CMPDAT equal to PERIOD, this flag is not working in down counter type selection. (bits: 28)
    ,CMPDIF4_MASK = 0x10000000
    ,CMPDIF4_POS = 28
    ,CMPDIF4 = 0x10000000
    // BPWM Compare Down Count Interrupt Flag Each bit n controls the corresponding BPWM channel n. Flag is set by hardware when BPWM counter down count and reaches BPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: If CMPDAT equal to PERIOD, this flag is not working in down counter type selection. (bits: 29)
    ,CMPDIF5_MASK = 0x20000000
    ,CMPDIF5_POS = 29
    ,CMPDIF5 = 0x20000000
    ,INTSTS_MASK = 0x3F3F0101
    ;
  };
  // BPWM Trigger EADC0/1 Source Select Register 0
  struct EADCTS0 : reg<ip_ver, base + 0xF8>
  {
    static constexpr typename EADCTS0::type
    // BPWM_CH0 Trigger EADC0/1 Source Select Others reserved (bits: 3-0)
     TRGSEL0_MASK = 0x0000000F
    ,TRGSEL0_POS = 0
    ,TRGSEL0_0 = 0x00000000 // BPWM_CH0 zero point
    ,TRGSEL0_1 = 0x00000001 // BPWM_CH0 period point
    ,TRGSEL0_2 = 0x00000002 // BPWM_CH0 zero or period point
    ,TRGSEL0_3 = 0x00000003 // BPWM_CH0 up-count CMPDAT point
    ,TRGSEL0_4 = 0x00000004 // BPWM_CH0 down-count CMPDAT point
    ,TRGSEL0_5 = 0x00000005 // Reserved.
    ,TRGSEL0_6 = 0x00000006 // Reserved.
    ,TRGSEL0_7 = 0x00000007 // Reserved.
    ,TRGSEL0_8 = 0x00000008 // BPWM_CH1 up-count CMPDAT point
    ,TRGSEL0_9 = 0x00000009 // BPWM_CH1 down-count CMPDAT point
    // BPWM_CH0 Trigger EADC0/1 Enable Bit (bits: 7)
    ,TRGEN0_MASK = 0x00000080
    ,TRGEN0_POS = 7
    ,TRGEN0 = 0x00000080
    // BPWM_CH1 Trigger EADC0/1 Source Select Others reserved (bits: 11-8)
    ,TRGSEL1_MASK = 0x00000F00
    ,TRGSEL1_POS = 8
    ,TRGSEL1_0 = 0x00000000 // BPWM_CH0 zero point
    ,TRGSEL1_1 = 0x00000100 // BPWM_CH0 period point
    ,TRGSEL1_2 = 0x00000200 // BPWM_CH0 zero or period point
    ,TRGSEL1_3 = 0x00000300 // BPWM_CH0 up-count CMPDAT point
    ,TRGSEL1_4 = 0x00000400 // BPWM_CH0 down-count CMPDAT point
    ,TRGSEL1_5 = 0x00000500 // Reserved.
    ,TRGSEL1_6 = 0x00000600 // Reserved.
    ,TRGSEL1_7 = 0x00000700 // Reserved.
    ,TRGSEL1_8 = 0x00000800 // BPWM_CH1 up-count CMPDAT point
    ,TRGSEL1_9 = 0x00000900 // BPWM_CH1 down-count CMPDAT point
    // BPWM_CH1 Trigger EADC0/1 Enable Bit (bits: 15)
    ,TRGEN1_MASK = 0x00008000
    ,TRGEN1_POS = 15
    ,TRGEN1 = 0x00008000
    // BPWM_CH2 Trigger EADC0/1 Source Select Others reserved (bits: 19-16)
    ,TRGSEL2_MASK = 0x000F0000
    ,TRGSEL2_POS = 16
    ,TRGSEL2_0 = 0x00000000 // BPWM_CH2 zero point
    ,TRGSEL2_1 = 0x00010000 // BPWM_CH2 period point
    ,TRGSEL2_2 = 0x00020000 // BPWM_CH2 zero or period point
    ,TRGSEL2_3 = 0x00030000 // BPWM_CH2 up-count CMPDAT point
    ,TRGSEL2_4 = 0x00040000 // BPWM_CH2 down-count CMPDAT point
    ,TRGSEL2_5 = 0x00050000 // Reserved.
    ,TRGSEL2_6 = 0x00060000 // Reserved.
    ,TRGSEL2_7 = 0x00070000 // Reserved.
    ,TRGSEL2_8 = 0x00080000 // BPWM_CH3 up-count CMPDAT point
    ,TRGSEL2_9 = 0x00090000 // BPWM_CH3 down-count CMPDAT point
    // BPWM_CH2 Trigger EADC0/1 Enable Bit (bits: 23)
    ,TRGEN2_MASK = 0x00800000
    ,TRGEN2_POS = 23
    ,TRGEN2 = 0x00800000
    // BPWM_CH3 Trigger EADC0/1 Source Select Others reserved. (bits: 27-24)
    ,TRGSEL3_MASK = 0x0F000000
    ,TRGSEL3_POS = 24
    ,TRGSEL3_0 = 0x00000000 // BPWM_CH2 zero point
    ,TRGSEL3_1 = 0x01000000 // BPWM_CH2 period point
    ,TRGSEL3_2 = 0x02000000 // BPWM_CH2 zero or period point
    ,TRGSEL3_3 = 0x03000000 // BPWM_CH2 up-count CMPDAT point
    ,TRGSEL3_4 = 0x04000000 // BPWM_CH2 down-count CMPDAT point
    ,TRGSEL3_5 = 0x05000000 // Reserved.
    ,TRGSEL3_6 = 0x06000000 // Reserved.
    ,TRGSEL3_7 = 0x07000000 // Reserved.
    ,TRGSEL3_8 = 0x08000000 // BPWM_CH3 up-count CMPDAT point
    ,TRGSEL3_9 = 0x09000000 // BPWM_CH3 down-count CMPDAT point
    // BPWM_CH3 Trigger EADC0/1 Enable Bit (bits: 31)
    ,TRGEN3_MASK = 0x80000000
    ,TRGEN3_POS = 31
    ,TRGEN3 = 0x80000000
    ,EADCTS0_MASK = 0x8F8F8F8F
    ;
  };
  // BPWM Trigger EADC0/1 Source Select Register 1
  struct EADCTS1 : reg<ip_ver, base + 0xFC>
  {
    static constexpr typename EADCTS1::type
    // BPWM_CH4 Trigger EADC0/1 Source Select Others reserved (bits: 3-0)
     TRGSEL4_MASK = 0x0000000F
    ,TRGSEL4_POS = 0
    ,TRGSEL4_0 = 0x00000000 // BPWM_CH4 zero point
    ,TRGSEL4_1 = 0x00000001 // BPWM_CH4 period point
    ,TRGSEL4_2 = 0x00000002 // BPWM_CH4 zero or period point
    ,TRGSEL4_3 = 0x00000003 // BPWM_CH4 up-count CMPDAT point
    ,TRGSEL4_4 = 0x00000004 // BPWM_CH4 down-count CMPDAT point
    ,TRGSEL4_5 = 0x00000005 // Reserved.
    ,TRGSEL4_6 = 0x00000006 // Reserved.
    ,TRGSEL4_7 = 0x00000007 // Reserved.
    ,TRGSEL4_8 = 0x00000008 // BPWM_CH5 up-count CMPDAT point
    ,TRGSEL4_9 = 0x00000009 // BPWM_CH5 down-count CMPDAT point
    // BPWM_CH4 Trigger EADC0/1 Enable Bit (bits: 7)
    ,TRGEN4_MASK = 0x00000080
    ,TRGEN4_POS = 7
    ,TRGEN4 = 0x00000080
    // BPWM_CH5 Trigger EADC0/1 Source Select Others reserved (bits: 11-8)
    ,TRGSEL5_MASK = 0x00000F00
    ,TRGSEL5_POS = 8
    ,TRGSEL5_0 = 0x00000000 // BPWM_CH4 zero point
    ,TRGSEL5_1 = 0x00000100 // BPWM_CH4 period point
    ,TRGSEL5_2 = 0x00000200 // BPWM_CH4 zero or period point
    ,TRGSEL5_3 = 0x00000300 // BPWM_CH4 up-count CMPDAT point
    ,TRGSEL5_4 = 0x00000400 // BPWM_CH4 down-count CMPDAT point
    ,TRGSEL5_5 = 0x00000500 // Reserved.
    ,TRGSEL5_6 = 0x00000600 // Reserved.
    ,TRGSEL5_7 = 0x00000700 // Reserved.
    ,TRGSEL5_8 = 0x00000800 // BPWM_CH5 up-count CMPDAT point
    ,TRGSEL5_9 = 0x00000900 // BPWM_CH5 down-count CMPDAT point
    // BPWM_CH5 Trigger EADC0/1 Enable Bit (bits: 15)
    ,TRGEN5_MASK = 0x00008000
    ,TRGEN5_POS = 15
    ,TRGEN5 = 0x00008000
    ,EADCTS1_MASK = 0x00008F8F
    ;
  };
  // BPWM Synchronous Start Control Register
  struct SSCTL : reg<ip_ver, base + 0x110>
  {
    static constexpr typename SSCTL::type
    // BPWM Synchronous Start Function 0 Enable Bit When synchronous start function is enabled, the BPWM_CH0 counter enable bit (CNTEN0) can be enabled by writing BPWM synchronous start trigger bit (CNTSEN). (bits: 0)
     SSEN0_MASK = 0x00000001
    ,SSEN0_POS = 0
    ,SSEN0_0 = 0x00000000 // BPWM synchronous start function Disabled
    ,SSEN0_1 = 0x00000001 // BPWM synchronous start function Enabled
    // BPWM Synchronous Start Source Select (bits: 9-8)
    ,SSRC_MASK = 0x00000300
    ,SSRC_POS = 8
    ,SSRC_0 = 0x00000000 // Synchronous start source come from PWM0
    ,SSRC_1 = 0x00000100 // Synchronous start source come from PWM1
    ,SSRC_2 = 0x00000200 // Synchronous start source come from BPWM0
    ,SSRC_3 = 0x00000300 // Synchronous start source come from BPWM1
    ,SSCTL_MASK = 0x00000301
    ;
  };
  // BPWM Synchronous Start Trigger Register
  struct SSTRG : reg<ip_ver, base + 0x114>
  {
    static constexpr typename SSTRG::type
    // BPWM Counter Synchronous Start Enable Bit(Write Only) BPMW counter synchronous enable function is used to make PWM or BPWM channels start counting at the same time. Writing this bit to 1 will also set the counter enable bit if correlated BPWM channel counter synchronous start function is enabled. (bits: 0)
     CNTSEN_MASK = 0x00000001
    ,CNTSEN_POS = 0
    ,CNTSEN = 0x00000001
    ,SSTRG_MASK = 0x00000001
    ;
  };
  // BPWM Status Register
  struct STATUS : reg<ip_ver, base + 0x120>
  {
    static constexpr typename STATUS::type
    // Time-base Counter 0 Equal to 0xFFFF Latched Flag (bits: 0)
     CNTMAXF0_MASK = 0x00000001
    ,CNTMAXF0_POS = 0
    ,CNTMAXF0_0 = 0x00000000 // The time-base counter never reached its maximum value 0xFFFF
    ,CNTMAXF0_1 = 0x00000001 // The time-base counter reached its maximum value. Software can write 1 to clear this bit
    // EADC0 EADC1 Start of Conversion Status Each bit n controls the corresponding BPWM channel n. (bits: 16)
    ,EADCTRG0_MASK = 0x00010000
    ,EADCTRG0_POS = 16
    ,EADCTRG0_0 = 0x00000000 // No EADC0/1 start of conversion trigger event has occurred
    ,EADCTRG0_1 = 0x00010000 // An EADC0/1 start of conversion trigger event has occurred. Software can write 1 to clear this bit
    // EADC0 EADC1 Start of Conversion Status Each bit n controls the corresponding BPWM channel n. (bits: 17)
    ,EADCTRG1_MASK = 0x00020000
    ,EADCTRG1_POS = 17
    ,EADCTRG1_0 = 0x00000000 // No EADC0/1 start of conversion trigger event has occurred
    ,EADCTRG1_1 = 0x00020000 // An EADC0/1 start of conversion trigger event has occurred. Software can write 1 to clear this bit
    // EADC0 EADC1 Start of Conversion Status Each bit n controls the corresponding BPWM channel n. (bits: 18)
    ,EADCTRG2_MASK = 0x00040000
    ,EADCTRG2_POS = 18
    ,EADCTRG2_0 = 0x00000000 // No EADC0/1 start of conversion trigger event has occurred
    ,EADCTRG2_1 = 0x00040000 // An EADC0/1 start of conversion trigger event has occurred. Software can write 1 to clear this bit
    // EADC0 EADC1 Start of Conversion Status Each bit n controls the corresponding BPWM channel n. (bits: 19)
    ,EADCTRG3_MASK = 0x00080000
    ,EADCTRG3_POS = 19
    ,EADCTRG3_0 = 0x00000000 // No EADC0/1 start of conversion trigger event has occurred
    ,EADCTRG3_1 = 0x00080000 // An EADC0/1 start of conversion trigger event has occurred. Software can write 1 to clear this bit
    // EADC0 EADC1 Start of Conversion Status Each bit n controls the corresponding BPWM channel n. (bits: 20)
    ,EADCTRG4_MASK = 0x00100000
    ,EADCTRG4_POS = 20
    ,EADCTRG4_0 = 0x00000000 // No EADC0/1 start of conversion trigger event has occurred
    ,EADCTRG4_1 = 0x00100000 // An EADC0/1 start of conversion trigger event has occurred. Software can write 1 to clear this bit
    // EADC0 EADC1 Start of Conversion Status Each bit n controls the corresponding BPWM channel n. (bits: 21)
    ,EADCTRG5_MASK = 0x00200000
    ,EADCTRG5_POS = 21
    ,EADCTRG5_0 = 0x00000000 // No EADC0/1 start of conversion trigger event has occurred
    ,EADCTRG5_1 = 0x00200000 // An EADC0/1 start of conversion trigger event has occurred. Software can write 1 to clear this bit
    ,STATUS_MASK = 0x003F0001
    ;
  };
  // BPWM Capture Input Enable Register
  struct CAPINEN : reg<ip_ver, base + 0x200>
  {
    static constexpr typename CAPINEN::type
    // Capture Input Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 0)
     CAPINEN0_MASK = 0x00000001
    ,CAPINEN0_POS = 0
    ,CAPINEN0_0 = 0x00000000 // BPWM Channel capture input path Disabled. The input of BPWM channel capture function is always regarded as 0
    ,CAPINEN0_1 = 0x00000001 // BPWM Channel capture input path Enabled. The input of BPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 1)
    ,CAPINEN1_MASK = 0x00000002
    ,CAPINEN1_POS = 1
    ,CAPINEN1_0 = 0x00000000 // BPWM Channel capture input path Disabled. The input of BPWM channel capture function is always regarded as 0
    ,CAPINEN1_1 = 0x00000002 // BPWM Channel capture input path Enabled. The input of BPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 2)
    ,CAPINEN2_MASK = 0x00000004
    ,CAPINEN2_POS = 2
    ,CAPINEN2_0 = 0x00000000 // BPWM Channel capture input path Disabled. The input of BPWM channel capture function is always regarded as 0
    ,CAPINEN2_1 = 0x00000004 // BPWM Channel capture input path Enabled. The input of BPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 3)
    ,CAPINEN3_MASK = 0x00000008
    ,CAPINEN3_POS = 3
    ,CAPINEN3_0 = 0x00000000 // BPWM Channel capture input path Disabled. The input of BPWM channel capture function is always regarded as 0
    ,CAPINEN3_1 = 0x00000008 // BPWM Channel capture input path Enabled. The input of BPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 4)
    ,CAPINEN4_MASK = 0x00000010
    ,CAPINEN4_POS = 4
    ,CAPINEN4_0 = 0x00000000 // BPWM Channel capture input path Disabled. The input of BPWM channel capture function is always regarded as 0
    ,CAPINEN4_1 = 0x00000010 // BPWM Channel capture input path Enabled. The input of BPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 5)
    ,CAPINEN5_MASK = 0x00000020
    ,CAPINEN5_POS = 5
    ,CAPINEN5_0 = 0x00000000 // BPWM Channel capture input path Disabled. The input of BPWM channel capture function is always regarded as 0
    ,CAPINEN5_1 = 0x00000020 // BPWM Channel capture input path Enabled. The input of BPWM channel capture function comes from correlative multifunction pin
    ,CAPINEN_MASK = 0x0000003F
    ;
  };
  // BPWM Capture Control Register
  struct CAPCTL : reg<ip_ver, base + 0x204>
  {
    static constexpr typename CAPCTL::type
    // Capture Function Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 0)
     CAPEN0_MASK = 0x00000001
    ,CAPEN0_POS = 0
    ,CAPEN0_0 = 0x00000000 // Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated
    ,CAPEN0_1 = 0x00000001 // Capture function Enabled. Capture latched the BPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 1)
    ,CAPEN1_MASK = 0x00000002
    ,CAPEN1_POS = 1
    ,CAPEN1_0 = 0x00000000 // Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated
    ,CAPEN1_1 = 0x00000002 // Capture function Enabled. Capture latched the BPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 2)
    ,CAPEN2_MASK = 0x00000004
    ,CAPEN2_POS = 2
    ,CAPEN2_0 = 0x00000000 // Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated
    ,CAPEN2_1 = 0x00000004 // Capture function Enabled. Capture latched the BPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 3)
    ,CAPEN3_MASK = 0x00000008
    ,CAPEN3_POS = 3
    ,CAPEN3_0 = 0x00000000 // Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated
    ,CAPEN3_1 = 0x00000008 // Capture function Enabled. Capture latched the BPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 4)
    ,CAPEN4_MASK = 0x00000010
    ,CAPEN4_POS = 4
    ,CAPEN4_0 = 0x00000000 // Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated
    ,CAPEN4_1 = 0x00000010 // Capture function Enabled. Capture latched the BPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 5)
    ,CAPEN5_MASK = 0x00000020
    ,CAPEN5_POS = 5
    ,CAPEN5_0 = 0x00000000 // Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated
    ,CAPEN5_1 = 0x00000020 // Capture function Enabled. Capture latched the BPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Inverter Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 8)
    ,CAPINV0_MASK = 0x00000100
    ,CAPINV0_POS = 8
    ,CAPINV0_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV0_1 = 0x00000100 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 9)
    ,CAPINV1_MASK = 0x00000200
    ,CAPINV1_POS = 9
    ,CAPINV1_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV1_1 = 0x00000200 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 10)
    ,CAPINV2_MASK = 0x00000400
    ,CAPINV2_POS = 10
    ,CAPINV2_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV2_1 = 0x00000400 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 11)
    ,CAPINV3_MASK = 0x00000800
    ,CAPINV3_POS = 11
    ,CAPINV3_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV3_1 = 0x00000800 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 12)
    ,CAPINV4_MASK = 0x00001000
    ,CAPINV4_POS = 12
    ,CAPINV4_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV4_1 = 0x00001000 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 13)
    ,CAPINV5_MASK = 0x00002000
    ,CAPINV5_POS = 13
    ,CAPINV5_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV5_1 = 0x00002000 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Rising Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 16)
    ,RCRLDEN0_MASK = 0x00010000
    ,RCRLDEN0_POS = 16
    ,RCRLDEN0_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN0_1 = 0x00010000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 17)
    ,RCRLDEN1_MASK = 0x00020000
    ,RCRLDEN1_POS = 17
    ,RCRLDEN1_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN1_1 = 0x00020000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 18)
    ,RCRLDEN2_MASK = 0x00040000
    ,RCRLDEN2_POS = 18
    ,RCRLDEN2_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN2_1 = 0x00040000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 19)
    ,RCRLDEN3_MASK = 0x00080000
    ,RCRLDEN3_POS = 19
    ,RCRLDEN3_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN3_1 = 0x00080000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 20)
    ,RCRLDEN4_MASK = 0x00100000
    ,RCRLDEN4_POS = 20
    ,RCRLDEN4_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN4_1 = 0x00100000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 21)
    ,RCRLDEN5_MASK = 0x00200000
    ,RCRLDEN5_POS = 21
    ,RCRLDEN5_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN5_1 = 0x00200000 // Rising capture reload counter Enabled
    // Falling Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 24)
    ,FCRLDEN0_MASK = 0x01000000
    ,FCRLDEN0_POS = 24
    ,FCRLDEN0_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN0_1 = 0x01000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 25)
    ,FCRLDEN1_MASK = 0x02000000
    ,FCRLDEN1_POS = 25
    ,FCRLDEN1_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN1_1 = 0x02000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 26)
    ,FCRLDEN2_MASK = 0x04000000
    ,FCRLDEN2_POS = 26
    ,FCRLDEN2_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN2_1 = 0x04000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 27)
    ,FCRLDEN3_MASK = 0x08000000
    ,FCRLDEN3_POS = 27
    ,FCRLDEN3_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN3_1 = 0x08000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 28)
    ,FCRLDEN4_MASK = 0x10000000
    ,FCRLDEN4_POS = 28
    ,FCRLDEN4_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN4_1 = 0x10000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 29)
    ,FCRLDEN5_MASK = 0x20000000
    ,FCRLDEN5_POS = 29
    ,FCRLDEN5_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN5_1 = 0x20000000 // Falling capture reload counter Enabled
    ,CAPCTL_MASK = 0x3F3F3F3F
    ;
  };
  // BPWM Capture Status Register
  struct CAPSTS : reg<ip_ver, base + 0x208>
  {
    static constexpr typename CAPSTS::type
    // Capture Rising Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CAPRIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPRIF. (bits: 0)
     CRIFOV0_MASK = 0x00000001
    ,CRIFOV0_POS = 0
    ,CRIFOV0 = 0x00000001
    // Capture Rising Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CAPRIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPRIF. (bits: 1)
    ,CRIFOV1_MASK = 0x00000002
    ,CRIFOV1_POS = 1
    ,CRIFOV1 = 0x00000002
    // Capture Rising Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CAPRIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPRIF. (bits: 2)
    ,CRIFOV2_MASK = 0x00000004
    ,CRIFOV2_POS = 2
    ,CRIFOV2 = 0x00000004
    // Capture Rising Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CAPRIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPRIF. (bits: 3)
    ,CRIFOV3_MASK = 0x00000008
    ,CRIFOV3_POS = 3
    ,CRIFOV3 = 0x00000008
    // Capture Rising Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CAPRIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPRIF. (bits: 4)
    ,CRIFOV4_MASK = 0x00000010
    ,CRIFOV4_POS = 4
    ,CRIFOV4 = 0x00000010
    // Capture Rising Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CAPRIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPRIF. (bits: 5)
    ,CRIFOV5_MASK = 0x00000020
    ,CRIFOV5_POS = 5
    ,CRIFOV5 = 0x00000020
    // Capture Falling Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CAPFIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPFIF. (bits: 8)
    ,CFIFOV0_MASK = 0x00000100
    ,CFIFOV0_POS = 8
    ,CFIFOV0 = 0x00000100
    // Capture Falling Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CAPFIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPFIF. (bits: 9)
    ,CFIFOV1_MASK = 0x00000200
    ,CFIFOV1_POS = 9
    ,CFIFOV1 = 0x00000200
    // Capture Falling Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CAPFIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPFIF. (bits: 10)
    ,CFIFOV2_MASK = 0x00000400
    ,CFIFOV2_POS = 10
    ,CFIFOV2 = 0x00000400
    // Capture Falling Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CAPFIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPFIF. (bits: 11)
    ,CFIFOV3_MASK = 0x00000800
    ,CFIFOV3_POS = 11
    ,CFIFOV3 = 0x00000800
    // Capture Falling Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CAPFIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPFIF. (bits: 12)
    ,CFIFOV4_MASK = 0x00001000
    ,CFIFOV4_POS = 12
    ,CFIFOV4 = 0x00001000
    // Capture Falling Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CAPFIF is 1. Each bit n controls the corresponding BPWM channel n. Note: This bit will be cleared automatically when user clear corresponding CAPFIF. (bits: 13)
    ,CFIFOV5_MASK = 0x00002000
    ,CFIFOV5_POS = 13
    ,CFIFOV5 = 0x00002000
    ,CAPSTS_MASK = 0x00003F3F
    ;
  };
  // BPWM Rising Capture Data Register 0
  struct RCAPDAT0 : reg<ip_ver, base + 0x20C>
  {
    static constexpr typename RCAPDAT0::type
    // BPWM Rising Capture Data (Read Only) When rising capture condition happened, the BPWM counter value will be saved in this register. (bits: 15-0)
     RCAPDAT_MASK = 0x0000FFFF
    ,RCAPDAT_POS = 0
    ,RCAPDAT0_MASK = 0x0000FFFF
    ;
  };
  // BPWM Falling Capture Data Register 0
  struct FCAPDAT0 : reg<ip_ver, base + 0x210>
  {
    static constexpr typename FCAPDAT0::type
    // BPWM Falling Capture Data (Read Only) When falling capture condition happened, the BPWM counter value will be saved in this register. (bits: 15-0)
     FCAPDAT_MASK = 0x0000FFFF
    ,FCAPDAT_POS = 0
    ,FCAPDAT0_MASK = 0x0000FFFF
    ;
  };
  // BPWM Rising Capture Data Register 1
  using RCAPDAT1 = reg<ip_ver, base + 0x214>;
  // BPWM Falling Capture Data Register 1
  using FCAPDAT1 = reg<ip_ver, base + 0x218>;
  // BPWM Rising Capture Data Register 2
  using RCAPDAT2 = reg<ip_ver, base + 0x21C>;
  // BPWM Falling Capture Data Register 2
  using FCAPDAT2 = reg<ip_ver, base + 0x220>;
  // BPWM Rising Capture Data Register 3
  using RCAPDAT3 = reg<ip_ver, base + 0x224>;
  // BPWM Falling Capture Data Register 3
  using FCAPDAT3 = reg<ip_ver, base + 0x228>;
  // BPWM Rising Capture Data Register 4
  using RCAPDAT4 = reg<ip_ver, base + 0x22C>;
  // BPWM Falling Capture Data Register 4
  using FCAPDAT4 = reg<ip_ver, base + 0x230>;
  // BPWM Rising Capture Data Register 5
  using RCAPDAT5 = reg<ip_ver, base + 0x234>;
  // BPWM Falling Capture Data Register 5
  using FCAPDAT5 = reg<ip_ver, base + 0x238>;
  // BPWM Capture Interrupt Enable Register
  struct CAPIEN : reg<ip_ver, base + 0x250>
  {
    static constexpr typename CAPIEN::type
    // BPWM Capture Rising Latch Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 5-0)
     CAPRIENN_MASK = 0x0000003F
    ,CAPRIENN_POS = 0
    ,CAPRIENN_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIENN_1 = 0x00000001 // Capture rising edge latch interrupt Enabled
    // BPWM Capture Falling Latch Interrupt Enable Bits Each bit n controls the corresponding BPWM channel n. (bits: 13-8)
    ,CAPFIENN_MASK = 0x00003F00
    ,CAPFIENN_POS = 8
    ,CAPFIENN_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIENN_1 = 0x00000100 // Capture falling edge latch interrupt Enabled
    ,CAPIEN_MASK = 0x00003F3F
    ;
  };
  // BPWM Capture Interrupt Flag Register
  struct CAPIF : reg<ip_ver, base + 0x254>
  {
    static constexpr typename CAPIF::type
    // BPWM Capture Rising Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 0)
     CAPRIF0_MASK = 0x00000001
    ,CAPRIF0_POS = 0
    ,CAPRIF0_0 = 0x00000000 // No capture rising latch condition happened
    ,CAPRIF0_1 = 0x00000001 // Capture rising latch condition happened, this flag will be set to high
    // BPWM Capture Rising Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 1)
    ,CAPRIF1_MASK = 0x00000002
    ,CAPRIF1_POS = 1
    ,CAPRIF1_0 = 0x00000000 // No capture rising latch condition happened
    ,CAPRIF1_1 = 0x00000002 // Capture rising latch condition happened, this flag will be set to high
    // BPWM Capture Rising Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 2)
    ,CAPRIF2_MASK = 0x00000004
    ,CAPRIF2_POS = 2
    ,CAPRIF2_0 = 0x00000000 // No capture rising latch condition happened
    ,CAPRIF2_1 = 0x00000004 // Capture rising latch condition happened, this flag will be set to high
    // BPWM Capture Rising Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 3)
    ,CAPRIF3_MASK = 0x00000008
    ,CAPRIF3_POS = 3
    ,CAPRIF3_0 = 0x00000000 // No capture rising latch condition happened
    ,CAPRIF3_1 = 0x00000008 // Capture rising latch condition happened, this flag will be set to high
    // BPWM Capture Rising Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 4)
    ,CAPRIF4_MASK = 0x00000010
    ,CAPRIF4_POS = 4
    ,CAPRIF4_0 = 0x00000000 // No capture rising latch condition happened
    ,CAPRIF4_1 = 0x00000010 // Capture rising latch condition happened, this flag will be set to high
    // BPWM Capture Rising Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 5)
    ,CAPRIF5_MASK = 0x00000020
    ,CAPRIF5_POS = 5
    ,CAPRIF5_0 = 0x00000000 // No capture rising latch condition happened
    ,CAPRIF5_1 = 0x00000020 // Capture rising latch condition happened, this flag will be set to high
    // BPWM Capture Falling Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 8)
    ,CAPFIF0_MASK = 0x00000100
    ,CAPFIF0_POS = 8
    ,CAPFIF0_0 = 0x00000000 // No capture falling latch condition happened
    ,CAPFIF0_1 = 0x00000100 // Capture falling latch condition happened, this flag will be set to high
    // BPWM Capture Falling Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 9)
    ,CAPFIF1_MASK = 0x00000200
    ,CAPFIF1_POS = 9
    ,CAPFIF1_0 = 0x00000000 // No capture falling latch condition happened
    ,CAPFIF1_1 = 0x00000200 // Capture falling latch condition happened, this flag will be set to high
    // BPWM Capture Falling Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 10)
    ,CAPFIF2_MASK = 0x00000400
    ,CAPFIF2_POS = 10
    ,CAPFIF2_0 = 0x00000000 // No capture falling latch condition happened
    ,CAPFIF2_1 = 0x00000400 // Capture falling latch condition happened, this flag will be set to high
    // BPWM Capture Falling Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 11)
    ,CAPFIF3_MASK = 0x00000800
    ,CAPFIF3_POS = 11
    ,CAPFIF3_0 = 0x00000000 // No capture falling latch condition happened
    ,CAPFIF3_1 = 0x00000800 // Capture falling latch condition happened, this flag will be set to high
    // BPWM Capture Falling Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 12)
    ,CAPFIF4_MASK = 0x00001000
    ,CAPFIF4_POS = 12
    ,CAPFIF4_0 = 0x00000000 // No capture falling latch condition happened
    ,CAPFIF4_1 = 0x00001000 // Capture falling latch condition happened, this flag will be set to high
    // BPWM Capture Falling Latch Interrupt Flag Each bit n controls the corresponding BPWM channel n. Note: This bit is cleared by writing 1 to it. (bits: 13)
    ,CAPFIF5_MASK = 0x00002000
    ,CAPFIF5_POS = 13
    ,CAPFIF5_0 = 0x00000000 // No capture falling latch condition happened
    ,CAPFIF5_1 = 0x00002000 // Capture falling latch condition happened, this flag will be set to high
    ,CAPIF_MASK = 0x00003F3F
    ;
  };
  // BPWM PERIOD Buffer
  struct PBUF : reg<ip_ver, base + 0x304>
  {
    static constexpr typename PBUF::type
    // BPWM Period Buffer (Read Only) Used as PERIOD active register. (bits: 15-0)
     PBUFVAL_MASK = 0x0000FFFF
    ,PBUFVAL_POS = 0
    ,PBUF_MASK = 0x0000FFFF
    ;
  };
  // BPWM CMPDAT 0 Buffer
  struct CMPBUF0 : reg<ip_ver, base + 0x31C>
  {
    static constexpr typename CMPBUF0::type
    // BPWM Comparator Buffer (Read Only) Used as CMP active register. (bits: 15-0)
     CMPBUF_MASK = 0x0000FFFF
    ,CMPBUF_POS = 0
    ,CMPBUF0_MASK = 0x0000FFFF
    ;
  };
  // BPWM CMPDAT 1 Buffer
  using CMPBUF1 = reg<ip_ver, base + 0x320>;
  // BPWM CMPDAT 2 Buffer
  using CMPBUF2 = reg<ip_ver, base + 0x324>;
  // BPWM CMPDAT 3 Buffer
  using CMPBUF3 = reg<ip_ver, base + 0x328>;
  // BPWM CMPDAT 4 Buffer
  using CMPBUF4 = reg<ip_ver, base + 0x32C>;
  // BPWM CMPDAT 5 Buffer
  using CMPBUF5 = reg<ip_ver, base + 0x330>;
}; // struct BPWM

} // namespace lmcu::device::ip::v1

