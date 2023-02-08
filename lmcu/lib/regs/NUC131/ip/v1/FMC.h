/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// FMC Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct FMC
{
  static constexpr auto ip_ver = ip_version::_1;

  // ISP Control Register
  struct ISPCON : reg<ip_ver, base + 0x0>
  {
    static constexpr typename ISPCON::type
    // ISP Enable Control (Write Protect ) ISP function enable bit. Set this bit to enable ISP function. (bits: 0)
     ISPEN_MASK = 0x00000001
    ,ISPEN_POS = 0
    ,ISPEN_0 = 0x00000000 // ISP function Disabled
    ,ISPEN_1 = 0x00000001 // ISP function Enabled
    // Boot Select (Write Protect ) Set/clear this bit to select next booting from LDROM/APROM, respectively. This bit also functions as chip booting status flag, which can be used to check where chip booted from. This bit is initiated with the inversed value of CBS in CONFIG0 after any reset is happened except CPU reset (RSTS_CPU is 1) or system reset (RSTS_SYS) is happened. (bits: 1)
    ,BS_MASK = 0x00000002
    ,BS_POS = 1
    ,BS_0 = 0x00000000 // Boot from APROM
    ,BS_1 = 0x00000002 // Boot from LDROM
    // APROM Update Enable Control (Write Protect) (bits: 3)
    ,APUEN_MASK = 0x00000008
    ,APUEN_POS = 3
    ,APUEN_0 = 0x00000000 // APROM cannot be updated when chip runs in APROM
    ,APUEN_1 = 0x00000008 // APROM can be updated when chip runs in APROM
    // Enable Config Update By ISP (Write Protect) (bits: 4)
    ,CFGUEN_MASK = 0x00000010
    ,CFGUEN_POS = 4
    ,CFGUEN_0 = 0x00000000 // ISP update config-bit Disabled
    ,CFGUEN_1 = 0x00000010 // ISP update config-bit Enabled
    // LDROM Update Enable Control (Write Protect) (bits: 5)
    ,LDUEN_MASK = 0x00000020
    ,LDUEN_POS = 5
    ,LDUEN_0 = 0x00000000 // LDROM cannot be updated
    ,LDUEN_1 = 0x00000020 // LDROM can be updated when chip runs in APROM
    // ISP Fail Flag (Write Protect) This bit is set by hardware when a triggered ISP meets any of the following conditions: (1) APROM writes to itself if APUEN is set to 0. (2) LDROM writes to itself if LDUEN is set to 0. (3) CONFIG is erased/programmed if CFGUEN is set to 0. (4) Destination address is illegal, such as over an available range. Write 1 to clear to this bit to 0. (bits: 6)
    ,ISPFF_MASK = 0x00000040
    ,ISPFF_POS = 6
    ,ISPFF = 0x00000040
    ,ISPCON_MASK = 0x0000007B
    ;
  };
  // ISP Address Register
  struct ISPADR : reg<ip_ver, base + 0x4>
  {
    static constexpr typename ISPADR::type
    // ISP Address The NuMicro( NUC131 series has a maximum of 17Kx32 (68 KB) embedded Flash, which supports word program only. ISPADR[1:0] must be kept 00b for ISP operation. (bits: 31-0)
     ISPADRVAL_MASK = 0xFFFFFFFF
    ,ISPADRVAL_POS = 0
    ,ISPADR_MASK = 0xFFFFFFFF
    ;
  };
  // ISP Data Register
  struct ISPDAT : reg<ip_ver, base + 0x8>
  {
    static constexpr typename ISPDAT::type
    // ISP Data Write data to this register before ISP program operation. Read data from this register after ISP read operation. (bits: 31-0)
     ISPDATVAL_MASK = 0xFFFFFFFF
    ,ISPDATVAL_POS = 0
    ,ISPDAT_MASK = 0xFFFFFFFF
    ;
  };
  // ISP Command Register
  struct ISPCMD : reg<ip_ver, base + 0xC>
  {
    static constexpr typename ISPCMD::type
    // ISP Command ISP command table is shown below: (bits: 5-0)
     ISPCMDVAL_MASK = 0x0000003F
    ,ISPCMDVAL_POS = 0
    ,ISPCMDVAL_0 = 0x00000000 // Read
    ,ISPCMDVAL_4 = 0x00000004 // Read Unique ID
    ,ISPCMDVAL_11 = 0x0000000B // Read Company ID (0xDA)
    ,ISPCMDVAL_33 = 0x00000021 // Program
    ,ISPCMDVAL_34 = 0x00000022 // Page Erase
    ,ISPCMDVAL_46 = 0x0000002E // Set Vector Page Re-Map
    ,ISPCMD_MASK = 0x0000003F
    ;
  };
  // ISP Trigger Control Register
  struct ISPTRG : reg<ip_ver, base + 0x10>
  {
    static constexpr typename ISPTRG::type
    // ISP Start Trigger (Write Protect) Write 1 to start ISP operation and this bit will be cleared to 0 by hardware automatically when ISP operation is finished. This bit is the protected bit, It means programming this bit needs to write <59h>, <16h>, <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 0)
     ISPGO_MASK = 0x00000001
    ,ISPGO_POS = 0
    ,ISPGO_0 = 0x00000000 // ISP operation finished
    ,ISPGO_1 = 0x00000001 // ISP is in progress
    ,ISPTRG_MASK = 0x00000001
    ;
  };
  // Data Flash Base Address
  struct DFBADR : reg<ip_ver, base + 0x14>
  {
    static constexpr typename DFBADR::type
    // Data Flash Base Address This register indicates Data Flash start address. It is read only. When DFVSEN is set to 0, the data flash is shared with APROM. The data flash size is defined by user configuration and the content of this register is loaded from Config1. When DFVSEN is set to 1, the data flash size is fixed as 4K and the start address can be read from this register is fixed at 0x0001_F000. (bits: 31-0)
     DFBADRVAL_MASK = 0xFFFFFFFF
    ,DFBADRVAL_POS = 0
    ,DFBADR_MASK = 0xFFFFFFFF
    ;
  };
  // Flash Access Time Control Register
  struct FATCON : reg<ip_ver, base + 0x18>
  {
    static constexpr typename FATCON::type
    // Chip Frequency Optimization Mode Select 0 (Write-Protection Bit) When CPU frequency is lower than 25 MHz, user can modify flash access delay cycle by FOMSEL1 and FOMSEL0 to improve system performance. (bits: 4)
     FOMSEL0_MASK = 0x00000010
    ,FOMSEL0_POS = 4
    ,FOMSEL0 = 0x00000010
    // Chip Frequency Optimization Mode Select1 (Write-protection Bit) (bits: 6)
    ,FOMSEL1_MASK = 0x00000040
    ,FOMSEL1_POS = 6
    ,FOMSEL1 = 0x00000040
    ,FATCON_MASK = 0x00000050
    ;
  };
  // ISP Status Register
  struct ISPSTA : reg<ip_ver, base + 0x40>
  {
    static constexpr typename ISPSTA::type
    // ISP Start Trigger (Read Only) Write 1 to start ISP operation and this bit will be cleared to 0 by hardware automatically when ISP operation is finished. Note: This bit is the same as ISPTRG bit0. (bits: 0)
     ISPGO_MASK = 0x00000001
    ,ISPGO_POS = 0
    ,ISPGO_0 = 0x00000000 // ISP operation finished
    ,ISPGO_1 = 0x00000001 // ISP operation progressed
    // Chip Boot Selection (Read Only) This is a mirror of CBS in CONFIG0. (bits: 2-1)
    ,CBS_MASK = 0x00000006
    ,CBS_POS = 1
    // ISP Fail Flag (Write-Protection Bit) This bit is set by hardware when a triggered ISP meets any of the following conditions: (1) APROM writes to itself (2) LDROM writes to itself (3) CONFIG is erased/programmed if CFGUEN is set to 0 (4) Destination address is illegal, such as over an available range Write 1 to clear this bit. Note: The function of this bit is the same as ISPCON bit6. (bits: 6)
    ,ISPFF_MASK = 0x00000040
    ,ISPFF_POS = 6
    ,ISPFF = 0x00000040
    // Vector Page Mapping Address (Read Only) The current flash address space 0x0000_0000~0x0000_01FF is mapping to address {VECMAP[11:0], 9'h000} ~ {VECMAP[11:0], 9'h1FF}. (bits: 20-9)
    ,VECMAP_MASK = 0x001FFE00
    ,VECMAP_POS = 9
    ,ISPSTA_MASK = 0x001FFE47
    ;
  };
}; // struct FMC

} // namespace lmcu::device::ip::v1

