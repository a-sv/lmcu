/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// USBD Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct USBD
{
  static constexpr auto ip_ver = ip_version::_1;

  // USB Device Interrupt Enable Register
  struct INTEN : reg<ip_ver, base + 0x0>
  {
    static constexpr typename INTEN::type
    // Bus Event Interrupt Enable Bit (bits: 0)
     BUSIEN_MASK = 0x00000001
    ,BUSIEN_POS = 0
    ,BUSIEN_0 = 0x00000000 // BUS event interrupt Disabled
    ,BUSIEN_1 = 0x00000001 // BUS event interrupt Enabled
    // USB Event Interrupt Enable Bit (bits: 1)
    ,USBIEN_MASK = 0x00000002
    ,USBIEN_POS = 1
    ,USBIEN_0 = 0x00000000 // USB event interrupt Disabled
    ,USBIEN_1 = 0x00000002 // USB event interrupt Enabled
    // VBUS Detection Interrupt Enable Bit (bits: 2)
    ,VBDETIEN_MASK = 0x00000004
    ,VBDETIEN_POS = 2
    ,VBDETIEN_0 = 0x00000000 // VBUS detection Interrupt Disabled
    ,VBDETIEN_1 = 0x00000004 // VBUS detection Interrupt Enabled
    // USB No-event-wake-up Interrupt Enable Bit (bits: 3)
    ,NEVWKIEN_MASK = 0x00000008
    ,NEVWKIEN_POS = 3
    ,NEVWKIEN_0 = 0x00000000 // No-event-wake-up Interrupt Disabled
    ,NEVWKIEN_1 = 0x00000008 // No-event-wake-up Interrupt Enabled
    // Start of Frame Interrupt Enable Bit (bits: 4)
    ,SOFIEN_MASK = 0x00000010
    ,SOFIEN_POS = 4
    ,SOFIEN_0 = 0x00000000 // SOF Interrupt Disabled
    ,SOFIEN_1 = 0x00000010 // SOF Interrupt Enabled
    // Wake-up Function Enable Bit (bits: 8)
    ,WKEN_MASK = 0x00000100
    ,WKEN_POS = 8
    ,WKEN_0 = 0x00000000 // USB wake-up function Disabled
    ,WKEN_1 = 0x00000100 // USB wake-up function Enabled
    // Active NAK Function and Its Status in IN Token (bits: 15)
    ,INNAKEN_MASK = 0x00008000
    ,INNAKEN_POS = 15
    ,INNAKEN_0 = 0x00000000 // When device responds NAK after receiving IN token, IN NAK status will not be updated to USBD_EPSTS0 and USBD_EPSTS1register, so that the USB interrupt event will not be asserted
    ,INNAKEN_1 = 0x00008000 // IN NAK status will be updated to USBD_EPSTS0 and USBD_EPSTS1 register and the USB interrupt event will be asserted, when the device responds NAK after receiving IN token
    ,INTEN_MASK = 0x0000811F
    ;
  };
  // USB Device Interrupt Event Status Register
  struct INTSTS : reg<ip_ver, base + 0x4>
  {
    static constexpr typename INTSTS::type
    // BUS Interrupt Status The BUS event means that there is one of the suspense or the resume function in the bus. (bits: 0)
     BUSIF_MASK = 0x00000001
    ,BUSIF_POS = 0
    ,BUSIF_0 = 0x00000000 // No BUS event occurred
    ,BUSIF_1 = 0x00000001 // Bus event occurred; check USBD_ATTR[3:0] to know which kind of bus event was occurred, cleared by write 1 to USBD_INTSTS[0]
    // USB Event Interrupt Status The USB event includes the SETUP Token, IN Token, OUT ACK, ISO IN, or ISO OUT events in the bus. (bits: 1)
    ,USBIF_MASK = 0x00000002
    ,USBIF_POS = 1
    ,USBIF_0 = 0x00000000 // No USB event occurred
    ,USBIF_1 = 0x00000002 // USB event occurred, check EPSTS0~5[2:0] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[1] or EPSTS0~11 and SETUP (USBD_INTSTS[31])
    // VBUS Detection Interrupt Status (bits: 2)
    ,VBDETIF_MASK = 0x00000004
    ,VBDETIF_POS = 2
    ,VBDETIF_0 = 0x00000000 // There is not attached/detached event in the USB
    ,VBDETIF_1 = 0x00000004 // There is attached/detached event in the USB bus and it is cleared by write 1 to USBD_INTSTS[2]
    // No-event-wake-up Interrupt Status (bits: 3)
    ,NEVWKIF_MASK = 0x00000008
    ,NEVWKIF_POS = 3
    ,NEVWKIF_0 = 0x00000000 // NEVWK event does not occur
    ,NEVWKIF_1 = 0x00000008 // No-event-wake-up event occurred, cleared by write 1 to USBD_INTSTS[3]
    // Start of Frame Interrupt Status (bits: 4)
    ,SOFIF_MASK = 0x00000010
    ,SOFIF_POS = 4
    ,SOFIF_0 = 0x00000000 // SOF event does not occur
    ,SOFIF_1 = 0x00000010 // SOF event occurred, cleared by write 1 to USBD_INTSTS[4]
    // Endpoint 0's USB Event Status (bits: 16)
    ,EPEVT0_MASK = 0x00010000
    ,EPEVT0_POS = 16
    ,EPEVT0_0 = 0x00000000 // No event occurred in endpoint 0
    ,EPEVT0_1 = 0x00010000 // USB event occurred on Endpoint 0, check USBD_EPSTS0[3:0] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[16] or USBD_INTSTS[1]
    // Endpoint 1's USB Event Status (bits: 17)
    ,EPEVT1_MASK = 0x00020000
    ,EPEVT1_POS = 17
    ,EPEVT1_0 = 0x00000000 // No event occurred in endpoint 1
    ,EPEVT1_1 = 0x00020000 // USB event occurred on Endpoint 1, check USBD_EPSTS0[7:4] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[17] or USBD_INTSTS[1]
    // Endpoint 2's USB Event Status (bits: 18)
    ,EPEVT2_MASK = 0x00040000
    ,EPEVT2_POS = 18
    ,EPEVT2_0 = 0x00000000 // No event occurred in endpoint 2
    ,EPEVT2_1 = 0x00040000 // USB event occurred on Endpoint 2, check USBD_EPSTS0[11:8] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[18] or USBD_INTSTS[1]
    // Endpoint 3's USB Event Status (bits: 19)
    ,EPEVT3_MASK = 0x00080000
    ,EPEVT3_POS = 19
    ,EPEVT3_0 = 0x00000000 // No event occurred in endpoint 3
    ,EPEVT3_1 = 0x00080000 // USB event occurred on Endpoint 3, check USBD_EPSTS0[15:12] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[19] or USBD_INTSTS[1]
    // Endpoint 4's USB Event Status (bits: 20)
    ,EPEVT4_MASK = 0x00100000
    ,EPEVT4_POS = 20
    ,EPEVT4_0 = 0x00000000 // No event occurred in endpoint 4
    ,EPEVT4_1 = 0x00100000 // USB event occurred on Endpoint 4, check USBD_EPSTS0[19:16] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[20] or USBD_INTSTS[1]
    // Endpoint 5's USB Event Status (bits: 21)
    ,EPEVT5_MASK = 0x00200000
    ,EPEVT5_POS = 21
    ,EPEVT5_0 = 0x00000000 // No event occurred in endpoint 5
    ,EPEVT5_1 = 0x00200000 // USB event occurred on Endpoint 5, check USBD_EPSTS0[23:20] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[21] or USBD_INTSTS[1]
    // Endpoint 6's USB Event Status (bits: 22)
    ,EPEVT6_MASK = 0x00400000
    ,EPEVT6_POS = 22
    ,EPEVT6_0 = 0x00000000 // No event occurred in endpoint 6
    ,EPEVT6_1 = 0x00400000 // USB event occurred on Endpoint 6, check USBD_EPSTS0[27:24] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[22] or USBD_INTSTS[1]
    // Endpoint 7's USB Event Status (bits: 23)
    ,EPEVT7_MASK = 0x00800000
    ,EPEVT7_POS = 23
    ,EPEVT7_0 = 0x00000000 // No event occurred in endpoint 7
    ,EPEVT7_1 = 0x00800000 // USB event occurred on Endpoint 7, check USBD_EPSTS0[31:28] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[23] or USBD_INTSTS[1]
    // Endpoint 8's USB Event Status (bits: 24)
    ,EPEVT8_MASK = 0x01000000
    ,EPEVT8_POS = 24
    ,EPEVT8_0 = 0x00000000 // No event occurred in endpoint 8
    ,EPEVT8_1 = 0x01000000 // USB event occurred on Endpoint 8, check USBD_EPSTS1[3 :0] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[24] or USBD_INTSTS[1]
    // Endpoint 9's USB Event Status (bits: 25)
    ,EPEVT9_MASK = 0x02000000
    ,EPEVT9_POS = 25
    ,EPEVT9_0 = 0x00000000 // No event occurred in endpoint 9
    ,EPEVT9_1 = 0x02000000 // USB event occurred on Endpoint 9, check USBD_EPSTS1[7 :4] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[25] or USBD_INTSTS[1]
    // Endpoint 10's USB Event Status (bits: 26)
    ,EPEVT10_MASK = 0x04000000
    ,EPEVT10_POS = 26
    ,EPEVT10_0 = 0x00000000 // No event occurred in endpoint 10
    ,EPEVT10_1 = 0x04000000 // USB event occurred on Endpoint 10, check USBD_EPSTS1[11 :8] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[26] or USBD_INTSTS[1]
    // Endpoint 11's USB Event Status (bits: 27)
    ,EPEVT11_MASK = 0x08000000
    ,EPEVT11_POS = 27
    ,EPEVT11_0 = 0x00000000 // No event occurred in endpoint 11
    ,EPEVT11_1 = 0x08000000 // USB event occurred on Endpoint 11, check USBD_EPSTS1[ 15:12] to know which kind of USB event was occurred, cleared by write 1 to USBD_INTSTS[27] or USBD_INTSTS[1]
    // Setup Event Status (bits: 31)
    ,SETUP_MASK = 0x80000000
    ,SETUP_POS = 31
    ,SETUP_0 = 0x00000000 // No Setup event
    ,SETUP_1 = 0x80000000 // Setup event occurred, cleared by write 1 to USBD_INTSTS[31]
    ,INTSTS_MASK = 0x8FFF001F
    ;
  };
  // USB Device Function Address Register
  struct FADDR : reg<ip_ver, base + 0x8>
  {
    static constexpr typename FADDR::type
    // USB Device Function Address (bits: 6-0)
     FADDRVAL_MASK = 0x0000007F
    ,FADDRVAL_POS = 0
    ,FADDR_MASK = 0x0000007F
    ;
  };
  // USB Device Endpoint Status Register
  struct EPSTS : reg<ip_ver, base + 0xC>
  {
    static constexpr typename EPSTS::type
    // Overrun It indicates that the received data is over the maximum payload number or not. (bits: 7)
     OV_MASK = 0x00000080
    ,OV_POS = 7
    ,OV_0 = 0x00000000 // No overrun
    ,OV_1 = 0x00000080 // Out Data is more than the Max Payload in MXPLD register or the Setup Data is more than 8 Bytes
    ,EPSTS_MASK = 0x00000080
    ;
  };
  // USB Device Bus Status and Attribution Register
  struct ATTR : reg<ip_ver, base + 0x10, 0x00000040>
  {
    static constexpr typename ATTR::type
    // USB Reset Status (Read Only) (bits: 0)
     USBRST_MASK = 0x00000001
    ,USBRST_POS = 0
    ,USBRST_0 = 0x00000000 // Bus no reset
    ,USBRST_1 = 0x00000001 // Bus reset when SE0 (single-ended 0) more than 2.5us
    // Suspend Status (Read Only) (bits: 1)
    ,SUSPEND_MASK = 0x00000002
    ,SUSPEND_POS = 1
    ,SUSPEND_0 = 0x00000000 // Bus no suspend
    ,SUSPEND_1 = 0x00000002 // Bus idle more than 3ms, either cable is plugged off or host is sleeping
    // Resume Status (Read Only) (bits: 2)
    ,RESUME_MASK = 0x00000004
    ,RESUME_POS = 2
    ,RESUME_0 = 0x00000000 // No bus resume
    ,RESUME_1 = 0x00000004 // Resume from suspend
    // Time-out Status (Read Only) (bits: 3)
    ,TOUT_MASK = 0x00000008
    ,TOUT_POS = 3
    ,TOUT_0 = 0x00000000 // No time-out
    ,TOUT_1 = 0x00000008 // No Bus response more than 18 bits time
    // PHY Transceiver Function Enable Bit (bits: 4)
    ,PHYEN_MASK = 0x00000010
    ,PHYEN_POS = 4
    ,PHYEN_0 = 0x00000000 // PHY transceiver function Disabled
    ,PHYEN_1 = 0x00000010 // PHY transceiver function Enabled
    // Remote Wake-up (bits: 5)
    ,RWAKEUP_MASK = 0x00000020
    ,RWAKEUP_POS = 5
    ,RWAKEUP_0 = 0x00000000 // Release the USB bus from K state
    ,RWAKEUP_1 = 0x00000020 // Force USB bus to K (USB_D+ low, USB_D-: high) state, used for remote wake-up
    // USB Controller Enable Bit (bits: 7)
    ,USBEN_MASK = 0x00000080
    ,USBEN_POS = 7
    ,USBEN_0 = 0x00000000 // USB Controller Disabled
    ,USBEN_1 = 0x00000080 // USB Controller Enabled
    // Pull-up Resistor on USB_DP Enable Bit (bits: 8)
    ,DPPUEN_MASK = 0x00000100
    ,DPPUEN_POS = 8
    ,DPPUEN_0 = 0x00000000 // Pull-up resistor in USB_D+ bus Disabled
    ,DPPUEN_1 = 0x00000100 // Pull-up resistor in USB_D+ bus Active
    // Power-down PHY Transceiver, Low Active (bits: 9)
    ,PWRDN_MASK = 0x00000200
    ,PWRDN_POS = 9
    ,PWRDN_0 = 0x00000000 // Power-down related circuit of PHY transceiver
    ,PWRDN_1 = 0x00000200 // Turn-on related circuit of PHY transceiver
    // CPU Access USB SRAM Size Mode Selection (bits: 10)
    ,BYTEM_MASK = 0x00000400
    ,BYTEM_POS = 10
    ,BYTEM_0 = 0x00000000 // Word mode: The size of the transfer from CPU to USB SRAM can be Word only
    ,BYTEM_1 = 0x00000400 // Byte mode: The size of the transfer from CPU to USB SRAM can be Byte only
    // LPM Token Acknowledge Enable Bit (bits: 11)
    ,LPMACK_MASK = 0x00000800
    ,LPMACK_POS = 11
    ,LPMACK_0 = 0x00000000 // the valid LPM Token will be NYET
    ,LPMACK_1 = 0x00000800 // the valid LPM Token will be ACK
    // LPM L1 Suspend (Read Only) (bits: 12)
    ,L1SUSPEND_MASK = 0x00001000
    ,L1SUSPEND_POS = 12
    ,L1SUSPEND_0 = 0x00000000 // Bus no L1 state suspend
    ,L1SUSPEND_1 = 0x00001000 // This bit is set by the hardware when LPM command to enter the L1 state is successfully received and acknowledged
    // LPM L1 Resume (Read Only) (bits: 13)
    ,L1RESUME_MASK = 0x00002000
    ,L1RESUME_POS = 13
    ,L1RESUME_0 = 0x00000000 // Bus no LPM L1 state resume
    ,L1RESUME_1 = 0x00002000 // LPM L1 state Resume from LPM L1 state suspend
    ,ATTR_MASK = 0x00003FBF
    ;
  };
  // USB Device VBUS Detection Register
  struct VBUSDET : reg<ip_ver, base + 0x14>
  {
    static constexpr typename VBUSDET::type
    // Device VBUS Detection (bits: 0)
     VBUSDETVAL_MASK = 0x00000001
    ,VBUSDETVAL_POS = 0
    ,VBUSDETVAL_0 = 0x00000000 // Controller is not attached to the USB host
    ,VBUSDETVAL_1 = 0x00000001 // Controller is attached to the USB host
    ,VBUSDET_MASK = 0x00000001
    ;
  };
  // SETUP Token Buffer Segmentation Register
  struct STBUFSEG : reg<ip_ver, base + 0x18>
  {
    static constexpr typename STBUFSEG::type
    // SETUP Token Buffer Segmentation It is used to indicate the offset address for the SETUP token with the USB Device SRAM starting address The effective starting address is USBD_SRAM address + {STBUFSEG, 3'b000} Note: It is used for SETUP token only. (bits: 8-3)
     STBUFSEGVAL_MASK = 0x000001F8
    ,STBUFSEGVAL_POS = 3
    ,STBUFSEG_MASK = 0x000001F8
    ;
  };
  // USB Device Endpoint Status Register 0
  struct EPSTS0 : reg<ip_ver, base + 0x20>
  {
    static constexpr typename EPSTS0::type
    // Endpoint 5 Status These bits are used to indicate the current status of this endpoint (bits: 23-20)
     EPSTS5_MASK = 0x00F00000
    ,EPSTS5_POS = 20
    ,EPSTS5_0 = 0x00000000 // In ACK
    ,EPSTS5_1 = 0x00100000 // In NAK
    ,EPSTS5_2 = 0x00200000 // Out Packet Data0 ACK
    ,EPSTS5_6 = 0x00600000 // Out Packet Data1 ACK
    ,EPSTS5_7 = 0x00700000 // Isochronous transfer end
    // Endpoint 6 Status These bits are used to indicate the current status of this endpoint (bits: 27-24)
    ,EPSTS6_MASK = 0x0F000000
    ,EPSTS6_POS = 24
    ,EPSTS6_0 = 0x00000000 // In ACK
    ,EPSTS6_1 = 0x01000000 // In NAK
    ,EPSTS6_2 = 0x02000000 // Out Packet Data0 ACK
    ,EPSTS6_6 = 0x06000000 // Out Packet Data1 ACK
    ,EPSTS6_7 = 0x07000000 // Isochronous transfer end
    // Endpoint 7 Status These bits are used to indicate the current status of this endpoint (bits: 31-28)
    ,EPSTS7_MASK = 0xF0000000
    ,EPSTS7_POS = 28
    ,EPSTS7_0 = 0x00000000 // In ACK
    ,EPSTS7_1 = 0x10000000 // In NAK
    ,EPSTS7_2 = 0x20000000 // Out Packet Data0 ACK
    ,EPSTS7_6 = 0x60000000 // Out Packet Data1 ACK
    ,EPSTS7_7 = 0x70000000 // Isochronous transfer end
    ,EPSTS0_MASK = 0xFFF00000
    ;
  };
  // USB Device Endpoint Status Register 1
  struct EPSTS1 : reg<ip_ver, base + 0x24>
  {
    static constexpr typename EPSTS1::type
    // Endpoint 8 Status These bits are used to indicate the current status of this endpoint (bits: 3-0)
     EPSTS8_MASK = 0x0000000F
    ,EPSTS8_POS = 0
    ,EPSTS8_0 = 0x00000000 // In ACK
    ,EPSTS8_1 = 0x00000001 // In NAK
    ,EPSTS8_2 = 0x00000002 // Out Packet Data0 ACK
    ,EPSTS8_6 = 0x00000006 // Out Packet Data1 ACK
    ,EPSTS8_7 = 0x00000007 // Isochronous transfer end
    // Endpoint 9 Status These bits are used to indicate the current status of this endpoint (bits: 7-4)
    ,EPSTS9_MASK = 0x000000F0
    ,EPSTS9_POS = 4
    ,EPSTS9_0 = 0x00000000 // In ACK
    ,EPSTS9_1 = 0x00000010 // In NAK
    ,EPSTS9_2 = 0x00000020 // Out Packet Data0 ACK
    ,EPSTS9_6 = 0x00000060 // Out Packet Data1 ACK
    ,EPSTS9_7 = 0x00000070 // Isochronous transfer end
    // Endpoint 10 Status These bits are used to indicate the current status of this endpoint (bits: 11-8)
    ,EPSTS10_MASK = 0x00000F00
    ,EPSTS10_POS = 8
    ,EPSTS10_0 = 0x00000000 // In ACK
    ,EPSTS10_1 = 0x00000100 // In NAK
    ,EPSTS10_2 = 0x00000200 // Out Packet Data0 ACK
    ,EPSTS10_6 = 0x00000600 // Out Packet Data1 ACK
    ,EPSTS10_7 = 0x00000700 // Isochronous transfer end
    // Endpoint 11 Status These bits are used to indicate the current status of this endpoint (bits: 15-12)
    ,EPSTS11_MASK = 0x0000F000
    ,EPSTS11_POS = 12
    ,EPSTS11_0 = 0x00000000 // In ACK
    ,EPSTS11_1 = 0x00001000 // In NAK
    ,EPSTS11_2 = 0x00002000 // Out Packet Data0 ACK
    ,EPSTS11_6 = 0x00006000 // Out Packet Data1 ACK
    ,EPSTS11_7 = 0x00007000 // Isochronous transfer end
    ,EPSTS1_MASK = 0x0000FFFF
    ;
  };
  // USB LPM Attribution Register
  struct LPMATTR : reg<ip_ver, base + 0x88>
  {
    static constexpr typename LPMATTR::type
    // LPM Link State These bits contain the bLinkState received with last ACK LPM Token (bits: 3-0)
     LPMLINKSTS_MASK = 0x0000000F
    ,LPMLINKSTS_POS = 0
    // LPM Best Effort Service Latency These bits contain the BESL value received with last ACK LPM Token (bits: 7-4)
    ,LPMBESL_MASK = 0x000000F0
    ,LPMBESL_POS = 4
    // LPM Remote Wakeup This bit contains the bRemoteWake value received with last ACK LPM Token (bits: 8)
    ,LPMRWAKUP_MASK = 0x00000100
    ,LPMRWAKUP_POS = 8
    ,LPMRWAKUP = 0x00000100
    ,LPMATTR_MASK = 0x000001FF
    ;
  };
  // USB Frame Number Register
  struct FN : reg<ip_ver, base + 0x8C>
  {
    static constexpr typename FN::type
    // Frame Number These bits contain the 11-bits frame number in the last received SOF packet. (bits: 10-0)
     FNVAL_MASK = 0x000007FF
    ,FNVAL_POS = 0
    ,FN_MASK = 0x000007FF
    ;
  };
  // USB Device Drive SE0 Control Register
  struct SE0 : reg<ip_ver, base + 0x90, 0x00000001>
  {
    static constexpr typename SE0::type
    // Drive Single Ended Zero in USB Bus The Single Ended Zero (SE0) is when both lines (USB_D+ and USB_D-) are being pulled low. (bits: 0)
     SE0VAL_MASK = 0x00000001
    ,SE0VAL_POS = 0
    ,SE0VAL_0 = 0x00000000 // Normal operation
    ,SE0VAL_1 = 0x00000001 // Force USB PHY transceiver to drive SE0
    ,SE0_MASK = 0x00000001
    ;
  };
  // Endpoint 0 Buffer Segmentation Register (count: 12)
  struct BUFSEG : reg<ip_ver, base + 0x500, 0x00000000, 12, 32, 16>
  {
    static constexpr typename BUFSEG::type
    // Endpoint Buffer Segmentation It is used to indicate the offset address for each endpoint with the USB SRAM starting address The effective starting address of the endpoint is USBD_SRAM address + { BUFSEG, 3'b000} Refer to the section 6.31.6.7 for the endpoint SRAM structure and its description. (bits: 8-3)
     BUFSEGVAL_MASK = 0x000001F8
    ,BUFSEGVAL_POS = 3
    ,BUFSEG_MASK = 0x000001F8
    ;
  };
  // Endpoint 0 Maximal Payload Register (count: 12)
  struct MXPLD : reg<ip_ver, base + 0x504, 0x00000000, 12, 32, 16>
  {
    static constexpr typename MXPLD::type
    // Maximal Payload Define the data length which is transmitted to host (IN token) or the actual data length which is received from the host (OUT token). It also used to indicate that the endpoint is ready to be transmitted in IN token or received in OUT token. (1) When the register is written by CPU, For IN token, the value of MXPLD is used to define the data length to be transmitted and indicate the data buffer is ready. For OUT token, it means that the controller is ready to receive data from the host and the value of MXPLD is the maximal data length comes from host. (2) When the register is read by CPU, For IN token, the value of MXPLD is indicated by the data length be transmitted to host For OUT token, the value of MXPLD is indicated the actual data length receiving from host. Note: Once MXPLD is written, the data packets will be transmitted/received immediately after IN/OUT token arrived. (bits: 8-0)
     MXPLDVAL_MASK = 0x000001FF
    ,MXPLDVAL_POS = 0
    ,MXPLD_MASK = 0x000001FF
    ;
  };
  // Endpoint 0 Configuration Register (count: 12)
  struct CFG : reg<ip_ver, base + 0x508, 0x00000000, 12, 32, 16>
  {
    static constexpr typename CFG::type
    // Endpoint Number These bits are used to define the endpoint number of the current endpoint (bits: 3-0)
     EPNUM_MASK = 0x0000000F
    ,EPNUM_POS = 0
    // Isochronous Endpoint This bit is used to set the endpoint as Isochronous endpoint, no handshake. (bits: 4)
    ,ISOCH_MASK = 0x00000010
    ,ISOCH_POS = 4
    ,ISOCH_0 = 0x00000000 // No Isochronous endpoint
    ,ISOCH_1 = 0x00000010 // Isochronous endpoint
    // Endpoint STATE (bits: 6-5)
    ,STATE_MASK = 0x00000060
    ,STATE_POS = 5
    ,STATE_0 = 0x00000000 // Endpoint is Disabled
    ,STATE_1 = 0x00000020 // Out endpoint
    ,STATE_2 = 0x00000040 // IN endpoint
    ,STATE_3 = 0x00000060 // Undefined
    // Data Sequence Synchronization Note: It is used to specify the DATA0 or DATA1 PID in the following IN token transaction. hardware will toggle automatically in IN token base on the bit. (bits: 7)
    ,DSQSYNC_MASK = 0x00000080
    ,DSQSYNC_POS = 7
    ,DSQSYNC_0 = 0x00000000 // DATA0 PID
    ,DSQSYNC_1 = 0x00000080 // DATA1 PID
    // Clear STALL Response (bits: 9)
    ,CSTALL_MASK = 0x00000200
    ,CSTALL_POS = 9
    ,CSTALL_0 = 0x00000000 // Disable the device to clear the STALL handshake in setup stage
    ,CSTALL_1 = 0x00000200 // Clear the device to response STALL handshake in setup stage
    ,CFG_MASK = 0x000002FF
    ;
  };
  // Endpoint 0 Set Stall and Clear In/Out Ready Control Register (count: 12)
  struct CFGP : reg<ip_ver, base + 0x50C, 0x00000000, 12, 32, 16>
  {
    static constexpr typename CFGP::type
    // Clear Ready When the USBD_MXPLDx register is set by user, it means that the endpoint is ready to transmit or receive data. If the user wants to disable this transaction before the transaction start, users can set this bit to 1 to disable it and it is auto clear to 0. For IN token, write '1' to clear the IN token had ready to transmit the data to USB. For OUT token, write '1' to clear the OUT token had ready to receive the data from USB. This bit is write 1 only and is always 0 when it is read back. (bits: 0)
     CLRRDY_MASK = 0x00000001
    ,CLRRDY_POS = 0
    ,CLRRDY = 0x00000001
    // Set STALL (bits: 1)
    ,SSTALL_MASK = 0x00000002
    ,SSTALL_POS = 1
    ,SSTALL_0 = 0x00000000 // Disable the device to response STALL
    ,SSTALL_1 = 0x00000002 // Set the device to respond STALL automatically
    ,CFGP_MASK = 0x00000003
    ;
  };
}; // struct USBD

} // namespace lmcu::device::ip::v1

