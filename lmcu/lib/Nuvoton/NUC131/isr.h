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


void bod();
void wdt();
void eint0();
void eint1();
void gpab();
void pcdef();
void tmr0();
void tmr1();
void tmr2();
void tmr3();
void uart02();
void uart1();
void spi0();
void uart3();
void uart4();
void uart5();
void i2c0();
void i2c1();
void can0();
void can1();
void pwm0();
void pwm1(); 
void bpwm0(); 
void bpwm1();
void brake0();
void brake1();
void pwrwu();
void adc();
void ckd();
void rtc();



// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------
