#pragma once
#include <lmcu/irq>
#include <lmcu/dev/rcc>
#include <lmcu/dev/cortex/nvic>
#include <lmcu/dev/cortex/core_debug>
//#include <lmcu/dev/cortex/dwt>

lmcu_inline void device_init();

extern "C"
{

// Init value for the stack pointer.
extern void __StackTop();

void lmcu_reset_handler()
{
  using namespace lmcu::device;

  // Start address for the initialization values of the .data section.
  extern unsigned long __etext;
  // Start address for the .data section.
  extern unsigned long __data_start__;
  // End address for the .data section.
  extern unsigned long __data_end__;
  // Start address for the .bss section.
  extern unsigned long __bss_start__;
  // End address for the .bss section.
  extern unsigned long __bss_end__;

  lmcu::irq::disable();

  // Copy the data segment initializers from flash to SRAM.
  for(auto src = &__etext, dst = &__data_start__; dst < &__data_end__;) {
    *(dst++) = *(src++);
  }

  // Zero fill the bss segment.
  for(auto dst = &__bss_start__; dst < &__bss_end__;) {
    *(dst++) = 0;
  }

  device_init();

  // Enable DWT counter for delay functions working.
  //CORE_DEBUG::DEMCR::set_b(CORE_DEBUG::DEMCR::TRCENA);
  //DWT::CTRL::set_b(DWT::CTRL::CYCCNTENA);

  // Start main program.
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
ISR_VECTOR(svcall)
ISR_VECTOR(pend_sv)
ISR_VECTOR(sys_tick)

ISR_VECTOR(wwdt)
ISR_VECTOR(sys)
ISR_VECTOR(eint0)
ISR_VECTOR(eint1)
ISR_VECTOR(eint2)
ISR_VECTOR(eint3)
ISR_VECTOR(comp)
ISR_VECTOR(dma)
ISR_VECTOR(adc)
ISR_VECTOR(dac)
ISR_VECTOR(tm0x)
ISR_VECTOR(tm10)
ISR_VECTOR(tm1x)
ISR_VECTOR(tm20)
ISR_VECTOR(tm2x)
ISR_VECTOR(tm3x)
ISR_VECTOR(urt0)
ISR_VECTOR(urt123)
ISR_VECTOR(urt4x)
ISR_VECTOR(spi0)
ISR_VECTOR(spix)
ISR_VECTOR(i2c0)
ISR_VECTOR(i2cx)
ISR_VECTOR(usb)
ISR_VECTOR(apx)
	

__attribute__((section(".isr_vector")))
extern void(*const vectors[])() =
{
    __StackTop,                     //  -
    lmcu_reset_handler,             //  -
    nmi,                            //  -
    hard_fault,                     //  -
    nullptr,                     	//  -
    nullptr,                      	//  -
    nullptr,                    	//  -
    nullptr,                        //  -
    nullptr,                        //  -
    nullptr,                        //  -
    nullptr,                        //  -
    svcall,                         //  -
    nullptr,                        //  -
    nullptr,                        //  -
    pend_sv,                        //  -
    sys_tick,                       //  -

    wwdt,                           //  0
    sys,                            //  1
    nullptr,                        //  2
    eint0,                          //  3
    eint1,                          //  4
    eint2,                          //  5
    eint3,                          //  6
    comp,                           //  7
    dma,                            //  8
    nullptr,                        //  9
    adc,                            //  10
    dac,                            //  11
    tm0x,                           //  12
    tm10,                           //  13
    tm1x,                           //  14
    tm20,                           //  15
    tm2x,                           //  16
    tm3x,                           //  17
    nullptr,                        //  18
    nullptr,                        //  19
    urt0,                           //  20
    urt123,                         //  21
    urt4x,                          //  22
    nullptr,                        //  23
    spi0,                           //  24
    spix,                           //  25
    nullptr,                        //  26
    nullptr,                        //  27
    i2c0,                           //  28
    i2cx,                           //  29
    usb,                            //  30
    apx,                            //  31
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
