/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Nested Vectored Interrupt Controller
// ------------------------------------------------------------------------------------------------
struct NVIC
{
  static constexpr std::uintptr_t base = 0xE000E000;

  // Interrupt Controller Type Register
  struct ICTR : reg<base + 0x4>
  {
    static constexpr typename ICTR::type
    // Number of interrupt lines that the NVIC supports (bits: 4-0)
     INTLINESNUM_MASK = 0x0000001F
    ,INTLINESNUM_POS = 0
    ,ICTR_MASK = 0x0000001F
    ;
  };
  // SysTick Control and Status Register
  struct STCSR : reg<base + 0x10>
  {
    static constexpr typename STCSR::type
    // 1 = counter operates in a multi-shot way. 0 = counter disabled. (bits: 0)
     ENABLE_MASK = 0x00000001
    ,ENABLE_POS = 0
    ,ENABLE = 0x00000001
    // 1 = counting down to 0 pends the SysTick handler. (bits: 1)
    ,TICKINT_MASK = 0x00000002
    ,TICKINT_POS = 1
    ,TICKINT = 0x00000002
    // 1 = core clock. 0 = external reference clock. (bits: 2)
    ,CLKSOURCE_MASK = 0x00000004
    ,CLKSOURCE_POS = 2
    ,CLKSOURCE = 0x00000004
    // Returns 1 if timer counted to 0 since last time this was read. Clears on read by application of any part of the SysTick Control and Status Register. (bits: 16)
    ,COUNTFLAG_MASK = 0x00010000
    ,COUNTFLAG_POS = 16
    ,COUNTFLAG = 0x00010000
    ,STCSR_MASK = 0x00010007
    ;
  };
  // SysTick Reload Value Register
  struct STRVR : reg<base + 0x14>
  {
    static constexpr typename STRVR::type
    // Value to load into the SysTick Current Value Register when the counter reaches 0. (bits: 23-0)
     RELOAD_MASK = 0x00FFFFFF
    ,RELOAD_POS = 0
    ,STRVR_MASK = 0x00FFFFFF
    ;
  };
  // SysTick Current Value Register
  struct STCVR : reg<base + 0x18>
  {
    static constexpr typename STCVR::type
    // Current value at the time the register is accessed. (bits: 23-0)
     CURRENT_MASK = 0x00FFFFFF
    ,CURRENT_POS = 0
    ,STCVR_MASK = 0x00FFFFFF
    ;
  };
  // SysTick Calibration Value Register
  struct STCALIBR : reg<base + 0x1C>
  {
    static constexpr typename STCALIBR::type
    // This value is the Reload value to use for 10ms timing. (bits: 23-0)
     TENMS_MASK = 0x00FFFFFF
    ,TENMS_POS = 0
    // 1 = the calibration value is not exactly 10ms because of clock frequency. (bits: 30)
    ,SKEW_MASK = 0x40000000
    ,SKEW_POS = 30
    ,SKEW = 0x40000000
    // 1 = the reference clock is not provided. (bits: 31)
    ,NOREF_MASK = 0x80000000
    ,NOREF_POS = 31
    ,NOREF = 0x80000000
    ,STCALIBR_MASK = 0xC0FFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER0 : reg<base + 0x100>
  {
    static constexpr typename ISER0::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER0_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER1 : reg<base + 0x104>
  {
    static constexpr typename ISER1::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER1_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER2 : reg<base + 0x108>
  {
    static constexpr typename ISER2::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER2_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER3 : reg<base + 0x10C>
  {
    static constexpr typename ISER3::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER3_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER4 : reg<base + 0x110>
  {
    static constexpr typename ISER4::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER4_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER5 : reg<base + 0x114>
  {
    static constexpr typename ISER5::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER5_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER6 : reg<base + 0x118>
  {
    static constexpr typename ISER6::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER6_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Enable Register
  struct ISER7 : reg<base + 0x11C>
  {
    static constexpr typename ISER7::type
    // Interrupt set enable bits (bits: 31-0)
     SETENA_MASK = 0xFFFFFFFF
    ,SETENA_POS = 0
    ,ISER7_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER0 : reg<base + 0x180>
  {
    static constexpr typename ICER0::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER0_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER1 : reg<base + 0x184>
  {
    static constexpr typename ICER1::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER1_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER2 : reg<base + 0x188>
  {
    static constexpr typename ICER2::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER2_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER3 : reg<base + 0x18C>
  {
    static constexpr typename ICER3::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER3_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER4 : reg<base + 0x190>
  {
    static constexpr typename ICER4::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER4_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER5 : reg<base + 0x194>
  {
    static constexpr typename ICER5::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER5_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER6 : reg<base + 0x198>
  {
    static constexpr typename ICER6::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER6_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Enable Register
  struct ICER7 : reg<base + 0x19C>
  {
    static constexpr typename ICER7::type
    // Interrupt clear-enable bits (bits: 31-0)
     CLRENA_MASK = 0xFFFFFFFF
    ,CLRENA_POS = 0
    ,ICER7_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR0 : reg<base + 0x200>
  {
    static constexpr typename ISPR0::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR0_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR1 : reg<base + 0x204>
  {
    static constexpr typename ISPR1::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR1_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR2 : reg<base + 0x208>
  {
    static constexpr typename ISPR2::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR2_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR3 : reg<base + 0x20C>
  {
    static constexpr typename ISPR3::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR3_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR4 : reg<base + 0x210>
  {
    static constexpr typename ISPR4::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR4_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR5 : reg<base + 0x214>
  {
    static constexpr typename ISPR5::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR5_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR6 : reg<base + 0x218>
  {
    static constexpr typename ISPR6::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR6_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Set-Pending Register
  struct ISPR7 : reg<base + 0x21C>
  {
    static constexpr typename ISPR7::type
    // Interrupt set-pending bits (bits: 31-0)
     SETPEND_MASK = 0xFFFFFFFF
    ,SETPEND_POS = 0
    ,ISPR7_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR0 : reg<base + 0x280>
  {
    static constexpr typename ICPR0::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR0_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR1 : reg<base + 0x284>
  {
    static constexpr typename ICPR1::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR1_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR2 : reg<base + 0x288>
  {
    static constexpr typename ICPR2::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR2_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR3 : reg<base + 0x28C>
  {
    static constexpr typename ICPR3::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR3_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR4 : reg<base + 0x290>
  {
    static constexpr typename ICPR4::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR4_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR5 : reg<base + 0x294>
  {
    static constexpr typename ICPR5::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR5_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR6 : reg<base + 0x298>
  {
    static constexpr typename ICPR6::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR6_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Clear-Pending Register
  struct ICPR7 : reg<base + 0x29C>
  {
    static constexpr typename ICPR7::type
    // Interrupt set-pending bits (bits: 31-0)
     CLRPEND_MASK = 0xFFFFFFFF
    ,CLRPEND_POS = 0
    ,ICPR7_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR0 : reg<base + 0x300>
  {
    static constexpr typename IABR0::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR0_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR1 : reg<base + 0x304>
  {
    static constexpr typename IABR1::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR1_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR2 : reg<base + 0x308>
  {
    static constexpr typename IABR2::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR2_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR3 : reg<base + 0x30C>
  {
    static constexpr typename IABR3::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR3_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR4 : reg<base + 0x310>
  {
    static constexpr typename IABR4::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR4_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR5 : reg<base + 0x314>
  {
    static constexpr typename IABR5::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR5_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR6 : reg<base + 0x318>
  {
    static constexpr typename IABR6::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR6_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Active Bit Register
  struct IABR7 : reg<base + 0x31C>
  {
    static constexpr typename IABR7::type
    // Interrupt active flags (bits: 31-0)
     ACTIVE_MASK = 0xFFFFFFFF
    ,ACTIVE_POS = 0
    ,IABR7_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR0 : reg<base + 0x400>
  {
    static constexpr typename IPR0::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR0_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR1 : reg<base + 0x404>
  {
    static constexpr typename IPR1::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR1_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR2 : reg<base + 0x408>
  {
    static constexpr typename IPR2::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR2_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR3 : reg<base + 0x40C>
  {
    static constexpr typename IPR3::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR3_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR4 : reg<base + 0x410>
  {
    static constexpr typename IPR4::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR4_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR5 : reg<base + 0x414>
  {
    static constexpr typename IPR5::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR5_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR6 : reg<base + 0x418>
  {
    static constexpr typename IPR6::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR6_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Priority Register
  struct IPR7 : reg<base + 0x41C>
  {
    static constexpr typename IPR7::type
    // Priority of interrupt 0 (bits: 7-0)
     PRI_0_MASK = 0x000000FF
    ,PRI_0_POS = 0
    // Priority of interrupt 1 (bits: 15-8)
    ,PRI_1_MASK = 0x0000FF00
    ,PRI_1_POS = 8
    // Priority of interrupt 2 (bits: 23-16)
    ,PRI_2_MASK = 0x00FF0000
    ,PRI_2_POS = 16
    // Priority of interrupt 3 (bits: 31-24)
    ,PRI_3_MASK = 0xFF000000
    ,PRI_3_POS = 24
    ,IPR7_MASK = 0xFFFFFFFF
    ;
  };
  // CPU ID Base Register
  struct CPUIDBR : reg<base + 0xD00, 0x411FC231>
  {
    static constexpr typename CPUIDBR::type
    // Implementation defined revision number. (bits: 3-0)
     REVISION_MASK = 0x0000000F
    ,REVISION_POS = 0
    // Number of processor within family (bits: 15-4)
    ,PARTNO_MASK = 0x0000FFF0
    ,PARTNO_POS = 4
    // Reads as 0xF (bits: 19-16)
    ,CONSTANT_MASK = 0x000F0000
    ,CONSTANT_POS = 16
    // Implementation defined variant number. (bits: 23-20)
    ,VARIANT_MASK = 0x00F00000
    ,VARIANT_POS = 20
    // Implementer code. ARM is 0x41. (bits: 31-24)
    ,IMPLEMENTER_MASK = 0xFF000000
    ,IMPLEMENTER_POS = 24
    ,CPUIDBR_MASK = 0xFFFFFFFF
    ;
  };
  // Interrupt Control State Register
  struct ICSR : reg<base + 0xD04>
  {
    static constexpr typename ICSR::type
    // Active ISR number field. (bits: 8-0)
     VECTACTIVE_MASK = 0x000001FF
    ,VECTACTIVE_POS = 0
    // This bit is 1 when the set of all active exceptions minus the IPSR_current_exception yields the empty set. (bits: 11)
    ,RETTOBASE_MASK = 0x00000800
    ,RETTOBASE_POS = 11
    ,RETTOBASE = 0x00000800
    // Pending ISR number field. (bits: 21-12)
    ,VECTPENDING_MASK = 0x003FF000
    ,VECTPENDING_POS = 12
    // Interrupt pending flag. Excludes NMI and Faults. (bits: 22)
    ,ISRPENDING_MASK = 0x00400000
    ,ISRPENDING_POS = 22
    ,ISRPENDING = 0x00400000
    // You must only use this at debug time. It indicates that a pending interrupt becomes active in the next running cycle. (bits: 23)
    ,ISRPREEMPT_MASK = 0x00800000
    ,ISRPREEMPT_POS = 23
    ,ISRPREEMPT = 0x00800000
    // Clear pending SysTick bit (bits: 25)
    ,PENDSTCLR_MASK = 0x02000000
    ,PENDSTCLR_POS = 25
    ,PENDSTCLR = 0x02000000
    // Set a pending SysTick bit (bits: 26)
    ,PENDSTSET_MASK = 0x04000000
    ,PENDSTSET_POS = 26
    ,PENDSTSET = 0x04000000
    // Clear pending pendSV bit (bits: 27)
    ,PENDSVCLR_MASK = 0x08000000
    ,PENDSVCLR_POS = 27
    ,PENDSVCLR = 0x08000000
    // Set pending pendSV bit (bits: 28)
    ,PENDSVSET_MASK = 0x10000000
    ,PENDSVSET_POS = 28
    ,PENDSVSET = 0x10000000
    // Set pending NMI bit (bits: 31)
    ,NMIPENDSET_MASK = 0x80000000
    ,NMIPENDSET_POS = 31
    ,NMIPENDSET = 0x80000000
    ,ICSR_MASK = 0x9EFFF9FF
    ;
  };
  // Vector Table Offset Register
  struct VTOR : reg<base + 0xD08>
  {
    static constexpr typename VTOR::type
    // Vector table base offset field. Contains the offset of the table base from the bottom of the SRAM or CODE space. (bits: 28-7)
     TBLOFF_MASK = 0x1FFFFF80
    ,TBLOFF_POS = 7
    // Table base is in Code (0) or RAM (1) (bits: 29)
    ,TBLBASE_MASK = 0x20000000
    ,TBLBASE_POS = 29
    ,TBLBASE = 0x20000000
    ,VTOR_MASK = 0x3FFFFF80
    ;
  };
  // System Control Register
  struct SCR : reg<base + 0xD10>
  {
    static constexpr typename SCR::type
    // Sleep on exit when returning from Handler mode to Thread mode. (bits: 1)
     SLEEPONEXIT_MASK = 0x00000002
    ,SLEEPONEXIT_POS = 1
    ,SLEEPONEXIT = 0x00000002
    // Sleep deep bit (bits: 2)
    ,SLEEPDEEP_MASK = 0x00000004
    ,SLEEPDEEP_POS = 2
    ,SLEEPDEEP = 0x00000004
    // When enabled, this causes WFE to wake up when an interrupt moves from inactive to pended. (bits: 4)
    ,SEVONPEND_MASK = 0x00000010
    ,SEVONPEND_POS = 4
    ,SEVONPEND = 0x00000010
    ,SCR_MASK = 0x00000016
    ;
  };
  // Configuration Control Register
  struct CCR : reg<base + 0xD14>
  {
    static constexpr typename CCR::type
    // When 0, default, It is only possible to enter Thread mode when returning from the last exception. When set to 1, Thread mode can be entered from any level in Handler mode by controlled return value. (bits: 0)
     NONEBASETHRDENA_MASK = 0x00000001
    ,NONEBASETHRDENA_POS = 0
    ,NONEBASETHRDENA = 0x00000001
    // If written as 1, enables user code to write the Software Trigger Interrupt register to trigger (pend) a Main exception, which is one associated with the Main stack pointer. (bits: 1)
    ,USERSETMPEND_MASK = 0x00000002
    ,USERSETMPEND_POS = 1
    ,USERSETMPEND = 0x00000002
    // Trap for unaligned access. This enables faulting/halting on any unaligned half or full word access. Unaligned load-store multiples always fault. The relevant Usage Fault Status Register bit is UNALIGNED. (bits: 3)
    ,UNALIGN_TRP_MASK = 0x00000008
    ,UNALIGN_TRP_POS = 3
    ,UNALIGN_TRP = 0x00000008
    // Trap on Divide by 0. This enables faulting/halting when an attempt is made to divide by 0. The relevant Usage Fault Status Register bit is DIVBYZERO. (bits: 4)
    ,DIV_0_TRP_MASK = 0x00000010
    ,DIV_0_TRP_POS = 4
    ,DIV_0_TRP = 0x00000010
    // When enabled, this causes handlers running at priority -1 and -2 (Hard Fault, NMI, and FAULTMASK escalated handlers) to ignore Data Bus faults caused by load and store instructions. When disabled, these bus faults cause a lock-up. (bits: 8)
    ,BFHFNMIGN_MASK = 0x00000100
    ,BFHFNMIGN_POS = 8
    ,BFHFNMIGN = 0x00000100
    // 1 = on exception entry, the SP used prior to the exception is adjusted to be 8-byte aligned and the context to restore it is saved. The SP is restored on the associated exception return. 0 = only 4-byte alignment is guaranteed for the SP used prior to the exception on exception entry. (bits: 9)
    ,STKALIGN_MASK = 0x00000200
    ,STKALIGN_POS = 9
    ,STKALIGN = 0x00000200
    ,CCR_MASK = 0x0000031B
    ;
  };
  // System Handler Priority Register 0
  struct SHPR0 : reg<base + 0xD18>
  {
    static constexpr typename SHPR0::type
    // Priority of system handler 4, 8, and 12. Mem Manage, reserved, and Debug Monitor. (bits: 7-0)
     PRI_4_MASK = 0x000000FF
    ,PRI_4_POS = 0
    // Priority of system handler 5, 9, and 13, Bus Fault, reserved, and reserved. (bits: 15-8)
    ,PRI_5_MASK = 0x0000FF00
    ,PRI_5_POS = 8
    // Priority of system handler 6, 10, and 14. Usage Fault, reserved, and PendSV. (bits: 23-16)
    ,PRI_6_MASK = 0x00FF0000
    ,PRI_6_POS = 16
    // Priority of system handler 7, 11, and 15. Reserved, SVCall, and SysTick. (bits: 31-24)
    ,PRI_7_MASK = 0xFF000000
    ,PRI_7_POS = 24
    ,SHPR0_MASK = 0xFFFFFFFF
    ;
  };
  // System Handler Priority Register 1
  struct SHPR1 : reg<base + 0xD1C>
  {
    static constexpr typename SHPR1::type
    // Priority of system handler 4, 8, and 12. Mem Manage, reserved, and Debug Monitor. (bits: 7-0)
     PRI_8_MASK = 0x000000FF
    ,PRI_8_POS = 0
    // Priority of system handler 5, 9, and 13, Bus Fault, reserved, and reserved. (bits: 15-8)
    ,PRI_9_MASK = 0x0000FF00
    ,PRI_9_POS = 8
    // Priority of system handler 6, 10, and 14. Usage Fault, reserved, and PendSV. (bits: 23-16)
    ,PRI_10_MASK = 0x00FF0000
    ,PRI_10_POS = 16
    // Priority of system handler 7, 11, and 15. Reserved, SVCall, and SysTick. (bits: 31-24)
    ,PRI_11_MASK = 0xFF000000
    ,PRI_11_POS = 24
    ,SHPR1_MASK = 0xFFFFFFFF
    ;
  };
  // System Handler Priority Register 2
  struct SHPR2 : reg<base + 0xD20>
  {
    static constexpr typename SHPR2::type
    // Priority of system handler 4, 8, and 12. Mem Manage, reserved, and Debug Monitor. (bits: 7-0)
     PRI_12_MASK = 0x000000FF
    ,PRI_12_POS = 0
    // Priority of system handler 5, 9, and 13, Bus Fault, reserved, and reserved. (bits: 15-8)
    ,PRI_13_MASK = 0x0000FF00
    ,PRI_13_POS = 8
    // Priority of system handler 6, 10, and 14. Usage Fault, reserved, and PendSV. (bits: 23-16)
    ,PRI_14_MASK = 0x00FF0000
    ,PRI_14_POS = 16
    // Priority of system handler 7, 11, and 15. Reserved, SVCall, and SysTick. (bits: 31-24)
    ,PRI_15_MASK = 0xFF000000
    ,PRI_15_POS = 24
    ,SHPR2_MASK = 0xFFFFFFFF
    ;
  };
  // Memory Manage Fault Status Register
  struct MMFSR : reg<base + 0xD28, 0x00000000, 1, 8>
  {
    static constexpr typename MMFSR::type
    // Instruction access violation flag. (bits: 0)
     IACCVIOL_MASK = 0x00000001
    ,IACCVIOL_POS = 0
    ,IACCVIOL = 0x00000001
    // Data access violation flag. (bits: 1)
    ,DACCVIOL_MASK = 0x00000002
    ,DACCVIOL_POS = 1
    ,DACCVIOL = 0x00000002
    // Unstack from exception return has caused one or more access violations. (bits: 3)
    ,MUNSTKERR_MASK = 0x00000008
    ,MUNSTKERR_POS = 3
    ,MUNSTKERR = 0x00000008
    // Stacking from exception has caused one or more access violations. (bits: 4)
    ,MSTKERR_MASK = 0x00000010
    ,MSTKERR_POS = 4
    ,MSTKERR = 0x00000010
    // Memory Manage Address Register (MMAR) address valid flag (bits: 7)
    ,MMARVALID_MASK = 0x00000080
    ,MMARVALID_POS = 7
    ,MMARVALID = 0x00000080
    ,MMFSR_MASK = 0x0000009B
    ;
  };
  // Bus Fault Status Register
  struct BFSR : reg<base + 0xD29, 0x00000000, 1, 8>
  {
    static constexpr typename BFSR::type
    // Instruction bus error flag. (bits: 0)
     IBUSERR_MASK = 0x00000001
    ,IBUSERR_POS = 0
    ,IBUSERR = 0x00000001
    // Precise data bus error return. (bits: 1)
    ,PRECISERR_MASK = 0x00000002
    ,PRECISERR_POS = 1
    ,PRECISERR = 0x00000002
    // Imprecise data bus error. (bits: 2)
    ,IMPRECISERR_MASK = 0x00000004
    ,IMPRECISERR_POS = 2
    ,IMPRECISERR = 0x00000004
    // Unstack from exception return has caused one or more bus faults. (bits: 3)
    ,UNSTKERR_MASK = 0x00000008
    ,UNSTKERR_POS = 3
    ,UNSTKERR = 0x00000008
    // Stacking from exception has caused one or more bus faults. (bits: 4)
    ,STKERR_MASK = 0x00000010
    ,STKERR_POS = 4
    ,STKERR = 0x00000010
    // This bit is set if the Bus Fault Address Register (BFAR) contains a valid address. (bits: 7)
    ,BFARVALID_MASK = 0x00000080
    ,BFARVALID_POS = 7
    ,BFARVALID = 0x00000080
    ,BFSR_MASK = 0x0000009F
    ;
  };
  // Usage Fault Status Register
  struct UFSR : reg<base + 0xD2B, 0x00000000, 1, 16>
  {
    static constexpr typename UFSR::type
    // The UNDEFINSTR flag is set when the processor attempts to execute an undefined instruction. (bits: 0)
     UNDEFINSTR_MASK = 0x00000001
    ,UNDEFINSTR_POS = 0
    ,UNDEFINSTR = 0x00000001
    // Invalid combination of EPSR and instruction, for reasons other than UNDEFINED instruction. (bits: 1)
    ,INVSTATE_MASK = 0x00000002
    ,INVSTATE_POS = 1
    ,INVSTATE = 0x00000002
    // Attempt to load EXC_RETURN into PC illegally. (bits: 2)
    ,INVPC_MASK = 0x00000004
    ,INVPC_POS = 2
    ,INVPC = 0x00000004
    // Attempt to use a coprocessor instruction. (bits: 3)
    ,NOCP_MASK = 0x00000008
    ,NOCP_POS = 3
    ,NOCP = 0x00000008
    // When UNALIGN_TRP is enabled, and there is an attempt to make an unaligned memory access, then this fault occurs. (bits: 8)
    ,UNALIGNED_MASK = 0x00000100
    ,UNALIGNED_POS = 8
    ,UNALIGNED = 0x00000100
    // When DIV_0_TRP (see Configuration Control Register on page 8-25) is enabled and an SDIV or UDIV instruction is used with a divisor of 0, this fault occurs. (bits: 9)
    ,DIVBYZERO_MASK = 0x00000200
    ,DIVBYZERO_POS = 9
    ,DIVBYZERO = 0x00000200
    ,UFSR_MASK = 0x0000030F
    ;
  };
  // Hard Fault Status Register
  struct HFSR : reg<base + 0xD2C>
  {
    static constexpr typename HFSR::type
    // This bit is set if there is a fault because of vector table read on exception processing (Bus Fault). (bits: 1)
     VECTTBL_MASK = 0x00000002
    ,VECTTBL_POS = 1
    ,VECTTBL = 0x00000002
    // Hard Fault activated because a Configurable Fault was received and cannot activate because of priority or because the Configurable Fault is disabled. (bits: 30)
    ,FORCED_MASK = 0x40000000
    ,FORCED_POS = 30
    ,FORCED = 0x40000000
    // This bit is set if there is a fault related to debug. (bits: 31)
    ,DEBUGEVT_MASK = 0x80000000
    ,DEBUGEVT_POS = 31
    ,DEBUGEVT = 0x80000000
    ,HFSR_MASK = 0xC0000002
    ;
  };
  // Debug Fault Status Register
  struct DFSR : reg<base + 0xD30>
  {
    static constexpr typename DFSR::type
    // Halt request flag (bits: 0)
     HALTED_MASK = 0x00000001
    ,HALTED_POS = 0
    ,HALTED = 0x00000001
    // BKPT flag (bits: 1)
    ,BKPT_MASK = 0x00000002
    ,BKPT_POS = 1
    ,BKPT = 0x00000002
    // Data Watchpoint and Trace (DWT) flag (bits: 2)
    ,DWTTRAP_MASK = 0x00000004
    ,DWTTRAP_POS = 2
    ,DWTTRAP = 0x00000004
    // Vector catch flag (bits: 3)
    ,VCATCH_MASK = 0x00000008
    ,VCATCH_POS = 3
    ,VCATCH = 0x00000008
    // External debug request flag (bits: 4)
    ,EXTERNAL_MASK = 0x00000010
    ,EXTERNAL_POS = 4
    ,EXTERNAL = 0x00000010
    ,DFSR_MASK = 0x0000001F
    ;
  };
  // Memory Manage Fault Address Register
  using MMFAR = reg<base + 0xD34>;
  // Bus Fault Address Register
  using BFAR = reg<base + 0xD38>;
  // Auxiliary Fault Status Register
  using AFSR = reg<base + 0xD3C>;
  // Software Trigger Interrupt Register
  struct STIR : reg<base + 0xF00>
  {
    static constexpr typename STIR::type
    // Interrupt ID field. (bits: 8-0)
     INTID_MASK = 0x000001FF
    ,INTID_POS = 0
    ,STIR_MASK = 0x000001FF
    ;
  };
}; // struct NVIC

} // namespace lmcu::device

