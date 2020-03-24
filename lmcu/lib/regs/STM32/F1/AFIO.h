/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// Alternate function I/Os
// ------------------------------------------------------------------------------------------------
struct AFIO
{
  static constexpr std::uintptr_t base = 0x40010000UL;

  // Event control register
  struct EVCR : reg<base + 0x0>
  {
    static constexpr type
    // Select the pin used to output the Cortex® EVENTOUT signal. (bits: 3-0)
     PIN_MASK = 0x0000000F
    ,PIN_POS = 0
    ,PIN_0 = 0x00000000 // Px0 selected
    ,PIN_1 = 0x00000001 // Px1 selected
    ,PIN_2 = 0x00000002 // Px2 selected
    ,PIN_3 = 0x00000003 // Px3 selected
    ,PIN_4 = 0x00000004 // Px4 selected
    ,PIN_5 = 0x00000005 // Px5 selected
    ,PIN_6 = 0x00000006 // Px6 selected
    ,PIN_7 = 0x00000007 // Px7 selected
    ,PIN_8 = 0x00000008 // Px8 selected
    ,PIN_9 = 0x00000009 // Px9 selected
    ,PIN_10 = 0x0000000A // Px10 selected
    ,PIN_11 = 0x0000000B // Px11 selected
    ,PIN_12 = 0x0000000C // Px12 selected
    ,PIN_13 = 0x0000000D // Px13 selected
    ,PIN_14 = 0x0000000E // Px14 selected
    ,PIN_15 = 0x0000000F // Px15 selected
    // Port selection (bits: 6-4)
    ,PORT_MASK = 0x00000070
    ,PORT_POS = 4
    ,PORT_A = 0x00000000 // PA selected
    ,PORT_B = 0x00000010 // PB selected
    ,PORT_C = 0x00000020 // PC selected
    ,PORT_D = 0x00000030 // PD selected
    ,PORT_E = 0x00000040 // PE selected
    // Event output enable (bits: 7)
    ,EVOE_MASK = 0x00000080
    ,EVOE_POS = 7
    ,EVOE = 0x00000080
    ,EVCR_MASK = 0x000000FF
    ;
  };
  // AF remap and debug I/O configuration register
  struct MAPR : reg<base + 0x4>
  {
    static constexpr type
    // SPI1 remapping (bits: 0)
     SPI1_REMAP_MASK = 0x00000001
    ,SPI1_REMAP_POS = 0
    ,SPI1_REMAP = 0x00000001
    // I2C1 remapping (bits: 1)
    ,I2C1_REMAP_MASK = 0x00000002
    ,I2C1_REMAP_POS = 1
    ,I2C1_REMAP = 0x00000002
    // USART1 remapping (bits: 2)
    ,USART1_REMAP_MASK = 0x00000004
    ,USART1_REMAP_POS = 2
    ,USART1_REMAP = 0x00000004
    // USART2 remapping (bits: 3)
    ,USART2_REMAP_MASK = 0x00000008
    ,USART2_REMAP_POS = 3
    ,USART2_REMAP = 0x00000008
    // USART3 remapping (bits: 5-4)
    ,USART3_REMAP_MASK = 0x00000030
    ,USART3_REMAP_POS = 4
    ,USART3_REMAP_NO_REMAP = 0x00000000 // No remap (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
    ,USART3_REMAP_PARTIAL_REMAP = 0x00000010 // Partial remap (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
    ,USART3_REMAP_FULL_REMAP = 0x00000030 // Full remap (TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12)
    // TIM1 remapping (bits: 7-6)
    ,TIM1_REMAP_MASK = 0x000000C0
    ,TIM1_REMAP_POS = 6
    ,TIM1_REMAP_NO_REMAP = 0x00000000 // No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
    ,TIM1_REMAP_PARTIAL_REMAP = 0x00000040 // Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1)
    ,TIM1_REMAP_FULL_REMAP = 0x000000C0 // Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12)
    // TIM2 remapping (bits: 9-8)
    ,TIM2_REMAP_MASK = 0x00000300
    ,TIM2_REMAP_POS = 8
    ,TIM2_REMAP_NO_REMAP = 0x00000000 // No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
    ,TIM2_REMAP_PARTIAL_REMAP1 = 0x00000100 // Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
    ,TIM2_REMAP_PARTIAL_REMAP2 = 0x00000200 // Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
    ,TIM2_REMAP_FULL_REMAP = 0x00000300 // Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
    // TIM3 remapping (bits: 11-10)
    ,TIM3_REMAP_MASK = 0x00000C00
    ,TIM3_REMAP_POS = 10
    ,TIM3_REMAP_NO_REMAP = 0x00000000 // No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
    ,TIM3_REMAP_PARTIAL_REMAP = 0x00000800 // Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
    ,TIM3_REMAP_FULL_REMAP = 0x00000C00 // Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
    // TIM4 remapping (bits: 12)
    ,TIM4_REMAP_MASK = 0x00001000
    ,TIM4_REMAP_POS = 12
    ,TIM4_REMAP = 0x00001000
    // CAN alternate function remapping (bits: 14-13)
    ,CAN1_REMAP_MASK = 0x00006000
    ,CAN1_REMAP_POS = 13
    ,CAN1_REMAP_NO_REMAP = 0x00000000 // CAN_RX mapped to PA11, CAN_TX mapped to PA12
    ,CAN1_REMAP_FULL_REMAP1 = 0x00004000 // CAN_RX mapped to PB8, CAN_TX mapped to PB9 (not available on 36-pin package)
    ,CAN1_REMAP_FULL_REMAP2 = 0x00006000 // CAN_RX mapped to PD0, CAN_TX mapped to PD1
    // Port D0/Port D1 mapping on OSC_IN/OSC_OUT (bits: 15)
    ,PD01_REMAP_MASK = 0x00008000
    ,PD01_REMAP_POS = 15
    ,PD01_REMAP = 0x00008000
    // TIM5 channel4 internal remap (bits: 16)
    ,TIM5CH4_IREMAP_MASK = 0x00010000
    ,TIM5CH4_IREMAP_POS = 16
    ,TIM5CH4_IREMAP = 0x00010000
    // ADC1 External trigger injected conversion remapping (bits: 17)
    ,ADC1_ETRGINJ_REMAP_MASK = 0x00020000
    ,ADC1_ETRGINJ_REMAP_POS = 17
    ,ADC1_ETRGINJ_REMAP = 0x00020000
    // ADC1 external trigger regular conversion remapping (bits: 18)
    ,ADC1_ETRGREG_REMAP_MASK = 0x00040000
    ,ADC1_ETRGREG_REMAP_POS = 18
    ,ADC1_ETRGREG_REMAP = 0x00040000
    // ADC2 external trigger injected conversion remapping (bits: 19)
    ,ADC2_ETRGINJ_REMAP_MASK = 0x00080000
    ,ADC2_ETRGINJ_REMAP_POS = 19
    ,ADC2_ETRGINJ_REMAP = 0x00080000
    // ADC2 external trigger regular conversion remapping (bits: 20)
    ,ADC2_ETRGREG_REMAP_MASK = 0x00100000
    ,ADC2_ETRGREG_REMAP_POS = 20
    ,ADC2_ETRGREG_REMAP = 0x00100000
    // Serial wire JTAG configuration (bits: 26-24)
    ,SWJ_CFG_MASK = 0x07000000
    ,SWJ_CFG_POS = 24
    ,SWJ_CFG_FULL_SWJ = 0x00000000 // Full SWJ (JTAG-DP + SW-DP)
    ,SWJ_CFG_FULL_SWJ_WITHOUT_NJTRST = 0x01000000 // Full SWJ (JTAG-DP + SW-DP) but without NJTRST
    ,SWJ_CFG_JTAG_DP_DISABLED_SW_DP_ENABLED = 0x02000000 // JTAG-DP Disabled and SW-DP Enabled
    ,SWJ_CFG_JTAG_DP_DISABLED_SW_DP_DISABLED = 0x04000000 // JTAG-DP Disabled and SW-DP Disabled
    ,MAPR_MASK = 0x071FFFFF
    ;
  };
  // External interrupt configuration register 1
  struct EXTICR1 : reg<base + 0x8>
  {
    static constexpr type
    // EXTI x configuration (bits: 3-0)
     EXTI0_MASK = 0x0000000F
    ,EXTI0_POS = 0
    ,EXTI0_PA = 0x00000000 // PA[x] pin
    ,EXTI0_PB = 0x00000001 // PB[x] pin
    ,EXTI0_PC = 0x00000002 // PC[x] pin
    ,EXTI0_PD = 0x00000003 // PD[x] pin
    ,EXTI0_PE = 0x00000004 // PE[x] pin
    ,EXTI0_PF = 0x00000005 // PF[x] pin
    ,EXTI0_PG = 0x00000006 // PG[x] pin
    // EXTI x configuration (bits: 7-4)
    ,EXTI1_MASK = 0x000000F0
    ,EXTI1_POS = 4
    ,EXTI1_PA = 0x00000000 // PA[x] pin
    ,EXTI1_PB = 0x00000010 // PB[x] pin
    ,EXTI1_PC = 0x00000020 // PC[x] pin
    ,EXTI1_PD = 0x00000030 // PD[x] pin
    ,EXTI1_PE = 0x00000040 // PE[x] pin
    ,EXTI1_PF = 0x00000050 // PF[x] pin
    ,EXTI1_PG = 0x00000060 // PG[x] pin
    // EXTI x configuration (bits: 11-8)
    ,EXTI2_MASK = 0x00000F00
    ,EXTI2_POS = 8
    ,EXTI2_PA = 0x00000000 // PA[x] pin
    ,EXTI2_PB = 0x00000100 // PB[x] pin
    ,EXTI2_PC = 0x00000200 // PC[x] pin
    ,EXTI2_PD = 0x00000300 // PD[x] pin
    ,EXTI2_PE = 0x00000400 // PE[x] pin
    ,EXTI2_PF = 0x00000500 // PF[x] pin
    ,EXTI2_PG = 0x00000600 // PG[x] pin
    // EXTI x configuration (bits: 15-12)
    ,EXTI3_MASK = 0x0000F000
    ,EXTI3_POS = 12
    ,EXTI3_PA = 0x00000000 // PA[x] pin
    ,EXTI3_PB = 0x00001000 // PB[x] pin
    ,EXTI3_PC = 0x00002000 // PC[x] pin
    ,EXTI3_PD = 0x00003000 // PD[x] pin
    ,EXTI3_PE = 0x00004000 // PE[x] pin
    ,EXTI3_PF = 0x00005000 // PF[x] pin
    ,EXTI3_PG = 0x00006000 // PG[x] pin
    ,EXTICR1_MASK = 0x0000FFFF
    ;
  };
  // External interrupt configuration register 2
  struct EXTICR2 : reg<base + 0xC>
  {
    static constexpr type
    // EXTI x configuration (bits: 3-0)
     EXTI4_MASK = 0x0000000F
    ,EXTI4_POS = 0
    ,EXTI4_PA = 0x00000000 // PA[x] pin
    ,EXTI4_PB = 0x00000001 // PB[x] pin
    ,EXTI4_PC = 0x00000002 // PC[x] pin
    ,EXTI4_PD = 0x00000003 // PD[x] pin
    ,EXTI4_PE = 0x00000004 // PE[x] pin
    ,EXTI4_PF = 0x00000005 // PF[x] pin
    ,EXTI4_PG = 0x00000006 // PG[x] pin
    // EXTI x configuration (bits: 7-4)
    ,EXTI5_MASK = 0x000000F0
    ,EXTI5_POS = 4
    ,EXTI5_PA = 0x00000000 // PA[x] pin
    ,EXTI5_PB = 0x00000010 // PB[x] pin
    ,EXTI5_PC = 0x00000020 // PC[x] pin
    ,EXTI5_PD = 0x00000030 // PD[x] pin
    ,EXTI5_PE = 0x00000040 // PE[x] pin
    ,EXTI5_PF = 0x00000050 // PF[x] pin
    ,EXTI5_PG = 0x00000060 // PG[x] pin
    // EXTI x configuration (bits: 11-8)
    ,EXTI6_MASK = 0x00000F00
    ,EXTI6_POS = 8
    ,EXTI6_PA = 0x00000000 // PA[x] pin
    ,EXTI6_PB = 0x00000100 // PB[x] pin
    ,EXTI6_PC = 0x00000200 // PC[x] pin
    ,EXTI6_PD = 0x00000300 // PD[x] pin
    ,EXTI6_PE = 0x00000400 // PE[x] pin
    ,EXTI6_PF = 0x00000500 // PF[x] pin
    ,EXTI6_PG = 0x00000600 // PG[x] pin
    // EXTI x configuration (bits: 15-12)
    ,EXTI7_MASK = 0x0000F000
    ,EXTI7_POS = 12
    ,EXTI7_PA = 0x00000000 // PA[x] pin
    ,EXTI7_PB = 0x00001000 // PB[x] pin
    ,EXTI7_PC = 0x00002000 // PC[x] pin
    ,EXTI7_PD = 0x00003000 // PD[x] pin
    ,EXTI7_PE = 0x00004000 // PE[x] pin
    ,EXTI7_PF = 0x00005000 // PF[x] pin
    ,EXTI7_PG = 0x00006000 // PG[x] pin
    ,EXTICR2_MASK = 0x0000FFFF
    ;
  };
  // External interrupt configuration register 3
  struct EXTICR3 : reg<base + 0x10>
  {
    static constexpr type
    // EXTI x configuration (bits: 3-0)
     EXTI4_MASK = 0x0000000F
    ,EXTI4_POS = 0
    ,EXTI4_PA = 0x00000000 // PA[x] pin
    ,EXTI4_PB = 0x00000001 // PB[x] pin
    ,EXTI4_PC = 0x00000002 // PC[x] pin
    ,EXTI4_PD = 0x00000003 // PD[x] pin
    ,EXTI4_PE = 0x00000004 // PE[x] pin
    ,EXTI4_PF = 0x00000005 // PF[x] pin
    ,EXTI4_PG = 0x00000006 // PG[x] pin
    // EXTI x configuration (bits: 7-4)
    ,EXTI5_MASK = 0x000000F0
    ,EXTI5_POS = 4
    ,EXTI5_PA = 0x00000000 // PA[x] pin
    ,EXTI5_PB = 0x00000010 // PB[x] pin
    ,EXTI5_PC = 0x00000020 // PC[x] pin
    ,EXTI5_PD = 0x00000030 // PD[x] pin
    ,EXTI5_PE = 0x00000040 // PE[x] pin
    ,EXTI5_PF = 0x00000050 // PF[x] pin
    ,EXTI5_PG = 0x00000060 // PG[x] pin
    // EXTI x configuration (bits: 11-8)
    ,EXTI6_MASK = 0x00000F00
    ,EXTI6_POS = 8
    ,EXTI6_PA = 0x00000000 // PA[x] pin
    ,EXTI6_PB = 0x00000100 // PB[x] pin
    ,EXTI6_PC = 0x00000200 // PC[x] pin
    ,EXTI6_PD = 0x00000300 // PD[x] pin
    ,EXTI6_PE = 0x00000400 // PE[x] pin
    ,EXTI6_PF = 0x00000500 // PF[x] pin
    ,EXTI6_PG = 0x00000600 // PG[x] pin
    // EXTI x configuration (bits: 15-12)
    ,EXTI7_MASK = 0x0000F000
    ,EXTI7_POS = 12
    ,EXTI7_PA = 0x00000000 // PA[x] pin
    ,EXTI7_PB = 0x00001000 // PB[x] pin
    ,EXTI7_PC = 0x00002000 // PC[x] pin
    ,EXTI7_PD = 0x00003000 // PD[x] pin
    ,EXTI7_PE = 0x00004000 // PE[x] pin
    ,EXTI7_PF = 0x00005000 // PF[x] pin
    ,EXTI7_PG = 0x00006000 // PG[x] pin
    ,EXTICR3_MASK = 0x0000FFFF
    ;
  };
  // External interrupt configuration register 4
  struct EXTICR4 : reg<base + 0x14>
  {
    static constexpr type
    // EXTI x configuration (bits: 3-0)
     EXTI12_MASK = 0x0000000F
    ,EXTI12_POS = 0
    ,EXTI12_PA = 0x00000000 // PA[x] pin
    ,EXTI12_PB = 0x00000001 // PB[x] pin
    ,EXTI12_PC = 0x00000002 // PC[x] pin
    ,EXTI12_PD = 0x00000003 // PD[x] pin
    ,EXTI12_PE = 0x00000004 // PE[x] pin
    ,EXTI12_PF = 0x00000005 // PF[x] pin
    ,EXTI12_PG = 0x00000006 // PG[x] pin
    // EXTI x configuration (bits: 7-4)
    ,EXTI13_MASK = 0x000000F0
    ,EXTI13_POS = 4
    ,EXTI13_PA = 0x00000000 // PA[x] pin
    ,EXTI13_PB = 0x00000010 // PB[x] pin
    ,EXTI13_PC = 0x00000020 // PC[x] pin
    ,EXTI13_PD = 0x00000030 // PD[x] pin
    ,EXTI13_PE = 0x00000040 // PE[x] pin
    ,EXTI13_PF = 0x00000050 // PF[x] pin
    ,EXTI13_PG = 0x00000060 // PG[x] pin
    // EXTI x configuration (bits: 11-8)
    ,EXTI14_MASK = 0x00000F00
    ,EXTI14_POS = 8
    ,EXTI14_PA = 0x00000000 // PA[x] pin
    ,EXTI14_PB = 0x00000100 // PB[x] pin
    ,EXTI14_PC = 0x00000200 // PC[x] pin
    ,EXTI14_PD = 0x00000300 // PD[x] pin
    ,EXTI14_PE = 0x00000400 // PE[x] pin
    ,EXTI14_PF = 0x00000500 // PF[x] pin
    ,EXTI14_PG = 0x00000600 // PG[x] pin
    // EXTI x configuration (bits: 15-12)
    ,EXTI15_MASK = 0x0000F000
    ,EXTI15_POS = 12
    ,EXTI15_PA = 0x00000000 // PA[x] pin
    ,EXTI15_PB = 0x00001000 // PB[x] pin
    ,EXTI15_PC = 0x00002000 // PC[x] pin
    ,EXTI15_PD = 0x00003000 // PD[x] pin
    ,EXTI15_PE = 0x00004000 // PE[x] pin
    ,EXTI15_PF = 0x00005000 // PF[x] pin
    ,EXTI15_PG = 0x00006000 // PG[x] pin
    ,EXTICR4_MASK = 0x0000FFFF
    ;
  };
  // AF remap and debug I/O configuration register 2
  struct MAPR2 : reg<base + 0x1C>
  {
    static constexpr type
    // TIM9 remapping (bits: 5)
     TIM9_REMAP_MASK = 0x00000020
    ,TIM9_REMAP_POS = 5
    ,TIM9_REMAP = 0x00000020
    // TIM10 remapping (bits: 6)
    ,TIM10_REMAP_MASK = 0x00000040
    ,TIM10_REMAP_POS = 6
    ,TIM10_REMAP = 0x00000040
    // TIM11 remapping (bits: 7)
    ,TIM11_REMAP_MASK = 0x00000080
    ,TIM11_REMAP_POS = 7
    ,TIM11_REMAP = 0x00000080
    // TIM13 remapping (bits: 8)
    ,TIM13_REMAP_MASK = 0x00000100
    ,TIM13_REMAP_POS = 8
    ,TIM13_REMAP = 0x00000100
    // TIM14 remapping (bits: 9)
    ,TIM14_REMAP_MASK = 0x00000200
    ,TIM14_REMAP_POS = 9
    ,TIM14_REMAP = 0x00000200
    // NADV connect/disconnect (bits: 10)
    ,FSMC_NADV_MASK = 0x00000400
    ,FSMC_NADV_POS = 10
    ,FSMC_NADV = 0x00000400
    ,MAPR2_MASK = 0x000007E0
    ;
  };
}; // struct AFIO

} // namespace lmcu::device

