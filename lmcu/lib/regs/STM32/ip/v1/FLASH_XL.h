/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// FLASH controller
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct FLASH_XL
{
  // FPEC key register2
  struct KEYR2 : reg<base + 0x44>
  {
    static constexpr typename KEYR2::type
    // (bits: 31-0)
     VAL_MASK = 0xFFFFFFFF
    ,VAL_POS = 0
    ,VAL_RDPRT = 0x000000A5 
    ,VAL_KEY1 = 0x45670123 
    ,VAL_KEY2 = 0xCDEF89AB 
    ,KEYR2_MASK = 0xFFFFFFFF
    ;
  };
  // Flash status register2
  struct SR2 : reg<base + 0x4C>
  {
    static constexpr typename SR2::type
    // Busy (bits: 0)
     BSY_MASK = 0x00000001
    ,BSY_POS = 0
    ,BSY = 0x00000001
    // Programming error (bits: 2)
    ,PGERR_MASK = 0x00000004
    ,PGERR_POS = 2
    ,PGERR = 0x00000004
    // Write protection error (bits: 4)
    ,WRPRTERR_MASK = 0x00000010
    ,WRPRTERR_POS = 4
    ,WRPRTERR = 0x00000010
    // End of operation (bits: 5)
    ,EOP_MASK = 0x00000020
    ,EOP_POS = 5
    ,EOP = 0x00000020
    ,SR2_MASK = 0x00000035
    ;
  };
  // Flash control register2
  struct CR2 : reg<base + 0x50, 0x00000080>
  {
    static constexpr typename CR2::type
    // Programming (bits: 0)
     PG_MASK = 0x00000001
    ,PG_POS = 0
    ,PG = 0x00000001
    // Page erase (bits: 1)
    ,PER_MASK = 0x00000002
    ,PER_POS = 1
    ,PER = 0x00000002
    // Mass erase (bits: 2)
    ,MER_MASK = 0x00000004
    ,MER_POS = 2
    ,MER = 0x00000004
    // Start (bits: 6)
    ,STRT_MASK = 0x00000040
    ,STRT_POS = 6
    ,STRT = 0x00000040
    // Lock (bits: 7)
    ,LOCK_MASK = 0x00000080
    ,LOCK_POS = 7
    ,LOCK = 0x00000080
    // Error interrupt enable (bits: 10)
    ,ERRIE_MASK = 0x00000400
    ,ERRIE_POS = 10
    ,ERRIE = 0x00000400
    // End of operation interrupt enable (bits: 12)
    ,EOPIE_MASK = 0x00001000
    ,EOPIE_POS = 12
    ,EOPIE = 0x00001000
    ,CR2_MASK = 0x000014C7
    ;
  };
  // Flash address register2
  using AR2 = reg<base + 0x54>;
  // Flash access control register
  struct ACR : reg<base + 0x0, 0x00000030>
  {
    static constexpr typename ACR::type
    // Latency (bits: 2-0)
     LATENCY_MASK = 0x00000007
    ,LATENCY_POS = 0
    ,LATENCY_0 = 0x00000000 // Zero wait state, if 0 < SYSCLK ≤ 24 MHz
    ,LATENCY_1 = 0x00000001 // One wait state, if 24 MHz < SYSCLK ≤ 48 MHz
    ,LATENCY_2 = 0x00000002 // Two wait states, if 48 MHz < SYSCLK ≤ 72 MHz
    // Flash half cycle access enable (bits: 3)
    ,HLFCYA_MASK = 0x00000008
    ,HLFCYA_POS = 3
    ,HLFCYA = 0x00000008
    // Prefetch buffer enable (bits: 4)
    ,PRFTBE_MASK = 0x00000010
    ,PRFTBE_POS = 4
    ,PRFTBE = 0x00000010
    // Prefetch buffer status (bits: 5)
    ,PRFTBS_MASK = 0x00000020
    ,PRFTBS_POS = 5
    ,PRFTBS = 0x00000020
    ,ACR_MASK = 0x0000003F
    ;
  };
  // FPEC key register
  struct KEYR : reg<base + 0x4>
  {
    static constexpr typename KEYR::type
    // (bits: 31-0)
     VAL_MASK = 0xFFFFFFFF
    ,VAL_POS = 0
    ,VAL_RDPRT = 0x000000A5 
    ,VAL_KEY1 = 0x45670123 
    ,VAL_KEY2 = 0xCDEF89AB 
    ,KEYR_MASK = 0xFFFFFFFF
    ;
  };
  // Flash OPTKEY register
  using OPTKEYR = reg<base + 0x8>;
  // Flash status register
  struct SR : reg<base + 0xC>
  {
    static constexpr typename SR::type
    // Busy (bits: 0)
     BSY_MASK = 0x00000001
    ,BSY_POS = 0
    ,BSY = 0x00000001
    // Programming error (bits: 2)
    ,PGERR_MASK = 0x00000004
    ,PGERR_POS = 2
    ,PGERR = 0x00000004
    // Write protection error (bits: 4)
    ,WRPRTERR_MASK = 0x00000010
    ,WRPRTERR_POS = 4
    ,WRPRTERR = 0x00000010
    // End of operation (bits: 5)
    ,EOP_MASK = 0x00000020
    ,EOP_POS = 5
    ,EOP = 0x00000020
    ,SR_MASK = 0x00000035
    ;
  };
  // Flash control register
  struct CR : reg<base + 0x10, 0x00000080>
  {
    static constexpr typename CR::type
    // Programming (bits: 0)
     PG_MASK = 0x00000001
    ,PG_POS = 0
    ,PG = 0x00000001
    // Page erase (bits: 1)
    ,PER_MASK = 0x00000002
    ,PER_POS = 1
    ,PER = 0x00000002
    // Mass erase (bits: 2)
    ,MER_MASK = 0x00000004
    ,MER_POS = 2
    ,MER = 0x00000004
    // Option byte programming (bits: 4)
    ,OPTPG_MASK = 0x00000010
    ,OPTPG_POS = 4
    ,OPTPG = 0x00000010
    // Option byte erase (bits: 5)
    ,OPTER_MASK = 0x00000020
    ,OPTER_POS = 5
    ,OPTER = 0x00000020
    // Start (bits: 6)
    ,STRT_MASK = 0x00000040
    ,STRT_POS = 6
    ,STRT = 0x00000040
    // Lock (bits: 7)
    ,LOCK_MASK = 0x00000080
    ,LOCK_POS = 7
    ,LOCK = 0x00000080
    // Option bytes write enable (bits: 9)
    ,OPTWRE_MASK = 0x00000200
    ,OPTWRE_POS = 9
    ,OPTWRE = 0x00000200
    // Error interrupt enable (bits: 10)
    ,ERRIE_MASK = 0x00000400
    ,ERRIE_POS = 10
    ,ERRIE = 0x00000400
    // End of operation interrupt enable (bits: 12)
    ,EOPIE_MASK = 0x00001000
    ,EOPIE_POS = 12
    ,EOPIE = 0x00001000
    ,CR_MASK = 0x000016F7
    ;
  };
  // Flash address register
  using AR = reg<base + 0x14>;
  // Option byte register
  struct OBR : reg<base + 0x1C>
  {
    static constexpr typename OBR::type
    // Option byte error (bits: 0)
     OPTERR_MASK = 0x00000001
    ,OPTERR_POS = 0
    ,OPTERR = 0x00000001
    // Read protection (bits: 1)
    ,RDPRT_MASK = 0x00000002
    ,RDPRT_POS = 1
    ,RDPRT = 0x00000002
    // User option bytes (bits: 9-2)
    ,USER_MASK = 0x000003FC
    ,USER_POS = 2
    ,USER_WDG_SW = 0x00000010 
    ,USER_NRST_STOP = 0x00000020 
    ,USER_NRST_STDBY = 0x00000040 
    // (bits: 17-10)
    ,DATA0_MASK = 0x0003FC00
    ,DATA0_POS = 10
    // (bits: 25-18)
    ,DATA1_MASK = 0x03FC0000
    ,DATA1_POS = 18
    ,OBR_MASK = 0x03FFFFFF
    ;
  };
  // Write protection register
  using WRPR = reg<base + 0x20, 0xFFFFFFFF>;
}; // struct FLASH_XL

} // namespace lmcu::device::ip::v1

