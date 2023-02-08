/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// GPIO Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct GPIO
{
  static constexpr auto ip_ver = ip_version::_1;

  // GPIO Port A Pin I/O Mode Control
  struct PMD : reg<ip_ver, base + 0x0>
  {
    static constexpr typename PMD::type
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 1-0)
     PMD0_MASK = 0x00000003
    ,PMD0_POS = 0
    ,PMD0_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD0_1 = 0x00000001 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD0_2 = 0x00000002 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD0_3 = 0x00000003 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 3-2)
    ,PMD1_MASK = 0x0000000C
    ,PMD1_POS = 2
    ,PMD1_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD1_1 = 0x00000004 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD1_2 = 0x00000008 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD1_3 = 0x0000000C // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 5-4)
    ,PMD2_MASK = 0x00000030
    ,PMD2_POS = 4
    ,PMD2_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD2_1 = 0x00000010 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD2_2 = 0x00000020 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD2_3 = 0x00000030 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 7-6)
    ,PMD3_MASK = 0x000000C0
    ,PMD3_POS = 6
    ,PMD3_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD3_1 = 0x00000040 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD3_2 = 0x00000080 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD3_3 = 0x000000C0 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 9-8)
    ,PMD4_MASK = 0x00000300
    ,PMD4_POS = 8
    ,PMD4_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD4_1 = 0x00000100 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD4_2 = 0x00000200 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD4_3 = 0x00000300 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 11-10)
    ,PMD5_MASK = 0x00000C00
    ,PMD5_POS = 10
    ,PMD5_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD5_1 = 0x00000400 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD5_2 = 0x00000800 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD5_3 = 0x00000C00 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 13-12)
    ,PMD6_MASK = 0x00003000
    ,PMD6_POS = 12
    ,PMD6_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD6_1 = 0x00001000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD6_2 = 0x00002000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD6_3 = 0x00003000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 15-14)
    ,PMD7_MASK = 0x0000C000
    ,PMD7_POS = 14
    ,PMD7_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD7_1 = 0x00004000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD7_2 = 0x00008000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD7_3 = 0x0000C000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 17-16)
    ,PMD8_MASK = 0x00030000
    ,PMD8_POS = 16
    ,PMD8_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD8_1 = 0x00010000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD8_2 = 0x00020000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD8_3 = 0x00030000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 19-18)
    ,PMD9_MASK = 0x000C0000
    ,PMD9_POS = 18
    ,PMD9_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD9_1 = 0x00040000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD9_2 = 0x00080000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD9_3 = 0x000C0000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 21-20)
    ,PMD10_MASK = 0x00300000
    ,PMD10_POS = 20
    ,PMD10_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD10_1 = 0x00100000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD10_2 = 0x00200000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD10_3 = 0x00300000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 23-22)
    ,PMD11_MASK = 0x00C00000
    ,PMD11_POS = 22
    ,PMD11_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD11_1 = 0x00400000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD11_2 = 0x00800000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD11_3 = 0x00C00000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 25-24)
    ,PMD12_MASK = 0x03000000
    ,PMD12_POS = 24
    ,PMD12_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD12_1 = 0x01000000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD12_2 = 0x02000000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD12_3 = 0x03000000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 27-26)
    ,PMD13_MASK = 0x0C000000
    ,PMD13_POS = 26
    ,PMD13_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD13_1 = 0x04000000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD13_2 = 0x08000000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD13_3 = 0x0C000000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 29-28)
    ,PMD14_MASK = 0x30000000
    ,PMD14_POS = 28
    ,PMD14_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD14_1 = 0x10000000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD14_2 = 0x20000000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD14_3 = 0x30000000 // GPIO port [n] pin is in Quasi-bidirectional mode
    // GPIOx I/O Pin[N] Mode Control Determine each I/O mode of GPIOx pins. Note2: The initial value of this field is defined by CIOINI (CONFIG0[10]). If CIOINI is set to 1, the default value is 0xFFFF_FFFF and all pins will be Quasi-bidirectional mode after chip is powered on. If CIOINI is cleared to 0, the default value is 0x0000_0000 and all pins will be input only mode after chip is powered on. (bits: 31-30)
    ,PMD15_MASK = 0xC0000000
    ,PMD15_POS = 30
    ,PMD15_0 = 0x00000000 // GPIO port [n] pin is in Input mode
    ,PMD15_1 = 0x40000000 // GPIO port [n] pin is in Push-pull Output mode
    ,PMD15_2 = 0x80000000 // GPIO port [n] pin is in Open-drain Output mode
    ,PMD15_3 = 0xC0000000 // GPIO port [n] pin is in Quasi-bidirectional mode
    ,PMD_MASK = 0xFFFFFFFF
    ;
  };
  // GPIO Port A Pin Digital Input Path Disable Control
  struct OFFD : reg<ip_ver, base + 0x4>
  {
    static constexpr typename OFFD::type
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 16)
     OFFD0_MASK = 0x00010000
    ,OFFD0_POS = 16
    ,OFFD0_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD0_1 = 0x00010000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 17)
    ,OFFD1_MASK = 0x00020000
    ,OFFD1_POS = 17
    ,OFFD1_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD1_1 = 0x00020000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 18)
    ,OFFD2_MASK = 0x00040000
    ,OFFD2_POS = 18
    ,OFFD2_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD2_1 = 0x00040000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 19)
    ,OFFD3_MASK = 0x00080000
    ,OFFD3_POS = 19
    ,OFFD3_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD3_1 = 0x00080000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 20)
    ,OFFD4_MASK = 0x00100000
    ,OFFD4_POS = 20
    ,OFFD4_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD4_1 = 0x00100000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 21)
    ,OFFD5_MASK = 0x00200000
    ,OFFD5_POS = 21
    ,OFFD5_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD5_1 = 0x00200000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 22)
    ,OFFD6_MASK = 0x00400000
    ,OFFD6_POS = 22
    ,OFFD6_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD6_1 = 0x00400000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 23)
    ,OFFD7_MASK = 0x00800000
    ,OFFD7_POS = 23
    ,OFFD7_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD7_1 = 0x00800000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 24)
    ,OFFD8_MASK = 0x01000000
    ,OFFD8_POS = 24
    ,OFFD8_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD8_1 = 0x01000000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 25)
    ,OFFD9_MASK = 0x02000000
    ,OFFD9_POS = 25
    ,OFFD9_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD9_1 = 0x02000000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 26)
    ,OFFD10_MASK = 0x04000000
    ,OFFD10_POS = 26
    ,OFFD10_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD10_1 = 0x04000000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 27)
    ,OFFD11_MASK = 0x08000000
    ,OFFD11_POS = 27
    ,OFFD11_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD11_1 = 0x08000000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 28)
    ,OFFD12_MASK = 0x10000000
    ,OFFD12_POS = 28
    ,OFFD12_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD12_1 = 0x10000000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 29)
    ,OFFD13_MASK = 0x20000000
    ,OFFD13_POS = 29
    ,OFFD13_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD13_1 = 0x20000000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 30)
    ,OFFD14_MASK = 0x40000000
    ,OFFD14_POS = 30
    ,OFFD14_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD14_1 = 0x40000000 // I/O digital input path Disabled (digital input tied to low)
    // GPIOx Pin[N] Digital Input Path Disable Control Each of these bits is used to control if the digital input path of corresponding GPIO pin is disabled. If input is analog signal, users can disable GPIO digital input path to avoid current leakage. (bits: 31)
    ,OFFD15_MASK = 0x80000000
    ,OFFD15_POS = 31
    ,OFFD15_0 = 0x00000000 // I/O digital input path Enabled
    ,OFFD15_1 = 0x80000000 // I/O digital input path Disabled (digital input tied to low)
    ,OFFD_MASK = 0xFFFF0000
    ;
  };
  // GPIO Port A Data Output Value
  struct DOUT : reg<ip_ver, base + 0x8, 0x0000FFFF>
  {
    static constexpr typename DOUT::type
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 0)
     DOUT0_MASK = 0x00000001
    ,DOUT0_POS = 0
    ,DOUT0_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT0_1 = 0x00000001 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 1)
    ,DOUT1_MASK = 0x00000002
    ,DOUT1_POS = 1
    ,DOUT1_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT1_1 = 0x00000002 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 2)
    ,DOUT2_MASK = 0x00000004
    ,DOUT2_POS = 2
    ,DOUT2_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT2_1 = 0x00000004 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 3)
    ,DOUT3_MASK = 0x00000008
    ,DOUT3_POS = 3
    ,DOUT3_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT3_1 = 0x00000008 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 4)
    ,DOUT4_MASK = 0x00000010
    ,DOUT4_POS = 4
    ,DOUT4_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT4_1 = 0x00000010 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 5)
    ,DOUT5_MASK = 0x00000020
    ,DOUT5_POS = 5
    ,DOUT5_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT5_1 = 0x00000020 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 6)
    ,DOUT6_MASK = 0x00000040
    ,DOUT6_POS = 6
    ,DOUT6_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT6_1 = 0x00000040 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 7)
    ,DOUT7_MASK = 0x00000080
    ,DOUT7_POS = 7
    ,DOUT7_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT7_1 = 0x00000080 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 8)
    ,DOUT8_MASK = 0x00000100
    ,DOUT8_POS = 8
    ,DOUT8_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT8_1 = 0x00000100 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 9)
    ,DOUT9_MASK = 0x00000200
    ,DOUT9_POS = 9
    ,DOUT9_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT9_1 = 0x00000200 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 10)
    ,DOUT10_MASK = 0x00000400
    ,DOUT10_POS = 10
    ,DOUT10_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT10_1 = 0x00000400 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 11)
    ,DOUT11_MASK = 0x00000800
    ,DOUT11_POS = 11
    ,DOUT11_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT11_1 = 0x00000800 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 12)
    ,DOUT12_MASK = 0x00001000
    ,DOUT12_POS = 12
    ,DOUT12_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT12_1 = 0x00001000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 13)
    ,DOUT13_MASK = 0x00002000
    ,DOUT13_POS = 13
    ,DOUT13_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT13_1 = 0x00002000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 14)
    ,DOUT14_MASK = 0x00004000
    ,DOUT14_POS = 14
    ,DOUT14_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT14_1 = 0x00004000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    // GPIOx Pin[N] Output Value Each of these bits controls the status of a GPIO pin when the GPIO pin is configured as Push-pull output, open-drain output or quasi-bidirectional mode. (bits: 15)
    ,DOUT15_MASK = 0x00008000
    ,DOUT15_POS = 15
    ,DOUT15_0 = 0x00000000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive Low if the GPIO pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT15_1 = 0x00008000 // GPIO port [A/B/C/D/E/F] Pin[n] will drive High if the GPIO pin is configured as Push-pull output or Quasi-bidirectional mode
    ,DOUT_MASK = 0x0000FFFF
    ;
  };
  // GPIO Port A Data Output Write Mask
  struct DMASK : reg<ip_ver, base + 0xC>
  {
    static constexpr typename DMASK::type
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 0)
     DMASK0_MASK = 0x00000001
    ,DMASK0_POS = 0
    ,DMASK0_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK0_1 = 0x00000001 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 1)
    ,DMASK1_MASK = 0x00000002
    ,DMASK1_POS = 1
    ,DMASK1_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK1_1 = 0x00000002 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 2)
    ,DMASK2_MASK = 0x00000004
    ,DMASK2_POS = 2
    ,DMASK2_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK2_1 = 0x00000004 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 3)
    ,DMASK3_MASK = 0x00000008
    ,DMASK3_POS = 3
    ,DMASK3_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK3_1 = 0x00000008 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 4)
    ,DMASK4_MASK = 0x00000010
    ,DMASK4_POS = 4
    ,DMASK4_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK4_1 = 0x00000010 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 5)
    ,DMASK5_MASK = 0x00000020
    ,DMASK5_POS = 5
    ,DMASK5_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK5_1 = 0x00000020 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 6)
    ,DMASK6_MASK = 0x00000040
    ,DMASK6_POS = 6
    ,DMASK6_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK6_1 = 0x00000040 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 7)
    ,DMASK7_MASK = 0x00000080
    ,DMASK7_POS = 7
    ,DMASK7_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK7_1 = 0x00000080 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 8)
    ,DMASK8_MASK = 0x00000100
    ,DMASK8_POS = 8
    ,DMASK8_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK8_1 = 0x00000100 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 9)
    ,DMASK9_MASK = 0x00000200
    ,DMASK9_POS = 9
    ,DMASK9_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK9_1 = 0x00000200 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 10)
    ,DMASK10_MASK = 0x00000400
    ,DMASK10_POS = 10
    ,DMASK10_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK10_1 = 0x00000400 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 11)
    ,DMASK11_MASK = 0x00000800
    ,DMASK11_POS = 11
    ,DMASK11_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK11_1 = 0x00000800 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 12)
    ,DMASK12_MASK = 0x00001000
    ,DMASK12_POS = 12
    ,DMASK12_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK12_1 = 0x00001000 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 13)
    ,DMASK13_MASK = 0x00002000
    ,DMASK13_POS = 13
    ,DMASK13_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK13_1 = 0x00002000 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 14)
    ,DMASK14_MASK = 0x00004000
    ,DMASK14_POS = 14
    ,DMASK14_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK14_1 = 0x00004000 // Corresponding GPIOx_DOUT[n] bit protected
    // Port [A/B/C/D/E/F] Data Output Write Mask These bits are used to protect the corresponding register of GPIOx_DOUT[n] bit. When the DMASK[n] bit is set to 1, the corresponding GPIOx_DOUT[n] bit is protected. If the write signal is masked, write data to the protect bit is ignored. (bits: 15)
    ,DMASK15_MASK = 0x00008000
    ,DMASK15_POS = 15
    ,DMASK15_0 = 0x00000000 // Corresponding GPIOx_DOUT[n] bit can be updated
    ,DMASK15_1 = 0x00008000 // Corresponding GPIOx_DOUT[n] bit protected
    ,DMASK_MASK = 0x0000FFFF
    ;
  };
  // GPIO Port A Pin Value
  struct PIN : reg<ip_ver, base + 0x10>
  {
    static constexpr typename PIN::type
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 0)
     PIN0_MASK = 0x00000001
    ,PIN0_POS = 0
    ,PIN0 = 0x00000001
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 1)
    ,PIN1_MASK = 0x00000002
    ,PIN1_POS = 1
    ,PIN1 = 0x00000002
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 2)
    ,PIN2_MASK = 0x00000004
    ,PIN2_POS = 2
    ,PIN2 = 0x00000004
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 3)
    ,PIN3_MASK = 0x00000008
    ,PIN3_POS = 3
    ,PIN3 = 0x00000008
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 4)
    ,PIN4_MASK = 0x00000010
    ,PIN4_POS = 4
    ,PIN4 = 0x00000010
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 5)
    ,PIN5_MASK = 0x00000020
    ,PIN5_POS = 5
    ,PIN5 = 0x00000020
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 6)
    ,PIN6_MASK = 0x00000040
    ,PIN6_POS = 6
    ,PIN6 = 0x00000040
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 7)
    ,PIN7_MASK = 0x00000080
    ,PIN7_POS = 7
    ,PIN7 = 0x00000080
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 8)
    ,PIN8_MASK = 0x00000100
    ,PIN8_POS = 8
    ,PIN8 = 0x00000100
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 9)
    ,PIN9_MASK = 0x00000200
    ,PIN9_POS = 9
    ,PIN9 = 0x00000200
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 10)
    ,PIN10_MASK = 0x00000400
    ,PIN10_POS = 10
    ,PIN10 = 0x00000400
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 11)
    ,PIN11_MASK = 0x00000800
    ,PIN11_POS = 11
    ,PIN11 = 0x00000800
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 12)
    ,PIN12_MASK = 0x00001000
    ,PIN12_POS = 12
    ,PIN12 = 0x00001000
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 13)
    ,PIN13_MASK = 0x00002000
    ,PIN13_POS = 13
    ,PIN13 = 0x00002000
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 14)
    ,PIN14_MASK = 0x00004000
    ,PIN14_POS = 14
    ,PIN14 = 0x00004000
    // Port [A/B/C/D/E/F] Pin Values Each bit of the register reflects the actual status of the respective GPIO pin. If the bit is 1, it indicates the corresponding pin status is high, else the pin status is low. Note: (bits: 15)
    ,PIN15_MASK = 0x00008000
    ,PIN15_POS = 15
    ,PIN15 = 0x00008000
    ,PIN_MASK = 0x0000FFFF
    ;
  };
  // GPIO Port A De-bounce Enable
  struct DBEN : reg<ip_ver, base + 0x14>
  {
    static constexpr typename DBEN::type
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 0)
     DBEN0_MASK = 0x00000001
    ,DBEN0_POS = 0
    ,DBEN0_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN0_1 = 0x00000001 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 1)
    ,DBEN1_MASK = 0x00000002
    ,DBEN1_POS = 1
    ,DBEN1_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN1_1 = 0x00000002 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 2)
    ,DBEN2_MASK = 0x00000004
    ,DBEN2_POS = 2
    ,DBEN2_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN2_1 = 0x00000004 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 3)
    ,DBEN3_MASK = 0x00000008
    ,DBEN3_POS = 3
    ,DBEN3_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN3_1 = 0x00000008 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 4)
    ,DBEN4_MASK = 0x00000010
    ,DBEN4_POS = 4
    ,DBEN4_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN4_1 = 0x00000010 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 5)
    ,DBEN5_MASK = 0x00000020
    ,DBEN5_POS = 5
    ,DBEN5_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN5_1 = 0x00000020 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 6)
    ,DBEN6_MASK = 0x00000040
    ,DBEN6_POS = 6
    ,DBEN6_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN6_1 = 0x00000040 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 7)
    ,DBEN7_MASK = 0x00000080
    ,DBEN7_POS = 7
    ,DBEN7_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN7_1 = 0x00000080 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 8)
    ,DBEN8_MASK = 0x00000100
    ,DBEN8_POS = 8
    ,DBEN8_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN8_1 = 0x00000100 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 9)
    ,DBEN9_MASK = 0x00000200
    ,DBEN9_POS = 9
    ,DBEN9_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN9_1 = 0x00000200 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 10)
    ,DBEN10_MASK = 0x00000400
    ,DBEN10_POS = 10
    ,DBEN10_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN10_1 = 0x00000400 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 11)
    ,DBEN11_MASK = 0x00000800
    ,DBEN11_POS = 11
    ,DBEN11_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN11_1 = 0x00000800 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 12)
    ,DBEN12_MASK = 0x00001000
    ,DBEN12_POS = 12
    ,DBEN12_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN12_1 = 0x00001000 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 13)
    ,DBEN13_MASK = 0x00002000
    ,DBEN13_POS = 13
    ,DBEN13_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN13_1 = 0x00002000 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 14)
    ,DBEN14_MASK = 0x00004000
    ,DBEN14_POS = 14
    ,DBEN14_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN14_1 = 0x00004000 // Bit[n] de-bounce function Enabled
    // Port [A/B/C/D/E/F] Input Signal De-Bounce Enable Control DBEN[n] is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBNCECON[4], one de-bounce sample cycle period is controlled by DBNCECON[3:0]. (bits: 15)
    ,DBEN15_MASK = 0x00008000
    ,DBEN15_POS = 15
    ,DBEN15_0 = 0x00000000 // Bit[n] de-bounce function Disabled
    ,DBEN15_1 = 0x00008000 // Bit[n] de-bounce function Enabled
    ,DBEN_MASK = 0x0000FFFF
    ;
  };
  // GPIO Port A Interrupt Mode Control
  struct IMD : reg<ip_ver, base + 0x18>
  {
    static constexpr typename IMD::type
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 0)
     IMD0_MASK = 0x00000001
    ,IMD0_POS = 0
    ,IMD0_0 = 0x00000000 // Edge trigger interrupt
    ,IMD0_1 = 0x00000001 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 1)
    ,IMD1_MASK = 0x00000002
    ,IMD1_POS = 1
    ,IMD1_0 = 0x00000000 // Edge trigger interrupt
    ,IMD1_1 = 0x00000002 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 2)
    ,IMD2_MASK = 0x00000004
    ,IMD2_POS = 2
    ,IMD2_0 = 0x00000000 // Edge trigger interrupt
    ,IMD2_1 = 0x00000004 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 3)
    ,IMD3_MASK = 0x00000008
    ,IMD3_POS = 3
    ,IMD3_0 = 0x00000000 // Edge trigger interrupt
    ,IMD3_1 = 0x00000008 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 4)
    ,IMD4_MASK = 0x00000010
    ,IMD4_POS = 4
    ,IMD4_0 = 0x00000000 // Edge trigger interrupt
    ,IMD4_1 = 0x00000010 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 5)
    ,IMD5_MASK = 0x00000020
    ,IMD5_POS = 5
    ,IMD5_0 = 0x00000000 // Edge trigger interrupt
    ,IMD5_1 = 0x00000020 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 6)
    ,IMD6_MASK = 0x00000040
    ,IMD6_POS = 6
    ,IMD6_0 = 0x00000000 // Edge trigger interrupt
    ,IMD6_1 = 0x00000040 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 7)
    ,IMD7_MASK = 0x00000080
    ,IMD7_POS = 7
    ,IMD7_0 = 0x00000000 // Edge trigger interrupt
    ,IMD7_1 = 0x00000080 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 8)
    ,IMD8_MASK = 0x00000100
    ,IMD8_POS = 8
    ,IMD8_0 = 0x00000000 // Edge trigger interrupt
    ,IMD8_1 = 0x00000100 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 9)
    ,IMD9_MASK = 0x00000200
    ,IMD9_POS = 9
    ,IMD9_0 = 0x00000000 // Edge trigger interrupt
    ,IMD9_1 = 0x00000200 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 10)
    ,IMD10_MASK = 0x00000400
    ,IMD10_POS = 10
    ,IMD10_0 = 0x00000000 // Edge trigger interrupt
    ,IMD10_1 = 0x00000400 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 11)
    ,IMD11_MASK = 0x00000800
    ,IMD11_POS = 11
    ,IMD11_0 = 0x00000000 // Edge trigger interrupt
    ,IMD11_1 = 0x00000800 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 12)
    ,IMD12_MASK = 0x00001000
    ,IMD12_POS = 12
    ,IMD12_0 = 0x00000000 // Edge trigger interrupt
    ,IMD12_1 = 0x00001000 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 13)
    ,IMD13_MASK = 0x00002000
    ,IMD13_POS = 13
    ,IMD13_0 = 0x00000000 // Edge trigger interrupt
    ,IMD13_1 = 0x00002000 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 14)
    ,IMD14_MASK = 0x00004000
    ,IMD14_POS = 14
    ,IMD14_0 = 0x00000000 // Edge trigger interrupt
    ,IMD14_1 = 0x00004000 // Level trigger interrupt
    // Port [A/B/C/D/E/F] Edge Or Level Detection Interrupt Control IMD[n] is used to control the interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 15)
    ,IMD15_MASK = 0x00008000
    ,IMD15_POS = 15
    ,IMD15_0 = 0x00000000 // Edge trigger interrupt
    ,IMD15_1 = 0x00008000 // Level trigger interrupt
    ,IMD_MASK = 0x0000FFFF
    ;
  };
  // GPIO Port A Interrupt Enable
  struct IEN : reg<ip_ver, base + 0x1C>
  {
    static constexpr typename IEN::type
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 0)
     IF_EN0_MASK = 0x00000001
    ,IF_EN0_POS = 0
    ,IF_EN0_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN0_1 = 0x00000001 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 1)
    ,IF_EN1_MASK = 0x00000002
    ,IF_EN1_POS = 1
    ,IF_EN1_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN1_1 = 0x00000002 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 2)
    ,IF_EN2_MASK = 0x00000004
    ,IF_EN2_POS = 2
    ,IF_EN2_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN2_1 = 0x00000004 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 3)
    ,IF_EN3_MASK = 0x00000008
    ,IF_EN3_POS = 3
    ,IF_EN3_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN3_1 = 0x00000008 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 4)
    ,IF_EN4_MASK = 0x00000010
    ,IF_EN4_POS = 4
    ,IF_EN4_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN4_1 = 0x00000010 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 5)
    ,IF_EN5_MASK = 0x00000020
    ,IF_EN5_POS = 5
    ,IF_EN5_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN5_1 = 0x00000020 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 6)
    ,IF_EN6_MASK = 0x00000040
    ,IF_EN6_POS = 6
    ,IF_EN6_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN6_1 = 0x00000040 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 7)
    ,IF_EN7_MASK = 0x00000080
    ,IF_EN7_POS = 7
    ,IF_EN7_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN7_1 = 0x00000080 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 8)
    ,IF_EN8_MASK = 0x00000100
    ,IF_EN8_POS = 8
    ,IF_EN8_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN8_1 = 0x00000100 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 9)
    ,IF_EN9_MASK = 0x00000200
    ,IF_EN9_POS = 9
    ,IF_EN9_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN9_1 = 0x00000200 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 10)
    ,IF_EN10_MASK = 0x00000400
    ,IF_EN10_POS = 10
    ,IF_EN10_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN10_1 = 0x00000400 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 11)
    ,IF_EN11_MASK = 0x00000800
    ,IF_EN11_POS = 11
    ,IF_EN11_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN11_1 = 0x00000800 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 12)
    ,IF_EN12_MASK = 0x00001000
    ,IF_EN12_POS = 12
    ,IF_EN12_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN12_1 = 0x00001000 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 13)
    ,IF_EN13_MASK = 0x00002000
    ,IF_EN13_POS = 13
    ,IF_EN13_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN13_1 = 0x00002000 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 14)
    ,IF_EN14_MASK = 0x00004000
    ,IF_EN14_POS = 14
    ,IF_EN14_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN14_1 = 0x00004000 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Falling Edge Or Input Level Low IF_EN[n] is used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IF_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <low> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <high-to-low> will generate the interrupt. (bits: 15)
    ,IF_EN15_MASK = 0x00008000
    ,IF_EN15_POS = 15
    ,IF_EN15_0 = 0x00000000 // PIN[n] state low-level or high-to-low change interrupt Disabled
    ,IF_EN15_1 = 0x00008000 // PIN[n] state low-level or high-to-low change interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 16)
    ,IR_EN0_MASK = 0x00010000
    ,IR_EN0_POS = 16
    ,IR_EN0_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN0_1 = 0x00010000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 17)
    ,IR_EN1_MASK = 0x00020000
    ,IR_EN1_POS = 17
    ,IR_EN1_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN1_1 = 0x00020000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 18)
    ,IR_EN2_MASK = 0x00040000
    ,IR_EN2_POS = 18
    ,IR_EN2_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN2_1 = 0x00040000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 19)
    ,IR_EN3_MASK = 0x00080000
    ,IR_EN3_POS = 19
    ,IR_EN3_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN3_1 = 0x00080000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 20)
    ,IR_EN4_MASK = 0x00100000
    ,IR_EN4_POS = 20
    ,IR_EN4_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN4_1 = 0x00100000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 21)
    ,IR_EN5_MASK = 0x00200000
    ,IR_EN5_POS = 21
    ,IR_EN5_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN5_1 = 0x00200000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 22)
    ,IR_EN6_MASK = 0x00400000
    ,IR_EN6_POS = 22
    ,IR_EN6_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN6_1 = 0x00400000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 23)
    ,IR_EN7_MASK = 0x00800000
    ,IR_EN7_POS = 23
    ,IR_EN7_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN7_1 = 0x00800000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 24)
    ,IR_EN8_MASK = 0x01000000
    ,IR_EN8_POS = 24
    ,IR_EN8_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN8_1 = 0x01000000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 25)
    ,IR_EN9_MASK = 0x02000000
    ,IR_EN9_POS = 25
    ,IR_EN9_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN9_1 = 0x02000000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 26)
    ,IR_EN10_MASK = 0x04000000
    ,IR_EN10_POS = 26
    ,IR_EN10_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN10_1 = 0x04000000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 27)
    ,IR_EN11_MASK = 0x08000000
    ,IR_EN11_POS = 27
    ,IR_EN11_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN11_1 = 0x08000000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 28)
    ,IR_EN12_MASK = 0x10000000
    ,IR_EN12_POS = 28
    ,IR_EN12_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN12_1 = 0x10000000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 29)
    ,IR_EN13_MASK = 0x20000000
    ,IR_EN13_POS = 29
    ,IR_EN13_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN13_1 = 0x20000000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 30)
    ,IR_EN14_MASK = 0x40000000
    ,IR_EN14_POS = 30
    ,IR_EN14_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN14_1 = 0x40000000 // PIN[n] level-high or low-to-high interrupt Enabled
    // Port [A/B/C/D/E/F] Interrupt Enabled By Input Rising Edge Or Input Level High IR_EN[n] used to enable the interrupt for each of the corresponding input GPIO_PIN[n]. Set bit to 1 also enable the pin wake-up function. When setting the IR_EN[n] bit to 1: If the interrupt is level trigger, the input PIN[n] state at level <high> will generate the interrupt. If the interrupt is edge trigger, the input PIN[n] state change from <low-to-high> will generate the interrupt. (bits: 31)
    ,IR_EN15_MASK = 0x80000000
    ,IR_EN15_POS = 31
    ,IR_EN15_0 = 0x00000000 // PIN[n] level-high or low-to-high interrupt Disabled
    ,IR_EN15_1 = 0x80000000 // PIN[n] level-high or low-to-high interrupt Enabled
    ,IEN_MASK = 0xFFFFFFFF
    ;
  };
  // GPIO Port A Interrupt Source Flag
  struct ISRC : reg<ip_ver, base + 0x20>
  {
    static constexpr typename ISRC::type
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 0)
     ISRC0_MASK = 0x00000001
    ,ISRC0_POS = 0
    ,ISRC0_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC0_1 = 0x00000001 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 1)
    ,ISRC1_MASK = 0x00000002
    ,ISRC1_POS = 1
    ,ISRC1_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC1_1 = 0x00000002 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 2)
    ,ISRC2_MASK = 0x00000004
    ,ISRC2_POS = 2
    ,ISRC2_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC2_1 = 0x00000004 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 3)
    ,ISRC3_MASK = 0x00000008
    ,ISRC3_POS = 3
    ,ISRC3_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC3_1 = 0x00000008 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 4)
    ,ISRC4_MASK = 0x00000010
    ,ISRC4_POS = 4
    ,ISRC4_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC4_1 = 0x00000010 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 5)
    ,ISRC5_MASK = 0x00000020
    ,ISRC5_POS = 5
    ,ISRC5_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC5_1 = 0x00000020 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 6)
    ,ISRC6_MASK = 0x00000040
    ,ISRC6_POS = 6
    ,ISRC6_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC6_1 = 0x00000040 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 7)
    ,ISRC7_MASK = 0x00000080
    ,ISRC7_POS = 7
    ,ISRC7_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC7_1 = 0x00000080 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 8)
    ,ISRC8_MASK = 0x00000100
    ,ISRC8_POS = 8
    ,ISRC8_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC8_1 = 0x00000100 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 9)
    ,ISRC9_MASK = 0x00000200
    ,ISRC9_POS = 9
    ,ISRC9_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC9_1 = 0x00000200 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 10)
    ,ISRC10_MASK = 0x00000400
    ,ISRC10_POS = 10
    ,ISRC10_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC10_1 = 0x00000400 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 11)
    ,ISRC11_MASK = 0x00000800
    ,ISRC11_POS = 11
    ,ISRC11_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC11_1 = 0x00000800 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 12)
    ,ISRC12_MASK = 0x00001000
    ,ISRC12_POS = 12
    ,ISRC12_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC12_1 = 0x00001000 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 13)
    ,ISRC13_MASK = 0x00002000
    ,ISRC13_POS = 13
    ,ISRC13_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC13_1 = 0x00002000 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 14)
    ,ISRC14_MASK = 0x00004000
    ,ISRC14_POS = 14
    ,ISRC14_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC14_1 = 0x00004000 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    // Port [A/B/C/D/E/F] Interrupt Source Flag Read : (bits: 15)
    ,ISRC15_MASK = 0x00008000
    ,ISRC15_POS = 15
    ,ISRC15_0 = 0x00000000 // No interrupt at GPIOx[n]. No action
    ,ISRC15_1 = 0x00008000 // GPIOx[n] generates an interrupt. Clear the corresponding pending interrupt
    ,ISRC_MASK = 0x0000FFFF
    ;
  };
}; // struct GPIO

} // namespace lmcu::device::ip::v1

