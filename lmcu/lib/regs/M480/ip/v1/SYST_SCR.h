/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// SYST_SCR Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct SYST_SCR
{
  static constexpr auto ip_ver = ip_version::_1;

  // SysTick Control and Status Register
  struct CTRL : reg<ip_ver, base + 0x10>
  {
    static constexpr typename CTRL::type
    // System Tick Counter Enabled (bits: 0)
     ENABLE_MASK = 0x00000001
    ,ENABLE_POS = 0
    ,ENABLE_0 = 0x00000000 // Counter Disabled
    ,ENABLE_1 = 0x00000001 // Counter will operate in a multi-shot manner
    // System Tick Interrupt Enabled (bits: 1)
    ,TICKINT_MASK = 0x00000002
    ,TICKINT_POS = 1
    ,TICKINT_0 = 0x00000000 // Counting down to 0 does not cause the SysTick exception to be pended. Software can use COUNTFLAG to determine if a count to zero has occurred
    ,TICKINT_1 = 0x00000002 // Counting down to 0 will cause the SysTick exception to be pended. Clearing the SysTick current value register by a register write in software will not cause SysTick to be pended
    // System Tick Clock Source Selection (bits: 2)
    ,CLKSRC_MASK = 0x00000004
    ,CLKSRC_POS = 2
    ,CLKSRC_0 = 0x00000000 // Clock source is the (optional) external reference clock
    ,CLKSRC_1 = 0x00000004 // Core clock used for SysTick
    // System Tick Counter Flag Returns 1 if timer counted to 0 since last time this register was read. COUNTFLAG is set by a count transition from 1 to 0. COUNTFLAG is cleared on read or by a write to the Current Value register. (bits: 16)
    ,COUNTFLAG_MASK = 0x00010000
    ,COUNTFLAG_POS = 16
    ,COUNTFLAG = 0x00010000
    ,CTRL_MASK = 0x00010007
    ;
  };
  // SysTick Reload Value Register
  struct LOAD : reg<ip_ver, base + 0x14>
  {
    static constexpr typename LOAD::type
    // System Tick Reload Value Value to load into the Current Value register when the counter reaches 0. (bits: 23-0)
     RELOAD_MASK = 0x00FFFFFF
    ,RELOAD_POS = 0
    ,LOAD_MASK = 0x00FFFFFF
    ;
  };
  // SysTick Current Value Register
  struct VAL : reg<ip_ver, base + 0x18>
  {
    static constexpr typename VAL::type
    // System Tick Current Value Current counter value. This is the value of the counter at the time it is sampled. The counter does not provide read-modify-write protection. The register is write-clear. A software write of any value will clear the register to 0. (bits: 23-0)
     CURRENT_MASK = 0x00FFFFFF
    ,CURRENT_POS = 0
    ,VAL_MASK = 0x00FFFFFF
    ;
  };
  // Interrupt Control and State Register
  struct ICSR : reg<ip_ver, base + 0xD04>
  {
    static constexpr typename ICSR::type
    // Number of the Current Active Exception (bits: 6-0)
     VECTACTIVE_MASK = 0x0000007F
    ,VECTACTIVE_POS = 0
    ,VECTACTIVE_0 = 0x00000000 // Thread mode
    // Preempted Active Exceptions Indicator Indicate whether There are Preempted Active Exceptions (bits: 11)
    ,RETTOBASE_MASK = 0x00000800
    ,RETTOBASE_POS = 11
    ,RETTOBASE_0 = 0x00000000 // there are preempted active exceptions to execute
    ,RETTOBASE_1 = 0x00000800 // there are no active exceptions, or the currently-executing exception is the only active exception
    // Number of the Highest Pended Exception Indicate the Exception Number of the Highest Priority Pending Enabled Exception The value indicated by this field includes the effect of the BASEPRI and FAULTMASK registers, but not any effect of the PRIMASK register. (bits: 17-12)
    ,VECTPENDING_MASK = 0x0003F000
    ,VECTPENDING_POS = 12
    ,VECTPENDING_0 = 0x00000000 // No pending exceptions
    // Interrupt Pending Flag, Excluding NMI and Faults (Read Only) (bits: 22)
    ,ISRPENDING_MASK = 0x00400000
    ,ISRPENDING_POS = 22
    ,ISRPENDING_0 = 0x00000000 // Interrupt not pending
    ,ISRPENDING_1 = 0x00400000 // Interrupt pending
    // Interrupt Preempt Bit (Read Only) If set, a pending exception will be serviced on exit from the debug halt state. (bits: 23)
    ,ISRPREEMPT_MASK = 0x00800000
    ,ISRPREEMPT_POS = 23
    ,ISRPREEMPT = 0x00800000
    // SysTick Exception Clear-pending Bit Write Operation: Note: This is a write only bit. To clear the PENDST bit, you must 'write 0 to PENDSTSET and write 1 to PENDSTRTC_CAL' at the same time. (bits: 25)
    ,PENDSTRTC_CAL_MASK = 0x02000000
    ,PENDSTRTC_CAL_POS = 25
    ,PENDSTRTC_CAL_0 = 0x00000000 // No effect
    ,PENDSTRTC_CAL_1 = 0x02000000 // Remove the pending state from the SysTick exception
    // SysTick Exception Set-pending Bit Write Operation: (bits: 26)
    ,PENDSTSET_MASK = 0x04000000
    ,PENDSTSET_POS = 26
    ,PENDSTSET_0 = 0x00000000 // No effect. SysTick exception is not pending
    ,PENDSTSET_1 = 0x04000000 // Change SysTick exception state to pending. SysTick exception is pending
    // PendSV Clear-pending Bit Write Operation: Note: This is a write only bit. To clear the PENDSV bit, you must 'write 0 to PENDSVSET and write 1 to PENDSVRTC_CAL' at the same time. (bits: 27)
    ,PENDSVRTC_CAL_MASK = 0x08000000
    ,PENDSVRTC_CAL_POS = 27
    ,PENDSVRTC_CAL_0 = 0x00000000 // No effect
    ,PENDSVRTC_CAL_1 = 0x08000000 // Remove the pending state from the PendSV exception
    // PendSV Set-pending Bit Write Operation: Note: Writing 1 to this bit is the only way to set the PendSV exception state to pending. (bits: 28)
    ,PENDSVSET_MASK = 0x10000000
    ,PENDSVSET_POS = 28
    ,PENDSVSET_0 = 0x00000000 // No effect. PendSV exception is not pending
    ,PENDSVSET_1 = 0x10000000 // Change PendSV exception state to pending. PendSV exception is pending
    // NMI Set-pending Bit Write Operation: Note: Because NMI is the highest-priority exception, normally the processor enters the NMI exception handler as soon as it detects a write of 1 to this bit. Entering the handler then clears this bit to 0. This means a read of this bit by the NMI exception handler returns 1 only if the NMI signal is reasserted while the processor is executing that handler. (bits: 31)
    ,NMIPENDSET_MASK = 0x80000000
    ,NMIPENDSET_POS = 31
    ,NMIPENDSET_0 = 0x00000000 // No effect. NMI exception is not pending
    ,NMIPENDSET_1 = 0x80000000 // Change NMI exception state to pending. NMI exception is pending
    ,ICSR_MASK = 0x9EC3F87F
    ;
  };
  // Application Interrupt and Reset Control Register
  struct AIRCR : reg<ip_ver, base + 0xD0C>
  {
    static constexpr typename AIRCR::type
    // Reserved. (bits: 0)
     VECTRESET_MASK = 0x00000001
    ,VECTRESET_POS = 0
    ,VECTRESET = 0x00000001
    // Exception Active Status Clear Bit Setting This Bit To 1 Will Clears All Active State Information For Fixed And Configurable Exceptions This bit is write only and can only be written when the core is halted. Note: It is the debugger's responsibility to re-initialize the stack. (bits: 1)
    ,VECTCLRACTIVE_MASK = 0x00000002
    ,VECTCLRACTIVE_POS = 1
    ,VECTCLRACTIVE = 0x00000002
    // System Reset Request Writing This Bit to 1 Will Cause A Reset Signal To Be Asserted To The Chip And Indicate A Reset Is Requested This bit is write only and self-cleared as part of the reset sequence. (bits: 2)
    ,SYSRESETREQ_MASK = 0x00000004
    ,SYSRESETREQ_POS = 2
    ,SYSRESETREQ = 0x00000004
    // Interrupt Priority Grouping This field determines the Split Of Group priority from subpriority, (bits: 10-8)
    ,PRIGROUP_MASK = 0x00000700
    ,PRIGROUP_POS = 8
    // Data Endianness (bits: 15)
    ,ENDIANNESS_MASK = 0x00008000
    ,ENDIANNESS_POS = 15
    ,ENDIANNESS_0 = 0x00000000 // Little-endian
    ,ENDIANNESS_1 = 0x00008000 // Big-endian
    // Register Access Key When writing this register, this field should be 0x05FA, otherwise the write action will be unpredictable. The VECTORKEY filed is used to prevent accidental write to this register from resetting the system or clearing of the exception status. (bits: 31-16)
    ,VECTORKEY_MASK = 0xFFFF0000
    ,VECTORKEY_POS = 16
    ,AIRCR_MASK = 0xFFFF8707
    ;
  };
  // System Control Register
  struct SCR : reg<ip_ver, base + 0xD10>
  {
    static constexpr typename SCR::type
    // Sleep-on-exit Enable Control This bit indicate Sleep-On-Exit when Returning from Handler Mode to Thread Mode. Setting this bit to 1 enables an interrupt driven application to avoid returning to an empty main application. (bits: 1)
     SLEEPONEXIT_MASK = 0x00000002
    ,SLEEPONEXIT_POS = 1
    ,SLEEPONEXIT_0 = 0x00000000 // Do not sleep when returning to Thread mode
    ,SLEEPONEXIT_1 = 0x00000002 // Enter sleep, or deep sleep, on return from an ISR to Thread mode
    // Processor Deep Sleep and Sleep Mode Selection Control whether the Processor Uses Sleep Or Deep Sleep as its Low Power Mode. (bits: 2)
    ,SLEEPDEEP_MASK = 0x00000004
    ,SLEEPDEEP_POS = 2
    ,SLEEPDEEP_0 = 0x00000000 // Sleep
    ,SLEEPDEEP_1 = 0x00000004 // Deep sleep
    // Send Event on Pending When an event or interrupt enters pending state, the event signal wakes up the processor from WFE. If the processor is not waiting for an event, the event is registered and affects the next WFE. The processor also wakes up on execution of an SEV instruction or an external event. (bits: 4)
    ,SEVONPEND_MASK = 0x00000010
    ,SEVONPEND_POS = 4
    ,SEVONPEND_0 = 0x00000000 // Only enabled interrupts or events can wake up the processor, while disabled interrupts are excluded
    ,SEVONPEND_1 = 0x00000010 // Enabled events and all interrupts, including disabled interrupts, can wake up the processor
    ,SCR_MASK = 0x00000016
    ;
  };
  // System Handler Priority Register 1
  struct SHPR1 : reg<ip_ver, base + 0xD18>
  {
    static constexpr typename SHPR1::type
    // Priority of system handler 4, MemManage (bits: 7-4)
     PRI_4_MASK = 0x000000F0
    ,PRI_4_POS = 4
    // Priority of system handler 5, BusFault (bits: 15-12)
    ,PRI_5_MASK = 0x0000F000
    ,PRI_5_POS = 12
    // Priority of system handler 6, UsageFault (bits: 23-20)
    ,PRI_6_MASK = 0x00F00000
    ,PRI_6_POS = 20
    ,SHPR1_MASK = 0x00F0F0F0
    ;
  };
  // System Handler Priority Register 2
  struct SHPR2 : reg<ip_ver, base + 0xD1C>
  {
    static constexpr typename SHPR2::type
    // Priority of System Handler 11 - SVCall '0' denotes the highest priority and '3' denotes the lowest priority. (bits: 31-28)
     PRI_11_MASK = 0xF0000000
    ,PRI_11_POS = 28
    ,SHPR2_MASK = 0xF0000000
    ;
  };
  // System Handler Priority Register 3
  struct SHPR3 : reg<ip_ver, base + 0xD20>
  {
    static constexpr typename SHPR3::type
    // Priority of System Handler 14 - PendSV '0' denotes the highest priority and '3' denotes the lowest priority. (bits: 23-20)
     PRI_14_MASK = 0x00F00000
    ,PRI_14_POS = 20
    // Priority of System Handler 15 - SysTick '0' denotes the highest priority and '3' denotes the lowest priority. (bits: 31-28)
    ,PRI_15_MASK = 0xF0000000
    ,PRI_15_POS = 28
    ,SHPR3_MASK = 0xF0F00000
    ;
  };
}; // struct SYST_SCR

} // namespace lmcu::device::ip::v1

