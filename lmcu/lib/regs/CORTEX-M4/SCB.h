/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// System Control Block
// ------------------------------------------------------------------------------------------------
struct SCB
{
  static constexpr auto ip_ver = ip_version::none;

  static constexpr std::uintptr_t base = 0xE000ED00;

  // CPUID Base Register (R/ )
  struct CPUID : reg<ip_ver, base + 0x0>
  {
    static constexpr typename CPUID::type
    // Implementor (bits: 31-24)
     IMPLEMENTER_MASK = 0xFF000000
    ,IMPLEMENTER_POS = 24
    // Processor revision (bits: 23-20)
    ,VARIANT_MASK = 0x00F00000
    ,VARIANT_POS = 20
    // Reads as 0xF (bits: 19-16)
    ,CONSTANT_MASK = 0x000F0000
    ,CONSTANT_POS = 16
    // Part number (bits: 15-4)
    ,PARTNO_MASK = 0x0000FFF0
    ,PARTNO_POS = 4
    // Patch release (bits: 3-0)
    ,REVISION_MASK = 0x0000000F
    ,REVISION_POS = 0
    ,CPUID_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Control and State Register (R/W)
  struct ICSR : reg<ip_ver, base + 0x4>
  {
    static constexpr typename ICSR::type
    // Active vector (bits: 9)
     VECTACTIVE_MASK = 0x00000200
    ,VECTACTIVE_POS = 9
    ,VECTACTIVE = 0x00000200
    // Return to base level (bits: 11)
    ,RETTOBASE_MASK = 0x00000800
    ,RETTOBASE_POS = 11
    ,RETTOBASE = 0x00000800
    // Pending vector (bits: 18-12)
    ,VECTPENDING_MASK = 0x0007F000
    ,VECTPENDING_POS = 12
    // Interrupt pending flag (bits: 22)
    ,ISRPENDING_MASK = 0x00400000
    ,ISRPENDING_POS = 22
    ,ISRPENDING = 0x00400000
    // SysTick exception clear-pending bit (bits: 25)
    ,PENDSTCLR_MASK = 0x02000000
    ,PENDSTCLR_POS = 25
    ,PENDSTCLR = 0x02000000
    // SysTick exception set-pending bit (bits: 26)
    ,PENDSTSET_MASK = 0x04000000
    ,PENDSTSET_POS = 26
    ,PENDSTSET = 0x04000000
    // PendSV clear-pending bit (bits: 27)
    ,PENDSVCLR_MASK = 0x08000000
    ,PENDSVCLR_POS = 27
    ,PENDSVCLR = 0x08000000
    // PendSV set-pending bit (bits: 28)
    ,PENDSVSET_MASK = 0x10000000
    ,PENDSVSET_POS = 28
    ,PENDSVSET = 0x10000000
    // NMI set-pending bit (bits: 31)
    ,NMIPENDSET_MASK = 0x80000000
    ,NMIPENDSET_POS = 31
    ,NMIPENDSET = 0x80000000
    ,ICSR_MASK = 0x9E47FA00
    ;
  };
  // Vector Table Offset Register (R/W)
  struct VTOR : reg<ip_ver, base + 0x8>
  {
    static constexpr typename VTOR::type
    // Vector table base offset field (bits: 29-9)
     TBLOFF_MASK = 0x3FFFFE00
    ,TBLOFF_POS = 9
    ,VTOR_MASK = 0x3FFFFE00
    ;
  };
  // Application Interrupt and Reset Control Register (R/W)
  struct AIRCR : reg<ip_ver, base + 0xC>
  {
    static constexpr typename AIRCR::type
    // VECTRESET (bits: 0)
     VECTRESET_MASK = 0x00000001
    ,VECTRESET_POS = 0
    ,VECTRESET = 0x00000001
    // VECTCLRACTIVE (bits: 1)
    ,VECTCLRACTIVE_MASK = 0x00000002
    ,VECTCLRACTIVE_POS = 1
    ,VECTCLRACTIVE = 0x00000002
    // SYSRESETREQ (bits: 2)
    ,SYSRESETREQ_MASK = 0x00000004
    ,SYSRESETREQ_POS = 2
    ,SYSRESETREQ = 0x00000004
    // PRIGROUP (bits: 10-8)
    ,PRIGROUP_MASK = 0x00000700
    ,PRIGROUP_POS = 8
    // ENDIANESS (bits: 15)
    ,ENDIANESS_MASK = 0x00008000
    ,ENDIANESS_POS = 15
    ,ENDIANESS = 0x00008000
    // Register key (bits: 31-16)
    ,VECTKEYSTAT_MASK = 0xFFFF0000
    ,VECTKEYSTAT_POS = 16
    ,AIRCR_MASK = 0xFFFF8707
    ;
  };
  // System Control Register (R/W)
  struct SCR : reg<ip_ver, base + 0x10>
  {
    static constexpr typename SCR::type
    // SLEEPONEXIT (bits: 1)
     SLEEPONEXIT_MASK = 0x00000002
    ,SLEEPONEXIT_POS = 1
    ,SLEEPONEXIT = 0x00000002
    // SLEEPDEEP (bits: 2)
    ,SLEEPDEEP_MASK = 0x00000004
    ,SLEEPDEEP_POS = 2
    ,SLEEPDEEP = 0x00000004
    // Send Event on Pending bit (bits: 4)
    ,SEVEONPEND_MASK = 0x00000010
    ,SEVEONPEND_POS = 4
    ,SEVEONPEND = 0x00000010
    ,SCR_MASK = 0x00000016
    ;
  };
  // Configuration Control Register (R/W)
  struct CCR : reg<ip_ver, base + 0x14>
  {
    static constexpr typename CCR::type
    // Configures how the processor enters Thread mode (bits: 0)
     NONBASETHRDENA_MASK = 0x00000001
    ,NONBASETHRDENA_POS = 0
    ,NONBASETHRDENA = 0x00000001
    // USERSETMPEND (bits: 1)
    ,USERSETMPEND_MASK = 0x00000002
    ,USERSETMPEND_POS = 1
    ,USERSETMPEND = 0x00000002
    // UNALIGN_TRP (bits: 3)
    ,UNALIGN__TRP_MASK = 0x00000008
    ,UNALIGN__TRP_POS = 3
    ,UNALIGN__TRP = 0x00000008
    // DIV_0_TRP (bits: 4)
    ,DIV_0_TRP_MASK = 0x00000010
    ,DIV_0_TRP_POS = 4
    ,DIV_0_TRP = 0x00000010
    // BFHFNMIGN (bits: 8)
    ,BFHFNMIGN_MASK = 0x00000100
    ,BFHFNMIGN_POS = 8
    ,BFHFNMIGN = 0x00000100
    // STKALIGN (bits: 9)
    ,STKALIGN_MASK = 0x00000200
    ,STKALIGN_POS = 9
    ,STKALIGN = 0x00000200
    ,CCR_MASK = 0x0000031B
    ;
  };
  // System Handlers Priority Registers (4-7, 8-11, 12-15) (R/W) (count: 12)
  using SHPR = reg<ip_ver, base + 0x18, 0x00000000, 12, 8>;
  // System Handler Control and State Register (R/W)
  struct SHCSR : reg<ip_ver, base + 0x24>
  {
    static constexpr typename SHCSR::type
    // Memory management fault exception active bit (bits: 0)
     MEMFAULTACT_MASK = 0x00000001
    ,MEMFAULTACT_POS = 0
    ,MEMFAULTACT = 0x00000001
    // Bus fault exception active bit (bits: 1)
    ,BUSFAULTACT_MASK = 0x00000002
    ,BUSFAULTACT_POS = 1
    ,BUSFAULTACT = 0x00000002
    // Usage fault exception active bit (bits: 3)
    ,USGFAULTACT_MASK = 0x00000008
    ,USGFAULTACT_POS = 3
    ,USGFAULTACT = 0x00000008
    // SVC call active bit (bits: 7)
    ,SVCALLACT_MASK = 0x00000080
    ,SVCALLACT_POS = 7
    ,SVCALLACT = 0x00000080
    // Debug monitor active bit (bits: 8)
    ,MONITORACT_MASK = 0x00000100
    ,MONITORACT_POS = 8
    ,MONITORACT = 0x00000100
    // PendSV exception active bit (bits: 10)
    ,PENDSVACT_MASK = 0x00000400
    ,PENDSVACT_POS = 10
    ,PENDSVACT = 0x00000400
    // SysTick exception active bit (bits: 11)
    ,SYSTICKACT_MASK = 0x00000800
    ,SYSTICKACT_POS = 11
    ,SYSTICKACT = 0x00000800
    // Usage fault exception pending bit (bits: 12)
    ,USGFAULTPENDED_MASK = 0x00001000
    ,USGFAULTPENDED_POS = 12
    ,USGFAULTPENDED = 0x00001000
    // Memory management fault exception pending bit (bits: 13)
    ,MEMFAULTPENDED_MASK = 0x00002000
    ,MEMFAULTPENDED_POS = 13
    ,MEMFAULTPENDED = 0x00002000
    // Bus fault exception pending bit (bits: 14)
    ,BUSFAULTPENDED_MASK = 0x00004000
    ,BUSFAULTPENDED_POS = 14
    ,BUSFAULTPENDED = 0x00004000
    // SVC call pending bit (bits: 15)
    ,SVCALLPENDED_MASK = 0x00008000
    ,SVCALLPENDED_POS = 15
    ,SVCALLPENDED = 0x00008000
    // Memory management fault enable bit (bits: 16)
    ,MEMFAULTENA_MASK = 0x00010000
    ,MEMFAULTENA_POS = 16
    ,MEMFAULTENA = 0x00010000
    // Bus fault enable bit (bits: 17)
    ,BUSFAULTENA_MASK = 0x00020000
    ,BUSFAULTENA_POS = 17
    ,BUSFAULTENA = 0x00020000
    // Usage fault enable bit (bits: 18)
    ,USGFAULTENA_MASK = 0x00040000
    ,USGFAULTENA_POS = 18
    ,USGFAULTENA = 0x00040000
    ,SHCSR_MASK = 0x0007FD8B
    ;
  };
  // Configurable Fault Status Register (R/W)
  struct CFSR : reg<ip_ver, base + 0x28>
  {
    static constexpr typename CFSR::type
    // Instruction access violation flag (bits: 0)
     IACCVIOL_MASK = 0x00000001
    ,IACCVIOL_POS = 0
    ,IACCVIOL = 0x00000001
    // Data access violation flag (bits: 1)
    ,DACCVIOL_MASK = 0x00000002
    ,DACCVIOL_POS = 1
    ,DACCVIOL = 0x00000002
    // Memory manager fault on unstacking for a return from exception (bits: 3)
    ,MUNSTKERR_MASK = 0x00000008
    ,MUNSTKERR_POS = 3
    ,MUNSTKERR = 0x00000008
    // Memory manager fault on stacking for exception entry (bits: 4)
    ,MSTKERR_MASK = 0x00000010
    ,MSTKERR_POS = 4
    ,MSTKERR = 0x00000010
    // MLSPERR</description> (bits: 5)
    ,MLSPERR_MASK = 0x00000020
    ,MLSPERR_POS = 5
    ,MLSPERR = 0x00000020
    // Memory Management Fault Address Register (MMAR) valid flag (bits: 7)
    ,MMARVALID_MASK = 0x00000080
    ,MMARVALID_POS = 7
    ,MMARVALID = 0x00000080
    // Instruction bus error (bits: 8)
    ,IBUSERR_MASK = 0x00000100
    ,IBUSERR_POS = 8
    ,IBUSERR = 0x00000100
    // Precise data bus error (bits: 9)
    ,PRECISERR_MASK = 0x00000200
    ,PRECISERR_POS = 9
    ,PRECISERR = 0x00000200
    // Imprecise data bus error (bits: 10)
    ,IMPRECISERR_MASK = 0x00000400
    ,IMPRECISERR_POS = 10
    ,IMPRECISERR = 0x00000400
    // Bus fault on unstacking for a return from exception (bits: 11)
    ,UNSTKERR_MASK = 0x00000800
    ,UNSTKERR_POS = 11
    ,UNSTKERR = 0x00000800
    // Bus fault on stacking for exception entry (bits: 12)
    ,STKERR_MASK = 0x00001000
    ,STKERR_POS = 12
    ,STKERR = 0x00001000
    // Bus fault on floating-point lazy state preservation (bits: 13)
    ,LSPERR_MASK = 0x00002000
    ,LSPERR_POS = 13
    ,LSPERR = 0x00002000
    // Bus Fault Address Register (BFAR) valid flag (bits: 15)
    ,BFARVALID_MASK = 0x00008000
    ,BFARVALID_POS = 15
    ,BFARVALID = 0x00008000
    // Undefined instruction usage fault (bits: 16)
    ,UNDEFINSTR_MASK = 0x00010000
    ,UNDEFINSTR_POS = 16
    ,UNDEFINSTR = 0x00010000
    // Invalid state usage fault (bits: 17)
    ,INVSTATE_MASK = 0x00020000
    ,INVSTATE_POS = 17
    ,INVSTATE = 0x00020000
    // Invalid PC load usage fault (bits: 18)
    ,INVPC_MASK = 0x00040000
    ,INVPC_POS = 18
    ,INVPC = 0x00040000
    // No coprocessor usage fault. (bits: 19)
    ,NOCP_MASK = 0x00080000
    ,NOCP_POS = 19
    ,NOCP = 0x00080000
    // Unaligned access usage fault (bits: 24)
    ,UNALIGNED_MASK = 0x01000000
    ,UNALIGNED_POS = 24
    ,UNALIGNED = 0x01000000
    // Divide by zero usage fault (bits: 25)
    ,DIVBYZERO_MASK = 0x02000000
    ,DIVBYZERO_POS = 25
    ,DIVBYZERO = 0x02000000
    ,CFSR_MASK = 0x030FBFBB
    ;
  };
  // HardFault Status Register (R/W)
  struct HFSR : reg<ip_ver, base + 0x2C>
  {
    static constexpr typename HFSR::type
    // Vector table hard fault (bits: 1)
     VECTTBL_MASK = 0x00000002
    ,VECTTBL_POS = 1
    ,VECTTBL = 0x00000002
    // Forced hard fault (bits: 30)
    ,FORCED_MASK = 0x40000000
    ,FORCED_POS = 30
    ,FORCED = 0x40000000
    // Reserved for Debug use (bits: 31)
    ,DEBUG_VT_MASK = 0x80000000
    ,DEBUG_VT_POS = 31
    ,DEBUG_VT = 0x80000000
    ,HFSR_MASK = 0xC0000002
    ;
  };
  // Debug Fault Status Register (R/W)
  using DFSR = reg<ip_ver, base + 0x30>;
  // MemManage Fault Address Register (R/W)
  using MMFAR = reg<ip_ver, base + 0x34>;
  // BusFault Address Register (R/W)
  using BFAR = reg<ip_ver, base + 0x38>;
  // Auxiliary Fault Status Register (R/W)
  using AFSR = reg<ip_ver, base + 0x3C>;
  // Processor Feature Register (R/ ) (count: 2)
  using PFR = reg<ip_ver, base + 0x40, 0x00000000, 2>;
  // Debug Feature Register (R/ )
  using DFR = reg<ip_ver, base + 0x48>;
  // Auxiliary Feature Register (R/ )
  using ADR = reg<ip_ver, base + 0x4C>;
  // Memory Model Feature Register (R/ ) (count: 4)
  using MMFR = reg<ip_ver, base + 0x50, 0x00000000, 4>;
  // Instruction Set Attributes Register (R/ ) (count: 5)
  using ISAR = reg<ip_ver, base + 0x60, 0x00000000, 5>;
  // Coprocessor Access Control Register (R/W)
  using CPACR = reg<ip_ver, base + 0x88>;
}; // struct SCB

} // namespace lmcu::device

