#pragma once
#include <lmcu/irq>
#include <lmcu/dev/rcc>
#include <lmcu/dev/cortex/nvic>
#include <lmcu/dev/cortex/core_debug>

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

ISR_VECTOR(bod) 
ISR_VECTOR(wdt)
ISR_VECTOR(eint0)
ISR_VECTOR(eint1)
ISR_VECTOR(gpab)
ISR_VECTOR(gpcdef)
ISR_VECTOR(tmr0)
ISR_VECTOR(tmr1)
ISR_VECTOR(tmr2)
ISR_VECTOR(tmr3)
ISR_VECTOR(uart02)
ISR_VECTOR(uart1)
ISR_VECTOR(spi0)
ISR_VECTOR(uart3)
ISR_VECTOR(uart4)
ISR_VECTOR(uart5)
ISR_VECTOR(i2c0)
ISR_VECTOR(i2c1) 
ISR_VECTOR(can0)
ISR_VECTOR(can1)
ISR_VECTOR(pwm0) 
ISR_VECTOR(pwm1) 
ISR_VECTOR(bpwm0) 
ISR_VECTOR(bpwm1)
ISR_VECTOR(brake0)
ISR_VECTOR(brake1)
ISR_VECTOR(pwrwu)
ISR_VECTOR(adc)
ISR_VECTOR(ckd)
ISR_VECTOR(rtc)


	

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

	bod,                            //  0 
    wdt,                            //  1
    eint0,                          //  2
    eint1,                          //  3
    gpab,                           //  4
    gpcdef,                         //  5
    nullptr,                        //  6 
    nullptr,                        //  7 
    tmr0,                           //  8 
    tmr1,                           //  9
    tmr2,                           //  10 
    tmr3,                           //  11 
    uart02,                         //  12
    uart1,                          //  13
    spi0,                           //  14
    uart3,                          //  15
    uart4,                          //  16
    uart5,                          //  17
    i2c0,                           //  18 
    i2c1,                           //  19
    can0,                           //  20
    nullptr,                        //  21
    pwm0,                           //  22
    pwm1,                           //  23 
    bpwm0,                          //  24  
    bpwm1,                          //  25 
    brake0,                         //  26
    brake1,                         //  27
    pwrwu,                          //  28
    adc,                            //  29
    ckd,                            //  30  
    nullptr,                        //  31  
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
