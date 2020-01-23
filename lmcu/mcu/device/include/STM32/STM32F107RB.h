/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

static constexpr auto name = "STM32F107RB";

static constexpr auto cpu_arch = arch::CM3;

static constexpr auto cpu_endian = endian::little;

static constexpr uint32_t rom_size = 131072;

static constexpr uint32_t ram_size = 65536;

static constexpr uint32_t pins = 64;

static constexpr uint32_t nvic_prio_bits = 4;

} // namespace lmcu::device


namespace lmcu::device {

enum class irqn : int32_t
{
  wwdg = 0,
  pvd = 1,
  tamper = 2,
  rtc = 3,
  flash = 4,
  rcc = 5,
  exti0 = 6,
  exti1 = 7,
  exti2 = 8,
  exti3 = 9,
  exti4 = 10,
  dma1_channel1 = 11,
  dma1_channel2 = 12,
  dma1_channel3 = 13,
  dma1_channel4 = 14,
  dma1_channel5 = 15,
  dma1_channel6 = 16,
  dma1_channel7 = 17,
  adc1 = 18,
  adc2 = 18,
  can1_tx = 19,
  can1_rx0 = 20,
  can1_rx1 = 21,
  can1_sce = 22,
  exti9_5 = 23,
  tim1_brk = 24,
  tim1_up = 25,
  tim1_trg_com = 26,
  tim1_cc = 27,
  tim2 = 28,
  tim3 = 29,
  tim4 = 30,
  i2c1_ev = 31,
  i2c1_er = 32,
  i2c2_ev = 33,
  i2c2_er = 34,
  spi1 = 35,
  spi2 = 36,
  usart1 = 37,
  usart2 = 38,
  usart3 = 39,
  exti15_10 = 40,
  rtc_alarm = 41,
  otg_fs_wkup = 42,
  tim5 = 50,
  spi3 = 51,
  uart4 = 52,
  uart5 = 53,
  tim6 = 54,
  tim7 = 55,
  dma2_channel1 = 56,
  dma2_channel2 = 57,
  dma2_channel3 = 58,
  dma2_channel4 = 59,
  dma2_channel5 = 60,
  eth = 61,
  eth_wkup = 62,
  can2_rx0 = 64,
  can2_rx1 = 65,
  can2_sce = 66,
  otg_fs = 67,
  nmi = -14,
  hard_fault = -13,
  mem_manage = -12,
  bus_fault = -11,
  usage_fault = -10,
  sv_call = -5,
  debug_mon = -4,
  pend_sv = -2,
  sys_tick = -1,
};

} // namespace lmcu::device

