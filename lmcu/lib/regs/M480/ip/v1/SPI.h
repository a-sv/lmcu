/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// SPI Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct SPI
{
  static constexpr auto ip_ver = ip_version::_1;

  // SPI Control Register
  struct CTL : reg<ip_ver, base + 0x0, 0x00000034>
  {
    static constexpr typename CTL::type
    // SPI Transfer Control Enable Bit In Master mode, the transfer will start when there is data in the FIFO buffer after this bit is set to 1. In Slave mode, this device is ready to receive data when this bit is set to 1. Note: Before changing the configurations of SPIx_CTL, SPIx_CLKDIV, SPIx_SSCTL and SPIx_FIFOCTL registers, user shall clear the SPIEN (SPIx_CTL[0]) and confirm the SPIENSTS (SPIx_STATUS[15]) is 0. (bits: 0)
     SPIEN_MASK = 0x00000001
    ,SPIEN_POS = 0
    ,SPIEN_0 = 0x00000000 // Transfer control Disabled
    ,SPIEN_1 = 0x00000001 // Transfer control Enabled
    // Receive on Negative Edge (bits: 1)
    ,RXNEG_MASK = 0x00000002
    ,RXNEG_POS = 1
    ,RXNEG_0 = 0x00000000 // Received data input signal is latched on the rising edge of SPI bus clock
    ,RXNEG_1 = 0x00000002 // Received data input signal is latched on the falling edge of SPI bus clock
    // Transmit on Negative Edge (bits: 2)
    ,TXNEG_MASK = 0x00000004
    ,TXNEG_POS = 2
    ,TXNEG_0 = 0x00000000 // Transmitted data output signal is changed on the rising edge of SPI bus clock
    ,TXNEG_1 = 0x00000004 // Transmitted data output signal is changed on the falling edge of SPI bus clock
    // Clock Polarity (bits: 3)
    ,CLKPOL_MASK = 0x00000008
    ,CLKPOL_POS = 3
    ,CLKPOL_0 = 0x00000000 // SPI bus clock is idle low
    ,CLKPOL_1 = 0x00000008 // SPI bus clock is idle high
    // Suspend Interval (Master Only) The four bits provide configurable suspend interval between two successive transmit/receive transaction in a transfer. The definition of the suspend interval is the interval between the last clock edge of the preceding transaction word and the first clock edge of the following transaction word. The default value is 0x3. The period of the suspend interval is obtained according to the following equation. (SUSPITV + 0.5) * period of SPICLK clock cycle Example: (bits: 7-4)
    ,SUSPITV_MASK = 0x000000F0
    ,SUSPITV_POS = 4
    // Data Width This field specifies how many bits can be transmitted / received in one transaction. The minimum bit length is 8 bits and can up to 32 bits. Note: This bit field will decide the depth of TX/RX FIFO configuration in SPI mode. Therefore, changing this bit field will clear TX/RX FIFO by hardware automatically. (bits: 12-8)
    ,DWIDTH_MASK = 0x00001F00
    ,DWIDTH_POS = 8
    // Send LSB First (bits: 13)
    ,LSB_MASK = 0x00002000
    ,LSB_POS = 13
    ,LSB_0 = 0x00000000 // The MSB, which bit of transmit/receive register depends on the setting of DWIDTH, is transmitted/received first
    ,LSB_1 = 0x00002000 // The LSB, bit 0 of the SPI TX register, is sent first to the SPI data output pin, and the first bit received from the SPI data input pin will be put in the LSB position of the RX register (bit 0 of SPI_RX)
    // SPI Half-duplex Transfer Enable Bit This bit is used to select full-duplex or half-duplex for SPI transfer. The bit field DATDIR (SPIx_CTL[20]) can be used to set the data direction in half-duplex transfer. (bits: 14)
    ,HALFDPX_MASK = 0x00004000
    ,HALFDPX_POS = 14
    ,HALFDPX_0 = 0x00000000 // SPI operates in full-duplex transfer
    ,HALFDPX_1 = 0x00004000 // SPI operates in half-duplex transfer
    // Receive-only Mode Enable Bit (Master Only) This bit field is only available in Master mode. In receive-only mode, SPI Master will generate SPI bus clock continuously for receiving data bit from SPI slave device and assert the BUSY status. (bits: 15)
    ,RXONLY_MASK = 0x00008000
    ,RXONLY_POS = 15
    ,RXONLY_0 = 0x00000000 // Receive-only mode Disabled
    ,RXONLY_1 = 0x00008000 // Receive-only mode Enabled
    // Unit Transfer Interrupt Enable Bit (bits: 17)
    ,UNITIEN_MASK = 0x00020000
    ,UNITIEN_POS = 17
    ,UNITIEN_0 = 0x00000000 // SPI unit transfer interrupt Disabled
    ,UNITIEN_1 = 0x00020000 // SPI unit transfer interrupt Enabled
    // Slave Mode Control (bits: 18)
    ,SLAVE_MASK = 0x00040000
    ,SLAVE_POS = 18
    ,SLAVE_0 = 0x00000000 // Master mode
    ,SLAVE_1 = 0x00040000 // Slave mode
    // Byte Reorder Function Enable Bit Note: Byte Reorder function is only available if DWIDTH is defined as 16, 24, and 32 bits. (bits: 19)
    ,REORDER_MASK = 0x00080000
    ,REORDER_POS = 19
    ,REORDER_0 = 0x00000000 // Byte Reorder function Disabled
    ,REORDER_1 = 0x00080000 // Byte Reorder function Enabled. A byte suspend interval will be inserted among each byte. The period of the byte suspend interval depends on the setting of SUSPITV
    // Data Port Direction Control This bit is used to select the data input/output direction in half-duplex transfer and Dual/Quad transfer (bits: 20)
    ,DATDIR_MASK = 0x00100000
    ,DATDIR_POS = 20
    ,DATDIR_0 = 0x00000000 // SPI data is input direction
    ,DATDIR_1 = 0x00100000 // SPI data is output direction
    ,CTL_MASK = 0x001EFFFF
    ;
  };
  // SPI Clock Divider Register
  struct CLKDIV : reg<ip_ver, base + 0x4>
  {
    static constexpr typename CLKDIV::type
    // Clock Divider The value in this field is the frequency divider for generating the peripheral clock, fspi_eclk, and the SPI bus clock of SPI Master. The frequency is obtained according to the following equation. where is the peripheral clock source, which is defined in the clock control register, CLK_CLKSEL2. Note 1: Not supported in I2S mode. Note 2: The time interval must be larger than or equal to 8 peripheral clock cycles between releasing SPI IP software reset and setting this clock divider register. (bits: 8-0)
     DIVIDER_MASK = 0x000001FF
    ,DIVIDER_POS = 0
    ,CLKDIV_MASK = 0x000001FF
    ;
  };
  // SPI Slave Select Control Register
  struct SSCTL : reg<ip_ver, base + 0x8>
  {
    static constexpr typename SSCTL::type
    // Slave Selection Control (Master Only) If AUTOSS bit is cleared to 0, (bits: 0)
     SS_MASK = 0x00000001
    ,SS_POS = 0
    ,SS_0 = 0x00000000 // set the SPIx_SS line to inactive state.\nKeep the SPIx_SS line at inactive state
    ,SS_1 = 0x00000001 // set the SPIx_SS line to active state.\nSPIx_SS line will be automatically driven to active state for the duration of data transfer, and will be driven to inactive state for the rest of the time. The active state of SPIx_SS is specified in SSACTPOL (SPIx_SSCTL[2])
    // Slave Selection Active Polarity This bit defines the active polarity of slave selection signal (SPIx_SS). (bits: 2)
    ,SSACTPOL_MASK = 0x00000004
    ,SSACTPOL_POS = 2
    ,SSACTPOL_0 = 0x00000000 // The slave selection signal SPIx_SS is active low
    ,SSACTPOL_1 = 0x00000004 // The slave selection signal SPIx_SS is active high
    // Automatic Slave Selection Function Enable Bit (Master Only) (bits: 3)
    ,AUTOSS_MASK = 0x00000008
    ,AUTOSS_POS = 3
    ,AUTOSS_0 = 0x00000000 // Automatic slave selection function Disabled. Slave selection signal will be asserted/de-asserted according to SS (SPIx_SSCTL[0])
    ,AUTOSS_1 = 0x00000008 // Automatic slave selection function Enabled
    // Slave Mode Bit Count Error Interrupt Enable Bit (bits: 8)
    ,SLVBEIEN_MASK = 0x00000100
    ,SLVBEIEN_POS = 8
    ,SLVBEIEN_0 = 0x00000000 // Slave mode bit count error interrupt Disabled
    ,SLVBEIEN_1 = 0x00000100 // Slave mode bit count error interrupt Enabled
    // Slave Mode TX Under Run Interrupt Enable Bit (bits: 9)
    ,SLVURIEN_MASK = 0x00000200
    ,SLVURIEN_POS = 9
    ,SLVURIEN_0 = 0x00000000 // Slave mode TX under run interrupt Disabled
    ,SLVURIEN_1 = 0x00000200 // Slave mode TX under run interrupt Enabled
    // Slave Select Active Interrupt Enable Bit (bits: 12)
    ,SSACTIEN_MASK = 0x00001000
    ,SSACTIEN_POS = 12
    ,SSACTIEN_0 = 0x00000000 // Slave select active interrupt Disabled
    ,SSACTIEN_1 = 0x00001000 // Slave select active interrupt Enabled
    // Slave Select Inactive Interrupt Enable Bit (bits: 13)
    ,SSINAIEN_MASK = 0x00002000
    ,SSINAIEN_POS = 13
    ,SSINAIEN_0 = 0x00000000 // Slave select inactive interrupt Disabled
    ,SSINAIEN_1 = 0x00002000 // Slave select inactive interrupt Enabled
    ,SSCTL_MASK = 0x0000330D
    ;
  };
  // SPI PDMA Control Register
  struct PDMACTL : reg<ip_ver, base + 0xC>
  {
    static constexpr typename PDMACTL::type
    // Transmit PDMA Enable Bit Note: In SPI Master mode with full duplex transfer, if both TX and RX PDMA functions are enabled, RX PDMA function cannot be enabled prior to TX PDMA function. User can enable TX PDMA function firstly or enable both functions simultaneously. (bits: 0)
     TXPDMAEN_MASK = 0x00000001
    ,TXPDMAEN_POS = 0
    ,TXPDMAEN_0 = 0x00000000 // Transmit PDMA function Disabled
    ,TXPDMAEN_1 = 0x00000001 // Transmit PDMA function Enabled
    // Receive PDMA Enable Bit (bits: 1)
    ,RXPDMAEN_MASK = 0x00000002
    ,RXPDMAEN_POS = 1
    ,RXPDMAEN_0 = 0x00000000 // Receive PDMA function Disabled
    ,RXPDMAEN_1 = 0x00000002 // Receive PDMA function Enabled
    // PDMA Reset (bits: 2)
    ,PDMARST_MASK = 0x00000004
    ,PDMARST_POS = 2
    ,PDMARST_0 = 0x00000000 // No effect
    ,PDMARST_1 = 0x00000004 // Reset the PDMA control logic of the SPI controller. This bit will be automatically cleared to 0
    ,PDMACTL_MASK = 0x00000007
    ;
  };
  // SPI FIFO Control Register
  struct FIFOCTL : reg<ip_ver, base + 0x10, 0x22000000>
  {
    static constexpr typename FIFOCTL::type
    // Receive Reset (bits: 0)
     RXRST_MASK = 0x00000001
    ,RXRST_POS = 0
    ,RXRST_0 = 0x00000000 // No effect
    ,RXRST_1 = 0x00000001 // Reset receive FIFO pointer and receive circuit. The RXFULL bit will be cleared to 0 and the RXEMPTY bit will be set to 1. This bit will be cleared to 0 by hardware about 3 system clock cycles + 2 peripheral clock cycles after it is set to 1. User can read TXRXRST (SPIx_STATUS[23]) to check if reset is accomplished or not
    // Transmit Reset Note: If TX underflow event occurs in SPI Slave mode, this bit can be used to make SPI return to idle state. (bits: 1)
    ,TXRST_MASK = 0x00000002
    ,TXRST_POS = 1
    ,TXRST_0 = 0x00000000 // No effect
    ,TXRST_1 = 0x00000002 // Reset transmit FIFO pointer and transmit circuit. The TXFULL bit will be cleared to 0 and the TXEMPTY bit will be set to 1. This bit will be cleared to 0 by hardware about 3 system clock cycles + 2 peripheral clock cycles after it is set to 1. User can read TXRXRST (SPIx_STATUS[23]) to check if reset is accomplished or not
    // Receive FIFO Threshold Interrupt Enable Bit (bits: 2)
    ,RXTHIEN_MASK = 0x00000004
    ,RXTHIEN_POS = 2
    ,RXTHIEN_0 = 0x00000000 // RX FIFO threshold interrupt Disabled
    ,RXTHIEN_1 = 0x00000004 // RX FIFO threshold interrupt Enabled
    // Transmit FIFO Threshold Interrupt Enable Bit (bits: 3)
    ,TXTHIEN_MASK = 0x00000008
    ,TXTHIEN_POS = 3
    ,TXTHIEN_0 = 0x00000000 // TX FIFO threshold interrupt Disabled
    ,TXTHIEN_1 = 0x00000008 // TX FIFO threshold interrupt Enabled
    // Slave Receive Time-out Interrupt Enable Bit (bits: 4)
    ,RXTOIEN_MASK = 0x00000010
    ,RXTOIEN_POS = 4
    ,RXTOIEN_0 = 0x00000000 // Receive time-out interrupt Disabled
    ,RXTOIEN_1 = 0x00000010 // Receive time-out interrupt Enabled
    // Receive FIFO Overrun Interrupt Enable Bit (bits: 5)
    ,RXOVIEN_MASK = 0x00000020
    ,RXOVIEN_POS = 5
    ,RXOVIEN_0 = 0x00000000 // Receive FIFO overrun interrupt Disabled
    ,RXOVIEN_1 = 0x00000020 // Receive FIFO overrun interrupt Enabled
    // TX Underflow Data Polarity Note 1: The TX underflow event occurs if there is no any data in TX FIFO when the slave selection signal is active. Note 2: This bit should be set as 0 in I2S mode. Note 3: When TX underflow event occurs, SPIx_MISO pin state will be determined by this setting even though TX FIFO is not empty afterward. Data stored in TX FIFO will be sent through SPIx_MISO pin in the next transfer frame. (bits: 6)
    ,TXUFPOL_MASK = 0x00000040
    ,TXUFPOL_POS = 6
    ,TXUFPOL_0 = 0x00000000 // The SPI data out is keep 0 if there is TX underflow event in Slave mode
    ,TXUFPOL_1 = 0x00000040 // The SPI data out is keep 1 if there is TX underflow event in Slave mode
    // TX Underflow Interrupt Enable Bit When TX underflow event occurs in Slave mode, TXUFIF (SPIx_STATUS[19]) will be set to 1. This bit is used to enable the TX underflow interrupt. (bits: 7)
    ,TXUFIEN_MASK = 0x00000080
    ,TXUFIEN_POS = 7
    ,TXUFIEN_0 = 0x00000000 // Slave TX underflow interrupt Disabled
    ,TXUFIEN_1 = 0x00000080 // Slave TX underflow interrupt Enabled
    // Receive FIFO Buffer Clear Note: The RX shift register will not be cleared. (bits: 8)
    ,RXFBCLR_MASK = 0x00000100
    ,RXFBCLR_POS = 8
    ,RXFBCLR_0 = 0x00000000 // No effect
    ,RXFBCLR_1 = 0x00000100 // Clear receive FIFO pointer. The RXFULL bit will be cleared to 0 and the RXEMPTY bit will be set to 1. This bit will be cleared to 0 by hardware about 1 system clock after it is set to 1
    // Transmit FIFO Buffer Clear Note: The TX shift register will not be cleared. (bits: 9)
    ,TXFBCLR_MASK = 0x00000200
    ,TXFBCLR_POS = 9
    ,TXFBCLR_0 = 0x00000000 // No effect
    ,TXFBCLR_1 = 0x00000200 // Clear transmit FIFO pointer. The TXFULL bit will be cleared to 0 and the TXEMPTY bit will be set to 1. This bit will be cleared to 0 by hardware about 1 system clock after it is set to 1
    // Receive FIFO Threshold If the valid data count of the receive FIFO buffer is larger than the (RXTH + 1) setting, the RXTHIF bit will be set to 1, else the RXTHIF bit will be cleared to 0. It could be 0~3. If SPI mode data width is 8~16 bits, it could be 0~7. (bits: 26-24)
    ,RXTH_MASK = 0x07000000
    ,RXTH_POS = 24
    // Transmit FIFO Threshold If the valid data count of the transmit FIFO buffer is less than or equal to the (TXTH + 1) setting, the TXTHIF bit will be set to 1, else the TXTHIF bit will be cleared to 0. It could be 0~3. If SPI mode data width is 8~16 bits, it could be 0~7. (bits: 30-28)
    ,TXTH_MASK = 0x70000000
    ,TXTH_POS = 28
    ,FIFOCTL_MASK = 0x770003FF
    ;
  };
  // SPI Status Register
  struct STATUS : reg<ip_ver, base + 0x14, 0x00050110>
  {
    static constexpr typename STATUS::type
    // Busy Status (Read Only) (bits: 0)
     BUSY_MASK = 0x00000001
    ,BUSY_POS = 0
    ,BUSY_0 = 0x00000000 // SPI controller is in idle state
    ,BUSY_1 = 0x00000001 // SPI controller is in busy state
    // Unit Transfer Interrupt Flag Note: This bit will be cleared by writing 1 to it. (bits: 1)
    ,UNITIF_MASK = 0x00000002
    ,UNITIF_POS = 1
    ,UNITIF_0 = 0x00000000 // No transaction has been finished since this bit was cleared to 0
    ,UNITIF_1 = 0x00000002 // SPI controller has finished one unit transfer
    // Slave Select Active Interrupt Flag Note: Only available in Slave mode. This bit will be cleared by writing 1 to it. (bits: 2)
    ,SSACTIF_MASK = 0x00000004
    ,SSACTIF_POS = 2
    ,SSACTIF_0 = 0x00000000 // Slave select active interrupt was cleared or not occurred
    ,SSACTIF_1 = 0x00000004 // Slave select active interrupt event occurred
    // Slave Select Inactive Interrupt Flag Note: Only available in Slave mode. This bit will be cleared by writing 1 to it. (bits: 3)
    ,SSINAIF_MASK = 0x00000008
    ,SSINAIF_POS = 3
    ,SSINAIF_0 = 0x00000000 // Slave select inactive interrupt was cleared or not occurred
    ,SSINAIF_1 = 0x00000008 // Slave select inactive interrupt event occurred
    // Slave Select Line Bus Status (Read Only) Note: This bit is only available in Slave mode. If SSACTPOL (SPIx_SSCTL[2]) is set 0, and the SSLINE is 1, the SPI slave select is in inactive status. (bits: 4)
    ,SSLINE_MASK = 0x00000010
    ,SSLINE_POS = 4
    ,SSLINE_0 = 0x00000000 // The slave select line status is 0
    ,SSLINE_1 = 0x00000010 // The slave select line status is 1
    // Slave Mode Bit Count Error Interrupt Flag In Slave mode, when the slave select line goes to inactive state, if bit counter is mismatch with DWIDTH, this interrupt flag will be set to 1. Note: If the slave select active but there is no any bus clock input, the SLVBEIF also active when the slave select goes to inactive state. This bit will be cleared by writing 1 to it (bits: 6)
    ,SLVBEIF_MASK = 0x00000040
    ,SLVBEIF_POS = 6
    ,SLVBEIF_0 = 0x00000000 // No Slave mode bit count error event
    ,SLVBEIF_1 = 0x00000040 // Slave mode bit count error event occurred
    // Slave Mode TX Under Run Interrupt Flag In Slave mode, if TX underflow event occurs and the slave select line goes to inactive state, this interrupt flag will be set to 1. Note: This bit will be cleared by writing 1 to it. (bits: 7)
    ,SLVURIF_MASK = 0x00000080
    ,SLVURIF_POS = 7
    ,SLVURIF_0 = 0x00000000 // No Slave TX under run event
    ,SLVURIF_1 = 0x00000080 // Slave TX under run event occurred
    // Receive FIFO Buffer Empty Indicator (Read Only) (bits: 8)
    ,RXEMPTY_MASK = 0x00000100
    ,RXEMPTY_POS = 8
    ,RXEMPTY_0 = 0x00000000 // Receive FIFO buffer is not empty
    ,RXEMPTY_1 = 0x00000100 // Receive FIFO buffer is empty
    // Receive FIFO Buffer Full Indicator (Read Only) (bits: 9)
    ,RXFULL_MASK = 0x00000200
    ,RXFULL_POS = 9
    ,RXFULL_0 = 0x00000000 // Receive FIFO buffer is not full
    ,RXFULL_1 = 0x00000200 // Receive FIFO buffer is full
    // Receive FIFO Threshold Interrupt Flag (Read Only) (bits: 10)
    ,RXTHIF_MASK = 0x00000400
    ,RXTHIF_POS = 10
    ,RXTHIF_0 = 0x00000000 // The valid data count within the receive FIFO buffer is smaller than or equal to the setting value of RXTH
    ,RXTHIF_1 = 0x00000400 // The valid data count within the receive FIFO buffer is larger than the setting value of RXTH
    // Receive FIFO Overrun Interrupt Flag When the receive FIFO buffer is full, the follow-up data will be dropped and this bit will be set to 1. Note: This bit will be cleared by writing 1 to it. (bits: 11)
    ,RXOVIF_MASK = 0x00000800
    ,RXOVIF_POS = 11
    ,RXOVIF_0 = 0x00000000 // No FIFO is overrun
    ,RXOVIF_1 = 0x00000800 // Receive FIFO is overrun
    // Receive Time-out Interrupt Flag Note: This bit will be cleared by writing 1 to it. (bits: 12)
    ,RXTOIF_MASK = 0x00001000
    ,RXTOIF_POS = 12
    ,RXTOIF_0 = 0x00000000 // No receive FIFO time-out event
    ,RXTOIF_1 = 0x00001000 // Receive FIFO buffer is not empty and no read operation on receive FIFO buffer over 64 SPI peripheral clock periods in Master mode or over 576 SPI peripheral clock periods in Slave mode. When the received FIFO buffer is read by software, the time-out status will be cleared automatically
    // SPI Enable Status (Read Only) Note: The SPI peripheral clock is asynchronous with the system clock. In order to make sure the SPI control logic is disabled, this bit indicates the real status of SPI controller. (bits: 15)
    ,SPIENSTS_MASK = 0x00008000
    ,SPIENSTS_POS = 15
    ,SPIENSTS_0 = 0x00000000 // SPI controller Disabled
    ,SPIENSTS_1 = 0x00008000 // SPI controller Enabled
    // Transmit FIFO Buffer Empty Indicator (Read Only) (bits: 16)
    ,TXEMPTY_MASK = 0x00010000
    ,TXEMPTY_POS = 16
    ,TXEMPTY_0 = 0x00000000 // Transmit FIFO buffer is not empty
    ,TXEMPTY_1 = 0x00010000 // Transmit FIFO buffer is empty
    // Transmit FIFO Buffer Full Indicator (Read Only) (bits: 17)
    ,TXFULL_MASK = 0x00020000
    ,TXFULL_POS = 17
    ,TXFULL_0 = 0x00000000 // Transmit FIFO buffer is not full
    ,TXFULL_1 = 0x00020000 // Transmit FIFO buffer is full
    // Transmit FIFO Threshold Interrupt Flag (Read Only) (bits: 18)
    ,TXTHIF_MASK = 0x00040000
    ,TXTHIF_POS = 18
    ,TXTHIF_0 = 0x00000000 // The valid data count within the transmit FIFO buffer is larger than the setting value of TXTH
    ,TXTHIF_1 = 0x00040000 // The valid data count within the transmit FIFO buffer is less than or equal to the setting value of TXTH
    // TX Underflow Interrupt Flag When the TX underflow event occurs, this bit will be set to 1, the state of data output pin depends on the setting of TXUFPOL. Note 1: This bit will be cleared by writing 1 to it. Note 2: If reset slave's transmission circuit when slave selection signal is active, this flag will be set to 1 after 2 peripheral clock cycles + 3 system clock cycles since the reset operation is done. (bits: 19)
    ,TXUFIF_MASK = 0x00080000
    ,TXUFIF_POS = 19
    ,TXUFIF_0 = 0x00000000 // No effect
    ,TXUFIF_1 = 0x00080000 // No data in Transmit FIFO and TX shift register when the slave selection signal is active
    // TX or RX Reset Status (Read Only) Note: Both the reset operations of TXRST and RXRST need 3 system clock cycles + 2 peripheral clock cycles. User can check the status of this bit to monitor the reset function is doing or done. (bits: 23)
    ,TXRXRST_MASK = 0x00800000
    ,TXRXRST_POS = 23
    ,TXRXRST_0 = 0x00000000 // The reset function of TXRST or RXRST is done
    ,TXRXRST_1 = 0x00800000 // Doing the reset function of TXRST or RXRST
    // Receive FIFO Data Count (Read Only) This bit field indicates the valid data count of receive FIFO buffer. (bits: 27-24)
    ,RXCNT_MASK = 0x0F000000
    ,RXCNT_POS = 24
    // Transmit FIFO Data Count (Read Only) This bit field indicates the valid data count of transmit FIFO buffer. (bits: 31-28)
    ,TXCNT_MASK = 0xF0000000
    ,TXCNT_POS = 28
    ,STATUS_MASK = 0xFF8F9FDF
    ;
  };
  // SPI Data Transmit Register
  struct TX : reg<ip_ver, base + 0x20>
  {
    static constexpr typename TX::type
    // Data Transmit Register The data transmit registers pass through the transmitted data into the 4-level transmit FIFO buffers. The number of valid bits depends on the setting of DWIDTH (SPIx_CTL[12:8]) in SPI mode or WDWIDTH (SPIx_I2SCTL[5:4]) in I2S mode. In SPI mode, if DWIDTH is set to 0x08, the bits TX[7:0] will be transmitted. If DWIDTH is set to 0x00, the SPI controller will perform a 32-bit transfer. In I2S mode, if WDWIDTH (SPIx_I2SCTL[5:4]) is set to 0x2, the data width of audio channel is 24-bit and corresponding to TX[23:0]. If WDWIDTH is set as 0x0, 0x1, or 0x3, all bits of this field are valid and referred to the data arrangement in I2S mode FIFO operation section Note: In Master mode, SPI controller will start to transfer the SPI bus clock after 1 APB clock and 6 peripheral clock cycles after user writes to this register. (bits: 31-0)
     TXVAL_MASK = 0xFFFFFFFF
    ,TXVAL_POS = 0
    ,TX_MASK = 0xFFFFFFFF
    ;
  };
  // SPI Data Receive Register
  struct RX : reg<ip_ver, base + 0x30>
  {
    static constexpr typename RX::type
    // Data Receive Register (Read Only) There are 4-level FIFO buffers in this controller. The data receive register holds the data received from SPI data input pin. If the RXEMPTY (SPIx_STATUS[8] or SPIx_I2SSTS[8]) is not set to 1, the receive FIFO buffers can be accessed through software by reading this register. (bits: 31-0)
     RXVAL_MASK = 0xFFFFFFFF
    ,RXVAL_POS = 0
    ,RX_MASK = 0xFFFFFFFF
    ;
  };
  // I2S Control Register
  struct I2SCTL : reg<ip_ver, base + 0x60>
  {
    static constexpr typename I2SCTL::type
    // I2S Controller Enable Bit Note 1: If enabling this bit, I2Sx_BCLK will start to output in Master mode. Note 2: Before changing the configurations of SPIx_I2SCTL, SPIx_I2SCLK, and SPIx_FIFOCTL registers, user shall clear the I2SEN (SPIx_I2SCTL[0]) and confirm the I2SENSTS (SPIx_I2SSTS[15]) is 0. (bits: 0)
     I2SEN_MASK = 0x00000001
    ,I2SEN_POS = 0
    ,I2SEN_0 = 0x00000000 // I2S mode Disabled
    ,I2SEN_1 = 0x00000001 // I2S mode Enabled
    // Transmit Enable Bit (bits: 1)
    ,TXEN_MASK = 0x00000002
    ,TXEN_POS = 1
    ,TXEN_0 = 0x00000000 // Data transmit Disabled
    ,TXEN_1 = 0x00000002 // Data transmit Enabled
    // Receive Enable Bit (bits: 2)
    ,RXEN_MASK = 0x00000004
    ,RXEN_POS = 2
    ,RXEN_0 = 0x00000000 // Data receive Disabled
    ,RXEN_1 = 0x00000004 // Data receive Enabled
    // Transmit Mute Enable Bit (bits: 3)
    ,MUTE_MASK = 0x00000008
    ,MUTE_POS = 3
    ,MUTE_0 = 0x00000000 // Transmit data is shifted from buffer
    ,MUTE_1 = 0x00000008 // Transmit channel zero
    // Word Width (bits: 5-4)
    ,WDWIDTH_MASK = 0x00000030
    ,WDWIDTH_POS = 4
    ,WDWIDTH_0 = 0x00000000 // data size is 8-bit
    ,WDWIDTH_1 = 0x00000010 // data size is 16-bit
    ,WDWIDTH_2 = 0x00000020 // data size is 24-bit
    ,WDWIDTH_3 = 0x00000030 // data size is 32-bit
    // Monaural Data (bits: 6)
    ,MONO_MASK = 0x00000040
    ,MONO_POS = 6
    ,MONO_0 = 0x00000000 // Data is stereo format
    ,MONO_1 = 0x00000040 // Data is monaural format
    // Stereo Data Order in FIFO (bits: 7)
    ,ORDER_MASK = 0x00000080
    ,ORDER_POS = 7
    ,ORDER_0 = 0x00000000 // Left channel data at high byte
    ,ORDER_1 = 0x00000080 // Left channel data at low byte
    // Slave Mode I2S can operate as master or slave. For Master mode, I2Sx_BCLK and I2Sx_LRCLK pins are output mode and send bit clock from this chip to audio CODEC chip. In Slave mode, I2Sx_BCLK and I2Sx_LRCLK pins are input mode and I2Sx_BCLK and I2Sx_LRCLK signals are received from outer audio CODEC chip. (bits: 8)
    ,SLAVE_MASK = 0x00000100
    ,SLAVE_POS = 8
    ,SLAVE_0 = 0x00000000 // Master mode
    ,SLAVE_1 = 0x00000100 // Slave mode
    // Master Clock Enable Bit If MCLKEN is set to 1, I2S controller will generate master clock on SPIx_I2SMCLK pin for external audio devices. (bits: 15)
    ,MCLKEN_MASK = 0x00008000
    ,MCLKEN_POS = 15
    ,MCLKEN_0 = 0x00000000 // Master clock Disabled
    ,MCLKEN_1 = 0x00008000 // Master clock Enabled
    // Right Channel Zero Cross Detection Enable Bit If this bit is set to 1, when right channel data sign bit change or next shift data bits are all 0 then RZCIF flag in SPIx_I2SSTS register is set to 1. This function is only available in transmit operation. (bits: 16)
    ,RZCEN_MASK = 0x00010000
    ,RZCEN_POS = 16
    ,RZCEN_0 = 0x00000000 // Right channel zero cross detection Disabled
    ,RZCEN_1 = 0x00010000 // Right channel zero cross detection Enabled
    // Left Channel Zero Cross Detection Enable Bit If this bit is set to 1, when left channel data sign bit changes or next shift data bits are all 0 then LZCIF flag in SPIx_I2SSTS register is set to 1. This function is only available in transmit operation. (bits: 17)
    ,LZCEN_MASK = 0x00020000
    ,LZCEN_POS = 17
    ,LZCEN_0 = 0x00000000 // Left channel zero cross detection Disabled
    ,LZCEN_1 = 0x00020000 // Left channel zero cross detection Enabled
    // Receive Left Channel Enable Bit (bits: 23)
    ,RXLCH_MASK = 0x00800000
    ,RXLCH_POS = 23
    ,RXLCH_0 = 0x00000000 // Receive right channel data in Mono mode
    ,RXLCH_1 = 0x00800000 // Receive left channel data in Mono mode
    // Right Channel Zero Cross Interrupt Enable Bit Interrupt occurs if this bit is set to 1 and right channel zero cross event occurs. (bits: 24)
    ,RZCIEN_MASK = 0x01000000
    ,RZCIEN_POS = 24
    ,RZCIEN_0 = 0x00000000 // Interrupt Disabled
    ,RZCIEN_1 = 0x01000000 // Interrupt Enabled
    // Left Channel Zero Cross Interrupt Enable Bit Interrupt occurs if this bit is set to 1 and left channel zero cross event occurs. (bits: 25)
    ,LZCIEN_MASK = 0x02000000
    ,LZCIEN_POS = 25
    ,LZCIEN_0 = 0x00000000 // Interrupt Disabled
    ,LZCIEN_1 = 0x02000000 // Interrupt Enabled
    // Data Format Selection (bits: 29-28)
    ,FORMAT_MASK = 0x30000000
    ,FORMAT_POS = 28
    ,FORMAT_0 = 0x00000000 // I2S data format
    ,FORMAT_1 = 0x10000000 // MSB justified data format
    ,FORMAT_2 = 0x20000000 // PCM mode A
    ,FORMAT_3 = 0x30000000 // PCM mode B
    // Bit Clock Loss Interrupt Enable Bit for Slave Mode Interrupt occurs if this bit is set to 1 and bit clock loss event occurs. (bits: 31)
    ,SLVERRIEN_MASK = 0x80000000
    ,SLVERRIEN_POS = 31
    ,SLVERRIEN_0 = 0x00000000 // Interrupt Disabled
    ,SLVERRIEN_1 = 0x80000000 // Interrupt Enabled
    ,I2SCTL_MASK = 0xB38381FF
    ;
  };
  // I2S Clock Divider Control Register
  struct I2SCLK : reg<ip_ver, base + 0x64>
  {
    static constexpr typename I2SCLK::type
    // Master Clock Divider If MCLKEN is set to 1, I2S controller will generate master clock for external audio devices. The frequency of master clock, fMCLK, is determined by the following expressions: where is the frequency of I2S peripheral clock source, which is defined in the clock control register CLK_CLKSEL2. In general, the master clock rate is 256 times sampling clock rate. (bits: 6-0)
     MCLKDIV_MASK = 0x0000007F
    ,MCLKDIV_POS = 0
    // Bit Clock Divider The I2S controller will generate bit clock in Master mode. The clock frequency of bit clock , fBCLK, is determined by the following expression: where is the frequency of I2S peripheral clock source, which is defined in the clock control register CLK_CLKSEL2. In I2S Slave mode, this field is used to define the frequency of peripheral clock and it's determined by . The peripheral clock frequency in I2S Slave mode must be equal to or faster than 6 times of input bit clock. Note: The time interval must be larger than or equal to 8 peripheral clock cycles between releasing SPI IP software reset and setting this clock divider register. (bits: 17-8)
    ,BCLKDIV_MASK = 0x0003FF00
    ,BCLKDIV_POS = 8
    ,I2SCLK_MASK = 0x0003FF7F
    ;
  };
  // I2S Status Register
  struct I2SSTS : reg<ip_ver, base + 0x68, 0x00050100>
  {
    static constexpr typename I2SSTS::type
    // Right Channel (Read Only) This bit indicates the current transmit data is belong to which channel. (bits: 4)
     RIGHT_MASK = 0x00000010
    ,RIGHT_POS = 4
    ,RIGHT_0 = 0x00000000 // Left channel
    ,RIGHT_1 = 0x00000010 // Right channel
    // Receive FIFO Buffer Empty Indicator (Read Only) (bits: 8)
    ,RXEMPTY_MASK = 0x00000100
    ,RXEMPTY_POS = 8
    ,RXEMPTY_0 = 0x00000000 // Receive FIFO buffer is not empty
    ,RXEMPTY_1 = 0x00000100 // Receive FIFO buffer is empty
    // Receive FIFO Buffer Full Indicator (Read Only) (bits: 9)
    ,RXFULL_MASK = 0x00000200
    ,RXFULL_POS = 9
    ,RXFULL_0 = 0x00000000 // Receive FIFO buffer is not full
    ,RXFULL_1 = 0x00000200 // Receive FIFO buffer is full
    // Receive FIFO Threshold Interrupt Flag (Read Only) (bits: 10)
    ,RXTHIF_MASK = 0x00000400
    ,RXTHIF_POS = 10
    ,RXTHIF_0 = 0x00000000 // The valid data count within the receive FIFO buffer is smaller than or equal to the setting value of RXTH
    ,RXTHIF_1 = 0x00000400 // The valid data count within the receive FIFO buffer is larger than the setting value of RXTH
    // Receive FIFO Overrun Interrupt Flag When the receive FIFO buffer is full, the follow-up data will be dropped and this bit will be set to 1. Note: This bit will be cleared by writing 1 to it. (bits: 11)
    ,RXOVIF_MASK = 0x00000800
    ,RXOVIF_POS = 11
    ,RXOVIF = 0x00000800
    // Receive Time-out Interrupt Flag Note: This bit will be cleared by writing 1 to it. (bits: 12)
    ,RXTOIF_MASK = 0x00001000
    ,RXTOIF_POS = 12
    ,RXTOIF_0 = 0x00000000 // No receive FIFO time-out event
    ,RXTOIF_1 = 0x00001000 // Receive FIFO buffer is not empty and no read operation on receive FIFO buffer over 64 SPI peripheral clock period in Master mode or over 576 SPI peripheral clock period in Slave mode. When the received FIFO buffer is read by software, the time-out status will be cleared automatically
    // I2S Enable Status (Read Only) Note: The SPI peripheral clock is asynchronous with the system clock. In order to make sure the SPI/I2S control logic is disabled, this bit indicates the real status of SPI/I2S control logic for user. (bits: 15)
    ,I2SENSTS_MASK = 0x00008000
    ,I2SENSTS_POS = 15
    ,I2SENSTS_0 = 0x00000000 // The SPI/I2S control logic is disabled
    ,I2SENSTS_1 = 0x00008000 // The SPI/I2S control logic is enabled
    // Transmit FIFO Buffer Empty Indicator (Read Only) (bits: 16)
    ,TXEMPTY_MASK = 0x00010000
    ,TXEMPTY_POS = 16
    ,TXEMPTY_0 = 0x00000000 // Transmit FIFO buffer is not empty
    ,TXEMPTY_1 = 0x00010000 // Transmit FIFO buffer is empty
    // Transmit FIFO Buffer Full Indicator (Read Only) (bits: 17)
    ,TXFULL_MASK = 0x00020000
    ,TXFULL_POS = 17
    ,TXFULL_0 = 0x00000000 // Transmit FIFO buffer is not full
    ,TXFULL_1 = 0x00020000 // Transmit FIFO buffer is full
    // Transmit FIFO Threshold Interrupt Flag (Read Only) (bits: 18)
    ,TXTHIF_MASK = 0x00040000
    ,TXTHIF_POS = 18
    ,TXTHIF_0 = 0x00000000 // The valid data count within the transmit FIFO buffer is larger than the setting value of TXTH
    ,TXTHIF_1 = 0x00040000 // The valid data count within the transmit FIFO buffer is less than or equal to the setting value of TXTH
    // Transmit FIFO Underflow Interrupt Flag When the transmit FIFO buffer is empty and there is no datum written into the FIFO buffer, if there is more bus clock input, this bit will be set to 1. Note: This bit will be cleared by writing 1 to it. (bits: 19)
    ,TXUFIF_MASK = 0x00080000
    ,TXUFIF_POS = 19
    ,TXUFIF = 0x00080000
    // Right Channel Zero Cross Interrupt Flag (bits: 20)
    ,RZCIF_MASK = 0x00100000
    ,RZCIF_POS = 20
    ,RZCIF_0 = 0x00000000 // No zero cross event occurred on right channel
    ,RZCIF_1 = 0x00100000 // Zero cross event occurred on right channel
    // Left Channel Zero Cross Interrupt Flag (bits: 21)
    ,LZCIF_MASK = 0x00200000
    ,LZCIF_POS = 21
    ,LZCIF_0 = 0x00000000 // No zero cross event occurred on left channel
    ,LZCIF_1 = 0x00200000 // Zero cross event occurred on left channel
    // Bit Clock Loss Interrupt Flag for Slave Mode Note: This bit will be cleared by writing 1 to it. (bits: 22)
    ,SLVERRIF_MASK = 0x00400000
    ,SLVERRIF_POS = 22
    ,SLVERRIF_0 = 0x00000000 // No bit clock loss event occurred
    ,SLVERRIF_1 = 0x00400000 // Bit clock loss event occurred
    // TX or RX Reset Status (Read Only) Note: Both the reset operations of TXRST and RXRST need 3 system clock cycles + 2 peripheral clock cycles. User can check the status of this bit to monitor the reset function is doing or done. (bits: 23)
    ,TXRXRST_MASK = 0x00800000
    ,TXRXRST_POS = 23
    ,TXRXRST_0 = 0x00000000 // The reset function of TXRST or RXRST is done
    ,TXRXRST_1 = 0x00800000 // Doing the reset function of TXRST or RXRST
    // Receive FIFO Data Count (Read Only) This bit field indicates the valid data count of receive FIFO buffer. (bits: 26-24)
    ,RXCNT_MASK = 0x07000000
    ,RXCNT_POS = 24
    // Transmit FIFO Data Count (Read Only) This bit field indicates the valid data count of transmit FIFO buffer. (bits: 30-28)
    ,TXCNT_MASK = 0x70000000
    ,TXCNT_POS = 28
    ,I2SSTS_MASK = 0x77FF9F10
    ;
  };
}; // struct SPI

} // namespace lmcu::device::ip::v1

