#pragma once
#include <lmcu/dev/mcu>
#include "../isr.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------

void wwdt();
void sys();
void eint0();
void eint1();
void eint2();
void eint3();
void comp();
void dma();
void adc();
void dac();
void tm0x();
void tm10();
void tm1x();
void tm20();
void tm2x();
void tm3x();
void urt0();
void urt123();
void urt4x();
void spi0();
void spix();
void i2c0();
void i2cx();
void usb();
void apx();


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------
