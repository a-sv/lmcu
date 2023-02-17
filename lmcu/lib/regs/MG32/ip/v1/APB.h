/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// APB Module Global Control
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct APB
{
  static constexpr auto ip_ver = ip_version::_1;

  // APB status register
  struct STA : reg<ip_ver, base + 0x0, 0x03000000>
  {
    static constexpr typename STA::type
    // OBM-1 break switching signal status (bits: 25)
     OBM1_SW_MASK = 0x02000000
    ,OBM1_SW_POS = 25
    ,OBM1_SW = 0x02000000
    // OBM-0 break switching signal status (bits: 24)
    ,OBM0_SW_MASK = 0x01000000
    ,OBM0_SW_POS = 24
    ,OBM0_SW = 0x01000000
    // OBM-1 output signal status (bits: 17)
    ,OBM1_OUT_MASK = 0x00020000
    ,OBM1_OUT_POS = 17
    ,OBM1_OUT = 0x00020000
    // OBM-0 output signal status (bits: 16)
    ,OBM0_OUT_MASK = 0x00010000
    ,OBM0_OUT_POS = 16
    ,OBM0_OUT = 0x00010000
    // OBM-1 break trigger event detect flag (bits: 9)
    ,OBM1F_MASK = 0x00000200
    ,OBM1F_POS = 9
    ,OBM1F_NORMAL = 0x00000000 // No event occurred
    ,OBM1F_HAPPENED = 0x00000200 // reset event happened
    // OBM-0 break trigger event detect flag (bits: 8)
    ,OBM0F_MASK = 0x00000100
    ,OBM0F_POS = 8
    ,OBM0F_NORMAL = 0x00000000 // No event occurred
    ,OBM0F_HAPPENED = 0x00000100 // reset event happened
    ,STA_MASK = 0x03030300
    ;
  };
  // APB interrupt enable register
  struct INT : reg<ip_ver, base + 0x4>
  {
    static constexpr typename INT::type
    // OBM-1 break trigger event detect interrupt enable (bits: 9)
     OBM1_IE_MASK = 0x00000200
    ,OBM1_IE_POS = 9
    ,OBM1_IE_DISABLE = 0x00000000 
    ,OBM1_IE_ENABLE = 0x00000200 
    // OBM-0 break trigger event detect interrupt enable (bits: 8)
    ,OBM0_IE_MASK = 0x00000100
    ,OBM0_IE_POS = 8
    ,OBM0_IE_DISABLE = 0x00000000 
    ,OBM0_IE_ENABLE = 0x00000100 
    // APB interrupt all enable (bits: 0)
    ,IEA_MASK = 0x00000001
    ,IEA_POS = 0
    ,IEA_DISABLE = 0x00000000 
    ,IEA_ENABLE = 0x00000001 
    ,INT_MASK = 0x00000301
    ;
  };
  // APB global control register 0
  struct CR0 : reg<ip_ver, base + 0x10>
  {
    static constexpr typename CR0::type
    // General purpose data register bits (bits: 23-16)
     GPR_MASK = 0x00FF0000
    ,GPR_POS = 16
    // IR data envelope signal source select (bits: 14-12)
    ,IRDAT_MUX_MASK = 0x00007000
    ,IRDAT_MUX_POS = 12
    ,IRDAT_MUX_DAT0 = 0x00000000 // Output 0
    ,IRDAT_MUX_DAT1 = 0x00001000 
    ,IRDAT_MUX_DAT2 = 0x00002000 
    ,IRDAT_MUX_DAT3 = 0x00003000 
    ,IRDAT_MUX_DAT4 = 0x00004000 
    ,IRDAT_MUX_DAT5 = 0x00005000 
    ,IRDAT_MUX_DAT6 = 0x00006000 
    ,IRDAT_MUX_DAT7 = 0x00007000 
    // IR carrier clock source select (bits: 10-8)
    ,IRCLK_MUX_MASK = 0x00000700
    ,IRCLK_MUX_POS = 8
    ,IRCLK_MUX_CLK0 = 0x00000000 // Output 0
    ,IRCLK_MUX_CLK1 = 0x00000100 
    ,IRCLK_MUX_CLK2 = 0x00000200 
    ,IRCLK_MUX_CLK3 = 0x00000300 
    ,IRCLK_MUX_CLK4 = 0x00000400 
    ,IRCLK_MUX_CLK5 = 0x00000500 
    ,IRCLK_MUX_CLK6 = 0x00000600 
    ,IRCLK_MUX_CLK7 = 0x00000700 
    // IR data envelope signal inverse enable bit (bits: 5)
    ,IRDAT_INV_MASK = 0x00000020
    ,IRDAT_INV_POS = 5
    ,IRDAT_INV_DISABLE = 0x00000000 
    ,IRDAT_INV_ENABLE = 0x00000020 
    // IR clock signal inverse enable bit (bits: 4)
    ,IRCLK_INV_MASK = 0x00000010
    ,IRCLK_INV_POS = 4
    ,IRCLK_INV_DISABLE = 0x00000000 
    ,IRCLK_INV_ENABLE = 0x00000010 
    ,CR0_MASK = 0x00FF7730
    ;
  };
  // APB global control register 1
  struct CR1 : reg<ip_ver, base + 0x14>
  {
    static constexpr typename CR1::type
    // TM36 2nd Timer/Counter enable bit (bits: 31)
     TM36_EN2_MASK = 0x80000000
    ,TM36_EN2_POS = 31
    ,TM36_EN2_NO = 0x00000000 // No effect
    ,TM36_EN2_ENABLE = 0x80000000 
    // TM16 2nd Timer/Counter enable bit (bits: 23)
    ,TM16_EN2_MASK = 0x00800000
    ,TM16_EN2_POS = 23
    ,TM16_EN2_NO = 0x00000000 // No effect
    ,TM16_EN2_ENABLE = 0x00800000 
    // TM10 2nd Timer/Counter enable bit (bits: 20)
    ,TM10_EN2_MASK = 0x00100000
    ,TM10_EN2_POS = 20
    ,TM10_EN2_NO = 0x00000000 // No effect
    ,TM10_EN2_ENABLE = 0x00100000 
    // TM01 2nd Timer/Counter enable bit (bits: 17)
    ,TM01_EN2_MASK = 0x00020000
    ,TM01_EN2_POS = 17
    ,TM01_EN2_NO = 0x00000000 // No effect
    ,TM01_EN2_ENABLE = 0x00020000 
    // TM00 2nd Timer/Counter enable bit (bits: 16)
    ,TM00_EN2_MASK = 0x00010000
    ,TM00_EN2_POS = 16
    ,TM00_EN2_NO = 0x00000000 // No effect
    ,TM00_EN2_ENABLE = 0x00010000 
    // TM36 main Timer/Counter enable bit (bits: 15)
    ,TM36_EN_MASK = 0x00008000
    ,TM36_EN_POS = 15
    ,TM36_EN_NO = 0x00000000 // No effect
    ,TM36_EN_ENABLE = 0x00008000 
    // TM16 main Timer/Counter enable bit (bits: 7)
    ,TM16_EN_MASK = 0x00000080
    ,TM16_EN_POS = 7
    ,TM16_EN_NO = 0x00000000 // No effect
    ,TM16_EN_ENABLE = 0x00000080 
    // TM10 main Timer/Counter enable bit (bits: 4)
    ,TM10_EN_MASK = 0x00000010
    ,TM10_EN_POS = 4
    ,TM10_EN_NO = 0x00000000 // No effect
    ,TM10_EN_ENABLE = 0x00000010 
    // TM01 main Timer/Counter enable bit (bits: 1)
    ,TM01_EN_MASK = 0x00000002
    ,TM01_EN_POS = 1
    ,TM01_EN_NO = 0x00000000 // No effect
    ,TM01_EN_ENABLE = 0x00000002 
    // TM00 main Timer/Counter enable bit (bits: 0)
    ,TM00_EN_MASK = 0x00000001
    ,TM00_EN_POS = 0
    ,TM00_EN_NO = 0x00000000 // No effect
    ,TM00_EN_ENABLE = 0x00000001 
    ,CR1_MASK = 0x80938093
    ;
  };
  // APB global control register 2
  struct CR2 : reg<ip_ver, base + 0x18>
  {
    static constexpr typename CR2::type
    // Timer internal common trigger source ITR7 source select (bits: 7-4)
     ITR7_MUX_MASK = 0x000000F0
    ,ITR7_MUX_POS = 4
    ,ITR7_MUX_TRG0 = 0x00000000 
    ,ITR7_MUX_TRG1 = 0x00000010 
    ,ITR7_MUX_TRG2 = 0x00000020 
    ,ITR7_MUX_TRG3 = 0x00000030 
    ,ITR7_MUX_TRG4 = 0x00000040 
    ,ITR7_MUX_TRG5 = 0x00000050 
    ,ITR7_MUX_TRG6 = 0x00000060 
    ,ITR7_MUX_TRG7 = 0x00000070 
    ,ITR7_MUX_TRG8 = 0x00000080 
    ,ITR7_MUX_TRG9 = 0x00000090 
    ,ITR7_MUX_TRG10 = 0x000000A0 
    // Timer internal common trigger source ITR6 source select (bits: 2-0)
    ,ITR6_MUX_MASK = 0x00000007
    ,ITR6_MUX_POS = 0
    ,ITR6_MUX_TRG0 = 0x00000000 
    ,ITR6_MUX_TRG1 = 0x00000001 
    ,ITR6_MUX_TRG2 = 0x00000002 
    ,ITR6_MUX_TRG3 = 0x00000003 
    ,ITR6_MUX_TRG4 = 0x00000004 
    ,ITR6_MUX_TRG5 = 0x00000005 
    ,ITR6_MUX_TRG6 = 0x00000006 
    ,ITR6_MUX_TRG7 = 0x00000007 
    ,CR2_MASK = 0x000000F7
    ;
  };
  // APB OBM0 control register-0
  struct OBM00 : reg<ip_ver, base + 0x20>
  {
    static constexpr typename OBM00::type
    // OBM0 break signal source channel-2 select (bits: 27-24)
     OBM0_BKS2_MASK = 0x0F000000
    ,OBM0_BKS2_POS = 24
    ,OBM0_BKS2_BK0 = 0x00000000 // Output 1
    ,OBM0_BKS2_BK1 = 0x01000000 
    ,OBM0_BKS2_BK2 = 0x02000000 
    ,OBM0_BKS2_BK3 = 0x03000000 
    ,OBM0_BKS2_BK4 = 0x04000000 
    ,OBM0_BKS2_BK5 = 0x05000000 
    ,OBM0_BKS2_BK6 = 0x06000000 
    ,OBM0_BKS2_BK7 = 0x07000000 
    ,OBM0_BKS2_BK8 = 0x08000000 
    ,OBM0_BKS2_BK9 = 0x09000000 
    ,OBM0_BKS2_BK10 = 0x0A000000 
    ,OBM0_BKS2_BK11 = 0x0B000000 
    ,OBM0_BKS2_BK12 = 0x0C000000 
    ,OBM0_BKS2_BK13 = 0x0D000000 
    ,OBM0_BKS2_BK14 = 0x0E000000 
    ,OBM0_BKS2_BK15 = 0x0F000000 
    // OBM0 break signal source channel-1 select (bits: 23-20)
    ,OBM0_BKS1_MASK = 0x00F00000
    ,OBM0_BKS1_POS = 20
    ,OBM0_BKS1_BK0 = 0x00000000 // Output 1
    ,OBM0_BKS1_BK1 = 0x00100000 
    ,OBM0_BKS1_BK2 = 0x00200000 
    ,OBM0_BKS1_BK3 = 0x00300000 
    ,OBM0_BKS1_BK4 = 0x00400000 
    ,OBM0_BKS1_BK5 = 0x00500000 
    ,OBM0_BKS1_BK6 = 0x00600000 
    ,OBM0_BKS1_BK7 = 0x00700000 
    ,OBM0_BKS1_BK8 = 0x00800000 
    ,OBM0_BKS1_BK9 = 0x00900000 
    ,OBM0_BKS1_BK10 = 0x00A00000 
    ,OBM0_BKS1_BK11 = 0x00B00000 
    ,OBM0_BKS1_BK12 = 0x00C00000 
    ,OBM0_BKS1_BK13 = 0x00D00000 
    ,OBM0_BKS1_BK14 = 0x00E00000 
    ,OBM0_BKS1_BK15 = 0x00F00000 
    // OBM0 break signal source channel-0 select (bits: 19-16)
    ,OBM0_BKS0_MASK = 0x000F0000
    ,OBM0_BKS0_POS = 16
    ,OBM0_BKS0_BK0 = 0x00000000 // Output 1
    ,OBM0_BKS0_BK1 = 0x00010000 
    ,OBM0_BKS0_BK2 = 0x00020000 
    ,OBM0_BKS0_BK3 = 0x00030000 
    ,OBM0_BKS0_BK4 = 0x00040000 
    ,OBM0_BKS0_BK5 = 0x00050000 
    ,OBM0_BKS0_BK6 = 0x00060000 
    ,OBM0_BKS0_BK7 = 0x00070000 
    ,OBM0_BKS0_BK8 = 0x00080000 
    ,OBM0_BKS0_BK9 = 0x00090000 
    ,OBM0_BKS0_BK10 = 0x000A0000 
    ,OBM0_BKS0_BK11 = 0x000B0000 
    ,OBM0_BKS0_BK12 = 0x000C0000 
    ,OBM0_BKS0_BK13 = 0x000D0000 
    ,OBM0_BKS0_BK14 = 0x000E0000 
    ,OBM0_BKS0_BK15 = 0x000F0000 
    // OBM0 break source-2 signal inverse enable bit (bits: 10)
    ,OBM0_BKN2_MASK = 0x00000400
    ,OBM0_BKN2_POS = 10
    ,OBM0_BKN2_DISABLE = 0x00000000 
    ,OBM0_BKN2_ENABLE = 0x00000400 
    // OBM0 break source-1 signal inverse enable bit (bits: 9)
    ,OBM0_BKN1_MASK = 0x00000200
    ,OBM0_BKN1_POS = 9
    ,OBM0_BKN1_DISABLE = 0x00000000 
    ,OBM0_BKN1_ENABLE = 0x00000200 
    // OBM0 break source-0 signal inverse enable bit (bits: 8)
    ,OBM0_BKN0_MASK = 0x00000100
    ,OBM0_BKN0_POS = 8
    ,OBM0_BKN0_DISABLE = 0x00000000 
    ,OBM0_BKN0_ENABLE = 0x00000100 
    // OBM0 break switching signal initial state write control (bits: 5)
    ,OBM0_LCK_MASK = 0x00000020
    ,OBM0_LCK_POS = 5
    ,OBM0_LCK_LOCKED = 0x00000000 
    ,OBM0_LCK_UN_LOCKED = 0x00000020 
    // OBM0 break switching signal initial state (bits: 4)
    ,OBM0_STA_MASK = 0x00000010
    ,OBM0_STA_POS = 4
    ,OBM0_STA_0 = 0x00000000 // Output 0
    ,OBM0_STA_1 = 0x00000010 // Output 1
    // OBM0 break operation mode select (bits: 1-0)
    ,OBM0_MDS_MASK = 0x00000003
    ,OBM0_MDS_POS = 0
    ,OBM0_MDS_AND = 0x00000000 // AND signal of all break channels' output
    ,OBM0_MDS_CLR = 0x00000001 // STA bit is cleared by falling edge of OR signal
    ,OBM0_MDS_SET = 0x00000002 // STA bit is set by falling edge of OR signal
    ,OBM0_MDS_TOGGLE = 0x00000003 // STA bit is toggle by falling edge of OR signal
    ,OBM00_MASK = 0x0FFF0733
    ;
  };
  // APB OBM0 control register-1
  struct OBM01 : reg<ip_ver, base + 0x24>
  {
    static constexpr typename OBM01::type
    // OBM0 output source channel-1 signal select (bits: 23-20)
     OBM0_MUX1_MASK = 0x00F00000
    ,OBM0_MUX1_POS = 20
    ,OBM0_MUX1_SR0 = 0x00000000 // Output 0
    ,OBM0_MUX1_SR1 = 0x00100000 
    ,OBM0_MUX1_SR2 = 0x00200000 
    ,OBM0_MUX1_SR3 = 0x00300000 
    ,OBM0_MUX1_SR4 = 0x00400000 
    ,OBM0_MUX1_SR5 = 0x00500000 
    ,OBM0_MUX1_SR6 = 0x00600000 
    ,OBM0_MUX1_SR7 = 0x00700000 
    ,OBM0_MUX1_SR8 = 0x00800000 
    ,OBM0_MUX1_SR9 = 0x00900000 
    ,OBM0_MUX1_SR10 = 0x00A00000 
    ,OBM0_MUX1_SR11 = 0x00B00000 
    ,OBM0_MUX1_SR12 = 0x00C00000 
    ,OBM0_MUX1_SR13 = 0x00D00000 
    ,OBM0_MUX1_SR14 = 0x00E00000 
    ,OBM0_MUX1_SR15 = 0x00F00000 
    // OBM0 output source channel-0 signal select (bits: 19-16)
    ,OBM0_MUX0_MASK = 0x000F0000
    ,OBM0_MUX0_POS = 16
    ,OBM0_MUX0_SR0 = 0x00000000 // Output 0
    ,OBM0_MUX0_SR1 = 0x00010000 
    ,OBM0_MUX0_SR2 = 0x00020000 
    ,OBM0_MUX0_SR3 = 0x00030000 
    ,OBM0_MUX0_SR4 = 0x00040000 
    ,OBM0_MUX0_SR5 = 0x00050000 
    ,OBM0_MUX0_SR6 = 0x00060000 
    ,OBM0_MUX0_SR7 = 0x00070000 
    ,OBM0_MUX0_SR8 = 0x00080000 
    ,OBM0_MUX0_SR9 = 0x00090000 
    ,OBM0_MUX0_SR10 = 0x000A0000 
    ,OBM0_MUX0_SR11 = 0x000B0000 
    ,OBM0_MUX0_SR12 = 0x000C0000 
    ,OBM0_MUX0_SR13 = 0x000D0000 
    ,OBM0_MUX0_SR14 = 0x000E0000 
    ,OBM0_MUX0_SR15 = 0x000F0000 
    // OBM0 output deglitch filter clock source select (bits: 5-4)
    ,OBM0_FCKS_MASK = 0x00000030
    ,OBM0_FCKS_POS = 4
    ,OBM0_FCKS_DISABLE = 0x00000000 
    ,OBM0_FCKS_APB = 0x00000010 // CLK_APB
    ,OBM0_FCKS_APB_DIV8 = 0x00000020 // CLK_APB divide by 8
    ,OBM0_FCKS_TM00_TRGO = 0x00000030 
    // OBM0 output signal inverse enable bit (bits: 2)
    ,OBM0_POL_MASK = 0x00000004
    ,OBM0_POL_POS = 2
    ,OBM0_POL_DISABLE = 0x00000000 
    ,OBM0_POL_ENABLE = 0x00000004 
    // OBM0 source channel-1 signal inverse enable bit (bits: 1)
    ,OBM0_INV1_MASK = 0x00000002
    ,OBM0_INV1_POS = 1
    ,OBM0_INV1_DISABLE = 0x00000000 
    ,OBM0_INV1_ENABLE = 0x00000002 
    // OBM0 source channel-0 signal inverse enable bit (bits: 0)
    ,OBM0_INV0_MASK = 0x00000001
    ,OBM0_INV0_POS = 0
    ,OBM0_INV0_DISABLE = 0x00000000 
    ,OBM0_INV0_ENABLE = 0x00000001 
    ,OBM01_MASK = 0x00FF0037
    ;
  };
  // APB OBM1 control register-0
  struct OBM10 : reg<ip_ver, base + 0x28>
  {
    static constexpr typename OBM10::type
    // OBM1 break signal source channel-2 select (bits: 27-24)
     OBM1_BKS2_MASK = 0x0F000000
    ,OBM1_BKS2_POS = 24
    ,OBM1_BKS2_BK0 = 0x00000000 // Output 1
    ,OBM1_BKS2_BK1 = 0x01000000 
    ,OBM1_BKS2_BK2 = 0x02000000 
    ,OBM1_BKS2_BK3 = 0x03000000 
    ,OBM1_BKS2_BK4 = 0x04000000 
    ,OBM1_BKS2_BK5 = 0x05000000 
    ,OBM1_BKS2_BK6 = 0x06000000 
    ,OBM1_BKS2_BK7 = 0x07000000 
    ,OBM1_BKS2_BK8 = 0x08000000 
    ,OBM1_BKS2_BK9 = 0x09000000 
    ,OBM1_BKS2_BK10 = 0x0A000000 
    ,OBM1_BKS2_BK11 = 0x0B000000 
    ,OBM1_BKS2_BK12 = 0x0C000000 
    ,OBM1_BKS2_BK13 = 0x0D000000 
    ,OBM1_BKS2_BK14 = 0x0E000000 
    ,OBM1_BKS2_BK15 = 0x0F000000 
    // OBM1 break signal source channel-1 select (bits: 23-20)
    ,OBM1_BKS1_MASK = 0x00F00000
    ,OBM1_BKS1_POS = 20
    ,OBM1_BKS1_BK0 = 0x00000000 // Output 1
    ,OBM1_BKS1_BK1 = 0x00100000 
    ,OBM1_BKS1_BK2 = 0x00200000 
    ,OBM1_BKS1_BK3 = 0x00300000 
    ,OBM1_BKS1_BK4 = 0x00400000 
    ,OBM1_BKS1_BK5 = 0x00500000 
    ,OBM1_BKS1_BK6 = 0x00600000 
    ,OBM1_BKS1_BK7 = 0x00700000 
    ,OBM1_BKS1_BK8 = 0x00800000 
    ,OBM1_BKS1_BK9 = 0x00900000 
    ,OBM1_BKS1_BK10 = 0x00A00000 
    ,OBM1_BKS1_BK11 = 0x00B00000 
    ,OBM1_BKS1_BK12 = 0x00C00000 
    ,OBM1_BKS1_BK13 = 0x00D00000 
    ,OBM1_BKS1_BK14 = 0x00E00000 
    ,OBM1_BKS1_BK15 = 0x00F00000 
    // OBM1 break signal source channel-0 select (bits: 19-16)
    ,OBM1_BKS0_MASK = 0x000F0000
    ,OBM1_BKS0_POS = 16
    ,OBM1_BKS0_BK0 = 0x00000000 // Output 1
    ,OBM1_BKS0_BK1 = 0x00010000 
    ,OBM1_BKS0_BK2 = 0x00020000 
    ,OBM1_BKS0_BK3 = 0x00030000 
    ,OBM1_BKS0_BK4 = 0x00040000 
    ,OBM1_BKS0_BK5 = 0x00050000 
    ,OBM1_BKS0_BK6 = 0x00060000 
    ,OBM1_BKS0_BK7 = 0x00070000 
    ,OBM1_BKS0_BK8 = 0x00080000 
    ,OBM1_BKS0_BK9 = 0x00090000 
    ,OBM1_BKS0_BK10 = 0x000A0000 
    ,OBM1_BKS0_BK11 = 0x000B0000 
    ,OBM1_BKS0_BK12 = 0x000C0000 
    ,OBM1_BKS0_BK13 = 0x000D0000 
    ,OBM1_BKS0_BK14 = 0x000E0000 
    ,OBM1_BKS0_BK15 = 0x000F0000 
    // OBM1 break source-2 signal inverse enable bit (bits: 10)
    ,OBM1_BKN2_MASK = 0x00000400
    ,OBM1_BKN2_POS = 10
    ,OBM1_BKN2_DISABLE = 0x00000000 
    ,OBM1_BKN2_ENABLE = 0x00000400 
    // OBM1 break source-1 signal inverse enable bit (bits: 9)
    ,OBM1_BKN1_MASK = 0x00000200
    ,OBM1_BKN1_POS = 9
    ,OBM1_BKN1_DISABLE = 0x00000000 
    ,OBM1_BKN1_ENABLE = 0x00000200 
    // OBM1 break source-0 signal inverse enable bit (bits: 8)
    ,OBM1_BKN0_MASK = 0x00000100
    ,OBM1_BKN0_POS = 8
    ,OBM1_BKN0_DISABLE = 0x00000000 
    ,OBM1_BKN0_ENABLE = 0x00000100 
    // OBM1 break switching signal initial state write control (bits: 5)
    ,OBM1_LCK_MASK = 0x00000020
    ,OBM1_LCK_POS = 5
    ,OBM1_LCK_LOCKED = 0x00000000 
    ,OBM1_LCK_UN_LOCKED = 0x00000020 
    // OBM1 break switching signal initial state (bits: 4)
    ,OBM1_STA_MASK = 0x00000010
    ,OBM1_STA_POS = 4
    ,OBM1_STA_0 = 0x00000000 // Output 0
    ,OBM1_STA_1 = 0x00000010 // Output 1
    // OBM1 break operation mode select (bits: 1-0)
    ,OBM1_MDS_MASK = 0x00000003
    ,OBM1_MDS_POS = 0
    ,OBM1_MDS_AND = 0x00000000 // AND signal of all break channels' output
    ,OBM1_MDS_CLR = 0x00000001 // STA bit is cleared by falling edge of OR signal
    ,OBM1_MDS_SET = 0x00000002 // STA bit is set by falling edge of OR signal
    ,OBM1_MDS_TOGGLE = 0x00000003 // STA bit is toggle by falling edge of OR signal
    ,OBM10_MASK = 0x0FFF0733
    ;
  };
  // APB OBM1 control register-1
  struct OBM11 : reg<ip_ver, base + 0x2C>
  {
    static constexpr typename OBM11::type
    // OBM1 output source channel-1 signal select (bits: 23-20)
     OBM1_MUX1_MASK = 0x00F00000
    ,OBM1_MUX1_POS = 20
    ,OBM1_MUX1_SR0 = 0x00000000 // Output 0
    ,OBM1_MUX1_SR1 = 0x00100000 
    ,OBM1_MUX1_SR2 = 0x00200000 
    ,OBM1_MUX1_SR3 = 0x00300000 
    ,OBM1_MUX1_SR4 = 0x00400000 
    ,OBM1_MUX1_SR5 = 0x00500000 
    ,OBM1_MUX1_SR6 = 0x00600000 
    ,OBM1_MUX1_SR7 = 0x00700000 
    ,OBM1_MUX1_SR8 = 0x00800000 
    ,OBM1_MUX1_SR9 = 0x00900000 
    ,OBM1_MUX1_SR10 = 0x00A00000 
    ,OBM1_MUX1_SR11 = 0x00B00000 
    ,OBM1_MUX1_SR12 = 0x00C00000 
    ,OBM1_MUX1_SR13 = 0x00D00000 
    ,OBM1_MUX1_SR14 = 0x00E00000 
    ,OBM1_MUX1_SR15 = 0x00F00000 
    // OBM1 output source channel-0 signal select (bits: 19-16)
    ,OBM1_MUX0_MASK = 0x000F0000
    ,OBM1_MUX0_POS = 16
    ,OBM1_MUX0_SR0 = 0x00000000 // Output 0
    ,OBM1_MUX0_SR1 = 0x00010000 
    ,OBM1_MUX0_SR2 = 0x00020000 
    ,OBM1_MUX0_SR3 = 0x00030000 
    ,OBM1_MUX0_SR4 = 0x00040000 
    ,OBM1_MUX0_SR5 = 0x00050000 
    ,OBM1_MUX0_SR6 = 0x00060000 
    ,OBM1_MUX0_SR7 = 0x00070000 
    ,OBM1_MUX0_SR8 = 0x00080000 
    ,OBM1_MUX0_SR9 = 0x00090000 
    ,OBM1_MUX0_SR10 = 0x000A0000 
    ,OBM1_MUX0_SR11 = 0x000B0000 
    ,OBM1_MUX0_SR12 = 0x000C0000 
    ,OBM1_MUX0_SR13 = 0x000D0000 
    ,OBM1_MUX0_SR14 = 0x000E0000 
    ,OBM1_MUX0_SR15 = 0x000F0000 
    // OBM1 output deglitch filter clock source select (bits: 5-4)
    ,OBM1_FCKS_MASK = 0x00000030
    ,OBM1_FCKS_POS = 4
    ,OBM1_FCKS_DISABLE = 0x00000000 
    ,OBM1_FCKS_APB = 0x00000010 // CLK_APB
    ,OBM1_FCKS_APB_DIV8 = 0x00000020 // CLK_APB divide by 8
    ,OBM1_FCKS_TM00_TRGO = 0x00000030 
    // OBM1 output signal inverse enable bit (bits: 2)
    ,OBM1_POL_MASK = 0x00000004
    ,OBM1_POL_POS = 2
    ,OBM1_POL_DISABLE = 0x00000000 
    ,OBM1_POL_ENABLE = 0x00000004 
    // OBM1 source channel-1 signal inverse enable bit (bits: 1)
    ,OBM1_INV1_MASK = 0x00000002
    ,OBM1_INV1_POS = 1
    ,OBM1_INV1_DISABLE = 0x00000000 
    ,OBM1_INV1_ENABLE = 0x00000002 
    // OBM1 source channel-0 signal inverse enable bit (bits: 0)
    ,OBM1_INV0_MASK = 0x00000001
    ,OBM1_INV0_POS = 0
    ,OBM1_INV0_DISABLE = 0x00000000 
    ,OBM1_INV0_ENABLE = 0x00000001 
    ,OBM11_MASK = 0x00FF0037
    ;
  };
}; // struct APB

} // namespace lmcu::device::ip::v1

