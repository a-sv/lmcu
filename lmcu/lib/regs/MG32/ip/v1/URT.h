/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// UART Control Module
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct URT
{
  static constexpr auto ip_ver = ip_version::_1;

  // URT status register 1
  struct STA : reg<ip_ver, base + 0x0>
  {
    static constexpr typename STA::type
    // UART auto baud-rate calibration sync field receive time-out time out flag (bits: 30)
     CALTMOF_MASK = 0x40000000
    ,CALTMOF_POS = 30
    ,CALTMOF_NORMAL = 0x00000000 // No event occurred
    ,CALTMOF_HAPPENED = 0x40000000 // Event happened
    // UART break receive time out flag. (set by hardware and clear by software writing 1) (bits: 29)
    ,BKTMOF_MASK = 0x20000000
    ,BKTMOF_POS = 29
    ,BKTMOF_NORMAL = 0x00000000 // No event occurred
    ,BKTMOF_HAPPENED = 0x20000000 // Event happened
    // UART idle state time out flag. (set by hardware and clear by software writing 1) (bits: 28)
    ,IDTMOF_MASK = 0x10000000
    ,IDTMOF_POS = 28
    ,IDTMOF_NORMAL = 0x00000000 // No event occurred
    ,IDTMOF_HAPPENED = 0x10000000 // Event happened
    // UART receive time out flag. (set by hardware and clear by software writing 1) (bits: 27)
    ,RXTMOF_MASK = 0x08000000
    ,RXTMOF_POS = 27
    ,RXTMOF_NORMAL = 0x00000000 // No event occurred
    ,RXTMOF_HAPPENED = 0x08000000 // Event happened
    // UART TX error detect flag (bits: 24)
    ,TXEF_MASK = 0x01000000
    ,TXEF_POS = 24
    ,TXEF_NORMAL = 0x00000000 // No event occurred
    ,TXEF_HAPPENED = 0x01000000 // Event happened
    // UART receive overrun error flag (bits: 23)
    ,ROVRF_MASK = 0x00800000
    ,ROVRF_POS = 23
    ,ROVRF_NORMAL = 0x00000000 // No event occurred
    ,ROVRF_HAPPENED = 0x00800000 // Event happened
    // UART receive noised character error flag (bits: 22)
    ,NCEF_MASK = 0x00400000
    ,NCEF_POS = 22
    ,NCEF_NORMAL = 0x00000000 // No event occurred
    ,NCEF_HAPPENED = 0x00400000 // Event happened
    // UART frame error flag. (set by hardware and clear by software writing 1) (bits: 21)
    ,FEF_MASK = 0x00200000
    ,FEF_POS = 21
    ,FEF_NORMAL = 0x00000000 // No event occurred
    ,FEF_HAPPENED = 0x00200000 // Event happened
    // UART parity error flag (bits: 20)
    ,PEF_MASK = 0x00100000
    ,PEF_POS = 20
    ,PEF_NORMAL = 0x00000000 // No event occurred
    ,PEF_HAPPENED = 0x00100000 // Event happened
    // UART CTS change detect interrupt flag (bits: 18)
    ,CTSF_MASK = 0x00040000
    ,CTSF_POS = 18
    ,CTSF_NORMAL = 0x00000000 // No event occurred
    ,CTSF_HAPPENED = 0x00040000 // Event happened
    // UART idle line detect flag. (set by hardware and clear by software writing 1) (bits: 17)
    ,IDLF_MASK = 0x00020000
    ,IDLF_POS = 17
    ,IDLF_NORMAL = 0x00000000 // No event occurred
    ,IDLF_HAPPENED = 0x00020000 // Event happened
    // UART break condition detect flag. (set by hardware and clear by software writing 1) (bits: 16)
    ,BKF_MASK = 0x00010000
    ,BKF_POS = 16
    ,BKF_NORMAL = 0x00000000 // No event occurred
    ,BKF_HAPPENED = 0x00010000 // Event happened
    // UART auto baud-rate calibration overflow status flag (bits: 15)
    ,CALOVF_MASK = 0x00008000
    ,CALOVF_POS = 15
    ,CALOVF_NORMAL = 0x00000000 // No event occurred
    ,CALOVF_HAPPENED = 0x00008000 // Event happened
    // UART auto baud-rate calibration underflow status flag (bits: 14)
    ,CALUDF_MASK = 0x00004000
    ,CALUDF_POS = 14
    ,CALUDF_NORMAL = 0x00000000 // No event occurred
    ,CALUDF_HAPPENED = 0x00004000 // Event happened
    // UART auto baud-rate calibration complete flag (bits: 13)
    ,CALCF_MASK = 0x00002000
    ,CALCF_POS = 13
    ,CALCF_NORMAL = 0x00000000 // No event occurred
    ,CALCF_HAPPENED = 0x00002000 // Event happened
    // UART timeout timer timeout flag. (set by hardware and clear by software writing 1) (bits: 12)
    ,TMOF_MASK = 0x00001000
    ,TMOF_POS = 12
    ,TMOF_NORMAL = 0x00000000 // No event occurred
    ,TMOF_HAPPENED = 0x00001000 // Event happened
    // UART baud-rate generator timer timeout flag (bits: 11)
    ,BRTF_MASK = 0x00000800
    ,BRTF_POS = 11
    ,BRTF_NORMAL = 0x00000000 // No event occurred
    ,BRTF_HAPPENED = 0x00000800 // Event happened
    // UART slave address matched flag. (set by hardware and clear by software writing 1) (bits: 10)
    ,SADRF_MASK = 0x00000400
    ,SADRF_POS = 10
    ,SADRF_NORMAL = 0x00000000 // No event occurred
    ,SADRF_HAPPENED = 0x00000400 // Event happened
    // UART transmit data register empty (bits: 7)
    ,TXF_MASK = 0x00000080
    ,TXF_POS = 7
    ,TXF_NORMAL = 0x00000000 // No event occurred
    ,TXF_HAPPENED = 0x00000080 // Event happened
    // UART receive data register not empty (bits: 6)
    ,RXF_MASK = 0x00000040
    ,RXF_POS = 6
    ,RXF_NORMAL = 0x00000000 // No event occurred
    ,RXF_HAPPENED = 0x00000040 // Event happened
    // UART received data byte number is different from previous received data byte number f (bits: 5)
    ,RXDF_MASK = 0x00000020
    ,RXDF_POS = 5
    ,RXDF_NORMAL = 0x00000000 // No event occurred
    ,RXDF_HAPPENED = 0x00000020 // Event happened
    // UART line statue flag for break condition, idle line, CTS detect (bits: 4)
    ,LSF_MASK = 0x00000010
    ,LSF_POS = 4
    ,LSF_NORMAL = 0x00000000 // No event occurred
    ,LSF_HAPPENED = 0x00000010 // Event happened
    // UART error interrupt flag for parity error, frame error, overrun error, receive time (bits: 3)
    ,ERRF_MASK = 0x00000008
    ,ERRF_POS = 3
    ,ERRF_NORMAL = 0x00000000 // No event occurred
    ,ERRF_HAPPENED = 0x00000008 // Event happened
    // UART transmission complete flag (bits: 2)
    ,TCF_MASK = 0x00000004
    ,TCF_POS = 2
    ,TCF_NORMAL = 0x00000000 // No event occurred
    ,TCF_HAPPENED = 0x00000004 // Event happened
    // UART general event flag (bits: 1)
    ,UGF_MASK = 0x00000002
    ,UGF_POS = 1
    ,UGF_NORMAL = 0x00000000 // No event occurred
    ,UGF_HAPPENED = 0x00000002 // Event happened
    // UART receive hold flag (bits: 0)
    ,RHF_MASK = 0x00000001
    ,RHF_POS = 0
    ,RHF_NORMAL = 0x00000000 // No event occurred
    ,RHF_HAPPENED = 0x00000001 // Event happened
    ,STA_MASK = 0x79F7FCFF
    ;
  };
  // URT interrupt enable register
  struct INT : reg<ip_ver, base + 0x4>
  {
    static constexpr typename INT::type
    // UART auto baud-rate calibration sync field receive time-out time out interrupt enable (bits: 30)
     CALTMO_IE_MASK = 0x40000000
    ,CALTMO_IE_POS = 30
    ,CALTMO_IE_DISABLE = 0x00000000 
    ,CALTMO_IE_ENABLE = 0x40000000 
    // UART break receive time out interrupt enable (bits: 29)
    ,BKTMO_IE_MASK = 0x20000000
    ,BKTMO_IE_POS = 29
    ,BKTMO_IE_DISABLE = 0x00000000 
    ,BKTMO_IE_ENABLE = 0x20000000 
    // UART idle state time out interrupt enable (bits: 28)
    ,IDTMO_IE_MASK = 0x10000000
    ,IDTMO_IE_POS = 28
    ,IDTMO_IE_DISABLE = 0x00000000 
    ,IDTMO_IE_ENABLE = 0x10000000 
    // UART receive time out interrupt enable (bits: 27)
    ,RXTMO_IE_MASK = 0x08000000
    ,RXTMO_IE_POS = 27
    ,RXTMO_IE_DISABLE = 0x00000000 
    ,RXTMO_IE_ENABLE = 0x08000000 
    // UART TX error detect interrupt enable. Refer to URTx_TXE_MDS for detail (bits: 24)
    ,TXE_IE_MASK = 0x01000000
    ,TXE_IE_POS = 24
    ,TXE_IE_DISABLE = 0x00000000 
    ,TXE_IE_ENABLE = 0x01000000 
    // UART receive overrun error interrupt enable. Refer to URTx_ROVRF for the detail (bits: 23)
    ,ROVR_IE_MASK = 0x00800000
    ,ROVR_IE_POS = 23
    ,ROVR_IE_DISABLE = 0x00000000 
    ,ROVR_IE_ENABLE = 0x00800000 
    // UART receive noised character interrupt enable (bits: 22)
    ,NCE_IE_MASK = 0x00400000
    ,NCE_IE_POS = 22
    ,NCE_IE_DISABLE = 0x00000000 
    ,NCE_IE_ENABLE = 0x00400000 
    // UART frame error interrupt enable (bits: 21)
    ,FE_IE_MASK = 0x00200000
    ,FE_IE_POS = 21
    ,FE_IE_DISABLE = 0x00000000 
    ,FE_IE_ENABLE = 0x00200000 
    // UART parity error interrupt enable (bits: 20)
    ,PE_IE_MASK = 0x00100000
    ,PE_IE_POS = 20
    ,PE_IE_DISABLE = 0x00000000 
    ,PE_IE_ENABLE = 0x00100000 
    // UART CTS change detect interrupt enable (bits: 18)
    ,CTS_IE_MASK = 0x00040000
    ,CTS_IE_POS = 18
    ,CTS_IE_DISABLE = 0x00000000 
    ,CTS_IE_ENABLE = 0x00040000 
    // UART idle line detect interrupt enable (bits: 17)
    ,IDL_IE_MASK = 0x00020000
    ,IDL_IE_POS = 17
    ,IDL_IE_DISABLE = 0x00000000 
    ,IDL_IE_ENABLE = 0x00020000 
    // UART break condition detect interrupt enable (bits: 16)
    ,BK_IE_MASK = 0x00010000
    ,BK_IE_POS = 16
    ,BK_IE_DISABLE = 0x00000000 
    ,BK_IE_ENABLE = 0x00010000 
    // UART auto baud-rate calibration complete interrupt enable (bits: 13)
    ,CALC_IE_MASK = 0x00002000
    ,CALC_IE_POS = 13
    ,CALC_IE_DISABLE = 0x00000000 
    ,CALC_IE_ENABLE = 0x00002000 
    // UART timeout timer timeout interrupt enable (bits: 12)
    ,TMO_IE_MASK = 0x00001000
    ,TMO_IE_POS = 12
    ,TMO_IE_DISABLE = 0x00000000 
    ,TMO_IE_ENABLE = 0x00001000 
    // UART baud-rate generator timer timeout interrupt enable (bits: 11)
    ,BRT_IE_MASK = 0x00000800
    ,BRT_IE_POS = 11
    ,BRT_IE_DISABLE = 0x00000000 
    ,BRT_IE_ENABLE = 0x00000800 
    // UART slave address matched interrupt enable (bits: 10)
    ,SADR_IE_MASK = 0x00000400
    ,SADR_IE_POS = 10
    ,SADR_IE_DISABLE = 0x00000000 
    ,SADR_IE_ENABLE = 0x00000400 
    // UART transmit data register empty interrupt enable. Refer to URTx_TXF for the detail (bits: 7)
    ,TX_IE_MASK = 0x00000080
    ,TX_IE_POS = 7
    ,TX_IE_DISABLE = 0x00000000 
    ,TX_IE_ENABLE = 0x00000080 
    // UART receive data register not empty interrupt enable (bits: 6)
    ,RX_IE_MASK = 0x00000040
    ,RX_IE_POS = 6
    ,RX_IE_DISABLE = 0x00000000 
    ,RX_IE_ENABLE = 0x00000040 
    // UART line statue flag for break condition, idle line, CTS detect (bits: 4)
    ,LS_IE_MASK = 0x00000010
    ,LS_IE_POS = 4
    ,LS_IE_DISABLE = 0x00000000 
    ,LS_IE_ENABLE = 0x00000010 
    // UART error interrupt enable for parity error, frame error, overrun error, receive tim (bits: 3)
    ,ERR_IE_MASK = 0x00000008
    ,ERR_IE_POS = 3
    ,ERR_IE_DISABLE = 0x00000000 
    ,ERR_IE_ENABLE = 0x00000008 
    // UART transmission complete interrupt enable (bits: 2)
    ,TC_IE_MASK = 0x00000004
    ,TC_IE_POS = 2
    ,TC_IE_DISABLE = 0x00000000 
    ,TC_IE_ENABLE = 0x00000004 
    // UART general event interrupt enable for URTx_SADRF , URTx_TF , URTx_RCNTF or URTx_TCN (bits: 1)
    ,UG_IE_MASK = 0x00000002
    ,UG_IE_POS = 1
    ,UG_IE_DISABLE = 0x00000000 
    ,UG_IE_ENABLE = 0x00000002 
    // UART interrupt all enable (bits: 0)
    ,IEA_MASK = 0x00000001
    ,IEA_POS = 0
    ,IEA_DISABLE = 0x00000000 
    ,IEA_ENABLE = 0x00000001 
    ,INT_MASK = 0x79F73CDF
    ;
  };
  // URT clock source register
  struct CLK : reg<ip_ver, base + 0x8>
  {
    static constexpr typename CLK::type
    // UART PSC clock output signal initial state control (bits: 29)
     CKO_LCK_MASK = 0x20000000
    ,CKO_LCK_POS = 29
    ,CKO_LCK_LOCKED = 0x00000000 
    ,CKO_LCK_UN_LOCKED = 0x20000000 
    // UART PSC clock output signal initial state (bits: 28)
    ,CKO_STA_MASK = 0x10000000
    ,CKO_STA_POS = 28
    ,CKO_STA_0 = 0x00000000 // Output 0
    ,CKO_STA_1 = 0x10000000 // Output 1
    // UART baud-rate timer timeout signal initial state control (bits: 27)
    ,BRO_LCK_MASK = 0x08000000
    ,BRO_LCK_POS = 27
    ,BRO_LCK_LOCKED = 0x00000000 
    ,BRO_LCK_UN_LOCKED = 0x08000000 
    // UART baud-rate timer timeout signal initial state (bits: 26)
    ,BRO_STA_MASK = 0x04000000
    ,BRO_STA_POS = 26
    ,BRO_STA_0 = 0x00000000 // Output 0
    ,BRO_STA_1 = 0x04000000 // Output 1
    // UART baud-rate timer mode select (bits: 25)
    ,BR_MDS_MASK = 0x02000000
    ,BR_MDS_POS = 25
    ,BR_MDS_SEPARATED = 0x00000000 // Separated PSC and CNT counters for UART baud-rate generator
    ,BR_MDS_COMBINED = 0x02000000 // Combine to a linear counter for general using timer
    // UART baud-rate timer enable. When enables, the baud-rate timer (bits: 24)
    ,BR_EN_MASK = 0x01000000
    ,BR_EN_POS = 24
    ,BR_EN_DISABLE = 0x00000000 
    ,BR_EN_ENABLE = 0x01000000 
    // UART transmission clock source select (bits: 21-20)
    ,TX_CKS_MASK = 0x00300000
    ,TX_CKS_POS = 20
    ,TX_CKS_INTERNAL = 0x00000000 // UART internal clock source CK_URTx_INT
    ,TX_CKS_TM01_TRGO = 0x00100000 
    ,TX_CKS_TM10_TRGO = 0x00200000 
    ,TX_CKS_EXT_CLK = 0x00300000 // external clock from URTx_CLK pin
    // UART receive clock source select (bits: 17-16)
    ,RX_CKS_MASK = 0x00030000
    ,RX_CKS_POS = 16
    ,RX_CKS_INTERNAL = 0x00000000 // UART internal clock source CK_URTx_INT
    ,RX_CKS_TM01_TRGO = 0x00010000 
    ,RX_CKS_TM10_TRGO = 0x00020000 
    ,RX_CKS_EXT_CLK = 0x00030000 // external clock from URTx_CLK pin
    // UART external clock input select (bits: 7)
    ,ECK_CKS_MASK = 0x00000080
    ,ECK_CKS_POS = 7
    ,ECK_CKS_CLK = 0x00000000 // URTx_CLK pin
    ,ECK_CKS_RX = 0x00000080 // receiving signal
    // UART external clock output source select (bits: 5)
    ,CLK_CKS_MASK = 0x00000020
    ,CLK_CKS_POS = 5
    ,CLK_CKS_OUT = 0x00000000 // CK_URTx_OUT from clock output divider
    ,CLK_CKS_SC = 0x00000020 // CK_URTx_SC from clock input prescaler
    // URTx_CLK signal output enable (bits: 4)
    ,CLK_EN_MASK = 0x00000010
    ,CLK_EN_POS = 4
    ,CLK_EN_DISABLE = 0x00000000 
    ,CLK_EN_ENABLE = 0x00000010 
    // UART internal clock CK_UART source select (bits: 3-1)
    ,CK_SEL_MASK = 0x0000000E
    ,CK_SEL_POS = 1
    ,CK_SEL_PROC = 0x00000000 // CK_URTx_PR process clock from CSC
    ,CK_SEL_CK_LS = 0x00000004 
    ,CK_SEL_TM00_TRGO = 0x00000006 
    ,CK_SEL_EXT_CLK = 0x00000008 // external clock from URTx_ECK signal
    ,CLK_MASK = 0x3F3300BE
    ;
  };
  // URT status register 2
  struct STA2 : reg<ip_ver, base + 0xC>
  {
    static constexpr typename STA2::type
    // UART data buffer transmission remained level indications (bits: 30-28)
     TX_LVL_MASK = 0x70000000
    ,TX_LVL_POS = 28
    ,TX_LVL_0 = 0x00000000 // 0-byte,empty
    ,TX_LVL_1 = 0x10000000 // 1-byte
    ,TX_LVL_2 = 0x20000000 // 2-byte
    ,TX_LVL_3 = 0x30000000 // 3-byte
    ,TX_LVL_4 = 0x40000000 // 4-byte
    // UART data buffer received level indications (bits: 26-24)
    ,RX_LVL_MASK = 0x07000000
    ,RX_LVL_POS = 24
    ,RX_LVL_0 = 0x00000000 // 0-byte,empty
    ,RX_LVL_1 = 0x01000000 // 1-byte
    ,RX_LVL_2 = 0x02000000 // 2-byte
    ,RX_LVL_3 = 0x03000000 // 3-byte
    ,RX_LVL_4 = 0x04000000 // 4-byte
    // UART CTS line status bit (bits: 12)
    ,CTS_MASK = 0x00001000
    ,CTS_POS = 12
    ,CTS = 0x00001000
    // UART IrDA data received busy flag (bits: 7)
    ,IR_BUSYF_MASK = 0x00000080
    ,IR_BUSYF_POS = 7
    ,IR_BUSYF_NO = 0x00000000 // No IrDA signal detect
    ,IR_BUSYF_BUSY = 0x00000080 // detect some IrDA signal
    // UART send break busy flag. (set and clear by hardware) (bits: 6)
    ,BKBF_MASK = 0x00000040
    ,BKBF_POS = 6
    ,BKBF_NORMAL = 0x00000000 // No break transmitted or transmit finished
    ,BKBF_BUSY = 0x00000040 // Event happened
    // UART receive noised character flag. (set and clear by hardware) (bits: 5)
    ,NCF_MASK = 0x00000020
    ,NCF_POS = 5
    ,NCF_NORMAL = 0x00000000 // No event occurred
    ,NCF_HAPPENED = 0x00000020 // Event happened
    // UART data receive slave address bit of shift buffer (bits: 2)
    ,ADR_MASK = 0x00000004
    ,ADR_POS = 2
    ,ADR = 0x00000004
    // UART data receive parity bit of shift buffer (bits: 1)
    ,PAR_MASK = 0x00000002
    ,PAR_POS = 1
    ,PAR = 0x00000002
    // UART RX busy flag (bits: 0)
    ,BUSYF_MASK = 0x00000001
    ,BUSYF_POS = 0
    ,BUSYF_NORMAL = 0x00000000 // No event occurred
    ,BUSYF_BUSY = 0x00000001 // Event happened
    ,STA2_MASK = 0x770010E7
    ;
  };
  // URT control register 0
  struct CR0 : reg<ip_ver, base + 0x10>
  {
    static constexpr typename CR0::type
    // Direct memory access enable to transmit (bits: 31)
     DMA_TXEN_MASK = 0x80000000
    ,DMA_TXEN_POS = 31
    ,DMA_TXEN_DISABLE = 0x00000000 
    ,DMA_TXEN_ENABLE = 0x80000000 
    // Direct memory access enable to receive (bits: 30)
    ,DMA_RXEN_MASK = 0x40000000
    ,DMA_RXEN_POS = 30
    ,DMA_RXEN_DISABLE = 0x00000000 
    ,DMA_RXEN_ENABLE = 0x40000000 
    // Hardware force to disable DMA TX function enable bit when detects a break condition (bits: 29)
    ,DDTX_EN_MASK = 0x20000000
    ,DDTX_EN_POS = 29
    ,DDTX_EN_DISABLE = 0x00000000 
    ,DDTX_EN_ENABLE = 0x20000000 
    // UART loop back mode enable bit (bits: 23)
    ,LBM_EN_MASK = 0x00800000
    ,LBM_EN_POS = 23
    ,LBM_EN_DISABLE = 0x00000000 
    ,LBM_EN_ENABLE = 0x00800000 
    // UART receiving noised character disable bit (bits: 22)
    ,NCHAR_DIS_MASK = 0x00400000
    ,NCHAR_DIS_POS = 22
    ,NCHAR_DIS_ENABLE = 0x00000000 // Accept noised character
    ,NCHAR_DIS_DISABLE = 0x00400000 // Skip noised character
    // UART receiving hold enable bit if receives a noised character (bits: 21)
    ,NCHAR_HE_MASK = 0x00200000
    ,NCHAR_HE_POS = 21
    ,NCHAR_HE_DISABLE = 0x00000000 
    ,NCHAR_HE_ENABLE = 0x00200000 
    // UART idle line detect management mode select (bits: 20)
    ,IDL_MDS_MASK = 0x00100000
    ,IDL_MDS_POS = 20
    ,IDL_MDS_NO = 0x00000000 // No operation
    ,IDL_MDS_LOAD = 0x00100000 // Force to load shadow buffer
    // UART data buffer high threshold for received access (bits: 17-16)
    ,RX_TH_MASK = 0x00030000
    ,RX_TH_POS = 16
    ,RX_TH_1BYTE = 0x00000000 // default
    ,RX_TH_2BYTE = 0x00010000 
    ,RX_TH_3BYTE = 0x00020000 
    ,RX_TH_4BYTE = 0x00030000 
    // URTx_DE signal output guard time select by unit of bit time (bits: 15-14)
    ,DE_GT_MASK = 0x0000C000
    ,DE_GT_POS = 14
    ,DE_GT_1_4 = 0x00000000 
    ,DE_GT_1_2 = 0x00004000 
    ,DE_GT_1 = 0x00008000 
    ,DE_GT_2 = 0x0000C000 
    // URTx_DE signal inverse enable. The hardware DE output default is low level (bits: 13)
    ,DE_INV_MASK = 0x00002000
    ,DE_INV_POS = 13
    ,DE_INV_DISABLE = 0x00000000 
    ,DE_INV_ENABLE = 0x00002000 
    // URTx_DE signal output enable (bits: 12)
    ,DE_EN_MASK = 0x00001000
    ,DE_EN_POS = 12
    ,DE_EN_DISABLE = 0x00000000 
    ,DE_EN_ENABLE = 0x00001000 
    // URTx_TX output signal inverse enable (bits: 11)
    ,TX_INV_MASK = 0x00000800
    ,TX_INV_POS = 11
    ,TX_INV_DISABLE = 0x00000000 
    ,TX_INV_ENABLE = 0x00000800 
    // URTx_RX input signal inverse enable (bits: 10)
    ,RX_INV_MASK = 0x00000400
    ,RX_INV_POS = 10
    ,RX_INV_DISABLE = 0x00000000 
    ,RX_INV_ENABLE = 0x00000400 
    // URTx_RX/URTx_TX swap enable bit (bits: 8)
    ,IO_SWP_MASK = 0x00000100
    ,IO_SWP_POS = 8
    ,IO_SWP_DISABLE = 0x00000000 
    ,IO_SWP_ENABLE = 0x00000100 
    // UART multi-processor global slave address enable (bits: 7)
    ,GSA_EN_MASK = 0x00000080
    ,GSA_EN_POS = 7
    ,GSA_EN = 0x00000080
    // UART mode select (bits: 6-4)
    ,MDS_MASK = 0x00000070
    ,MDS_POS = 4
    ,MDS_UART = 0x00000000 // UART mode
    ,MDS_SYNC = 0x00000010 // Synchronous/Shift-Register mode
    ,MDS_IDLE = 0x00000020 // Idle-line mode for multi-processor
    ,MDS_ADR = 0x00000030 // Address-bit mode for multi-processor
    // UART communication data line select (bits: 3)
    ,DAT_LINE_MASK = 0x00000008
    ,DAT_LINE_POS = 3
    ,DAT_LINE_2 = 0x00000000 // 2-lines separated ~ URTx_RX , URTx_TX
    ,DAT_LINE_1 = 0x00000008 // 1-line Bidirectional ~URTx_TX only
    // UART Half-duplex mode enable (bits: 2)
    ,HDX_EN_MASK = 0x00000004
    ,HDX_EN_POS = 2
    ,HDX_EN_DISABLE = 0x00000000 
    ,HDX_EN_ENABLE = 0x00000004 
    // UART RX data oversampling majority vote select (bits: 1)
    ,OS_MDS_MASK = 0x00000002
    ,OS_MDS_POS = 1
    ,OS_MDS_THREE = 0x00000000 // Three sample bits method
    ,OS_MDS_ONE = 0x00000002 // One sample bit method and noise free
    // UART function enable bit (bits: 0)
    ,EN_MASK = 0x00000001
    ,EN_POS = 0
    ,EN_DISABLE = 0x00000000 
    ,EN_ENABLE = 0x00000001 
    ,CR0_MASK = 0xE0F3FDFF
    ;
  };
  // URT control register 1
  struct CR1 : reg<ip_ver, base + 0x14, 0x0F400F40>
  {
    static constexpr typename CR1::type
    // UARTTX data oversampling samples select (bits: 28-24)
     TXOS_NUM_MASK = 0x1F000000
    ,TXOS_NUM_POS = 24
    // UART TX stop bit length select (bits: 23-22)
    ,TXSTP_LEN_MASK = 0x00C00000
    ,TXSTP_LEN_POS = 22
    ,TXSTP_LEN_0_5BIT = 0x00000000 
    ,TXSTP_LEN_1BIT = 0x00400000 
    ,TXSTP_LEN_1_5BIT = 0x00800000 
    ,TXSTP_LEN_2BIT = 0x00C00000 
    // UART TX data order Msb first enable (bits: 21)
    ,TXMSB_EN_MASK = 0x00200000
    ,TXMSB_EN_POS = 21
    ,TXMSB_EN_DISABLE = 0x00000000 
    ,TXMSB_EN_ENABLE = 0x00200000 
    // UART stuck parity bit output enable (bits: 20)
    ,TXPAR_STK_MASK = 0x00100000
    ,TXPAR_STK_POS = 20
    ,TXPAR_STK_DISABLE = 0x00000000 
    ,TXPAR_STK_ENABLE = 0x00100000 
    // UART TX parity bit polarity. This bit is no effect for SPI and SYNC mods (bits: 19)
    ,TXPAR_POL_MASK = 0x00080000
    ,TXPAR_POL_POS = 19
    ,TXPAR_POL_EVEN = 0x00000000 
    ,TXPAR_POL_ODD = 0x00080000 
    // UART TX parity bit enable (bits: 18)
    ,TXPAR_EN_MASK = 0x00040000
    ,TXPAR_EN_POS = 18
    ,TXPAR_EN_DISABLE = 0x00000000 
    ,TXPAR_EN_ENABLE = 0x00040000 
    // UART TX data bit length (bits: 17-16)
    ,TXDSIZE_MASK = 0x00030000
    ,TXDSIZE_POS = 16
    ,TXDSIZE_8BIT = 0x00000000 
    ,TXDSIZE_7BIT = 0x00010000 
    // UART RX data oversampling samples select (bits: 12-8)
    ,RXOS_NUM_MASK = 0x00001F00
    ,RXOS_NUM_POS = 8
    // UART RX stop bit length select (bits: 7-6)
    ,RXSTP_LEN_MASK = 0x000000C0
    ,RXSTP_LEN_POS = 6
    ,RXSTP_LEN_0_5BIT = 0x00000000 
    ,RXSTP_LEN_1BIT = 0x00000040 
    ,RXSTP_LEN_1_5BIT = 0x00000080 
    ,RXSTP_LEN_2BIT = 0x000000C0 
    // UART RX data order Msb first enable (bits: 5)
    ,RXMSB_EN_MASK = 0x00000020
    ,RXMSB_EN_POS = 5
    ,RXMSB_EN_DISABLE = 0x00000000 
    ,RXMSB_EN_ENABLE = 0x00000020 
    // UART stuck parity bit input enable (bits: 4)
    ,RXPAR_STK_MASK = 0x00000010
    ,RXPAR_STK_POS = 4
    ,RXPAR_STK_DISABLE = 0x00000000 
    ,RXPAR_STK_ENABLE = 0x00000010 
    // UART RX parity bit polarity. This bit is no effect for SYNC mods (bits: 3)
    ,RXPAR_POL_MASK = 0x00000008
    ,RXPAR_POL_POS = 3
    ,RXPAR_POL_EVEN = 0x00000000 
    ,RXPAR_POL_ODD = 0x00000008 
    // UART RX parity bit enable (bits: 2)
    ,RXPAR_EN_MASK = 0x00000004
    ,RXPAR_EN_POS = 2
    ,RXPAR_EN_DISABLE = 0x00000000 
    ,RXPAR_EN_ENABLE = 0x00000004 
    // UART RX data bit length (bits: 1-0)
    ,RXDSIZE_MASK = 0x00000003
    ,RXDSIZE_POS = 0
    ,RXDSIZE_8BIT = 0x00000000 
    ,RXDSIZE_7BIT = 0x00000001 
    ,CR1_MASK = 0x1FFF1FFF
    ;
  };
  // URT control register 2
  struct CR2 : reg<ip_ver, base + 0x18>
  {
    static constexpr typename CR2::type
    // UART NSS signal output use software control bit enable (bits: 26)
     NSS_SWEN_MASK = 0x04000000
    ,NSS_SWEN_POS = 26
    ,NSS_SWEN_DISABLE = 0x00000000 
    ,NSS_SWEN_ENABLE = 0x04000000 
    // UART NSS output signal inverse enable (bits: 25)
    ,NSS_INV_MASK = 0x02000000
    ,NSS_INV_POS = 25
    ,NSS_INV_DISABLE = 0x00000000 
    ,NSS_INV_ENABLE = 0x02000000 
    // UART NSS signal software output control bit when URTx_NSS_SWEN is disable (bits: 16)
    ,NSS_SWO_MASK = 0x00010000
    ,NSS_SWO_POS = 16
    ,NSS_SWO = 0x00010000
    // UART transmitter halt enable (bits: 4)
    ,TX_HALT_MASK = 0x00000010
    ,TX_HALT_POS = 4
    ,TX_HALT_DISABLE = 0x00000000 
    ,TX_HALT_ENABLE = 0x00000010 
    // UART transmitter enable (bits: 3)
    ,TX_EN_MASK = 0x00000008
    ,TX_EN_POS = 3
    ,TX_EN_DISABLE = 0x00000000 
    ,TX_EN_ENABLE = 0x00000008 
    // UART receiver enable (bits: 2)
    ,RX_EN_MASK = 0x00000004
    ,RX_EN_POS = 2
    ,RX_EN_DISABLE = 0x00000000 
    ,RX_EN_ENABLE = 0x00000004 
    // UART slave address for next data transmitted (bits: 1)
    ,ADR_TX_MASK = 0x00000002
    ,ADR_TX_POS = 1
    ,ADR_TX_NORMAL = 0x00000000 
    ,ADR_TX_SEND = 0x00000002 // Send Address
    // UART break condition for next data transmitted (bits: 0)
    ,BK_TX_MASK = 0x00000001
    ,BK_TX_POS = 0
    ,BK_TX_NORMAL = 0x00000000 
    ,BK_TX_SEND = 0x00000001 // Send Break
    ,CR2_MASK = 0x0601001F
    ;
  };
  // URT control register 3
  struct CR3 : reg<ip_ver, base + 0x1C, 0x00000A00>
  {
    static constexpr typename CR3::type
    // UART TX guard time or idle-line length (bits: 23-16)
     TXGT_LEN_MASK = 0x00FF0000
    ,TXGT_LEN_POS = 16
    // UART idle line detect threshold value by using receive bit time (bits: 15-8)
    ,DET_IDL_MASK = 0x0000FF00
    ,DET_IDL_POS = 8
    // UART bit time select for break detection or transmission (bits: 4)
    ,DET_BK_MASK = 0x00000010
    ,DET_BK_POS = 4
    ,DET_BK_1BIT = 0x00000000 
    ,DET_BK_3BIT = 0x00000010 
    // UART clock phase select (bits: 2)
    ,CPHA_MASK = 0x00000004
    ,CPHA_POS = 2
    ,CPHA_LEADING_EDGE = 0x00000000 
    ,CPHA_TRAILING_EDGE = 0x00000004 
    // UART clock polarity select. It is used to select the SPI clock level in idle state (bits: 1)
    ,CPOL_MASK = 0x00000002
    ,CPOL_POS = 1
    ,CPOL_LOW = 0x00000000 
    ,CPOL_HIGH = 0x00000002 
    ,CR3_MASK = 0x00FFFF16
    ;
  };
  // URT control register 4
  struct CR4 : reg<ip_ver, base + 0x20>
  {
    static constexpr typename CR4::type
    // UART remained data byte number in data register. Value 0~4 is valid only (bits: 14-12)
     TNUM_MASK = 0x00007000
    ,TNUM_POS = 12
    ,TNUM_0 = 0x00000000 // 0-byte
    ,TNUM_1 = 0x00001000 // 1-byte
    ,TNUM_2 = 0x00002000 // 2-byte
    ,TNUM_3 = 0x00003000 // 3-byte
    ,TNUM_4 = 0x00004000 // 4-byte
    // UART received data byte number when data shadow buffer last transfer to URTx_RDAT reg (bits: 10-8)
    ,RNUM_MASK = 0x00000700
    ,RNUM_POS = 8
    ,RNUM_0 = 0x00000000 // 0-byte
    ,RNUM_1 = 0x00000100 // 1-byte
    ,RNUM_2 = 0x00000200 // 2-byte
    ,RNUM_3 = 0x00000300 // 3-byte
    ,RNUM_4 = 0x00000400 // 4-byte
    // UART transmitted data clear enable (bits: 7)
    ,TDAT_CLR_MASK = 0x00000080
    ,TDAT_CLR_POS = 7
    ,TDAT_CLR_DISABLE = 0x00000000 
    ,TDAT_CLR_ENABLE = 0x00000080 
    // UART received data clear enable (bits: 6)
    ,RDAT_CLR_MASK = 0x00000040
    ,RDAT_CLR_POS = 6
    ,RDAT_CLR_DISABLE = 0x00000000 
    ,RDAT_CLR_ENABLE = 0x00000040 
    // UART inverse transmitted data enable (bits: 5)
    ,TDAT_INV_MASK = 0x00000020
    ,TDAT_INV_POS = 5
    ,TDAT_INV_DISABLE = 0x00000000 
    ,TDAT_INV_ENABLE = 0x00000020 
    // UART inverse received data enable (bits: 4)
    ,RDAT_INV_MASK = 0x00000010
    ,RDAT_INV_POS = 4
    ,RDAT_INV_DISABLE = 0x00000000 
    ,RDAT_INV_ENABLE = 0x00000010 
    ,CR4_MASK = 0x000077F0
    ;
  };
  // URT baud-rate clock counter reload register
  struct RLR : reg<ip_ver, base + 0x24>
  {
    static constexpr typename RLR::type
    // UART baud-rate clock prescaler reload register (bits: 11-8)
     PSR_MASK = 0x00000F00
    ,PSR_POS = 8
    // UART baud-rate clock counter reload register (bits: 7-0)
    ,RLRVAL_MASK = 0x000000FF
    ,RLRVAL_POS = 0
    ,RLR_MASK = 0x00000FFF
    ;
  };
  // URT1 baud-rate clock counter register
  struct CNT : reg<ip_ver, base + 0x28>
  {
    static constexpr typename CNT::type
    // UART baud-rate clock prescaler value register (bits: 11-8)
     PSC_MASK = 0x00000F00
    ,PSC_POS = 8
    // UART baud-rate clock counter value register (bits: 7-0)
    ,CNTVAL_MASK = 0x000000FF
    ,CNTVAL_POS = 0
    ,CNT_MASK = 0x00000FFF
    ;
  };
  // URT RX data capture register
  struct RCAP : reg<ip_ver, base + 0x2C>
  {
    static constexpr typename RCAP::type
    // UART capture address bit from RX shift buffer (bits: 10)
     RCAP_ADR_MASK = 0x00000400
    ,RCAP_ADR_POS = 10
    ,RCAP_ADR = 0x00000400
    // UART capture parity bit from RX shift buffer (bits: 9)
    ,RCAP_PAR_MASK = 0x00000200
    ,RCAP_PAR_POS = 9
    ,RCAP_PAR = 0x00000200
    // UART capture stop bit from RX shift buffer (bits: 8)
    ,RCAP_STP_MASK = 0x00000100
    ,RCAP_STP_POS = 8
    ,RCAP_STP = 0x00000100
    // UART capture data from RX shift buffer for Parity error / Frame error / Break detect (bits: 7-0)
    ,RCAP_DAT_MASK = 0x000000FF
    ,RCAP_DAT_POS = 0
    ,RCAP_MASK = 0x000007FF
    ;
  };
  // URT1 RX data register
  struct RDAT : reg<ip_ver, base + 0x30>
  {
    static constexpr typename RDAT::type
    // UART received data register (bits: 31-0)
     RDATVAL_MASK = 0xFFFFFFFF
    ,RDATVAL_POS = 0
    ,RDAT_MASK = 0xFFFFFFFF
    ;
  };
  // URT TX data register
  struct TDAT8 : reg<ip_ver, base + 0x34, 0x00000000, 1, 8>
  {
    static constexpr typename TDAT8::type
    // UART transmitted data register (1 byte) (bits: 7-0)
     TDAT_MASK = 0x000000FF
    ,TDAT_POS = 0
    ,TDAT8_MASK = 0x000000FF
    ;
  };
  // URT TX data register
  struct TDAT16 : reg<ip_ver, base + 0x34, 0x00000000, 1, 16>
  {
    static constexpr typename TDAT16::type
    // UART transmitted data register (2 bytes) (bits: 15-0)
     TDAT_MASK = 0x0000FFFF
    ,TDAT_POS = 0
    ,TDAT16_MASK = 0x0000FFFF
    ;
  };
  // URT TX data register
  struct TDAT32 : reg<ip_ver, base + 0x34>
  {
    static constexpr typename TDAT32::type
    // UART transmitted data register (4 bytes) (bits: 31-0)
     TDAT_MASK = 0xFFFFFFFF
    ,TDAT_POS = 0
    ,TDAT32_MASK = 0xFFFFFFFF
    ;
  };
  // URT TX data 3-byte register
  struct TDAT3 : reg<ip_ver, base + 0x38>
  {
    static constexpr typename TDAT3::type
    // UART transmitted data register for 3-byte data write only (bits: 23-0)
     TDAT3VAL_MASK = 0x00FFFFFF
    ,TDAT3VAL_POS = 0
    ,TDAT3_MASK = 0x00FFFFFF
    ;
  };
  // URT data shift buffer register
  struct SBUF : reg<ip_ver, base + 0x3C>
  {
    static constexpr typename SBUF::type
    // UART TX data shift buffer register (bits: 15-8)
     TSBUF_MASK = 0x0000FF00
    ,TSBUF_POS = 8
    // UART RX data shift buffer register (bits: 7-0)
    ,RSBUF_MASK = 0x000000FF
    ,RSBUF_POS = 0
    ,SBUF_MASK = 0x0000FFFF
    ;
  };
  // URT timeout control register
  struct TMOUT : reg<ip_ver, base + 0x40>
  {
    static constexpr typename TMOUT::type
    // UART calibration timeout detect threshold value for TMO counter value comparison (bits: 31-28)
     CALTMO_TH_MASK = 0xF0000000
    ,CALTMO_TH_POS = 28
    // UART receive Break timeout detect threshold value by using receive bit time (bits: 27-24)
    ,BKTMO_TH_MASK = 0x0F000000
    ,BKTMO_TH_POS = 24
    // UART RX data buffer timeout detect threshold value by using receive bit time (bits: 23-16)
    ,RXTMO_TH_MASK = 0x00FF0000
    ,RXTMO_TH_POS = 16
    // UART timeout timer timeout signal initial state control (bits: 15)
    ,TMO_LCK_MASK = 0x00008000
    ,TMO_LCK_POS = 15
    ,TMO_LCK_LOCKED = 0x00000000 
    ,TMO_LCK_UN_LOCKED = 0x00008000 
    // UART timeout timer timeout signal initial state (bits: 14)
    ,TMO_STA_MASK = 0x00004000
    ,TMO_STA_POS = 14
    ,TMO_STA_0 = 0x00000000 // Output 0
    ,TMO_STA_1 = 0x00004000 // Output 1
    // UART timeout timer clock source select (bits: 10-8)
    ,TMO_CKS_MASK = 0x00000700
    ,TMO_CKS_POS = 8
    ,TMO_CKS_UART = 0x00000000 // CK_URTx_BIT clock
    ,TMO_CKS_INPUT = 0x00000100 // CK_UART clock input)
    ,TMO_CKS_NOISE = 0x00000200 // Noise bit receive event
    // UART Calibration timeout detection enable bit (bits: 7)
    ,CALTMO_EN_MASK = 0x00000080
    ,CALTMO_EN_POS = 7
    ,CALTMO_EN_DISABLE = 0x00000000 
    ,CALTMO_EN_ENABLE = 0x00000080 
    // UART Break timeout detection enable bit (bits: 6)
    ,BKTMO_EN_MASK = 0x00000040
    ,BKTMO_EN_POS = 6
    ,BKTMO_EN_DISABLE = 0x00000000 
    ,BKTMO_EN_ENABLE = 0x00000040 
    // UART RX timeout enable bit for shadow buffer data loading into URTx_RDAT (bits: 5)
    ,RXTMO_EN_MASK = 0x00000020
    ,RXTMO_EN_POS = 5
    ,RXTMO_EN_DISABLE = 0x00000000 
    ,RXTMO_EN_ENABLE = 0x00000020 
    // UART Idle timeout detection enable bit (bits: 4)
    ,IDTMO_EN_MASK = 0x00000010
    ,IDTMO_EN_POS = 4
    ,IDTMO_EN_DISABLE = 0x00000000 
    ,IDTMO_EN_ENABLE = 0x00000010 
    // UART timeout timer mode select (bits: 3-2)
    ,TMO_MDS_MASK = 0x0000000C
    ,TMO_MDS_POS = 2
    ,TMO_MDS_UART = 0x00000000 // UART timeout timer
    ,TMO_MDS_GENERAL = 0x00000004 // general timer
    // UART timeout timer force reset enable. (set by software and clear by hardware) (bits: 1)
    ,TMO_RST_MASK = 0x00000002
    ,TMO_RST_POS = 1
    ,TMO_RST_DISABLE = 0x00000000 
    ,TMO_RST_ENABLE = 0x00000002 
    // UART timeout timer enable (bits: 0)
    ,TMO_EN_MASK = 0x00000001
    ,TMO_EN_POS = 0
    ,TMO_EN_DISABLE = 0x00000000 
    ,TMO_EN_ENABLE = 0x00000001 
    ,TMOUT_MASK = 0xFFFFC7FF
    ;
  };
  // URT timeout control register 2
  struct TMOUT2 : reg<ip_ver, base + 0x44>
  {
    static constexpr typename TMOUT2::type
    // UART timeout counter value (bits: 31-16)
     TMO_CNT_MASK = 0xFFFF0000
    ,TMO_CNT_POS = 16
    // UART receive idle timeout detect threshold value by using receive bit time (bits: 15-0)
    ,IDTMO_TH_MASK = 0x0000FFFF
    ,IDTMO_TH_POS = 0
    ,TMOUT2_MASK = 0xFFFFFFFF
    ;
  };
  // URT SmartCard control register
  struct SC : reg<ip_ver, base + 0x48>
  {
    static constexpr typename SC::type
    // UART RX parity error detect and NACK transmission retry maximum number (bits: 14-12)
     RXE_NUM_MASK = 0x00007000
    ,RXE_NUM_POS = 12
    // UART TX error detect and data resend maximum number (bits: 10-8)
    ,TXE_NUM_MASK = 0x00000700
    ,TXE_NUM_POS = 8
    // UART RX parity error detect and NACK transmission (bits: 4)
    ,RXE_LEN_MASK = 0x00000010
    ,RXE_LEN_POS = 4
    ,RXE_LEN_1BIT = 0x00000000 
    ,RXE_LEN_2BIT = 0x00000010 
    // UART TX error detect mode select (bits: 3-2)
    ,TXE_MDS_MASK = 0x0000000C
    ,TXE_MDS_POS = 2
    ,TXE_MDS_DISABLE = 0x00000000 
    ,TXE_MDS_CHK_LOW = 0x00000004 // check asserted low by RX device (for SmartCard)
    ,TXE_MDS_CHK_TX = 0x00000008 // check TX data by RX input data (for LIN mode)
    // UART RX parity error detect control mode select (bits: 1-0)
    ,RXE_MDS_MASK = 0x00000003
    ,RXE_MDS_POS = 0
    ,RXE_MDS_DISABLE = 0x00000000 
    ,RXE_MDS_ENABLE = 0x00000001 // hardware RX auto retry number by setting URTx_RXE_NUM
    ,RXE_MDS_AUTO = 0x00000002 // hardware RX auto retry always unless receiving parity correct character
    ,SC_MASK = 0x0000771F
    ;
  };
  // URT slave address detect register
  struct SADR : reg<ip_ver, base + 0x4C>
  {
    static constexpr typename SADR::type
    // UART multi-processor slave address mask register (bits: 15-8)
     SA_MSK_MASK = 0x0000FF00
    ,SA_MSK_POS = 8
    // UART multi-processor mode received slave address (bits: 7-0)
    ,SA_RX_MASK = 0x000000FF
    ,SA_RX_POS = 0
    ,SADR_MASK = 0x0000FFFF
    ;
  };
  // URT calibration control register
  struct CAL : reg<ip_ver, base + 0x50>
  {
    static constexpr typename CAL::type
    // UART auto baud-rate calibration complete data receive hold enable (bits: 7)
     CALC_HE_MASK = 0x00000080
    ,CALC_HE_POS = 7
    ,CALC_HE_DISABLE = 0x00000000 
    ,CALC_HE_ENABLE = 0x00000080 
    // UART auto baud-rate calibration mode select (bits: 3-2)
    ,CAL_MDS_MASK = 0x0000000C
    ,CAL_MDS_POS = 2
    ,CAL_MDS_START = 0x00000000 // measure the start bit
    ,CAL_MDS_EDGE = 0x00000004 // measure start falling edge to next falling edge
    // UART Break detection and auto baud-rate calibration enable (bits: 1)
    ,CAL_AUTO_MASK = 0x00000002
    ,CAL_AUTO_POS = 1
    ,CAL_AUTO_DISABLE = 0x00000000 
    ,CAL_AUTO_ENABLE = 0x00000002 
    // UART baud-rate calibration enable (bits: 0)
    ,CAL_EN_MASK = 0x00000001
    ,CAL_EN_POS = 0
    ,CAL_EN_DISABLE = 0x00000000 
    ,CAL_EN_ENABLE = 0x00000001 
    ,CAL_MASK = 0x0000008F
    ;
  };
  // URT IrDA control register
  struct IRDA : reg<ip_ver, base + 0x54, 0x00000300>
  {
    static constexpr typename IRDA::type
    // UART IrDA output pulse width select (bits: 11-8)
     IR_PW_MASK = 0x00000F00
    ,IR_PW_POS = 8
    // UART IrDA data received mode select (bits: 1)
    ,IR_MDS_MASK = 0x00000002
    ,IR_MDS_POS = 1
    ,IR_MDS_NORMAL = 0x00000000 
    ,IR_MDS_WIDE = 0x00000002 
    // UART IrDA data format enable (bits: 0)
    ,IR_EN_MASK = 0x00000001
    ,IR_EN_POS = 0
    ,IR_EN_DISABLE = 0x00000000 
    ,IR_EN_ENABLE = 0x00000001 
    ,IRDA_MASK = 0x00000F03
    ;
  };
  // URT hardware flow control register
  struct HFC : reg<ip_ver, base + 0x58>
  {
    static constexpr typename HFC::type
    // URTx_RTS output control data bit. This bit is no effect when URTx_RTS_EN is set (bits: 4)
     RTS_OUT_MASK = 0x00000010
    ,RTS_OUT_POS = 4
    ,RTS_OUT_0 = 0x00000000 // Output 0
    ,RTS_OUT_1 = 0x00000010 // Output 1
    // URTx_RTS output inverse enable (bits: 3)
    ,RTS_INV_MASK = 0x00000008
    ,RTS_INV_POS = 3
    ,RTS_INV_DISABLE = 0x00000000 
    ,RTS_INV_ENABLE = 0x00000008 
    // URTx_CTS input inverse enable (bits: 2)
    ,CTS_INV_MASK = 0x00000004
    ,CTS_INV_POS = 2
    ,CTS_INV_DISABLE = 0x00000000 
    ,CTS_INV_ENABLE = 0x00000004 
    // UART RTS hardware flow control enable (bits: 1)
    ,RTS_EN_MASK = 0x00000002
    ,RTS_EN_POS = 1
    ,RTS_EN_DISABLE = 0x00000000 
    ,RTS_EN_ENABLE = 0x00000002 
    // UART CTS hardware flow control enable (bits: 0)
    ,CTS_EN_MASK = 0x00000001
    ,CTS_EN_POS = 0
    ,CTS_EN_DISABLE = 0x00000000 
    ,CTS_EN_ENABLE = 0x00000001 
    ,HFC_MASK = 0x0000001F
    ;
  };
  // URT mute control register
  struct MUTE : reg<ip_ver, base + 0x5C, 0x00010100>
  {
    static constexpr typename MUTE::type
    // UART auto exit mute mode and receive data by idle line detection enable bit (bits: 18)
     MUTE_AEX2_MASK = 0x00040000
    ,MUTE_AEX2_POS = 18
    ,MUTE_AEX2_DISABLE = 0x00000000 
    ,MUTE_AEX2_ENABLE = 0x00040000 
    // UART auto exit mute mode and receive data by Break condition detection enable bit (bits: 17)
    ,MUTE_AEX1_MASK = 0x00020000
    ,MUTE_AEX1_POS = 17
    ,MUTE_AEX1_DISABLE = 0x00000000 
    ,MUTE_AEX1_ENABLE = 0x00020000 
    // UART auto exit mute mode and receive data by multi-processor slave address matched co (bits: 16)
    ,MUTE_AEX0_MASK = 0x00010000
    ,MUTE_AEX0_POS = 16
    ,MUTE_AEX0_DISABLE = 0x00000000 
    ,MUTE_AEX0_ENABLE = 0x00010000 
    // UART mute mode auto enter by idle line detection enable bit (bits: 9)
    ,MUTE_AEN1_MASK = 0x00000200
    ,MUTE_AEN1_POS = 9
    ,MUTE_AEN1_DISABLE = 0x00000000 
    ,MUTE_AEN1_ENABLE = 0x00000200 
    // UART mute mode auto enter by multi-processor slave address unmatched condition enable (bits: 8)
    ,MUTE_AEN0_MASK = 0x00000100
    ,MUTE_AEN0_POS = 8
    ,MUTE_AEN0_DISABLE = 0x00000000 
    ,MUTE_AEN0_ENABLE = 0x00000100 
    // UART mute mode enable (bits: 0)
    ,MUTE_EN_MASK = 0x00000001
    ,MUTE_EN_POS = 0
    ,MUTE_EN_DISABLE = 0x00000000 
    ,MUTE_EN_ENABLE = 0x00000001 
    ,MUTE_MASK = 0x00070301
    ;
  };
}; // struct URT

} // namespace lmcu::device::ip::v1

