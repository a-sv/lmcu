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

  // Control and Status Register
  struct CNTRL : reg<ip_ver, base + 0x0, 0x05003004>
  {
    static constexpr typename CNTRL::type
    // SPI Transfer Control Bit And Busy Status If FIFO mode is disabled, during the data transfer, this bit keeps the value of 1. As the transfer is finished, this bit will be cleared automatically. Software can read this bit to check if the SPI is in busy status. In FIFO mode, this bit will be controlled by hardware. Software should not modify this bit. In Slave mode, this bit always returns 1 when this register is read by software. In Master mode, this bit reflects the busy or idle status of SPI. Note: When FIFO mode is disabled, all configurations should be set before writing 1 to this GO_BUSY bit. (bits: 0)
     GO_BUSY_MASK = 0x00000001
    ,GO_BUSY_POS = 0
    ,GO_BUSY_0 = 0x00000000 // Data transfer stopped
    ,GO_BUSY_1 = 0x00000001 // In Master mode, writing 1 to this bit to start the SPI data transfer; in Slave mode, writing 1 to this bit indicates that the slave is ready to communicate with a master
    // Receive On Negative Edge (bits: 1)
    ,RX_NEG_MASK = 0x00000002
    ,RX_NEG_POS = 1
    ,RX_NEG_0 = 0x00000000 // Received data input signal is latched on the rising edge of SPI bus clock
    ,RX_NEG_1 = 0x00000002 // Received data input signal is latched on the falling edge of SPI bus clock
    // Transmit On Negative Edge (bits: 2)
    ,TX_NEG_MASK = 0x00000004
    ,TX_NEG_POS = 2
    ,TX_NEG_0 = 0x00000000 // Transmitted data output signal is changed on the rising edge of SPI bus clock
    ,TX_NEG_1 = 0x00000004 // Transmitted data output signal is changed on the falling edge of SPI bus clock
    // Transmit Bit Length This field specifies how many bits can be transmitted/received in one transaction. The minimum bit length is 8 bits and can up to 32 bits. (bits: 7-3)
    ,TX_BIT_LEN_MASK = 0x000000F8
    ,TX_BIT_LEN_POS = 3
    // Send LSB First (bits: 10)
    ,LSB_MASK = 0x00000400
    ,LSB_POS = 10
    ,LSB_0 = 0x00000000 // The MSB, which bit of transmit/receive register depends on the setting of TX_BIT_LEN, is transmitted/received first
    ,LSB_1 = 0x00000400 // The LSB, bit 0 of the SPI TX0/1 register, is sent first to the SPI data output pin, and the first bit received from the SPI data input pin will be put in the LSB position of the RX register (bit 0 of SPI_RX0/1)
    // Clock Polarity (bits: 11)
    ,CLKP_MASK = 0x00000800
    ,CLKP_POS = 11
    ,CLKP_0 = 0x00000000 // SPI bus clock is idle low
    ,CLKP_1 = 0x00000800 // SPI bus clock is idle high
    // Suspend Interval (Master Only) The four bits provide configurable suspend interval between two successive transmit/receive transaction in a transfer. The definition of the suspend interval is the interval between the last clock edge of the preceding transaction word and the first clock edge of the following transaction word. The default value is 0x3. The period of the suspend interval is obtained according to the following equation. (SP_CYCLE[3:0] + 0.5) * period of SPI bus clock cycle Example: If the variable clock function is enabled and the transmit FIFO buffer is not empty, the minimum period of suspend interval between the successive transactions is (6.5 + SP_CYCLE) * SPI bus clock cycle. (bits: 15-12)
    ,SP_CYCLE_MASK = 0x0000F000
    ,SP_CYCLE_POS = 12
    // Unit Transfer Interrupt Flag Note: This bit will be cleared by writing 1 to itself. (bits: 16)
    ,IF_MASK = 0x00010000
    ,IF_POS = 16
    ,IF_0 = 0x00000000 // No transaction has been finished since this bit was cleared to 0
    ,IF_1 = 0x00010000 // SPI controller has finished one unit transfer
    // Unit Transfer Interrupt EnableBit (bits: 17)
    ,IE_MASK = 0x00020000
    ,IE_POS = 17
    ,IE_0 = 0x00000000 // SPI unit transfer interrupt Disabled
    ,IE_1 = 0x00020000 // SPI unit transfer interrupt Enabled
    // Slave Mode EnableBit (bits: 18)
    ,SLAVE_MASK = 0x00040000
    ,SLAVE_POS = 18
    ,SLAVE_0 = 0x00000000 // Master mode
    ,SLAVE_1 = 0x00040000 // Slave mode
    // Byte Reorder Function EnableBit Note: Byte Reorder function is only available if TX_BIT_LEN is defined as 16, 24, and 32 bits. In Slave mode with level-trigger configuration, the slave select pin must be kept at active state during the byte suspend interval. The Byte Reorder function is not supported when the variable bus clock function or Dual I/O mode is enabled. (bits: 19)
    ,REORDER_MASK = 0x00080000
    ,REORDER_POS = 19
    ,REORDER_0 = 0x00000000 // Byte Reorder function Disabled
    ,REORDER_1 = 0x00080000 // Byte Reorder function Enabled. A byte suspend interval will be inserted among each byte. The period of the byte suspend interval depends on the setting of SP_CYCLE
    // FIFO Mode Enable Control Note: Before enabling FIFO mode, the other related settings should be set in advance. In Master mode, if the FIFO mode is enabled, the GO_BUSY bit will be set to 1 automatically after writing data to the transmit FIFO buffer; the GO_BUSY bit will be cleared to 0 automatically when the SPI controller is in idle. If all data stored at transmit FIFO buffer are sent out, the TX_EMPTY bit will be set to 1 and the GO_BUSY bit will be cleared to 0. After clearing this bit to 0, user must wait for at least 2 peripheral clock periods before setting this bit to 1 again. (bits: 21)
    ,FIFO_MASK = 0x00200000
    ,FIFO_POS = 21
    ,FIFO_0 = 0x00000000 // FIFO mode Disabled
    ,FIFO_1 = 0x00200000 // FIFO mode Enabled
    // Variable Clock Enable Control (Master Only) Note: When this VARCLK_EN bit is set to 1, the setting of TX_BIT_LEN must be programmed as 0x10 (16-bit mode). (bits: 23)
    ,VARCLK_EN_MASK = 0x00800000
    ,VARCLK_EN_POS = 23
    ,VARCLK_EN_0 = 0x00000000 // SPI clock output frequency is fixed and decided only by the value of DIVIDER
    ,VARCLK_EN_1 = 0x00800000 // SPI clock output frequency is variable. The output frequency is decided by the value of VARCLK, DIVIDER, and DIVIDER2
    // Receive FIFO Buffer Empty Indicator (Read Only) It is a mutual mirror bit of SPI_STATUS[24]. (bits: 24)
    ,RX_EMPTY_MASK = 0x01000000
    ,RX_EMPTY_POS = 24
    ,RX_EMPTY_0 = 0x00000000 // Receive FIFO buffer is not empty
    ,RX_EMPTY_1 = 0x01000000 // Receive FIFO buffer is empty
    // Receive FIFO Buffer Full Indicator (Read Only) It is a mutual mirror bit of SPI_STATUS[25]. (bits: 25)
    ,RX_FULL_MASK = 0x02000000
    ,RX_FULL_POS = 25
    ,RX_FULL_0 = 0x00000000 // Receive FIFO buffer is not full
    ,RX_FULL_1 = 0x02000000 // Receive FIFO buffer is full
    // Transmit FIFO Buffer Empty Indicator (Read Only) It is a mutual mirror bit of SPI_STATUS[26]. (bits: 26)
    ,TX_EMPTY_MASK = 0x04000000
    ,TX_EMPTY_POS = 26
    ,TX_EMPTY_0 = 0x00000000 // Transmit FIFO buffer is not empty
    ,TX_EMPTY_1 = 0x04000000 // Transmit FIFO buffer is empty
    // Transmit FIFO Buffer Full Indicator (Read Only) It is a mutual mirror bit of SPI_STATUS[27]. (bits: 27)
    ,TX_FULL_MASK = 0x08000000
    ,TX_FULL_POS = 27
    ,TX_FULL_0 = 0x00000000 // Transmit FIFO buffer is not full
    ,TX_FULL_1 = 0x08000000 // Transmit FIFO buffer is full
    ,CNTRL_MASK = 0x0FAFFCFF
    ;
  };
  // Clock Divider Register
  struct DIVIDER : reg<ip_ver, base + 0x4>
  {
    static constexpr typename DIVIDER::type
    // Clock Divider 1 Register The value in this field is the frequency divider for generating the SPI peripheral clock, fspi_eclk, and the SPI bus clock of SPI master. The frequency is obtained according to the following equation. If the bit of BCn, SPI_CNTRL2[31], is set to 0, else if BCn is set to 1, where is the SPI peripheral clock source, which is defined in the CLKSEL1 register. (bits: 7-0)
     DIVIDERVAL_MASK = 0x000000FF
    ,DIVIDERVAL_POS = 0
    // Clock Divider 2 Register (Master Only) The value in this field is the 2nd frequency divider for generating the second clock of the variable clock function. The frequency is obtained according to the following equation: If the VARCLK_EN bit is cleared to 0, this setting is unmeaning. (bits: 23-16)
    ,DIVIDER2_MASK = 0x00FF0000
    ,DIVIDER2_POS = 16
    ,DIVIDER_MASK = 0x00FF00FF
    ;
  };
  // Slave Select Register
  struct SSR : reg<ip_ver, base + 0x8>
  {
    static constexpr typename SSR::type
    // Slave Select Control Bit (Master Only) If AUTOSS bit is cleared, writing 1 to any bit of this field sets the proper SPI0_SPISS0 line to an active state and writing 0 sets the line back to inactive state. If the AUTOSS bit is set, writing 0 to any bit location of this field will keep the corresponding SPI0_SPISS0 line at inactive state; writing 1 to any bit location of this field will select appropriate SPI0_SPISS0 line to be automatically driven to active state for the duration of the transmit/receive, and will be driven to inactive state for the rest of the time. The active state of SPI0_SPISS0 is specified in SS_LVL. Note: SPI0_SPISS0 is defined as the slave select input in Slave mode. (bits: 0)
     SSRVAL_MASK = 0x00000001
    ,SSRVAL_POS = 0
    ,SSRVAL = 0x00000001
    // Slave Select Active Level This bit defines the active status of slave select signal (SPI0_SPISS0). (bits: 2)
    ,SS_LVL_MASK = 0x00000004
    ,SS_LVL_POS = 2
    ,SS_LVL_0 = 0x00000000 // The slave select signal SPI0_SPISS0 is active on low-level/falling-edge
    ,SS_LVL_1 = 0x00000004 // The slave select signal SPI0_SPISS0 is active on high-level/rising-edge
    // Automatic Slave Select Function Enable Control (Master Only) (bits: 3)
    ,AUTOSS_MASK = 0x00000008
    ,AUTOSS_POS = 3
    ,AUTOSS_0 = 0x00000000 // If this bit is cleared, slave select signal will be asserted/de-asserted by setting /clearing the corresponding bit of SPI_SSR[0]
    ,AUTOSS_1 = 0x00000008 // If this bit is set, SPI0_SPISS0 signal will be generated automatically. It means that device/slave select signal, which is set in SPI_SSR[0], will be asserted by the SPI controller when transmit/receive is started, and will be de-asserted after each transmit/receive is finished
    // Slave Select Level Trigger Enable Control (Slave Only) (bits: 4)
    ,SS_LTRIG_MASK = 0x00000010
    ,SS_LTRIG_POS = 4
    ,SS_LTRIG_0 = 0x00000000 // Slave select signal is edge-trigger. This is the default value. The SS_LVL bit decides the signal is active after a falling-edge or rising-edge
    ,SS_LTRIG_1 = 0x00000010 // Slave select signal is level-trigger. The SS_LVL bit decides the signal is active low or active high
    // Level Trigger Accomplish Flag In Slave mode, this bit indicates whether the received bit number meets the requirement or not after the current transaction done. Note: This bit is READ only. As the GO_BUSY bit is set to 1 by software, the LTRIG_FLAG will be cleared to 0 after 4 SPI peripheral clock periods plus 1 system clock period. In FIFO mode, this bit has no meaning. (bits: 5)
    ,LTRIG_FLAG_MASK = 0x00000020
    ,LTRIG_FLAG_POS = 5
    ,LTRIG_FLAG_0 = 0x00000000 // Transferred bit length of one transaction does not meet the specified requirement
    ,LTRIG_FLAG_1 = 0x00000020 // Transferred bit length meets the specified requirement which defined in TX_BIT_LEN
    ,SSR_MASK = 0x0000003D
    ;
  };
  // Data Receive Register 0
  struct RX0 : reg<ip_ver, base + 0x10>
  {
    static constexpr typename RX0::type
    // Data Receive Register The data receive register holds the datum received from SPI data input pin. If FIFO mode is disabled, the last received data can be accessed through software by reading this register. If the FIFO bit is set as 1 and the RX_EMPTY bit, SPI_CNTRL[24] or SPI_STATUS[24], is not set to 1, the receive FIFO buffer can be accessed through software by reading this register. This is a read-only register. (bits: 31-0)
     RX_MASK = 0xFFFFFFFF
    ,RX_POS = 0
    ,RX0_MASK = 0xFFFFFFFF
    ;
  };
  // Data Receive Register 1
  using RX1 = reg<ip_ver, base + 0x14>;
  // Data Transmit Register 0
  struct TX0 : reg<ip_ver, base + 0x20>
  {
    static constexpr typename TX0::type
    // Data Transmit Register The data transmit registers hold the data to be transmitted in the next transfer. The number of valid bits depends on the setting of transmit bit length field of the SPI_CNTRL register. For example, if TX_BIT_LEN is set to 0x08, the bits TX[7:0] will be transmitted in next transfer. If TX_BIT_LEN is set to 0x00, the SPI controller will perform a 32-bit transfer. Note 1: When the SPI controller is configured as a slave device and FIFO mode is disabled, if the SPI controller attempts to transmit data to a master, the transmit data register should be updated by software before setting the GO_BUSY bit to 1. Note 2: In Master mode, SPI controller will start to transfer after 5 peripheral clock cycles since user wrote to this register. (bits: 31-0)
     TX_MASK = 0xFFFFFFFF
    ,TX_POS = 0
    ,TX0_MASK = 0xFFFFFFFF
    ;
  };
  // Data Transmit Register 1
  using TX1 = reg<ip_ver, base + 0x24>;
  // Variable Clock Pattern Register
  struct VARCLK : reg<ip_ver, base + 0x34, 0x007FFF87>
  {
    static constexpr typename VARCLK::type
    // Variable Clock Pattern This register defines the clock pattern of the SPI transfer. If the variable clock function is disabled, this setting is unmeaning. Refer to the <Variable Clock Function> paragraph for more detail description. (bits: 31-0)
     VARCLKVAL_MASK = 0xFFFFFFFF
    ,VARCLKVAL_POS = 0
    ,VARCLK_MASK = 0xFFFFFFFF
    ;
  };
  // Control and Status Register 2
  struct CNTRL2 : reg<ip_ver, base + 0x3C, 0x00001000>
  {
    static constexpr typename CNTRL2::type
    // Slave 3-Wire Mode Enable Control This is used to ignore the slave select signal in Slave mode. The SPI controller can work with 3-wire interface including SPI0_CLK, SPI0_MISO0 and SPI0_MOSI0 pins. Note: In Slave 3-wire mode, the SS_LTRIG, SPI_SSR[4] will be set as 1 automatically. (bits: 8)
     NOSLVSEL_MASK = 0x00000100
    ,NOSLVSEL_POS = 8
    ,NOSLVSEL_0 = 0x00000000 // 4-wire bi-direction interface
    ,NOSLVSEL_1 = 0x00000100 // 3-wire bi-direction interface
    // Slave 3-Wire Mode Abort Control In normal operation, there is an interrupt event when the received data meet the required bits which defined in TX_BIT_LEN. If the received bits are less than the requirement and there is no more SPI clock input over the one transfer time in Slave 3-wire mode, the user can set this bit to force the current transfer done and then the user can get a transfer done interrupt event. Note: This bit will be cleared to 0 automatically by hardware after it is set to 1 by software. (bits: 9)
    ,SLV_ABORT_MASK = 0x00000200
    ,SLV_ABORT_POS = 9
    ,SLV_ABORT = 0x00000200
    // Slave 3-Wire Mode Start Interrupt Enable Control Used to enable interrupt when the transfer has started in Slave 3-wire mode. If there is no transfer done interrupt over the time period which is defined by user after the transfer start, the user can set the SLV_ABORT bit to force the transfer done. (bits: 10)
    ,SSTA_INTEN_MASK = 0x00000400
    ,SSTA_INTEN_POS = 10
    ,SSTA_INTEN_0 = 0x00000000 // Transaction start interrupt Disabled
    ,SSTA_INTEN_1 = 0x00000400 // Transaction start interrupt Enabled. It will be cleared to 0 as the current transfer is done or the SLV_START_INTSTS bit is cleared
    // Slave 3-Wire Mode Start Interrupt Status This bit indicates if a transaction has started in Slave 3-wire mode. It is a mutual mirror bit of SPI_STATUS[11]. (bits: 11)
    ,SLV_START_INTSTS_MASK = 0x00000800
    ,SLV_START_INTSTS_POS = 11
    ,SLV_START_INTSTS_0 = 0x00000000 // Slave has not detected any SPI clock transition since the SSTA_INTEN bit was set to 1
    ,SLV_START_INTSTS_1 = 0x00000800 // A transaction has started in Slave 3-wire mode. It will be cleared automatically when a transaction is done or by writing 1 to this bit
    // Dual I/O Mode Direction Control (bits: 12)
    ,DUAL_IO_DIR_MASK = 0x00001000
    ,DUAL_IO_DIR_POS = 12
    ,DUAL_IO_DIR_0 = 0x00000000 // Dual Input mode
    ,DUAL_IO_DIR_1 = 0x00001000 // Dual Output mode
    // Dual I/O Mode EnableBit (bits: 13)
    ,DUAL_IO_EN_MASK = 0x00002000
    ,DUAL_IO_EN_POS = 13
    ,DUAL_IO_EN_0 = 0x00000000 // Dual I/O mode Disabled
    ,DUAL_IO_EN_1 = 0x00002000 // Dual I/O mode Enabled
    // Slave Select Inactive Interrupt Option This setting is only available if the SPI controller is configured as level trigger slave device. (bits: 16)
    ,SS_INT_OPT_MASK = 0x00010000
    ,SS_INT_OPT_POS = 16
    ,SS_INT_OPT_0 = 0x00000000 // As the slave select signal goes to inactive level, the IF bit will NOT be set to 1
    ,SS_INT_OPT_1 = 0x00010000 // As the slave select signal goes to inactive level, the IF bit will be set to 1
    // SPI Peripheral Clock Backward Compatible Option Refer to the description of SPI_DIVIDER register for details. (bits: 31)
    ,BCN_MASK = 0x80000000
    ,BCN_POS = 31
    ,BCN_0 = 0x00000000 // Backward compatible clock configuration
    ,BCN_1 = 0x80000000 // Clock configuration is not backward compatible
    ,CNTRL2_MASK = 0x80013F00
    ;
  };
  // SPI FIFO Control Register
  struct FIFO_CTL : reg<ip_ver, base + 0x40, 0x44000000>
  {
    static constexpr typename FIFO_CTL::type
    // Clear Receive FIFO Buffer (bits: 0)
     RX_CLR_MASK = 0x00000001
    ,RX_CLR_POS = 0
    ,RX_CLR_0 = 0x00000000 // No effect
    ,RX_CLR_1 = 0x00000001 // Clear receive FIFO buffer. The RX_FULL flag will be cleared to 0 and the RX_EMPTY flag will be set to 1. This bit will be cleared to 0 by hardware after it is set to 1 by software
    // Clear Transmit FIFO Buffer (bits: 1)
    ,TX_CLR_MASK = 0x00000002
    ,TX_CLR_POS = 1
    ,TX_CLR_0 = 0x00000000 // No effect
    ,TX_CLR_1 = 0x00000002 // Clear transmit FIFO buffer. The TX_FULL flag will be cleared to 0 and the TX_EMPTY flag will be set to 1. This bit will be cleared to 0 by hardware after it is set to 1 by software
    // Receive Threshold Interrupt Enable Control (bits: 2)
    ,RX_INTEN_MASK = 0x00000004
    ,RX_INTEN_POS = 2
    ,RX_INTEN_0 = 0x00000000 // RX threshold interrupt Disabled
    ,RX_INTEN_1 = 0x00000004 // RX threshold interrupt Enabled
    // Transmit Threshold Interrupt Enable Control (bits: 3)
    ,TX_INTEN_MASK = 0x00000008
    ,TX_INTEN_POS = 3
    ,TX_INTEN_0 = 0x00000000 // TX threshold interrupt Disabled
    ,TX_INTEN_1 = 0x00000008 // TX threshold interrupt Enabled
    // Receive FIFO Overrun Interrupt Enable Control (bits: 6)
    ,RXOV_INTEN_MASK = 0x00000040
    ,RXOV_INTEN_POS = 6
    ,RXOV_INTEN_0 = 0x00000000 // Receive FIFO overrun interrupt Disabled
    ,RXOV_INTEN_1 = 0x00000040 // Receive FIFO overrun interrupt Enabled
    // Receive FIFO Time-Out Interrupt Enable Control (bits: 21)
    ,TIMEOUT_INTEN_MASK = 0x00200000
    ,TIMEOUT_INTEN_POS = 21
    ,TIMEOUT_INTEN_0 = 0x00000000 // Time-out interrupt Disabled
    ,TIMEOUT_INTEN_1 = 0x00200000 // Time-out interrupt Enabled
    // Receive FIFO Threshold If the valid data count of the receive FIFO buffer is larger than the RX_THRESHOLD setting, the RX_INTSTS bit will be set to 1, else the RX_INTSTS bit will be cleared to 0. (bits: 26-24)
    ,RX_THRESHOLD_MASK = 0x07000000
    ,RX_THRESHOLD_POS = 24
    // Transmit FIFO Threshold If the valid data count of the transmit FIFO buffer is less than or equal to the TX_THRESHOLD setting, the TX_INTSTS bit will be set to 1, else the TX_INTSTS bit will be cleared to 0. (bits: 30-28)
    ,TX_THRESHOLD_MASK = 0x70000000
    ,TX_THRESHOLD_POS = 28
    ,FIFO_CTL_MASK = 0x7720004F
    ;
  };
  // SPI Status Register
  struct STATUS : reg<ip_ver, base + 0x44, 0x05000000>
  {
    static constexpr typename STATUS::type
    // Receive FIFO Threshold Interrupt Status (Read Only) (bits: 0)
     RX_INTSTS_MASK = 0x00000001
    ,RX_INTSTS_POS = 0
    ,RX_INTSTS_0 = 0x00000000 // The valid data count within the Rx FIFO buffer is less than or equal to the setting value of RX_THRESHOLD
    ,RX_INTSTS_1 = 0x00000001 // The valid data count within the receive FIFO buffer is larger than the setting value of RX_THRESHOLD
    // Receive FIFO Overrun Status When the receive FIFO buffer is full, the follow-up data will be dropped and this bit will be set to 1. Note: This bit will be cleared by writing 1 to itself. (bits: 2)
    ,RX_OVERRUN_MASK = 0x00000004
    ,RX_OVERRUN_POS = 2
    ,RX_OVERRUN = 0x00000004
    // Transmit FIFO Threshold Interrupt Status (Read Only) (bits: 4)
    ,TX_INTSTS_MASK = 0x00000010
    ,TX_INTSTS_POS = 4
    ,TX_INTSTS_0 = 0x00000000 // The valid data count within the transmit FIFO buffer is larger than the setting value of TX_THRESHOLD
    ,TX_INTSTS_1 = 0x00000010 // The valid data count within the transmit FIFO buffer is less than or equal to the setting value of TX_THRESHOLD
    // Slave Start Interrupt Status It is used to dedicate if a transaction has started in Slave 3-wire mode. It is a mutual mirror bit of SPI_CNTRL2[11]. (bits: 11)
    ,SLV_START_INTSTS_MASK = 0x00000800
    ,SLV_START_INTSTS_POS = 11
    ,SLV_START_INTSTS_0 = 0x00000000 // Slave has not detected any SPI clock transition since the SSTA_INTEN bit was set to 1
    ,SLV_START_INTSTS_1 = 0x00000800 // A transaction has started in Slave 3-wire mode. It will be cleared as a transaction is done or by writing 1 to this bit
    // Receive FIFO Data Count (Read Only) This bit field indicates the valid data count of receive FIFO buffer. (bits: 15-12)
    ,RX_FIFO_COUNT_MASK = 0x0000F000
    ,RX_FIFO_COUNT_POS = 12
    // SPI Unit Transfer Interrupt Flag It is a mutual mirror bit of SPI_CNTRL[16]. Note: This bit will be cleared by writing 1 to itself. (bits: 16)
    ,IF_MASK = 0x00010000
    ,IF_POS = 16
    ,IF_0 = 0x00000000 // No transaction has been finished since this bit was cleared to 0
    ,IF_1 = 0x00010000 // SPI controller has finished one unit transfer
    // Time-Out Interrupt Flag Note: This bit will be cleared by writing 1 to itself. (bits: 20)
    ,TIMEOUT_MASK = 0x00100000
    ,TIMEOUT_POS = 20
    ,TIMEOUT_0 = 0x00000000 // No receive FIFO time-out event
    ,TIMEOUT_1 = 0x00100000 // Receive FIFO buffer is not empty and no read operation on receive FIFO buffer over 64 SPI clock period in Master mode or over 576 SPI peripheral clock period in Slave mode. When the received FIFO buffer is read by software, the time-out status will be cleared automatically
    // Receive FIFO Buffer Empty Indicator (Read Only) It is a mutual mirror bit of SPI_CNTRL[24]. (bits: 24)
    ,RX_EMPTY_MASK = 0x01000000
    ,RX_EMPTY_POS = 24
    ,RX_EMPTY_0 = 0x00000000 // Receive FIFO buffer is not empty
    ,RX_EMPTY_1 = 0x01000000 // Receive FIFO buffer is empty
    // Receive FIFO Buffer Empty Indicator (Read Only) It is a mutual mirror bit of SPI_CNTRL[25]. (bits: 25)
    ,RX_FULL_MASK = 0x02000000
    ,RX_FULL_POS = 25
    ,RX_FULL_0 = 0x00000000 // Receive FIFO buffer is not full
    ,RX_FULL_1 = 0x02000000 // Receive FIFO buffer is full
    // Transmit FIFO Buffer Empty Indicator (Read Only) It is a mutual mirror bit of SPI_CNTRL[26]. (bits: 26)
    ,TX_EMPTY_MASK = 0x04000000
    ,TX_EMPTY_POS = 26
    ,TX_EMPTY_0 = 0x00000000 // Transmit FIFO buffer is not empty
    ,TX_EMPTY_1 = 0x04000000 // Transmit FIFO buffer is empty
    // Transmit FIFO Buffer Full Indicator (Read Only) It is a mutual mirror bit of SPI_CNTRL[27]. (bits: 27)
    ,TX_FULL_MASK = 0x08000000
    ,TX_FULL_POS = 27
    ,TX_FULL_0 = 0x00000000 // Transmit FIFO buffer is not full
    ,TX_FULL_1 = 0x08000000 // Transmit FIFO buffer is full
    // Transmit FIFO Data Count (Read Only) This bit field indicates the valid data count of transmit FIFO buffer. (bits: 31-28)
    ,TX_FIFO_COUNT_MASK = 0xF0000000
    ,TX_FIFO_COUNT_POS = 28
    ,STATUS_MASK = 0xFF11F815
    ;
  };
}; // struct SPI

} // namespace lmcu::device::ip::v1

