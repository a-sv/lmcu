/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// General-purpose timer
// ------------------------------------------------------------------------------------------------
struct TIM4
{
  static constexpr std::uintptr_t base = 0x40000800;

  // Control register 2
  struct CR2 : reg<16, base + 0x4, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Capture/compare DMA selection (bits: 3)
     CCDS_MASK = 0x00000008
    ,CCDS_POS = 3
    ,CCDS = 0x00000008
    // Master mode selection (bits: 6-4)
    ,MMS_MASK = 0x00000070
    ,MMS_POS = 4
    ,MMS_RESET = 0x00000000 // Reset - the UG bit from the TIMx_EGR register is used as trigger output (TRGO).
    ,MMS_ENABLE = 0x00000010 // Enable - the Counter Enable signal CNT_EN is used as trigger output (TRGO).
    ,MMS_UPDATE = 0x00000020 // Update - The update event is selected as trigger output (TRGO).
    ,MMS_COMPARE_PULSE = 0x00000030 // Compare Pulse - The trigger output send a positive pulse when the CC1IF flag is to be set (even if it was already high), as soon as a capture or a compare match occurred. 
    ,MMS_CMP_OC1REF = 0x00000040 // Compare - OC1REF signal is used as trigger output (TRGO)
    ,MMS_CMP_OC2REF = 0x00000050 // Compare - OC2REF signal is used as trigger output (TRGO)
    ,MMS_CMP_OC3REF = 0x00000060 // Compare - OC3REF signal is used as trigger output (TRGO)
    ,MMS_CMP_OC4REF = 0x00000070 // Compare - OC4REF signal is used as trigger output (TRGO)
    // TI1 selection (bits: 7)
    ,TI1S_MASK = 0x00000080
    ,TI1S_POS = 7
    ,TI1S = 0x00000080
    ,CR2_MASK = 0x000000F8
    ;
  };
  // DMA/interrupt enable register
  struct DIER : reg<16, base + 0xC, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Update interrupt enable (bits: 0)
     UIE_MASK = 0x00000001
    ,UIE_POS = 0
    ,UIE = 0x00000001
    // Capture/Compare 1 interrupt enable (bits: 1)
    ,CC1IE_MASK = 0x00000002
    ,CC1IE_POS = 1
    ,CC1IE = 0x00000002
    // Capture/Compare 2 interrupt enable (bits: 2)
    ,CC2IE_MASK = 0x00000004
    ,CC2IE_POS = 2
    ,CC2IE = 0x00000004
    // Capture/Compare 3 interrupt enable (bits: 3)
    ,CC3IE_MASK = 0x00000008
    ,CC3IE_POS = 3
    ,CC3IE = 0x00000008
    // Capture/Compare 4 interrupt enable (bits: 4)
    ,CC4IE_MASK = 0x00000010
    ,CC4IE_POS = 4
    ,CC4IE = 0x00000010
    // Trigger interrupt enable (bits: 6)
    ,TIE_MASK = 0x00000040
    ,TIE_POS = 6
    ,TIE = 0x00000040
    // Update DMA request enable (bits: 8)
    ,UDE_MASK = 0x00000100
    ,UDE_POS = 8
    ,UDE = 0x00000100
    // Capture/Compare 1 DMA request enable (bits: 9)
    ,CC1DE_MASK = 0x00000200
    ,CC1DE_POS = 9
    ,CC1DE = 0x00000200
    // Capture/Compare 2 DMA request enable (bits: 10)
    ,CC2DE_MASK = 0x00000400
    ,CC2DE_POS = 10
    ,CC2DE = 0x00000400
    // Capture/Compare 3 DMA request enable (bits: 11)
    ,CC3DE_MASK = 0x00000800
    ,CC3DE_POS = 11
    ,CC3DE = 0x00000800
    // Capture/Compare 4 DMA request enable (bits: 12)
    ,CC4DE_MASK = 0x00001000
    ,CC4DE_POS = 12
    ,CC4DE = 0x00001000
    // Trigger DMA request enable (bits: 14)
    ,TDE_MASK = 0x00004000
    ,TDE_POS = 14
    ,TDE = 0x00004000
    ,DIER_MASK = 0x00005F5F
    ;
  };
  // Status register
  struct SR : reg<16, base + 0x10, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Update interrupt flag (bits: 0)
     UIF_MASK = 0x00000001
    ,UIF_POS = 0
    ,UIF = 0x00000001
    // Capture/Compare 1 interrupt flag (bits: 1)
    ,CC1IF_MASK = 0x00000002
    ,CC1IF_POS = 1
    ,CC1IF = 0x00000002
    // Capture/Compare 2 interrupt flag (bits: 2)
    ,CC2IF_MASK = 0x00000004
    ,CC2IF_POS = 2
    ,CC2IF = 0x00000004
    // Capture/Compare 3 interrupt flag (bits: 3)
    ,CC3IF_MASK = 0x00000008
    ,CC3IF_POS = 3
    ,CC3IF = 0x00000008
    // Capture/Compare 4 interrupt flag (bits: 4)
    ,CC4IF_MASK = 0x00000010
    ,CC4IF_POS = 4
    ,CC4IF = 0x00000010
    // Trigger interrupt flag (bits: 6)
    ,TIF_MASK = 0x00000040
    ,TIF_POS = 6
    ,TIF = 0x00000040
    // Capture/Compare 1 overcapture flag (bits: 9)
    ,CC1OF_MASK = 0x00000200
    ,CC1OF_POS = 9
    ,CC1OF = 0x00000200
    // Capture/Compare 2 overcapture flag (bits: 10)
    ,CC2OF_MASK = 0x00000400
    ,CC2OF_POS = 10
    ,CC2OF = 0x00000400
    // Capture/Compare 3 overcapture flag (bits: 11)
    ,CC3OF_MASK = 0x00000800
    ,CC3OF_POS = 11
    ,CC3OF = 0x00000800
    // Capture/Compare 4 overcapture flag (bits: 12)
    ,CC4OF_MASK = 0x00001000
    ,CC4OF_POS = 12
    ,CC4OF = 0x00001000
    ,SR_MASK = 0x00001E5F
    ;
  };
  // Event generation register
  struct EGR : reg<16, base + 0x14, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Update generation (bits: 0)
     UG_MASK = 0x00000001
    ,UG_POS = 0
    ,UG = 0x00000001
    // Capture/Compare 1 generation (bits: 1)
    ,CC1G_MASK = 0x00000002
    ,CC1G_POS = 1
    ,CC1G = 0x00000002
    // Capture/Compare 2 generation (bits: 2)
    ,CC2G_MASK = 0x00000004
    ,CC2G_POS = 2
    ,CC2G = 0x00000004
    // Capture/Compare 3 generation (bits: 3)
    ,CC3G_MASK = 0x00000008
    ,CC3G_POS = 3
    ,CC3G = 0x00000008
    // Capture/Compare 4 generation (bits: 4)
    ,CC4G_MASK = 0x00000010
    ,CC4G_POS = 4
    ,CC4G = 0x00000010
    // Trigger generation (bits: 6)
    ,TG_MASK = 0x00000040
    ,TG_POS = 6
    ,TG = 0x00000040
    ,EGR_MASK = 0x0000005F
    ;
  };
  // Capture/compare mode register 2
  struct CCER : reg<16, base + 0x20, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Capture/Compare y output enable (bits: 0)
     CC1E_MASK = 0x00000001
    ,CC1E_POS = 0
    ,CC1E = 0x00000001
    // Capture/Compare y output polarity (bits: 1)
    ,CC1P_MASK = 0x00000002
    ,CC1P_POS = 1
    ,CC1P = 0x00000002
    // Capture/Compare y output enable (bits: 4)
    ,CC2E_MASK = 0x00000010
    ,CC2E_POS = 4
    ,CC2E = 0x00000010
    // Capture/Compare y output polarity (bits: 5)
    ,CC2P_MASK = 0x00000020
    ,CC2P_POS = 5
    ,CC2P = 0x00000020
    // Capture/Compare y output enable (bits: 8)
    ,CC3E_MASK = 0x00000100
    ,CC3E_POS = 8
    ,CC3E = 0x00000100
    // Capture/Compare y output polarity (bits: 9)
    ,CC3P_MASK = 0x00000200
    ,CC3P_POS = 9
    ,CC3P = 0x00000200
    // Capture/Compare 4 output enable (bits: 12)
    ,CC4E_MASK = 0x00001000
    ,CC4E_POS = 12
    ,CC4E = 0x00001000
    // Capture/Compare 4 output polarity (bits: 13)
    ,CC4P_MASK = 0x00002000
    ,CC4P_POS = 13
    ,CC4P = 0x00002000
    ,CCER_MASK = 0x00003333
    ;
  };
  // DMA address for full transfer
  using DMAR = reg<16, base + 0x4C, 0x00000000, 0x00000000>;
  // Control register 1
  struct CR1 : reg<16, base + 0x0, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Counter enable (bits: 0)
     CEN_MASK = 0x00000001
    ,CEN_POS = 0
    ,CEN = 0x00000001
    // Update disable (bits: 1)
    ,UDIS_MASK = 0x00000002
    ,UDIS_POS = 1
    ,UDIS = 0x00000002
    // Update request source (bits: 2)
    ,URS_MASK = 0x00000004
    ,URS_POS = 2
    ,URS = 0x00000004
    // One pulse mode (bits: 3)
    ,OPM_MASK = 0x00000008
    ,OPM_POS = 3
    ,OPM = 0x00000008
    // Direction (bits: 4)
    ,DIR_MASK = 0x00000010
    ,DIR_POS = 4
    ,DIR = 0x00000010
    // Center-aligned mode selection (bits: 6-5)
    ,CMS_MASK = 0x00000060
    ,CMS_POS = 5
    ,CMS_EDGE_ALIGNED_MODE = 0x00000000 // Edge-aligned mode. The counter counts up or down depending on the direction bit (DIR). 
    ,CMS_CENTER_ALIGNED_MODE1 = 0x00000020 // Center-aligned mode 1. The counter counts up and down alternatively. Output compare interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set only when the counter is counting down. 
    ,CMS_CENTER_ALIGNED_MODE2 = 0x00000040 // Center-aligned mode 2. The counter counts up and down alternatively. Output compare interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set only when the counter is counting up. 
    ,CMS_CENTER_ALIGNED_MODE3 = 0x00000060 // Center-aligned mode 3. The counter counts up and down alternatively. Output compare interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set both when the counter is counting up or down. 
    // Auto-reload preload enable (bits: 7)
    ,ARPE_MASK = 0x00000080
    ,ARPE_POS = 7
    ,ARPE = 0x00000080
    // Clock division (bits: 9-8)
    ,CKD_MASK = 0x00000300
    ,CKD_POS = 8
    ,CKD_1 = 0x00000000 // tDTS = tCK_INT
    ,CKD_2 = 0x00000100 // tDTS = 2 * tCK_INT
    ,CKD_4 = 0x00000200 // tDTS = 4 * tCK_INT
    ,CR1_MASK = 0x000003FF
    ;
  };
  // Slave mode control register
  struct SMCR : reg<16, base + 0x8, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Slave mode selection (bits: 2-0)
     SMS_MASK = 0x00000007
    ,SMS_POS = 0
    ,SMS_DISABLED = 0x00000000 // Slave mode disabled - if CEN = ‘1’ then the prescaler is clocked directly by the internal clock. 
    ,SMS_ENCODER_MODE_1 = 0x00000001 // Encoder mode 1 - Counter counts up/down on TI2FP1 edge depending on TI1FP2 level. 
    ,SMS_ENCODER_MODE_2 = 0x00000002 // Encoder mode 2 - Counter counts up/down on TI1FP2 edge depending on TI2FP1 level. 
    ,SMS_ENCODER_MODE_3 = 0x00000003 // Encoder mode 3 - Counter counts up/down on both TI1FP1 and TI2FP2 edges depending on the level of the other input. 
    ,SMS_RESET_MODE = 0x00000004 // Reset Mode - Rising edge of the selected trigger input (TRGI) reinitializes the counter and generates an update of the registers. 
    ,SMS_GATED_MODE = 0x00000005 // Gated Mode - The counter clock is enabled when the trigger input (TRGI) is high. The counter stops (but is not reset) as soon as the trigger becomes low. Both start and stop of the counter are controlled. 
    ,SMS_TRIGGER_MODE = 0x00000006 // Trigger Mode - The counter starts at a rising edge of the trigger TRGI (but it is not reset). Only the start of the counter is controlled. 
    ,SMS_EXTERNAL_CLOCK_MODE_1 = 0x00000007 // Rising edges of the selected trigger (TRGI) clock the counter.
    // Trigger selection (bits: 6-4)
    ,TS_MASK = 0x00000070
    ,TS_POS = 4
    ,TS_ITR0 = 0x00000000 // Internal Trigger 0 (ITR0)
    ,TS_ITR1 = 0x00000010 // Internal Trigger 1 (ITR1)
    ,TS_ITR2 = 0x00000020 // Internal Trigger 2 (ITR2)
    ,TS_ITR3 = 0x00000030 // Internal Trigger 3 (ITR3)
    ,TS_TI1F_ED = 0x00000040 // TI1 Edge Detector (TI1F_ED)
    ,TS_TI1FP1 = 0x00000050 // Filtered Timer Input 1 (TI1FP1)
    ,TS_TI2FP2 = 0x00000060 // Filtered Timer Input 2 (TI2FP2)
    ,TS_ETRF = 0x00000070 // External Trigger input (ETRF)
    // Master/slave mode (bits: 7)
    ,MSM_MASK = 0x00000080
    ,MSM_POS = 7
    ,MSM = 0x00000080
    // External trigger filter (bits: 11-8)
    ,ETF_MASK = 0x00000F00
    ,ETF_POS = 8
    ,ETF_DISABLED = 0x00000000 // No filter, sampling is done at fDTS
    ,ETF_CK_INT_N2 = 0x00000100 // fSAMPLING = fCK_INT, N = 2
    ,ETF_CK_INT_N4 = 0x00000200 // fSAMPLING = fCK_INT, N = 4
    ,ETF_CK_INT_N8 = 0x00000300 // fSAMPLING = fCK_INT, N = 8
    ,ETF_DTS_DIV2_N6 = 0x00000400 // fSAMPLING = fDTS / 2, N = 6
    ,ETF_DTS_DIV2_N8 = 0x00000500 // fSAMPLING = fDTS / 2, N = 8
    ,ETF_DTS_DIV4_N6 = 0x00000600 // fSAMPLING = fDTS / 4, N = 6
    ,ETF_DTS_DIV4_N8 = 0x00000700 // fSAMPLING = fDTS / 4, N = 8
    ,ETF_DTS_DIV8_N6 = 0x00000800 // fSAMPLING = fDTS / 8, N = 6
    ,ETF_DTS_DIV8_N8 = 0x00000900 // fSAMPLING = fDTS / 8, N = 8
    ,ETF_DTS_DIV16_N5 = 0x00000A00 // fSAMPLING = fDTS / 16, N = 5
    ,ETF_DTS_DIV16_N6 = 0x00000B00 // fSAMPLING = fDTS / 16, N = 6
    ,ETF_DTS_DIV16_N8 = 0x00000C00 // fSAMPLING = fDTS / 16, N = 8
    ,ETF_DTS_DIV32_N5 = 0x00000D00 // fSAMPLING = fDTS / 32, N = 5
    ,ETF_DTS_DIV32_N6 = 0x00000E00 // fSAMPLING = fDTS / 32, N = 6
    ,ETF_DTS_DIV32_N8 = 0x00000F00 // fSAMPLING = fDTS / 32, N = 8
    // External trigger prescaler (bits: 13-12)
    ,ETPS_MASK = 0x00003000
    ,ETPS_POS = 12
    ,ETPS_DISABLED = 0x00000000 // Prescaler OFF
    ,ETPS_ETRP_DIV2 = 0x00001000 // ETRP frequency divided by 2
    ,ETPS_ETRP_DIV4 = 0x00002000 // ETRP frequency divided by 4
    ,ETPS_ETRP_DIV8 = 0x00003000 // ETRP frequency divided by 8
    // External clock enable (bits: 14)
    ,ECE_MASK = 0x00004000
    ,ECE_POS = 14
    ,ECE = 0x00004000
    // External trigger polarity (bits: 15)
    ,ETP_MASK = 0x00008000
    ,ETP_POS = 15
    ,ETP = 0x00008000
    ,SMCR_MASK = 0x0000FFF7
    ;
  };
  // Capture/compare mode register 1
  struct CCMR1 : reg<16, base + 0x18, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Capture/Compare 1 selection (bits: 1-0)
     CC1S_MASK = 0x00000003
    ,CC1S_POS = 0
    ,CC1S_OUTPUT = 0x00000000 // CC1 channel is configured as output
    ,CC1S_INPUT_TI1 = 0x00000001 // CC1 channel is configured as input, IC1 is mapped on TI1
    ,CC1S_INPUT_TI2 = 0x00000002 // CC1 channel is configured as input, IC1 is mapped on TI2
    ,CC1S_INPUT_TRC = 0x00000003 // CC1 channel is configured as input, IC1 is mapped on TRC
    // Output Compare y fast enable (bits: 2)
    ,OC1FE_MASK = 0x00000004
    ,OC1FE_POS = 2
    ,OC1FE = 0x00000004
    // Output Compare y preload enable (bits: 3)
    ,OC1PE_MASK = 0x00000008
    ,OC1PE_POS = 3
    ,OC1PE = 0x00000008
    // Output Compare y mode (bits: 6-4)
    ,OC1M_MASK = 0x00000070
    ,OC1M_POS = 4
    ,OC1M_FROZEN = 0x00000000 // The comparison between the output compare register TIMx_CCRy and the counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing base). 
    ,OC1M_ACTIVE = 0x00000010 // Set channel to active level on match.
    ,OC1M_INACTIVE = 0x00000020 // Set channel to inactive level on match.
    ,OC1M_TOGGLE = 0x00000030 // OCyREF toggles when TIMx_CNT = TIMx_CCRy
    ,OC1M_FORCE_INACTIVE = 0x00000040 // Force inactive level - OCyREF is forced low.
    ,OC1M_FORCE_ACTIVE = 0x00000050 // Force active level - OCyREF is forced high.
    ,OC1M_PWM_MODE_1 = 0x00000060 // PWM mode 1 - In upcounting, channel y is active as long as TIMx_CNT < TIMx_CCRy else inactive. In downcounting, channel y is inactive (OC1REF=‘0’) as long as TIMx_CNT > TIMx_CCRy else active (OCyREF=’1’). 
    ,OC1M_PWM_MODE_2 = 0x00000070 // PWM mode 2 - In upcounting, channel y is inactive as long as TIMx_CNT < TIMx_CCRy else active. In downcounting, channel y is active as long as TIMx_CNT > TIMx_CCRy else inactive. 
    // Output Compare y clear enable (bits: 7)
    ,OC1CE_MASK = 0x00000080
    ,OC1CE_POS = 7
    ,OC1CE = 0x00000080
    // Capture/Compare 2 selection (bits: 9-8)
    ,CC2S_MASK = 0x00000300
    ,CC2S_POS = 8
    ,CC2S_OUTPUT = 0x00000000 // CC2 channel is configured as output
    ,CC2S_INPUT_TI2 = 0x00000100 // CC2 channel is configured as input, IC2 is mapped on TI2
    ,CC2S_INPUT_TI1 = 0x00000200 // CC2 channel is configured as input, IC2 is mapped on TI1
    ,CC2S_INPUT_TRC = 0x00000300 // CC2 channel is configured as input, IC2 is mapped on TRC
    // Output Compare y fast enable (bits: 10)
    ,OC2FE_MASK = 0x00000400
    ,OC2FE_POS = 10
    ,OC2FE = 0x00000400
    // Output Compare y preload enable (bits: 11)
    ,OC2PE_MASK = 0x00000800
    ,OC2PE_POS = 11
    ,OC2PE = 0x00000800
    // Output Compare y mode (bits: 14-12)
    ,OC2M_MASK = 0x00007000
    ,OC2M_POS = 12
    ,OC2M_FROZEN = 0x00000000 // The comparison between the output compare register TIMx_CCRy and the counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing base). 
    ,OC2M_ACTIVE = 0x00001000 // Set channel to active level on match.
    ,OC2M_INACTIVE = 0x00002000 // Set channel to inactive level on match.
    ,OC2M_TOGGLE = 0x00003000 // OCyREF toggles when TIMx_CNT = TIMx_CCRy
    ,OC2M_FORCE_INACTIVE = 0x00004000 // Force inactive level - OCyREF is forced low.
    ,OC2M_FORCE_ACTIVE = 0x00005000 // Force active level - OCyREF is forced high.
    ,OC2M_PWM_MODE_1 = 0x00006000 // PWM mode 1 - In upcounting, channel y is active as long as TIMx_CNT < TIMx_CCRy else inactive. In downcounting, channel y is inactive (OC1REF=‘0’) as long as TIMx_CNT > TIMx_CCRy else active (OCyREF=’1’). 
    ,OC2M_PWM_MODE_2 = 0x00007000 // PWM mode 2 - In upcounting, channel y is inactive as long as TIMx_CNT < TIMx_CCRy else active. In downcounting, channel y is active as long as TIMx_CNT > TIMx_CCRy else inactive. 
    // Output Compare y clear enable (bits: 15)
    ,OC2CE_MASK = 0x00008000
    ,OC2CE_POS = 15
    ,OC2CE = 0x00008000
    // Input capture y prescaler (bits: 3-2)
    ,IC1PSC_MASK = 0x0000000C
    ,IC1PSC_POS = 2
    ,IC1PSC_DISABLED = 0x00000000 // No prescaler, capture is done each time an edge is detected on the capture input
    ,IC1PSC_2 = 0x00000004 // Capture is done once every 2 events
    ,IC1PSC_4 = 0x00000008 // Capture is done once every 4 events
    ,IC1PSC_8 = 0x0000000C // Capture is done once every 8 events
    // Input capture y filter (bits: 7-4)
    ,IC1F_MASK = 0x000000F0
    ,IC1F_POS = 4
    ,IC1F_DISABLED = 0x00000000 // No filter, sampling is done at fDTS
    ,IC1F_CK_INT_N2 = 0x00000010 // fSAMPLING = fCK_INT, N = 2
    ,IC1F_CK_INT_N4 = 0x00000020 // fSAMPLING = fCK_INT, N = 4
    ,IC1F_CK_INT_N8 = 0x00000030 // fSAMPLING = fCK_INT, N = 8
    ,IC1F_DTS_DIV2_N6 = 0x00000040 // fSAMPLING = fDTS / 2, N = 6
    ,IC1F_DTS_DIV2_N8 = 0x00000050 // fSAMPLING = fDTS / 2, N = 8
    ,IC1F_DTS_DIV4_N6 = 0x00000060 // fSAMPLING = fDTS / 4, N = 6
    ,IC1F_DTS_DIV4_N8 = 0x00000070 // fSAMPLING = fDTS / 4, N = 8
    ,IC1F_DTS_DIV8_N6 = 0x00000080 // fSAMPLING = fDTS / 8, N = 6
    ,IC1F_DTS_DIV8_N8 = 0x00000090 // fSAMPLING = fDTS / 8, N = 8
    ,IC1F_DTS_DIV16_N5 = 0x000000A0 // fSAMPLING = fDTS / 16, N = 5
    ,IC1F_DTS_DIV16_N6 = 0x000000B0 // fSAMPLING = fDTS / 16, N = 6
    ,IC1F_DTS_DIV16_N8 = 0x000000C0 // fSAMPLING = fDTS / 16, N = 8
    ,IC1F_DTS_DIV32_N5 = 0x000000D0 // fSAMPLING = fDTS / 32, N = 5
    ,IC1F_DTS_DIV32_N6 = 0x000000E0 // fSAMPLING = fDTS / 32, N = 6
    ,IC1F_DTS_DIV32_N8 = 0x000000F0 // fSAMPLING = fDTS / 32, N = 8
    // Input capture y prescaler (bits: 11-10)
    ,IC2PSC_MASK = 0x00000C00
    ,IC2PSC_POS = 10
    ,IC2PSC_DISABLED = 0x00000000 // No prescaler, capture is done each time an edge is detected on the capture input
    ,IC2PSC_2 = 0x00000400 // Capture is done once every 2 events
    ,IC2PSC_4 = 0x00000800 // Capture is done once every 4 events
    ,IC2PSC_8 = 0x00000C00 // Capture is done once every 8 events
    // Input capture y filter (bits: 15-12)
    ,IC2F_MASK = 0x0000F000
    ,IC2F_POS = 12
    ,IC2F_DISABLED = 0x00000000 // No filter, sampling is done at fDTS
    ,IC2F_CK_INT_N2 = 0x00001000 // fSAMPLING = fCK_INT, N = 2
    ,IC2F_CK_INT_N4 = 0x00002000 // fSAMPLING = fCK_INT, N = 4
    ,IC2F_CK_INT_N8 = 0x00003000 // fSAMPLING = fCK_INT, N = 8
    ,IC2F_DTS_DIV2_N6 = 0x00004000 // fSAMPLING = fDTS / 2, N = 6
    ,IC2F_DTS_DIV2_N8 = 0x00005000 // fSAMPLING = fDTS / 2, N = 8
    ,IC2F_DTS_DIV4_N6 = 0x00006000 // fSAMPLING = fDTS / 4, N = 6
    ,IC2F_DTS_DIV4_N8 = 0x00007000 // fSAMPLING = fDTS / 4, N = 8
    ,IC2F_DTS_DIV8_N6 = 0x00008000 // fSAMPLING = fDTS / 8, N = 6
    ,IC2F_DTS_DIV8_N8 = 0x00009000 // fSAMPLING = fDTS / 8, N = 8
    ,IC2F_DTS_DIV16_N5 = 0x0000A000 // fSAMPLING = fDTS / 16, N = 5
    ,IC2F_DTS_DIV16_N6 = 0x0000B000 // fSAMPLING = fDTS / 16, N = 6
    ,IC2F_DTS_DIV16_N8 = 0x0000C000 // fSAMPLING = fDTS / 16, N = 8
    ,IC2F_DTS_DIV32_N5 = 0x0000D000 // fSAMPLING = fDTS / 32, N = 5
    ,IC2F_DTS_DIV32_N6 = 0x0000E000 // fSAMPLING = fDTS / 32, N = 6
    ,IC2F_DTS_DIV32_N8 = 0x0000F000 // fSAMPLING = fDTS / 32, N = 8
    ,CCMR1_MASK = 0x0000FFFF
    ;
  };
  // Capture/compare mode register 2
  struct CCMR2 : reg<16, base + 0x1C, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Capture/Compare 3 selection (bits: 1-0)
     CC3S_MASK = 0x00000003
    ,CC3S_POS = 0
    ,CC3S_OUTPUT = 0x00000000 // CC3 channel is configured as output
    ,CC3S_INPUT_TI3 = 0x00000001 // CC3 channel is configured as input, IC3 is mapped on TI3
    ,CC3S_INPUT_TI4 = 0x00000002 // CC3 channel is configured as input, IC3 is mapped on TI4
    ,CC3S_INPUT_TRC = 0x00000003 // CC3 channel is configured as input, IC3 is mapped on TRC
    // Output Compare y fast enable (bits: 2)
    ,OC3FE_MASK = 0x00000004
    ,OC3FE_POS = 2
    ,OC3FE = 0x00000004
    // Output Compare y preload enable (bits: 3)
    ,OC3PE_MASK = 0x00000008
    ,OC3PE_POS = 3
    ,OC3PE = 0x00000008
    // Output Compare y mode (bits: 6-4)
    ,OC3M_MASK = 0x00000070
    ,OC3M_POS = 4
    ,OC3M_FROZEN = 0x00000000 // The comparison between the output compare register TIMx_CCRy and the counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing base). 
    ,OC3M_ACTIVE = 0x00000010 // Set channel to active level on match.
    ,OC3M_INACTIVE = 0x00000020 // Set channel to inactive level on match.
    ,OC3M_TOGGLE = 0x00000030 // OCyREF toggles when TIMx_CNT = TIMx_CCRy
    ,OC3M_FORCE_INACTIVE = 0x00000040 // Force inactive level - OCyREF is forced low.
    ,OC3M_FORCE_ACTIVE = 0x00000050 // Force active level - OCyREF is forced high.
    ,OC3M_PWM_MODE_1 = 0x00000060 // PWM mode 1 - In upcounting, channel y is active as long as TIMx_CNT < TIMx_CCRy else inactive. In downcounting, channel y is inactive (OC1REF=‘0’) as long as TIMx_CNT > TIMx_CCRy else active (OCyREF=’1’). 
    ,OC3M_PWM_MODE_2 = 0x00000070 // PWM mode 2 - In upcounting, channel y is inactive as long as TIMx_CNT < TIMx_CCRy else active. In downcounting, channel y is active as long as TIMx_CNT > TIMx_CCRy else inactive. 
    // Output Compare y clear enable (bits: 7)
    ,OC3CE_MASK = 0x00000080
    ,OC3CE_POS = 7
    ,OC3CE = 0x00000080
    // Capture/Compare 4 selection (bits: 9-8)
    ,CC4S_MASK = 0x00000300
    ,CC4S_POS = 8
    ,CC4S_OUTPUT = 0x00000000 // CC4 channel is configured as output
    ,CC4S_INPUT_TI4 = 0x00000100 // CC4 channel is configured as input, IC4 is mapped on TI4
    ,CC4S_INPUT_TI3 = 0x00000200 // CC4 channel is configured as input, IC4 is mapped on TI3
    ,CC4S_INPUT_TRC = 0x00000300 // CC4 channel is configured as input, IC4 is mapped on TRC
    // Output Compare y fast enable (bits: 10)
    ,OC4FE_MASK = 0x00000400
    ,OC4FE_POS = 10
    ,OC4FE = 0x00000400
    // Output Compare y preload enable (bits: 11)
    ,OC4PE_MASK = 0x00000800
    ,OC4PE_POS = 11
    ,OC4PE = 0x00000800
    // Output Compare y mode (bits: 14-12)
    ,OC4M_MASK = 0x00007000
    ,OC4M_POS = 12
    ,OC4M_FROZEN = 0x00000000 // The comparison between the output compare register TIMx_CCRy and the counter TIMx_CNT has no effect on the outputs.(this mode is used to generate a timing base). 
    ,OC4M_ACTIVE = 0x00001000 // Set channel to active level on match.
    ,OC4M_INACTIVE = 0x00002000 // Set channel to inactive level on match.
    ,OC4M_TOGGLE = 0x00003000 // OCyREF toggles when TIMx_CNT = TIMx_CCRy
    ,OC4M_FORCE_INACTIVE = 0x00004000 // Force inactive level - OCyREF is forced low.
    ,OC4M_FORCE_ACTIVE = 0x00005000 // Force active level - OCyREF is forced high.
    ,OC4M_PWM_MODE_1 = 0x00006000 // PWM mode 1 - In upcounting, channel y is active as long as TIMx_CNT < TIMx_CCRy else inactive. In downcounting, channel y is inactive (OC1REF=‘0’) as long as TIMx_CNT > TIMx_CCRy else active (OCyREF=’1’). 
    ,OC4M_PWM_MODE_2 = 0x00007000 // PWM mode 2 - In upcounting, channel y is inactive as long as TIMx_CNT < TIMx_CCRy else active. In downcounting, channel y is active as long as TIMx_CNT > TIMx_CCRy else inactive. 
    // Output Compare y clear enable (bits: 15)
    ,OC4CE_MASK = 0x00008000
    ,OC4CE_POS = 15
    ,OC4CE = 0x00008000
    // Input capture y prescaler (bits: 3-2)
    ,IC3PSC_MASK = 0x0000000C
    ,IC3PSC_POS = 2
    ,IC3PSC_DISABLED = 0x00000000 // No prescaler, capture is done each time an edge is detected on the capture input
    ,IC3PSC_2 = 0x00000004 // Capture is done once every 2 events
    ,IC3PSC_4 = 0x00000008 // Capture is done once every 4 events
    ,IC3PSC_8 = 0x0000000C // Capture is done once every 8 events
    // Input capture y filter (bits: 7-4)
    ,IC3F_MASK = 0x000000F0
    ,IC3F_POS = 4
    ,IC3F_DISABLED = 0x00000000 // No filter, sampling is done at fDTS
    ,IC3F_CK_INT_N2 = 0x00000010 // fSAMPLING = fCK_INT, N = 2
    ,IC3F_CK_INT_N4 = 0x00000020 // fSAMPLING = fCK_INT, N = 4
    ,IC3F_CK_INT_N8 = 0x00000030 // fSAMPLING = fCK_INT, N = 8
    ,IC3F_DTS_DIV2_N6 = 0x00000040 // fSAMPLING = fDTS / 2, N = 6
    ,IC3F_DTS_DIV2_N8 = 0x00000050 // fSAMPLING = fDTS / 2, N = 8
    ,IC3F_DTS_DIV4_N6 = 0x00000060 // fSAMPLING = fDTS / 4, N = 6
    ,IC3F_DTS_DIV4_N8 = 0x00000070 // fSAMPLING = fDTS / 4, N = 8
    ,IC3F_DTS_DIV8_N6 = 0x00000080 // fSAMPLING = fDTS / 8, N = 6
    ,IC3F_DTS_DIV8_N8 = 0x00000090 // fSAMPLING = fDTS / 8, N = 8
    ,IC3F_DTS_DIV16_N5 = 0x000000A0 // fSAMPLING = fDTS / 16, N = 5
    ,IC3F_DTS_DIV16_N6 = 0x000000B0 // fSAMPLING = fDTS / 16, N = 6
    ,IC3F_DTS_DIV16_N8 = 0x000000C0 // fSAMPLING = fDTS / 16, N = 8
    ,IC3F_DTS_DIV32_N5 = 0x000000D0 // fSAMPLING = fDTS / 32, N = 5
    ,IC3F_DTS_DIV32_N6 = 0x000000E0 // fSAMPLING = fDTS / 32, N = 6
    ,IC3F_DTS_DIV32_N8 = 0x000000F0 // fSAMPLING = fDTS / 32, N = 8
    // Input capture y prescaler (bits: 11-10)
    ,IC4PSC_MASK = 0x00000C00
    ,IC4PSC_POS = 10
    ,IC4PSC_DISABLED = 0x00000000 // No prescaler, capture is done each time an edge is detected on the capture input
    ,IC4PSC_2 = 0x00000400 // Capture is done once every 2 events
    ,IC4PSC_4 = 0x00000800 // Capture is done once every 4 events
    ,IC4PSC_8 = 0x00000C00 // Capture is done once every 8 events
    // Input capture y filter (bits: 15-12)
    ,IC4F_MASK = 0x0000F000
    ,IC4F_POS = 12
    ,IC4F_DISABLED = 0x00000000 // No filter, sampling is done at fDTS
    ,IC4F_CK_INT_N2 = 0x00001000 // fSAMPLING = fCK_INT, N = 2
    ,IC4F_CK_INT_N4 = 0x00002000 // fSAMPLING = fCK_INT, N = 4
    ,IC4F_CK_INT_N8 = 0x00003000 // fSAMPLING = fCK_INT, N = 8
    ,IC4F_DTS_DIV2_N6 = 0x00004000 // fSAMPLING = fDTS / 2, N = 6
    ,IC4F_DTS_DIV2_N8 = 0x00005000 // fSAMPLING = fDTS / 2, N = 8
    ,IC4F_DTS_DIV4_N6 = 0x00006000 // fSAMPLING = fDTS / 4, N = 6
    ,IC4F_DTS_DIV4_N8 = 0x00007000 // fSAMPLING = fDTS / 4, N = 8
    ,IC4F_DTS_DIV8_N6 = 0x00008000 // fSAMPLING = fDTS / 8, N = 6
    ,IC4F_DTS_DIV8_N8 = 0x00009000 // fSAMPLING = fDTS / 8, N = 8
    ,IC4F_DTS_DIV16_N5 = 0x0000A000 // fSAMPLING = fDTS / 16, N = 5
    ,IC4F_DTS_DIV16_N6 = 0x0000B000 // fSAMPLING = fDTS / 16, N = 6
    ,IC4F_DTS_DIV16_N8 = 0x0000C000 // fSAMPLING = fDTS / 16, N = 8
    ,IC4F_DTS_DIV32_N5 = 0x0000D000 // fSAMPLING = fDTS / 32, N = 5
    ,IC4F_DTS_DIV32_N6 = 0x0000E000 // fSAMPLING = fDTS / 32, N = 6
    ,IC4F_DTS_DIV32_N8 = 0x0000F000 // fSAMPLING = fDTS / 32, N = 8
    ,CCMR2_MASK = 0x0000FFFF
    ;
  };
  // Counter
  using CNT = reg<16, base + 0x24, 0x00000000, 0x00000000>;
  // Prescaler
  using PSC = reg<16, base + 0x28, 0x00000000, 0x00000000>;
  // Auto-reload register
  using ARR = reg<16, base + 0x2C, 0x00000000, 0x0000FFFF>;
  // Capture/compare register 1
  using CCR1 = reg<16, base + 0x34, 0x00000000, 0x00000000>;
  // Capture/compare register 2
  using CCR2 = reg<16, base + 0x38, 0x00000000, 0x00000000>;
  // Capture/compare register 3
  using CCR3 = reg<16, base + 0x3C, 0x00000000, 0x00000000>;
  // Capture/compare register 4
  using CCR4 = reg<16, base + 0x40, 0x00000000, 0x00000000>;
  // DMA control register
  struct DCR : reg<16, base + 0x48, 0x00000000, 0x00000000>
  {
    static constexpr type
    // DMA base address (bits: 4-0)
     DBA_MASK = 0x0000001F
    ,DBA_POS = 0
    // DMA burst length (bits: 12-8)
    ,DBL_MASK = 0x00001F00
    ,DBL_POS = 8
    ,DCR_MASK = 0x00001F1F
    ;
  };
}; // struct TIM4

} // namespace lmcu::device

