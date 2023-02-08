/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../../../common.h"

namespace lmcu::device::ip::v1 {

// ------------------------------------------------------------------------------------------------
// ADC Register Map
// ------------------------------------------------------------------------------------------------
template<std::uintptr_t base>
struct ADC
{
  static constexpr auto ip_ver = ip_version::_1;

  // ADC Data Register 0
  struct ADDR0 : reg<ip_ver, base + 0x0>
  {
    static constexpr typename ADDR0::type
    // A/D Conversion Result This field contains conversion result of ADC. (bits: 15-0)
     RSLT_MASK = 0x0000FFFF
    ,RSLT_POS = 0
    // Overrun Flag If converted data in RSLT has not been read before new conversion result is loaded to this register, OVERRUN is set to 1 and previous conversion result is gone. It is cleared by hardware after ADDR register is read. This is a read only bit. (bits: 16)
    ,OVERRUN_MASK = 0x00010000
    ,OVERRUN_POS = 16
    ,OVERRUN_0 = 0x00000000 // Data in RSLT (ADDRx[15:0], x=0~7) is recent conversion result
    ,OVERRUN_1 = 0x00010000 // Data in RSLT (ADDRx[15:0], x=0~7) is overwritten
    // Valid Flag This bit is set to 1 when corresponding channel analog input conversion is completed and cleared by hardware after ADDR register is read. This is a read only bit. (bits: 17)
    ,VALID_MASK = 0x00020000
    ,VALID_POS = 17
    ,VALID_0 = 0x00000000 // Data in RSLT bits (ADDRx[15:0], x=0~7) is not valid
    ,VALID_1 = 0x00020000 // Data in RSLT bits (ADDRx[15:0], x=0~7) is valid
    ,ADDR0_MASK = 0x0003FFFF
    ;
  };
  // ADC Data Register 1
  using ADDR1 = reg<ip_ver, base + 0x4>;
  // ADC Data Register 2
  using ADDR2 = reg<ip_ver, base + 0x8>;
  // ADC Data Register 3
  using ADDR3 = reg<ip_ver, base + 0xC>;
  // ADC Data Register 4
  using ADDR4 = reg<ip_ver, base + 0x10>;
  // ADC Data Register 5
  using ADDR5 = reg<ip_ver, base + 0x14>;
  // ADC Data Register 6
  using ADDR6 = reg<ip_ver, base + 0x18>;
  // ADC Data Register 7
  using ADDR7 = reg<ip_ver, base + 0x1C>;
  // ADC Control Register
  struct ADCR : reg<ip_ver, base + 0x20>
  {
    static constexpr typename ADCR::type
    // A/D Converter Enable Control Before starting A/D conversion function, this bit should be set to 1. Clear it to 0 to disable A/D converter analog circuit for saving power consumption. (bits: 0)
     ADEN_MASK = 0x00000001
    ,ADEN_POS = 0
    ,ADEN_0 = 0x00000000 // Disabled
    ,ADEN_1 = 0x00000001 // Enabled
    // A/D Interrupt Enable Control A/D conversion end interrupt request is generated if ADIE bit (ADCR[1]) is set to 1. (bits: 1)
    ,ADIE_MASK = 0x00000002
    ,ADIE_POS = 1
    ,ADIE_0 = 0x00000000 // A/D interrupt function Disabled
    ,ADIE_1 = 0x00000002 // A/D interrupt function Enabled
    // A/D Converter Operation Mode When changing the operation mode, software should disable ADST bit (ADCR[11]) firstly. (bits: 3-2)
    ,ADMD_MASK = 0x0000000C
    ,ADMD_POS = 2
    ,ADMD_0 = 0x00000000 // Single conversion
    ,ADMD_1 = 0x00000004 // Reserved
    ,ADMD_2 = 0x00000008 // Single-cycle scan
    ,ADMD_3 = 0x0000000C // Continuous scan
    // Hardware Trigger Source Software should disable TRGEN (ADCR[8]) and ADST (ADCR[11]) before change TRGS. (bits: 5-4)
    ,TRGS_MASK = 0x00000030
    ,TRGS_POS = 4
    ,TRGS_0 = 0x00000000 // A/D conversion is started by external STADC pin
    ,TRGS_3 = 0x00000030 // A/D conversion is started by PWM Center-aligned trigger
    // External Trigger Condition These two bits decide external pin STADC trigger event is level or edge. The signal must be kept at stable state at least 8 PCLKs for level trigger and 4 PCLKs at high and low state for edge trigger. (bits: 7-6)
    ,TRGCOND_MASK = 0x000000C0
    ,TRGCOND_POS = 6
    ,TRGCOND_0 = 0x00000000 // Low level
    ,TRGCOND_1 = 0x00000040 // High level
    ,TRGCOND_2 = 0x00000080 // Falling edge
    ,TRGCOND_3 = 0x000000C0 // Rising edge
    // Hardware Trigger Enable Control Enable or disable triggering of A/D conversion by hardware (external STADC pin or PWM Center-aligned trigger). ADC hardware trigger function is only supported in single-cycle scan mode. If hardware trigger mode, the ADST bit (ADCR[11]) can be set to 1 by the selected hardware trigger source. (bits: 8)
    ,TRGEN_MASK = 0x00000100
    ,TRGEN_POS = 8
    ,TRGEN_0 = 0x00000000 // Disabled
    ,TRGEN_1 = 0x00000100 // Enabled
    // Differential Input Mode Control (bits: 10)
    ,DIFFEN_MASK = 0x00000400
    ,DIFFEN_POS = 10
    ,DIFFEN_0 = 0x00000000 // Single-end analog input mode
    ,DIFFEN_1 = 0x00000400 // Differential analog input mode
    // A/D Conversion Start ADST bit can be set to 1 from three sources: software, PWM Center-aligned trigger and external pin STADC. ADST will be cleared to 0 by hardware automatically at the ends of single mode and single-cycle scan mode. In continuous scan mode, A/D conversion is continuously performed until software writes 0 to this bit or chip reset. (bits: 11)
    ,ADST_MASK = 0x00000800
    ,ADST_POS = 11
    ,ADST_0 = 0x00000000 // Conversion stops and A/D converter enter idle state
    ,ADST_1 = 0x00000800 // Conversion starts
    // A/D Differential Input Mode Output Format (bits: 31)
    ,DMOF_MASK = 0x80000000
    ,DMOF_POS = 31
    ,DMOF_0 = 0x00000000 // A/D Conversion result will be filled in RSLT at ADDRx registers with unsigned format
    ,DMOF_1 = 0x80000000 // A/D Conversion result will be filled in RSLT at ADDRx registers with 2'complement format
    ,ADCR_MASK = 0x80000DFF
    ;
  };
  // ADC Channel Enable Register
  struct ADCHER : reg<ip_ver, base + 0x24>
  {
    static constexpr typename ADCHER::type
    // Analog Input Channel Enable Control Set CHEN[7:0] to enable the corresponding analog input channel 7 ~ 0. If DIFFEN bit (ADCR[10]) is set to 1, only the even number channels need to be enabled. (bits: 7-0)
     CHEN_MASK = 0x000000FF
    ,CHEN_POS = 0
    ,CHEN_0 = 0x00000000 // ADC input channel Disabled
    ,CHEN_1 = 0x00000001 // ADC input channel Enabled
    // Analog Input Channel 7 Selection (bits: 9-8)
    ,PRESEL_MASK = 0x00000300
    ,PRESEL_POS = 8
    ,PRESEL_0 = 0x00000000 // External analog input
    ,PRESEL_1 = 0x00000100 // Internal band-gap voltage
    ,PRESEL_2 = 0x00000200 // Reserved
    ,PRESEL_3 = 0x00000300 // Reserved
    ,ADCHER_MASK = 0x000003FF
    ;
  };
  // ADC Compare Register 0
  struct ADCMPR0 : reg<ip_ver, base + 0x28>
  {
    static constexpr typename ADCMPR0::type
    // Compare Enable Control Set this bit to 1 to enable ADC controller to compare CMPD (ADCMPR0/1[27:16]) with specified channel conversion result when converted data is loaded into ADDR register. (bits: 0)
     CMPEN_MASK = 0x00000001
    ,CMPEN_POS = 0
    ,CMPEN_0 = 0x00000000 // Compare function Disabled
    ,CMPEN_1 = 0x00000001 // Compare function Enabled
    // Compare Interrupt Enable Control If the compare function is enabled and the compare condition matches the setting of CMPCOND (ADCMPR0/1[2]) and CMPMATCNT (ADCMPR0/1[11:8]), CMPF0/1 bit (ADSR[1]/[2]) will be asserted, in the meanwhile, if CMPIE (ADCMPR0/1[1]) is set to 1, a compare interrupt request is generated. (bits: 1)
    ,CMPIE_MASK = 0x00000002
    ,CMPIE_POS = 1
    ,CMPIE_0 = 0x00000000 // Compare function interrupt Disabled
    ,CMPIE_1 = 0x00000002 // Compare function interrupt Enabled
    // Compare Condition Note: When the internal counter reaches the value to (CMPMATCNT (ADCMPR0/1[11:8]) + 1), the CMPF0/1 bit (ADSR[1]/[2]) will be set. (bits: 2)
    ,CMPCOND_MASK = 0x00000004
    ,CMPCOND_POS = 2
    ,CMPCOND_0 = 0x00000000 // Set the compare condition as that when a 12-bit A/D conversion result is less than the 12-bit CMPD (ADCMPR0/1[27:16]), the internal match counter will increase one
    ,CMPCOND_1 = 0x00000004 // Set the compare condition as that when a 12-bit A/D conversion result is greater or equal to the 12-bit CMPD (ADCMPR0/1[27:16]), the internal match counter will increase one
    // Compare Channel Selection (bits: 5-3)
    ,CMPCH_MASK = 0x00000038
    ,CMPCH_POS = 3
    ,CMPCH_0 = 0x00000000 // Channel 0 conversion result is selected to be compared
    ,CMPCH_1 = 0x00000008 // Channel 1 conversion result is selected to be compared
    ,CMPCH_2 = 0x00000010 // Channel 2 conversion result is selected to be compared
    ,CMPCH_3 = 0x00000018 // Channel 3 conversion result is selected to be compared
    ,CMPCH_4 = 0x00000020 // Channel 4 conversion result is selected to be compared
    ,CMPCH_5 = 0x00000028 // Channel 5 conversion result is selected to be compared
    ,CMPCH_6 = 0x00000030 // Channel 6 conversion result is selected to be compared
    ,CMPCH_7 = 0x00000038 // Channel 7 conversion result is selected to be compared
    // Compare Match Count When the specified A/D channel analog conversion result matches the compare condition defined by CMPCOND (ADCMPR0/1[2]), the internal match counter will increase 1, The comparing data must successively matched with the compare condition. Once any comparing data does not match during the comparing, the internal counter will clear to 0. When the internal counter reaches the value to (CMPMATCNT (ADCMPR0/1[11:8]) +1), the CMPF0/1 bit (ADSR[1]/[2]) will be set. (bits: 11-8)
    ,CMPMATCNT_MASK = 0x00000F00
    ,CMPMATCNT_POS = 8
    // Comparison Data The 12-bit data is used to compare with conversion result of specified channel. When DMOF bit (ADCR[31]) is set to 0, ADC comparator compares CMPD with conversion result with unsigned format. CMPD should be filled in unsigned format. When DMOF bit (ADCR[31]) is set to 1, ADC comparator compares CMPD with conversion result with 2'complement format. CMPD should be filled in 2'complement format. (bits: 27-16)
    ,CMPD_MASK = 0x0FFF0000
    ,CMPD_POS = 16
    ,ADCMPR0_MASK = 0x0FFF0F3F
    ;
  };
  // ADC Compare Register 1
  using ADCMPR1 = reg<ip_ver, base + 0x2C>;
  // ADC Status Register
  struct ADSR : reg<ip_ver, base + 0x30>
  {
    static constexpr typename ADSR::type
    // A/D Conversion End Flag A status flag that indicates the end of A/D conversion. ADF is set to 1 at these two conditions: 1. When A/D conversion ends in Single mode. 2. When A/D conversion ends on all specified channels in Scan mode. This flag can be cleared by writing 1 to itself. (bits: 0)
     ADF_MASK = 0x00000001
    ,ADF_POS = 0
    ,ADF = 0x00000001
    // Compare Flag When the selected channel A/D conversion result meets setting condition in ADCMPR0 then this bit is set to 1. And it is cleared by writing 1 to self. (bits: 1)
    ,CMPF0_MASK = 0x00000002
    ,CMPF0_POS = 1
    ,CMPF0_0 = 0x00000000 // Conversion result in ADDR does not meet ADCMPR0 setting
    ,CMPF0_1 = 0x00000002 // Conversion result in ADDR meets ADCMPR0 setting
    // Compare Flag When the selected channel A/D conversion result meets setting condition in ADCMPR1 then this bit is set to 1. And it is cleared by writing 1 to self. (bits: 2)
    ,CMPF1_MASK = 0x00000004
    ,CMPF1_POS = 2
    ,CMPF1_0 = 0x00000000 // Conversion result in ADDR does not meet ADCMPR1 setting
    ,CMPF1_1 = 0x00000004 // Conversion result in ADDR meets ADCMPR1 setting
    // BUSY/IDLE This bit is mirror of as ADST bit (ADCR[11]). It is read only. (bits: 3)
    ,BUSY_MASK = 0x00000008
    ,BUSY_POS = 3
    ,BUSY_0 = 0x00000000 // A/D converter is in idle state
    ,BUSY_1 = 0x00000008 // A/D converter is busy at conversion
    // Current Conversion Channel It is read only. (bits: 6-4)
    ,CHANNEL_MASK = 0x00000070
    ,CHANNEL_POS = 4
    // Data Valid Flag It is a mirror of VALID bit (ADDR0~7[17]). It is read only. (bits: 15-8)
    ,VALID_MASK = 0x0000FF00
    ,VALID_POS = 8
    // Overrun Flag It is a mirror to OVERRUN bit (ADDR0~7[16]). It is read only. (bits: 23-16)
    ,OVERRUN_MASK = 0x00FF0000
    ,OVERRUN_POS = 16
    ,ADSR_MASK = 0x00FFFF7F
    ;
  };
}; // struct ADC

} // namespace lmcu::device::ip::v1

