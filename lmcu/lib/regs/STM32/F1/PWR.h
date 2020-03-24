/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Power control
// ------------------------------------------------------------------------------------------------
struct PWR
{
  static constexpr std::uintptr_t base = 0x40007000UL;

  // Power control register
  struct CR : reg<base + 0x0>
  {
    static constexpr type
    // Low-power deepsleep (bits: 0)
     LPDS_MASK = 0x00000001
    ,LPDS_POS = 0
    ,LPDS = 0x00000001
    // Power down deepsleep (bits: 1)
    ,PDDS_MASK = 0x00000002
    ,PDDS_POS = 1
    ,PDDS = 0x00000002
    // Clear wakeup flag (bits: 2)
    ,CWUF_MASK = 0x00000004
    ,CWUF_POS = 2
    ,CWUF = 0x00000004
    // Clear standby flag (bits: 3)
    ,CSBF_MASK = 0x00000008
    ,CSBF_POS = 3
    ,CSBF = 0x00000008
    // Power voltage detector enable (bits: 4)
    ,PVDE_MASK = 0x00000010
    ,PVDE_POS = 4
    ,PVDE = 0x00000010
    // PVD level selection. (bits: 7-5)
    ,PLS_MASK = 0x000000E0
    ,PLS_POS = 5
    ,PLS_2_2V = 0x00000000 // 2.2V
    ,PLS_2_3V = 0x00000020 // 2.3V
    ,PLS_2_4V = 0x00000040 // 2.4V
    ,PLS_2_5V = 0x00000060 // 2.5V
    ,PLS_2_6V = 0x00000080 // 2.6V
    ,PLS_2_7V = 0x000000A0 // 2.7V
    ,PLS_2_8V = 0x000000C0 // 2.8V
    ,PLS_2_9V = 0x000000E0 // 2.9V
    // Disable backup domain write protection (bits: 8)
    ,DBP_MASK = 0x00000100
    ,DBP_POS = 8
    ,DBP = 0x00000100
    ,CR_MASK = 0x000001FF
    ;
  };
  // Power control/status register
  struct CSR : reg<base + 0x4>
  {
    static constexpr type
    // Wakeup flag (bits: 0)
     WUF_MASK = 0x00000001
    ,WUF_POS = 0
    ,WUF = 0x00000001
    // Standby flag (bits: 1)
    ,SBF_MASK = 0x00000002
    ,SBF_POS = 1
    ,SBF = 0x00000002
    // PVD output (bits: 2)
    ,PVDO_MASK = 0x00000004
    ,PVDO_POS = 2
    ,PVDO = 0x00000004
    // Enable WKUP pin (bits: 8)
    ,EWUP_MASK = 0x00000100
    ,EWUP_POS = 8
    ,EWUP = 0x00000100
    ,CSR_MASK = 0x00000107
    ;
  };
}; // struct PWR

} // namespace lmcu::device

