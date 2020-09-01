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

  extern int _start();

  lmcu::irq::disable();

  // Copy the data segment initializers from flash to SRAM.
  for(auto src = &_sidata, dst = &_sdata; dst < &_edata;) {
    *(dst++) = *(src++);
  }

  // Zero fill the bss segment.
  for(auto dst = &_sbss; dst < &_ebss;) {
    *(dst++) = 0;
  }

  device_init();

  // Enable DWT counter for delay functions working.
  CORE_DEBUG::DEMCR::set_b(CORE_DEBUG::DEMCR::TRCENA);
  DWT::CTRL::set_b(DWT::CTRL::CYCCNTENA);

  // Start main program.
  _start();
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

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------
