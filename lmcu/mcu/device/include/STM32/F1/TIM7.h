/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Basic timer
// ------------------------------------------------------------------------------------------------
struct TIM7
{
  static constexpr std::uintptr_t base = 0x40001400;

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
    ;
  };
  // Control register 2
  struct CR2 : reg<16, base + 0x4, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Master mode selection (bits: 6-4)
     MMS_MASK = 0x00000070
    ,MMS_POS = 4
    ,MMS_RESET = 0x00000000 // Reset - the UG bit from the TIMx_EGR register is used as trigger output (TRGO).
    ,MMS_ENABLE = 0x00000010 // Enable - the Counter Enable signal CNT_EN is used as trigger output (TRGO).
    ,MMS_UPDATE = 0x00000020 // Update - The update event is selected as trigger output (TRGO).
    ,MMS_COMPARE_PULSE = 0x00000030 // Compare Pulse - The trigger output send a positive pulse when the CC1IF flag is to be set (even if it was already high), as soon as a capture or a compare match occurred. 
    ,MMS_CMP_OC1REF = 0x00000040 // Compare - OC1REF signal is used as trigger output (TRGO)
    ,MMS_CMP_OC2REF = 0x00000050 // Compare - OC2REF signal is used as trigger output (TRGO)
    ,MMS_CMP_OC3REF = 0x00000060 // Compare - OC3REF signal is used as trigger output (TRGO)
    ,MMS_CMP_OC4REF = 0x00000070 // Compare - OC4REF signal is used as trigger output (TRGO)
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
    // Update DMA request enable (bits: 8)
    ,UDE_MASK = 0x00000100
    ,UDE_POS = 8
    ,UDE = 0x00000100
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
    ;
  };
  // Counter
  using CNT = reg<16, base + 0x24, 0x00000000, 0x00000000>;
  // Prescaler
  using PSC = reg<16, base + 0x28, 0x00000000, 0x00000000>;
  // Auto-reload register
  using ARR = reg<16, base + 0x2C, 0x00000000, 0x0000FFFF>;
}; // struct TIM7

} // namespace lmcu::device

