/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// General Purpose IO Port Control
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct IOP
{
  static constexpr auto ip_ver = ip_version::_1;

  // Output data register
  struct OUT : reg<ip_ver, base + 0x0, 0xFFFFFFFF>
  {
    static constexpr typename OUT::type
    // IO pin 15 output data bit (bits: 15)
     OUT15_MASK = 0x00008000
    ,OUT15_POS = 15
    ,OUT15 = 0x00008000
    // IO pin 14 output data bit (bits: 14)
    ,OUT14_MASK = 0x00004000
    ,OUT14_POS = 14
    ,OUT14 = 0x00004000
    // IO pin 13 output data bit (bits: 13)
    ,OUT13_MASK = 0x00002000
    ,OUT13_POS = 13
    ,OUT13 = 0x00002000
    // IO pin 12 output data bit (bits: 12)
    ,OUT12_MASK = 0x00001000
    ,OUT12_POS = 12
    ,OUT12 = 0x00001000
    // IO pin 11 output data bit (bits: 11)
    ,OUT11_MASK = 0x00000800
    ,OUT11_POS = 11
    ,OUT11 = 0x00000800
    // IO pin 10 output data bit (bits: 10)
    ,OUT10_MASK = 0x00000400
    ,OUT10_POS = 10
    ,OUT10 = 0x00000400
    // IO pin 9 output data bit (bits: 9)
    ,OUT9_MASK = 0x00000200
    ,OUT9_POS = 9
    ,OUT9 = 0x00000200
    // IO pin 8 output data bit (bits: 8)
    ,OUT8_MASK = 0x00000100
    ,OUT8_POS = 8
    ,OUT8 = 0x00000100
    // IO pin 7 output data bit (bits: 7)
    ,OUT7_MASK = 0x00000080
    ,OUT7_POS = 7
    ,OUT7 = 0x00000080
    // IO pin 6 output data bit (bits: 6)
    ,OUT6_MASK = 0x00000040
    ,OUT6_POS = 6
    ,OUT6 = 0x00000040
    // IO pin 5 output data bit (bits: 5)
    ,OUT5_MASK = 0x00000020
    ,OUT5_POS = 5
    ,OUT5 = 0x00000020
    // IO pin 4 output data bit (bits: 4)
    ,OUT4_MASK = 0x00000010
    ,OUT4_POS = 4
    ,OUT4 = 0x00000010
    // IO pin 3 output data bit (bits: 3)
    ,OUT3_MASK = 0x00000008
    ,OUT3_POS = 3
    ,OUT3 = 0x00000008
    // IO pin 2 output data bit (bits: 2)
    ,OUT2_MASK = 0x00000004
    ,OUT2_POS = 2
    ,OUT2 = 0x00000004
    // IO pin 1 output data bit (bits: 1)
    ,OUT1_MASK = 0x00000002
    ,OUT1_POS = 1
    ,OUT1 = 0x00000002
    // IO pin 0 output data bit (bits: 0)
    ,OUT0_MASK = 0x00000001
    ,OUT0_POS = 0
    ,OUT0 = 0x00000001
    ,OUT_MASK = 0x0000FFFF
    ;
  };
  // Input data register
  struct IN : reg<ip_ver, base + 0x4, 0x000000F0>
  {
    static constexpr typename IN::type
    // IO pin 15 input pin status (bits: 15)
     IN15_MASK = 0x00008000
    ,IN15_POS = 15
    ,IN15 = 0x00008000
    // IO pin 14 input pin status (bits: 14)
    ,IN14_MASK = 0x00004000
    ,IN14_POS = 14
    ,IN14 = 0x00004000
    // IO pin 13 input pin status (bits: 13)
    ,IN13_MASK = 0x00002000
    ,IN13_POS = 13
    ,IN13 = 0x00002000
    // IO pin 12 input pin status (bits: 12)
    ,IN12_MASK = 0x00001000
    ,IN12_POS = 12
    ,IN12 = 0x00001000
    // IO pin 11 input pin status (bits: 11)
    ,IN11_MASK = 0x00000800
    ,IN11_POS = 11
    ,IN11 = 0x00000800
    // IO pin 10 input pin status (bits: 10)
    ,IN10_MASK = 0x00000400
    ,IN10_POS = 10
    ,IN10 = 0x00000400
    // IO pin 9 input pin status (bits: 9)
    ,IN9_MASK = 0x00000200
    ,IN9_POS = 9
    ,IN9 = 0x00000200
    // IO pin 8 input pin status (bits: 8)
    ,IN8_MASK = 0x00000100
    ,IN8_POS = 8
    ,IN8 = 0x00000100
    // IO pin 7 input pin status (bits: 7)
    ,IN7_MASK = 0x00000080
    ,IN7_POS = 7
    ,IN7 = 0x00000080
    // IO pin 6 input pin status (bits: 6)
    ,IN6_MASK = 0x00000040
    ,IN6_POS = 6
    ,IN6 = 0x00000040
    // IO pin 5 input pin status (bits: 5)
    ,IN5_MASK = 0x00000020
    ,IN5_POS = 5
    ,IN5 = 0x00000020
    // IO pin 4 input pin status (bits: 4)
    ,IN4_MASK = 0x00000010
    ,IN4_POS = 4
    ,IN4 = 0x00000010
    // IO pin 3 input pin status (bits: 3)
    ,IN3_MASK = 0x00000008
    ,IN3_POS = 3
    ,IN3 = 0x00000008
    // IO pin 2 input pin status (bits: 2)
    ,IN2_MASK = 0x00000004
    ,IN2_POS = 2
    ,IN2 = 0x00000004
    // IO pin 1 input pin status (bits: 1)
    ,IN1_MASK = 0x00000002
    ,IN1_POS = 1
    ,IN1 = 0x00000002
    // IO pin 0 input pin status (bits: 0)
    ,IN0_MASK = 0x00000001
    ,IN0_POS = 0
    ,IN0 = 0x00000001
    ,IN_MASK = 0x0000FFFF
    ;
  };
  // Port set / clear register
  struct SC : reg<ip_ver, base + 0x8>
  {
    static constexpr typename SC::type
    // IO pin 15 clear data bit. This bit is no effect for writing 0 (bits: 31)
     CLR15_MASK = 0x80000000
    ,CLR15_POS = 31
    ,CLR15 = 0x80000000
    // IO pin 14 clear data bit. This bit is no effect for writing 0 (bits: 30)
    ,CLR14_MASK = 0x40000000
    ,CLR14_POS = 30
    ,CLR14 = 0x40000000
    // IO pin 13 clear data bit. This bit is no effect for writing 0 (bits: 29)
    ,CLR13_MASK = 0x20000000
    ,CLR13_POS = 29
    ,CLR13 = 0x20000000
    // IO pin 12 clear data bit. This bit is no effect for writing 0 (bits: 28)
    ,CLR12_MASK = 0x10000000
    ,CLR12_POS = 28
    ,CLR12 = 0x10000000
    // IO pin 11 clear data bit. This bit is no effect for writing 0 (bits: 27)
    ,CLR11_MASK = 0x08000000
    ,CLR11_POS = 27
    ,CLR11 = 0x08000000
    // IO pin 10 clear data bit. This bit is no effect for writing 0 (bits: 26)
    ,CLR10_MASK = 0x04000000
    ,CLR10_POS = 26
    ,CLR10 = 0x04000000
    // IO pin 9 clear data bit. This bit is no effect for writing 0 (bits: 25)
    ,CLR9_MASK = 0x02000000
    ,CLR9_POS = 25
    ,CLR9 = 0x02000000
    // IO pin 8 clear data bit. This bit is no effect for writing 0 (bits: 24)
    ,CLR8_MASK = 0x01000000
    ,CLR8_POS = 24
    ,CLR8 = 0x01000000
    // IO pin 7 clear data bit. This bit is no effect for writing 0 (bits: 23)
    ,CLR7_MASK = 0x00800000
    ,CLR7_POS = 23
    ,CLR7 = 0x00800000
    // IO pin 6 clear data bit. This bit is no effect for writing 0 (bits: 22)
    ,CLR6_MASK = 0x00400000
    ,CLR6_POS = 22
    ,CLR6 = 0x00400000
    // IO pin 5 clear data bit. This bit is no effect for writing 0 (bits: 21)
    ,CLR5_MASK = 0x00200000
    ,CLR5_POS = 21
    ,CLR5 = 0x00200000
    // IO pin 4 clear data bit. This bit is no effect for writing 0 (bits: 20)
    ,CLR4_MASK = 0x00100000
    ,CLR4_POS = 20
    ,CLR4 = 0x00100000
    // IO pin 3 clear data bit. This bit is no effect for writing 0 (bits: 19)
    ,CLR3_MASK = 0x00080000
    ,CLR3_POS = 19
    ,CLR3 = 0x00080000
    // IO pin 2 clear data bit. This bit is no effect for writing 0 (bits: 18)
    ,CLR2_MASK = 0x00040000
    ,CLR2_POS = 18
    ,CLR2 = 0x00040000
    // IO pin 1 clear data bit. This bit is no effect for writing 0 (bits: 17)
    ,CLR1_MASK = 0x00020000
    ,CLR1_POS = 17
    ,CLR1 = 0x00020000
    // IO pin 0 clear data bit. This bit is no effect for writing 0 (bits: 16)
    ,CLR0_MASK = 0x00010000
    ,CLR0_POS = 16
    ,CLR0 = 0x00010000
    // IO pin 15 set data bit. This bit is no effect for writing 0 (bits: 15)
    ,SET15_MASK = 0x00008000
    ,SET15_POS = 15
    ,SET15 = 0x00008000
    // IO pin 14 set data bit. This bit is no effect for writing 0 (bits: 14)
    ,SET14_MASK = 0x00004000
    ,SET14_POS = 14
    ,SET14 = 0x00004000
    // IO pin 13 set data bit. This bit is no effect for writing 0 (bits: 13)
    ,SET13_MASK = 0x00002000
    ,SET13_POS = 13
    ,SET13 = 0x00002000
    // IO pin 12 set data bit. This bit is no effect for writing 0 (bits: 12)
    ,SET12_MASK = 0x00001000
    ,SET12_POS = 12
    ,SET12 = 0x00001000
    // IO pin 11 set data bit. This bit is no effect for writing 0 (bits: 11)
    ,SET11_MASK = 0x00000800
    ,SET11_POS = 11
    ,SET11 = 0x00000800
    // IO pin 10 set data bit. This bit is no effect for writing 0 (bits: 10)
    ,SET10_MASK = 0x00000400
    ,SET10_POS = 10
    ,SET10 = 0x00000400
    // IO pin 9 set data bit. This bit is no effect for writing 0 (bits: 9)
    ,SET9_MASK = 0x00000200
    ,SET9_POS = 9
    ,SET9 = 0x00000200
    // IO pin 8 set data bit. This bit is no effect for writing 0 (bits: 8)
    ,SET8_MASK = 0x00000100
    ,SET8_POS = 8
    ,SET8 = 0x00000100
    // IO pin 7 set data bit. This bit is no effect for writing 0 (bits: 7)
    ,SET7_MASK = 0x00000080
    ,SET7_POS = 7
    ,SET7 = 0x00000080
    // IO pin 6 set data bit. This bit is no effect for writing 0 (bits: 6)
    ,SET6_MASK = 0x00000040
    ,SET6_POS = 6
    ,SET6 = 0x00000040
    // IO pin 5 set data bit. This bit is no effect for writing 0 (bits: 5)
    ,SET5_MASK = 0x00000020
    ,SET5_POS = 5
    ,SET5 = 0x00000020
    // IO pin 4 set data bit. This bit is no effect for writing 0 (bits: 4)
    ,SET4_MASK = 0x00000010
    ,SET4_POS = 4
    ,SET4 = 0x00000010
    // IO pin 3 set data bit. This bit is no effect for writing 0 (bits: 3)
    ,SET3_MASK = 0x00000008
    ,SET3_POS = 3
    ,SET3 = 0x00000008
    // IO pin 2 set data bit. This bit is no effect for writing 0 (bits: 2)
    ,SET2_MASK = 0x00000004
    ,SET2_POS = 2
    ,SET2 = 0x00000004
    // IO pin 1 set data bit. This bit is no effect for writing 0 (bits: 1)
    ,SET1_MASK = 0x00000002
    ,SET1_POS = 1
    ,SET1 = 0x00000002
    // IO pin 0 set data bit. This bit is no effect for writing 0 (bits: 0)
    ,SET0_MASK = 0x00000001
    ,SET0_POS = 0
    ,SET0 = 0x00000001
    ,SC_MASK = 0xFFFFFFFF
    ;
  };
  // Port set and clear register 0
  struct SCR0 : reg<ip_ver, base + 0x10>
  {
    static constexpr typename SCR0::type
    // GPIO Port set or clear bit for P3 (bits: 24)
     SC3_MASK = 0x01000000
    ,SC3_POS = 24
    ,SC3 = 0x01000000
    // GPIO Port set or clear bit for P2 (bits: 16)
    ,SC2_MASK = 0x00010000
    ,SC2_POS = 16
    ,SC2 = 0x00010000
    // GPIO Port set or clear bit for P1 (bits: 8)
    ,SC1_MASK = 0x00000100
    ,SC1_POS = 8
    ,SC1 = 0x00000100
    // GPIO Port set or clear bit for P0 (bits: 0)
    ,SC0_MASK = 0x00000001
    ,SC0_POS = 0
    ,SC0 = 0x00000001
    ,SCR0_MASK = 0x01010101
    ;
  };
  // Port set and clear register 1
  struct SCR1 : reg<ip_ver, base + 0x14>
  {
    static constexpr typename SCR1::type
    // GPIO Port set or clear bit for P6 (bits: 16)
     SC6_MASK = 0x00010000
    ,SC6_POS = 16
    ,SC6 = 0x00010000
    // GPIO Port set or clear bit for P5 (bits: 8)
    ,SC5_MASK = 0x00000100
    ,SC5_POS = 8
    ,SC5 = 0x00000100
    // GPIO Port set or clear bit for P4 (bits: 0)
    ,SC4_MASK = 0x00000001
    ,SC4_POS = 0
    ,SC4 = 0x00000001
    ,SCR1_MASK = 0x00010101
    ;
  };
  // Port set and clear register 2
  struct SCR2 : reg<ip_ver, base + 0x18>
  {
    static constexpr typename SCR2::type
    // GPIO Port set or clear bit for P11 (bits: 24)
     SC11_MASK = 0x01000000
    ,SC11_POS = 24
    ,SC11 = 0x01000000
    // GPIO Port set or clear bit for P10 (bits: 16)
    ,SC10_MASK = 0x00010000
    ,SC10_POS = 16
    ,SC10 = 0x00010000
    // GPIO Port set or clear bit for P9 (bits: 8)
    ,SC9_MASK = 0x00000100
    ,SC9_POS = 8
    ,SC9 = 0x00000100
    // GPIO Port set or clear bit for P8 (bits: 0)
    ,SC8_MASK = 0x00000001
    ,SC8_POS = 0
    ,SC8 = 0x00000001
    ,SCR2_MASK = 0x01010101
    ;
  };
  // Port set and clear register 3
  struct SCR3 : reg<ip_ver, base + 0x1C>
  {
    static constexpr typename SCR3::type
    // GPIO Port set or clear bit for P14 (bits: 16)
     SC14_MASK = 0x00010000
    ,SC14_POS = 16
    ,SC14 = 0x00010000
    // GPIO Port set or clear bit for P13 (bits: 8)
    ,SC13_MASK = 0x00000100
    ,SC13_POS = 8
    ,SC13 = 0x00000100
    // GPIO Port set or clear bit for P12 (bits: 0)
    ,SC12_MASK = 0x00000001
    ,SC12_POS = 0
    ,SC12 = 0x00000001
    ,SCR3_MASK = 0x00010101
    ;
  };
}; // struct IOP

} // namespace lmcu::device::ip::v1

