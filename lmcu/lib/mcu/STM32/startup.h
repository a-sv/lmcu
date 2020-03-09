#pragma once
#include <lmcu/irq>
#include <lmcu/dev/rcc>
#include <lmcu/dev/nvic>
#include <lmcu/dev/core_debug>
#include <lmcu/dev/dwt>

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
  while(true)
    ;
}

#pragma weak nmi_irq = default_handler
#pragma weak hard_fault_irq = default_handler
#pragma weak mem_manage_irq = default_handler
#pragma weak bus_fault_irq = default_handler
#pragma weak usage_fault_irq = default_handler
#pragma weak svcall_irq = default_handler
#pragma weak debug_mon_irq = default_handler
#pragma weak pend_sv_irq = default_handler
#pragma weak sys_tick_irq = default_handler

} // extern "C"
