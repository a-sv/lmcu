/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// SYS Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct SYS
{
  static constexpr auto ip_ver = ip_version::_1;

  // Part Device Identification Number Register
  struct PDID : reg<ip_ver, base + 0x0, 0x00451A93>
  {
    static constexpr typename PDID::type
    // Part Device Identification Number (Read Only) This register reflects device part number code. Software can read this register to identify which device is used. (bits: 31-0)
     PDIDVAL_MASK = 0xFFFFFFFF
    ,PDIDVAL_POS = 0
    ,PDID_MASK = 0xFFFFFFFF
    ;
  };
  // System Reset Status Register
  struct RSTSTS : reg<ip_ver, base + 0x4, 0x00000043>
  {
    static constexpr typename RSTSTS::type
    // POR Reset Flag The POR reset flag is set by the 'Reset Signal' from the Power-on Reset (POR) Controller or bit CHIPRST (SYS_IPRST0[0]) to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 0)
     PORF_MASK = 0x00000001
    ,PORF_POS = 0
    ,PORF_0 = 0x00000000 // No reset from POR or CHIPRST
    ,PORF_1 = 0x00000001 // Power-on Reset (POR) or CHIPRST had issued the reset signal to reset the system
    // NRESET Pin Reset Flag The nRESET pin reset flag is set by the 'Reset Signal' from the nRESET Pin to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 1)
    ,PINRF_MASK = 0x00000002
    ,PINRF_POS = 1
    ,PINRF_0 = 0x00000000 // No reset from nRESET pin
    ,PINRF_1 = 0x00000002 // Pin nRESET had issued the reset signal to reset the system
    // WDT Reset Flag The WDT reset flag is set by the 'Reset Signal' from the Watchdog Timer or Window Watchdog Timer to indicate the previous reset source. Note 1: Write 1 to clear this bit to 0. Note 2: Watchdog Timer register RSTF(WDT_CTL[2]) bit is set if the system has been reset by WDT time-out reset. Window Watchdog Timer register WWDTRF(WWDT_STATUS[1]) bit is set if the system has been reset by WWDT time-out reset. (bits: 2)
    ,WDTRF_MASK = 0x00000004
    ,WDTRF_POS = 2
    ,WDTRF_0 = 0x00000000 // No reset from watchdog timer or window watchdog timer
    ,WDTRF_1 = 0x00000004 // The watchdog timer or window watchdog timer had issued the reset signal to reset the system
    // LVR Reset Flag The LVR reset flag is set by the 'Reset Signal' from the Low Voltage Reset Controller to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 3)
    ,LVRF_MASK = 0x00000008
    ,LVRF_POS = 3
    ,LVRF_0 = 0x00000000 // No reset from LVR
    ,LVRF_1 = 0x00000008 // LVR controller had issued the reset signal to reset the system
    // BOD Reset Flag The BOD reset flag is set by the 'Reset Signal' from the Brown-Out Detector to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 4)
    ,BODRF_MASK = 0x00000010
    ,BODRF_POS = 4
    ,BODRF_0 = 0x00000000 // No reset from BOD
    ,BODRF_1 = 0x00000010 // The BOD had issued the reset signal to reset the system
    // System Reset Flag The system reset flag is set by the 'Reset Signal' from the Cortex-M4 Core to indicate the previous reset source. Note: Write 1 to clear this bit to 0. (bits: 5)
    ,SYSRF_MASK = 0x00000020
    ,SYSRF_POS = 5
    ,SYSRF_0 = 0x00000000 // No reset from Cortex-M4
    ,SYSRF_1 = 0x00000020 // The Cortex-M4 had issued the reset signal to reset the system by writing 1 to the bit SYSRESETREQ(AIRCR[2], Application Interrupt and Reset Control Register, address = 0xE000ED0C) in system control registers of Cortex-M4 core
    // HRESET Reset Flag The HRESET reset flag is set by the 'Reset Signal' from the HRESET. Note: Write 1 to clear this bit to 0. (bits: 6)
    ,HRESETRF_MASK = 0x00000040
    ,HRESETRF_POS = 6
    ,HRESETRF_0 = 0x00000000 // No reset from HRESET
    ,HRESETRF_1 = 0x00000040 // Reset from HRESET
    // CPU Reset Flag The CPU reset flag is set by hardware if software writes CPURST (SYS_IPRST0[1]) 1 to reset Cortex-M4 Core and Flash Memory Controller (FMC). Note: Write 1 to clear this bit to 0. (bits: 7)
    ,CPURF_MASK = 0x00000080
    ,CPURF_POS = 7
    ,CPURF_0 = 0x00000000 // No reset from CPU
    ,CPURF_1 = 0x00000080 // The Cortex-M4 Core and FMC are reset by software setting CPURST to 1
    // CPU Lockup Reset Flag Note 1: Write 1 to clear this bit to 0. Note 2: When CPU lockup happened under ICE is connected, this flag will set to 1 but chip will not reset. (bits: 8)
    ,CPULKRF_MASK = 0x00000100
    ,CPULKRF_POS = 8
    ,CPULKRF_0 = 0x00000000 // No reset from CPU lockup happened
    ,CPULKRF_1 = 0x00000100 // The Cortex-M4 lockup happened and chip is reset
    ,RSTSTS_MASK = 0x000001FF
    ;
  };
  // Peripheral Reset Control Register 0
  struct IPRST0 : reg<ip_ver, base + 0x8>
  {
    static constexpr typename IPRST0::type
    // Chip One-shot Reset (Write Protect) Setting this bit will reset the whole chip, including Processor core and all peripherals, and this bit will automatically return to 0 after the 2 clock cycles. The CHIPRST is same as the POR reset, all the chip controllers is reset and the chip setting from Flash are also reload. About the difference between CHIPRST and SYSRESETREQ(AIRCR[2]), please refer to section 7.2.2 Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     CHIPRST_MASK = 0x00000001
    ,CHIPRST_POS = 0
    ,CHIPRST_0 = 0x00000000 // Chip normal operation
    ,CHIPRST_1 = 0x00000001 // Chip one-shot reset
    // Processor Core One-shot Reset (Write Protect) Setting this bit will only reset the processor core and Flash Memory Controller(FMC), and this bit will automatically return to 0 after the 2 clock cycles. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 1)
    ,CPURST_MASK = 0x00000002
    ,CPURST_POS = 1
    ,CPURST_0 = 0x00000000 // Processor core normal operation
    ,CPURST_1 = 0x00000002 // Processor core one-shot reset
    // PDMA Controller Reset (Write Protect) Setting this bit to 1 will generate a reset signal to the PDMA. User needs to set this bit to 0 to release from reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 2)
    ,PDMARST_MASK = 0x00000004
    ,PDMARST_POS = 2
    ,PDMARST_0 = 0x00000000 // PDMA controller normal operation
    ,PDMARST_1 = 0x00000004 // PDMA controller reset
    // EBI Controller Reset (Write Protect) Set this bit to 1 will generate a reset signal to the EBI. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 3)
    ,EBIRST_MASK = 0x00000008
    ,EBIRST_POS = 3
    ,EBIRST_0 = 0x00000000 // EBI controller normal operation
    ,EBIRST_1 = 0x00000008 // EBI controller reset
    // EMAC Controller Reset (Write Protect) Setting this bit to 1 will generate a reset signal to the EMAC controller. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 5)
    ,EMACRST_MASK = 0x00000020
    ,EMACRST_POS = 5
    ,EMACRST_0 = 0x00000000 // EMAC controller normal operation
    ,EMACRST_1 = 0x00000020 // EMAC controller reset
    // SDHOST0 Controller Reset (Write Protect) Setting this bit to 1 will generate a reset signal to the SDHOST0 controller. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 6)
    ,SDH0RST_MASK = 0x00000040
    ,SDH0RST_POS = 6
    ,SDH0RST_0 = 0x00000000 // SDHOST0 controller normal operation
    ,SDH0RST_1 = 0x00000040 // SDHOST0 controller reset
    // CRC Calculation Controller Reset (Write Protect) Set this bit to 1 will generate a reset signal to the CRC calculation controller. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 7)
    ,CRCRST_MASK = 0x00000080
    ,CRCRST_POS = 7
    ,CRCRST_0 = 0x00000000 // CRC calculation controller normal operation
    ,CRCRST_1 = 0x00000080 // CRC calculation controller reset
    // CCAP Controller Reset (Write Protect) Set this bit to 1 will generate a reset signal to the CCAP controller. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 8)
    ,CCAPRST_MASK = 0x00000100
    ,CCAPRST_POS = 8
    ,CCAPRST_0 = 0x00000000 // CCAP controller normal operation
    ,CCAPRST_1 = 0x00000100 // CCAP controller reset
    // HSUSBD Controller Reset (Write Protect) Setting this bit to 1 will generate a reset signal to the HSUSBD controller. User needs to set this bit to 0 to release from the reset state. (bits: 10)
    ,HSUSBDRST_MASK = 0x00000400
    ,HSUSBDRST_POS = 10
    ,HSUSBDRST_0 = 0x00000000 // HSUSBD controller normal operation
    ,HSUSBDRST_1 = 0x00000400 // HSUSBD controller reset
    // CRYPTO Controller Reset (Write Protect) Setting this bit to 1 will generate a reset signal to the CRYPTO controller. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 12)
    ,CRPTRST_MASK = 0x00001000
    ,CRPTRST_POS = 12
    ,CRPTRST_0 = 0x00000000 // CRYPTO controller normal operation
    ,CRPTRST_1 = 0x00001000 // CRYPTO controller reset
    // SPIM Controller Reset Setting this bit to 1 will generate a reset signal to the SPIM controller. User needs to set this bit to 0 to release from the reset state. (bits: 14)
    ,SPIMRST_MASK = 0x00004000
    ,SPIMRST_POS = 14
    ,SPIMRST_0 = 0x00000000 // SPIM controller normal operation
    ,SPIMRST_1 = 0x00004000 // SPIM controller reset
    // HSUSBH Controller Reset (Write Protect) Set this bit to 1 will generate a reset signal to the HSUSBH controller. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 16)
    ,HSUSBHRST_MASK = 0x00010000
    ,HSUSBHRST_POS = 16
    ,HSUSBHRST_0 = 0x00000000 // HSUSBH controller normal operation
    ,HSUSBHRST_1 = 0x00010000 // HSUSBH controller reset
    // SDHOST1 Controller Reset (Write Protect) Setting this bit to 1 will generate a reset signal to the SDHOST1 controller. User needs to set this bit to 0 to release from the reset state. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 17)
    ,SDH1RST_MASK = 0x00020000
    ,SDH1RST_POS = 17
    ,SDH1RST_0 = 0x00000000 // SDHOST1 controller normal operation
    ,SDH1RST_1 = 0x00020000 // SDHOST1 controller reset
    ,IPRST0_MASK = 0x000355EF
    ;
  };
  // Peripheral Reset Control Register 1
  struct IPRST1 : reg<ip_ver, base + 0xC>
  {
    static constexpr typename IPRST1::type
    // GPIO Controller Reset (bits: 1)
     GPIORST_MASK = 0x00000002
    ,GPIORST_POS = 1
    ,GPIORST_0 = 0x00000000 // GPIO controller normal operation
    ,GPIORST_1 = 0x00000002 // GPIO controller reset
    // Timer0 Controller Reset (bits: 2)
    ,TMR0RST_MASK = 0x00000004
    ,TMR0RST_POS = 2
    ,TMR0RST_0 = 0x00000000 // Timer0 controller normal operation
    ,TMR0RST_1 = 0x00000004 // Timer0 controller reset
    // Timer1 Controller Reset (bits: 3)
    ,TMR1RST_MASK = 0x00000008
    ,TMR1RST_POS = 3
    ,TMR1RST_0 = 0x00000000 // Timer1 controller normal operation
    ,TMR1RST_1 = 0x00000008 // Timer1 controller reset
    // Timer2 Controller Reset (bits: 4)
    ,TMR2RST_MASK = 0x00000010
    ,TMR2RST_POS = 4
    ,TMR2RST_0 = 0x00000000 // Timer2 controller normal operation
    ,TMR2RST_1 = 0x00000010 // Timer2 controller reset
    // Timer3 Controller Reset (bits: 5)
    ,TMR3RST_MASK = 0x00000020
    ,TMR3RST_POS = 5
    ,TMR3RST_0 = 0x00000000 // Timer3 controller normal operation
    ,TMR3RST_1 = 0x00000020 // Timer3 controller reset
    // Analog Comparator 0/1 Controller Reset (bits: 7)
    ,ACMP01RST_MASK = 0x00000080
    ,ACMP01RST_POS = 7
    ,ACMP01RST_0 = 0x00000000 // Analog Comparator 0/1 controller normal operation
    ,ACMP01RST_1 = 0x00000080 // Analog Comparator 0/1 controller reset
    // I2C0 Controller Reset (bits: 8)
    ,I2C0RST_MASK = 0x00000100
    ,I2C0RST_POS = 8
    ,I2C0RST_0 = 0x00000000 // I2C0 controller normal operation
    ,I2C0RST_1 = 0x00000100 // I2C0 controller reset
    // I2C1 Controller Reset (bits: 9)
    ,I2C1RST_MASK = 0x00000200
    ,I2C1RST_POS = 9
    ,I2C1RST_0 = 0x00000000 // I2C1 controller normal operation
    ,I2C1RST_1 = 0x00000200 // I2C1 controller reset
    // I2C2 Controller Reset (bits: 10)
    ,I2C2RST_MASK = 0x00000400
    ,I2C2RST_POS = 10
    ,I2C2RST_0 = 0x00000000 // I2C2 controller normal operation
    ,I2C2RST_1 = 0x00000400 // I2C2 controller reset
    // Qual SPI0 Controller Reset (bits: 12)
    ,QSPI0RST_MASK = 0x00001000
    ,QSPI0RST_POS = 12
    ,QSPI0RST_0 = 0x00000000 // Qual SPI0 controller normal operation
    ,QSPI0RST_1 = 0x00001000 // Qual SPI0 controller reset
    // SPI0 Controller Reset (bits: 13)
    ,SPI0RST_MASK = 0x00002000
    ,SPI0RST_POS = 13
    ,SPI0RST_0 = 0x00000000 // SPI0 controller normal operation
    ,SPI0RST_1 = 0x00002000 // SPI0 controller reset
    // SPI1 Controller Reset (bits: 14)
    ,SPI1RST_MASK = 0x00004000
    ,SPI1RST_POS = 14
    ,SPI1RST_0 = 0x00000000 // SPI1 controller normal operation
    ,SPI1RST_1 = 0x00004000 // SPI1 controller reset
    // SPI2 Controller Reset (bits: 15)
    ,SPI2RST_MASK = 0x00008000
    ,SPI2RST_POS = 15
    ,SPI2RST_0 = 0x00000000 // SPI2 controller normal operation
    ,SPI2RST_1 = 0x00008000 // SPI2 controller reset
    // UART0 Controller Reset (bits: 16)
    ,UART0RST_MASK = 0x00010000
    ,UART0RST_POS = 16
    ,UART0RST_0 = 0x00000000 // UART0 controller normal operation
    ,UART0RST_1 = 0x00010000 // UART0 controller reset
    // UART1 Controller Reset (bits: 17)
    ,UART1RST_MASK = 0x00020000
    ,UART1RST_POS = 17
    ,UART1RST_0 = 0x00000000 // UART1 controller normal operation
    ,UART1RST_1 = 0x00020000 // UART1 controller reset
    // UART2 Controller Reset (bits: 18)
    ,UART2RST_MASK = 0x00040000
    ,UART2RST_POS = 18
    ,UART2RST_0 = 0x00000000 // UART2 controller normal operation
    ,UART2RST_1 = 0x00040000 // UART2 controller reset
    // UART3 Controller Reset (bits: 19)
    ,UART3RST_MASK = 0x00080000
    ,UART3RST_POS = 19
    ,UART3RST_0 = 0x00000000 // UART3 controller normal operation
    ,UART3RST_1 = 0x00080000 // UART3 controller reset
    // UART4 Controller Reset (bits: 20)
    ,UART4RST_MASK = 0x00100000
    ,UART4RST_POS = 20
    ,UART4RST_0 = 0x00000000 // UART4 controller normal operation
    ,UART4RST_1 = 0x00100000 // UART4 controller reset
    // UART5 Controller Reset (bits: 21)
    ,UART5RST_MASK = 0x00200000
    ,UART5RST_POS = 21
    ,UART5RST_0 = 0x00000000 // UART5 controller normal operation
    ,UART5RST_1 = 0x00200000 // UART5 controller reset
    // UART6 Controller Reset (bits: 22)
    ,UART6RST_MASK = 0x00400000
    ,UART6RST_POS = 22
    ,UART6RST_0 = 0x00000000 // UART6 controller normal operation
    ,UART6RST_1 = 0x00400000 // UART6 controller reset
    // UART7 Controller Reset (bits: 23)
    ,UART7RST_MASK = 0x00800000
    ,UART7RST_POS = 23
    ,UART7RST_0 = 0x00000000 // UART7 controller normal operation
    ,UART7RST_1 = 0x00800000 // UART7 controller reset
    // CAN0 Controller Reset (bits: 24)
    ,CAN0RST_MASK = 0x01000000
    ,CAN0RST_POS = 24
    ,CAN0RST_0 = 0x00000000 // CAN0 controller normal operation
    ,CAN0RST_1 = 0x01000000 // CAN0 controller reset
    // CAN1 Controller Reset (bits: 25)
    ,CAN1RST_MASK = 0x02000000
    ,CAN1RST_POS = 25
    ,CAN1RST_0 = 0x00000000 // CAN1 controller normal operation
    ,CAN1RST_1 = 0x02000000 // CAN1 controller reset
    // OTG Controller Reset (bits: 26)
    ,OTGRST_MASK = 0x04000000
    ,OTGRST_POS = 26
    ,OTGRST_0 = 0x00000000 // OTG controller normal operation
    ,OTGRST_1 = 0x04000000 // OTG controller reset
    // USBD Controller Reset (bits: 27)
    ,USBDRST_MASK = 0x08000000
    ,USBDRST_POS = 27
    ,USBDRST_0 = 0x00000000 // USBD controller normal operation
    ,USBDRST_1 = 0x08000000 // USBD controller reset
    // EADC Controller Reset (bits: 28)
    ,EADCRST_MASK = 0x10000000
    ,EADCRST_POS = 28
    ,EADCRST_0 = 0x00000000 // EADC controller normal operation
    ,EADCRST_1 = 0x10000000 // EADC controller reset
    // I2S0 Controller Reset (bits: 29)
    ,I2S0RST_MASK = 0x20000000
    ,I2S0RST_POS = 29
    ,I2S0RST_0 = 0x00000000 // I2S0 controller normal operation
    ,I2S0RST_1 = 0x20000000 // I2S0 controller reset
    // HSOTG Controller Reset (bits: 30)
    ,HSOTGRST_MASK = 0x40000000
    ,HSOTGRST_POS = 30
    ,HSOTGRST_0 = 0x00000000 // HSOTG controller normal operation
    ,HSOTGRST_1 = 0x40000000 // HSOTG controller reset
    // TRNG Controller Reset (bits: 31)
    ,TRNGRST_MASK = 0x80000000
    ,TRNGRST_POS = 31
    ,TRNGRST_0 = 0x00000000 // TRNG controller normal operation
    ,TRNGRST_1 = 0x80000000 // TRNG controller reset
    ,IPRST1_MASK = 0xFFFFF7BE
    ;
  };
  // Peripheral Reset Control Register 2
  struct IPRST2 : reg<ip_ver, base + 0x10>
  {
    static constexpr typename IPRST2::type
    // SC0 Controller Reset (bits: 0)
     SC0RST_MASK = 0x00000001
    ,SC0RST_POS = 0
    ,SC0RST_0 = 0x00000000 // SC0 controller normal operation
    ,SC0RST_1 = 0x00000001 // SC0 controller reset
    // SC1 Controller Reset (bits: 1)
    ,SC1RST_MASK = 0x00000002
    ,SC1RST_POS = 1
    ,SC1RST_0 = 0x00000000 // SC1 controller normal operation
    ,SC1RST_1 = 0x00000002 // SC1 controller reset
    // SC2 Controller Reset (bits: 2)
    ,SC2RST_MASK = 0x00000004
    ,SC2RST_POS = 2
    ,SC2RST_0 = 0x00000000 // SC2 controller normal operation
    ,SC2RST_1 = 0x00000004 // SC2 controller reset
    // QSPI1 Controller Reset (bits: 4)
    ,QSPI1RST_MASK = 0x00000010
    ,QSPI1RST_POS = 4
    ,QSPI1RST_0 = 0x00000000 // QSPI1 controller normal operation
    ,QSPI1RST_1 = 0x00000010 // QSPI1 controller reset
    // SPI3 Controller Reset (bits: 6)
    ,SPI3RST_MASK = 0x00000040
    ,SPI3RST_POS = 6
    ,SPI3RST_0 = 0x00000000 // SPI3 controller normal operation
    ,SPI3RST_1 = 0x00000040 // SPI3 controller reset
    // USCI0 Controller Reset (bits: 8)
    ,USCI0RST_MASK = 0x00000100
    ,USCI0RST_POS = 8
    ,USCI0RST_0 = 0x00000000 // USCI0 controller normal operation
    ,USCI0RST_1 = 0x00000100 // USCI0 controller reset
    // USCI1 Controller Reset (bits: 9)
    ,USCI1RST_MASK = 0x00000200
    ,USCI1RST_POS = 9
    ,USCI1RST_0 = 0x00000000 // USCI1 controller normal operation
    ,USCI1RST_1 = 0x00000200 // USCI1 controller reset
    // DAC Controller Reset (bits: 12)
    ,DACRST_MASK = 0x00001000
    ,DACRST_POS = 12
    ,DACRST_0 = 0x00000000 // DAC controller normal operation
    ,DACRST_1 = 0x00001000 // DAC controller reset
    // EPWM0 Controller Reset (bits: 16)
    ,EPWM0RST_MASK = 0x00010000
    ,EPWM0RST_POS = 16
    ,EPWM0RST_0 = 0x00000000 // EPWM0 controller normal operation
    ,EPWM0RST_1 = 0x00010000 // EPWM0 controller reset
    // EPWM1 Controller Reset (bits: 17)
    ,EPWM1RST_MASK = 0x00020000
    ,EPWM1RST_POS = 17
    ,EPWM1RST_0 = 0x00000000 // EPWM1 controller normal operation
    ,EPWM1RST_1 = 0x00020000 // EPWM1 controller reset
    // BPWM0 Controller Reset (bits: 18)
    ,BPWM0RST_MASK = 0x00040000
    ,BPWM0RST_POS = 18
    ,BPWM0RST_0 = 0x00000000 // BPWM0 controller normal operation
    ,BPWM0RST_1 = 0x00040000 // BPWM0 controller reset
    // BPWM1 Controller Reset (bits: 19)
    ,BPWM1RST_MASK = 0x00080000
    ,BPWM1RST_POS = 19
    ,BPWM1RST_0 = 0x00000000 // BPWM1 controller normal operation
    ,BPWM1RST_1 = 0x00080000 // BPWM1 controller reset
    // QEI0 Controller Reset (bits: 22)
    ,QEI0RST_MASK = 0x00400000
    ,QEI0RST_POS = 22
    ,QEI0RST_0 = 0x00000000 // QEI0 controller normal operation
    ,QEI0RST_1 = 0x00400000 // QEI0 controller reset
    // QEI1 Controller Reset (bits: 23)
    ,QEI1RST_MASK = 0x00800000
    ,QEI1RST_POS = 23
    ,QEI1RST_0 = 0x00000000 // QEI1 controller normal operation
    ,QEI1RST_1 = 0x00800000 // QEI1 controller reset
    // ECAP0 Controller Reset (bits: 26)
    ,ECAP0RST_MASK = 0x04000000
    ,ECAP0RST_POS = 26
    ,ECAP0RST_0 = 0x00000000 // ECAP0 controller normal operation
    ,ECAP0RST_1 = 0x04000000 // ECAP0 controller reset
    // ECAP1 Controller Reset (bits: 27)
    ,ECAP1RST_MASK = 0x08000000
    ,ECAP1RST_POS = 27
    ,ECAP1RST_0 = 0x00000000 // ECAP1 controller normal operation
    ,ECAP1RST_1 = 0x08000000 // ECAP1 controller reset
    // CAN2 Controller Reset (bits: 28)
    ,CAN2RST_MASK = 0x10000000
    ,CAN2RST_POS = 28
    ,CAN2RST_0 = 0x00000000 // CAN2 controller normal operation
    ,CAN2RST_1 = 0x10000000 // CAN2 controller reset
    // OP Amplifier (OPA) Controller Reset (bits: 30)
    ,OPARST_MASK = 0x40000000
    ,OPARST_POS = 30
    ,OPARST_0 = 0x00000000 // OPA controller normal operation
    ,OPARST_1 = 0x40000000 // OPA controller reset
    // EADC1 Controller Reset (bits: 31)
    ,EADC1RST_MASK = 0x80000000
    ,EADC1RST_POS = 31
    ,EADC1RST_0 = 0x00000000 // EADC1 controller normal operation
    ,EADC1RST_1 = 0x80000000 // EADC1 controller reset
    ,IPRST2_MASK = 0xDCCF1357
    ;
  };
  // Brown-out Detector Control Register
  struct BODCTL : reg<ip_ver, base + 0x18, 0x00000380>
  {
    static constexpr typename BODCTL::type
    // Brown-out Detector Enable Bit (Write Protect) The default value is set by Flash controller user configuration register CBODEN (CONFIG0 [19]). Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     BODEN_MASK = 0x00000001
    ,BODEN_POS = 0
    ,BODEN_0 = 0x00000000 // Brown-out Detector function Disabled
    ,BODEN_1 = 0x00000001 // Brown-out Detector function Enabled
    // Brown-out Reset Enable Bit (Write Protect) The default value is set by Flash controller user configuration register CBORST(CONFIG0[20]) bit. Note 1: While the Brown-out Detector function is enabled (BODEN high) and BOD reset function is enabled (BODRSTEN high), BOD will assert a signal to reset chip when the detected voltage is lower than the threshold (BODOUT high). While the BOD function is enabled (BODEN high) and BOD interrupt function is enabled (BODRSTEN low), BOD will assert an interrupt if BODOUT is high. BOD interrupt will keep till to the BODEN set to 0. BOD interrupt can be blocked by disabling the NVIC BOD interrupt or disabling BOD function (set BODEN low). Note 2: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 3)
    ,BODRSTEN_MASK = 0x00000008
    ,BODRSTEN_POS = 3
    ,BODRSTEN_0 = 0x00000000 // Brown-out 'INTERRUPT' function Enabled
    ,BODRSTEN_1 = 0x00000008 // Brown-out 'RESET' function Enabled
    // Brown-out Detector Interrupt Flag Note: Write 1 to clear this bit to 0. (bits: 4)
    ,BODIF_MASK = 0x00000010
    ,BODIF_POS = 4
    ,BODIF_0 = 0x00000000 // Brown-out Detector does not detect any voltage draft at VDD down through or up through the voltage of BODVL setting
    ,BODIF_1 = 0x00000010 // When Brown-out Detector detects the VDD is dropped down through the voltage of BODVL setting or the VDD is raised up through the voltage of BODVL setting, this bit is set to 1 and the brown-out interrupt is requested if brown-out interrupt is enabled
    // Brown-out Detector Low Power Mode (Write Protect) Note 1: The BOD consumes about 100uA in normal mode, the low power mode can reduce the current to about 1/10 but slow the BOD response. Note 2: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 5)
    ,BODLPM_MASK = 0x00000020
    ,BODLPM_POS = 5
    ,BODLPM_0 = 0x00000000 // BOD operate in normal mode (default)
    ,BODLPM_1 = 0x00000020 // BOD Low Power mode Enabled
    // Brown-out Detector Output Status It means the detected voltage is lower than BODVL setting. If the BODEN is 0, BOD function disabled, this bit always responds 0000. (bits: 6)
    ,BODOUT_MASK = 0x00000040
    ,BODOUT_POS = 6
    ,BODOUT_0 = 0x00000000 // Brown-out Detector output status is 0
    ,BODOUT_1 = 0x00000040 // Brown-out Detector output status is 1
    // Low Voltage Reset Enable Bit (Write Protect) The LVR function resets the chip when the input power voltage is lower than LVR circuit setting. LVR function is enabled by default. Note 1: After enabling the bit, the LVR function will be active with 100us delay for LVR output stable (default). Note 2: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 7)
    ,LVREN_MASK = 0x00000080
    ,LVREN_POS = 7
    ,LVREN_0 = 0x00000000 // Low Voltage Reset function Disabled
    ,LVREN_1 = 0x00000080 // Low Voltage Reset function Enabled
    // Brown-out Detector Output De-glitch Time Select (Write Protect) Note: These bits are write protected. Refer to the SYS_REGLCTL register. (bits: 10-8)
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
    // LVR Output De-glitch Time Select (Write Protect) Note: These bits are write protected. Refer to the SYS_REGLCTL register. (bits: 14-12)
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
    // Brown-out Detector Threshold Voltage Selection (Write Protect) The default value is set by Flash controller user configuration register CBOV (CONFIG0 [23:21]). Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 18-16)
    ,BODVL_MASK = 0x00070000
    ,BODVL_POS = 16
    ,BODVL_0 = 0x00000000 // Brown-Out Detector threshold voltage is 1.6V
    ,BODVL_1 = 0x00010000 // Brown-Out Detector threshold voltage is 1.8V
    ,BODVL_2 = 0x00020000 // Brown-Out Detector threshold voltage is 2.0V
    ,BODVL_3 = 0x00030000 // Brown-Out Detector threshold voltage is 2.2V
    ,BODVL_4 = 0x00040000 // Brown-Out Detector threshold voltage is 2.4V
    ,BODVL_5 = 0x00050000 // Brown-Out Detector threshold voltage is 2.6V
    ,BODVL_6 = 0x00060000 // Brown-Out Detector threshold voltage is 2.8V
    ,BODVL_7 = 0x00070000 // Brown-Out Detector threshold voltage is 3.0V
    ,BODCTL_MASK = 0x000777F9
    ;
  };
  // Internal Voltage Source Control Register
  struct IVSCTL : reg<ip_ver, base + 0x1C>
  {
    static constexpr typename IVSCTL::type
    // Temperature Sensor Enable Bit This bit is used to enable/disable temperature sensor function. (bits: 0)
     VTEMPEN_MASK = 0x00000001
    ,VTEMPEN_POS = 0
    ,VTEMPEN_0 = 0x00000000 // Temperature sensor function Disabled (default)
    ,VTEMPEN_1 = 0x00000001 // Temperature sensor function Enabled
    // VBAT Unity Gain Buffer Enable Bit This bit is used to enable/disable VBAT unity gain buffer function. Note: After this bit is set to 1, the value of VBAT unity gain buffer output voltage can be obtained from ADC conversion result (bits: 1)
    ,VBATUGEN_MASK = 0x00000002
    ,VBATUGEN_POS = 1
    ,VBATUGEN_0 = 0x00000000 // VBAT unity gain buffer function Disabled (default)
    ,VBATUGEN_1 = 0x00000002 // VBAT unity gain buffer function Enabled
    ,IVSCTL_MASK = 0x00000003
    ;
  };
  // VREF Control Register
  struct VREFCTL : reg<ip_ver, base + 0x28, 0x00000200>
  {
    static constexpr typename VREFCTL::type
    // VREF Control Bits (Write Protect) Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 4-0)
     VREFCTLVAL_MASK = 0x0000001F
    ,VREFCTLVAL_POS = 0
    ,VREFCTLVAL_0 = 0x00000000 // VREF is from external pin
    ,VREFCTLVAL_3 = 0x00000003 // VREF is internal 1.6V
    ,VREFCTLVAL_7 = 0x00000007 // VREF is internal 2.0V
    ,VREFCTLVAL_11 = 0x0000000B // VREF is internal 2.5V
    ,VREFCTLVAL_15 = 0x0000000F // VREF is internal 3.0V
    // Pre-load Timing Selection (Write Protect) (bits: 7-6)
    ,PRELOAD_SEL_MASK = 0x000000C0
    ,PRELOAD_SEL_POS = 6
    ,PRELOAD_SEL_0 = 0x00000000 // pre-load time is 60us for 0.1uF Capacitor
    ,PRELOAD_SEL_1 = 0x00000040 // pre-load time is 310us for 1uF Capacitor
    ,PRELOAD_SEL_2 = 0x00000080 // pre-load time is 1270us for 4.7uF Capacitor
    ,PRELOAD_SEL_3 = 0x000000C0 // pre-load time is 2650us for 10uF Capacitor
    // Chip Internal Voltage Bandgap Force Enable Bit(Write Only) (bits: 24)
    ,VBGFEN_MASK = 0x01000000
    ,VBGFEN_POS = 24
    ,VBGFEN_0 = 0x00000000 // Chip internal voltage bandgap controlled by ADC/ACMP if source selected
    ,VBGFEN_1 = 0x01000000 // Chip internal voltage bandgap force enable
    // Chip Internal Voltage Bandgap Current Selection Bits (Write Only) Note: When ADC conversion source select bandgap voltage, suggest set VBGISEL as 10. (bits: 26-25)
    ,VBGISEL_MASK = 0x06000000
    ,VBGISEL_POS = 25
    ,VBGISEL_0 = 0x00000000 // Bandgap voltage buffer current is 4.2uA
    ,VBGISEL_1 = 0x02000000 // Bandgap voltage buffer current is 7.3uA
    ,VBGISEL_2 = 0x04000000 // Bandgap voltage buffer current is 10.4uA
    ,VBGISEL_3 = 0x06000000 // Bandgap voltage buffer current is 13.5uA
    ,VREFCTL_MASK = 0x070000DF
    ;
  };
  // USB PHY Control Register
  struct USBPHY : reg<ip_ver, base + 0x2C, 0x00030007>
  {
    static constexpr typename USBPHY::type
    // USB Role Option (Write Protect) These two bits are used to select the role of USB. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 1-0)
     USBROLE_MASK = 0x00000003
    ,USBROLE_POS = 0
    ,USBROLE_0 = 0x00000000 // Standard USB Device mode
    ,USBROLE_1 = 0x00000001 // Standard USB Host mode
    ,USBROLE_2 = 0x00000002 // ID dependent mode
    ,USBROLE_3 = 0x00000003 // On-The-Go device mode
    // Note: This bit must always be kept 1. If set to 0, the result is unpredictable (bits: 2)
    ,SBO_MASK = 0x00000004
    ,SBO_POS = 2
    ,SBO = 0x00000004
    // USB PHY Enable This bit is used to enable/disable USB PHY. (bits: 8)
    ,USBEN_MASK = 0x00000100
    ,USBEN_POS = 8
    ,USBEN_0 = 0x00000000 // USB PHY Disabled
    ,USBEN_1 = 0x00000100 // USB PHY Enabled
    // HSUSB Role Option (Write Protect) These two bits are used to select the role of HSUSB Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 17-16)
    ,HSUSBROLE_MASK = 0x00030000
    ,HSUSBROLE_POS = 16
    ,HSUSBROLE_0 = 0x00000000 // Standard HSUSB Device mode
    ,HSUSBROLE_1 = 0x00010000 // Standard HSUSB Host mode
    ,HSUSBROLE_2 = 0x00020000 // ID dependent mode
    ,HSUSBROLE_3 = 0x00030000 // On-The-Go device mode
    // HSUSB PHY Enable This bit is used to enable/disable HSUSB PHY. (bits: 24)
    ,HSUSBEN_MASK = 0x01000000
    ,HSUSBEN_POS = 24
    ,HSUSBEN_0 = 0x00000000 // HSUSB PHY Disabled
    ,HSUSBEN_1 = 0x01000000 // HSUSB PHY Enabled
    // HSUSB PHY Active Control This bit is used to control HSUSB PHY at reset state or active state Note: After set HSUSBEN (SYS_USBPHY[24]) to enable HSUSB PHY, user should keep HSUSB PHY at reset mode at lease 10uS before changing to active mode (bits: 25)
    ,HSUSBACT_MASK = 0x02000000
    ,HSUSBACT_POS = 25
    ,HSUSBACT_0 = 0x00000000 // HSUSB PHY at reset state
    ,HSUSBACT_1 = 0x02000000 // HSUSB PHY at active state
    ,USBPHY_MASK = 0x03030107
    ;
  };
  // GPIOA Low Byte Multiple Function Control Register
  struct GPA_MFPL : reg<ip_ver, base + 0x30>
  {
    static constexpr typename GPA_MFPL::type
    // PA.0 Multi-function Pin Selection (bits: 3-0)
     PA0MFP_MASK = 0x0000000F
    ,PA0MFP_POS = 0
    // PA.1 Multi-function Pin Selection (bits: 7-4)
    ,PA1MFP_MASK = 0x000000F0
    ,PA1MFP_POS = 4
    // PA.2 Multi-function Pin Selection (bits: 11-8)
    ,PA2MFP_MASK = 0x00000F00
    ,PA2MFP_POS = 8
    // PA.3 Multi-function Pin Selection (bits: 15-12)
    ,PA3MFP_MASK = 0x0000F000
    ,PA3MFP_POS = 12
    // PA.4 Multi-function Pin Selection (bits: 19-16)
    ,PA4MFP_MASK = 0x000F0000
    ,PA4MFP_POS = 16
    // PA.5 Multi-function Pin Selection (bits: 23-20)
    ,PA5MFP_MASK = 0x00F00000
    ,PA5MFP_POS = 20
    // PA.6 Multi-function Pin Selection (bits: 27-24)
    ,PA6MFP_MASK = 0x0F000000
    ,PA6MFP_POS = 24
    // PA.7 Multi-function Pin Selection (bits: 31-28)
    ,PA7MFP_MASK = 0xF0000000
    ,PA7MFP_POS = 28
    ,GPA_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOA High Byte Multiple Function Control Register
  struct GPA_MFPH : reg<ip_ver, base + 0x34>
  {
    static constexpr typename GPA_MFPH::type
    // PA.8 Multi-function Pin Selection (bits: 3-0)
     PA8MFP_MASK = 0x0000000F
    ,PA8MFP_POS = 0
    // PA.9 Multi-function Pin Selection (bits: 7-4)
    ,PA9MFP_MASK = 0x000000F0
    ,PA9MFP_POS = 4
    // PA.10 Multi-function Pin Selection (bits: 11-8)
    ,PA10MFP_MASK = 0x00000F00
    ,PA10MFP_POS = 8
    // PA.11 Multi-function Pin Selection (bits: 15-12)
    ,PA11MFP_MASK = 0x0000F000
    ,PA11MFP_POS = 12
    // PA.12 Multi-function Pin Selection (bits: 19-16)
    ,PA12MFP_MASK = 0x000F0000
    ,PA12MFP_POS = 16
    // PA.13 Multi-function Pin Selection (bits: 23-20)
    ,PA13MFP_MASK = 0x00F00000
    ,PA13MFP_POS = 20
    // PA.14 Multi-function Pin Selection (bits: 27-24)
    ,PA14MFP_MASK = 0x0F000000
    ,PA14MFP_POS = 24
    // PA.15 Multi-function Pin Selection (bits: 31-28)
    ,PA15MFP_MASK = 0xF0000000
    ,PA15MFP_POS = 28
    ,GPA_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOB Low Byte Multiple Function Control Register
  struct GPB_MFPL : reg<ip_ver, base + 0x38>
  {
    static constexpr typename GPB_MFPL::type
    // PB.0 Multi-function Pin Selection (bits: 3-0)
     PB0MFP_MASK = 0x0000000F
    ,PB0MFP_POS = 0
    // PB.1 Multi-function Pin Selection (bits: 7-4)
    ,PB1MFP_MASK = 0x000000F0
    ,PB1MFP_POS = 4
    // PB.2 Multi-function Pin Selection (bits: 11-8)
    ,PB2MFP_MASK = 0x00000F00
    ,PB2MFP_POS = 8
    // PB.3 Multi-function Pin Selection (bits: 15-12)
    ,PB3MFP_MASK = 0x0000F000
    ,PB3MFP_POS = 12
    // PB.4 Multi-function Pin Selection (bits: 19-16)
    ,PB4MFP_MASK = 0x000F0000
    ,PB4MFP_POS = 16
    // PB.5 Multi-function Pin Selection (bits: 23-20)
    ,PB5MFP_MASK = 0x00F00000
    ,PB5MFP_POS = 20
    // PB.6 Multi-function Pin Selection (bits: 27-24)
    ,PB6MFP_MASK = 0x0F000000
    ,PB6MFP_POS = 24
    // PB.7 Multi-function Pin Selection (bits: 31-28)
    ,PB7MFP_MASK = 0xF0000000
    ,PB7MFP_POS = 28
    ,GPB_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOB High Byte Multiple Function Control Register
  struct GPB_MFPH : reg<ip_ver, base + 0x3C>
  {
    static constexpr typename GPB_MFPH::type
    // PB.8 Multi-function Pin Selection (bits: 3-0)
     PB8MFP_MASK = 0x0000000F
    ,PB8MFP_POS = 0
    // PB.9 Multi-function Pin Selection (bits: 7-4)
    ,PB9MFP_MASK = 0x000000F0
    ,PB9MFP_POS = 4
    // PB.10 Multi-function Pin Selection (bits: 11-8)
    ,PB10MFP_MASK = 0x00000F00
    ,PB10MFP_POS = 8
    // PB.11 Multi-function Pin Selection (bits: 15-12)
    ,PB11MFP_MASK = 0x0000F000
    ,PB11MFP_POS = 12
    // PB.12 Multi-function Pin Selection (bits: 19-16)
    ,PB12MFP_MASK = 0x000F0000
    ,PB12MFP_POS = 16
    // PB.13 Multi-function Pin Selection (bits: 23-20)
    ,PB13MFP_MASK = 0x00F00000
    ,PB13MFP_POS = 20
    // PB.14 Multi-function Pin Selection (bits: 27-24)
    ,PB14MFP_MASK = 0x0F000000
    ,PB14MFP_POS = 24
    // PB.15 Multi-function Pin Selection (bits: 31-28)
    ,PB15MFP_MASK = 0xF0000000
    ,PB15MFP_POS = 28
    ,GPB_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOC Low Byte Multiple Function Control Register
  struct GPC_MFPL : reg<ip_ver, base + 0x40>
  {
    static constexpr typename GPC_MFPL::type
    // PC.0 Multi-function Pin Selection (bits: 3-0)
     PC0MFP_MASK = 0x0000000F
    ,PC0MFP_POS = 0
    // PC.1 Multi-function Pin Selection (bits: 7-4)
    ,PC1MFP_MASK = 0x000000F0
    ,PC1MFP_POS = 4
    // PC.2 Multi-function Pin Selection (bits: 11-8)
    ,PC2MFP_MASK = 0x00000F00
    ,PC2MFP_POS = 8
    // PC.3 Multi-function Pin Selection (bits: 15-12)
    ,PC3MFP_MASK = 0x0000F000
    ,PC3MFP_POS = 12
    // PC.4 Multi-function Pin Selection (bits: 19-16)
    ,PC4MFP_MASK = 0x000F0000
    ,PC4MFP_POS = 16
    // PC.5 Multi-function Pin Selection (bits: 23-20)
    ,PC5MFP_MASK = 0x00F00000
    ,PC5MFP_POS = 20
    // PC.6 Multi-function Pin Selection (bits: 27-24)
    ,PC6MFP_MASK = 0x0F000000
    ,PC6MFP_POS = 24
    // PC.7 Multi-function Pin Selection (bits: 31-28)
    ,PC7MFP_MASK = 0xF0000000
    ,PC7MFP_POS = 28
    ,GPC_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOC High Byte Multiple Function Control Register
  struct GPC_MFPH : reg<ip_ver, base + 0x44>
  {
    static constexpr typename GPC_MFPH::type
    // PC.8 Multi-function Pin Selection (bits: 3-0)
     PC8MFP_MASK = 0x0000000F
    ,PC8MFP_POS = 0
    // PC.9 Multi-function Pin Selection (bits: 7-4)
    ,PC9MFP_MASK = 0x000000F0
    ,PC9MFP_POS = 4
    // PC.10 Multi-function Pin Selection (bits: 11-8)
    ,PC10MFP_MASK = 0x00000F00
    ,PC10MFP_POS = 8
    // PC.11 Multi-function Pin Selection (bits: 15-12)
    ,PC11MFP_MASK = 0x0000F000
    ,PC11MFP_POS = 12
    // PC.12 Multi-function Pin Selection (bits: 19-16)
    ,PC12MFP_MASK = 0x000F0000
    ,PC12MFP_POS = 16
    // PC.13 Multi-function Pin Selection (bits: 23-20)
    ,PC13MFP_MASK = 0x00F00000
    ,PC13MFP_POS = 20
    // PC.14 Multi-function Pin Selection (bits: 27-24)
    ,PC14MFP_MASK = 0x0F000000
    ,PC14MFP_POS = 24
    // PC.15 Multi-function Pin Selection (bits: 31-28)
    ,PC15MFP_MASK = 0xF0000000
    ,PC15MFP_POS = 28
    ,GPC_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOD Low Byte Multiple Function Control Register
  struct GPD_MFPL : reg<ip_ver, base + 0x48>
  {
    static constexpr typename GPD_MFPL::type
    // PD.0 Multi-function Pin Selection (bits: 3-0)
     PD0MFP_MASK = 0x0000000F
    ,PD0MFP_POS = 0
    // PD.1 Multi-function Pin Selection (bits: 7-4)
    ,PD1MFP_MASK = 0x000000F0
    ,PD1MFP_POS = 4
    // PD.2 Multi-function Pin Selection (bits: 11-8)
    ,PD2MFP_MASK = 0x00000F00
    ,PD2MFP_POS = 8
    // PD.3 Multi-function Pin Selection (bits: 15-12)
    ,PD3MFP_MASK = 0x0000F000
    ,PD3MFP_POS = 12
    // PD.4 Multi-function Pin Selection (bits: 19-16)
    ,PD4MFP_MASK = 0x000F0000
    ,PD4MFP_POS = 16
    // PD.5 Multi-function Pin Selection (bits: 23-20)
    ,PD5MFP_MASK = 0x00F00000
    ,PD5MFP_POS = 20
    // PD.6 Multi-function Pin Selection (bits: 27-24)
    ,PD6MFP_MASK = 0x0F000000
    ,PD6MFP_POS = 24
    // PD.7 Multi-function Pin Selection (bits: 31-28)
    ,PD7MFP_MASK = 0xF0000000
    ,PD7MFP_POS = 28
    ,GPD_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOD High Byte Multiple Function Control Register
  struct GPD_MFPH : reg<ip_ver, base + 0x4C>
  {
    static constexpr typename GPD_MFPH::type
    // PD.8 Multi-function Pin Selection (bits: 3-0)
     PD8MFP_MASK = 0x0000000F
    ,PD8MFP_POS = 0
    // PD.9 Multi-function Pin Selection (bits: 7-4)
    ,PD9MFP_MASK = 0x000000F0
    ,PD9MFP_POS = 4
    // PD.10 Multi-function Pin Selection (bits: 11-8)
    ,PD10MFP_MASK = 0x00000F00
    ,PD10MFP_POS = 8
    // PD.11 Multi-function Pin Selection (bits: 15-12)
    ,PD11MFP_MASK = 0x0000F000
    ,PD11MFP_POS = 12
    // PD.12 Multi-function Pin Selection (bits: 19-16)
    ,PD12MFP_MASK = 0x000F0000
    ,PD12MFP_POS = 16
    // PD.13 Multi-function Pin Selection (bits: 23-20)
    ,PD13MFP_MASK = 0x00F00000
    ,PD13MFP_POS = 20
    // PD.14 Multi-function Pin Selection (bits: 27-24)
    ,PD14MFP_MASK = 0x0F000000
    ,PD14MFP_POS = 24
    // PD.15 Multi-function Pin Selection (bits: 31-28)
    ,PD15MFP_MASK = 0xF0000000
    ,PD15MFP_POS = 28
    ,GPD_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOE Low Byte Multiple Function Control Register
  struct GPE_MFPL : reg<ip_ver, base + 0x50>
  {
    static constexpr typename GPE_MFPL::type
    // PE.0 Multi-function Pin Selection (bits: 3-0)
     PE0MFP_MASK = 0x0000000F
    ,PE0MFP_POS = 0
    // PE.1 Multi-function Pin Selection (bits: 7-4)
    ,PE1MFP_MASK = 0x000000F0
    ,PE1MFP_POS = 4
    // PE.2 Multi-function Pin Selection (bits: 11-8)
    ,PE2MFP_MASK = 0x00000F00
    ,PE2MFP_POS = 8
    // PE.3 Multi-function Pin Selection (bits: 15-12)
    ,PE3MFP_MASK = 0x0000F000
    ,PE3MFP_POS = 12
    // PE.4 Multi-function Pin Selection (bits: 19-16)
    ,PE4MFP_MASK = 0x000F0000
    ,PE4MFP_POS = 16
    // PE.5 Multi-function Pin Selection (bits: 23-20)
    ,PE5MFP_MASK = 0x00F00000
    ,PE5MFP_POS = 20
    // PE.6 Multi-function Pin Selection (bits: 27-24)
    ,PE6MFP_MASK = 0x0F000000
    ,PE6MFP_POS = 24
    // PE.7 Multi-function Pin Selection (bits: 31-28)
    ,PE7MFP_MASK = 0xF0000000
    ,PE7MFP_POS = 28
    ,GPE_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOE High Byte Multiple Function Control Register
  struct GPE_MFPH : reg<ip_ver, base + 0x54>
  {
    static constexpr typename GPE_MFPH::type
    // PE.8 Multi-function Pin Selection (bits: 3-0)
     PE8MFP_MASK = 0x0000000F
    ,PE8MFP_POS = 0
    // PE.9 Multi-function Pin Selection (bits: 7-4)
    ,PE9MFP_MASK = 0x000000F0
    ,PE9MFP_POS = 4
    // PE.10 Multi-function Pin Selection (bits: 11-8)
    ,PE10MFP_MASK = 0x00000F00
    ,PE10MFP_POS = 8
    // PE.11 Multi-function Pin Selection (bits: 15-12)
    ,PE11MFP_MASK = 0x0000F000
    ,PE11MFP_POS = 12
    // PE.12 Multi-function Pin Selection (bits: 19-16)
    ,PE12MFP_MASK = 0x000F0000
    ,PE12MFP_POS = 16
    // PE.13 Multi-function Pin Selection (bits: 23-20)
    ,PE13MFP_MASK = 0x00F00000
    ,PE13MFP_POS = 20
    // PE.14 Multi-function Pin Selection (bits: 27-24)
    ,PE14MFP_MASK = 0x0F000000
    ,PE14MFP_POS = 24
    // PE.15 Multi-function Pin Selection (bits: 31-28)
    ,PE15MFP_MASK = 0xF0000000
    ,PE15MFP_POS = 28
    ,GPE_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOF Low Byte Multiple Function Control Register
  struct GPF_MFPL : reg<ip_ver, base + 0x58, 0x000000EE>
  {
    static constexpr typename GPF_MFPL::type
    // PF.0 Multi-function Pin Selection (bits: 3-0)
     PF0MFP_MASK = 0x0000000F
    ,PF0MFP_POS = 0
    // PF.1 Multi-function Pin Selection (bits: 7-4)
    ,PF1MFP_MASK = 0x000000F0
    ,PF1MFP_POS = 4
    // PF.2 Multi-function Pin Selection (bits: 11-8)
    ,PF2MFP_MASK = 0x00000F00
    ,PF2MFP_POS = 8
    // PF.3 Multi-function Pin Selection (bits: 15-12)
    ,PF3MFP_MASK = 0x0000F000
    ,PF3MFP_POS = 12
    // PF.4 Multi-function Pin Selection (bits: 19-16)
    ,PF4MFP_MASK = 0x000F0000
    ,PF4MFP_POS = 16
    // PF.5 Multi-function Pin Selection (bits: 23-20)
    ,PF5MFP_MASK = 0x00F00000
    ,PF5MFP_POS = 20
    // PF.6 Multi-function Pin Selection (bits: 27-24)
    ,PF6MFP_MASK = 0x0F000000
    ,PF6MFP_POS = 24
    // PF.7 Multi-function Pin Selection (bits: 31-28)
    ,PF7MFP_MASK = 0xF0000000
    ,PF7MFP_POS = 28
    ,GPF_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOF High Byte Multiple Function Control Register
  struct GPF_MFPH : reg<ip_ver, base + 0x5C>
  {
    static constexpr typename GPF_MFPH::type
    // PF.8 Multi-function Pin Selection (bits: 3-0)
     PF8MFP_MASK = 0x0000000F
    ,PF8MFP_POS = 0
    // PF.9 Multi-function Pin Selection (bits: 7-4)
    ,PF9MFP_MASK = 0x000000F0
    ,PF9MFP_POS = 4
    // PF.10 Multi-function Pin Selection (bits: 11-8)
    ,PF10MFP_MASK = 0x00000F00
    ,PF10MFP_POS = 8
    // PF.11 Multi-function Pin Selection (bits: 15-12)
    ,PF11MFP_MASK = 0x0000F000
    ,PF11MFP_POS = 12
    // PF.12 Multi-function Pin Selection (bits: 19-16)
    ,PF12MFP_MASK = 0x000F0000
    ,PF12MFP_POS = 16
    // PF.13 Multi-function Pin Selection (bits: 23-20)
    ,PF13MFP_MASK = 0x00F00000
    ,PF13MFP_POS = 20
    // PF.14 Multi-function Pin Selection (bits: 27-24)
    ,PF14MFP_MASK = 0x0F000000
    ,PF14MFP_POS = 24
    // PF.15 Multi-function Pin Selection (bits: 31-28)
    ,PF15MFP_MASK = 0xF0000000
    ,PF15MFP_POS = 28
    ,GPF_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOG Low Byte Multiple Function Control Register
  struct GPG_MFPL : reg<ip_ver, base + 0x60>
  {
    static constexpr typename GPG_MFPL::type
    // PG.0 Multi-function Pin Selection (bits: 3-0)
     PG0MFP_MASK = 0x0000000F
    ,PG0MFP_POS = 0
    // PG.1 Multi-function Pin Selection (bits: 7-4)
    ,PG1MFP_MASK = 0x000000F0
    ,PG1MFP_POS = 4
    // PG.2 Multi-function Pin Selection (bits: 11-8)
    ,PG2MFP_MASK = 0x00000F00
    ,PG2MFP_POS = 8
    // PG.3 Multi-function Pin Selection (bits: 15-12)
    ,PG3MFP_MASK = 0x0000F000
    ,PG3MFP_POS = 12
    // PG.4 Multi-function Pin Selection (bits: 19-16)
    ,PG4MFP_MASK = 0x000F0000
    ,PG4MFP_POS = 16
    // PG.5 Multi-function Pin Selection (bits: 23-20)
    ,PG5MFP_MASK = 0x00F00000
    ,PG5MFP_POS = 20
    // PG.6 Multi-function Pin Selection (bits: 27-24)
    ,PG6MFP_MASK = 0x0F000000
    ,PG6MFP_POS = 24
    // PG.7 Multi-function Pin Selection (bits: 31-28)
    ,PG7MFP_MASK = 0xF0000000
    ,PG7MFP_POS = 28
    ,GPG_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOG High Byte Multiple Function Control Register
  struct GPG_MFPH : reg<ip_ver, base + 0x64>
  {
    static constexpr typename GPG_MFPH::type
    // PG.8 Multi-function Pin Selection (bits: 3-0)
     PG8MFP_MASK = 0x0000000F
    ,PG8MFP_POS = 0
    // PG.9 Multi-function Pin Selection (bits: 7-4)
    ,PG9MFP_MASK = 0x000000F0
    ,PG9MFP_POS = 4
    // PG.10 Multi-function Pin Selection (bits: 11-8)
    ,PG10MFP_MASK = 0x00000F00
    ,PG10MFP_POS = 8
    // PG.11 Multi-function Pin Selection (bits: 15-12)
    ,PG11MFP_MASK = 0x0000F000
    ,PG11MFP_POS = 12
    // PG.12 Multi-function Pin Selection (bits: 19-16)
    ,PG12MFP_MASK = 0x000F0000
    ,PG12MFP_POS = 16
    // PG.13 Multi-function Pin Selection (bits: 23-20)
    ,PG13MFP_MASK = 0x00F00000
    ,PG13MFP_POS = 20
    // PG.14 Multi-function Pin Selection (bits: 27-24)
    ,PG14MFP_MASK = 0x0F000000
    ,PG14MFP_POS = 24
    // PG.15 Multi-function Pin Selection (bits: 31-28)
    ,PG15MFP_MASK = 0xF0000000
    ,PG15MFP_POS = 28
    ,GPG_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOH Low Byte Multiple Function Control Register
  struct GPH_MFPL : reg<ip_ver, base + 0x68>
  {
    static constexpr typename GPH_MFPL::type
    // PH.0 Multi-function Pin Selection (bits: 3-0)
     PH0MFP_MASK = 0x0000000F
    ,PH0MFP_POS = 0
    // PH.1 Multi-function Pin Selection (bits: 7-4)
    ,PH1MFP_MASK = 0x000000F0
    ,PH1MFP_POS = 4
    // PH.2 Multi-function Pin Selection (bits: 11-8)
    ,PH2MFP_MASK = 0x00000F00
    ,PH2MFP_POS = 8
    // PH.3 Multi-function Pin Selection (bits: 15-12)
    ,PH3MFP_MASK = 0x0000F000
    ,PH3MFP_POS = 12
    // PH.4 Multi-function Pin Selection (bits: 19-16)
    ,PH4MFP_MASK = 0x000F0000
    ,PH4MFP_POS = 16
    // PH.5 Multi-function Pin Selection (bits: 23-20)
    ,PH5MFP_MASK = 0x00F00000
    ,PH5MFP_POS = 20
    // PH.6 Multi-function Pin Selection (bits: 27-24)
    ,PH6MFP_MASK = 0x0F000000
    ,PH6MFP_POS = 24
    // PH.7 Multi-function Pin Selection (bits: 31-28)
    ,PH7MFP_MASK = 0xF0000000
    ,PH7MFP_POS = 28
    ,GPH_MFPL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOH High Byte Multiple Function Control Register
  struct GPH_MFPH : reg<ip_ver, base + 0x6C>
  {
    static constexpr typename GPH_MFPH::type
    // PH.8 Multi-function Pin Selection (bits: 3-0)
     PH8MFP_MASK = 0x0000000F
    ,PH8MFP_POS = 0
    // PH.9 Multi-function Pin Selection (bits: 7-4)
    ,PH9MFP_MASK = 0x000000F0
    ,PH9MFP_POS = 4
    // PH.10 Multi-function Pin Selection (bits: 11-8)
    ,PH10MFP_MASK = 0x00000F00
    ,PH10MFP_POS = 8
    // PH.11 Multi-function Pin Selection (bits: 15-12)
    ,PH11MFP_MASK = 0x0000F000
    ,PH11MFP_POS = 12
    // PH.12 Multi-function Pin Selection (bits: 19-16)
    ,PH12MFP_MASK = 0x000F0000
    ,PH12MFP_POS = 16
    // PH.13 Multi-function Pin Selection (bits: 23-20)
    ,PH13MFP_MASK = 0x00F00000
    ,PH13MFP_POS = 20
    // PH.14 Multi-function Pin Selection (bits: 27-24)
    ,PH14MFP_MASK = 0x0F000000
    ,PH14MFP_POS = 24
    // PH.15 Multi-function Pin Selection (bits: 31-28)
    ,PH15MFP_MASK = 0xF0000000
    ,PH15MFP_POS = 28
    ,GPH_MFPH_MASK = 0xFFFFFFFF
    ;
  };
  // GPIOA Multiple Function Output Select Register
  struct GPA_MFOS : reg<ip_ver, base + 0x80>
  {
    static constexpr typename GPA_MFOS::type
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 0)
     MFOS0_MASK = 0x00000001
    ,MFOS0_POS = 0
    ,MFOS0_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS0_1 = 0x00000001 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 1)
    ,MFOS1_MASK = 0x00000002
    ,MFOS1_POS = 1
    ,MFOS1_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS1_1 = 0x00000002 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 2)
    ,MFOS2_MASK = 0x00000004
    ,MFOS2_POS = 2
    ,MFOS2_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS2_1 = 0x00000004 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 3)
    ,MFOS3_MASK = 0x00000008
    ,MFOS3_POS = 3
    ,MFOS3_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS3_1 = 0x00000008 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 4)
    ,MFOS4_MASK = 0x00000010
    ,MFOS4_POS = 4
    ,MFOS4_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS4_1 = 0x00000010 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 5)
    ,MFOS5_MASK = 0x00000020
    ,MFOS5_POS = 5
    ,MFOS5_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS5_1 = 0x00000020 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 6)
    ,MFOS6_MASK = 0x00000040
    ,MFOS6_POS = 6
    ,MFOS6_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS6_1 = 0x00000040 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 7)
    ,MFOS7_MASK = 0x00000080
    ,MFOS7_POS = 7
    ,MFOS7_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS7_1 = 0x00000080 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 8)
    ,MFOS8_MASK = 0x00000100
    ,MFOS8_POS = 8
    ,MFOS8_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS8_1 = 0x00000100 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 9)
    ,MFOS9_MASK = 0x00000200
    ,MFOS9_POS = 9
    ,MFOS9_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS9_1 = 0x00000200 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 10)
    ,MFOS10_MASK = 0x00000400
    ,MFOS10_POS = 10
    ,MFOS10_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS10_1 = 0x00000400 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 11)
    ,MFOS11_MASK = 0x00000800
    ,MFOS11_POS = 11
    ,MFOS11_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS11_1 = 0x00000800 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 12)
    ,MFOS12_MASK = 0x00001000
    ,MFOS12_POS = 12
    ,MFOS12_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS12_1 = 0x00001000 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 13)
    ,MFOS13_MASK = 0x00002000
    ,MFOS13_POS = 13
    ,MFOS13_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS13_1 = 0x00002000 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 14)
    ,MFOS14_MASK = 0x00004000
    ,MFOS14_POS = 14
    ,MFOS14_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS14_1 = 0x00004000 // Multiple function pin output mode type is Open-drain mode
    // GPIOA-h Pin[n] Multiple Function Pin Output Mode Select This bit used to select multiple function pin output mode type for Px.n pin (bits: 15)
    ,MFOS15_MASK = 0x00008000
    ,MFOS15_POS = 15
    ,MFOS15_0 = 0x00000000 // Multiple function pin output mode type is Push-pull mode
    ,MFOS15_1 = 0x00008000 // Multiple function pin output mode type is Open-drain mode
    ,GPA_MFOS_MASK = 0x0000FFFF
    ;
  };
  // GPIOB Multiple Function Output Select Register
  using GPB_MFOS = reg<ip_ver, base + 0x84>;
  // GPIOC Multiple Function Output Select Register
  using GPC_MFOS = reg<ip_ver, base + 0x88>;
  // GPIOD Multiple Function Output Select Register
  using GPD_MFOS = reg<ip_ver, base + 0x8C>;
  // GPIOE Multiple Function Output Select Register
  using GPE_MFOS = reg<ip_ver, base + 0x90>;
  // GPIOF Multiple Function Output Select Register
  using GPF_MFOS = reg<ip_ver, base + 0x94>;
  // GPIOG Multiple Function Output Select Register
  using GPG_MFOS = reg<ip_ver, base + 0x98>;
  // GPIOH Multiple Function Output Select Register
  using GPH_MFOS = reg<ip_ver, base + 0x9C>;
  // System SRAM Interrupt Enable Control Register
  struct SRAM_INTCTL : reg<ip_ver, base + 0xC0>
  {
    static constexpr typename SRAM_INTCTL::type
    // SRAM Parity Check Error Interrupt Enable Bit (bits: 0)
     PERRIEN_MASK = 0x00000001
    ,PERRIEN_POS = 0
    ,PERRIEN_0 = 0x00000000 // SRAM parity check error interrupt Disabled
    ,PERRIEN_1 = 0x00000001 // SRAM parity check error interrupt Enabled
    ,SRAM_INTCTL_MASK = 0x00000001
    ;
  };
  // System SRAM Parity Error Status Register
  struct SRAM_STATUS : reg<ip_ver, base + 0xC4>
  {
    static constexpr typename SRAM_STATUS::type
    // SRAM Parity Check Error Flag This bit indicates the System SRAM parity error occurred. Write 1 to clear this to 0. (bits: 0)
     PERRIF_MASK = 0x00000001
    ,PERRIF_POS = 0
    ,PERRIF_0 = 0x00000000 // No System SRAM parity error
    ,PERRIF_1 = 0x00000001 // System SRAM parity error occur
    ,SRAM_STATUS_MASK = 0x00000001
    ;
  };
  // System SRAM Parity Check Error Address Register
  struct SRAM_ERRADDR : reg<ip_ver, base + 0xC8>
  {
    static constexpr typename SRAM_ERRADDR::type
    // System SRAM Parity Error Address This register shows system SRAM parity error byte address. (bits: 31-0)
     ERRADDR_MASK = 0xFFFFFFFF
    ,ERRADDR_POS = 0
    ,SRAM_ERRADDR_MASK = 0xFFFFFFFF
    ;
  };
  // System SRAM BIST Test Control Register
  struct SRAM_BISTCTL : reg<ip_ver, base + 0xD0>
  {
    static constexpr typename SRAM_BISTCTL::type
    // SRAM Bank0 BIST Enable Bit (Write Protect) This bit enables BIST test for SRAM bank0. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     SRBIST0_MASK = 0x00000001
    ,SRBIST0_POS = 0
    ,SRBIST0_0 = 0x00000000 // system SRAM bank0 BIST Disabled
    ,SRBIST0_1 = 0x00000001 // system SRAM bank0 BIST Enabled
    // SRAM Bank1 BIST Enable Bit (Write Protect) This bit enables BIST test for SRAM bank1. Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 1)
    ,SRBIST1_MASK = 0x00000002
    ,SRBIST1_POS = 1
    ,SRBIST1_0 = 0x00000000 // system SRAM bank1 BIST Disabled
    ,SRBIST1_1 = 0x00000002 // system SRAM bank1 BIST Enabled
    // CACHE BIST Enable Bit (Write Protect) This bit enables BIST test for CACHE RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 2)
    ,CRBIST_MASK = 0x00000004
    ,CRBIST_POS = 2
    ,CRBIST_0 = 0x00000000 // system CACHE BIST Disabled
    ,CRBIST_1 = 0x00000004 // system CACHE BIST Enabled
    // CAN BIST Enable Bit (Write Protect) This bit enables BIST test for CAN RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 3)
    ,CANBIST_MASK = 0x00000008
    ,CANBIST_POS = 3
    ,CANBIST_0 = 0x00000000 // system CAN BIST Disabled
    ,CANBIST_1 = 0x00000008 // system CAN BIST Enabled
    // USB BIST Enable Bit (Write Protect) This bit enables BIST test for USB RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 4)
    ,USBBIST_MASK = 0x00000010
    ,USBBIST_POS = 4
    ,USBBIST_0 = 0x00000000 // system USB BIST Disabled
    ,USBBIST_1 = 0x00000010 // system USB BIST Enabled
    // SPIM BIST Enable Bit (Write Protect) This bit enables BIST test for SPIM RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 5)
    ,SPIMBIST_MASK = 0x00000020
    ,SPIMBIST_POS = 5
    ,SPIMBIST_0 = 0x00000000 // system SPIM BIST Disabled
    ,SPIMBIST_1 = 0x00000020 // system SPIM BIST Enabled
    // EMC BIST Enable Bit (Write Protect) This bit enables BIST test for EMC RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 6)
    ,EMCBIST_MASK = 0x00000040
    ,EMCBIST_POS = 6
    ,EMCBIST_0 = 0x00000000 // system EMC BIST Disabled
    ,EMCBIST_1 = 0x00000040 // system EMC BIST Enabled
    // PDMA BIST Enable Bit (Write Protect) This bit enables BIST test for PDMA RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 7)
    ,PDMABIST_MASK = 0x00000080
    ,PDMABIST_POS = 7
    ,PDMABIST_0 = 0x00000000 // system PDMA BIST Disabled
    ,PDMABIST_1 = 0x00000080 // system PDMA BIST Enabled
    // HSUSBD BIST Enable Bit (Write Protect) This bit enables BIST test for HSUSBD RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 8)
    ,HSUSBDBIST_MASK = 0x00000100
    ,HSUSBDBIST_POS = 8
    ,HSUSBDBIST_0 = 0x00000000 // system HSUSBD BIST Disabled
    ,HSUSBDBIST_1 = 0x00000100 // system HSUSBD BIST Enabled
    // HSUSBH BIST Enable Bit (Write Protect) This bit enables BIST test for HSUSBH RAM Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 9)
    ,HSUSBHBIST_MASK = 0x00000200
    ,HSUSBHBIST_POS = 9
    ,HSUSBHBIST_0 = 0x00000000 // system HSUSBH BIST Disabled
    ,HSUSBHBIST_1 = 0x00000200 // system HSUSBH BIST Enabled
    ,SRAM_BISTCTL_MASK = 0x000003FF
    ;
  };
  // System SRAM BIST Test Status Register
  struct SRAM_BISTSTS : reg<ip_ver, base + 0xD4>
  {
    static constexpr typename SRAM_BISTSTS::type
    // 1st System SRAM BIST Fail Flag (bits: 0)
     SRBISTEF0_MASK = 0x00000001
    ,SRBISTEF0_POS = 0
    ,SRBISTEF0_0 = 0x00000000 // 1st system SRAM BIST test pass
    ,SRBISTEF0_1 = 0x00000001 // 1st system SRAM BIST test fail
    // 2nd System SRAM BIST Fail Flag (bits: 1)
    ,SRBISTEF1_MASK = 0x00000002
    ,SRBISTEF1_POS = 1
    ,SRBISTEF1_0 = 0x00000000 // 2nd system SRAM BIST test pass
    ,SRBISTEF1_1 = 0x00000002 // 2nd system SRAM BIST test fail
    // CACHE SRAM BIST Fail Flag (bits: 2)
    ,CRBISTEF_MASK = 0x00000004
    ,CRBISTEF_POS = 2
    ,CRBISTEF_0 = 0x00000000 // System CACHE RAM BIST test pass
    ,CRBISTEF_1 = 0x00000004 // System CACHE RAM BIST test fail
    // CAN SRAM BIST Fail Flag (bits: 3)
    ,CANBEF_MASK = 0x00000008
    ,CANBEF_POS = 3
    ,CANBEF_0 = 0x00000000 // CAN SRAM BIST test pass
    ,CANBEF_1 = 0x00000008 // CAN SRAM BIST test fail
    // USB SRAM BIST Fail Flag (bits: 4)
    ,USBBEF_MASK = 0x00000010
    ,USBBEF_POS = 4
    ,USBBEF_0 = 0x00000000 // USB SRAM BIST test pass
    ,USBBEF_1 = 0x00000010 // USB SRAM BIST test fail
    // PDMA SRAM BIST Fail Flag (bits: 7)
    ,PDMABEF_MASK = 0x00000080
    ,PDMABEF_POS = 7
    ,PDMABEF_0 = 0x00000000 // PDMA SRAM BIST test pass
    ,PDMABEF_1 = 0x00000080 // PDMA SRAM BIST test fail
    // 1st SRAM BIST Test Finish (bits: 16)
    ,SRBEND0_MASK = 0x00010000
    ,SRBEND0_POS = 16
    ,SRBEND0_0 = 0x00000000 // 1st system SRAM BIST active
    ,SRBEND0_1 = 0x00010000 // 1st system SRAM BIST finish
    // 2nd SRAM BIST Test Finish (bits: 17)
    ,SRBEND1_MASK = 0x00020000
    ,SRBEND1_POS = 17
    ,SRBEND1_0 = 0x00000000 // 2nd system SRAM BIST is active
    ,SRBEND1_1 = 0x00020000 // 2nd system SRAM BIST finish
    // CACHE SRAM BIST Test Finish (bits: 18)
    ,CRBEND_MASK = 0x00040000
    ,CRBEND_POS = 18
    ,CRBEND_0 = 0x00000000 // System CACHE RAM BIST is active
    ,CRBEND_1 = 0x00040000 // System CACHE RAM BIST test finish
    // CAN SRAM BIST Test Finish (bits: 19)
    ,CANBEND_MASK = 0x00080000
    ,CANBEND_POS = 19
    ,CANBEND_0 = 0x00000000 // CAN SRAM BIST is active
    ,CANBEND_1 = 0x00080000 // CAN SRAM BIST test finish
    // USB SRAM BIST Test Finish (bits: 20)
    ,USBBEND_MASK = 0x00100000
    ,USBBEND_POS = 20
    ,USBBEND_0 = 0x00000000 // USB SRAM BIST is active
    ,USBBEND_1 = 0x00100000 // USB SRAM BIST test finish
    // PDMA SRAM BIST Test Finish (bits: 23)
    ,PDMABEND_MASK = 0x00800000
    ,PDMABEND_POS = 23
    ,PDMABEND_0 = 0x00000000 // PDMA SRAM BIST is active
    ,PDMABEND_1 = 0x00800000 // PDMA SRAM BIST test finish
    ,SRAM_BISTSTS_MASK = 0x009F009F
    ;
  };
  // HIRC48M Trim Control Register
  struct HIRCTCTL : reg<ip_ver, base + 0xE4, 0x00080000>
  {
    static constexpr typename HIRCTCTL::type
    // Trim Frequency Selection This field indicates the target frequency of 48 MHz internal high speed RC oscillator (HIRC) auto trim. During auto trim operation, if clock error detected with CESTOPEN is set to 1 or trim retry limitation count reached, this field will be cleared to 00 automatically. (bits: 1-0)
     FREQSEL_MASK = 0x00000003
    ,FREQSEL_POS = 0
    ,FREQSEL_0 = 0x00000000 // Disable HIRC auto trim function
    ,FREQSEL_1 = 0x00000001 // Enable HIRC auto trim function and trim HIRC to 48 MHz
    ,FREQSEL_2 = 0x00000002 // Reserved.
    ,FREQSEL_3 = 0x00000003 // Reserved.
    // Trim Calculation Loop Selection This field defines that trim value calculation is based on how many reference clocks. Note: For example, if LOOPSEL is set as 00, auto trim circuit will calculate trim value based on the average frequency difference in 4 clocks of reference clock. (bits: 5-4)
    ,LOOPSEL_MASK = 0x00000030
    ,LOOPSEL_POS = 4
    ,LOOPSEL_0 = 0x00000000 // Trim value calculation is based on average difference in 4 clocks of reference clock
    ,LOOPSEL_1 = 0x00000010 // Trim value calculation is based on average difference in 8 clocks of reference clock
    ,LOOPSEL_2 = 0x00000020 // Trim value calculation is based on average difference in 16 clocks of reference clock
    ,LOOPSEL_3 = 0x00000030 // Trim value calculation is based on average difference in 32 clocks of reference clock
    // Trim Value Update Limitation Count This field defines that how many times the auto trim circuit will try to update the HIRC trim value before the frequency of HIRC locked. Once the HIRC locked, the internal trim value update counter will be reset. If the trim value update counter reached this limitation value and frequency of HIRC still doesn't lock, the auto trim operation will be disabled and FREQSEL will be cleared to 00. (bits: 7-6)
    ,RETRYCNT_MASK = 0x000000C0
    ,RETRYCNT_POS = 6
    ,RETRYCNT_0 = 0x00000000 // Trim retry count limitation is 64 loops
    ,RETRYCNT_1 = 0x00000040 // Trim retry count limitation is 128 loops
    ,RETRYCNT_2 = 0x00000080 // Trim retry count limitation is 256 loops
    ,RETRYCNT_3 = 0x000000C0 // Trim retry count limitation is 512 loops
    // Clock Error Stop Enable Bit (bits: 8)
    ,CESTOPEN_MASK = 0x00000100
    ,CESTOPEN_POS = 8
    ,CESTOPEN_0 = 0x00000000 // The trim operation is keep going if clock is inaccuracy
    ,CESTOPEN_1 = 0x00000100 // The trim operation is stopped if clock is inaccuracy
    // Boundary Enable Bit (bits: 9)
    ,BOUNDEN_MASK = 0x00000200
    ,BOUNDEN_POS = 9
    ,BOUNDEN_0 = 0x00000000 // Boundary function Disabled
    ,BOUNDEN_1 = 0x00000200 // Boundary function Enabled
    // Reference Clock Selection Note: HIRC trim reference clock is 20 kHz in test mode. (bits: 10)
    ,REFCKSEL_MASK = 0x00000400
    ,REFCKSEL_POS = 10
    ,REFCKSEL_0 = 0x00000000 // HIRC trim reference clock is from LXT (32.768 kHz)
    ,REFCKSEL_1 = 0x00000400 // HIRC trim reference clock is from internal USB synchronous mode
    // Boundary Selection Fill the boundary range from 0x1 to 0x31, 0x0 is reserved. Note: This field is effective only when the BOUNDEN(SYS_HIRCTRIMCTL[9]) is enabled. (bits: 20-16)
    ,BOUNDARY_MASK = 0x001F0000
    ,BOUNDARY_POS = 16
    ,HIRCTCTL_MASK = 0x001F07F3
    ;
  };
  // HIRC48M Trim Interrupt Enable Register
  struct HIRCTIEN : reg<ip_ver, base + 0xE8>
  {
    static constexpr typename HIRCTIEN::type
    // Trim Failure Interrupt Enable Bit This bit controls if an interrupt will be triggered while HIRC trim value update limitation count reached and HIRC frequency still not locked on target frequency set by FREQSEL(SYS_IRCTCTL[1:0]). If this bit is high and TFAILIF(SYS_IRCTISTS[1]) is set during auto trim operation, an interrupt will be triggered to notify that HIRC trim value update limitation count was reached. (bits: 1)
     TFAILIEN_MASK = 0x00000002
    ,TFAILIEN_POS = 1
    ,TFAILIEN_0 = 0x00000000 // Disable TFAILIF(SYS_IRCTISTS[1]) status to trigger an interrupt to CPU
    ,TFAILIEN_1 = 0x00000002 // Enable TFAILIF(SYS_IRCTISTS[1]) status to trigger an interrupt to CPU
    // Clock Error Interrupt Enable Bit This bit controls if CPU would get an interrupt while clock is inaccuracy during auto trim operation. If this bit is set to1, and CLKERRIF(SYS_IRCTISTS[2]) is set during auto trim operation, an interrupt will be triggered to notify the clock frequency is inaccuracy. (bits: 2)
    ,CLKEIEN_MASK = 0x00000004
    ,CLKEIEN_POS = 2
    ,CLKEIEN_0 = 0x00000000 // Disable CLKERRIF(SYS_IRCTISTS[2]) status to trigger an interrupt to CPU
    ,CLKEIEN_1 = 0x00000004 // Enable CLKERRIF(SYS_IRCTISTS[2]) status to trigger an interrupt to CPU
    ,HIRCTIEN_MASK = 0x00000006
    ;
  };
  // HIRC48M Trim Interrupt Status Register
  struct HIRCTISTS : reg<ip_ver, base + 0xEC>
  {
    static constexpr typename HIRCTISTS::type
    // HIRC Frequency Lock Status This bit indicates the HIRC frequency is locked. This is a status bit and doesn't trigger any interrupt Write 1 to clear this to 0. This bit will be set automatically, if the frequency is lock and the RC_TRIM is enabled. (bits: 0)
     FREQLOCK_MASK = 0x00000001
    ,FREQLOCK_POS = 0
    ,FREQLOCK_0 = 0x00000000 // The internal high-speed oscillator frequency doesn't lock at 48 MHz yet
    ,FREQLOCK_1 = 0x00000001 // The internal high-speed oscillator frequency locked at 48 MHz
    // Trim Failure Interrupt Status This bit indicates that HIRC trim value update limitation count reached and the HIRC clock frequency still doesn't be locked. Once this bit is set, the auto trim operation stopped and FREQSEL(SYS_IRCTCTL[1:0]) will be cleared to 00 by hardware automatically. If this bit is set and TFAILIEN(SYS_IRCTIEN[1]) is high, an interrupt will be triggered to notify that HIRC trim value update limitation count was reached. Write 1 to clear this to 0. (bits: 1)
    ,TFAILIF_MASK = 0x00000002
    ,TFAILIF_POS = 1
    ,TFAILIF_0 = 0x00000000 // Trim value update limitation count does not reach
    ,TFAILIF_1 = 0x00000002 // Trim value update limitation count reached and HIRC frequency still not locked
    // Clock Error Interrupt Status When the frequency of 32.768 kHz external low speed crystal oscillator (LXT) or 48 MHz internal high speed RC oscillator (HIRC) is shift larger to unreasonable value, this bit will be set and to be an indicate that clock frequency is inaccuracy Once this bit is set to 1, the auto trim operation stopped and FREQSEL(SYS_IRCTCL[1:0]) will be cleared to 00 by hardware automatically if CESTOPEN(SYS_IRCTCTL[8]) is set to 1. If this bit is set and CLKEIEN(SYS_IRCTIEN[2]) is high, an interrupt will be triggered to notify the clock frequency is inaccuracy. Write 1 to clear this to 0. (bits: 2)
    ,CLKERRIF_MASK = 0x00000004
    ,CLKERRIF_POS = 2
    ,CLKERRIF_0 = 0x00000000 // Clock frequency is accuracy
    ,CLKERRIF_1 = 0x00000004 // Clock frequency is inaccuracy
    // Over Boundary Status When the over boundary function is set, if there occurs the over boundary condition, this flag will be set. Note 1: Write 1 to clear this flag. (bits: 3)
    ,OVBDIF_MASK = 0x00000008
    ,OVBDIF_POS = 3
    ,OVBDIF_0 = 0x00000000 // Over boundary coundition did not occur
    ,OVBDIF_1 = 0x00000008 // Over boundary coundition occurred
    ,HIRCTISTS_MASK = 0x0000000F
    ;
  };
  // HIRC Trim Control Register
  struct IRCTCTL : reg<ip_ver, base + 0xF0, 0x00080000>
  {
    static constexpr typename IRCTCTL::type
    // Trim Frequency Selection This field indicates the target frequency of 12 MHz internal high speed RC oscillator (HIRC) auto trim. During auto trim operation, if clock error detected with CESTOPEN is set to 1 or trim retry limitation count reached, this field will be cleared to 00 automatically. (bits: 1-0)
     FREQSEL_MASK = 0x00000003
    ,FREQSEL_POS = 0
    ,FREQSEL_0 = 0x00000000 // Disable HIRC auto trim function
    ,FREQSEL_1 = 0x00000001 // Enable HIRC auto trim function and trim HIRC to 12 MHz
    ,FREQSEL_2 = 0x00000002 // Reserved.
    ,FREQSEL_3 = 0x00000003 // Reserved.
    // Trim Calculation Loop Selection This field defines that trim value calculation is based on how many reference clocks. Note: For example, if LOOPSEL is set as 00, auto trim circuit will calculate trim value based on the average frequency difference in 4 clocks of reference clock. (bits: 5-4)
    ,LOOPSEL_MASK = 0x00000030
    ,LOOPSEL_POS = 4
    ,LOOPSEL_0 = 0x00000000 // Trim value calculation is based on average difference in 4 clocks of reference clock
    ,LOOPSEL_1 = 0x00000010 // Trim value calculation is based on average difference in 8 clocks of reference clock
    ,LOOPSEL_2 = 0x00000020 // Trim value calculation is based on average difference in 16 clocks of reference clock
    ,LOOPSEL_3 = 0x00000030 // Trim value calculation is based on average difference in 32 clocks of reference clock
    // Trim Value Update Limitation Count This field defines that how many times the auto trim circuit will try to update the HIRC trim value before the frequency of HIRC locked. Once the HIRC locked, the internal trim value update counter will be reset. If the trim value update counter reached this limitation value and frequency of HIRC still doesn't lock, the auto trim operation will be disabled and FREQSEL will be cleared to 00. (bits: 7-6)
    ,RETRYCNT_MASK = 0x000000C0
    ,RETRYCNT_POS = 6
    ,RETRYCNT_0 = 0x00000000 // Trim retry count limitation is 64 loops
    ,RETRYCNT_1 = 0x00000040 // Trim retry count limitation is 128 loops
    ,RETRYCNT_2 = 0x00000080 // Trim retry count limitation is 256 loops
    ,RETRYCNT_3 = 0x000000C0 // Trim retry count limitation is 512 loops
    // Clock Error Stop Enable Bit (bits: 8)
    ,CESTOPEN_MASK = 0x00000100
    ,CESTOPEN_POS = 8
    ,CESTOPEN_0 = 0x00000000 // The trim operation is keep going if clock is inaccuracy
    ,CESTOPEN_1 = 0x00000100 // The trim operation is stopped if clock is inaccuracy
    // Boundary Enable Bit (bits: 9)
    ,BOUNDEN_MASK = 0x00000200
    ,BOUNDEN_POS = 9
    ,BOUNDEN_0 = 0x00000000 // Boundary function Disabled
    ,BOUNDEN_1 = 0x00000200 // Boundary function Enabled
    // Reference Clock Selection Note: HIRC trim reference clock is 20 kHz in test mode. (bits: 10)
    ,REFCKSEL_MASK = 0x00000400
    ,REFCKSEL_POS = 10
    ,REFCKSEL_0 = 0x00000000 // HIRC trim reference clock is from LXT (32.768 kHz)
    ,REFCKSEL_1 = 0x00000400 // HIRC trim reference clock is from internal USB synchronous mode
    // Boundary Selection Fill the boundary range from 0x1 to 0x31, 0x0 is reserved. Note 1: This field is effective only when the BOUNDEN(SYS_HIRCTRIMCTL[9]) is enabled. (bits: 20-16)
    ,BOUNDARY_MASK = 0x001F0000
    ,BOUNDARY_POS = 16
    ,IRCTCTL_MASK = 0x001F07F3
    ;
  };
  // HIRC Trim Interrupt Enable Register
  struct IRCTIEN : reg<ip_ver, base + 0xF4>
  {
    static constexpr typename IRCTIEN::type
    // Trim Failure Interrupt Enable Bit This bit controls if an interrupt will be triggered while HIRC trim value update limitation count reached and HIRC frequency still not locked on target frequency set by FREQSEL(SYS_IRCTCTL[1:0]). If this bit is high and TFAILIF(SYS_IRCTISTS[1]) is set during auto trim operation, an interrupt will be triggered to notify that HIRC trim value update limitation count was reached. (bits: 1)
     TFAILIEN_MASK = 0x00000002
    ,TFAILIEN_POS = 1
    ,TFAILIEN_0 = 0x00000000 // Disable TFAILIF(SYS_IRCTISTS[1]) status to trigger an interrupt to CPU
    ,TFAILIEN_1 = 0x00000002 // Enable TFAILIF(SYS_IRCTISTS[1]) status to trigger an interrupt to CPU
    // Clock Error Interrupt Enable Bit This bit controls if CPU would get an interrupt while clock is inaccuracy during auto trim operation. If this bit is set to1, and CLKERRIF(SYS_IRCTISTS[2]) is set during auto trim operation, an interrupt will be triggered to notify the clock frequency is inaccuracy. (bits: 2)
    ,CLKEIEN_MASK = 0x00000004
    ,CLKEIEN_POS = 2
    ,CLKEIEN_0 = 0x00000000 // Disable CLKERRIF(SYS_IRCTISTS[2]) status to trigger an interrupt to CPU
    ,CLKEIEN_1 = 0x00000004 // Enable CLKERRIF(SYS_IRCTISTS[2]) status to trigger an interrupt to CPU
    ,IRCTIEN_MASK = 0x00000006
    ;
  };
  // HIRC Trim Interrupt Status Register
  struct IRCTISTS : reg<ip_ver, base + 0xF8>
  {
    static constexpr typename IRCTISTS::type
    // HIRC Frequency Lock Status This bit indicates the HIRC frequency is locked. This is a status bit and doesn't trigger any interrupt Write 1 to clear this to 0. This bit will be set automatically, if the frequency is lock and the RC_TRIM is enabled. (bits: 0)
     FREQLOCK_MASK = 0x00000001
    ,FREQLOCK_POS = 0
    ,FREQLOCK_0 = 0x00000000 // The internal high-speed oscillator frequency doesn't lock at 12 MHz yet
    ,FREQLOCK_1 = 0x00000001 // The internal high-speed oscillator frequency locked at 12 MHz
    // Trim Failure Interrupt Status This bit indicates that HIRC trim value update limitation count reached and the HIRC clock frequency still doesn't be locked. Once this bit is set, the auto trim operation stopped and FREQSEL(SYS_IRCTCTL[1:0]) will be cleared to 00 by hardware automatically. If this bit is set and TFAILIEN(SYS_IRCTIEN[1]) is high, an interrupt will be triggered to notify that HIRC trim value update limitation count was reached. Write 1 to clear this to 0. (bits: 1)
    ,TFAILIF_MASK = 0x00000002
    ,TFAILIF_POS = 1
    ,TFAILIF_0 = 0x00000000 // Trim value update limitation count does not reach
    ,TFAILIF_1 = 0x00000002 // Trim value update limitation count reached and HIRC frequency still not locked
    // Clock Error Interrupt Status When the frequency of 32.768 kHz external low speed crystal oscillator (LXT) or 12 MHz internal high speed RC oscillator (HIRC) is shift larger to unreasonable value, this bit will be set and to be an indicate that clock frequency is inaccuracy Once this bit is set to 1, the auto trim operation stopped and FREQSEL(SYS_IRCTCL[1:0]) will be cleared to 00 by hardware automatically if CESTOPEN(SYS_IRCTCTL[8]) is set to 1. If this bit is set and CLKEIEN(SYS_IRCTIEN[2]) is high, an interrupt will be triggered to notify the clock frequency is inaccuracy. Write 1 to clear this to 0. (bits: 2)
    ,CLKERRIF_MASK = 0x00000004
    ,CLKERRIF_POS = 2
    ,CLKERRIF_0 = 0x00000000 // Clock frequency is accuracy
    ,CLKERRIF_1 = 0x00000004 // Clock frequency is inaccuracy
    // Over Boundary Status When the over boundary function is set, if there occurs the over boundary condition, this flag will be set. Note 1: Write 1 to clear this flag. (bits: 3)
    ,OVBDIF_MASK = 0x00000008
    ,OVBDIF_POS = 3
    ,OVBDIF_0 = 0x00000000 // Over boundary coundition did not occur
    ,OVBDIF_1 = 0x00000008 // Over boundary coundition occurred
    ,IRCTISTS_MASK = 0x0000000F
    ;
  };
  // Register Lock Control Register
  struct REGLCTL : reg<ip_ver, base + 0x100>
  {
    static constexpr typename REGLCTL::type
    // Register Lock Control Code Some registers have write-protection function. Writing these registers have to disable the protected function by writing the sequence value '59h', '16h', '88h' to this field. After this sequence is completed, the REGLCTL bit will be set to 1 and write-protection registers can be normal write. REGLCTL[0] Register Lock Control Disable Index (bits: 7-0)
     REGLCTLVAL_MASK = 0x000000FF
    ,REGLCTLVAL_POS = 0
    ,REGLCTLVAL_0 = 0x00000000 // Write-protection Enabled for writing protected registers. Any write to the protected register is ignored
    ,REGLCTLVAL_1 = 0x00000001 // Write-protection Disabled for writing protected registers
    ,REGLCTL_MASK = 0x000000FF
    ;
  };
  // Analog POR Disable Control Register
  struct PORDISAN : reg<ip_ver, base + 0x1EC>
  {
    static constexpr typename PORDISAN::type
    // Power-on Reset Enable Bit (Write Protect) After powered on, User can turn off internal analog POR circuit to save power by writing 0x5AA5 to this field. The analog POR circuit will be active again when this field is set to another value or chip is reset by other reset source, including: nRESET, Watchdog, LVR reset, BOD reset, ICE reset command and the software-chip reset function. Note: This bit is write protected. Refer to the SYS_REGLCTL register. Note: M48xID/M487KMCAN series will disable POR by hardware when system enter power-down mode. (bits: 15-0)
     POROFFAN_MASK = 0x0000FFFF
    ,POROFFAN_POS = 0
    ,PORDISAN_MASK = 0x0000FFFF
    ;
  };
  // Chip Series Version Register
  struct CSERVER : reg<ip_ver, base + 0x1F4>
  {
    static constexpr typename CSERVER::type
    // Chip Series Version These bits indicate the series version of chip. (bits: 7-0)
     VERSION_MASK = 0x000000FF
    ,VERSION_POS = 0
    ,VERSION_0 = 0x00000000 // M48xID/M487KMCAN
    ,VERSION_1 = 0x00000001 // M48xGC/M48xE8
    ,CSERVER_MASK = 0x000000FF
    ;
  };
  // Power Level Control Register
  struct PLCTL : reg<ip_ver, base + 0x1F8>
  {
    static constexpr typename PLCTL::type
    // Power Level Select(Write Protect) These bits indicate the status of power level. (bits: 1-0)
     PLSEL_MASK = 0x00000003
    ,PLSEL_POS = 0
    ,PLSEL_0 = 0x00000000 // Power level is PL0
    ,PLSEL_1 = 0x00000001 // Power level is PL1
    // LDO Voltage Scaling Step(Write Protect) The LVSSTEP value is LDO voltage rising step. (bits: 21-16)
    ,LVSSTEP_MASK = 0x003F0000
    ,LVSSTEP_POS = 16
    // LDO Voltage Scaling Period(Write Protect) The LVSPRD value is the period of each LDO voltage rising step. (bits: 31-24)
    ,LVSPRD_MASK = 0xFF000000
    ,LVSPRD_POS = 24
    ,PLCTL_MASK = 0xFF3F0003
    ;
  };
  // Power Level Status Register
  struct PLSTS : reg<ip_ver, base + 0x1FC, 0x00000100>
  {
    static constexpr typename PLSTS::type
    // Power Level Change Busy Bit (Read Only) This bit is set by hardware when power level is changing. After power level change is completed, this bit will be cleared automatically by hardware. (bits: 0)
     PLCBUSY_MASK = 0x00000001
    ,PLCBUSY_POS = 0
    ,PLCBUSY_0 = 0x00000000 // Core voltage change is completed
    ,PLCBUSY_1 = 0x00000001 // Core voltage change is ongoing
    // Power Level Status (Read Only) This bit indicates the status of power level. (bits: 9-8)
    ,PLSTATUS_MASK = 0x00000300
    ,PLSTATUS_POS = 8
    ,PLSTATUS_0 = 0x00000000 // Power level is PL0
    ,PLSTATUS_1 = 0x00000100 // Power level is PL1
    ,PLSTS_MASK = 0x00000301
    ;
  };
  // AHB Bus Matrix Priority Control Register
  struct AHBMCTL : reg<ip_ver, base + 0x400, 0x00000001>
  {
    static constexpr typename AHBMCTL::type
    // Highest AHB Bus Priority of Cortex-M4 Core Enable Bit (Write Protect) Enable Cortex-M4 Core With Highest AHB Bus Priority In AHB Bus Matrix Note: This bit is write protected. Refer to the SYS_REGLCTL register. (bits: 0)
     INTACTEN_MASK = 0x00000001
    ,INTACTEN_POS = 0
    ,INTACTEN_0 = 0x00000000 // Round-robin mode
    ,INTACTEN_1 = 0x00000001 // Cortex-M4 CPU with highest bus priority when interrupt occurred
    ,AHBMCTL_MASK = 0x00000001
    ;
  };
}; // struct SYS

} // namespace lmcu::device::ip::v1

