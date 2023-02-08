/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// PDMA Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct PDMA
{
  static constexpr auto ip_ver = ip_version::_1;

  // Descriptor Table Control Register of PDMA Channel (count: 16)
  struct DSCT_CTL : reg<ip_ver, base + 0x0, 0x00000000, 16, 32, 16>
  {
    static constexpr typename DSCT_CTL::type
    // PDMA Operation Mode Selection\nNote: Before filling new transfer task in the Descriptor Table, user must check the PDMA_INTSTS[1] to make sure the curren task is complete. (bits: 1-0)
     OPMODE_MASK = 0x00000003
    ,OPMODE_POS = 0
    ,OPMODE_0 = 0x00000000 // Idle state: Channel is stopped or this table is complete, when PDMA finish channel table task, OPMODE will be cleared to idle state automatically
    ,OPMODE_1 = 0x00000001 // Basic mode: The descriptor table only has one task. When this task is finished, the PDMA_INTSTS[1] will be asserted
    ,OPMODE_2 = 0x00000002 // Scatter-Gather mode: When operating in this mode, user must give the next descriptor table address in PDMA_DSCT_NEXT register; PDMA controller will ignore this task, then load the next task to execute
    ,OPMODE_3 = 0x00000003 // Reserved.
    // Transfer Type (bits: 2)
    ,TXTYPE_MASK = 0x00000004
    ,TXTYPE_POS = 2
    ,TXTYPE_0 = 0x00000000 // Burst transfer type
    ,TXTYPE_1 = 0x00000004 // Single transfer type
    // Burst Size (bits: 6-4)
    ,BURSIZE_MASK = 0x00000070
    ,BURSIZE_POS = 4
    // Table Interrupt Disable Bit (bits: 7)
    ,TBINTDIS_MASK = 0x00000080
    ,TBINTDIS_POS = 7
    ,TBINTDIS_0 = 0x00000000 // Table interrupt Enabled
    ,TBINTDIS_1 = 0x00000080 // Table interrupt Disabled
    // Source Address Increment (bits: 9-8)
    ,SAINC_MASK = 0x00000300
    ,SAINC_POS = 8
    ,SAINC_3 = 0x00000300 // No increment (fixed address)
    // Destination Address Increment (bits: 11-10)
    ,DAINC_MASK = 0x00000C00
    ,DAINC_POS = 10
    ,DAINC_3 = 0x00000C00 // No increment (fixed address)
    // Transfer Width Selection (bits: 13-12)
    ,TXWIDTH_MASK = 0x00003000
    ,TXWIDTH_POS = 12
    ,TXWIDTH_0 = 0x00000000 // One byte (8 bit) is transferred for every operation
    ,TXWIDTH_1 = 0x00001000 // One half-word (16 bit) is transferred for every operation.
    ,TXWIDTH_2 = 0x00002000 // One word (32-bit) is transferred for every operation.
    // Stride Mode Enable Bit (bits: 15)
    ,STRIDEEN_MASK = 0x00008000
    ,STRIDEEN_POS = 15
    ,STRIDEEN_0 = 0x00000000 // Stride transfer mode Disabled
    ,STRIDEEN_1 = 0x00008000 // Stride transfer mode Enabled.
    // Transfer Count (bits: 31-16)
    ,TXCNT_MASK = 0xFFFF0000
    ,TXCNT_POS = 16
    ,DSCT_CTL_MASK = 0xFFFFBFF7
    ;
  };
  // Source Address Register of PDMA Channel (count: 16)
  using DSCT_SA = reg<ip_ver, base + 0x4, 0x00000000, 16, 32, 16>;
  // Destination Address Register of PDMA Channel (count: 16)
  using DSCT_DA = reg<ip_ver, base + 0x8, 0x00000000, 16, 32, 16>;
  // Next Scatter-gather Descriptor Table Offset Address of PDMA Channel n (count: 16)
  using DSCT_NEXT = reg<ip_ver, base + 0xC, 0x00000000, 16, 32, 16>;
  // Current Scatter-gather Descriptor Table Address of PDMA Channel n (count: 16)
  struct CURSCAT : reg<ip_ver, base + 0x100, 0x00000000, 16>
  {
    static constexpr typename CURSCAT::type
    // PDMA Current Description Address (Read Only) This field indicates a 32-bit current external description address of PDMA controller. Note: This field is read only and used for Scatter-Gather mode only to indicate the current external description address. (bits: 31-0)
     CURADDR_MASK = 0xFFFFFFFF
    ,CURADDR_POS = 0
    ,CURSCAT_MASK = 0xFFFFFFFF
    ;
  };
  // PDMA Channel Control Register
  struct CHCTL : reg<ip_ver, base + 0x400>
  {
    static constexpr typename CHCTL::type
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 0)
     CHEN0_MASK = 0x00000001
    ,CHEN0_POS = 0
    ,CHEN0_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN0_1 = 0x00000001 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 1)
    ,CHEN1_MASK = 0x00000002
    ,CHEN1_POS = 1
    ,CHEN1_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN1_1 = 0x00000002 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 2)
    ,CHEN2_MASK = 0x00000004
    ,CHEN2_POS = 2
    ,CHEN2_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN2_1 = 0x00000004 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 3)
    ,CHEN3_MASK = 0x00000008
    ,CHEN3_POS = 3
    ,CHEN3_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN3_1 = 0x00000008 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 4)
    ,CHEN4_MASK = 0x00000010
    ,CHEN4_POS = 4
    ,CHEN4_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN4_1 = 0x00000010 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 5)
    ,CHEN5_MASK = 0x00000020
    ,CHEN5_POS = 5
    ,CHEN5_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN5_1 = 0x00000020 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 6)
    ,CHEN6_MASK = 0x00000040
    ,CHEN6_POS = 6
    ,CHEN6_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN6_1 = 0x00000040 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 7)
    ,CHEN7_MASK = 0x00000080
    ,CHEN7_POS = 7
    ,CHEN7_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN7_1 = 0x00000080 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 8)
    ,CHEN8_MASK = 0x00000100
    ,CHEN8_POS = 8
    ,CHEN8_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN8_1 = 0x00000100 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 9)
    ,CHEN9_MASK = 0x00000200
    ,CHEN9_POS = 9
    ,CHEN9_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN9_1 = 0x00000200 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 10)
    ,CHEN10_MASK = 0x00000400
    ,CHEN10_POS = 10
    ,CHEN10_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN10_1 = 0x00000400 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 11)
    ,CHEN11_MASK = 0x00000800
    ,CHEN11_POS = 11
    ,CHEN11_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN11_1 = 0x00000800 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 12)
    ,CHEN12_MASK = 0x00001000
    ,CHEN12_POS = 12
    ,CHEN12_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN12_1 = 0x00001000 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 13)
    ,CHEN13_MASK = 0x00002000
    ,CHEN13_POS = 13
    ,CHEN13_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN13_1 = 0x00002000 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 14)
    ,CHEN14_MASK = 0x00004000
    ,CHEN14_POS = 14
    ,CHEN14_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN14_1 = 0x00004000 // PDMA channel [n] Enabled
    // PDMA Channel Enable Bits Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled. Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit. (bits: 15)
    ,CHEN15_MASK = 0x00008000
    ,CHEN15_POS = 15
    ,CHEN15_0 = 0x00000000 // PDMA channel [n] Disabled
    ,CHEN15_1 = 0x00008000 // PDMA channel [n] Enabled
    ,CHCTL_MASK = 0x0000FFFF
    ;
  };
  // PDMA Transfer Pause Control Register
  struct PAUSE : reg<ip_ver, base + 0x404>
  {
    static constexpr typename PAUSE::type
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 0)
     PAUSE0_MASK = 0x00000001
    ,PAUSE0_POS = 0
    ,PAUSE0_0 = 0x00000000 // No effect
    ,PAUSE0_1 = 0x00000001 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 1)
    ,PAUSE1_MASK = 0x00000002
    ,PAUSE1_POS = 1
    ,PAUSE1_0 = 0x00000000 // No effect
    ,PAUSE1_1 = 0x00000002 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 2)
    ,PAUSE2_MASK = 0x00000004
    ,PAUSE2_POS = 2
    ,PAUSE2_0 = 0x00000000 // No effect
    ,PAUSE2_1 = 0x00000004 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 3)
    ,PAUSE3_MASK = 0x00000008
    ,PAUSE3_POS = 3
    ,PAUSE3_0 = 0x00000000 // No effect
    ,PAUSE3_1 = 0x00000008 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 4)
    ,PAUSE4_MASK = 0x00000010
    ,PAUSE4_POS = 4
    ,PAUSE4_0 = 0x00000000 // No effect
    ,PAUSE4_1 = 0x00000010 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 5)
    ,PAUSE5_MASK = 0x00000020
    ,PAUSE5_POS = 5
    ,PAUSE5_0 = 0x00000000 // No effect
    ,PAUSE5_1 = 0x00000020 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 6)
    ,PAUSE6_MASK = 0x00000040
    ,PAUSE6_POS = 6
    ,PAUSE6_0 = 0x00000000 // No effect
    ,PAUSE6_1 = 0x00000040 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 7)
    ,PAUSE7_MASK = 0x00000080
    ,PAUSE7_POS = 7
    ,PAUSE7_0 = 0x00000000 // No effect
    ,PAUSE7_1 = 0x00000080 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 8)
    ,PAUSE8_MASK = 0x00000100
    ,PAUSE8_POS = 8
    ,PAUSE8_0 = 0x00000000 // No effect
    ,PAUSE8_1 = 0x00000100 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 9)
    ,PAUSE9_MASK = 0x00000200
    ,PAUSE9_POS = 9
    ,PAUSE9_0 = 0x00000000 // No effect
    ,PAUSE9_1 = 0x00000200 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 10)
    ,PAUSE10_MASK = 0x00000400
    ,PAUSE10_POS = 10
    ,PAUSE10_0 = 0x00000000 // No effect
    ,PAUSE10_1 = 0x00000400 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 11)
    ,PAUSE11_MASK = 0x00000800
    ,PAUSE11_POS = 11
    ,PAUSE11_0 = 0x00000000 // No effect
    ,PAUSE11_1 = 0x00000800 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 12)
    ,PAUSE12_MASK = 0x00001000
    ,PAUSE12_POS = 12
    ,PAUSE12_0 = 0x00000000 // No effect
    ,PAUSE12_1 = 0x00001000 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 13)
    ,PAUSE13_MASK = 0x00002000
    ,PAUSE13_POS = 13
    ,PAUSE13_0 = 0x00000000 // No effect
    ,PAUSE13_1 = 0x00002000 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 14)
    ,PAUSE14_MASK = 0x00004000
    ,PAUSE14_POS = 14
    ,PAUSE14_0 = 0x00000000 // No effect
    ,PAUSE14_1 = 0x00004000 // Pause PDMA channel n transfer
    // PDMA Channel n Transfer Pause Control (Write Only) (bits: 15)
    ,PAUSE15_MASK = 0x00008000
    ,PAUSE15_POS = 15
    ,PAUSE15_0 = 0x00000000 // No effect
    ,PAUSE15_1 = 0x00008000 // Pause PDMA channel n transfer
    ,PAUSE_MASK = 0x0000FFFF
    ;
  };
  // PDMA Software Request Register
  struct SWREQ : reg<ip_ver, base + 0x408>
  {
    static constexpr typename SWREQ::type
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 0)
     SWREQ0_MASK = 0x00000001
    ,SWREQ0_POS = 0
    ,SWREQ0_0 = 0x00000000 // No effect
    ,SWREQ0_1 = 0x00000001 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 1)
    ,SWREQ1_MASK = 0x00000002
    ,SWREQ1_POS = 1
    ,SWREQ1_0 = 0x00000000 // No effect
    ,SWREQ1_1 = 0x00000002 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 2)
    ,SWREQ2_MASK = 0x00000004
    ,SWREQ2_POS = 2
    ,SWREQ2_0 = 0x00000000 // No effect
    ,SWREQ2_1 = 0x00000004 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 3)
    ,SWREQ3_MASK = 0x00000008
    ,SWREQ3_POS = 3
    ,SWREQ3_0 = 0x00000000 // No effect
    ,SWREQ3_1 = 0x00000008 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 4)
    ,SWREQ4_MASK = 0x00000010
    ,SWREQ4_POS = 4
    ,SWREQ4_0 = 0x00000000 // No effect
    ,SWREQ4_1 = 0x00000010 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 5)
    ,SWREQ5_MASK = 0x00000020
    ,SWREQ5_POS = 5
    ,SWREQ5_0 = 0x00000000 // No effect
    ,SWREQ5_1 = 0x00000020 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 6)
    ,SWREQ6_MASK = 0x00000040
    ,SWREQ6_POS = 6
    ,SWREQ6_0 = 0x00000000 // No effect
    ,SWREQ6_1 = 0x00000040 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 7)
    ,SWREQ7_MASK = 0x00000080
    ,SWREQ7_POS = 7
    ,SWREQ7_0 = 0x00000000 // No effect
    ,SWREQ7_1 = 0x00000080 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 8)
    ,SWREQ8_MASK = 0x00000100
    ,SWREQ8_POS = 8
    ,SWREQ8_0 = 0x00000000 // No effect
    ,SWREQ8_1 = 0x00000100 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 9)
    ,SWREQ9_MASK = 0x00000200
    ,SWREQ9_POS = 9
    ,SWREQ9_0 = 0x00000000 // No effect
    ,SWREQ9_1 = 0x00000200 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 10)
    ,SWREQ10_MASK = 0x00000400
    ,SWREQ10_POS = 10
    ,SWREQ10_0 = 0x00000000 // No effect
    ,SWREQ10_1 = 0x00000400 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 11)
    ,SWREQ11_MASK = 0x00000800
    ,SWREQ11_POS = 11
    ,SWREQ11_0 = 0x00000000 // No effect
    ,SWREQ11_1 = 0x00000800 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 12)
    ,SWREQ12_MASK = 0x00001000
    ,SWREQ12_POS = 12
    ,SWREQ12_0 = 0x00000000 // No effect
    ,SWREQ12_1 = 0x00001000 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 13)
    ,SWREQ13_MASK = 0x00002000
    ,SWREQ13_POS = 13
    ,SWREQ13_0 = 0x00000000 // No effect
    ,SWREQ13_1 = 0x00002000 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 14)
    ,SWREQ14_MASK = 0x00004000
    ,SWREQ14_POS = 14
    ,SWREQ14_0 = 0x00000000 // No effect
    ,SWREQ14_1 = 0x00004000 // Generate a software request
    // PDMA Software Request (Write Only) Set this bit to 1 to generate a software request to PDMA [n]. Note 1: User can read PDMA_TRGSTS register to know which channel is on active. Active flag may be triggered by software request or peripheral request. Note 2: If user does not enable corresponding PDMA channel, the software request will be ignored. (bits: 15)
    ,SWREQ15_MASK = 0x00008000
    ,SWREQ15_POS = 15
    ,SWREQ15_0 = 0x00000000 // No effect
    ,SWREQ15_1 = 0x00008000 // Generate a software request
    ,SWREQ_MASK = 0x0000FFFF
    ;
  };
  // PDMA Channel Request Status Register
  struct TRGSTS : reg<ip_ver, base + 0x40C>
  {
    static constexpr typename TRGSTS::type
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 0)
     REQSTS0_MASK = 0x00000001
    ,REQSTS0_POS = 0
    ,REQSTS0_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS0_1 = 0x00000001 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 1)
    ,REQSTS1_MASK = 0x00000002
    ,REQSTS1_POS = 1
    ,REQSTS1_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS1_1 = 0x00000002 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 2)
    ,REQSTS2_MASK = 0x00000004
    ,REQSTS2_POS = 2
    ,REQSTS2_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS2_1 = 0x00000004 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 3)
    ,REQSTS3_MASK = 0x00000008
    ,REQSTS3_POS = 3
    ,REQSTS3_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS3_1 = 0x00000008 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 4)
    ,REQSTS4_MASK = 0x00000010
    ,REQSTS4_POS = 4
    ,REQSTS4_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS4_1 = 0x00000010 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 5)
    ,REQSTS5_MASK = 0x00000020
    ,REQSTS5_POS = 5
    ,REQSTS5_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS5_1 = 0x00000020 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 6)
    ,REQSTS6_MASK = 0x00000040
    ,REQSTS6_POS = 6
    ,REQSTS6_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS6_1 = 0x00000040 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 7)
    ,REQSTS7_MASK = 0x00000080
    ,REQSTS7_POS = 7
    ,REQSTS7_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS7_1 = 0x00000080 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 8)
    ,REQSTS8_MASK = 0x00000100
    ,REQSTS8_POS = 8
    ,REQSTS8_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS8_1 = 0x00000100 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 9)
    ,REQSTS9_MASK = 0x00000200
    ,REQSTS9_POS = 9
    ,REQSTS9_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS9_1 = 0x00000200 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 10)
    ,REQSTS10_MASK = 0x00000400
    ,REQSTS10_POS = 10
    ,REQSTS10_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS10_1 = 0x00000400 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 11)
    ,REQSTS11_MASK = 0x00000800
    ,REQSTS11_POS = 11
    ,REQSTS11_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS11_1 = 0x00000800 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 12)
    ,REQSTS12_MASK = 0x00001000
    ,REQSTS12_POS = 12
    ,REQSTS12_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS12_1 = 0x00001000 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 13)
    ,REQSTS13_MASK = 0x00002000
    ,REQSTS13_POS = 13
    ,REQSTS13_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS13_1 = 0x00002000 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 14)
    ,REQSTS14_MASK = 0x00004000
    ,REQSTS14_POS = 14
    ,REQSTS14_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS14_1 = 0x00004000 // PDMA Channel n has a request
    // PDMA Channel Request Status (Read Only) This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral. When PDMA controller finishes channel transfer, this bit will be cleared automatically. Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer. (bits: 15)
    ,REQSTS15_MASK = 0x00008000
    ,REQSTS15_POS = 15
    ,REQSTS15_0 = 0x00000000 // PDMA Channel n has no request
    ,REQSTS15_1 = 0x00008000 // PDMA Channel n has a request
    ,TRGSTS_MASK = 0x0000FFFF
    ;
  };
  // PDMA Fixed Priority Setting Register
  struct PRISET : reg<ip_ver, base + 0x410>
  {
    static constexpr typename PRISET::type
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 0)
     FPRISET0_MASK = 0x00000001
    ,FPRISET0_POS = 0
    ,FPRISET0_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET0_1 = 0x00000001 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 1)
    ,FPRISET1_MASK = 0x00000002
    ,FPRISET1_POS = 1
    ,FPRISET1_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET1_1 = 0x00000002 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 2)
    ,FPRISET2_MASK = 0x00000004
    ,FPRISET2_POS = 2
    ,FPRISET2_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET2_1 = 0x00000004 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 3)
    ,FPRISET3_MASK = 0x00000008
    ,FPRISET3_POS = 3
    ,FPRISET3_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET3_1 = 0x00000008 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 4)
    ,FPRISET4_MASK = 0x00000010
    ,FPRISET4_POS = 4
    ,FPRISET4_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET4_1 = 0x00000010 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 5)
    ,FPRISET5_MASK = 0x00000020
    ,FPRISET5_POS = 5
    ,FPRISET5_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET5_1 = 0x00000020 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 6)
    ,FPRISET6_MASK = 0x00000040
    ,FPRISET6_POS = 6
    ,FPRISET6_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET6_1 = 0x00000040 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 7)
    ,FPRISET7_MASK = 0x00000080
    ,FPRISET7_POS = 7
    ,FPRISET7_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET7_1 = 0x00000080 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 8)
    ,FPRISET8_MASK = 0x00000100
    ,FPRISET8_POS = 8
    ,FPRISET8_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET8_1 = 0x00000100 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 9)
    ,FPRISET9_MASK = 0x00000200
    ,FPRISET9_POS = 9
    ,FPRISET9_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET9_1 = 0x00000200 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 10)
    ,FPRISET10_MASK = 0x00000400
    ,FPRISET10_POS = 10
    ,FPRISET10_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET10_1 = 0x00000400 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 11)
    ,FPRISET11_MASK = 0x00000800
    ,FPRISET11_POS = 11
    ,FPRISET11_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET11_1 = 0x00000800 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 12)
    ,FPRISET12_MASK = 0x00001000
    ,FPRISET12_POS = 12
    ,FPRISET12_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET12_1 = 0x00001000 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 13)
    ,FPRISET13_MASK = 0x00002000
    ,FPRISET13_POS = 13
    ,FPRISET13_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET13_1 = 0x00002000 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 14)
    ,FPRISET14_MASK = 0x00004000
    ,FPRISET14_POS = 14
    ,FPRISET14_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET14_1 = 0x00004000 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    // PDMA Fixed Priority Setting Set this bit to 1 to enable fixed priority level. Write Operation: Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register. (bits: 15)
    ,FPRISET15_MASK = 0x00008000
    ,FPRISET15_POS = 15
    ,FPRISET15_0 = 0x00000000 // No effect. Corresponding PDMA channel is round-robin priority
    ,FPRISET15_1 = 0x00008000 // Set PDMA channel [n] to fixed priority channel. Corresponding PDMA channel is fixed priority
    ,PRISET_MASK = 0x0000FFFF
    ;
  };
  // PDMA Fixed Priority Clear Register
  struct PRICLR : reg<ip_ver, base + 0x414>
  {
    static constexpr typename PRICLR::type
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 0)
     FPRICLR0_MASK = 0x00000001
    ,FPRICLR0_POS = 0
    ,FPRICLR0_0 = 0x00000000 // No effect
    ,FPRICLR0_1 = 0x00000001 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 1)
    ,FPRICLR1_MASK = 0x00000002
    ,FPRICLR1_POS = 1
    ,FPRICLR1_0 = 0x00000000 // No effect
    ,FPRICLR1_1 = 0x00000002 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 2)
    ,FPRICLR2_MASK = 0x00000004
    ,FPRICLR2_POS = 2
    ,FPRICLR2_0 = 0x00000000 // No effect
    ,FPRICLR2_1 = 0x00000004 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 3)
    ,FPRICLR3_MASK = 0x00000008
    ,FPRICLR3_POS = 3
    ,FPRICLR3_0 = 0x00000000 // No effect
    ,FPRICLR3_1 = 0x00000008 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 4)
    ,FPRICLR4_MASK = 0x00000010
    ,FPRICLR4_POS = 4
    ,FPRICLR4_0 = 0x00000000 // No effect
    ,FPRICLR4_1 = 0x00000010 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 5)
    ,FPRICLR5_MASK = 0x00000020
    ,FPRICLR5_POS = 5
    ,FPRICLR5_0 = 0x00000000 // No effect
    ,FPRICLR5_1 = 0x00000020 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 6)
    ,FPRICLR6_MASK = 0x00000040
    ,FPRICLR6_POS = 6
    ,FPRICLR6_0 = 0x00000000 // No effect
    ,FPRICLR6_1 = 0x00000040 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 7)
    ,FPRICLR7_MASK = 0x00000080
    ,FPRICLR7_POS = 7
    ,FPRICLR7_0 = 0x00000000 // No effect
    ,FPRICLR7_1 = 0x00000080 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 8)
    ,FPRICLR8_MASK = 0x00000100
    ,FPRICLR8_POS = 8
    ,FPRICLR8_0 = 0x00000000 // No effect
    ,FPRICLR8_1 = 0x00000100 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 9)
    ,FPRICLR9_MASK = 0x00000200
    ,FPRICLR9_POS = 9
    ,FPRICLR9_0 = 0x00000000 // No effect
    ,FPRICLR9_1 = 0x00000200 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 10)
    ,FPRICLR10_MASK = 0x00000400
    ,FPRICLR10_POS = 10
    ,FPRICLR10_0 = 0x00000000 // No effect
    ,FPRICLR10_1 = 0x00000400 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 11)
    ,FPRICLR11_MASK = 0x00000800
    ,FPRICLR11_POS = 11
    ,FPRICLR11_0 = 0x00000000 // No effect
    ,FPRICLR11_1 = 0x00000800 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 12)
    ,FPRICLR12_MASK = 0x00001000
    ,FPRICLR12_POS = 12
    ,FPRICLR12_0 = 0x00000000 // No effect
    ,FPRICLR12_1 = 0x00001000 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 13)
    ,FPRICLR13_MASK = 0x00002000
    ,FPRICLR13_POS = 13
    ,FPRICLR13_0 = 0x00000000 // No effect
    ,FPRICLR13_1 = 0x00002000 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 14)
    ,FPRICLR14_MASK = 0x00004000
    ,FPRICLR14_POS = 14
    ,FPRICLR14_0 = 0x00000000 // No effect
    ,FPRICLR14_1 = 0x00004000 // Clear PDMA channel [n] fixed priority setting
    // PDMA Fixed Priority Clear Bits (Write Only) Set this bit to 1 to clear fixed priority level. Note: User can read PDMA_PRISET register to know the channel priority. (bits: 15)
    ,FPRICLR15_MASK = 0x00008000
    ,FPRICLR15_POS = 15
    ,FPRICLR15_0 = 0x00000000 // No effect
    ,FPRICLR15_1 = 0x00008000 // Clear PDMA channel [n] fixed priority setting
    ,PRICLR_MASK = 0x0000FFFF
    ;
  };
  // PDMA Interrupt Enable Register
  struct INTEN : reg<ip_ver, base + 0x418>
  {
    static constexpr typename INTEN::type
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 0)
     INTEN0_MASK = 0x00000001
    ,INTEN0_POS = 0
    ,INTEN0_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN0_1 = 0x00000001 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 1)
    ,INTEN1_MASK = 0x00000002
    ,INTEN1_POS = 1
    ,INTEN1_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN1_1 = 0x00000002 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 2)
    ,INTEN2_MASK = 0x00000004
    ,INTEN2_POS = 2
    ,INTEN2_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN2_1 = 0x00000004 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 3)
    ,INTEN3_MASK = 0x00000008
    ,INTEN3_POS = 3
    ,INTEN3_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN3_1 = 0x00000008 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 4)
    ,INTEN4_MASK = 0x00000010
    ,INTEN4_POS = 4
    ,INTEN4_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN4_1 = 0x00000010 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 5)
    ,INTEN5_MASK = 0x00000020
    ,INTEN5_POS = 5
    ,INTEN5_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN5_1 = 0x00000020 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 6)
    ,INTEN6_MASK = 0x00000040
    ,INTEN6_POS = 6
    ,INTEN6_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN6_1 = 0x00000040 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 7)
    ,INTEN7_MASK = 0x00000080
    ,INTEN7_POS = 7
    ,INTEN7_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN7_1 = 0x00000080 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 8)
    ,INTEN8_MASK = 0x00000100
    ,INTEN8_POS = 8
    ,INTEN8_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN8_1 = 0x00000100 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 9)
    ,INTEN9_MASK = 0x00000200
    ,INTEN9_POS = 9
    ,INTEN9_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN9_1 = 0x00000200 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 10)
    ,INTEN10_MASK = 0x00000400
    ,INTEN10_POS = 10
    ,INTEN10_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN10_1 = 0x00000400 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 11)
    ,INTEN11_MASK = 0x00000800
    ,INTEN11_POS = 11
    ,INTEN11_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN11_1 = 0x00000800 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 12)
    ,INTEN12_MASK = 0x00001000
    ,INTEN12_POS = 12
    ,INTEN12_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN12_1 = 0x00001000 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 13)
    ,INTEN13_MASK = 0x00002000
    ,INTEN13_POS = 13
    ,INTEN13_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN13_1 = 0x00002000 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 14)
    ,INTEN14_MASK = 0x00004000
    ,INTEN14_POS = 14
    ,INTEN14_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN14_1 = 0x00004000 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    // PDMA Interrupt Enable Bits This field is used to enable PDMA channel[n] interrupt. (bits: 15)
    ,INTEN15_MASK = 0x00008000
    ,INTEN15_POS = 15
    ,INTEN15_0 = 0x00000000 // PDMA channel n interrupt Disabled
    ,INTEN15_1 = 0x00008000 // PDMA channel n interrupt Enabled.Note: The interrupt flag is time-out, abort, transfer done and align
    ,INTEN_MASK = 0x0000FFFF
    ;
  };
  // PDMA Interrupt Status Register
  struct INTSTS : reg<ip_ver, base + 0x41C>
  {
    static constexpr typename INTSTS::type
    // PDMA Read/Write Target Abort Interrupt Flag (Read Only) This bit indicates that PDMA has target abort error; Software can read PDMA_ABTSTS register to find which channel has target abort error. (bits: 0)
     ABTIF_MASK = 0x00000001
    ,ABTIF_POS = 0
    ,ABTIF_0 = 0x00000000 // No AHB bus ERROR response received
    ,ABTIF_1 = 0x00000001 // AHB bus ERROR response received
    // Transfer Done Interrupt Flag (Read Only) This bit indicates that PDMA controller has finished transmission; User can read PDMA_TDSTS register to indicate which channel finished transfer. (bits: 1)
    ,TDIF_MASK = 0x00000002
    ,TDIF_POS = 1
    ,TDIF_0 = 0x00000000 // Not finished yet
    ,TDIF_1 = 0x00000002 // PDMA channel has finished transmission
    // Transfer Alignment Interrupt Flag (Read Only) (bits: 2)
    ,ALIGNF_MASK = 0x00000004
    ,ALIGNF_POS = 2
    ,ALIGNF_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGNF_1 = 0x00000004 // PDMA channel source address or destination address is not follow transfer width setting
    // Request Time-out Flag for Channel 0 This flag indicates that PDMA controller has waited peripheral request for a period defined by PDMA_TOC0, user can write 1 to clear these bits. Note: Please disable time-out function before clear this bit. (bits: 8)
    ,REQTOF0_MASK = 0x00000100
    ,REQTOF0_POS = 8
    ,REQTOF0_0 = 0x00000000 // No request time-out
    ,REQTOF0_1 = 0x00000100 // Peripheral request time-out
    // Request Time-out Flag for Channel 1 This flag indicates that PDMA controller has waited peripheral request for a period defined by PDMA_TOC1, user can write 1 to clear these bits. Note: Please disable time-out function before clear this bit. (bits: 9)
    ,REQTOF1_MASK = 0x00000200
    ,REQTOF1_POS = 9
    ,REQTOF1_0 = 0x00000000 // No request time-out
    ,REQTOF1_1 = 0x00000200 // Peripheral request time-out
    ,INTSTS_MASK = 0x00000307
    ;
  };
  // PDMA Channel Read/Write Target Abort Flag Register
  struct ABTSTS : reg<ip_ver, base + 0x420>
  {
    static constexpr typename ABTSTS::type
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 0)
     ABTIF0_MASK = 0x00000001
    ,ABTIF0_POS = 0
    ,ABTIF0_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF0_1 = 0x00000001 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 1)
    ,ABTIF1_MASK = 0x00000002
    ,ABTIF1_POS = 1
    ,ABTIF1_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF1_1 = 0x00000002 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 2)
    ,ABTIF2_MASK = 0x00000004
    ,ABTIF2_POS = 2
    ,ABTIF2_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF2_1 = 0x00000004 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 3)
    ,ABTIF3_MASK = 0x00000008
    ,ABTIF3_POS = 3
    ,ABTIF3_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF3_1 = 0x00000008 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 4)
    ,ABTIF4_MASK = 0x00000010
    ,ABTIF4_POS = 4
    ,ABTIF4_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF4_1 = 0x00000010 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 5)
    ,ABTIF5_MASK = 0x00000020
    ,ABTIF5_POS = 5
    ,ABTIF5_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF5_1 = 0x00000020 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 6)
    ,ABTIF6_MASK = 0x00000040
    ,ABTIF6_POS = 6
    ,ABTIF6_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF6_1 = 0x00000040 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 7)
    ,ABTIF7_MASK = 0x00000080
    ,ABTIF7_POS = 7
    ,ABTIF7_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF7_1 = 0x00000080 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 8)
    ,ABTIF8_MASK = 0x00000100
    ,ABTIF8_POS = 8
    ,ABTIF8_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF8_1 = 0x00000100 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 9)
    ,ABTIF9_MASK = 0x00000200
    ,ABTIF9_POS = 9
    ,ABTIF9_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF9_1 = 0x00000200 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 10)
    ,ABTIF10_MASK = 0x00000400
    ,ABTIF10_POS = 10
    ,ABTIF10_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF10_1 = 0x00000400 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 11)
    ,ABTIF11_MASK = 0x00000800
    ,ABTIF11_POS = 11
    ,ABTIF11_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF11_1 = 0x00000800 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 12)
    ,ABTIF12_MASK = 0x00001000
    ,ABTIF12_POS = 12
    ,ABTIF12_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF12_1 = 0x00001000 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 13)
    ,ABTIF13_MASK = 0x00002000
    ,ABTIF13_POS = 13
    ,ABTIF13_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF13_1 = 0x00002000 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 14)
    ,ABTIF14_MASK = 0x00004000
    ,ABTIF14_POS = 14
    ,ABTIF14_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF14_1 = 0x00004000 // AHB bus ERROR response received when channel n transfer
    // PDMA Read/Write Target Abort Interrupt Status Flag This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits. Note: If channel n target abort, REQSRCn should set0 to disable peripheral request. (bits: 15)
    ,ABTIF15_MASK = 0x00008000
    ,ABTIF15_POS = 15
    ,ABTIF15_0 = 0x00000000 // No AHB bus ERROR response received when channel n transfer
    ,ABTIF15_1 = 0x00008000 // AHB bus ERROR response received when channel n transfer
    ,ABTSTS_MASK = 0x0000FFFF
    ;
  };
  // PDMA Channel Transfer Done Flag Register
  struct TDSTS : reg<ip_ver, base + 0x424>
  {
    static constexpr typename TDSTS::type
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 0)
     TDIF0_MASK = 0x00000001
    ,TDIF0_POS = 0
    ,TDIF0_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF0_1 = 0x00000001 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 1)
    ,TDIF1_MASK = 0x00000002
    ,TDIF1_POS = 1
    ,TDIF1_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF1_1 = 0x00000002 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 2)
    ,TDIF2_MASK = 0x00000004
    ,TDIF2_POS = 2
    ,TDIF2_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF2_1 = 0x00000004 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 3)
    ,TDIF3_MASK = 0x00000008
    ,TDIF3_POS = 3
    ,TDIF3_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF3_1 = 0x00000008 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 4)
    ,TDIF4_MASK = 0x00000010
    ,TDIF4_POS = 4
    ,TDIF4_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF4_1 = 0x00000010 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 5)
    ,TDIF5_MASK = 0x00000020
    ,TDIF5_POS = 5
    ,TDIF5_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF5_1 = 0x00000020 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 6)
    ,TDIF6_MASK = 0x00000040
    ,TDIF6_POS = 6
    ,TDIF6_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF6_1 = 0x00000040 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 7)
    ,TDIF7_MASK = 0x00000080
    ,TDIF7_POS = 7
    ,TDIF7_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF7_1 = 0x00000080 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 8)
    ,TDIF8_MASK = 0x00000100
    ,TDIF8_POS = 8
    ,TDIF8_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF8_1 = 0x00000100 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 9)
    ,TDIF9_MASK = 0x00000200
    ,TDIF9_POS = 9
    ,TDIF9_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF9_1 = 0x00000200 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 10)
    ,TDIF10_MASK = 0x00000400
    ,TDIF10_POS = 10
    ,TDIF10_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF10_1 = 0x00000400 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 11)
    ,TDIF11_MASK = 0x00000800
    ,TDIF11_POS = 11
    ,TDIF11_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF11_1 = 0x00000800 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 12)
    ,TDIF12_MASK = 0x00001000
    ,TDIF12_POS = 12
    ,TDIF12_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF12_1 = 0x00001000 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 13)
    ,TDIF13_MASK = 0x00002000
    ,TDIF13_POS = 13
    ,TDIF13_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF13_1 = 0x00002000 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 14)
    ,TDIF14_MASK = 0x00004000
    ,TDIF14_POS = 14
    ,TDIF14_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF14_1 = 0x00004000 // PDMA channel has finished transmission
    // Transfer Done Flag This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits. (bits: 15)
    ,TDIF15_MASK = 0x00008000
    ,TDIF15_POS = 15
    ,TDIF15_0 = 0x00000000 // PDMA channel transfer has not finished
    ,TDIF15_1 = 0x00008000 // PDMA channel has finished transmission
    ,TDSTS_MASK = 0x0000FFFF
    ;
  };
  // PDMA Transfer Alignment Status Register
  struct ALIGN : reg<ip_ver, base + 0x428>
  {
    static constexpr typename ALIGN::type
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 0)
     ALIGN0_MASK = 0x00000001
    ,ALIGN0_POS = 0
    ,ALIGN0_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN0_1 = 0x00000001 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 1)
    ,ALIGN1_MASK = 0x00000002
    ,ALIGN1_POS = 1
    ,ALIGN1_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN1_1 = 0x00000002 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 2)
    ,ALIGN2_MASK = 0x00000004
    ,ALIGN2_POS = 2
    ,ALIGN2_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN2_1 = 0x00000004 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 3)
    ,ALIGN3_MASK = 0x00000008
    ,ALIGN3_POS = 3
    ,ALIGN3_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN3_1 = 0x00000008 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 4)
    ,ALIGN4_MASK = 0x00000010
    ,ALIGN4_POS = 4
    ,ALIGN4_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN4_1 = 0x00000010 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 5)
    ,ALIGN5_MASK = 0x00000020
    ,ALIGN5_POS = 5
    ,ALIGN5_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN5_1 = 0x00000020 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 6)
    ,ALIGN6_MASK = 0x00000040
    ,ALIGN6_POS = 6
    ,ALIGN6_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN6_1 = 0x00000040 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 7)
    ,ALIGN7_MASK = 0x00000080
    ,ALIGN7_POS = 7
    ,ALIGN7_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN7_1 = 0x00000080 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 8)
    ,ALIGN8_MASK = 0x00000100
    ,ALIGN8_POS = 8
    ,ALIGN8_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN8_1 = 0x00000100 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 9)
    ,ALIGN9_MASK = 0x00000200
    ,ALIGN9_POS = 9
    ,ALIGN9_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN9_1 = 0x00000200 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 10)
    ,ALIGN10_MASK = 0x00000400
    ,ALIGN10_POS = 10
    ,ALIGN10_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN10_1 = 0x00000400 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 11)
    ,ALIGN11_MASK = 0x00000800
    ,ALIGN11_POS = 11
    ,ALIGN11_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN11_1 = 0x00000800 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 12)
    ,ALIGN12_MASK = 0x00001000
    ,ALIGN12_POS = 12
    ,ALIGN12_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN12_1 = 0x00001000 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 13)
    ,ALIGN13_MASK = 0x00002000
    ,ALIGN13_POS = 13
    ,ALIGN13_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN13_1 = 0x00002000 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 14)
    ,ALIGN14_MASK = 0x00004000
    ,ALIGN14_POS = 14
    ,ALIGN14_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN14_1 = 0x00004000 // PDMA channel source address or destination address is not follow transfer width setting
    // Transfer Alignment Flag Note: Source address and destination address should be alignment. (bits: 15)
    ,ALIGN15_MASK = 0x00008000
    ,ALIGN15_POS = 15
    ,ALIGN15_0 = 0x00000000 // PDMA channel source address and destination address both follow transfer width setting
    ,ALIGN15_1 = 0x00008000 // PDMA channel source address or destination address is not follow transfer width setting
    ,ALIGN_MASK = 0x0000FFFF
    ;
  };
  // PDMA Transfer Active Flag Register
  struct TACTSTS : reg<ip_ver, base + 0x42C>
  {
    static constexpr typename TACTSTS::type
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 0)
     TXACTF0_MASK = 0x00000001
    ,TXACTF0_POS = 0
    ,TXACTF0_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF0_1 = 0x00000001 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 1)
    ,TXACTF1_MASK = 0x00000002
    ,TXACTF1_POS = 1
    ,TXACTF1_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF1_1 = 0x00000002 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 2)
    ,TXACTF2_MASK = 0x00000004
    ,TXACTF2_POS = 2
    ,TXACTF2_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF2_1 = 0x00000004 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 3)
    ,TXACTF3_MASK = 0x00000008
    ,TXACTF3_POS = 3
    ,TXACTF3_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF3_1 = 0x00000008 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 4)
    ,TXACTF4_MASK = 0x00000010
    ,TXACTF4_POS = 4
    ,TXACTF4_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF4_1 = 0x00000010 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 5)
    ,TXACTF5_MASK = 0x00000020
    ,TXACTF5_POS = 5
    ,TXACTF5_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF5_1 = 0x00000020 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 6)
    ,TXACTF6_MASK = 0x00000040
    ,TXACTF6_POS = 6
    ,TXACTF6_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF6_1 = 0x00000040 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 7)
    ,TXACTF7_MASK = 0x00000080
    ,TXACTF7_POS = 7
    ,TXACTF7_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF7_1 = 0x00000080 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 8)
    ,TXACTF8_MASK = 0x00000100
    ,TXACTF8_POS = 8
    ,TXACTF8_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF8_1 = 0x00000100 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 9)
    ,TXACTF9_MASK = 0x00000200
    ,TXACTF9_POS = 9
    ,TXACTF9_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF9_1 = 0x00000200 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 10)
    ,TXACTF10_MASK = 0x00000400
    ,TXACTF10_POS = 10
    ,TXACTF10_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF10_1 = 0x00000400 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 11)
    ,TXACTF11_MASK = 0x00000800
    ,TXACTF11_POS = 11
    ,TXACTF11_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF11_1 = 0x00000800 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 12)
    ,TXACTF12_MASK = 0x00001000
    ,TXACTF12_POS = 12
    ,TXACTF12_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF12_1 = 0x00001000 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 13)
    ,TXACTF13_MASK = 0x00002000
    ,TXACTF13_POS = 13
    ,TXACTF13_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF13_1 = 0x00002000 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 14)
    ,TXACTF14_MASK = 0x00004000
    ,TXACTF14_POS = 14
    ,TXACTF14_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF14_1 = 0x00004000 // PDMA channel is active
    // Transfer on Active Flag (Read Only) This bit indicates which PDMA channel is in active. (bits: 15)
    ,TXACTF15_MASK = 0x00008000
    ,TXACTF15_POS = 15
    ,TXACTF15_0 = 0x00000000 // PDMA channel is not finished
    ,TXACTF15_1 = 0x00008000 // PDMA channel is active
    ,TACTSTS_MASK = 0x0000FFFF
    ;
  };
  // PDMA Time-out Prescaler Register
  struct TOUTPSC : reg<ip_ver, base + 0x430>
  {
    static constexpr typename TOUTPSC::type
    // PDMA Channel 0 Time-out Clock Source Prescaler Bits (bits: 2-0)
     TOUTPSC0_MASK = 0x00000007
    ,TOUTPSC0_POS = 0
    ,TOUTPSC0_0 = 0x00000000 // PDMA channel 0 time-out clock source is HCLK/28
    ,TOUTPSC0_1 = 0x00000001 // PDMA channel 0 time-out clock source is HCLK/29
    ,TOUTPSC0_2 = 0x00000002 // PDMA channel 0 time-out clock source is HCLK/210
    ,TOUTPSC0_3 = 0x00000003 // PDMA channel 0 time-out clock source is HCLK/211
    ,TOUTPSC0_4 = 0x00000004 // PDMA channel 0 time-out clock source is HCLK/212
    ,TOUTPSC0_5 = 0x00000005 // PDMA channel 0 time-out clock source is HCLK/213
    ,TOUTPSC0_6 = 0x00000006 // PDMA channel 0 time-out clock source is HCLK/214
    ,TOUTPSC0_7 = 0x00000007 // PDMA channel 0 time-out clock source is HCLK/215
    // PDMA Channel 1 Time-out Clock Source Prescaler Bits (bits: 6-4)
    ,TOUTPSC1_MASK = 0x00000070
    ,TOUTPSC1_POS = 4
    ,TOUTPSC1_0 = 0x00000000 // PDMA channel 1 time-out clock source is HCLK/28
    ,TOUTPSC1_1 = 0x00000010 // PDMA channel 1 time-out clock source is HCLK/29
    ,TOUTPSC1_2 = 0x00000020 // PDMA channel 1 time-out clock source is HCLK/210
    ,TOUTPSC1_3 = 0x00000030 // PDMA channel 1 time-out clock source is HCLK/211
    ,TOUTPSC1_4 = 0x00000040 // PDMA channel 1 time-out clock source is HCLK/212
    ,TOUTPSC1_5 = 0x00000050 // PDMA channel 1 time-out clock source is HCLK/213
    ,TOUTPSC1_6 = 0x00000060 // PDMA channel 1 time-out clock source is HCLK/214
    ,TOUTPSC1_7 = 0x00000070 // PDMA channel 1 time-out clock source is HCLK/215
    ,TOUTPSC_MASK = 0x00000077
    ;
  };
  // PDMA Time-out Enable Register
  struct TOUTEN : reg<ip_ver, base + 0x434>
  {
    static constexpr typename TOUTEN::type
    // PDMA Time-out Enable Bits (bits: 0)
     TOUTEN0_MASK = 0x00000001
    ,TOUTEN0_POS = 0
    ,TOUTEN0_0 = 0x00000000 // PDMA Channel n time-out function Disabled
    ,TOUTEN0_1 = 0x00000001 // PDMA Channel n time-out function Enabled
    // PDMA Time-out Enable Bits (bits: 1)
    ,TOUTEN1_MASK = 0x00000002
    ,TOUTEN1_POS = 1
    ,TOUTEN1_0 = 0x00000000 // PDMA Channel n time-out function Disabled
    ,TOUTEN1_1 = 0x00000002 // PDMA Channel n time-out function Enabled
    ,TOUTEN_MASK = 0x00000003
    ;
  };
  // PDMA Time-out Interrupt Enable Register
  struct TOUTIEN : reg<ip_ver, base + 0x438>
  {
    static constexpr typename TOUTIEN::type
    // PDMA Time-out Interrupt Enable Bits (bits: 0)
     TOUTIEN0_MASK = 0x00000001
    ,TOUTIEN0_POS = 0
    ,TOUTIEN0_0 = 0x00000000 // PDMA Channel n time-out interrupt Disabled
    ,TOUTIEN0_1 = 0x00000001 // PDMA Channel n time-out interrupt Enabled
    // PDMA Time-out Interrupt Enable Bits (bits: 1)
    ,TOUTIEN1_MASK = 0x00000002
    ,TOUTIEN1_POS = 1
    ,TOUTIEN1_0 = 0x00000000 // PDMA Channel n time-out interrupt Disabled
    ,TOUTIEN1_1 = 0x00000002 // PDMA Channel n time-out interrupt Enabled
    ,TOUTIEN_MASK = 0x00000003
    ;
  };
  // PDMA Scatter-gather Descriptor Table Base Address Register
  struct SCATBA : reg<ip_ver, base + 0x43C, 0x20000000>
  {
    static constexpr typename SCATBA::type
    // PDMA Scatter-gather Descriptor Table Address In Scatter-Gather mode, this is the base address for calculating the next link - list address. The next link address equation is Note: Only useful in Scatter-Gather mode. (bits: 31-16)
     SCATBAVAL_MASK = 0xFFFF0000
    ,SCATBAVAL_POS = 16
    ,SCATBA_MASK = 0xFFFF0000
    ;
  };
  // PDMA Time-out Counter Ch1 and Ch0 Register
  struct TOC0_1 : reg<ip_ver, base + 0x440>
  {
    static constexpr typename TOC0_1::type
    // Time-out Counter for Channel 0 This controls the period of time-out function for channel 0. The calculation unit is based on TOUTPSC0 (PDMA_TOUTPSC[2:0]) clock. (bits: 15-0)
     TOC0_MASK = 0x0000FFFF
    ,TOC0_POS = 0
    // Time-out Counter for Channel 1 This controls the period of time-out function for channel 1. The calculation unit is based on 10 kHz clock. The example of time-out period can refer TOC0 bit description. (bits: 31-16)
    ,TOC1_MASK = 0xFFFF0000
    ,TOC1_POS = 16
    ,TOC0_1_MASK = 0xFFFFFFFF
    ;
  };
  // PDMA Channel Reset Register
  struct CHRST : reg<ip_ver, base + 0x460>
  {
    static constexpr typename CHRST::type
    // Channel n Reset Note: This function don't support stride mode. (bits: 15-0)
     CHNRST_MASK = 0x0000FFFF
    ,CHNRST_POS = 0
    ,CHNRST_0 = 0x00000000 // corresponding channel n is not reset
    ,CHNRST_1 = 0x00000001 // corresponding channel n is reset
    ,CHRST_MASK = 0x0000FFFF
    ;
  };
  // PDMA Request Source Select Register 0
  struct REQSEL0_3 : reg<ip_ver, base + 0x480>
  {
    static constexpr typename REQSEL0_3::type
    // Channel 0 Request Source Selection This filed defines which peripheral is connected to PDMA channel 0. User can configure the peripheral by setting REQSRC0. Note 1: A peripheral cannot be assigned to two channels at the same time. Note 2: This field is useless when transfer between memory and memory. (bits: 6-0)
     REQSRC0_MASK = 0x0000007F
    ,REQSRC0_POS = 0
    ,REQSRC0_0 = 0x00000000 // Disable PDMA peripheral request
    ,REQSRC0_1 = 0x00000001 // Reserved.
    ,REQSRC0_2 = 0x00000002 // Channel connects to USB_TX
    ,REQSRC0_3 = 0x00000003 // Channel connects to USB_RX
    ,REQSRC0_4 = 0x00000004 // Channel connects to UART0_TX
    ,REQSRC0_5 = 0x00000005 // Channel connects to UART0_RX
    ,REQSRC0_6 = 0x00000006 // Channel connects to UART1_TX
    ,REQSRC0_7 = 0x00000007 // Channel connects to UART1_RX
    ,REQSRC0_8 = 0x00000008 // Channel connects to UART2_TX
    ,REQSRC0_9 = 0x00000009 // Channel connects to UART2_RX
    ,REQSRC0_10 = 0x0000000A // Channel connects to UART3_TX
    ,REQSRC0_11 = 0x0000000B // Channel connects to UART3_RX
    ,REQSRC0_12 = 0x0000000C // Channel connects to UART4_TX
    ,REQSRC0_13 = 0x0000000D // Channel connects to UART4_RX
    ,REQSRC0_14 = 0x0000000E // Channel connects to UART5_TX
    ,REQSRC0_15 = 0x0000000F // Channel connects to UART5_RX
    ,REQSRC0_16 = 0x00000010 // Channel connects to USCI0_TX
    ,REQSRC0_17 = 0x00000011 // Channel connects to USCI0_RX
    ,REQSRC0_18 = 0x00000012 // Channel connects to USCI1_TX
    ,REQSRC0_19 = 0x00000013 // Channel connects to USCI1_RX
    ,REQSRC0_20 = 0x00000014 // Channel connects to QSPI0_TX
    ,REQSRC0_21 = 0x00000015 // Channel connects to QSPI0_RX
    ,REQSRC0_22 = 0x00000016 // Channel connects to SPI0_TX
    ,REQSRC0_23 = 0x00000017 // Channel connects to SPI0_RX
    ,REQSRC0_24 = 0x00000018 // Channel connects to SPI1_TX
    ,REQSRC0_25 = 0x00000019 // Channel connects to SPI1_RX
    ,REQSRC0_26 = 0x0000001A // Channel connects to SPI2_TX
    ,REQSRC0_27 = 0x0000001B // Channel connects to SPI2_RX
    ,REQSRC0_28 = 0x0000001C // Channel connects to SPI3_TX
    ,REQSRC0_29 = 0x0000001D // Channel connects to SPI3_RX
    ,REQSRC0_30 = 0x0000001E // Channel connects to QSPI1_TX
    ,REQSRC0_31 = 0x0000001F // Channel connects to QSPI1_RX
    ,REQSRC0_32 = 0x00000020 // Channel connects to EPWM0_P1_RX
    ,REQSRC0_33 = 0x00000021 // Channel connects to EPWM0_P2_RX
    ,REQSRC0_34 = 0x00000022 // Channel connects to EPWM0_P3_RX
    ,REQSRC0_35 = 0x00000023 // Channel connects to EPWM1_P1_RX
    ,REQSRC0_36 = 0x00000024 // Channel connects to EPWM1_P2_RX
    ,REQSRC0_37 = 0x00000025 // Channel connects to EPWM1_P3_RX
    ,REQSRC0_38 = 0x00000026 // Channel connects to I2C0_TX
    ,REQSRC0_39 = 0x00000027 // Channel connects to I2C0_RX
    ,REQSRC0_40 = 0x00000028 // Channel connects to I2C1_TX
    ,REQSRC0_41 = 0x00000029 // Channel connects to I2C1_RX
    ,REQSRC0_42 = 0x0000002A // Channel connects to I2C2_TX
    ,REQSRC0_43 = 0x0000002B // Channel connects to I2C2_RX
    ,REQSRC0_44 = 0x0000002C // Channel connects to I2S0_TX
    ,REQSRC0_45 = 0x0000002D // Channel connects to I2S0_RX
    ,REQSRC0_46 = 0x0000002E // Channel connects to TMR0
    ,REQSRC0_47 = 0x0000002F // Channel connects to TMR1
    ,REQSRC0_48 = 0x00000030 // Channel connects to TMR2
    ,REQSRC0_49 = 0x00000031 // Channel connects to TMR3
    ,REQSRC0_50 = 0x00000032 // Channel connects to EADC0_RX
    ,REQSRC0_51 = 0x00000033 // Channel connects to DAC0_TX
    ,REQSRC0_52 = 0x00000034 // Channel connects to DAC1_TX
    ,REQSRC0_53 = 0x00000035 // Channel connects to EPWM0_CH0_TX
    ,REQSRC0_54 = 0x00000036 // Channel connects to EPWM0_CH1_TX
    ,REQSRC0_55 = 0x00000037 // Channel connects to EPWM0_CH2_TX
    ,REQSRC0_56 = 0x00000038 // Channel connects to EPWM0_CH3_TX
    ,REQSRC0_57 = 0x00000039 // Channel connects to EPWM0_CH4_TX
    ,REQSRC0_58 = 0x0000003A // Channel connects to EPWM0_CH5_TX
    ,REQSRC0_59 = 0x0000003B // Channel connects to EPWM1_CH0_TX
    ,REQSRC0_60 = 0x0000003C // Channel connects to EPWM1_CH1_TX
    ,REQSRC0_61 = 0x0000003D // Channel connects to EPWM1_CH2_TX
    ,REQSRC0_62 = 0x0000003E // Channel connects to EPWM1_CH3_TX
    ,REQSRC0_63 = 0x0000003F // Channel connects to EPWM1_CH4_TX
    ,REQSRC0_64 = 0x00000040 // Channel connects to EPWM1_CH5_TX
    ,REQSRC0_65 = 0x00000041 // Reserved.
    ,REQSRC0_66 = 0x00000042 // Channel connects to UART6_TX
    ,REQSRC0_67 = 0x00000043 // Channel connects to UART6_RX
    ,REQSRC0_68 = 0x00000044 // Channel connects to UART7_TX
    ,REQSRC0_69 = 0x00000045 // Channel connects to UART7_RX
    ,REQSRC0_70 = 0x00000046 // Channel connects to EADC1_RX
    // Channel 1 Request Source Selection This filed defines which peripheral is connected to PDMA channel 1. User can configure the peripheral setting by REQSRC1. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 14-8)
    ,REQSRC1_MASK = 0x00007F00
    ,REQSRC1_POS = 8
    // Channel 2 Request Source Selection This filed defines which peripheral is connected to PDMA channel 2. User can configure the peripheral setting by REQSRC2. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 22-16)
    ,REQSRC2_MASK = 0x007F0000
    ,REQSRC2_POS = 16
    // Channel 3 Request Source Selection This filed defines which peripheral is connected to PDMA channel 3. User can configure the peripheral setting by REQSRC3. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 30-24)
    ,REQSRC3_MASK = 0x7F000000
    ,REQSRC3_POS = 24
    ,REQSEL0_3_MASK = 0x7F7F7F7F
    ;
  };
  // PDMA Request Source Select Register 1
  struct REQSEL4_7 : reg<ip_ver, base + 0x484>
  {
    static constexpr typename REQSEL4_7::type
    // Channel 4 Request Source Selection This filed defines which peripheral is connected to PDMA channel 4. User can configure the peripheral setting by REQSRC4. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 6-0)
     REQSRC4_MASK = 0x0000007F
    ,REQSRC4_POS = 0
    // Channel 5 Request Source Selection This filed defines which peripheral is connected to PDMA channel 5. User can configure the peripheral setting by REQSRC5. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 14-8)
    ,REQSRC5_MASK = 0x00007F00
    ,REQSRC5_POS = 8
    // Channel 6 Request Source Selection This filed defines which peripheral is connected to PDMA channel 6. User can configure the peripheral setting by REQSRC6. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 22-16)
    ,REQSRC6_MASK = 0x007F0000
    ,REQSRC6_POS = 16
    // Channel 7 Request Source Selection This filed defines which peripheral is connected to PDMA channel 7. User can configure the peripheral setting by REQSRC7. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 30-24)
    ,REQSRC7_MASK = 0x7F000000
    ,REQSRC7_POS = 24
    ,REQSEL4_7_MASK = 0x7F7F7F7F
    ;
  };
  // PDMA Request Source Select Register 2
  struct REQSEL8_11 : reg<ip_ver, base + 0x488>
  {
    static constexpr typename REQSEL8_11::type
    // Channel 8 Request Source Selection This filed defines which peripheral is connected to PDMA channel 8. User can configure the peripheral setting by REQSRC8. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 6-0)
     REQSRC8_MASK = 0x0000007F
    ,REQSRC8_POS = 0
    // Channel 9 Request Source Selection This filed defines which peripheral is connected to PDMA channel 9. User can configure the peripheral setting by REQSRC9. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 14-8)
    ,REQSRC9_MASK = 0x00007F00
    ,REQSRC9_POS = 8
    // Channel 10 Request Source Selection This filed defines which peripheral is connected to PDMA channel 10. User can configure the peripheral setting by REQSRC10. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 22-16)
    ,REQSRC10_MASK = 0x007F0000
    ,REQSRC10_POS = 16
    // Channel 11 Request Source Selection This filed defines which peripheral is connected to PDMA channel 11. User can configure the peripheral setting by REQSRC11. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 30-24)
    ,REQSRC11_MASK = 0x7F000000
    ,REQSRC11_POS = 24
    ,REQSEL8_11_MASK = 0x7F7F7F7F
    ;
  };
  // PDMA Request Source Select Register 3
  struct REQSEL12_15 : reg<ip_ver, base + 0x48C>
  {
    static constexpr typename REQSEL12_15::type
    // Channel 12 Request Source Selection This filed defines which peripheral is connected to PDMA channel 12. User can configure the peripheral setting by REQSRC12. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 6-0)
     REQSRC12_MASK = 0x0000007F
    ,REQSRC12_POS = 0
    // Channel 13 Request Source Selection This filed defines which peripheral is connected to PDMA channel 13. User can configure the peripheral setting by REQSRC13. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 14-8)
    ,REQSRC13_MASK = 0x00007F00
    ,REQSRC13_POS = 8
    // Channel 14 Request Source Selection This filed defines which peripheral is connected to PDMA channel 14. User can configure the peripheral setting by REQSRC14. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 22-16)
    ,REQSRC14_MASK = 0x007F0000
    ,REQSRC14_POS = 16
    // Channel 15 Request Source Selection This filed defines which peripheral is connected to PDMA channel 15. User can configure the peripheral setting by REQSRC15. Note: The channel configuration is the same as REQSRC0 field. Please refer to the explanation of REQSRC0. (bits: 30-24)
    ,REQSRC15_MASK = 0x7F000000
    ,REQSRC15_POS = 24
    ,REQSEL12_15_MASK = 0x7F7F7F7F
    ;
  };
  // Stride Transfer Count Register of PDMA Channel 0
  struct STC0 : reg<ip_ver, base + 0x500>
  {
    static constexpr typename STC0::type
    // PDMA Stride Transfer Count The 16-bit register defines the stride transfer count of each row, the real transfer count is (STC + 1). (bits: 15-0)
     STC_MASK = 0x0000FFFF
    ,STC_POS = 0
    ,STC0_MASK = 0x0000FFFF
    ;
  };
  // Address Stride Offset Control Register of PDMA Channel 0
  struct ASOCTL0 : reg<ip_ver, base + 0x504>
  {
    static constexpr typename ASOCTL0::type
    // PDMA Source Address Stride Offset Length The 16-bit register defines the source address stride transfer offset count of each row. (bits: 15-0)
     SASOL_MASK = 0x0000FFFF
    ,SASOL_POS = 0
    // PDMA Destination Address Stride Offset Length The 16-bit register defines the destination address stride transfer offset count of each row. (bits: 31-16)
    ,DASOL_MASK = 0xFFFF0000
    ,DASOL_POS = 16
    ,ASOCTL0_MASK = 0xFFFFFFFF
    ;
  };
  // Stride Transfer Count Register of PDMA Channel 1
  using STC1 = reg<ip_ver, base + 0x508>;
  // Address Stride Offset Control Register of PDMA Channel 1
  using ASOCTL1 = reg<ip_ver, base + 0x50C>;
  // Stride Transfer Count Register of PDMA Channel 2
  using STC2 = reg<ip_ver, base + 0x510>;
  // Address Stride Offset Control Register of PDMA Channel 2
  using ASOCTL2 = reg<ip_ver, base + 0x514>;
  // Stride Transfer Count Register of PDMA Channel 3
  using STC3 = reg<ip_ver, base + 0x518>;
  // Address Stride Offset Control Register of PDMA Channel 3
  using ASOCTL3 = reg<ip_ver, base + 0x51C>;
  // Stride Transfer Count Register of PDMA Channel 4
  using STC4 = reg<ip_ver, base + 0x520>;
  // Address Stride Offset Control Register of PDMA Channel 4
  using ASOCTL4 = reg<ip_ver, base + 0x524>;
  // Stride Transfer Count Register of PDMA Channel 5
  using STC5 = reg<ip_ver, base + 0x528>;
  // Address Stride Offset Control Register of PDMA Channel 5
  using ASOCTL5 = reg<ip_ver, base + 0x52C>;
  // Address Interval Control Register of PDMA Channel 0
  struct AICTL0 : reg<ip_ver, base + 0x600>
  {
    static constexpr typename AICTL0::type
    // PDMA Source Address Interval Count The 16-bit register defines the source address interval count of each row. Note: This register should be set to 0 when repeat count(PDMA_RCNTn) set to 0. (bits: 15-0)
     SAICNT_MASK = 0x0000FFFF
    ,SAICNT_POS = 0
    // PDMA Destination Address Interval Count The 16-bit register defines the destination address interval count of each row. Note: This register should be set to 0 when repeat count(PDMA_RCNTn) set to 0. (bits: 31-16)
    ,DAICNT_MASK = 0xFFFF0000
    ,DAICNT_POS = 16
    ,AICTL0_MASK = 0xFFFFFFFF
    ;
  };
  // Repeat Count Register of PDMA Channel 0
  struct RCNT0 : reg<ip_ver, base + 0x604>
  {
    static constexpr typename RCNT0::type
    // PDMA Repeat Count The 16-bit register defines the repeat times of block transfer. Note: This register should be set to 0 when stride function disabled. (bits: 15-0)
     RCNT_MASK = 0x0000FFFF
    ,RCNT_POS = 0
    ,RCNT0_MASK = 0x0000FFFF
    ;
  };
  // Address Interval Control Register of PDMA Channel 1
  using AICTL1 = reg<ip_ver, base + 0x608>;
  // Repeat Count Register of PDMA Channel 1
  using RCNT1 = reg<ip_ver, base + 0x60C>;
}; // struct PDMA

} // namespace lmcu::device::ip::v1

