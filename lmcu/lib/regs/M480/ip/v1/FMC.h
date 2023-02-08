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
  struct ISPCTL : reg<ip_ver, base + 0x0>
  {
    static constexpr typename ISPCTL::type
    // ISP Enable Bit (Write Protect) ISP function enable bit. Set this bit to enable ISP function. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     ISPEN_MASK = 0x00000001
    ,ISPEN_POS = 0
    ,ISPEN_0 = 0x00000000 // ISP function Disabled
    ,ISPEN_1 = 0x00000001 // ISP function Enabled
    // Boot Select (Write Protect) When MBS in CONFIG0 is 1, set/clear this bit to select next booting from LDROM/APROM, respectively. This bit also functions as chip booting status flag, which can be used to check where chip booted from. This bit is initiated with the inversed value of CBS[1] (CONFIG0[7]) after any reset is happened except CPU reset (CPU is 1) or system reset (SYS) is happened Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 1)
    ,BS_MASK = 0x00000002
    ,BS_POS = 1
    ,BS_0 = 0x00000000 // Boot from APROM when MBS (CONFIG0[5]) is 1
    ,BS_1 = 0x00000002 // Boot from LDROM when MBS (CONFIG0[5]) is 1
    // APROM Update Enable Bit (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 3)
    ,APUEN_MASK = 0x00000008
    ,APUEN_POS = 3
    ,APUEN_0 = 0x00000000 // APROM cannot be updated when the chip runs in APROM
    ,APUEN_1 = 0x00000008 // APROM can be updated when the chip runs in APROM
    // CONFIG Update Enable Bit (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 4)
    ,CFGUEN_MASK = 0x00000010
    ,CFGUEN_POS = 4
    ,CFGUEN_0 = 0x00000000 // CONFIG cannot be updated
    ,CFGUEN_1 = 0x00000010 // CONFIG can be updated
    // LDROM Update Enable Bit (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 5)
    ,LDUEN_MASK = 0x00000020
    ,LDUEN_POS = 5
    ,LDUEN_0 = 0x00000000 // LDROM cannot be updated
    ,LDUEN_1 = 0x00000020 // LDROM can be updated
    // ISP Fail Flag (Write Protect) This bit is set by hardware when a triggered ISP meets any of the following conditions: This bit needs to be cleared by writing 1 to it. APROM writes to itself if APUEN is set to 0. APROM(except for Data Flash) is erased/programmed if KEYLOCK is 1 LDROM writes to itself if LDUEN is set to 0. LDROM is erased/programmed if KEYLOCK is set to 1 CONFIG is erased/programmed if CFGUEN is set to 0. CONFIG is erased/programmed if KEYLOCK is set to 1 and KEYENROM[1:0] are 1 KPROM is erased/programmed if KEYLOCK is set to 1 Erase or Program command at brown-out detected Destination address is illegal, such as over an available range. Invalid ISP commands Page Erase command at LOCK mode with ICE connection Invalid operations (except for chip erase) with ICE connection if SBLOCK is not 0x5A Read any content of boot loader with ICE connection The base and size of new XOM regsions is wrong, overlap or writed twice The input setting of XOM page erase function is wrong The active XOM regsion is accessed (except for chip erase, page erase, chksum and read CID/DID) The XOM setting page is accessed (except for chip erase, word program and read) Violate the load code read protection OTP is erased, multi-word programed or 64-bit read Checksum or Flash All One Verification is not executed in their valid range Block erase or bank erase is not executed in APROM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 6)
    ,ISPFF_MASK = 0x00000040
    ,ISPFF_POS = 6
    ,ISPFF = 0x00000040
    // Boot Loader Booting (Write Protect) This bit is initiated with the inversed value of MBS (CONFIG0[5]). Any reset, except CPU reset (CPU is 1) or system reset (SYS), BL will be reloaded. This bit is used to check chip boot from Boot Loader or not. User should keep original value of this bit when updating FMC_ISPCTL register. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 16)
    ,BL_MASK = 0x00010000
    ,BL_POS = 16
    ,BL_0 = 0x00000000 // Boot from APROM or LDROM
    ,BL_1 = 0x00010000 // Boot from Boot Loader
    ,ISPCTL_MASK = 0x0001007B
    ;
  };
  // ISP Address Register
  struct ISPADDR : reg<ip_ver, base + 0x4>
  {
    static constexpr typename ISPADDR::type
    // ISP Address The M480 series is equipped with embedded Flash. ISPADDR[1:0] must be kept 00 for ISP 32-bit operation. ISPADDR[2:0] must be kept 000 for ISP 64-bit operation. For CRC32 Checksum Calculation command, this field is the Flash starting address for checksum calculation, 4 Kbytes alignment is necessary for CRC32 checksum calculation. For Flash32-bit Program, ISP address needs word alignment (4-byte). For Flash 64-bit Program, ISP address needs double word alignment (8-byte). (bits: 31-0)
     ISPADDRVAL_MASK = 0xFFFFFFFF
    ,ISPADDRVAL_POS = 0
    ,ISPADDR_MASK = 0xFFFFFFFF
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
    // ISP Command ISP command table is shown below: The other commands are invalid. (bits: 6-0)
     CMD_MASK = 0x0000007F
    ,CMD_POS = 0
    ,CMD_0 = 0x00000000 // FLASH Read
    ,CMD_4 = 0x00000004 // Read Unique ID
    ,CMD_8 = 0x00000008 // Read Flash All-One Result
    ,CMD_11 = 0x0000000B // Read Company ID
    ,CMD_12 = 0x0000000C // Read Device ID
    ,CMD_13 = 0x0000000D // Read Checksum
    ,CMD_33 = 0x00000021 // FLASH 32-bit Program
    ,CMD_34 = 0x00000022 // FLASH Page Erase. Erase any page in two banks, except for OTP
    ,CMD_35 = 0x00000023 // FLASH Bank Erase. Erase all pages of APROM in BANK0 or BANK1
    ,CMD_37 = 0x00000025 // FLASH Block Erase. Erase four pages alignment of APROM in BANK0 or BANK1
    ,CMD_39 = 0x00000027 // FLASH Multi-Word Program
    ,CMD_40 = 0x00000028 // Run Flash All-One Verification
    ,CMD_45 = 0x0000002D // Run Checksum Calculation
    ,CMD_46 = 0x0000002E // Vector Remap
    ,CMD_64 = 0x00000040 // FLASH 64-bit Read
    ,CMD_97 = 0x00000061 // FLASH 64-bit Program
    ,ISPCMD_MASK = 0x0000007F
    ;
  };
  // ISP Trigger Control Register
  struct ISPTRG : reg<ip_ver, base + 0x10>
  {
    static constexpr typename ISPTRG::type
    // ISP Start Trigger (Write Protect) Write 1 to start ISP operation and this bit will be cleared to 0 by hardware automatically when ISP operation is finished. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     ISPGO_MASK = 0x00000001
    ,ISPGO_POS = 0
    ,ISPGO_0 = 0x00000000 // ISP operation is finished
    ,ISPGO_1 = 0x00000001 // ISP is progressed
    ,ISPTRG_MASK = 0x00000001
    ;
  };
  // Data Flash Base Address
  struct DFBA : reg<ip_ver, base + 0x14>
  {
    static constexpr typename DFBA::type
    // Data Flash Base Address This register indicates Data Flash start address. It is a read only register. The Data Flash is shared with APROM. the content of this register is loaded from CONFIG1 (bits: 31-0)
     DFBAVAL_MASK = 0xFFFFFFFF
    ,DFBAVAL_POS = 0
    ,DFBA_MASK = 0xFFFFFFFF
    ;
  };
  // Flash Access Time Control Register
  struct FTCTL : reg<ip_ver, base + 0x18>
  {
    static constexpr typename FTCTL::type
    // Flash Cache Invalidation (Write Protect) Note 1: Write 1 to start cache invalidation. The value will be changed to 0 once the process finishes. Note 2: This bit is write-protected. Refer to the SYS_REGLCTL register. Note 3: When ISP is processed, the Flash Cache will be invalid. (bits: 9)
     CACHEINV_MASK = 0x00000200
    ,CACHEINV_POS = 9
    ,CACHEINV_0 = 0x00000000 // Flash Cache Invalidation finished (default)
    ,CACHEINV_1 = 0x00000200 // Flash Cache Invalidation
    ,FTCTL_MASK = 0x00000200
    ;
  };
  // ISP Status Register
  struct ISPSTS : reg<ip_ver, base + 0x40>
  {
    static constexpr typename ISPSTS::type
    // ISP Busy Flag (Read Only) Write 1 to start ISP operation and this bit will be cleared to 0 by hardware automatically when ISP operation is finished. This bit is the mirror of ISPGO(FMC_ISPTRG[0]). (bits: 0)
     ISPBUSY_MASK = 0x00000001
    ,ISPBUSY_POS = 0
    ,ISPBUSY_0 = 0x00000000 // ISP operation is finished
    ,ISPBUSY_1 = 0x00000001 // ISP is progressed
    // Boot Selection of CONFIG (Read Only) This bit is initiated with the CBS (CONFIG0[7:6]) after any reset is happened except CPU reset (CPU is 1) or system reset (SYS) is happened. (bits: 2-1)
    ,CBS_MASK = 0x00000006
    ,CBS_POS = 1
    ,CBS_0 = 0x00000000 // LDROM with IAP mode
    ,CBS_1 = 0x00000002 // LDROM without IAP mode
    ,CBS_2 = 0x00000004 // APROM with IAP mode
    ,CBS_3 = 0x00000006 // APROM without IAP mode
    // Boot From Boot Loader Selection Flag (Read Only) This bit is initiated with the MBS (CONFIG0[5]) after any reset is happened except CPU reset (CPU is 1) or system reset (SYS) is happened. (bits: 3)
    ,MBS_MASK = 0x00000008
    ,MBS_POS = 3
    ,MBS_0 = 0x00000000 // Boot from Boot Loader
    ,MBS_1 = 0x00000008 // Boot from LDROM/APROM.(.see CBS bit setting)
    // Flash Access Cycle Auto-tuning Disable Flag (Read Only) This bit is set if Flash access cycle auto-tunning function is disabled. The auto-tunning function is disabled by FADIS(FMC_CYCCTL[8]) or HIRC clock is not ready. (bits: 4)
    ,FCYCDIS_MASK = 0x00000010
    ,FCYCDIS_POS = 4
    ,FCYCDIS_0 = 0x00000000 // Flash access cycle auto-tuning Enabled
    ,FCYCDIS_1 = 0x00000010 // Flash access cyle auto-tuning Disabled
    // Flash Program with Fast Verification Flag (Read Only) This bit is set if data is mismatched at ISP programming verification. This bit is clear by performing ISP Flash erase or ISP read CID operation (bits: 5)
    ,PGFF_MASK = 0x00000020
    ,PGFF_POS = 5
    ,PGFF_0 = 0x00000000 // Flash Program is success
    ,PGFF_1 = 0x00000020 // Flash Program is fail. Program data is different with data in the Flash memory
    // ISP Fail Flag (Write Protect) This bit is the mirror of ISPFF (FMC_ISPCTL[6]), it needs to be cleared by writing 1 to FMC_ISPCTL[6] or FMC_ISPSTS[6]. This bit is set by hardware when a triggered ISP meets any of the following conditions: APROM writes to itself if APUEN is set to 0. APROM(except for Data Flash) is erased/programmed if KEYLOCK is 1 LDROM writes to itself if LDUEN is set to 0. LDROM is erased/programmed if KEYLOCK is set to 1 CONFIG is erased/programmed if CFGUEN is set to 0. CONFIG is erased/programmed if KEYLOCK is set to 1 and KEYENROM[1:0] are 1 KPROM is erased/programmed if KEYLOCK is set to 1 Erase or Program command at brown-out detected Destination address is illegal, such as over an available range. Invalid ISP commands Page Erase command at LOCK mode with ICE connection Invalid operations (except for chip erase) with ICE connection if SBLOCK is not 0x5A Read any content of boot loader with ICE connection The base and size of new XOM regsions is wrong, overlap or writed twice The input setting of XOM page erase function is wrong The active XOM regsion is accessed (except for chip erase, page erase, chksum and read CID/DID) The XOM setting page is accessed (except for chip erase, word program and read) Violate the load code read protection OTP is erased, multi-word programed or 64-bit read Checksum or Flash All One Verification is not executed in their valid range Block erase or bank erase is not executed in APROM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 6)
    ,ISPFF_MASK = 0x00000040
    ,ISPFF_POS = 6
    ,ISPFF = 0x00000040
    // Flash All-one Verification Flag This bit is set by hardware if all of Flash bits are 1, and clear if Flash bits are not all 1 after 'Run Flash All-One Verification' complete; this bit also can be clear by writing 1 (bits: 7)
    ,ALLONE_MASK = 0x00000080
    ,ALLONE_POS = 7
    ,ALLONE_0 = 0x00000000 // All of Flash bits are 1 after 'Run Flash All-One Verification' complete
    ,ALLONE_1 = 0x00000080 // Flash bits are not all 1 after 'Run Flash All-One Verification' complete
    // Vector Page Mapping Address (Read Only) All access to 0x0000_0000~0x0000_01FF is remapped to the Flash memory address {VECMAP[14:0], 9'h000} ~ {VECMAP[14:0], 9'h1FF} (bits: 23-9)
    ,VECMAP_MASK = 0x00FFFE00
    ,VECMAP_POS = 9
    ,ISPSTS_MASK = 0x00FFFEFF
    ;
  };
  // Flash Access Cycle Control Register
  struct CYCCTL : reg<ip_ver, base + 0x4C>
  {
    static constexpr typename CYCCTL::type
    // Flash Access Cycle Control (Write Protect) This register is updated automatically by hardware while FCYCDIS (FMC_ISPSTS[4]) is 0, and updated by software while auto-tuning function disabled ( FADIS (FMC_CYCTL[8]) is 1) The optimized HCLK working frequency range is 192 MHz Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 3-0)
     CYCLE_MASK = 0x0000000F
    ,CYCLE_POS = 0
    ,CYCLE_0 = 0x00000000 // CPU access with zero wait cycle ; Flash access cycle is 1;
    ,CYCLE_1 = 0x00000001 // CPU access with one wait cycle if cache miss; Flash access cycle is 1;
    ,CYCLE_2 = 0x00000002 // CPU access with two wait cycles if cache miss; Flash access cycle is 2;
    ,CYCLE_3 = 0x00000003 // CPU access with three wait cycles if cache miss; Flash access cycle is 3;
    ,CYCLE_4 = 0x00000004 // CPU access with four wait cycles if cache miss; Flash access cycle is 4;
    ,CYCLE_5 = 0x00000005 // CPU access with five wait cycles if cache miss; Flash access cycle is 5;
    ,CYCLE_6 = 0x00000006 // CPU access with six wait cycles if cache miss; Flash access cycle is 6;
    ,CYCLE_7 = 0x00000007 // CPU access with seven wait cycles if cache miss; Flash access cycle is 7;
    ,CYCLE_8 = 0x00000008 // CPU access with eight wait cycles if cache miss; Flash access cycle is 8;
    // Flash Access Cycle Auto-tuning Disable Bit (Write Protect) Set this bit to disable Flash access cycle auto-tuning function Note: This bit is write protected. Refer to the SYS_REGLCTL register. When FMC is doing auto-tuning, we considered as an ISP operation need to monitor busy flag. (bits: 8)
    ,FADIS_MASK = 0x00000100
    ,FADIS_POS = 8
    ,FADIS_0 = 0x00000000 // Flash access cycle auto-tuning Enabled
    ,FADIS_1 = 0x00000100 // Flash access cycle auto-tuning Disabled
    ,CYCCTL_MASK = 0x0000010F
    ;
  };
  // KPROM KEY0 Data Register
  struct KPKEY0 : reg<ip_ver, base + 0x50>
  {
    static constexpr typename KPKEY0::type
    // KPROM KEY0 Data (Write Only) Write KPKEY0 data to this register before KEY Comparison operation. (bits: 31-0)
     KPKEY0VAL_MASK = 0xFFFFFFFF
    ,KPKEY0VAL_POS = 0
    ,KPKEY0_MASK = 0xFFFFFFFF
    ;
  };
  // KPROM KEY1 Data Register
  struct KPKEY1 : reg<ip_ver, base + 0x54>
  {
    static constexpr typename KPKEY1::type
    // KPROM KEY1 Data (Write Only) Write KPKEY1 data to this register before KEY Comparison operation. (bits: 31-0)
     KPKEY1VAL_MASK = 0xFFFFFFFF
    ,KPKEY1VAL_POS = 0
    ,KPKEY1_MASK = 0xFFFFFFFF
    ;
  };
  // KPROM KEY2 Data Register
  struct KPKEY2 : reg<ip_ver, base + 0x58>
  {
    static constexpr typename KPKEY2::type
    // KPROM KEY2 Data (Write Only) Write KPKEY2 data to this register before KEY Comparison operation. (bits: 31-0)
     KPKEY2VAL_MASK = 0xFFFFFFFF
    ,KPKEY2VAL_POS = 0
    ,KPKEY2_MASK = 0xFFFFFFFF
    ;
  };
  // KPROM KEY Comparison Trigger Control Register
  struct KPKEYTRG : reg<ip_ver, base + 0x5C>
  {
    static constexpr typename KPKEYTRG::type
    // KPROM KEY Comparison Start Trigger (Write Protect) Write 1 to start KEY comparison operation and this bit will be cleared to 0 by hardware automatically when KEY comparison operation is finished. This trigger operation is valid while FORBID (FMC_KPKEYSTS [3]) is 0. Note: This bit is write-protected. Refer to the SYS_REGLCTL register. (bits: 0)
     KPKEYGO_MASK = 0x00000001
    ,KPKEYGO_POS = 0
    ,KPKEYGO_0 = 0x00000000 // KEY comparison operation is finished
    ,KPKEYGO_1 = 0x00000001 // KEY comparison is progressed
    // Timeout Counting Enable Bit (Write Protect) 10 minutes is at least for timeout, and average is about 20 minutes. Note: This bit is write-protected. Refer to the SYS_REGLCTL register. (bits: 1)
    ,TCEN_MASK = 0x00000002
    ,TCEN_POS = 1
    ,TCEN_0 = 0x00000000 // Timeout counting Disabled
    ,TCEN_1 = 0x00000002 // Timeout counting Enabled if input key is matched after key comparison finished
    ,KPKEYTRG_MASK = 0x00000003
    ;
  };
  // KPROM KEY Comparison Status Register
  struct KPKEYSTS : reg<ip_ver, base + 0x60>
  {
    static constexpr typename KPKEYSTS::type
    // KEY Comparison Busy (Read Only) (bits: 0)
     KEYBUSY_MASK = 0x00000001
    ,KEYBUSY_POS = 0
    ,KEYBUSY_0 = 0x00000000 // KEY comparison is finished
    ,KEYBUSY_1 = 0x00000001 // KEY comparison is busy
    // KEY LOCK Flag This bit is set to 1 if KEYMATCH (FMC_KPKEYSTS [2]) is 0 and cleared to 0 if KEYMATCH is 1 in Security Key protection. After Mass Erase operation, users must reset or power on /off to clear this bit to 0. This bit also can be set to 1 while: CPU write 1 to KEYLOCK(FMC_KPKEYSTS[1]) or KEYFLAG(FMC_KPKEYSTS[4]) is 1 at power-on or reset or KEYENROM is programmed a non-0xFF value or Timeout event or FORBID(FMC_KPKEYSTS[3]) is 1 CONFIG write protect is depended on CFGFLAG (bits: 1)
    ,KEYLOCK_MASK = 0x00000002
    ,KEYLOCK_POS = 1
    ,KEYLOCK_0 = 0x00000000 // KPROM, LDROM and APROM (not include Data Flash) is not in write protection
    ,KEYLOCK_1 = 0x00000002 // KPROM, LDROM and APROM (not include Data Flash) is in write protection
    // KEY Match Flag (Read Only) This bit is set to 1 after KEY comparison complete if the KEY0, KEY1 and KEY2 are matched with the 96-bit security keys in KPROM; and cleared to 0 if KEYs are unmatched. This bit is also cleared to 0 while CPU writing 1 to KEYLOCK(FMC_KPKEYSTS[1]) or Timeout event or KPROM is erased or KEYENROM is programmed to a non-0xFF value. Chip is in Power-down mode. (bits: 2)
    ,KEYMATCH_MASK = 0x00000004
    ,KEYMATCH_POS = 2
    ,KEYMATCH_0 = 0x00000000 // KEY0, KEY1, and KEY2 are unmatched with the KPROM setting
    ,KEYMATCH_1 = 0x00000004 // KEY0, KEY1, and KEY2 are matched with the KPROM setting
    // KEY Comparison Forbidden Flag (Read Only) This bit is set to 1 when KPKECNT(FMC_KPKEY0[4:0]) is more than KPKEMAX (FMC_KPKEY0[12:8]) or KPCNT (FMC_KPCNT [2:0]) is more than KPMAX (FMC_KPCNT [10:8]). (bits: 3)
    ,FORBID_MASK = 0x00000008
    ,FORBID_POS = 3
    ,FORBID_0 = 0x00000000 // KEY comparison is not forbidden
    ,FORBID_1 = 0x00000008 // KEY comparison is forbidden, KEYGO (FMC_KEYTRG [0]) cannot trigger
    // KEY Protection Enable Flag (Read Only) This bit is set while the KEYENROM [7:0] is not 0xFF at power-on or reset. This bit is cleared to 0 by hardware while KPROM is erased. This bit is set to 1 by hardware while KEYENROM is programmed to a non-0xFF value. (bits: 4)
    ,KEYFLAG_MASK = 0x00000010
    ,KEYFLAG_POS = 4
    ,KEYFLAG_0 = 0x00000000 // Security Key protection Disabled
    ,KEYFLAG_1 = 0x00000010 // Security Key protection Enabled
    // CONFIG Write-protection Enable Flag (Read Only) This bit is set while the KEYENROM [0] is 0 at power-on or reset. This bit is cleared to 0 by hardware while KPROM is erased. This bit is set to 1 by hardware while KEYENROM[0] is programmed to 0. (bits: 5)
    ,CFGFLAG_MASK = 0x00000020
    ,CFGFLAG_POS = 5
    ,CFGFLAG_0 = 0x00000000 // CONFIG write-protection Disabled
    ,CFGFLAG_1 = 0x00000020 // CONFIG write-protection Enabled
    ,KPKEYSTS_MASK = 0x0000003F
    ;
  };
  // KPROM KEY-unmatched Counting Register
  struct KPKEYCNT : reg<ip_ver, base + 0x64>
  {
    static constexpr typename KPKEYCNT::type
    // Error Key Entry Counter at Each Power-on (Read Only) KPKECNT is increased when entry keys is wrong in Security Key protection. KPKECNT is cleared to 0 if key comparison is matched or system power-on. (bits: 5-0)
     KPKECNT_MASK = 0x0000003F
    ,KPKECNT_POS = 0
    // Maximum Number for Error Key Entry at Each Power-on (Read Only) KPKEMAX is the maximum error key entry number at each power-on. When KPKEMAXROM of KPROM is erased or programmed, KPKEMAX will also be updated. KPKEMAX is used to limit KPKECNT(FMC_KPKEY0[5:0]) maximum counting. The FORBID (FMC_KPKEYSTS [3]) will be set to 1 when KPKECNT is more than KPKEMAX. (bits: 13-8)
    ,KPKEMAX_MASK = 0x00003F00
    ,KPKEMAX_POS = 8
    ,KPKEYCNT_MASK = 0x00003F3F
    ;
  };
  // KPROM KEY-unmatched Power-on Counting Register
  struct KPCNT : reg<ip_ver, base + 0x68>
  {
    static constexpr typename KPCNT::type
    // Power-on Counter for Error Key Entry (Read Only) KPCNT is the power-on counting for error key entry in Security Key protection. KPCNT is cleared to 0 if key comparison is matched. (bits: 3-0)
     KPCNTVAL_MASK = 0x0000000F
    ,KPCNTVAL_POS = 0
    // Power-on Maximum Number for Error Key Entry (Read Only) KPMAX is the power-on maximum number for error key entry. When KPMAXROM of KPROM is erased or programmed, KPMAX will also be updated. KPMAX is used to limit KPCNT (FMC_KPCNT [3:0]) maximum counting. The FORBID(FMC_KPKEYSTS[3]) will be set to 1 when KPCNT is more than KPMAX (bits: 11-8)
    ,KPMAX_MASK = 0x00000F00
    ,KPMAX_POS = 8
    ,KPCNT_MASK = 0x00000F0F
    ;
  };
  // ISP Data0 Register
  struct MPDAT0 : reg<ip_ver, base + 0x80>
  {
    static constexpr typename MPDAT0::type
    // ISP Data 0 This register is the first 32-bit data for 32-bit/64-bit/multi-word programming, and it is also the mirror of FMC_ISPDAT, both registers keep the same data. (bits: 31-0)
     ISPDAT0_MASK = 0xFFFFFFFF
    ,ISPDAT0_POS = 0
    ,MPDAT0_MASK = 0xFFFFFFFF
    ;
  };
  // ISP Data1 Register
  struct MPDAT1 : reg<ip_ver, base + 0x84>
  {
    static constexpr typename MPDAT1::type
    // ISP Data 1 This register is the second 32-bit data for 64-bit/multi-word programming. (bits: 31-0)
     ISPDAT1_MASK = 0xFFFFFFFF
    ,ISPDAT1_POS = 0
    ,MPDAT1_MASK = 0xFFFFFFFF
    ;
  };
  // ISP Data2 Register
  struct MPDAT2 : reg<ip_ver, base + 0x88>
  {
    static constexpr typename MPDAT2::type
    // ISP Data 2 This register is the third 32-bit data for multi-word programming. (bits: 31-0)
     ISPDAT2_MASK = 0xFFFFFFFF
    ,ISPDAT2_POS = 0
    ,MPDAT2_MASK = 0xFFFFFFFF
    ;
  };
  // ISP Data3 Register
  struct MPDAT3 : reg<ip_ver, base + 0x8C>
  {
    static constexpr typename MPDAT3::type
    // ISP Data 3 This register is the fourth 32-bit data for multi-word programming. (bits: 31-0)
     ISPDAT3_MASK = 0xFFFFFFFF
    ,ISPDAT3_POS = 0
    ,MPDAT3_MASK = 0xFFFFFFFF
    ;
  };
  // ISP Multi-program Status Register
  struct MPSTS : reg<ip_ver, base + 0xC0>
  {
    static constexpr typename MPSTS::type
    // ISP Multi-word Program Busy Flag (Read Only) Write 1 to start ISP Multi-Word program operation and this bit will be cleared to 0 by hardware automatically when ISP Multi-Word program operation is finished. This bit is the mirror of ISPGO(FMC_ISPTRG[0]). (bits: 0)
     MPBUSY_MASK = 0x00000001
    ,MPBUSY_POS = 0
    ,MPBUSY_0 = 0x00000000 // ISP Multi-Word program operation is finished
    ,MPBUSY_1 = 0x00000001 // ISP Multi-Word program operation is progressed
    // ISP Multi-program Status (Read Only) (bits: 1)
    ,PPGO_MASK = 0x00000002
    ,PPGO_POS = 1
    ,PPGO_0 = 0x00000000 // ISP multi-word program operation is not active
    ,PPGO_1 = 0x00000002 // ISP multi-word program operation is in progress
    // ISP Fail Flag (Read Only) This bit is the mirror of ISPFF (FMC_ISPCTL[6]), it needs to be cleared by writing 1 to FMC_ISPCTL[6] or FMC_ISPSTS[6]. This bit is set by hardware when a triggered ISP meets any of the following conditions: APROM writes to itself if APUEN is set to 0. APROM(except for Data Flash) is erased/programmed if KEYLOCK is 1 LDROM writes to itself if LDUEN is set to 0. LDROM is erased/programmed if KEYLOCK is set to 1 CONFIG is erased/programmed if CFGUEN is set to 0. CONFIG is erased/programmed if KEYLOCK is set to 1 and KEYENROM[1:0] are 1 KPROM is erased/programmed if KEYLOCK is set to 1 Erase or Program command at brown-out detected Destination address is illegal, such as over an available range. Invalid ISP commands Page Erase command at LOCK mode with ICE connection Invalid operations (except for chip erase) with ICE connection if SBLOCK is not 0x5A Read any content of boot loader with ICE connection The base and size of new XOM regsions is wrong, overlap or writed twice The input setting of XOM page erase function is wrong The active XOM regsion is accessed (except for chip erase, page erase, chksum and read CID/DID) The XOM setting page is accessed (except for chip erase, word program and read) Violate the load code read protection OTP is erased, multi-word programed or 64-bit read Checksum or Flash All One Verification is not executed in their valid range Block erase or bank erase is not executed in APROM (bits: 2)
    ,ISPFF_MASK = 0x00000004
    ,ISPFF_POS = 2
    ,ISPFF = 0x00000004
    // KEY Comparison Busy (Read Only) (bits: 3)
    ,KEYBUSY_MASK = 0x00000008
    ,KEYBUSY_POS = 3
    ,KEYBUSY_0 = 0x00000000 // KEY Comparison is finished
    ,KEYBUSY_1 = 0x00000008 // KEY Comparison is busy
    // ISP DATA 0 Flag (Read Only) This bit is set when FMC_MPDAT0 is written and auto-clear to 0 when the FMC_MPDAT0 data is programmed to Flash complete. (bits: 4)
    ,D0_MASK = 0x00000010
    ,D0_POS = 4
    ,D0_0 = 0x00000000 // FMC_MPDAT0 register is empty, or program to Flash complete
    ,D0_1 = 0x00000010 // FMC_MPDAT0 register has been written, and not program to Flash complete
    // ISP DATA 1 Flag (Read Only) This bit is set when FMC_MPDAT1 is written and auto-clear to 0 when the FMC_MPDAT1 data is programmed to Flash complete. (bits: 5)
    ,D1_MASK = 0x00000020
    ,D1_POS = 5
    ,D1_0 = 0x00000000 // FMC_MPDAT1 register is empty, or program to Flash complete
    ,D1_1 = 0x00000020 // FMC_MPDAT1 register has been written, and not program to Flash complete
    // ISP DATA 2 Flag (Read Only) This bit is set when FMC_MPDAT2 is written and auto-clear to 0 when the FMC_MPDAT2 data is programmed to Flash complete. (bits: 6)
    ,D2_MASK = 0x00000040
    ,D2_POS = 6
    ,D2_0 = 0x00000000 // FMC_MPDAT2 register is empty, or program to Flash complete
    ,D2_1 = 0x00000040 // FMC_MPDAT2 register has been written, and not program to Flash complete
    // ISP DATA 3 Flag (Read Only) This bit is set when FMC_MPDAT3 is written and auto-clear to 0 when the FMC_MPDAT3 data is programmed to Flash complete. (bits: 7)
    ,D3_MASK = 0x00000080
    ,D3_POS = 7
    ,D3_0 = 0x00000000 // FMC_MPDAT3 register is empty, or program to Flash complete
    ,D3_1 = 0x00000080 // FMC_MPDAT3 register has been written, and not program to Flash complete
    ,MPSTS_MASK = 0x000000FF
    ;
  };
  // ISP Multi-program Address Register
  struct MPADDR : reg<ip_ver, base + 0xC4>
  {
    static constexpr typename MPADDR::type
    // ISP Multi-word Program Address MPADDR is the address of ISP multi-word program operation when ISPGO flag is 1. MPADDR will keep the final ISP address when ISP multi-word program is complete. (bits: 31-0)
     MPADDRVAL_MASK = 0xFFFFFFFF
    ,MPADDRVAL_POS = 0
    ,MPADDR_MASK = 0xFFFFFFFF
    ;
  };
  // XOM Region 0 Status Register
  struct XOMR0STS : reg<ip_ver, base + 0xD0, 0x0FF000FF>
  {
    static constexpr typename XOMR0STS::type
    // XOM Region 0 Size (Page-aligned) SIZE is the page number of XOM Region 0. (bits: 7-0)
     SIZE_MASK = 0x000000FF
    ,SIZE_POS = 0
    // XOM Region 0 Base Address (Page-aligned) BASE is the base address of XOM Region 0. (bits: 31-8)
    ,BASE_MASK = 0xFFFFFF00
    ,BASE_POS = 8
    ,XOMR0STS_MASK = 0xFFFFFFFF
    ;
  };
  // XOM Region 1 Status Register
  struct XOMR1STS : reg<ip_ver, base + 0xD4, 0x0FF000FF>
  {
    static constexpr typename XOMR1STS::type
    // XOM Region 1 Size (Page-aligned) SIZE is the page number of XOM Region 1. (bits: 7-0)
     SIZE_MASK = 0x000000FF
    ,SIZE_POS = 0
    // XOM Region 1 Base Address (Page-aligned) BASE is the base address of XOM Region 1. (bits: 31-8)
    ,BASE_MASK = 0xFFFFFF00
    ,BASE_POS = 8
    ,XOMR1STS_MASK = 0xFFFFFFFF
    ;
  };
  // XOM Region 2 Status Register
  struct XOMR2STS : reg<ip_ver, base + 0xD8, 0x0FF000FF>
  {
    static constexpr typename XOMR2STS::type
    // XOM Region 2 Size (Page-aligned) SIZE is the page number of XOM Region 2. (bits: 7-0)
     SIZE_MASK = 0x000000FF
    ,SIZE_POS = 0
    // XOM Region 2 Base Address (Page-aligned) BASE is the base address of XOM Region 2. (bits: 31-8)
    ,BASE_MASK = 0xFFFFFF00
    ,BASE_POS = 8
    ,XOMR2STS_MASK = 0xFFFFFFFF
    ;
  };
  // XOM Region 3 Status Register
  struct XOMR3STS : reg<ip_ver, base + 0xDC, 0x0FF000FF>
  {
    static constexpr typename XOMR3STS::type
    // XOM Region 3 Size (Page-aligned) SIZE is the page number of XOM Region 3. (bits: 7-0)
     SIZE_MASK = 0x000000FF
    ,SIZE_POS = 0
    // XOM Region 3 Base Address (Page-aligned) BASE is the base address of XOM Region 3. (bits: 31-8)
    ,BASE_MASK = 0xFFFFFF00
    ,BASE_POS = 8
    ,XOMR3STS_MASK = 0xFFFFFFFF
    ;
  };
  // XOM Status Register
  struct XOMSTS : reg<ip_ver, base + 0xE0>
  {
    static constexpr typename XOMSTS::type
    // XOM Region 0 On XOM Region 0 active status. (bits: 0)
     XOMR0ON_MASK = 0x00000001
    ,XOMR0ON_POS = 0
    ,XOMR0ON_0 = 0x00000000 // No active
    ,XOMR0ON_1 = 0x00000001 // XOM region 0 is active
    // XOM Region 1 On XOM Region 1 active status. (bits: 1)
    ,XOMR1ON_MASK = 0x00000002
    ,XOMR1ON_POS = 1
    ,XOMR1ON_0 = 0x00000000 // No active
    ,XOMR1ON_1 = 0x00000002 // XOM region 1 is active
    // XOM Region 2 On XOM Region 2 active status. (bits: 2)
    ,XOMR2ON_MASK = 0x00000004
    ,XOMR2ON_POS = 2
    ,XOMR2ON_0 = 0x00000000 // No active
    ,XOMR2ON_1 = 0x00000004 // XOM region 2 is active
    // XOM Region 3 On XOM Region 3 active status. (bits: 3)
    ,XOMR3ON_MASK = 0x00000008
    ,XOMR3ON_POS = 3
    ,XOMR3ON_0 = 0x00000000 // No active
    ,XOMR3ON_1 = 0x00000008 // XOM region 3 is active
    // XOM Page Erase Function Fail XOM page erase function status. If XOMPEF is set to 1, user needs to erase XOM region again. (bits: 4)
    ,XOMPEF_MASK = 0x00000010
    ,XOMPEF_POS = 4
    ,XOMPEF_0 = 0x00000000 // Sucess
    ,XOMPEF_1 = 0x00000010 // Fail
    ,XOMSTS_MASK = 0x0000001F
    ;
  };
}; // struct FMC

} // namespace lmcu::device::ip::v1

