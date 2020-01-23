/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../common.h"

namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// General-purpose I/Os
// ------------------------------------------------------------------------------------------------
struct GPIOD
{
  static constexpr std::uintptr_t base = 0x40011400;

  // Port configuration register low
  struct CRL : reg<32, base + 0x0, 0x00000000, 0x44444444>
  {
    static constexpr type
    // Port x mode bits (bits: 1-0)
     MODE0_MASK = 0x00000003
    ,MODE0_POS = 0
    ,MODE0_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE0_SPEED_10MHZ = 0x00000001 // Output mode, max speed 10 MHz.
    ,MODE0_SPEED_2MHZ = 0x00000002 // Output mode, max speed 10 MHz.
    ,MODE0_SPEED_50MHZ = 0x00000003 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 3-2)
    ,CNF0_MASK = 0x0000000C
    ,CNF0_POS = 2
    // Port x mode bits (bits: 5-4)
    ,MODE1_MASK = 0x00000030
    ,MODE1_POS = 4
    ,MODE1_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE1_SPEED_10MHZ = 0x00000010 // Output mode, max speed 10 MHz.
    ,MODE1_SPEED_2MHZ = 0x00000020 // Output mode, max speed 10 MHz.
    ,MODE1_SPEED_50MHZ = 0x00000030 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 7-6)
    ,CNF1_MASK = 0x000000C0
    ,CNF1_POS = 6
    // Port x mode bits (bits: 9-8)
    ,MODE2_MASK = 0x00000300
    ,MODE2_POS = 8
    ,MODE2_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE2_SPEED_10MHZ = 0x00000100 // Output mode, max speed 10 MHz.
    ,MODE2_SPEED_2MHZ = 0x00000200 // Output mode, max speed 10 MHz.
    ,MODE2_SPEED_50MHZ = 0x00000300 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 11-10)
    ,CNF2_MASK = 0x00000C00
    ,CNF2_POS = 10
    // Port x mode bits (bits: 13-12)
    ,MODE3_MASK = 0x00003000
    ,MODE3_POS = 12
    ,MODE3_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE3_SPEED_10MHZ = 0x00001000 // Output mode, max speed 10 MHz.
    ,MODE3_SPEED_2MHZ = 0x00002000 // Output mode, max speed 10 MHz.
    ,MODE3_SPEED_50MHZ = 0x00003000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 15-14)
    ,CNF3_MASK = 0x0000C000
    ,CNF3_POS = 14
    // Port x mode bits (bits: 17-16)
    ,MODE4_MASK = 0x00030000
    ,MODE4_POS = 16
    ,MODE4_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE4_SPEED_10MHZ = 0x00010000 // Output mode, max speed 10 MHz.
    ,MODE4_SPEED_2MHZ = 0x00020000 // Output mode, max speed 10 MHz.
    ,MODE4_SPEED_50MHZ = 0x00030000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 19-18)
    ,CNF4_MASK = 0x000C0000
    ,CNF4_POS = 18
    // Port x mode bits (bits: 21-20)
    ,MODE5_MASK = 0x00300000
    ,MODE5_POS = 20
    ,MODE5_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE5_SPEED_10MHZ = 0x00100000 // Output mode, max speed 10 MHz.
    ,MODE5_SPEED_2MHZ = 0x00200000 // Output mode, max speed 10 MHz.
    ,MODE5_SPEED_50MHZ = 0x00300000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 23-22)
    ,CNF5_MASK = 0x00C00000
    ,CNF5_POS = 22
    // Port x mode bits (bits: 25-24)
    ,MODE6_MASK = 0x03000000
    ,MODE6_POS = 24
    ,MODE6_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE6_SPEED_10MHZ = 0x01000000 // Output mode, max speed 10 MHz.
    ,MODE6_SPEED_2MHZ = 0x02000000 // Output mode, max speed 10 MHz.
    ,MODE6_SPEED_50MHZ = 0x03000000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 27-26)
    ,CNF6_MASK = 0x0C000000
    ,CNF6_POS = 26
    // Port x mode bits (bits: 29-28)
    ,MODE7_MASK = 0x30000000
    ,MODE7_POS = 28
    ,MODE7_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE7_SPEED_10MHZ = 0x10000000 // Output mode, max speed 10 MHz.
    ,MODE7_SPEED_2MHZ = 0x20000000 // Output mode, max speed 10 MHz.
    ,MODE7_SPEED_50MHZ = 0x30000000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 31-30)
    ,CNF7_MASK = 0xC0000000
    ,CNF7_POS = 30
    ;
  };
  // Port configuration register high
  struct CRH : reg<32, base + 0x4, 0x00000000, 0x44444444>
  {
    static constexpr type
    // Port x mode bits (bits: 1-0)
     MODE8_MASK = 0x00000003
    ,MODE8_POS = 0
    ,MODE8_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE8_SPEED_10MHZ = 0x00000001 // Output mode, max speed 10 MHz.
    ,MODE8_SPEED_2MHZ = 0x00000002 // Output mode, max speed 10 MHz.
    ,MODE8_SPEED_50MHZ = 0x00000003 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 3-2)
    ,CNF8_MASK = 0x0000000C
    ,CNF8_POS = 2
    // Port x mode bits (bits: 5-4)
    ,MODE9_MASK = 0x00000030
    ,MODE9_POS = 4
    ,MODE9_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE9_SPEED_10MHZ = 0x00000010 // Output mode, max speed 10 MHz.
    ,MODE9_SPEED_2MHZ = 0x00000020 // Output mode, max speed 10 MHz.
    ,MODE9_SPEED_50MHZ = 0x00000030 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 7-6)
    ,CNF9_MASK = 0x000000C0
    ,CNF9_POS = 6
    // Port x mode bits (bits: 9-8)
    ,MODE10_MASK = 0x00000300
    ,MODE10_POS = 8
    ,MODE10_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE10_SPEED_10MHZ = 0x00000100 // Output mode, max speed 10 MHz.
    ,MODE10_SPEED_2MHZ = 0x00000200 // Output mode, max speed 10 MHz.
    ,MODE10_SPEED_50MHZ = 0x00000300 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 11-10)
    ,CNF10_MASK = 0x00000C00
    ,CNF10_POS = 10
    // Port x mode bits (bits: 13-12)
    ,MODE11_MASK = 0x00003000
    ,MODE11_POS = 12
    ,MODE11_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE11_SPEED_10MHZ = 0x00001000 // Output mode, max speed 10 MHz.
    ,MODE11_SPEED_2MHZ = 0x00002000 // Output mode, max speed 10 MHz.
    ,MODE11_SPEED_50MHZ = 0x00003000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 15-14)
    ,CNF11_MASK = 0x0000C000
    ,CNF11_POS = 14
    // Port x mode bits (bits: 17-16)
    ,MODE12_MASK = 0x00030000
    ,MODE12_POS = 16
    ,MODE12_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE12_SPEED_10MHZ = 0x00010000 // Output mode, max speed 10 MHz.
    ,MODE12_SPEED_2MHZ = 0x00020000 // Output mode, max speed 10 MHz.
    ,MODE12_SPEED_50MHZ = 0x00030000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 19-18)
    ,CNF12_MASK = 0x000C0000
    ,CNF12_POS = 18
    // Port x mode bits (bits: 21-20)
    ,MODE13_MASK = 0x00300000
    ,MODE13_POS = 20
    ,MODE13_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE13_SPEED_10MHZ = 0x00100000 // Output mode, max speed 10 MHz.
    ,MODE13_SPEED_2MHZ = 0x00200000 // Output mode, max speed 10 MHz.
    ,MODE13_SPEED_50MHZ = 0x00300000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 23-22)
    ,CNF13_MASK = 0x00C00000
    ,CNF13_POS = 22
    // Port x mode bits (bits: 25-24)
    ,MODE14_MASK = 0x03000000
    ,MODE14_POS = 24
    ,MODE14_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE14_SPEED_10MHZ = 0x01000000 // Output mode, max speed 10 MHz.
    ,MODE14_SPEED_2MHZ = 0x02000000 // Output mode, max speed 10 MHz.
    ,MODE14_SPEED_50MHZ = 0x03000000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 27-26)
    ,CNF14_MASK = 0x0C000000
    ,CNF14_POS = 26
    // Port x mode bits (bits: 29-28)
    ,MODE15_MASK = 0x30000000
    ,MODE15_POS = 28
    ,MODE15_INPUT = 0x00000000 // Input mode (reset state)
    ,MODE15_SPEED_10MHZ = 0x10000000 // Output mode, max speed 10 MHz.
    ,MODE15_SPEED_2MHZ = 0x20000000 // Output mode, max speed 10 MHz.
    ,MODE15_SPEED_50MHZ = 0x30000000 // Output mode, max speed 50 MHz.
    // Port x configuration bits (bits: 31-30)
    ,CNF15_MASK = 0xC0000000
    ,CNF15_POS = 30
    ;
  };
  // Port input data register
  struct IDR : reg<32, base + 0x8, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Port input data (bits: 0)
     IDR0_MASK = 0x00000001
    ,IDR0_POS = 0
    ,IDR0 = 0x00000001
    // Port input data (bits: 1)
    ,IDR1_MASK = 0x00000002
    ,IDR1_POS = 1
    ,IDR1 = 0x00000002
    // Port input data (bits: 2)
    ,IDR2_MASK = 0x00000004
    ,IDR2_POS = 2
    ,IDR2 = 0x00000004
    // Port input data (bits: 3)
    ,IDR3_MASK = 0x00000008
    ,IDR3_POS = 3
    ,IDR3 = 0x00000008
    // Port input data (bits: 4)
    ,IDR4_MASK = 0x00000010
    ,IDR4_POS = 4
    ,IDR4 = 0x00000010
    // Port input data (bits: 5)
    ,IDR5_MASK = 0x00000020
    ,IDR5_POS = 5
    ,IDR5 = 0x00000020
    // Port input data (bits: 6)
    ,IDR6_MASK = 0x00000040
    ,IDR6_POS = 6
    ,IDR6 = 0x00000040
    // Port input data (bits: 7)
    ,IDR7_MASK = 0x00000080
    ,IDR7_POS = 7
    ,IDR7 = 0x00000080
    // Port input data (bits: 8)
    ,IDR8_MASK = 0x00000100
    ,IDR8_POS = 8
    ,IDR8 = 0x00000100
    // Port input data (bits: 9)
    ,IDR9_MASK = 0x00000200
    ,IDR9_POS = 9
    ,IDR9 = 0x00000200
    // Port input data (bits: 10)
    ,IDR10_MASK = 0x00000400
    ,IDR10_POS = 10
    ,IDR10 = 0x00000400
    // Port input data (bits: 11)
    ,IDR11_MASK = 0x00000800
    ,IDR11_POS = 11
    ,IDR11 = 0x00000800
    // Port input data (bits: 12)
    ,IDR12_MASK = 0x00001000
    ,IDR12_POS = 12
    ,IDR12 = 0x00001000
    // Port input data (bits: 13)
    ,IDR13_MASK = 0x00002000
    ,IDR13_POS = 13
    ,IDR13 = 0x00002000
    // Port input data (bits: 14)
    ,IDR14_MASK = 0x00004000
    ,IDR14_POS = 14
    ,IDR14 = 0x00004000
    // Port input data (bits: 15)
    ,IDR15_MASK = 0x00008000
    ,IDR15_POS = 15
    ,IDR15 = 0x00008000
    ;
  };
  // Port output data register
  struct ODR : reg<32, base + 0xC, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Port output data (bits: 0)
     ODR0_MASK = 0x00000001
    ,ODR0_POS = 0
    ,ODR0 = 0x00000001
    // Port output data (bits: 1)
    ,ODR1_MASK = 0x00000002
    ,ODR1_POS = 1
    ,ODR1 = 0x00000002
    // Port output data (bits: 2)
    ,ODR2_MASK = 0x00000004
    ,ODR2_POS = 2
    ,ODR2 = 0x00000004
    // Port output data (bits: 3)
    ,ODR3_MASK = 0x00000008
    ,ODR3_POS = 3
    ,ODR3 = 0x00000008
    // Port output data (bits: 4)
    ,ODR4_MASK = 0x00000010
    ,ODR4_POS = 4
    ,ODR4 = 0x00000010
    // Port output data (bits: 5)
    ,ODR5_MASK = 0x00000020
    ,ODR5_POS = 5
    ,ODR5 = 0x00000020
    // Port output data (bits: 6)
    ,ODR6_MASK = 0x00000040
    ,ODR6_POS = 6
    ,ODR6 = 0x00000040
    // Port output data (bits: 7)
    ,ODR7_MASK = 0x00000080
    ,ODR7_POS = 7
    ,ODR7 = 0x00000080
    // Port output data (bits: 8)
    ,ODR8_MASK = 0x00000100
    ,ODR8_POS = 8
    ,ODR8 = 0x00000100
    // Port output data (bits: 9)
    ,ODR9_MASK = 0x00000200
    ,ODR9_POS = 9
    ,ODR9 = 0x00000200
    // Port output data (bits: 10)
    ,ODR10_MASK = 0x00000400
    ,ODR10_POS = 10
    ,ODR10 = 0x00000400
    // Port output data (bits: 11)
    ,ODR11_MASK = 0x00000800
    ,ODR11_POS = 11
    ,ODR11 = 0x00000800
    // Port output data (bits: 12)
    ,ODR12_MASK = 0x00001000
    ,ODR12_POS = 12
    ,ODR12 = 0x00001000
    // Port output data (bits: 13)
    ,ODR13_MASK = 0x00002000
    ,ODR13_POS = 13
    ,ODR13 = 0x00002000
    // Port output data (bits: 14)
    ,ODR14_MASK = 0x00004000
    ,ODR14_POS = 14
    ,ODR14 = 0x00004000
    // Port output data (bits: 15)
    ,ODR15_MASK = 0x00008000
    ,ODR15_POS = 15
    ,ODR15 = 0x00008000
    ;
  };
  // Port bit set/reset register
  struct BSRR : reg<32, base + 0x10, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Port x Set bit (bits: 0)
     BS0_MASK = 0x00000001
    ,BS0_POS = 0
    ,BS0 = 0x00000001
    // Port x Set bit (bits: 1)
    ,BS1_MASK = 0x00000002
    ,BS1_POS = 1
    ,BS1 = 0x00000002
    // Port x Set bit (bits: 2)
    ,BS2_MASK = 0x00000004
    ,BS2_POS = 2
    ,BS2 = 0x00000004
    // Port x Set bit (bits: 3)
    ,BS3_MASK = 0x00000008
    ,BS3_POS = 3
    ,BS3 = 0x00000008
    // Port x Set bit (bits: 4)
    ,BS4_MASK = 0x00000010
    ,BS4_POS = 4
    ,BS4 = 0x00000010
    // Port x Set bit (bits: 5)
    ,BS5_MASK = 0x00000020
    ,BS5_POS = 5
    ,BS5 = 0x00000020
    // Port x Set bit (bits: 6)
    ,BS6_MASK = 0x00000040
    ,BS6_POS = 6
    ,BS6 = 0x00000040
    // Port x Set bit (bits: 7)
    ,BS7_MASK = 0x00000080
    ,BS7_POS = 7
    ,BS7 = 0x00000080
    // Port x Set bit (bits: 8)
    ,BS8_MASK = 0x00000100
    ,BS8_POS = 8
    ,BS8 = 0x00000100
    // Port x Set bit (bits: 9)
    ,BS9_MASK = 0x00000200
    ,BS9_POS = 9
    ,BS9 = 0x00000200
    // Port x Set bit (bits: 10)
    ,BS10_MASK = 0x00000400
    ,BS10_POS = 10
    ,BS10 = 0x00000400
    // Port x Set bit (bits: 11)
    ,BS11_MASK = 0x00000800
    ,BS11_POS = 11
    ,BS11 = 0x00000800
    // Port x Set bit (bits: 12)
    ,BS12_MASK = 0x00001000
    ,BS12_POS = 12
    ,BS12 = 0x00001000
    // Port x Set bit (bits: 13)
    ,BS13_MASK = 0x00002000
    ,BS13_POS = 13
    ,BS13 = 0x00002000
    // Port x Set bit (bits: 14)
    ,BS14_MASK = 0x00004000
    ,BS14_POS = 14
    ,BS14 = 0x00004000
    // Port x Set bit (bits: 15)
    ,BS15_MASK = 0x00008000
    ,BS15_POS = 15
    ,BS15 = 0x00008000
    // Port x Reset bit (bits: 16)
    ,BR0_MASK = 0x00010000
    ,BR0_POS = 16
    ,BR0 = 0x00010000
    // Port x Reset bit (bits: 17)
    ,BR1_MASK = 0x00020000
    ,BR1_POS = 17
    ,BR1 = 0x00020000
    // Port x Reset bit (bits: 18)
    ,BR2_MASK = 0x00040000
    ,BR2_POS = 18
    ,BR2 = 0x00040000
    // Port x Reset bit (bits: 19)
    ,BR3_MASK = 0x00080000
    ,BR3_POS = 19
    ,BR3 = 0x00080000
    // Port x Reset bit (bits: 20)
    ,BR4_MASK = 0x00100000
    ,BR4_POS = 20
    ,BR4 = 0x00100000
    // Port x Reset bit (bits: 21)
    ,BR5_MASK = 0x00200000
    ,BR5_POS = 21
    ,BR5 = 0x00200000
    // Port x Reset bit (bits: 22)
    ,BR6_MASK = 0x00400000
    ,BR6_POS = 22
    ,BR6 = 0x00400000
    // Port x Reset bit (bits: 23)
    ,BR7_MASK = 0x00800000
    ,BR7_POS = 23
    ,BR7 = 0x00800000
    // Port x Reset bit (bits: 24)
    ,BR8_MASK = 0x01000000
    ,BR8_POS = 24
    ,BR8 = 0x01000000
    // Port x Reset bit (bits: 25)
    ,BR9_MASK = 0x02000000
    ,BR9_POS = 25
    ,BR9 = 0x02000000
    // Port x Reset bit (bits: 26)
    ,BR10_MASK = 0x04000000
    ,BR10_POS = 26
    ,BR10 = 0x04000000
    // Port x Reset bit (bits: 27)
    ,BR11_MASK = 0x08000000
    ,BR11_POS = 27
    ,BR11 = 0x08000000
    // Port x Reset bit (bits: 28)
    ,BR12_MASK = 0x10000000
    ,BR12_POS = 28
    ,BR12 = 0x10000000
    // Port x Reset bit (bits: 29)
    ,BR13_MASK = 0x20000000
    ,BR13_POS = 29
    ,BR13 = 0x20000000
    // Port x Reset bit (bits: 30)
    ,BR14_MASK = 0x40000000
    ,BR14_POS = 30
    ,BR14 = 0x40000000
    // Port x Reset bit (bits: 31)
    ,BR15_MASK = 0x80000000
    ,BR15_POS = 31
    ,BR15 = 0x80000000
    ;
  };
  // Port bit reset register
  struct BRR : reg<32, base + 0x14, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Port x Reset bit (bits: 0)
     BR0_MASK = 0x00000001
    ,BR0_POS = 0
    ,BR0 = 0x00000001
    // Port x Reset bit (bits: 1)
    ,BR1_MASK = 0x00000002
    ,BR1_POS = 1
    ,BR1 = 0x00000002
    // Port x Reset bit (bits: 2)
    ,BR2_MASK = 0x00000004
    ,BR2_POS = 2
    ,BR2 = 0x00000004
    // Port x Reset bit (bits: 3)
    ,BR3_MASK = 0x00000008
    ,BR3_POS = 3
    ,BR3 = 0x00000008
    // Port x Reset bit (bits: 4)
    ,BR4_MASK = 0x00000010
    ,BR4_POS = 4
    ,BR4 = 0x00000010
    // Port x Reset bit (bits: 5)
    ,BR5_MASK = 0x00000020
    ,BR5_POS = 5
    ,BR5 = 0x00000020
    // Port x Reset bit (bits: 6)
    ,BR6_MASK = 0x00000040
    ,BR6_POS = 6
    ,BR6 = 0x00000040
    // Port x Reset bit (bits: 7)
    ,BR7_MASK = 0x00000080
    ,BR7_POS = 7
    ,BR7 = 0x00000080
    // Port x Reset bit (bits: 8)
    ,BR8_MASK = 0x00000100
    ,BR8_POS = 8
    ,BR8 = 0x00000100
    // Port x Reset bit (bits: 9)
    ,BR9_MASK = 0x00000200
    ,BR9_POS = 9
    ,BR9 = 0x00000200
    // Port x Reset bit (bits: 10)
    ,BR10_MASK = 0x00000400
    ,BR10_POS = 10
    ,BR10 = 0x00000400
    // Port x Reset bit (bits: 11)
    ,BR11_MASK = 0x00000800
    ,BR11_POS = 11
    ,BR11 = 0x00000800
    // Port x Reset bit (bits: 12)
    ,BR12_MASK = 0x00001000
    ,BR12_POS = 12
    ,BR12 = 0x00001000
    // Port x Reset bit (bits: 13)
    ,BR13_MASK = 0x00002000
    ,BR13_POS = 13
    ,BR13 = 0x00002000
    // Port x Reset bit (bits: 14)
    ,BR14_MASK = 0x00004000
    ,BR14_POS = 14
    ,BR14 = 0x00004000
    // Port x Reset bit (bits: 15)
    ,BR15_MASK = 0x00008000
    ,BR15_POS = 15
    ,BR15 = 0x00008000
    ;
  };
  // Port configuration lock register
  struct LCKR : reg<32, base + 0x18, 0x00000000, 0x00000000>
  {
    static constexpr type
    // Port x Lock bit y (y = 0 .. 15) (bits: 0)
     LCK0_MASK = 0x00000001
    ,LCK0_POS = 0
    ,LCK0 = 0x00000001
    // Port x Lock bit y (y = 0 .. 15) (bits: 1)
    ,LCK1_MASK = 0x00000002
    ,LCK1_POS = 1
    ,LCK1 = 0x00000002
    // Port x Lock bit y (y = 0 .. 15) (bits: 2)
    ,LCK2_MASK = 0x00000004
    ,LCK2_POS = 2
    ,LCK2 = 0x00000004
    // Port x Lock bit y (y = 0 .. 15) (bits: 3)
    ,LCK3_MASK = 0x00000008
    ,LCK3_POS = 3
    ,LCK3 = 0x00000008
    // Port x Lock bit y (y = 0 .. 15) (bits: 4)
    ,LCK4_MASK = 0x00000010
    ,LCK4_POS = 4
    ,LCK4 = 0x00000010
    // Port x Lock bit y (y = 0 .. 15) (bits: 5)
    ,LCK5_MASK = 0x00000020
    ,LCK5_POS = 5
    ,LCK5 = 0x00000020
    // Port x Lock bit y (y = 0 .. 15) (bits: 6)
    ,LCK6_MASK = 0x00000040
    ,LCK6_POS = 6
    ,LCK6 = 0x00000040
    // Port x Lock bit y (y = 0 .. 15) (bits: 7)
    ,LCK7_MASK = 0x00000080
    ,LCK7_POS = 7
    ,LCK7 = 0x00000080
    // Port x Lock bit y (y = 0 .. 15) (bits: 8)
    ,LCK8_MASK = 0x00000100
    ,LCK8_POS = 8
    ,LCK8 = 0x00000100
    // Port x Lock bit y (y = 0 .. 15) (bits: 9)
    ,LCK9_MASK = 0x00000200
    ,LCK9_POS = 9
    ,LCK9 = 0x00000200
    // Port x Lock bit y (y = 0 .. 15) (bits: 10)
    ,LCK10_MASK = 0x00000400
    ,LCK10_POS = 10
    ,LCK10 = 0x00000400
    // Port x Lock bit y (y = 0 .. 15) (bits: 11)
    ,LCK11_MASK = 0x00000800
    ,LCK11_POS = 11
    ,LCK11 = 0x00000800
    // Port x Lock bit y (y = 0 .. 15) (bits: 12)
    ,LCK12_MASK = 0x00001000
    ,LCK12_POS = 12
    ,LCK12 = 0x00001000
    // Port x Lock bit y (y = 0 .. 15) (bits: 13)
    ,LCK13_MASK = 0x00002000
    ,LCK13_POS = 13
    ,LCK13 = 0x00002000
    // Port x Lock bit y (y = 0 .. 15) (bits: 14)
    ,LCK14_MASK = 0x00004000
    ,LCK14_POS = 14
    ,LCK14 = 0x00004000
    // Port x Lock bit y (y = 0 .. 15) (bits: 15)
    ,LCK15_MASK = 0x00008000
    ,LCK15_POS = 15
    ,LCK15 = 0x00008000
    // Lock key (bits: 16)
    ,LCKK_MASK = 0x00010000
    ,LCKK_POS = 16
    ,LCKK = 0x00010000
    ;
  };
}; // struct GPIOD

} // namespace lmcu::device

