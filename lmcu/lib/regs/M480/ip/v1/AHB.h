/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// AHB Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct AHB
{
  static constexpr auto ip_ver = ip_version::_1;

  // AHB Bus Matrix Priority Control Register
  struct AHBMCTL : reg<ip_ver, base + 0x0, 0x00000001>
  {
    static constexpr typename AHBMCTL::type
    // Highest AHB Bus Priority of Cortex®-M4 Core Enable Bit (Write Protect) Enable Cortex®-M4 Core With Highest AHB Bus Priority In AHB Bus Matrix Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     INTACTEN_MASK = 0x00000001
    ,INTACTEN_POS = 0
    ,INTACTEN_0 = 0x00000000 // Run robin mode
    ,INTACTEN_1 = 0x00000001 // Cortex®-M4 CPU with highest bus priority when interrupt occusr
    ,AHBMCTL_MASK = 0x00000001
    ;
  };
}; // struct AHB

} // namespace lmcu::device::ip::v1

