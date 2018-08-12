#pragma once
#include "../gpio.h"

namespace lmcu::gpio {

enum class remap
{
  //
  // MAPR
  //

#if defined(STM32F107VC)
  ptp_pps__not_output_on_PB5 = 0,
  ptp_pps__output_on_PB5 = 1,

  tim2_itr1__ptp = 2,
  tim2_itr1__usb_otg_sof = 3,

  // SPI_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3, SPI3_MISO/PB4, SPI3_MOSI-I2S3_SD/PB5
  spi3_i2s3__no_remap = 4,
  // SPI3_NSS-I2S3_WS/PA4, SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12
  spi3_i2s3__remap = 5,
#endif

  jtag__full_swj = 6,
  jtag__full_swj_without_njtrst = 7,
  jtag__dp_disabled_and_sw_dp_enabled = 8,
  jtag__dp_and_sw_dp_disabled = 9,

#if defined(STM32F107VC)
  eth__mii_phy = 10,
  eth__rmii_phy = 11,

  // CAN2_RX/PB12, CAN2_TX/PB13
  can2__no_remap = 12,
  // CAN2_RX/PB5, CAN2_TX/PB6
  can2__remap = 13,

  // RX_DV-CRS_DV/PA7, RXD0/PC4, RXD1/PC5, RXD2/PB0, RXD3/PB1
  eth__no_remap = 14,
  // RX_DV-CRS_DV/PD8, RXD0/PD9, RXD1/PD10, RXD2/PD11, RXD3/PD12
  eth__remap = 15,
#endif

#if defined(STM32F103C8)
  adc2__etrgreg_exti11 = 16,
  adc2__etrgreg_tim8_trgo = 17,
  adc2__etrginj_exti15 = 18,
  adc2__etrginj_tim8_channel4 = 19,

  adc1__etrgreg_exti11 = 20,
  adc1__etrgreg_tim8_trgo = 21,
  adc1__etrginj_exti15 = 22,
  adc1__etrginj_tim8_channel4 = 23,
#endif

#if defined(TIM5)
  tim5__ch4_PA3 = 24,
  tim5__ch4_lsiclk = 25,
#endif

  PD0_no_remap__PD1_no_remap = 26,
  PD0_osc_in__PD1_osc_out = 27,

  // CAN_RX/PA11, CAN_TX/PA12
  can1__no_remap = 28,
  // CAN_RX/PB8, CAN_TX/PB9
  can1__remap_1 = 29,
  // CAN_RX/PD0, CAN_TX/PD1
  can1__remap_2 = 30,

  // TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9
  tim4__no_remap = 31,
  // TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15
  tim4__full_remap = 32,

  // CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1
  tim3__no_remap = 33,
  // CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1
  tim3__partial_remap = 34,
  // CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9
  tim3__full_remap = 35,

  // CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3
  tim2__no_remap = 36,
  // CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3
  tim2__partial_remap_1 = 37,
  // CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11
  tim2__partial_remap_2 = 38,
  // CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11
  tim2__full_remap = 39,

  // ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15
  tim1__no_remap = 40,
  // ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1
  tim1__partial_remap = 41,
  // ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12
  tim1__full_remap = 42,

  // TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14
  usart3__no_remap = 43,
  // TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14
  usart3__partial_remap = 44,
  // TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12
  usart3__full_remap = 45,

  // CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4
  usart2__no_remap = 46,
  // CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7
  usart2__remap = 47,

  // TX/PA9, RX/PA10
  usart1__no_remap = 48,
  // TX/PB6, RX/PB7
  usart1__remap = 49,

  // SCL/PB6, SDA/PB7
  i2c1__no_remap = 50,
  // SCL/PB8, SDA/PB9
  i2c1__remap = 51,

  // NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7
  spi1__no_remap = 52,
  // NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5
  spi1__remap = 53,

  //
  // MAPR2
  //

  fsmc__nadv_connected = 54,
  fsmc__nadv_not_connected = 55,

#if defined(TIM14)
  // TIM14_CH1/PA7
  tim14__no_remap = 56,
  // TIM14_CH1/PF9
  tim14__remap = 57,
#endif

#if defined(TIM13)
  // TIM13_CH1/PA6
  tim13__no_remap = 58,
  // TIM13_CH1/PF8
  tim13__remap = 59,
#endif

#if defined(TIM11)
  // TIM11_CH1/PB9
  tim11__no_remap = 60,
  // TIM11_CH1/PF7
  tim11__remap = 61,
#endif

#if defined(TIM10)
  // TIM10_CH1/PB8
  tim10__no_remap = 62,
  // TIM10_CH1/PF6
  tim10__remap = 63,
#endif

#if defined(TIM9)
  // TIM9_CH1/PA2, TIM9_CH2/PA3
  tim9__no_remap = 64,
  // TIM9_CH1/PE5, TIM9_CH2/PE6
  tim9__remap = 65
#endif
};

#include "detail/gpio.h"

template<port ..._ports>
void enable(bool afio_on = true) { detail::enable<_ports...>(afio_on); }

template<port ..._ports>
void disable(bool afio_off = true) { detail::disable<_ports...>(afio_off); }

template<remap ..._ports>
void remap() { detail::remap<_ports...>(); }

} // namespace lmcu::gpio
