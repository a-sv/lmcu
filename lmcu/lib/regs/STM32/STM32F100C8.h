/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

static constexpr auto name = "STM32F100C8";

static constexpr auto cpu_arch = arch::CM3;

static constexpr auto cpu_endian = endian::little;

static constexpr uint32_t rom_size = 65536;

static constexpr uint32_t ram_size = 8192;

static constexpr uint32_t pins = 48;

static constexpr uint32_t nvic_prio_bits = 4;

} // namespace lmcu::device

namespace lmcu::device {

enum class irqn : int32_t
{
  invalid_irqn = -15,
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
  usb_hp = 19,
  can1_tx = 19,
  usb_lp = 20,
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
  usb_wkup = 42,
  tim8_brk = 43,
  tim8_up = 44,
  tim8_trg_com = 45,
  tim8_cc = 46,
  adc3 = 47,
  fsmc = 48,
  sdio = 49,
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
  dma2_channel5 = 59,
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

constexpr irqn find_irqn(const char *name) noexcept
{
  constexpr std::pair<const char*, irqn> irqlst[] =
  {
    {"wwdg", irqn::wwdg},
    {"pvd", irqn::pvd},
    {"tamper", irqn::tamper},
    {"rtc", irqn::rtc},
    {"flash", irqn::flash},
    {"rcc", irqn::rcc},
    {"exti0", irqn::exti0},
    {"exti1", irqn::exti1},
    {"exti2", irqn::exti2},
    {"exti3", irqn::exti3},
    {"exti4", irqn::exti4},
    {"dma1_channel1", irqn::dma1_channel1},
    {"dma1_channel2", irqn::dma1_channel2},
    {"dma1_channel3", irqn::dma1_channel3},
    {"dma1_channel4", irqn::dma1_channel4},
    {"dma1_channel5", irqn::dma1_channel5},
    {"dma1_channel6", irqn::dma1_channel6},
    {"dma1_channel7", irqn::dma1_channel7},
    {"adc1", irqn::adc1},
    {"adc2", irqn::adc2},
    {"usb_hp", irqn::usb_hp},
    {"can1_tx", irqn::can1_tx},
    {"usb_lp", irqn::usb_lp},
    {"can1_rx0", irqn::can1_rx0},
    {"can1_rx1", irqn::can1_rx1},
    {"can1_sce", irqn::can1_sce},
    {"exti9_5", irqn::exti9_5},
    {"tim1_brk", irqn::tim1_brk},
    {"tim1_up", irqn::tim1_up},
    {"tim1_trg_com", irqn::tim1_trg_com},
    {"tim1_cc", irqn::tim1_cc},
    {"tim2", irqn::tim2},
    {"tim3", irqn::tim3},
    {"tim4", irqn::tim4},
    {"i2c1_ev", irqn::i2c1_ev},
    {"i2c1_er", irqn::i2c1_er},
    {"i2c2_ev", irqn::i2c2_ev},
    {"i2c2_er", irqn::i2c2_er},
    {"spi1", irqn::spi1},
    {"spi2", irqn::spi2},
    {"usart1", irqn::usart1},
    {"usart2", irqn::usart2},
    {"usart3", irqn::usart3},
    {"exti15_10", irqn::exti15_10},
    {"rtc_alarm", irqn::rtc_alarm},
    {"usb_wkup", irqn::usb_wkup},
    {"tim8_brk", irqn::tim8_brk},
    {"tim8_up", irqn::tim8_up},
    {"tim8_trg_com", irqn::tim8_trg_com},
    {"tim8_cc", irqn::tim8_cc},
    {"adc3", irqn::adc3},
    {"fsmc", irqn::fsmc},
    {"sdio", irqn::sdio},
    {"tim5", irqn::tim5},
    {"spi3", irqn::spi3},
    {"uart4", irqn::uart4},
    {"uart5", irqn::uart5},
    {"tim6", irqn::tim6},
    {"tim7", irqn::tim7},
    {"dma2_channel1", irqn::dma2_channel1},
    {"dma2_channel2", irqn::dma2_channel2},
    {"dma2_channel3", irqn::dma2_channel3},
    {"dma2_channel4", irqn::dma2_channel4},
    {"dma2_channel5", irqn::dma2_channel5},
    {"nmi", irqn::nmi},
    {"hard_fault", irqn::hard_fault},
    {"mem_manage", irqn::mem_manage},
    {"bus_fault", irqn::bus_fault},
    {"usage_fault", irqn::usage_fault},
    {"sv_call", irqn::sv_call},
    {"debug_mon", irqn::debug_mon},
    {"pend_sv", irqn::pend_sv},
    {"sys_tick", irqn::sys_tick},
  };

  auto cmp = [](const char *a, const char *b)
  {
    while(*a && *b) {
      if(*a++ != *b++) { return false; }
    }
    return *a == *b;
  };

  for(auto irq : irqlst) {
    if(cmp(name, irq.first)) { return irq.second; }
  }

  return irqn::invalid_irqn;
}

} // namespace lmcu::device

