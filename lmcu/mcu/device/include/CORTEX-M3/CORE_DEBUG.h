/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Core debug functionality
// ------------------------------------------------------------------------------------------------
struct CORE_DEBUG
{
  static constexpr std::uintptr_t base = 0xE000EDF0;

  // Debug Halting Control and Status Register
  struct DHCSR : reg<32, base + 0x0, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Enables debug. (bits: 0)
     C_DEBUGEN_MASK = 0x00000001
    ,C_DEBUGEN_POS = 0
    ,C_DEBUGEN = 0x00000001
    // Halts the core. (bits: 1)
    ,C_HALT_MASK = 0x00000002
    ,C_HALT_POS = 1
    ,C_HALT = 0x00000002
    // Steps the core in halted debug. (bits: 2)
    ,C_STEP_MASK = 0x00000004
    ,C_STEP_POS = 2
    ,C_STEP = 0x00000004
    // Mask interrupts when stepping or running in halted debug. (bits: 3)
    ,C_MASKINTS_MASK = 0x00000008
    ,C_MASKINTS_POS = 3
    ,C_MASKINTS = 0x00000008
    // If the core is stalled on a load/store operation the stall ceases and the instruction is forced to complete. This enables Halting debug to gain control of the core.  (bits: 5)
    ,C_SNAPSTALL_MASK = 0x00000020
    ,C_SNAPSTALL_POS = 5
    ,C_SNAPSTALL = 0x00000020
    // Register Read/Write on the Debug Core Register Selector register is available. Last transfer is complete.  (bits: 16)
    ,S_REGRDY_MASK = 0x00010000
    ,S_REGRDY_POS = 16
    ,S_REGRDY = 0x00010000
    // The core is in debug state when S_HALT is set. (bits: 17)
    ,S_HALT_MASK = 0x00020000
    ,S_HALT_POS = 17
    ,S_HALT = 0x00020000
    // Indicates that the core is sleeping (WFI, WFE or SLEEP-ON-EXIT). (bits: 18)
    ,S_SLEEP_MASK = 0x00040000
    ,S_SLEEP_POS = 18
    ,S_SLEEP = 0x00040000
    // Reads as one if the core is running (not halted) and a lockup condition is present. (bits: 19)
    ,S_LOCKUP_MASK = 0x00080000
    ,S_LOCKUP_POS = 19
    ,S_LOCKUP = 0x00080000
    // Indicates that an instruction has completed since last read. (bits: 24)
    ,S_RETIRE_ST_MASK = 0x01000000
    ,S_RETIRE_ST_POS = 24
    ,S_RETIRE_ST = 0x01000000
    // Indicates that the core has been reset, or is now being reset, since the last time this bit was read.  (bits: 25)
    ,S_RESET_ST_MASK = 0x02000000
    ,S_RESET_ST_POS = 25
    ,S_RESET_ST = 0x02000000
    // Debug Key. 0xA05F must be written whenever this register is written. (bits: 31-16)
    ,DBGKEY_MASK = 0xFFFF0000
    ,DBGKEY_POS = 16
    ;
  };
  // Debug Halting Control and Status Register
  struct DCRSR : reg<32, base + 0x4, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Register select (bits: 4-0)
     REGSEL_MASK = 0x0000001F
    ,REGSEL_POS = 0
    ,REGSEL_R0 = 0x00000000 
    ,REGSEL_R1 = 0x00000001 
    ,REGSEL_R2 = 0x00000002 
    ,REGSEL_R3 = 0x00000003 
    ,REGSEL_R4 = 0x00000004 
    ,REGSEL_R5 = 0x00000005 
    ,REGSEL_R6 = 0x00000006 
    ,REGSEL_R7 = 0x00000007 
    ,REGSEL_R8 = 0x00000008 
    ,REGSEL_R9 = 0x00000009 
    ,REGSEL_R10 = 0x0000000A 
    ,REGSEL_R11 = 0x0000000B 
    ,REGSEL_R12 = 0x0000000C 
    ,REGSEL_R13 = 0x0000000D 
    ,REGSEL_R14 = 0x0000000E 
    ,REGSEL_DBG_RET_ADDR = 0x0000000F // DebugReturnAddress()
    ,REGSEL_XPSR = 0x00000010 // xPSR/Flags, Execution Number, and state information
    ,REGSEL_MSP = 0x00000011 // MSP (Main SP)
    ,REGSEL_RAZ_WI = 0x00000012 // RAZ/WI
    ;
  };
  // Debug Core Register Data Register
  using DCRDR = reg<32, base + 0x8, 0x00000000, 0x00000000>;
  // Debug Exception and Monitor Control Register
  struct DEMCR : reg<32, base + 0xC, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Reset Vector Catch. Halt running system if Core reset occurs. (bits: 0)
     VC_CORERESET_MASK = 0x00000001
    ,VC_CORERESET_POS = 0
    ,VC_CORERESET = 0x00000001
    // Debug trap on Memory Management faults. (bits: 4)
    ,VC_MMERR_MASK = 0x00000010
    ,VC_MMERR_POS = 4
    ,VC_MMERR = 0x00000010
    // Debug trap on Usage Fault access to Coprocessor which is not present or marked as not present in CAR register.  (bits: 5)
    ,VC_NOCPERR_MASK = 0x00000020
    ,VC_NOCPERR_POS = 5
    ,VC_NOCPERR = 0x00000020
    // Debug trap on Usage Fault enabled checking errors. (bits: 6)
    ,VC_CHKERR_MASK = 0x00000040
    ,VC_CHKERR_POS = 6
    ,VC_CHKERR = 0x00000040
    // Debug trap on Usage Fault state errors. (bits: 7)
    ,VC_STATERR_MASK = 0x00000080
    ,VC_STATERR_POS = 7
    ,VC_STATERR = 0x00000080
    // Debug Trap on normal Bus error. (bits: 8)
    ,VC_BUSERR_MASK = 0x00000100
    ,VC_BUSERR_POS = 8
    ,VC_BUSERR = 0x00000100
    // Debug Trap on interrupt/exception service errors. (bits: 9)
    ,VC_INTERR_MASK = 0x00000200
    ,VC_INTERR_POS = 9
    ,VC_INTERR = 0x00000200
    // Debug trap on Hard Fault. (bits: 10)
    ,VC_HARDERR_MASK = 0x00000400
    ,VC_HARDERR_POS = 10
    ,VC_HARDERR = 0x00000400
    // Enable the debug monitor. (bits: 16)
    ,MON_EN_MASK = 0x00010000
    ,MON_EN_POS = 16
    ,MON_EN = 0x00010000
    // Pend the monitor to activate when priority permits. (bits: 17)
    ,MON_PEND_MASK = 0x00020000
    ,MON_PEND_POS = 17
    ,MON_PEND = 0x00020000
    // When MON_EN = 1, this steps the core. When MON_EN = 0, this bit is ignored. (bits: 18)
    ,MON_STEP_MASK = 0x00040000
    ,MON_STEP_POS = 18
    ,MON_STEP = 0x00040000
    // This enables the monitor to identify how it wakes up. (bits: 19)
    ,MON_REQ_MASK = 0x00080000
    ,MON_REQ_POS = 19
    ,MON_REQ = 0x00080000
    // This bit must be set to 1 to enable use of the trace and debug blocks. (bits: 24)
    ,TRCENA_MASK = 0x01000000
    ,TRCENA_POS = 24
    ,TRCENA = 0x01000000
    ;
  };
}; // struct CORE_DEBUG

} // namespace lmcu::device

