/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Inter-integrated circuit interface
// ------------------------------------------------------------------------------------------------
struct I2C2
{
  static constexpr std::uintptr_t base = 0x40005800;

  // Control register 1
  struct CR1 : reg<16, base + 0x0, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Peripheral enable (bits: 0)
     PE_MASK = 0x00000001
    ,PE_POS = 0
    ,PE = 0x00000001
    // SMBus mode (bits: 1)
    ,SMBUS_MASK = 0x00000002
    ,SMBUS_POS = 1
    ,SMBUS = 0x00000002
    // SMBus type (bits: 3)
    ,SMBTYPE_MASK = 0x00000008
    ,SMBTYPE_POS = 3
    ,SMBTYPE = 0x00000008
    // ARP enable (bits: 4)
    ,ENARP_MASK = 0x00000010
    ,ENARP_POS = 4
    ,ENARP = 0x00000010
    // PEC enable (bits: 5)
    ,ENPEC_MASK = 0x00000020
    ,ENPEC_POS = 5
    ,ENPEC = 0x00000020
    // General call enable (bits: 6)
    ,ENGC_MASK = 0x00000040
    ,ENGC_POS = 6
    ,ENGC = 0x00000040
    // Clock stretching disable (Slave mode) (bits: 7)
    ,NOSTRETCH_MASK = 0x00000080
    ,NOSTRETCH_POS = 7
    ,NOSTRETCH = 0x00000080
    // Start generation (bits: 8)
    ,START_MASK = 0x00000100
    ,START_POS = 8
    ,START = 0x00000100
    // Stop generation (bits: 9)
    ,STOP_MASK = 0x00000200
    ,STOP_POS = 9
    ,STOP = 0x00000200
    // Acknowledge enable (bits: 10)
    ,ACK_MASK = 0x00000400
    ,ACK_POS = 10
    ,ACK = 0x00000400
    // Acknowledge/PEC Position (for data reception) (bits: 11)
    ,POS_MASK = 0x00000800
    ,POS_POS = 11
    ,POS = 0x00000800
    // Packet error checking (bits: 12)
    ,PEC_MASK = 0x00001000
    ,PEC_POS = 12
    ,PEC = 0x00001000
    // SMBus alert (bits: 13)
    ,ALERT_MASK = 0x00002000
    ,ALERT_POS = 13
    ,ALERT = 0x00002000
    // Software reset (bits: 15)
    ,SWRST_MASK = 0x00008000
    ,SWRST_POS = 15
    ,SWRST = 0x00008000
    ,CR1_MASK = 0x0000BFFB
    ;
  };
  // Control register 2
  struct CR2 : reg<16, base + 0x4, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Peripheral clock frequency (bits: 5-0)
     FREQ_MASK = 0x0000003F
    ,FREQ_POS = 0
    // Error interrupt enable (bits: 8)
    ,ITERREN_MASK = 0x00000100
    ,ITERREN_POS = 8
    ,ITERREN = 0x00000100
    // Event interrupt enable (bits: 9)
    ,ITEVTEN_MASK = 0x00000200
    ,ITEVTEN_POS = 9
    ,ITEVTEN = 0x00000200
    // Buffer interrupt enable (bits: 10)
    ,ITBUFEN_MASK = 0x00000400
    ,ITBUFEN_POS = 10
    ,ITBUFEN = 0x00000400
    // DMA requests enable (bits: 11)
    ,DMAEN_MASK = 0x00000800
    ,DMAEN_POS = 11
    ,DMAEN = 0x00000800
    // DMA last transfer (bits: 12)
    ,LAST_MASK = 0x00001000
    ,LAST_POS = 12
    ,LAST = 0x00001000
    ,CR2_MASK = 0x00001F3F
    ;
  };
  // Own address register 1
  struct OAR1 : reg<16, base + 0x8, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Interface address (bits: 9-0)
     ADD_MASK = 0x000003FF
    ,ADD_POS = 0
    // Addressing mode (slave mode) (bits: 15)
    ,ADDMODE_MASK = 0x00008000
    ,ADDMODE_POS = 15
    ,ADDMODE = 0x00008000
    ,OAR1_MASK = 0x000083FF
    ;
  };
  // Own address register 2
  struct OAR2 : reg<16, base + 0xC, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Dual addressing mode enable (bits: 0)
     ENDUAL_MASK = 0x00000001
    ,ENDUAL_POS = 0
    ,ENDUAL = 0x00000001
    // Interface address (bits: 7-1)
    ,ADD2_MASK = 0x000000FE
    ,ADD2_POS = 1
    ,OAR2_MASK = 0x000000FF
    ;
  };
  // Data register
  struct DR : reg<16, base + 0x10, 0x00000000, 0x00000000>
  {
    static constexpr type
    // 8-bit data (bits: 7-0)
     DATA_MASK = 0x000000FF
    ,DATA_POS = 0
    ,DR_MASK = 0x000000FF
    ;
  };
  // Status register 1
  struct SR1 : reg<16, base + 0x14, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Start bit (Master mode) (bits: 0)
     SB_MASK = 0x00000001
    ,SB_POS = 0
    ,SB = 0x00000001
    // Address sent (master mode)/matched (slave mode) (bits: 1)
    ,ADDR_MASK = 0x00000002
    ,ADDR_POS = 1
    ,ADDR = 0x00000002
    // Byte transfer finished (bits: 2)
    ,BTF_MASK = 0x00000004
    ,BTF_POS = 2
    ,BTF = 0x00000004
    // 10-bit header sent (Master mode) (bits: 3)
    ,ADD10_MASK = 0x00000008
    ,ADD10_POS = 3
    ,ADD10 = 0x00000008
    // Stop detection (slave mode) (bits: 4)
    ,STOPF_MASK = 0x00000010
    ,STOPF_POS = 4
    ,STOPF = 0x00000010
    // Data register not empty (receivers) (bits: 6)
    ,RXNE_MASK = 0x00000040
    ,RXNE_POS = 6
    ,RXNE = 0x00000040
    // Data register empty (transmitters) (bits: 7)
    ,TXE_MASK = 0x00000080
    ,TXE_POS = 7
    ,TXE = 0x00000080
    // Bus error (bits: 8)
    ,BERR_MASK = 0x00000100
    ,BERR_POS = 8
    ,BERR = 0x00000100
    // Arbitration lost (master mode) (bits: 9)
    ,ARLO_MASK = 0x00000200
    ,ARLO_POS = 9
    ,ARLO = 0x00000200
    // Acknowledge failure (bits: 10)
    ,AF_MASK = 0x00000400
    ,AF_POS = 10
    ,AF = 0x00000400
    // Overrun/Underrun (bits: 11)
    ,OVR_MASK = 0x00000800
    ,OVR_POS = 11
    ,OVR = 0x00000800
    // PEC Error in reception (bits: 12)
    ,PECERR_MASK = 0x00001000
    ,PECERR_POS = 12
    ,PECERR = 0x00001000
    // Timeout or Tlow error (bits: 14)
    ,TIMEOUT_MASK = 0x00004000
    ,TIMEOUT_POS = 14
    ,TIMEOUT = 0x00004000
    // SMBus alert (bits: 15)
    ,SMBALERT_MASK = 0x00008000
    ,SMBALERT_POS = 15
    ,SMBALERT = 0x00008000
    ,SR1_MASK = 0x0000DFDF
    ;
  };
  // Status register 2
  struct SR2 : reg<16, base + 0x18, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Master/slave (bits: 0)
     MSL_MASK = 0x00000001
    ,MSL_POS = 0
    ,MSL = 0x00000001
    // Bus busy (bits: 1)
    ,BUSY_MASK = 0x00000002
    ,BUSY_POS = 1
    ,BUSY = 0x00000002
    // Transmitter/receiver (bits: 2)
    ,TRA_MASK = 0x00000004
    ,TRA_POS = 2
    ,TRA = 0x00000004
    // General call address (Slave mode) (bits: 4)
    ,GENCALL_MASK = 0x00000010
    ,GENCALL_POS = 4
    ,GENCALL = 0x00000010
    // SMBus device default address (Slave mode) (bits: 5)
    ,SMBDEFAULT_MASK = 0x00000020
    ,SMBDEFAULT_POS = 5
    ,SMBDEFAULT = 0x00000020
    // SMBus host header (Slave mode) (bits: 6)
    ,SMBHOST_MASK = 0x00000040
    ,SMBHOST_POS = 6
    ,SMBHOST = 0x00000040
    // Dual flag (Slave mode) (bits: 7)
    ,DUALF_MASK = 0x00000080
    ,DUALF_POS = 7
    ,DUALF = 0x00000080
    // Packet error checking register (bits: 15-8)
    ,PEC_MASK = 0x0000FF00
    ,PEC_POS = 8
    ,SR2_MASK = 0x0000FFF7
    ;
  };
  // Clock control register
  struct CCR : reg<16, base + 0x1C, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Clock control register in Fm/Sm mode (Master mode) (bits: 11-0)
     CCRVAL_MASK = 0x00000FFF
    ,CCRVAL_POS = 0
    // Fm mode duty cycle (bits: 14)
    ,DUTY_MASK = 0x00004000
    ,DUTY_POS = 14
    ,DUTY = 0x00004000
    // I2C master mode selection (bits: 15)
    ,F_S_MASK = 0x00008000
    ,F_S_POS = 15
    ,F_S = 0x00008000
    ,CCR_MASK = 0x0000CFFF
    ;
  };
  // TRISE register
  struct TRISE : reg<16, base + 0x20, 0x00000000, 0x00000002>
  {
    static constexpr type
    // Maximum rise time in Fm/Sm mode (Master mode) (bits: 5-0)
     TRISEVAL_MASK = 0x0000003F
    ,TRISEVAL_POS = 0
    ,TRISE_MASK = 0x0000003F
    ;
  };
}; // struct I2C2

} // namespace lmcu::device

