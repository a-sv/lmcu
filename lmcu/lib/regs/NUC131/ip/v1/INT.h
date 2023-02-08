/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// INT Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct INT
{
  static constexpr auto ip_ver = ip_version::_1;

  // Reserved
  using SRC = reg<ip_ver, base + 0x7C>;
  // NMI Source Interrupt Select Control Register
  struct SEL : reg<ip_ver, base + 0x80>
  {
    static constexpr typename SEL::type
    // NMI Interrupt Source Selection The NMI interrupt to Cortex-M0 can be selected from one of the peripheral interrupt by setting NMI_SEL. (bits: 4-0)
     NMI_SEL_MASK = 0x0000001F
    ,NMI_SEL_POS = 0
    // NMI Interrupt Enable Control (Write Protect) Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 8)
    ,NMI_EN_MASK = 0x00000100
    ,NMI_EN_POS = 8
    ,NMI_EN_0 = 0x00000000 // NMI interrupt Disabled
    ,NMI_EN_1 = 0x00000100 // NMI interrupt Enabled
    ,SEL_MASK = 0x0000011F
    ;
  };
  // MCU Interrupt Request Source Register
  struct IRQ : reg<ip_ver, base + 0x84>
  {
    static constexpr typename IRQ::type
    // MCU IRQ Source Register The MCU_IRQ collects all the interrupts from the peripherals and generates the synchronous interrupt to Cortex-M0. There are two modes to generate interrupt to Cortex-M0, the normal mode and test mode. The MCU_IRQ collects all interrupts from each peripheral and synchronizes them and interrupts the Cortex-M0. When the MCU_IRQ[n] is 0: Set MCU_IRQ[n] 1 will generate an interrupt to Cortex-M0 NVIC[n]. When the MCU_IRQ[n] is 1 (mean an interrupt is assert), setting 1 to the MCU_IRQ[n] 1 will clear the interrupt and setting MCU_IRQ[n] 0: has no effect. (bits: 31-0)
     MCU_IRQ_MASK = 0xFFFFFFFF
    ,MCU_IRQ_POS = 0
    ,IRQ_MASK = 0xFFFFFFFF
    ;
  };
  // MCU Interrupt Request Control Register
  struct IRQCR : reg<ip_ver, base + 0x88>
  {
    static constexpr typename IRQCR::type
    // Fast IRQ Latency Enable Control (bits: 0)
     FAST_IRQ_MASK = 0x00000001
    ,FAST_IRQ_POS = 0
    ,FAST_IRQ_0 = 0x00000000 // MCU IRQ latency is fixed at 13 clock cycles of HCLK, MCU will enter IRQ handler after this fixed latency when interrupt happened
    ,FAST_IRQ_1 = 0x00000001 // MCU IRQ latency will not fixed, MCU will enter IRQ handler as soon as possible when interrupt happened
    ,IRQCR_MASK = 0x00000001
    ;
  };
}; // struct INT

} // namespace lmcu::device::ip::v1

