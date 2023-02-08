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

  // UART Receive/Transmit Buffer Register
  struct DAT : reg<ip_ver, base + 0x0>
  {
    static constexpr typename DAT::type
    // Data Receive/Transmit Buffer Write Operation: By writing one byte to this register, the data byte will be stored in transmitter FIFO. The UART controller will send out the data stored in transmitter FIFO top location through the UART_TXD. Read Operation: By reading this register, the UART controller will return an 8-bit data received from receiver FIFO. (bits: 7-0)
     DATVAL_MASK = 0x000000FF
    ,DATVAL_POS = 0
    // PARITY Bit Receive/Transmit Buffer Write Operation: By writing to this bit, the PARITY bit will be stored in transmitter FIFO. If PBE (UART_LINE[3]) and PSS (UART_LINE[7]) are set, the UART controller will send out this bit follow the DAT (UART_DAT[7:0]) through the UART_TXD. Read Operation: If PBE (UART_LINE[3]) and PSS (UART_LINE[7]) are enabled, the PARITY bit can be read by this bit. Note: This bit has effect only when PBE (UART_LINE[3]) and PSS (UART_LINE[7]) are set. (bits: 8)
    ,PARITY_MASK = 0x00000100
    ,PARITY_POS = 8
    ,PARITY = 0x00000100
    ,DAT_MASK = 0x000001FF
    ;
  };
  // UART Interrupt Enable Register
  struct INTEN : reg<ip_ver, base + 0x4>
  {
    static constexpr typename INTEN::type
    // Receive Data Available Interrupt Enable Bit (bits: 0)
     RDAIEN_MASK = 0x00000001
    ,RDAIEN_POS = 0
    ,RDAIEN_0 = 0x00000000 // Receive data available interrupt Disabled
    ,RDAIEN_1 = 0x00000001 // Receive data available interrupt Enabled
    // Transmit Holding Register Empty Interrupt Enable Bit (bits: 1)
    ,THREIEN_MASK = 0x00000002
    ,THREIEN_POS = 1
    ,THREIEN_0 = 0x00000000 // Transmit holding register empty interrupt Disabled
    ,THREIEN_1 = 0x00000002 // Transmit holding register empty interrupt Enabled
    // Receive Line Status Interrupt Enable Bit (bits: 2)
    ,RLSIEN_MASK = 0x00000004
    ,RLSIEN_POS = 2
    ,RLSIEN_0 = 0x00000000 // Receive Line Status interrupt Disabled
    ,RLSIEN_1 = 0x00000004 // Receive Line Status interrupt Enabled
    // Modem Status Interrupt Enable Bit (bits: 3)
    ,MODEMIEN_MASK = 0x00000008
    ,MODEMIEN_POS = 3
    ,MODEMIEN_0 = 0x00000000 // Modem status interrupt Disabled
    ,MODEMIEN_1 = 0x00000008 // Modem status interrupt Enabled
    // RX Time-out Interrupt Enable Bit (bits: 4)
    ,RXTOIEN_MASK = 0x00000010
    ,RXTOIEN_POS = 4
    ,RXTOIEN_0 = 0x00000000 // RX time-out interrupt Disabled
    ,RXTOIEN_1 = 0x00000010 // RX time-out interrupt Enabled
    // Buffer Error Interrupt Enable Bit (bits: 5)
    ,BUFERRIEN_MASK = 0x00000020
    ,BUFERRIEN_POS = 5
    ,BUFERRIEN_0 = 0x00000000 // Buffer error interrupt Disabled
    ,BUFERRIEN_1 = 0x00000020 // Buffer error interrupt Enabled
    // Wake-up Interrupt Enable Bit (bits: 6)
    ,WKIEN_MASK = 0x00000040
    ,WKIEN_POS = 6
    ,WKIEN_0 = 0x00000000 // Wake-up Interrupt Disabled
    ,WKIEN_1 = 0x00000040 // Wake-up Interrupt Enabled
    // LIN Bus Interrupt Enable Bit Note: This bit is used for LIN function mode. (bits: 8)
    ,LINIEN_MASK = 0x00000100
    ,LINIEN_POS = 8
    ,LINIEN_0 = 0x00000000 // LIN bus interrupt Disabled
    ,LINIEN_1 = 0x00000100 // LIN bus interrupt Enabled
    // Receive Buffer Time-out Counter Enable Bit (bits: 11)
    ,TOCNTEN_MASK = 0x00000800
    ,TOCNTEN_POS = 11
    ,TOCNTEN_0 = 0x00000000 // Receive Buffer Time-out counter Disabled
    ,TOCNTEN_1 = 0x00000800 // Receive Buffer Time-out counter Enabled
    // nRTS Auto-flow Control Enable Bit Note: When nRTS auto-flow is enabled, if the number of bytes in the RX FIFO equals the RTSTRGLV (UART_FIFO[19:16]), the UART will de-assert nRTS signal. (bits: 12)
    ,ATORTSEN_MASK = 0x00001000
    ,ATORTSEN_POS = 12
    ,ATORTSEN_0 = 0x00000000 // nRTS auto-flow control Disabled
    ,ATORTSEN_1 = 0x00001000 // nRTS auto-flow control Enabled
    // nCTS Auto-flow Control Enable Bit Note: When nCTS auto-flow is enabled, the UART will send data to external device if nCTS input assert (UART will not send data to device until nCTS is asserted). (bits: 13)
    ,ATOCTSEN_MASK = 0x00002000
    ,ATOCTSEN_POS = 13
    ,ATOCTSEN_0 = 0x00000000 // nCTS auto-flow control Disabled
    ,ATOCTSEN_1 = 0x00002000 // nCTS auto-flow control Enabled
    // TX PDMA Enable Bit Note: If RLSIEN (UART_INTEN[2]) is enabled and HWRLSINT (UART_INTSTS[26]) is set to 1, the RLS (Receive Line Status) Interrupt is caused. If RLS interrupt is caused by Break Error Flag BIF(UART_FIFOSTS[6]), Frame Error Flag FEF(UART_FIFO[5]) or Parity Error Flag PEF(UART_FIFOSTS[4]), UART PDMA transmit request operation is stopped. Clear Break Error Flag BIF or Frame Error Flag FEF or Parity Error Flag PEF by writing '1' to corresponding BIF, FEF and PEF to make UART PDMA transmit request operation continue. (bits: 14)
    ,TXPDMAEN_MASK = 0x00004000
    ,TXPDMAEN_POS = 14
    ,TXPDMAEN_0 = 0x00000000 // TX PDMA Disabled
    ,TXPDMAEN_1 = 0x00004000 // TX PDMA Enabled
    // RX PDMA Enable Bit This bit can enable or disable RX PDMA service. Note: If RLSIEN (UART_INTEN[2]) is enabled and HWRLSINT (UART_INTSTS[26]) is set to 1, the RLS (Receive Line Status) Interrupt is caused. If RLS interrupt is caused by Break Error Flag BIF(UART_FIFOSTS[6]), Frame Error Flag FEF(UART_FIFO[5]) or Parity Error Flag PEF(UART_FIFOSTS[4]), UART PDMA receive request operation is stopped. Clear Break Error Flag BIF or Frame Error Flag FEF or Parity Error Flag PEF by writing '1' to corresponding BIF, FEF and PEF to make UART PDMA receive request operation continue. (bits: 15)
    ,RXPDMAEN_MASK = 0x00008000
    ,RXPDMAEN_POS = 15
    ,RXPDMAEN_0 = 0x00000000 // RX PDMA Disabled
    ,RXPDMAEN_1 = 0x00008000 // RX PDMA Enabled
    // Single-wire Bit Error Detection Interrupt Enable Bit Set this bit, the Single-wire Half Duplex Bit Error Detection Interrupt SWBEINT(UART_INTSTS[24]) is generated when Single-wire Bit Error Detection SWBEIF(UART_INTSTS[16]) is set. Note: This bit is valid when FUNCSEL (UART_FUNCSEL[2:0]) is select UART Single-wire mode. (bits: 16)
    ,SWBEIEN_MASK = 0x00010000
    ,SWBEIEN_POS = 16
    ,SWBEIEN_0 = 0x00000000 // Single-wire Bit Error Detect Inerrupt Disabled
    ,SWBEIEN_1 = 0x00010000 // Single-wire Bit Error Detect Inerrupt Enabled
    // Auto-baud Rate Interrupt Enable Bit (bits: 18)
    ,ABRIEN_MASK = 0x00040000
    ,ABRIEN_POS = 18
    ,ABRIEN_0 = 0x00000000 // Auto-baud rate interrupt Disabled
    ,ABRIEN_1 = 0x00040000 // Auto-baud rate interrupt Enabled
    // Transmitter Empty Interrupt Enable Bit If TXENDIEN (UART_INTEN[22]) is enabled, the Transmitter Empty interrupt TXENDINT (UART_INTSTS[30]) will be generated when TXENDIF (UART_INTSTS[22]) is set (TX FIFO (UART_DAT) is empty and the STOP bit of the last byte has been transmitted). (bits: 22)
    ,TXENDIEN_MASK = 0x00400000
    ,TXENDIEN_POS = 22
    ,TXENDIEN_0 = 0x00000000 // Transmitter empty interrupt Disabled
    ,TXENDIEN_1 = 0x00400000 // Transmitter empty interrupt Enabled
    ,INTEN_MASK = 0x0045F97F
    ;
  };
  // UART FIFO Control Register
  struct FIFO : reg<ip_ver, base + 0x8, 0x00000101>
  {
    static constexpr typename FIFO::type
    // RX Field Software Reset When RXRST (UART_FIFO[1]) is set, all the byte in the receiver FIFO and RX internal state machine are cleared. Note 1: This bit will automatically clear at least 3 UART peripheral clock cycles. Note 2: Before setting this bit, it should wait for the RXIDLE (UART_FIFOSTS[29]) be set. (bits: 1)
     RXRST_MASK = 0x00000002
    ,RXRST_POS = 1
    ,RXRST_0 = 0x00000000 // No effect
    ,RXRST_1 = 0x00000002 // Reset the RX internal state machine and pointers
    // TX Field Software Reset When TXRST (UART_FIFO[2]) is set, all the byte in the transmit FIFO and TX internal state machine are cleared. Note 1: This bit will automatically clear at least 3 UART peripheral clock cycles. Note 2: Before setting this bit, it should wait for the TXEMPTYF (UART_FIFOSTS[28]) be set. (bits: 2)
    ,TXRST_MASK = 0x00000004
    ,TXRST_POS = 2
    ,TXRST_0 = 0x00000000 // No effect
    ,TXRST_1 = 0x00000004 // Reset the TX internal state machine and pointers
    // RX FIFO Interrupt Trigger Level When the number of bytes in the receive FIFO equals the RFITL, the RDAIF (UART_INTSTS[0]) will be set (if RDAIEN (UART_INTEN [0]) enabled, and an interrupt will be generated). (bits: 7-4)
    ,RFITL_MASK = 0x000000F0
    ,RFITL_POS = 4
    ,RFITL_0 = 0x00000000 // RX FIFO Interrupt Trigger Level is 1 byte
    ,RFITL_1 = 0x00000010 // RX FIFO Interrupt Trigger Level is 4 bytes
    ,RFITL_2 = 0x00000020 // RX FIFO Interrupt Trigger Level is 8 bytes
    ,RFITL_3 = 0x00000030 // RX FIFO Interrupt Trigger Level is 14 bytes
    // Receiver Disable Bit The receiver is disabled or not (set 1 to disable receiver). Note: This bit is used for RS-485 Normal Multi-drop mode. It should be programmed before RS485NMM (UART_ALTCTL [8]) is programmed. (bits: 8)
    ,RXOFF_MASK = 0x00000100
    ,RXOFF_POS = 8
    ,RXOFF_0 = 0x00000000 // Receiver Enabled
    ,RXOFF_1 = 0x00000100 // Receiver Disabled
    // nRTS Trigger Level for Auto-flow Control Note: This field is used for auto nRTS flow control. (bits: 19-16)
    ,RTSTRGLV_MASK = 0x000F0000
    ,RTSTRGLV_POS = 16
    ,RTSTRGLV_0 = 0x00000000 // nRTS Trigger Level is 1 byte
    ,RTSTRGLV_1 = 0x00010000 // nRTS Trigger Level is 4 bytes
    ,RTSTRGLV_2 = 0x00020000 // nRTS Trigger Level is 8 bytes
    ,RTSTRGLV_3 = 0x00030000 // nRTS Trigger Level is 14 bytes
    ,FIFO_MASK = 0x000F01F6
    ;
  };
  // UART Line Control Register
  struct LINE : reg<ip_ver, base + 0xC>
  {
    static constexpr typename LINE::type
    // Word Length Selection This field sets UART word length. (bits: 1-0)
     WLS_MASK = 0x00000003
    ,WLS_POS = 0
    ,WLS_0 = 0x00000000 // 5 bits
    ,WLS_1 = 0x00000001 // 6 bits
    ,WLS_2 = 0x00000002 // 7 bits
    ,WLS_3 = 0x00000003 // 8 bits
    // Number of 'STOP Bit' (bits: 2)
    ,NSB_MASK = 0x00000004
    ,NSB_POS = 2
    ,NSB_0 = 0x00000000 // One 'STOP bit' is generated in the transmitted data
    ,NSB_1 = 0x00000004 // When select 5-bit word length, 1.5 'STOP bit' is generated in the transmitted data. When select 6-, 7- and 8-bit word length, 2 'STOP bit' is generated in the transmitted data
    // PARITY Bit Enable Bit Note: PARITY bit is generated on each outgoing character and is checked on each incoming data. (bits: 3)
    ,PBE_MASK = 0x00000008
    ,PBE_POS = 3
    ,PBE_0 = 0x00000000 // PARITY bit generated Disabled
    ,PBE_1 = 0x00000008 // PARITY bit generated Enabled
    // Even Parity Enable Bit Note: This bit has effect only when PBE (UART_LINE[3]) is set. (bits: 4)
    ,EPE_MASK = 0x00000010
    ,EPE_POS = 4
    ,EPE_0 = 0x00000000 // Odd number of logic 1's is transmitted and checked in each word
    ,EPE_1 = 0x00000010 // Even number of logic 1's is transmitted and checked in each word
    // Stick Parity Enable Bit Note: If PBE (UART_LINE[3]) and EPE (UART_LINE[4]) are logic 1, the PARITY bit is transmitted and checked as logic 0. If PBE (UART_LINE[3]) is 1 and EPE (UART_LINE[4]) is 0 then the PARITY bit is transmitted and checked as 1. (bits: 5)
    ,SPE_MASK = 0x00000020
    ,SPE_POS = 5
    ,SPE_0 = 0x00000000 // Stick parity Disabled
    ,SPE_1 = 0x00000020 // Stick parity Enabled
    // Break Control Bit Note: When this bit is set to logic 1, the transmitted serial data output (TX) is forced to the Spacing State (logic 0). This bit acts only on TX line and has no effect on the transmitter logic. (bits: 6)
    ,BCB_MASK = 0x00000040
    ,BCB_POS = 6
    ,BCB_0 = 0x00000000 // Break Control Disabled
    ,BCB_1 = 0x00000040 // Break Control Enabled
    // PARITY Bit Source Selection The PARITY bit can be selected to be generated and checked automatically or by software. Note 1: This bit has effect only when PBE (UART_LINE[3]) is set. Note 2: If PSS is 0, the PARITY bit is transmitted and checked automatically. If PSS is 1, the transmitted PARITY bit value can be determined by writing PARITY (UART_DAT[8]) and the PARITY bit can be read by reading PARITY (UART_DAT[8]). (bits: 7)
    ,PSS_MASK = 0x00000080
    ,PSS_POS = 7
    ,PSS_0 = 0x00000000 // PARITY bit is generated by EPE (UART_LINE[4]) and SPE (UART_LINE[5]) setting and checked automatically
    ,PSS_1 = 0x00000080 // PARITY bit generated and checked by software
    // TX Data Inverted Note 1: Before setting this bit, TXRXDIS (UART_FUNCSEL[3]) should be set then waited for TXRXACT (UART_FIFOSTS[31]) is cleared. When the configuration is done, cleared TXRXDIS (UART_FUNCSEL[3]) to activate UART controller. Note 2: This bit is valid when FUNCSEL (UART_FUNCSEL[1:0]) is select UART, LIN or RS485 function. (bits: 8)
    ,TXDINV_MASK = 0x00000100
    ,TXDINV_POS = 8
    ,TXDINV_0 = 0x00000000 // Transmitted data signal inverted Disabled
    ,TXDINV_1 = 0x00000100 // Transmitted data signal inverted Enabled
    // RX Data Inverted Note 1: Before setting this bit, TXRXDIS (UART_FUNCSEL[3]) should be set then waited for TXRXACT (UART_FIFOSTS[31]) is cleared. When the configuration is done, cleared TXRXDIS (UART_FUNCSEL[3]) to activate UART controller. Note 2: This bit is valid when FUNCSEL (UART_FUNCSEL[1:0]) is select UART, LIN or RS485 function. (bits: 9)
    ,RXDINV_MASK = 0x00000200
    ,RXDINV_POS = 9
    ,RXDINV_0 = 0x00000000 // Received data signal inverted Disabled
    ,RXDINV_1 = 0x00000200 // Received data signal inverted Enabled
    ,LINE_MASK = 0x000003FF
    ;
  };
  // UART Modem Control Register
  struct MODEM : reg<ip_ver, base + 0x10, 0x00000200>
  {
    static constexpr typename MODEM::type
    // nRTS (Request-to-send) Signal Control This bit is direct control internal nRTS signal active or not, and then drive the nRTS pin output with RTSACTLV bit configuration. Note 1: The nRTS signal control bit is not effective when nRTS auto-flow control is enabled in UART function mode. Note 2: The nRTS signal control bit is not effective when RS-485 auto direction mode (AUD) is enabled in RS-485 function mode. Note 3: Single-wire mode is support this feature. (bits: 1)
     RTS_MASK = 0x00000002
    ,RTS_POS = 1
    ,RTS_0 = 0x00000000 // nRTS signal is active
    ,RTS_1 = 0x00000002 // nRTS signal is inactive
    // nRTS Pin Active Level This bit defines the active level state of nRTS pin output. Note 1: Refer to Figure 6.1613 and Figure 6.1614 for UART function mode. Note 2: Refer to Figure 6.1624 and Figure 6.1625 for RS-485 function mode. Note 3: Before setting this bit, TXRXDIS (UART_FUNCSEL[3]) should be set then waited for TXRXACT (UART_FIFOSTS[31]) is cleared. When the configuration is done, cleared TXRXDIS (UART_FUNCSEL[3]) to activate UART controller. (bits: 9)
    ,RTSACTLV_MASK = 0x00000200
    ,RTSACTLV_POS = 9
    ,RTSACTLV_0 = 0x00000000 // nRTS pin output is high level active
    ,RTSACTLV_1 = 0x00000200 // nRTS pin output is low level active. (Default)
    // nRTS Pin Status (Read Only) This bit mirror from nRTS pin output of voltage logic status. (bits: 13)
    ,RTSSTS_MASK = 0x00002000
    ,RTSSTS_POS = 13
    ,RTSSTS_0 = 0x00000000 // nRTS pin output is low level voltage logic state
    ,RTSSTS_1 = 0x00002000 // nRTS pin output is high level voltage logic state
    ,MODEM_MASK = 0x00002202
    ;
  };
  // UART Modem Status Register
  struct MODEMSTS : reg<ip_ver, base + 0x14, 0x00000110>
  {
    static constexpr typename MODEMSTS::type
    // Detect nCTS State Change Flag This bit is set whenever nCTS input has change state, and it will generate Modem interrupt to CPU when MODEMIEN (UART_INTEN [3]) is set to 1. Note: This bit can be cleared by writing '1' to it. (bits: 0)
     CTSDETF_MASK = 0x00000001
    ,CTSDETF_POS = 0
    ,CTSDETF_0 = 0x00000000 // nCTS input has not change state
    ,CTSDETF_1 = 0x00000001 // nCTS input has change state
    // nCTS Pin Status (Read Only) This bit mirror from nCTS pin input of voltage logic status. Note: This bit echoes when UART controller peripheral clock is enabled, and nCTS multi-function port is selected. (bits: 4)
    ,CTSSTS_MASK = 0x00000010
    ,CTSSTS_POS = 4
    ,CTSSTS_0 = 0x00000000 // nCTS pin input is low level voltage logic state
    ,CTSSTS_1 = 0x00000010 // nCTS pin input is high level voltage logic state
    // nCTS Pin Active Level This bit defines the active level state of nCTS pin input. Note: Before setting this bit, TXRXDIS (UART_FUNCSEL[3]) should be set then waited for TXRXACT (UART_FIFOSTS[31]) is cleared. When the configuration is done, cleared TXRXDIS (UART_FUNCSEL[3]) to activate UART controller. (bits: 8)
    ,CTSACTLV_MASK = 0x00000100
    ,CTSACTLV_POS = 8
    ,CTSACTLV_0 = 0x00000000 // nCTS pin input is high level active
    ,CTSACTLV_1 = 0x00000100 // nCTS pin input is low level active. (Default)
    ,MODEMSTS_MASK = 0x00000111
    ;
  };
  // UART FIFO Status Register
  struct FIFOSTS : reg<ip_ver, base + 0x18>
  {
    static constexpr typename FIFOSTS::type
    // RX Overflow Error Interrupt Flag This bit is set when RX FIFO overflow. If the number of bytes of received data is greater than RX_FIFO (UART_DAT) size 16 bytes, this bit will be set. Note: This bit can be cleared by writing '1' to it. (bits: 0)
     RXOVIF_MASK = 0x00000001
    ,RXOVIF_POS = 0
    ,RXOVIF_0 = 0x00000000 // RX FIFO is not overflow
    ,RXOVIF_1 = 0x00000001 // RX FIFO is overflow
    // Auto-baud Rate Detect Interrupt Flag This bit is set to logic '1' when auto-baud rate detect function is finished. Note: This bit can be cleared by writing '1' to it. (bits: 1)
    ,ABRDIF_MASK = 0x00000002
    ,ABRDIF_POS = 1
    ,ABRDIF_0 = 0x00000000 // Auto-baud rate detect function is not finished
    ,ABRDIF_1 = 0x00000002 // Auto-baud rate detect function is finished
    // Auto-baud Rate Detect Time-out Interrupt Flag This bit is set to logic '1' in Auto-baud Rate Detect mode when the baud rate counter is overflow. Note: This bit can be cleared by writing '1' to it. (bits: 2)
    ,ABRDTOIF_MASK = 0x00000004
    ,ABRDTOIF_POS = 2
    ,ABRDTOIF_0 = 0x00000000 // Auto-baud rate counter is underflow
    ,ABRDTOIF_1 = 0x00000004 // Auto-baud rate counter is overflow
    // RS-485 Address Byte Detect Flag Note 1: This field is used for RS-485 function mode and ADDRDEN (UART_ALTCTL[15]) is set to 1 to enable Address detection mode. Note 2: This bit can be cleared by writing '1' to it. (bits: 3)
    ,ADDRDETF_MASK = 0x00000008
    ,ADDRDETF_POS = 3
    ,ADDRDETF_0 = 0x00000000 // Receiver detects a data that is not an address bit (bit 9 ='0')
    ,ADDRDETF_1 = 0x00000008 // Receiver detects a data that is an address bit (bit 9 ='1')
    // Parity Error Flag This bit is set to logic 1 whenever the received character does not have a valid 'PARITY bit'. Note: This bit can be cleared by writing '1' to it. (bits: 4)
    ,PEF_MASK = 0x00000010
    ,PEF_POS = 4
    ,PEF_0 = 0x00000000 // No parity error is generated
    ,PEF_1 = 0x00000010 // Parity error is generated
    // Framing Error Flag This bit is set to logic 1 whenever the received character does not have a valid 'STOP bit' (that is, the STOP bit following the last data bit or PARITY bit is detected as logic 0). Note: This bit can be cleared by writing '1' to it. (bits: 5)
    ,FEF_MASK = 0x00000020
    ,FEF_POS = 5
    ,FEF_0 = 0x00000000 // No framing error is generated
    ,FEF_1 = 0x00000020 // Framing error is generated
    // Break Interrupt Flag This bit is set to logic 1 whenever the received data input (RX) is held in the 'spacing state' (logic 0) for longer than a full word transmission time (that is, the total time of 'START bit' + data bits + parity + STOP bits). Note: This bit can be cleared by writing '1' to it. (bits: 6)
    ,BIF_MASK = 0x00000040
    ,BIF_POS = 6
    ,BIF_0 = 0x00000000 // No Break interrupt is generated
    ,BIF_1 = 0x00000040 // Break interrupt is generated
    // RX FIFO Pointer (Read Only) This field indicates the RX FIFO Buffer Pointer. When UART receives one byte from external device, RXPTR increases one. When one byte of RX FIFO is read by CPU, RXPTR decreases one. The Maximum value shown in RXPTR is 15. When the using level of RX FIFO Buffer equal to 16, the RXFULL bit is set to 1 and RXPTR will show 0. As one byte of RX FIFO is read by CPU, the RXFULL bit is cleared to 0 and RXPTR will show 15. (bits: 13-8)
    ,RXPTR_MASK = 0x00003F00
    ,RXPTR_POS = 8
    // Receiver FIFO Empty (Read Only) This bit initiate RX FIFO empty or not. Note: When the last byte of RX FIFO has been read by CPU, hardware sets this bit high. It will be cleared when UART receives any new data. (bits: 14)
    ,RXEMPTY_MASK = 0x00004000
    ,RXEMPTY_POS = 14
    ,RXEMPTY_0 = 0x00000000 // RX FIFO is not empty
    ,RXEMPTY_1 = 0x00004000 // RX FIFO is empty
    // Receiver FIFO Full (Read Only) This bit initiates RX FIFO full or not. Note: This bit is set when the number of usage in RX FIFO Buffer is equal to 16, otherwise it is cleared by hardware. (bits: 15)
    ,RXFULL_MASK = 0x00008000
    ,RXFULL_POS = 15
    ,RXFULL_0 = 0x00000000 // RX FIFO is not full
    ,RXFULL_1 = 0x00008000 // RX FIFO is full
    // TX FIFO Pointer (Read Only) This field indicates the TX FIFO Buffer Pointer. When CPU writes one byte into UART_DAT, TXPTR increases one. When one byte of TX FIFO is transferred to Transmitter Shift Register, TXPTR decreases one. The Maximum value shown in TXPTR is 15. When the using level of TX FIFO Buffer equal to 16, the TXFULL bit is set to 1 and TXPTR will show 0. As one byte of TX FIFO is transferred to Transmitter Shift Register, the TXFULL bit is cleared to 0 and TXPTR will show 15. (bits: 21-16)
    ,TXPTR_MASK = 0x003F0000
    ,TXPTR_POS = 16
    // Transmitter FIFO Empty (Read Only) This bit indicates TX FIFO empty or not. Note: When the last byte of TX FIFO has been transferred to Transmitter Shift Register, hardware sets this bit high. It will be cleared when writing data into UART_DAT (TX FIFO not empty). (bits: 22)
    ,TXEMPTY_MASK = 0x00400000
    ,TXEMPTY_POS = 22
    ,TXEMPTY_0 = 0x00000000 // TX FIFO is not empty
    ,TXEMPTY_1 = 0x00400000 // TX FIFO is empty
    // Transmitter FIFO Full (Read Only) This bit indicates TX FIFO full or not. Note: This bit is set when the number of usage in TX FIFO Buffer is equal to 16, otherwise it is cleared by hardware. (bits: 23)
    ,TXFULL_MASK = 0x00800000
    ,TXFULL_POS = 23
    ,TXFULL_0 = 0x00000000 // TX FIFO is not full
    ,TXFULL_1 = 0x00800000 // TX FIFO is full
    // TX Overflow Error Interrupt Flag If TX FIFO (UART_DAT) is full, an additional write to UART_DAT will cause this bit to logic 1. Note: This bit can be cleared by writing '1' to it. (bits: 24)
    ,TXOVIF_MASK = 0x01000000
    ,TXOVIF_POS = 24
    ,TXOVIF_0 = 0x00000000 // TX FIFO is not overflow
    ,TXOVIF_1 = 0x01000000 // TX FIFO is overflow
    // Transmitter Empty Flag (Read Only) This bit is set by hardware when TX FIFO (UART_DAT) is empty and the STOP bit of the last byte has been transmitted. Note: This bit is cleared automatically when TX FIFO is not empty or the last byte transmission has not completed. (bits: 28)
    ,TXEMPTYF_MASK = 0x10000000
    ,TXEMPTYF_POS = 28
    ,TXEMPTYF_0 = 0x00000000 // TX FIFO is not empty or the STOP bit of the last byte has been not transmitted
    ,TXEMPTYF_1 = 0x10000000 // TX FIFO is empty and the STOP bit of the last byte has been transmitted
    // RX Idle Status (Read Only) This bit is set by hardware when RX is idle. (bits: 29)
    ,RXIDLE_MASK = 0x20000000
    ,RXIDLE_POS = 29
    ,RXIDLE_0 = 0x00000000 // RX is busy
    ,RXIDLE_1 = 0x20000000 // RX is idle. (Default)
    // TX and RX Active Status (Read Only) This bit indicates TX and RX are active or inactive. Note: When TXRXDIS (UART_FUNCSEL[3]) is set and both TX and RX are in idle state, this bit is cleared. The UART controller can not transmit or receive data at this moment. Otherwise this bit is set. (bits: 31)
    ,TXRXACT_MASK = 0x80000000
    ,TXRXACT_POS = 31
    ,TXRXACT_0 = 0x00000000 // TX and RX are inactive
    ,TXRXACT_1 = 0x80000000 // TX and RX are active. (Default)
    ,FIFOSTS_MASK = 0xB1FFFF7F
    ;
  };
  // UART Interrupt Status Register
  struct INTSTS : reg<ip_ver, base + 0x1C, 0x00400002>
  {
    static constexpr typename INTSTS::type
    // Receive Data Available Interrupt Flag (Read Only) When the number of bytes in the RX FIFO equals the RFITL then the RDAIF(UART_INTSTS[0]) will be set. If RDAIEN (UART_INTEN [0]) is enabled, the RDA interrupt will be generated. Note: This bit is read only and will be cleared when the number of unread bytes of RX FIFO drops below the threshold level (RFITL(UART_FIFO[7:4]). (bits: 0)
     RDAIF_MASK = 0x00000001
    ,RDAIF_POS = 0
    ,RDAIF_0 = 0x00000000 // No RDA interrupt flag is generated
    ,RDAIF_1 = 0x00000001 // RDA interrupt flag is generated
    // Transmit Holding Register Empty Interrupt Flag (Read Only) This bit is set when the last data of TX FIFO is transferred to Transmitter Shift Register. If THREIEN (UART_INTEN[1]) is enabled, the THRE interrupt will be generated. Note: This bit is read only and will be cleared when writing data into UART_DAT (TX FIFO is not empty). (bits: 1)
    ,THREIF_MASK = 0x00000002
    ,THREIF_POS = 1
    ,THREIF_0 = 0x00000000 // No THRE interrupt flag is generated
    ,THREIF_1 = 0x00000002 // THRE interrupt flag is generated
    // Receive Line Interrupt Flag (Read Only) This bit is set when the RX receive data have parity error, frame error or break error (at least one of 3 bits, BIF(UART_FIFOSTS[6]), FEF(UART_FIFOSTS[5]) and PEF(UART_FIFOSTS[4]), is set). If RLSIEN (UART_INTEN [2]) is enabled, the RLS interrupt will be generated. Note 2: This bit is read only and reset to 0 when all bits of BIF (UART_FIFOSTS[6]), FEF(UART_FIFOSTS[5]) and PEF(UART_FIFOSTS[4]) are cleared. Note 3: In RS-485 function mode, this bit is read only and reset to 0 when all bits of BIF (UART_FIFOSTS[6]), FEF(UART_FIFOSTS[5]), PEF(UART_FIFOSTS[4]) and ADDRDETF (UART_FIFOSTS[3]) are cleared. (bits: 2)
    ,RLSIF_MASK = 0x00000004
    ,RLSIF_POS = 2
    ,RLSIF_0 = 0x00000000 // No RLS interrupt flag is generated
    ,RLSIF_1 = 0x00000004 // RLS interrupt flag is generated
    // MODEM Interrupt Flag (Read Only) Note: This bit is read only and reset to 0 when bit CTSDETF is cleared by a write 1 on CTSDETF(UART_MODEMSTS[0]). (bits: 3)
    ,MODEMIF_MASK = 0x00000008
    ,MODEMIF_POS = 3
    ,MODEMIF_0 = 0x00000000 // No Modem interrupt flag is generated
    ,MODEMIF_1 = 0x00000008 // Modem interrupt flag is generated
    // RX Time-out Interrupt Flag (Read Only) This bit is set when the RX FIFO is not empty and no activities occurred in the RX FIFO and the time-out counter equal to TOIC (UART_TOUT[7:0]). If RXTOIEN (UART_INTEN [4]) is enabled, the RX time-out interrupt will be generated. Note: This bit is read only and user can read UART_DAT (RX is in active) to clear it. (bits: 4)
    ,RXTOIF_MASK = 0x00000010
    ,RXTOIF_POS = 4
    ,RXTOIF_0 = 0x00000000 // No RX time-out interrupt flag is generated
    ,RXTOIF_1 = 0x00000010 // RX time-out interrupt flag is generated
    // Buffer Error Interrupt Flag (Read Only) This bit is set when the TX FIFO or RX FIFO overflows (TXOVIF (UART_FIFOSTS[24]) or RXOVIF (UART_FIFOSTS[0]) is set). When BUFERRIF (UART_INTSTS[5]) is set, the transfer is not correct. If BUFERRIEN (UART_INTEN [5]) is enabled, the buffer error interrupt will be generated. Note: This bit is cleared if both of RXOVIF(UART_FIFOSTS[0]) and TXOVIF(UART_FIFOSTS[24]) are cleared to 0 by writing 1 to RXOVIF(UART_FIFOSTS[0]) and TXOVIF(UART_FIFOSTS[24]). (bits: 5)
    ,BUFERRIF_MASK = 0x00000020
    ,BUFERRIF_POS = 5
    ,BUFERRIF_0 = 0x00000000 // No buffer error interrupt flag is generated
    ,BUFERRIF_1 = 0x00000020 // Buffer error interrupt flag is generated
    // UART Wake-up Interrupt Flag (Read Only) This bit is set when TOUTWKF (UART_WKSTS[4]), RS485WKF (UART_WKSTS[3]), RFRTWKF (UART_WKSTS[2]), DATWKF (UART_WKSTS[1]) or CTSWKF(UART_WKSTS[0]) is set to 1. Note: This bit is cleared if all of TOUTWKF, RS485WKF, RFRTWKF, DATWKF and CTSWKF are cleared to 0 by writing 1 to the corresponding interrupt flag. (bits: 6)
    ,WKIF_MASK = 0x00000040
    ,WKIF_POS = 6
    ,WKIF_0 = 0x00000000 // No UART wake-up interrupt flag is generated
    ,WKIF_1 = 0x00000040 // UART wake-up interrupt flag is generated
    // LIN Bus Interrupt Flag Note: This bit is cleared when SLVHDETF(UART_LINSTS[0]), BRKDETF(UART_LINSTS[8]), BITEF(UART_LINSTS[9]), SLVIDPEF (UART_LINSTS[2]) and SLVHEF(UART_LINSTS[1]) all are cleared and software writing '1' to LINIF(UART_INTSTS[7]). (bits: 7)
    ,LINIF_MASK = 0x00000080
    ,LINIF_POS = 7
    ,LINIF_0 = 0x00000000 // None of SLVHDETF, BRKDETF, BITEF, SLVIDPEF and SLVHEF is generated
    ,LINIF_1 = 0x00000080 // At least one of SLVHDETF, BRKDETF, BITEF, SLVIDPEF and SLVHEF is generated
    // Receive Data Available Interrupt Indicator (Read Only) This bit is set if RDAIEN (UART_INTEN[0]) and RDAIF (UART_INTSTS[0]) are both set to 1. (bits: 8)
    ,RDAINT_MASK = 0x00000100
    ,RDAINT_POS = 8
    ,RDAINT_0 = 0x00000000 // No RDA interrupt is generated
    ,RDAINT_1 = 0x00000100 // RDA interrupt is generated
    // Transmit Holding Register Empty Interrupt Indicator (Read Only) This bit is set if THREIEN (UART_INTEN[1]) and THREIF(UART_INTSTS[1]) are both set to 1. (bits: 9)
    ,THREINT_MASK = 0x00000200
    ,THREINT_POS = 9
    ,THREINT_0 = 0x00000000 // No THRE interrupt is generated
    ,THREINT_1 = 0x00000200 // THRE interrupt is generated
    // Receive Line Status Interrupt Indicator (Read Only) This bit is set if RLSIEN (UART_INTEN[2]) and RLSIF(UART_INTSTS[2]) are both set to 1. (bits: 10)
    ,RLSINT_MASK = 0x00000400
    ,RLSINT_POS = 10
    ,RLSINT_0 = 0x00000000 // No RLS interrupt is generated
    ,RLSINT_1 = 0x00000400 // RLS interrupt is generated
    // MODEM Status Interrupt Indicator (Read Only) This bit is set if MODEMIEN(UART_INTEN[3]) and MODEMIF(UART_INTSTS[3]) are both set to 1 (bits: 11)
    ,MODEMINT_MASK = 0x00000800
    ,MODEMINT_POS = 11
    ,MODEMINT_0 = 0x00000000 // No Modem interrupt is generated
    ,MODEMINT_1 = 0x00000800 // Modem interrupt is generated
    // RX Time-out Interrupt Indicator (Read Only) This bit is set if RXTOIEN (UART_INTEN[4]) and RXTOIF(UART_INTSTS[4]) are both set to 1. (bits: 12)
    ,RXTOINT_MASK = 0x00001000
    ,RXTOINT_POS = 12
    ,RXTOINT_0 = 0x00000000 // No RX time-out interrupt is generated
    ,RXTOINT_1 = 0x00001000 // RX time-out interrupt is generated
    // Buffer Error Interrupt Indicator (Read Only) This bit is set if BUFERRIEN(UART_INTEN[5]) and BUFERRIF(UART_ INTSTS[5]) are both set to 1. (bits: 13)
    ,BUFERRINT_MASK = 0x00002000
    ,BUFERRINT_POS = 13
    ,BUFERRINT_0 = 0x00000000 // No buffer error interrupt is generated
    ,BUFERRINT_1 = 0x00002000 // Buffer error interrupt is generated
    // UART Wake-up Interrupt Indicator (Read Only) This bit is set if WKIEN (UART_INTEN[6]) and WKIF (UART_INTSTS[6]) are both set to 1. (bits: 14)
    ,WKINT_MASK = 0x00004000
    ,WKINT_POS = 14
    ,WKINT_0 = 0x00000000 // No UART wake-up interrupt is generated
    ,WKINT_1 = 0x00004000 // UART wake-up interrupt is generated
    // LIN Bus Interrupt Indicator (Read Only) This bit is set if LINIEN (UART_INTEN[8]) and LINIF(UART_INTSTS[7]) are both set to 1. (bits: 15)
    ,LININT_MASK = 0x00008000
    ,LININT_POS = 15
    ,LININT_0 = 0x00000000 // No LIN Bus interrupt is generated
    ,LININT_1 = 0x00008000 // The LIN Bus interrupt is generated
    // Single-wire Bit Error Detection Interrupt Flag This bit is set when the single wire bus state not equals to UART controller TX state in Single-wire mode. Note 1: This bit is active when FUNCSEL (UART_FUNCSEL[2:0]) is select UART Single-wire mode. Note 2: This bit can be cleared by writing '1' to it. (bits: 16)
    ,SBEIF_MASK = 0x00010000
    ,SBEIF_POS = 16
    ,SBEIF_0 = 0x00000000 // No single-wire bit error detection interrupt flag is generated
    ,SBEIF_1 = 0x00010000 // Single-wire bit error detection interrupt flag is generated
    // PDMA Mode Receive Line Status Flag (Read Only) This bit is set when the RX receive data have parity error, frame error or break error (at least one of 3 bits, BIF (UART_FIFOSTS[6]), FEF (UART_FIFOSTS[5]) and PEF (UART_FIFOSTS[4]) is set). If RLSIEN (UART_INTEN [2]) is enabled, the RLS interrupt will be generated. Note 2: In UART function mode, this bit is read only and reset to 0 when all bits of BIF(UART_FIFOSTS[6]), FEF(UART_FIFOSTS[5]) and PEF(UART_FIFOSTS[4]) are cleared. Note 3: In RS-485 function mode, this bit is read only and reset to 0 when all bits of BIF(UART_FIFOSTS[6]), FEF(UART_FIFOSTS[5]), PEF(UART_FIFOSTS[4]) and ADDRDETF (UART_FIFOSTS[3]) are cleared. (bits: 18)
    ,HWRLSIF_MASK = 0x00040000
    ,HWRLSIF_POS = 18
    ,HWRLSIF_0 = 0x00000000 // No RLS interrupt flag is generated in PDMA mode
    ,HWRLSIF_1 = 0x00040000 // RLS interrupt flag is generated in PDMA mode
    // PDMA Mode MODEM Interrupt Flag (Read Only) Note: This bit is read only and reset to 0 when the bit CTSDETF (UART_MODEMSTS[0]) is cleared by writing 1 on CTSDETF (UART_MODEMSTS [0]). (bits: 19)
    ,HWMODIF_MASK = 0x00080000
    ,HWMODIF_POS = 19
    ,HWMODIF_0 = 0x00000000 // No Modem interrupt flag is generated in PDMA mode
    ,HWMODIF_1 = 0x00080000 // Modem interrupt flag is generated in PDMA mode
    // PDMA Mode RX Time-out Interrupt Flag (Read Only) This bit is set when the RX FIFO is not empty and no activities occurred in the RX FIFO and the time-out counter equal to TOIC (UART_TOUT[7:0]). If RXTOIEN (UART_INTEN [4]) is enabled, the RX time-out interrupt will be generated. Note: This bit is read only and user can read UART_DAT (RX is in active) to clear it. (bits: 20)
    ,HWTOIF_MASK = 0x00100000
    ,HWTOIF_POS = 20
    ,HWTOIF_0 = 0x00000000 // No RX time-out interrupt flag is generated in PDMA mode
    ,HWTOIF_1 = 0x00100000 // RX time-out interrupt flag is generated in PDMA mode
    // PDMA Mode Buffer Error Interrupt Flag (Read Only) This bit is set when the TX or RX FIFO overflows (TXOVIF (UART_FIFOSTS [24]) or RXOVIF (UART_FIFOSTS[0]) is set). When BUFERRIF (UART_INTSTS[5]) is set, the transfer maybe is not correct. If BUFERRIEN (UART_INTEN [5]) is enabled, the buffer error interrupt will be generated. Note: This bit is cleared when both TXOVIF (UART_FIFOSTS[24]]) and RXOVIF (UART_FIFOSTS[0]) are cleared. (bits: 21)
    ,HWBUFEIF_MASK = 0x00200000
    ,HWBUFEIF_POS = 21
    ,HWBUFEIF_0 = 0x00000000 // No buffer error interrupt flag is generated in PDMA mode
    ,HWBUFEIF_1 = 0x00200000 // Buffer error interrupt flag is generated in PDMA mode
    // Transmitter Empty Interrupt Flag This bit is set when TX FIFO (UART_DAT) is empty and the STOP bit of the last byte has been transmitted (TXEMPTYF (UART_FIFOSTS[28]) is set). If TXENDIEN (UART_INTEN[22]) is enabled, the Transmitter Empty interrupt will be generated. Note: This bit is cleared automatically when TX FIFO is not empty or the last byte transmission has not completed. (bits: 22)
    ,TXENDIF_MASK = 0x00400000
    ,TXENDIF_POS = 22
    ,TXENDIF_0 = 0x00000000 // No transmitter empty interrupt flag is generated
    ,TXENDIF_1 = 0x00400000 // Transmitter empty interrupt flag is generated
    // Single-wire Bit Error Detect Interrupt Indicator (Read Only) This bit is set if SWBEIEN (UART_INTEN[16]) and SWBEIF (UART_INTSTS[16]) are both set to 1. (bits: 24)
    ,SWBEINT_MASK = 0x01000000
    ,SWBEINT_POS = 24
    ,SWBEINT_0 = 0x00000000 // No Single-wire Bit Error Detection Interrupt generated
    ,SWBEINT_1 = 0x01000000 // Single-wire Bit Error Detection Interrupt generated
    // PDMA Mode Receive Line Status Interrupt Indicator (Read Only) This bit is set if RLSIEN (UART_INTEN[2]) and HWRLSIF(UART_INTSTS[18]) are both set to 1. (bits: 26)
    ,HWRLSINT_MASK = 0x04000000
    ,HWRLSINT_POS = 26
    ,HWRLSINT_0 = 0x00000000 // No RLS interrupt is generated in PDMA mode
    ,HWRLSINT_1 = 0x04000000 // RLS interrupt is generated in PDMA mode
    // PDMA Mode MODEM Status Interrupt Indicator (Read Only) This bit is set if MODEMIEN (UART_INTEN[3]) and HWMODIF(UART_INTSTS[19]) are both set to 1. (bits: 27)
    ,HWMODINT_MASK = 0x08000000
    ,HWMODINT_POS = 27
    ,HWMODINT_0 = 0x00000000 // No Modem interrupt is generated in PDMA mode
    ,HWMODINT_1 = 0x08000000 // Modem interrupt is generated in PDMA mode
    // PDMA Mode RX Time-out Interrupt Indicator (Read Only) This bit is set if RXTOIEN (UART_INTEN[4]) and HWTOIF(UART_INTSTS[20]) are both set to 1. (bits: 28)
    ,HWTOINT_MASK = 0x10000000
    ,HWTOINT_POS = 28
    ,HWTOINT_0 = 0x00000000 // No RX time-out interrupt is generated in PDMA mode
    ,HWTOINT_1 = 0x10000000 // RX time-out interrupt is generated in PDMA mode
    // PDMA Mode Buffer Error Interrupt Indicator (Read Only) This bit is set if BUFERRIEN (UART_INTEN[5]) and HWBUFEIF (UART_INTSTS[21]) are both set to 1. (bits: 29)
    ,HWBUFEINT_MASK = 0x20000000
    ,HWBUFEINT_POS = 29
    ,HWBUFEINT_0 = 0x00000000 // No buffer error interrupt is generated in PDMA mode
    ,HWBUFEINT_1 = 0x20000000 // Buffer error interrupt is generated in PDMA mode
    // Transmitter Empty Interrupt Indicator (Read Only) This bit is set if TXENDIEN (UART_INTEN[22]) and TXENDIF(UART_INTSTS[22]) are both set to 1. (bits: 30)
    ,TXENDINT_MASK = 0x40000000
    ,TXENDINT_POS = 30
    ,TXENDINT_0 = 0x00000000 // No Transmitter Empty interrupt is generated
    ,TXENDINT_1 = 0x40000000 // Transmitter Empty interrupt is generated
    // Auto-baud Rate Interrupt Indicator (Read Only) This bit is set if ABRIEN (UART_INTEN[18]) and ABRIF (UART_ALTCTL[17]) are both set to 1. (bits: 31)
    ,ABRINT_MASK = 0x80000000
    ,ABRINT_POS = 31
    ,ABRINT_0 = 0x00000000 // No Auto-baud Rate interrupt is generated
    ,ABRINT_1 = 0x80000000 // The Auto-baud Rate interrupt is generated
    ,INTSTS_MASK = 0xFD7DFFFF
    ;
  };
  // UART Time-out Register
  struct TOUT : reg<ip_ver, base + 0x20>
  {
    static constexpr typename TOUT::type
    // Time-out Interrupt Comparator (bits: 7-0)
     TOIC_MASK = 0x000000FF
    ,TOIC_POS = 0
    // TX Delay Time Value This field is used to program the transfer delay time between the last STOP bit and next START bit. The unit is bit time. (bits: 15-8)
    ,DLY_MASK = 0x0000FF00
    ,DLY_POS = 8
    ,TOUT_MASK = 0x0000FFFF
    ;
  };
  // UART Baud Rate Divider Register
  struct BAUD : reg<ip_ver, base + 0x24, 0x0F000000>
  {
    static constexpr typename BAUD::type
    // Baud Rate Divider The field indicates the baud rate divider. This filed is used in baud rate calculation. The detail description is shown in Table 6.164. (bits: 15-0)
     BRD_MASK = 0x0000FFFF
    ,BRD_POS = 0
    // Extra Divider for BAUD Rate Mode 1 This field is used for baud rate calculation in mode 1 and has no effect for baud rate calculation in mode 0 and mode 2. The detail description is shown in Table 6.164. (bits: 27-24)
    ,EDIVM1_MASK = 0x0F000000
    ,EDIVM1_POS = 24
    // BAUD Rate Mode Selection Bit 0 This bit is baud rate mode selection bit 0. UART provides three baud rate calculation modes. This bit combines with BAUDM1 (UART_BAUD[29]) to select baud rate calculation mode. The detail description is shown in Table 6.164. (bits: 28)
    ,BAUDM0_MASK = 0x10000000
    ,BAUDM0_POS = 28
    ,BAUDM0 = 0x10000000
    // BAUD Rate Mode Selection Bit 1 This bit is baud rate mode selection bit 1. UART provides three baud rate calculation modes. This bit combines with BAUDM0 (UART_BAUD[28]) to select baud rate calculation mode. The detail description is shown in Table 6.164. Note: In IrDA mode must be operated in mode 0. (bits: 29)
    ,BAUDM1_MASK = 0x20000000
    ,BAUDM1_POS = 29
    ,BAUDM1 = 0x20000000
    ,BAUD_MASK = 0x3F00FFFF
    ;
  };
  // UART IrDA Control Register
  struct IRDA : reg<ip_ver, base + 0x28, 0x00000040>
  {
    static constexpr typename IRDA::type
    // IrDA Receiver/Transmitter Selection Enable Bit (bits: 1)
     TXEN_MASK = 0x00000002
    ,TXEN_POS = 1
    ,TXEN_0 = 0x00000000 // IrDA Transmitter Disabled and Receiver Enabled. (Default)
    ,TXEN_1 = 0x00000002 // IrDA Transmitter Enabled and Receiver Disabled
    // IrDA Inverse Transmitting Output Signal Note 1: Before setting this bit, TXRXDIS (UART_FUNCSEL[3]) should be set then waited for TXRXACT (UART_FIFOSTS[31]) is cleared. When the configuration is done, cleared TXRXDIS (UART_FUNCSEL[3]) to activate UART controller. Note 2: This bit is valid when FUNCSEL (UART_FUNCSEL[1:0]) is select IrDA function. (bits: 5)
    ,TXINV_MASK = 0x00000020
    ,TXINV_POS = 5
    ,TXINV_0 = 0x00000000 // None inverse transmitting signal. (Default)
    ,TXINV_1 = 0x00000020 // Inverse transmitting output signal
    // IrDA Inverse Receive Input Signal Note 1: Before setting this bit, TXRXDIS (UART_FUNCSEL[3]) should be set then waited for TXRXACT (UART_FIFOSTS[31]) is cleared. When the configuration is done, cleared TXRXDIS (UART_FUNCSEL[3]) to activate UART controller. Note 2: This bit is valid when FUNCSEL (UART_FUNCSEL[1:0]) is select IrDA function. (bits: 6)
    ,RXINV_MASK = 0x00000040
    ,RXINV_POS = 6
    ,RXINV_0 = 0x00000000 // None inverse receiving input signal
    ,RXINV_1 = 0x00000040 // Inverse receiving input signal. (Default)
    ,IRDA_MASK = 0x00000062
    ;
  };
  // UART Alternate Control/Status Register
  struct ALTCTL : reg<ip_ver, base + 0x2C, 0x0000000C>
  {
    static constexpr typename ALTCTL::type
    // UART LIN Break Field Length This field indicates a 4-bit LIN TX break field count. Note 1: This break field length is BRKFL + 1. (bits: 3-0)
     BRKFL_MASK = 0x0000000F
    ,BRKFL_POS = 0
    // LIN RX Enable Bit (bits: 6)
    ,LINRXEN_MASK = 0x00000040
    ,LINRXEN_POS = 6
    ,LINRXEN_0 = 0x00000000 // LIN RX mode Disabled
    ,LINRXEN_1 = 0x00000040 // LIN RX mode Enabled
    // LIN TX Break Mode Enable Bit Note: When TX break field transfer operation finished, this bit will be cleared automatically. (bits: 7)
    ,LINTXEN_MASK = 0x00000080
    ,LINTXEN_POS = 7
    ,LINTXEN_0 = 0x00000000 // LIN TX Break mode Disabled
    ,LINTXEN_1 = 0x00000080 // LIN TX Break mode Enabled
    // RS-485 Normal Multi-drop Operation Mode (NMM) Note: It cannot be active with RS-485_AAD operation mode. (bits: 8)
    ,RS485NMM_MASK = 0x00000100
    ,RS485NMM_POS = 8
    ,RS485NMM_0 = 0x00000000 // RS-485 Normal Multi-drop Operation mode (NMM) Disabled
    ,RS485NMM_1 = 0x00000100 // RS-485 Normal Multi-drop Operation mode (NMM) Enabled
    // RS-485 Auto Address Detection Operation Mode (AAD) Note: It cannot be active with RS-485_NMM operation mode. (bits: 9)
    ,RS485AAD_MASK = 0x00000200
    ,RS485AAD_POS = 9
    ,RS485AAD_0 = 0x00000000 // RS-485 Auto Address Detection Operation mode (AAD) Disabled
    ,RS485AAD_1 = 0x00000200 // RS-485 Auto Address Detection Operation mode (AAD) Enabled
    // RS-485 Auto Direction Function (AUD) Note: It can be active with RS-485_AAD or RS-485_NMM operation mode. (bits: 10)
    ,RS485AUD_MASK = 0x00000400
    ,RS485AUD_POS = 10
    ,RS485AUD_0 = 0x00000000 // RS-485 Auto Direction Operation function (AUD) Disabled
    ,RS485AUD_1 = 0x00000400 // RS-485 Auto Direction Operation function (AUD) Enabled
    // RS-485 Address Detection Enable Bit This bit is used to enable RS-485 Address Detection mode. Note: This bit is used for RS-485 any operation mode. (bits: 15)
    ,ADDRDEN_MASK = 0x00008000
    ,ADDRDEN_POS = 15
    ,ADDRDEN_0 = 0x00000000 // Address detection mode Disabled
    ,ADDRDEN_1 = 0x00008000 // Address detection mode Enabled
    // Auto-baud Rate Interrupt Flag (Read Only) This bit is set when auto-baud rate detection function finished or the auto-baud rate counter was overflow and if ABRIEN(UART_INTEN [18]) is set then the auto-baud rate interrupt will be generated. Note: This bit is read only, but it can be cleared by writing '1' to ABRDTOIF (UART_FIFOSTS[2]) and ABRDIF(UART_FIFOSTS[1]). (bits: 17)
    ,ABRIF_MASK = 0x00020000
    ,ABRIF_POS = 17
    ,ABRIF_0 = 0x00000000 // No auto-baud rate interrupt flag is generated
    ,ABRIF_1 = 0x00020000 // Auto-baud rate interrupt flag is generated
    // Auto-baud Rate Detect Enable Bit Note : This bit is cleared automatically after auto-baud detection is finished. (bits: 18)
    ,ABRDEN_MASK = 0x00040000
    ,ABRDEN_POS = 18
    ,ABRDEN_0 = 0x00000000 // Auto-baud rate detect function Disabled
    ,ABRDEN_1 = 0x00040000 // Auto-baud rate detect function Enabled
    // Auto-baud Rate Detect Bit Length Note : The calculation of bit number includes the START bit. (bits: 20-19)
    ,ABRDBITS_MASK = 0x00180000
    ,ABRDBITS_POS = 19
    ,ABRDBITS_0 = 0x00000000 // 1-bit time from START bit to the 1st rising edge. The input pattern shall be 0x01
    ,ABRDBITS_1 = 0x00080000 // 2-bit time from START bit to the 1st rising edge. The input pattern shall be 0x02
    ,ABRDBITS_2 = 0x00100000 // 4-bit time from START bit to the 1st rising edge. The input pattern shall be 0x08
    ,ABRDBITS_3 = 0x00180000 // 8-bit time from START bit to the 1st rising edge. The input pattern shall be 0x80
    // Address Match Value This field contains the RS-485 address match values. Note: This field is used for RS-485 auto address detection mode. (bits: 31-24)
    ,ADDRMV_MASK = 0xFF000000
    ,ADDRMV_POS = 24
    ,ALTCTL_MASK = 0xFF1E87CF
    ;
  };
  // UART Function Select Register
  struct FUNCSEL : reg<ip_ver, base + 0x30>
  {
    static constexpr typename FUNCSEL::type
    // Function Select (bits: 2-0)
     FUNCSELVAL_MASK = 0x00000007
    ,FUNCSELVAL_POS = 0
    ,FUNCSELVAL_0 = 0x00000000 // UART function
    ,FUNCSELVAL_1 = 0x00000001 // LIN function
    ,FUNCSELVAL_2 = 0x00000002 // IrDA function
    ,FUNCSELVAL_3 = 0x00000003 // RS-485 function
    ,FUNCSELVAL_4 = 0x00000004 // UART Single-wire function
    // TX and RX Disable Bit Setting this bit can disable TX and RX. Note: The TX and RX will not disable immediately when this bit is set. The TX and RX compelet current task before disable TX and RX. When TX and RX disable, the TXRXACT (UART_FIFOSTS[31]) is cleared. (bits: 3)
    ,TXRXDIS_MASK = 0x00000008
    ,TXRXDIS_POS = 3
    ,TXRXDIS_0 = 0x00000000 // TX and RX Enabled
    ,TXRXDIS_1 = 0x00000008 // TX and RX Disabled
    ,FUNCSEL_MASK = 0x0000000F
    ;
  };
  // UART Baud Rate Compensation Register
  struct BRCOMP : reg<ip_ver, base + 0x3C>
  {
    static constexpr typename BRCOMP::type
    // Baud Rate Compensation Patten These 9-bits are used to define the relative bit is compensated or not. BRCOMP[7:0] is used to define the compensation of UART_DAT[7:0] and BRCOM[8] is used to define the PARITY bit. (bits: 8-0)
     BRCOMPVAL_MASK = 0x000001FF
    ,BRCOMPVAL_POS = 0
    // Baud Rate Compensation Decrease (bits: 31)
    ,BRCOMPDEC_MASK = 0x80000000
    ,BRCOMPDEC_POS = 31
    ,BRCOMPDEC_0 = 0x00000000 // Positive (increase one module clock) compensation for each compensated bit
    ,BRCOMPDEC_1 = 0x80000000 // Negative (decrease one module clock) compensation for each compensated bit
    ,BRCOMP_MASK = 0x800001FF
    ;
  };
  // UART Wake-up Control Register
  struct WKCTL : reg<ip_ver, base + 0x40>
  {
    static constexpr typename WKCTL::type
    // nCTS Wake-up Enable Bit Note:When the system is in Power-down mode, an external.nCTS change will wake up system from Power-down mode. (bits: 0)
     WKCTSEN_MASK = 0x00000001
    ,WKCTSEN_POS = 0
    ,WKCTSEN_0 = 0x00000000 // nCTS Wake-up system function Disabled
    ,WKCTSEN_1 = 0x00000001 // nCTS Wake-up system function Enabled
    // Incoming Data Wake-up Enable Bit Note:When the system is in Power-down mode, incoming data will wake-up system from Power-down mode. (bits: 1)
    ,WKDATEN_MASK = 0x00000002
    ,WKDATEN_POS = 1
    ,WKDATEN_0 = 0x00000000 // Incoming data wake-up system function Disabled
    ,WKDATEN_1 = 0x00000002 // Incoming data wake-up system function Enabled
    // Received Data FIFO Reached Threshold Wake-up Enable Bit Note: When the system is in Power-down mode, Received Data FIFO reached threshold will wake-up system from Power-down mode. (bits: 2)
    ,WKRFRTEN_MASK = 0x00000004
    ,WKRFRTEN_POS = 2
    ,WKRFRTEN_0 = 0x00000000 // Received Data FIFO reached threshold wake-up system function Disabled
    ,WKRFRTEN_1 = 0x00000004 // Received Data FIFO reached threshold wake-up system function Enabled
    // RS-485 Address Match (AAD Mode) Wake-up Enable Bit Note 1: When the system is in.Power-down mode, RS-485 Address Match will wake-up system from Power-down mode. Note 2: This bit is used for RS-485 Auto Address Detection (AAD) mode in RS-485 function mode and ADDRDEN (UART_ALTCTL[15]) is set to 1. (bits: 3)
    ,WKRS485EN_MASK = 0x00000008
    ,WKRS485EN_POS = 3
    ,WKRS485EN_0 = 0x00000000 // RS-485 Address Match (AAD mode) wake-up system function Disabled
    ,WKRS485EN_1 = 0x00000008 // RS-485 Address Match (AAD mode) wake-up system function Enabled
    // Received Data FIFO Reached Threshold Time-out Wake-up Enable Bit Note 1: When the system is in Power-down mode, Received Data FIFO reached threshold time-out will wake up system from Power-down mode. Note 2: It is suggested the function is enabled when the WKRFRTEN (UART_WKCTL[2]) is set to 1. (bits: 4)
    ,WKTOUTEN_MASK = 0x00000010
    ,WKTOUTEN_POS = 4
    ,WKTOUTEN_0 = 0x00000000 // Received Data FIFO reached threshold time-out wake-up system function Disabled
    ,WKTOUTEN_1 = 0x00000010 // Received Data FIFO reached threshold time-out wake-up system function Enabled
    ,WKCTL_MASK = 0x0000001F
    ;
  };
  // UART Wake-up Status Register
  struct WKSTS : reg<ip_ver, base + 0x44>
  {
    static constexpr typename WKSTS::type
    // nCTS Wake-up Flag This bit is set if chip wake-up from power-down state by nCTS wake-up. Note 1: If WKCTSEN (UART_WKCTL[0]) is enabled, the nCTS wake-up cause this bit is set to '1'. Note 2: This bit can be cleared by writing '1' to it. (bits: 0)
     CTSWKF_MASK = 0x00000001
    ,CTSWKF_POS = 0
    ,CTSWKF_0 = 0x00000000 // Chip stays in power-down state
    ,CTSWKF_1 = 0x00000001 // Chip wake-up from power-down state by nCTS wake-up
    // Incoming Data Wake-up Flag This bit is set if chip wake-up from power-down state by data wake-up. Note 1: If WKDATEN (UART_WKCTL[1]) is enabled, the Incoming Data wake-up cause this bit is set to '1'. Note 2: This bit can be cleared by writing '1' to it. (bits: 1)
    ,DATWKF_MASK = 0x00000002
    ,DATWKF_POS = 1
    ,DATWKF_0 = 0x00000000 // Chip stays in power-down state
    ,DATWKF_1 = 0x00000002 // Chip wake-up from power-down state by Incoming Data wake-up
    // Received Data FIFO Reached Threshold Wake-up Flag This bit is set if chip wake-up from power-down state by Received Data FIFO reached threshold wake-up. Note 1: If WKRFRTEN (UART_WKCTL[2]) is enabled, the Received Data FIFO Reached Threshold wake-up cause this bit is set to '1'. Note 2: This bit can be cleared by writing '1' to it. (bits: 2)
    ,RFRTWKF_MASK = 0x00000004
    ,RFRTWKF_POS = 2
    ,RFRTWKF_0 = 0x00000000 // Chip stays in power-down state
    ,RFRTWKF_1 = 0x00000004 // Chip wake-up from power-down state by Received Data FIFO Reached Threshold wake-up
    // RS-485 Address Match (AAD Mode) Wake-up Flag This bit is set if chip wake-up from power-down state by RS-485 Address Match (AAD mode). Note 1: If WKRS485EN (UART_WKCTL[3]) is enabled, the RS-485 Address Match (AAD mode) wake-up cause this bit is set to '1'. Note 2: This bit can be cleared by writing '1' to it. (bits: 3)
    ,RS485WKF_MASK = 0x00000008
    ,RS485WKF_POS = 3
    ,RS485WKF_0 = 0x00000000 // Chip stays in power-down state
    ,RS485WKF_1 = 0x00000008 // Chip wake-up from power-down state by RS-485 Address Match (AAD mode) wake-up
    // Received Data FIFO Threshold Time-out Wake-up Flag This bit is set if chip wake-up from power-down state by Received Data FIFO Threshold Time-out wake-up. Note 1: If WKTOUTEN (UART_WKCTL[4]) is enabled, the Received Data FIFO reached threshold time-out wake-up cause this bit is set to '1'. Note 2: This bit can be cleared by writing '1' to it. (bits: 4)
    ,TOUTWKF_MASK = 0x00000010
    ,TOUTWKF_POS = 4
    ,TOUTWKF_0 = 0x00000000 // Chip stays in power-down state
    ,TOUTWKF_1 = 0x00000010 // Chip wake-up from power-down state by Received Data FIFO reached threshold time-out
    ,WKSTS_MASK = 0x0000001F
    ;
  };
  // UART Incoming Data Wake-up Compensation Register
  struct DWKCOMP : reg<ip_ver, base + 0x48>
  {
    static constexpr typename DWKCOMP::type
    // START Bit Compensation Value These bits field indicate how many clock cycle selected by UART_CLK do the UART controller can get the 1st bit (START bit) when the device is wake-up from Power-down mode. Note: It is valid only when WKDATEN (UART_WKCTL[1]) is set. (bits: 15-0)
     STCOMP_MASK = 0x0000FFFF
    ,STCOMP_POS = 0
    ,DWKCOMP_MASK = 0x0000FFFF
    ;
  };
}; // struct UART

} // namespace lmcu::device::ip::v1

