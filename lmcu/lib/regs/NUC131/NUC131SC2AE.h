/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

static constexpr auto name = "NUC131SC2AE";

static constexpr auto cpu_arch = arch::CM0;

static constexpr auto cpu_endian = endian::little;

static constexpr uint32_t rom_size = 36864;

static constexpr uint32_t ram_size = 8192;

static constexpr uint32_t pins = 64;

static constexpr uint32_t nvic_prio_bits = 4;

} // namespace lmcu::device

namespace lmcu::device {

enum class irqn : int32_t
{
  invalid_irqn = -15,
  bod = 0,
  wdt = 1,
  eint0 = 2,
  eint1 = 3,
  gpab = 4,
  gpcdef = 5,
  tmr0 = 8,
  tmr1 = 9,
  tmr2 = 10,
  tmr3 = 11,
  uart02 = 12,
  uart1 = 13,
  spi0 = 14,
  uart3 = 15,
  uart4 = 16,
  uart5 = 17,
  i2c0 = 18,
  i2c1 = 19,
  can0 = 20,
  pwm0 = 22,
  pwm1 = 23,
  bpwm0 = 24,
  bpwm1 = 25,
  brake0 = 26,
  brake1 = 27,
  pwrwu = 28,
  adc = 29,
  ckd = 30,
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
    {"bod", irqn::bod},
    {"wdt", irqn::wdt},
    {"eint0", irqn::eint0},
    {"eint1", irqn::eint1},
    {"gpab", irqn::gpab},
    {"gpcdef", irqn::gpcdef},
    {"tmr0", irqn::tmr0},
    {"tmr1", irqn::tmr1},
    {"tmr2", irqn::tmr2},
    {"tmr3", irqn::tmr3},
    {"uart02", irqn::uart02},
    {"uart1", irqn::uart1},
    {"spi0", irqn::spi0},
    {"uart3", irqn::uart3},
    {"uart4", irqn::uart4},
    {"uart5", irqn::uart5},
    {"i2c0", irqn::i2c0},
    {"i2c1", irqn::i2c1},
    {"can0", irqn::can0},
    {"pwm0", irqn::pwm0},
    {"pwm1", irqn::pwm1},
    {"bpwm0", irqn::bpwm0},
    {"bpwm1", irqn::bpwm1},
    {"brake0", irqn::brake0},
    {"brake1", irqn::brake1},
    {"pwrwu", irqn::pwrwu},
    {"adc", irqn::adc},
    {"ckd", irqn::ckd},
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

