/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// The DWT unit performs the following debug functionality
// ------------------------------------------------------------------------------------------------
struct DWT
{
  static constexpr std::uintptr_t base = 0xE0001000;

  // Control Register
  struct CTRL : reg<base + 0x0>
  {
    static constexpr typename CTRL::type
    // Enable the CYCCNT counter. (bits: 0)
     CYCCNTENA_MASK = 0x00000001
    ,CYCCNTENA_POS = 0
    ,CYCCNTENA = 0x00000001
    // Reload value for POSTCNT, bits [8:5], post-scalar counter. (bits: 4-1)
    ,POSTPRESET_MASK = 0x0000001E
    ,POSTPRESET_POS = 1
    // Post-scalar counter for CYCTAP. (bits: 8-5)
    ,POSTCNT_MASK = 0x000001E0
    ,POSTCNT_POS = 5
    // Selects a tap on the DWT_CYCCNT register. (bits: 9)
    ,CYCTAP_MASK = 0x00000200
    ,CYCTAP_POS = 9
    ,CYCTAP = 0x00000200
    // Feeds a synchronization pulse to the ITM SYNCENA control. (bits: 11-10)
    ,SYNCTAP_MASK = 0x00000C00
    ,SYNCTAP_POS = 10
    // Enables PC Sampling event. (bits: 12)
    ,PCSAMPLEENA_MASK = 0x00001000
    ,PCSAMPLEENA_POS = 12
    ,PCSAMPLEENA = 0x00001000
    // Enables Interrupt event tracing (bits: 16)
    ,EXCTRCENA_MASK = 0x00010000
    ,EXCTRCENA_POS = 16
    ,EXCTRCENA = 0x00010000
    // Enables CPI count event. (bits: 17)
    ,CPIEVTENA_MASK = 0x00020000
    ,CPIEVTENA_POS = 17
    ,CPIEVTENA = 0x00020000
    // Enables Interrupt overhead event. (bits: 18)
    ,EXCEVTENA_MASK = 0x00040000
    ,EXCEVTENA_POS = 18
    ,EXCEVTENA = 0x00040000
    // Enables Sleep count event. (bits: 19)
    ,SLEEPEVTENA_MASK = 0x00080000
    ,SLEEPEVTENA_POS = 19
    ,SLEEPEVTENA = 0x00080000
    // Enables LSU count event. (bits: 20)
    ,LSUEVTENA_MASK = 0x00100000
    ,LSUEVTENA_POS = 20
    ,LSUEVTENA = 0x00100000
    // Enables Folded instruction count event. (bits: 21)
    ,FOLDEVTENA_MASK = 0x00200000
    ,FOLDEVTENA_POS = 21
    ,FOLDEVTENA = 0x00200000
    // Enables Cycle count event. (bits: 22)
    ,CYCEVTEN_MASK = 0x00400000
    ,CYCEVTEN_POS = 22
    ,CYCEVTEN = 0x00400000
    // Number of comparators field. (bits: 31-28)
    ,NUMCOMP_MASK = 0xF0000000
    ,NUMCOMP_POS = 28
    ,CTRL_MASK = 0xF07F1FFF
    ;
  };
  // Current PC Sampler Cycle Count Register
  using CYCCNT = reg<base + 0x4>;
  // CPI Count Register
  struct CPICR : reg<base + 0x8>
  {
    static constexpr typename CPICR::type
    // Current CPI counter value. (bits: 7-0)
     CPICNT_MASK = 0x000000FF
    ,CPICNT_POS = 0
    ,CPICR_MASK = 0x000000FF
    ;
  };
  // Exception Overhead Count Register
  struct EOCR : reg<base + 0xC>
  {
    static constexpr typename EOCR::type
    // Current interrupt overhead counter value. (bits: 7-0)
     INTCNT_MASK = 0x000000FF
    ,INTCNT_POS = 0
    ,EOCR_MASK = 0x000000FF
    ;
  };
  // Sleep Count Register
  struct SCR : reg<base + 0x10>
  {
    static constexpr typename SCR::type
    // Sleep counter. Counts the number of cycles during which the processor is sleeping. (bits: 7-0)
     SLEEPCNT_MASK = 0x000000FF
    ,SLEEPCNT_POS = 0
    ,SCR_MASK = 0x000000FF
    ;
  };
  // LSU Count Register
  struct LSUCR : reg<base + 0x14>
  {
    static constexpr typename LSUCR::type
    // LSU counter. This counts the total number of cycles that the processor is processing an LSU operation. (bits: 7-0)
     LSUCNT_MASK = 0x000000FF
    ,LSUCNT_POS = 0
    ,LSUCR_MASK = 0x000000FF
    ;
  };
  // Fold Count Register
  struct FCR : reg<base + 0x18>
  {
    static constexpr typename FCR::type
    // This counts the total number folded instructions. (bits: 7-0)
     FOLDCNT_MASK = 0x000000FF
    ,FOLDCNT_POS = 0
    ,FCR_MASK = 0x000000FF
    ;
  };
  // Program Counter Sample Register
  using PCSR = reg<base + 0x1C>;
  // Comparator Register
  using CMPR0 = reg<base + 0x20>;
  // Comparator Register
  using CMPR1 = reg<base + 0x30>;
  // Comparator Register
  using CMPR2 = reg<base + 0x40>;
  // Comparator Register
  using CMPR3 = reg<base + 0x50>;
  // Mask Register
  using MSKR0 = reg<base + 0x24>;
  // Mask Register
  using MSKR1 = reg<base + 0x34>;
  // Mask Register
  using MSKR2 = reg<base + 0x44>;
  // Mask Register
  using MSKR3 = reg<base + 0x54>;
  // Function Register
  struct FR0 : reg<base + 0x28>
  {
    static constexpr typename FR0::type
    // FUNCTION settings (bits: 3-0)
     FUNCTION_MASK = 0x0000000F
    ,FUNCTION_POS = 0
    ,FUNCTION_DISABLED = 0x00000000 // disabled
    ,FUNCTION_FN1 = 0x00000001 // EMITRANGE = 0, sample and emit PC through ITM; EMITRANGE = 1, emit address offset through ITM
    ,FUNCTION_FN2 = 0x00000002 // EMITRANGE = 0, emit data through ITM on read and write; EMITRANGE = 1, emit data and address offset through ITM on read or write.
    ,FUNCTION_FN3 = 0x00000003 // EMITRANGE = 0, sample PC and data value through ITM on read or write; EMITRANGE = 1, emit address offset and data value through ITM on read or write.
    ,FUNCTION_FN4 = 0x00000004 // Watchpoint on PC match.
    ,FUNCTION_FN5 = 0x00000005 // Watchpoint on read.
    ,FUNCTION_FN6 = 0x00000006 // Watchpoint on write.
    ,FUNCTION_FN7 = 0x00000007 // Watchpoint on read or write.
    ,FUNCTION_FN8 = 0x00000008 // ETM trigger on PC match
    ,FUNCTION_FN9 = 0x00000009 // ETM trigger on read
    ,FUNCTION_FN10 = 0x0000000A // ETM trigger on write
    ,FUNCTION_FN11 = 0x0000000B // ETM trigger on read or write
    ,FR0_MASK = 0x0000000F
    ;
  };
}; // struct DWT

} // namespace lmcu::device

