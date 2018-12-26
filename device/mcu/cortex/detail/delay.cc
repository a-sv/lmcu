#include "../dwt_delay.h"

extern "C"
void lmcu_delay_ms(uint32_t ms) { lmcu::delay::ms(ms); }
