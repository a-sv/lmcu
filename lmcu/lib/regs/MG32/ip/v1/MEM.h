/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// Internal Memory Controller
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct MEM
{
  static constexpr auto ip_ver = ip_version::_1;

  // MEM status register
  struct STA : reg<ip_ver, base + 0x0>
  {
    static constexpr typename STA::type
    // IAP Flash memory size setting error flag (bits: 16)
     IAPSEF_MASK = 0x00010000
    ,IAPSEF_POS = 16
    ,IAPSEF_NORMAL = 0x00000000 // Not busy
    ,IAPSEF_ERR = 0x00010000 // Size over maximum value error
    // Flash memory read protect error detection flag (bits: 6)
    ,RPEF_MASK = 0x00000040
    ,RPEF_POS = 6
    ,RPEF_NORMAL = 0x00000000 // No event occurred
    ,RPEF_HAPPENED = 0x00000040 // reset event happened
    // Flash memory write protect error detection flag (bits: 5)
    ,WPEF_MASK = 0x00000020
    ,WPEF_POS = 5
    ,WPEF_NORMAL = 0x00000000 // No event occurred
    ,WPEF_HAPPENED = 0x00000020 // reset event happened
    // Memory code execution illegal address error detection flag (bits: 4)
    ,IAEF_MASK = 0x00000010
    ,IAEF_POS = 4
    ,IAEF_NORMAL = 0x00000000 // No event occurred
    ,IAEF_HAPPENED = 0x00000010 // reset event happened
    // Flash memory end of processing flag (bits: 1)
    ,EOPF_MASK = 0x00000002
    ,EOPF_POS = 1
    ,EOPF_NORMAL = 0x00000000 // No event occurred
    ,EOPF_HAPPENED = 0x00000002 // reset event happened
    // Flash memory access busy flag (bits: 0)
    ,FBUSYF_MASK = 0x00000001
    ,FBUSYF_POS = 0
    ,FBUSYF_NORMAL = 0x00000000 // Not busy
    ,FBUSYF_BUSY = 0x00000001 
    ,STA_MASK = 0x00010073
    ;
  };
  // MEM interrupt enable register
  struct INT : reg<ip_ver, base + 0x4>
  {
    static constexpr typename INT::type
    // Flash memory read protect error detection reset enable (bits: 22)
     RPE_RE_MASK = 0x00400000
    ,RPE_RE_POS = 22
    ,RPE_RE_DISABLE = 0x00000000 
    ,RPE_RE_ENABLE = 0x00400000 
    // Flash memory write protect error detection reset enable (bits: 21)
    ,WPE_RE_MASK = 0x00200000
    ,WPE_RE_POS = 21
    ,WPE_RE_DISABLE = 0x00000000 
    ,WPE_RE_ENABLE = 0x00200000 
    // Memory code execution illegal address detection reset enable (bits: 20)
    ,IAE_RE_MASK = 0x00100000
    ,IAE_RE_POS = 20
    ,IAE_RE_DISABLE = 0x00000000 
    ,IAE_RE_ENABLE = 0x00100000 
    // Flash memory read protect error detection interrupt enable (bits: 6)
    ,RPE_IE_MASK = 0x00000040
    ,RPE_IE_POS = 6
    ,RPE_IE_DISABLE = 0x00000000 
    ,RPE_IE_ENABLE = 0x00000040 
    // Flash memory write protect error detection interrupt enable (bits: 5)
    ,WPE_IE_MASK = 0x00000020
    ,WPE_IE_POS = 5
    ,WPE_IE_DISABLE = 0x00000000 
    ,WPE_IE_ENABLE = 0x00000020 
    // Memory code execution illegal address error detection interrupt enable (bits: 4)
    ,IAE_IE_MASK = 0x00000010
    ,IAE_IE_POS = 4
    ,IAE_IE_DISABLE = 0x00000000 
    ,IAE_IE_ENABLE = 0x00000010 
    // Flash memory end of processing interrupt enable (bits: 1)
    ,EOP_IE_MASK = 0x00000002
    ,EOP_IE_POS = 1
    ,EOP_IE_DISABLE = 0x00000000 
    ,EOP_IE_ENABLE = 0x00000002 
    // Memory controller interrupt all enable (bits: 0)
    ,IEA_MASK = 0x00000001
    ,IEA_POS = 0
    ,IEA_DISABLE = 0x00000000 
    ,IEA_ENABLE = 0x00000001 
    ,INT_MASK = 0x00700073
    ;
  };
  // MEM write protected key register
  struct KEY : reg<ip_ver, base + 0xC, 0x00010001>
  {
    static constexpr typename KEY::type
    // Reset key register-2 (bits: 31-16)
     KEY2_MASK = 0xFFFF0000
    ,KEY2_POS = 16
    // Reset key register (bits: 15-0)
    ,KEYVAL_MASK = 0x0000FFFF
    ,KEYVAL_POS = 0
    ,KEY_MASK = 0xFFFFFFFF
    ;
  };
  // MEM control register 0
  struct CR0 : reg<ip_ver, base + 0x10, 0x00200002>
  {
    static constexpr typename CR0::type
    // IAP memory size MEM_IAP_SIZE register access enable (bits: 21)
     IAP_AEN_MASK = 0x00200000
    ,IAP_AEN_POS = 21
    ,IAP_AEN_DISABLE = 0x00000000 // Register access lock
    ,IAP_AEN_ENABLE = 0x00200000 
    // Flash memory read high speed mode enable during reset (bits: 20)
    ,HSP_EN_MASK = 0x00100000
    ,HSP_EN_POS = 20
    ,HSP_EN_DISABLE = 0x00000000 
    ,HSP_EN_ENABLE = 0x00100000 
    // System reset memory select and memory is mapped at 0x0000 0000 (bits: 17-16)
    ,BOOT_MS_MASK = 0x00030000
    ,BOOT_MS_POS = 16
    ,BOOT_MS_APPLICATION_FLASH = 0x00000000 
    ,BOOT_MS_BOOT_FLASH = 0x00010000 
    ,BOOT_MS_EMBEDDED_SRAM = 0x00020000 
    // Flash memory read access wait state selection (bits: 13-12)
    ,FWAIT_MASK = 0x00003000
    ,FWAIT_POS = 12
    ,FWAIT_ZERO = 0x00000000 // Zero wait state if 25 MHz > CK_AHB
    ,FWAIT_ONE = 0x00001000 // One wait state if 50MHz >CK_AHB> 25 MHz
    ,FWAIT_TWO = 0x00003000 // Two wait state if 75MHz >CK_AHB> 50 MHz
    // AP/IAP flash memory access mode select (bits: 7-4)
    ,MDS_MASK = 0x000000F0
    ,MDS_POS = 4
    ,MDS_NO = 0x00000000 // No Operation
    ,MDS_WRITE = 0x00000010 // Write AP/IAP/ISPD Flash
    ,MDS_ERASE = 0x00000020 // Erase a page of AP/IAP/ISPD Flash
    // CPU hold control under flash memory access (bits: 2)
    ,HOLD_MASK = 0x00000004
    ,HOLD_POS = 2
    ,HOLD_HOLD = 0x00000000 
    ,HOLD_NORMAL = 0x00000004 
    // Flash memory data access error HardFault enable (bits: 1)
    ,HF_EN_MASK = 0x00000002
    ,HF_EN_POS = 1
    ,HF_EN_DISABLE = 0x00000000 
    ,HF_EN_ENABLE = 0x00000002 
    // Memory controller enable (bits: 0)
    ,EN_MASK = 0x00000001
    ,EN_POS = 0
    ,EN_DISABLE = 0x00000000 
    ,EN_ENABLE = 0x00000001 
    ,CR0_MASK = 0x003330F7
    ;
  };
  // MEM control register 1
  struct CR1 : reg<ip_ver, base + 0x14, 0x00000010>
  {
    static constexpr typename CR1::type
    // Flash OB0 Option-Byte memory write enable (bits: 11)
     OB_WEN_MASK = 0x00000800
    ,OB_WEN_POS = 11
    ,OB_WEN_DISABLE = 0x00000000 
    ,OB_WEN_ENABLE = 0x00000800 
    // Flash ISP Boot memory read enable for AP program (bits: 9)
    ,ISP_REN_MASK = 0x00000200
    ,ISP_REN_POS = 9
    ,ISP_REN_DISABLE = 0x00000000 
    ,ISP_REN_ENABLE = 0x00000200 
    // Flash ISP Boot memory write enable (bits: 8)
    ,ISP_WEN_MASK = 0x00000100
    ,ISP_WEN_POS = 8
    ,ISP_WEN_DISABLE = 0x00000000 
    ,ISP_WEN_ENABLE = 0x00000100 
    // Flash IAP data memory code execution function enable (bits: 4)
    ,IAP_EXEC_MASK = 0x00000010
    ,IAP_EXEC_POS = 4
    ,IAP_EXEC_DISABLE = 0x00000000 
    ,IAP_EXEC_ENABLE = 0x00000010 
    // Flash ISP data memory read enable for ISP program (bits: 3)
    ,ISPD_REN_MASK = 0x00000008
    ,ISPD_REN_POS = 3
    ,ISPD_REN_DISABLE = 0x00000000 
    ,ISPD_REN_ENABLE = 0x00000008 
    // Flash ISP data memory write enable for ISP program (bits: 2)
    ,ISPD_WEN_MASK = 0x00000004
    ,ISPD_WEN_POS = 2
    ,ISPD_WEN_DISABLE = 0x00000000 
    ,ISPD_WEN_ENABLE = 0x00000004 
    // Flash IAP memory write enable (bits: 1)
    ,IAP_WEN_MASK = 0x00000002
    ,IAP_WEN_POS = 1
    ,IAP_WEN_DISABLE = 0x00000000 
    ,IAP_WEN_ENABLE = 0x00000002 
    // Flash AP memory write enable (bits: 0)
    ,AP_WEN_MASK = 0x00000001
    ,AP_WEN_POS = 0
    ,AP_WEN_DISABLE = 0x00000000 
    ,AP_WEN_ENABLE = 0x00000001 
    ,CR1_MASK = 0x00000B1F
    ;
  };
  // MEM Flash memory protected key register
  struct SKEY : reg<ip_ver, base + 0x1C, 0x00000007>
  {
    static constexpr typename SKEY::type
    // Reserved. for internal using (bits: 31-16)
     SKEY2_MASK = 0xFFFF0000
    ,SKEY2_POS = 16
    // MEM sequential key register for AP/IAP/ISPD flash (bits: 7-0)
    ,SKEYVAL_MASK = 0x000000FF
    ,SKEYVAL_POS = 0
    ,SKEY_MASK = 0xFFFF00FF
    ;
  };
  // MEM Flash memory address register
  struct FADR : reg<ip_ver, base + 0x20>
  {
    static constexpr typename FADR::type
    // Flash memory access address register (bits: 31-0)
     FADRVAL_MASK = 0xFFFFFFFF
    ,FADRVAL_POS = 0
    ,FADR_MASK = 0xFFFFFFFF
    ;
  };
  // MEM Flash memory data register
  struct FDAT : reg<ip_ver, base + 0x24>
  {
    static constexpr typename FDAT::type
    // Flash memory access data register (bits: 31-0)
     FDATVAL_MASK = 0xFFFFFFFF
    ,FDATVAL_POS = 0
    ,FDAT_MASK = 0xFFFFFFFF
    ;
  };
  // MEM Flash memory IAP size register
  struct IAPSZ : reg<ip_ver, base + 0x28>
  {
    static constexpr typename IAPSZ::type
    // IAP memory size select (bits: 15-8)
     IAP_SIZE_MASK = 0x0000FF00
    ,IAP_SIZE_POS = 8
    ,IAPSZ_MASK = 0x0000FF00
    ;
  };
  // MEM manufacturer control register
  struct MCR : reg<ip_ver, base + 0x2C>
  {
    static constexpr typename MCR::type
    // Flash OB1 Option-Byte memory write enable (bits: 0)
     OB1_WEN_MASK = 0x00000001
    ,OB1_WEN_POS = 0
    ,OB1_WEN_DISABLE = 0x00000000 
    ,OB1_WEN_ENABLE = 0x00000001 
    ,MCR_MASK = 0x00000001
    ;
  };
}; // struct MEM

} // namespace lmcu::device::ip::v1

