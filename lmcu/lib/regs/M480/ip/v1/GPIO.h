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

  // PA I/O Mode Control
  struct MODE : reg<ip_ver, base + 0x0>
  {
    static constexpr typename MODE::type
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 1-0)
     MODE0_MASK = 0x00000003
    ,MODE0_POS = 0
    ,MODE0_0 = 0x00000000 // Px.n is in Input mode
    ,MODE0_1 = 0x00000001 // Px.n is in Push-pull Output mode
    ,MODE0_2 = 0x00000002 // Px.n is in Open-drain Output mode
    ,MODE0_3 = 0x00000003 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 3-2)
    ,MODE1_MASK = 0x0000000C
    ,MODE1_POS = 2
    ,MODE1_0 = 0x00000000 // Px.n is in Input mode
    ,MODE1_1 = 0x00000004 // Px.n is in Push-pull Output mode
    ,MODE1_2 = 0x00000008 // Px.n is in Open-drain Output mode
    ,MODE1_3 = 0x0000000C // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 5-4)
    ,MODE2_MASK = 0x00000030
    ,MODE2_POS = 4
    ,MODE2_0 = 0x00000000 // Px.n is in Input mode
    ,MODE2_1 = 0x00000010 // Px.n is in Push-pull Output mode
    ,MODE2_2 = 0x00000020 // Px.n is in Open-drain Output mode
    ,MODE2_3 = 0x00000030 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 7-6)
    ,MODE3_MASK = 0x000000C0
    ,MODE3_POS = 6
    ,MODE3_0 = 0x00000000 // Px.n is in Input mode
    ,MODE3_1 = 0x00000040 // Px.n is in Push-pull Output mode
    ,MODE3_2 = 0x00000080 // Px.n is in Open-drain Output mode
    ,MODE3_3 = 0x000000C0 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 3-2)
    ,MODE4_MASK = 0x0000000C
    ,MODE4_POS = 2
    ,MODE4_0 = 0x00000000 // Px.n is in Input mode
    ,MODE4_1 = 0x00000004 // Px.n is in Push-pull Output mode
    ,MODE4_2 = 0x00000008 // Px.n is in Open-drain Output mode
    ,MODE4_3 = 0x0000000C // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 11-10)
    ,MODE5_MASK = 0x00000C00
    ,MODE5_POS = 10
    ,MODE5_0 = 0x00000000 // Px.n is in Input mode
    ,MODE5_1 = 0x00000400 // Px.n is in Push-pull Output mode
    ,MODE5_2 = 0x00000800 // Px.n is in Open-drain Output mode
    ,MODE5_3 = 0x00000C00 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 13-12)
    ,MODE6_MASK = 0x00003000
    ,MODE6_POS = 12
    ,MODE6_0 = 0x00000000 // Px.n is in Input mode
    ,MODE6_1 = 0x00001000 // Px.n is in Push-pull Output mode
    ,MODE6_2 = 0x00002000 // Px.n is in Open-drain Output mode
    ,MODE6_3 = 0x00003000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 15-14)
    ,MODE7_MASK = 0x0000C000
    ,MODE7_POS = 14
    ,MODE7_0 = 0x00000000 // Px.n is in Input mode
    ,MODE7_1 = 0x00004000 // Px.n is in Push-pull Output mode
    ,MODE7_2 = 0x00008000 // Px.n is in Open-drain Output mode
    ,MODE7_3 = 0x0000C000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 9-8)
    ,MODE8_MASK = 0x00000300
    ,MODE8_POS = 8
    ,MODE8_0 = 0x00000000 // Px.n is in Input mode
    ,MODE8_1 = 0x00000100 // Px.n is in Push-pull Output mode
    ,MODE8_2 = 0x00000200 // Px.n is in Open-drain Output mode
    ,MODE8_3 = 0x00000300 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 19-18)
    ,MODE9_MASK = 0x000C0000
    ,MODE9_POS = 18
    ,MODE9_0 = 0x00000000 // Px.n is in Input mode
    ,MODE9_1 = 0x00040000 // Px.n is in Push-pull Output mode
    ,MODE9_2 = 0x00080000 // Px.n is in Open-drain Output mode
    ,MODE9_3 = 0x000C0000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 21-20)
    ,MODE10_MASK = 0x00300000
    ,MODE10_POS = 20
    ,MODE10_0 = 0x00000000 // Px.n is in Input mode
    ,MODE10_1 = 0x00100000 // Px.n is in Push-pull Output mode
    ,MODE10_2 = 0x00200000 // Px.n is in Open-drain Output mode
    ,MODE10_3 = 0x00300000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 23-22)
    ,MODE11_MASK = 0x00C00000
    ,MODE11_POS = 22
    ,MODE11_0 = 0x00000000 // Px.n is in Input mode
    ,MODE11_1 = 0x00400000 // Px.n is in Push-pull Output mode
    ,MODE11_2 = 0x00800000 // Px.n is in Open-drain Output mode
    ,MODE11_3 = 0x00C00000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 25-24)
    ,MODE12_MASK = 0x03000000
    ,MODE12_POS = 24
    ,MODE12_0 = 0x00000000 // Px.n is in Input mode
    ,MODE12_1 = 0x01000000 // Px.n is in Push-pull Output mode
    ,MODE12_2 = 0x02000000 // Px.n is in Open-drain Output mode
    ,MODE12_3 = 0x03000000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 27-26)
    ,MODE13_MASK = 0x0C000000
    ,MODE13_POS = 26
    ,MODE13_0 = 0x00000000 // Px.n is in Input mode
    ,MODE13_1 = 0x04000000 // Px.n is in Push-pull Output mode
    ,MODE13_2 = 0x08000000 // Px.n is in Open-drain Output mode
    ,MODE13_3 = 0x0C000000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 29-28)
    ,MODE14_MASK = 0x30000000
    ,MODE14_POS = 28
    ,MODE14_0 = 0x00000000 // Px.n is in Input mode
    ,MODE14_1 = 0x10000000 // Px.n is in Push-pull Output mode
    ,MODE14_2 = 0x20000000 // Px.n is in Open-drain Output mode
    ,MODE14_3 = 0x30000000 // Px.n is in Quasi-bidirectional mode
    // Port A-H I/O Pin[n] Mode Control Determine each I/O mode of Px.n pins. (bits: 31-30)
    ,MODE15_MASK = 0xC0000000
    ,MODE15_POS = 30
    ,MODE15_0 = 0x00000000 // Px.n is in Input mode
    ,MODE15_1 = 0x40000000 // Px.n is in Push-pull Output mode
    ,MODE15_2 = 0x80000000 // Px.n is in Open-drain Output mode
    ,MODE15_3 = 0xC0000000 // Px.n is in Quasi-bidirectional mode
    ,MODE_MASK = 0xFFFCFFFF
    ;
  };
  // PA Digital Input Path Disable Control
  struct DINOFF : reg<ip_ver, base + 0x4>
  {
    static constexpr typename DINOFF::type
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 16)
     DINOFF0_MASK = 0x00010000
    ,DINOFF0_POS = 16
    ,DINOFF0_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF0_1 = 0x00010000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 17)
    ,DINOFF1_MASK = 0x00020000
    ,DINOFF1_POS = 17
    ,DINOFF1_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF1_1 = 0x00020000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 18)
    ,DINOFF2_MASK = 0x00040000
    ,DINOFF2_POS = 18
    ,DINOFF2_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF2_1 = 0x00040000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 19)
    ,DINOFF3_MASK = 0x00080000
    ,DINOFF3_POS = 19
    ,DINOFF3_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF3_1 = 0x00080000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 20)
    ,DINOFF4_MASK = 0x00100000
    ,DINOFF4_POS = 20
    ,DINOFF4_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF4_1 = 0x00100000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 21)
    ,DINOFF5_MASK = 0x00200000
    ,DINOFF5_POS = 21
    ,DINOFF5_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF5_1 = 0x00200000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 22)
    ,DINOFF6_MASK = 0x00400000
    ,DINOFF6_POS = 22
    ,DINOFF6_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF6_1 = 0x00400000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 23)
    ,DINOFF7_MASK = 0x00800000
    ,DINOFF7_POS = 23
    ,DINOFF7_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF7_1 = 0x00800000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 24)
    ,DINOFF8_MASK = 0x01000000
    ,DINOFF8_POS = 24
    ,DINOFF8_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF8_1 = 0x01000000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 25)
    ,DINOFF9_MASK = 0x02000000
    ,DINOFF9_POS = 25
    ,DINOFF9_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF9_1 = 0x02000000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 26)
    ,DINOFF10_MASK = 0x04000000
    ,DINOFF10_POS = 26
    ,DINOFF10_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF10_1 = 0x04000000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 27)
    ,DINOFF11_MASK = 0x08000000
    ,DINOFF11_POS = 27
    ,DINOFF11_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF11_1 = 0x08000000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 28)
    ,DINOFF12_MASK = 0x10000000
    ,DINOFF12_POS = 28
    ,DINOFF12_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF12_1 = 0x10000000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 29)
    ,DINOFF13_MASK = 0x20000000
    ,DINOFF13_POS = 29
    ,DINOFF13_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF13_1 = 0x20000000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 30)
    ,DINOFF14_MASK = 0x40000000
    ,DINOFF14_POS = 30
    ,DINOFF14_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF14_1 = 0x40000000 // Px.n digital input path Disabled (digital input tied to low)
    // Port A-H Pin[n] Digital Input Path Disable Bit Each of these bits is used to control if the digital input path of corresponding Px.n pin is disabled. If input is analog signal, users can disable Px.n digital input path to avoid input current leakage. (bits: 31)
    ,DINOFF15_MASK = 0x80000000
    ,DINOFF15_POS = 31
    ,DINOFF15_0 = 0x00000000 // Px.n digital input path Enabled
    ,DINOFF15_1 = 0x80000000 // Px.n digital input path Disabled (digital input tied to low)
    ,DINOFF_MASK = 0xFFFF0000
    ;
  };
  // PA Data Output Value
  struct DOUT : reg<ip_ver, base + 0x8, 0x0000FFFF>
  {
    static constexpr typename DOUT::type
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 0)
     DOUT0_MASK = 0x00000001
    ,DOUT0_POS = 0
    ,DOUT0_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT0_1 = 0x00000001 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 1)
    ,DOUT1_MASK = 0x00000002
    ,DOUT1_POS = 1
    ,DOUT1_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT1_1 = 0x00000002 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 2)
    ,DOUT2_MASK = 0x00000004
    ,DOUT2_POS = 2
    ,DOUT2_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT2_1 = 0x00000004 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 3)
    ,DOUT3_MASK = 0x00000008
    ,DOUT3_POS = 3
    ,DOUT3_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT3_1 = 0x00000008 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 4)
    ,DOUT4_MASK = 0x00000010
    ,DOUT4_POS = 4
    ,DOUT4_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT4_1 = 0x00000010 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 5)
    ,DOUT5_MASK = 0x00000020
    ,DOUT5_POS = 5
    ,DOUT5_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT5_1 = 0x00000020 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 6)
    ,DOUT6_MASK = 0x00000040
    ,DOUT6_POS = 6
    ,DOUT6_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT6_1 = 0x00000040 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 7)
    ,DOUT7_MASK = 0x00000080
    ,DOUT7_POS = 7
    ,DOUT7_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT7_1 = 0x00000080 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 8)
    ,DOUT8_MASK = 0x00000100
    ,DOUT8_POS = 8
    ,DOUT8_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT8_1 = 0x00000100 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 9)
    ,DOUT9_MASK = 0x00000200
    ,DOUT9_POS = 9
    ,DOUT9_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT9_1 = 0x00000200 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 10)
    ,DOUT10_MASK = 0x00000400
    ,DOUT10_POS = 10
    ,DOUT10_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT10_1 = 0x00000400 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 11)
    ,DOUT11_MASK = 0x00000800
    ,DOUT11_POS = 11
    ,DOUT11_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT11_1 = 0x00000800 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 12)
    ,DOUT12_MASK = 0x00001000
    ,DOUT12_POS = 12
    ,DOUT12_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT12_1 = 0x00001000 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 13)
    ,DOUT13_MASK = 0x00002000
    ,DOUT13_POS = 13
    ,DOUT13_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT13_1 = 0x00002000 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 14)
    ,DOUT14_MASK = 0x00004000
    ,DOUT14_POS = 14
    ,DOUT14_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT14_1 = 0x00004000 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    // Port A-H Pin[n] Output Value Each of these bits controls the status of a Px.n pin when the Px.n is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode. (bits: 15)
    ,DOUT15_MASK = 0x00008000
    ,DOUT15_POS = 15
    ,DOUT15_0 = 0x00000000 // Px.n will drive Low if the Px.n pin is configured as Push-pull output, Open-drain output or Quasi-bidirectional mode
    ,DOUT15_1 = 0x00008000 // Px.n will drive High if the Px.n pin is configured as Push-pull output or Quasi-bidirectional mode
    ,DOUT_MASK = 0x0000FFFF
    ;
  };
  // PA Data Output Write Mask
  struct DATMSK : reg<ip_ver, base + 0xC>
  {
    static constexpr typename DATMSK::type
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 0)
     DATMSK0_MASK = 0x00000001
    ,DATMSK0_POS = 0
    ,DATMSK0_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK0_1 = 0x00000001 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 1)
    ,DATMSK1_MASK = 0x00000002
    ,DATMSK1_POS = 1
    ,DATMSK1_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK1_1 = 0x00000002 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 2)
    ,DATMSK2_MASK = 0x00000004
    ,DATMSK2_POS = 2
    ,DATMSK2_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK2_1 = 0x00000004 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 3)
    ,DATMSK3_MASK = 0x00000008
    ,DATMSK3_POS = 3
    ,DATMSK3_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK3_1 = 0x00000008 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 4)
    ,DATMSK4_MASK = 0x00000010
    ,DATMSK4_POS = 4
    ,DATMSK4_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK4_1 = 0x00000010 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 5)
    ,DATMSK5_MASK = 0x00000020
    ,DATMSK5_POS = 5
    ,DATMSK5_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK5_1 = 0x00000020 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 6)
    ,DATMSK6_MASK = 0x00000040
    ,DATMSK6_POS = 6
    ,DATMSK6_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK6_1 = 0x00000040 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 7)
    ,DATMSK7_MASK = 0x00000080
    ,DATMSK7_POS = 7
    ,DATMSK7_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK7_1 = 0x00000080 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 8)
    ,DATMSK8_MASK = 0x00000100
    ,DATMSK8_POS = 8
    ,DATMSK8_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK8_1 = 0x00000100 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 9)
    ,DATMSK9_MASK = 0x00000200
    ,DATMSK9_POS = 9
    ,DATMSK9_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK9_1 = 0x00000200 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 10)
    ,DATMSK10_MASK = 0x00000400
    ,DATMSK10_POS = 10
    ,DATMSK10_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK10_1 = 0x00000400 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 11)
    ,DATMSK11_MASK = 0x00000800
    ,DATMSK11_POS = 11
    ,DATMSK11_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK11_1 = 0x00000800 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 12)
    ,DATMSK12_MASK = 0x00001000
    ,DATMSK12_POS = 12
    ,DATMSK12_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK12_1 = 0x00001000 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 13)
    ,DATMSK13_MASK = 0x00002000
    ,DATMSK13_POS = 13
    ,DATMSK13_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK13_1 = 0x00002000 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 14)
    ,DATMSK14_MASK = 0x00004000
    ,DATMSK14_POS = 14
    ,DATMSK14_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK14_1 = 0x00004000 // Corresponding DOUT (Px_DOUT[n]) bit protected
    // Port A-H Pin[n] Data Output Write Mask These bits are used to protect the corresponding DOUT (Px_DOUT[n]) bit. When the DATMSK (Px_DATMSK[n]) bit is set to 1, the corresponding DOUT (Px_DOUT[n]) bit is protected. If the write signal is masked, writing data to the protect bit is ignored. (bits: 15)
    ,DATMSK15_MASK = 0x00008000
    ,DATMSK15_POS = 15
    ,DATMSK15_0 = 0x00000000 // Corresponding DOUT (Px_DOUT[n]) bit can be updated
    ,DATMSK15_1 = 0x00008000 // Corresponding DOUT (Px_DOUT[n]) bit protected
    ,DATMSK_MASK = 0x0000FFFF
    ;
  };
  // PA Pin Value
  struct PIN : reg<ip_ver, base + 0x10>
  {
    static constexpr typename PIN::type
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 0)
     PIN0_MASK = 0x00000001
    ,PIN0_POS = 0
    ,PIN0 = 0x00000001
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 1)
    ,PIN1_MASK = 0x00000002
    ,PIN1_POS = 1
    ,PIN1 = 0x00000002
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 2)
    ,PIN2_MASK = 0x00000004
    ,PIN2_POS = 2
    ,PIN2 = 0x00000004
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 3)
    ,PIN3_MASK = 0x00000008
    ,PIN3_POS = 3
    ,PIN3 = 0x00000008
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 4)
    ,PIN4_MASK = 0x00000010
    ,PIN4_POS = 4
    ,PIN4 = 0x00000010
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 5)
    ,PIN5_MASK = 0x00000020
    ,PIN5_POS = 5
    ,PIN5 = 0x00000020
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 6)
    ,PIN6_MASK = 0x00000040
    ,PIN6_POS = 6
    ,PIN6 = 0x00000040
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 7)
    ,PIN7_MASK = 0x00000080
    ,PIN7_POS = 7
    ,PIN7 = 0x00000080
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 8)
    ,PIN8_MASK = 0x00000100
    ,PIN8_POS = 8
    ,PIN8 = 0x00000100
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 9)
    ,PIN9_MASK = 0x00000200
    ,PIN9_POS = 9
    ,PIN9 = 0x00000200
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 10)
    ,PIN10_MASK = 0x00000400
    ,PIN10_POS = 10
    ,PIN10 = 0x00000400
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 11)
    ,PIN11_MASK = 0x00000800
    ,PIN11_POS = 11
    ,PIN11 = 0x00000800
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 12)
    ,PIN12_MASK = 0x00001000
    ,PIN12_POS = 12
    ,PIN12 = 0x00001000
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 13)
    ,PIN13_MASK = 0x00002000
    ,PIN13_POS = 13
    ,PIN13 = 0x00002000
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 14)
    ,PIN14_MASK = 0x00004000
    ,PIN14_POS = 14
    ,PIN14 = 0x00004000
    // Port A-H Pin[n] Pin Value Each bit of the register reflects the actual status of the respective Px.n pin. If the bit is 1, it indicates the corresponding pin status is high; else the pin status is low. Note: (bits: 15)
    ,PIN15_MASK = 0x00008000
    ,PIN15_POS = 15
    ,PIN15 = 0x00008000
    ,PIN_MASK = 0x0000FFFF
    ;
  };
  // PA De-bounce Enable Control Register
  struct DBEN : reg<ip_ver, base + 0x14>
  {
    static constexpr typename DBEN::type
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 0)
     DBEN0_MASK = 0x00000001
    ,DBEN0_POS = 0
    ,DBEN0_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN0_1 = 0x00000001 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 1)
    ,DBEN1_MASK = 0x00000002
    ,DBEN1_POS = 1
    ,DBEN1_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN1_1 = 0x00000002 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 2)
    ,DBEN2_MASK = 0x00000004
    ,DBEN2_POS = 2
    ,DBEN2_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN2_1 = 0x00000004 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 3)
    ,DBEN3_MASK = 0x00000008
    ,DBEN3_POS = 3
    ,DBEN3_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN3_1 = 0x00000008 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 4)
    ,DBEN4_MASK = 0x00000010
    ,DBEN4_POS = 4
    ,DBEN4_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN4_1 = 0x00000010 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 5)
    ,DBEN5_MASK = 0x00000020
    ,DBEN5_POS = 5
    ,DBEN5_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN5_1 = 0x00000020 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 6)
    ,DBEN6_MASK = 0x00000040
    ,DBEN6_POS = 6
    ,DBEN6_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN6_1 = 0x00000040 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 7)
    ,DBEN7_MASK = 0x00000080
    ,DBEN7_POS = 7
    ,DBEN7_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN7_1 = 0x00000080 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 8)
    ,DBEN8_MASK = 0x00000100
    ,DBEN8_POS = 8
    ,DBEN8_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN8_1 = 0x00000100 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 9)
    ,DBEN9_MASK = 0x00000200
    ,DBEN9_POS = 9
    ,DBEN9_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN9_1 = 0x00000200 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 10)
    ,DBEN10_MASK = 0x00000400
    ,DBEN10_POS = 10
    ,DBEN10_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN10_1 = 0x00000400 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 11)
    ,DBEN11_MASK = 0x00000800
    ,DBEN11_POS = 11
    ,DBEN11_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN11_1 = 0x00000800 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 12)
    ,DBEN12_MASK = 0x00001000
    ,DBEN12_POS = 12
    ,DBEN12_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN12_1 = 0x00001000 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 13)
    ,DBEN13_MASK = 0x00002000
    ,DBEN13_POS = 13
    ,DBEN13_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN13_1 = 0x00002000 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 14)
    ,DBEN14_MASK = 0x00004000
    ,DBEN14_POS = 14
    ,DBEN14_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN14_1 = 0x00004000 // Px.n de-bounce function Enabled
    // Port A-H Pin[n] Input Signal De-bounce Enable Bit The DBEN[n] bit is used to enable the de-bounce function for each corresponding bit. If the input signal pulse width cannot be sampled by continuous two de-bounce sample cycle, the input signal transition is seen as the signal bounce and will not trigger the interrupt. The de-bounce clock source is controlled by DBCLKSRC (GPIO_DBCTL [4]), one de-bounce sample cycle period is controlled by DBCLKSEL (GPIO_DBCTL [3:0]). (bits: 15)
    ,DBEN15_MASK = 0x00008000
    ,DBEN15_POS = 15
    ,DBEN15_0 = 0x00000000 // Px.n de-bounce function Disabled
    ,DBEN15_1 = 0x00008000 // Px.n de-bounce function Enabled
    ,DBEN_MASK = 0x0000FFFF
    ;
  };
  // PA Interrupt Trigger Type Control
  struct INTTYPE : reg<ip_ver, base + 0x18>
  {
    static constexpr typename INTTYPE::type
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 0)
     TYPE0_MASK = 0x00000001
    ,TYPE0_POS = 0
    ,TYPE0_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE0_1 = 0x00000001 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 1)
    ,TYPE1_MASK = 0x00000002
    ,TYPE1_POS = 1
    ,TYPE1_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE1_1 = 0x00000002 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 2)
    ,TYPE2_MASK = 0x00000004
    ,TYPE2_POS = 2
    ,TYPE2_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE2_1 = 0x00000004 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 3)
    ,TYPE3_MASK = 0x00000008
    ,TYPE3_POS = 3
    ,TYPE3_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE3_1 = 0x00000008 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 4)
    ,TYPE4_MASK = 0x00000010
    ,TYPE4_POS = 4
    ,TYPE4_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE4_1 = 0x00000010 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 5)
    ,TYPE5_MASK = 0x00000020
    ,TYPE5_POS = 5
    ,TYPE5_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE5_1 = 0x00000020 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 6)
    ,TYPE6_MASK = 0x00000040
    ,TYPE6_POS = 6
    ,TYPE6_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE6_1 = 0x00000040 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 7)
    ,TYPE7_MASK = 0x00000080
    ,TYPE7_POS = 7
    ,TYPE7_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE7_1 = 0x00000080 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 8)
    ,TYPE8_MASK = 0x00000100
    ,TYPE8_POS = 8
    ,TYPE8_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE8_1 = 0x00000100 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 9)
    ,TYPE9_MASK = 0x00000200
    ,TYPE9_POS = 9
    ,TYPE9_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE9_1 = 0x00000200 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 10)
    ,TYPE10_MASK = 0x00000400
    ,TYPE10_POS = 10
    ,TYPE10_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE10_1 = 0x00000400 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 11)
    ,TYPE11_MASK = 0x00000800
    ,TYPE11_POS = 11
    ,TYPE11_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE11_1 = 0x00000800 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 12)
    ,TYPE12_MASK = 0x00001000
    ,TYPE12_POS = 12
    ,TYPE12_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE12_1 = 0x00001000 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 13)
    ,TYPE13_MASK = 0x00002000
    ,TYPE13_POS = 13
    ,TYPE13_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE13_1 = 0x00002000 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 14)
    ,TYPE14_MASK = 0x00004000
    ,TYPE14_POS = 14
    ,TYPE14_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE14_1 = 0x00004000 // Level trigger interrupt
    // Port A-H Pin[n] Edge or Level Detection Interrupt Trigger Type Control TYPE (Px_INTTYPE[n]) bit is used to control the triggered interrupt is by level trigger or by edge trigger. If the interrupt is by edge trigger, the trigger source can be controlled by de-bounce. If the interrupt is by level trigger, the input source is sampled by one HCLK clock and generates the interrupt. (bits: 15)
    ,TYPE15_MASK = 0x00008000
    ,TYPE15_POS = 15
    ,TYPE15_0 = 0x00000000 // Edge trigger interrupt
    ,TYPE15_1 = 0x00008000 // Level trigger interrupt
    ,INTTYPE_MASK = 0x0000FFFF
    ;
  };
  // PA Interrupt Enable Control Register
  struct INTEN : reg<ip_ver, base + 0x1C>
  {
    static constexpr typename INTEN::type
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 0)
     FLIEN0_MASK = 0x00000001
    ,FLIEN0_POS = 0
    ,FLIEN0_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN0_1 = 0x00000001 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 1)
    ,FLIEN1_MASK = 0x00000002
    ,FLIEN1_POS = 1
    ,FLIEN1_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN1_1 = 0x00000002 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 2)
    ,FLIEN2_MASK = 0x00000004
    ,FLIEN2_POS = 2
    ,FLIEN2_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN2_1 = 0x00000004 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 3)
    ,FLIEN3_MASK = 0x00000008
    ,FLIEN3_POS = 3
    ,FLIEN3_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN3_1 = 0x00000008 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 4)
    ,FLIEN4_MASK = 0x00000010
    ,FLIEN4_POS = 4
    ,FLIEN4_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN4_1 = 0x00000010 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 5)
    ,FLIEN5_MASK = 0x00000020
    ,FLIEN5_POS = 5
    ,FLIEN5_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN5_1 = 0x00000020 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 6)
    ,FLIEN6_MASK = 0x00000040
    ,FLIEN6_POS = 6
    ,FLIEN6_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN6_1 = 0x00000040 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 7)
    ,FLIEN7_MASK = 0x00000080
    ,FLIEN7_POS = 7
    ,FLIEN7_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN7_1 = 0x00000080 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 8)
    ,FLIEN8_MASK = 0x00000100
    ,FLIEN8_POS = 8
    ,FLIEN8_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN8_1 = 0x00000100 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 9)
    ,FLIEN9_MASK = 0x00000200
    ,FLIEN9_POS = 9
    ,FLIEN9_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN9_1 = 0x00000200 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 10)
    ,FLIEN10_MASK = 0x00000400
    ,FLIEN10_POS = 10
    ,FLIEN10_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN10_1 = 0x00000400 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 11)
    ,FLIEN11_MASK = 0x00000800
    ,FLIEN11_POS = 11
    ,FLIEN11_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN11_1 = 0x00000800 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 12)
    ,FLIEN12_MASK = 0x00001000
    ,FLIEN12_POS = 12
    ,FLIEN12_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN12_1 = 0x00001000 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 13)
    ,FLIEN13_MASK = 0x00002000
    ,FLIEN13_POS = 13
    ,FLIEN13_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN13_1 = 0x00002000 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 14)
    ,FLIEN14_MASK = 0x00004000
    ,FLIEN14_POS = 14
    ,FLIEN14_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN14_1 = 0x00004000 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Falling Edge or Low Level Interrupt Trigger Type Enable Bit The FLIEN (Px_INTEN[n]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the FLIEN (Px_INTEN[n]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at low level. If the interrupt is edge trigger(TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from high to low. (bits: 15)
    ,FLIEN15_MASK = 0x00008000
    ,FLIEN15_POS = 15
    ,FLIEN15_0 = 0x00000000 // Px.n level low or high to low interrupt Disabled
    ,FLIEN15_1 = 0x00008000 // Px.n level low or high to low interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 16)
    ,RHIEN0_MASK = 0x00010000
    ,RHIEN0_POS = 16
    ,RHIEN0_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN0_1 = 0x00010000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 17)
    ,RHIEN1_MASK = 0x00020000
    ,RHIEN1_POS = 17
    ,RHIEN1_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN1_1 = 0x00020000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 18)
    ,RHIEN2_MASK = 0x00040000
    ,RHIEN2_POS = 18
    ,RHIEN2_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN2_1 = 0x00040000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 19)
    ,RHIEN3_MASK = 0x00080000
    ,RHIEN3_POS = 19
    ,RHIEN3_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN3_1 = 0x00080000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 20)
    ,RHIEN4_MASK = 0x00100000
    ,RHIEN4_POS = 20
    ,RHIEN4_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN4_1 = 0x00100000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 21)
    ,RHIEN5_MASK = 0x00200000
    ,RHIEN5_POS = 21
    ,RHIEN5_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN5_1 = 0x00200000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 22)
    ,RHIEN6_MASK = 0x00400000
    ,RHIEN6_POS = 22
    ,RHIEN6_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN6_1 = 0x00400000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 23)
    ,RHIEN7_MASK = 0x00800000
    ,RHIEN7_POS = 23
    ,RHIEN7_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN7_1 = 0x00800000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 24)
    ,RHIEN8_MASK = 0x01000000
    ,RHIEN8_POS = 24
    ,RHIEN8_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN8_1 = 0x01000000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 25)
    ,RHIEN9_MASK = 0x02000000
    ,RHIEN9_POS = 25
    ,RHIEN9_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN9_1 = 0x02000000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 26)
    ,RHIEN10_MASK = 0x04000000
    ,RHIEN10_POS = 26
    ,RHIEN10_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN10_1 = 0x04000000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 27)
    ,RHIEN11_MASK = 0x08000000
    ,RHIEN11_POS = 27
    ,RHIEN11_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN11_1 = 0x08000000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 28)
    ,RHIEN12_MASK = 0x10000000
    ,RHIEN12_POS = 28
    ,RHIEN12_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN12_1 = 0x10000000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 29)
    ,RHIEN13_MASK = 0x20000000
    ,RHIEN13_POS = 29
    ,RHIEN13_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN13_1 = 0x20000000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 30)
    ,RHIEN14_MASK = 0x40000000
    ,RHIEN14_POS = 30
    ,RHIEN14_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN14_1 = 0x40000000 // Px.n level high or low to high interrupt Enabled
    // Port A-H Pin[n] Rising Edge or High Level Interrupt Trigger Type Enable Bit The RHIEN (Px_INTEN[n+16]) bit is used to enable the interrupt for each of the corresponding input Px.n pin. Set bit to 1 also enable the pin wake-up function. When setting the RHIEN (Px_INTEN[n+16]) bit to 1 : If the interrupt is level trigger (TYPE (Px_INTTYPE[n]) bit is set to 1), the input Px.n pin will generate the interrupt while this pin state is at high level. If the interrupt is edge trigger (TYPE (Px_INTTYPE[n]) bit is set to 0), the input Px.n pin will generate the interrupt while this pin state changed from low to high. (bits: 31)
    ,RHIEN15_MASK = 0x80000000
    ,RHIEN15_POS = 31
    ,RHIEN15_0 = 0x00000000 // Px.n level high or low to high interrupt Disabled
    ,RHIEN15_1 = 0x80000000 // Px.n level high or low to high interrupt Enabled
    ,INTEN_MASK = 0xFFFFFFFF
    ;
  };
  // PA Interrupt Source Flag
  struct INTSRC : reg<ip_ver, base + 0x20>
  {
    static constexpr typename INTSRC::type
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 0)
     INTSRC0_MASK = 0x00000001
    ,INTSRC0_POS = 0
    ,INTSRC0_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC0_1 = 0x00000001 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 1)
    ,INTSRC1_MASK = 0x00000002
    ,INTSRC1_POS = 1
    ,INTSRC1_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC1_1 = 0x00000002 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 2)
    ,INTSRC2_MASK = 0x00000004
    ,INTSRC2_POS = 2
    ,INTSRC2_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC2_1 = 0x00000004 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 3)
    ,INTSRC3_MASK = 0x00000008
    ,INTSRC3_POS = 3
    ,INTSRC3_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC3_1 = 0x00000008 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 4)
    ,INTSRC4_MASK = 0x00000010
    ,INTSRC4_POS = 4
    ,INTSRC4_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC4_1 = 0x00000010 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 5)
    ,INTSRC5_MASK = 0x00000020
    ,INTSRC5_POS = 5
    ,INTSRC5_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC5_1 = 0x00000020 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 6)
    ,INTSRC6_MASK = 0x00000040
    ,INTSRC6_POS = 6
    ,INTSRC6_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC6_1 = 0x00000040 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 7)
    ,INTSRC7_MASK = 0x00000080
    ,INTSRC7_POS = 7
    ,INTSRC7_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC7_1 = 0x00000080 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 8)
    ,INTSRC8_MASK = 0x00000100
    ,INTSRC8_POS = 8
    ,INTSRC8_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC8_1 = 0x00000100 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 9)
    ,INTSRC9_MASK = 0x00000200
    ,INTSRC9_POS = 9
    ,INTSRC9_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC9_1 = 0x00000200 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 10)
    ,INTSRC10_MASK = 0x00000400
    ,INTSRC10_POS = 10
    ,INTSRC10_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC10_1 = 0x00000400 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 11)
    ,INTSRC11_MASK = 0x00000800
    ,INTSRC11_POS = 11
    ,INTSRC11_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC11_1 = 0x00000800 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 12)
    ,INTSRC12_MASK = 0x00001000
    ,INTSRC12_POS = 12
    ,INTSRC12_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC12_1 = 0x00001000 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 13)
    ,INTSRC13_MASK = 0x00002000
    ,INTSRC13_POS = 13
    ,INTSRC13_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC13_1 = 0x00002000 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 14)
    ,INTSRC14_MASK = 0x00004000
    ,INTSRC14_POS = 14
    ,INTSRC14_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC14_1 = 0x00004000 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    // Port A-H Pin[n] Interrupt Source Flag Write Operation : (bits: 15)
    ,INTSRC15_MASK = 0x00008000
    ,INTSRC15_POS = 15
    ,INTSRC15_0 = 0x00000000 // No action.\nNo interrupt at Px.n
    ,INTSRC15_1 = 0x00008000 // Clear the corresponding pending interrupt.\nPx.n generates an interrupt
    ,INTSRC_MASK = 0x0000FFFF
    ;
  };
  // PA Input Schmitt Trigger Enable Register
  struct SMTEN : reg<ip_ver, base + 0x24>
  {
    static constexpr typename SMTEN::type
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 0)
     SMTEN0_MASK = 0x00000001
    ,SMTEN0_POS = 0
    ,SMTEN0_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN0_1 = 0x00000001 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 1)
    ,SMTEN1_MASK = 0x00000002
    ,SMTEN1_POS = 1
    ,SMTEN1_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN1_1 = 0x00000002 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 2)
    ,SMTEN2_MASK = 0x00000004
    ,SMTEN2_POS = 2
    ,SMTEN2_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN2_1 = 0x00000004 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 3)
    ,SMTEN3_MASK = 0x00000008
    ,SMTEN3_POS = 3
    ,SMTEN3_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN3_1 = 0x00000008 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 4)
    ,SMTEN4_MASK = 0x00000010
    ,SMTEN4_POS = 4
    ,SMTEN4_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN4_1 = 0x00000010 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 5)
    ,SMTEN5_MASK = 0x00000020
    ,SMTEN5_POS = 5
    ,SMTEN5_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN5_1 = 0x00000020 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 6)
    ,SMTEN6_MASK = 0x00000040
    ,SMTEN6_POS = 6
    ,SMTEN6_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN6_1 = 0x00000040 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 7)
    ,SMTEN7_MASK = 0x00000080
    ,SMTEN7_POS = 7
    ,SMTEN7_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN7_1 = 0x00000080 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 8)
    ,SMTEN8_MASK = 0x00000100
    ,SMTEN8_POS = 8
    ,SMTEN8_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN8_1 = 0x00000100 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 9)
    ,SMTEN9_MASK = 0x00000200
    ,SMTEN9_POS = 9
    ,SMTEN9_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN9_1 = 0x00000200 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 10)
    ,SMTEN10_MASK = 0x00000400
    ,SMTEN10_POS = 10
    ,SMTEN10_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN10_1 = 0x00000400 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 11)
    ,SMTEN11_MASK = 0x00000800
    ,SMTEN11_POS = 11
    ,SMTEN11_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN11_1 = 0x00000800 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 12)
    ,SMTEN12_MASK = 0x00001000
    ,SMTEN12_POS = 12
    ,SMTEN12_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN12_1 = 0x00001000 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 13)
    ,SMTEN13_MASK = 0x00002000
    ,SMTEN13_POS = 13
    ,SMTEN13_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN13_1 = 0x00002000 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 14)
    ,SMTEN14_MASK = 0x00004000
    ,SMTEN14_POS = 14
    ,SMTEN14_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN14_1 = 0x00004000 // Px.n input schmitt trigger function Enabled
    // Port A-H Pin[n] Input Schmitt Trigger Enable Bit (bits: 15)
    ,SMTEN15_MASK = 0x00008000
    ,SMTEN15_POS = 15
    ,SMTEN15_0 = 0x00000000 // Px.n input schmitt trigger function Disabled
    ,SMTEN15_1 = 0x00008000 // Px.n input schmitt trigger function Enabled
    ,SMTEN_MASK = 0x0000FFFF
    ;
  };
  // PA High Slew Rate Control Register
  struct SLEWCTL : reg<ip_ver, base + 0x28>
  {
    static constexpr typename SLEWCTL::type
    // Port A-H Pin[n] High Slew Rate Control (bits: 1-0)
     HSREN0_MASK = 0x00000003
    ,HSREN0_POS = 0
    ,HSREN0_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN0_1 = 0x00000001 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN0_2 = 0x00000002 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN0_3 = 0x00000003 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 3-2)
    ,HSREN1_MASK = 0x0000000C
    ,HSREN1_POS = 2
    ,HSREN1_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN1_1 = 0x00000004 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN1_2 = 0x00000008 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN1_3 = 0x0000000C // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 5-4)
    ,HSREN2_MASK = 0x00000030
    ,HSREN2_POS = 4
    ,HSREN2_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN2_1 = 0x00000010 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN2_2 = 0x00000020 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN2_3 = 0x00000030 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 7-6)
    ,HSREN3_MASK = 0x000000C0
    ,HSREN3_POS = 6
    ,HSREN3_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN3_1 = 0x00000040 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN3_2 = 0x00000080 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN3_3 = 0x000000C0 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 9-8)
    ,HSREN4_MASK = 0x00000300
    ,HSREN4_POS = 8
    ,HSREN4_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN4_1 = 0x00000100 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN4_2 = 0x00000200 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN4_3 = 0x00000300 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 11-10)
    ,HSREN5_MASK = 0x00000C00
    ,HSREN5_POS = 10
    ,HSREN5_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN5_1 = 0x00000400 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN5_2 = 0x00000800 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN5_3 = 0x00000C00 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 13-12)
    ,HSREN6_MASK = 0x00003000
    ,HSREN6_POS = 12
    ,HSREN6_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN6_1 = 0x00001000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN6_2 = 0x00002000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN6_3 = 0x00003000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 15-14)
    ,HSREN7_MASK = 0x0000C000
    ,HSREN7_POS = 14
    ,HSREN7_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN7_1 = 0x00004000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN7_2 = 0x00008000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN7_3 = 0x0000C000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 17-16)
    ,HSREN8_MASK = 0x00030000
    ,HSREN8_POS = 16
    ,HSREN8_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN8_1 = 0x00010000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN8_2 = 0x00020000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN8_3 = 0x00030000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 19-18)
    ,HSREN9_MASK = 0x000C0000
    ,HSREN9_POS = 18
    ,HSREN9_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN9_1 = 0x00040000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN9_2 = 0x00080000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN9_3 = 0x000C0000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 21-20)
    ,HSREN10_MASK = 0x00300000
    ,HSREN10_POS = 20
    ,HSREN10_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN10_1 = 0x00100000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN10_2 = 0x00200000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN10_3 = 0x00300000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 23-22)
    ,HSREN11_MASK = 0x00C00000
    ,HSREN11_POS = 22
    ,HSREN11_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN11_1 = 0x00400000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN11_2 = 0x00800000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN11_3 = 0x00C00000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 25-24)
    ,HSREN12_MASK = 0x03000000
    ,HSREN12_POS = 24
    ,HSREN12_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN12_1 = 0x01000000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN12_2 = 0x02000000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN12_3 = 0x03000000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 27-26)
    ,HSREN13_MASK = 0x0C000000
    ,HSREN13_POS = 26
    ,HSREN13_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN13_1 = 0x04000000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN13_2 = 0x08000000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN13_3 = 0x0C000000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 29-28)
    ,HSREN14_MASK = 0x30000000
    ,HSREN14_POS = 28
    ,HSREN14_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN14_1 = 0x10000000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN14_2 = 0x20000000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN14_3 = 0x30000000 // Reserved.
    // Port A-H Pin[n] High Slew Rate Control (bits: 31-30)
    ,HSREN15_MASK = 0xC0000000
    ,HSREN15_POS = 30
    ,HSREN15_0 = 0x00000000 // Px.n output with normal slew rate mode (maximum 40 MHz at 2.7V)
    ,HSREN15_1 = 0x40000000 // Px.n output with high slew rate mode (maximum 80 MHz at 2.7V)
    ,HSREN15_2 = 0x80000000 // Px.n output with fast slew rate mode (maximum 100 MHz at 2.7V)
    ,HSREN15_3 = 0xC0000000 // Reserved.
    ,SLEWCTL_MASK = 0xFFFFFFFF
    ;
  };
  // PA Pull-up and Pull-down Selection Register
  struct PUSEL : reg<ip_ver, base + 0x30>
  {
    static constexpr typename PUSEL::type
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 1-0)
     PUSEL0_MASK = 0x00000003
    ,PUSEL0_POS = 0
    ,PUSEL0_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL0_1 = 0x00000001 // Px.n pull-up enable
    ,PUSEL0_2 = 0x00000002 // Px.n pull-down enable
    ,PUSEL0_3 = 0x00000003 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 3-2)
    ,PUSEL1_MASK = 0x0000000C
    ,PUSEL1_POS = 2
    ,PUSEL1_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL1_1 = 0x00000004 // Px.n pull-up enable
    ,PUSEL1_2 = 0x00000008 // Px.n pull-down enable
    ,PUSEL1_3 = 0x0000000C // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 5-4)
    ,PUSEL2_MASK = 0x00000030
    ,PUSEL2_POS = 4
    ,PUSEL2_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL2_1 = 0x00000010 // Px.n pull-up enable
    ,PUSEL2_2 = 0x00000020 // Px.n pull-down enable
    ,PUSEL2_3 = 0x00000030 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 7-6)
    ,PUSEL3_MASK = 0x000000C0
    ,PUSEL3_POS = 6
    ,PUSEL3_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL3_1 = 0x00000040 // Px.n pull-up enable
    ,PUSEL3_2 = 0x00000080 // Px.n pull-down enable
    ,PUSEL3_3 = 0x000000C0 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 9-8)
    ,PUSEL4_MASK = 0x00000300
    ,PUSEL4_POS = 8
    ,PUSEL4_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL4_1 = 0x00000100 // Px.n pull-up enable
    ,PUSEL4_2 = 0x00000200 // Px.n pull-down enable
    ,PUSEL4_3 = 0x00000300 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 11-10)
    ,PUSEL5_MASK = 0x00000C00
    ,PUSEL5_POS = 10
    ,PUSEL5_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL5_1 = 0x00000400 // Px.n pull-up enable
    ,PUSEL5_2 = 0x00000800 // Px.n pull-down enable
    ,PUSEL5_3 = 0x00000C00 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 13-12)
    ,PUSEL6_MASK = 0x00003000
    ,PUSEL6_POS = 12
    ,PUSEL6_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL6_1 = 0x00001000 // Px.n pull-up enable
    ,PUSEL6_2 = 0x00002000 // Px.n pull-down enable
    ,PUSEL6_3 = 0x00003000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 15-14)
    ,PUSEL7_MASK = 0x0000C000
    ,PUSEL7_POS = 14
    ,PUSEL7_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL7_1 = 0x00004000 // Px.n pull-up enable
    ,PUSEL7_2 = 0x00008000 // Px.n pull-down enable
    ,PUSEL7_3 = 0x0000C000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 17-16)
    ,PUSEL8_MASK = 0x00030000
    ,PUSEL8_POS = 16
    ,PUSEL8_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL8_1 = 0x00010000 // Px.n pull-up enable
    ,PUSEL8_2 = 0x00020000 // Px.n pull-down enable
    ,PUSEL8_3 = 0x00030000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 19-18)
    ,PUSEL9_MASK = 0x000C0000
    ,PUSEL9_POS = 18
    ,PUSEL9_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL9_1 = 0x00040000 // Px.n pull-up enable
    ,PUSEL9_2 = 0x00080000 // Px.n pull-down enable
    ,PUSEL9_3 = 0x000C0000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 21-20)
    ,PUSEL10_MASK = 0x00300000
    ,PUSEL10_POS = 20
    ,PUSEL10_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL10_1 = 0x00100000 // Px.n pull-up enable
    ,PUSEL10_2 = 0x00200000 // Px.n pull-down enable
    ,PUSEL10_3 = 0x00300000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 23-22)
    ,PUSEL11_MASK = 0x00C00000
    ,PUSEL11_POS = 22
    ,PUSEL11_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL11_1 = 0x00400000 // Px.n pull-up enable
    ,PUSEL11_2 = 0x00800000 // Px.n pull-down enable
    ,PUSEL11_3 = 0x00C00000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 25-24)
    ,PUSEL12_MASK = 0x03000000
    ,PUSEL12_POS = 24
    ,PUSEL12_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL12_1 = 0x01000000 // Px.n pull-up enable
    ,PUSEL12_2 = 0x02000000 // Px.n pull-down enable
    ,PUSEL12_3 = 0x03000000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 27-26)
    ,PUSEL13_MASK = 0x0C000000
    ,PUSEL13_POS = 26
    ,PUSEL13_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL13_1 = 0x04000000 // Px.n pull-up enable
    ,PUSEL13_2 = 0x08000000 // Px.n pull-down enable
    ,PUSEL13_3 = 0x0C000000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 29-28)
    ,PUSEL14_MASK = 0x30000000
    ,PUSEL14_POS = 28
    ,PUSEL14_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL14_1 = 0x10000000 // Px.n pull-up enable
    ,PUSEL14_2 = 0x20000000 // Px.n pull-down enable
    ,PUSEL14_3 = 0x30000000 // Reserved.
    // Port A-H Pin[n] Pull-up and Pull-down Enable Register Determine each I/O Pull-up/pull-down of Px.n pins. (bits: 31-30)
    ,PUSEL15_MASK = 0xC0000000
    ,PUSEL15_POS = 30
    ,PUSEL15_0 = 0x00000000 // Px.n pull-up and pull-down disable
    ,PUSEL15_1 = 0x40000000 // Px.n pull-up enable
    ,PUSEL15_2 = 0x80000000 // Px.n pull-down enable
    ,PUSEL15_3 = 0xC0000000 // Reserved.
    ,PUSEL_MASK = 0xFFFFFFFF
    ;
  };
  // GPIO A-H Pin Data Input/Output Register (count: 16)
  struct PDIO : reg<ip_ver, base + 0x400, 0x00000000, 16>
  {
    static constexpr typename PDIO::type
    // GPIO Px.n Pin Data Input/Output Writing this bit can control one GPIO pin output value. (bits: 0)
     PDIOVAL_MASK = 0x00000001
    ,PDIOVAL_POS = 0
    ,PDIOVAL_0 = 0x00000000 // Corresponding GPIO pin set to low
    ,PDIOVAL_1 = 0x00000001 // Corresponding GPIO pin set to high
    ,PDIO_MASK = 0x00000001
    ;
  };
}; // struct GPIO

} // namespace lmcu::device::ip::v1

