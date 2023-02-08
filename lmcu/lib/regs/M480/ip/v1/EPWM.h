/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// EPWM Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct EPWM
{
  static constexpr auto ip_ver = ip_version::_1;

  // EPWM Control Register 0
  struct CTL0 : reg<ip_ver, base + 0x0>
  {
    static constexpr typename CTL0::type
    // Center Re-load In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the center point of a period. (bits: 0)
     CTRLD0_MASK = 0x00000001
    ,CTRLD0_POS = 0
    ,CTRLD0 = 0x00000001
    // Center Re-load In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the center point of a period. (bits: 1)
    ,CTRLD1_MASK = 0x00000002
    ,CTRLD1_POS = 1
    ,CTRLD1 = 0x00000002
    // Center Re-load In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the center point of a period. (bits: 2)
    ,CTRLD2_MASK = 0x00000004
    ,CTRLD2_POS = 2
    ,CTRLD2 = 0x00000004
    // Center Re-load In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the center point of a period. (bits: 3)
    ,CTRLD3_MASK = 0x00000008
    ,CTRLD3_POS = 3
    ,CTRLD3 = 0x00000008
    // Center Re-load In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the center point of a period. (bits: 4)
    ,CTRLD4_MASK = 0x00000010
    ,CTRLD4_POS = 4
    ,CTRLD4 = 0x00000010
    // Center Re-load In up-down counter type, PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the center point of a period. (bits: 5)
    ,CTRLD5_MASK = 0x00000020
    ,CTRLD5_POS = 5
    ,CTRLD5 = 0x00000020
    // Window Load Enable Bits (bits: 8)
    ,WINLDEN0_MASK = 0x00000100
    ,WINLDEN0_POS = 8
    ,WINLDEN0_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,WINLDEN0_1 = 0x00000100 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point of each period when valid reload window is set. The valid reload window is set by software write 1 to EPWM_LOAD register and cleared by hardware after load success
    // Window Load Enable Bits (bits: 9)
    ,WINLDEN1_MASK = 0x00000200
    ,WINLDEN1_POS = 9
    ,WINLDEN1_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,WINLDEN1_1 = 0x00000200 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point of each period when valid reload window is set. The valid reload window is set by software write 1 to EPWM_LOAD register and cleared by hardware after load success
    // Window Load Enable Bits (bits: 10)
    ,WINLDEN2_MASK = 0x00000400
    ,WINLDEN2_POS = 10
    ,WINLDEN2_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,WINLDEN2_1 = 0x00000400 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point of each period when valid reload window is set. The valid reload window is set by software write 1 to EPWM_LOAD register and cleared by hardware after load success
    // Window Load Enable Bits (bits: 11)
    ,WINLDEN3_MASK = 0x00000800
    ,WINLDEN3_POS = 11
    ,WINLDEN3_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,WINLDEN3_1 = 0x00000800 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point of each period when valid reload window is set. The valid reload window is set by software write 1 to EPWM_LOAD register and cleared by hardware after load success
    // Window Load Enable Bits (bits: 12)
    ,WINLDEN4_MASK = 0x00001000
    ,WINLDEN4_POS = 12
    ,WINLDEN4_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,WINLDEN4_1 = 0x00001000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point of each period when valid reload window is set. The valid reload window is set by software write 1 to EPWM_LOAD register and cleared by hardware after load success
    // Window Load Enable Bits (bits: 13)
    ,WINLDEN5_MASK = 0x00002000
    ,WINLDEN5_POS = 13
    ,WINLDEN5_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,WINLDEN5_1 = 0x00002000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point of each period when valid reload window is set. The valid reload window is set by software write 1 to EPWM_LOAD register and cleared by hardware after load success
    // Immediately Load Enable Bits Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid. (bits: 16)
    ,IMMLDEN0_MASK = 0x00010000
    ,IMMLDEN0_POS = 16
    ,IMMLDEN0_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN0_1 = 0x00010000 // PERIOD/CMP will load to PBUF and CMPBUF immediately when software update PERIOD/CMP
    // Immediately Load Enable Bits Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid. (bits: 17)
    ,IMMLDEN1_MASK = 0x00020000
    ,IMMLDEN1_POS = 17
    ,IMMLDEN1_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN1_1 = 0x00020000 // PERIOD/CMP will load to PBUF and CMPBUF immediately when software update PERIOD/CMP
    // Immediately Load Enable Bits Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid. (bits: 18)
    ,IMMLDEN2_MASK = 0x00040000
    ,IMMLDEN2_POS = 18
    ,IMMLDEN2_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN2_1 = 0x00040000 // PERIOD/CMP will load to PBUF and CMPBUF immediately when software update PERIOD/CMP
    // Immediately Load Enable Bits Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid. (bits: 19)
    ,IMMLDEN3_MASK = 0x00080000
    ,IMMLDEN3_POS = 19
    ,IMMLDEN3_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN3_1 = 0x00080000 // PERIOD/CMP will load to PBUF and CMPBUF immediately when software update PERIOD/CMP
    // Immediately Load Enable Bits Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid. (bits: 20)
    ,IMMLDEN4_MASK = 0x00100000
    ,IMMLDEN4_POS = 20
    ,IMMLDEN4_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN4_1 = 0x00100000 // PERIOD/CMP will load to PBUF and CMPBUF immediately when software update PERIOD/CMP
    // Immediately Load Enable Bits Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid. (bits: 21)
    ,IMMLDEN5_MASK = 0x00200000
    ,IMMLDEN5_POS = 21
    ,IMMLDEN5_0 = 0x00000000 // PERIOD will load to PBUF at the end point of each period. CMP will load to CMPBUF at the end point or center point of each period by setting CTRLD bit
    ,IMMLDEN5_1 = 0x00200000 // PERIOD/CMP will load to PBUF and CMPBUF immediately when software update PERIOD/CMP
    // Group Function Enable Bit (bits: 24)
    ,GROUPEN_MASK = 0x01000000
    ,GROUPEN_POS = 24
    ,GROUPEN_0 = 0x00000000 // The output waveform of each EPWM channel are independent
    ,GROUPEN_1 = 0x01000000 // Unify the EPWM_CH2 and EPWM_CH4 to output the same waveform as EPWM_CH0 and unify the EPWM_CH3 and EPWM_CH5 to output the same waveform as EPWM_CH1
    // ICE Debug Mode Counter Halt (Write Protect) If counter halt is enabled, EPWM all counters will keep current value until exit ICE debug mode. Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 30)
    ,DBGHALT_MASK = 0x40000000
    ,DBGHALT_POS = 30
    ,DBGHALT_0 = 0x00000000 // ICE debug mode counter halt Disabled
    ,DBGHALT_1 = 0x40000000 // ICE debug mode counter halt Enabled
    // ICE Debug Mode Acknowledge Disable Bit (Write Protect) EPWM pin will keep output no matter ICE debug mode acknowledged or not. Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 31)
    ,DBGTRIOFF_MASK = 0x80000000
    ,DBGTRIOFF_POS = 31
    ,DBGTRIOFF_0 = 0x00000000 // ICE debug mode acknowledgement effects EPWM output
    ,DBGTRIOFF_1 = 0x80000000 // ICE debug mode acknowledgement disabled
    ,CTL0_MASK = 0xC13F3F3F
    ;
  };
  // EPWM Control Register 1
  struct CTL1 : reg<ip_ver, base + 0x4>
  {
    static constexpr typename CTL1::type
    // EPWM Counter Behavior Type (bits: 1-0)
     CNTTYPE0_MASK = 0x00000003
    ,CNTTYPE0_POS = 0
    ,CNTTYPE0_0 = 0x00000000 // Up counter type (supported in capture mode)
    ,CNTTYPE0_1 = 0x00000001 // Down count type (supported in capture mode)
    ,CNTTYPE0_2 = 0x00000002 // Up-down counter type
    ,CNTTYPE0_3 = 0x00000003 // Reserved.
    // EPWM Counter Behavior Type (bits: 3-2)
    ,CNTTYPE1_MASK = 0x0000000C
    ,CNTTYPE1_POS = 2
    ,CNTTYPE1_0 = 0x00000000 // Up counter type (supported in capture mode)
    ,CNTTYPE1_1 = 0x00000004 // Down count type (supported in capture mode)
    ,CNTTYPE1_2 = 0x00000008 // Up-down counter type
    ,CNTTYPE1_3 = 0x0000000C // Reserved.
    // EPWM Counter Behavior Type (bits: 5-4)
    ,CNTTYPE2_MASK = 0x00000030
    ,CNTTYPE2_POS = 4
    ,CNTTYPE2_0 = 0x00000000 // Up counter type (supported in capture mode)
    ,CNTTYPE2_1 = 0x00000010 // Down count type (supported in capture mode)
    ,CNTTYPE2_2 = 0x00000020 // Up-down counter type
    ,CNTTYPE2_3 = 0x00000030 // Reserved.
    // EPWM Counter Behavior Type (bits: 7-6)
    ,CNTTYPE3_MASK = 0x000000C0
    ,CNTTYPE3_POS = 6
    ,CNTTYPE3_0 = 0x00000000 // Up counter type (supported in capture mode)
    ,CNTTYPE3_1 = 0x00000040 // Down count type (supported in capture mode)
    ,CNTTYPE3_2 = 0x00000080 // Up-down counter type
    ,CNTTYPE3_3 = 0x000000C0 // Reserved.
    // EPWM Counter Behavior Type (bits: 9-8)
    ,CNTTYPE4_MASK = 0x00000300
    ,CNTTYPE4_POS = 8
    ,CNTTYPE4_0 = 0x00000000 // Up counter type (supported in capture mode)
    ,CNTTYPE4_1 = 0x00000100 // Down count type (supported in capture mode)
    ,CNTTYPE4_2 = 0x00000200 // Up-down counter type
    ,CNTTYPE4_3 = 0x00000300 // Reserved.
    // EPWM Counter Behavior Type (bits: 11-10)
    ,CNTTYPE5_MASK = 0x00000C00
    ,CNTTYPE5_POS = 10
    ,CNTTYPE5_0 = 0x00000000 // Up counter type (supported in capture mode)
    ,CNTTYPE5_1 = 0x00000400 // Down count type (supported in capture mode)
    ,CNTTYPE5_2 = 0x00000800 // Up-down counter type
    ,CNTTYPE5_3 = 0x00000C00 // Reserved.
    // EPWM Counter Mode (bits: 16)
    ,CNTMODE0_MASK = 0x00010000
    ,CNTMODE0_POS = 16
    ,CNTMODE0_0 = 0x00000000 // Auto-reload mode
    ,CNTMODE0_1 = 0x00010000 // One-shot mode
    // EPWM Counter Mode (bits: 17)
    ,CNTMODE1_MASK = 0x00020000
    ,CNTMODE1_POS = 17
    ,CNTMODE1_0 = 0x00000000 // Auto-reload mode
    ,CNTMODE1_1 = 0x00020000 // One-shot mode
    // EPWM Counter Mode (bits: 18)
    ,CNTMODE2_MASK = 0x00040000
    ,CNTMODE2_POS = 18
    ,CNTMODE2_0 = 0x00000000 // Auto-reload mode
    ,CNTMODE2_1 = 0x00040000 // One-shot mode
    // EPWM Counter Mode (bits: 19)
    ,CNTMODE3_MASK = 0x00080000
    ,CNTMODE3_POS = 19
    ,CNTMODE3_0 = 0x00000000 // Auto-reload mode
    ,CNTMODE3_1 = 0x00080000 // One-shot mode
    // EPWM Counter Mode (bits: 20)
    ,CNTMODE4_MASK = 0x00100000
    ,CNTMODE4_POS = 20
    ,CNTMODE4_0 = 0x00000000 // Auto-reload mode
    ,CNTMODE4_1 = 0x00100000 // One-shot mode
    // EPWM Counter Mode (bits: 21)
    ,CNTMODE5_MASK = 0x00200000
    ,CNTMODE5_POS = 21
    ,CNTMODE5_0 = 0x00000000 // Auto-reload mode
    ,CNTMODE5_1 = 0x00200000 // One-shot mode
    // EPWM Output Mode Each bit n controls the output mode of corresponding EPWM channel n. Note: When operating in group function, these bits must all set to the same mode. (bits: 24)
    ,OUTMODE0_MASK = 0x01000000
    ,OUTMODE0_POS = 24
    ,OUTMODE0_0 = 0x00000000 // EPWM independent mode
    ,OUTMODE0_1 = 0x01000000 // EPWM complementary mode
    // EPWM Output Mode Each bit n controls the output mode of corresponding EPWM channel n. Note: When operating in group function, these bits must all set to the same mode. (bits: 25)
    ,OUTMODE2_MASK = 0x02000000
    ,OUTMODE2_POS = 25
    ,OUTMODE2_0 = 0x00000000 // EPWM independent mode
    ,OUTMODE2_1 = 0x02000000 // EPWM complementary mode
    // EPWM Output Mode Each bit n controls the output mode of corresponding EPWM channel n. Note: When operating in group function, these bits must all set to the same mode. (bits: 26)
    ,OUTMODE4_MASK = 0x04000000
    ,OUTMODE4_POS = 26
    ,OUTMODE4_0 = 0x00000000 // EPWM independent mode
    ,OUTMODE4_1 = 0x04000000 // EPWM complementary mode
    ,CTL1_MASK = 0x073F0FFF
    ;
  };
  // EPWM Synchronization Register
  struct SYNC : reg<ip_ver, base + 0x8>
  {
    static constexpr typename SYNC::type
    // SYNC Phase Enable Bits (bits: 0)
     PHSEN0_MASK = 0x00000001
    ,PHSEN0_POS = 0
    ,PHSEN0_0 = 0x00000000 // EPWM counter disable to load PHS value
    ,PHSEN0_1 = 0x00000001 // EPWM counter enable to load PHS value
    // SYNC Phase Enable Bits (bits: 1)
    ,PHSEN2_MASK = 0x00000002
    ,PHSEN2_POS = 1
    ,PHSEN2_0 = 0x00000000 // EPWM counter disable to load PHS value
    ,PHSEN2_1 = 0x00000002 // EPWM counter enable to load PHS value
    // SYNC Phase Enable Bits (bits: 2)
    ,PHSEN4_MASK = 0x00000004
    ,PHSEN4_POS = 2
    ,PHSEN4_0 = 0x00000000 // EPWM counter disable to load PHS value
    ,PHSEN4_1 = 0x00000004 // EPWM counter enable to load PHS value
    // EPWM0_SYNC_IN Source Selection (bits: 9-8)
    ,SINSRC0_MASK = 0x00000300
    ,SINSRC0_POS = 8
    ,SINSRC0_0 = 0x00000000 // Synchronize source from SYNC_IN or SWSYNC
    ,SINSRC0_1 = 0x00000100 // Counter equal to 0
    ,SINSRC0_2 = 0x00000200 // Counter equal to EPWM_CMPDATm, m denotes 1, 3, 5
    ,SINSRC0_3 = 0x00000300 // SYNC_OUT will not be generated
    // EPWM0_SYNC_IN Source Selection (bits: 11-10)
    ,SINSRC2_MASK = 0x00000C00
    ,SINSRC2_POS = 10
    ,SINSRC2_0 = 0x00000000 // Synchronize source from SYNC_IN or SWSYNC
    ,SINSRC2_1 = 0x00000400 // Counter equal to 0
    ,SINSRC2_2 = 0x00000800 // Counter equal to EPWM_CMPDATm, m denotes 1, 3, 5
    ,SINSRC2_3 = 0x00000C00 // SYNC_OUT will not be generated
    // EPWM0_SYNC_IN Source Selection (bits: 13-12)
    ,SINSRC4_MASK = 0x00003000
    ,SINSRC4_POS = 12
    ,SINSRC4_0 = 0x00000000 // Synchronize source from SYNC_IN or SWSYNC
    ,SINSRC4_1 = 0x00001000 // Counter equal to 0
    ,SINSRC4_2 = 0x00002000 // Counter equal to EPWM_CMPDATm, m denotes 1, 3, 5
    ,SINSRC4_3 = 0x00003000 // SYNC_OUT will not be generated
    // EPWM0_SYNC_IN Noise Filter Enable Bits (bits: 16)
    ,SNFLTEN_MASK = 0x00010000
    ,SNFLTEN_POS = 16
    ,SNFLTEN_0 = 0x00000000 // Noise filter of input pin EPWM0_SYNC_IN Disabled
    ,SNFLTEN_1 = 0x00010000 // Noise filter of input pin EPWM0_SYNC_IN Enabled
    // SYNC Edge Detector Filter Clock Selection (bits: 19-17)
    ,SFLTCSEL_MASK = 0x000E0000
    ,SFLTCSEL_POS = 17
    ,SFLTCSEL_0 = 0x00000000 // Filter clock = HCLK
    ,SFLTCSEL_1 = 0x00020000 // Filter clock = HCLK/2
    ,SFLTCSEL_2 = 0x00040000 // Filter clock = HCLK/4
    ,SFLTCSEL_3 = 0x00060000 // Filter clock = HCLK/8
    ,SFLTCSEL_4 = 0x00080000 // Filter clock = HCLK/16
    ,SFLTCSEL_5 = 0x000A0000 // Filter clock = HCLK/32
    ,SFLTCSEL_6 = 0x000C0000 // Filter clock = HCLK/64
    ,SFLTCSEL_7 = 0x000E0000 // Filter clock = HCLK/128
    // SYNC Edge Detector Filter Count The register bits control the counter number of edge detector. (bits: 22-20)
    ,SFLTCNT_MASK = 0x00700000
    ,SFLTCNT_POS = 20
    // SYNC Input Pin Inverse (bits: 23)
    ,SINPINV_MASK = 0x00800000
    ,SINPINV_POS = 23
    ,SINPINV_0 = 0x00000000 // The state of pin SYNC is passed to the negative edge detector
    ,SINPINV_1 = 0x00800000 // The inversed state of pin SYNC is passed to the negative edge detector
    // EPWM Phase Direction Control (bits: 24)
    ,PHSDIR0_MASK = 0x01000000
    ,PHSDIR0_POS = 24
    ,PHSDIR0_0 = 0x00000000 // Control EPWM counter count decrement after synchronizing
    ,PHSDIR0_1 = 0x01000000 // Control EPWM counter count increment after synchronizing
    // EPWM Phase Direction Control (bits: 25)
    ,PHSDIR2_MASK = 0x02000000
    ,PHSDIR2_POS = 25
    ,PHSDIR2_0 = 0x00000000 // Control EPWM counter count decrement after synchronizing
    ,PHSDIR2_1 = 0x02000000 // Control EPWM counter count increment after synchronizing
    // EPWM Phase Direction Control (bits: 26)
    ,PHSDIR4_MASK = 0x04000000
    ,PHSDIR4_POS = 26
    ,PHSDIR4_0 = 0x00000000 // Control EPWM counter count decrement after synchronizing
    ,PHSDIR4_1 = 0x04000000 // Control EPWM counter count increment after synchronizing
    ,SYNC_MASK = 0x07FF3F07
    ;
  };
  // EPWM Software Control Synchronization Register
  struct SWSYNC : reg<ip_ver, base + 0xC>
  {
    static constexpr typename SWSYNC::type
    // Software SYNC Function When SINSRCn (EPWM_SYNC[13:8]) is selected to 0, SYNC_OUT source comes from SYNC_IN or this bit. (bits: 0)
     SWSYNC0_MASK = 0x00000001
    ,SWSYNC0_POS = 0
    ,SWSYNC0 = 0x00000001
    // Software SYNC Function When SINSRCn (EPWM_SYNC[13:8]) is selected to 0, SYNC_OUT source comes from SYNC_IN or this bit. (bits: 1)
    ,SWSYNC2_MASK = 0x00000002
    ,SWSYNC2_POS = 1
    ,SWSYNC2 = 0x00000002
    // Software SYNC Function When SINSRCn (EPWM_SYNC[13:8]) is selected to 0, SYNC_OUT source comes from SYNC_IN or this bit. (bits: 2)
    ,SWSYNC4_MASK = 0x00000004
    ,SWSYNC4_POS = 2
    ,SWSYNC4 = 0x00000004
    ,SWSYNC_MASK = 0x00000007
    ;
  };
  // EPWM Clock Source Register
  struct CLKSRC : reg<ip_ver, base + 0x10>
  {
    static constexpr typename CLKSRC::type
    // EPWM_CH01 External Clock Source Select (bits: 2-0)
     ECLKSRC0_MASK = 0x00000007
    ,ECLKSRC0_POS = 0
    ,ECLKSRC0_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,ECLKSRC0_1 = 0x00000001 // TIMER0 overflow
    ,ECLKSRC0_2 = 0x00000002 // TIMER1 overflow
    ,ECLKSRC0_3 = 0x00000003 // TIMER2 overflow
    ,ECLKSRC0_4 = 0x00000004 // TIMER3 overflow
    // EPWM_CH23 External Clock Source Select (bits: 10-8)
    ,ECLKSRC2_MASK = 0x00000700
    ,ECLKSRC2_POS = 8
    ,ECLKSRC2_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,ECLKSRC2_1 = 0x00000100 // TIMER0 overflow
    ,ECLKSRC2_2 = 0x00000200 // TIMER1 overflow
    ,ECLKSRC2_3 = 0x00000300 // TIMER2 overflow
    ,ECLKSRC2_4 = 0x00000400 // TIMER3 overflow
    // EPWM_CH45 External Clock Source Select (bits: 18-16)
    ,ECLKSRC4_MASK = 0x00070000
    ,ECLKSRC4_POS = 16
    ,ECLKSRC4_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,ECLKSRC4_1 = 0x00010000 // TIMER0 overflow
    ,ECLKSRC4_2 = 0x00020000 // TIMER1 overflow
    ,ECLKSRC4_3 = 0x00030000 // TIMER2 overflow
    ,ECLKSRC4_4 = 0x00040000 // TIMER3 overflow
    ,CLKSRC_MASK = 0x00070707
    ;
  };
  // EPWM Clock Prescale Register 0/1
  struct CLKPSC0_1 : reg<ip_ver, base + 0x14>
  {
    static constexpr typename CLKPSC0_1::type
    // EPWM Counter Clock Prescale The clock of EPWM counter is decided by clock prescaler. Each EPWM pair share one EPWM counter clock prescaler. The clock of EPWM counter is divided by (CLKPSC+ 1). (bits: 11-0)
     CLKPSC_MASK = 0x00000FFF
    ,CLKPSC_POS = 0
    ,CLKPSC0_1_MASK = 0x00000FFF
    ;
  };
  // EPWM Clock Prescale Register 2/3
  using CLKPSC2_3 = reg<ip_ver, base + 0x18>;
  // EPWM Clock Prescale Register 4/5
  using CLKPSC4_5 = reg<ip_ver, base + 0x1C>;
  // EPWM Counter Enable Register
  struct CNTEN : reg<ip_ver, base + 0x20>
  {
    static constexpr typename CNTEN::type
    // EPWM Counter Enable Bits (bits: 0)
     CNTEN0_MASK = 0x00000001
    ,CNTEN0_POS = 0
    ,CNTEN0_0 = 0x00000000 // EPWM Counter and clock prescaler stop running
    ,CNTEN0_1 = 0x00000001 // EPWM Counter and clock prescaler start running
    // EPWM Counter Enable Bits (bits: 1)
    ,CNTEN1_MASK = 0x00000002
    ,CNTEN1_POS = 1
    ,CNTEN1_0 = 0x00000000 // EPWM Counter and clock prescaler stop running
    ,CNTEN1_1 = 0x00000002 // EPWM Counter and clock prescaler start running
    // EPWM Counter Enable Bits (bits: 2)
    ,CNTEN2_MASK = 0x00000004
    ,CNTEN2_POS = 2
    ,CNTEN2_0 = 0x00000000 // EPWM Counter and clock prescaler stop running
    ,CNTEN2_1 = 0x00000004 // EPWM Counter and clock prescaler start running
    // EPWM Counter Enable Bits (bits: 3)
    ,CNTEN3_MASK = 0x00000008
    ,CNTEN3_POS = 3
    ,CNTEN3_0 = 0x00000000 // EPWM Counter and clock prescaler stop running
    ,CNTEN3_1 = 0x00000008 // EPWM Counter and clock prescaler start running
    // EPWM Counter Enable Bits (bits: 4)
    ,CNTEN4_MASK = 0x00000010
    ,CNTEN4_POS = 4
    ,CNTEN4_0 = 0x00000000 // EPWM Counter and clock prescaler stop running
    ,CNTEN4_1 = 0x00000010 // EPWM Counter and clock prescaler start running
    // EPWM Counter Enable Bits (bits: 5)
    ,CNTEN5_MASK = 0x00000020
    ,CNTEN5_POS = 5
    ,CNTEN5_0 = 0x00000000 // EPWM Counter and clock prescaler stop running
    ,CNTEN5_1 = 0x00000020 // EPWM Counter and clock prescaler start running
    ,CNTEN_MASK = 0x0000003F
    ;
  };
  // EPWM Clear Counter Register
  struct CNTCLR : reg<ip_ver, base + 0x24>
  {
    static constexpr typename CNTCLR::type
    // Clear EPWM Counter Control Bit It is automatically cleared by hardware. Each bit n controls the corresponding EPWM channel n. (bits: 0)
     CNTCLR0_MASK = 0x00000001
    ,CNTCLR0_POS = 0
    ,CNTCLR0_0 = 0x00000000 // No effect
    ,CNTCLR0_1 = 0x00000001 // Clear 16-bit EPWM counter to 0000H
    // Clear EPWM Counter Control Bit It is automatically cleared by hardware. Each bit n controls the corresponding EPWM channel n. (bits: 1)
    ,CNTCLR1_MASK = 0x00000002
    ,CNTCLR1_POS = 1
    ,CNTCLR1_0 = 0x00000000 // No effect
    ,CNTCLR1_1 = 0x00000002 // Clear 16-bit EPWM counter to 0000H
    // Clear EPWM Counter Control Bit It is automatically cleared by hardware. Each bit n controls the corresponding EPWM channel n. (bits: 2)
    ,CNTCLR2_MASK = 0x00000004
    ,CNTCLR2_POS = 2
    ,CNTCLR2_0 = 0x00000000 // No effect
    ,CNTCLR2_1 = 0x00000004 // Clear 16-bit EPWM counter to 0000H
    // Clear EPWM Counter Control Bit It is automatically cleared by hardware. Each bit n controls the corresponding EPWM channel n. (bits: 3)
    ,CNTCLR3_MASK = 0x00000008
    ,CNTCLR3_POS = 3
    ,CNTCLR3_0 = 0x00000000 // No effect
    ,CNTCLR3_1 = 0x00000008 // Clear 16-bit EPWM counter to 0000H
    // Clear EPWM Counter Control Bit It is automatically cleared by hardware. Each bit n controls the corresponding EPWM channel n. (bits: 4)
    ,CNTCLR4_MASK = 0x00000010
    ,CNTCLR4_POS = 4
    ,CNTCLR4_0 = 0x00000000 // No effect
    ,CNTCLR4_1 = 0x00000010 // Clear 16-bit EPWM counter to 0000H
    // Clear EPWM Counter Control Bit It is automatically cleared by hardware. Each bit n controls the corresponding EPWM channel n. (bits: 5)
    ,CNTCLR5_MASK = 0x00000020
    ,CNTCLR5_POS = 5
    ,CNTCLR5_0 = 0x00000000 // No effect
    ,CNTCLR5_1 = 0x00000020 // Clear 16-bit EPWM counter to 0000H
    ,CNTCLR_MASK = 0x0000003F
    ;
  };
  // EPWM Load Register
  struct LOAD : reg<ip_ver, base + 0x28>
  {
    static constexpr typename LOAD::type
    // Re-load EPWM Comparator Register (EPWM_CMPDATn) Control Bit This bit is software write, hardware clear when current EPWM period end. Write Operation: (bits: 0)
     LOAD0_MASK = 0x00000001
    ,LOAD0_POS = 0
    ,LOAD0_0 = 0x00000000 // No effect. No load window is set
    ,LOAD0_1 = 0x00000001 // Set load window of window loading mode. Load window is set
    // Re-load EPWM Comparator Register (EPWM_CMPDATn) Control Bit This bit is software write, hardware clear when current EPWM period end. Write Operation: (bits: 1)
    ,LOAD1_MASK = 0x00000002
    ,LOAD1_POS = 1
    ,LOAD1_0 = 0x00000000 // No effect. No load window is set
    ,LOAD1_1 = 0x00000002 // Set load window of window loading mode. Load window is set
    // Re-load EPWM Comparator Register (EPWM_CMPDATn) Control Bit This bit is software write, hardware clear when current EPWM period end. Write Operation: (bits: 2)
    ,LOAD2_MASK = 0x00000004
    ,LOAD2_POS = 2
    ,LOAD2_0 = 0x00000000 // No effect. No load window is set
    ,LOAD2_1 = 0x00000004 // Set load window of window loading mode. Load window is set
    // Re-load EPWM Comparator Register (EPWM_CMPDATn) Control Bit This bit is software write, hardware clear when current EPWM period end. Write Operation: (bits: 3)
    ,LOAD3_MASK = 0x00000008
    ,LOAD3_POS = 3
    ,LOAD3_0 = 0x00000000 // No effect. No load window is set
    ,LOAD3_1 = 0x00000008 // Set load window of window loading mode. Load window is set
    // Re-load EPWM Comparator Register (EPWM_CMPDATn) Control Bit This bit is software write, hardware clear when current EPWM period end. Write Operation: (bits: 4)
    ,LOAD4_MASK = 0x00000010
    ,LOAD4_POS = 4
    ,LOAD4_0 = 0x00000000 // No effect. No load window is set
    ,LOAD4_1 = 0x00000010 // Set load window of window loading mode. Load window is set
    // Re-load EPWM Comparator Register (EPWM_CMPDATn) Control Bit This bit is software write, hardware clear when current EPWM period end. Write Operation: (bits: 5)
    ,LOAD5_MASK = 0x00000020
    ,LOAD5_POS = 5
    ,LOAD5_0 = 0x00000000 // No effect. No load window is set
    ,LOAD5_1 = 0x00000020 // Set load window of window loading mode. Load window is set
    ,LOAD_MASK = 0x0000003F
    ;
  };
  // EPWM Period Register 0
  struct PERIOD0 : reg<ip_ver, base + 0x30>
  {
    static constexpr typename PERIOD0::type
    // EPWM Period Register Up-Count mode: In this mode, EPWM counter counts from 0 to PERIOD, and restarts from 0. (bits: 15-0)
     PERIOD_MASK = 0x0000FFFF
    ,PERIOD_POS = 0
    ,PERIOD0_MASK = 0x0000FFFF
    ;
  };
  // EPWM Period Register 1
  using PERIOD1 = reg<ip_ver, base + 0x34>;
  // EPWM Period Register 2
  using PERIOD2 = reg<ip_ver, base + 0x38>;
  // EPWM Period Register 3
  using PERIOD3 = reg<ip_ver, base + 0x3C>;
  // EPWM Period Register 4
  using PERIOD4 = reg<ip_ver, base + 0x40>;
  // EPWM Period Register 5
  using PERIOD5 = reg<ip_ver, base + 0x44>;
  // EPWM Comparator Register 0
  struct CMPDAT0 : reg<ip_ver, base + 0x50>
  {
    static constexpr typename CMPDAT0::type
    // EPWM Comparator Register CMP is used to compare with CNT (EPWM_CNTn[15:0]) bits to generate EPWM waveform, interrupt and trigger EADC/DAC. In complementary mode, EPWM_CMPDAT0, EPWM_CMPDAT 2, EPWM_CMPDAT4 denote as first compared point, and EPWM_CMPDAT1, EPWM_CMPDAT3, EPWM_CMPDAT5 denote as second compared point for the corresponding 3 complementary pairs EPWM_CH0 and EPWM_CH1, EPWM_CH2 and EPWM_CH3, EPWM_CH4 and EPWM_CH5. (bits: 15-0)
     CMP_MASK = 0x0000FFFF
    ,CMP_POS = 0
    ,CMPDAT0_MASK = 0x0000FFFF
    ;
  };
  // EPWM Comparator Register 1
  using CMPDAT1 = reg<ip_ver, base + 0x54>;
  // EPWM Comparator Register 2
  using CMPDAT2 = reg<ip_ver, base + 0x58>;
  // EPWM Comparator Register 3
  using CMPDAT3 = reg<ip_ver, base + 0x5C>;
  // EPWM Comparator Register 4
  using CMPDAT4 = reg<ip_ver, base + 0x60>;
  // EPWM Comparator Register 5
  using CMPDAT5 = reg<ip_ver, base + 0x64>;
  // EPWM Dead-time Control Register 0/1
  struct DTCTL0_1 : reg<ip_ver, base + 0x70>
  {
    static constexpr typename DTCTL0_1::type
    // Dead-time Counter (Write Protect) The dead-time can be calculated from the following formula: Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 11-0)
     DTCNT_MASK = 0x00000FFF
    ,DTCNT_POS = 0
    // Enable Dead-time Insertion for EPWM Pair (EPWM_CH0, EPWM_CH1) (EPWM_CH2, EPWM_CH3) (EPWM_CH4, EPWM_CH5) (Write Protect) Dead-time insertion is only active when this pair of complementary EPWM is enabled. If dead- time insertion is inactive, the outputs of pin pair are complementary without any delay. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 16)
    ,DTEN_MASK = 0x00010000
    ,DTEN_POS = 16
    ,DTEN_0 = 0x00000000 // Dead-time insertion Disabled on the pin pair
    ,DTEN_1 = 0x00010000 // Dead-time insertion Enabled on the pin pair
    // Dead-time Clock Select (Write Protect) Note: This bit is write protected. Refer to REGWRPROT register. (bits: 24)
    ,DTCKSEL_MASK = 0x01000000
    ,DTCKSEL_POS = 24
    ,DTCKSEL_0 = 0x00000000 // Dead-time clock source from EPWM_CLK
    ,DTCKSEL_1 = 0x01000000 // Dead-time clock source from prescaler output
    ,DTCTL0_1_MASK = 0x01010FFF
    ;
  };
  // EPWM Dead-time Control Register 2/3
  using DTCTL2_3 = reg<ip_ver, base + 0x74>;
  // EPWM Dead-time Control Register 4/5
  using DTCTL4_5 = reg<ip_ver, base + 0x78>;
  // EPWM Counter Phase Register 0/1
  struct PHS0_1 : reg<ip_ver, base + 0x80>
  {
    static constexpr typename PHS0_1::type
    // EPWM Synchronous Start Phase Bits PHS determines the EPWM synchronous start phase value. These bits only use in synchronous function. (bits: 15-0)
     PHS_MASK = 0x0000FFFF
    ,PHS_POS = 0
    ,PHS0_1_MASK = 0x0000FFFF
    ;
  };
  // EPWM Counter Phase Register 2/3
  using PHS2_3 = reg<ip_ver, base + 0x84>;
  // EPWM Counter Phase Register 4/5
  using PHS4_5 = reg<ip_ver, base + 0x88>;
  // EPWM Counter Register 0
  struct CNT0 : reg<ip_ver, base + 0x90>
  {
    static constexpr typename CNT0::type
    // EPWM Data Register (Read Only) User can monitor CNT to know the current value in 16-bit period counter. (bits: 15-0)
     CNT_MASK = 0x0000FFFF
    ,CNT_POS = 0
    // EPWM Direction Indicator Flag (Read Only) (bits: 16)
    ,DIRF_MASK = 0x00010000
    ,DIRF_POS = 16
    ,DIRF_0 = 0x00000000 // Counter is counting down
    ,DIRF_1 = 0x00010000 // Counter is counting up
    ,CNT0_MASK = 0x0001FFFF
    ;
  };
  // EPWM Counter Register 1
  using CNT1 = reg<ip_ver, base + 0x94>;
  // EPWM Counter Register 2
  using CNT2 = reg<ip_ver, base + 0x98>;
  // EPWM Counter Register 3
  using CNT3 = reg<ip_ver, base + 0x9C>;
  // EPWM Counter Register 4
  using CNT4 = reg<ip_ver, base + 0xA0>;
  // EPWM Counter Register 5
  using CNT5 = reg<ip_ver, base + 0xA4>;
  // EPWM Generation Register 0
  struct WGCTL0 : reg<ip_ver, base + 0xB0>
  {
    static constexpr typename WGCTL0::type
    // EPWM Zero Point Control EPWM can control output level when EPWM counter counts to 0. (bits: 1-0)
     ZPCTL0_MASK = 0x00000003
    ,ZPCTL0_POS = 0
    ,ZPCTL0_0 = 0x00000000 // Do nothing
    ,ZPCTL0_1 = 0x00000001 // EPWM zero point output Low
    ,ZPCTL0_2 = 0x00000002 // EPWM zero point output High
    ,ZPCTL0_3 = 0x00000003 // EPWM zero point output Toggle
    // EPWM Zero Point Control EPWM can control output level when EPWM counter counts to 0. (bits: 3-2)
    ,ZPCTL1_MASK = 0x0000000C
    ,ZPCTL1_POS = 2
    ,ZPCTL1_0 = 0x00000000 // Do nothing
    ,ZPCTL1_1 = 0x00000004 // EPWM zero point output Low
    ,ZPCTL1_2 = 0x00000008 // EPWM zero point output High
    ,ZPCTL1_3 = 0x0000000C // EPWM zero point output Toggle
    // EPWM Zero Point Control EPWM can control output level when EPWM counter counts to 0. (bits: 5-4)
    ,ZPCTL2_MASK = 0x00000030
    ,ZPCTL2_POS = 4
    ,ZPCTL2_0 = 0x00000000 // Do nothing
    ,ZPCTL2_1 = 0x00000010 // EPWM zero point output Low
    ,ZPCTL2_2 = 0x00000020 // EPWM zero point output High
    ,ZPCTL2_3 = 0x00000030 // EPWM zero point output Toggle
    // EPWM Zero Point Control EPWM can control output level when EPWM counter counts to 0. (bits: 7-6)
    ,ZPCTL3_MASK = 0x000000C0
    ,ZPCTL3_POS = 6
    ,ZPCTL3_0 = 0x00000000 // Do nothing
    ,ZPCTL3_1 = 0x00000040 // EPWM zero point output Low
    ,ZPCTL3_2 = 0x00000080 // EPWM zero point output High
    ,ZPCTL3_3 = 0x000000C0 // EPWM zero point output Toggle
    // EPWM Zero Point Control EPWM can control output level when EPWM counter counts to 0. (bits: 9-8)
    ,ZPCTL4_MASK = 0x00000300
    ,ZPCTL4_POS = 8
    ,ZPCTL4_0 = 0x00000000 // Do nothing
    ,ZPCTL4_1 = 0x00000100 // EPWM zero point output Low
    ,ZPCTL4_2 = 0x00000200 // EPWM zero point output High
    ,ZPCTL4_3 = 0x00000300 // EPWM zero point output Toggle
    // EPWM Zero Point Control EPWM can control output level when EPWM counter counts to 0. (bits: 11-10)
    ,ZPCTL5_MASK = 0x00000C00
    ,ZPCTL5_POS = 10
    ,ZPCTL5_0 = 0x00000000 // Do nothing
    ,ZPCTL5_1 = 0x00000400 // EPWM zero point output Low
    ,ZPCTL5_2 = 0x00000800 // EPWM zero point output High
    ,ZPCTL5_3 = 0x00000C00 // EPWM zero point output Toggle
    // EPWM Period (Center) Point Control EPWM can control output level when EPWM counter counts to (PERIODn+1). Note: This bit is center point control when EPWM counter operating in up-down counter type. (bits: 17-16)
    ,PRDPCTL0_MASK = 0x00030000
    ,PRDPCTL0_POS = 16
    ,PRDPCTL0_0 = 0x00000000 // Do nothing
    ,PRDPCTL0_1 = 0x00010000 // EPWM period (center) point output Low
    ,PRDPCTL0_2 = 0x00020000 // EPWM period (center) point output High
    ,PRDPCTL0_3 = 0x00030000 // EPWM period (center) point output Toggle
    // EPWM Period (Center) Point Control EPWM can control output level when EPWM counter counts to (PERIODn+1). Note: This bit is center point control when EPWM counter operating in up-down counter type. (bits: 19-18)
    ,PRDPCTL1_MASK = 0x000C0000
    ,PRDPCTL1_POS = 18
    ,PRDPCTL1_0 = 0x00000000 // Do nothing
    ,PRDPCTL1_1 = 0x00040000 // EPWM period (center) point output Low
    ,PRDPCTL1_2 = 0x00080000 // EPWM period (center) point output High
    ,PRDPCTL1_3 = 0x000C0000 // EPWM period (center) point output Toggle
    // EPWM Period (Center) Point Control EPWM can control output level when EPWM counter counts to (PERIODn+1). Note: This bit is center point control when EPWM counter operating in up-down counter type. (bits: 21-20)
    ,PRDPCTL2_MASK = 0x00300000
    ,PRDPCTL2_POS = 20
    ,PRDPCTL2_0 = 0x00000000 // Do nothing
    ,PRDPCTL2_1 = 0x00100000 // EPWM period (center) point output Low
    ,PRDPCTL2_2 = 0x00200000 // EPWM period (center) point output High
    ,PRDPCTL2_3 = 0x00300000 // EPWM period (center) point output Toggle
    // EPWM Period (Center) Point Control EPWM can control output level when EPWM counter counts to (PERIODn+1). Note: This bit is center point control when EPWM counter operating in up-down counter type. (bits: 23-22)
    ,PRDPCTL3_MASK = 0x00C00000
    ,PRDPCTL3_POS = 22
    ,PRDPCTL3_0 = 0x00000000 // Do nothing
    ,PRDPCTL3_1 = 0x00400000 // EPWM period (center) point output Low
    ,PRDPCTL3_2 = 0x00800000 // EPWM period (center) point output High
    ,PRDPCTL3_3 = 0x00C00000 // EPWM period (center) point output Toggle
    // EPWM Period (Center) Point Control EPWM can control output level when EPWM counter counts to (PERIODn+1). Note: This bit is center point control when EPWM counter operating in up-down counter type. (bits: 25-24)
    ,PRDPCTL4_MASK = 0x03000000
    ,PRDPCTL4_POS = 24
    ,PRDPCTL4_0 = 0x00000000 // Do nothing
    ,PRDPCTL4_1 = 0x01000000 // EPWM period (center) point output Low
    ,PRDPCTL4_2 = 0x02000000 // EPWM period (center) point output High
    ,PRDPCTL4_3 = 0x03000000 // EPWM period (center) point output Toggle
    // EPWM Period (Center) Point Control EPWM can control output level when EPWM counter counts to (PERIODn+1). Note: This bit is center point control when EPWM counter operating in up-down counter type. (bits: 27-26)
    ,PRDPCTL5_MASK = 0x0C000000
    ,PRDPCTL5_POS = 26
    ,PRDPCTL5_0 = 0x00000000 // Do nothing
    ,PRDPCTL5_1 = 0x04000000 // EPWM period (center) point output Low
    ,PRDPCTL5_2 = 0x08000000 // EPWM period (center) point output High
    ,PRDPCTL5_3 = 0x0C000000 // EPWM period (center) point output Toggle
    ,WGCTL0_MASK = 0x0FFF0FFF
    ;
  };
  // EPWM Generation Register 1
  struct WGCTL1 : reg<ip_ver, base + 0xB4>
  {
    static constexpr typename WGCTL1::type
    // EPWM Compare Up Point Control EPWM can control output level when EPWM counter counts up to CMP. Note: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4. (bits: 1-0)
     CMPUCTL0_MASK = 0x00000003
    ,CMPUCTL0_POS = 0
    ,CMPUCTL0_0 = 0x00000000 // Do nothing
    ,CMPUCTL0_1 = 0x00000001 // EPWM compare up point output Low
    ,CMPUCTL0_2 = 0x00000002 // EPWM compare up point output High
    ,CMPUCTL0_3 = 0x00000003 // EPWM compare up point output Toggle
    // EPWM Compare Up Point Control EPWM can control output level when EPWM counter counts up to CMP. Note: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4. (bits: 3-2)
    ,CMPUCTL1_MASK = 0x0000000C
    ,CMPUCTL1_POS = 2
    ,CMPUCTL1_0 = 0x00000000 // Do nothing
    ,CMPUCTL1_1 = 0x00000004 // EPWM compare up point output Low
    ,CMPUCTL1_2 = 0x00000008 // EPWM compare up point output High
    ,CMPUCTL1_3 = 0x0000000C // EPWM compare up point output Toggle
    // EPWM Compare Up Point Control EPWM can control output level when EPWM counter counts up to CMP. Note: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4. (bits: 5-4)
    ,CMPUCTL2_MASK = 0x00000030
    ,CMPUCTL2_POS = 4
    ,CMPUCTL2_0 = 0x00000000 // Do nothing
    ,CMPUCTL2_1 = 0x00000010 // EPWM compare up point output Low
    ,CMPUCTL2_2 = 0x00000020 // EPWM compare up point output High
    ,CMPUCTL2_3 = 0x00000030 // EPWM compare up point output Toggle
    // EPWM Compare Up Point Control EPWM can control output level when EPWM counter counts up to CMP. Note: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4. (bits: 7-6)
    ,CMPUCTL3_MASK = 0x000000C0
    ,CMPUCTL3_POS = 6
    ,CMPUCTL3_0 = 0x00000000 // Do nothing
    ,CMPUCTL3_1 = 0x00000040 // EPWM compare up point output Low
    ,CMPUCTL3_2 = 0x00000080 // EPWM compare up point output High
    ,CMPUCTL3_3 = 0x000000C0 // EPWM compare up point output Toggle
    // EPWM Compare Up Point Control EPWM can control output level when EPWM counter counts up to CMP. Note: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4. (bits: 9-8)
    ,CMPUCTL4_MASK = 0x00000300
    ,CMPUCTL4_POS = 8
    ,CMPUCTL4_0 = 0x00000000 // Do nothing
    ,CMPUCTL4_1 = 0x00000100 // EPWM compare up point output Low
    ,CMPUCTL4_2 = 0x00000200 // EPWM compare up point output High
    ,CMPUCTL4_3 = 0x00000300 // EPWM compare up point output Toggle
    // EPWM Compare Up Point Control EPWM can control output level when EPWM counter counts up to CMP. Note: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4. (bits: 11-10)
    ,CMPUCTL5_MASK = 0x00000C00
    ,CMPUCTL5_POS = 10
    ,CMPUCTL5_0 = 0x00000000 // Do nothing
    ,CMPUCTL5_1 = 0x00000400 // EPWM compare up point output Low
    ,CMPUCTL5_2 = 0x00000800 // EPWM compare up point output High
    ,CMPUCTL5_3 = 0x00000C00 // EPWM compare up point output Toggle
    // EPWM Compare Down Point Control EPWM can control output level when EPWM counter counts down to CMP. Note: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4. (bits: 17-16)
    ,CMPDCTL0_MASK = 0x00030000
    ,CMPDCTL0_POS = 16
    ,CMPDCTL0_0 = 0x00000000 // Do nothing
    ,CMPDCTL0_1 = 0x00010000 // EPWM compare down point output Low
    ,CMPDCTL0_2 = 0x00020000 // EPWM compare down point output High
    ,CMPDCTL0_3 = 0x00030000 // EPWM compare down point output Toggle
    // EPWM Compare Down Point Control EPWM can control output level when EPWM counter counts down to CMP. Note: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4. (bits: 19-18)
    ,CMPDCTL1_MASK = 0x000C0000
    ,CMPDCTL1_POS = 18
    ,CMPDCTL1_0 = 0x00000000 // Do nothing
    ,CMPDCTL1_1 = 0x00040000 // EPWM compare down point output Low
    ,CMPDCTL1_2 = 0x00080000 // EPWM compare down point output High
    ,CMPDCTL1_3 = 0x000C0000 // EPWM compare down point output Toggle
    // EPWM Compare Down Point Control EPWM can control output level when EPWM counter counts down to CMP. Note: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4. (bits: 21-20)
    ,CMPDCTL2_MASK = 0x00300000
    ,CMPDCTL2_POS = 20
    ,CMPDCTL2_0 = 0x00000000 // Do nothing
    ,CMPDCTL2_1 = 0x00100000 // EPWM compare down point output Low
    ,CMPDCTL2_2 = 0x00200000 // EPWM compare down point output High
    ,CMPDCTL2_3 = 0x00300000 // EPWM compare down point output Toggle
    // EPWM Compare Down Point Control EPWM can control output level when EPWM counter counts down to CMP. Note: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4. (bits: 23-22)
    ,CMPDCTL3_MASK = 0x00C00000
    ,CMPDCTL3_POS = 22
    ,CMPDCTL3_0 = 0x00000000 // Do nothing
    ,CMPDCTL3_1 = 0x00400000 // EPWM compare down point output Low
    ,CMPDCTL3_2 = 0x00800000 // EPWM compare down point output High
    ,CMPDCTL3_3 = 0x00C00000 // EPWM compare down point output Toggle
    // EPWM Compare Down Point Control EPWM can control output level when EPWM counter counts down to CMP. Note: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4. (bits: 25-24)
    ,CMPDCTL4_MASK = 0x03000000
    ,CMPDCTL4_POS = 24
    ,CMPDCTL4_0 = 0x00000000 // Do nothing
    ,CMPDCTL4_1 = 0x01000000 // EPWM compare down point output Low
    ,CMPDCTL4_2 = 0x02000000 // EPWM compare down point output High
    ,CMPDCTL4_3 = 0x03000000 // EPWM compare down point output Toggle
    // EPWM Compare Down Point Control EPWM can control output level when EPWM counter counts down to CMP. Note: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4. (bits: 27-26)
    ,CMPDCTL5_MASK = 0x0C000000
    ,CMPDCTL5_POS = 26
    ,CMPDCTL5_0 = 0x00000000 // Do nothing
    ,CMPDCTL5_1 = 0x04000000 // EPWM compare down point output Low
    ,CMPDCTL5_2 = 0x08000000 // EPWM compare down point output High
    ,CMPDCTL5_3 = 0x0C000000 // EPWM compare down point output Toggle
    ,WGCTL1_MASK = 0x0FFF0FFF
    ;
  };
  // EPWM Mask Enable Register
  struct MSKEN : reg<ip_ver, base + 0xB8>
  {
    static constexpr typename MSKEN::type
    // EPWM Mask Enable Bits The EPWM output signal will be masked when this bit is enabled. The corresponding EPWM channel n will output MSKDATn (EPWM_MSK[5:0]) data. (bits: 0)
     MSKEN0_MASK = 0x00000001
    ,MSKEN0_POS = 0
    ,MSKEN0_0 = 0x00000000 // EPWM output signal is non-masked
    ,MSKEN0_1 = 0x00000001 // EPWM output signal is masked and output MSKDATn data
    // EPWM Mask Enable Bits The EPWM output signal will be masked when this bit is enabled. The corresponding EPWM channel n will output MSKDATn (EPWM_MSK[5:0]) data. (bits: 1)
    ,MSKEN1_MASK = 0x00000002
    ,MSKEN1_POS = 1
    ,MSKEN1_0 = 0x00000000 // EPWM output signal is non-masked
    ,MSKEN1_1 = 0x00000002 // EPWM output signal is masked and output MSKDATn data
    // EPWM Mask Enable Bits The EPWM output signal will be masked when this bit is enabled. The corresponding EPWM channel n will output MSKDATn (EPWM_MSK[5:0]) data. (bits: 2)
    ,MSKEN2_MASK = 0x00000004
    ,MSKEN2_POS = 2
    ,MSKEN2_0 = 0x00000000 // EPWM output signal is non-masked
    ,MSKEN2_1 = 0x00000004 // EPWM output signal is masked and output MSKDATn data
    // EPWM Mask Enable Bits The EPWM output signal will be masked when this bit is enabled. The corresponding EPWM channel n will output MSKDATn (EPWM_MSK[5:0]) data. (bits: 3)
    ,MSKEN3_MASK = 0x00000008
    ,MSKEN3_POS = 3
    ,MSKEN3_0 = 0x00000000 // EPWM output signal is non-masked
    ,MSKEN3_1 = 0x00000008 // EPWM output signal is masked and output MSKDATn data
    // EPWM Mask Enable Bits The EPWM output signal will be masked when this bit is enabled. The corresponding EPWM channel n will output MSKDATn (EPWM_MSK[5:0]) data. (bits: 4)
    ,MSKEN4_MASK = 0x00000010
    ,MSKEN4_POS = 4
    ,MSKEN4_0 = 0x00000000 // EPWM output signal is non-masked
    ,MSKEN4_1 = 0x00000010 // EPWM output signal is masked and output MSKDATn data
    // EPWM Mask Enable Bits The EPWM output signal will be masked when this bit is enabled. The corresponding EPWM channel n will output MSKDATn (EPWM_MSK[5:0]) data. (bits: 5)
    ,MSKEN5_MASK = 0x00000020
    ,MSKEN5_POS = 5
    ,MSKEN5_0 = 0x00000000 // EPWM output signal is non-masked
    ,MSKEN5_1 = 0x00000020 // EPWM output signal is masked and output MSKDATn data
    ,MSKEN_MASK = 0x0000003F
    ;
  };
  // EPWM Mask Data Register
  struct MSK : reg<ip_ver, base + 0xBC>
  {
    static constexpr typename MSK::type
    // EPWM Mask Data Bit This data bit control the state of EPWMn output pin, if corresponding mask function is enabled. (bits: 0)
     MSKDAT0_MASK = 0x00000001
    ,MSKDAT0_POS = 0
    ,MSKDAT0_0 = 0x00000000 // Output logic low to EPWM channel n
    ,MSKDAT0_1 = 0x00000001 // Output logic high to EPWM channel n
    // EPWM Mask Data Bit This data bit control the state of EPWMn output pin, if corresponding mask function is enabled. (bits: 1)
    ,MSKDAT1_MASK = 0x00000002
    ,MSKDAT1_POS = 1
    ,MSKDAT1_0 = 0x00000000 // Output logic low to EPWM channel n
    ,MSKDAT1_1 = 0x00000002 // Output logic high to EPWM channel n
    // EPWM Mask Data Bit This data bit control the state of EPWMn output pin, if corresponding mask function is enabled. (bits: 2)
    ,MSKDAT2_MASK = 0x00000004
    ,MSKDAT2_POS = 2
    ,MSKDAT2_0 = 0x00000000 // Output logic low to EPWM channel n
    ,MSKDAT2_1 = 0x00000004 // Output logic high to EPWM channel n
    // EPWM Mask Data Bit This data bit control the state of EPWMn output pin, if corresponding mask function is enabled. (bits: 3)
    ,MSKDAT3_MASK = 0x00000008
    ,MSKDAT3_POS = 3
    ,MSKDAT3_0 = 0x00000000 // Output logic low to EPWM channel n
    ,MSKDAT3_1 = 0x00000008 // Output logic high to EPWM channel n
    // EPWM Mask Data Bit This data bit control the state of EPWMn output pin, if corresponding mask function is enabled. (bits: 4)
    ,MSKDAT4_MASK = 0x00000010
    ,MSKDAT4_POS = 4
    ,MSKDAT4_0 = 0x00000000 // Output logic low to EPWM channel n
    ,MSKDAT4_1 = 0x00000010 // Output logic high to EPWM channel n
    // EPWM Mask Data Bit This data bit control the state of EPWMn output pin, if corresponding mask function is enabled. (bits: 5)
    ,MSKDAT5_MASK = 0x00000020
    ,MSKDAT5_POS = 5
    ,MSKDAT5_0 = 0x00000000 // Output logic low to EPWM channel n
    ,MSKDAT5_1 = 0x00000020 // Output logic high to EPWM channel n
    ,MSK_MASK = 0x0000003F
    ;
  };
  // EPWM Brake Noise Filter Register
  struct BNF : reg<ip_ver, base + 0xC0>
  {
    static constexpr typename BNF::type
    // EPWM Brake 0 Noise Filter Enable Bit (bits: 0)
     BRK0NFEN_MASK = 0x00000001
    ,BRK0NFEN_POS = 0
    ,BRK0NFEN_0 = 0x00000000 // Noise filter of EPWM Brake 0 Disabled
    ,BRK0NFEN_1 = 0x00000001 // Noise filter of EPWM Brake 0 Enabled
    // Brake 0 Edge Detector Filter Clock Selection (bits: 3-1)
    ,BRK0NFSEL_MASK = 0x0000000E
    ,BRK0NFSEL_POS = 1
    ,BRK0NFSEL_0 = 0x00000000 // Filter clock = HCLK
    ,BRK0NFSEL_1 = 0x00000002 // Filter clock = HCLK/2
    ,BRK0NFSEL_2 = 0x00000004 // Filter clock = HCLK/4
    ,BRK0NFSEL_3 = 0x00000006 // Filter clock = HCLK/8
    ,BRK0NFSEL_4 = 0x00000008 // Filter clock = HCLK/16
    ,BRK0NFSEL_5 = 0x0000000A // Filter clock = HCLK/32
    ,BRK0NFSEL_6 = 0x0000000C // Filter clock = HCLK/64
    ,BRK0NFSEL_7 = 0x0000000E // Filter clock = HCLK/128
    // Brake 0 Edge Detector Filter Count The register bits control the Brake0 filter counter to count from 0 to BRK0FCNT. (bits: 6-4)
    ,BRK0FCNT_MASK = 0x00000070
    ,BRK0FCNT_POS = 4
    // Brake 0 Pin Inverse (bits: 7)
    ,BRK0PINV_MASK = 0x00000080
    ,BRK0PINV_POS = 7
    ,BRK0PINV_0 = 0x00000000 // brake pin event will be detected if EPWMx_BRAKE0 pin status transfer from low to high in edge-detect, or pin status is high in level-detect
    ,BRK0PINV_1 = 0x00000080 // brake pin event will be detected if EPWMx_BRAKE0 pin status transfer from high to low in edge-detect, or pin status is low in level-detect
    // EPWM Brake 1 Noise Filter Enable Bit (bits: 8)
    ,BRK1NFEN_MASK = 0x00000100
    ,BRK1NFEN_POS = 8
    ,BRK1NFEN_0 = 0x00000000 // Noise filter of EPWM Brake 1 Disabled
    ,BRK1NFEN_1 = 0x00000100 // Noise filter of EPWM Brake 1 Enabled
    // Brake 1 Edge Detector Filter Clock Selection (bits: 11-9)
    ,BRK1NFSEL_MASK = 0x00000E00
    ,BRK1NFSEL_POS = 9
    ,BRK1NFSEL_0 = 0x00000000 // Filter clock = HCLK
    ,BRK1NFSEL_1 = 0x00000200 // Filter clock = HCLK/2
    ,BRK1NFSEL_2 = 0x00000400 // Filter clock = HCLK/4
    ,BRK1NFSEL_3 = 0x00000600 // Filter clock = HCLK/8
    ,BRK1NFSEL_4 = 0x00000800 // Filter clock = HCLK/16
    ,BRK1NFSEL_5 = 0x00000A00 // Filter clock = HCLK/32
    ,BRK1NFSEL_6 = 0x00000C00 // Filter clock = HCLK/64
    ,BRK1NFSEL_7 = 0x00000E00 // Filter clock = HCLK/128
    // Brake 1 Edge Detector Filter Count The register bits control the Brake1 filter counter to count from 0 to BRK1FCNT. (bits: 14-12)
    ,BRK1FCNT_MASK = 0x00007000
    ,BRK1FCNT_POS = 12
    // Brake 1 Pin Inverse (bits: 15)
    ,BRK1PINV_MASK = 0x00008000
    ,BRK1PINV_POS = 15
    ,BRK1PINV_0 = 0x00000000 // brake pin event will be detected if EPWMx_BRAKE1 pin status transfer from low to high in edge-detect, or pin status is high in level-detect
    ,BRK1PINV_1 = 0x00008000 // brake pin event will be detected if EPWMx_BRAKE1 pin status transfer from high to low in edge-detect, or pin status is low in level-detect
    // Brake 0 Pin Source Select For EPWM0 setting: (bits: 16)
    ,BK0SRC_MASK = 0x00010000
    ,BK0SRC_POS = 16
    ,BK0SRC_0 = 0x00000000 // Brake 0 pin source come from EPWM0_BRAKE0. Brake 0 pin source come from EPWM1_BRAKE0
    ,BK0SRC_1 = 0x00010000 // Brake 0 pin source come from EPWM1_BRAKE0. Brake 0 pin source come from EPWM0_BRAKE0
    // Brake 1 Pin Source Select For EPWM0 setting: (bits: 24)
    ,BK1SRC_MASK = 0x01000000
    ,BK1SRC_POS = 24
    ,BK1SRC_0 = 0x00000000 // Brake 1 pin source come from EPWM0_BRAKE1. Brake 1 pin source come from EPWM1_BRAKE1
    ,BK1SRC_1 = 0x01000000 // Brake 1 pin source come from EPWM1_BRAKE1. Brake 1 pin source come from EPWM0_BRAKE1
    ,BNF_MASK = 0x0101FFFF
    ;
  };
  // EPWM System Fail Brake Control Register
  struct FAILBRK : reg<ip_ver, base + 0xC4>
  {
    static constexpr typename FAILBRK::type
    // Clock Security System Detection Trigger EPWM Brake Function 0 Enable Bit (bits: 0)
     CSSBRKEN_MASK = 0x00000001
    ,CSSBRKEN_POS = 0
    ,CSSBRKEN_0 = 0x00000000 // Brake Function triggered by CSS detection Disabled
    ,CSSBRKEN_1 = 0x00000001 // Brake Function triggered by CSS detection Enabled
    // Brown-out Detection Trigger EPWM Brake Function 0 Enable Bit (bits: 1)
    ,BODBRKEN_MASK = 0x00000002
    ,BODBRKEN_POS = 1
    ,BODBRKEN_0 = 0x00000000 // Brake Function triggered by BOD Disabled
    ,BODBRKEN_1 = 0x00000002 // Brake Function triggered by BOD Enabled
    // SRAM Parity Error Detection Trigger EPWM Brake Function 0 Enable Bit (bits: 2)
    ,RAMBRKEN_MASK = 0x00000004
    ,RAMBRKEN_POS = 2
    ,RAMBRKEN_0 = 0x00000000 // Brake Function triggered by SRAM parity error detection Disabled
    ,RAMBRKEN_1 = 0x00000004 // Brake Function triggered by SRAM parity error detection Enabled
    // Core Lockup Detection Trigger EPWM Brake Function 0 Enable Bit (bits: 3)
    ,CORBRKEN_MASK = 0x00000008
    ,CORBRKEN_POS = 3
    ,CORBRKEN_0 = 0x00000000 // Brake Function triggered by Core lockup detection Disabled
    ,CORBRKEN_1 = 0x00000008 // Brake Function triggered by Core lockup detection Enabled
    ,FAILBRK_MASK = 0x0000000F
    ;
  };
  // EPWM Brake Detect Control Register 0/1
  struct BRKCTL0_1 : reg<ip_ver, base + 0xC8>
  {
    static constexpr typename BRKCTL0_1::type
    // Enable ACMP0_O Digital Output As Edge-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 0)
     CPO0EBEN_MASK = 0x00000001
    ,CPO0EBEN_POS = 0
    ,CPO0EBEN_0 = 0x00000000 // ACMP0_O as edge-detect brake source Disabled
    ,CPO0EBEN_1 = 0x00000001 // ACMP0_O as edge-detect brake source Enabled
    // Enable ACMP1_O Digital Output As Edge-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 1)
    ,CPO1EBEN_MASK = 0x00000002
    ,CPO1EBEN_POS = 1
    ,CPO1EBEN_0 = 0x00000000 // ACMP1_O as edge-detect brake source Disabled
    ,CPO1EBEN_1 = 0x00000002 // ACMP1_O as edge-detect brake source Enabled
    // Enable EPWMx_BRAKE0 Pin As Edge-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 4)
    ,BRKP0EEN_MASK = 0x00000010
    ,BRKP0EEN_POS = 4
    ,BRKP0EEN_0 = 0x00000000 // EPWMx_BRAKE0 pin as edge-detect brake source Disabled
    ,BRKP0EEN_1 = 0x00000010 // EPWMx_BRAKE0 pin as edge-detect brake source Enabled
    // Enable EPWMx_BRAKE1 Pin As Edge-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 5)
    ,BRKP1EEN_MASK = 0x00000020
    ,BRKP1EEN_POS = 5
    ,BRKP1EEN_0 = 0x00000000 // EPWMx_BRAKE1 pin as edge-detect brake source Disabled
    ,BRKP1EEN_1 = 0x00000020 // EPWMx_BRAKE1 pin as edge-detect brake source Enabled
    // Enable System Fail As Edge-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 7)
    ,SYSEBEN_MASK = 0x00000080
    ,SYSEBEN_POS = 7
    ,SYSEBEN_0 = 0x00000000 // System Fail condition as edge-detect brake source Disabled
    ,SYSEBEN_1 = 0x00000080 // System Fail condition as edge-detect brake source Enabled
    // Enable ACMP0_O Digital Output As Level-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 8)
    ,CPO0LBEN_MASK = 0x00000100
    ,CPO0LBEN_POS = 8
    ,CPO0LBEN_0 = 0x00000000 // ACMP0_O as level-detect brake source Disabled
    ,CPO0LBEN_1 = 0x00000100 // ACMP0_O as level-detect brake source Enabled
    // Enable ACMP1_O Digital Output As Level-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 9)
    ,CPO1LBEN_MASK = 0x00000200
    ,CPO1LBEN_POS = 9
    ,CPO1LBEN_0 = 0x00000000 // ACMP1_O as level-detect brake source Disabled
    ,CPO1LBEN_1 = 0x00000200 // ACMP1_O as level-detect brake source Enabled
    // Enable BKP0 Pin As Level-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 12)
    ,BRKP0LEN_MASK = 0x00001000
    ,BRKP0LEN_POS = 12
    ,BRKP0LEN_0 = 0x00000000 // EPWMx_BRAKE0 pin as level-detect brake source Disabled
    ,BRKP0LEN_1 = 0x00001000 // EPWMx_BRAKE0 pin as level-detect brake source Enabled
    // Enable BKP1 Pin As Level-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 13)
    ,BRKP1LEN_MASK = 0x00002000
    ,BRKP1LEN_POS = 13
    ,BRKP1LEN_0 = 0x00000000 // EPWMx_BRAKE1 pin as level-detect brake source Disabled
    ,BRKP1LEN_1 = 0x00002000 // EPWMx_BRAKE1 pin as level-detect brake source Enabled
    // Enable System Fail As Level-detect Brake Source (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 15)
    ,SYSLBEN_MASK = 0x00008000
    ,SYSLBEN_POS = 15
    ,SYSLBEN_0 = 0x00000000 // System Fail condition as level-detect brake source Disabled
    ,SYSLBEN_1 = 0x00008000 // System Fail condition as level-detect brake source Enabled
    // EPWM Brake Action Select for Even Channel (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 17-16)
    ,BRKAEVEN_MASK = 0x00030000
    ,BRKAEVEN_POS = 16
    ,BRKAEVEN_0 = 0x00000000 // EPWMx brake event will not affect even channels output
    ,BRKAEVEN_1 = 0x00010000 // EPWM even channel output tri-state when EPWMx brake event happened
    ,BRKAEVEN_2 = 0x00020000 // EPWM even channel output low level when EPWMx brake event happened
    ,BRKAEVEN_3 = 0x00030000 // EPWM even channel output high level when EPWMx brake event happened
    // EPWM Brake Action Select for Odd Channel (Write Protect) Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 19-18)
    ,BRKAODD_MASK = 0x000C0000
    ,BRKAODD_POS = 18
    ,BRKAODD_0 = 0x00000000 // EPWMx brake event will not affect odd channels output
    ,BRKAODD_1 = 0x00040000 // EPWM odd channel output tri-state when EPWMx brake event happened
    ,BRKAODD_2 = 0x00080000 // EPWM odd channel output low level when EPWMx brake event happened
    ,BRKAODD_3 = 0x000C0000 // EPWM odd channel output high level when EPWMx brake event happened
    // Enable EADC0 Result Monitor (EADC0RM) As Edge-detect Brake Source (Write Protect) Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 20)
    ,EADC0EBEN_MASK = 0x00100000
    ,EADC0EBEN_POS = 20
    ,EADC0EBEN_0 = 0x00000000 // EADC0RM as edge-detect brake source Disabled
    ,EADC0EBEN_1 = 0x00100000 // EADC0RM as edge-detect brake source Enabled
    // Enable EADC1 Result Monitor (EADC1RM) As Edge-detect Brake Source (Write Protect) Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 21)
    ,EADC1EBEN_MASK = 0x00200000
    ,EADC1EBEN_POS = 21
    ,EADC1EBEN_0 = 0x00000000 // EADC1RM as edge-detect brake source Disabled
    ,EADC1EBEN_1 = 0x00200000 // EADC1RM as edge-detect brake source Enabled
    // Enable EADC0 Result Monitor (EADC0RM) As Level-detect Brake Source (Write Protect) Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 28)
    ,EADC0LBEN_MASK = 0x10000000
    ,EADC0LBEN_POS = 28
    ,EADC0LBEN_0 = 0x00000000 // EADC0RM as level-detect brake source Disabled
    ,EADC0LBEN_1 = 0x10000000 // EADC0RM as level-detect brake source Enabled
    // Enable EADC1 Result Monitor (EADC1RM) As Level-detect Brake Source (Write Protect) Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 29)
    ,EADC1LBEN_MASK = 0x20000000
    ,EADC1LBEN_POS = 29
    ,EADC1LBEN_0 = 0x00000000 // EADC1RM as level-detect brake source Disabled
    ,EADC1LBEN_1 = 0x20000000 // EADC1RM as level-detect brake source Enabled
    ,BRKCTL0_1_MASK = 0x303FB3B3
    ;
  };
  // EPWM Brake Detect Control Register 2/3
  using BRKCTL2_3 = reg<ip_ver, base + 0xCC>;
  // EPWM Brake Detect Control Register 4/5
  using BRKCTL4_5 = reg<ip_ver, base + 0xD0>;
  // EPWM Pin Polar Inverse Register
  struct POLCTL : reg<ip_ver, base + 0xD4>
  {
    static constexpr typename POLCTL::type
    // EPWM PIN Polar Inverse Control The register controls polarity state of EPWMx_CHn output pin. (bits: 0)
     PINV0_MASK = 0x00000001
    ,PINV0_POS = 0
    ,PINV0_0 = 0x00000000 // EPWMx_CHn output pin polar inverse Disabled
    ,PINV0_1 = 0x00000001 // EPWMx_CHn output pin polar inverse Enabled
    // EPWM PIN Polar Inverse Control The register controls polarity state of EPWMx_CHn output pin. (bits: 1)
    ,PINV1_MASK = 0x00000002
    ,PINV1_POS = 1
    ,PINV1_0 = 0x00000000 // EPWMx_CHn output pin polar inverse Disabled
    ,PINV1_1 = 0x00000002 // EPWMx_CHn output pin polar inverse Enabled
    // EPWM PIN Polar Inverse Control The register controls polarity state of EPWMx_CHn output pin. (bits: 2)
    ,PINV2_MASK = 0x00000004
    ,PINV2_POS = 2
    ,PINV2_0 = 0x00000000 // EPWMx_CHn output pin polar inverse Disabled
    ,PINV2_1 = 0x00000004 // EPWMx_CHn output pin polar inverse Enabled
    // EPWM PIN Polar Inverse Control The register controls polarity state of EPWMx_CHn output pin. (bits: 3)
    ,PINV3_MASK = 0x00000008
    ,PINV3_POS = 3
    ,PINV3_0 = 0x00000000 // EPWMx_CHn output pin polar inverse Disabled
    ,PINV3_1 = 0x00000008 // EPWMx_CHn output pin polar inverse Enabled
    // EPWM PIN Polar Inverse Control The register controls polarity state of EPWMx_CHn output pin. (bits: 4)
    ,PINV4_MASK = 0x00000010
    ,PINV4_POS = 4
    ,PINV4_0 = 0x00000000 // EPWMx_CHn output pin polar inverse Disabled
    ,PINV4_1 = 0x00000010 // EPWMx_CHn output pin polar inverse Enabled
    // EPWM PIN Polar Inverse Control The register controls polarity state of EPWMx_CHn output pin. (bits: 5)
    ,PINV5_MASK = 0x00000020
    ,PINV5_POS = 5
    ,PINV5_0 = 0x00000000 // EPWMx_CHn output pin polar inverse Disabled
    ,PINV5_1 = 0x00000020 // EPWMx_CHn output pin polar inverse Enabled
    ,POLCTL_MASK = 0x0000003F
    ;
  };
  // EPWM Output Enable Register
  struct POEN : reg<ip_ver, base + 0xD8>
  {
    static constexpr typename POEN::type
    // EPWM Pin Output Enable Bits (bits: 0)
     POEN0_MASK = 0x00000001
    ,POEN0_POS = 0
    ,POEN0_0 = 0x00000000 // EPWMx_CHn pin at tri-state
    ,POEN0_1 = 0x00000001 // EPWMx_CHn pin in output mode
    // EPWM Pin Output Enable Bits (bits: 1)
    ,POEN1_MASK = 0x00000002
    ,POEN1_POS = 1
    ,POEN1_0 = 0x00000000 // EPWMx_CHn pin at tri-state
    ,POEN1_1 = 0x00000002 // EPWMx_CHn pin in output mode
    // EPWM Pin Output Enable Bits (bits: 2)
    ,POEN2_MASK = 0x00000004
    ,POEN2_POS = 2
    ,POEN2_0 = 0x00000000 // EPWMx_CHn pin at tri-state
    ,POEN2_1 = 0x00000004 // EPWMx_CHn pin in output mode
    // EPWM Pin Output Enable Bits (bits: 3)
    ,POEN3_MASK = 0x00000008
    ,POEN3_POS = 3
    ,POEN3_0 = 0x00000000 // EPWMx_CHn pin at tri-state
    ,POEN3_1 = 0x00000008 // EPWMx_CHn pin in output mode
    // EPWM Pin Output Enable Bits (bits: 4)
    ,POEN4_MASK = 0x00000010
    ,POEN4_POS = 4
    ,POEN4_0 = 0x00000000 // EPWMx_CHn pin at tri-state
    ,POEN4_1 = 0x00000010 // EPWMx_CHn pin in output mode
    // EPWM Pin Output Enable Bits (bits: 5)
    ,POEN5_MASK = 0x00000020
    ,POEN5_POS = 5
    ,POEN5_0 = 0x00000000 // EPWMx_CHn pin at tri-state
    ,POEN5_1 = 0x00000020 // EPWMx_CHn pin in output mode
    ,POEN_MASK = 0x0000003F
    ;
  };
  // EPWM Software Brake Control Register
  struct SWBRK : reg<ip_ver, base + 0xDC>
  {
    static constexpr typename SWBRK::type
    // EPWM Edge Brake Software Trigger (Write Only) (Write Protect) Write 1 to this bit will trigger edge brake, and set BRKEIFn to 1 in EPWM_INTSTS1 register. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 0)
     BRKETRG0_MASK = 0x00000001
    ,BRKETRG0_POS = 0
    ,BRKETRG0 = 0x00000001
    // EPWM Edge Brake Software Trigger (Write Only) (Write Protect) Write 1 to this bit will trigger edge brake, and set BRKEIFn to 1 in EPWM_INTSTS1 register. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 1)
    ,BRKETRG2_MASK = 0x00000002
    ,BRKETRG2_POS = 1
    ,BRKETRG2 = 0x00000002
    // EPWM Edge Brake Software Trigger (Write Only) (Write Protect) Write 1 to this bit will trigger edge brake, and set BRKEIFn to 1 in EPWM_INTSTS1 register. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 2)
    ,BRKETRG4_MASK = 0x00000004
    ,BRKETRG4_POS = 2
    ,BRKETRG4 = 0x00000004
    // EPWM Level Brake Software Trigger (Write Only) (Write Protect) Write 1 to this bit will trigger level brake, and set BRKLIFn to 1 in EPWM_INTSTS1 register. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 8)
    ,BRKLTRG0_MASK = 0x00000100
    ,BRKLTRG0_POS = 8
    ,BRKLTRG0 = 0x00000100
    // EPWM Level Brake Software Trigger (Write Only) (Write Protect) Write 1 to this bit will trigger level brake, and set BRKLIFn to 1 in EPWM_INTSTS1 register. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 9)
    ,BRKLTRG2_MASK = 0x00000200
    ,BRKLTRG2_POS = 9
    ,BRKLTRG2 = 0x00000200
    // EPWM Level Brake Software Trigger (Write Only) (Write Protect) Write 1 to this bit will trigger level brake, and set BRKLIFn to 1 in EPWM_INTSTS1 register. Note: This bit is write protected. Refer to SYS_REGLCTL register. (bits: 10)
    ,BRKLTRG4_MASK = 0x00000400
    ,BRKLTRG4_POS = 10
    ,BRKLTRG4 = 0x00000400
    ,SWBRK_MASK = 0x00000707
    ;
  };
  // EPWM Interrupt Enable Register 0
  struct INTEN0 : reg<ip_ver, base + 0xE0>
  {
    static constexpr typename INTEN0::type
    // EPWM Zero Point Interrupt Enable Bits Note: Odd channels will read always 0 at complementary mode. (bits: 0)
     ZIEN0_MASK = 0x00000001
    ,ZIEN0_POS = 0
    ,ZIEN0_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN0_1 = 0x00000001 // Zero point interrupt Enabled
    // EPWM Zero Point Interrupt Enable Bits Note: Odd channels will read always 0 at complementary mode. (bits: 1)
    ,ZIEN1_MASK = 0x00000002
    ,ZIEN1_POS = 1
    ,ZIEN1_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN1_1 = 0x00000002 // Zero point interrupt Enabled
    // EPWM Zero Point Interrupt Enable Bits Note: Odd channels will read always 0 at complementary mode. (bits: 2)
    ,ZIEN2_MASK = 0x00000004
    ,ZIEN2_POS = 2
    ,ZIEN2_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN2_1 = 0x00000004 // Zero point interrupt Enabled
    // EPWM Zero Point Interrupt Enable Bits Note: Odd channels will read always 0 at complementary mode. (bits: 3)
    ,ZIEN3_MASK = 0x00000008
    ,ZIEN3_POS = 3
    ,ZIEN3_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN3_1 = 0x00000008 // Zero point interrupt Enabled
    // EPWM Zero Point Interrupt Enable Bits Note: Odd channels will read always 0 at complementary mode. (bits: 4)
    ,ZIEN4_MASK = 0x00000010
    ,ZIEN4_POS = 4
    ,ZIEN4_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN4_1 = 0x00000010 // Zero point interrupt Enabled
    // EPWM Zero Point Interrupt Enable Bits Note: Odd channels will read always 0 at complementary mode. (bits: 5)
    ,ZIEN5_MASK = 0x00000020
    ,ZIEN5_POS = 5
    ,ZIEN5_0 = 0x00000000 // Zero point interrupt Disabled
    ,ZIEN5_1 = 0x00000020 // Zero point interrupt Enabled
    // EPWM Period Point Interrupt Enable Bits Note1: When up-down counter type period point means center point. Note2: Odd channels will read always 0 at complementary mode. (bits: 8)
    ,PIEN0_MASK = 0x00000100
    ,PIEN0_POS = 8
    ,PIEN0_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN0_1 = 0x00000100 // Period point interrupt Enabled
    // EPWM Period Point Interrupt Enable Bits Note1: When up-down counter type period point means center point. Note2: Odd channels will read always 0 at complementary mode. (bits: 9)
    ,PIEN1_MASK = 0x00000200
    ,PIEN1_POS = 9
    ,PIEN1_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN1_1 = 0x00000200 // Period point interrupt Enabled
    // EPWM Period Point Interrupt Enable Bits Note1: When up-down counter type period point means center point. Note2: Odd channels will read always 0 at complementary mode. (bits: 10)
    ,PIEN2_MASK = 0x00000400
    ,PIEN2_POS = 10
    ,PIEN2_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN2_1 = 0x00000400 // Period point interrupt Enabled
    // EPWM Period Point Interrupt Enable Bits Note1: When up-down counter type period point means center point. Note2: Odd channels will read always 0 at complementary mode. (bits: 11)
    ,PIEN3_MASK = 0x00000800
    ,PIEN3_POS = 11
    ,PIEN3_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN3_1 = 0x00000800 // Period point interrupt Enabled
    // EPWM Period Point Interrupt Enable Bits Note1: When up-down counter type period point means center point. Note2: Odd channels will read always 0 at complementary mode. (bits: 12)
    ,PIEN4_MASK = 0x00001000
    ,PIEN4_POS = 12
    ,PIEN4_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN4_1 = 0x00001000 // Period point interrupt Enabled
    // EPWM Period Point Interrupt Enable Bits Note1: When up-down counter type period point means center point. Note2: Odd channels will read always 0 at complementary mode. (bits: 13)
    ,PIEN5_MASK = 0x00002000
    ,PIEN5_POS = 13
    ,PIEN5_0 = 0x00000000 // Period point interrupt Disabled
    ,PIEN5_1 = 0x00002000 // Period point interrupt Enabled
    // EPWM Compare Up Count Interrupt Enable Bits Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4. (bits: 16)
    ,CMPUIEN0_MASK = 0x00010000
    ,CMPUIEN0_POS = 16
    ,CMPUIEN0_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN0_1 = 0x00010000 // Compare up count interrupt Enabled
    // EPWM Compare Up Count Interrupt Enable Bits Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4. (bits: 17)
    ,CMPUIEN1_MASK = 0x00020000
    ,CMPUIEN1_POS = 17
    ,CMPUIEN1_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN1_1 = 0x00020000 // Compare up count interrupt Enabled
    // EPWM Compare Up Count Interrupt Enable Bits Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4. (bits: 18)
    ,CMPUIEN2_MASK = 0x00040000
    ,CMPUIEN2_POS = 18
    ,CMPUIEN2_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN2_1 = 0x00040000 // Compare up count interrupt Enabled
    // EPWM Compare Up Count Interrupt Enable Bits Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4. (bits: 19)
    ,CMPUIEN3_MASK = 0x00080000
    ,CMPUIEN3_POS = 19
    ,CMPUIEN3_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN3_1 = 0x00080000 // Compare up count interrupt Enabled
    // EPWM Compare Up Count Interrupt Enable Bits Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4. (bits: 20)
    ,CMPUIEN4_MASK = 0x00100000
    ,CMPUIEN4_POS = 20
    ,CMPUIEN4_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN4_1 = 0x00100000 // Compare up count interrupt Enabled
    // EPWM Compare Up Count Interrupt Enable Bits Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4. (bits: 21)
    ,CMPUIEN5_MASK = 0x00200000
    ,CMPUIEN5_POS = 21
    ,CMPUIEN5_0 = 0x00000000 // Compare up count interrupt Disabled
    ,CMPUIEN5_1 = 0x00200000 // Compare up count interrupt Enabled
    // EPWM Compare Down Count Interrupt Enable Bits Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4. (bits: 24)
    ,CMPDIEN0_MASK = 0x01000000
    ,CMPDIEN0_POS = 24
    ,CMPDIEN0_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN0_1 = 0x01000000 // Compare down count interrupt Enabled
    // EPWM Compare Down Count Interrupt Enable Bits Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4. (bits: 25)
    ,CMPDIEN1_MASK = 0x02000000
    ,CMPDIEN1_POS = 25
    ,CMPDIEN1_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN1_1 = 0x02000000 // Compare down count interrupt Enabled
    // EPWM Compare Down Count Interrupt Enable Bits Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4. (bits: 26)
    ,CMPDIEN2_MASK = 0x04000000
    ,CMPDIEN2_POS = 26
    ,CMPDIEN2_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN2_1 = 0x04000000 // Compare down count interrupt Enabled
    // EPWM Compare Down Count Interrupt Enable Bits Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4. (bits: 27)
    ,CMPDIEN3_MASK = 0x08000000
    ,CMPDIEN3_POS = 27
    ,CMPDIEN3_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN3_1 = 0x08000000 // Compare down count interrupt Enabled
    // EPWM Compare Down Count Interrupt Enable Bits Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4. (bits: 28)
    ,CMPDIEN4_MASK = 0x10000000
    ,CMPDIEN4_POS = 28
    ,CMPDIEN4_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN4_1 = 0x10000000 // Compare down count interrupt Enabled
    // EPWM Compare Down Count Interrupt Enable Bits Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4. (bits: 29)
    ,CMPDIEN5_MASK = 0x20000000
    ,CMPDIEN5_POS = 29
    ,CMPDIEN5_0 = 0x00000000 // Compare down count interrupt Disabled
    ,CMPDIEN5_1 = 0x20000000 // Compare down count interrupt Enabled
    ,INTEN0_MASK = 0x3F3F3F3F
    ;
  };
  // EPWM Interrupt Enable Register 1
  struct INTEN1 : reg<ip_ver, base + 0xE4>
  {
    static constexpr typename INTEN1::type
    // EPWM Edge-detect Brake Interrupt Enable for Channel0/1 (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 0)
     BRKEIEN0_1_MASK = 0x00000001
    ,BRKEIEN0_1_POS = 0
    ,BRKEIEN0_1_0 = 0x00000000 // Edge-detect Brake interrupt for channel0/1 Disabled
    ,BRKEIEN0_1_1 = 0x00000001 // Edge-detect Brake interrupt for channel0/1 Enabled
    // EPWM Edge-detect Brake Interrupt Enable for Channel2/3 (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 1)
    ,BRKEIEN2_3_MASK = 0x00000002
    ,BRKEIEN2_3_POS = 1
    ,BRKEIEN2_3_0 = 0x00000000 // Edge-detect Brake interrupt for channel2/3 Disabled
    ,BRKEIEN2_3_1 = 0x00000002 // Edge-detect Brake interrupt for channel2/3 Enabled
    // EPWM Edge-detect Brake Interrupt Enable for Channel4/5 (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 2)
    ,BRKEIEN4_5_MASK = 0x00000004
    ,BRKEIEN4_5_POS = 2
    ,BRKEIEN4_5_0 = 0x00000000 // Edge-detect Brake interrupt for channel4/5 Disabled
    ,BRKEIEN4_5_1 = 0x00000004 // Edge-detect Brake interrupt for channel4/5 Enabled
    // EPWM Level-detect Brake Interrupt Enable for Channel0/1 (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 8)
    ,BRKLIEN0_1_MASK = 0x00000100
    ,BRKLIEN0_1_POS = 8
    ,BRKLIEN0_1_0 = 0x00000000 // Level-detect Brake interrupt for channel0/1 Disabled
    ,BRKLIEN0_1_1 = 0x00000100 // Level-detect Brake interrupt for channel0/1 Enabled
    // EPWM Level-detect Brake Interrupt Enable for Channel2/3 (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 9)
    ,BRKLIEN2_3_MASK = 0x00000200
    ,BRKLIEN2_3_POS = 9
    ,BRKLIEN2_3_0 = 0x00000000 // Level-detect Brake interrupt for channel2/3 Disabled
    ,BRKLIEN2_3_1 = 0x00000200 // Level-detect Brake interrupt for channel2/3 Enabled
    // EPWM Level-detect Brake Interrupt Enable for Channel4/5 (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 10)
    ,BRKLIEN4_5_MASK = 0x00000400
    ,BRKLIEN4_5_POS = 10
    ,BRKLIEN4_5_0 = 0x00000000 // Level-detect Brake interrupt for channel4/5 Disabled
    ,BRKLIEN4_5_1 = 0x00000400 // Level-detect Brake interrupt for channel4/5 Enabled
    ,INTEN1_MASK = 0x00000707
    ;
  };
  // EPWM Interrupt Flag Register 0
  struct INTSTS0 : reg<ip_ver, base + 0xE8>
  {
    static constexpr typename INTSTS0::type
    // EPWM Zero Point Interrupt Flag This bit is set by hardware when EPWM counter reaches 0. Note: This bit can be cleared to 0 by software writing 1 (bits: 0)
     ZIF0_MASK = 0x00000001
    ,ZIF0_POS = 0
    ,ZIF0 = 0x00000001
    // EPWM Zero Point Interrupt Flag This bit is set by hardware when EPWM counter reaches 0. Note: This bit can be cleared to 0 by software writing 1 (bits: 1)
    ,ZIF1_MASK = 0x00000002
    ,ZIF1_POS = 1
    ,ZIF1 = 0x00000002
    // EPWM Zero Point Interrupt Flag This bit is set by hardware when EPWM counter reaches 0. Note: This bit can be cleared to 0 by software writing 1 (bits: 2)
    ,ZIF2_MASK = 0x00000004
    ,ZIF2_POS = 2
    ,ZIF2 = 0x00000004
    // EPWM Zero Point Interrupt Flag This bit is set by hardware when EPWM counter reaches 0. Note: This bit can be cleared to 0 by software writing 1 (bits: 3)
    ,ZIF3_MASK = 0x00000008
    ,ZIF3_POS = 3
    ,ZIF3 = 0x00000008
    // EPWM Zero Point Interrupt Flag This bit is set by hardware when EPWM counter reaches 0. Note: This bit can be cleared to 0 by software writing 1 (bits: 4)
    ,ZIF4_MASK = 0x00000010
    ,ZIF4_POS = 4
    ,ZIF4 = 0x00000010
    // EPWM Zero Point Interrupt Flag This bit is set by hardware when EPWM counter reaches 0. Note: This bit can be cleared to 0 by software writing 1 (bits: 5)
    ,ZIF5_MASK = 0x00000020
    ,ZIF5_POS = 5
    ,ZIF5 = 0x00000020
    // EPWM Period Point Interrupt Flag This bit is set by hardware when EPWM counter reaches EPWM_PERIODn. Note: This bit can be cleared to 0 by software writing 1. (bits: 8)
    ,PIF0_MASK = 0x00000100
    ,PIF0_POS = 8
    ,PIF0 = 0x00000100
    // EPWM Period Point Interrupt Flag This bit is set by hardware when EPWM counter reaches EPWM_PERIODn. Note: This bit can be cleared to 0 by software writing 1. (bits: 9)
    ,PIF1_MASK = 0x00000200
    ,PIF1_POS = 9
    ,PIF1 = 0x00000200
    // EPWM Period Point Interrupt Flag This bit is set by hardware when EPWM counter reaches EPWM_PERIODn. Note: This bit can be cleared to 0 by software writing 1. (bits: 10)
    ,PIF2_MASK = 0x00000400
    ,PIF2_POS = 10
    ,PIF2 = 0x00000400
    // EPWM Period Point Interrupt Flag This bit is set by hardware when EPWM counter reaches EPWM_PERIODn. Note: This bit can be cleared to 0 by software writing 1. (bits: 11)
    ,PIF3_MASK = 0x00000800
    ,PIF3_POS = 11
    ,PIF3 = 0x00000800
    // EPWM Period Point Interrupt Flag This bit is set by hardware when EPWM counter reaches EPWM_PERIODn. Note: This bit can be cleared to 0 by software writing 1. (bits: 12)
    ,PIF4_MASK = 0x00001000
    ,PIF4_POS = 12
    ,PIF4 = 0x00001000
    // EPWM Period Point Interrupt Flag This bit is set by hardware when EPWM counter reaches EPWM_PERIODn. Note: This bit can be cleared to 0 by software writing 1. (bits: 13)
    ,PIF5_MASK = 0x00002000
    ,PIF5_POS = 13
    ,PIF5 = 0x00002000
    // EPWM Compare Up Count Interrupt Flag Flag is set by hardware when EPWM counter up count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPUIF1, 3, 5 is used as another CMPUIF for channel 0, 2, 4. (bits: 16)
    ,CMPUIF0_MASK = 0x00010000
    ,CMPUIF0_POS = 16
    ,CMPUIF0 = 0x00010000
    // EPWM Compare Up Count Interrupt Flag Flag is set by hardware when EPWM counter up count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPUIF1, 3, 5 is used as another CMPUIF for channel 0, 2, 4. (bits: 17)
    ,CMPUIF1_MASK = 0x00020000
    ,CMPUIF1_POS = 17
    ,CMPUIF1 = 0x00020000
    // EPWM Compare Up Count Interrupt Flag Flag is set by hardware when EPWM counter up count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPUIF1, 3, 5 is used as another CMPUIF for channel 0, 2, 4. (bits: 18)
    ,CMPUIF2_MASK = 0x00040000
    ,CMPUIF2_POS = 18
    ,CMPUIF2 = 0x00040000
    // EPWM Compare Up Count Interrupt Flag Flag is set by hardware when EPWM counter up count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPUIF1, 3, 5 is used as another CMPUIF for channel 0, 2, 4. (bits: 19)
    ,CMPUIF3_MASK = 0x00080000
    ,CMPUIF3_POS = 19
    ,CMPUIF3 = 0x00080000
    // EPWM Compare Up Count Interrupt Flag Flag is set by hardware when EPWM counter up count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPUIF1, 3, 5 is used as another CMPUIF for channel 0, 2, 4. (bits: 20)
    ,CMPUIF4_MASK = 0x00100000
    ,CMPUIF4_POS = 20
    ,CMPUIF4 = 0x00100000
    // EPWM Compare Up Count Interrupt Flag Flag is set by hardware when EPWM counter up count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPUIF1, 3, 5 is used as another CMPUIF for channel 0, 2, 4. (bits: 21)
    ,CMPUIF5_MASK = 0x00200000
    ,CMPUIF5_POS = 21
    ,CMPUIF5 = 0x00200000
    // EPWM Compare Down Count Interrupt Flag Flag is set by hardware when EPWM counter down count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4. (bits: 24)
    ,CMPDIF0_MASK = 0x01000000
    ,CMPDIF0_POS = 24
    ,CMPDIF0 = 0x01000000
    // EPWM Compare Down Count Interrupt Flag Flag is set by hardware when EPWM counter down count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4. (bits: 25)
    ,CMPDIF1_MASK = 0x02000000
    ,CMPDIF1_POS = 25
    ,CMPDIF1 = 0x02000000
    // EPWM Compare Down Count Interrupt Flag Flag is set by hardware when EPWM counter down count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4. (bits: 26)
    ,CMPDIF2_MASK = 0x04000000
    ,CMPDIF2_POS = 26
    ,CMPDIF2 = 0x04000000
    // EPWM Compare Down Count Interrupt Flag Flag is set by hardware when EPWM counter down count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4. (bits: 27)
    ,CMPDIF3_MASK = 0x08000000
    ,CMPDIF3_POS = 27
    ,CMPDIF3 = 0x08000000
    // EPWM Compare Down Count Interrupt Flag Flag is set by hardware when EPWM counter down count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4. (bits: 28)
    ,CMPDIF4_MASK = 0x10000000
    ,CMPDIF4_POS = 28
    ,CMPDIF4 = 0x10000000
    // EPWM Compare Down Count Interrupt Flag Flag is set by hardware when EPWM counter down count and reaches EPWM_CMPDATn, software can clear this bit by writing 1 to it. Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4. (bits: 29)
    ,CMPDIF5_MASK = 0x20000000
    ,CMPDIF5_POS = 29
    ,CMPDIF5 = 0x20000000
    ,INTSTS0_MASK = 0x3F3F3F3F
    ;
  };
  // EPWM Interrupt Flag Register 1
  struct INTSTS1 : reg<ip_ver, base + 0xEC>
  {
    static constexpr typename INTSTS1::type
    // EPWM Channel N Edge-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 0)
     BRKEIF0_MASK = 0x00000001
    ,BRKEIF0_POS = 0
    ,BRKEIF0_0 = 0x00000000 // EPWM channel n edge-detect brake event do not happened
    ,BRKEIF0_1 = 0x00000001 // When EPWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Edge-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 1)
    ,BRKEIF1_MASK = 0x00000002
    ,BRKEIF1_POS = 1
    ,BRKEIF1_0 = 0x00000000 // EPWM channel n edge-detect brake event do not happened
    ,BRKEIF1_1 = 0x00000002 // When EPWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Edge-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 2)
    ,BRKEIF2_MASK = 0x00000004
    ,BRKEIF2_POS = 2
    ,BRKEIF2_0 = 0x00000000 // EPWM channel n edge-detect brake event do not happened
    ,BRKEIF2_1 = 0x00000004 // When EPWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Edge-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 3)
    ,BRKEIF3_MASK = 0x00000008
    ,BRKEIF3_POS = 3
    ,BRKEIF3_0 = 0x00000000 // EPWM channel n edge-detect brake event do not happened
    ,BRKEIF3_1 = 0x00000008 // When EPWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Edge-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 4)
    ,BRKEIF4_MASK = 0x00000010
    ,BRKEIF4_POS = 4
    ,BRKEIF4_0 = 0x00000000 // EPWM channel n edge-detect brake event do not happened
    ,BRKEIF4_1 = 0x00000010 // When EPWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Edge-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 5)
    ,BRKEIF5_MASK = 0x00000020
    ,BRKEIF5_POS = 5
    ,BRKEIF5_0 = 0x00000000 // EPWM channel n edge-detect brake event do not happened
    ,BRKEIF5_1 = 0x00000020 // When EPWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Level-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 8)
    ,BRKLIF0_MASK = 0x00000100
    ,BRKLIF0_POS = 8
    ,BRKLIF0_0 = 0x00000000 // EPWM channel n level-detect brake event do not happened
    ,BRKLIF0_1 = 0x00000100 // When EPWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Level-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 9)
    ,BRKLIF1_MASK = 0x00000200
    ,BRKLIF1_POS = 9
    ,BRKLIF1_0 = 0x00000000 // EPWM channel n level-detect brake event do not happened
    ,BRKLIF1_1 = 0x00000200 // When EPWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Level-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 10)
    ,BRKLIF2_MASK = 0x00000400
    ,BRKLIF2_POS = 10
    ,BRKLIF2_0 = 0x00000000 // EPWM channel n level-detect brake event do not happened
    ,BRKLIF2_1 = 0x00000400 // When EPWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Level-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 11)
    ,BRKLIF3_MASK = 0x00000800
    ,BRKLIF3_POS = 11
    ,BRKLIF3_0 = 0x00000000 // EPWM channel n level-detect brake event do not happened
    ,BRKLIF3_1 = 0x00000800 // When EPWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Level-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 12)
    ,BRKLIF4_MASK = 0x00001000
    ,BRKLIF4_POS = 12
    ,BRKLIF4_0 = 0x00000000 // EPWM channel n level-detect brake event do not happened
    ,BRKLIF4_1 = 0x00001000 // When EPWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Level-detect Brake Interrupt Flag (Write Protect) Note: This bit is write protected. Refer toSYS_REGLCTL register. (bits: 13)
    ,BRKLIF5_MASK = 0x00002000
    ,BRKLIF5_POS = 13
    ,BRKLIF5_0 = 0x00000000 // EPWM channel n level-detect brake event do not happened
    ,BRKLIF5_1 = 0x00002000 // When EPWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear
    // EPWM Channel N Edge-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When edge-detect brake interrupt flag is cleared, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 16)
    ,BRKESTS0_MASK = 0x00010000
    ,BRKESTS0_POS = 16
    ,BRKESTS0_0 = 0x00000000 // EPWM channel n edge-detect brake state is released
    ,BRKESTS0_1 = 0x00010000 // When EPWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Edge-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When edge-detect brake interrupt flag is cleared, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 17)
    ,BRKESTS1_MASK = 0x00020000
    ,BRKESTS1_POS = 17
    ,BRKESTS1_0 = 0x00000000 // EPWM channel n edge-detect brake state is released
    ,BRKESTS1_1 = 0x00020000 // When EPWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Edge-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When edge-detect brake interrupt flag is cleared, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 18)
    ,BRKESTS2_MASK = 0x00040000
    ,BRKESTS2_POS = 18
    ,BRKESTS2_0 = 0x00000000 // EPWM channel n edge-detect brake state is released
    ,BRKESTS2_1 = 0x00040000 // When EPWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Edge-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When edge-detect brake interrupt flag is cleared, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 19)
    ,BRKESTS3_MASK = 0x00080000
    ,BRKESTS3_POS = 19
    ,BRKESTS3_0 = 0x00000000 // EPWM channel n edge-detect brake state is released
    ,BRKESTS3_1 = 0x00080000 // When EPWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Edge-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When edge-detect brake interrupt flag is cleared, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 20)
    ,BRKESTS4_MASK = 0x00100000
    ,BRKESTS4_POS = 20
    ,BRKESTS4_0 = 0x00000000 // EPWM channel n edge-detect brake state is released
    ,BRKESTS4_1 = 0x00100000 // When EPWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Edge-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When edge-detect brake interrupt flag is cleared, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 21)
    ,BRKESTS5_MASK = 0x00200000
    ,BRKESTS5_POS = 21
    ,BRKESTS5_0 = 0x00000000 // EPWM channel n edge-detect brake state is released
    ,BRKESTS5_1 = 0x00200000 // When EPWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Level-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 24)
    ,BRKLSTS0_MASK = 0x01000000
    ,BRKLSTS0_POS = 24
    ,BRKLSTS0_0 = 0x00000000 // EPWM channel n level-detect brake state is released
    ,BRKLSTS0_1 = 0x01000000 // When EPWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Level-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 25)
    ,BRKLSTS1_MASK = 0x02000000
    ,BRKLSTS1_POS = 25
    ,BRKLSTS1_0 = 0x00000000 // EPWM channel n level-detect brake state is released
    ,BRKLSTS1_1 = 0x02000000 // When EPWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Level-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 26)
    ,BRKLSTS2_MASK = 0x04000000
    ,BRKLSTS2_POS = 26
    ,BRKLSTS2_0 = 0x00000000 // EPWM channel n level-detect brake state is released
    ,BRKLSTS2_1 = 0x04000000 // When EPWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Level-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 27)
    ,BRKLSTS3_MASK = 0x08000000
    ,BRKLSTS3_POS = 27
    ,BRKLSTS3_0 = 0x00000000 // EPWM channel n level-detect brake state is released
    ,BRKLSTS3_1 = 0x08000000 // When EPWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Level-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 28)
    ,BRKLSTS4_MASK = 0x10000000
    ,BRKLSTS4_POS = 28
    ,BRKLSTS4_0 = 0x00000000 // EPWM channel n level-detect brake state is released
    ,BRKLSTS4_1 = 0x10000000 // When EPWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    // EPWM Channel N Level-detect Brake Status (Read Only) Note: This bit is read only and auto cleared by hardware. When enabled brake source return to high level, EPWM will release brake state until current EPWM period finished. The EPWM waveform will start output from next full EPWM period. (bits: 29)
    ,BRKLSTS5_MASK = 0x20000000
    ,BRKLSTS5_POS = 29
    ,BRKLSTS5_0 = 0x00000000 // EPWM channel n level-detect brake state is released
    ,BRKLSTS5_1 = 0x20000000 // When EPWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the EPWM channel n at brake state
    ,INTSTS1_MASK = 0x3F3F3F3F
    ;
  };
  // EPWM Trigger DAC Enable Register
  struct DACTRGEN : reg<ip_ver, base + 0xF4>
  {
    static constexpr typename DACTRGEN::type
    // EPWM Zero Point Trigger DAC Enable Bits EPWM can trigger EADC/DAC/DMA to start action when EPWM counter down count to zero if this bit is set to1. (bits: 0)
     ZTE0_MASK = 0x00000001
    ,ZTE0_POS = 0
    ,ZTE0_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,ZTE0_1 = 0x00000001 // EPWM period point trigger DAC function Enabled
    // EPWM Zero Point Trigger DAC Enable Bits EPWM can trigger EADC/DAC/DMA to start action when EPWM counter down count to zero if this bit is set to1. (bits: 1)
    ,ZTE1_MASK = 0x00000002
    ,ZTE1_POS = 1
    ,ZTE1_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,ZTE1_1 = 0x00000002 // EPWM period point trigger DAC function Enabled
    // EPWM Zero Point Trigger DAC Enable Bits EPWM can trigger EADC/DAC/DMA to start action when EPWM counter down count to zero if this bit is set to1. (bits: 2)
    ,ZTE2_MASK = 0x00000004
    ,ZTE2_POS = 2
    ,ZTE2_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,ZTE2_1 = 0x00000004 // EPWM period point trigger DAC function Enabled
    // EPWM Zero Point Trigger DAC Enable Bits EPWM can trigger EADC/DAC/DMA to start action when EPWM counter down count to zero if this bit is set to1. (bits: 3)
    ,ZTE3_MASK = 0x00000008
    ,ZTE3_POS = 3
    ,ZTE3_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,ZTE3_1 = 0x00000008 // EPWM period point trigger DAC function Enabled
    // EPWM Zero Point Trigger DAC Enable Bits EPWM can trigger EADC/DAC/DMA to start action when EPWM counter down count to zero if this bit is set to1. (bits: 4)
    ,ZTE4_MASK = 0x00000010
    ,ZTE4_POS = 4
    ,ZTE4_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,ZTE4_1 = 0x00000010 // EPWM period point trigger DAC function Enabled
    // EPWM Zero Point Trigger DAC Enable Bits EPWM can trigger EADC/DAC/DMA to start action when EPWM counter down count to zero if this bit is set to1. (bits: 5)
    ,ZTE5_MASK = 0x00000020
    ,ZTE5_POS = 5
    ,ZTE5_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,ZTE5_1 = 0x00000020 // EPWM period point trigger DAC function Enabled
    // EPWM Period Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to (PERIODn+1) if this bit is set to1. (bits: 8)
    ,PTE0_MASK = 0x00000100
    ,PTE0_POS = 8
    ,PTE0_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,PTE0_1 = 0x00000100 // EPWM period point trigger DAC function Enabled
    // EPWM Period Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to (PERIODn+1) if this bit is set to1. (bits: 9)
    ,PTE1_MASK = 0x00000200
    ,PTE1_POS = 9
    ,PTE1_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,PTE1_1 = 0x00000200 // EPWM period point trigger DAC function Enabled
    // EPWM Period Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to (PERIODn+1) if this bit is set to1. (bits: 10)
    ,PTE2_MASK = 0x00000400
    ,PTE2_POS = 10
    ,PTE2_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,PTE2_1 = 0x00000400 // EPWM period point trigger DAC function Enabled
    // EPWM Period Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to (PERIODn+1) if this bit is set to1. (bits: 11)
    ,PTE3_MASK = 0x00000800
    ,PTE3_POS = 11
    ,PTE3_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,PTE3_1 = 0x00000800 // EPWM period point trigger DAC function Enabled
    // EPWM Period Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to (PERIODn+1) if this bit is set to1. (bits: 12)
    ,PTE4_MASK = 0x00001000
    ,PTE4_POS = 12
    ,PTE4_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,PTE4_1 = 0x00001000 // EPWM period point trigger DAC function Enabled
    // EPWM Period Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to (PERIODn+1) if this bit is set to1. (bits: 13)
    ,PTE5_MASK = 0x00002000
    ,PTE5_POS = 13
    ,PTE5_0 = 0x00000000 // EPWM period point trigger DAC function Disabled
    ,PTE5_1 = 0x00002000 // EPWM period point trigger DAC function Enabled
    // EPWM Compare Up Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in down counter type. Note2: In complementary mode, CUTRGEN1, 3, 5 is used as another CUTRGEN for channel 0, 2, 4. (bits: 16)
    ,CUTRGEN0_MASK = 0x00010000
    ,CUTRGEN0_POS = 16
    ,CUTRGEN0_0 = 0x00000000 // EPWM Compare Up point trigger DAC function Disabled
    ,CUTRGEN0_1 = 0x00010000 // EPWM Compare Up point trigger DAC function Enabled
    // EPWM Compare Up Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in down counter type. Note2: In complementary mode, CUTRGEN1, 3, 5 is used as another CUTRGEN for channel 0, 2, 4. (bits: 17)
    ,CUTRGEN1_MASK = 0x00020000
    ,CUTRGEN1_POS = 17
    ,CUTRGEN1_0 = 0x00000000 // EPWM Compare Up point trigger DAC function Disabled
    ,CUTRGEN1_1 = 0x00020000 // EPWM Compare Up point trigger DAC function Enabled
    // EPWM Compare Up Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in down counter type. Note2: In complementary mode, CUTRGEN1, 3, 5 is used as another CUTRGEN for channel 0, 2, 4. (bits: 18)
    ,CUTRGEN2_MASK = 0x00040000
    ,CUTRGEN2_POS = 18
    ,CUTRGEN2_0 = 0x00000000 // EPWM Compare Up point trigger DAC function Disabled
    ,CUTRGEN2_1 = 0x00040000 // EPWM Compare Up point trigger DAC function Enabled
    // EPWM Compare Up Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in down counter type. Note2: In complementary mode, CUTRGEN1, 3, 5 is used as another CUTRGEN for channel 0, 2, 4. (bits: 19)
    ,CUTRGEN3_MASK = 0x00080000
    ,CUTRGEN3_POS = 19
    ,CUTRGEN3_0 = 0x00000000 // EPWM Compare Up point trigger DAC function Disabled
    ,CUTRGEN3_1 = 0x00080000 // EPWM Compare Up point trigger DAC function Enabled
    // EPWM Compare Up Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in down counter type. Note2: In complementary mode, CUTRGEN1, 3, 5 is used as another CUTRGEN for channel 0, 2, 4. (bits: 20)
    ,CUTRGEN4_MASK = 0x00100000
    ,CUTRGEN4_POS = 20
    ,CUTRGEN4_0 = 0x00000000 // EPWM Compare Up point trigger DAC function Disabled
    ,CUTRGEN4_1 = 0x00100000 // EPWM Compare Up point trigger DAC function Enabled
    // EPWM Compare Up Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter counts up to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in down counter type. Note2: In complementary mode, CUTRGEN1, 3, 5 is used as another CUTRGEN for channel 0, 2, 4. (bits: 21)
    ,CUTRGEN5_MASK = 0x00200000
    ,CUTRGEN5_POS = 21
    ,CUTRGEN5_0 = 0x00000000 // EPWM Compare Up point trigger DAC function Disabled
    ,CUTRGEN5_1 = 0x00200000 // EPWM Compare Up point trigger DAC function Enabled
    // EPWM Compare Down Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter down count to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in up counter type. Note2: In complementary mode, CDTRGEN1, 3, 5 is used as another CDTRGEN for channel 0, 2, 4. (bits: 24)
    ,CDTRGEN0_MASK = 0x01000000
    ,CDTRGEN0_POS = 24
    ,CDTRGEN0_0 = 0x00000000 // EPWM Compare Down count point trigger DAC function Disabled
    ,CDTRGEN0_1 = 0x01000000 // EPWM Compare Down count point trigger DAC function Enabled
    // EPWM Compare Down Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter down count to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in up counter type. Note2: In complementary mode, CDTRGEN1, 3, 5 is used as another CDTRGEN for channel 0, 2, 4. (bits: 25)
    ,CDTRGEN1_MASK = 0x02000000
    ,CDTRGEN1_POS = 25
    ,CDTRGEN1_0 = 0x00000000 // EPWM Compare Down count point trigger DAC function Disabled
    ,CDTRGEN1_1 = 0x02000000 // EPWM Compare Down count point trigger DAC function Enabled
    // EPWM Compare Down Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter down count to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in up counter type. Note2: In complementary mode, CDTRGEN1, 3, 5 is used as another CDTRGEN for channel 0, 2, 4. (bits: 26)
    ,CDTRGEN2_MASK = 0x04000000
    ,CDTRGEN2_POS = 26
    ,CDTRGEN2_0 = 0x00000000 // EPWM Compare Down count point trigger DAC function Disabled
    ,CDTRGEN2_1 = 0x04000000 // EPWM Compare Down count point trigger DAC function Enabled
    // EPWM Compare Down Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter down count to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in up counter type. Note2: In complementary mode, CDTRGEN1, 3, 5 is used as another CDTRGEN for channel 0, 2, 4. (bits: 27)
    ,CDTRGEN3_MASK = 0x08000000
    ,CDTRGEN3_POS = 27
    ,CDTRGEN3_0 = 0x00000000 // EPWM Compare Down count point trigger DAC function Disabled
    ,CDTRGEN3_1 = 0x08000000 // EPWM Compare Down count point trigger DAC function Enabled
    // EPWM Compare Down Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter down count to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in up counter type. Note2: In complementary mode, CDTRGEN1, 3, 5 is used as another CDTRGEN for channel 0, 2, 4. (bits: 28)
    ,CDTRGEN4_MASK = 0x10000000
    ,CDTRGEN4_POS = 28
    ,CDTRGEN4_0 = 0x00000000 // EPWM Compare Down count point trigger DAC function Disabled
    ,CDTRGEN4_1 = 0x10000000 // EPWM Compare Down count point trigger DAC function Enabled
    // EPWM Compare Down Count Point Trigger DAC Enable Bits EPWM can trigger DAC to start action when EPWM counter down count to CMP if this bit is set to1. Note1: This bit should keep at 0 when EPWM counter operating in up counter type. Note2: In complementary mode, CDTRGEN1, 3, 5 is used as another CDTRGEN for channel 0, 2, 4. (bits: 29)
    ,CDTRGEN5_MASK = 0x20000000
    ,CDTRGEN5_POS = 29
    ,CDTRGEN5_0 = 0x00000000 // EPWM Compare Down count point trigger DAC function Disabled
    ,CDTRGEN5_1 = 0x20000000 // EPWM Compare Down count point trigger DAC function Enabled
    ,DACTRGEN_MASK = 0x3F3F3F3F
    ;
  };
  // EPWM Trigger EADC Source Select Register 0
  struct EADCTS0 : reg<ip_ver, base + 0xF8>
  {
    static constexpr typename EADCTS0::type
    // EPWM_CH0 Trigger EADC Source Select (bits: 3-0)
     TRGSEL0_MASK = 0x0000000F
    ,TRGSEL0_POS = 0
    ,TRGSEL0_0 = 0x00000000 // EPWM_CH0 zero point
    ,TRGSEL0_1 = 0x00000001 // EPWM_CH0 period point
    ,TRGSEL0_2 = 0x00000002 // EPWM_CH0 zero or period point
    ,TRGSEL0_3 = 0x00000003 // EPWM_CH0 up-count compared point
    ,TRGSEL0_4 = 0x00000004 // EPWM_CH0 down-count compared point
    ,TRGSEL0_5 = 0x00000005 // EPWM_CH1 zero point
    ,TRGSEL0_6 = 0x00000006 // EPWM_CH1 period point
    ,TRGSEL0_7 = 0x00000007 // EPWM_CH1 zero or period point
    ,TRGSEL0_8 = 0x00000008 // EPWM_CH1 up-count compared point
    ,TRGSEL0_9 = 0x00000009 // EPWM_CH1 down-count compared point
    ,TRGSEL0_10 = 0x0000000A // EPWM_CH0 up-count free trigger compared point
    ,TRGSEL0_11 = 0x0000000B // EPWM_CH0 down-count free trigger compared point
    ,TRGSEL0_12 = 0x0000000C // EPWM_CH2 up-count free trigger compared point
    ,TRGSEL0_13 = 0x0000000D // EPWM_CH2 down-count free trigger compared point
    ,TRGSEL0_14 = 0x0000000E // EPWM_CH4 up-count free trigger compared point
    ,TRGSEL0_15 = 0x0000000F // EPWM_CH4 down-count free trigger compared point
    // EPWM_CH0 Trigger EADC Enable Bit (bits: 7)
    ,TRGEN0_MASK = 0x00000080
    ,TRGEN0_POS = 7
    ,TRGEN0_0 = 0x00000000 // EPWM_CH0 Trigger EADC function Disabled
    ,TRGEN0_1 = 0x00000080 // EPWM_CH0 Trigger EADC function Enabled
    // EPWM_CH1 Trigger EADC Source Select (bits: 11-8)
    ,TRGSEL1_MASK = 0x00000F00
    ,TRGSEL1_POS = 8
    ,TRGSEL1_0 = 0x00000000 // EPWM_CH0 zero point
    ,TRGSEL1_1 = 0x00000100 // EPWM_CH0 period point
    ,TRGSEL1_2 = 0x00000200 // EPWM_CH0 zero or period point
    ,TRGSEL1_3 = 0x00000300 // EPWM_CH0 up-count compared point
    ,TRGSEL1_4 = 0x00000400 // EPWM_CH0 down-count compared point
    ,TRGSEL1_5 = 0x00000500 // EPWM_CH1 zero point
    ,TRGSEL1_6 = 0x00000600 // EPWM_CH1 period point
    ,TRGSEL1_7 = 0x00000700 // EPWM_CH1 zero or period point
    ,TRGSEL1_8 = 0x00000800 // EPWM_CH1 up-count compared point
    ,TRGSEL1_9 = 0x00000900 // EPWM_CH1 down-count compared point
    ,TRGSEL1_10 = 0x00000A00 // EPWM_CH0 up-count free trigger compared point
    ,TRGSEL1_11 = 0x00000B00 // EPWM_CH0 down-count free trigger compared point
    ,TRGSEL1_12 = 0x00000C00 // EPWM_CH2 up-count free trigger compared point
    ,TRGSEL1_13 = 0x00000D00 // EPWM_CH2 down-count free trigger compared point
    ,TRGSEL1_14 = 0x00000E00 // EPWM_CH4 up-count free trigger compared point
    ,TRGSEL1_15 = 0x00000F00 // EPWM_CH4 down-count free trigger compared point
    // EPWM_CH1 Trigger EADC Enable Bit (bits: 15)
    ,TRGEN1_MASK = 0x00008000
    ,TRGEN1_POS = 15
    ,TRGEN1_0 = 0x00000000 // EPWM_CH1 Trigger EADC function Disabled
    ,TRGEN1_1 = 0x00008000 // EPWM_CH1 Trigger EADC function Enabled
    // EPWM_CH2 Trigger EADC Source Select (bits: 19-16)
    ,TRGSEL2_MASK = 0x000F0000
    ,TRGSEL2_POS = 16
    ,TRGSEL2_0 = 0x00000000 // EPWM_CH2 zero point
    ,TRGSEL2_1 = 0x00010000 // EPWM_CH2 period point
    ,TRGSEL2_2 = 0x00020000 // EPWM_CH2 zero or period point
    ,TRGSEL2_3 = 0x00030000 // EPWM_CH2 up-count compared point
    ,TRGSEL2_4 = 0x00040000 // EPWM_CH2 down-count compared point
    ,TRGSEL2_5 = 0x00050000 // EPWM_CH3 zero point
    ,TRGSEL2_6 = 0x00060000 // EPWM_CH3 period point
    ,TRGSEL2_7 = 0x00070000 // EPWM_CH3 zero or period point
    ,TRGSEL2_8 = 0x00080000 // EPWM_CH3 up-count compared point
    ,TRGSEL2_9 = 0x00090000 // EPWM_CH3 down-count compared point
    ,TRGSEL2_10 = 0x000A0000 // EPWM_CH0 up-count free trigger compared point
    ,TRGSEL2_11 = 0x000B0000 // EPWM_CH0 down-count free trigger compared point
    ,TRGSEL2_12 = 0x000C0000 // EPWM_CH2 up-count free trigger compared point
    ,TRGSEL2_13 = 0x000D0000 // EPWM_CH2 down-count free trigger compared point
    ,TRGSEL2_14 = 0x000E0000 // EPWM_CH4 up-count free trigger compared point
    ,TRGSEL2_15 = 0x000F0000 // EPWM_CH4 down-count free trigger compared point
    // EPWM_CH2 Trigger EADC Enable Bit (bits: 23)
    ,TRGEN2_MASK = 0x00800000
    ,TRGEN2_POS = 23
    ,TRGEN2_0 = 0x00000000 // EPWM_CH2 Trigger EADC function Disabled
    ,TRGEN2_1 = 0x00800000 // EPWM_CH2 Trigger EADC function Enabled
    // EPWM_CH3 Trigger EADC Source Select (bits: 27-24)
    ,TRGSEL3_MASK = 0x0F000000
    ,TRGSEL3_POS = 24
    ,TRGSEL3_0 = 0x00000000 // EPWM_CH2 zero point
    ,TRGSEL3_1 = 0x01000000 // EPWM_CH2 period point
    ,TRGSEL3_2 = 0x02000000 // EPWM_CH2 zero or period point
    ,TRGSEL3_3 = 0x03000000 // EPWM_CH2 up-count compared point
    ,TRGSEL3_4 = 0x04000000 // EPWM_CH2 down-count compared point
    ,TRGSEL3_5 = 0x05000000 // EPWM_CH3 zero point
    ,TRGSEL3_6 = 0x06000000 // EPWM_CH3 period point
    ,TRGSEL3_7 = 0x07000000 // EPWM_CH3 zero or period point
    ,TRGSEL3_8 = 0x08000000 // EPWM_CH3 up-count compared point
    ,TRGSEL3_9 = 0x09000000 // EPWM_CH3 down-count compared point
    ,TRGSEL3_10 = 0x0A000000 // EPWM_CH0 up-count free trigger compared point
    ,TRGSEL3_11 = 0x0B000000 // EPWM_CH0 down-count free trigger compared point
    ,TRGSEL3_12 = 0x0C000000 // EPWM_CH2 up-count free trigger compared point
    ,TRGSEL3_13 = 0x0D000000 // EPWM_CH2 down-count free trigger compared point
    ,TRGSEL3_14 = 0x0E000000 // EPWM_CH4 up-count free trigger compared point
    ,TRGSEL3_15 = 0x0F000000 // EPWM_CH4 down-count free trigger compared point
    // EPWM_CH3 Trigger EADC Enable Bit (bits: 31)
    ,TRGEN3_MASK = 0x80000000
    ,TRGEN3_POS = 31
    ,TRGEN3_0 = 0x00000000 // EPWM_CH3 Trigger EADC function Disabled
    ,TRGEN3_1 = 0x80000000 // EPWM_CH3 Trigger EADC function Enabled
    ,EADCTS0_MASK = 0x8F8F8F8F
    ;
  };
  // EPWM Trigger EADC Source Select Register 1
  struct EADCTS1 : reg<ip_ver, base + 0xFC>
  {
    static constexpr typename EADCTS1::type
    // EPWM_CH4 Trigger EADC Source Select (bits: 3-0)
     TRGSEL4_MASK = 0x0000000F
    ,TRGSEL4_POS = 0
    ,TRGSEL4_0 = 0x00000000 // EPWM_CH4 zero point
    ,TRGSEL4_1 = 0x00000001 // EPWM_CH4 period point
    ,TRGSEL4_2 = 0x00000002 // EPWM_CH4 zero or period point
    ,TRGSEL4_3 = 0x00000003 // EPWM_CH4 up-count compared point
    ,TRGSEL4_4 = 0x00000004 // EPWM_CH4 down-count compared point
    ,TRGSEL4_5 = 0x00000005 // EPWM_CH5 zero point
    ,TRGSEL4_6 = 0x00000006 // EPWM_CH5 period point
    ,TRGSEL4_7 = 0x00000007 // EPWM_CH5 zero or period point
    ,TRGSEL4_8 = 0x00000008 // EPWM_CH5 up-count compared point
    ,TRGSEL4_9 = 0x00000009 // EPWM_CH5 down-count compared point
    ,TRGSEL4_10 = 0x0000000A // EPWM_CH0 up-count free trigger compared point
    ,TRGSEL4_11 = 0x0000000B // EPWM_CH0 down-count free trigger compared point
    ,TRGSEL4_12 = 0x0000000C // EPWM_CH2 up-count free trigger compared point
    ,TRGSEL4_13 = 0x0000000D // EPWM_CH2 down-count free trigger compared point
    ,TRGSEL4_14 = 0x0000000E // EPWM_CH4 up-count free trigger compared point
    ,TRGSEL4_15 = 0x0000000F // EPWM_CH4 down-count free trigger compared point
    // EPWM_CH4 Trigger EADC Enable Bit (bits: 7)
    ,TRGEN4_MASK = 0x00000080
    ,TRGEN4_POS = 7
    ,TRGEN4_0 = 0x00000000 // EPWM_CH4 Trigger EADC function Disabled
    ,TRGEN4_1 = 0x00000080 // EPWM_CH4 Trigger EADC function Enabled
    // EPWM_CH5 Trigger EADC Source Select (bits: 11-8)
    ,TRGSEL5_MASK = 0x00000F00
    ,TRGSEL5_POS = 8
    ,TRGSEL5_0 = 0x00000000 // EPWM_CH4 zero point
    ,TRGSEL5_1 = 0x00000100 // EPWM_CH4 period point
    ,TRGSEL5_2 = 0x00000200 // EPWM_CH4 zero or period point
    ,TRGSEL5_3 = 0x00000300 // EPWM_CH4 up-count compared point
    ,TRGSEL5_4 = 0x00000400 // EPWM_CH4 down-count compared point
    ,TRGSEL5_5 = 0x00000500 // EPWM_CH5 zero point
    ,TRGSEL5_6 = 0x00000600 // EPWM_CH5 period point
    ,TRGSEL5_7 = 0x00000700 // EPWM_CH5 zero or period point
    ,TRGSEL5_8 = 0x00000800 // EPWM_CH5 up-count compared point
    ,TRGSEL5_9 = 0x00000900 // EPWM_CH5 down-count compared point
    ,TRGSEL5_10 = 0x00000A00 // EPWM_CH0 up-count free trigger compared point
    ,TRGSEL5_11 = 0x00000B00 // EPWM_CH0 down-count free trigger compared point
    ,TRGSEL5_12 = 0x00000C00 // EPWM_CH2 up-count free trigger compared point
    ,TRGSEL5_13 = 0x00000D00 // EPWM_CH2 down-count free trigger compared point
    ,TRGSEL5_14 = 0x00000E00 // EPWM_CH4 up-count free trigger compared point
    ,TRGSEL5_15 = 0x00000F00 // EPWM_CH4 down-count free trigger compared point
    // EPWM_CH5 Trigger EADC Enable Bit (bits: 15)
    ,TRGEN5_MASK = 0x00008000
    ,TRGEN5_POS = 15
    ,TRGEN5_0 = 0x00000000 // EPWM_CH5 Trigger EADC function Disabled
    ,TRGEN5_1 = 0x00008000 // EPWM_CH5 Trigger EADC function Enabled
    ,EADCTS1_MASK = 0x00008F8F
    ;
  };
  // EPWM Free Trigger Compare Register 0/1
  struct FTCMPDAT0_1 : reg<ip_ver, base + 0x100>
  {
    static constexpr typename FTCMPDAT0_1::type
    // EPWM Free Trigger Compare Register (bits: 15-0)
     FTCMP_MASK = 0x0000FFFF
    ,FTCMP_POS = 0
    ,FTCMPDAT0_1_MASK = 0x0000FFFF
    ;
  };
  // EPWM Free Trigger Compare Register 2/3
  using FTCMPDAT2_3 = reg<ip_ver, base + 0x104>;
  // EPWM Free Trigger Compare Register 4/5
  using FTCMPDAT4_5 = reg<ip_ver, base + 0x108>;
  // EPWM Synchronous Start Control Register
  struct SSCTL : reg<ip_ver, base + 0x110>
  {
    static constexpr typename SSCTL::type
    // EPWM Synchronous Start Function Enable Bits When synchronous start function is enabled, the EPWM counter enable register (EPWM_CNTEN) can be enabled by writing EPWM synchronous start trigger bit (CNTSEN). (bits: 0)
     SSEN0_MASK = 0x00000001
    ,SSEN0_POS = 0
    ,SSEN0_0 = 0x00000000 // EPWM synchronous start function Disabled
    ,SSEN0_1 = 0x00000001 // EPWM synchronous start function Enabled
    // EPWM Synchronous Start Function Enable Bits When synchronous start function is enabled, the EPWM counter enable register (EPWM_CNTEN) can be enabled by writing EPWM synchronous start trigger bit (CNTSEN). (bits: 1)
    ,SSEN1_MASK = 0x00000002
    ,SSEN1_POS = 1
    ,SSEN1_0 = 0x00000000 // EPWM synchronous start function Disabled
    ,SSEN1_1 = 0x00000002 // EPWM synchronous start function Enabled
    // EPWM Synchronous Start Function Enable Bits When synchronous start function is enabled, the EPWM counter enable register (EPWM_CNTEN) can be enabled by writing EPWM synchronous start trigger bit (CNTSEN). (bits: 2)
    ,SSEN2_MASK = 0x00000004
    ,SSEN2_POS = 2
    ,SSEN2_0 = 0x00000000 // EPWM synchronous start function Disabled
    ,SSEN2_1 = 0x00000004 // EPWM synchronous start function Enabled
    // EPWM Synchronous Start Function Enable Bits When synchronous start function is enabled, the EPWM counter enable register (EPWM_CNTEN) can be enabled by writing EPWM synchronous start trigger bit (CNTSEN). (bits: 3)
    ,SSEN3_MASK = 0x00000008
    ,SSEN3_POS = 3
    ,SSEN3_0 = 0x00000000 // EPWM synchronous start function Disabled
    ,SSEN3_1 = 0x00000008 // EPWM synchronous start function Enabled
    // EPWM Synchronous Start Function Enable Bits When synchronous start function is enabled, the EPWM counter enable register (EPWM_CNTEN) can be enabled by writing EPWM synchronous start trigger bit (CNTSEN). (bits: 4)
    ,SSEN4_MASK = 0x00000010
    ,SSEN4_POS = 4
    ,SSEN4_0 = 0x00000000 // EPWM synchronous start function Disabled
    ,SSEN4_1 = 0x00000010 // EPWM synchronous start function Enabled
    // EPWM Synchronous Start Function Enable Bits When synchronous start function is enabled, the EPWM counter enable register (EPWM_CNTEN) can be enabled by writing EPWM synchronous start trigger bit (CNTSEN). (bits: 5)
    ,SSEN5_MASK = 0x00000020
    ,SSEN5_POS = 5
    ,SSEN5_0 = 0x00000000 // EPWM synchronous start function Disabled
    ,SSEN5_1 = 0x00000020 // EPWM synchronous start function Enabled
    // EPWM Synchronous Start Source Select Bits (bits: 9-8)
    ,SSRC_MASK = 0x00000300
    ,SSRC_POS = 8
    ,SSRC_0 = 0x00000000 // Synchronous start source come from EPWM0
    ,SSRC_1 = 0x00000100 // Synchronous start source come from EPWM1
    ,SSRC_2 = 0x00000200 // Synchronous start source come from BPWM0
    ,SSRC_3 = 0x00000300 // Synchronous start source come from BPWM1
    ,SSCTL_MASK = 0x0000033F
    ;
  };
  // EPWM Synchronous Start Trigger Register
  struct SSTRG : reg<ip_ver, base + 0x114>
  {
    static constexpr typename SSTRG::type
    // EPWM Counter Synchronous Start Enable (Write Only) PMW counter synchronous enable function is used to make selected EPWM channels (include EPWM0_CHx and EPWM1_CHx) start counting at the same time. Writing this bit to 1 will also set the counter enable bit (CNTENn, n denotes channel 0 to 5) if correlated EPWM channel counter synchronous start function is enabled. (bits: 0)
     CNTSEN_MASK = 0x00000001
    ,CNTSEN_POS = 0
    ,CNTSEN = 0x00000001
    ,SSTRG_MASK = 0x00000001
    ;
  };
  // EPWM Leading Edge Blanking Control Register
  struct LEBCTL : reg<ip_ver, base + 0x118>
  {
    static constexpr typename LEBCTL::type
    // EPWM Leading Edge Blanking Enable Bit (bits: 0)
     LEBEN_MASK = 0x00000001
    ,LEBEN_POS = 0
    ,LEBEN_0 = 0x00000000 // EPWM Leading Edge Blanking Disabled
    ,LEBEN_1 = 0x00000001 // EPWM Leading Edge Blanking Enabled
    // EPWM Leading Edge Blanking Source From EPWM_CH0 Enable Bit (bits: 8)
    ,SRCEN0_MASK = 0x00000100
    ,SRCEN0_POS = 8
    ,SRCEN0_0 = 0x00000000 // EPWM Leading Edge Blanking Source from EPWM_CH0 Disabled
    ,SRCEN0_1 = 0x00000100 // EPWM Leading Edge Blanking Source from EPWM_CH0 Enabled
    // EPWM Leading Edge Blanking Source From EPWM_CH2 Enable Bit (bits: 9)
    ,SRCEN2_MASK = 0x00000200
    ,SRCEN2_POS = 9
    ,SRCEN2_0 = 0x00000000 // EPWM Leading Edge Blanking Source from EPWM_CH2 Disabled
    ,SRCEN2_1 = 0x00000200 // EPWM Leading Edge Blanking Source from EPWM_CH2 Enabled
    // EPWM Leading Edge Blanking Source From EPWM_CH4 Enable Bit (bits: 10)
    ,SRCEN4_MASK = 0x00000400
    ,SRCEN4_POS = 10
    ,SRCEN4_0 = 0x00000000 // EPWM Leading Edge Blanking Source from EPWM_CH4 Disabled
    ,SRCEN4_1 = 0x00000400 // EPWM Leading Edge Blanking Source from EPWM_CH4 Enabled
    // EPWM Leading Edge Blanking Trigger Type (bits: 17-16)
    ,TRGTYPE_MASK = 0x00030000
    ,TRGTYPE_POS = 16
    ,TRGTYPE_0 = 0x00000000 // When detect leading edge blanking source rising edge, blanking counter start counting
    ,TRGTYPE_1 = 0x00010000 // When detect leading edge blanking source falling edge, blanking counter start counting
    ,TRGTYPE_2 = 0x00020000 // When detect leading edge blanking source rising or falling edge, blanking counter start counting
    ,TRGTYPE_3 = 0x00030000 // Reserved.
    ,LEBCTL_MASK = 0x00030701
    ;
  };
  // EPWM Leading Edge Blanking Counter Register
  struct LEBCNT : reg<ip_ver, base + 0x11C>
  {
    static constexpr typename LEBCNT::type
    // EPWM Leading Edge Blanking Counter (bits: 8-0)
     LEBCNTVAL_MASK = 0x000001FF
    ,LEBCNTVAL_POS = 0
    ,LEBCNT_MASK = 0x000001FF
    ;
  };
  // EPWM Status Register
  struct STATUS : reg<ip_ver, base + 0x120>
  {
    static constexpr typename STATUS::type
    // Time-base Counter Equal to 0xFFFF Latched Flag Note: This bit can be cleared by software writing 1. (bits: 0)
     CNTMAXF0_MASK = 0x00000001
    ,CNTMAXF0_POS = 0
    ,CNTMAXF0_0 = 0x00000000 // The time-base counter never reached its maximum value 0xFFFF
    ,CNTMAXF0_1 = 0x00000001 // The time-base counter reached its maximum value
    // Time-base Counter Equal to 0xFFFF Latched Flag Note: This bit can be cleared by software writing 1. (bits: 1)
    ,CNTMAXF1_MASK = 0x00000002
    ,CNTMAXF1_POS = 1
    ,CNTMAXF1_0 = 0x00000000 // The time-base counter never reached its maximum value 0xFFFF
    ,CNTMAXF1_1 = 0x00000002 // The time-base counter reached its maximum value
    // Time-base Counter Equal to 0xFFFF Latched Flag Note: This bit can be cleared by software writing 1. (bits: 2)
    ,CNTMAXF2_MASK = 0x00000004
    ,CNTMAXF2_POS = 2
    ,CNTMAXF2_0 = 0x00000000 // The time-base counter never reached its maximum value 0xFFFF
    ,CNTMAXF2_1 = 0x00000004 // The time-base counter reached its maximum value
    // Time-base Counter Equal to 0xFFFF Latched Flag Note: This bit can be cleared by software writing 1. (bits: 3)
    ,CNTMAXF3_MASK = 0x00000008
    ,CNTMAXF3_POS = 3
    ,CNTMAXF3_0 = 0x00000000 // The time-base counter never reached its maximum value 0xFFFF
    ,CNTMAXF3_1 = 0x00000008 // The time-base counter reached its maximum value
    // Time-base Counter Equal to 0xFFFF Latched Flag Note: This bit can be cleared by software writing 1. (bits: 4)
    ,CNTMAXF4_MASK = 0x00000010
    ,CNTMAXF4_POS = 4
    ,CNTMAXF4_0 = 0x00000000 // The time-base counter never reached its maximum value 0xFFFF
    ,CNTMAXF4_1 = 0x00000010 // The time-base counter reached its maximum value
    // Time-base Counter Equal to 0xFFFF Latched Flag Note: This bit can be cleared by software writing 1. (bits: 5)
    ,CNTMAXF5_MASK = 0x00000020
    ,CNTMAXF5_POS = 5
    ,CNTMAXF5_0 = 0x00000000 // The time-base counter never reached its maximum value 0xFFFF
    ,CNTMAXF5_1 = 0x00000020 // The time-base counter reached its maximum value
    // Input Synchronization Latched Flag Note: This bit can be cleared by software writing 1. (bits: 8)
    ,SYNCINF0_MASK = 0x00000100
    ,SYNCINF0_POS = 8
    ,SYNCINF0_0 = 0x00000000 // No SYNC_IN event has occurred
    ,SYNCINF0_1 = 0x00000100 // A SYNC_IN event has occurred
    // Input Synchronization Latched Flag Note: This bit can be cleared by software writing 1. (bits: 9)
    ,SYNCINF2_MASK = 0x00000200
    ,SYNCINF2_POS = 9
    ,SYNCINF2_0 = 0x00000000 // No SYNC_IN event has occurred
    ,SYNCINF2_1 = 0x00000200 // A SYNC_IN event has occurred
    // Input Synchronization Latched Flag Note: This bit can be cleared by software writing 1. (bits: 10)
    ,SYNCINF4_MASK = 0x00000400
    ,SYNCINF4_POS = 10
    ,SYNCINF4_0 = 0x00000000 // No SYNC_IN event has occurred
    ,SYNCINF4_1 = 0x00000400 // A SYNC_IN event has occurred
    // EADC Start of Conversion Flag Note: This bit can be cleared by software writing 1. (bits: 16)
    ,EADCTRGF0_MASK = 0x00010000
    ,EADCTRGF0_POS = 16
    ,EADCTRGF0_0 = 0x00000000 // No EADC start of conversion trigger event has occurred
    ,EADCTRGF0_1 = 0x00010000 // An EADC start of conversion trigger event has occurred
    // EADC Start of Conversion Flag Note: This bit can be cleared by software writing 1. (bits: 17)
    ,EADCTRGF1_MASK = 0x00020000
    ,EADCTRGF1_POS = 17
    ,EADCTRGF1_0 = 0x00000000 // No EADC start of conversion trigger event has occurred
    ,EADCTRGF1_1 = 0x00020000 // An EADC start of conversion trigger event has occurred
    // EADC Start of Conversion Flag Note: This bit can be cleared by software writing 1. (bits: 18)
    ,EADCTRGF2_MASK = 0x00040000
    ,EADCTRGF2_POS = 18
    ,EADCTRGF2_0 = 0x00000000 // No EADC start of conversion trigger event has occurred
    ,EADCTRGF2_1 = 0x00040000 // An EADC start of conversion trigger event has occurred
    // EADC Start of Conversion Flag Note: This bit can be cleared by software writing 1. (bits: 19)
    ,EADCTRGF3_MASK = 0x00080000
    ,EADCTRGF3_POS = 19
    ,EADCTRGF3_0 = 0x00000000 // No EADC start of conversion trigger event has occurred
    ,EADCTRGF3_1 = 0x00080000 // An EADC start of conversion trigger event has occurred
    // EADC Start of Conversion Flag Note: This bit can be cleared by software writing 1. (bits: 20)
    ,EADCTRGF4_MASK = 0x00100000
    ,EADCTRGF4_POS = 20
    ,EADCTRGF4_0 = 0x00000000 // No EADC start of conversion trigger event has occurred
    ,EADCTRGF4_1 = 0x00100000 // An EADC start of conversion trigger event has occurred
    // EADC Start of Conversion Flag Note: This bit can be cleared by software writing 1. (bits: 21)
    ,EADCTRGF5_MASK = 0x00200000
    ,EADCTRGF5_POS = 21
    ,EADCTRGF5_0 = 0x00000000 // No EADC start of conversion trigger event has occurred
    ,EADCTRGF5_1 = 0x00200000 // An EADC start of conversion trigger event has occurred
    // DAC Start of Conversion Flag Note: This bit can be cleared by software writing 1. (bits: 24)
    ,DACTRGF_MASK = 0x01000000
    ,DACTRGF_POS = 24
    ,DACTRGF_0 = 0x00000000 // No DAC start of conversion trigger event has occurred
    ,DACTRGF_1 = 0x01000000 // A DAC start of conversion trigger event has occurred
    ,STATUS_MASK = 0x013F073F
    ;
  };
  // EPWM Interrupt Flag Accumulator Register 0
  struct IFA0 : reg<ip_ver, base + 0x130>
  {
    static constexpr typename IFA0::type
    // EPWM_CHn Interrupt Flag Counter The register sets the count number which defines (IFACNT+1) times of EPWM_CHn period occurs to set bit IFAIFn to request the EPWM period interrupt. EPWM flag will be set in every IFACNT[15:0] times of EPWM period. (bits: 15-0)
     IFACNT_MASK = 0x0000FFFF
    ,IFACNT_POS = 0
    // EPWM_CHn Accumulator Stop Mode Enable Bits (bits: 24)
    ,STPMOD_MASK = 0x01000000
    ,STPMOD_POS = 24
    ,STPMOD_0 = 0x00000000 // EPWM_CHn Stop Mode Disable
    ,STPMOD_1 = 0x01000000 // EPWM_CHn Stop Mode Enable
    // EPWM_CHn Interrupt Flag Accumulator Source Select (bits: 29-28)
    ,IFASEL_MASK = 0x30000000
    ,IFASEL_POS = 28
    ,IFASEL_0 = 0x00000000 // EPWM_CHn zero point
    ,IFASEL_1 = 0x10000000 // EPWM_CHn period in channel n
    ,IFASEL_2 = 0x20000000 // EPWM_CHn up-count compared point
    ,IFASEL_3 = 0x30000000 // EPWM_CHn down-count compared point
    // EPWM_CHn Interrupt Flag Accumulator Enable Bits (bits: 31)
    ,IFAEN_MASK = 0x80000000
    ,IFAEN_POS = 31
    ,IFAEN_0 = 0x00000000 // EPWM_CHn interrupt flag accumulator Disabled
    ,IFAEN_1 = 0x80000000 // EPWM_CHn interrupt flag accumulator Enabled
    ,IFA0_MASK = 0xB100FFFF
    ;
  };
  // EPWM Interrupt Flag Accumulator Register 1
  using IFA1 = reg<ip_ver, base + 0x134>;
  // EPWM Interrupt Flag Accumulator Register 2
  using IFA2 = reg<ip_ver, base + 0x138>;
  // EPWM Interrupt Flag Accumulator Register 3
  using IFA3 = reg<ip_ver, base + 0x13C>;
  // EPWM Interrupt Flag Accumulator Register 4
  using IFA4 = reg<ip_ver, base + 0x140>;
  // EPWM Interrupt Flag Accumulator Register 5
  using IFA5 = reg<ip_ver, base + 0x144>;
  // EPWM Accumulator Interrupt Flag Register
  struct AINTSTS : reg<ip_ver, base + 0x150>
  {
    static constexpr typename AINTSTS::type
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Flag Flag is set by hardware when condition match IFASEL in EPWM_IFAn register, software can clear this bit by writing 1 to it. (bits: 0)
     IFAIF0_MASK = 0x00000001
    ,IFAIF0_POS = 0
    ,IFAIF0 = 0x00000001
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Flag Flag is set by hardware when condition match IFASEL in EPWM_IFAn register, software can clear this bit by writing 1 to it. (bits: 1)
    ,IFAIF1_MASK = 0x00000002
    ,IFAIF1_POS = 1
    ,IFAIF1 = 0x00000002
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Flag Flag is set by hardware when condition match IFASEL in EPWM_IFAn register, software can clear this bit by writing 1 to it. (bits: 2)
    ,IFAIF2_MASK = 0x00000004
    ,IFAIF2_POS = 2
    ,IFAIF2 = 0x00000004
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Flag Flag is set by hardware when condition match IFASEL in EPWM_IFAn register, software can clear this bit by writing 1 to it. (bits: 3)
    ,IFAIF3_MASK = 0x00000008
    ,IFAIF3_POS = 3
    ,IFAIF3 = 0x00000008
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Flag Flag is set by hardware when condition match IFASEL in EPWM_IFAn register, software can clear this bit by writing 1 to it. (bits: 4)
    ,IFAIF4_MASK = 0x00000010
    ,IFAIF4_POS = 4
    ,IFAIF4 = 0x00000010
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Flag Flag is set by hardware when condition match IFASEL in EPWM_IFAn register, software can clear this bit by writing 1 to it. (bits: 5)
    ,IFAIF5_MASK = 0x00000020
    ,IFAIF5_POS = 5
    ,IFAIF5 = 0x00000020
    ,AINTSTS_MASK = 0x0000003F
    ;
  };
  // EPWM Accumulator Interrupt Enable Register
  struct AINTEN : reg<ip_ver, base + 0x154>
  {
    static constexpr typename AINTEN::type
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Enable Bits (bits: 0)
     IFAIEN0_MASK = 0x00000001
    ,IFAIEN0_POS = 0
    ,IFAIEN0_0 = 0x00000000 // Interrupt Flag accumulator interrupt Disabled
    ,IFAIEN0_1 = 0x00000001 // Interrupt Flag accumulator interrupt Enabled
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Enable Bits (bits: 1)
    ,IFAIEN1_MASK = 0x00000002
    ,IFAIEN1_POS = 1
    ,IFAIEN1_0 = 0x00000000 // Interrupt Flag accumulator interrupt Disabled
    ,IFAIEN1_1 = 0x00000002 // Interrupt Flag accumulator interrupt Enabled
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Enable Bits (bits: 2)
    ,IFAIEN2_MASK = 0x00000004
    ,IFAIEN2_POS = 2
    ,IFAIEN2_0 = 0x00000000 // Interrupt Flag accumulator interrupt Disabled
    ,IFAIEN2_1 = 0x00000004 // Interrupt Flag accumulator interrupt Enabled
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Enable Bits (bits: 3)
    ,IFAIEN3_MASK = 0x00000008
    ,IFAIEN3_POS = 3
    ,IFAIEN3_0 = 0x00000000 // Interrupt Flag accumulator interrupt Disabled
    ,IFAIEN3_1 = 0x00000008 // Interrupt Flag accumulator interrupt Enabled
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Enable Bits (bits: 4)
    ,IFAIEN4_MASK = 0x00000010
    ,IFAIEN4_POS = 4
    ,IFAIEN4_0 = 0x00000000 // Interrupt Flag accumulator interrupt Disabled
    ,IFAIEN4_1 = 0x00000010 // Interrupt Flag accumulator interrupt Enabled
    // EPWM_CHn Interrupt Flag Accumulator Interrupt Enable Bits (bits: 5)
    ,IFAIEN5_MASK = 0x00000020
    ,IFAIEN5_POS = 5
    ,IFAIEN5_0 = 0x00000000 // Interrupt Flag accumulator interrupt Disabled
    ,IFAIEN5_1 = 0x00000020 // Interrupt Flag accumulator interrupt Enabled
    ,AINTEN_MASK = 0x0000003F
    ;
  };
  // EPWM Accumulator PDMA Control Register
  struct APDMACTL : reg<ip_ver, base + 0x158>
  {
    static constexpr typename APDMACTL::type
    // Channel n Accumulator PDMA Enable Bits (bits: 0)
     APDMAEN0_MASK = 0x00000001
    ,APDMAEN0_POS = 0
    ,APDMAEN0_0 = 0x00000000 // Channel n PDMA function Disabled
    ,APDMAEN0_1 = 0x00000001 // Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register
    // Channel n Accumulator PDMA Enable Bits (bits: 1)
    ,APDMAEN1_MASK = 0x00000002
    ,APDMAEN1_POS = 1
    ,APDMAEN1_0 = 0x00000000 // Channel n PDMA function Disabled
    ,APDMAEN1_1 = 0x00000002 // Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register
    // Channel n Accumulator PDMA Enable Bits (bits: 2)
    ,APDMAEN2_MASK = 0x00000004
    ,APDMAEN2_POS = 2
    ,APDMAEN2_0 = 0x00000000 // Channel n PDMA function Disabled
    ,APDMAEN2_1 = 0x00000004 // Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register
    // Channel n Accumulator PDMA Enable Bits (bits: 3)
    ,APDMAEN3_MASK = 0x00000008
    ,APDMAEN3_POS = 3
    ,APDMAEN3_0 = 0x00000000 // Channel n PDMA function Disabled
    ,APDMAEN3_1 = 0x00000008 // Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register
    // Channel n Accumulator PDMA Enable Bits (bits: 4)
    ,APDMAEN4_MASK = 0x00000010
    ,APDMAEN4_POS = 4
    ,APDMAEN4_0 = 0x00000000 // Channel n PDMA function Disabled
    ,APDMAEN4_1 = 0x00000010 // Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register
    // Channel n Accumulator PDMA Enable Bits (bits: 5)
    ,APDMAEN5_MASK = 0x00000020
    ,APDMAEN5_POS = 5
    ,APDMAEN5_0 = 0x00000000 // Channel n PDMA function Disabled
    ,APDMAEN5_1 = 0x00000020 // Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register
    ,APDMACTL_MASK = 0x0000003F
    ;
  };
  // EPWM Fault Detect Enable Register
  struct FDEN : reg<ip_ver, base + 0x160>
  {
    static constexpr typename FDEN::type
    // EPWM Fault Detect Function Enable Bit (bits: 0)
     FDEN0_MASK = 0x00000001
    ,FDEN0_POS = 0
    ,FDEN0_0 = 0x00000000 // Fault detect function Disable
    ,FDEN0_1 = 0x00000001 // Fault detect function Enable
    // EPWM Fault Detect Function Enable Bit (bits: 1)
    ,FDEN1_MASK = 0x00000002
    ,FDEN1_POS = 1
    ,FDEN1_0 = 0x00000000 // Fault detect function Disable
    ,FDEN1_1 = 0x00000002 // Fault detect function Enable
    // EPWM Fault Detect Function Enable Bit (bits: 2)
    ,FDEN2_MASK = 0x00000004
    ,FDEN2_POS = 2
    ,FDEN2_0 = 0x00000000 // Fault detect function Disable
    ,FDEN2_1 = 0x00000004 // Fault detect function Enable
    // EPWM Fault Detect Function Enable Bit (bits: 3)
    ,FDEN3_MASK = 0x00000008
    ,FDEN3_POS = 3
    ,FDEN3_0 = 0x00000000 // Fault detect function Disable
    ,FDEN3_1 = 0x00000008 // Fault detect function Enable
    // EPWM Fault Detect Function Enable Bit (bits: 4)
    ,FDEN4_MASK = 0x00000010
    ,FDEN4_POS = 4
    ,FDEN4_0 = 0x00000000 // Fault detect function Disable
    ,FDEN4_1 = 0x00000010 // Fault detect function Enable
    // EPWM Fault Detect Function Enable Bit (bits: 5)
    ,FDEN5_MASK = 0x00000020
    ,FDEN5_POS = 5
    ,FDEN5_0 = 0x00000000 // Fault detect function Disable
    ,FDEN5_1 = 0x00000020 // Fault detect function Enable
    // EPWM Channel n Output Fault Detect Disable Bit (bits: 8)
    ,FDODIS0_MASK = 0x00000100
    ,FDODIS0_POS = 8
    ,FDODIS0_0 = 0x00000000 // EPWM detect fault and output Enable
    ,FDODIS0_1 = 0x00000100 // EPWM detect fault and output Disable
    // EPWM Channel n Output Fault Detect Disable Bit (bits: 9)
    ,FDODIS1_MASK = 0x00000200
    ,FDODIS1_POS = 9
    ,FDODIS1_0 = 0x00000000 // EPWM detect fault and output Enable
    ,FDODIS1_1 = 0x00000200 // EPWM detect fault and output Disable
    // EPWM Channel n Output Fault Detect Disable Bit (bits: 10)
    ,FDODIS2_MASK = 0x00000400
    ,FDODIS2_POS = 10
    ,FDODIS2_0 = 0x00000000 // EPWM detect fault and output Enable
    ,FDODIS2_1 = 0x00000400 // EPWM detect fault and output Disable
    // EPWM Channel n Output Fault Detect Disable Bit (bits: 11)
    ,FDODIS3_MASK = 0x00000800
    ,FDODIS3_POS = 11
    ,FDODIS3_0 = 0x00000000 // EPWM detect fault and output Enable
    ,FDODIS3_1 = 0x00000800 // EPWM detect fault and output Disable
    // EPWM Channel n Output Fault Detect Disable Bit (bits: 12)
    ,FDODIS4_MASK = 0x00001000
    ,FDODIS4_POS = 12
    ,FDODIS4_0 = 0x00000000 // EPWM detect fault and output Enable
    ,FDODIS4_1 = 0x00001000 // EPWM detect fault and output Disable
    // EPWM Channel n Output Fault Detect Disable Bit (bits: 13)
    ,FDODIS5_MASK = 0x00002000
    ,FDODIS5_POS = 13
    ,FDODIS5_0 = 0x00000000 // EPWM detect fault and output Enable
    ,FDODIS5_1 = 0x00002000 // EPWM detect fault and output Disable
    // EPWM Channel n Fault Detect Clock Source Select Bit (bits: 16)
    ,FDCKS0_MASK = 0x00010000
    ,FDCKS0_POS = 16
    ,FDCKS0_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,FDCKS0_1 = 0x00010000 // EPWMx_CLK divide by prescaler, x denotes 0 or 1
    // EPWM Channel n Fault Detect Clock Source Select Bit (bits: 17)
    ,FDCKS1_MASK = 0x00020000
    ,FDCKS1_POS = 17
    ,FDCKS1_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,FDCKS1_1 = 0x00020000 // EPWMx_CLK divide by prescaler, x denotes 0 or 1
    // EPWM Channel n Fault Detect Clock Source Select Bit (bits: 18)
    ,FDCKS2_MASK = 0x00040000
    ,FDCKS2_POS = 18
    ,FDCKS2_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,FDCKS2_1 = 0x00040000 // EPWMx_CLK divide by prescaler, x denotes 0 or 1
    // EPWM Channel n Fault Detect Clock Source Select Bit (bits: 19)
    ,FDCKS3_MASK = 0x00080000
    ,FDCKS3_POS = 19
    ,FDCKS3_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,FDCKS3_1 = 0x00080000 // EPWMx_CLK divide by prescaler, x denotes 0 or 1
    // EPWM Channel n Fault Detect Clock Source Select Bit (bits: 20)
    ,FDCKS4_MASK = 0x00100000
    ,FDCKS4_POS = 20
    ,FDCKS4_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,FDCKS4_1 = 0x00100000 // EPWMx_CLK divide by prescaler, x denotes 0 or 1
    // EPWM Channel n Fault Detect Clock Source Select Bit (bits: 21)
    ,FDCKS5_MASK = 0x00200000
    ,FDCKS5_POS = 21
    ,FDCKS5_0 = 0x00000000 // EPWMx_CLK, x denotes 0 or 1
    ,FDCKS5_1 = 0x00200000 // EPWMx_CLK divide by prescaler, x denotes 0 or 1
    ,FDEN_MASK = 0x003F3F3F
    ;
  };
  // EPWM Fault Detect Control Register 0
  struct FDCTL0 : reg<ip_ver, base + 0x164>
  {
    static constexpr typename FDCTL0::type
    // Transition Mask Counter The fault detect result will be masked before counter count from 0 to TRMSKCNT. FDCKS is set to 0: Mask time is EPWMx_CLK * (2^FDCKSEL) * (TRMSKCNT+2) FDCKS is set to 1: Mask time EPWMx_CLK * CLKPSC * (2^FDCKSEL) * (TRMSKCNT+2) Note: CLKPSC (EPWM_CLKPSCn_m[11:0]) is 0: (bits: 6-0)
     TRMSKCNT_MASK = 0x0000007F
    ,TRMSKCNT_POS = 0
    // Fault Detect Mask Enable Bit (bits: 15)
    ,FDMSKEN_MASK = 0x00008000
    ,FDMSKEN_POS = 15
    ,FDMSKEN_0 = 0x00000000 // Fault detect mask function Disable
    ,FDMSKEN_1 = 0x00008000 // Fault detect mask function Enable
    // Deglitch Sampling Cycle FDCKS is set to 0: Sampling detect signal each EPWMx_CLK * (2^FDCKSEL) period and detect DGSMPCYC+1 times FDCKS is set to 1: Sampling detect signal each EPWMx_CLK * CLKPSC * (2^FDCKSEL) period and detect DGSMPCYC+1 times Note: CLKPSC (EPWM_CLKPSCn_m[11:0]) is 0: (bits: 18-16)
    ,DGSMPCYC_MASK = 0x00070000
    ,DGSMPCYC_POS = 16
    // EPWM Channel Fault Detect Clock Select (bits: 29-28)
    ,FDCKSEL_MASK = 0x30000000
    ,FDCKSEL_POS = 28
    ,FDCKSEL_0 = 0x00000000 // FLT_CLK/1
    ,FDCKSEL_1 = 0x10000000 // FLT_CLK/2
    ,FDCKSEL_2 = 0x20000000 // FLT_CLK/4
    ,FDCKSEL_3 = 0x30000000 // FLT_CLK/8
    // Fault Detect Deglitch Enable Bit (bits: 31)
    ,FDDGEN_MASK = 0x80000000
    ,FDDGEN_POS = 31
    ,FDDGEN_0 = 0x00000000 // Fault detect deglitch function Disable
    ,FDDGEN_1 = 0x80000000 // Fault detect deglitch function Enable
    ,FDCTL0_MASK = 0xB007807F
    ;
  };
  // EPWM Fault Detect Control Register 1
  using FDCTL1 = reg<ip_ver, base + 0x168>;
  // EPWM Fault Detect Control Register 2
  using FDCTL2 = reg<ip_ver, base + 0x16C>;
  // EPWM Fault Detect Control Register 3
  using FDCTL3 = reg<ip_ver, base + 0x170>;
  // EPWM Fault Detect Control Register 4
  using FDCTL4 = reg<ip_ver, base + 0x174>;
  // EPWM Fault Detect Control Register 5
  using FDCTL5 = reg<ip_ver, base + 0x178>;
  // EPWM Fault Detect Interrupt Enable Register
  struct FDIEN : reg<ip_ver, base + 0x17C>
  {
    static constexpr typename FDIEN::type
    // EPWM Channel n Fault Detect Interrupt Enable Bit (bits: 0)
     FDIENN_MASK = 0x00000001
    ,FDIENN_POS = 0
    ,FDIENN_0 = 0x00000000 // EPWM Channel n Fault Detect Interrupt Disable
    ,FDIENN_1 = 0x00000001 // EPWM Channel n Fault Detect Interrupt Enable
    ,FDIEN_MASK = 0x00000001
    ;
  };
  // EPWM Fault Detect Interrupt Flag Register
  struct FDSTS : reg<ip_ver, base + 0x180>
  {
    static constexpr typename FDSTS::type
    // EPWM Channel n Fault Detect Interrupt Flag Bit Fault Detect Interrupt Flag will be set when EPWM output short. Software can clear this bit by writing 1 to it. (bits: 5-0)
     FDIFN_MASK = 0x0000003F
    ,FDIFN_POS = 0
    ,FDSTS_MASK = 0x0000003F
    ;
  };
  // EPWM Trigger EADC Prescale Control Register
  struct EADCPSCCTL : reg<ip_ver, base + 0x184>
  {
    static constexpr typename EADCPSCCTL::type
    // EPWM Trigger EADC Pre-scale Function Enable Bits (bits: 0)
     PSCEN0_MASK = 0x00000001
    ,PSCEN0_POS = 0
    ,PSCEN0_0 = 0x00000000 // EPWM Trigger EADC Pre-scale Function Disable
    ,PSCEN0_1 = 0x00000001 // EPWM Trigger EADC Pre-scale Function Enable
    // EPWM Trigger EADC Pre-scale Function Enable Bits (bits: 1)
    ,PSCEN1_MASK = 0x00000002
    ,PSCEN1_POS = 1
    ,PSCEN1_0 = 0x00000000 // EPWM Trigger EADC Pre-scale Function Disable
    ,PSCEN1_1 = 0x00000002 // EPWM Trigger EADC Pre-scale Function Enable
    // EPWM Trigger EADC Pre-scale Function Enable Bits (bits: 2)
    ,PSCEN2_MASK = 0x00000004
    ,PSCEN2_POS = 2
    ,PSCEN2_0 = 0x00000000 // EPWM Trigger EADC Pre-scale Function Disable
    ,PSCEN2_1 = 0x00000004 // EPWM Trigger EADC Pre-scale Function Enable
    // EPWM Trigger EADC Pre-scale Function Enable Bits (bits: 3)
    ,PSCEN3_MASK = 0x00000008
    ,PSCEN3_POS = 3
    ,PSCEN3_0 = 0x00000000 // EPWM Trigger EADC Pre-scale Function Disable
    ,PSCEN3_1 = 0x00000008 // EPWM Trigger EADC Pre-scale Function Enable
    // EPWM Trigger EADC Pre-scale Function Enable Bits (bits: 4)
    ,PSCEN4_MASK = 0x00000010
    ,PSCEN4_POS = 4
    ,PSCEN4_0 = 0x00000000 // EPWM Trigger EADC Pre-scale Function Disable
    ,PSCEN4_1 = 0x00000010 // EPWM Trigger EADC Pre-scale Function Enable
    // EPWM Trigger EADC Pre-scale Function Enable Bits (bits: 5)
    ,PSCEN5_MASK = 0x00000020
    ,PSCEN5_POS = 5
    ,PSCEN5_0 = 0x00000000 // EPWM Trigger EADC Pre-scale Function Disable
    ,PSCEN5_1 = 0x00000020 // EPWM Trigger EADC Pre-scale Function Enable
    ,EADCPSCCTL_MASK = 0x0000003F
    ;
  };
  // EPWM Trigger EADC Prescale Register 0
  struct EADCPSC0 : reg<ip_ver, base + 0x188>
  {
    static constexpr typename EADCPSC0::type
    // EPWM Channel 0 Trigger EADC Prescale The register sets the count number which defines (EADCPSC0+1) times of EPWM_CH0 trigger EADC event occurs to trigger EADC and set trigger EADC flag bit EADCTRGF0. (bits: 3-0)
     EADCPSC0VAL_MASK = 0x0000000F
    ,EADCPSC0VAL_POS = 0
    // EPWM Channel 1 Trigger EADC Prescale The register sets the count number which defines (EADCPSC1+1) times of EPWM_CH1 trigger EADC event occurs to trigger EADC and set trigger EADC flag bit EADCTRGF1. (bits: 11-8)
    ,EADCPSC1_MASK = 0x00000F00
    ,EADCPSC1_POS = 8
    // EPWM Channel 2 Trigger EADC Prescale The register sets the count number which defines (EADCPSC2+1) times of EPWM_CH2 trigger EADC event occurs to trigger EADC and set trigger EADC flag bit EADCTRGF2. (bits: 19-16)
    ,EADCPSC2_MASK = 0x000F0000
    ,EADCPSC2_POS = 16
    // EPWM Channel 3 Trigger EADC Prescale The register sets the count number which defines (EADCPSC3+1) times of EPWM_CH3 trigger EADC event occurs to trigger EADC and set trigger EADC flag bit EADCTRGF3. (bits: 27-24)
    ,EADCPSC3_MASK = 0x0F000000
    ,EADCPSC3_POS = 24
    ,EADCPSC0_MASK = 0x0F0F0F0F
    ;
  };
  // EPWM Trigger EADC Prescale Register 1
  struct EADCPSC1 : reg<ip_ver, base + 0x18C>
  {
    static constexpr typename EADCPSC1::type
    // EPWM Channel 4 Trigger EADC Prescale The register sets the count number which defines (EADCPSC4+1) times of EPWM_CH4 trigger EADC event occurs to trigger EADC and set trigger EADC flag bit EADCTRGF4. (bits: 3-0)
     EADCPSC4_MASK = 0x0000000F
    ,EADCPSC4_POS = 0
    // EPWM Channel 5 Trigger EADC Prescale The register sets the count number which defines (EADCPSC5+1) times of EPWM_CH5 trigger EADC event occurs to trigger EADC and set trigger EADC flag bit EADCTRGF5. (bits: 11-8)
    ,EADCPSC5_MASK = 0x00000F00
    ,EADCPSC5_POS = 8
    ,EADCPSC1_MASK = 0x00000F0F
    ;
  };
  // EPWM Trigger EADC Prescale Counter Register 0
  struct EADCPSCNT0 : reg<ip_ver, base + 0x190>
  {
    static constexpr typename EADCPSCNT0::type
    // EPWM Trigger EADC Prescale Counter 0 User can monitor PSCNT0 to know the current value in 4-bit trigger EADC prescale counter. Note1: user can write only when PSCEN0 is 0. Note2: Write data limitation: PSCNT0 EADCPSC0. (bits: 3-0)
     PSCNT0_MASK = 0x0000000F
    ,PSCNT0_POS = 0
    // EPWM Trigger EADC Prescale Counter 1 User can monitor PSCNT1 to know the current value in 4-bit trigger EADC prescale counter. Note1: user can write only when PSCEN1 is 0. Note2: Write data limitation: PSCNT1 EADCPSC1. (bits: 11-8)
    ,PSCNT1_MASK = 0x00000F00
    ,PSCNT1_POS = 8
    // EPWM Trigger EADC Prescale Counter 2 User can monitor PSCNT2 to know the current value in 4-bit trigger EADC prescale counter. Note1: user can write only when PSCEN2 is 0. Note2: Write data limitation: PSCNT2 EADCPSC2. (bits: 19-16)
    ,PSCNT2_MASK = 0x000F0000
    ,PSCNT2_POS = 16
    // EPWM Trigger EADC Prescale Counter 3 User can monitor PSCNT3 to know the current value in 4-bit trigger EADC prescale counter. Note1: user can write only when PSCEN3 is 0. Note2: Write data limitation: PSCNT3 EADCPSC3. (bits: 27-24)
    ,PSCNT3_MASK = 0x0F000000
    ,PSCNT3_POS = 24
    ,EADCPSCNT0_MASK = 0x0F0F0F0F
    ;
  };
  // EPWM Trigger EADC Prescale Counter Register 1
  struct EADCPSCNT1 : reg<ip_ver, base + 0x194>
  {
    static constexpr typename EADCPSCNT1::type
    // EPWM Trigger EADC Prescale Counter 4 User can monitor PSCNT4 to know the current value in 4-bit trigger EADC prescale counter. Note1: user can write only when PSCEN4 is 0. Note2: Write data limitation: PSCNT4 EADCPSC4. (bits: 3-0)
     PSCNT4_MASK = 0x0000000F
    ,PSCNT4_POS = 0
    // EPWM Trigger EADC Prescale Counter 5 User can monitor PSCNT5 to know the current value in 4-bit trigger EADC prescale counter. Note1: user can write only when PSCEN5 is 0. Note2: Write data limitation: PSCNT5 EADCPSC5. (bits: 11-8)
    ,PSCNT5_MASK = 0x00000F00
    ,PSCNT5_POS = 8
    ,EADCPSCNT1_MASK = 0x00000F0F
    ;
  };
  // EPWM Capture Input Enable Register
  struct CAPINEN : reg<ip_ver, base + 0x200>
  {
    static constexpr typename CAPINEN::type
    // Capture Input Enable Bits (bits: 0)
     CAPINEN0_MASK = 0x00000001
    ,CAPINEN0_POS = 0
    ,CAPINEN0_0 = 0x00000000 // EPWM Channel capture input path Disabled. The input of EPWM channel capture function is always regarded as 0
    ,CAPINEN0_1 = 0x00000001 // EPWM Channel capture input path Enabled. The input of EPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits (bits: 1)
    ,CAPINEN1_MASK = 0x00000002
    ,CAPINEN1_POS = 1
    ,CAPINEN1_0 = 0x00000000 // EPWM Channel capture input path Disabled. The input of EPWM channel capture function is always regarded as 0
    ,CAPINEN1_1 = 0x00000002 // EPWM Channel capture input path Enabled. The input of EPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits (bits: 2)
    ,CAPINEN2_MASK = 0x00000004
    ,CAPINEN2_POS = 2
    ,CAPINEN2_0 = 0x00000000 // EPWM Channel capture input path Disabled. The input of EPWM channel capture function is always regarded as 0
    ,CAPINEN2_1 = 0x00000004 // EPWM Channel capture input path Enabled. The input of EPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits (bits: 3)
    ,CAPINEN3_MASK = 0x00000008
    ,CAPINEN3_POS = 3
    ,CAPINEN3_0 = 0x00000000 // EPWM Channel capture input path Disabled. The input of EPWM channel capture function is always regarded as 0
    ,CAPINEN3_1 = 0x00000008 // EPWM Channel capture input path Enabled. The input of EPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits (bits: 4)
    ,CAPINEN4_MASK = 0x00000010
    ,CAPINEN4_POS = 4
    ,CAPINEN4_0 = 0x00000000 // EPWM Channel capture input path Disabled. The input of EPWM channel capture function is always regarded as 0
    ,CAPINEN4_1 = 0x00000010 // EPWM Channel capture input path Enabled. The input of EPWM channel capture function comes from correlative multifunction pin
    // Capture Input Enable Bits (bits: 5)
    ,CAPINEN5_MASK = 0x00000020
    ,CAPINEN5_POS = 5
    ,CAPINEN5_0 = 0x00000000 // EPWM Channel capture input path Disabled. The input of EPWM channel capture function is always regarded as 0
    ,CAPINEN5_1 = 0x00000020 // EPWM Channel capture input path Enabled. The input of EPWM channel capture function comes from correlative multifunction pin
    ,CAPINEN_MASK = 0x0000003F
    ;
  };
  // EPWM Capture Control Register
  struct CAPCTL : reg<ip_ver, base + 0x204>
  {
    static constexpr typename CAPCTL::type
    // Capture Function Enable Bits (bits: 0)
     CAPEN0_MASK = 0x00000001
    ,CAPEN0_POS = 0
    ,CAPEN0_0 = 0x00000000 // Capture function Disabled. EPWM_RCAPDATn/EPWM_FCAPDATn register will not be updated
    ,CAPEN0_1 = 0x00000001 // Capture function Enabled. Capture latched the EPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits (bits: 1)
    ,CAPEN1_MASK = 0x00000002
    ,CAPEN1_POS = 1
    ,CAPEN1_0 = 0x00000000 // Capture function Disabled. EPWM_RCAPDATn/EPWM_FCAPDATn register will not be updated
    ,CAPEN1_1 = 0x00000002 // Capture function Enabled. Capture latched the EPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits (bits: 2)
    ,CAPEN2_MASK = 0x00000004
    ,CAPEN2_POS = 2
    ,CAPEN2_0 = 0x00000000 // Capture function Disabled. EPWM_RCAPDATn/EPWM_FCAPDATn register will not be updated
    ,CAPEN2_1 = 0x00000004 // Capture function Enabled. Capture latched the EPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits (bits: 3)
    ,CAPEN3_MASK = 0x00000008
    ,CAPEN3_POS = 3
    ,CAPEN3_0 = 0x00000000 // Capture function Disabled. EPWM_RCAPDATn/EPWM_FCAPDATn register will not be updated
    ,CAPEN3_1 = 0x00000008 // Capture function Enabled. Capture latched the EPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits (bits: 4)
    ,CAPEN4_MASK = 0x00000010
    ,CAPEN4_POS = 4
    ,CAPEN4_0 = 0x00000000 // Capture function Disabled. EPWM_RCAPDATn/EPWM_FCAPDATn register will not be updated
    ,CAPEN4_1 = 0x00000010 // Capture function Enabled. Capture latched the EPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Function Enable Bits (bits: 5)
    ,CAPEN5_MASK = 0x00000020
    ,CAPEN5_POS = 5
    ,CAPEN5_0 = 0x00000000 // Capture function Disabled. EPWM_RCAPDATn/EPWM_FCAPDATn register will not be updated
    ,CAPEN5_1 = 0x00000020 // Capture function Enabled. Capture latched the EPWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch)
    // Capture Inverter Enable Bits (bits: 8)
    ,CAPINV0_MASK = 0x00000100
    ,CAPINV0_POS = 8
    ,CAPINV0_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV0_1 = 0x00000100 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits (bits: 9)
    ,CAPINV1_MASK = 0x00000200
    ,CAPINV1_POS = 9
    ,CAPINV1_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV1_1 = 0x00000200 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits (bits: 10)
    ,CAPINV2_MASK = 0x00000400
    ,CAPINV2_POS = 10
    ,CAPINV2_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV2_1 = 0x00000400 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits (bits: 11)
    ,CAPINV3_MASK = 0x00000800
    ,CAPINV3_POS = 11
    ,CAPINV3_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV3_1 = 0x00000800 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits (bits: 12)
    ,CAPINV4_MASK = 0x00001000
    ,CAPINV4_POS = 12
    ,CAPINV4_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV4_1 = 0x00001000 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Capture Inverter Enable Bits (bits: 13)
    ,CAPINV5_MASK = 0x00002000
    ,CAPINV5_POS = 13
    ,CAPINV5_0 = 0x00000000 // Capture source inverter Disabled
    ,CAPINV5_1 = 0x00002000 // Capture source inverter Enabled. Reverse the input signal from GPIO
    // Rising Capture Reload Enable Bits (bits: 16)
    ,RCRLDEN0_MASK = 0x00010000
    ,RCRLDEN0_POS = 16
    ,RCRLDEN0_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN0_1 = 0x00010000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits (bits: 17)
    ,RCRLDEN1_MASK = 0x00020000
    ,RCRLDEN1_POS = 17
    ,RCRLDEN1_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN1_1 = 0x00020000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits (bits: 18)
    ,RCRLDEN2_MASK = 0x00040000
    ,RCRLDEN2_POS = 18
    ,RCRLDEN2_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN2_1 = 0x00040000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits (bits: 19)
    ,RCRLDEN3_MASK = 0x00080000
    ,RCRLDEN3_POS = 19
    ,RCRLDEN3_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN3_1 = 0x00080000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits (bits: 20)
    ,RCRLDEN4_MASK = 0x00100000
    ,RCRLDEN4_POS = 20
    ,RCRLDEN4_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN4_1 = 0x00100000 // Rising capture reload counter Enabled
    // Rising Capture Reload Enable Bits (bits: 21)
    ,RCRLDEN5_MASK = 0x00200000
    ,RCRLDEN5_POS = 21
    ,RCRLDEN5_0 = 0x00000000 // Rising capture reload counter Disabled
    ,RCRLDEN5_1 = 0x00200000 // Rising capture reload counter Enabled
    // Falling Capture Reload Enable Bits (bits: 24)
    ,FCRLDEN0_MASK = 0x01000000
    ,FCRLDEN0_POS = 24
    ,FCRLDEN0_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN0_1 = 0x01000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits (bits: 25)
    ,FCRLDEN1_MASK = 0x02000000
    ,FCRLDEN1_POS = 25
    ,FCRLDEN1_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN1_1 = 0x02000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits (bits: 26)
    ,FCRLDEN2_MASK = 0x04000000
    ,FCRLDEN2_POS = 26
    ,FCRLDEN2_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN2_1 = 0x04000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits (bits: 27)
    ,FCRLDEN3_MASK = 0x08000000
    ,FCRLDEN3_POS = 27
    ,FCRLDEN3_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN3_1 = 0x08000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits (bits: 28)
    ,FCRLDEN4_MASK = 0x10000000
    ,FCRLDEN4_POS = 28
    ,FCRLDEN4_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN4_1 = 0x10000000 // Falling capture reload counter Enabled
    // Falling Capture Reload Enable Bits (bits: 29)
    ,FCRLDEN5_MASK = 0x20000000
    ,FCRLDEN5_POS = 29
    ,FCRLDEN5_0 = 0x00000000 // Falling capture reload counter Disabled
    ,FCRLDEN5_1 = 0x20000000 // Falling capture reload counter Enabled
    ,CAPCTL_MASK = 0x3F3F3F3F
    ;
  };
  // EPWM Capture Status Register
  struct CAPSTS : reg<ip_ver, base + 0x208>
  {
    static constexpr typename CAPSTS::type
    // Capture Rising Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CRLIFn(EPWM_CAPIF[n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CRLIFn(EPWM_CAPIF[n]). (bits: 0)
     CRLIFOV0_MASK = 0x00000001
    ,CRLIFOV0_POS = 0
    ,CRLIFOV0 = 0x00000001
    // Capture Rising Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CRLIFn(EPWM_CAPIF[n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CRLIFn(EPWM_CAPIF[n]). (bits: 1)
    ,CRLIFOV1_MASK = 0x00000002
    ,CRLIFOV1_POS = 1
    ,CRLIFOV1 = 0x00000002
    // Capture Rising Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CRLIFn(EPWM_CAPIF[n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CRLIFn(EPWM_CAPIF[n]). (bits: 2)
    ,CRLIFOV2_MASK = 0x00000004
    ,CRLIFOV2_POS = 2
    ,CRLIFOV2 = 0x00000004
    // Capture Rising Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CRLIFn(EPWM_CAPIF[n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CRLIFn(EPWM_CAPIF[n]). (bits: 3)
    ,CRLIFOV3_MASK = 0x00000008
    ,CRLIFOV3_POS = 3
    ,CRLIFOV3 = 0x00000008
    // Capture Rising Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CRLIFn(EPWM_CAPIF[n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CRLIFn(EPWM_CAPIF[n]). (bits: 4)
    ,CRLIFOV4_MASK = 0x00000010
    ,CRLIFOV4_POS = 4
    ,CRLIFOV4 = 0x00000010
    // Capture Rising Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if rising latch happened when the corresponding CRLIFn(EPWM_CAPIF[n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CRLIFn(EPWM_CAPIF[n]). (bits: 5)
    ,CRLIFOV5_MASK = 0x00000020
    ,CRLIFOV5_POS = 5
    ,CRLIFOV5 = 0x00000020
    // Capture Falling Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CFLIFn(EPWM_CAPIF[8+n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CFLIFn(EPWM_CAPIF[8+n]). (bits: 8)
    ,CFLIFOV0_MASK = 0x00000100
    ,CFLIFOV0_POS = 8
    ,CFLIFOV0 = 0x00000100
    // Capture Falling Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CFLIFn(EPWM_CAPIF[8+n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CFLIFn(EPWM_CAPIF[8+n]). (bits: 9)
    ,CFLIFOV1_MASK = 0x00000200
    ,CFLIFOV1_POS = 9
    ,CFLIFOV1 = 0x00000200
    // Capture Falling Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CFLIFn(EPWM_CAPIF[8+n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CFLIFn(EPWM_CAPIF[8+n]). (bits: 10)
    ,CFLIFOV2_MASK = 0x00000400
    ,CFLIFOV2_POS = 10
    ,CFLIFOV2 = 0x00000400
    // Capture Falling Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CFLIFn(EPWM_CAPIF[8+n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CFLIFn(EPWM_CAPIF[8+n]). (bits: 11)
    ,CFLIFOV3_MASK = 0x00000800
    ,CFLIFOV3_POS = 11
    ,CFLIFOV3 = 0x00000800
    // Capture Falling Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CFLIFn(EPWM_CAPIF[8+n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CFLIFn(EPWM_CAPIF[8+n]). (bits: 12)
    ,CFLIFOV4_MASK = 0x00001000
    ,CFLIFOV4_POS = 12
    ,CFLIFOV4 = 0x00001000
    // Capture Falling Latch Interrupt Flag Overrun Status (Read Only) This flag indicates if falling latch happened when the corresponding CFLIFn(EPWM_CAPIF[8+n]) is 1. Note: This bit will be cleared automatically when user clear corresponding CFLIFn(EPWM_CAPIF[8+n]). (bits: 13)
    ,CFLIFOV5_MASK = 0x00002000
    ,CFLIFOV5_POS = 13
    ,CFLIFOV5 = 0x00002000
    ,CAPSTS_MASK = 0x00003F3F
    ;
  };
  // EPWM Rising Capture Data Register 0
  struct RCAPDAT0 : reg<ip_ver, base + 0x20C>
  {
    static constexpr typename RCAPDAT0::type
    // EPWM Rising Capture Data Register (Read Only) When rising capture condition happened, the EPWM counter value will be saved in this register. (bits: 15-0)
     RCAPDAT_MASK = 0x0000FFFF
    ,RCAPDAT_POS = 0
    ,RCAPDAT0_MASK = 0x0000FFFF
    ;
  };
  // EPWM Falling Capture Data Register 0
  struct FCAPDAT0 : reg<ip_ver, base + 0x210>
  {
    static constexpr typename FCAPDAT0::type
    // EPWM Falling Capture Data Register (Read Only) When falling capture condition happened, the EPWM counter value will be saved in this register. (bits: 15-0)
     FCAPDAT_MASK = 0x0000FFFF
    ,FCAPDAT_POS = 0
    ,FCAPDAT0_MASK = 0x0000FFFF
    ;
  };
  // EPWM Rising Capture Data Register 1
  using RCAPDAT1 = reg<ip_ver, base + 0x214>;
  // EPWM Falling Capture Data Register 1
  using FCAPDAT1 = reg<ip_ver, base + 0x218>;
  // EPWM Rising Capture Data Register 2
  using RCAPDAT2 = reg<ip_ver, base + 0x21C>;
  // EPWM Falling Capture Data Register 2
  using FCAPDAT2 = reg<ip_ver, base + 0x220>;
  // EPWM Rising Capture Data Register 3
  using RCAPDAT3 = reg<ip_ver, base + 0x224>;
  // EPWM Falling Capture Data Register 3
  using FCAPDAT3 = reg<ip_ver, base + 0x228>;
  // EPWM Rising Capture Data Register 4
  using RCAPDAT4 = reg<ip_ver, base + 0x22C>;
  // EPWM Falling Capture Data Register 4
  using FCAPDAT4 = reg<ip_ver, base + 0x230>;
  // EPWM Rising Capture Data Register 5
  using RCAPDAT5 = reg<ip_ver, base + 0x234>;
  // EPWM Falling Capture Data Register 5
  using FCAPDAT5 = reg<ip_ver, base + 0x238>;
  // EPWM PDMA Control Register
  struct PDMACTL : reg<ip_ver, base + 0x23C>
  {
    static constexpr typename PDMACTL::type
    // Channel 0/1 PDMA Enable Bit (bits: 0)
     CHEN0_1_MASK = 0x00000001
    ,CHEN0_1_POS = 0
    ,CHEN0_1_0 = 0x00000000 // Channel 0/1 PDMA function Disabled
    ,CHEN0_1_1 = 0x00000001 // Channel 0/1 PDMA function Enabled for the channel 0/1 captured data and transfer to memory
    // Select EPWM_RCAPDAT0/1 or EPWM_FCAPDAT0/1 to Do PDMA Transfer (bits: 2-1)
    ,CAPMOD0_1_MASK = 0x00000006
    ,CAPMOD0_1_POS = 1
    ,CAPMOD0_1_0 = 0x00000000 // Reserved.
    ,CAPMOD0_1_1 = 0x00000002 // EPWM_RCAPDAT0/1
    ,CAPMOD0_1_2 = 0x00000004 // EPWM_FCAPDAT0/1
    ,CAPMOD0_1_3 = 0x00000006 // Both EPWM_RCAPDAT0/1 and EPWM_FCAPDAT0/1
    // Capture Channel 0/1 Rising/Falling Order (bits: 3)
    ,CAPORD0_1_MASK = 0x00000008
    ,CAPORD0_1_POS = 3
    ,CAPORD0_1_0 = 0x00000000 // EPWM_FCAPDAT0/1 is the first captured data to memory
    ,CAPORD0_1_1 = 0x00000008 // EPWM_RCAPDAT0/1 is the first captured data to memory
    // Select Channel 0/1 to Do PDMA Transfer (bits: 4)
    ,CHSEL0_1_MASK = 0x00000010
    ,CHSEL0_1_POS = 4
    ,CHSEL0_1_0 = 0x00000000 // Channel0
    ,CHSEL0_1_1 = 0x00000010 // Channel1
    // Channel 2/3 PDMA Enable Bit (bits: 8)
    ,CHEN2_3_MASK = 0x00000100
    ,CHEN2_3_POS = 8
    ,CHEN2_3_0 = 0x00000000 // Channel 2/3 PDMA function Disabled
    ,CHEN2_3_1 = 0x00000100 // Channel 2/3 PDMA function Enabled for the channel 2/3 captured data and transfer to memory
    // Select EPWM_RCAPDAT2/3 or EPWM_FCAODAT2/3 to Do PDMA Transfer (bits: 10-9)
    ,CAPMOD2_3_MASK = 0x00000600
    ,CAPMOD2_3_POS = 9
    ,CAPMOD2_3_0 = 0x00000000 // Reserved.
    ,CAPMOD2_3_1 = 0x00000200 // EPWM_RCAPDAT2/3
    ,CAPMOD2_3_2 = 0x00000400 // EPWM_FCAPDAT2/3
    ,CAPMOD2_3_3 = 0x00000600 // Both EPWM_RCAPDAT2/3 and EPWM_FCAPDAT2/3
    // Capture Channel 2/3 Rising/Falling Order (bits: 11)
    ,CAPORD2_3_MASK = 0x00000800
    ,CAPORD2_3_POS = 11
    ,CAPORD2_3_0 = 0x00000000 // EPWM_FCAPDAT2/3 is the first captured data to memory
    ,CAPORD2_3_1 = 0x00000800 // EPWM_RCAPDAT2/3 is the first captured data to memory
    // Select Channel 2/3 to Do PDMA Transfer (bits: 12)
    ,CHSEL2_3_MASK = 0x00001000
    ,CHSEL2_3_POS = 12
    ,CHSEL2_3_0 = 0x00000000 // Channel2
    ,CHSEL2_3_1 = 0x00001000 // Channel3
    // Channel 4/5 PDMA Enable Bit (bits: 16)
    ,CHEN4_5_MASK = 0x00010000
    ,CHEN4_5_POS = 16
    ,CHEN4_5_0 = 0x00000000 // Channel 4/5 PDMA function Disabled
    ,CHEN4_5_1 = 0x00010000 // Channel 4/5 PDMA function Enabled for the channel 4/5 captured data and transfer to memory
    // Select EPWM_RCAPDAT4/5 or EPWM_FCAPDAT4/5 to Do PDMA Transfer (bits: 18-17)
    ,CAPMOD4_5_MASK = 0x00060000
    ,CAPMOD4_5_POS = 17
    ,CAPMOD4_5_0 = 0x00000000 // Reserved.
    ,CAPMOD4_5_1 = 0x00020000 // EPWM_RCAPDAT4/5
    ,CAPMOD4_5_2 = 0x00040000 // EPWM_FCAPDAT4/5
    ,CAPMOD4_5_3 = 0x00060000 // Both EPWM_RCAPDAT4/5 and EPWM_FCAPDAT4/5
    // Capture Channel 4/5 Rising/Falling Order (bits: 19)
    ,CAPORD4_5_MASK = 0x00080000
    ,CAPORD4_5_POS = 19
    ,CAPORD4_5_0 = 0x00000000 // EPWM_FCAPDAT4/5 is the first captured data to memory
    ,CAPORD4_5_1 = 0x00080000 // EPWM_RCAPDAT4/5 is the first captured data to memory
    // Select Channel 4/5 to Do PDMA Transfer (bits: 20)
    ,CHSEL4_5_MASK = 0x00100000
    ,CHSEL4_5_POS = 20
    ,CHSEL4_5_0 = 0x00000000 // Channel4
    ,CHSEL4_5_1 = 0x00100000 // Channel5
    ,PDMACTL_MASK = 0x001F1F1F
    ;
  };
  // EPWM Capture Channel 01 PDMA Register
  struct PDMACAP0_1 : reg<ip_ver, base + 0x240>
  {
    static constexpr typename PDMACAP0_1::type
    // EPWM Capture PDMA Register (Read Only) This register is used as a buffer to transfer EPWM capture rising or falling data to memory by PDMA. (bits: 15-0)
     CAPBUF_MASK = 0x0000FFFF
    ,CAPBUF_POS = 0
    ,PDMACAP0_1_MASK = 0x0000FFFF
    ;
  };
  // EPWM Capture Channel 23 PDMA Register
  using PDMACAP2_3 = reg<ip_ver, base + 0x244>;
  // EPWM Capture Channel 45 PDMA Register
  using PDMACAP4_5 = reg<ip_ver, base + 0x248>;
  // EPWM Capture Interrupt Enable Register
  struct CAPIEN : reg<ip_ver, base + 0x250>
  {
    static constexpr typename CAPIEN::type
    // EPWM Capture Rising Latch Interrupt Enable Bits (bits: 0)
     CAPRIEN0_MASK = 0x00000001
    ,CAPRIEN0_POS = 0
    ,CAPRIEN0_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIEN0_1 = 0x00000001 // Capture rising edge latch interrupt Enabled
    // EPWM Capture Rising Latch Interrupt Enable Bits (bits: 1)
    ,CAPRIEN1_MASK = 0x00000002
    ,CAPRIEN1_POS = 1
    ,CAPRIEN1_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIEN1_1 = 0x00000002 // Capture rising edge latch interrupt Enabled
    // EPWM Capture Rising Latch Interrupt Enable Bits (bits: 2)
    ,CAPRIEN2_MASK = 0x00000004
    ,CAPRIEN2_POS = 2
    ,CAPRIEN2_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIEN2_1 = 0x00000004 // Capture rising edge latch interrupt Enabled
    // EPWM Capture Rising Latch Interrupt Enable Bits (bits: 3)
    ,CAPRIEN3_MASK = 0x00000008
    ,CAPRIEN3_POS = 3
    ,CAPRIEN3_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIEN3_1 = 0x00000008 // Capture rising edge latch interrupt Enabled
    // EPWM Capture Rising Latch Interrupt Enable Bits (bits: 4)
    ,CAPRIEN4_MASK = 0x00000010
    ,CAPRIEN4_POS = 4
    ,CAPRIEN4_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIEN4_1 = 0x00000010 // Capture rising edge latch interrupt Enabled
    // EPWM Capture Rising Latch Interrupt Enable Bits (bits: 5)
    ,CAPRIEN5_MASK = 0x00000020
    ,CAPRIEN5_POS = 5
    ,CAPRIEN5_0 = 0x00000000 // Capture rising edge latch interrupt Disabled
    ,CAPRIEN5_1 = 0x00000020 // Capture rising edge latch interrupt Enabled
    // EPWM Capture Falling Latch Interrupt Enable Bits (bits: 8)
    ,CAPFIEN0_MASK = 0x00000100
    ,CAPFIEN0_POS = 8
    ,CAPFIEN0_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIEN0_1 = 0x00000100 // Capture falling edge latch interrupt Enabled
    // EPWM Capture Falling Latch Interrupt Enable Bits (bits: 9)
    ,CAPFIEN1_MASK = 0x00000200
    ,CAPFIEN1_POS = 9
    ,CAPFIEN1_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIEN1_1 = 0x00000200 // Capture falling edge latch interrupt Enabled
    // EPWM Capture Falling Latch Interrupt Enable Bits (bits: 10)
    ,CAPFIEN2_MASK = 0x00000400
    ,CAPFIEN2_POS = 10
    ,CAPFIEN2_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIEN2_1 = 0x00000400 // Capture falling edge latch interrupt Enabled
    // EPWM Capture Falling Latch Interrupt Enable Bits (bits: 11)
    ,CAPFIEN3_MASK = 0x00000800
    ,CAPFIEN3_POS = 11
    ,CAPFIEN3_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIEN3_1 = 0x00000800 // Capture falling edge latch interrupt Enabled
    // EPWM Capture Falling Latch Interrupt Enable Bits (bits: 12)
    ,CAPFIEN4_MASK = 0x00001000
    ,CAPFIEN4_POS = 12
    ,CAPFIEN4_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIEN4_1 = 0x00001000 // Capture falling edge latch interrupt Enabled
    // EPWM Capture Falling Latch Interrupt Enable Bits (bits: 13)
    ,CAPFIEN5_MASK = 0x00002000
    ,CAPFIEN5_POS = 13
    ,CAPFIEN5_0 = 0x00000000 // Capture falling edge latch interrupt Disabled
    ,CAPFIEN5_1 = 0x00002000 // Capture falling edge latch interrupt Enabled
    ,CAPIEN_MASK = 0x00003F3F
    ;
  };
  // EPWM Capture Interrupt Flag Register
  struct CAPIF : reg<ip_ver, base + 0x254>
  {
    static constexpr typename CAPIF::type
    // EPWM Capture Rising Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CRLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 0)
     CRLIF0_MASK = 0x00000001
    ,CRLIF0_POS = 0
    ,CRLIF0_0 = 0x00000000 // No capture rising latch condition happened
    ,CRLIF0_1 = 0x00000001 // Capture rising latch condition happened, this flag will be set to high
    // EPWM Capture Rising Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CRLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 1)
    ,CRLIF1_MASK = 0x00000002
    ,CRLIF1_POS = 1
    ,CRLIF1_0 = 0x00000000 // No capture rising latch condition happened
    ,CRLIF1_1 = 0x00000002 // Capture rising latch condition happened, this flag will be set to high
    // EPWM Capture Rising Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CRLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 2)
    ,CRLIF2_MASK = 0x00000004
    ,CRLIF2_POS = 2
    ,CRLIF2_0 = 0x00000000 // No capture rising latch condition happened
    ,CRLIF2_1 = 0x00000004 // Capture rising latch condition happened, this flag will be set to high
    // EPWM Capture Rising Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CRLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 3)
    ,CRLIF3_MASK = 0x00000008
    ,CRLIF3_POS = 3
    ,CRLIF3_0 = 0x00000000 // No capture rising latch condition happened
    ,CRLIF3_1 = 0x00000008 // Capture rising latch condition happened, this flag will be set to high
    // EPWM Capture Rising Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CRLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 4)
    ,CRLIF4_MASK = 0x00000010
    ,CRLIF4_POS = 4
    ,CRLIF4_0 = 0x00000000 // No capture rising latch condition happened
    ,CRLIF4_1 = 0x00000010 // Capture rising latch condition happened, this flag will be set to high
    // EPWM Capture Rising Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CRLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 5)
    ,CRLIF5_MASK = 0x00000020
    ,CRLIF5_POS = 5
    ,CRLIF5_0 = 0x00000000 // No capture rising latch condition happened
    ,CRLIF5_1 = 0x00000020 // Capture rising latch condition happened, this flag will be set to high
    // EPWM Capture Falling Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CFLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 8)
    ,CFLIF0_MASK = 0x00000100
    ,CFLIF0_POS = 8
    ,CFLIF0_0 = 0x00000000 // No capture falling latch condition happened
    ,CFLIF0_1 = 0x00000100 // Capture falling latch condition happened, this flag will be set to high
    // EPWM Capture Falling Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CFLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 9)
    ,CFLIF1_MASK = 0x00000200
    ,CFLIF1_POS = 9
    ,CFLIF1_0 = 0x00000000 // No capture falling latch condition happened
    ,CFLIF1_1 = 0x00000200 // Capture falling latch condition happened, this flag will be set to high
    // EPWM Capture Falling Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CFLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 10)
    ,CFLIF2_MASK = 0x00000400
    ,CFLIF2_POS = 10
    ,CFLIF2_0 = 0x00000000 // No capture falling latch condition happened
    ,CFLIF2_1 = 0x00000400 // Capture falling latch condition happened, this flag will be set to high
    // EPWM Capture Falling Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CFLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 11)
    ,CFLIF3_MASK = 0x00000800
    ,CFLIF3_POS = 11
    ,CFLIF3_0 = 0x00000000 // No capture falling latch condition happened
    ,CFLIF3_1 = 0x00000800 // Capture falling latch condition happened, this flag will be set to high
    // EPWM Capture Falling Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CFLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 12)
    ,CFLIF4_MASK = 0x00001000
    ,CFLIF4_POS = 12
    ,CFLIF4_0 = 0x00000000 // No capture falling latch condition happened
    ,CFLIF4_1 = 0x00001000 // Capture falling latch condition happened, this flag will be set to high
    // EPWM Capture Falling Latch Interrupt Flag Note1: When Capture with PDMA operating, EPWM_CAPIF corresponding channel CFLIFn will be cleared by hardware after PDMA transfer data. Note2: This bit is cleared by writing 1 to it. (bits: 13)
    ,CFLIF5_MASK = 0x00002000
    ,CFLIF5_POS = 13
    ,CFLIF5_0 = 0x00000000 // No capture falling latch condition happened
    ,CFLIF5_1 = 0x00002000 // Capture falling latch condition happened, this flag will be set to high
    ,CAPIF_MASK = 0x00003F3F
    ;
  };
  // EPWM PERIOD0 Buffer
  struct PBUF0 : reg<ip_ver, base + 0x304>
  {
    static constexpr typename PBUF0::type
    // EPWM Period Register Buffer (Read Only) Used as PERIOD active register. (bits: 15-0)
     PBUF_MASK = 0x0000FFFF
    ,PBUF_POS = 0
    ,PBUF0_MASK = 0x0000FFFF
    ;
  };
  // EPWM PERIOD1 Buffer
  using PBUF1 = reg<ip_ver, base + 0x308>;
  // EPWM PERIOD2 Buffer
  using PBUF2 = reg<ip_ver, base + 0x30C>;
  // EPWM PERIOD3 Buffer
  using PBUF3 = reg<ip_ver, base + 0x310>;
  // EPWM PERIOD4 Buffer
  using PBUF4 = reg<ip_ver, base + 0x314>;
  // EPWM PERIOD5 Buffer
  using PBUF5 = reg<ip_ver, base + 0x318>;
  // EPWM CMPDAT0 Buffer
  struct CMPBUF0 : reg<ip_ver, base + 0x31C>
  {
    static constexpr typename CMPBUF0::type
    // EPWM Comparator Register Buffer (Read Only) Used as CMP active register. (bits: 15-0)
     CMPBUF_MASK = 0x0000FFFF
    ,CMPBUF_POS = 0
    ,CMPBUF0_MASK = 0x0000FFFF
    ;
  };
  // EPWM CMPDAT1 Buffer
  using CMPBUF1 = reg<ip_ver, base + 0x320>;
  // EPWM CMPDAT2 Buffer
  using CMPBUF2 = reg<ip_ver, base + 0x324>;
  // EPWM CMPDAT3 Buffer
  using CMPBUF3 = reg<ip_ver, base + 0x328>;
  // EPWM CMPDAT4 Buffer
  using CMPBUF4 = reg<ip_ver, base + 0x32C>;
  // EPWM CMPDAT5 Buffer
  using CMPBUF5 = reg<ip_ver, base + 0x330>;
  // EPWM CLKPSC0_1 Buffer
  struct CPSCBUF0_1 : reg<ip_ver, base + 0x334>
  {
    static constexpr typename CPSCBUF0_1::type
    // EPWM Counter Clock Prescale Buffer Used as EPWM counter clock pre-scare active register. (bits: 11-0)
     CPSCBUF_MASK = 0x00000FFF
    ,CPSCBUF_POS = 0
    ,CPSCBUF0_1_MASK = 0x00000FFF
    ;
  };
  // EPWM CLKPSC2_3 Buffer
  using CPSCBUF2_3 = reg<ip_ver, base + 0x338>;
  // EPWM CLKPSC4_5 Buffer
  using CPSCBUF4_5 = reg<ip_ver, base + 0x33C>;
  // EPWM FTCMPDAT0_1 Buffer
  struct FTCBUF0_1 : reg<ip_ver, base + 0x340>
  {
    static constexpr typename FTCBUF0_1::type
    // EPWM FTCMPDAT Buffer (Read Only) Used as FTCMP active buffer. (bits: 15-0)
     FTCMPBUF_MASK = 0x0000FFFF
    ,FTCMPBUF_POS = 0
    ,FTCBUF0_1_MASK = 0x0000FFFF
    ;
  };
  // EPWM FTCMPDAT2_3 Buffer
  using FTCBUF2_3 = reg<ip_ver, base + 0x344>;
  // EPWM FTCMPDAT4_5 Buffer
  using FTCBUF4_5 = reg<ip_ver, base + 0x348>;
  // EPWM FTCMPDAT Indicator Register
  struct FTCI : reg<ip_ver, base + 0x34C>
  {
    static constexpr typename FTCI::type
    // EPWM FTCMPDAT Up Indicator Indicator is set by hardware when EPWM counter up count and reaches EPWM_FTCMPDATn, software can clear this bit by writing 1 to it. (bits: 0)
     FTCMU0_MASK = 0x00000001
    ,FTCMU0_POS = 0
    ,FTCMU0 = 0x00000001
    // EPWM FTCMPDAT Up Indicator Indicator is set by hardware when EPWM counter up count and reaches EPWM_FTCMPDATn, software can clear this bit by writing 1 to it. (bits: 1)
    ,FTCMU2_MASK = 0x00000002
    ,FTCMU2_POS = 1
    ,FTCMU2 = 0x00000002
    // EPWM FTCMPDAT Up Indicator Indicator is set by hardware when EPWM counter up count and reaches EPWM_FTCMPDATn, software can clear this bit by writing 1 to it. (bits: 2)
    ,FTCMU4_MASK = 0x00000004
    ,FTCMU4_POS = 2
    ,FTCMU4 = 0x00000004
    // EPWM FTCMPDAT Down Indicator Indicator is set by hardware when EPWM counter down count and reaches EPWM_FTCMPDATn, software can clear this bit by writing 1 to it. (bits: 8)
    ,FTCMD0_MASK = 0x00000100
    ,FTCMD0_POS = 8
    ,FTCMD0 = 0x00000100
    // EPWM FTCMPDAT Down Indicator Indicator is set by hardware when EPWM counter down count and reaches EPWM_FTCMPDATn, software can clear this bit by writing 1 to it. (bits: 9)
    ,FTCMD2_MASK = 0x00000200
    ,FTCMD2_POS = 9
    ,FTCMD2 = 0x00000200
    // EPWM FTCMPDAT Down Indicator Indicator is set by hardware when EPWM counter down count and reaches EPWM_FTCMPDATn, software can clear this bit by writing 1 to it. (bits: 10)
    ,FTCMD4_MASK = 0x00000400
    ,FTCMD4_POS = 10
    ,FTCMD4 = 0x00000400
    ,FTCI_MASK = 0x00000707
    ;
  };
}; // struct EPWM

} // namespace lmcu::device::ip::v1

