/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// IO Mode/AFS Setting
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct IOM
{
  static constexpr auto ip_ver = ip_version::_1;

  // PIN IO control register (count: 15)
  struct CR : reg<ip_ver, base + 0x0, 0x00000000, 15>
  {
    static constexpr typename CR::type
    // Pin alternate function select. Refer the GPIO AFS table for detail information (bits: 15-12)
     AFS_MASK = 0x0000F000
    ,AFS_POS = 12
    ,AFS_AF0 = 0x00000000 
    ,AFS_AF1 = 0x00001000 
    ,AFS_AF2 = 0x00002000 
    ,AFS_AF3 = 0x00003000 
    ,AFS_AF4 = 0x00004000 
    ,AFS_AF5 = 0x00005000 
    ,AFS_AF6 = 0x00006000 
    ,AFS_AF7 = 0x00007000 
    ,AFS_AF8 = 0x00008000 
    ,AFS_AF9 = 0x00009000 
    ,AFS_AF10 = 0x0000A000 
    // Pin input deglitch filter clock divider select (bits: 11-10)
    ,FDIV_MASK = 0x00000C00
    ,FDIV_POS = 10
    ,FDIV_BYPASS = 0x00000000 // Bypass filter
    ,FDIV_DIV1 = 0x00000400 // Divided by 1
    ,FDIV_DIV4 = 0x00000800 // Divided by 4
    ,FDIV_DIV16 = 0x00000C00 // Divided by 16
    // Pin output drive strength select (bits: 9-8)
    ,ODC_MASK = 0x00000300
    ,ODC_POS = 8
    ,ODC_LEVEL0 = 0x00000000 // Drive strength-full
    ,ODC_LEVEL1 = 0x00000100 // Drive strength-1/2
    ,ODC_LEVEL2 = 0x00000200 // Drive strength-1/4
    ,ODC_LEVEL3 = 0x00000300 // Drive strength-1/8
    // Pin input inverse enable bit (bits: 7)
    ,INV_MASK = 0x00000080
    ,INV_POS = 7
    ,INV_DISABLE = 0x00000000 
    ,INV_ENABLE = 0x00000080 
    // Pin pull-up resister enable bit (bits: 5)
    ,PU_MASK = 0x00000020
    ,PU_POS = 5
    ,PU_DISABLE = 0x00000000 
    ,PU_ENABLE = 0x00000020 
    // Pin output high speed mode enable bit (bits: 3)
    ,HS_MASK = 0x00000008
    ,HS_POS = 3
    ,HS_DISABLE = 0x00000000 
    ,HS_ENABLE = 0x00000008 
    // Pin IO mode control bits (bits: 2-0)
    ,IOM_MASK = 0x00000007
    ,IOM_POS = 0
    ,IOM_AIO = 0x00000000 // analog IO
    ,IOM_ODO = 0x00000001 // open drain output
    ,IOM_PPO = 0x00000002 // push pull output
    ,IOM_DIN = 0x00000003 // Digital input
    ,CR_MASK = 0x0000FFAF
    ;
  };
  // Port input filter control register
  struct FLT : reg<ip_ver, base + 0x40>
  {
    static constexpr typename FLT::type
    // Port input deglitch filter clock source select for all pins of the port (bits: 2-0)
     FCKS_MASK = 0x00000007
    ,FCKS_POS = 0
    ,FCKS_CLK_AHB = 0x00000000 
    ,FCKS_CLK_AHB_DIV8 = 0x00000001 // CLK_AHB divide by 8
    ,FCKS_CLK_ILRCO = 0x00000002 
    ,FCKS_TM00_TRGO = 0x00000003 
    ,FCKS_CK_UT = 0x00000004 
    ,FLT_MASK = 0x00000007
    ;
  };
}; // struct IOM

} // namespace lmcu::device::ip::v1

