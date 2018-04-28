#pragma once

#ifdef __cplusplus
extern "C" {
#endif

uint32_t lmcu_hardware_clock();
uint32_t lmcu_apb1_clock();
uint32_t lmcu_apb2_clock();
uint32_t lmcu_adc_clock();
uint32_t lmcu_apb1_timer_clock();
uint32_t lmcu_apb2_timer_clock();

#ifdef __cplusplus
} // extern "C"
#endif
