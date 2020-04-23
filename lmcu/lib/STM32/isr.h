#pragma once

#ifdef __cplusplus
// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------
extern "C" {
#endif

void nmi_irq();
void hard_fault_irq();
void mem_manage_irq();
void bus_fault_irq();
void usage_fault_irq();
void svcall_irq();
void debug_mon_irq();
void pend_sv_irq();
void sys_tick_irq();

#ifdef __cplusplus
} // extern "C"
// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------
#endif
