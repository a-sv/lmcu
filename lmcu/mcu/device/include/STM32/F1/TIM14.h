/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// General-purpose timer
// ------------------------------------------------------------------------------------------------
struct TIM14
{
  static constexpr std::uintptr_t base = 0x40002000;

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
    ,CR1_MASK = 0x0000038F
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
    ,DIER_MASK = 0x00000003
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
    // Capture/Compare 1 overcapture flag (bits: 9)
    ,CC1OF_MASK = 0x00000200
    ,CC1OF_POS = 9
    ,CC1OF = 0x00000200
    ,SR_MASK = 0x00000203
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
    ,EGR_MASK = 0x00000003
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
    ,CCMR1_MASK = 0x000000FF
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
    // Capture/Compare y complementary output polarity (bits: 3)
    ,CC1NP_MASK = 0x00000008
    ,CC1NP_POS = 3
    ,CC1NP = 0x00000008
    ,CCER_MASK = 0x0000000B
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
}; // struct TIM14

} // namespace lmcu::device

