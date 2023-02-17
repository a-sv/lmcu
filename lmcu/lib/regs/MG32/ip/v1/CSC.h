/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// Clock Source Controller
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct CSC
{
  static constexpr auto ip_ver = ip_version::_1;

  // CSC status register
  struct STA : reg<ip_ver, base + 0x0, 0x00020000>
  {
    static constexpr typename STA::type
    // PLL clock stable and ready status after PLL enabled (bits: 31)
     PLL_STA_MASK = 0x80000000
    ,PLL_STA_POS = 31
    ,PLL_STA_UNREADY = 0x00000000 
    ,PLL_STA_READY = 0x80000000 
    // IHRCO clock stable and ready status after IHRCO enabled (bits: 30)
    ,IHRCO_STA_MASK = 0x40000000
    ,IHRCO_STA_POS = 30
    ,IHRCO_STA_UNREADY = 0x00000000 
    ,IHRCO_STA_READY = 0x40000000 
    // ILRCO clock stable and ready status after ILRCO enabled (bits: 29)
    ,ILRCO_STA_MASK = 0x20000000
    ,ILRCO_STA_POS = 29
    ,ILRCO_STA_UNREADY = 0x00000000 
    ,ILRCO_STA_READY = 0x20000000 
    // XOSC clock stable and ready status after XOSC enabled (bits: 28)
    ,XOSC_STA_MASK = 0x10000000
    ,XOSC_STA_POS = 28
    ,XOSC_STA_UNREADY = 0x00000000 
    ,XOSC_STA_READY = 0x10000000 
    // System main clock source select MUX switching status (bits: 26-24)
    ,MAIN_STA_MASK = 0x07000000
    ,MAIN_STA_POS = 24
    ,MAIN_STA_SWITCHING = 0x00000000 // MUX is switching and clock is not yet stable
    ,MAIN_STA_CK_HS = 0x01000000 // MUX has switched and clock is ready
    ,MAIN_STA_CK_PLLI = 0x02000000 // MUX has switched and clock is ready
    ,MAIN_STA_CK_PLLO = 0x04000000 // MUX has switched and clock is ready
    // Input high speed clock source select MUX switching status (bits: 23-20)
    ,HS_STA_MASK = 0x00F00000
    ,HS_STA_POS = 20
    ,HS_STA_SWITCHING = 0x00000000 // MUX is switching and clock is not yet stable
    ,HS_STA_IHRCO = 0x00100000 
    ,HS_STA_XOSC = 0x00200000 
    ,HS_STA_ILRCO = 0x00400000 
    ,HS_STA_CK_EXT = 0x00800000 
    // Input low speed clock source select MUX switching status (bits: 19-16)
    ,LS_STA_MASK = 0x000F0000
    ,LS_STA_POS = 16
    ,LS_STA_SWITCHING = 0x00000000 // MUX is switching and clock is not yet stable
    ,LS_STA_XOSC = 0x00020000 
    ,LS_STA_ILRCO = 0x00040000 
    ,LS_STA_CK_EXT = 0x00080000 
    // XOSC missing clock detect failure event flag (bits: 7)
    ,MCDF_MASK = 0x00000080
    ,MCDF_POS = 7
    ,MCDF_NORMAL = 0x00000000 // No event occurred
    ,MCDF_HAPPENED = 0x00000080 // Event happened
    // PLL clock stable and ready detect flag (bits: 6)
    ,PLLF_MASK = 0x00000040
    ,PLLF_POS = 6
    ,PLLF_NORMAL = 0x00000000 // No event occurred
    ,PLLF_HAPPENED = 0x00000040 // Event happened
    // IHRCO clock stable and ready detect flag (bits: 5)
    ,IHRCOF_MASK = 0x00000020
    ,IHRCOF_POS = 5
    ,IHRCOF_NORMAL = 0x00000000 // No event occurred
    ,IHRCOF_HAPPENED = 0x00000020 // Event happened
    // ILRCO clock stable and ready detect flag (bits: 4)
    ,ILRCOF_MASK = 0x00000010
    ,ILRCOF_POS = 4
    ,ILRCOF_NORMAL = 0x00000000 // No event occurred
    ,ILRCOF_HAPPENED = 0x00000010 // Event happened
    // XOSC clock stable and ready detect flag (bits: 1)
    ,XOSCF_MASK = 0x00000002
    ,XOSCF_POS = 1
    ,XOSCF_NORMAL = 0x00000000 // No event occurred
    ,XOSCF_HAPPENED = 0x00000002 // Event happened
    ,STA_MASK = 0xF7FF00F2
    ;
  };
  // CSC interrupt enable register
  struct INT : reg<ip_ver, base + 0x4>
  {
    static constexpr typename INT::type
    // XOSC missing clock detect failure event interrupt enable (bits: 7)
     MCD_IE_MASK = 0x00000080
    ,MCD_IE_POS = 7
    ,MCD_IE_DISABLE = 0x00000000 
    ,MCD_IE_ENABLE = 0x00000080 
    // PLL clock stable interrupt enable (bits: 6)
    ,PLL_IE_MASK = 0x00000040
    ,PLL_IE_POS = 6
    ,PLL_IE_DISABLE = 0x00000000 
    ,PLL_IE_ENABLE = 0x00000040 
    // IHRCO clock stable interrupt enable (bits: 5)
    ,IHRCO_IE_MASK = 0x00000020
    ,IHRCO_IE_POS = 5
    ,IHRCO_IE_DISABLE = 0x00000000 
    ,IHRCO_IE_ENABLE = 0x00000020 
    // ILRCO clock stable interrupt enable (bits: 4)
    ,ILRCO_IE_MASK = 0x00000010
    ,ILRCO_IE_POS = 4
    ,ILRCO_IE_DISABLE = 0x00000000 
    ,ILRCO_IE_ENABLE = 0x00000010 
    // XOSC clock stable interrupt enable (bits: 1)
    ,XOSC_IE_MASK = 0x00000002
    ,XOSC_IE_POS = 1
    ,XOSC_IE_DISABLE = 0x00000000 
    ,XOSC_IE_ENABLE = 0x00000002 
    // CSC interrupt all enable (bits: 0)
    ,IEA_MASK = 0x00000001
    ,IEA_POS = 0
    ,IEA_DISABLE = 0x00000000 
    ,IEA_ENABLE = 0x00000001 
    ,INT_MASK = 0x000000F3
    ;
  };
  // CSC OSC and PLL control register
  struct PLL : reg<ip_ver, base + 0x8>
  {
    static constexpr typename PLL::type
    // Gain control bits of XOSC. (The default value is loaded from CFG OR after Warm reset) (bits: 17-16)
     XOSC_GN_MASK = 0x00030000
    ,XOSC_GN_POS = 16
    ,XOSC_GN_32K_NORMAL = 0x00000000 // for 32KHz crystal
    ,XOSC_GN_MEDIUM = 0x00010000 
    ,XOSC_GN_32K_LOWEST = 0x00020000 // for 32KHz crystal
    // CSC PLL multiplication factor select (bits: 8)
    ,PLL_MUL_MASK = 0x00000100
    ,PLL_MUL_POS = 8
    ,PLL_MUL_16 = 0x00000000 // PLL input clock x 16
    ,PLL_MUL_24 = 0x00000100 // PLL input clock x 24
    ,PLL_MASK = 0x00030100
    ;
  };
  // CSC write protected Key register
  struct KEY : reg<ip_ver, base + 0xC, 0x00000001>
  {
    static constexpr typename KEY::type
    // CSC key register (bits: 15-0)
     KEYVAL_MASK = 0x0000FFFF
    ,KEYVAL_POS = 0
    ,KEY_MASK = 0x0000FFFF
    ;
  };
  // CSC clock source control register 0
  struct CR0 : reg<ip_ver, base + 0x10, 0x00000200>
  {
    static constexpr typename CR0::type
    // Missing clock detection duration select (bits: 23-22)
     MCD_SEL_MASK = 0x00C00000
    ,MCD_SEL_POS = 22
    ,MCD_SEL_125US = 0x00000000 
    ,MCD_SEL_250US = 0x00400000 
    ,MCD_SEL_500US = 0x00800000 
    ,MCD_SEL_1MS = 0x00C00000 
    // IHRCO clock frequency trimming set select (bits: 18)
    ,IHRCO_SEL_MASK = 0x00040000
    ,IHRCO_SEL_POS = 18
    ,IHRCO_SEL_12 = 0x00000000 // 12MHz from trimming set 0
    ,IHRCO_SEL_11 = 0x00040000 // 11.059MHz from trimming set 1
    // System tick timer external clock source select (bits: 16)
    ,ST_SEL_MASK = 0x00010000
    ,ST_SEL_POS = 16
    ,ST_SEL_HCLK8 = 0x00000000 // HCLK divided by 8
    ,ST_SEL_CK_LS2 = 0x00010000 // CK_LS divided by 2
    // System main clock source select (bits: 15-14)
    ,MAIN_SEL_MASK = 0x0000C000
    ,MAIN_SEL_POS = 14
    ,MAIN_SEL_CK_HS = 0x00000000 
    ,MAIN_SEL_CK_PLLI = 0x00004000 
    ,MAIN_SEL_CK_PLLO = 0x00008000 
    // Input high speed clock source select (bits: 11-10)
    ,HS_SEL_MASK = 0x00000C00
    ,HS_SEL_POS = 10
    ,HS_SEL_IHRCO = 0x00000000 
    ,HS_SEL_XOSC = 0x00000400 
    ,HS_SEL_ILRCO = 0x00000800 
    ,HS_SEL_CK_EXT = 0x00000C00 
    // Input low speed clock source select (bits: 9-8)
    ,LS_SEL_MASK = 0x00000300
    ,LS_SEL_POS = 8
    ,LS_SEL_XOSC = 0x00000100 
    ,LS_SEL_ILRCO = 0x00000200 
    ,LS_SEL_CK_EXT = 0x00000300 
    // PLL circuit enable (bits: 5)
    ,PLL_EN_MASK = 0x00000020
    ,PLL_EN_POS = 5
    ,PLL_EN_DISABLE = 0x00000000 
    ,PLL_EN_ENABLE = 0x00000020 
    // MCD missing clock detector circuit disable (bits: 4)
    ,MCD_DIS_MASK = 0x00000010
    ,MCD_DIS_POS = 4
    ,MCD_DIS_ENABLE = 0x00000000 
    ,MCD_DIS_DISABLE = 0x00000010 
    // IHRCO circuit enable (bits: 3)
    ,IHRCO_EN_MASK = 0x00000008
    ,IHRCO_EN_POS = 3
    ,IHRCO_EN_DISABLE = 0x00000000 
    ,IHRCO_EN_ENABLE = 0x00000008 
    ,CR0_MASK = 0x00C5CF38
    ;
  };
  // CSC clock divider register
  struct DIV : reg<ip_ver, base + 0x14>
  {
    static constexpr typename DIV::type
    // Unit time clock source divider (bits: 27-26)
     UT_DIV_MASK = 0x0C000000
    ,UT_DIV_POS = 26
    ,UT_DIV_DIV32 = 0x00000000 // divided by 32
    ,UT_DIV_DIV8 = 0x04000000 // divided by 8
    ,UT_DIV_DIV16 = 0x08000000 // divided by 16
    ,UT_DIV_DIV128 = 0x0C000000 // divided by 128
    // APB clock source divider. Value 0~4 mean to divide by 1,2,4,8,16 (bits: 18-16)
    ,APB_DIV_MASK = 0x00070000
    ,APB_DIV_POS = 16
    ,APB_DIV_DIV1 = 0x00000000 // divided by 1
    ,APB_DIV_DIV2 = 0x00010000 // divided by 2
    ,APB_DIV_DIV4 = 0x00020000 // divided by 4
    ,APB_DIV_DIV8 = 0x00030000 // divided by 8
    ,APB_DIV_DIV16 = 0x00040000 // divided by 16
    // AHB clock source divider. Value 0~9 mean to divide by 1,2,4,8,16,32,64,128,256,512 (bits: 11-8)
    ,AHB_DIV_MASK = 0x00000F00
    ,AHB_DIV_POS = 8
    ,AHB_DIV_DIV1 = 0x00000000 // divided by 1
    ,AHB_DIV_DIV2 = 0x00000100 // divided by 2
    ,AHB_DIV_DIV4 = 0x00000200 // divided by 4
    ,AHB_DIV_DIV8 = 0x00000300 // divided by 8
    ,AHB_DIV_DIV16 = 0x00000400 // divided by 16
    ,AHB_DIV_DIV32 = 0x00000500 // divided by 32
    ,AHB_DIV_DIV64 = 0x00000600 // divided by 64
    ,AHB_DIV_DIV128 = 0x00000700 // divided by 128
    ,AHB_DIV_DIV256 = 0x00000800 // divided by 256
    ,AHB_DIV_DIV512 = 0x00000900 // divided by 512
    // PLL output clock source divider (bits: 5-4)
    ,PLLO_DIV_MASK = 0x00000030
    ,PLLO_DIV_POS = 4
    ,PLLO_DIV_DIV4 = 0x00000000 // divided by 4
    ,PLLO_DIV_DIV3 = 0x00000010 // divided by 3
    ,PLLO_DIV_DIV2 = 0x00000020 // divided by 2
    ,PLLO_DIV_DIV1 = 0x00000030 // divided by 1
    // PLL input clock source divider (bits: 1-0)
    ,PLLI_DIV_MASK = 0x00000003
    ,PLLI_DIV_POS = 0
    ,PLLI_DIV_DIV1 = 0x00000000 // divided by 1
    ,PLLI_DIV_DIV2 = 0x00000001 // divided by 2
    ,PLLI_DIV_DIV4 = 0x00000002 // divided by 4
    ,PLLI_DIV_DIV6 = 0x00000003 // divided by 6
    ,DIV_MASK = 0x0C070F33
    ;
  };
  // CSC internal clock output control register
  struct CKO : reg<ip_ver, base + 0x18>
  {
    static constexpr typename CKO::type
    // Internal clock output source select (bits: 6-4)
     CKO_SEL_MASK = 0x00000070
    ,CKO_SEL_POS = 4
    ,CKO_SEL_CK_MAIN = 0x00000000 
    ,CKO_SEL_CK_AHB = 0x00000010 
    ,CKO_SEL_CK_APB = 0x00000020 
    ,CKO_SEL_CK_HS = 0x00000030 
    ,CKO_SEL_CK_LS = 0x00000040 
    ,CKO_SEL_CK_XOSC = 0x00000050 
    // Internal clock output divider (bits: 3-2)
    ,CKO_DIV_MASK = 0x0000000C
    ,CKO_DIV_POS = 2
    ,CKO_DIV_DIV1 = 0x00000000 // divided by 1
    ,CKO_DIV_DIV2 = 0x00000004 // divided by 2
    ,CKO_DIV_DIV4 = 0x00000008 // divided by 4
    ,CKO_DIV_DIV8 = 0x0000000C // divided by 8
    // Internal clock output enable. When enables, it will reset the output divider (bits: 0)
    ,CKO_EN_MASK = 0x00000001
    ,CKO_EN_POS = 0
    ,CKO_EN_DISABLE = 0x00000000 
    ,CKO_EN_ENABLE = 0x00000001 
    ,CKO_MASK = 0x0000007D
    ;
  };
  // CSC AHB clock control register
  struct AHB : reg<ip_ver, base + 0x1C>
  {
    static constexpr typename AHB::type
    // DMA clock source enable (bits: 15)
     DMA_EN_MASK = 0x00008000
    ,DMA_EN_POS = 15
    ,DMA_EN_DISABLE = 0x00000000 
    ,DMA_EN_ENABLE = 0x00008000 
    // GPL clock source enable (bits: 8)
    ,GPL_EN_MASK = 0x00000100
    ,GPL_EN_POS = 8
    ,GPL_EN_DISABLE = 0x00000000 
    ,GPL_EN_ENABLE = 0x00000100 
    // IO Port D clock source enable (bits: 3)
    ,IOPD_EN_MASK = 0x00000008
    ,IOPD_EN_POS = 3
    ,IOPD_EN_DISABLE = 0x00000000 
    ,IOPD_EN_ENABLE = 0x00000008 
    // IO Port C clock source enable (bits: 2)
    ,IOPC_EN_MASK = 0x00000004
    ,IOPC_EN_POS = 2
    ,IOPC_EN_DISABLE = 0x00000000 
    ,IOPC_EN_ENABLE = 0x00000004 
    // IO Port B clock source enable (bits: 1)
    ,IOPB_EN_MASK = 0x00000002
    ,IOPB_EN_POS = 1
    ,IOPB_EN_DISABLE = 0x00000000 
    ,IOPB_EN_ENABLE = 0x00000002 
    // IO Port A clock source enable (bits: 0)
    ,IOPA_EN_MASK = 0x00000001
    ,IOPA_EN_POS = 0
    ,IOPA_EN_DISABLE = 0x00000000 
    ,IOPA_EN_ENABLE = 0x00000001 
    ,AHB_MASK = 0x0000810F
    ;
  };
  // CSC APB clock control register 0
  struct APB0 : reg<ip_ver, base + 0x20>
  {
    static constexpr typename APB0::type
    // URT1 UART module clock source enable (bits: 17)
     URT1_EN_MASK = 0x00020000
    ,URT1_EN_POS = 17
    ,URT1_EN_DISABLE = 0x00000000 
    ,URT1_EN_ENABLE = 0x00020000 
    // URT0 UART module clock source enable (bits: 16)
    ,URT0_EN_MASK = 0x00010000
    ,URT0_EN_POS = 16
    ,URT0_EN_DISABLE = 0x00000000 
    ,URT0_EN_ENABLE = 0x00010000 
    // SPI0 module clock source enable (bits: 12)
    ,SPI0_EN_MASK = 0x00001000
    ,SPI0_EN_POS = 12
    ,SPI0_EN_DISABLE = 0x00000000 
    ,SPI0_EN_ENABLE = 0x00001000 
    // I2C0 module clock source enable (bits: 8)
    ,I2C0_EN_MASK = 0x00000100
    ,I2C0_EN_POS = 8
    ,I2C0_EN_DISABLE = 0x00000000 
    ,I2C0_EN_ENABLE = 0x00000100 
    // WWDT module clock source enable. (This register is reset only by Cold reset.) (bits: 7)
    ,WWDT_EN_MASK = 0x00000080
    ,WWDT_EN_POS = 7
    ,WWDT_EN_DISABLE = 0x00000000 
    ,WWDT_EN_ENABLE = 0x00000080 
    // IWDT module clock source enable (bits: 6)
    ,IWDT_EN_MASK = 0x00000040
    ,IWDT_EN_POS = 6
    ,IWDT_EN_DISABLE = 0x00000000 
    ,IWDT_EN_ENABLE = 0x00000040 
    // RTC module clock source enable (bits: 5)
    ,RTC_EN_MASK = 0x00000020
    ,RTC_EN_POS = 5
    ,RTC_EN_DISABLE = 0x00000000 
    ,RTC_EN_ENABLE = 0x00000020 
    // CMP module clock source enable (bits: 2)
    ,CMP_EN_MASK = 0x00000004
    ,CMP_EN_POS = 2
    ,CMP_EN_DISABLE = 0x00000000 
    ,CMP_EN_ENABLE = 0x00000004 
    // ADC module clock source enable (bits: 0)
    ,ADC0_EN_MASK = 0x00000001
    ,ADC0_EN_POS = 0
    ,ADC0_EN_DISABLE = 0x00000000 
    ,ADC0_EN_ENABLE = 0x00000001 
    ,APB0_MASK = 0x000311E5
    ;
  };
  // CSC APB clock control register 1
  struct APB1 : reg<ip_ver, base + 0x24>
  {
    static constexpr typename APB1::type
    // TM36 module clock source enable (bits: 15)
     TM36_EN_MASK = 0x00008000
    ,TM36_EN_POS = 15
    ,TM36_EN_DISABLE = 0x00000000 
    ,TM36_EN_ENABLE = 0x00008000 
    // TM11 module clock source enable (bits: 7)
    ,TM16_EN_MASK = 0x00000080
    ,TM16_EN_POS = 7
    ,TM16_EN_DISABLE = 0x00000000 
    ,TM16_EN_ENABLE = 0x00000080 
    // TM10 module clock source enable (bits: 4)
    ,TM10_EN_MASK = 0x00000010
    ,TM10_EN_POS = 4
    ,TM10_EN_DISABLE = 0x00000000 
    ,TM10_EN_ENABLE = 0x00000010 
    // TM01 module clock source enable (bits: 1)
    ,TM01_EN_MASK = 0x00000002
    ,TM01_EN_POS = 1
    ,TM01_EN_DISABLE = 0x00000000 
    ,TM01_EN_ENABLE = 0x00000002 
    // TM00 module clock source enable (bits: 0)
    ,TM00_EN_MASK = 0x00000001
    ,TM00_EN_POS = 0
    ,TM00_EN_DISABLE = 0x00000000 
    ,TM00_EN_ENABLE = 0x00000001 
    ,APB1_MASK = 0x00008093
    ;
  };
  // CSC SLEEP mode clock enable register 0
  struct SLP0 : reg<ip_ver, base + 0x30>
  {
    static constexpr typename SLP0::type
    // URT1 UART module clock enable in SLEEP mode (bits: 17)
     SLP_URT1_MASK = 0x00020000
    ,SLP_URT1_POS = 17
    ,SLP_URT1_DISABLE = 0x00000000 
    ,SLP_URT1_ENABLE = 0x00020000 
    // URT0 UART module clock enable in SLEEP mode (bits: 16)
    ,SLP_URT0_MASK = 0x00010000
    ,SLP_URT0_POS = 16
    ,SLP_URT0_DISABLE = 0x00000000 
    ,SLP_URT0_ENABLE = 0x00010000 
    // SPI0 module clock enable in SLEEP mode (bits: 12)
    ,SLP_SPI0_MASK = 0x00001000
    ,SLP_SPI0_POS = 12
    ,SLP_SPI0_DISABLE = 0x00000000 
    ,SLP_SPI0_ENABLE = 0x00001000 
    // I2C0 module clock enable in SLEEP mode (bits: 8)
    ,SLP_I2C0_MASK = 0x00000100
    ,SLP_I2C0_POS = 8
    ,SLP_I2C0_DISABLE = 0x00000000 
    ,SLP_I2C0_ENABLE = 0x00000100 
    // WWDT module clock enable in SLEEP mode (bits: 7)
    ,SLP_WWDT_MASK = 0x00000080
    ,SLP_WWDT_POS = 7
    ,SLP_WWDT_DISABLE = 0x00000000 
    ,SLP_WWDT_ENABLE = 0x00000080 
    // IWDT module clock enable in SLEEP mode (bits: 6)
    ,SLP_IWDT_MASK = 0x00000040
    ,SLP_IWDT_POS = 6
    ,SLP_IWDT_DISABLE = 0x00000000 
    ,SLP_IWDT_ENABLE = 0x00000040 
    // IWDT module clock enable in SLEEP mode (bits: 5)
    ,SLP_RTC_MASK = 0x00000020
    ,SLP_RTC_POS = 5
    ,SLP_RTC_DISABLE = 0x00000000 
    ,SLP_RTC_ENABLE = 0x00000020 
    // CMP module clock enable in SLEEP mode (bits: 2)
    ,SLP_CMP_MASK = 0x00000004
    ,SLP_CMP_POS = 2
    ,SLP_CMP_DISABLE = 0x00000000 
    ,SLP_CMP_ENABLE = 0x00000004 
    // ADC module clock enable in SLEEP mode (bits: 0)
    ,SLP_ADC0_MASK = 0x00000001
    ,SLP_ADC0_POS = 0
    ,SLP_ADC0_DISABLE = 0x00000000 
    ,SLP_ADC0_ENABLE = 0x00000001 
    ,SLP0_MASK = 0x000311E5
    ;
  };
  // CSC SLEEP mode clock enable register 1
  struct SLP1 : reg<ip_ver, base + 0x34>
  {
    static constexpr typename SLP1::type
    // TM36 module clock enable in SLEEP mode (bits: 15)
     SLP_TM36_MASK = 0x00008000
    ,SLP_TM36_POS = 15
    ,SLP_TM36_DISABLE = 0x00000000 
    ,SLP_TM36_ENABLE = 0x00008000 
    // TM11 module clock enable in SLEEP mode (bits: 7)
    ,SLP_TM16_MASK = 0x00000080
    ,SLP_TM16_POS = 7
    ,SLP_TM16_DISABLE = 0x00000000 
    ,SLP_TM16_ENABLE = 0x00000080 
    // TM10 module clock enable in SLEEP mode (bits: 4)
    ,SLP_TM10_MASK = 0x00000010
    ,SLP_TM10_POS = 4
    ,SLP_TM10_DISABLE = 0x00000000 
    ,SLP_TM10_ENABLE = 0x00000010 
    // TM01 module clock enable in SLEEP mode (bits: 1)
    ,SLP_TM01_MASK = 0x00000002
    ,SLP_TM01_POS = 1
    ,SLP_TM01_DISABLE = 0x00000000 
    ,SLP_TM01_ENABLE = 0x00000002 
    // TM00 module clock enable in SLEEP mode (bits: 0)
    ,SLP_TM00_MASK = 0x00000001
    ,SLP_TM00_POS = 0
    ,SLP_TM00_DISABLE = 0x00000000 
    ,SLP_TM00_ENABLE = 0x00000001 
    ,SLP1_MASK = 0x00008093
    ;
  };
  // CSC STOP mode clock enable register 0
  struct STP0 : reg<ip_ver, base + 0x38>
  {
    static constexpr typename STP0::type
    // IWDT module clock enable in STOP mode (bits: 6)
     STP_IWDT_MASK = 0x00000040
    ,STP_IWDT_POS = 6
    ,STP_IWDT_DISABLE = 0x00000000 
    ,STP_IWDT_ENABLE = 0x00000040 
    // IWDT module clock enable in STOP mode (bits: 5)
    ,STP_RTC_MASK = 0x00000020
    ,STP_RTC_POS = 5
    ,STP_RTC_DISABLE = 0x00000000 
    ,STP_RTC_ENABLE = 0x00000020 
    ,STP0_MASK = 0x00000060
    ;
  };
  // CSC clock source select register 0
  struct CKS0 : reg<ip_ver, base + 0x40>
  {
    static constexpr typename CKS0::type
    // CMP process clock source select (bits: 4)
     CMP_CKS_MASK = 0x00000010
    ,CMP_CKS_POS = 4
    ,CMP_CKS_CK_APB = 0x00000000 
    ,CMP_CKS_CK_AHB = 0x00000010 
    // ADC0 process clock source select (bits: 0)
    ,ADC0_CKS_MASK = 0x00000001
    ,ADC0_CKS_POS = 0
    ,ADC0_CKS_CK_APB = 0x00000000 
    ,ADC0_CKS_CK_AHB = 0x00000001 
    ,CKS0_MASK = 0x00000011
    ;
  };
  // CSC clock source select register 1
  struct CKS1 : reg<ip_ver, base + 0x44>
  {
    static constexpr typename CKS1::type
    // URT1 process clock source select (bits: 18)
     URT1_CKS_MASK = 0x00040000
    ,URT1_CKS_POS = 18
    ,URT1_CKS_CK_APB = 0x00000000 
    ,URT1_CKS_CK_AHB = 0x00040000 
    // URT0 process clock source select (bits: 16)
    ,URT0_CKS_MASK = 0x00010000
    ,URT0_CKS_POS = 16
    ,URT0_CKS_CK_APB = 0x00000000 
    ,URT0_CKS_CK_AHB = 0x00010000 
    // SPI0 process clock source select (bits: 8)
    ,SPI0_CKS_MASK = 0x00000100
    ,SPI0_CKS_POS = 8
    ,SPI0_CKS_CK_APB = 0x00000000 
    ,SPI0_CKS_CK_AHB = 0x00000100 
    // I2C0 process clock source select (bits: 0)
    ,I2C0_CKS_MASK = 0x00000001
    ,I2C0_CKS_POS = 0
    ,I2C0_CKS_CK_APB = 0x00000000 
    ,I2C0_CKS_CK_AHB = 0x00000001 
    ,CKS1_MASK = 0x00050101
    ;
  };
  // CSC clock source select register 2
  struct CKS2 : reg<ip_ver, base + 0x48>
  {
    static constexpr typename CKS2::type
    // TM36 process clock source select (bits: 30)
     TM36_CKS_MASK = 0x40000000
    ,TM36_CKS_POS = 30
    ,TM36_CKS_CK_APB = 0x00000000 
    ,TM36_CKS_CK_AHB = 0x40000000 
    // TM11 process clock source select (bits: 14)
    ,TM16_CKS_MASK = 0x00004000
    ,TM16_CKS_POS = 14
    ,TM16_CKS_CK_APB = 0x00000000 
    ,TM16_CKS_CK_AHB = 0x00004000 
    // TM10 process clock source select (bits: 8)
    ,TM10_CKS_MASK = 0x00000100
    ,TM10_CKS_POS = 8
    ,TM10_CKS_CK_APB = 0x00000000 
    ,TM10_CKS_CK_AHB = 0x00000100 
    // TM01 process clock source select (bits: 2)
    ,TM01_CKS_MASK = 0x00000004
    ,TM01_CKS_POS = 2
    ,TM01_CKS_CK_APB = 0x00000000 
    ,TM01_CKS_CK_AHB = 0x00000004 
    // TM00 process clock source select (bits: 0)
    ,TM00_CKS_MASK = 0x00000001
    ,TM00_CKS_POS = 0
    ,TM00_CKS_CK_APB = 0x00000000 
    ,TM00_CKS_CK_AHB = 0x00000001 
    ,CKS2_MASK = 0x40004105
    ;
  };
}; // struct CSC

} // namespace lmcu::device::ip::v1

