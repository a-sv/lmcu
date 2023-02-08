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
  struct PWRCTL : reg<ip_ver, base + 0x0, 0x00001C1C>
  {
    static constexpr typename PWRCTL::type
    // HXT Enable Bit (Write Protect) The bit default value is set by Flash controller user configuration register CONFIG0 [26:24]. When the default clock source is from HXT, this bit is set to 1 automatically. Note: 1.This bit is write protected. Refer to the SYS_REGLCTL register. 2.When HXT is enabled, GPIO must be set as input mode. (bits: 0)
     HXTEN_MASK = 0x00000001
    ,HXTEN_POS = 0
    ,HXTEN_0 = 0x00000000 // 4~24 MHz external high speed crystal (HXT) Disabled
    ,HXTEN_1 = 0x00000001 // 4~24 MHz external high speed crystal (HXT) Enabled
    // LXT Enable Bit (Write Protect) Note: 1. This bit is write protected. Refer to the SYS_REGLCTL register. 2. When LXT is enabled, GPIO must be set as input mode. (bits: 1)
    ,LXTEN_MASK = 0x00000002
    ,LXTEN_POS = 1
    ,LXTEN_0 = 0x00000000 // 32.768 kHz external low speed crystal (LXT) Disabled
    ,LXTEN_1 = 0x00000002 // 32.768 kHz external low speed crystal (LXT) Enabled
    // HIRC Enable Bit (Write Protect) Note:1.This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 2)
    ,HIRCEN_MASK = 0x00000004
    ,HIRCEN_POS = 2
    ,HIRCEN_0 = 0x00000000 // 12 MHz internal high speed RC oscillator (HIRC) Disabled
    ,HIRCEN_1 = 0x00000004 // 12 MHz internal high speed RC oscillator (HIRC) Enabled
    // LIRC Enable Bit (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 3)
    ,LIRCEN_MASK = 0x00000008
    ,LIRCEN_POS = 3
    ,LIRCEN_0 = 0x00000000 // 10 kHz internal low speed RC oscillator (LIRC) Disabled
    ,LIRCEN_1 = 0x00000008 // 10 kHz internal low speed RC oscillator (LIRC) Enabled
    // Enable the Wake-up Delay Counter (Write Protect) When the chip wakes up from Power-down mode, the clock control will delay certain clock cycles to wait system clock stable. The delayed clock cycle is 4096 clock cycles when chip works at 4~24 MHz external high speed crystal oscillator (HXT), and 256 clock cycles when chip works at 12 MHz internal high speed RC oscillator (HIRC). Note: This bit is write protected. Refer to the SYS_REGLCTL register (bits: 4)
    ,PDWKDLY_MASK = 0x00000010
    ,PDWKDLY_POS = 4
    ,PDWKDLY_0 = 0x00000000 // Clock cycles delay Disabled
    ,PDWKDLY_1 = 0x00000010 // Clock cycles delay Enabled
    // Power-down Mode Wake-up Interrupt Enable Bit (Write Protect) Note1: The interrupt will occur when both PDWKIF and PDWKIEN are high. Note2: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 5)
    ,PDWKIEN_MASK = 0x00000020
    ,PDWKIEN_POS = 5
    ,PDWKIEN_0 = 0x00000000 // Power-down mode wake-up interrupt Disabled
    ,PDWKIEN_1 = 0x00000020 // Power-down mode wake-up interrupt Enabled
    // Power-down Mode Wake-up Interrupt Status Set by 'Power-down wake-up event', it indicates that resume from Power-down mode' The flag is set if any wake-up source is occurred. Refer Power Modes and Wake-up Sources chapter. Note1: Write 1 to clear the bit to 0. Note2: This bit works only if PDWKIEN (CLK_PWRCTL[5]) set to 1. (bits: 6)
    ,PDWKIF_MASK = 0x00000040
    ,PDWKIF_POS = 6
    ,PDWKIF = 0x00000040
    // System Power-down Enable (Write Protect) When this bit is set to 1, Power-down mode is enabled and chip keeps active till the CPU sleep mode is also active and then the chip enters Power-down mode. When chip wakes up from Power-down mode, this bit is auto cleared. Users need to set this bit again for next Power-down. In Power-down mode, HXT and the HIRC will be disabled in this mode, but LXT and LIRC are not controlled by Power-down mode. In Power-down mode, the PLL and system clock are disabled, and ignored the clock source selection. The clocks of peripheral are not controlled by Power-down mode, if the peripheral clock source is from LXT or LIRC. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 7)
    ,PDEN_MASK = 0x00000080
    ,PDEN_POS = 7
    ,PDEN_0 = 0x00000000 // Chip will not enter Power-down mode after CPU sleep command WFI
    ,PDEN_1 = 0x00000080 // Chip enters Power-down mode after CPU sleep command WFI
    // HXT Gain Control Bit (Write Protect) This is a protected register. Please refer to open lock sequence to program it. Gain control is used to enlarge the gain of crystal to make sure crystal work normally. If gain control is enabled, crystal will consume more power than gain control off. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 11-10)
    ,HXTGAIN_MASK = 0x00000C00
    ,HXTGAIN_POS = 10
    ,HXTGAIN_0 = 0x00000000 // HXT frequency is lower than from 8 MHz
    ,HXTGAIN_1 = 0x00000400 // HXT frequency is from 8 MHz to 12 MHz
    ,HXTGAIN_2 = 0x00000800 // HXT frequency is from 12 MHz to 16 MHz
    ,HXTGAIN_3 = 0x00000C00 // HXT frequency is higher than 16 MHz
    // HXT Crystal Type Select Bit (Write Protect) This is a protected register. Please refer to open lock sequence to program it. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 12)
    ,HXTSELTYP_MASK = 0x00001000
    ,HXTSELTYP_POS = 12
    ,HXTSELTYP_0 = 0x00000000 // Select INV type
    ,HXTSELTYP_1 = 0x00001000 // Select GM type
    // HXT Crystal TURBO Mode (Write Protect) This is a protected register. Please refer to open lock sequence to program it. (bits: 13)
    ,HXTTBEN_MASK = 0x00002000
    ,HXTTBEN_POS = 13
    ,HXTTBEN_0 = 0x00000000 // HXT Crystal TURBO mode Disabled
    ,HXTTBEN_1 = 0x00002000 // HXT Crystal TURBO mode Enabled
    // HIRC Stable Count Select (Write Protect ) Others: Reserved Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 17-16)
    ,HIRCSTBS_MASK = 0x00030000
    ,HIRCSTBS_POS = 16
    ,HIRCSTBS_0 = 0x00000000 // HIRC stable count = 64 clocks
    ,HIRCSTBS_1 = 0x00010000 // HIRC stable count = 24 clocks
    // HIRC48M Enable Bit (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 18)
    ,HIRC48MEN_MASK = 0x00040000
    ,HIRC48MEN_POS = 18
    ,HIRC48MEN_0 = 0x00000000 // 48 MHz internal high speed RC oscillator (HIRC48M) Disabled
    ,HIRC48MEN_1 = 0x00040000 // 48 MHz internal high speed RC oscillator (HIRC48M) Enabled
    ,PWRCTL_MASK = 0x00073CFF
    ;
  };
  // AHB Devices Clock Enable Control Register
  struct AHBCLK : reg<ip_ver, base + 0x4, 0x00008004>
  {
    static constexpr typename AHBCLK::type
    // PDMA Controller Clock Enable Bit (bits: 1)
     PDMACKEN_MASK = 0x00000002
    ,PDMACKEN_POS = 1
    ,PDMACKEN_0 = 0x00000000 // PDMA peripheral clock Disabled
    ,PDMACKEN_1 = 0x00000002 // PDMA peripheral clock Enabled
    // Flash ISP Controller Clock Enable Bit (bits: 2)
    ,ISPCKEN_MASK = 0x00000004
    ,ISPCKEN_POS = 2
    ,ISPCKEN_0 = 0x00000000 // Flash ISP peripheral clock Disabled
    ,ISPCKEN_1 = 0x00000004 // Flash ISP peripheral clock Enabled
    // EBI Controller Clock Enable Bit (bits: 3)
    ,EBICKEN_MASK = 0x00000008
    ,EBICKEN_POS = 3
    ,EBICKEN_0 = 0x00000000 // EBI peripheral clock Disabled
    ,EBICKEN_1 = 0x00000008 // EBI peripheral clock Enabled
    // Ethernet Controller Clock Enable Bit (bits: 5)
    ,EMACCKEN_MASK = 0x00000020
    ,EMACCKEN_POS = 5
    ,EMACCKEN_0 = 0x00000000 // Ethernet Controller engine clock Disabled
    ,EMACCKEN_1 = 0x00000020 // Ethernet Controller engine clock Enabled
    // SD0 Controller Clock Enable Bit (bits: 6)
    ,SDH0CKEN_MASK = 0x00000040
    ,SDH0CKEN_POS = 6
    ,SDH0CKEN_0 = 0x00000000 // SD0 engine clock Disabled
    ,SDH0CKEN_1 = 0x00000040 // SD0 engine clock Enabled
    // CRC Generator Controller Clock Enable Bit (bits: 7)
    ,CRCCKEN_MASK = 0x00000080
    ,CRCCKEN_POS = 7
    ,CRCCKEN_0 = 0x00000000 // CRC peripheral clock Disabled
    ,CRCCKEN_1 = 0x00000080 // CRC peripheral clock Enabled
    // Camera Capture Interface Controller Clock Enable Control (bits: 8)
    ,CCAPCKEN_MASK = 0x00000100
    ,CCAPCKEN_POS = 8
    ,CCAPCKEN_0 = 0x00000000 // CCAP controller's clock Disabled
    ,CCAPCKEN_1 = 0x00000100 // CCAP controller's clock Enabled
    // Sensor Clock Enable Control (bits: 9)
    ,SENCKEN_MASK = 0x00000200
    ,SENCKEN_POS = 9
    ,SENCKEN_0 = 0x00000000 // CCAP Sensor clock Disabled
    ,SENCKEN_1 = 0x00000200 // CCAP Sensor clock Enabled
    // HSUSB Device Clock Enable Bit (bits: 10)
    ,HSUSBDCKEN_MASK = 0x00000400
    ,HSUSBDCKEN_POS = 10
    ,HSUSBDCKEN_0 = 0x00000000 // HSUSB device controller's clock Disabled
    ,HSUSBDCKEN_1 = 0x00000400 // HSUSB device controller's clock Enabled
    // Cryptographic Accelerator Clock Enable Bit (bits: 12)
    ,CRPTCKEN_MASK = 0x00001000
    ,CRPTCKEN_POS = 12
    ,CRPTCKEN_0 = 0x00000000 // Cryptographic Accelerator clock Disabled
    ,CRPTCKEN_1 = 0x00001000 // Cryptographic Accelerator clock Enabled
    // SPIM Controller Clock Enable Bit (bits: 14)
    ,SPIMCKEN_MASK = 0x00004000
    ,SPIMCKEN_POS = 14
    ,SPIMCKEN_0 = 0x00000000 // SPIM controller clock Disabled
    ,SPIMCKEN_1 = 0x00004000 // SPIM controller clock Enabled
    // Flash Memory Controller Clock Enable Bit in IDLE Mode (bits: 15)
    ,FMCIDLE_MASK = 0x00008000
    ,FMCIDLE_POS = 15
    ,FMCIDLE_0 = 0x00000000 // FMC clock Disabled when chip is under IDLE mode
    ,FMCIDLE_1 = 0x00008000 // FMC clock Enabled when chip is under IDLE mode
    // USB HOST Controller Clock Enable Bit (bits: 16)
    ,USBHCKEN_MASK = 0x00010000
    ,USBHCKEN_POS = 16
    ,USBHCKEN_0 = 0x00000000 // USB HOST peripheral clock Disabled
    ,USBHCKEN_1 = 0x00010000 // USB HOST peripheral clock Enabled
    // SD1 Controller Clock Enable Bit (bits: 17)
    ,SDH1CKEN_MASK = 0x00020000
    ,SDH1CKEN_POS = 17
    ,SDH1CKEN_0 = 0x00000000 // SD1 engine clock Disabled
    ,SDH1CKEN_1 = 0x00020000 // SD1 engine clock Enabled
    ,AHBCLK_MASK = 0x0003D7EE
    ;
  };
  // APB Devices Clock Enable Control Register 0
  struct APBCLK0 : reg<ip_ver, base + 0x8, 0x00000001>
  {
    static constexpr typename APBCLK0::type
    // Watchdog Timer Clock Enable Bit (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     WDTCKEN_MASK = 0x00000001
    ,WDTCKEN_POS = 0
    ,WDTCKEN_0 = 0x00000000 // Watchdog timer clock Disabled
    ,WDTCKEN_1 = 0x00000001 // Watchdog timer clock Enabled
    // Real-time-clock APB Interface Clock Enable Bit This bit is used to control the RTC APB clock only. The RTC peripheral clock source is selected from RTCSEL(CLK_CLKSEL3[8]). It can be selected to 32.768 kHz external low speed crystal or 10 kHz internal low speed RC oscillator (LIRC). (bits: 1)
    ,RTCCKEN_MASK = 0x00000002
    ,RTCCKEN_POS = 1
    ,RTCCKEN_0 = 0x00000000 // RTC clock Disabled
    ,RTCCKEN_1 = 0x00000002 // RTC clock Enabled
    // Timer0 Clock Enable Bit (bits: 2)
    ,TMR0CKEN_MASK = 0x00000004
    ,TMR0CKEN_POS = 2
    ,TMR0CKEN_0 = 0x00000000 // Timer0 clock Disabled
    ,TMR0CKEN_1 = 0x00000004 // Timer0 clock Enabled
    // Timer1 Clock Enable Bit (bits: 3)
    ,TMR1CKEN_MASK = 0x00000008
    ,TMR1CKEN_POS = 3
    ,TMR1CKEN_0 = 0x00000000 // Timer1 clock Disabled
    ,TMR1CKEN_1 = 0x00000008 // Timer1 clock Enabled
    // Timer2 Clock Enable Bit (bits: 4)
    ,TMR2CKEN_MASK = 0x00000010
    ,TMR2CKEN_POS = 4
    ,TMR2CKEN_0 = 0x00000000 // Timer2 clock Disabled
    ,TMR2CKEN_1 = 0x00000010 // Timer2 clock Enabled
    // Timer3 Clock Enable Bit (bits: 5)
    ,TMR3CKEN_MASK = 0x00000020
    ,TMR3CKEN_POS = 5
    ,TMR3CKEN_0 = 0x00000000 // Timer3 clock Disabled
    ,TMR3CKEN_1 = 0x00000020 // Timer3 clock Enabled
    // CLKO Clock Enable Bit (bits: 6)
    ,CLKOCKEN_MASK = 0x00000040
    ,CLKOCKEN_POS = 6
    ,CLKOCKEN_0 = 0x00000000 // CLKO clock Disabled
    ,CLKOCKEN_1 = 0x00000040 // CLKO clock Enabled
    // Analog Comparator 0/1 Clock Enable Bit (bits: 7)
    ,ACMP01CKEN_MASK = 0x00000080
    ,ACMP01CKEN_POS = 7
    ,ACMP01CKEN_0 = 0x00000000 // Analog comparator 0/1 clock Disabled
    ,ACMP01CKEN_1 = 0x00000080 // Analog comparator 0/1 clock Enabled
    // I2C0 Clock Enable Bit (bits: 8)
    ,I2C0CKEN_MASK = 0x00000100
    ,I2C0CKEN_POS = 8
    ,I2C0CKEN_0 = 0x00000000 // I2C0 clock Disabled
    ,I2C0CKEN_1 = 0x00000100 // I2C0 clock Enabled
    // I2C1 Clock Enable Bit (bits: 9)
    ,I2C1CKEN_MASK = 0x00000200
    ,I2C1CKEN_POS = 9
    ,I2C1CKEN_0 = 0x00000000 // I2C1 clock Disabled
    ,I2C1CKEN_1 = 0x00000200 // I2C1 clock Enabled
    // I2C2 Clock Enable Bit (bits: 10)
    ,I2C2CKEN_MASK = 0x00000400
    ,I2C2CKEN_POS = 10
    ,I2C2CKEN_0 = 0x00000000 // I2C2 clock Disabled
    ,I2C2CKEN_1 = 0x00000400 // I2C2 clock Enabled
    // QSPI0 Clock Enable Bit (bits: 12)
    ,QSPI0CKEN_MASK = 0x00001000
    ,QSPI0CKEN_POS = 12
    ,QSPI0CKEN_0 = 0x00000000 // QSPI0 clock Disabled
    ,QSPI0CKEN_1 = 0x00001000 // QSPI0 clock Enabled
    // SPI0 Clock Enable Bit (bits: 13)
    ,SPI0CKEN_MASK = 0x00002000
    ,SPI0CKEN_POS = 13
    ,SPI0CKEN_0 = 0x00000000 // SPI0 clock Disabled
    ,SPI0CKEN_1 = 0x00002000 // SPI0 clock Enabled
    // SPI1 Clock Enable Bit (bits: 14)
    ,SPI1CKEN_MASK = 0x00004000
    ,SPI1CKEN_POS = 14
    ,SPI1CKEN_0 = 0x00000000 // SPI1 clock Disabled
    ,SPI1CKEN_1 = 0x00004000 // SPI1 clock Enabled
    // SPI2 Clock Enable Bit (bits: 15)
    ,SPI2CKEN_MASK = 0x00008000
    ,SPI2CKEN_POS = 15
    ,SPI2CKEN_0 = 0x00000000 // SPI2 clock Disabled
    ,SPI2CKEN_1 = 0x00008000 // SPI2 clock Enabled
    // UART0 Clock Enable Bit (bits: 16)
    ,UART0CKEN_MASK = 0x00010000
    ,UART0CKEN_POS = 16
    ,UART0CKEN_0 = 0x00000000 // UART0 clock Disabled
    ,UART0CKEN_1 = 0x00010000 // UART0 clock Enabled
    // UART1 Clock Enable Bit (bits: 17)
    ,UART1CKEN_MASK = 0x00020000
    ,UART1CKEN_POS = 17
    ,UART1CKEN_0 = 0x00000000 // UART1 clock Disabled
    ,UART1CKEN_1 = 0x00020000 // UART1 clock Enabled
    // UART2 Clock Enable Bit (bits: 18)
    ,UART2CKEN_MASK = 0x00040000
    ,UART2CKEN_POS = 18
    ,UART2CKEN_0 = 0x00000000 // UART2 clock Disabled
    ,UART2CKEN_1 = 0x00040000 // UART2 clock Enabled
    // UART3 Clock Enable Bit (bits: 19)
    ,UART3CKEN_MASK = 0x00080000
    ,UART3CKEN_POS = 19
    ,UART3CKEN_0 = 0x00000000 // UART3 clock Disabled
    ,UART3CKEN_1 = 0x00080000 // UART3 clock Enabled
    // UART4 Clock Enable Bit (bits: 20)
    ,UART4CKEN_MASK = 0x00100000
    ,UART4CKEN_POS = 20
    ,UART4CKEN_0 = 0x00000000 // UART4 clock Disabled
    ,UART4CKEN_1 = 0x00100000 // UART4 clock Enabled
    // UART5 Clock Enable Bit (bits: 21)
    ,UART5CKEN_MASK = 0x00200000
    ,UART5CKEN_POS = 21
    ,UART5CKEN_0 = 0x00000000 // UART5 clock Disabled
    ,UART5CKEN_1 = 0x00200000 // UART5 clock Enabled
    // UART6 Clock Enable Bit (bits: 22)
    ,UART6CKEN_MASK = 0x00400000
    ,UART6CKEN_POS = 22
    ,UART6CKEN_0 = 0x00000000 // UART6 clock Disabled
    ,UART6CKEN_1 = 0x00400000 // UART6 clock Enabled
    // UART7 Clock Enable Bit (bits: 23)
    ,UART7CKEN_MASK = 0x00800000
    ,UART7CKEN_POS = 23
    ,UART7CKEN_0 = 0x00000000 // UART7 clock Disabled
    ,UART7CKEN_1 = 0x00800000 // UART7 clock Enabled
    // CAN0 Clock Enable Bit (bits: 24)
    ,CAN0CKEN_MASK = 0x01000000
    ,CAN0CKEN_POS = 24
    ,CAN0CKEN_0 = 0x00000000 // CAN0 clock Disabled
    ,CAN0CKEN_1 = 0x01000000 // CAN0 clock Enabled
    // CAN1 Clock Enable Bit (bits: 25)
    ,CAN1CKEN_MASK = 0x02000000
    ,CAN1CKEN_POS = 25
    ,CAN1CKEN_0 = 0x00000000 // CAN1 clock Disabled
    ,CAN1CKEN_1 = 0x02000000 // CAN1 clock Enabled
    // USB OTG Clock Enable Bit (bits: 26)
    ,OTGCKEN_MASK = 0x04000000
    ,OTGCKEN_POS = 26
    ,OTGCKEN_0 = 0x00000000 // USB OTG clock Disabled
    ,OTGCKEN_1 = 0x04000000 // USB OTG clock Enabled
    // USB Device Clock Enable Bit (bits: 27)
    ,USBDCKEN_MASK = 0x08000000
    ,USBDCKEN_POS = 27
    ,USBDCKEN_0 = 0x00000000 // USB device clock Disabled
    ,USBDCKEN_1 = 0x08000000 // USB device clock Enabled
    // Enhanced Analog-digital-converter (EADC) Clock Enable Bit (bits: 28)
    ,EADCCKEN_MASK = 0x10000000
    ,EADCCKEN_POS = 28
    ,EADCCKEN_0 = 0x00000000 // EADC clock Disabled
    ,EADCCKEN_1 = 0x10000000 // EADC clock Enabled
    // I2S0 Clock Enable Bit (bits: 29)
    ,I2S0CKEN_MASK = 0x20000000
    ,I2S0CKEN_POS = 29
    ,I2S0CKEN_0 = 0x00000000 // I2S0 clock Disabled
    ,I2S0CKEN_1 = 0x20000000 // I2S0 clock Enabled
    // HSUSB OTG Clock Enable Bit (bits: 30)
    ,HSOTGCKEN_MASK = 0x40000000
    ,HSOTGCKEN_POS = 30
    ,HSOTGCKEN_0 = 0x00000000 // HSUSB OTG clock Disabled
    ,HSOTGCKEN_1 = 0x40000000 // HSUSB OTG clock Enabled
    ,APBCLK0_MASK = 0x7FFFF7FF
    ;
  };
  // APB Devices Clock Enable Control Register 1
  struct APBCLK1 : reg<ip_ver, base + 0xC>
  {
    static constexpr typename APBCLK1::type
    // SC0 Clock Enable Bit (bits: 0)
     SC0CKEN_MASK = 0x00000001
    ,SC0CKEN_POS = 0
    ,SC0CKEN_0 = 0x00000000 // SC0 clock Disabled
    ,SC0CKEN_1 = 0x00000001 // SC0 clock Enabled
    // SC1 Clock Enable Bit (bits: 1)
    ,SC1CKEN_MASK = 0x00000002
    ,SC1CKEN_POS = 1
    ,SC1CKEN_0 = 0x00000000 // SC1 clock Disabled
    ,SC1CKEN_1 = 0x00000002 // SC1 clock Enabled
    // SC2 Clock Enable Bit (bits: 2)
    ,SC2CKEN_MASK = 0x00000004
    ,SC2CKEN_POS = 2
    ,SC2CKEN_0 = 0x00000000 // SC2 clock Disabled
    ,SC2CKEN_1 = 0x00000004 // SC2 clock Enabled
    // QSPI1 Clock Enable Bit (bits: 4)
    ,QSPI1CKEN_MASK = 0x00000010
    ,QSPI1CKEN_POS = 4
    ,QSPI1CKEN_0 = 0x00000000 // QSPI1 clock Disabled
    ,QSPI1CKEN_1 = 0x00000010 // QSPI1 clock Enabled
    // SPI3 Clock Enable Bit (bits: 6)
    ,SPI3CKEN_MASK = 0x00000040
    ,SPI3CKEN_POS = 6
    ,SPI3CKEN_0 = 0x00000000 // SPI3 clock Disabled
    ,SPI3CKEN_1 = 0x00000040 // SPI3 clock Enabled
    // USCI0 Clock Enable Bit (bits: 8)
    ,USCI0CKEN_MASK = 0x00000100
    ,USCI0CKEN_POS = 8
    ,USCI0CKEN_0 = 0x00000000 // USCI0 clock Disabled
    ,USCI0CKEN_1 = 0x00000100 // USCI0 clock Enabled
    // USCI1 Clock Enable Bit (bits: 9)
    ,USCI1CKEN_MASK = 0x00000200
    ,USCI1CKEN_POS = 9
    ,USCI1CKEN_0 = 0x00000000 // USCI1 clock Disabled
    ,USCI1CKEN_1 = 0x00000200 // USCI1 clock Enabled
    // DAC Clock Enable Bit (bits: 12)
    ,DACCKEN_MASK = 0x00001000
    ,DACCKEN_POS = 12
    ,DACCKEN_0 = 0x00000000 // DAC clock Disabled
    ,DACCKEN_1 = 0x00001000 // DAC clock Enabled
    // EPWM0 Clock Enable Bit (bits: 16)
    ,EPWM0CKEN_MASK = 0x00010000
    ,EPWM0CKEN_POS = 16
    ,EPWM0CKEN_0 = 0x00000000 // EPWM0 clock Disabled
    ,EPWM0CKEN_1 = 0x00010000 // EPWM0 clock Enabled
    // EPWM1 Clock Enable Bit (bits: 17)
    ,EPWM1CKEN_MASK = 0x00020000
    ,EPWM1CKEN_POS = 17
    ,EPWM1CKEN_0 = 0x00000000 // EPWM1 clock Disabled
    ,EPWM1CKEN_1 = 0x00020000 // EPWM1 clock Enabled
    // BPWM0 Clock Enable Bit (bits: 18)
    ,BPWM0CKEN_MASK = 0x00040000
    ,BPWM0CKEN_POS = 18
    ,BPWM0CKEN_0 = 0x00000000 // BPWM0 clock Disabled
    ,BPWM0CKEN_1 = 0x00040000 // BPWM0 clock Enabled
    // BPWM1 Clock Enable Bit (bits: 19)
    ,BPWM1CKEN_MASK = 0x00080000
    ,BPWM1CKEN_POS = 19
    ,BPWM1CKEN_0 = 0x00000000 // BPWM1 clock Disabled
    ,BPWM1CKEN_1 = 0x00080000 // BPWM1 clock Enabled
    // QEI0 Clock Enable Bit (bits: 22)
    ,QEI0CKEN_MASK = 0x00400000
    ,QEI0CKEN_POS = 22
    ,QEI0CKEN_0 = 0x00000000 // QEI0 clock Disabled
    ,QEI0CKEN_1 = 0x00400000 // QEI0 clock Enabled
    // QEI1 Clock Enable Bit (bits: 23)
    ,QEI1CKEN_MASK = 0x00800000
    ,QEI1CKEN_POS = 23
    ,QEI1CKEN_0 = 0x00000000 // QEI1 clock Disabled
    ,QEI1CKEN_1 = 0x00800000 // QEI1 clock Enabled
    // TRNG Clock Enable Bit (bits: 25)
    ,TRNGCKEN_MASK = 0x02000000
    ,TRNGCKEN_POS = 25
    ,TRNGCKEN_0 = 0x00000000 // TRNG clock Disabled
    ,TRNGCKEN_1 = 0x02000000 // TRNG clock Enabled
    // ECAP0 Clock Enable Bit (bits: 26)
    ,ECAP0CKEN_MASK = 0x04000000
    ,ECAP0CKEN_POS = 26
    ,ECAP0CKEN_0 = 0x00000000 // ECAP0 clock Disabled
    ,ECAP0CKEN_1 = 0x04000000 // ECAP0 clock Enabled
    // ECAP1 Clock Enable Bit (bits: 27)
    ,ECAP1CKEN_MASK = 0x08000000
    ,ECAP1CKEN_POS = 27
    ,ECAP1CKEN_0 = 0x00000000 // ECAP1 clock Disabled
    ,ECAP1CKEN_1 = 0x08000000 // ECAP1 clock Enabled
    // CAN2 Clock Enable Bit (bits: 28)
    ,CAN2CKEN_MASK = 0x10000000
    ,CAN2CKEN_POS = 28
    ,CAN2CKEN_0 = 0x00000000 // CAN2 clock Disabled
    ,CAN2CKEN_1 = 0x10000000 // CAN2 clock Enabled
    // OP Amplifier (OPA) Clock Enable Bit (bits: 30)
    ,OPACKEN_MASK = 0x40000000
    ,OPACKEN_POS = 30
    ,OPACKEN_0 = 0x00000000 // OPA clock Disabled
    ,OPACKEN_1 = 0x40000000 // OPA clock Enabled
    // Enhanced Analog-digital-converter 1 (EADC1) Clock Enable Bit (bits: 31)
    ,EADC1CKEN_MASK = 0x80000000
    ,EADC1CKEN_POS = 31
    ,EADC1CKEN_0 = 0x00000000 // EADC1 clock Disabled
    ,EADC1CKEN_1 = 0x80000000 // EADC1 clock Enabled
    ,APBCLK1_MASK = 0xDECF1357
    ;
  };
  // Clock Source Select Control Register 0
  struct CLKSEL0 : reg<ip_ver, base + 0x10, 0x00F30130>
  {
    static constexpr typename CLKSEL0::type
    // HCLK Clock Source Selection (Write Protect) Before clock switching, the related clock sources (both pre-select and new-select) must be turned on. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 2-0)
     HCLKSEL_MASK = 0x00000007
    ,HCLKSEL_POS = 0
    ,HCLKSEL_0 = 0x00000000 // Clock source from HXT
    ,HCLKSEL_1 = 0x00000001 // Clock source from LXT
    ,HCLKSEL_2 = 0x00000002 // Clock source from PLL
    ,HCLKSEL_3 = 0x00000003 // Clock source from LIRC
    ,HCLKSEL_7 = 0x00000007 // Clock source from HIRC
    // Cortex-M4F SysTick Clock Source Selection (Write Protect) Note2: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 5-3)
    ,STCLKSEL_MASK = 0x00000038
    ,STCLKSEL_POS = 3
    ,STCLKSEL_0 = 0x00000000 // Clock source from HXT
    ,STCLKSEL_1 = 0x00000008 // Clock source from LXT
    ,STCLKSEL_2 = 0x00000010 // Clock source from HXT/2
    ,STCLKSEL_3 = 0x00000018 // Clock source from HCLK/2
    ,STCLKSEL_7 = 0x00000038 // Clock source from HIRC/2
    // USB Clock Source Selection (Write Protect) (bits: 8)
    ,USBSEL_MASK = 0x00000100
    ,USBSEL_POS = 8
    ,USBSEL_0 = 0x00000000 // Clock source from HIRC48M
    ,USBSEL_1 = 0x00000100 // Clock source from PLL
    // CCAP Engine Clock Source Selection (Write Protect) (bits: 17-16)
    ,CCAPSEL_MASK = 0x00030000
    ,CCAPSEL_POS = 16
    ,CCAPSEL_0 = 0x00000000 // Clock source from HXT clock
    ,CCAPSEL_1 = 0x00010000 // Clock source from PLL clock
    ,CCAPSEL_2 = 0x00020000 // Clock source from HCLK
    ,CCAPSEL_3 = 0x00030000 // Clock source from HIRC clock
    // SD0 Engine Clock Source Selection (Write Protect) (bits: 21-20)
    ,SDH0SEL_MASK = 0x00300000
    ,SDH0SEL_POS = 20
    ,SDH0SEL_0 = 0x00000000 // Clock source from HXT clock
    ,SDH0SEL_1 = 0x00100000 // Clock source from PLL clock
    ,SDH0SEL_2 = 0x00200000 // Clock source from HCLK
    ,SDH0SEL_3 = 0x00300000 // Clock source from HIRC clock
    // SD1 Engine Clock Source Selection (Write Protect) (bits: 23-22)
    ,SDH1SEL_MASK = 0x00C00000
    ,SDH1SEL_POS = 22
    ,SDH1SEL_0 = 0x00000000 // Clock source from HXT clock
    ,SDH1SEL_1 = 0x00400000 // Clock source from PLL clock
    ,SDH1SEL_2 = 0x00800000 // Clock source from HCLK
    ,SDH1SEL_3 = 0x00C00000 // Clock source from HIRC clock
    ,CLKSEL0_MASK = 0x00F3013F
    ;
  };
  // Clock Source Select Control Register 1
  struct CLKSEL1 : reg<ip_ver, base + 0x14>
  {
    static constexpr typename CLKSEL1::type
    // Watchdog Timer Clock Source Selection (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 1-0)
     WDTSEL_MASK = 0x00000003
    ,WDTSEL_POS = 0
    ,WDTSEL_0 = 0x00000000 // Reserved.
    ,WDTSEL_1 = 0x00000001 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,WDTSEL_2 = 0x00000002 // Clock source from HCLK/2048
    ,WDTSEL_3 = 0x00000003 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    // TIMER0 Clock Source Selection (bits: 10-8)
    ,TMR0SEL_MASK = 0x00000700
    ,TMR0SEL_POS = 8
    ,TMR0SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,TMR0SEL_1 = 0x00000100 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,TMR0SEL_2 = 0x00000200 // Clock source from PCLK0
    ,TMR0SEL_3 = 0x00000300 // Clock source from external clock TM0 pin
    ,TMR0SEL_5 = 0x00000500 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR0SEL_7 = 0x00000700 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // TIMER1 Clock Source Selection (bits: 14-12)
    ,TMR1SEL_MASK = 0x00007000
    ,TMR1SEL_POS = 12
    ,TMR1SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,TMR1SEL_1 = 0x00001000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,TMR1SEL_2 = 0x00002000 // Clock source from PCLK0
    ,TMR1SEL_3 = 0x00003000 // Clock source from external clock TM1 pin
    ,TMR1SEL_5 = 0x00005000 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR1SEL_7 = 0x00007000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // TIMER2 Clock Source Selection (bits: 18-16)
    ,TMR2SEL_MASK = 0x00070000
    ,TMR2SEL_POS = 16
    ,TMR2SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,TMR2SEL_1 = 0x00010000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,TMR2SEL_2 = 0x00020000 // Clock source from PCLK1
    ,TMR2SEL_3 = 0x00030000 // Clock source from external clock TM2 pin
    ,TMR2SEL_5 = 0x00050000 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR2SEL_7 = 0x00070000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // TIMER3 Clock Source Selection (bits: 22-20)
    ,TMR3SEL_MASK = 0x00700000
    ,TMR3SEL_POS = 20
    ,TMR3SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,TMR3SEL_1 = 0x00100000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,TMR3SEL_2 = 0x00200000 // Clock source from PCLK1
    ,TMR3SEL_3 = 0x00300000 // Clock source from external clock TM3 pin
    ,TMR3SEL_5 = 0x00500000 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,TMR3SEL_7 = 0x00700000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // UART0 Clock Source Selection (bits: 25-24)
    ,UART0SEL_MASK = 0x03000000
    ,UART0SEL_POS = 24
    ,UART0SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART0SEL_1 = 0x01000000 // Clock source from PLL
    ,UART0SEL_2 = 0x02000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART0SEL_3 = 0x03000000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // UART1 Clock Source Selection (bits: 27-26)
    ,UART1SEL_MASK = 0x0C000000
    ,UART1SEL_POS = 26
    ,UART1SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART1SEL_1 = 0x04000000 // Clock source from PLL
    ,UART1SEL_2 = 0x08000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART1SEL_3 = 0x0C000000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // Clock Divider Clock Source Selection (bits: 29-28)
    ,CLKOSEL_MASK = 0x30000000
    ,CLKOSEL_POS = 28
    ,CLKOSEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,CLKOSEL_1 = 0x10000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,CLKOSEL_2 = 0x20000000 // Clock source from HCLK
    ,CLKOSEL_3 = 0x30000000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // Window Watchdog Timer Clock Source Selection (bits: 31-30)
    ,WWDTSEL_MASK = 0xC0000000
    ,WWDTSEL_POS = 30
    ,WWDTSEL_2 = 0x80000000 // Clock source from HCLK/2048
    ,WWDTSEL_3 = 0xC0000000 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    ,CLKSEL1_MASK = 0xFF777703
    ;
  };
  // Clock Source Select Control Register 2
  struct CLKSEL2 : reg<ip_ver, base + 0x18, 0x000003AB>
  {
    static constexpr typename CLKSEL2::type
    // EPWM0 Clock Source Selection The peripheral clock source of EPWM0 is defined by EPWM0SEL. (bits: 0)
     EPWM0SEL_MASK = 0x00000001
    ,EPWM0SEL_POS = 0
    ,EPWM0SEL_0 = 0x00000000 // Clock source from PLL
    ,EPWM0SEL_1 = 0x00000001 // Clock source from PCLK0
    // EPWM1 Clock Source Selection The peripheral clock source of EPWM1 is defined by EPWM1SEL. (bits: 1)
    ,EPWM1SEL_MASK = 0x00000002
    ,EPWM1SEL_POS = 1
    ,EPWM1SEL_0 = 0x00000000 // Clock source from PLL
    ,EPWM1SEL_1 = 0x00000002 // Clock source from PCLK1
    // QSPI0 Clock Source Selection (bits: 3-2)
    ,QSPI0SEL_MASK = 0x0000000C
    ,QSPI0SEL_POS = 2
    ,QSPI0SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,QSPI0SEL_1 = 0x00000004 // Clock source from PLL
    ,QSPI0SEL_2 = 0x00000008 // Clock source from PCLK0
    ,QSPI0SEL_3 = 0x0000000C // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // SPI0 Clock Source Selection (bits: 5-4)
    ,SPI0SEL_MASK = 0x00000030
    ,SPI0SEL_POS = 4
    ,SPI0SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,SPI0SEL_1 = 0x00000010 // Clock source from PLL
    ,SPI0SEL_2 = 0x00000020 // Clock source from PCLK1
    ,SPI0SEL_3 = 0x00000030 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // SPI1 Clock Source Selection (bits: 7-6)
    ,SPI1SEL_MASK = 0x000000C0
    ,SPI1SEL_POS = 6
    ,SPI1SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,SPI1SEL_1 = 0x00000040 // Clock source from PLL
    ,SPI1SEL_2 = 0x00000080 // Clock source from PCLK0
    ,SPI1SEL_3 = 0x000000C0 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // BPWM0 Clock Source Selection The peripheral clock source of BPWM0 is defined by BPWM0SEL. (bits: 8)
    ,BPWM0SEL_MASK = 0x00000100
    ,BPWM0SEL_POS = 8
    ,BPWM0SEL_0 = 0x00000000 // Clock source from PLL
    ,BPWM0SEL_1 = 0x00000100 // Clock source from PCLK0
    // BPWM1 Clock Source Selection The peripheral clock source of BPWM1 is defined by BPWM1SEL. (bits: 9)
    ,BPWM1SEL_MASK = 0x00000200
    ,BPWM1SEL_POS = 9
    ,BPWM1SEL_0 = 0x00000000 // Clock source from PLL
    ,BPWM1SEL_1 = 0x00000200 // Clock source from PCLK1
    // SPI2 Clock Source Selection (bits: 11-10)
    ,SPI2SEL_MASK = 0x00000C00
    ,SPI2SEL_POS = 10
    ,SPI2SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,SPI2SEL_1 = 0x00000400 // Clock source from PLL
    ,SPI2SEL_2 = 0x00000800 // Clock source from PCLK1
    ,SPI2SEL_3 = 0x00000C00 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // SPI3 Clock Source Selection (bits: 13-12)
    ,SPI3SEL_MASK = 0x00003000
    ,SPI3SEL_POS = 12
    ,SPI3SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,SPI3SEL_1 = 0x00001000 // Clock source from PLL
    ,SPI3SEL_2 = 0x00002000 // Clock source from PCLK0
    ,SPI3SEL_3 = 0x00003000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    ,CLKSEL2_MASK = 0x00003FFF
    ;
  };
  // Clock Source Select Control Register 3
  struct CLKSEL3 : reg<ip_ver, base + 0x1C>
  {
    static constexpr typename CLKSEL3::type
    // SC0 Clock Source Selection (bits: 1-0)
     SC0SEL_MASK = 0x00000003
    ,SC0SEL_POS = 0
    ,SC0SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,SC0SEL_1 = 0x00000001 // Clock source from PLL
    ,SC0SEL_2 = 0x00000002 // Clock source from PCLK0
    ,SC0SEL_3 = 0x00000003 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // SC0 Clock Source Selection (bits: 3-2)
    ,SC1SEL_MASK = 0x0000000C
    ,SC1SEL_POS = 2
    ,SC1SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,SC1SEL_1 = 0x00000004 // Clock source from PLL
    ,SC1SEL_2 = 0x00000008 // Clock source from PCLK1
    ,SC1SEL_3 = 0x0000000C // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // SC2 Clock Source Selection (bits: 5-4)
    ,SC2SEL_MASK = 0x00000030
    ,SC2SEL_POS = 4
    ,SC2SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,SC2SEL_1 = 0x00000010 // Clock source from PLL
    ,SC2SEL_2 = 0x00000020 // Clock source from PCLK0
    ,SC2SEL_3 = 0x00000030 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // RTC Clock Source Selection (bits: 8)
    ,RTCSEL_MASK = 0x00000100
    ,RTCSEL_POS = 8
    ,RTCSEL_0 = 0x00000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,RTCSEL_1 = 0x00000100 // Clock source from 10 kHz internal low speed RC oscillator (LIRC)
    // QSPI1 Clock Source Selection (bits: 13-12)
    ,QSPI1SEL_MASK = 0x00003000
    ,QSPI1SEL_POS = 12
    ,QSPI1SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,QSPI1SEL_1 = 0x00001000 // Clock source from PLL
    ,QSPI1SEL_2 = 0x00002000 // Clock source from PCLK1
    ,QSPI1SEL_3 = 0x00003000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // I2S0 Clock Source Selection (bits: 17-16)
    ,I2S0SEL_MASK = 0x00030000
    ,I2S0SEL_POS = 16
    ,I2S0SEL_0 = 0x00000000 // Clock source from HXT clock
    ,I2S0SEL_1 = 0x00010000 // Clock source from PLL clock
    ,I2S0SEL_2 = 0x00020000 // Clock source from PCLK0
    ,I2S0SEL_3 = 0x00030000 // Clock source from HIRC clock
    // UART6 Clock Source Selection (bits: 21-20)
    ,UART6SEL_MASK = 0x00300000
    ,UART6SEL_POS = 20
    ,UART6SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART6SEL_1 = 0x00100000 // Clock source from PLL
    ,UART6SEL_2 = 0x00200000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART6SEL_3 = 0x00300000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // UART7 Clock Source Selection (bits: 23-22)
    ,UART7SEL_MASK = 0x00C00000
    ,UART7SEL_POS = 22
    ,UART7SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART7SEL_1 = 0x00400000 // Clock source from PLL
    ,UART7SEL_2 = 0x00800000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART7SEL_3 = 0x00C00000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // UART2 Clock Source Selection (bits: 25-24)
    ,UART2SEL_MASK = 0x03000000
    ,UART2SEL_POS = 24
    ,UART2SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART2SEL_1 = 0x01000000 // Clock source from PLL
    ,UART2SEL_2 = 0x02000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART2SEL_3 = 0x03000000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // UART3 Clock Source Selection (bits: 27-26)
    ,UART3SEL_MASK = 0x0C000000
    ,UART3SEL_POS = 26
    ,UART3SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART3SEL_1 = 0x04000000 // Clock source from PLL
    ,UART3SEL_2 = 0x08000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART3SEL_3 = 0x0C000000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // UART4 Clock Source Selection (bits: 29-28)
    ,UART4SEL_MASK = 0x30000000
    ,UART4SEL_POS = 28
    ,UART4SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART4SEL_1 = 0x10000000 // Clock source from PLL
    ,UART4SEL_2 = 0x20000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART4SEL_3 = 0x30000000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    // UART5 Clock Source Selection (bits: 31-30)
    ,UART5SEL_MASK = 0xC0000000
    ,UART5SEL_POS = 30
    ,UART5SEL_0 = 0x00000000 // Clock source from 4~24 MHz external high speed crystal oscillator (HXT)
    ,UART5SEL_1 = 0x40000000 // Clock source from PLL
    ,UART5SEL_2 = 0x80000000 // Clock source from 32.768 kHz external low speed crystal oscillator (LXT)
    ,UART5SEL_3 = 0xC0000000 // Clock source from 12 MHz internal high speed RC oscillator (HIRC)
    ,CLKSEL3_MASK = 0xFFF3313F
    ;
  };
  // Clock Divider Number Register 0
  struct CLKDIV0 : reg<ip_ver, base + 0x20>
  {
    static constexpr typename CLKDIV0::type
    // HCLK Clock Divide Number From HCLK Clock Source Note: If HCLK clock source frequency is PLL, HCLKDIV should not be 1. HCLK PLL/2 (bits: 3-0)
     HCLKDIV_MASK = 0x0000000F
    ,HCLKDIV_POS = 0
    // USB Clock Divide Number From PLL Clock (bits: 7-4)
    ,USBDIV_MASK = 0x000000F0
    ,USBDIV_POS = 4
    // UART0 Clock Divide Number From UART0 Clock Source (bits: 11-8)
    ,UART0DIV_MASK = 0x00000F00
    ,UART0DIV_POS = 8
    // UART1 Clock Divide Number From UART1 Clock Source (bits: 15-12)
    ,UART1DIV_MASK = 0x0000F000
    ,UART1DIV_POS = 12
    // EADC Clock Divide Number From EADC Clock Source (bits: 23-16)
    ,EADCDIV_MASK = 0x00FF0000
    ,EADCDIV_POS = 16
    // SD0 Clock Divide Number From SD0 Clock Source (bits: 31-24)
    ,SDH0DIV_MASK = 0xFF000000
    ,SDH0DIV_POS = 24
    ,CLKDIV0_MASK = 0xFFFFFFFF
    ;
  };
  // Clock Divider Number Register 1
  struct CLKDIV1 : reg<ip_ver, base + 0x24>
  {
    static constexpr typename CLKDIV1::type
    // SC0 Clock Divide Number From SC0 Clock Source (bits: 7-0)
     SC0DIV_MASK = 0x000000FF
    ,SC0DIV_POS = 0
    // SC1 Clock Divide Number From SC1 Clock Source (bits: 15-8)
    ,SC1DIV_MASK = 0x0000FF00
    ,SC1DIV_POS = 8
    // SC2 Clock Divide Number From SC2 Clock Source (bits: 23-16)
    ,SC2DIV_MASK = 0x00FF0000
    ,SC2DIV_POS = 16
    ,CLKDIV1_MASK = 0x00FFFFFF
    ;
  };
  // Clock Divider Number Register 2
  struct CLKDIV2 : reg<ip_ver, base + 0x28>
  {
    static constexpr typename CLKDIV2::type
    // I2S0 Clock Divide Number From I2S0 Clock Source (bits: 3-0)
     I2S0DIV_MASK = 0x0000000F
    ,I2S0DIV_POS = 0
    // EADC1 Clock Divide Number From EADC Clock Source (bits: 31-24)
    ,EADC1DIV_MASK = 0xFF000000
    ,EADC1DIV_POS = 24
    ,CLKDIV2_MASK = 0xFF00000F
    ;
  };
  // Clock Divider Number Register 3
  struct CLKDIV3 : reg<ip_ver, base + 0x2C>
  {
    static constexpr typename CLKDIV3::type
    // Camera Capture Sensor Clock Divide Number From CCAP Clock Source (bits: 7-0)
     CCAPDIV_MASK = 0x000000FF
    ,CCAPDIV_POS = 0
    // Video Pixel Clock Divide Number From CCAP Clock Source (bits: 15-8)
    ,VSENSEDIV_MASK = 0x0000FF00
    ,VSENSEDIV_POS = 8
    // Ethernet Clock Divide Number Form HCLK (bits: 23-16)
    ,EMACDIV_MASK = 0x00FF0000
    ,EMACDIV_POS = 16
    // SD1 Clock Divide Number From SD1 Clock Source (bits: 31-24)
    ,SDH1DIV_MASK = 0xFF000000
    ,SDH1DIV_POS = 24
    ,CLKDIV3_MASK = 0xFFFFFFFF
    ;
  };
  // Clock Divider Number Register 4
  struct CLKDIV4 : reg<ip_ver, base + 0x30>
  {
    static constexpr typename CLKDIV4::type
    // UART2 Clock Divide Number From UART2 Clock Source (bits: 3-0)
     UART2DIV_MASK = 0x0000000F
    ,UART2DIV_POS = 0
    // UART3 Clock Divide Number From UART3 Clock Source (bits: 7-4)
    ,UART3DIV_MASK = 0x000000F0
    ,UART3DIV_POS = 4
    // UART4 Clock Divide Number From UART4 Clock Source (bits: 11-8)
    ,UART4DIV_MASK = 0x00000F00
    ,UART4DIV_POS = 8
    // UART5 Clock Divide Number From UART5 Clock Source (bits: 15-12)
    ,UART5DIV_MASK = 0x0000F000
    ,UART5DIV_POS = 12
    // UART6 Clock Divide Number From UART6 Clock Source (bits: 19-16)
    ,UART6DIV_MASK = 0x000F0000
    ,UART6DIV_POS = 16
    // UART7 Clock Divide Number From UART7 Clock Source (bits: 23-20)
    ,UART7DIV_MASK = 0x00F00000
    ,UART7DIV_POS = 20
    ,CLKDIV4_MASK = 0x00FFFFFF
    ;
  };
  // APB Clock Divider Register
  struct PCLKDIV : reg<ip_ver, base + 0x34>
  {
    static constexpr typename PCLKDIV::type
    // APB0 Clock Divider APB0 clock can be divided from HCLK Others: Reserved. Note: PCLK must be less than 96 MHz. (bits: 2-0)
     APB0DIV_MASK = 0x00000007
    ,APB0DIV_POS = 0
    // APB1 Clock Divider APB1 clock can be divided from HCLK Others: Reserved. Note: PCLK must be less than 96 MHz. (bits: 6-4)
    ,APB1DIV_MASK = 0x00000070
    ,APB1DIV_POS = 4
    ,PCLKDIV_MASK = 0x00000077
    ;
  };
  // PLL Control Register
  struct PLLCTL : reg<ip_ver, base + 0x40, 0x0005C02E>
  {
    static constexpr typename PLLCTL::type
    // PLL Feedback Divider Control (Write Protect) Refer to the formulas below the table. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 8-0)
     FBDIV_MASK = 0x000001FF
    ,FBDIV_POS = 0
    // PLL Input Divider Control (Write Protect) Refer to the formulas below the table. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 13-9)
    ,INDIV_MASK = 0x00003E00
    ,INDIV_POS = 9
    // PLL Output Divider Control (Write Protect) Refer to the formulas below the table. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 15-14)
    ,OUTDIV_MASK = 0x0000C000
    ,OUTDIV_POS = 14
    // Power-down Mode (Write Protect) If set the PDEN bit to 1 in CLK_PWRCTL register, the PLL will enter Power-down mode, too. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 16)
    ,PD_MASK = 0x00010000
    ,PD_POS = 16
    ,PD_0 = 0x00000000 // PLL is in normal mode
    ,PD_1 = 0x00010000 // PLL is in Power-down mode (default)
    // PLL Bypass Control (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 17)
    ,BP_MASK = 0x00020000
    ,BP_POS = 17
    ,BP_0 = 0x00000000 // PLL is in normal mode (default)
    ,BP_1 = 0x00020000 // PLL clock output is same as PLL input clock FIN
    // PLL OE (FOUT Enable) Pin Control (Write Protect) Note 1: This bit is write protected. Refer to the SYS_REGLCTL register. Note 2: If HCLK is switched to PLL, OE(CLK_PLLCTL[18]) cannot be set to 1 to avoid clock stop. (bits: 18)
    ,OE_MASK = 0x00040000
    ,OE_POS = 18
    ,OE_0 = 0x00000000 // PLL FOUT Enabled
    ,OE_1 = 0x00040000 // PLL FOUT is fixed low
    // PLL Source Clock Selection (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 19)
    ,PLLSRC_MASK = 0x00080000
    ,PLLSRC_POS = 19
    ,PLLSRC_0 = 0x00000000 // PLL source clock from 4~24 MHz external high-speed crystal oscillator (HXT)
    ,PLLSRC_1 = 0x00080000 // PLL source clock from 12 MHz internal high-speed oscillator (HIRC)
    // PLL Stable Counter Selection (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 23)
    ,STBSEL_MASK = 0x00800000
    ,STBSEL_POS = 23
    ,STBSEL_0 = 0x00000000 // PLL stable time is 1200 PLL source clock (suitable for source clock is equal to or less than 12 MHz)
    ,STBSEL_1 = 0x00800000 // PLL stable time is 2400 PLL source clock (suitable for source clock is larger than 12 MHz)
    ,PLLCTL_MASK = 0x008FFFFF
    ;
  };
  // Clock Status Monitor Register
  struct STATUS : reg<ip_ver, base + 0x50>
  {
    static constexpr typename STATUS::type
    // HXT Clock Source Stable Flag (Read Only) (bits: 0)
     HXTSTB_MASK = 0x00000001
    ,HXTSTB_POS = 0
    ,HXTSTB_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock is not stable or disabled
    ,HXTSTB_1 = 0x00000001 // 4~24 MHz external high speed crystal oscillator (HXT) clock is stable and enabled
    // LXT Clock Source Stable Flag (Read Only) (bits: 1)
    ,LXTSTB_MASK = 0x00000002
    ,LXTSTB_POS = 1
    ,LXTSTB_0 = 0x00000000 // 32.768 kHz external low speed crystal oscillator (LXT) clock is not stable or disabled
    ,LXTSTB_1 = 0x00000002 // 32.768 kHz external low speed crystal oscillator (LXT) clock is stabled and enabled
    // Internal PLL Clock Source Stable Flag (Read Only) (bits: 2)
    ,PLLSTB_MASK = 0x00000004
    ,PLLSTB_POS = 2
    ,PLLSTB_0 = 0x00000000 // Internal PLL clock is not stable or disabled
    ,PLLSTB_1 = 0x00000004 // Internal PLL clock is stable and enabled
    // LIRC Clock Source Stable Flag (Read Only) (bits: 3)
    ,LIRCSTB_MASK = 0x00000008
    ,LIRCSTB_POS = 3
    ,LIRCSTB_0 = 0x00000000 // 10 kHz internal low speed RC oscillator (LIRC) clock is not stable or disabled
    ,LIRCSTB_1 = 0x00000008 // 10 kHz internal low speed RC oscillator (LIRC) clock is stable and enabled
    // HIRC Clock Source Stable Flag (Read Only) (bits: 4)
    ,HIRCSTB_MASK = 0x00000010
    ,HIRCSTB_POS = 4
    ,HIRCSTB_0 = 0x00000000 // 12 MHz internal high speed RC oscillator (HIRC) clock is not stable or disabled
    ,HIRCSTB_1 = 0x00000010 // 12 MHz internal high speed RC oscillator (HIRC) clock is stable and enabled
    // HIRC48M Clock Source Stable Flag (Read Only) (bits: 6)
    ,HIRC48MSTB_MASK = 0x00000040
    ,HIRC48MSTB_POS = 6
    ,HIRC48MSTB_0 = 0x00000000 // 48 MHz internal high speed RC oscillator (HIRC48M) clock is not stable or disabled
    ,HIRC48MSTB_1 = 0x00000040 // 48 MHz internal high speed RC oscillator (HIRC48M) clock is stable and enabled
    // Clock Switching Fail Flag (Read Only) This bit is updated when software switches system clock source. If switch target clock is stable, this bit will be set to 0. If switch target clock is not stable, this bit will be set to 1. Note: Write 1 to clear the bit to 0. (bits: 7)
    ,CLKSFAIL_MASK = 0x00000080
    ,CLKSFAIL_POS = 7
    ,CLKSFAIL_0 = 0x00000000 // Clock switching success
    ,CLKSFAIL_1 = 0x00000080 // Clock switching failure
    ,STATUS_MASK = 0x000000DF
    ;
  };
  // Clock Output Control Register
  struct CLKOCTL : reg<ip_ver, base + 0x60>
  {
    static constexpr typename CLKOCTL::type
    // Clock Output Frequency Selection The formula of output frequency is Fin is the input clock frequency. Fout is the frequency of divider output clock. N is the 4-bit value of FREQSEL[3:0]. (bits: 3-0)
     FREQSEL_MASK = 0x0000000F
    ,FREQSEL_POS = 0
    // Clock Output Enable Bit (bits: 4)
    ,CLKOEN_MASK = 0x00000010
    ,CLKOEN_POS = 4
    ,CLKOEN_0 = 0x00000000 // Clock Output function Disabled
    ,CLKOEN_1 = 0x00000010 // Clock Output function Enabled
    // Clock Output Divide One Enable Bit (bits: 5)
    ,DIV1EN_MASK = 0x00000020
    ,DIV1EN_POS = 5
    ,DIV1EN_0 = 0x00000000 // Clock Output will output clock with source frequency divided by FREQSEL
    ,DIV1EN_1 = 0x00000020 // Clock Output will output clock with source frequency
    // Clock Output 1Hz Enable Bit (bits: 6)
    ,CLK1HZEN_MASK = 0x00000040
    ,CLK1HZEN_POS = 6
    ,CLK1HZEN_0 = 0x00000000 // 1 Hz clock output for 32.768 kHz frequency compensation Disabled
    ,CLK1HZEN_1 = 0x00000040 // 1 Hz clock output for 32.768 kHz frequency compensation Enabled
    ,CLKOCTL_MASK = 0x0000007F
    ;
  };
  // Clock Fail Detector Control Register
  struct CLKDCTL : reg<ip_ver, base + 0x70>
  {
    static constexpr typename CLKDCTL::type
    // HXT Clock Fail Detector Enable Bit (bits: 4)
     HXTFDEN_MASK = 0x00000010
    ,HXTFDEN_POS = 4
    ,HXTFDEN_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock fail detector Disabled
    ,HXTFDEN_1 = 0x00000010 // 4~24 MHz external high speed crystal oscillator (HXT) clock fail detector Enabled
    // HXT Clock Fail Interrupt Enable Bit (bits: 5)
    ,HXTFIEN_MASK = 0x00000020
    ,HXTFIEN_POS = 5
    ,HXTFIEN_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock fail interrupt Disabled
    ,HXTFIEN_1 = 0x00000020 // 4~24 MHz external high speed crystal oscillator (HXT) clock fail interrupt Enabled
    // LXT Clock Fail Detector Enable Bit (bits: 12)
    ,LXTFDEN_MASK = 0x00001000
    ,LXTFDEN_POS = 12
    ,LXTFDEN_0 = 0x00000000 // 32.768 kHz external low speed crystal oscillator (LXT) clock fail detector Disabled
    ,LXTFDEN_1 = 0x00001000 // 32.768 kHz external low speed crystal oscillator (LXT) clock fail detector Enabled
    // LXT Clock Fail Interrupt Enable Bit (bits: 13)
    ,LXTFIEN_MASK = 0x00002000
    ,LXTFIEN_POS = 13
    ,LXTFIEN_0 = 0x00000000 // 32.768 kHz external low speed crystal oscillator (LXT) clock fail interrupt Disabled
    ,LXTFIEN_1 = 0x00002000 // 32.768 kHz external low speed crystal oscillator (LXT) clock fail interrupt Enabled
    // HXT Clock Frequency Range Detector Enable Bit (bits: 16)
    ,HXTFQDEN_MASK = 0x00010000
    ,HXTFQDEN_POS = 16
    ,HXTFQDEN_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock frequency range detector Disabled
    ,HXTFQDEN_1 = 0x00010000 // 4~24 MHz external high speed crystal oscillator (HXT) clock frequency range detector Enabled
    // HXT Clock Frequency Range Detector Interrupt Enable Bit (bits: 17)
    ,HXTFQIEN_MASK = 0x00020000
    ,HXTFQIEN_POS = 17
    ,HXTFQIEN_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock frequency range detector fail interrupt Disabled
    ,HXTFQIEN_1 = 0x00020000 // 4~24 MHz external high speed crystal oscillator (HXT) clock frequency range detector fail interrupt Enabled
    ,CLKDCTL_MASK = 0x00033030
    ;
  };
  // Clock Fail Detector Status Register
  struct CLKDSTS : reg<ip_ver, base + 0x74>
  {
    static constexpr typename CLKDSTS::type
    // HXT Clock Fail Interrupt Flag Note: Write 1 to clear the bit to 0. (bits: 0)
     HXTFIF_MASK = 0x00000001
    ,HXTFIF_POS = 0
    ,HXTFIF_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock is normal
    ,HXTFIF_1 = 0x00000001 // 4~24 MHz external high speed crystal oscillator (HXT) clock stops
    // LXT Clock Fail Interrupt Flag Note: Write 1 to clear the bit to 0. (bits: 1)
    ,LXTFIF_MASK = 0x00000002
    ,LXTFIF_POS = 1
    ,LXTFIF_0 = 0x00000000 // 32.768 kHz external low speed crystal oscillator (LXT) clock is normal
    ,LXTFIF_1 = 0x00000002 // 32.768 kHz external low speed crystal oscillator (LXT) stops
    // HXT Clock Frequency Range Detector Interrupt Flag Note: Write 1 to clear the bit to 0. (bits: 8)
    ,HXTFQIF_MASK = 0x00000100
    ,HXTFQIF_POS = 8
    ,HXTFQIF_0 = 0x00000000 // 4~24 MHz external high speed crystal oscillator (HXT) clock frequency is normal
    ,HXTFQIF_1 = 0x00000100 // 4~24 MHz external high speed crystal oscillator (HXT) clock frequency is abnormal
    ,CLKDSTS_MASK = 0x00000103
    ;
  };
  // Clock Frequency Range Detector Upper Boundary Register
  struct CDUPB : reg<ip_ver, base + 0x78>
  {
    static constexpr typename CDUPB::type
    // HXT Clock Frequency Range Detector Upper Boundary Value The bits define the maximum value of frequency range detector window. When HXT frequency higher than this maximum frequency value, the HXT Clock Frequency Range Detector Interrupt Flag will set to 1. (bits: 9-0)
     UPERBD_MASK = 0x000003FF
    ,UPERBD_POS = 0
    ,CDUPB_MASK = 0x000003FF
    ;
  };
  // Clock Frequency Range Detector Lower Boundary Register
  struct CDLOWB : reg<ip_ver, base + 0x7C>
  {
    static constexpr typename CDLOWB::type
    // HXT Clock Frequency Range Detector Lower Boundary Value The bits define the minimum value of frequency range detector window. When HXT frequency lower than this minimum frequency value, the HXT Clock Frequency Range Detector Interrupt Flag will set to 1. (bits: 9-0)
     LOWERBD_MASK = 0x000003FF
    ,LOWERBD_POS = 0
    ,CDLOWB_MASK = 0x000003FF
    ;
  };
  // Power Manager Control Register
  struct PMUCTL : reg<ip_ver, base + 0x90, 0x00000080>
  {
    static constexpr typename PMUCTL::type
    // Power-down Mode Selection (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. These bits control chip power-down mode grade selection when CPU execute WFI/WFE instruction. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 2-0)
     PDMSEL_MASK = 0x00000007
    ,PDMSEL_POS = 0
    ,PDMSEL_0 = 0x00000000 // Power-down mode is selected. (NPD)
    ,PDMSEL_1 = 0x00000001 // Low leakage Power-down mode is selected (LLPD)
    ,PDMSEL_2 = 0x00000002 // Fast wake-up Power-down mode is selected (FWPD)
    ,PDMSEL_3 = 0x00000003 // Reserved.
    ,PDMSEL_4 = 0x00000004 // Standby Power-down mode 0 is selected (SPD0) (SRAM retention)
    ,PDMSEL_5 = 0x00000005 // Standby Power-down mode 1 is selected (SPD1)
    ,PDMSEL_6 = 0x00000006 // Deep Power-down mode is selected (DPD)
    ,PDMSEL_7 = 0x00000007 // Reserved.
    // Deep-power-down Mode GPIO Hold Enable Bit (bits: 3)
    ,DPDHOLDEN_MASK = 0x00000008
    ,DPDHOLDEN_POS = 3
    ,DPDHOLDEN_0 = 0x00000000 // When GPIO enters deep power-down mode, all I/O status are tri-state
    ,DPDHOLDEN_1 = 0x00000008 // When GPIO enters deep power-down mode, all I/O status are hold to keep normal operating status. After chip was waked up from deep power-down mode, the I/O are still keep hold status until user set CLK_IOPDCTL[0] to release I/O hold status. (M48xGC/M48xE8)
    // SRAM Retention Range Select Bit (Write Protect) Select SRAM retention range when chip enter SPD mode. (M48xGC/M48xE8) Note: This bit is write protected. Refer to the SYS_REGLCTL register. Note: Chip may work in SPD mode abnormally, if not select SRAM retention size before enter SPD mode. (bits: 6-4)
    ,SRETSEL_MASK = 0x00000070
    ,SRETSEL_POS = 4
    ,SRETSEL_0 = 0x00000000 // No SRAM retention
    ,SRETSEL_1 = 0x00000010 // 16K SRAM retention when chip enter SPD mode
    ,SRETSEL_2 = 0x00000020 // 32K SRAM retention when chip enter SPD mode
    ,SRETSEL_3 = 0x00000030 // 64K SRAM retention when chip enter SPD mode
    ,SRETSEL_4 = 0x00000040 // 128K SRAM retention when chip enter SPD mode
    // Wake-up Timer Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. Note: This bit is write protected. Refer to the SYS_REGLCTL register (bits: 8)
    ,WKTMREN_MASK = 0x00000100
    ,WKTMREN_POS = 8
    ,WKTMREN_0 = 0x00000000 // Wake-up timer disable at DPD/SPD mode
    ,WKTMREN_1 = 0x00000100 // Wake-up timer enabled at DPD/SPD mode
    // Wake-up Timer Time-out Interval Select (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. These bits control wake-up timer time-out interval when chip at DPD/SPD mode. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 12-9)
    ,WKTMRIS_MASK = 0x00001E00
    ,WKTMRIS_POS = 9
    ,WKTMRIS_0 = 0x00000000 // Time-out interval is 128 OSC10K clocks (12.8 ms)
    ,WKTMRIS_1 = 0x00000200 // Time-out interval is 256 OSC10K clocks (25.6 ms)
    ,WKTMRIS_2 = 0x00000400 // Time-out interval is 512 OSC10K clocks (51.2 ms)
    ,WKTMRIS_3 = 0x00000600 // Time-out interval is 1024 OSC10K clocks (102.4ms)
    ,WKTMRIS_4 = 0x00000800 // Time-out interval is 4096 OSC10K clocks (409.6ms)
    ,WKTMRIS_5 = 0x00000A00 // Time-out interval is 8192 OSC10K clocks (819.2ms)
    ,WKTMRIS_6 = 0x00000C00 // Time-out interval is 16384 OSC10K clocks (1638.4ms)
    ,WKTMRIS_7 = 0x00000E00 // Time-out interval is 65536 OSC10K clocks (6553.6ms)
    ,WKTMRIS_8 = 0x00001000 // Time-out interval is 131072 OSC10K clocks (13107.2ms)
    ,WKTMRIS_9 = 0x00001200 // Time-out interval is 262144 OSC10K clocks (26214.4ms)
    ,WKTMRIS_10 = 0x00001400 // Time-out interval is 524288 OSC10K clocks (52428.8ms)
    ,WKTMRIS_11 = 0x00001600 // Time-out interval is 1048576 OSC10K clocks (104857.6ms)
    // Wake-up Pin0 Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. This is control register for GPC.0 to wake-up pin. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 17-16)
    ,WKPINEN0_MASK = 0x00030000
    ,WKPINEN0_POS = 16
    ,WKPINEN0_0 = 0x00000000 // Wake-up pin disable at Deep Power-down mode
    ,WKPINEN0_1 = 0x00010000 // Wake-up pin rising edge enabled at Deep Power-down mode
    ,WKPINEN0_2 = 0x00020000 // Wake-up pin falling edge enabled at Deep Power-down mode
    ,WKPINEN0_3 = 0x00030000 // Wake-up pin both edge enabled at Deep Power-down mode
    // ACMP Standby Power-down Mode Wake-up Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 18)
    ,ACMPSPWK_MASK = 0x00040000
    ,ACMPSPWK_POS = 18
    ,ACMPSPWK_0 = 0x00000000 // ACMP wake-up disable at Standby Power-down mode
    ,ACMPSPWK_1 = 0x00040000 // ACMP wake-up enabled at Standby Power-down mode
    // RTC Wake-up Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 23)
    ,RTCWKEN_MASK = 0x00800000
    ,RTCWKEN_POS = 23
    ,RTCWKEN_0 = 0x00000000 // RTC wake-up disable at Deep Power-down mode or Standby Power-down mode
    ,RTCWKEN_1 = 0x00800000 // RTC wake-up enabled at Deep Power-down mode or Standby Power-down mode
    // Wake-up Pin1 Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. This is control register for GPB.0 to wake-up pin. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 25-24)
    ,WKPINEN1_MASK = 0x03000000
    ,WKPINEN1_POS = 24
    ,WKPINEN1_0 = 0x00000000 // Wake-up pin disable at Deep Power-down mode
    ,WKPINEN1_1 = 0x01000000 // Wake-up pin rising edge enabled at Deep Power-down mode
    ,WKPINEN1_2 = 0x02000000 // Wake-up pin falling edge enabled at Deep Power-down mode
    ,WKPINEN1_3 = 0x03000000 // Wake-up pin both edge enabled at Deep Power-down mode
    // Wake-up Pin2 Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. This is control register for GPB.2 to wake-up pin. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 27-26)
    ,WKPINEN2_MASK = 0x0C000000
    ,WKPINEN2_POS = 26
    ,WKPINEN2_0 = 0x00000000 // Wake-up pin disable at Deep Power-down mode
    ,WKPINEN2_1 = 0x04000000 // Wake-up pin rising edge enabled at Deep Power-down mode
    ,WKPINEN2_2 = 0x08000000 // Wake-up pin falling edge enabled at Deep Power-down mode
    ,WKPINEN2_3 = 0x0C000000 // Wake-up pin both edge enabled at Deep Power-down mode
    // Wake-up Pin3 Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. This is control register for GPB.12 to wake-up pin. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 29-28)
    ,WKPINEN3_MASK = 0x30000000
    ,WKPINEN3_POS = 28
    ,WKPINEN3_0 = 0x00000000 // Wake-up pin disable at Deep Power-down mode
    ,WKPINEN3_1 = 0x10000000 // Wake-up pin rising edge enabled at Deep Power-down mode
    ,WKPINEN3_2 = 0x20000000 // Wake-up pin falling edge enabled at Deep Power-down mode
    ,WKPINEN3_3 = 0x30000000 // Wake-up pin both edge enabled at Deep Power-down mode
    // Wake-up Pin4 Enable Bit (Write Protect) This is a protected bit. Please refer to open lock sequence to program it. This is control register for GPF.6 to wake-up pin. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 31-30)
    ,WKPINEN4_MASK = 0xC0000000
    ,WKPINEN4_POS = 30
    ,WKPINEN4_0 = 0x00000000 // Wake-up pin disable at Deep Power-down mode
    ,WKPINEN4_1 = 0x40000000 // Wake-up pin rising edge enabled at Deep Power-down mode
    ,WKPINEN4_2 = 0x80000000 // Wake-up pin falling edge enabled at Deep Power-down mode
    ,WKPINEN4_3 = 0xC0000000 // Wake-up pin both edge enabled at Deep Power-down mode
    ,PMUCTL_MASK = 0xFF871F7F
    ;
  };
  // Power Manager Status Register
  struct PMUSTS : reg<ip_ver, base + 0x94>
  {
    static constexpr typename PMUSTS::type
    // Pin0 Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Deep Power-down mode was requested by a transition of the WAKEUP pin (GPC.0). This flag is cleared when DPD mode is entered. (bits: 0)
     PINWK0_MASK = 0x00000001
    ,PINWK0_POS = 0
    ,PINWK0 = 0x00000001
    // Timer Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Deep Power-down mode (DPD) or Standby Power-down (SPD) mode was requested by wakeup timer time-out. This flag is cleared when DPD or SPD mode is entered. (bits: 1)
    ,TMRWK_MASK = 0x00000002
    ,TMRWK_POS = 1
    ,TMRWK = 0x00000002
    // RTC Wake-up Flag (Read Only) This flag indicates that wakeup of device from Deep Power-down mode (DPD) or Standby Power-down (SPD) mode was requested with a RTC alarm, tick time or tamper happened. This flag is cleared when DPD or SPD mode is entered. (bits: 2)
    ,RTCWK_MASK = 0x00000004
    ,RTCWK_POS = 2
    ,RTCWK = 0x00000004
    // Pin1 Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Deep Power-down mode was requested by a transition of the WAKEUP pin (PB.0). This flag is cleared when DPD mode is entered. (bits: 3)
    ,PINWK1_MASK = 0x00000008
    ,PINWK1_POS = 3
    ,PINWK1 = 0x00000008
    // Pin2 Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Deep Power-down mode was requested by a transition of the WAKEUP pin (PB.2). This flag is cleared when DPD mode is entered. (bits: 4)
    ,PINWK2_MASK = 0x00000010
    ,PINWK2_POS = 4
    ,PINWK2 = 0x00000010
    // Pin3 Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Deep Power-down mode was requested by a transition of the WAKEUP pin (PB.12). This flag is cleared when DPD mode is entered. (bits: 5)
    ,PINWK3_MASK = 0x00000020
    ,PINWK3_POS = 5
    ,PINWK3 = 0x00000020
    // Pin4 Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Deep Power-down mode was requested by a transition of the WAKEUP pin (PF.6). This flag is cleared when DPD mode is entered. (bits: 6)
    ,PINWK4_MASK = 0x00000040
    ,PINWK4_POS = 6
    ,PINWK4 = 0x00000040
    // GPA Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Standby Power-down mode was requested by a transition of selected one GPA group pins. This flag is cleared when SPD mode is entered. (bits: 8)
    ,GPAWK_MASK = 0x00000100
    ,GPAWK_POS = 8
    ,GPAWK = 0x00000100
    // GPB Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Standby Power-down mode was requested by a transition of selected one GPB group pins. This flag is cleared when SPD mode is entered. (bits: 9)
    ,GPBWK_MASK = 0x00000200
    ,GPBWK_POS = 9
    ,GPBWK = 0x00000200
    // GPC Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Standby Power-down mode was requested by a transition of selected one GPC group pins. This flag is cleared when SPD mode is entered. (bits: 10)
    ,GPCWK_MASK = 0x00000400
    ,GPCWK_POS = 10
    ,GPCWK = 0x00000400
    // GPD Wake-up Flag (Read Only) This flag indicates that wake-up of chip from Standby Power-down mode was requested by a transition of selected one GPD group pins. This flag is cleared when SPD mode is entered. (bits: 11)
    ,GPDWK_MASK = 0x00000800
    ,GPDWK_POS = 11
    ,GPDWK = 0x00000800
    // LVR Wake-up Flag (Read Only) This flag indicates that wakeup of device from Standby Power-down mode was requested with a LVR happened. This flag is cleared when SPD mode is entered. (bits: 12)
    ,LVRWK_MASK = 0x00001000
    ,LVRWK_POS = 12
    ,LVRWK = 0x00001000
    // BOD Wake-up Flag (Read Only) This flag indicates that wakeup of device from Standby Power-down mode (SPD) was requested with a BOD happened. This flag is cleared when SPD mode is entered. (bits: 13)
    ,BODWK_MASK = 0x00002000
    ,BODWK_POS = 13
    ,BODWK = 0x00002000
    // ACMP Wake-up Flag (Read Only) This flag indicates that wakeup of device from Standby Power-down mode (SPD) was requested with a ACMP transition. This flag is cleared when SPD mode is entered. (bits: 14)
    ,ACMPWK_MASK = 0x00004000
    ,ACMPWK_POS = 14
    ,ACMPWK = 0x00004000
    // Clear Wake-up Flag (bits: 31)
    ,CLRWK_MASK = 0x80000000
    ,CLRWK_POS = 31
    ,CLRWK_0 = 0x00000000 // No clear
    ,CLRWK_1 = 0x80000000 // Clear all wake-up flag
    ,PMUSTS_MASK = 0x80007F7F
    ;
  };
  // LDO Control Register
  struct LDOCTL : reg<ip_ver, base + 0x98>
  {
    static constexpr typename LDOCTL::type
    // DPD Wake Up Time Select Bit (bits: 0)
     DPDWKSEL_MASK = 0x00000001
    ,DPDWKSEL_POS = 0
    ,DPDWKSEL_0 = 0x00000000 // DPD wake up ready time about 3 cycles LIRC
    ,DPDWKSEL_1 = 0x00000001 // DPD wake up ready time about 2 cycles LIRC
    ,LDOCTL_MASK = 0x00000001
    ;
  };
  // Standby Power-down Wake-up De-bounce Control Register
  struct SWKDBCTL : reg<ip_ver, base + 0x9C>
  {
    static constexpr typename SWKDBCTL::type
    // Standby Power-down Wake-up De-bounce Sampling Cycle Selection Note: De-bounce counter clock source is the 10 kHz internal low speed RC oscillator (LIRC). (bits: 3-0)
     SWKDBCLKSEL_MASK = 0x0000000F
    ,SWKDBCLKSEL_POS = 0
    ,SWKDBCLKSEL_0 = 0x00000000 // Sample wake-up input once per 1 clocks
    ,SWKDBCLKSEL_1 = 0x00000001 // Sample wake-up input once per 2 clocks
    ,SWKDBCLKSEL_2 = 0x00000002 // Sample wake-up input once per 4 clocks
    ,SWKDBCLKSEL_3 = 0x00000003 // Sample wake-up input once per 8 clocks
    ,SWKDBCLKSEL_4 = 0x00000004 // Sample wake-up input once per 16 clocks
    ,SWKDBCLKSEL_5 = 0x00000005 // Sample wake-up input once per 32 clocks
    ,SWKDBCLKSEL_6 = 0x00000006 // Sample wake-up input once per 64 clocks
    ,SWKDBCLKSEL_7 = 0x00000007 // Sample wake-up input once per 128 clocks
    ,SWKDBCLKSEL_8 = 0x00000008 // Sample wake-up input once per 256 clocks
    ,SWKDBCLKSEL_9 = 0x00000009 // Sample wake-up input once per 2*256 clocks
    ,SWKDBCLKSEL_10 = 0x0000000A // Sample wake-up input once per 4*256 clocks
    ,SWKDBCLKSEL_11 = 0x0000000B // Sample wake-up input once per 8*256 clocks
    ,SWKDBCLKSEL_12 = 0x0000000C // Sample wake-up input once per 16*256 clocks
    ,SWKDBCLKSEL_13 = 0x0000000D // Sample wake-up input once per 32*256 clocks
    ,SWKDBCLKSEL_14 = 0x0000000E // Sample wake-up input once per 64*256 clocks
    ,SWKDBCLKSEL_15 = 0x0000000F // Sample wake-up input once per 128*256 clocks.
    ,SWKDBCTL_MASK = 0x0000000F
    ;
  };
  // GPA Standby Power-down Wake-up Control Register
  struct PASWKCTL : reg<ip_ver, base + 0xA0>
  {
    static constexpr typename PASWKCTL::type
    // Standby Power-down Pin Wake-up Enable Bit (bits: 0)
     WKEN_MASK = 0x00000001
    ,WKEN_POS = 0
    ,WKEN_0 = 0x00000000 // GPA group pin wake-up function Disabled
    ,WKEN_1 = 0x00000001 // GPA group pin wake-up function Enabled
    // Pin Rising Edge Wake-up Enable Bit (bits: 1)
    ,PRWKEN_MASK = 0x00000002
    ,PRWKEN_POS = 1
    ,PRWKEN_0 = 0x00000000 // GPA group pin rising edge wake-up function Disabled
    ,PRWKEN_1 = 0x00000002 // GPA group pin rising edge wake-up function Enabled
    // Pin Falling Edge Wake-up Enable Bit (bits: 2)
    ,PFWKEN_MASK = 0x00000004
    ,PFWKEN_POS = 2
    ,PFWKEN_0 = 0x00000000 // GPA group pin falling edge wake-up function Disabled
    ,PFWKEN_1 = 0x00000004 // GPA group pin falling edge wake-up function Enabled
    // GPA Standby Power-down Wake-up Pin Select (bits: 7-4)
    ,WKPSEL_MASK = 0x000000F0
    ,WKPSEL_POS = 4
    ,WKPSEL_0 = 0x00000000 // GPA.0 wake-up function Enabled
    ,WKPSEL_1 = 0x00000010 // GPA.1 wake-up function Enabled
    ,WKPSEL_2 = 0x00000020 // GPA.2 wake-up function Enabled
    ,WKPSEL_3 = 0x00000030 // GPA.3 wake-up function Enabled
    ,WKPSEL_4 = 0x00000040 // GPA.4 wake-up function Enabled
    ,WKPSEL_5 = 0x00000050 // GPA.5 wake-up function Enabled
    ,WKPSEL_6 = 0x00000060 // GPA.6 wake-up function Enabled
    ,WKPSEL_7 = 0x00000070 // GPA.7 wake-up function Enabled
    ,WKPSEL_8 = 0x00000080 // GPA.8 wake-up function Enabled
    ,WKPSEL_9 = 0x00000090 // GPA.9 wake-up function Enabled
    ,WKPSEL_10 = 0x000000A0 // GPA.10 wake-up function Enabled
    ,WKPSEL_11 = 0x000000B0 // GPA.11 wake-up function Enabled
    ,WKPSEL_12 = 0x000000C0 // GPA.12 wake-up function Enabled
    ,WKPSEL_13 = 0x000000D0 // GPA.13 wake-up function Enabled
    ,WKPSEL_14 = 0x000000E0 // GPA.14 wake-up function Enabled
    ,WKPSEL_15 = 0x000000F0 // GPA.15 wake-up function Enabled
    // GPA Input Signal De-bounce Enable Bit The DBEN bit is used to enable the de-bounce function for each corresponding IO. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the wake-up. The de-bounce clock source is the 10 kHz internal low speed RC oscillator. The de-bounce function is valid only for edgetriggered. (bits: 8)
    ,DBEN_MASK = 0x00000100
    ,DBEN_POS = 8
    ,DBEN_0 = 0x00000000 // Standby power-down wake-up pin De-bounce function Disabled
    ,DBEN_1 = 0x00000100 // Standby power-down wake-up pin De-bounce function Enabled
    ,PASWKCTL_MASK = 0x000001F7
    ;
  };
  // GPB Standby Power-down Wake-up Control Register
  struct PBSWKCTL : reg<ip_ver, base + 0xA4>
  {
    static constexpr typename PBSWKCTL::type
    // Standby Power-down Pin Wake-up Enable Bit (bits: 0)
     WKEN_MASK = 0x00000001
    ,WKEN_POS = 0
    ,WKEN_0 = 0x00000000 // GPB group pin wake-up function Disabled
    ,WKEN_1 = 0x00000001 // GPB group pin wake-up function Enabled
    // Pin Rising Edge Wake-up Enable Bit (bits: 1)
    ,PRWKEN_MASK = 0x00000002
    ,PRWKEN_POS = 1
    ,PRWKEN_0 = 0x00000000 // GPB group pin rising edge wake-up function Disabled
    ,PRWKEN_1 = 0x00000002 // GPB group pin rising edge wake-up function Enabled
    // Pin Falling Edge Wake-up Enable Bit (bits: 2)
    ,PFWKEN_MASK = 0x00000004
    ,PFWKEN_POS = 2
    ,PFWKEN_0 = 0x00000000 // GPB group pin falling edge wake-up function Disabled
    ,PFWKEN_1 = 0x00000004 // GPB group pin falling edge wake-up function Enabled
    // GPB Standby Power-down Wake-up Pin Select (bits: 7-4)
    ,WKPSEL_MASK = 0x000000F0
    ,WKPSEL_POS = 4
    ,WKPSEL_0 = 0x00000000 // GPB.0 wake-up function Enabled
    ,WKPSEL_1 = 0x00000010 // GPB.1 wake-up function Enabled
    ,WKPSEL_2 = 0x00000020 // GPB.2 wake-up function Enabled
    ,WKPSEL_3 = 0x00000030 // GPB.3 wake-up function Enabled
    ,WKPSEL_4 = 0x00000040 // GPB.4 wake-up function Enabled
    ,WKPSEL_5 = 0x00000050 // GPB.5 wake-up function Enabled
    ,WKPSEL_6 = 0x00000060 // GPB.6 wake-up function Enabled
    ,WKPSEL_7 = 0x00000070 // GPB.7 wake-up function Enabled
    ,WKPSEL_8 = 0x00000080 // GPB.8 wake-up function Enabled
    ,WKPSEL_9 = 0x00000090 // GPB.9 wake-up function Enabled
    ,WKPSEL_10 = 0x000000A0 // GPB.10 wake-up function Enabled
    ,WKPSEL_11 = 0x000000B0 // GPB.11 wake-up function Enabled
    ,WKPSEL_12 = 0x000000C0 // GPB.12 wake-up function Enabled
    ,WKPSEL_13 = 0x000000D0 // GPB.13 wake-up function Enabled
    ,WKPSEL_14 = 0x000000E0 // GPB.14 wake-up function Enabled
    ,WKPSEL_15 = 0x000000F0 // GPB.15 wake-up function Enabled
    // GPB Input Signal De-bounce Enable Bit The DBEN bit is used to enable the de-bounce function for each corresponding IO. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the wake-up. The de-bounce clock source is the 10 kHz internal low speed RC oscillator. The de-bounce function is valid only for edgetriggered. (bits: 8)
    ,DBEN_MASK = 0x00000100
    ,DBEN_POS = 8
    ,DBEN_0 = 0x00000000 // Standby power-down wake-up pin De-bounce function Disabled
    ,DBEN_1 = 0x00000100 // Standby power-down wake-up pin De-bounce function Enabled
    ,PBSWKCTL_MASK = 0x000001F7
    ;
  };
  // GPC Standby Power-down Wake-up Control Register
  struct PCSWKCTL : reg<ip_ver, base + 0xA8>
  {
    static constexpr typename PCSWKCTL::type
    // Standby Power-down Pin Wake-up Enable Bit (bits: 0)
     WKEN_MASK = 0x00000001
    ,WKEN_POS = 0
    ,WKEN_0 = 0x00000000 // GPC group pin wake-up function Disabled
    ,WKEN_1 = 0x00000001 // GPC group pin wake-up function Enabled
    // Pin Rising Edge Wake-up Enable Bit (bits: 1)
    ,PRWKEN_MASK = 0x00000002
    ,PRWKEN_POS = 1
    ,PRWKEN_0 = 0x00000000 // GPC group pin rising edge wake-up function Disabled
    ,PRWKEN_1 = 0x00000002 // GPC group pin rising edge wake-up function Enabled
    // Pin Falling Edge Wake-up Enable Bit (bits: 2)
    ,PFWKEN_MASK = 0x00000004
    ,PFWKEN_POS = 2
    ,PFWKEN_0 = 0x00000000 // GPC group pin falling edge wake-up function Disabled
    ,PFWKEN_1 = 0x00000004 // GPC group pin falling edge wake-up function Enabled
    // GPC Standby Power-down Wake-up Pin Select (bits: 7-4)
    ,WKPSEL_MASK = 0x000000F0
    ,WKPSEL_POS = 4
    ,WKPSEL_0 = 0x00000000 // GPC.0 wake-up function Enabled
    ,WKPSEL_1 = 0x00000010 // GPC.1 wake-up function Enabled
    ,WKPSEL_2 = 0x00000020 // GPC.2 wake-up function Enabled
    ,WKPSEL_3 = 0x00000030 // GPC.3 wake-up function Enabled
    ,WKPSEL_4 = 0x00000040 // GPC.4 wake-up function Enabled
    ,WKPSEL_5 = 0x00000050 // GPC.5 wake-up function Enabled
    ,WKPSEL_6 = 0x00000060 // GPC.6 wake-up function Enabled
    ,WKPSEL_7 = 0x00000070 // GPC.7 wake-up function Enabled
    ,WKPSEL_8 = 0x00000080 // GPC.8 wake-up function Enabled
    ,WKPSEL_9 = 0x00000090 // GPC.9 wake-up function Enabled
    ,WKPSEL_10 = 0x000000A0 // GPC.10 wake-up function Enabled
    ,WKPSEL_11 = 0x000000B0 // GPC.11 wake-up function Enabled
    ,WKPSEL_12 = 0x000000C0 // GPC.12 wake-up function Enabled
    ,WKPSEL_13 = 0x000000D0 // GPC.13 wake-up function Enabled
    ,WKPSEL_14 = 0x000000E0 // GPC.14 wake-up function Enabled
    ,WKPSEL_15 = 0x000000F0 // GPC.15 wake-up function Enabled
    // GPC Input Signal De-bounce Enable Bit The DBEN bit is used to enable the de-bounce function for each corresponding IO. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the wake-up. The de-bounce clock source is the 10 kHz internal low speed RC oscillator. Note: The de-bounce function is valid only for edgetriggered. (bits: 8)
    ,DBEN_MASK = 0x00000100
    ,DBEN_POS = 8
    ,DBEN_0 = 0x00000000 // Standby power-down wake-up pin De-bounce function Disabled
    ,DBEN_1 = 0x00000100 // Standby power-down wake-up pin De-bounce function Enabled
    ,PCSWKCTL_MASK = 0x000001F7
    ;
  };
  // GPD Standby Power-down Wake-up Control Register
  struct PDSWKCTL : reg<ip_ver, base + 0xAC>
  {
    static constexpr typename PDSWKCTL::type
    // Standby Power-down Pin Wake-up Enable Bit (bits: 0)
     WKEN_MASK = 0x00000001
    ,WKEN_POS = 0
    ,WKEN_0 = 0x00000000 // GPD group pin wake-up function Disabled
    ,WKEN_1 = 0x00000001 // GPD group pin wake-up function Enabled
    // Pin Rising Edge Wake-up Enable Bit (bits: 1)
    ,PRWKEN_MASK = 0x00000002
    ,PRWKEN_POS = 1
    ,PRWKEN_0 = 0x00000000 // GPD group pin rising edge wake-up function Disabled
    ,PRWKEN_1 = 0x00000002 // GPD group pin rising edge wake-up function Enabled
    // Pin Falling Edge Wake-up Enable Bit (bits: 2)
    ,PFWKEN_MASK = 0x00000004
    ,PFWKEN_POS = 2
    ,PFWKEN_0 = 0x00000000 // GPD group pin falling edge wake-up function Disabled
    ,PFWKEN_1 = 0x00000004 // GPD group pin falling edge wake-up function Enabled
    // GPD Standby Power-down Wake-up Pin Select (bits: 7-4)
    ,WKPSEL_MASK = 0x000000F0
    ,WKPSEL_POS = 4
    ,WKPSEL_0 = 0x00000000 // GPD.0 wake-up function Enabled
    ,WKPSEL_1 = 0x00000010 // GPD.1 wake-up function Enabled
    ,WKPSEL_2 = 0x00000020 // GPD.2 wake-up function Enabled
    ,WKPSEL_3 = 0x00000030 // GPD.3 wake-up function Enabled
    ,WKPSEL_4 = 0x00000040 // GPD.4 wake-up function Enabled
    ,WKPSEL_5 = 0x00000050 // GPD.5 wake-up function Enabled
    ,WKPSEL_6 = 0x00000060 // GPD.6 wake-up function Enabled
    ,WKPSEL_7 = 0x00000070 // GPD.7 wake-up function Enabled
    ,WKPSEL_8 = 0x00000080 // GPD.8 wake-up function Enabled
    ,WKPSEL_9 = 0x00000090 // GPD.9 wake-up function Enabled
    ,WKPSEL_10 = 0x000000A0 // GPD.10 wake-up function Enabled
    ,WKPSEL_11 = 0x000000B0 // GPD.11 wake-up function Enabled
    ,WKPSEL_12 = 0x000000C0 // GPD.12 wake-up function Enabled
    ,WKPSEL_13 = 0x000000D0 // GPD.13 wake-up function Enabled
    ,WKPSEL_14 = 0x000000E0 // GPD.14 wake-up function Enabled
    ,WKPSEL_15 = 0x000000F0 // GPD.15 wake-up function Enabled
    // GPD Input Signal De-bounce Enable Bit The DBEN bit is used to enable the de-bounce function for each corresponding IO. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the wake-up. The de-bounce clock source is the 10 kHz internal low speed RC oscillator. Note: The de-bounce function is valid only for edgetriggered. (bits: 8)
    ,DBEN_MASK = 0x00000100
    ,DBEN_POS = 8
    ,DBEN_0 = 0x00000000 // Standby power-down wake-up pin De-bounce function Disabled
    ,DBEN_1 = 0x00000100 // Standby power-down wake-up pin De-bounce function Enabled
    ,PDSWKCTL_MASK = 0x000001F7
    ;
  };
  // GPIO Standby Power-down Control Register
  struct IOPDCTL : reg<ip_ver, base + 0xB0>
  {
    static constexpr typename IOPDCTL::type
    // GPIO Hold Release When GPIO enters deep power-down mode or standby power-down mode, all I/O status are hold to keep normal operating status. After chip was waked up from deep power-down mode or standby power-down mode, the I/O are still keep hold status until user set this bit to release I/O hold status. Note: This bit is auto cleared by hardware. (bits: 0)
     IOHR_MASK = 0x00000001
    ,IOHR_POS = 0
    ,IOHR = 0x00000001
    ,IOPDCTL_MASK = 0x00000001
    ;
  };
}; // struct CLK

} // namespace lmcu::device::ip::v1

