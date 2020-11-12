/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// The ITM is a an application driven trace source that supports printf style debugging
// ------------------------------------------------------------------------------------------------
struct ITM
{
  static constexpr auto ip_ver = ip_version::none;

  static constexpr std::uintptr_t base = 0xE0000000;

  // Stimulus Ports (count: 32)
  using SP = reg<ip_ver, base + 0x0, 0x00000000, 32>;
  // Trace Enable Register
  struct TER : reg<ip_ver, base + 0xE00>
  {
    static constexpr typename TER::type
    // Bit mask to enable tracing on ITM stimulus ports. One bit per stimulus port. (bits: 31-0)
     STIMENA_MASK = 0xFFFFFFFF
    ,STIMENA_POS = 0
    ,TER_MASK = 0xFFFFFFFF
    ;
  };
  // Trace Privilege Register
  struct TPR : reg<ip_ver, base + 0xE40>
  {
    static constexpr typename TPR::type
    // Bit mask to enable tracing on ITM stimulus ports (bits: 3-0)
     PRIVMASK_MASK = 0x0000000F
    ,PRIVMASK_POS = 0
    ,TPR_MASK = 0x0000000F
    ;
  };
  // Trace Control Register
  struct TCR : reg<ip_ver, base + 0xE80>
  {
    static constexpr typename TCR::type
    // Set when ITM events present and being drained (bits: 23)
     BUSY_MASK = 0x00800000
    ,BUSY_POS = 23
    ,BUSY = 0x00800000
    // ATB ID for CoreSight system (bits: 22-16)
    ,ATBID_MASK = 0x007F0000
    ,ATBID_POS = 16
    // Timestamp prescaler (bits: 9-8)
    ,TSPRESCALE_MASK = 0x00000300
    ,TSPRESCALE_POS = 8
    ,TSPRESCALE_1 = 0x00000000 // no prescaling
    ,TSPRESCALE_4 = 0x00000100 // divide by 4
    ,TSPRESCALE_16 = 0x00000200 // divide by 16
    ,TSPRESCALE_64 = 0x00000300 // divide by 64
    // Enable SWV behavior – count on TPIUEMIT and TPIUBAUD (bits: 4)
    ,SWOENA_MASK = 0x00000010
    ,SWOENA_POS = 4
    ,SWOENA = 0x00000010
    // Enables the DWT stimulus (bits: 3)
    ,DWTENA_MASK = 0x00000008
    ,DWTENA_POS = 3
    ,DWTENA = 0x00000008
    // Enables sync packets for TPIU (bits: 2)
    ,SYNCENA_MASK = 0x00000004
    ,SYNCENA_POS = 2
    ,SYNCENA = 0x00000004
    // Enables differential timestamps (bits: 1)
    ,TSENA_MASK = 0x00000002
    ,TSENA_POS = 1
    ,TSENA = 0x00000002
    // Enable ITM (bits: 0)
    ,ITMENA_MASK = 0x00000001
    ,ITMENA_POS = 0
    ,ITMENA = 0x00000001
    ,TCR_MASK = 0x00FF031F
    ;
  };
  // Integration Write Register
  struct IWR : reg<ip_ver, base + 0xEF8>
  {
    static constexpr typename IWR::type
    // When the integration mode is set: 0 = ATVALIDM clear, 1 = ATVALIDM set (bits: 0)
     ATVALIDM_MASK = 0x00000001
    ,ATVALIDM_POS = 0
    ,ATVALIDM = 0x00000001
    ,IWR_MASK = 0x00000001
    ;
  };
  // Integration Read Register
  struct IRR : reg<ip_ver, base + 0xEFC>
  {
    static constexpr typename IRR::type
    // Value on ATREADYM (bits: 0)
     ATREADYM_MASK = 0x00000001
    ,ATREADYM_POS = 0
    ,ATREADYM = 0x00000001
    ,IRR_MASK = 0x00000001
    ;
  };
  // Integration Mode Control
  struct IMCR : reg<ip_ver, base + 0xF00>
  {
    static constexpr typename IMCR::type
    // 0 = ATVALIDM normal, 1 = ATVALIDM driven from Integration Write Register (bits: 0)
     INTEGRATION_MASK = 0x00000001
    ,INTEGRATION_POS = 0
    ,INTEGRATION = 0x00000001
    ,IMCR_MASK = 0x00000001
    ;
  };
  // Lock Access Register
  struct LAR : reg<ip_ver, base + 0xFB0>
  {
    static constexpr typename LAR::type
    // A privileged write of KEY enables more write access to Control Register 0xE00::0xFFC. An invalid write removes write access. (bits: 31-0)
     LOCK_ACCESS_MASK = 0xFFFFFFFF
    ,LOCK_ACCESS_POS = 0
    ,LOCK_ACCESS_KEY = 0xC5ACCE55 
    ,LAR_MASK = 0xFFFFFFFF
    ;
  };
  // Lock Status Register
  struct LSR : reg<ip_ver, base + 0xFB4, 0x00000003>
  {
    static constexpr typename LSR::type
    // You cannot implement 8-bit lock accesses (bits: 2)
     BYTE_ACC_MASK = 0x00000004
    ,BYTE_ACC_POS = 2
    ,BYTE_ACC = 0x00000004
    // Write access to component is blocked. All writes are ignored, reads are permitted (bits: 1)
    ,ACCESS_MASK = 0x00000002
    ,ACCESS_POS = 1
    ,ACCESS = 0x00000002
    // Indicates that a lock mechanism exists for this component (bits: 0)
    ,PRESENT_MASK = 0x00000001
    ,PRESENT_POS = 0
    ,PRESENT = 0x00000001
    ,LSR_MASK = 0x00000007
    ;
  };
  using PID4 = reg<ip_ver, base + 0xFD0, 0x00000004>;
  using PID5 = reg<ip_ver, base + 0xFD4>;
  using PID6 = reg<ip_ver, base + 0xFD8>;
  using PID7 = reg<ip_ver, base + 0xFDC>;
  using PID0 = reg<ip_ver, base + 0xFE0, 0x00000001>;
  using PID1 = reg<ip_ver, base + 0xFE4, 0x000000B0>;
  using PID2 = reg<ip_ver, base + 0xFE8, 0x0000001B>;
  using PID3 = reg<ip_ver, base + 0xFEC>;
  using CID0 = reg<ip_ver, base + 0xFF0, 0x0000000D>;
  using CID1 = reg<ip_ver, base + 0xFF4, 0x000000E0>;
  using CID2 = reg<ip_ver, base + 0xFF8, 0x00000005>;
  using CID3 = reg<ip_ver, base + 0xFFC, 0x000000B1>;
}; // struct ITM

} // namespace lmcu::device

