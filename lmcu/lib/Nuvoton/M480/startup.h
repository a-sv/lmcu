#pragma once
#include <lmcu/irq>
#include <lmcu/dev/rcc>
#include <lmcu/dev/cortex/nvic>
#include <lmcu/dev/cortex/core_debug>
#include <lmcu/dev/cortex/dwt>

lmcu_inline void device_init();

extern "C"
{

// Init value for the stack pointer.
extern void _estack();

void lmcu_reset_handler()
{
  using namespace lmcu::device;

  // Start address for the initialization values of the .data section.
  extern unsigned long _sidata;
  // Start address for the .data section.
  extern unsigned long _sdata;
  // End address for the .data section.
  extern unsigned long _edata;
  // Start address for the .bss section.
  extern unsigned long _sbss;
  // End address for the .bss section.
  extern unsigned long _ebss;

  lmcu::irq::disable();

  // Copy the data segment initializers from flash to SRAM.
  for(auto src = &_sidata, dst = &_sdata; dst < &_edata;) {
    *(dst++) = *(src++);
  }

  // Zero fill the bss segment.
  for(auto dst = &_sbss; dst < &_ebss;) {
    *(dst++) = 0;
  }

  // Unlock Register
/*  SYS::REGLCTL::set(0x59);
  SYS::REGLCTL::set(0x16);
  SYS::REGLCTL::set(0x88);

  //ENABLE_SPIM_CACHE ??



  // Lock register
  SYS::REGLCTL::set(0x0);*/

  device_init();

  // Enable DWT counter for delay functions working
  CORE_DEBUG::DEMCR::set_b(CORE_DEBUG::DEMCR::TRCENA);
  DWT::CTRL::set_b(DWT::CTRL::CYCCNTENA);

  // Start main program
  asm volatile(
  "bl __libc_init_array;"
  "bl main;"
  );
}

static void default_handler()
{
  while(true) { asm volatile("nop"); }
}

} // extern "C"

#define ISR_VECTOR(name) \
  void name() __attribute__((weak, alias("_ZN4lmcu3isr15default_handlerEv")));

// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------

void default_handler() __attribute__((weak, alias("default_handler")));

ISR_VECTOR(nmi)
ISR_VECTOR(hard_fault)
ISR_VECTOR(mem_manage)
ISR_VECTOR(bus_fault)
ISR_VECTOR(usage_fault)
ISR_VECTOR(svcall)
ISR_VECTOR(debug_mon)
ISR_VECTOR(pend_sv)
ISR_VECTOR(sys_tick)

ISR_VECTOR(bod)
ISR_VECTOR(irc)
ISR_VECTOR(pwrwu)
ISR_VECTOR(rampe)
ISR_VECTOR(ckfail)
ISR_VECTOR(rtc)
ISR_VECTOR(tamper)
ISR_VECTOR(wdt)
ISR_VECTOR(wwdt)
ISR_VECTOR(eint0)
ISR_VECTOR(eint1)
ISR_VECTOR(eint2)
ISR_VECTOR(eint3)
ISR_VECTOR(eint4)
ISR_VECTOR(eint5)
ISR_VECTOR(gpa)
ISR_VECTOR(gpb)
ISR_VECTOR(gpc)
ISR_VECTOR(gpd)
ISR_VECTOR(gpe)
ISR_VECTOR(gpf)
ISR_VECTOR(qspi0)
ISR_VECTOR(spi0)
ISR_VECTOR(brake0)
ISR_VECTOR(epwm0p0)
ISR_VECTOR(epwm0p1)
ISR_VECTOR(epwm0p2)
ISR_VECTOR(brake1)
ISR_VECTOR(epwm1p0)
ISR_VECTOR(epwm1p1)
ISR_VECTOR(epwm1p2)
ISR_VECTOR(timer0)
ISR_VECTOR(timer1)
ISR_VECTOR(timer2)
ISR_VECTOR(timer3)
ISR_VECTOR(uart0)
ISR_VECTOR(uart1)
ISR_VECTOR(i2c0)
ISR_VECTOR(i2c1)
ISR_VECTOR(pdma)
ISR_VECTOR(dac)
ISR_VECTOR(eadc00)
ISR_VECTOR(eadc01)
ISR_VECTOR(acmp)
ISR_VECTOR(eadc02)
ISR_VECTOR(eadc03)
ISR_VECTOR(uart2)
ISR_VECTOR(uart3)
ISR_VECTOR(qspi1)
ISR_VECTOR(spi1)
ISR_VECTOR(spi2)
ISR_VECTOR(usbd)
ISR_VECTOR(ohci)
ISR_VECTOR(otg)
ISR_VECTOR(can0)
ISR_VECTOR(can1)
ISR_VECTOR(sc0)
ISR_VECTOR(sc1)
ISR_VECTOR(sc2)
ISR_VECTOR(spi3)
ISR_VECTOR(sdh0)
ISR_VECTOR(hsusbd)
ISR_VECTOR(emac_tx)
ISR_VECTOR(emac_rx)
ISR_VECTOR(i2s)
ISR_VECTOR(opa)
ISR_VECTOR(crypto)
ISR_VECTOR(gpg)
ISR_VECTOR(eint6)
ISR_VECTOR(uart4)
ISR_VECTOR(uart5)
ISR_VECTOR(usci0)
ISR_VECTOR(usci1)
ISR_VECTOR(bpwm0)
ISR_VECTOR(bpwm1)
ISR_VECTOR(spim)
ISR_VECTOR(ccap)
ISR_VECTOR(i2c2)
ISR_VECTOR(qei0)
ISR_VECTOR(qei1)
ISR_VECTOR(ecap0)
ISR_VECTOR(ecap1)
ISR_VECTOR(gph)
ISR_VECTOR(eint7)
ISR_VECTOR(sdh1)
ISR_VECTOR(ehci)
ISR_VECTOR(hsotg)
ISR_VECTOR(trng)
ISR_VECTOR(uart6)
ISR_VECTOR(uart7)
ISR_VECTOR(eadc10)
ISR_VECTOR(eadc11)
ISR_VECTOR(eadc12)
ISR_VECTOR(eadc13)
ISR_VECTOR(can2)

__attribute__((section(".isr_vector")))
extern void(*const vectors[])() =
{
    _estack,                        //  -
    lmcu_reset_handler,             //  -
    nmi,                            //  -
    hard_fault,                     //  -
    mem_manage,                     //  -
    bus_fault,                      //  -
    usage_fault,                    //  -
    nullptr,                        //  -
    nullptr,                        //  -
    nullptr,                        //  -
    nullptr,                        //  -
    svcall,                         //  -
    debug_mon,                      //  -
    nullptr,                        //  -
    pend_sv,                        //  -
    sys_tick,                       //  -

    bod,                            //  0
    irc,                            //  1
    pwrwu,                          //  2
    rampe,                          //  3
    ckfail,                         //  4
    nullptr,                        //  5
    rtc,                            //  6
    tamper,                         //  7
    wdt,                            //  8
    wwdt,                           //  9
    eint0,                          //  10
    eint1,                          //  11
    eint2,                          //  12
    eint3,                          //  13
    eint4,                          //  14
    eint5,                          //  15
    gpa,                            //  16
    gpb,                            //  17
    gpc,                            //  18
    gpd,                            //  19
    gpe,                            //  20
    gpf,                            //  21
    qspi0,                          //  22
    spi0,                           //  23
    brake0,                         //  24
    epwm0p0,                        //  25
    epwm0p1,                        //  26
    epwm0p2,                        //  27
    brake1,                         //  28
    epwm1p0,                        //  29
    epwm1p1,                        //  30
    epwm1p2,                        //  31
    timer0,                         //  32
    timer1,                         //  33
    timer2,                         //  34
    timer3,                         //  35
    uart0,                          //  36
    uart1,                          //  37
    i2c0,                           //  38
    i2c1,                           //  39
    pdma,                           //  40
    dac,                            //  41
    eadc00,                         //  42
    eadc01,                         //  43
    acmp,                           //  44
    nullptr,                        //  45
    eadc02,                         //  46
    eadc03,                         //  47
    uart2,                          //  48
    uart3,                          //  49
    qspi1,                          //  50
    spi1,                           //  51
    spi2,                           //  52
    usbd,                           //  53
    ohci,                           //  54
    otg,                            //  55
    can0,                           //  56
    can1,                           //  57
    sc0,                            //  58
    sc1,                            //  59
    sc2,                            //  60
    nullptr,                        //  61
    spi3,                           //  62
    nullptr,                        //  63
    sdh0,                           //  64
    hsusbd,                         //  65
    emac_tx,                        //  66
    emac_rx,                        //  67
    i2s,                            //  68
    nullptr,                        //  69
    opa,                            //  70
    crypto,                         //  71
    gpg,                            //  72
    eint6,                          //  73
    uart4,                          //  74
    uart5,                          //  75
    usci0,                          //  76
    usci1,                          //  77
    bpwm0,                          //  78
    bpwm1,                          //  79
    spim,                           //  80
    ccap,                           //  81
    i2c2,                           //  82
    nullptr,                        //  83
    qei0,                           //  84
    qei1,                           //  85
    ecap0,                          //  86
    ecap1,                          //  87
    gph,                            //  88
    eint7,                          //  89
    sdh1,                           //  90
    nullptr,                        //  91
    ehci,                           //  92
    hsotg,                          //  93
    nullptr,                        //  94
    nullptr,                        //  95
    nullptr,                        //  96
    nullptr,                        //  97
    nullptr,                        //  98
    nullptr,                        //  99
    nullptr,                        //  100
    trng,                           //  101
    uart6,                          //  102
    uart7,                          //  103
    eadc10,                         //  104
    eadc11,                         //  105
    eadc12,                         //  106
    eadc13,                         //  107
    can2                            //  108
};

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------

lmcu_inline void device_init()
{
    using namespace lmcu::device;

    // Set vector table relocation
    NVIC::VTOR::set(NVIC::VTOR::type(lmcu::isr::vectors));
}
