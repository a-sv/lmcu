/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// UART Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct UART
{
  static constexpr auto ip_ver = ip_version::_1;

  // UART Receive Buffer Register
  struct RBR : reg<ip_ver, base + 0x0>
  {
    static constexpr typename RBR::type
    // Receive Buffer Register (Read Only) By reading this register, the UART will return the 8-bit data received from RX pin (LSB first). (bits: 7-0)
     RBRVAL_MASK = 0x000000FF
    ,RBRVAL_POS = 0
    ,RBR_MASK = 0x000000FF
    ;
  };
  // UART Transmit Holding Register
  struct THR : reg<ip_ver, base + 0x0>
  {
    static constexpr typename THR::type
    // Transmit Holding Register By writing one byte to this register, the data byte will be stored in transmitter FIFO. The UART Controller will send out the data stored in transmitter FIFO top location through the TX pin. (bits: 7-0)
     THRVAL_MASK = 0x000000FF
    ,THRVAL_POS = 0
    ,THR_MASK = 0x000000FF
    ;
  };
  // UART Interrupt Enable Register
  struct IER : reg<ip_ver, base + 0x4>
  {
    static constexpr typename IER::type
    // Receive Data Available Interrupt Enable Control (bits: 0)
     RDA_IEN_MASK = 0x00000001
    ,RDA_IEN_POS = 0
    ,RDA_IEN_0 = 0x00000000 // RDA_INT Masked off
    ,RDA_IEN_1 = 0x00000001 // RDA_INT Enabled
    // Transmit Holding Register Empty Interrupt Enable Control (bits: 1)
    ,THRE_IEN_MASK = 0x00000002
    ,THRE_IEN_POS = 1
    ,THRE_IEN_0 = 0x00000000 // THRE_INT Masked off
    ,THRE_IEN_1 = 0x00000002 // THRE_INT Enabled
    // Receive Line Status Interrupt Enable Control (bits: 2)
    ,RLS_IEN_MASK = 0x00000004
    ,RLS_IEN_POS = 2
    ,RLS_IEN_0 = 0x00000000 // RLS_INT Masked off
    ,RLS_IEN_1 = 0x00000004 // RLS_INT Enabled
    // Modem Status Interrupt Enable Control (Available In UART0/UART1 Channel) (bits: 3)
    ,MODEM_IEN_MASK = 0x00000008
    ,MODEM_IEN_POS = 3
    ,MODEM_IEN_0 = 0x00000000 // MODEM_INT Masked off
    ,MODEM_IEN_1 = 0x00000008 // MODEM_INT Enabled
    // RX Time-Out Interrupt Enable Control (bits: 4)
    ,TOUT_IEN_MASK = 0x00000010
    ,TOUT_IEN_POS = 4
    ,TOUT_IEN_0 = 0x00000000 // TOUT_INT Masked off
    ,TOUT_IEN_1 = 0x00000010 // TOUT_INT Enabled
    // Buffer Error Interrupt Enable Control (bits: 5)
    ,BUF_ERR_IEN_MASK = 0x00000020
    ,BUF_ERR_IEN_POS = 5
    ,BUF_ERR_IEN_0 = 0x00000000 // BUF_ERR_INT Masked off
    ,BUF_ERR_IEN_1 = 0x00000020 // BUF_ERR_INT Enabled
    // NCTS Wake-Up Interrupt Enable Control (bits: 6)
    ,WKCTSIEN_MASK = 0x00000040
    ,WKCTSIEN_POS = 6
    ,WKCTSIEN_0 = 0x00000000 // nCTS wake-up system function Disabled
    ,WKCTSIEN_1 = 0x00000040 // Wake-up system function Enabled, when the system is in Power-down mode, an external nCTS change will wake-up system from Power-down mode
    // LIN Bus Interrupt Enable Control Note: This field is used for LIN function mode. (bits: 8)
    ,LIN_IEN_MASK = 0x00000100
    ,LIN_IEN_POS = 8
    ,LIN_IEN_0 = 0x00000000 // Lin bus interrupt Disabled
    ,LIN_IEN_1 = 0x00000100 // Lin bus interrupt Enabled
    // Incoming Data Wake-Up Interrupt Enable Control Note: Hardware will clear this bit when the incoming data wake-up operation finishes and <system clock> work stable. (bits: 10)
    ,WKDATIEN_MASK = 0x00000400
    ,WKDATIEN_POS = 10
    ,WKDATIEN_0 = 0x00000000 // Incoming data wake-up system function Disabled
    ,WKDATIEN_1 = 0x00000400 // Incoming data wake-up system function Enabled, when the system is in Power-down mode, incoming data will wake-up system from Power-down mode
    // Time-Out Counter Enable Control (bits: 11)
    ,TIME_OUT_EN_MASK = 0x00000800
    ,TIME_OUT_EN_POS = 11
    ,TIME_OUT_EN_0 = 0x00000000 // Time-out counter Disabled
    ,TIME_OUT_EN_1 = 0x00000800 // Time-out counter Enabled
    // RTS Auto Flow Control Enable Control ( Available In UART0/UART1 Channel) When RTS auto-flow is enabled, if the number of bytes in the RX FIFO equals the RTS_TRI_LEV (UA_FCR [19:16]), the UART will de-assert RTS signal. (bits: 12)
    ,AUTO_RTS_EN_MASK = 0x00001000
    ,AUTO_RTS_EN_POS = 12
    ,AUTO_RTS_EN_0 = 0x00000000 // RTS auto flow control Disabled
    ,AUTO_RTS_EN_1 = 0x00001000 // RTS auto flow control Enabled
    // CTS Auto Flow Control Enable Control (Available In UART0/UART1 Channel) When CTS auto-flow is enabled, the UART will send data to external device when CTS input assert (UART will not send data to device until CTS is asserted). (bits: 13)
    ,AUTO_CTS_EN_MASK = 0x00002000
    ,AUTO_CTS_EN_POS = 13
    ,AUTO_CTS_EN_0 = 0x00000000 // CTS auto flow control Disabled
    ,AUTO_CTS_EN_1 = 0x00002000 // CTS auto flow control Enabled
    // Auto-Baud Rate Interrupt Enable Control (bits: 18)
    ,ABRIEN_MASK = 0x00040000
    ,ABRIEN_POS = 18
    ,ABRIEN_0 = 0x00000000 // Auto-baud rate interrupt Disabled
    ,ABRIEN_1 = 0x00040000 // Auto-baud rate interrupt Enabled
    ,IER_MASK = 0x00043D7F
    ;
  };
  // UART FIFO Control Register
  struct FCR : reg<ip_ver, base + 0x8, 0x00000101>
  {
    static constexpr typename FCR::type
    // RX Field Software Reset When RFR is set, all the byte in the receiver FIFO /receive buffer and RX internal state machine are cleared. Note: This bit will automatically clear at least 3 UART peripherial clock cycles. (bits: 1)
     RFR_MASK = 0x00000002
    ,RFR_POS = 1
    ,RFR_0 = 0x00000000 // No effect
    ,RFR_1 = 0x00000002 // Reset the RX internal state machine and pointers
    // TX Field Software Reset When TFR is set, all the byte in the transmit FIFO/ transmit buffer and TX internal state machine are cleared. Note: This bit will automatically clear at least 3 UART peripherial clock cycles. (bits: 2)
    ,TFR_MASK = 0x00000004
    ,TFR_POS = 2
    ,TFR_0 = 0x00000000 // No effect
    ,TFR_1 = 0x00000004 // Reset the TX internal state machine and pointers
    // RX FIFO Interrupt (INT_RDA) Trigger Level (Available In UART0/UART1/UART2 Channel) When the number of bytes in the receive FIFO equals the RFITL, the RDA_IF will be set (if UA_IER [RDA_IEN] enabled, and an interrupt will be generated). (bits: 7-4)
    ,RFITL_MASK = 0x000000F0
    ,RFITL_POS = 4
    ,RFITL_0 = 0x00000000 // RX FIFO Interrupt Trigger Level is 1 byte. RX Buffer Interrupt Trigger Level is 1 byte
    ,RFITL_1 = 0x00000010 // RX FIFO Interrupt Trigger Level is 4 bytes
    ,RFITL_2 = 0x00000020 // RX FIFO Interrupt Trigger Level is 8 bytes
    ,RFITL_3 = 0x00000030 // RX FIFO Interrupt Trigger Level is 14 bytes
    // Receiver Disable Control The receiver is disabled or not (set 1 to disable receiver). Note: This field is used for RS-485 Normal Multi-drop mode. It should be programmed before RS-485_NMM (UA_ALT_CSR[8]) is programmed. (bits: 8)
    ,RX_DIS_MASK = 0x00000100
    ,RX_DIS_POS = 8
    ,RX_DIS_0 = 0x00000000 // Receiver Enabled
    ,RX_DIS_1 = 0x00000100 // Receiver Disabled
    // RTS Trigger Level For Auto-Flow Control Use (Available In UART0/UART1 Channel) Note: This field is used for RTS auto-flow control. (bits: 19-16)
    ,RTS_TRI_LEV_MASK = 0x000F0000
    ,RTS_TRI_LEV_POS = 16
    ,RTS_TRI_LEV_0 = 0x00000000 // RTS Trigger Level is 1 byte
    ,RTS_TRI_LEV_1 = 0x00010000 // RTS Trigger Level is 4 bytes
    ,RTS_TRI_LEV_2 = 0x00020000 // RTS Trigger Level is 8 bytes
    ,RTS_TRI_LEV_3 = 0x00030000 // RTS Trigger Level is 14 bytes
    ,FCR_MASK = 0x000F01F6
    ;
  };
  // UART Line Control Register
  struct LCR : reg<ip_ver, base + 0xC>
  {
    static constexpr typename LCR::type
    // Word Length Selection (bits: 1-0)
     WLS_MASK = 0x00000003
    ,WLS_POS = 0
    ,WLS_0 = 0x00000000 // Word length is 5-bit
    ,WLS_1 = 0x00000001 // Word length is 6-bit
    ,WLS_2 = 0x00000002 // Word length is 7-bit
    ,WLS_3 = 0x00000003 // Word length is 8-bit
    // Number Of <STOP Bit> (bits: 2)
    ,NSB_MASK = 0x00000004
    ,NSB_POS = 2
    ,NSB_0 = 0x00000000 // One <STOP bit> is generated in the transmitted data
    ,NSB_1 = 0x00000004 // When select 5-bit word length, 1.5 <STOP Bit> is generated in the transmitted data. When select 6-,7- and 8-bti word length, 2 <STOP Bit> is generated in the transmitted data
    // Parity Bit Enable Control (bits: 3)
    ,PBE_MASK = 0x00000008
    ,PBE_POS = 3
    ,PBE_0 = 0x00000000 // No parity bit
    ,PBE_1 = 0x00000008 // Parity bit is generated on each outgoing character and is checked on each incoming data
    // Even Parity Enable Control This bit has effect only when PBE (UA_LCR[3]) is set. (bits: 4)
    ,EPE_MASK = 0x00000010
    ,EPE_POS = 4
    ,EPE_0 = 0x00000000 // Odd number of logic 1's is transmitted and checked in each word
    ,EPE_1 = 0x00000010 // Even number of logic 1's is transmitted and checked in each word
    // Stick Parity Enable Control (bits: 5)
    ,SPE_MASK = 0x00000020
    ,SPE_POS = 5
    ,SPE_0 = 0x00000000 // Stick parity Disabled
    ,SPE_1 = 0x00000020 // If PBE (UA_LCR[3]) and EBE (UA_LCR[4]) are logic 1, the parity bit is transmitted and checked as logic 0. If PBE (UA_LCR[3]) is 1 and EBE (UA_LCR[4]) is 0 then the parity bit is transmitted and checked as 1
    // Break Control Bit When this bit is set to logic 1, the serial data output (TX) is forced to the Spacing State (logic 0). This bit acts only on TX and has no effect on the transmitter logic. (bits: 6)
    ,BCB_MASK = 0x00000040
    ,BCB_POS = 6
    ,BCB = 0x00000040
    ,LCR_MASK = 0x0000007F
    ;
  };
  // UART FIFO Status Register
  struct FSR : reg<ip_ver, base + 0x18, 0x10404000>
  {
    static constexpr typename FSR::type
    // RX Overflow Error IF (Read Only) This bit is set when RX FIFO overflow. If the number of bytes of received data is greater than RX_FIFO (UA_RBR) size, 16 bytes of UART0/UART1/UART2, this bit will be set. Note: This bit is read only, but can be cleared by writing <1> to it. (bits: 0)
     RX_OVER_IF_MASK = 0x00000001
    ,RX_OVER_IF_POS = 0
    ,RX_OVER_IF_0 = 0x00000000 // RX FIFO is not overflow. RX Buffer is not overflow
    ,RX_OVER_IF_1 = 0x00000001 // RX FIFO is overflow. RX Buffer is overflow
    // Auto-Baud Rate Detect Interrupt (Read Only) This bit is set to logic <1> when auto-baud rate detect function is finished. Note: This bit is read only, but can be cleared by writing <1> to it. (bits: 1)
    ,ABRDIF_MASK = 0x00000002
    ,ABRDIF_POS = 1
    ,ABRDIF_0 = 0x00000000 // Auto-baud rate detect function is not finished
    ,ABRDIF_1 = 0x00000002 // Auto-baud rate detect function is finished
    // Auto-Baud Rate Time-Out Interrupt (Read Only) Note1: This bit is set to logic <1> in Auto-baud Rate Detect mode and the baud rate counter is overflow. Note2: This bit is read only, but can be cleared by writing <1> to it. (bits: 2)
    ,ABRDTOIF_MASK = 0x00000004
    ,ABRDTOIF_POS = 2
    ,ABRDTOIF_0 = 0x00000000 // Auto-baud rate counter is underflow
    ,ABRDTOIF_1 = 0x00000004 // Auto-baud rate counter is overflow
    // RS-485 Address Byte Detection Flag (Read Only) (Available In UART0/UART1) Note1: This field is used for RS-485 function mode and RS485_ADD_EN (UA_ALT_CSR[15]) is set to 1 to enable Address detection mode. Note2: This bit is read only, but can be cleared by writing '1' to it. (bits: 3)
    ,RS485_ADD_DETF_MASK = 0x00000008
    ,RS485_ADD_DETF_POS = 3
    ,RS485_ADD_DETF_0 = 0x00000000 // Receiver detects a data that is not an address bit (bit 9 ='1')
    ,RS485_ADD_DETF_1 = 0x00000008 // Receiver detects a data that is an address bit (bit 9 ='1')
    // Parity Error Flag (Read Only) This bit is set to logic 1 whenever the received character does not have a valid <parity bit>, and is reset whenever the CPU writes 1 to this bit. Note: This bit is read only, but can be cleared by writing <1> to it. (bits: 4)
    ,PEF_MASK = 0x00000010
    ,PEF_POS = 4
    ,PEF_0 = 0x00000000 // No parity error is generated
    ,PEF_1 = 0x00000010 // Parity error is generated
    // Framing Error Flag (Read Only) This bit is set to logic 1 whenever the received character does not have a valid <STOP Bit> (that is, the stop bit following the last data bit or parity bit is detected as logic 0), and is reset whenever the CPU writes 1 to this bit. Note: This bit is read only, but can be cleared by writing <1> to it. (bits: 5)
    ,FEF_MASK = 0x00000020
    ,FEF_POS = 5
    ,FEF_0 = 0x00000000 // No framing error is generated
    ,FEF_1 = 0x00000020 // Framing error is generated
    // Break Interrupt Flag (Read Only) This bit is set to logic 1 whenever the received data input(RX) is held in the <spacing state> (logic 0) for longer than a full word transmission time (that is, the total time of <start bit> + data bits + parity + stop bits) and is reset whenever the CPU writes 1 to this bit. Note: This bit is read only, but can be cleared by writing <1> to it. (bits: 6)
    ,BIF_MASK = 0x00000040
    ,BIF_POS = 6
    ,BIF_0 = 0x00000000 // No Break interrupt is generated
    ,BIF_1 = 0x00000040 // Break interrupt is generated
    // RX FIFO Pointer (Read Only) This field indicates the RX FIFO Buffer Pointer. When UART receives one byte from external device, then RX_POINTER increases one. When one byte of RX FIFO is read by CPU, then RX_POINTER decreases one. The Maximum value shown in RX_POINTER is 15 (UART0/UART1/UART2). When the using level of RX FIFO Buffer equal to 16, the RX_FULL bit is set to 1 and RX_POINTER will show 0. As one byte of RX FIFO is read by CPU, the RX_FULL bit is cleared to 0 and RX_POINTER will show 15 (UART0/UART1/UART2). When RX Buffer is equal to 1, if one byte data is received, the RX_FULL bit is set to 1 and RX_POINTER will show 1. Once the RX Buffer is read, the RX_POINTER is 0. (bits: 13-8)
    ,RX_POINTER_MASK = 0x00003F00
    ,RX_POINTER_POS = 8
    // Receiver FIFO Empty (Read Only) This bit initiate RX FIFO empty or not. (UART0/UART1/UART2) Note: When the last byte of RX Buffer has been read by CPU, hardware sets this bit high. It will be cleared when UART receives any new data. (bits: 14)
    ,RX_EMPTY_MASK = 0x00004000
    ,RX_EMPTY_POS = 14
    ,RX_EMPTY_0 = 0x00000000 // RX FIFO is not empty. RX Buffer is not empty
    ,RX_EMPTY_1 = 0x00004000 // RX FIFO is empty. RX Buffer is empty
    // Receiver FIFO Full (Read Only) This bit initiates RX FIFO is full or not (UART0/UART1/UART2). Note: This bit is set when the number of usage in RX Buffer is equal to 1 (UART3/UART4/UART5), otherwise is cleared by hardware. (bits: 15)
    ,RX_FULL_MASK = 0x00008000
    ,RX_FULL_POS = 15
    ,RX_FULL_0 = 0x00000000 // RX FIFO is not full. RX buffer is not full
    ,RX_FULL_1 = 0x00008000 // RX FIFO is full. RX bufferis full
    // TX FIFO Pointer (Read Only) This field indicates the TX FIFO Buffer Pointer. When CPU writes one byte into UA_THR, then TX_POINTER increases one. When one byte of TX FIFO is transferred to Transmitter Shift Register, then TX_POINTER decreases one. The Maximum value shown in TX_POINTER is 15 (UART0/UART1/UART2). When the using level of TX FIFO Buffer is equal to 16, the TX_FULL bit is set to 1 and TX_POINTER will show 0. As one byte of TX FIFO is transferred to Transmitter Shift Register, the TX_FULL bit is cleared to 0 and TX_POINTER will show 15 (UART0/UART1/UART2). TX_POINTER is 0 (UART3/URT4/UART5). When TX Buffer is equal to 1, if one byte data is received, the TX_FULL bit is set to 1 and TX_POINTER will show 1. Once the TX Buffer is read, the TX_POINTER is 0. (bits: 21-16)
    ,TX_POINTER_MASK = 0x003F0000
    ,TX_POINTER_POS = 16
    // Transmitter FIFO Empty (Read Only) This bit indicates TX FIFO empty or not. (UART0/UART1/UART2) Note: When the last byte of TX Buffer has been transferred to Transmitter Shift Register, hardware sets this bit high. It will be cleared when writing data into THR (TX FIFO not empty). (bits: 22)
    ,TX_EMPTY_MASK = 0x00400000
    ,TX_EMPTY_POS = 22
    ,TX_EMPTY_0 = 0x00000000 // TX FIFO is not empty. TX Buffer is not empty
    ,TX_EMPTY_1 = 0x00400000 // TX FIFO is empty. TX Buffer is empty
    // Transmitter FIFO Full (Read Only) This bit indicates TX FIFO is full or not. (UART0/UART1/UART2) This bit is set when the number of usage in TX Buffer is equal to 1 (UART3/UART4/UART5), otherwise is cleared by hardware. (bits: 23)
    ,TX_FULL_MASK = 0x00800000
    ,TX_FULL_POS = 23
    ,TX_FULL_0 = 0x00000000 // TX FIFO is not full. TX Buffer is not full
    ,TX_FULL_1 = 0x00800000 // TX FIFO is full. TX Buffer is full
    // TX Overflow Error Interrupt Flag (Read Only) If TX FIFO (UA_THR) is full, an additional write to UA_THR will cause this bit to logic 1. (UART0/UART1/UART2) Note: This bit is read only, but can be cleared by writing <1> to it. (bits: 24)
    ,TX_OVER_IF_MASK = 0x01000000
    ,TX_OVER_IF_POS = 24
    ,TX_OVER_IF_0 = 0x00000000 // TX FIFO is not overflow. TX Buffer is not overflow
    ,TX_OVER_IF_1 = 0x01000000 // TX FIFO is overflow. TX Buffer is overflow
    // Transmitter Empty Flag (Read Only) This bit is set by hardware when TX FIFO (UA_THR) is empty and the STOP bit of the last byte has been transmitted. (UART0/UART1/UART2) Note: This bit is cleared automatically when TX FIFO/TX Buffer is not empty or the last byte transmission has not completed. (bits: 28)
    ,TE_FLAG_MASK = 0x10000000
    ,TE_FLAG_POS = 28
    ,TE_FLAG_0 = 0x00000000 // TX FIFO is not empty. TX Buffer is not empty
    ,TE_FLAG_1 = 0x10000000 // TX FIFO is empty. TX Buffer is empty
    ,FSR_MASK = 0x11FFFF7F
    ;
  };
  // UART Interrupt Status Register
  struct ISR : reg<ip_ver, base + 0x1C, 0x00000002>
  {
    static constexpr typename ISR::type
    // Receive Data Available Interrupt Flag (Read Only) When the number of bytes in the RX FIFO (UART0/UART1/UART2) / RX Buffer (UART3/UART4/UART5) equals the RFITL then the RDA_IF(UA_ISR[0]) will be set. If RDA_IEN (UA_IER [0]) is enabled, the RDA interrupt will be generated. Note: This bit is read only and it will be cleared when the number of unread bytes of RX FIFO drops below the threshold level (RFITL(UA_FCR[7:4]). (bits: 0)
     RDA_IF_MASK = 0x00000001
    ,RDA_IF_POS = 0
    ,RDA_IF_0 = 0x00000000 // No RDA interrupt flag is generated
    ,RDA_IF_1 = 0x00000001 // RDA interrupt flag is generated
    // Transmit Holding Register Empty Interrupt Flag (Read Only) This bit is set when the last data of TX FIFO (UART0/UART1/UART2) / TX Buffer (UART3/UART4/UART5) is transferred to Transmitter Shift Register. If THRE_IEN (UA_IER[1]) is enabled, the THRE interrupt will be generated. Note: This bit is read only and it will be cleared when writing data into THR (TX FIFO not empty). (bits: 1)
    ,THRE_IF_MASK = 0x00000002
    ,THRE_IF_POS = 1
    ,THRE_IF_0 = 0x00000000 // No THRE interrupt flag is generated
    ,THRE_IF_1 = 0x00000002 // THRE interrupt flag is generated
    // Receive Line Interrupt Flag (Read Only) This bit is set when the RX receive data have parity error, frame error or break error (at least one of 3 bits, BIF(UA_FSR[6]), FEF(UA_FSR[5]) and PEF(UA_FSR[4]), is set). If RLS_IEN (UA_IER [2]) is enabled, the RLS interrupt will be generated. Note2: This bit is read only and reset to 0 when all bits of BIF(UA_FSR[6]), FEF(UA_FSR[5]) and PEF(UA_FSR[4]) are cleared. Note3: In RS-485 function mode, this bit is read only and reset to 0 when all bits of BIF(UA_FSR[6]) , FEF(UA_FSR[5]) and PEF(UA_FSR[4]) and RS485_ADD_DETF (UA_FSR[3]) are cleared. (bits: 2)
    ,RLS_IF_MASK = 0x00000004
    ,RLS_IF_POS = 2
    ,RLS_IF_0 = 0x00000000 // No RLS interrupt flag is generated
    ,RLS_IF_1 = 0x00000004 // RLS interrupt flag is generated
    // MODEM Interrupt Flag (Read Only) (Not Available In UART2 Channel) Note: This bit is read only and reset to 0 when bit DCTSF is cleared by a write 1 on DCTSF(UA_MSR[0]). (bits: 3)
    ,MODEM_IF_MASK = 0x00000008
    ,MODEM_IF_POS = 3
    ,MODEM_IF_0 = 0x00000000 // No Modem interrupt flag is generated
    ,MODEM_IF_1 = 0x00000008 // Modem interrupt flag is generated
    // Time-Out Interrupt Flag (Read Only) This bit is set when the RX FIFO (UART0/UART1/UART2) / RX Buffer (UART3/UART4/UART5) is not empty and no activities occurred in the RX FIFO and the time-out counter equal to TOIC. If TOUT_IEN (UA_IER [4]) is enabled, the Tout interrupt will be generated. Note: This bit is read only and user can read UA_RBR (RX is in active) to clear it. (bits: 4)
    ,TOUT_IF_MASK = 0x00000010
    ,TOUT_IF_POS = 4
    ,TOUT_IF_0 = 0x00000000 // No Time-out interrupt flag is generated
    ,TOUT_IF_1 = 0x00000010 // Time-out interrupt flag is generated
    // Buffer Error Interrupt Flag (Read Only) This bit is set when the TX FIFO (UART0/UART1/UART2) / TX Buffer (UART3/UART4/UART5) or RX FIFO (UART0/UART1/UART2)/ RX Buffer (UART3/UART4/UART5) overflows (TX_OVER_IF (UA_FSR[24]) or RX_OVER_IF (UA_FSR[0]) is set). When BUF_ERR_IF (UA_ISR[5]) is set, the transfer is not correct. If BUF_ERR_IEN (UA_IER [8]) is enabled, the buffer error interrupt will be generated. Note: This bit is read only and reset to 0 when all bits of TX_OVER_IF(UA_FSR[24]) and RX_OVER_IF(UA_FSR[0]) are cleared. (bits: 5)
    ,BUF_ERR_IF_MASK = 0x00000020
    ,BUF_ERR_IF_POS = 5
    ,BUF_ERR_IF_0 = 0x00000000 // No buffer error interrupt flag is generated
    ,BUF_ERR_IF_1 = 0x00000020 // Buffer error interrupt flag is generated
    // UART Wake-Up Flag (Read Only) This bit is set when DATWKIF (UART_INTSTS[17]) or CTSWKIF(UART_INTSTS[16]) is set to 1. Note: This bit is read only. This bit is cleared if both of DATWKIF (UART_INTSTS[17]) and CTSWKIF (UART_INTSTS[16]) are cleared to 0 by writing 1 to DATWKIF (UART_INTSTS[17]) and CTSWKIF (UART_INTSTS[17]). (bits: 6)
    ,WKIF_MASK = 0x00000040
    ,WKIF_POS = 6
    ,WKIF_0 = 0x00000000 // No DATWKIF and CTSWKIF are generated
    ,WKIF_1 = 0x00000040 // DATWKIF or CTSWKIF
    // LIN Bus Flag (Read Only)(UART0/UARt1/UART2) Note: This bit is read only. This bit is cleared when LINS_HDET_F (UA_LIN_SR[0]), LIN_BKDET_F (UA_LIN_SR[9]), BIT_ERR_F (UA_LIN_SR[9]), LINS_IDPENR_F (UA_LIN_SR[2]) and LINS_HERR_F (UA_LIN_SR[1]) all are cleared. (bits: 7)
    ,LIN_IF_MASK = 0x00000080
    ,LIN_IF_POS = 7
    ,LIN_IF_0 = 0x00000000 // None of LINS_HDET_F, LIN_BKDET_F, BIT_ERR_F, LINS_IDPERR_F and LINS_HERR_F is generated
    ,LIN_IF_1 = 0x00000080 // At least one of LINS_HDET_F, LIN_BKDET_F, BIT_ERR_F, LINS_IDPERR_F and LINS_HERR_F is generated
    // Receive Data Available Interrupt Indicator (Read Only) This bit is set if RDA_IEN (UA_IER[0]) and RDA_IF (UA_ISR[0]) are both set to 1. (bits: 8)
    ,RDA_INT_MASK = 0x00000100
    ,RDA_INT_POS = 8
    ,RDA_INT_0 = 0x00000000 // No RDA interrupt is generated
    ,RDA_INT_1 = 0x00000100 // RDA interrupt is generated
    // Transmit Holding Register Empty Interrupt Indicator (Read Only) This bit is set if THRE_IEN (UA_IER[1])and THRE_IF(UA_SR[1]) are both set to 1. (bits: 9)
    ,THRE_INT_MASK = 0x00000200
    ,THRE_INT_POS = 9
    ,THRE_INT_0 = 0x00000000 // No THRE interrupt is generated
    ,THRE_INT_1 = 0x00000200 // THRE interrupt is generated
    // Receive Line Status Interrupt Indicator (Read Only) This bit is set if RLS_IEN (UA_IER[2]) and RLS_IF(UA_ISR[2]) are both set to 1. (bits: 10)
    ,RLS_INT_MASK = 0x00000400
    ,RLS_INT_POS = 10
    ,RLS_INT_0 = 0x00000000 // No RLS interrupt is generated
    ,RLS_INT_1 = 0x00000400 // RLS interrupt is generated
    // MODEM Status Interrupt Indicator (Read Only) (Available In UART0/UART1 Channel) This bit is set if MODEM_IEN(UA_IER[3] and MODEM_IF(UA_ISR[4]) are both set to 1 (bits: 11)
    ,MODEM_INT_MASK = 0x00000800
    ,MODEM_INT_POS = 11
    ,MODEM_INT_0 = 0x00000000 // No Modem interrupt is generated
    ,MODEM_INT_1 = 0x00000800 // Modem interrupt is generated
    // Time-Out Interrupt Indicator (Read Only) This bit is set if TOUT_IEN(UA_IER[4]) and TOUT_IF(UA_ISR[4]) are both set to 1. (bits: 12)
    ,TOUT_INT_MASK = 0x00001000
    ,TOUT_INT_POS = 12
    ,TOUT_INT_0 = 0x00000000 // No Tout interrupt is generated
    ,TOUT_INT_1 = 0x00001000 // Tout interrupt is generated
    // Buffer Error Interrupt Indicator (Read Only) This bit is set if BUF_ERR_IEN(UA_IER[5] and BUF_ERR_IF(UA_ISR[5]) are both set to 1. (bits: 13)
    ,BUF_ERR_INT_MASK = 0x00002000
    ,BUF_ERR_INT_POS = 13
    ,BUF_ERR_INT_0 = 0x00000000 // No buffer error interrupt is generated
    ,BUF_ERR_INT_1 = 0x00002000 // Buffer error interrupt is generated
    // LIN Bus Interrupt Indicator (Read Only) This bit is set if LIN_IEN (UA_IER[8]) and LIN _IF(UA_ISR[7]) are both set to 1. (bits: 15)
    ,LIN_INT_MASK = 0x00008000
    ,LIN_INT_POS = 15
    ,LIN_INT_0 = 0x00000000 // No LIN Bus interrupt is generated
    ,LIN_INT_1 = 0x00008000 // The LIN Bus interrupt is generated
    // NCTS Wake-Up Interrupt Flag (Read Only) Note1: If WKCTSIEN (UA_IER[6])is enabled, the wake-up interrupt is generated. Note2: This bit is read only, but can be cleared by writing '1' to it. (bits: 16)
    ,CTSWKIF_MASK = 0x00010000
    ,CTSWKIF_POS = 16
    ,CTSWKIF_0 = 0x00000000 // Chip stays in power-down state
    ,CTSWKIF_1 = 0x00010000 // Chip wake-up from power-down state by nCTS wake-up
    // Data Wake-Up Interrupt Flag (Read Only) This bit is set if chip wake-up from power-down state by data wake-up. Note1: If WKDATIEN (UA_IER[10]) is enabled, the wake-up interrupt is generated. Note2: This bit is read only, but can be cleared by writing '1' to it. (bits: 17)
    ,DATWKIF_MASK = 0x00020000
    ,DATWKIF_POS = 17
    ,DATWKIF_0 = 0x00000000 // Chip stays in power-down state
    ,DATWKIF_1 = 0x00020000 // Chip wake-up from power-down state by data wake-up
    ,ISR_MASK = 0x0003BFFF
    ;
  };
  // UART Time-out Register
  struct TOR : reg<ip_ver, base + 0x20>
  {
    static constexpr typename TOR::type
    // Time-Out Interrupt Comparator (bits: 7-0)
     TOIC_MASK = 0x000000FF
    ,TOIC_POS = 0
    // TX Delay Time Value This field is used to programming the transfer delay time between the last stop bit and next start bit. (bits: 15-8)
    ,DLY_MASK = 0x0000FF00
    ,DLY_POS = 8
    ,TOR_MASK = 0x0000FFFF
    ;
  };
  // UART Baud Rate Divisor Register
  struct BAUD : reg<ip_ver, base + 0x24, 0x0F000000>
  {
    static constexpr typename BAUD::type
    // Baud Rate Divider The field indicates the baud rate divider. (bits: 15-0)
     BRD_MASK = 0x0000FFFF
    ,BRD_POS = 0
    // Divider X (bits: 27-24)
    ,DIVIDER_X_MASK = 0x0F000000
    ,DIVIDER_X_POS = 24
    // Divider X Equal To 1 Refer to Table 624 UART Baud Rate Equation for more information. (bits: 28)
    ,DIV_X_ONE_MASK = 0x10000000
    ,DIV_X_ONE_POS = 28
    ,DIV_X_ONE_0 = 0x00000000 // Divider M = X (the equation of M = X+1, but DIVIDER_X[27:24] must = 8)
    ,DIV_X_ONE_1 = 0x10000000 // Divider M = 1 (the equation of M = 1, but BRD [15:0] must = 3)
    // Divider X Enable Control Refer to Table 624 UART Baud Rate Equation for more information. Note: In IrDA mode, this bit must disable. (bits: 29)
    ,DIV_X_EN_MASK = 0x20000000
    ,DIV_X_EN_POS = 29
    ,DIV_X_EN_0 = 0x00000000 // Divider X Disabled (the equation of M = 16)
    ,DIV_X_EN_1 = 0x20000000 // Divider X Enabled (the equation of M = X+1, but DIVIDER_X [27:24] must = 8)
    ,BAUD_MASK = 0x3F00FFFF
    ;
  };
  // UART IrDA Control Register
  struct IRCR : reg<ip_ver, base + 0x28, 0x00000040>
  {
    static constexpr typename IRCR::type
    // IrDA Receiver/Transmitter Selection Enable Control (bits: 1)
     TX_SELECT_MASK = 0x00000002
    ,TX_SELECT_POS = 1
    ,TX_SELECT_0 = 0x00000000 // IrDA Transmitter Disabled and Receiver Enabled
    ,TX_SELECT_1 = 0x00000002 // IrDA Transmitter Enabled and Receiver Disabled
    // IrDA Inverse Transmitting Output Signal Control (bits: 5)
    ,INV_TX_MASK = 0x00000020
    ,INV_TX_POS = 5
    ,INV_TX_0 = 0x00000000 // None inverse transmitting signal
    ,INV_TX_1 = 0x00000020 // Inverse transmitting output signal
    // IrDA Inverse Receive Input Signal Control (bits: 6)
    ,INV_RX_MASK = 0x00000040
    ,INV_RX_POS = 6
    ,INV_RX_0 = 0x00000000 // None inverse receiving input signal
    ,INV_RX_1 = 0x00000040 // Inverse receiving input signal
    ,IRCR_MASK = 0x00000062
    ;
  };
  // UART Alternate Control/Status Register
  struct ALT_CSR : reg<ip_ver, base + 0x2C, 0x0000000C>
  {
    static constexpr typename ALT_CSR::type
    // UART LIN Break Field Length (Available In UART0/UART1/UART2) This field indicates a 4-bit LIN TX break field count. Note1: This break field length is LIN_BKFL + 1. (bits: 3-0)
     LIN_BKFL_MASK = 0x0000000F
    ,LIN_BKFL_POS = 0
    // LIN RX Enable Control (Available In UART0/UART1/UART2) (bits: 6)
    ,LIN_RX_EN_MASK = 0x00000040
    ,LIN_RX_EN_POS = 6
    ,LIN_RX_EN_0 = 0x00000000 // LIN RX mode Disabled
    ,LIN_RX_EN_1 = 0x00000040 // LIN RX mode Enabled
    // LIN TX Break Mode Enable Control (Available In UART0/UART1/UART2) Note: When TX break field transfer operation finished, this bit will be cleared automatically. (bits: 7)
    ,LIN_TX_EN_MASK = 0x00000080
    ,LIN_TX_EN_POS = 7
    ,LIN_TX_EN_0 = 0x00000000 // LIN TX Break mode Disabled
    ,LIN_TX_EN_1 = 0x00000080 // LIN TX Break mode Enabled
    // RS-485 Normal Multi-Drop Operation Mode (NMM) (Available In UART0/UART1) Note: It cannot be active with RS-485_AAD operation mode. (bits: 8)
    ,RS485_NMM_MASK = 0x00000100
    ,RS485_NMM_POS = 8
    ,RS485_NMM_0 = 0x00000000 // RS-485 Normal Multi-drop Operation mode (NMM) Disabled
    ,RS485_NMM_1 = 0x00000100 // RS-485 Normal Multi-drop Operation mode (NMM) Enabled
    // RS-485 Auto Address Detection Operation Mode (AAD) (Available In UART0/UART1) Note: It cannot be active with RS-485_NMM operation mode. (bits: 9)
    ,RS485_AAD_MASK = 0x00000200
    ,RS485_AAD_POS = 9
    ,RS485_AAD_0 = 0x00000000 // RS-485 Auto Address Detection Operation mode (AAD) Disabled
    ,RS485_AAD_1 = 0x00000200 // RS-485 Auto Address Detection Operation mode (AAD) Enabled
    // RS-485 Auto Direction Mode (AUD) (Available In UART0/UART1) Note: It can be active with RS-485_AAD or RS-485_NMM operation mode. (bits: 10)
    ,RS485_AUD_MASK = 0x00000400
    ,RS485_AUD_POS = 10
    ,RS485_AUD_0 = 0x00000000 // RS-485 Auto Direction Operation mode (AUO) Disabled
    ,RS485_AUD_1 = 0x00000400 // RS-485 Auto Direction Operation mode (AUO) Enabled
    // RS-485 Address Detection Enable Control (Available In UART0/UART1) This bit is used to enable RS-485 Address Detection mode. Note: This bit is used for RS-485 any operation mode. (bits: 15)
    ,RS485_ADD_EN_MASK = 0x00008000
    ,RS485_ADD_EN_POS = 15
    ,RS485_ADD_EN_0 = 0x00000000 // Address detection mode Disabled
    ,RS485_ADD_EN_1 = 0x00008000 // Address detection mode Enabled
    // Auto-Baud Rate Interrupt Flag (Read Only) This bit is set when auto-baud rate detection function finished or the auto-baud rate counter was overflow and if ABRIEN(UART_IEN [18]) is set then the auto-baud rate interrupt will be generated. Note: This bit is read only, but it can be cleared by writing <1> to ABRDTOIF (UA_FSR[2]) and ABRDIF(UA_FSR[1]). (bits: 17)
    ,ABRIF_MASK = 0x00020000
    ,ABRIF_POS = 17
    ,ABRIF = 0x00020000
    // Auto-Baud Rate Detect Enable Control This bit is cleared automatically after auto-baud detection is finished. (bits: 18)
    ,ABRDEN_MASK = 0x00040000
    ,ABRDEN_POS = 18
    ,ABRDEN_0 = 0x00000000 // Auto-baud rate detect function Disabled
    ,ABRDEN_1 = 0x00040000 // Auto-baud rate detect function Enabled
    // Auto-Baud Rate Detect Bit Length Note: The calculation of bit number includes the START bit. (bits: 20-19)
    ,ABRDBITS_MASK = 0x00180000
    ,ABRDBITS_POS = 19
    ,ABRDBITS_0 = 0x00000000 // 1-bit time from Start bit to the 1st rising edge. The input pattern shall be 0x01
    ,ABRDBITS_1 = 0x00080000 // 2-bit time from Start bit to the 1st rising edge. The input pattern shall be 0x02
    ,ABRDBITS_2 = 0x00100000 // 4-bit time from Start bit to the 1st rising edge. The input pattern shall be 0x08
    ,ABRDBITS_3 = 0x00180000 // 8-bit time from Start bit to the 1st rising edge. The input pattern shall be 0x80
    // Address Match Value Register (Available In UART0/UART1) This field contains the RS-485 address match values. Note: This field is used for RS-485 auto address detection mode. (bits: 31-24)
    ,ADDR_MATCH_MASK = 0xFF000000
    ,ADDR_MATCH_POS = 24
    ,ALT_CSR_MASK = 0xFF1E87CF
    ;
  };
  // UART Function Select Register
  struct FUN_SEL : reg<ip_ver, base + 0x30>
  {
    static constexpr typename FUN_SEL::type
    // Function Select Enable Control (bits: 1-0)
     FUN_SELVAL_MASK = 0x00000003
    ,FUN_SELVAL_POS = 0
    ,FUN_SELVAL_0 = 0x00000000 // UART function Enabled
    ,FUN_SELVAL_1 = 0x00000001 // LIN function Enabled. (Available in UART0/UART1/UART2)
    ,FUN_SELVAL_2 = 0x00000002 // IrDA function Enabled
    ,FUN_SELVAL_3 = 0x00000003 // RS-485 function Enabled. (Available in UART0/UART1)
    ,FUN_SEL_MASK = 0x00000003
    ;
  };
}; // struct UART

} // namespace lmcu::device::ip::v1

