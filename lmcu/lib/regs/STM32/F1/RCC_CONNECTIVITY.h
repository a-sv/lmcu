/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Reset and clock control
// ------------------------------------------------------------------------------------------------
struct RCC
{
  static constexpr std::uintptr_t base = 0x40021000UL;

  // Clock control register
  struct CR : reg<base + 0x0, 0x00000083>
  {
    static constexpr type
    // PLL clock ready flag (bits: 25)
     PLLRDY_MASK = 0x02000000
    ,PLLRDY_POS = 25
    ,PLLRDY = 0x02000000
    // PLL2 enable (bits: 26)
    ,PLL2ON_MASK = 0x04000000
    ,PLL2ON_POS = 26
    ,PLL2ON = 0x04000000
    // PLL2 clock ready flag (bits: 27)
    ,PLL2RDY_MASK = 0x08000000
    ,PLL2RDY_POS = 27
    ,PLL2RDY = 0x08000000
    // PLL3 enable (bits: 28)
    ,PLL3ON_MASK = 0x10000000
    ,PLL3ON_POS = 28
    ,PLL3ON = 0x10000000
    // PLL3 clock ready flag (bits: 29)
    ,PLL3RDY_MASK = 0x20000000
    ,PLL3RDY_POS = 29
    ,PLL3RDY = 0x20000000
    // Internal High Speed clock enable (bits: 0)
    ,HSION_MASK = 0x00000001
    ,HSION_POS = 0
    ,HSION = 0x00000001
    // Internal High Speed clock ready flag (bits: 1)
    ,HSIRDY_MASK = 0x00000002
    ,HSIRDY_POS = 1
    ,HSIRDY = 0x00000002
    // Internal High Speed clock trimming (bits: 7-3)
    ,HSITRIM_MASK = 0x000000F8
    ,HSITRIM_POS = 3
    // Internal high-speed clock calibration (bits: 15-8)
    ,HSICAL_MASK = 0x0000FF00
    ,HSICAL_POS = 8
    // HSE clock enable (bits: 16)
    ,HSEON_MASK = 0x00010000
    ,HSEON_POS = 16
    ,HSEON = 0x00010000
    // External high-speed clock ready flag (bits: 17)
    ,HSERDY_MASK = 0x00020000
    ,HSERDY_POS = 17
    ,HSERDY = 0x00020000
    // External high-speed clock bypass (bits: 18)
    ,HSEBYP_MASK = 0x00040000
    ,HSEBYP_POS = 18
    ,HSEBYP = 0x00040000
    // Clock security system enable (bits: 19)
    ,CSSON_MASK = 0x00080000
    ,CSSON_POS = 19
    ,CSSON = 0x00080000
    // PLL enable (bits: 24)
    ,PLLON_MASK = 0x01000000
    ,PLLON_POS = 24
    ,PLLON = 0x01000000
    ,CR_MASK = 0x3F0FFFFB
    ;
  };
  // Clock configuration register
  struct CFGR : reg<base + 0x4>
  {
    static constexpr type
    // LSB of division factor PREDIV1 (bits: 17)
     PLLXTPRE_MASK = 0x00020000
    ,PLLXTPRE_POS = 17
    ,PLLXTPRE = 0x00020000
    // PLL multiplication factor (bits: 21-18)
    ,PLLMUL_MASK = 0x003C0000
    ,PLLMUL_POS = 18
    ,PLLMUL_MUL4 = 0x00080000 // PLL input clock x 4
    ,PLLMUL_MUL5 = 0x000C0000 // PLL input clock x 5
    ,PLLMUL_MUL6 = 0x00100000 // PLL input clock x 6
    ,PLLMUL_MUL7 = 0x00140000 // PLL input clock x 7
    ,PLLMUL_MUL8 = 0x00180000 // PLL input clock x 8
    ,PLLMUL_MUL9 = 0x001C0000 // PLL input clock x 9
    ,PLLMUL_MUL6_5 = 0x00340000 // PLL input clock x 6.5
    // USB OTG FS prescaler (bits: 22)
    ,OTGFSPRE_MASK = 0x00400000
    ,OTGFSPRE_POS = 22
    ,OTGFSPRE = 0x00400000
    // Microcontroller clock output (bits: 27-24)
    ,MCO_MASK = 0x0F000000
    ,MCO_POS = 24
    ,MCO_PLL2 = 0x08000000 // PLL2 clock
    ,MCO_PLL3_DIV2 = 0x09000000 // PLL3 clock divided by 2
    ,MCO_XT1 = 0x0A000000 // XT1 external 3-25 MHz oscillator clock (for Ethernet)
    ,MCO_PLL3 = 0x0B000000 // PLL3 clock (for Ethernet)
    ,MCO_DISABLE = 0x00000000 // No clock
    ,MCO_SYSCLK = 0x04000000 // System clock (SYSCLK)
    ,MCO_HSI = 0x05000000 // HSI clock
    ,MCO_HSE = 0x06000000 // HSE clock
    ,MCO_PLL_DIV2 = 0x07000000 // PLL clock divided by 2
    // System clock switch (bits: 1-0)
    ,SW_MASK = 0x00000003
    ,SW_POS = 0
    ,SW_HSI = 0x00000000 // HSI selected as system clock
    ,SW_HSE = 0x00000001 // HSE selected as system clock
    ,SW_PLL = 0x00000002 // PLL selected as system clock
    // System clock switch status (bits: 3-2)
    ,SWS_MASK = 0x0000000C
    ,SWS_POS = 2
    ,SWS_HSI = 0x00000000 // HSI oscillator used as system clock
    ,SWS_HSE = 0x00000004 // HSE oscillator used as system clock
    ,SWS_PLL = 0x00000008 // PLL used as system clock
    // AHB prescaler (bits: 7-4)
    ,HPRE_MASK = 0x000000F0
    ,HPRE_POS = 4
    ,HPRE_DIV1 = 0x00000000 // SYSCLK not divided
    ,HPRE_DIV2 = 0x00000080 // SYSCLK divided by 2
    ,HPRE_DIV4 = 0x00000090 // SYSCLK divided by 4
    ,HPRE_DIV8 = 0x000000A0 // SYSCLK divided by 8
    ,HPRE_DIV16 = 0x000000B0 // SYSCLK divided by 16
    ,HPRE_DIV64 = 0x000000C0 // SYSCLK divided by 64
    ,HPRE_DIV128 = 0x000000D0 // SYSCLK divided by 128
    ,HPRE_DIV256 = 0x000000E0 // SYSCLK divided by 256
    ,HPRE_DIV512 = 0x000000F0 // SYSCLK divided by 512
    // APB low-speed prescaler (APB1) (bits: 10-8)
    ,PPRE1_MASK = 0x00000700
    ,PPRE1_POS = 8
    ,PPRE1_DIV1 = 0x00000000 // HCLK not divided
    ,PPRE1_DIV2 = 0x00000400 // HCLK divided by 2
    ,PPRE1_DIV4 = 0x00000500 // HCLK divided by 4
    ,PPRE1_DIV8 = 0x00000600 // HCLK divided by 8
    ,PPRE1_DIV16 = 0x00000700 // HCLK divided by 16
    // APB high-speed prescaler (APB2) (bits: 13-11)
    ,PPRE2_MASK = 0x00003800
    ,PPRE2_POS = 11
    ,PPRE2_DIV1 = 0x00000000 // HCLK not divided
    ,PPRE2_DIV2 = 0x00002000 // HCLK divided by 2
    ,PPRE2_DIV4 = 0x00002800 // HCLK divided by 4
    ,PPRE2_DIV8 = 0x00003000 // HCLK divided by 8
    ,PPRE2_DIV16 = 0x00003800 // HCLK divided by 16
    // ADC prescaler (bits: 15-14)
    ,ADCPRE_MASK = 0x0000C000
    ,ADCPRE_POS = 14
    ,ADCPRE_DIV2 = 0x00000000 // HCLK divided by 2
    ,ADCPRE_DIV4 = 0x00004000 // HCLK divided by 4
    ,ADCPRE_DIV6 = 0x00008000 // HCLK divided by 6
    ,ADCPRE_DIV8 = 0x0000C000 // HCLK divided by 8
    // PLL entry clock source (bits: 16)
    ,PLLSRC_MASK = 0x00010000
    ,PLLSRC_POS = 16
    ,PLLSRC = 0x00010000
    ,CFGR_MASK = 0x0F7FFFFF
    ;
  };
  // Clock interrupt register
  struct CIR : reg<base + 0x8>
  {
    static constexpr type
    // PLL2 Ready Interrupt flag (bits: 5)
     PLL2RDYF_MASK = 0x00000020
    ,PLL2RDYF_POS = 5
    ,PLL2RDYF = 0x00000020
    // PLL3 Ready Interrupt flag (bits: 6)
    ,PLL3RDYF_MASK = 0x00000040
    ,PLL3RDYF_POS = 6
    ,PLL3RDYF = 0x00000040
    // PLL2 Ready Interrupt Enable (bits: 13)
    ,PLL2RDYIE_MASK = 0x00002000
    ,PLL2RDYIE_POS = 13
    ,PLL2RDYIE = 0x00002000
    // PLL3 Ready Interrupt Enable (bits: 14)
    ,PLL3RDYIE_MASK = 0x00004000
    ,PLL3RDYIE_POS = 14
    ,PLL3RDYIE = 0x00004000
    // PLL2 Ready Interrupt Clear (bits: 21)
    ,PLL2RDYC_MASK = 0x00200000
    ,PLL2RDYC_POS = 21
    ,PLL2RDYC = 0x00200000
    // PLL3 Ready Interrupt Clear (bits: 22)
    ,PLL3RDYC_MASK = 0x00400000
    ,PLL3RDYC_POS = 22
    ,PLL3RDYC = 0x00400000
    // LSI ready interrupt flag (bits: 0)
    ,LSIRDYF_MASK = 0x00000001
    ,LSIRDYF_POS = 0
    ,LSIRDYF = 0x00000001
    // LSE ready interrupt flag (bits: 1)
    ,LSERDYF_MASK = 0x00000002
    ,LSERDYF_POS = 1
    ,LSERDYF = 0x00000002
    // HSI ready interrupt flag (bits: 2)
    ,HSIRDYF_MASK = 0x00000004
    ,HSIRDYF_POS = 2
    ,HSIRDYF = 0x00000004
    // HSE ready interrupt flag (bits: 3)
    ,HSERDYF_MASK = 0x00000008
    ,HSERDYF_POS = 3
    ,HSERDYF = 0x00000008
    // PLL ready interrupt flag (bits: 4)
    ,PLLRDYF_MASK = 0x00000010
    ,PLLRDYF_POS = 4
    ,PLLRDYF = 0x00000010
    // Clock security system interrupt flag (bits: 7)
    ,CSSF_MASK = 0x00000080
    ,CSSF_POS = 7
    ,CSSF = 0x00000080
    // LSI ready interrupt enable (bits: 8)
    ,LSIRDYIE_MASK = 0x00000100
    ,LSIRDYIE_POS = 8
    ,LSIRDYIE = 0x00000100
    // LSE ready interrupt enable (bits: 9)
    ,LSERDYIE_MASK = 0x00000200
    ,LSERDYIE_POS = 9
    ,LSERDYIE = 0x00000200
    // HSI ready interrupt enable (bits: 10)
    ,HSIRDYIE_MASK = 0x00000400
    ,HSIRDYIE_POS = 10
    ,HSIRDYIE = 0x00000400
    // HSE ready interrupt enable (bits: 11)
    ,HSERDYIE_MASK = 0x00000800
    ,HSERDYIE_POS = 11
    ,HSERDYIE = 0x00000800
    // PLL ready interrupt enable (bits: 12)
    ,PLLRDYIE_MASK = 0x00001000
    ,PLLRDYIE_POS = 12
    ,PLLRDYIE = 0x00001000
    // LSI ready interrupt clear (bits: 16)
    ,LSIRDYC_MASK = 0x00010000
    ,LSIRDYC_POS = 16
    ,LSIRDYC = 0x00010000
    // LSE ready interrupt clear (bits: 17)
    ,LSERDYC_MASK = 0x00020000
    ,LSERDYC_POS = 17
    ,LSERDYC = 0x00020000
    // HSI ready interrupt clear (bits: 18)
    ,HSIRDYC_MASK = 0x00040000
    ,HSIRDYC_POS = 18
    ,HSIRDYC = 0x00040000
    // HSE ready interrupt clear (bits: 19)
    ,HSERDYC_MASK = 0x00080000
    ,HSERDYC_POS = 19
    ,HSERDYC = 0x00080000
    // PLL ready interrupt clear (bits: 20)
    ,PLLRDYC_MASK = 0x00100000
    ,PLLRDYC_POS = 20
    ,PLLRDYC = 0x00100000
    // Clock security system interrupt clear (bits: 23)
    ,CSSC_MASK = 0x00800000
    ,CSSC_POS = 23
    ,CSSC = 0x00800000
    ,CIR_MASK = 0x00FF7FFF
    ;
  };
  // APB2 peripheral reset register
  struct APB2RSTR : reg<base + 0xC>
  {
    static constexpr type
    // Alternate function IO reset (bits: 0)
     AFIORST_MASK = 0x00000001
    ,AFIORST_POS = 0
    ,AFIORST = 0x00000001
    // IO port A reset (bits: 2)
    ,IOPARST_MASK = 0x00000004
    ,IOPARST_POS = 2
    ,IOPARST = 0x00000004
    // IO port B reset (bits: 3)
    ,IOPBRST_MASK = 0x00000008
    ,IOPBRST_POS = 3
    ,IOPBRST = 0x00000008
    // IO port C reset (bits: 4)
    ,IOPCRST_MASK = 0x00000010
    ,IOPCRST_POS = 4
    ,IOPCRST = 0x00000010
    // IO port D reset (bits: 5)
    ,IOPDRST_MASK = 0x00000020
    ,IOPDRST_POS = 5
    ,IOPDRST = 0x00000020
    // IO port E reset (bits: 6)
    ,IOPERST_MASK = 0x00000040
    ,IOPERST_POS = 6
    ,IOPERST = 0x00000040
    // ADC1 interface reset (bits: 9)
    ,ADC1RST_MASK = 0x00000200
    ,ADC1RST_POS = 9
    ,ADC1RST = 0x00000200
    // ADC2 interface reset (bits: 10)
    ,ADC2RST_MASK = 0x00000400
    ,ADC2RST_POS = 10
    ,ADC2RST = 0x00000400
    // TIM1 timer reset (bits: 11)
    ,TIM1RST_MASK = 0x00000800
    ,TIM1RST_POS = 11
    ,TIM1RST = 0x00000800
    // SPI1 reset (bits: 12)
    ,SPI1RST_MASK = 0x00001000
    ,SPI1RST_POS = 12
    ,SPI1RST = 0x00001000
    // USART1 reset (bits: 14)
    ,USART1RST_MASK = 0x00004000
    ,USART1RST_POS = 14
    ,USART1RST = 0x00004000
    ,APB2RSTR_MASK = 0x00005E7D
    ;
  };
  // APB1 peripheral reset register
  struct APB1RSTR : reg<base + 0x10>
  {
    static constexpr type
    // CAN2 reset (bits: 26)
     CAN2RST_MASK = 0x04000000
    ,CAN2RST_POS = 26
    ,CAN2RST = 0x04000000
    // TIM2 timer reset (bits: 0)
    ,TIM2RST_MASK = 0x00000001
    ,TIM2RST_POS = 0
    ,TIM2RST = 0x00000001
    // TIM3 timer reset (bits: 1)
    ,TIM3RST_MASK = 0x00000002
    ,TIM3RST_POS = 1
    ,TIM3RST = 0x00000002
    // TIM4 timer reset (bits: 2)
    ,TIM4RST_MASK = 0x00000004
    ,TIM4RST_POS = 2
    ,TIM4RST = 0x00000004
    // TIM5 timer reset (bits: 3)
    ,TIM5RST_MASK = 0x00000008
    ,TIM5RST_POS = 3
    ,TIM5RST = 0x00000008
    // TIM6 timer reset (bits: 4)
    ,TIM6RST_MASK = 0x00000010
    ,TIM6RST_POS = 4
    ,TIM6RST = 0x00000010
    // TIM7 timer reset (bits: 5)
    ,TIM7RST_MASK = 0x00000020
    ,TIM7RST_POS = 5
    ,TIM7RST = 0x00000020
    // Window watchdog reset (bits: 11)
    ,WWDGRST_MASK = 0x00000800
    ,WWDGRST_POS = 11
    ,WWDGRST = 0x00000800
    // SPI2 reset (bits: 14)
    ,SPI2RST_MASK = 0x00004000
    ,SPI2RST_POS = 14
    ,SPI2RST = 0x00004000
    // SPI3 reset (bits: 15)
    ,SPI3RST_MASK = 0x00008000
    ,SPI3RST_POS = 15
    ,SPI3RST = 0x00008000
    // USART2 reset (bits: 17)
    ,USART2RST_MASK = 0x00020000
    ,USART2RST_POS = 17
    ,USART2RST = 0x00020000
    // USART3 reset (bits: 18)
    ,USART3RST_MASK = 0x00040000
    ,USART3RST_POS = 18
    ,USART3RST = 0x00040000
    // USART4 reset (bits: 19)
    ,UART4RST_MASK = 0x00080000
    ,UART4RST_POS = 19
    ,UART4RST = 0x00080000
    // USART5 reset (bits: 20)
    ,UART5RST_MASK = 0x00100000
    ,UART5RST_POS = 20
    ,UART5RST = 0x00100000
    // I2C1 reset (bits: 21)
    ,I2C1RST_MASK = 0x00200000
    ,I2C1RST_POS = 21
    ,I2C1RST = 0x00200000
    // I2C2 reset (bits: 22)
    ,I2C2RST_MASK = 0x00400000
    ,I2C2RST_POS = 22
    ,I2C2RST = 0x00400000
    // CAN1 reset (bits: 25)
    ,CAN1RST_MASK = 0x02000000
    ,CAN1RST_POS = 25
    ,CAN1RST = 0x02000000
    // Backup interface reset (bits: 27)
    ,BKPRST_MASK = 0x08000000
    ,BKPRST_POS = 27
    ,BKPRST = 0x08000000
    // Power interface reset (bits: 28)
    ,PWRRST_MASK = 0x10000000
    ,PWRRST_POS = 28
    ,PWRRST = 0x10000000
    // DAC interface reset (bits: 29)
    ,DACRST_MASK = 0x20000000
    ,DACRST_POS = 29
    ,DACRST = 0x20000000
    ,APB1RSTR_MASK = 0x3E7EC83F
    ;
  };
  // AHB peripheral clock enable register
  struct AHBENR : reg<base + 0x14, 0x00000014>
  {
    static constexpr type
    // USB OTG FS clock enable (bits: 12)
     OTGFSEN_MASK = 0x00001000
    ,OTGFSEN_POS = 12
    ,OTGFSEN = 0x00001000
    // Ethernet MAC clock enable (bits: 14)
    ,ETHMACEN_MASK = 0x00004000
    ,ETHMACEN_POS = 14
    ,ETHMACEN = 0x00004000
    // Ethernet MAC TX clock enable (bits: 15)
    ,ETHMACTXEN_MASK = 0x00008000
    ,ETHMACTXEN_POS = 15
    ,ETHMACTXEN = 0x00008000
    // Ethernet MAC RX clock enable (bits: 16)
    ,ETHMACRXEN_MASK = 0x00010000
    ,ETHMACRXEN_POS = 16
    ,ETHMACRXEN = 0x00010000
    // DMA1 clock enable (bits: 0)
    ,DMA1EN_MASK = 0x00000001
    ,DMA1EN_POS = 0
    ,DMA1EN = 0x00000001
    // DMA2 clock enable (bits: 1)
    ,DMA2EN_MASK = 0x00000002
    ,DMA2EN_POS = 1
    ,DMA2EN = 0x00000002
    // SRAM interface clock enable (bits: 2)
    ,SRAMEN_MASK = 0x00000004
    ,SRAMEN_POS = 2
    ,SRAMEN = 0x00000004
    // FLITF clock enable (bits: 4)
    ,FLITFEN_MASK = 0x00000010
    ,FLITFEN_POS = 4
    ,FLITFEN = 0x00000010
    // CRC clock enable (bits: 6)
    ,CRCEN_MASK = 0x00000040
    ,CRCEN_POS = 6
    ,CRCEN = 0x00000040
    ,AHBENR_MASK = 0x0001D057
    ;
  };
  // APB2 peripheral clock enable register
  struct APB2ENR : reg<base + 0x18>
  {
    static constexpr type
    // Alternate function IO clock enable (bits: 0)
     AFIOEN_MASK = 0x00000001
    ,AFIOEN_POS = 0
    ,AFIOEN = 0x00000001
    // IO port A clock enable (bits: 2)
    ,IOPAEN_MASK = 0x00000004
    ,IOPAEN_POS = 2
    ,IOPAEN = 0x00000004
    // IO port B clock enable (bits: 3)
    ,IOPBEN_MASK = 0x00000008
    ,IOPBEN_POS = 3
    ,IOPBEN = 0x00000008
    // IO port C clock enable (bits: 4)
    ,IOPCEN_MASK = 0x00000010
    ,IOPCEN_POS = 4
    ,IOPCEN = 0x00000010
    // IO port D clock enable (bits: 5)
    ,IOPDEN_MASK = 0x00000020
    ,IOPDEN_POS = 5
    ,IOPDEN = 0x00000020
    // IO port E clock enable (bits: 6)
    ,IOPEEN_MASK = 0x00000040
    ,IOPEEN_POS = 6
    ,IOPEEN = 0x00000040
    // ADC1 interface clock enable (bits: 9)
    ,ADC1EN_MASK = 0x00000200
    ,ADC1EN_POS = 9
    ,ADC1EN = 0x00000200
    // ADC2 interface clock enable (bits: 10)
    ,ADC2EN_MASK = 0x00000400
    ,ADC2EN_POS = 10
    ,ADC2EN = 0x00000400
    // TIM1 timer clock enable (bits: 11)
    ,TIM1EN_MASK = 0x00000800
    ,TIM1EN_POS = 11
    ,TIM1EN = 0x00000800
    // SPI1 clock enable (bits: 12)
    ,SPI1EN_MASK = 0x00001000
    ,SPI1EN_POS = 12
    ,SPI1EN = 0x00001000
    // USART1 clock enable (bits: 14)
    ,USART1EN_MASK = 0x00004000
    ,USART1EN_POS = 14
    ,USART1EN = 0x00004000
    ,APB2ENR_MASK = 0x00005E7D
    ;
  };
  // APB1 peripheral clock enable register
  struct APB1ENR : reg<base + 0x1C>
  {
    static constexpr type
    // CAN2 clock enable (bits: 26)
     CAN2EN_MASK = 0x04000000
    ,CAN2EN_POS = 26
    ,CAN2EN = 0x04000000
    // TIM2 timer clock enable (bits: 0)
    ,TIM2EN_MASK = 0x00000001
    ,TIM2EN_POS = 0
    ,TIM2EN = 0x00000001
    // TIM3 timer clock enable (bits: 1)
    ,TIM3EN_MASK = 0x00000002
    ,TIM3EN_POS = 1
    ,TIM3EN = 0x00000002
    // TIM4 timer clock enable (bits: 2)
    ,TIM4EN_MASK = 0x00000004
    ,TIM4EN_POS = 2
    ,TIM4EN = 0x00000004
    // TIM5 timer clock enable (bits: 3)
    ,TIM5EN_MASK = 0x00000008
    ,TIM5EN_POS = 3
    ,TIM5EN = 0x00000008
    // TIM6 timer clock enable (bits: 4)
    ,TIM6EN_MASK = 0x00000010
    ,TIM6EN_POS = 4
    ,TIM6EN = 0x00000010
    // TIM7 timer clock enable (bits: 5)
    ,TIM7EN_MASK = 0x00000020
    ,TIM7EN_POS = 5
    ,TIM7EN = 0x00000020
    // Window watchdog clock enable (bits: 11)
    ,WWDGEN_MASK = 0x00000800
    ,WWDGEN_POS = 11
    ,WWDGEN = 0x00000800
    // SPI2 clock enable (bits: 14)
    ,SPI2EN_MASK = 0x00004000
    ,SPI2EN_POS = 14
    ,SPI2EN = 0x00004000
    // SPI 3 clock enable (bits: 15)
    ,SPI3EN_MASK = 0x00008000
    ,SPI3EN_POS = 15
    ,SPI3EN = 0x00008000
    // USART2 clock enable (bits: 17)
    ,USART2EN_MASK = 0x00020000
    ,USART2EN_POS = 17
    ,USART2EN = 0x00020000
    // USART3 clock enable (bits: 18)
    ,USART3EN_MASK = 0x00040000
    ,USART3EN_POS = 18
    ,USART3EN = 0x00040000
    // USART4 clock enable (bits: 19)
    ,UART4EN_MASK = 0x00080000
    ,UART4EN_POS = 19
    ,UART4EN = 0x00080000
    // USART5 clock enable (bits: 20)
    ,UART5EN_MASK = 0x00100000
    ,UART5EN_POS = 20
    ,UART5EN = 0x00100000
    // I2C1 clock enable (bits: 21)
    ,I2C1EN_MASK = 0x00200000
    ,I2C1EN_POS = 21
    ,I2C1EN = 0x00200000
    // I2C2 clock enable (bits: 22)
    ,I2C2EN_MASK = 0x00400000
    ,I2C2EN_POS = 22
    ,I2C2EN = 0x00400000
    // CAN1 clock enable (bits: 25)
    ,CAN1EN_MASK = 0x02000000
    ,CAN1EN_POS = 25
    ,CAN1EN = 0x02000000
    // Backup interface clock enable (bits: 27)
    ,BKPEN_MASK = 0x08000000
    ,BKPEN_POS = 27
    ,BKPEN = 0x08000000
    // Power interface clock enable (bits: 28)
    ,PWREN_MASK = 0x10000000
    ,PWREN_POS = 28
    ,PWREN = 0x10000000
    // DAC interface clock enable (bits: 29)
    ,DACEN_MASK = 0x20000000
    ,DACEN_POS = 29
    ,DACEN = 0x20000000
    ,APB1ENR_MASK = 0x3E7EC83F
    ;
  };
  // AHB peripheral clock reset register
  struct AHBRSTR : reg<base + 0x28>
  {
    static constexpr type
    // USB OTG FS reset (bits: 12)
     OTGFSRST_MASK = 0x00001000
    ,OTGFSRST_POS = 12
    ,OTGFSRST = 0x00001000
    // Ethernet MAC reset (bits: 14)
    ,ETHMACRST_MASK = 0x00004000
    ,ETHMACRST_POS = 14
    ,ETHMACRST = 0x00004000
    ,AHBRSTR_MASK = 0x00005000
    ;
  };
  // Clock configuration register2
  struct CFGR2 : reg<base + 0x2C>
  {
    static constexpr type
    // PREDIV1 division factor (bits: 3-0)
     PREDIV1_MASK = 0x0000000F
    ,PREDIV1_POS = 0
    ,PREDIV1_DIV1 = 0x00000000 // Input clock not divided
    ,PREDIV1_DIV2 = 0x00000001 // Input clock divided by 2
    ,PREDIV1_DIV3 = 0x00000002 // Input clock divided by 3
    ,PREDIV1_DIV4 = 0x00000003 // Input clock divided by 4
    ,PREDIV1_DIV5 = 0x00000004 // Input clock divided by 5
    ,PREDIV1_DIV6 = 0x00000005 // Input clock divided by 6
    ,PREDIV1_DIV7 = 0x00000006 // Input clock divided by 7
    ,PREDIV1_DIV8 = 0x00000007 // Input clock divided by 8
    ,PREDIV1_DIV9 = 0x00000008 // Input clock divided by 9
    ,PREDIV1_DIV10 = 0x00000009 // Input clock divided by 10
    ,PREDIV1_DIV11 = 0x0000000A // Input clock divided by 11
    ,PREDIV1_DIV12 = 0x0000000B // Input clock divided by 12
    ,PREDIV1_DIV13 = 0x0000000C // Input clock divided by 13
    ,PREDIV1_DIV14 = 0x0000000D // Input clock divided by 14
    ,PREDIV1_DIV15 = 0x0000000E // Input clock divided by 15
    ,PREDIV1_DIV16 = 0x0000000F // Input clock divided by 16
    // PREDIV2 division factor (bits: 7-4)
    ,PREDIV2_MASK = 0x000000F0
    ,PREDIV2_POS = 4
    ,PREDIV2_DIV1 = 0x00000000 // Input clock not divided
    ,PREDIV2_DIV2 = 0x00000010 // Input clock divided by 2
    ,PREDIV2_DIV3 = 0x00000020 // Input clock divided by 3
    ,PREDIV2_DIV4 = 0x00000030 // Input clock divided by 4
    ,PREDIV2_DIV5 = 0x00000040 // Input clock divided by 5
    ,PREDIV2_DIV6 = 0x00000050 // Input clock divided by 6
    ,PREDIV2_DIV7 = 0x00000060 // Input clock divided by 7
    ,PREDIV2_DIV8 = 0x00000070 // Input clock divided by 8
    ,PREDIV2_DIV9 = 0x00000080 // Input clock divided by 9
    ,PREDIV2_DIV10 = 0x00000090 // Input clock divided by 10
    ,PREDIV2_DIV11 = 0x000000A0 // Input clock divided by 11
    ,PREDIV2_DIV12 = 0x000000B0 // Input clock divided by 12
    ,PREDIV2_DIV13 = 0x000000C0 // Input clock divided by 13
    ,PREDIV2_DIV14 = 0x000000D0 // Input clock divided by 14
    ,PREDIV2_DIV15 = 0x000000E0 // Input clock divided by 15
    ,PREDIV2_DIV16 = 0x000000F0 // Input clock divided by 16
    // PLL2 Multiplication Factor (bits: 11-8)
    ,PLL2MUL_MASK = 0x00000F00
    ,PLL2MUL_POS = 8
    ,PLL2MUL_MUL8 = 0x00000600 // PLL clock entry x 8
    ,PLL2MUL_MUL9 = 0x00000700 // PLL clock entry x 9
    ,PLL2MUL_MUL10 = 0x00000800 // PLL clock entry x 10
    ,PLL2MUL_MUL11 = 0x00000900 // PLL clock entry x 11
    ,PLL2MUL_MUL12 = 0x00000A00 // PLL clock entry x 12
    ,PLL2MUL_MUL13 = 0x00000B00 // PLL clock entry x 13
    ,PLL2MUL_MUL14 = 0x00000C00 // PLL clock entry x 14
    ,PLL2MUL_MUL16 = 0x00000E00 // PLL clock entry x 16
    ,PLL2MUL_MUL20 = 0x00000F00 // PLL clock entry x 20
    // PLL3 Multiplication Factor (bits: 15-12)
    ,PLL3MUL_MASK = 0x0000F000
    ,PLL3MUL_POS = 12
    ,PLL3MUL_MUL8 = 0x00006000 // PLL clock entry x 8
    ,PLL3MUL_MUL9 = 0x00007000 // PLL clock entry x 9
    ,PLL3MUL_MUL10 = 0x00008000 // PLL clock entry x 10
    ,PLL3MUL_MUL11 = 0x00009000 // PLL clock entry x 11
    ,PLL3MUL_MUL12 = 0x0000A000 // PLL clock entry x 12
    ,PLL3MUL_MUL13 = 0x0000B000 // PLL clock entry x 13
    ,PLL3MUL_MUL14 = 0x0000C000 // PLL clock entry x 14
    ,PLL3MUL_MUL16 = 0x0000E000 // PLL clock entry x 16
    ,PLL3MUL_MUL20 = 0x0000F000 // PLL clock entry x 20
    // PREDIV1 entry clock source (bits: 16)
    ,PREDIV1SRC_MASK = 0x00010000
    ,PREDIV1SRC_POS = 16
    ,PREDIV1SRC = 0x00010000
    // I2S2 clock source (bits: 17)
    ,I2S2SRC_MASK = 0x00020000
    ,I2S2SRC_POS = 17
    ,I2S2SRC = 0x00020000
    // I2S3 clock source (bits: 18)
    ,I2S3SRC_MASK = 0x00040000
    ,I2S3SRC_POS = 18
    ,I2S3SRC = 0x00040000
    ,CFGR2_MASK = 0x0007FFFF
    ;
  };
  // Backup domain control register
  struct BDCR : reg<base + 0x20>
  {
    static constexpr type
    // External low-speed oscillator enable (bits: 0)
     LSEON_MASK = 0x00000001
    ,LSEON_POS = 0
    ,LSEON = 0x00000001
    // External low-speed oscillator ready (bits: 1)
    ,LSERDY_MASK = 0x00000002
    ,LSERDY_POS = 1
    ,LSERDY = 0x00000002
    // External low-speed oscillator bypass (bits: 2)
    ,LSEBYP_MASK = 0x00000004
    ,LSEBYP_POS = 2
    ,LSEBYP = 0x00000004
    // RTC clock source selection (bits: 9-8)
    ,RTCSEL_MASK = 0x00000300
    ,RTCSEL_POS = 8
    ,RTCSEL_DISABLE = 0x00000000 // No clock
    ,RTCSEL_LSE = 0x00000100 // LSE oscillator clock used as RTC clock
    ,RTCSEL_LSI = 0x00000200 // LSI oscillator clock used as RTC clock
    ,RTCSEL_HSE = 0x00000300 // HSE oscillator clock divided by 128 used as RTC clock
    // RTC clock enable (bits: 15)
    ,RTCEN_MASK = 0x00008000
    ,RTCEN_POS = 15
    ,RTCEN = 0x00008000
    // Backup domain software reset (bits: 16)
    ,BDRST_MASK = 0x00010000
    ,BDRST_POS = 16
    ,BDRST = 0x00010000
    ,BDCR_MASK = 0x00018307
    ;
  };
  // Control/status register
  struct CSR : reg<base + 0x24, 0x0C000000>
  {
    static constexpr type
    // Internal low-speed oscillator enable (bits: 0)
     LSION_MASK = 0x00000001
    ,LSION_POS = 0
    ,LSION = 0x00000001
    // Internal low-speed oscillator ready (bits: 1)
    ,LSIRDY_MASK = 0x00000002
    ,LSIRDY_POS = 1
    ,LSIRDY = 0x00000002
    // Remove reset flag (bits: 24)
    ,RMVF_MASK = 0x01000000
    ,RMVF_POS = 24
    ,RMVF = 0x01000000
    // PIN reset flag (bits: 26)
    ,PINRSTF_MASK = 0x04000000
    ,PINRSTF_POS = 26
    ,PINRSTF = 0x04000000
    // POR/PDR reset flag (bits: 27)
    ,PORRSTF_MASK = 0x08000000
    ,PORRSTF_POS = 27
    ,PORRSTF = 0x08000000
    // Software reset flag (bits: 28)
    ,SFTRSTF_MASK = 0x10000000
    ,SFTRSTF_POS = 28
    ,SFTRSTF = 0x10000000
    // Independent watchdog reset flag (bits: 29)
    ,IWDGRSTF_MASK = 0x20000000
    ,IWDGRSTF_POS = 29
    ,IWDGRSTF = 0x20000000
    // Window watchdog reset flag (bits: 30)
    ,WWDGRSTF_MASK = 0x40000000
    ,WWDGRSTF_POS = 30
    ,WWDGRSTF = 0x40000000
    // Low-power reset flag (bits: 31)
    ,LPWRRSTF_MASK = 0x80000000
    ,LPWRRSTF_POS = 31
    ,LPWRRSTF = 0x80000000
    ,CSR_MASK = 0xFD000003
    ;
  };
}; // struct RCC

} // namespace lmcu::device

