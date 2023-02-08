/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// I2C Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct I2C
{
  static constexpr auto ip_ver = ip_version::_1;

  // I2C Control Register
  struct I2CON : reg<ip_ver, base + 0x0>
  {
    static constexpr typename I2CON::type
    // Assert Acknowledge Control (bits: 2)
     AA_MASK = 0x00000004
    ,AA_POS = 2
    ,AA = 0x00000004
    // I2C Interrupt Flag When a new I2C state is present in the I2CSTATUS register, the SI flag is set by hardware, and if bit EI (I2CON [7]) is set, the I2C interrupt is requested. SI must be cleared by software. Clear SI by writing 1 to this bit. (bits: 3)
    ,SI_MASK = 0x00000008
    ,SI_POS = 3
    ,SI = 0x00000008
    // I2C STOP Control In Master mode, setting STO to transmit a STOP condition to bus then I2C hardware will check the bus condition if a STOP condition is detected this bit will be cleared by hardware automatically. In a slave mode, setting STO resets I2C hardware to the defined <not addressed> slave mode. This means it is NO LONGER in the slave receiver mode to receive data from the master transmit device. (bits: 4)
    ,STO_MASK = 0x00000010
    ,STO_POS = 4
    ,STO = 0x00000010
    // I2C START Control Setting STA to logic 1 to enter Master mode, the I2C hardware sends a START or repeat START condition to bus when the bus is free. (bits: 5)
    ,STA_MASK = 0x00000020
    ,STA_POS = 5
    ,STA = 0x00000020
    // I2C Controller Enable Control (bits: 6)
    ,ENS1_MASK = 0x00000040
    ,ENS1_POS = 6
    ,ENS1_0 = 0x00000000 // Disabled
    ,ENS1_1 = 0x00000040 // Enabled
    // Interrupt Enable Control (bits: 7)
    ,EI_MASK = 0x00000080
    ,EI_POS = 7
    ,EI_0 = 0x00000000 // I2C interrupt Disabled
    ,EI_1 = 0x00000080 // I2C interrupt Enabled
    ,I2CON_MASK = 0x000000FC
    ;
  };
  // I2C Slave Address Register0
  struct I2CADDR0 : reg<ip_ver, base + 0x4>
  {
    static constexpr typename I2CADDR0::type
    // General Call Function (bits: 0)
     GC_MASK = 0x00000001
    ,GC_POS = 0
    ,GC_0 = 0x00000000 // General Call Function Disabled
    ,GC_1 = 0x00000001 // General Call Function Enabled
    // I2C Address Register The content of this register is irrelevant when I2C is in Master mode. In the slave mode, the seven most significant bits must be loaded with the chip's own address. The I2C hardware will react if either of the address is matched. (bits: 7-1)
    ,I2CADDR_MASK = 0x000000FE
    ,I2CADDR_POS = 1
    ,I2CADDR0_MASK = 0x000000FF
    ;
  };
  // I2C Data Register
  struct I2CDAT : reg<ip_ver, base + 0x8>
  {
    static constexpr typename I2CDAT::type
    // I2C Data Register This field is located with the 8-bit transferred data of I2C serial port. (bits: 7-0)
     I2CDATVAL_MASK = 0x000000FF
    ,I2CDATVAL_POS = 0
    ,I2CDAT_MASK = 0x000000FF
    ;
  };
  // I2C Status Register
  struct I2CSTATUS : reg<ip_ver, base + 0xC, 0x000000F8>
  {
    static constexpr typename I2CSTATUS::type
    // I2C Status Register There are 26 possible status codes. When I2CSTATUS contains 0xF8, no serial interrupt is requested. In addition, states 0x00 stands for a Bus Error. A Bus Error occurs when a START or STOP condition is present at an illegal position in the formation frame. Example of illegal position are during the serial transfer of an address byte, a data byte or an acknowledge bit. (bits: 7-0)
     I2CSTATUSVAL_MASK = 0x000000FF
    ,I2CSTATUSVAL_POS = 0
    ,I2CSTATUS_MASK = 0x000000FF
    ;
  };
  // I2C Clock Divided Register
  struct I2CLK : reg<ip_ver, base + 0x10>
  {
    static constexpr typename I2CLK::type
    // I2C Clock Divided Register Note: The minimum value of I2CLK is 4. (bits: 7-0)
     I2CLKVAL_MASK = 0x000000FF
    ,I2CLKVAL_POS = 0
    ,I2CLK_MASK = 0x000000FF
    ;
  };
  // I2C Time-out Counter Register
  struct I2CTOC : reg<ip_ver, base + 0x14>
  {
    static constexpr typename I2CTOC::type
    // Time-Out Flag This bit is set by hardware when I2C time-out happened and it can interrupt CPU if I2C interrupt enable bit EI (I2CON[7]) is set to 1. Note: Write 1 to clear this bit. (bits: 0)
     TIF_MASK = 0x00000001
    ,TIF_POS = 0
    ,TIF = 0x00000001
    // Time-Out Counter Input Clock Divided By 4 When Enabled, The time-out period is extend 4 times. (bits: 1)
    ,DIV4_MASK = 0x00000002
    ,DIV4_POS = 1
    ,DIV4_0 = 0x00000000 // Disabled
    ,DIV4_1 = 0x00000002 // Enabled
    // Time-Out Counter Enable Control When Enabled, the 14-bit time-out counter will start counting when SI (I2CON[3]) is clear. Setting flag SI SI(I2CON[3]) to high will reset counter and re-start up counting after SI SI(I2CON[3]) is cleared. (bits: 2)
    ,ENTI_MASK = 0x00000004
    ,ENTI_POS = 2
    ,ENTI_0 = 0x00000000 // Disabled
    ,ENTI_1 = 0x00000004 // Enabled
    ,I2CTOC_MASK = 0x00000007
    ;
  };
  // I2C Slave Address Register1
  using I2CADDR1 = reg<ip_ver, base + 0x18>;
  // I2C Slave Address Register2
  using I2CADDR2 = reg<ip_ver, base + 0x1C>;
  // I2C Slave Address Register3
  using I2CADDR3 = reg<ip_ver, base + 0x20>;
  // I2C Slave Address Mask Register0
  struct I2CADM0 : reg<ip_ver, base + 0x24>
  {
    static constexpr typename I2CADM0::type
    // I2C Address Mask Register I2C bus controllers support multiple address recognition with four address mask register. When the bit in the address mask register is set to one, it means the received corresponding address bit is don't-care. If the bit is set to zero, that means the received corresponding register bit should be exact the same as address register. (bits: 7-1)
     I2CADM_MASK = 0x000000FE
    ,I2CADM_POS = 1
    ,I2CADM_0 = 0x00000000 // Mask Disabled (the received corresponding register bit should be exact the same as address register.)
    ,I2CADM_1 = 0x00000002 // Mask Enabled (the received corresponding address bit is don't care.)
    ,I2CADM0_MASK = 0x000000FE
    ;
  };
  // I2C Slave Address Mask Register1
  using I2CADM1 = reg<ip_ver, base + 0x28>;
  // I2C Slave Address Mask Register2
  using I2CADM2 = reg<ip_ver, base + 0x2C>;
  // I2C Slave Address Mask Register3
  using I2CADM3 = reg<ip_ver, base + 0x30>;
  // I2C Wake-up Control Register
  struct I2CWKUPCON : reg<ip_ver, base + 0x3C>
  {
    static constexpr typename I2CWKUPCON::type
    // I2C Wake-Up Enable Control (bits: 0)
     WKUPEN_MASK = 0x00000001
    ,WKUPEN_POS = 0
    ,WKUPEN_0 = 0x00000000 // I2C wake-up function Disabled
    ,WKUPEN_1 = 0x00000001 // I2C wake-up function Enabled
    ,I2CWKUPCON_MASK = 0x00000001
    ;
  };
  // I2C Wake-up Status Register
  struct I2CWKUPSTS : reg<ip_ver, base + 0x40>
  {
    static constexpr typename I2CWKUPSTS::type
    // I2C Wake-Up Flag Note: Software can write 1 to clear this bit. (bits: 0)
     WKUPIF_MASK = 0x00000001
    ,WKUPIF_POS = 0
    ,WKUPIF_0 = 0x00000000 // Chip is not woken-up from Power-down mode by I2C
    ,WKUPIF_1 = 0x00000001 // Chip is woken-up from Power-down mode by I2C
    ,I2CWKUPSTS_MASK = 0x00000001
    ;
  };
}; // struct I2C

} // namespace lmcu::device::ip::v1

