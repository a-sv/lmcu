/**************************************************************************************************/
/**                             AUTO-GENERATED FILE. DO NOT MODIFY!                              **/
/**************************************************************************************************/
#pragma once
#include "../common.h"

namespace lmcu::device {

static constexpr auto name = "M483SGC";

static constexpr auto cpu_arch = arch::CM4;

static constexpr auto cpu_endian = endian::little;

static constexpr uint32_t rom_size = 262144;

static constexpr uint32_t ram_size = 131072;

static constexpr uint32_t pins = 64;

static constexpr uint32_t nvic_prio_bits = 4;

} // namespace lmcu::device

namespace lmcu::device {

enum class irqn : int32_t
{
  invalid_irqn = -15,
  bod = 0,
  irc = 1,
  pwrwu = 2,
  rampe = 3,
  ckfail = 4,
  rtc = 6,
  tamper = 7,
  wdt = 8,
  wwdt = 9,
  eint0 = 10,
  eint1 = 11,
  eint2 = 12,
  eint3 = 13,
  eint4 = 14,
  eint5 = 15,
  gpa = 16,
  gpb = 17,
  gpc = 18,
  gpd = 19,
  gpe = 20,
  gpf = 21,
  qspi0 = 22,
  spi0 = 23,
  brake0 = 24,
  epwm0p0 = 25,
  epwm0p1 = 26,
  epwm0p2 = 27,
  brake1 = 28,
  epwm1p0 = 29,
  epwm1p1 = 30,
  epwm1p2 = 31,
  timer0 = 32,
  timer1 = 33,
  timer2 = 34,
  timer3 = 35,
  uart0 = 36,
  uart1 = 37,
  i2c0 = 38,
  i2c1 = 39,
  pdma = 40,
  dac = 41,
  eadc00 = 42,
  eadc01 = 43,
  acmp = 44,
  eadc02 = 46,
  eadc03 = 47,
  uart2 = 48,
  uart3 = 49,
  qspi1 = 50,
  spi1 = 51,
  spi2 = 52,
  usbd = 53,
  ohci = 54,
  otg = 55,
  can0 = 56,
  can1 = 57,
  sc0 = 58,
  sc1 = 59,
  sc2 = 60,
  spi3 = 62,
  sdh0 = 64,
  hsusbd = 65,
  emac_tx = 66,
  emac_rx = 67,
  i2s = 68,
  opa = 70,
  crypto = 71,
  gpg = 72,
  eint6 = 73,
  uart4 = 74,
  uart5 = 75,
  usci0 = 76,
  usci1 = 77,
  bpwm0 = 78,
  bpwm1 = 79,
  spim = 80,
  ccap = 81,
  i2c2 = 82,
  qei0 = 84,
  qei1 = 85,
  ecap0 = 86,
  ecap1 = 87,
  gph = 88,
  eint7 = 89,
  sdh1 = 90,
  ehci = 92,
  hsotg = 93,
  trng = 101,
  uart6 = 102,
  uart7 = 103,
  eadc10 = 104,
  eadc11 = 105,
  eadc12 = 106,
  eadc13 = 107,
  can2 = 108,
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
    {"bod", irqn::bod},
    {"irc", irqn::irc},
    {"pwrwu", irqn::pwrwu},
    {"rampe", irqn::rampe},
    {"ckfail", irqn::ckfail},
    {"rtc", irqn::rtc},
    {"tamper", irqn::tamper},
    {"wdt", irqn::wdt},
    {"wwdt", irqn::wwdt},
    {"eint0", irqn::eint0},
    {"eint1", irqn::eint1},
    {"eint2", irqn::eint2},
    {"eint3", irqn::eint3},
    {"eint4", irqn::eint4},
    {"eint5", irqn::eint5},
    {"gpa", irqn::gpa},
    {"gpb", irqn::gpb},
    {"gpc", irqn::gpc},
    {"gpd", irqn::gpd},
    {"gpe", irqn::gpe},
    {"gpf", irqn::gpf},
    {"qspi0", irqn::qspi0},
    {"spi0", irqn::spi0},
    {"brake0", irqn::brake0},
    {"epwm0p0", irqn::epwm0p0},
    {"epwm0p1", irqn::epwm0p1},
    {"epwm0p2", irqn::epwm0p2},
    {"brake1", irqn::brake1},
    {"epwm1p0", irqn::epwm1p0},
    {"epwm1p1", irqn::epwm1p1},
    {"epwm1p2", irqn::epwm1p2},
    {"timer0", irqn::timer0},
    {"timer1", irqn::timer1},
    {"timer2", irqn::timer2},
    {"timer3", irqn::timer3},
    {"uart0", irqn::uart0},
    {"uart1", irqn::uart1},
    {"i2c0", irqn::i2c0},
    {"i2c1", irqn::i2c1},
    {"pdma", irqn::pdma},
    {"dac", irqn::dac},
    {"eadc00", irqn::eadc00},
    {"eadc01", irqn::eadc01},
    {"acmp", irqn::acmp},
    {"eadc02", irqn::eadc02},
    {"eadc03", irqn::eadc03},
    {"uart2", irqn::uart2},
    {"uart3", irqn::uart3},
    {"qspi1", irqn::qspi1},
    {"spi1", irqn::spi1},
    {"spi2", irqn::spi2},
    {"usbd", irqn::usbd},
    {"ohci", irqn::ohci},
    {"otg", irqn::otg},
    {"can0", irqn::can0},
    {"can1", irqn::can1},
    {"sc0", irqn::sc0},
    {"sc1", irqn::sc1},
    {"sc2", irqn::sc2},
    {"spi3", irqn::spi3},
    {"sdh0", irqn::sdh0},
    {"hsusbd", irqn::hsusbd},
    {"emac_tx", irqn::emac_tx},
    {"emac_rx", irqn::emac_rx},
    {"i2s", irqn::i2s},
    {"opa", irqn::opa},
    {"crypto", irqn::crypto},
    {"gpg", irqn::gpg},
    {"eint6", irqn::eint6},
    {"uart4", irqn::uart4},
    {"uart5", irqn::uart5},
    {"usci0", irqn::usci0},
    {"usci1", irqn::usci1},
    {"bpwm0", irqn::bpwm0},
    {"bpwm1", irqn::bpwm1},
    {"spim", irqn::spim},
    {"ccap", irqn::ccap},
    {"i2c2", irqn::i2c2},
    {"qei0", irqn::qei0},
    {"qei1", irqn::qei1},
    {"ecap0", irqn::ecap0},
    {"ecap1", irqn::ecap1},
    {"gph", irqn::gph},
    {"eint7", irqn::eint7},
    {"sdh1", irqn::sdh1},
    {"ehci", irqn::ehci},
    {"hsotg", irqn::hsotg},
    {"trng", irqn::trng},
    {"uart6", irqn::uart6},
    {"uart7", irqn::uart7},
    {"eadc10", irqn::eadc10},
    {"eadc11", irqn::eadc11},
    {"eadc12", irqn::eadc12},
    {"eadc13", irqn::eadc13},
    {"can2", irqn::can2},
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

