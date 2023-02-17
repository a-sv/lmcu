/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

static constexpr auto name = "MG32F02A032AD48";

static constexpr auto cpu_arch = arch::CM0;

static constexpr auto cpu_endian = endian::little;

static constexpr uint32_t rom_size = 32768;

static constexpr uint32_t ram_size = 4096;

static constexpr uint32_t pins = 48;

static constexpr uint32_t nvic_prio_bits = 4;

} // namespace lmcu::device

namespace lmcu::device {

enum class irqn : int32_t
{
  invalid_irqn = -15,
  wwdt = 0,
  sys = 1,
  eint0 = 3,
  eint1 = 4,
  eint2 = 5,
  eint3 = 6,
  comp = 7,
  dma = 8,
  adc = 10,
  dac = 11,
  tm0x = 12,
  tm10 = 13,
  tm1x = 14,
  tm20 = 15,
  tm2x = 16,
  tm3x = 17,
  urt0 = 20,
  urt123 = 21,
  urt4x = 22,
  spi0 = 24,
  spix = 25,
  i2c0 = 28,
  i2cx = 29,
  usb = 30,
  apx = 31,
  nmi = -14,
  hard_fault = -13,
  sv_call = -5,
  pend_sv = -2,
  sys_tick = -1,
};

constexpr irqn find_irqn(const char *name) noexcept
{
  constexpr std::pair<const char*, irqn> irqlst[] =
  {
    {"wwdt", irqn::wwdt},
    {"sys", irqn::sys},
    {"eint0", irqn::eint0},
    {"eint1", irqn::eint1},
    {"eint2", irqn::eint2},
    {"eint3", irqn::eint3},
    {"comp", irqn::comp},
    {"dma", irqn::dma},
    {"adc", irqn::adc},
    {"dac", irqn::dac},
    {"tm0x", irqn::tm0x},
    {"tm10", irqn::tm10},
    {"tm1x", irqn::tm1x},
    {"tm20", irqn::tm20},
    {"tm2x", irqn::tm2x},
    {"tm3x", irqn::tm3x},
    {"urt0", irqn::urt0},
    {"urt123", irqn::urt123},
    {"urt4x", irqn::urt4x},
    {"spi0", irqn::spi0},
    {"spix", irqn::spix},
    {"i2c0", irqn::i2c0},
    {"i2cx", irqn::i2cx},
    {"usb", irqn::usb},
    {"apx", irqn::apx},
    {"nmi", irqn::nmi},
    {"hard_fault", irqn::hard_fault},
    {"sv_call", irqn::sv_call},
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

