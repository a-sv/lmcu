/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// CAN Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct CAN
{
  static constexpr auto ip_ver = ip_version::_1;

  // Control Register
  struct CON : reg<ip_ver, base + 0x0, 0x00000001>
  {
    static constexpr typename CON::type
    // Init Initialization (bits: 0)
     INIT_MASK = 0x00000001
    ,INIT_POS = 0
    ,INIT_0 = 0x00000000 // Normal Operation
    ,INIT_1 = 0x00000001 // Initialization is started
    // Module Interrupt Enable Control (bits: 1)
    ,IE_MASK = 0x00000002
    ,IE_POS = 1
    ,IE_0 = 0x00000000 // Disabled
    ,IE_1 = 0x00000002 // Enabled
    // Status Change Interrupt Enable Control (bits: 2)
    ,SIE_MASK = 0x00000004
    ,SIE_POS = 2
    ,SIE_0 = 0x00000000 // Disabled - No Status Change Interrupt will be generated
    ,SIE_1 = 0x00000004 // Enabled - An interrupt will be generated when a message transfer is successfully completed or a CAN bus error is detected
    // Error Interrupt Enable Control (bits: 3)
    ,EIE_MASK = 0x00000008
    ,EIE_POS = 3
    ,EIE_0 = 0x00000000 // Disabled - No Error Status Interrupt will be generated
    ,EIE_1 = 0x00000008 // Enabled - A change in the bits BOff (CAN_STATUS[7]) or EWarn (CAN_STATUS[6]) in the Status Register will generate an interrupt
    // Automatic Re-Transmission Disable Control (bits: 5)
    ,DAR_MASK = 0x00000020
    ,DAR_POS = 5
    ,DAR_0 = 0x00000000 // Automatic Retransmission of disturbed messages Enabled
    ,DAR_1 = 0x00000020 // Automatic Retransmission Disabled
    // Configuration Change Enable Control (bits: 6)
    ,CCE_MASK = 0x00000040
    ,CCE_POS = 6
    ,CCE_0 = 0x00000000 // No write access to the Bit Timing Register
    ,CCE_1 = 0x00000040 // Write access to the Bit Timing Register (CAN_BTIME) allowed. (while Init bit (CAN_CON[0]) = 1)
    // Test Mode Enable Control (bits: 7)
    ,TEST_MASK = 0x00000080
    ,TEST_POS = 7
    ,TEST_0 = 0x00000000 // Normal Operation
    ,TEST_1 = 0x00000080 // Test Mode
    ,CON_MASK = 0x000000EF
    ;
  };
  // Status Register
  struct STATUS : reg<ip_ver, base + 0x4>
  {
    static constexpr typename STATUS::type
    // Last Error Code (Type Of The Last Error To Occur On The CAN Bus) The LEC field holds a code, which indicates the type of the last error to occur on the CAN bus. This field will be cleared to '0' when a message has been transferred (reception or transmission) without error. The unused code '7' may be written by the CPU to check for updates. The following table describes the error code. (bits: 2-0)
     LEC_MASK = 0x00000007
    ,LEC_POS = 0
    // Transmitted A Message Successfully (bits: 3)
    ,TXOK_MASK = 0x00000008
    ,TXOK_POS = 3
    ,TXOK_0 = 0x00000000 // Since this bit was reset by the CPU, no message has been successfully transmitted. This bit is never reset by the CAN Core
    ,TXOK_1 = 0x00000008 // Since this bit was last reset by the CPU, a message has been successfully (error free and acknowledged by at least one other node) transmitted
    // Received A Message Successfully (bits: 4)
    ,RXOK_MASK = 0x00000010
    ,RXOK_POS = 4
    ,RXOK_0 = 0x00000000 // No message has been successfully received since this bit was last reset by the CPU. This bit is never reset by the CAN Core
    ,RXOK_1 = 0x00000010 // A message has been successfully received since this bit was last reset by the CPU (independent of the result of acceptance filtering)
    // Error Passive (Read Only) (bits: 5)
    ,EPASS_MASK = 0x00000020
    ,EPASS_POS = 5
    ,EPASS_0 = 0x00000000 // The CAN Core is error active
    ,EPASS_1 = 0x00000020 // The CAN Core is in the error passive state as defined in the CAN Specification
    // Error Warning Status (Read Only) (bits: 6)
    ,EWARN_MASK = 0x00000040
    ,EWARN_POS = 6
    ,EWARN_0 = 0x00000000 // Both error counters are below the error warning limit of 96
    ,EWARN_1 = 0x00000040 // At least one of the error counters in the EML has reached the error warning limit of 96
    // Bus-Off Status (Read Only) (bits: 7)
    ,BOFF_MASK = 0x00000080
    ,BOFF_POS = 7
    ,BOFF_0 = 0x00000000 // The CAN module is not in bus-off state
    ,BOFF_1 = 0x00000080 // The CAN module is in bus-off state
    ,STATUS_MASK = 0x000000FF
    ;
  };
  // Error Counter Register
  struct ERR : reg<ip_ver, base + 0x8>
  {
    static constexpr typename ERR::type
    // Transmit Error Counter Actual state of the Transmit Error Counter. Values between 0 and 255. (bits: 7-0)
     TEC_MASK = 0x000000FF
    ,TEC_POS = 0
    // Receive Error Counter Actual state of the Receive Error Counter. Values between 0 and 127. (bits: 14-8)
    ,REC_MASK = 0x00007F00
    ,REC_POS = 8
    // Receive Error Passive (bits: 15)
    ,RP_MASK = 0x00008000
    ,RP_POS = 15
    ,RP_0 = 0x00000000 // The Receive Error Counter is below the error passive level
    ,RP_1 = 0x00008000 // The Receive Error Counter has reached the error passive level as defined in the CAN Specification
    ,ERR_MASK = 0x0000FFFF
    ;
  };
  // Bit Timing Register
  struct BTIME : reg<ip_ver, base + 0xC, 0x00002301>
  {
    static constexpr typename BTIME::type
    // Baud Rate Prescaler 0x01-0x3F: The value by which the oscillator frequency is divided for generating the bit time quanta. The bit time is built up from a multiple of this quantum. Valid values for the Baud Rate Prescaler are [0...63]. The actual interpretation by the hardware of this value is such that one more than the value programmed here is used. (bits: 5-0)
     BRP_MASK = 0x0000003F
    ,BRP_POS = 0
    // (Re)Synchronization Jump Width 0x0-0x3: Valid programmed values are [0...3]. The actual interpretation by the hardware of this value is such that one more than the value programmed here is used. (bits: 7-6)
    ,SJW_MASK = 0x000000C0
    ,SJW_POS = 6
    // Time Segment Before The Sample Point Minus Sync_Seg 0x01-0x0F: valid values for TSeg1 are [1...15]. The actual interpretation by the hardware of this value is such that one more than the value programmed is used. (bits: 11-8)
    ,TSEG1_MASK = 0x00000F00
    ,TSEG1_POS = 8
    // Time Segment After Sample Point 0x0-0x7: Valid values for TSeg2 are [0...7]. The actual interpretation by the hardware of this value is such that one more than the value programmed here is used. (bits: 14-12)
    ,TSEG2_MASK = 0x00007000
    ,TSEG2_POS = 12
    ,BTIME_MASK = 0x00007FFF
    ;
  };
  // Interrupt Identifier Register
  struct IIDR : reg<ip_ver, base + 0x10>
  {
    static constexpr typename IIDR::type
    // Interrupt Identifier (Indicates The Source Of The Interrupt) If several interrupts are pending, the CAN Interrupt Register will point to the pending interrupt with the highest priority, disregarding their chronological order. An interrupt remains pending until the application software has cleared it. If IntId is different from 0x0000 and IE (CAN_IFn_MCON[1]) is set, the IRQ interrupt signal to the EIC is active. The interrupt remains active until IntId is back to value 0x0000 (the cause of the interrupt is reset) or until IE is reset. The Status Interrupt has the highest priority. Among the message interrupts, the Message Object' s interrupt priority decreases with increasing message number. A message interrupt is cleared by clearing the Message Object's IntPnd bit (CAN_IFn_MCON[13]). The Status Interrupt is cleared by reading the Status Register. (bits: 15-0)
     INTID_MASK = 0x0000FFFF
    ,INTID_POS = 0
    ,IIDR_MASK = 0x0000FFFF
    ;
  };
  // Test Register (Register Map Note 1)
  struct TEST : reg<ip_ver, base + 0x14, 0x00000080>
  {
    static constexpr typename TEST::type
    // Basic Mode (bits: 2)
     BASIC_MASK = 0x00000004
    ,BASIC_POS = 2
    ,BASIC_0 = 0x00000000 // Basic Mode Disabled
    ,BASIC_1 = 0x00000004 // IF1 Registers used as Tx Buffer, IF2 Registers used as Rx Buffer
    // Silent Mode (bits: 3)
    ,SILENT_MASK = 0x00000008
    ,SILENT_POS = 3
    ,SILENT_0 = 0x00000000 // Normal operation
    ,SILENT_1 = 0x00000008 // The module is in Silent Mode
    // Loop Back Mode Enable Control (bits: 4)
    ,LBACK_MASK = 0x00000010
    ,LBACK_POS = 4
    ,LBACK_0 = 0x00000000 // Loop Back Mode is Disabled
    ,LBACK_1 = 0x00000010 // Loop Back Mode is Enabled
    // Tx[1:0]: Control Of CAN_TX Pin (bits: 6-5)
    ,TX_MASK = 0x00000060
    ,TX_POS = 5
    ,TX_0 = 0x00000000 // Reset value, CAN_TX pin is controlled by the CAN Core
    ,TX_1 = 0x00000020 // Sample Point can be monitored at CAN_TX pin
    ,TX_2 = 0x00000040 // CAN_TX pin drives a dominant ('0') value
    ,TX_3 = 0x00000060 // CAN_TX pin drives a recessive ('1') value
    // Monitors The Actual Value Of CAN_RX Pin (Read Only) (bits: 7)
    ,RX_MASK = 0x00000080
    ,RX_POS = 7
    ,RX_0 = 0x00000000 // The CAN bus is dominant (CAN_RX = '0')
    ,RX_1 = 0x00000080 // The CAN bus is recessive (CAN_RX = '1')
    ,TEST_MASK = 0x000000FC
    ;
  };
  // Baud Rate Prescaler Extension Register
  struct BRPE : reg<ip_ver, base + 0x18>
  {
    static constexpr typename BRPE::type
    // Baud Rate Prescaler Extension 0x00-0x0F: By programming BRPE, the Baud Rate Prescaler can be extended to values up to 1023. The actual interpretation by the hardware is that one more than the value programmed by BRPE (MSBs) and BTIME (LSBs) is used. (bits: 3-0)
     BRPEVAL_MASK = 0x0000000F
    ,BRPEVAL_POS = 0
    ,BRPE_MASK = 0x0000000F
    ;
  };
  // IF1 (Register Map Note 2) Command Request Registers
  struct IF1_CREQ : reg<ip_ver, base + 0x20, 0x00000001>
  {
    static constexpr typename IF1_CREQ::type
    // Message Number 0x01-0x20: Valid Message Number, the Message Object in the Message. RAM is selected for data transfer. 0x00: Not a valid Message Number, interpreted as 0x20. 0x21-0x3F: Not a valid Message Number, interpreted as 0x01-0x1F. (bits: 5-0)
     MESSAGENUMBER_MASK = 0x0000003F
    ,MESSAGENUMBER_POS = 0
    // Busy Flag (bits: 15)
    ,BUSY_MASK = 0x00008000
    ,BUSY_POS = 15
    ,BUSY_0 = 0x00000000 // Read/write action has finished
    ,BUSY_1 = 0x00008000 // Writing to the IFn Command Request Register is in progress. This bit can only be read by the software
    ,IF1_CREQ_MASK = 0x0000803F
    ;
  };
  // IF1 Command Mask Register
  struct IF1_CMASK : reg<ip_ver, base + 0x24>
  {
    static constexpr typename IF1_CMASK::type
    // Access Data Bytes [7:4] Write Operation: (bits: 0)
     DAT_B_MASK = 0x00000001
    ,DAT_B_POS = 0
    ,DAT_B_0 = 0x00000000 // Data Bytes [7:4] unchanged
    ,DAT_B_1 = 0x00000001 // Transfer Data Bytes [7:4] to Message Object. Transfer Data Bytes [7:4] to IFn Message Buffer Register
    // Access Data Bytes [3:0] Write Operation: (bits: 1)
    ,DAT_A_MASK = 0x00000002
    ,DAT_A_POS = 1
    ,DAT_A_0 = 0x00000000 // Data Bytes [3:0] unchanged
    ,DAT_A_1 = 0x00000002 // Transfer Data Bytes [3:0] to Message Object. Transfer Data Bytes [3:0] to IFn Message Buffer Register
    // Access Transmission Request Bit When Write Operation Note: A read access to a Message Object can be combined with the reset of the control bits IntPnd and NewDat. The values of these bits transferred to the IFn Message Control Register always reflect the status before resetting these bits. (bits: 2)
    ,TXRQST_NEWDAT_MASK = 0x00000004
    ,TXRQST_NEWDAT_POS = 2
    ,TXRQST_NEWDAT_0 = 0x00000000 // TxRqst bit unchanged. NewDat bit remains unchanged
    ,TXRQST_NEWDAT_1 = 0x00000004 // Set TxRqst bit. Clear NewDat bit in the Message Object
    // Clear Interrupt Pending Bit Write Operation: When writing to a Message Object, this bit is ignored. Read Operation: (bits: 3)
    ,CLRINTPND_MASK = 0x00000008
    ,CLRINTPND_POS = 3
    ,CLRINTPND_0 = 0x00000000 // IntPnd bit (CAN_IFn_MCON[13]) remains unchanged
    ,CLRINTPND_1 = 0x00000008 // Clear IntPnd bit in the Message Object
    // Control Access Control Bit Write Operation: (bits: 4)
    ,CONTROL_MASK = 0x00000010
    ,CONTROL_POS = 4
    ,CONTROL_0 = 0x00000000 // Control Bits unchanged
    ,CONTROL_1 = 0x00000010 // Transfer Control Bits to Message Object. Transfer Control Bits to IFn Message Buffer Register
    // Access Arbitration Bits Write Operation: (bits: 5)
    ,ARB_MASK = 0x00000020
    ,ARB_POS = 5
    ,ARB_0 = 0x00000000 // Arbitration bits unchanged
    ,ARB_1 = 0x00000020 // Transfer Identifier + Dir (CAN_IFn_ARB2[13]) + Xtd (CAN_IFn_ARB2[14]) + MsgVal (CAN_IFn_ARB2[15]) to Message Object. Transfer Identifier + Dir + Xtd + MsgVal to IFn Message Buffer Register
    // Access Mask Bits Write Operation: (bits: 6)
    ,MASK_MASK = 0x00000040
    ,MASK_POS = 6
    ,MASK_0 = 0x00000000 // Mask bits unchanged
    ,MASK_1 = 0x00000040 // Transfer Identifier Mask + MDir + MXtd to Message Object. Transfer Identifier Mask + MDir + MXtd to IFn Message Buffer Register
    // Write / Read Mode (bits: 7)
    ,WR_RD_MASK = 0x00000080
    ,WR_RD_POS = 7
    ,WR_RD_0 = 0x00000000 // Read: Transfer data from the Message Object addressed by the Command Request Register into the selected Message Buffer Registers
    ,WR_RD_1 = 0x00000080 // Write: Transfer data from the selected Message Buffer Registers to the Message Object addressed by the Command Request Register
    ,IF1_CMASK_MASK = 0x000000FF
    ;
  };
  // IF1 Mask 1 Register
  struct IF1_MASK1 : reg<ip_ver, base + 0x28, 0x0000FFFF>
  {
    static constexpr typename IF1_MASK1::type
    // Identifier Mask 15-0 (bits: 15-0)
     MSK15_0_MASK = 0x0000FFFF
    ,MSK15_0_POS = 0
    ,MSK15_0_0 = 0x00000000 // The corresponding bit in the identifier of the message object cannot inhibit the match in the acceptance filtering
    ,MSK15_0_1 = 0x00000001 // The corresponding identifier bit is used for acceptance filtering
    ,IF1_MASK1_MASK = 0x0000FFFF
    ;
  };
  // IF1 Mask 2 Register
  struct IF1_MASK2 : reg<ip_ver, base + 0x2C, 0x0000FFFF>
  {
    static constexpr typename IF1_MASK2::type
    // Identifier Mask 28-16 (bits: 12-0)
     MSK28_16_MASK = 0x00001FFF
    ,MSK28_16_POS = 0
    ,MSK28_16_0 = 0x00000000 // The corresponding bit in the identifier of the message object cannot inhibit the match in the acceptance filtering
    ,MSK28_16_1 = 0x00000001 // The corresponding identifier bit is used for acceptance filtering
    // Mask Message Direction (bits: 14)
    ,MDIR_MASK = 0x00004000
    ,MDIR_POS = 14
    ,MDIR_0 = 0x00000000 // The message direction bit (Dir (CAN_IFn_ARB2[13])) has no effect on the acceptance filtering
    ,MDIR_1 = 0x00004000 // The message direction bit (Dir) is used for acceptance filtering
    // Mask Extended Identifier Note: When 11-bit (standard) Identifiers are used for a Message Object, the identifiers of received Data Frames are written into bits ID28 to ID18 (CAN_IFn_ARB2[12:2]). For acceptance filtering, only these bits together with mask bits Msk28 to Msk18 (CAN_IFn_MASK2[12:2]) are considered. (bits: 15)
    ,MXTD_MASK = 0x00008000
    ,MXTD_POS = 15
    ,MXTD_0 = 0x00000000 // The extended identifier bit (IDE) has no effect on the acceptance filtering
    ,MXTD_1 = 0x00008000 // The extended identifier bit (IDE) is used for acceptance filtering
    ,IF1_MASK2_MASK = 0x0000DFFF
    ;
  };
  // IF1 Arbitration 1 Register
  struct IF1_ARB1 : reg<ip_ver, base + 0x30>
  {
    static constexpr typename IF1_ARB1::type
    // Message Identifier 15-0 ID28 - ID0, 29-bit Identifier (Extended Frame). ID28 - ID18, 11-bit Identifier (Standard Frame). (bits: 15-0)
     ID15_0_MASK = 0x0000FFFF
    ,ID15_0_POS = 0
    ,IF1_ARB1_MASK = 0x0000FFFF
    ;
  };
  // IF1 Arbitration 2 Register
  struct IF1_ARB2 : reg<ip_ver, base + 0x34>
  {
    static constexpr typename IF1_ARB2::type
    // Message Identifier 28-16 ID28 - ID0, 29-bit Identifier (Extended Frame). ID28 - ID18, 11-bit Identifier (Standard Frame). (bits: 12-0)
     ID28_16_MASK = 0x00001FFF
    ,ID28_16_POS = 0
    // Message Direction (bits: 13)
    ,DIR_MASK = 0x00002000
    ,DIR_POS = 13
    ,DIR_0 = 0x00000000 // Direction is receive
    ,DIR_1 = 0x00002000 // Direction is transmit
    // Extended Identifier (bits: 14)
    ,XTD_MASK = 0x00004000
    ,XTD_POS = 14
    ,XTD_0 = 0x00000000 // The 11-bit (standard) Identifier will be used for this Message Object
    ,XTD_1 = 0x00004000 // The 29-bit (extended) Identifier will be used for this Message Object
    // Message Valid Note: The application software must reset the MsgVal bit of all unused Messages Objects during the initialization before it resets bit Init (CAN_CON[0]). This bit must also be reset before the identifier Id28-0 (CAN_IFn_ARB1/2), the control bits Xtd (CAN_IFn_ARB2[14]), Dir (CAN_IFn_ARB2[13]), or the Data Length Code DLC3-0 (CAN_IFn_MCON[3:0]) are modified, or if the Messages Object is no longer required. (bits: 15)
    ,MSGVAL_MASK = 0x00008000
    ,MSGVAL_POS = 15
    ,MSGVAL_0 = 0x00000000 // The Message Object is ignored by the Message Handler
    ,MSGVAL_1 = 0x00008000 // The Message Object is configured and should be considered by the Message Handler
    ,IF1_ARB2_MASK = 0x0000FFFF
    ;
  };
  // IF1 Message Control Register
  struct IF1_MCON : reg<ip_ver, base + 0x38>
  {
    static constexpr typename IF1_MCON::type
    // Data Length Code 0-8: Data Frame has 0-8 data bytes. 9-15: Data Frame has 8 data bytes Note: The Data Length Code of a Message Object must be defined the same as in all the corresponding objects with the same identifier at other nodes. When the Message Handler stores a data frame, it will write the DLC to the value given by the received message. Data(0): 1st data byte of a CAN Data Frame Data(1): 2nd data byte of a CAN Data Frame Data(2): 3rd data byte of a CAN Data Frame Data(3): 4th data byte of a CAN Data Frame Data(4): 5th data byte of a CAN Data Frame Data(5): 6th data byte of a CAN Data Frame Data(6): 7th data byte of a CAN Data Frame Data(7): 8th data byte of a CAN Data Frame Note: The Data(0) byte is the first data byte shifted into the shift register of the CAN Core during a reception while the Data(7) byte is the last. When the Message Handler stores a Data Frame, it will write all the eight data bytes into a Message Object. If the Data Length Code is less than 8, the remaining bytes of the Message Object will be overwritten by unspecified values. (bits: 3-0)
     DLC_MASK = 0x0000000F
    ,DLC_POS = 0
    // End Of Buffer Note: This bit is used to concatenate two or more Message Objects (up to 32) to build a FIFO Buffer. For single Message Objects (not belonging to a FIFO Buffer), this bit must always be set to one. (bits: 7)
    ,EOB_MASK = 0x00000080
    ,EOB_POS = 7
    ,EOB_0 = 0x00000000 // Message Object belongs to a FIFO Buffer and is not the last Message Object of that FIFO Buffer
    ,EOB_1 = 0x00000080 // Single Message Object or last Message Object of a FIFO Buffer
    // Transmit Request (bits: 8)
    ,TXRQST_MASK = 0x00000100
    ,TXRQST_POS = 8
    ,TXRQST_0 = 0x00000000 // This Message Object is not waiting for transmission
    ,TXRQST_1 = 0x00000100 // The transmission of this Message Object is requested and is not yet done
    // Remote Enable Control (bits: 9)
    ,RMTEN_MASK = 0x00000200
    ,RMTEN_POS = 9
    ,RMTEN_0 = 0x00000000 // At the reception of a Remote Frame, TxRqst (CAN_IFn_MCON[8]) is left unchanged
    ,RMTEN_1 = 0x00000200 // At the reception of a Remote Frame, TxRqst is set
    // Receive Interrupt Enable Control (bits: 10)
    ,RXIE_MASK = 0x00000400
    ,RXIE_POS = 10
    ,RXIE_0 = 0x00000000 // IntPnd (CAN_IFn_MCON[13]) will be left unchanged after a successful reception of a frame
    ,RXIE_1 = 0x00000400 // IntPnd will be set after a successful reception of a frame
    // Transmit Interrupt Enable Control (bits: 11)
    ,TXIE_MASK = 0x00000800
    ,TXIE_POS = 11
    ,TXIE_0 = 0x00000000 // IntPnd (CAN_IFn_MCON[13]) will be left unchanged after the successful transmission of a frame
    ,TXIE_1 = 0x00000800 // IntPnd will be set after a successful transmission of a frame
    // Use Acceptance Mask Note: If the UMask bit is set to one, the Message Object's mask bits have to be programmed during initialization of the Message Object before MsgVal bit (CAN_IFn_ARB2[15]) is set to one. (bits: 12)
    ,UMASK_MASK = 0x00001000
    ,UMASK_POS = 12
    ,UMASK_0 = 0x00000000 // Mask ignored
    ,UMASK_1 = 0x00001000 // Use Mask (Msk28-0, MXtd, and MDir) for acceptance filtering
    // Interrupt Pending (bits: 13)
    ,INTPND_MASK = 0x00002000
    ,INTPND_POS = 13
    ,INTPND_0 = 0x00000000 // This message object is not the source of an interrupt
    ,INTPND_1 = 0x00002000 // This message object is the source of an interrupt. The Interrupt Identifier in the Interrupt Register will point to this message object if there is no other interrupt source with higher priority
    // (bits: 14)
    ,MSGLST_MASK = 0x00004000
    ,MSGLST_POS = 14
    ,MSGLST_0 = 0x00000000 // No message lost since last time this bit was reset by the CPU
    ,MSGLST_1 = 0x00004000 // The Message Handler stored a new message into this object when NewDat was still set, the CPU has lost a message
    // New Data (bits: 15)
    ,NEWDAT_MASK = 0x00008000
    ,NEWDAT_POS = 15
    ,NEWDAT_0 = 0x00000000 // No new data has been written into the data portion of this Message Object by the Message Handler since last time this flag was cleared by the application software
    ,NEWDAT_1 = 0x00008000 // The Message Handler or the application software has written new data into the data portion of this Message Object
    ,IF1_MCON_MASK = 0x0000FF8F
    ;
  };
  // IF1 Data A1 Register (Register Map Note 3)
  struct IF1_DAT_A1 : reg<ip_ver, base + 0x3C>
  {
    static constexpr typename IF1_DAT_A1::type
    // Data Byte 0 1st data byte of a CAN Data Frame. (bits: 7-0)
     DATA_0_MASK = 0x000000FF
    ,DATA_0_POS = 0
    // Data Byte 1 2nd data byte of a CAN Data Frame. (bits: 15-8)
    ,DATA_1_MASK = 0x0000FF00
    ,DATA_1_POS = 8
    ,IF1_DAT_A1_MASK = 0x0000FFFF
    ;
  };
  // IF1 Data A2 Register (Register Map Note 3)
  struct IF1_DAT_A2 : reg<ip_ver, base + 0x40>
  {
    static constexpr typename IF1_DAT_A2::type
    // Data Byte 2 3rd data byte of CAN Data Frame. (bits: 7-0)
     DATA_2_MASK = 0x000000FF
    ,DATA_2_POS = 0
    // Data Byte 3 4th data byte of CAN Data Frame. (bits: 15-8)
    ,DATA_3_MASK = 0x0000FF00
    ,DATA_3_POS = 8
    ,IF1_DAT_A2_MASK = 0x0000FFFF
    ;
  };
  // IF1 Data B1 Register (Register Map Note 3)
  struct IF1_DAT_B1 : reg<ip_ver, base + 0x44>
  {
    static constexpr typename IF1_DAT_B1::type
    // Data Byte 4 5th data byte of CAN Data Frame. (bits: 7-0)
     DATA_4_MASK = 0x000000FF
    ,DATA_4_POS = 0
    // Data Byte 5 6th data byte of CAN Data Frame. (bits: 15-8)
    ,DATA_5_MASK = 0x0000FF00
    ,DATA_5_POS = 8
    ,IF1_DAT_B1_MASK = 0x0000FFFF
    ;
  };
  // IF1 Data B2 Register (Register Map Note 3)
  struct IF1_DAT_B2 : reg<ip_ver, base + 0x48>
  {
    static constexpr typename IF1_DAT_B2::type
    // Data Byte 6 7th data byte of CAN Data Frame. (bits: 7-0)
     DATA_6_MASK = 0x000000FF
    ,DATA_6_POS = 0
    // Data Byte 7 8th data byte of CAN Data Frame. (bits: 15-8)
    ,DATA_7_MASK = 0x0000FF00
    ,DATA_7_POS = 8
    ,IF1_DAT_B2_MASK = 0x0000FFFF
    ;
  };
  // IF2 (Register Map Note 2) Command Request Registers
  using IF2_CREQ = reg<ip_ver, base + 0x80>;
  // IF2 Command Mask Register
  using IF2_CMASK = reg<ip_ver, base + 0x84>;
  // IF2 Mask 1 Register
  using IF2_MASK1 = reg<ip_ver, base + 0x88>;
  // IF2 Mask 2 Register
  using IF2_MASK2 = reg<ip_ver, base + 0x8C>;
  // IF2 Arbitration 1 Register
  using IF2_ARB1 = reg<ip_ver, base + 0x90>;
  // IF2 Arbitration 2 Register
  using IF2_ARB2 = reg<ip_ver, base + 0x94>;
  // IF2 Message Control Register
  using IF2_MCON = reg<ip_ver, base + 0x98>;
  // IF2 Data A1 Register (Register Map Note 3)
  using IF2_DAT_A1 = reg<ip_ver, base + 0x9C>;
  // IF2 Data A2 Register (Register Map Note 3)
  using IF2_DAT_A2 = reg<ip_ver, base + 0xA0>;
  // IF2 Data B1 Register (Register Map Note 3)
  using IF2_DAT_B1 = reg<ip_ver, base + 0xA4>;
  // IF2 Data B2 Register (Register Map Note 3)
  using IF2_DAT_B2 = reg<ip_ver, base + 0xA8>;
  // Transmission Request Register 1
  struct TXREQ1 : reg<ip_ver, base + 0x100>
  {
    static constexpr typename TXREQ1::type
    // Transmission Request Bits 16-1 (Of All Message Objects) These bits are read only. (bits: 15-0)
     TXRQST16_1_MASK = 0x0000FFFF
    ,TXRQST16_1_POS = 0
    ,TXRQST16_1_0 = 0x00000000 // This Message Object is not waiting for transmission
    ,TXRQST16_1_1 = 0x00000001 // The transmission of this Message Object is requested and is not yet done
    ,TXREQ1_MASK = 0x0000FFFF
    ;
  };
  // Transmission Request Register 2
  struct TXREQ2 : reg<ip_ver, base + 0x104>
  {
    static constexpr typename TXREQ2::type
    // Transmission Request Bits 32-17 (Of All Message Objects) These bits are read only. (bits: 15-0)
     TXRQST32_17_MASK = 0x0000FFFF
    ,TXRQST32_17_POS = 0
    ,TXRQST32_17_0 = 0x00000000 // This Message Object is not waiting for transmission
    ,TXRQST32_17_1 = 0x00000001 // The transmission of this Message Object is requested and is not yet done
    ,TXREQ2_MASK = 0x0000FFFF
    ;
  };
  // New Data Register 1
  struct NDAT1 : reg<ip_ver, base + 0x120>
  {
    static constexpr typename NDAT1::type
    // New Data Bits 16-1 (Of All Message Objects) (bits: 15-0)
     NEWDATA16_1_MASK = 0x0000FFFF
    ,NEWDATA16_1_POS = 0
    ,NEWDATA16_1_0 = 0x00000000 // No new data has been written into the data portion of this Message Object by the Message Handler since the last time this flag was cleared by the application software
    ,NEWDATA16_1_1 = 0x00000001 // The Message Handler or the application software has written new data into the data portion of this Message Object
    ,NDAT1_MASK = 0x0000FFFF
    ;
  };
  // New Data Register 2
  struct NDAT2 : reg<ip_ver, base + 0x124>
  {
    static constexpr typename NDAT2::type
    // New Data Bits 32-17 (Of All Message Objects) (bits: 15-0)
     NEWDATA32_17_MASK = 0x0000FFFF
    ,NEWDATA32_17_POS = 0
    ,NEWDATA32_17_0 = 0x00000000 // No new data has been written into the data portion of this Message Object by the Message Handler since the last time this flag was cleared by the application software
    ,NEWDATA32_17_1 = 0x00000001 // The Message Handler or the application software has written new data into the data portion of this Message Object
    ,NDAT2_MASK = 0x0000FFFF
    ;
  };
  // Interrupt Pending Register 1
  struct IPND1 : reg<ip_ver, base + 0x140>
  {
    static constexpr typename IPND1::type
    // Interrupt Pending Bits 16-1 (Of All Message Objects) (bits: 15-0)
     INTPND16_1_MASK = 0x0000FFFF
    ,INTPND16_1_POS = 0
    ,INTPND16_1_0 = 0x00000000 // This message object is not the source of an interrupt
    ,INTPND16_1_1 = 0x00000001 // This message object is the source of an interrupt
    ,IPND1_MASK = 0x0000FFFF
    ;
  };
  // Interrupt Pending Register 2
  struct IPND2 : reg<ip_ver, base + 0x144>
  {
    static constexpr typename IPND2::type
    // Interrupt Pending Bits 32-17 (Of All Message Objects) (bits: 15-0)
     INTPND32_17_MASK = 0x0000FFFF
    ,INTPND32_17_POS = 0
    ,INTPND32_17_0 = 0x00000000 // This message object is not the source of an interrupt
    ,INTPND32_17_1 = 0x00000001 // This message object is the source of an interrupt
    ,IPND2_MASK = 0x0000FFFF
    ;
  };
  // Message Valid Register 1
  struct MVLD1 : reg<ip_ver, base + 0x160>
  {
    static constexpr typename MVLD1::type
    // Message Valid Bits 16-1 (Of All Message Objects) (Read Only) Ex. CAN_MVLD1[0] means Message object No.1 is valid or not. If CAN_MVLD1[0] is set, message object No.1 is configured. (bits: 15-0)
     MSGVAL16_1_MASK = 0x0000FFFF
    ,MSGVAL16_1_POS = 0
    ,MSGVAL16_1_0 = 0x00000000 // This Message Object is ignored by the Message Handler
    ,MSGVAL16_1_1 = 0x00000001 // This Message Object is configured and should be considered by the Message Handler
    ,MVLD1_MASK = 0x0000FFFF
    ;
  };
  // Message Valid Register 2
  struct MVLD2 : reg<ip_ver, base + 0x164>
  {
    static constexpr typename MVLD2::type
    // Message Valid Bits 32-17 (Of All Message Objects) (Read Only) Ex.CAN_MVLD2[15] means Message object No.32 is valid or not. If CAN_MVLD2[15] is set, message object No.32 is configured. (bits: 15-0)
     MSGVAL32_17_MASK = 0x0000FFFF
    ,MSGVAL32_17_POS = 0
    ,MSGVAL32_17_0 = 0x00000000 // This Message Object is ignored by the Message Handler
    ,MSGVAL32_17_1 = 0x00000001 // This Message Object is configured and should be considered by the Message Handler
    ,MVLD2_MASK = 0x0000FFFF
    ;
  };
  // Wake-up Enable Register
  struct WU_EN : reg<ip_ver, base + 0x168>
  {
    static constexpr typename WU_EN::type
    // Wake-Up Enable Control Note: User can wake-up system when there is a falling edge in the CAN_Rx pin. (bits: 0)
     WAKUP_EN_MASK = 0x00000001
    ,WAKUP_EN_POS = 0
    ,WAKUP_EN_0 = 0x00000000 // The wake-up function Disabled
    ,WAKUP_EN_1 = 0x00000001 // The wake-up function Enabled
    ,WU_EN_MASK = 0x00000001
    ;
  };
  // Wake-up Status Register
  struct WU_STATUS : reg<ip_ver, base + 0x16C>
  {
    static constexpr typename WU_STATUS::type
    // Wake-Up Status Note: This bit can be cleared by writing '0'. (bits: 0)
     WAKUP_STS_MASK = 0x00000001
    ,WAKUP_STS_POS = 0
    ,WAKUP_STS_0 = 0x00000000 // No wake-up event occurred
    ,WAKUP_STS_1 = 0x00000001 // Wake-up event occurred
    ,WU_STATUS_MASK = 0x00000001
    ;
  };
}; // struct CAN

} // namespace lmcu::device::ip::v1

