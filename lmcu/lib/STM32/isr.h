#pragma once

// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------

void default_handler();
void nmi();
void hard_fault();
void mem_manage();
void bus_fault();
void usage_fault();
void svcall();
void debug_mon();
void pend_sv();
void sys_tick();

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------