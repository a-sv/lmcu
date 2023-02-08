/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// GCR Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct GCR
{
  static constexpr auto ip_ver = ip_version::_1;

  // Part Device Identification Number Register
  struct PDID : reg<ip_ver, base + 0x0, 0x20140018>
  {
    static constexpr typename PDID::type
    // Part Device Identification Number This register reflects device part number code. Software can read this register to identify which device is used. (bits: 31-0)
     PDIDVAL_MASK = 0xFFFFFFFF
    ,PDIDVAL_POS = 0
    ,PDID_MASK = 0xFFFFFFFF
    ;
  };
  // System Reset Source Register
  struct RSTSRC : reg<ip_ver, base + 0x4>
  {
    static constexpr typename RSTSRC::type
    // Power-On Reset Flag The RSTS_POR Flag is set by the {Reset Signal} from the Power-On Reset (POR) vontroller or bit CHIP_RST (IPRSTC1[0]) to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 0)
     RSTS_POR_MASK = 0x00000001
    ,RSTS_POR_POS = 0
    ,RSTS_POR_0 = 0x00000000 // No reset from POR or CHIP_RST (IPRSTC1[0])
    ,RSTS_POR_1 = 0x00000001 // Power-on Reset (POR) or CHIP_RST (IPRSTC1[0]) had issued the reset signal to reset the system
    // Reset Pin Reset Flag The RSTS_RESET flag is set by the {Reset Signal} from the nRESET Pin to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 1)
    ,RSTS_RESET_MASK = 0x00000002
    ,RSTS_RESET_POS = 1
    ,RSTS_RESET_0 = 0x00000000 // No reset from nRESET pin
    ,RSTS_RESET_1 = 0x00000002 // The Pin nRESET had issued the reset signal to reset the system
    // Watchdog Timer Reset Flag The RSTS_WDT flag is set by the {Reset Signal} from the watchdog timer or window watchdog timer to indicate the previous reset source. Note1: Write 1 to clear this bit to 0. Note2: Watchdog Timer register WTRF (WTCR[2]) bit is set if the system has been reset by WDT time-out reset. Window Watchdog Timer register WWDTRF (WWDTSR) bit is set if the system has been reset by WWDT time-out reset. (bits: 2)
    ,RSTS_WDT_MASK = 0x00000004
    ,RSTS_WDT_POS = 2
    ,RSTS_WDT_0 = 0x00000000 // No reset from watchdog timer or window watchdog timer
    ,RSTS_WDT_1 = 0x00000004 // The watchdog timer or window watchdog timer had issued the reset signal to reset the system
    // Low Voltage Reset Flag The RSTS_LVR flag is set by the {Reset Signal} from the Low-Voltage-Reset controller to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 3)
    ,RSTS_LVR_MASK = 0x00000008
    ,RSTS_LVR_POS = 3
    ,RSTS_LVR_0 = 0x00000000 // No reset from LVR
    ,RSTS_LVR_1 = 0x00000008 // The LVR controller had issued the reset signal to reset the system
    // Brown-Out Detector Reset Flag The RSTS_BOD flag is set by the {Reset Signal} from the Brown-Out Detector to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 4)
    ,RSTS_BOD_MASK = 0x00000010
    ,RSTS_BOD_POS = 4
    ,RSTS_BOD_0 = 0x00000000 // No reset from BOD
    ,RSTS_BOD_1 = 0x00000010 // The BOD had issued the reset signal to reset the system
    // SYS Reset Flag The RSTS_SYS flag Is set by the {Reset Signal} from the Cortex-M0 coreto indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 5)
    ,RSTS_SYS_MASK = 0x00000020
    ,RSTS_SYS_POS = 5
    ,RSTS_SYS_0 = 0x00000000 // No reset from Cortex-M0
    ,RSTS_SYS_1 = 0x00000020 // The Cortex-M0 had issued the reset signal to reset the system by writing 1 to bit SYSRESETREQ (AIRCR[2], Application Interrupt and Reset Control Register, address = 0xE000ED0C) in system control registers of Cortex-M0 kernel
    // CPU Reset Flag The RSTS_CPU flag Is set by hardware if software writes CPU_RST (IPRSTC1[1]) 1 To reset Cortex-M0 coreand flash memory controller (FMC). Note: Write 1 to clear this bit to 0. (bits: 7)
    ,RSTS_CPU_MASK = 0x00000080
    ,RSTS_CPU_POS = 7
    ,RSTS_CPU_0 = 0x00000000 // No reset from CPU
    ,RSTS_CPU_1 = 0x00000080 // Cortex-M0 CPU core and FMC are reset by software setting CPU_RST (IPRSTC1[1]) to 1
    ,RSTSRC_MASK = 0x000000BF
    ;
  };
  // Peripheral Reset Control Register 1
  struct IPRSTC1 : reg<ip_ver, base + 0x8>
  {
    static constexpr typename IPRSTC1::type
    // CHIP One-Shot Reset (Write Protect) Setting this bit will reset the whole chip, including CPU coreand all peripherals, and this bit will automatically return to 0 after the 2 clock cycles. The CHIP_RST is the same as the POR reset, all the chip controllers are reset and the chip setting from flash are also reload. For the difference between CHIP_RST and SYSRESETREQ, please refer to section 6.2.2. Note: This bit is the protected bit, and programming it needs to write [59h], [16h], and [88h[ to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 0)
     CHIP_RST_MASK = 0x00000001
    ,CHIP_RST_POS = 0
    ,CHIP_RST_0 = 0x00000000 // CHIP normal operation
    ,CHIP_RST_1 = 0x00000001 // CHIP one-shot reset
    // CPU Kernel One-Shot Reset (Write Protect) Setting this bit will only reset the CPU coreand Flash Memory Controller(FMC), and this bit will automatically return 0 after the two clock cycles. Note: This bit is the protected bit, and programming it needs to write [59h], [16h], and [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 1)
    ,CPU_RST_MASK = 0x00000002
    ,CPU_RST_POS = 1
    ,CPU_RST_0 = 0x00000000 // CPU normal operation
    ,CPU_RST_1 = 0x00000002 // CPU one-shot reset
    ,IPRSTC1_MASK = 0x00000003
    ;
  };
  // Peripheral Reset Control Register 2
  struct IPRSTC2 : reg<ip_ver, base + 0xC>
  {
    static constexpr typename IPRSTC2::type
    // GPIO Controller Reset (bits: 1)
     GPIO_RST_MASK = 0x00000002
    ,GPIO_RST_POS = 1
    ,GPIO_RST_0 = 0x00000000 // GPIO controller normal operation
    ,GPIO_RST_1 = 0x00000002 // GPIO controller reset
    // Timer0 Controller Reset (bits: 2)
    ,TMR0_RST_MASK = 0x00000004
    ,TMR0_RST_POS = 2
    ,TMR0_RST_0 = 0x00000000 // Timer0 controller normal operation
    ,TMR0_RST_1 = 0x00000004 // Timer0 controller reset
    // Timer1 Controller Reset (bits: 3)
    ,TMR1_RST_MASK = 0x00000008
    ,TMR1_RST_POS = 3
    ,TMR1_RST_0 = 0x00000000 // Timer1 controller normal operation
    ,TMR1_RST_1 = 0x00000008 // Timer1 controller reset
    // Timer2 Controller Reset (bits: 4)
    ,TMR2_RST_MASK = 0x00000010
    ,TMR2_RST_POS = 4
    ,TMR2_RST_0 = 0x00000000 // Timer2 controller normal operation
    ,TMR2_RST_1 = 0x00000010 // Timer2 controller reset
    // Timer3 Controller Reset (bits: 5)
    ,TMR3_RST_MASK = 0x00000020
    ,TMR3_RST_POS = 5
    ,TMR3_RST_0 = 0x00000000 // Timer3 controller normal operation
    ,TMR3_RST_1 = 0x00000020 // Timer3 controller reset
    // I2C0 Controller Reset (bits: 8)
    ,I2C0_RST_MASK = 0x00000100
    ,I2C0_RST_POS = 8
    ,I2C0_RST_0 = 0x00000000 // I2C0 controller normal operation
    ,I2C0_RST_1 = 0x00000100 // I2C0 controller reset
    // I2C1 Controller Reset (bits: 9)
    ,I2C1_RST_MASK = 0x00000200
    ,I2C1_RST_POS = 9
    ,I2C1_RST_0 = 0x00000000 // I2C1 controller normal operation
    ,I2C1_RST_1 = 0x00000200 // I2C1 controller reset
    // SPI0 Controller Reset (bits: 12)
    ,SPI0_RST_MASK = 0x00001000
    ,SPI0_RST_POS = 12
    ,SPI0_RST_0 = 0x00000000 // SPI0 controller normal operation
    ,SPI0_RST_1 = 0x00001000 // SPI0 controller reset
    // UART0 Controller Reset (bits: 16)
    ,UART0_RST_MASK = 0x00010000
    ,UART0_RST_POS = 16
    ,UART0_RST_0 = 0x00000000 // UART0 controller normal operation
    ,UART0_RST_1 = 0x00010000 // UART0 controller reset
    // UART1 Controller Reset (bits: 17)
    ,UART1_RST_MASK = 0x00020000
    ,UART1_RST_POS = 17
    ,UART1_RST_0 = 0x00000000 // UART1 controller normal operation
    ,UART1_RST_1 = 0x00020000 // UART1 controller reset
    // UART2 Controller Reset (bits: 18)
    ,UART2_RST_MASK = 0x00040000
    ,UART2_RST_POS = 18
    ,UART2_RST_0 = 0x00000000 // UART2 controller normal operation
    ,UART2_RST_1 = 0x00040000 // UART2 controller reset
    // CAN0 Controller Reset (bits: 24)
    ,CAN0_RST_MASK = 0x01000000
    ,CAN0_RST_POS = 24
    ,CAN0_RST_0 = 0x00000000 // CAN0 controller normal operation
    ,CAN0_RST_1 = 0x01000000 // CAN0 controller reset
    // ADC Controller Reset (bits: 28)
    ,ADC_RST_MASK = 0x10000000
    ,ADC_RST_POS = 28
    ,ADC_RST_0 = 0x00000000 // ADC controller normal operation
    ,ADC_RST_1 = 0x10000000 // ADC controller reset
    ,IPRSTC2_MASK = 0x1107133E
    ;
  };
  // Peripheral Reset Control Register 3
  struct IPRSTC3 : reg<ip_ver, base + 0x10>
  {
    static constexpr typename IPRSTC3::type
    // UART3 Controller Reset (bits: 8)
     UART3_RST_MASK = 0x00000100
    ,UART3_RST_POS = 8
    ,UART3_RST_0 = 0x00000000 // UART3 controller normal operation
    ,UART3_RST_1 = 0x00000100 // UART3 controller reset
    // UART4 Controller Reset (bits: 9)
    ,UART4_RST_MASK = 0x00000200
    ,UART4_RST_POS = 9
    ,UART4_RST_0 = 0x00000000 // UART4 controller normal operation
    ,UART4_RST_1 = 0x00000200 // UART4 controller reset
    // UART5 Controller Reset (bits: 10)
    ,UART5_RST_MASK = 0x00000400
    ,UART5_RST_POS = 10
    ,UART5_RST_0 = 0x00000000 // UART5 controller normal operation
    ,UART5_RST_1 = 0x00000400 // UART5 controller reset
    // PWM0 Controller Reset (bits: 16)
    ,PWM0_RST_MASK = 0x00010000
    ,PWM0_RST_POS = 16
    ,PWM0_RST_0 = 0x00000000 // PWM0 controller normal operation
    ,PWM0_RST_1 = 0x00010000 // PWM0 controller reset
    // PWM1 Controller Reset (bits: 17)
    ,PWM1_RST_MASK = 0x00020000
    ,PWM1_RST_POS = 17
    ,PWM1_RST_0 = 0x00000000 // PWM1 controller normal operation
    ,PWM1_RST_1 = 0x00020000 // PWM1 controller reset
    // BPWM0 Controller Reset (bits: 18)
    ,BPWM0_RST_MASK = 0x00040000
    ,BPWM0_RST_POS = 18
    ,BPWM0_RST_0 = 0x00000000 // BPWM0 controller normal operation
    ,BPWM0_RST_1 = 0x00040000 // BPWM0 controller reset
    // BPWM1 Controller Reset (bits: 19)
    ,BPWM1_RST_MASK = 0x00080000
    ,BPWM1_RST_POS = 19
    ,BPWM1_RST_0 = 0x00000000 // BPWM1 controller normal operation
    ,BPWM1_RST_1 = 0x00080000 // BPWM1 controller reset
    ,IPRSTC3_MASK = 0x000F0700
    ;
  };
  // Brown-out Detector Control Register
  struct BODCR : reg<ip_ver, base + 0x18, 0x00000380>
  {
    static constexpr typename BODCR::type
    // Brown-Out Detector Enable Control (Write Protect) The default value is set by flash memory controller user configuration register CBODEN (CONFIG0[23]) bit. Note: This bit is the protected bit. It means programming this needs to write [59h], [16h], [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 0)
     BOD_EN_MASK = 0x00000001
    ,BOD_EN_POS = 0
    ,BOD_EN_0 = 0x00000000 // Brown-out Detector function Disabled
    ,BOD_EN_1 = 0x00000001 // Brown-out Detector function Enabled
    // Brown-Out Detector Threshold Voltage Selection (Write Protect) The default value is set by flash memory controller user configuration register CBOV (CONFIG0[22:21]) bit. Note: This bit is the protected bit. It means programming this needs to write [59h], [16h], [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 2-1)
    ,BOD_VL_MASK = 0x00000006
    ,BOD_VL_POS = 1
    ,BOD_VL_0 = 0x00000000 // Brown-out voltage is 2.2V
    ,BOD_VL_1 = 0x00000002 // Brown-out voltage is 2.7V
    ,BOD_VL_2 = 0x00000004 // Brown-out voltage is 3.7V
    ,BOD_VL_3 = 0x00000006 // Brown-out voltage is 4.4V
    // Brown-Out Reset Enable Control (Write Protect) While the Brown-out Detector function is enabled (BOD_EN high) and BOD reset function is enabled (BOD_RSTEN high), BOD will assert a signal to reset chip when the detected voltage is lower than the threshold (BOD_OUT high). Note1: While the BOD function is enabled (BOD_EN high) and BOD interrupt function is enabled (BOD_RSTEN low), BOD will assert an interrupt if BOD_OUT is high. BOD interrupt will keep till to the BOD_EN set to 0. BOD interrupt can be blocked by disabling the NVIC BOD interrupt or disabling BOD function (set BOD_EN low). Note2: The default value is set by flash controller user configuration register CBORST (CONFIG0[20]) bit. Note3: This bit is the protected bit. It means programming this needs to write [59h], [16h], [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 3)
    ,BOD_RSTEN_MASK = 0x00000008
    ,BOD_RSTEN_POS = 3
    ,BOD_RSTEN_0 = 0x00000000 // Brown-out [INTERRUPT] function Enabled
    ,BOD_RSTEN_1 = 0x00000008 // Brown-out [RESET] function Enabled
    // Brown-Out Detector Interrupt Flag Note: Write 1 to clear this bit to 0. (bits: 4)
    ,BOD_INTF_MASK = 0x00000010
    ,BOD_INTF_POS = 4
    ,BOD_INTF_0 = 0x00000000 // Brown-out Detector does not detect any voltage draft at VDD down through or up through the voltage of BOD_VL setting
    ,BOD_INTF_1 = 0x00000010 // When Brown-out Detector detects the VDD is dropped down through the voltage of BOD_VL setting or the VDD is raised up through the voltage of BOD_VL setting, this bit is set to 1 and the Brown-out interrupt is requested if Brown-out interrupt is enabled
    // Brown-Out Detector Low Power Mode (Write Protect) Note1: The BOD consumes about 100 uA in Normal mode, and the low power mode can reduce the current to about 1/10 but slow the BOD response. Note2: This bit is the protected bit, and programming it needs to write [59h], [16h], and [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 5)
    ,BOD_LPM_MASK = 0x00000020
    ,BOD_LPM_POS = 5
    ,BOD_LPM_0 = 0x00000000 // BOD operated in Normal mode (default)
    ,BOD_LPM_1 = 0x00000020 // BOD Low Power mode Enabled
    // Brown-Out Detector Output Status (bits: 6)
    ,BOD_OUT_MASK = 0x00000040
    ,BOD_OUT_POS = 6
    ,BOD_OUT_0 = 0x00000000 // Brown-out Detector output status is 0. It means the detected voltage is higher than BOD_VL setting or BOD_EN is 0
    ,BOD_OUT_1 = 0x00000040 // Brown-out Detector output status is 1. It means the detected voltage is lower than BOD_VL setting. If the BOD_EN is 0, BOD function disabled, this bit always responds to 0
    // Low Voltage Reset Enable Control (Write Protect) The LVR function reset the chip when the input power voltage is lower than LVR circuit setting. LVR function is enabled by default. Note: This bit is the protected bit, and programming it needs to write [59h], [16h], and [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 7)
    ,LVR_EN_MASK = 0x00000080
    ,LVR_EN_POS = 7
    ,LVR_EN_0 = 0x00000000 // Low Voltage Reset function Disabled
    ,LVR_EN_1 = 0x00000080 // Low Voltage Reset function Enabled - After enabling the bit, the LVR function will be active with 100us delay for LVR output stable (default)
    // Brown-Out Detector Output De-Glitch Time Select (Write Protect) Note: This bit is the protected bit, and programming it needs to write [59h], [16h], and [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 10-8)
    ,BODDGSEL_MASK = 0x00000700
    ,BODDGSEL_POS = 8
    ,BODDGSEL_0 = 0x00000000 // BOD output is sampled by RC10K clock
    ,BODDGSEL_1 = 0x00000100 // 4 system clock (HCLK)
    ,BODDGSEL_2 = 0x00000200 // 8 system clock (HCLK)
    ,BODDGSEL_3 = 0x00000300 // 16 system clock (HCLK)
    ,BODDGSEL_4 = 0x00000400 // 32 system clock (HCLK)
    ,BODDGSEL_5 = 0x00000500 // 64 system clock (HCLK)
    ,BODDGSEL_6 = 0x00000600 // 128 system clock (HCLK)
    ,BODDGSEL_7 = 0x00000700 // 256 system clock (HCLK)
    // LVR Output De-Glitch Time Select (Write Protect) Note: This bit is the protected bit, and programming it needs to write [59h], [16h], and [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 14-12)
    ,LVRDGSEL_MASK = 0x00007000
    ,LVRDGSEL_POS = 12
    ,LVRDGSEL_0 = 0x00000000 // Without de-glitch function
    ,LVRDGSEL_1 = 0x00001000 // 4 system clock (HCLK)
    ,LVRDGSEL_2 = 0x00002000 // 8 system clock (HCLK)
    ,LVRDGSEL_3 = 0x00003000 // 16 system clock (HCLK)
    ,LVRDGSEL_4 = 0x00004000 // 32 system clock (HCLK)
    ,LVRDGSEL_5 = 0x00005000 // 64 system clock (HCLK)
    ,LVRDGSEL_6 = 0x00006000 // 128 system clock (HCLK)
    ,LVRDGSEL_7 = 0x00007000 // 256 system clock (HCLK)
    ,BODCR_MASK = 0x000077FF
    ;
  };
  // Power-on-reset Controller Register
  struct PORCR : reg<ip_ver, base + 0x24>
  {
    static constexpr typename PORCR::type
    // Power-On-Reset Enable Control (Write Protect) When powered on, the POR circuit generates a reset signal to reset the whole chip function, but noise on the power may cause the POR active again. User can disable internal POR circuit to avoid unpredictable noise to cause chip reset by writing 0x5AA5 to this field. The POR function will be active again when this field is set to another value or chip is reset by other reset source, including: nRESET, Watchdog Timer reset, Window Watchdog Timer reset, LVR reset, BOD reset, ICE reset command and the software-chip reset function Note: This bit is the protected bit. It means programming this needs to write [59h], [16h], [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 15-0)
     POR_DIS_CODE_MASK = 0x0000FFFF
    ,POR_DIS_CODE_POS = 0
    ,PORCR_MASK = 0x0000FFFF
    ;
  };
  // VREF Controller Register
  struct VREFCR : reg<ip_ver, base + 0x28, 0x00000010>
  {
    static constexpr typename VREFCR::type
    // ADC VREF Path Control (Write Protect) Note: This bit is the protected bit, and programming it needs to write [59h], [16h], and [88h] to address 0x5000_0100 to disable register protection. Refer to the register REGWRPROT at address GCR_BA+0x100. (bits: 4)
     ADC_VREFSEL_MASK = 0x00000010
    ,ADC_VREFSEL_POS = 4
    ,ADC_VREFSEL_0 = 0x00000000 // ADC VREF is from VREF pin
    ,ADC_VREFSEL_1 = 0x00000010 // ADC VREF is from AVDD
    ,VREFCR_MASK = 0x00000010
    ;
  };
  // GPIOA Multiple Function and Input Type Control Register
  struct GPA_MFP : reg<ip_ver, base + 0x30>
  {
    static constexpr typename GPA_MFP::type
    // PA.0 Pin Function Selection Bits PA0_PWM04 (ALT_MFP3[4]), PA0_UR5TXD (ALT_MFP4[7]), PA0_I2C1SCL (ALT_MFP4[12]) and GPA_MFP0 determine the PA.0 function. (PA0_PWM04, PA0_UR5TXD, PA0_I2C1SCL, GPA_MFP0) value and function mapping is as following list. (bits: 0)
     GPA_MFP0_MASK = 0x00000001
    ,GPA_MFP0_POS = 0
    ,GPA_MFP0 = 0x00000001
    // PA.1 Pin Function Selection Bits PA1_PWM05 (ALT_MFP3[5]), PA1_UR5RXD (ALT_MFP4[6]), PA1_I2C1SDA (ALT_MFP4[13]) and GPA_MFP1 determine the PA.1 function. (PA1_PWM05, PA1_UR5RXD, PA1_I2C1SDA, GPA_MFP1) value and function mapping is as following list. (bits: 1)
    ,GPA_MFP1_MASK = 0x00000002
    ,GPA_MFP1_POS = 1
    ,GPA_MFP1 = 0x00000002
    // PA.2 Pin Function Selection Bits PA2_PWM10 (ALT_MFP3[6]), PA2_UR3TXD (ALT_MFP4[3]) and GPA_MFP2 determine the PA.2 function. (PA2_PWM10, PA2_UR3TXD, GPA_MFP2) value and function mapping is as following list. (bits: 2)
    ,GPA_MFP2_MASK = 0x00000004
    ,GPA_MFP2_POS = 2
    ,GPA_MFP2 = 0x00000004
    // PA.3 Pin Function Selection Bits PA3_PWM11 (ALT_MFP3[7]), PA3_UR3RXD (ALT_MFP4[2]) and GPA_MFP3 determine the PA.3 function. (PA3_PWM11, PA3_UR3RXD, GPA_MFP3) value and function mapping is as following list. (bits: 3)
    ,GPA_MFP3_MASK = 0x00000008
    ,GPA_MFP3_POS = 3
    ,GPA_MFP3 = 0x00000008
    // PA.4 Pin Function Selection Bit GPA_MFP4 determines the PA.4 function. (bits: 4)
    ,GPA_MFP4_MASK = 0x00000010
    ,GPA_MFP4_POS = 4
    ,GPA_MFP4_0 = 0x00000000 // GPIO function is selected
    ,GPA_MFP4_1 = 0x00000010 // ADC4 function is selected
    // PA.5 Pin Function Selection Bits PA5_UR3RXD (ALT_MFP4[4]) and GPA_MFP5 determine the PA.5 function. (PA5_UR3RXD, GPA_MFP5) value and function mapping is as following list. (bits: 5)
    ,GPA_MFP5_MASK = 0x00000020
    ,GPA_MFP5_POS = 5
    ,GPA_MFP5 = 0x00000020
    // PA.6 Pin Function Selection Bits PA6_UR3TXD (ALT_MFP4[5]) and GPA_MFP6 determine the PA.6 function. (PA6_UR3TXD, GPA_MFP6) value and function mapping is as following list. (bits: 6)
    ,GPA_MFP6_MASK = 0x00000040
    ,GPA_MFP6_POS = 6
    ,GPA_MFP6 = 0x00000040
    // PA.7 Pin Function Selection Bits PA7_VREF (ALT_MFP4[14]) and GPA_MFP7 determine the PA.7 function. (PA7_VREF, GPA_MFP7) value and function mapping is as following list. (bits: 7)
    ,GPA_MFP7_MASK = 0x00000080
    ,GPA_MFP7_POS = 7
    ,GPA_MFP7 = 0x00000080
    // PA.8 Pin Function Selection Bits PA8_UR1RTS (ALT_MFP4[0]) and GPA_MFP8 determine the PA.8 function. (PA8_UR1RTS, GPA_MFP8) value and function mapping is as following list. (bits: 8)
    ,GPA_MFP8_MASK = 0x00000100
    ,GPA_MFP8_POS = 8
    ,GPA_MFP8 = 0x00000100
    // PA.9 Pin Function Selection Bits PA9_UR1CTS (ALT_MFP4[1]) and GPA_MFP9 determine the PA.9 function. (PA9_UR1CTS, GPA_MFP9) value and function mapping is as following list. (bits: 9)
    ,GPA_MFP9_MASK = 0x00000200
    ,GPA_MFP9_POS = 9
    ,GPA_MFP9 = 0x00000200
    // PA.10 Pin Function Selection Bits PA10_PWM12 (ALT_MFP3[8]) and GPA_MFP10 determine the PA.10 function. (PA10_PWM12, GPA_MFP10) value and function mapping is as following list. (bits: 10)
    ,GPA_MFP10_MASK = 0x00000400
    ,GPA_MFP10_POS = 10
    ,GPA_MFP10 = 0x00000400
    // PA.11 Pin Function Selection Bits PA11_PWM13 (ALT_MFP3[9]) and GPA_MFP11 determine the PA.11 function. (PA11_PWM13, GPA_MFP11) value and function mapping is as following list. (bits: 11)
    ,GPA_MFP11_MASK = 0x00000800
    ,GPA_MFP11_POS = 11
    ,GPA_MFP11 = 0x00000800
    // PA.12 Pin Function Selection Bits PA12_UR5RXD (ALT_MFP4[8]) and GPA_MFP12 determine the PA.12 function. (PA12_UR5RXD, GPA_MFP12) value and function mapping is as following list. (bits: 12)
    ,GPA_MFP12_MASK = 0x00001000
    ,GPA_MFP12_POS = 12
    ,GPA_MFP12 = 0x00001000
    // PA.13 Pin Function Selection Bits PA13_UR5TXD (ALT_MFP4[9]) and GPA_MFP13 determine the PA.13 function. (PA13_UR5TXD, GPA_MFP13) value and function mapping is as following list. (bits: 13)
    ,GPA_MFP13_MASK = 0x00002000
    ,GPA_MFP13_POS = 13
    ,GPA_MFP13 = 0x00002000
    // PA.14 Pin Function Selection Bit GPA_MFP14 determines the PA.14 function. (bits: 14)
    ,GPA_MFP14_MASK = 0x00004000
    ,GPA_MFP14_POS = 14
    ,GPA_MFP14_0 = 0x00000000 // GPIO function is selected
    ,GPA_MFP14_1 = 0x00004000 // PWM0_CH2 function is selected
    // PA.15 Pin Function Selection Bit GPA_MFP15 determines the PA.15 function. (bits: 15)
    ,GPA_MFP15_MASK = 0x00008000
    ,GPA_MFP15_POS = 15
    ,GPA_MFP15_0 = 0x00000000 // GPIO function is selected
    ,GPA_MFP15_1 = 0x00008000 // PWM0_CH3 function is selected
    // Trigger Function Selection (bits: 31-16)
    ,GPA_TYPEN_MASK = 0xFFFF0000
    ,GPA_TYPEN_POS = 16
    ,GPA_TYPEN_0 = 0x00000000 // GPIOA[15:0] I/O input Schmitt Trigger function Disabled
    ,GPA_TYPEN_1 = 0x00010000 // GPIOA[15:0] I/O input Schmitt Trigger function Enabled
    ,GPA_MFP_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOB Multiple Function and Input Type Control Register
  struct GPB_MFP : reg<ip_ver, base + 0x34>
  {
    static constexpr typename GPB_MFP::type
    // PB.0 Pin Function Selection Bit GPB_MFP0 determines the PB.0 function. (bits: 0)
     GPB_MFP0_MASK = 0x00000001
    ,GPB_MFP0_POS = 0
    ,GPB_MFP0_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP0_1 = 0x00000001 // UART0_RXD function is selected
    // PB.1 Pin Function Selection Bit GPB_MFP1 determines the PB.1 function. (bits: 1)
    ,GPB_MFP1_MASK = 0x00000002
    ,GPB_MFP1_POS = 1
    ,GPB_MFP1_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP1_1 = 0x00000002 // UART0_TXD function is selected
    // PB.2 Pin Function Selection Bits PB2_TM2 (ALT_MFP2[4]), PB2_PWM1BK1 (ALT_MFP3[31]), PB2_T2EX (ALT_MFP[26]) and GPB_MFP2 determine the PB.2 function. (PB2_TM2, PB2_PWM1BK1, PB2_T2EX, GPB_MFP2) value and function mapping is as following list. (bits: 2)
    ,GPB_MFP2_MASK = 0x00000004
    ,GPB_MFP2_POS = 2
    ,GPB_MFP2 = 0x00000004
    // PB.3 Pin Function Selection Bits PB3_TM3 (ALT_MFP2[5]), PB3_PWM1BK0 (ALT_MFP3[30]), PB3_T3EX (ALT_MFP[27]) and GPB_MFP3 determine the PB.3 function. (PB3_TM3, PB3_PWM1BK0, PB3_T3EX, GPB_MFP3) value and function mapping is as following list. (bits: 3)
    ,GPB_MFP3_MASK = 0x00000008
    ,GPB_MFP3_POS = 3
    ,GPB_MFP3 = 0x00000008
    // PB.4 Pin Function Selection Bit GPB_MFP4 determines the PB.4 function. (bits: 4)
    ,GPB_MFP4_MASK = 0x00000010
    ,GPB_MFP4_POS = 4
    ,GPB_MFP4_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP4_1 = 0x00000010 // UART1_RXD function is selected
    // PB 5 Pin Function Selection Bit GPB_MFP5 determines the PB.5 function. (bits: 5)
    ,GPB_MFP5_MASK = 0x00000020
    ,GPB_MFP5_POS = 5
    ,GPB_MFP5_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP5_1 = 0x00000020 // UART1_TXD function is selected
    // PB.6 Pin Function Selection Bit GPB_MFP6 determines the PB.6 function. (bits: 6)
    ,GPB_MFP6_MASK = 0x00000040
    ,GPB_MFP6_POS = 6
    ,GPB_MFP6_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP6_1 = 0x00000040 // UART1_nRTS function is selected
    // PB.7 Pin Function Selection Bit GPB_MFP7 determines the PB.7 function. (bits: 7)
    ,GPB_MFP7_MASK = 0x00000080
    ,GPB_MFP7_POS = 7
    ,GPB_MFP7_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP7_1 = 0x00000080 // UART1_nCTS function is selected
    // PB.8 Pin Function Selection Bits PB8_BPWM12 (ALT_MFP3[20]), PB8_CLKO (ALT_MFP[29]) and GPB_MFP8 determine the PB.8 function. (PB8_BPWM12, PB8_CLKO, GPB_MFP8) value and function mapping is as following list. (bits: 8)
    ,GPB_MFP8_MASK = 0x00000100
    ,GPB_MFP8_POS = 8
    ,GPB_MFP8 = 0x00000100
    // PB.9 Pin Function Selection Bit GPB_MFP9 determines the PB.9 function. (bits: 9)
    ,GPB_MFP9_MASK = 0x00000200
    ,GPB_MFP9_POS = 9
    ,GPB_MFP9_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP9_1 = 0x00000200 // TM1 function is selected
    // PB.10 Pin Function Selection Bit GPB_MFP10 determines the PB.10 function. (bits: 10)
    ,GPB_MFP10_MASK = 0x00000400
    ,GPB_MFP10_POS = 10
    ,GPB_MFP10_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP10_1 = 0x00000400 // TM2 function is selected
    // PB.11 Pin Function Selection Bits PB11_PWM04 (ALT_MFP3[24]) and GPB_MFP11 determine the PB.11 function. (PB11_PWM04, GPB_MFP11) value and function mapping is as following list. (bits: 11)
    ,GPB_MFP11_MASK = 0x00000800
    ,GPB_MFP11_POS = 11
    ,GPB_MFP11 = 0x00000800
    // PB.12 Pin Function Selection Bits PB12_BPWM13 (ALT_MFP3[21]) and GPB_MFP12 determine the PB.12 function. (PB12_BPWM13, GPB_MFP12) value and function mapping is as following list. (bits: 12)
    ,GPB_MFP12_MASK = 0x00001000
    ,GPB_MFP12_POS = 12
    ,GPB_MFP12 = 0x00001000
    // PB.14 Pin Function Selection Bit GPB_MFP14 determines the PB.14 function. (bits: 14)
    ,GPB_MFP14_MASK = 0x00004000
    ,GPB_MFP14_POS = 14
    ,GPB_MFP14_0 = 0x00000000 // GPIO function is selected
    ,GPB_MFP14_1 = 0x00004000 // INT0 function is selected
    // PB.15 Pin Function Selection Bits PB15_BPWM15 (ALT_MFP3[23]), PB15_T0EX (ALT_MFP[24]), PB15_TM0 (ALT_MFP2[2]) and GPB_MFP15 determine the PB.15 function. (PB15_BPWM15, PB15_T0EX, PB15_TM0, GPB_MFP15) value and function mapping is as following list. (bits: 15)
    ,GPB_MFP15_MASK = 0x00008000
    ,GPB_MFP15_POS = 15
    ,GPB_MFP15 = 0x00008000
    // Trigger Function Selection (bits: 31-16)
    ,GPB_TYPEN_MASK = 0xFFFF0000
    ,GPB_TYPEN_POS = 16
    ,GPB_TYPEN_0 = 0x00000000 // GPIOB[15:0] I/O input Schmitt Trigger function Disabled
    ,GPB_TYPEN_1 = 0x00010000 // GPIOB[15:0] I/O input Schmitt Trigger function Enabled
    ,GPB_MFP_MASK = 0xFFFFDFFF
    ;
  };
  // GPIOC Multiple Function and Input Type Control Register
  struct GPC_MFP : reg<ip_ver, base + 0x38>
  {
    static constexpr typename GPC_MFP::type
    // PC.0 Pin Function Selection Bits PC0_BPWM00 (ALT_MFP3[12]) and GPC_MFP0 determine the PC.0 function. (PC0_BPWM00, GPC_MFP0) value and function mapping is as following list. (bits: 0)
     GPC_MFP0_MASK = 0x00000001
    ,GPC_MFP0_POS = 0
    ,GPC_MFP0 = 0x00000001
    // PC.1 Pin Function Selection Bits PC1_BPWM01 (ALT_MFP3[13]) and GPC_MFP1 determine the PC.1 function. (PC1_BPWM01, GPC_MFP1) value and function mapping is as following list. (bits: 1)
    ,GPC_MFP1_MASK = 0x00000002
    ,GPC_MFP1_POS = 1
    ,GPC_MFP1 = 0x00000002
    // PC.2 Pin Function Selection Bits PC2_BPWM02 (ALT_MFP3[14]) and GPC_MFP2 determine the PC.2 function. (PC2_BPWM02, GPC_MFP2) value and function mapping is as following list. (bits: 2)
    ,GPC_MFP2_MASK = 0x00000004
    ,GPC_MFP2_POS = 2
    ,GPC_MFP2 = 0x00000004
    // PC.3 Pin Function Selection Bits PC3_BPWM03 (ALT_MFP3[15]) and GPC_MFP3 determine the PC.3 function. (PC3_BPWM03, GPC_MFP3) value and function mapping is as following list. (bits: 3)
    ,GPC_MFP3_MASK = 0x00000008
    ,GPC_MFP3_POS = 3
    ,GPC_MFP3 = 0x00000008
    // PC.6 Pin Function Selection Bits PC6_PWM0BK0 (ALT_MFP3[28]), PC6_I2C0SDA (ALT_MFP4[10]) and GPC_MFP6 determine the PC.6 function. (PC6_PWM0BK0, PC6_I2C0SDA, GPC_MFP6) value and function mapping is as following list. (bits: 6)
    ,GPC_MFP6_MASK = 0x00000040
    ,GPC_MFP6_POS = 6
    ,GPC_MFP6 = 0x00000040
    // PC.7 Pin Function Selection Bits PC7_PWM0BK1 (ALT_MFP3[29]), PC7_I2C0SCL (ALT_MFP4[11]) and GPC_MFP7 determine the PC.7 function. (PC7_PWM0BK1, PC7_I2C0SCL, GPC_MFP7) value and function mapping is as following list. (bits: 7)
    ,GPC_MFP7_MASK = 0x00000080
    ,GPC_MFP7_POS = 7
    ,GPC_MFP7 = 0x00000080
    // PC.8 Pin Function Selection Bit GPC_MFP8 determines the PC.8 function. (bits: 8)
    ,GPC_MFP8_MASK = 0x00000100
    ,GPC_MFP8_POS = 8
    ,GPC_MFP8_0 = 0x00000000 // GPIO function is selected
    ,GPC_MFP8_1 = 0x00000100 // PWM0_BRAKE0 function is selected
    // PC.9 Pin Function Selection Bit GPC_MFP9 determines the PC.9 function. (bits: 9)
    ,GPC_MFP9_MASK = 0x00000200
    ,GPC_MFP9_POS = 9
    ,GPC_MFP9_0 = 0x00000000 // GPIO function is selected
    ,GPC_MFP9_1 = 0x00000200 // PWM0_BRAKE1 function is selected
    // PC.10 Pin Function Selection Bit GPC_MFP10 determines the PC.10 function. (bits: 10)
    ,GPC_MFP10_MASK = 0x00000400
    ,GPC_MFP10_POS = 10
    ,GPC_MFP10_0 = 0x00000000 // GPIO function is selected
    ,GPC_MFP10_1 = 0x00000400 // PWM1_BRAKE0 function is selected
    // PC.11 Pin Function Selection Bit GPC_MFP11 determines the PC.11 function. (bits: 11)
    ,GPC_MFP11_MASK = 0x00000800
    ,GPC_MFP11_POS = 11
    ,GPC_MFP11_0 = 0x00000000 // GPIO function is selected
    ,GPC_MFP11_1 = 0x00000800 // PWM1_BRAKE1 function is selected
    // Trigger Function Selection (bits: 31-16)
    ,GPC_TYPEN_MASK = 0xFFFF0000
    ,GPC_TYPEN_POS = 16
    ,GPC_TYPEN_0 = 0x00000000 // GPIOC[15:0] I/O input Schmitt Trigger function Disabled
    ,GPC_TYPEN_1 = 0x00010000 // GPIOC[15:0] I/O input Schmitt Trigger function Enabled
    ,GPC_MFP_MASK = 0xFFFF0FCF
    ;
  };
  // GPIOD Multiple Function and Input Type Control Register
  struct GPD_MFP : reg<ip_ver, base + 0x3C>
  {
    static constexpr typename GPD_MFP::type
    // PD.6 Pin Function Selection Bits PD6_BPWM11 (ALT_MFP3[19]) and GPD_MFP6 determine the PD.6 function. (PD6_BPWM11, GPD_MFP6) value and function mapping is as following list. (bits: 6)
     GPD_MFP6_MASK = 0x00000040
    ,GPD_MFP6_POS = 6
    ,GPD_MFP6 = 0x00000040
    // PD.7 Pin Function Selection Bits PD7_BPWM10 (ALT_MFP3[18]) and GPD_MFP7 determine the PD.7 function. (PD7_BPWM10, GPD_MFP7) value and function mapping is as following list. (bits: 7)
    ,GPD_MFP7_MASK = 0x00000080
    ,GPD_MFP7_POS = 7
    ,GPD_MFP7 = 0x00000080
    // PD.14 Pin Function Selection Bits PD14_BPWM05 (ALT_MFP3[17]) and GPD_MFP14 determine the PD.14 function. (PD14_BPWM05, GPD_MFP14) value and function mapping is as following list. (bits: 14)
    ,GPD_MFP14_MASK = 0x00004000
    ,GPD_MFP14_POS = 14
    ,GPD_MFP14 = 0x00004000
    // PD.15 Pin Function Selection Bits PD15_BPWM04 (ALT_MFP3[16]) and GPD_MFP15 determine the PD.15 function. (PD15_BPWM04, GPD_MFP15) value and function mapping is as following list. (bits: 15)
    ,GPD_MFP15_MASK = 0x00008000
    ,GPD_MFP15_POS = 15
    ,GPD_MFP15 = 0x00008000
    // Trigger Function Selection (bits: 31-16)
    ,GPD_TYPEN_MASK = 0xFFFF0000
    ,GPD_TYPEN_POS = 16
    ,GPD_TYPEN_0 = 0x00000000 // GPIOD[15:0] I/O input Schmitt Trigger function Disabled
    ,GPD_TYPEN_1 = 0x00010000 // GPIOD[15:0] I/O input Schmitt Trigger function Enabled
    ,GPD_MFP_MASK = 0xFFFFC0C0
    ;
  };
  // GPIOE Multiple Function and Input Type Control Register
  struct GPE_MFP : reg<ip_ver, base + 0x40>
  {
    static constexpr typename GPE_MFP::type
    // PE.5 Pin Function Selection Bits PE5_T1EX (ALT_MFP[25]), PE5_TM1 (ALT_MFP2[3]) and GPE_MFP5 determine the PE.5 function. (PE5_T1EX, PE5_TM1, GPE_MFP5) value and function mapping is as following list. (bits: 5)
     GPE_MFP5_MASK = 0x00000020
    ,GPE_MFP5_POS = 5
    ,GPE_MFP5 = 0x00000020
    // Trigger Function Selection (bits: 21)
    ,GPE_TYPE5_MASK = 0x00200000
    ,GPE_TYPE5_POS = 21
    ,GPE_TYPE5_0 = 0x00000000 // GPIOE[5] I/O input Schmitt Trigger function Disabled
    ,GPE_TYPE5_1 = 0x00200000 // GPIOE[5] I/O input Schmitt Trigger function Enabled
    ,GPE_MFP_MASK = 0x00200020
    ;
  };
  // GPIOF Multiple Function and Input Type Control Register
  struct GPF_MFP : reg<ip_ver, base + 0x44, 0x000000C0>
  {
    static constexpr typename GPF_MFP::type
    // PF.0 Pin Function Selection Bit GPF_MFP0 determines the PF.0 function. Note: This bit is read only and is decided by user configuration CGPFMFP (CONFIG0[27]). (bits: 0)
     GPF_MFP0_MASK = 0x00000001
    ,GPF_MFP0_POS = 0
    ,GPF_MFP0_0 = 0x00000000 // GPIO function is selected
    ,GPF_MFP0_1 = 0x00000001 // XT1_OUT function is selected
    // PF.1 Pin Function Selection Bit GPF_MFP1 determine the PF.1 function. Note: This bit is read only and is decided by user configuration CGPFMFP (CONFIG0[27]). (bits: 1)
    ,GPF_MFP1_MASK = 0x00000002
    ,GPF_MFP1_POS = 1
    ,GPF_MFP1_0 = 0x00000000 // GPIO function is selected
    ,GPF_MFP1_1 = 0x00000002 // XT1_IN function is selected
    // PF.4 Pin Function Selection Bits PF4_PWM14 (ALT_MFP3[10]) and GPF_MFP4 determine the PF.4 function. (PF4_PWM14, GPF_MFP4) value and function mapping is as following list. (bits: 4)
    ,GPF_MFP4_MASK = 0x00000010
    ,GPF_MFP4_POS = 4
    ,GPF_MFP4 = 0x00000010
    // PF.5 Pin Function Selection Bits PF5_PWM15 (ALT_MFP3[11]) and GPF_MFP5 determine the PF.5 function. (PF5_PWM15, GPF_MFP5) value and function mapping is as following list. (bits: 5)
    ,GPF_MFP5_MASK = 0x00000020
    ,GPF_MFP5_POS = 5
    ,GPF_MFP5 = 0x00000020
    // PF.6 Pin Function Selection Bit GPF_MFP6 determines the PF.6 function. (bits: 6)
    ,GPF_MFP6_MASK = 0x00000040
    ,GPF_MFP6_POS = 6
    ,GPF_MFP6_0 = 0x00000000 // GPIO function is selected
    ,GPF_MFP6_1 = 0x00000040 // ICE_CLK function is selected
    // PF.7 Pin Function Selection Bit GPF_MFP7 determines the PF.7 function. (bits: 7)
    ,GPF_MFP7_MASK = 0x00000080
    ,GPF_MFP7_POS = 7
    ,GPF_MFP7_0 = 0x00000000 // GPIO function is selected
    ,GPF_MFP7_1 = 0x00000080 // ICE_DAT function is selected
    // PF.8 Pin Function Selection Bit PF8_BPWM14 (ALT_MFP3[22]), GPF_MFP8 determines the PF.8 function. (PF8_BPWM14, GPF_MFP8) value and function mapping is as following list. (bits: 8)
    ,GPF_MFP8_MASK = 0x00000100
    ,GPF_MFP8_POS = 8
    ,GPF_MFP8 = 0x00000100
    // Trigger Function Selection (bits: 24-16)
    ,GPF_TYPEN_MASK = 0x01FF0000
    ,GPF_TYPEN_POS = 16
    ,GPF_TYPEN_0 = 0x00000000 // GPIOF[8:0] I/O input Schmitt Trigger function Disabled
    ,GPF_TYPEN_1 = 0x00010000 // GPIOF[8:0] I/O input Schmitt Trigger function Enabled
    ,GPF_MFP_MASK = 0x01FF01F3
    ;
  };
  // Alternative Multiple Function Pin Control Register
  struct ALT_MFP : reg<ip_ver, base + 0x50>
  {
    static constexpr typename ALT_MFP::type
    // PB.15 Pin Alternative Function Selection Bits PB15_BPWM15 (ALT_MFP3[23]), PB15_T0EX (ALT_MFP[24]), PB15_TM0 (ALT_MFP2[2]) and GPB_MFP15 determine the PB.15 function. (PB15_BPWM15, PB15_T0EX, PB15_TM0, GPB_MFP15) value and function mapping is as following list. (bits: 24)
     PB15_T0EX_MASK = 0x01000000
    ,PB15_T0EX_POS = 24
    ,PB15_T0EX = 0x01000000
    // PE.5 Pin Alternative Function Selection Bits PE5_T1EX (ALT_MFP[25]), PE5_TM1 (ALT_MFP2[3]) and GPE_MFP5 determine the PE.5 function. (PE5_T1EX, PE5_TM1, GPE_MFP5) value and function mapping is as following list. (bits: 25)
    ,PE5_T1EX_MASK = 0x02000000
    ,PE5_T1EX_POS = 25
    ,PE5_T1EX = 0x02000000
    // PB.2 Pin Alternative Function Selection Bits PB2_TM2 (ALT_MFP2[4]), PB2_PWM1BK1 (ALT_MFP3[31]), PB2_T2EX (ALT_MFP[26]) and GPB_MFP2 determine the PB.2 function. (PB2_TM2, PB2_PWM1BK1, PB2_T2EX, GPB_MFP2) value and function mapping is as following list. (bits: 26)
    ,PB2_T2EX_MASK = 0x04000000
    ,PB2_T2EX_POS = 26
    ,PB2_T2EX = 0x04000000
    // PB.3 Pin Alternative Function Selection Bits PB3_TM3 (ALT_MFP2[5]), PB3_PWM1BK0 (ALT_MFP3[30]), PB3_T3EX (ALT_MFP[27]) and GPB_MFP3 determine the PB.3 function. (PB3_TM3, PB3_PWM1BK0, PB3_T3EX, GPB_MFP3) value and function mapping is as following list. (bits: 27)
    ,PB3_T3EX_MASK = 0x08000000
    ,PB3_T3EX_POS = 27
    ,PB3_T3EX = 0x08000000
    // PB.8 Pin Alternative Function Selection Bits PB8_BPWM12 (ALT_MFP3[20]), PB8_CLKO (ALT_MFP[29]) and GPB_MFP8 determine the PB.8 function. (PB8_BPWM12, PB8_CLKO, GPB_MFP8) value and function mapping is as following list. (bits: 29)
    ,PB8_CLKO_MASK = 0x20000000
    ,PB8_CLKO_POS = 29
    ,PB8_CLKO = 0x20000000
    ,ALT_MFP_MASK = 0x2F000000
    ;
  };
  // Alternative Multiple Function Pin Control Register 2
  struct ALT_MFP2 : reg<ip_ver, base + 0x5C>
  {
    static constexpr typename ALT_MFP2::type
    // PB.15 Pin Alternative Function Selection Bits PB15_BPWM15 (ALT_MFP3[23]), PB15_T0EX (ALT_MFP[24]), PB15_TM0 (ALT_MFP2[2]) and GPB_MFP15 determine the PB.15 function. (PB15_BPWM15, PB15_T0EX, PB15_TM0, GPB_MFP15) value and function mapping is as following list. (bits: 2)
     PB15_TM0_MASK = 0x00000004
    ,PB15_TM0_POS = 2
    ,PB15_TM0 = 0x00000004
    // PE.5 Pin Alternative Function Selection Bits PE5_T1EX (ALT_MFP[25]), PE5_TM1 (ALT_MFP2[3]) and GPE_MFP5 determine the PE.5 function. (PE5_T1EX, PE5_TM1, GPE_MFP5) value and function mapping is as following list. (bits: 3)
    ,PE5_TM1_MASK = 0x00000008
    ,PE5_TM1_POS = 3
    ,PE5_TM1 = 0x00000008
    // PB.2 Pin Alternative Function Selection Bits PB2_TM2 (ALT_MFP2[4]), PB2_PWM1BK1 (ALT_MFP3[31]), PB2_T2EX (ALT_MFP[26]) and GPB_MFP2 determine the PB.2 function. (PB2_TM2, PB2_PWM1BK1, PB2_T2EX, GPB_MFP2) value and function mapping is as following list. (bits: 4)
    ,PB2_TM2_MASK = 0x00000010
    ,PB2_TM2_POS = 4
    ,PB2_TM2 = 0x00000010
    // PB.3 Pin Alternative Function Selection Bits PB3_TM3 (ALT_MFP2[5]), PB3_PWM1BK0 (ALT_MFP3[30]), PB3_T3EX (ALT_MFP[27]) and GPB_MFP3 determine the PB.3 function. (PB3_TM3, PB3_PWM1BK0, PB3_T3EX, GPB_MFP3) value and function mapping is as following list. (bits: 5)
    ,PB3_TM3_MASK = 0x00000020
    ,PB3_TM3_POS = 5
    ,PB3_TM3 = 0x00000020
    ,ALT_MFP2_MASK = 0x0000003C
    ;
  };
  // Alternative Multiple Function Pin Control Register 3
  struct ALT_MFP3 : reg<ip_ver, base + 0x60>
  {
    static constexpr typename ALT_MFP3::type
    // PA.0 Pin Alternative Function Selection Bits PA0_PWM04 (ALT_MFP3[4]), PA0_UR5TXD (ALT_MFP4[7]), PA0_I2C1SCL (ALT_MFP4[12]) and GPA_MFP0 determine the PA.0 function. (PA0_PWM04, PA0_UR5TXD, PA0_I2C1SCL, GPA_MFP0) value and function mapping is as following list. (bits: 4)
     PA0_PWM04_MASK = 0x00000010
    ,PA0_PWM04_POS = 4
    ,PA0_PWM04 = 0x00000010
    // PA.1 Pin Alternative Function Selection Bits PA1_PWM05 (ALT_MFP3[5]), PA1_UR5RXD (ALT_MFP4[6]), PA1_I2C1SDA (ALT_MFP4[13]) and GPA_MFP1 determine the PA.1 function. (PA1_PWM05, PA1_UR5RXD , PA1_I2C1SDA, GPA_MFP1) value and function mapping is as following list. (bits: 5)
    ,PA1_PWM05_MASK = 0x00000020
    ,PA1_PWM05_POS = 5
    ,PA1_PWM05 = 0x00000020
    // PA.2 Pin Alternative Function Selection Bits PA2_PWM10 (ALT_MFP3[6]), PA2_UR3TXD (ALT_MFP4[3]) and GPA_MFP2 determine the PA.2 function. (PA2_PWM10, PA2_UR3TXD, GPA_MFP2) value and function mapping is as following list. (bits: 6)
    ,PA2_PWM10_MASK = 0x00000040
    ,PA2_PWM10_POS = 6
    ,PA2_PWM10 = 0x00000040
    // PA.3 Pin Alternative Function Selection Bits PA3_PWM11 (ALT_MFP3[7]), PA3_UR3RXD (ALT_MFP4[2]) and GPA_MFP3 determine the PA.3 function. (PA3_PWM11, PA3_UR3RXD, GPA_MFP3) value and function mapping is as following list. (bits: 7)
    ,PA3_PWM11_MASK = 0x00000080
    ,PA3_PWM11_POS = 7
    ,PA3_PWM11 = 0x00000080
    // PA.10 Pin Alternative Function Selection Bits PA10_PWM12 (ALT_MFP3[8]) and GPA_MFP10 determine the PA.10 function. (PA10_PWM12, GPA_MFP10) value and function mapping is as following list. (bits: 8)
    ,PA10_PWM12_MASK = 0x00000100
    ,PA10_PWM12_POS = 8
    ,PA10_PWM12 = 0x00000100
    // PA.11 Pin Alternative Function Selection Bits PA11_PWM13 (ALT_MFP3[9]) and GPA_MFP11 determine the PA.11 function. (PA11_PWM13, GPA_MFP11) value and function mapping is as following list. (bits: 9)
    ,PA11_PWM13_MASK = 0x00000200
    ,PA11_PWM13_POS = 9
    ,PA11_PWM13 = 0x00000200
    // PF.4 Pin Alternative Function Selection Bits PF4_PWM14 (ALT_MFP3[10]) and GPF_MFP4 determine the PF.4 function. (PF4_PWM14, GPF_MFP4) value and function mapping is as following list. (bits: 10)
    ,PF4_PWM14_MASK = 0x00000400
    ,PF4_PWM14_POS = 10
    ,PF4_PWM14 = 0x00000400
    // PF.5 Pin Alternative Function Selection Bits PF5_PWM15 (ALT_MFP3[11]) and GPF_MFP5 determine the PF.5 function. (PF5_PWM15, GPF_MFP5) value and function mapping is as following list. (bits: 11)
    ,PF5_PWM15_MASK = 0x00000800
    ,PF5_PWM15_POS = 11
    ,PF5_PWM15 = 0x00000800
    // PC.0 Pin Alternative Function Selection Bits PC0_BPWM00 (ALT_MFP3[12]) and GPC_MFP0 determine the PC.0 function. (PC0_BPWM00, GPC_MFP0) value and function mapping is as following list. (bits: 12)
    ,PC0_BPWM00_MASK = 0x00001000
    ,PC0_BPWM00_POS = 12
    ,PC0_BPWM00 = 0x00001000
    // PC.1 Pin Alternative Function Selection Bits PC1_BPWM01 (ALT_MFP3[13]) and GPC_MFP1 determine the PC.1 function. (PC1_BPWM01, GPC_MFP1) value and function mapping is as following list. (bits: 13)
    ,PC1_BPWM01_MASK = 0x00002000
    ,PC1_BPWM01_POS = 13
    ,PC1_BPWM01 = 0x00002000
    // PC.2 Pin Alternative Function Selection Bits PC2_BPWM02 (ALT_MFP3[14]) and GPC_MFP2 determine the PC.2 function. (PC2_BPWM02, GPC_MFP2) value and function mapping is as following list. (bits: 14)
    ,PC2_BPWM02_MASK = 0x00004000
    ,PC2_BPWM02_POS = 14
    ,PC2_BPWM02 = 0x00004000
    // PC.3 Pin Alternative Function Selection Bits PC3_BPWM03 (ALT_MFP3[15]) and GPC_MFP3 determine the PC.3 function. (PC3_BPWM03, GPC_MFP3) value and function mapping is as following list. (bits: 15)
    ,PC3_BPWM03_MASK = 0x00008000
    ,PC3_BPWM03_POS = 15
    ,PC3_BPWM03 = 0x00008000
    // PD.15 Pin Alternative Function Selection Bits PD15_BPWM04 (ALT_MFP3[16]) and GPD_MFP15 determine the PD.15 function. (PD15_BPWM04, GPD_MFP15) value and function mapping is as following list. (bits: 16)
    ,PD15_BPWM04_MASK = 0x00010000
    ,PD15_BPWM04_POS = 16
    ,PD15_BPWM04 = 0x00010000
    // PD.14 Pin Alternative Function Selection Bits PD14_BPWM05 (ALT_MFP3[17]) and GPD_MFP14 determine the PD.14 function. (PD14_BPWM05, GPD_MFP14) value and function mapping is as following list. (bits: 17)
    ,PD14_BPWM05_MASK = 0x00020000
    ,PD14_BPWM05_POS = 17
    ,PD14_BPWM05 = 0x00020000
    // PD.7 Pin Alternative Function Selection Bits PD7_BPWM10 (ALT_MFP3[18]) and GPD_MFP7 determine the PD.7 function. (PD7_BPWM10, GPD_MFP7) value and function mapping is as following list. (bits: 18)
    ,PD7_BPWM10_MASK = 0x00040000
    ,PD7_BPWM10_POS = 18
    ,PD7_BPWM10 = 0x00040000
    // PD.6 Pin Alternative Function Selection Bits PD6_BPWM11 (ALT_MFP3[19]) and GPD_MFP6 determine the PD.6 function. (PD6_BPWM11, GPD_MFP6) value and function mapping is as following list. (bits: 19)
    ,PD6_BPWM11_MASK = 0x00080000
    ,PD6_BPWM11_POS = 19
    ,PD6_BPWM11 = 0x00080000
    // PB.8 Pin Alternative Function Selection Bits PB8_BPWM12 (ALT_MFP3[20]), PB8_CLKO (ALT_MFP[29]) and GPB_MFP8 determine the PB.8 function. (PB8_BPWM12, PB8_CLKO, GPB_MFP8) value and function mapping is as following list. (bits: 20)
    ,PB8_BPWM12_MASK = 0x00100000
    ,PB8_BPWM12_POS = 20
    ,PB8_BPWM12 = 0x00100000
    // PB.12 Pin Alternative Function Selection Bits PB12_BPWM13 (ALT_MFP3[21]) and GPB_MFP12 determine the PB.12 function. (PB12_BPWM13, GPB_MFP12) value and function mapping is as following list. (bits: 21)
    ,PB12_BPWM13_MASK = 0x00200000
    ,PB12_BPWM13_POS = 21
    ,PB12_BPWM13 = 0x00200000
    // PF.8 Pin Function Selection Bit PF8_BPWM14 (ALT_MFP3[22]), GPF_MFP8 determines the PF.8 function. (PF8_BPWM14, GPF_MFP8) value and function mapping is as following list. (bits: 22)
    ,PF8_BPWM14_MASK = 0x00400000
    ,PF8_BPWM14_POS = 22
    ,PF8_BPWM14 = 0x00400000
    // PB.15 Pin Function Selection Bits PB15_BPWM15 (ALT_MFP3[23]), PB15_T0EX (ALT_MFP[24]), PB15_TM0 (ALT_MFP2[2]) and GPB_MFP15 determine the PB.15 function. (PB15_BPWM15, PB15_T0EX, PB15_TM0, GPB_MFP15) value and function mapping is as following list. (bits: 23)
    ,PB15_BPWM15_MASK = 0x00800000
    ,PB15_BPWM15_POS = 23
    ,PB15_BPWM15 = 0x00800000
    // PB.11 Pin Alternative Function Selection Bits PB11_PWM04 (ALT_MFP3[24]) and GPB_MFP11 determine the PB.11 function. (PB11_PWM04, GPB_MFP11) value and function mapping is as following list. (bits: 24)
    ,PB11_PWM04_MASK = 0x01000000
    ,PB11_PWM04_POS = 24
    ,PB11_PWM04 = 0x01000000
    // PC.6 Pin Alternative Function Selection Bits PC6_PWM0BK0 (ALT_MFP3[28]), PC6_I2C0SDA (ALT_MFP4[10]) and GPC_MFP6 determine the PC.6 function. (PC6_PWM0BK0, PC6_I2C0SDA, GPB_MFP6) value and function mapping is as following list. (bits: 28)
    ,PC6_PWM0BK0_MASK = 0x10000000
    ,PC6_PWM0BK0_POS = 28
    ,PC6_PWM0BK0 = 0x10000000
    // PC.7 Pin Alternative Function Selection Bits PC7_PWM0BK1 (ALT_MFP3[29]), PC7_I2C0SCL (ALT_MFP4[11]) and GPC_MFP7 determine the PC.7 function. (PC7_PWM0BK1, PC7_I2C0SCL, GPC_MFP7) value and function mapping is as following list. (bits: 29)
    ,PC7_PWM0BK1_MASK = 0x20000000
    ,PC7_PWM0BK1_POS = 29
    ,PC7_PWM0BK1 = 0x20000000
    // PB.3 Pin Alternative Function Selection Bits PB3_TM3 (ALT_MFP2[5]), PB3_PWM1BK0 (ALT_MFP3[30]), PB3_T3EX (ALT_MFP[27]) and GPB_MFP3 determine the PB.3 function. (PB3_TM3, PB3_PWM1BK0, PB3_T3EX, GPB_MFP3) value and function mapping is as following list. (bits: 30)
    ,PB3_PWM1BK0_MASK = 0x40000000
    ,PB3_PWM1BK0_POS = 30
    ,PB3_PWM1BK0 = 0x40000000
    // PB.2 Pin Alternative Function Selection Bits PB2_TM2 (ALT_MFP2[4]), PB2_PWM1BK1 (ALT_MFP3[31]), PB2_T2EX (ALT_MFP[26]) and GPB_MFP2 determine the PB.2 function. (PB2_TM2, PB2_PWM1BK1, PB2_T2EX, GPB_MFP2) value and function mapping is as following list. (bits: 31)
    ,PB2_PWM1BK1_MASK = 0x80000000
    ,PB2_PWM1BK1_POS = 31
    ,PB2_PWM1BK1 = 0x80000000
    ,ALT_MFP3_MASK = 0xF1FFFFF0
    ;
  };
  // Alternative Multiple Function Pin Control Register 4
  struct ALT_MFP4 : reg<ip_ver, base + 0x64>
  {
    static constexpr typename ALT_MFP4::type
    // PA.8 Pin Alternative Function Selection Bits PA8_UR1RTS (ALT_MFP4[0]) and GPA_MFP8 determine the PA.8 function. (PA8_UR1RTS, GPA_MFP8) value and function mapping is as following list. (bits: 0)
     PA8_UR1RTS_MASK = 0x00000001
    ,PA8_UR1RTS_POS = 0
    ,PA8_UR1RTS = 0x00000001
    // PA.9 Pin Alternative Function Selection Bits PA9_UR1CTS (ALT_MFP4[1]) and GPA_MFP9 determine the PA.9 function. (PA9_UR1CTS, GPA_MFP9) value and function mapping is as following list. (bits: 1)
    ,PA9_UR1CTS_MASK = 0x00000002
    ,PA9_UR1CTS_POS = 1
    ,PA9_UR1CTS = 0x00000002
    // PA.3 Pin Alternative Function Selection Bits PA3_PWM11 (ALT_MFP3[7]), PA3_UR3RXD (ALT_MFP4[2]) and GPA_MFP3 determine the PA.3 function. (PA3_PWM11, PA3_UR3RXD, GPA_MFP3) value and function mapping is as following list. (bits: 2)
    ,PA3_UR3RXD_MASK = 0x00000004
    ,PA3_UR3RXD_POS = 2
    ,PA3_UR3RXD = 0x00000004
    // PA.2 Pin Alternative Function Selection Bits PA2_PWM10 (ALT_MFP3[6]), PA2_UR3TXD (ALT_MFP4[3]) and GPA_MFP2 determine the PA.2 function. (PA2_PWM10, PA2_UR3TXD, GPA_MFP2) value and function mapping is as following list. (bits: 3)
    ,PA2_UR3TXD_MASK = 0x00000008
    ,PA2_UR3TXD_POS = 3
    ,PA2_UR3TXD = 0x00000008
    // PA.5 Pin Alternative Function Selection Bits PA5_UR3RXD (ALT_MFP4[4]) and GPA_MFP5 determine the PA.5 function. (PA5_UR3RXD, GPA_MFP5) value and function mapping is as following list. (bits: 4)
    ,PA5_UR3RXD_MASK = 0x00000010
    ,PA5_UR3RXD_POS = 4
    ,PA5_UR3RXD = 0x00000010
    // PA.6 Pin Alternative Function Selection Bits PA6_UR3TXD (ALT_MFP4[5]) and GPA_MFP6 determine the PA.6 function. (PA6_UR3TXD, GPA_MFP6) value and function mapping is as following list. (bits: 5)
    ,PA6_UR3TXD_MASK = 0x00000020
    ,PA6_UR3TXD_POS = 5
    ,PA6_UR3TXD = 0x00000020
    // PA.1 Pin Alternative Function Selection Bits PA1_PWM05 (ALT_MFP3[5]), PA1_UR5RXD (ALT_MFP4[6]), PA1_I2C1SDA (ALT_MFP4[13]) and GPA_MFP1 determine the PA.1 function. (PA1_PWM05, PA1_UR5RXD, PA1_I2C1SDA, GPA_MFP1) value and function mapping is as following list. (bits: 6)
    ,PA1_UR5RXD_MASK = 0x00000040
    ,PA1_UR5RXD_POS = 6
    ,PA1_UR5RXD = 0x00000040
    // PA.0 Pin Alternative Function Selection Bits PA0_PWM04 (ALT_MFP3[4]), PA0_UR5TXD (ALT_MFP4[7]), PA0_I2C1SCL (ALT_MFP4[12]) and GPA_MFP0 determine the PA.0 function. (PA0_PWM04, PA0_UR5TXD, PA0_I2C1SCL, GPA_MFP0) value and function mapping is as following list. (bits: 7)
    ,PA0_UR5TXD_MASK = 0x00000080
    ,PA0_UR5TXD_POS = 7
    ,PA0_UR5TXD = 0x00000080
    // PA.12 Pin Alternative Function Selection Bits PA12_UR5RXD (ALT_MFP4[8]) and GPA_MFP12 determine the PA.12 function. (PA12_UR5RXD, GPA_MFP12) value and function mapping is as following list. (bits: 8)
    ,PA12_UR5RXD_MASK = 0x00000100
    ,PA12_UR5RXD_POS = 8
    ,PA12_UR5RXD = 0x00000100
    // PA.13 Pin Alternative Function Selection Bits PA13_UR5TXD (ALT_MFP4[9]) and GPA_MFP13 determine the PA.13 function. (PA13_UR5TXD, GPA_MFP13) value and function mapping is as following list. (bits: 9)
    ,PA13_UR5TXD_MASK = 0x00000200
    ,PA13_UR5TXD_POS = 9
    ,PA13_UR5TXD = 0x00000200
    // PC.6 Pin Alternative Function Selection Bits PC6_PWM0BK0 (ALT_MFP3[28]), PC6_I2C0SDA (ALT_MFP4[10]) and GPC_MFP6 determine the PC.6 function. (PC6_PWM0BK0, PC6_I2C0SDA, GPC_MFP6) value and function mapping is as following list. (bits: 10)
    ,PC6_I2C0SDA_MASK = 0x00000400
    ,PC6_I2C0SDA_POS = 10
    ,PC6_I2C0SDA = 0x00000400
    // PC.7 Pin Alternative Function Selection Bits PC7_PWM0BK1 (ALT_MFP3[29]), PC7_I2C0SCL (ALT_MFP4[11]) and GPC_MFP7 determine the PC.7 function. (PC7_PWM0BK1, PC7_I2C0SCL, GPC_MFP7) value and function mapping is as following list. (bits: 11)
    ,PC7_I2C0SCL_MASK = 0x00000800
    ,PC7_I2C0SCL_POS = 11
    ,PC7_I2C0SCL = 0x00000800
    // PA.0 Pin Alternative Function Selection Bits PA0_PWM04 (ALT_MFP3[4]), PA0_UR5TXD (ALT_MFP4[7]), PA0_I2C1SCL (ALT_MFP4[12]) and GPA_MFP0 determine the PA.0 function. (PA0_PWM04, PA0_UR5TXD, PA0_I2C1SCL, GPA_MFP0) value and function mapping is as following list. (bits: 12)
    ,PA0_I2C1SCL_MASK = 0x00001000
    ,PA0_I2C1SCL_POS = 12
    ,PA0_I2C1SCL = 0x00001000
    // PA.1 Pin Alternative Function Selection Bits PA1_PWM05 (ALT_MFP3[5]), PA1_UR5RXD (ALT_MFP4[6]), PA1_I2C1SDA (ALT_MFP4[13]) and GPA_MFP1 determine the PA.1 function. (PA1_PWM05, PA1_UR5RXD, PA1_I2C1SDA, GPA_MFP1) value and function mapping is as following list. (bits: 13)
    ,PA1_I2C1SDA_MASK = 0x00002000
    ,PA1_I2C1SDA_POS = 13
    ,PA1_I2C1SDA = 0x00002000
    // PA.7 Pin Alternative Function Selection Bits PA7_VREF (ALT_MFP4[14]) and GPA_MFP7 determine the PA.7 function. (PA7_VREF, GPA_MFP7) value and function mapping is as following list. (bits: 14)
    ,PA7_VREF_MASK = 0x00004000
    ,PA7_VREF_POS = 14
    ,PA7_VREF = 0x00004000
    ,ALT_MFP4_MASK = 0x00007FFF
    ;
  };
  // Register Write Protection Register
  struct REGWRPROT : reg<ip_ver, base + 0x100>
  {
    static constexpr typename REGWRPROT::type
    // Register Write-Protection Disable Index (Read Only) The Protected registers are: IPRSTC1: address 0x5000_0008 BODCR: address 0x5000_0018 PORCR: address 0x5000_0024 VREFCR: address 0x5000_0028 PWRCON: address 0x5000_0200 (bit[6] is not protected for power wake-up interrupt clear) APBCLK bit[0]: address 0x5000_0208 (bit[0] is Watchdog Timer clock enable) CLKSEL0: address 0x5000_0210 (for HCLK and CPU STCLK clock source selection) CLKSEL1 bit[1:0]: address 0x5000_0214 (for Watchdog Timer clock source selection) NMI_SEL bit[8]: address 0x5000_0380 (for NMI_EN clock source selection) ISPCON: address 0x5000_C000 (Flash ISP Control register) ISPTRG: address 0x5000_C010 (ISP Trigger Control register) FATCON: address 0x5000_C018 WTCR: address 0x4000_4000 WTCRALT: address 0x4000_4004 PWM_CTL0: address 0x4004_0000, 0x4014_0000 PWM_DTCTL0_1: address 0x4004_0070, 0x4014_0070 PWM_DTCTL2_3: address 0x4004_0074, 0x4014_0074 PWM_DTCTL4_5: address 0x4004_0078, 0x4014_0078 PWM_BRKCTL0_1: address 0x4004_00C8, 0x4014_00C8 PWM_BRKCTL2_3: address 0x4004_00CC, 0x4014_00CC PWM_BRKCTL4_5: address 0x4004_00D0, 0x4014_00D0 PWM_SWBRK: address 0x4004_00DC, 0x4014_00DC PWM_INTEN1: address 0x4004_00E4, 0x4014_00E4 PWM_INTSTS1: address 0x4004_00EC, 0x4014_00EC BPWM_CTL0: address 0x4004_4000, 0x4014_4000 Note: The bits which are write-protected will be noted as (Write Protect) beside the description. (bits: 0)
     REGPROTDIS_MASK = 0x00000001
    ,REGPROTDIS_POS = 0
    ,REGPROTDIS_0 = 0x00000000 // Write-protection is enabled for writing protected registers. Any write to the protected register is ignored
    ,REGPROTDIS_1 = 0x00000001 // Write-protection is disabled for writing protected registers
    // Register Write-Protection Code (Write Only) Some registers have write-protection function. Writing these registers have to disable the protected function by writing the sequence value [59h], [16h], [88h] to this field. After this sequence is completed, the REGPROTDIS bit will be set to 1 and write-protection registers can be normal write. (bits: 7-1)
    ,REGWRPROTVAL_MASK = 0x000000FE
    ,REGWRPROTVAL_POS = 1
    ,REGWRPROT_MASK = 0x000000FF
    ;
  };
}; // struct GCR

} // namespace lmcu::device::ip::v1

