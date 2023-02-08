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
  using CPUID = reg<ip_ver, base + 0x0>;
  // Interrupt Control and State Register (R/W)
  using ICSR = reg<ip_ver, base + 0x4>;
  // Vector Table Offset Register (R/W)
  using VTOR = reg<ip_ver, base + 0x8>;
  // Application Interrupt and Reset Control Register (R/W)
  using AIRCR = reg<ip_ver, base + 0xC>;
  // System Control Register (R/W)
  using SCR = reg<ip_ver, base + 0x10>;
  // Configuration Control Register (R/W)
  using CCR = reg<ip_ver, base + 0x14>;
  // System Handlers Priority Registers (4-7, 8-11, 12-15) (R/W) (count: 12)
  using SHPR = reg<ip_ver, base + 0x18, 0x00000000, 12, 8>;
  // System Handler Control and State Register (R/W)
  using SHCSR = reg<ip_ver, base + 0x24>;
  // Configurable Fault Status Register (R/W)
  using CFSR = reg<ip_ver, base + 0x28>;
  // HardFault Status Register (R/W)
  using HFSR = reg<ip_ver, base + 0x2C>;
  // Debug Fault Status Register (R/W)
  using DFSR = reg<ip_ver, base + 0x30>;
  // MemManage Fault Address Register (R/W)
  using MMFAR = reg<ip_ver, base + 0x34>;
  // BusFault Address Register (R/W)
  using BFAR = reg<ip_ver, base + 0x38>;
  // Auxiliary Fault Status Register (R/W)
  using AFSR = reg<ip_ver, base + 0x3C>;
  // Processor Feature Register (R/ ) (count: 2)
  using ID_PFR = reg<ip_ver, base + 0x40, 0x00000000, 2>;
  // Debug Feature Register (R/ )
  using ID_DFR = reg<ip_ver, base + 0x48>;
  // Auxiliary Feature Register (R/ )
  using ID_AFR = reg<ip_ver, base + 0x4C>;
  // Memory Model Feature Register (R/ ) (count: 4)
  using ID_MFR = reg<ip_ver, base + 0x50, 0x00000000, 4>;
  // Instruction Set Attributes Register (R/ ) (count: 5)
  using ID_ISAR = reg<ip_ver, base + 0x60, 0x00000000, 5>;
  // Cache Level ID register (R/ )
  using CLIDR = reg<ip_ver, base + 0x78>;
  // Cache Type register (R/ )
  using CTR = reg<ip_ver, base + 0x7C>;
  // Cache Size ID Register (R/ )
  using CCSIDR = reg<ip_ver, base + 0x80>;
  // Cache Size Selection Register (R/W)
  using CSSELR = reg<ip_ver, base + 0x84>;
  // Coprocessor Access Control Register (R/W)
  using CPACR = reg<ip_ver, base + 0x88>;
  // Software Triggered Interrupt Register ( /W)
  using STIR = reg<ip_ver, base + 0x200>;
  // Media and VFP Feature Register 0 (R/ )
  using MVFR0 = reg<ip_ver, base + 0x240>;
  // Media and VFP Feature Register 1 (R/ )
  using MVFR1 = reg<ip_ver, base + 0x244>;
  // Media and VFP Feature Register 1 (R/ )
  using MVFR2 = reg<ip_ver, base + 0x248>;
  // I-Cache Invalidate All to PoU ( /W)
  using ICIALLU = reg<ip_ver, base + 0x250>;
  // I-Cache Invalidate by MVA to PoU ( /W)
  using ICIMVAU = reg<ip_ver, base + 0x258>;
  // D-Cache Invalidate by MVA to PoC ( /W)
  using DCIMVAC = reg<ip_ver, base + 0x25C>;
  // D-Cache Invalidate by Set-way ( /W)
  using DCISW = reg<ip_ver, base + 0x260>;
  // D-Cache Clean by MVA to PoU ( /W)
  using DCCMVAU = reg<ip_ver, base + 0x264>;
  // D-Cache Clean by MVA to PoC ( /W)
  using DCCMVAC = reg<ip_ver, base + 0x268>;
  // D-Cache Clean by Set-way ( /W)
  using DCCSW = reg<ip_ver, base + 0x26C>;
  // D-Cache Clean and Invalidate by MVA to PoC ( /W)
  using DCCIMVAC = reg<ip_ver, base + 0x270>;
  // D-Cache Clean and Invalidate by Set-way ( /W)
  using DCCISW = reg<ip_ver, base + 0x274>;
  // Instruction Tightly-Coupled Memory Control Register (R/W)
  using ITCMCR = reg<ip_ver, base + 0x290>;
  // Data Tightly-Coupled Memory Control Registers (R/W)
  using DTCMCR = reg<ip_ver, base + 0x294>;
  // AHBP Control Register (R/W)
  using AHBPCR = reg<ip_ver, base + 0x298>;
  // L1 Cache Control Register (R/W)
  using CACR = reg<ip_ver, base + 0x29C>;
  // AHB Slave Control Register (R/W)
  using AHBSCR = reg<ip_ver, base + 0x2A0>;
  // Auxiliary Bus Fault Status Register (R/W)
  using ABFSR = reg<ip_ver, base + 0x2A8>;
}; // struct SCB

} // namespace lmcu::device

