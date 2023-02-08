/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// CRC Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct CRC
{
  static constexpr auto ip_ver = ip_version::_1;

  // CRC Control Register
  struct CTL : reg<ip_ver, base + 0x0, 0x20000000>
  {
    static constexpr typename CTL::type
    // CRC Channel Enable Bit (bits: 0)
     CRCEN_MASK = 0x00000001
    ,CRCEN_POS = 0
    ,CRCEN_0 = 0x00000000 // No effect
    ,CRCEN_1 = 0x00000001 // CRC operation Enabled
    // Checksum Initialization Note: This bit will be cleared automatically. (bits: 1)
    ,CHKSINIT_MASK = 0x00000002
    ,CHKSINIT_POS = 1
    ,CHKSINIT_0 = 0x00000000 // No effect
    ,CHKSINIT_1 = 0x00000002 // Initial checksum value by auto reload CRC_SEED register value to CRC_CHECKSUM register value
    // Write Data Bit Order Reverse This bit is used to enable the bit order reverse function per byte for write data value in CRC_DAT register. Note: If the write data is 0xAABBCCDD, the bit order reverse for CRC write data in is 0x55DD33BB. (bits: 24)
    ,DATREV_MASK = 0x01000000
    ,DATREV_POS = 24
    ,DATREV_0 = 0x00000000 // Bit order reversed for CRC write data in Disabled
    ,DATREV_1 = 0x01000000 // Bit order reversed for CRC write data in Enabled (per byte)
    // Checksum Bit Order Reverse This bit is used to enable the bit order reverse function for checksum result in CRC_CHECKSUM register. Note: If the checksum result is 0xDD7B0F2E, the bit order reverse for CRC checksum is 0x74F0DEBB. (bits: 25)
    ,CHKSREV_MASK = 0x02000000
    ,CHKSREV_POS = 25
    ,CHKSREV_0 = 0x00000000 // Bit order reverse for CRC checksum Disabled
    ,CHKSREV_1 = 0x02000000 // Bit order reverse for CRC checksum Enabled
    // Write Data 1's Complement This bit is used to enable the 1's complement function for write data value in CRC_DAT register. (bits: 26)
    ,DATFMT_MASK = 0x04000000
    ,DATFMT_POS = 26
    ,DATFMT_0 = 0x00000000 // 1's complement for CRC writes data in Disabled
    ,DATFMT_1 = 0x04000000 // 1's complement for CRC writes data in Enabled
    // Checksum 1's Complement This bit is used to enable the 1's complement function for checksum result in CRC_CHECKSUM register. (bits: 27)
    ,CHKSFMT_MASK = 0x08000000
    ,CHKSFMT_POS = 27
    ,CHKSFMT_0 = 0x00000000 // 1's complement for CRC checksum Disabled
    ,CHKSFMT_1 = 0x08000000 // 1's complement for CRC checksum Enabled
    // CPU Write Data Length This field indicates the write data length. Note: When the write data length is 8-bit mode, the valid data in CRC_DAT register is only DATA[7:0] bits; if the write data length is 16-bit mode, the valid data in CRC_DAT register is only DATA[15:0]. (bits: 29-28)
    ,DATLEN_MASK = 0x30000000
    ,DATLEN_POS = 28
    ,DATLEN_0 = 0x00000000 // Data length is 8-bit mode
    ,DATLEN_1 = 0x10000000 // Data length is 16-bit mode.
    ,DATLEN_2 = 0x20000000 // Data length is 32-bit mode
    // CRC Polynomial Mode This field indicates the CRC operation polynomial mode. (bits: 31-30)
    ,CRCMODE_MASK = 0xC0000000
    ,CRCMODE_POS = 30
    ,CRCMODE_0 = 0x00000000 // CRC-CCITT Polynomial mode
    ,CRCMODE_1 = 0x40000000 // CRC-8 Polynomial mode
    ,CRCMODE_2 = 0x80000000 // CRC-16 Polynomial mode
    ,CRCMODE_3 = 0xC0000000 // CRC-32 Polynomial mode
    ,CTL_MASK = 0xFF000003
    ;
  };
  // CRC Write Data Register
  struct DAT : reg<ip_ver, base + 0x4>
  {
    static constexpr typename DAT::type
    // CRC Write Data Bits User can write data directly by CPU mode or use PDMA function to write data to this field to perform CRC operation. Note: When the write data length is 8-bit mode, the valid data in CRC_DAT register is only DATA[7:0] bits; if the write data length is 16-bit mode, the valid data in CRC_DAT register is only DATA[15:0]. (bits: 31-0)
     DATA_MASK = 0xFFFFFFFF
    ,DATA_POS = 0
    ,DAT_MASK = 0xFFFFFFFF
    ;
  };
  // CRC Seed Register
  struct SEED : reg<ip_ver, base + 0x8>
  {
    static constexpr typename SEED::type
    // CRC Seed Value This field indicates the CRC seed value. Note: This field will be reloaded as checksum initial value (CRC_CHECKSUM register) after perform CHKSINIT (CRC_CTL[1]). (bits: 31-0)
     SEEDVAL_MASK = 0xFFFFFFFF
    ,SEEDVAL_POS = 0
    ,SEED_MASK = 0xFFFFFFFF
    ;
  };
  // CRC Checksum Register
  struct CHECKSUM : reg<ip_ver, base + 0xC>
  {
    static constexpr typename CHECKSUM::type
    // CRC Checksum Results This field indicates the CRC checksum result. (bits: 31-0)
     CHECKSUMVAL_MASK = 0xFFFFFFFF
    ,CHECKSUMVAL_POS = 0
    ,CHECKSUM_MASK = 0xFFFFFFFF
    ;
  };
}; // struct CRC

} // namespace lmcu::device::ip::v1

