/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// CLK Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct CLK
{
  static constexpr auto ip_ver = ip_version::_1;

  // System Power-down Control Register
  struct PWRCON : reg<ip_ver, base + 0x0, 0x00000010>
  {
    static constexpr typename PWRCON::type
    // 4~24 MHz External High Speed Crystal Oscillator (HXT) Enable Control (Write Protect) The bit default value is set by flash controller user configuration register CONFIG0 [26:24]. When the default clock source is from 4~24 MHz external high speed crystal oscillator, this bit is set to 1 automatically. Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 0)
     XTL12M_EN_MASK = 0x00000001
    ,XTL12M_EN_POS = 0
    ,XTL12M_EN_0 = 0x00000000 // 4 ~ 24 MHz external high speed crystal oscillator (HXT) Disabled
    ,XTL12M_EN_1 = 0x00000001 // 4 ~ 24 MHz external high speed crystal oscillator (HXT) Enabled
    // 22.1184 MHz Internal High Speed RC Oscillator (HIRC) Enable Control (Write Protect) Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 2)
    ,OSC22M_EN_MASK = 0x00000004
    ,OSC22M_EN_POS = 2
    ,OSC22M_EN_0 = 0x00000000 // 22.1184 MHz internal high speed RC oscillator (HIRC) Disabled
    ,OSC22M_EN_1 = 0x00000004 // 22.1184 MHz internal high speed RC oscillator (HIRC) Enabled
    // 10 KHz Internal Low Speed RC Oscillator (LIRC) Enable Control (Write Protect) Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 3)
    ,OSC10K_EN_MASK = 0x00000008
    ,OSC10K_EN_POS = 3
    ,OSC10K_EN_0 = 0x00000000 // 10 kHz internal low speed RC oscillator (LIRC) Disabled
    ,OSC10K_EN_1 = 0x00000008 // 10 kHz internal low speed RC oscillator (LIRC) Enabled
    // Wake-Up Delay Counter Enable Control (Write Protect) When the chip wakes up from Power-down mode, the clock control will delay certain clock cycles to wait system clock stable. The delayed clock cycle is 4096 clock cycles when chip works at 4~24 MHz external high speed crystal oscillator (HXT), and 256 clock cycles when chip works at 22.1184 MHz internal high speed oscillator (HIRC). Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 4)
    ,PD_WU_DLY_MASK = 0x00000010
    ,PD_WU_DLY_POS = 4
    ,PD_WU_DLY_0 = 0x00000000 // Clock cycles delay Disabled
    ,PD_WU_DLY_1 = 0x00000010 // Clock cycles delay Enabled
    // Power-Down Mode Wake-Up Interrupt Enable Control (Write Protect) Note1: The interrupt will occur when both PD_WU_STS and PD_WU_INT_EN are high. Note2: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 5)
    ,PD_WU_INT_EN_MASK = 0x00000020
    ,PD_WU_INT_EN_POS = 5
    ,PD_WU_INT_EN_0 = 0x00000000 // Power-down mode wake-up interrupt Disabled
    ,PD_WU_INT_EN_1 = 0x00000020 // Power-down mode wake-up interrupt Enabled
    // Power-Down Mode Wake-Up Interrupt Status Set by <Power-down wake-up event>, it indicates that resume from Power-down mode. The flag is set if the GPIO, UART, WDT, I2C, TIMER, CAN, or BOD wake-up occurred. Write 1 to clear the bit to 0. Note: This bit is working only if PD_WU_INT_EN (PWRCON[5]) set to 1. (bits: 6)
    ,PD_WU_STS_MASK = 0x00000040
    ,PD_WU_STS_POS = 6
    ,PD_WU_STS = 0x00000040
    // System Power-Down Enable Control (Write Protect) When this bit is set to 1, Power-down mode is enabled and chip Power-down behavior will depends on the PD_WAIT_CPU bit (a) If the PD_WAIT_CPU is 0, the chip enters Power-down mode immediately after the PWR_DOWN_EN bit set. (b) if the PD_WAIT_CPU is 1, the chip keeps active till the CPU sleep mode is also active and then the chip enters Power-down mode (recommend) When chip wakes up from Power-down mode, this bit is cleared by hardware. User needs to set this bit again for next Power-down. In Power-down mode, 4~24 MHz external high speed crystal oscillator (HXT) and the 22.1184 MHz internal high speed RC oscillator (HIRC) will be disabled in this mode, but the 10 kHz internal low speed RC oscillator (LIRC) is not controlled by Power-down mode. In Power- down mode, the PLL and system clock are disabled, and ignored the clock source selection. The clocks of peripheral are not controlled by Power-down mode, if the peripheral clock source is from the 10 kHz internal low speed RC oscillator (LIRC). Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 7)
    ,PWR_DOWN_EN_MASK = 0x00000080
    ,PWR_DOWN_EN_POS = 7
    ,PWR_DOWN_EN_0 = 0x00000000 // Chip operating normally or chip in Idle mode because of WFI command
    ,PWR_DOWN_EN_1 = 0x00000080 // Chip enters Power-down mode instantly or waits CPU sleep command WFI
    // Power-Down Entry Condition Control (Write Protect) Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 8)
    ,PD_WAIT_CPU_MASK = 0x00000100
    ,PD_WAIT_CPU_POS = 8
    ,PD_WAIT_CPU_0 = 0x00000000 // Chip enters Power-down mode when the PWR_DOWN_EN bit is set to 1
    ,PD_WAIT_CPU_1 = 0x00000100 // Chip enters Power- down mode when the both PD_WAIT_CPU and PWR_DOWN_EN bits are set to 1 and CPU runs WFI instruction
    ,PWRCON_MASK = 0x000001FD
    ;
  };
  // AHB Devices Clock Enable Control Register
  struct AHBCLK : reg<ip_ver, base + 0x4, 0x00000005>
  {
    static constexpr typename AHBCLK::type
    // Flash ISP Controller Clock Enable Control (bits: 2)
     ISP_EN_MASK = 0x00000004
    ,ISP_EN_POS = 2
    ,ISP_EN_0 = 0x00000000 // Flash ISP peripherial clock Disabled
    ,ISP_EN_1 = 0x00000004 // Flash ISP peripherial clock Enabled
    ,AHBCLK_MASK = 0x00000004
    ;
  };
  // APB Devices Clock Enable Control Register
  struct APBCLK : reg<ip_ver, base + 0x8>
  {
    static constexpr typename APBCLK::type
    // Watchdog Timer Clock Enable Control (Write Protect) Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 0)
     WDT_EN_MASK = 0x00000001
    ,WDT_EN_POS = 0
    ,WDT_EN_0 = 0x00000000 // Watchdog Timer clock Disabled
    ,WDT_EN_1 = 0x00000001 // Watchdog Timer clock Enabled
    // Timer0 Clock Enable Control (bits: 2)
    ,TMR0_EN_MASK = 0x00000004
    ,TMR0_EN_POS = 2
    ,TMR0_EN_0 = 0x00000000 // Timer0 clock Disabled
    ,TMR0_EN_1 = 0x00000004 // Timer0 clock Enabled
    // Timer1 Clock Enable Control (bits: 3)
    ,TMR1_EN_MASK = 0x00000008
    ,TMR1_EN_POS = 3
    ,TMR1_EN_0 = 0x00000000 // Timer1 clock Disabled
    ,TMR1_EN_1 = 0x00000008 // Timer1 clock Enabled
    // Timer2 Clock Enable Control (bits: 4)
    ,TMR2_EN_MASK = 0x00000010
    ,TMR2_EN_POS = 4
    ,TMR2_EN_0 = 0x00000000 // Timer2 clock Disabled
    ,TMR2_EN_1 = 0x00000010 // Timer2 clock Enabled
    // Timer3 Clock Enable Control (bits: 5)
    ,TMR3_EN_MASK = 0x00000020
    ,TMR3_EN_POS = 5
    ,TMR3_EN_0 = 0x00000000 // Timer3 clock Disabled
    ,TMR3_EN_1 = 0x00000020 // Timer3 clock Enabled
    // Frequency Divider Output Clock Enable Control (bits: 6)
    ,FDIV_EN_MASK = 0x00000040
    ,FDIV_EN_POS = 6
    ,FDIV_EN_0 = 0x00000000 // FDIV clock Disabled
    ,FDIV_EN_1 = 0x00000040 // FDIV clock Enabled
    // I2C0 Clock Enable Control (bits: 8)
    ,I2C0_EN_MASK = 0x00000100
    ,I2C0_EN_POS = 8
    ,I2C0_EN_0 = 0x00000000 // I2C0 clock Disabled
    ,I2C0_EN_1 = 0x00000100 // I2C0 clock Enabled
    // I2C1 Clock Enable Control (bits: 9)
    ,I2C1_EN_MASK = 0x00000200
    ,I2C1_EN_POS = 9
    ,I2C1_EN_0 = 0x00000000 // I2C1 clock Disabled
    ,I2C1_EN_1 = 0x00000200 // I2C1 clock Enabled
    // SPI0 Clock Enable Control (bits: 12)
    ,SPI0_EN_MASK = 0x00001000
    ,SPI0_EN_POS = 12
    ,SPI0_EN_0 = 0x00000000 // SPI0 clock Disabled
    ,SPI0_EN_1 = 0x00001000 // SPI0 clock Enabled
    // UART0 Clock Enable Control (bits: 16)
    ,UART0_EN_MASK = 0x00010000
    ,UART0_EN_POS = 16
    ,UART0_EN_0 = 0x00000000 // UART0 clock Disabled
    ,UART0_EN_1 = 0x00010000 // UART0 clock Enabled
    // UART1 Clock Enable Control (bits: 17)
    ,UART1_EN_MASK = 0x00020000
    ,UART1_EN_POS = 17
    ,UART1_EN_0 = 0x00000000 // UART1 clock Disabled
    ,UART1_EN_1 = 0x00020000 // UART1 clock Enabled
    // UART2 Clock Enable Control (bits: 18)
    ,UART2_EN_MASK = 0x00040000
    ,UART2_EN_POS = 18
    ,UART2_EN_0 = 0x00000000 // UART2 clock Disabled
    ,UART2_EN_1 = 0x00040000 // UART2 clock Enabled
    // CAN Bus Controller-0 Clock Enable Control (bits: 24)
    ,CAN0_EN_MASK = 0x01000000
    ,CAN0_EN_POS = 24
    ,CAN0_EN_0 = 0x00000000 // CAN0 clock Disabled
    ,CAN0_EN_1 = 0x01000000 // CAN0 clock Enabled
    // Analog-Digital-Converter (ADC) Clock Enable Control (bits: 28)
    ,ADC_EN_MASK = 0x10000000
    ,ADC_EN_POS = 28
    ,ADC_EN_0 = 0x00000000 // ADC clock Disabled
    ,ADC_EN_1 = 0x10000000 // ADC clock Enabled
    ,APBCLK_MASK = 0x1107137D
    ;
  };
  // Clock Status Monitor Register
  struct CLKSTATUS : reg<ip_ver, base + 0xC>
  {
    static constexpr typename CLKSTATUS::type
    // 4~24 MHz External High Speed Crystal Oscillator (HXT) Clock Source Stable Flag (Read Only) (bits: 0)
     XTL12M_STB_MASK = 0x00000001
    ,XTL12M_STB_POS = 0
    ,XTL12M_STB_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock is not stable or disabled
    ,XTL12M_STB_1 = 0x00000001 // 4~24 MHz external high speed crystal oscillator (HXT) clock is stable and enabled
    // Internal PLL Clock Source Stable Flag (Read Only) (bits: 2)
    ,PLL_STB_MASK = 0x00000004
    ,PLL_STB_POS = 2
    ,PLL_STB_0 = 0x00000000 // Internal PLL clock is not stable or disabled
    ,PLL_STB_1 = 0x00000004 // Internal PLL clock is stable in normal mode
    // Internal 10 KHz Low Speed Oscillator (LIRC) Clock Source Stable Flag (Read Only) (bits: 3)
    ,OSC10K_STB_MASK = 0x00000008
    ,OSC10K_STB_POS = 3
    ,OSC10K_STB_0 = 0x00000000 // 10 kHz internal low speed RC oscillator (LIRC) clock is not stable or disabled
    ,OSC10K_STB_1 = 0x00000008 // 10 kHz internal low speed RC oscillator (LIRC) clock is stable and enabled
    // 22.1184 MHz Internal High Speed RC Oscillator (HIRC) Clock Source Stable Flag (Read Only) (bits: 4)
    ,OSC22M_STB_MASK = 0x00000010
    ,OSC22M_STB_POS = 4
    ,OSC22M_STB_0 = 0x00000000 // 22.1184 MHz internal high speed RC oscillator (HIRC) clock is not stable or disabled
    ,OSC22M_STB_1 = 0x00000010 // 22.1184 MHz internal high speed RC oscillator (HIRC) clock is stable and enabled
    // Clock Switching Fail Flag (Read Only) This bit is an index that if current system clock source is match as user defined at HCLK_S (CLKSEL[2:0]). When user switchs system clock, the system clock source will keep old clock until the new clock is stable. During the period that waiting new clock stable, this bit will be an index shows system clock source is not match as user wanted. (bits: 7)
    ,CLK_SW_FAIL_MASK = 0x00000080
    ,CLK_SW_FAIL_POS = 7
    ,CLK_SW_FAIL_0 = 0x00000000 // Clock switching success
    ,CLK_SW_FAIL_1 = 0x00000080 // Clock switching failure
    ,CLKSTATUS_MASK = 0x0000009D
    ;
  };
  // Clock Source Select Control Register 0
  struct CLKSEL0 : reg<ip_ver, base + 0x10, 0x00000030>
  {
    static constexpr typename CLKSEL0::type
    // HCLK Clock Source Select (Write Protect) Before clock switching, the related clock sources (both pre-select and new-select) must be enabled The 3-bit default value is reloaded from the value of CFOSC (CONFIG0[26:24]) in user configuration register of Flash controller by any reset. Therefore the default value is either 000b or 111b. These bits are protected bit. It means programming this bit needs to write <59h>, <16h>, <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 2-0)
     HCLK_S_MASK = 0x00000007
    ,HCLK_S_POS = 0
    ,HCLK_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,HCLK_S_1 = 0x00000001 // Reserved
    ,HCLK_S_2 = 0x00000002 // Clock source from PLL
    ,HCLK_S_3 = 0x00000003 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,HCLK_S_7 = 0x00000007 // Clock source from 22.1184 MHz internalhigh speed RC oscillator (HIRC)
    // Cortex-M0 SysTick Clock Source Select (Write Protect) (bits: 5-3)
    ,STCLK_S_MASK = 0x00000038
    ,STCLK_S_POS = 3
    ,STCLK_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,STCLK_S_1 = 0x00000008 // Reserved
    ,STCLK_S_2 = 0x00000010 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)/2
    ,STCLK_S_3 = 0x00000018 // Clock source from HCLK/2
    ,STCLK_S_7 = 0x00000038 // Clock source from 22.1184 MHz internal high speed RC oscillator (HIRC)/2
    ,CLKSEL0_MASK = 0x0000003F
    ;
  };
  // Clock Source Select Control Register 1
  struct CLKSEL1 : reg<ip_ver, base + 0x14>
  {
    static constexpr typename CLKSEL1::type
    // Watchdog Timer Clock Source Select (Write Protect) Note: This bit is the protected bit, and programming it needs to write <59h>, <16h>, and <88h> to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 1-0)
     WDT_S_MASK = 0x00000003
    ,WDT_S_POS = 0
    ,WDT_S_0 = 0x00000000 // Reserved
    ,WDT_S_1 = 0x00000001 // Reserved
    ,WDT_S_2 = 0x00000002 // Clock source from HCLK/2048
    ,WDT_S_3 = 0x00000003 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    // ADC Clock Source Select (bits: 3-2)
    ,ADC_S_MASK = 0x0000000C
    ,ADC_S_POS = 2
    ,ADC_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,ADC_S_1 = 0x00000004 // Clock source from PLL
    ,ADC_S_2 = 0x00000008 // Clock source from HCLK
    ,ADC_S_3 = 0x0000000C // Clock source from 22.1184 MHz internal high speed RC oscillator (HIRC)
    // SPI0 Clock Source Selection (bits: 4)
    ,SPI0_S_MASK = 0x00000010
    ,SPI0_S_POS = 4
    ,SPI0_S_0 = 0x00000000 // Clock source from PLL
    ,SPI0_S_1 = 0x00000010 // Clock source from HCLK
    // TIMER0 Clock Source Selection (bits: 10-8)
    ,TMR0_S_MASK = 0x00000700
    ,TMR0_S_POS = 8
    ,TMR0_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,TMR0_S_1 = 0x00000100 // Reserved
    ,TMR0_S_2 = 0x00000200 // Clock source from HCLK
    ,TMR0_S_3 = 0x00000300 // Clock source from external trigger
    ,TMR0_S_5 = 0x00000500 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR0_S_7 = 0x00000700 // Clock source from 22.1184 MHz internal high speed RC oscillator (HIRC)
    // TIMER1 Clock Source Selection (bits: 14-12)
    ,TMR1_S_MASK = 0x00007000
    ,TMR1_S_POS = 12
    ,TMR1_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,TMR1_S_1 = 0x00001000 // Reserved
    ,TMR1_S_2 = 0x00002000 // Clock source from HCLK
    ,TMR1_S_3 = 0x00003000 // Clock source from external trigger
    ,TMR1_S_5 = 0x00005000 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR1_S_7 = 0x00007000 // Clock source from 22.1184 MHz internal high speed RC oscillator (HIRC)
    // TIMER2 Clock Source Selection (bits: 18-16)
    ,TMR2_S_MASK = 0x00070000
    ,TMR2_S_POS = 16
    ,TMR2_S_0 = 0x00000000 // Clock source from external 4~24 MHz high speed crystal oscillator (HXT)
    ,TMR2_S_1 = 0x00010000 // Reserved
    ,TMR2_S_2 = 0x00020000 // Clock source from HCLK
    ,TMR2_S_3 = 0x00030000 // Clock source from external trigger
    ,TMR2_S_5 = 0x00050000 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR2_S_7 = 0x00070000 // Clock source from 22.1184 MHz internal high speed RC oscillator (HIRC)
    // TIMER3 Clock Source Selection (bits: 22-20)
    ,TMR3_S_MASK = 0x00700000
    ,TMR3_S_POS = 20
    ,TMR3_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,TMR3_S_1 = 0x00100000 // Reserved
    ,TMR3_S_2 = 0x00200000 // Clock source from HCLK
    ,TMR3_S_3 = 0x00300000 // Clock source from external trigger
    ,TMR3_S_5 = 0x00500000 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR3_S_7 = 0x00700000 // Clock source from 22.1184 MHz internal high speed RC oscillator (HIRC)
    // UART Clock Source Selection (bits: 25-24)
    ,UART_S_MASK = 0x03000000
    ,UART_S_POS = 24
    ,UART_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART_S_1 = 0x01000000 // Clock source from PLL
    ,UART_S_3 = 0x03000000 // Clock source from 22.1184 MHz internal high speed RC oscillator (HIRC)
    ,CLKSEL1_MASK = 0x0377771F
    ;
  };
  // Clock Divider Number Register
  struct CLKDIV : reg<ip_ver, base + 0x18>
  {
    static constexpr typename CLKDIV::type
    // HCLK Clock Divide Number From HCLK Clock Source (bits: 3-0)
     HCLK_N_MASK = 0x0000000F
    ,HCLK_N_POS = 0
    // UART Clock Divide Number From UART Clock Source (bits: 11-8)
    ,UART_N_MASK = 0x00000F00
    ,UART_N_POS = 8
    // ADC Clock Divide Number From ADC Clock Source (bits: 23-16)
    ,ADC_N_MASK = 0x00FF0000
    ,ADC_N_POS = 16
    ,CLKDIV_MASK = 0x00FF0F0F
    ;
  };
  // Clock Source Select Control Register 2
  struct CLKSEL2 : reg<ip_ver, base + 0x1C, 0x000200FF>
  {
    static constexpr typename CLKSEL2::type
    // Clock Divider Clock Source Selection (bits: 3-2)
     FRQDIV_S_MASK = 0x0000000C
    ,FRQDIV_S_POS = 2
    ,FRQDIV_S_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator clock
    ,FRQDIV_S_1 = 0x00000004 // Reserved
    ,FRQDIV_S_2 = 0x00000008 // Clock source from HCLK
    ,FRQDIV_S_3 = 0x0000000C // Clock source from 22.1184 MHz internal high speed RC oscillator clock
    // Window Watchdog Timer Clock Source Selection (bits: 17-16)
    ,WWDT_S_MASK = 0x00030000
    ,WWDT_S_POS = 16
    ,WWDT_S_2 = 0x00020000 // Clock source from HCLK/2048 clock
    ,WWDT_S_3 = 0x00030000 // Clock source from 10 kHz internal low speed RC oscillator clock
    ,CLKSEL2_MASK = 0x0003000C
    ;
  };
  // PLL Control Register
  struct PLLCON : reg<ip_ver, base + 0x20, 0x0005C22E>
  {
    static constexpr typename PLLCON::type
    // PLL Feedback Divider Control Bits Refer to the formulas below the table. (bits: 8-0)
     FB_DV_MASK = 0x000001FF
    ,FB_DV_POS = 0
    // PLL Input Divider Control Bits Refer to the formulas below the table. (bits: 13-9)
    ,IN_DV_MASK = 0x00003E00
    ,IN_DV_POS = 9
    // PLL Output Divider Control Bits Refer to the formulas below the table. (bits: 15-14)
    ,OUT_DV_MASK = 0x0000C000
    ,OUT_DV_POS = 14
    // Power-Down Mode If the PWR_DOWN_EN bit is set to 1 in PWRCON register, the PLL will enter Power-down mode too. (bits: 16)
    ,PD_MASK = 0x00010000
    ,PD_POS = 16
    ,PD_0 = 0x00000000 // PLL is in Normal mode
    ,PD_1 = 0x00010000 // PLL is in Power-down mode (default)
    // PLL Bypass Control (bits: 17)
    ,BP_MASK = 0x00020000
    ,BP_POS = 17
    ,BP_0 = 0x00000000 // PLL is in Normal mode (default)
    ,BP_1 = 0x00020000 // PLL clock output is same as PLL source clock input
    // PLL OE (FOUT Enable) Pin Control (bits: 18)
    ,OE_MASK = 0x00040000
    ,OE_POS = 18
    ,OE_0 = 0x00000000 // PLL FOUT Enabled
    ,OE_1 = 0x00040000 // PLL FOUT is fixed low
    // PLL Source Clock Selection (bits: 19)
    ,PLL_SRC_MASK = 0x00080000
    ,PLL_SRC_POS = 19
    ,PLL_SRC_0 = 0x00000000 // PLL source clock from 4~24 MHz external high speed crystal oscillator
    ,PLL_SRC_1 = 0x00080000 // PLL source clock from 22.1184 MHz internal high speed RC oscillator
    ,PLLCON_MASK = 0x000FFFFF
    ;
  };
  // Frequency Divider Control Register
  struct FRQDIV : reg<ip_ver, base + 0x24>
  {
    static constexpr typename FRQDIV::type
    // Divider Output Frequency Selection Bits The formula of output frequency is Fin is the input clock frequency. Fout is the frequency of divider output clock. N is the 4-bit value of FSEL[3:0]. (bits: 3-0)
     FSEL_MASK = 0x0000000F
    ,FSEL_POS = 0
    // Frequency Divider Enable Control (bits: 4)
    ,DIVIDER_EN_MASK = 0x00000010
    ,DIVIDER_EN_POS = 4
    ,DIVIDER_EN_0 = 0x00000000 // Frequency divider function Disabled
    ,DIVIDER_EN_1 = 0x00000010 // Frequency divider function Enabled
    // Frequency Divider One Enable Control (bits: 5)
    ,DIVIDER1_MASK = 0x00000020
    ,DIVIDER1_POS = 5
    ,DIVIDER1_0 = 0x00000000 // Frequency divider will output clock with source frequency divided by FSEL
    ,DIVIDER1_1 = 0x00000020 // Frequency divider will output clock with source frequency
    ,FRQDIV_MASK = 0x0000003F
    ;
  };
  // APB Devices Clock Enable Control Register 1
  struct APBCLK1 : reg<ip_ver, base + 0x30>
  {
    static constexpr typename APBCLK1::type
    // UART3 Clock Enable Control (bits: 8)
     UART3_EN_MASK = 0x00000100
    ,UART3_EN_POS = 8
    ,UART3_EN_0 = 0x00000000 // UART3 clock Disabled
    ,UART3_EN_1 = 0x00000100 // UART3 clock Enabled
    // UART4 Clock Enable Control (bits: 9)
    ,UART4_EN_MASK = 0x00000200
    ,UART4_EN_POS = 9
    ,UART4_EN_0 = 0x00000000 // UART4 clock Disabled
    ,UART4_EN_1 = 0x00000200 // UART4 clock Enabled
    // UART5 Clock Enable Control (bits: 10)
    ,UART5_EN_MASK = 0x00000400
    ,UART5_EN_POS = 10
    ,UART5_EN_0 = 0x00000000 // UART5 clock Disabled
    ,UART5_EN_1 = 0x00000400 // UART5 clock Enabled
    // PWM0 Clock Enable Control (bits: 16)
    ,PWM0_EN_MASK = 0x00010000
    ,PWM0_EN_POS = 16
    ,PWM0_EN_0 = 0x00000000 // PWM0 clock Disabled
    ,PWM0_EN_1 = 0x00010000 // PWM0 clock Enabled
    // PWM1 Clock Enable Control (bits: 17)
    ,PWM1_EN_MASK = 0x00020000
    ,PWM1_EN_POS = 17
    ,PWM1_EN_0 = 0x00000000 // PWM1 clock Disabled
    ,PWM1_EN_1 = 0x00020000 // PWM1 clock Enabled
    // BPWM0 Clock Enable Control (bits: 18)
    ,BPWM0_EN_MASK = 0x00040000
    ,BPWM0_EN_POS = 18
    ,BPWM0_EN_0 = 0x00000000 // BPWM0 clock Disabled
    ,BPWM0_EN_1 = 0x00040000 // BPWM0 clock Enabled
    // BPWM1 Clock Enable Control (bits: 19)
    ,BPWM1_EN_MASK = 0x00080000
    ,BPWM1_EN_POS = 19
    ,BPWM1_EN_0 = 0x00000000 // BPWM1 clock Disabled
    ,BPWM1_EN_1 = 0x00080000 // BPWM1 clock Enabled
    ,APBCLK1_MASK = 0x000F0700
    ;
  };
  // Clock Source Select Control Register 3
  struct CLKSEL3 : reg<ip_ver, base + 0x34, 0x000F003F>
  {
    static constexpr typename CLKSEL3::type
    // PWM0 Clock Source Selection The Engine clock source of PWM0 is defined by PWM0_S. (bits: 16)
     PWM0_S_MASK = 0x00010000
    ,PWM0_S_POS = 16
    ,PWM0_S_0 = 0x00000000 // Clock source from PLL
    ,PWM0_S_1 = 0x00010000 // Clock source from PCLK
    // PWM1 Clock Source Selection The Engine clock source of PWM1 is defined by PWM1_S. (bits: 17)
    ,PWM1_S_MASK = 0x00020000
    ,PWM1_S_POS = 17
    ,PWM1_S_0 = 0x00000000 // Clock source from PLL
    ,PWM1_S_1 = 0x00020000 // Clock source from PCLK
    // BPWM0 Clock Source Selection The Engine clock source of BPWM0 is defined by BPWM0_S. (bits: 18)
    ,BPWM0_S_MASK = 0x00040000
    ,BPWM0_S_POS = 18
    ,BPWM0_S_0 = 0x00000000 // Clock source from PLL
    ,BPWM0_S_1 = 0x00040000 // Clock source from PCLK
    // BPWM1 Clock Source Selection The Engine clock source of BPWM1 is defined by BPWM1_S. (bits: 19)
    ,BPWM1_S_MASK = 0x00080000
    ,BPWM1_S_POS = 19
    ,BPWM1_S_0 = 0x00000000 // Clock source from PLL
    ,BPWM1_S_1 = 0x00080000 // Clock source from PCLK
    ,CLKSEL3_MASK = 0x000F0000
    ;
  };
  // Clock Fail Detector Control Register
  struct CLKDCTL : reg<ip_ver, base + 0x70>
  {
    static constexpr typename CLKDCTL::type
    // HXT Clock Fail Detector Enable Control (bits: 4)
     HXTFDEN_MASK = 0x00000010
    ,HXTFDEN_POS = 4
    ,HXTFDEN_0 = 0x00000000 // HXT clock Fail detector Disabled
    ,HXTFDEN_1 = 0x00000010 // HXT clock Fail detector Enabled
    // HXT Clock Fail Interrupt Enable Control (bits: 5)
    ,HXTFIEN_MASK = 0x00000020
    ,HXTFIEN_POS = 5
    ,HXTFIEN_0 = 0x00000000 // HXT clock Fail interrupt Disabled
    ,HXTFIEN_1 = 0x00000020 // HXT clock Fail interrupt Enabled
    // HXT Clock Frequency Monitor Enable Control (bits: 16)
    ,HXTFQDEN_MASK = 0x00010000
    ,HXTFQDEN_POS = 16
    ,HXTFQDEN_0 = 0x00000000 // HXT clock frequency monitor Disabled
    ,HXTFQDEN_1 = 0x00010000 // HXT clock frequency monitor Enabled
    // HXT Clock Frequency Monitor Interrupt Enable Control (bits: 17)
    ,HXTFQIEN_MASK = 0x00020000
    ,HXTFQIEN_POS = 17
    ,HXTFQIEN_0 = 0x00000000 // HXT clock frequency monitor fail interrupt Disabled
    ,HXTFQIEN_1 = 0x00020000 // HXT clock frequency monitor fail interrupt Enabled
    ,CLKDCTL_MASK = 0x00030030
    ;
  };
  // Clock Fail Detector Status Register
  struct CLKDSTS : reg<ip_ver, base + 0x74>
  {
    static constexpr typename CLKDSTS::type
    // HXT Clock Fail Interrupt Flag (bits: 0)
     HXTFIF_MASK = 0x00000001
    ,HXTFIF_POS = 0
    ,HXTFIF_0 = 0x00000000 // HXT clock normal
    ,HXTFIF_1 = 0x00000001 // HXT clock stop (write <1> to clear)
    // HXT Clock Frequency Monitor Interrupt Flag (bits: 8)
    ,HXTFQIF_MASK = 0x00000100
    ,HXTFQIF_POS = 8
    ,HXTFQIF_0 = 0x00000000 // HXT clock normal
    ,HXTFQIF_1 = 0x00000100 // HXT clock frequency abnormal (write <1> to clear)
    ,CLKDSTS_MASK = 0x00000101
    ;
  };
  // Clock Frequency Detector Upper Boundary Register
  struct CDUPB : reg<ip_ver, base + 0x78>
  {
    static constexpr typename CDUPB::type
    // HXT Clock Frequency Detector Upper Boundary The bits define the high value of frequency monitor window. When HXT frequency monitor value higher than this register, the HXT frequency detect fail interrupt flag will set to 1. (bits: 9-0)
     UPERBD_MASK = 0x000003FF
    ,UPERBD_POS = 0
    ,CDUPB_MASK = 0x000003FF
    ;
  };
  // Clock Frequency Detector Lower Boundary Register
  struct CDLOWB : reg<ip_ver, base + 0x7C>
  {
    static constexpr typename CDLOWB::type
    // HXT Clock Frequency Detector Lower Boundary The bits define the low value of frequency monitor window. When HXT frequency monitor values lower than this register, the HXT frequency detect fail interrupt flag will set to 1. (bits: 9-0)
     LOWERBD_MASK = 0x000003FF
    ,LOWERBD_POS = 0
    ,CDLOWB_MASK = 0x000003FF
    ;
  };
}; // struct CLK

} // namespace lmcu::device::ip::v1

