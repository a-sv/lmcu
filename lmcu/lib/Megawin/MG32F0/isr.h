#pragma once

// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------

void default_handler();
void nmi();
void hard_fault();
void svcall();
void pend_sv();
void sys_tick();


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------