/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// Direct memory access controller
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct DMA
{
  static constexpr auto ip_ver = ip_version::_1;

  // DMA interrupt status register
  struct ISR : reg<ip_ver, base + 0x0>
  {
    static constexpr typename ISR::type
    // Channel global interrupt flag (bits: 0)
     GIF1_MASK = 0x00000001
    ,GIF1_POS = 0
    ,GIF1 = 0x00000001
    // Channel transfer complete flag (bits: 1)
    ,TCIF1_MASK = 0x00000002
    ,TCIF1_POS = 1
    ,TCIF1 = 0x00000002
    // Channel half transfer flag (bits: 2)
    ,HTIF1_MASK = 0x00000004
    ,HTIF1_POS = 2
    ,HTIF1 = 0x00000004
    // Channel transfer error flag (bits: 3)
    ,TEIF1_MASK = 0x00000008
    ,TEIF1_POS = 3
    ,TEIF1 = 0x00000008
    // Channel global interrupt flag (bits: 4)
    ,GIF2_MASK = 0x00000010
    ,GIF2_POS = 4
    ,GIF2 = 0x00000010
    // Channel transfer complete flag (bits: 5)
    ,TCIF2_MASK = 0x00000020
    ,TCIF2_POS = 5
    ,TCIF2 = 0x00000020
    // Channel half transfer flag (bits: 6)
    ,HTIF2_MASK = 0x00000040
    ,HTIF2_POS = 6
    ,HTIF2 = 0x00000040
    // Channel transfer error flag (bits: 7)
    ,TEIF2_MASK = 0x00000080
    ,TEIF2_POS = 7
    ,TEIF2 = 0x00000080
    // Channel global interrupt flag (bits: 8)
    ,GIF3_MASK = 0x00000100
    ,GIF3_POS = 8
    ,GIF3 = 0x00000100
    // Channel transfer complete flag (bits: 9)
    ,TCIF3_MASK = 0x00000200
    ,TCIF3_POS = 9
    ,TCIF3 = 0x00000200
    // Channel half transfer flag (bits: 10)
    ,HTIF3_MASK = 0x00000400
    ,HTIF3_POS = 10
    ,HTIF3 = 0x00000400
    // Channel transfer error flag (bits: 11)
    ,TEIF3_MASK = 0x00000800
    ,TEIF3_POS = 11
    ,TEIF3 = 0x00000800
    // Channel global interrupt flag (bits: 12)
    ,GIF4_MASK = 0x00001000
    ,GIF4_POS = 12
    ,GIF4 = 0x00001000
    // Channel transfer complete flag (bits: 13)
    ,TCIF4_MASK = 0x00002000
    ,TCIF4_POS = 13
    ,TCIF4 = 0x00002000
    // Channel half transfer flag (bits: 14)
    ,HTIF4_MASK = 0x00004000
    ,HTIF4_POS = 14
    ,HTIF4 = 0x00004000
    // Channel transfer error flag (bits: 15)
    ,TEIF4_MASK = 0x00008000
    ,TEIF4_POS = 15
    ,TEIF4 = 0x00008000
    // Channel global interrupt flag (bits: 16)
    ,GIF5_MASK = 0x00010000
    ,GIF5_POS = 16
    ,GIF5 = 0x00010000
    // Channel transfer complete flag (bits: 17)
    ,TCIF5_MASK = 0x00020000
    ,TCIF5_POS = 17
    ,TCIF5 = 0x00020000
    // Channel half transfer flag (bits: 18)
    ,HTIF5_MASK = 0x00040000
    ,HTIF5_POS = 18
    ,HTIF5 = 0x00040000
    // Channel transfer error flag (bits: 19)
    ,TEIF5_MASK = 0x00080000
    ,TEIF5_POS = 19
    ,TEIF5 = 0x00080000
    // Channel global interrupt flag (bits: 20)
    ,GIF6_MASK = 0x00100000
    ,GIF6_POS = 20
    ,GIF6 = 0x00100000
    // Channel transfer complete flag (bits: 21)
    ,TCIF6_MASK = 0x00200000
    ,TCIF6_POS = 21
    ,TCIF6 = 0x00200000
    // Channel half transfer flag (bits: 22)
    ,HTIF6_MASK = 0x00400000
    ,HTIF6_POS = 22
    ,HTIF6 = 0x00400000
    // Channel transfer error flag (bits: 23)
    ,TEIF6_MASK = 0x00800000
    ,TEIF6_POS = 23
    ,TEIF6 = 0x00800000
    // Channel global interrupt flag (bits: 24)
    ,GIF7_MASK = 0x01000000
    ,GIF7_POS = 24
    ,GIF7 = 0x01000000
    // Channel transfer complete flag (bits: 25)
    ,TCIF7_MASK = 0x02000000
    ,TCIF7_POS = 25
    ,TCIF7 = 0x02000000
    // Channel half transfer flag (bits: 26)
    ,HTIF7_MASK = 0x04000000
    ,HTIF7_POS = 26
    ,HTIF7 = 0x04000000
    // Channel transfer error flag (bits: 27)
    ,TEIF7_MASK = 0x08000000
    ,TEIF7_POS = 27
    ,TEIF7 = 0x08000000
    ,ISR_MASK = 0x0FFFFFFF
    ;
  };
  // DMA interrupt flag clear register
  struct IFCR : reg<ip_ver, base + 0x4>
  {
    static constexpr typename IFCR::type
    // Channel global interrupt clear (bits: 0)
     CGIF1_MASK = 0x00000001
    ,CGIF1_POS = 0
    ,CGIF1 = 0x00000001
    // Channel transfer complete clear (bits: 1)
    ,CTCIF1_MASK = 0x00000002
    ,CTCIF1_POS = 1
    ,CTCIF1 = 0x00000002
    // Channel half transfer clear (bits: 2)
    ,CHTIF1_MASK = 0x00000004
    ,CHTIF1_POS = 2
    ,CHTIF1 = 0x00000004
    // Channel transfer error clear (bits: 3)
    ,CTEIF1_MASK = 0x00000008
    ,CTEIF1_POS = 3
    ,CTEIF1 = 0x00000008
    // Channel global interrupt clear (bits: 4)
    ,CGIF2_MASK = 0x00000010
    ,CGIF2_POS = 4
    ,CGIF2 = 0x00000010
    // Channel transfer complete clear (bits: 5)
    ,CTCIF2_MASK = 0x00000020
    ,CTCIF2_POS = 5
    ,CTCIF2 = 0x00000020
    // Channel half transfer clear (bits: 6)
    ,CHTIF2_MASK = 0x00000040
    ,CHTIF2_POS = 6
    ,CHTIF2 = 0x00000040
    // Channel transfer error clear (bits: 7)
    ,CTEIF2_MASK = 0x00000080
    ,CTEIF2_POS = 7
    ,CTEIF2 = 0x00000080
    // Channel global interrupt clear (bits: 8)
    ,CGIF3_MASK = 0x00000100
    ,CGIF3_POS = 8
    ,CGIF3 = 0x00000100
    // Channel transfer complete clear (bits: 9)
    ,CTCIF3_MASK = 0x00000200
    ,CTCIF3_POS = 9
    ,CTCIF3 = 0x00000200
    // Channel half transfer clear (bits: 10)
    ,CHTIF3_MASK = 0x00000400
    ,CHTIF3_POS = 10
    ,CHTIF3 = 0x00000400
    // Channel transfer error clear (bits: 11)
    ,CTEIF3_MASK = 0x00000800
    ,CTEIF3_POS = 11
    ,CTEIF3 = 0x00000800
    // Channel global interrupt clear (bits: 12)
    ,CGIF4_MASK = 0x00001000
    ,CGIF4_POS = 12
    ,CGIF4 = 0x00001000
    // Channel transfer complete clear (bits: 13)
    ,CTCIF4_MASK = 0x00002000
    ,CTCIF4_POS = 13
    ,CTCIF4 = 0x00002000
    // Channel half transfer clear (bits: 14)
    ,CHTIF4_MASK = 0x00004000
    ,CHTIF4_POS = 14
    ,CHTIF4 = 0x00004000
    // Channel transfer error clear (bits: 15)
    ,CTEIF4_MASK = 0x00008000
    ,CTEIF4_POS = 15
    ,CTEIF4 = 0x00008000
    // Channel global interrupt clear (bits: 16)
    ,CGIF5_MASK = 0x00010000
    ,CGIF5_POS = 16
    ,CGIF5 = 0x00010000
    // Channel transfer complete clear (bits: 17)
    ,CTCIF5_MASK = 0x00020000
    ,CTCIF5_POS = 17
    ,CTCIF5 = 0x00020000
    // Channel half transfer clear (bits: 18)
    ,CHTIF5_MASK = 0x00040000
    ,CHTIF5_POS = 18
    ,CHTIF5 = 0x00040000
    // Channel transfer error clear (bits: 19)
    ,CTEIF5_MASK = 0x00080000
    ,CTEIF5_POS = 19
    ,CTEIF5 = 0x00080000
    // Channel global interrupt clear (bits: 20)
    ,CGIF6_MASK = 0x00100000
    ,CGIF6_POS = 20
    ,CGIF6 = 0x00100000
    // Channel transfer complete clear (bits: 21)
    ,CTCIF6_MASK = 0x00200000
    ,CTCIF6_POS = 21
    ,CTCIF6 = 0x00200000
    // Channel half transfer clear (bits: 22)
    ,CHTIF6_MASK = 0x00400000
    ,CHTIF6_POS = 22
    ,CHTIF6 = 0x00400000
    // Channel transfer error clear (bits: 23)
    ,CTEIF6_MASK = 0x00800000
    ,CTEIF6_POS = 23
    ,CTEIF6 = 0x00800000
    // Channel global interrupt clear (bits: 24)
    ,CGIF7_MASK = 0x01000000
    ,CGIF7_POS = 24
    ,CGIF7 = 0x01000000
    // Channel transfer complete clear (bits: 25)
    ,CTCIF7_MASK = 0x02000000
    ,CTCIF7_POS = 25
    ,CTCIF7 = 0x02000000
    // Channel half transfer clear (bits: 26)
    ,CHTIF7_MASK = 0x04000000
    ,CHTIF7_POS = 26
    ,CHTIF7 = 0x04000000
    // Channel transfer error clear (bits: 27)
    ,CTEIF7_MASK = 0x08000000
    ,CTEIF7_POS = 27
    ,CTEIF7 = 0x08000000
    ,IFCR_MASK = 0x0FFFFFFF
    ;
  };
  // DMA channel configuration register (count: 7)
  struct CCR : reg<ip_ver, base + 0x8, 0x00000000, 7, 32, 32>
  {
    static constexpr typename CCR::type
    // Channel enable (bits: 0)
     EN_MASK = 0x00000001
    ,EN_POS = 0
    ,EN = 0x00000001
    // Transfer complete interrupt enable (bits: 1)
    ,TCIE_MASK = 0x00000002
    ,TCIE_POS = 1
    ,TCIE = 0x00000002
    // Half transfer interrupt enable (bits: 2)
    ,HTIE_MASK = 0x00000004
    ,HTIE_POS = 2
    ,HTIE = 0x00000004
    // Transfer error interrupt enable (bits: 3)
    ,TEIE_MASK = 0x00000008
    ,TEIE_POS = 3
    ,TEIE = 0x00000008
    // Data transfer direction (bits: 4)
    ,DIR_MASK = 0x00000010
    ,DIR_POS = 4
    ,DIR = 0x00000010
    // Circular mode (bits: 5)
    ,CIRC_MASK = 0x00000020
    ,CIRC_POS = 5
    ,CIRC = 0x00000020
    // Peripheral increment mode (bits: 6)
    ,PINC_MASK = 0x00000040
    ,PINC_POS = 6
    ,PINC = 0x00000040
    // Memory increment mode (bits: 7)
    ,MINC_MASK = 0x00000080
    ,MINC_POS = 7
    ,MINC = 0x00000080
    // Peripheral size (bits: 9-8)
    ,PSIZE_MASK = 0x00000300
    ,PSIZE_POS = 8
    // Memory size (bits: 11-10)
    ,MSIZE_MASK = 0x00000C00
    ,MSIZE_POS = 10
    // Channel priority level (bits: 13-12)
    ,PL_MASK = 0x00003000
    ,PL_POS = 12
    // Memory to memory mode (bits: 14)
    ,MEM2MEM_MASK = 0x00004000
    ,MEM2MEM_POS = 14
    ,MEM2MEM = 0x00004000
    ,CCR_MASK = 0x00007FFF
    ;
  };
  // DMA channel number of data register (count: 7)
  struct CNDTR : reg<ip_ver, base + 0xC, 0x00000000, 7, 32, 32>
  {
    static constexpr typename CNDTR::type
    // Number of data to transfer (bits: 15-0)
     NDT_MASK = 0x0000FFFF
    ,NDT_POS = 0
    ,CNDTR_MASK = 0x0000FFFF
    ;
  };
  // DMA channel peripheral address register (count: 7)
  using CPAR = reg<ip_ver, base + 0x10, 0x00000000, 7, 32, 32>;
  // DMA channel memory address register (count: 7)
  using CMAR = reg<ip_ver, base + 0x14, 0x00000000, 7, 32, 32>;
}; // struct DMA

} // namespace lmcu::device::ip::v1

