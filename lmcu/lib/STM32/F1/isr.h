#pragma once
#include <lmcu/dev/mcu>
#include "../isr.h"

#ifdef __cplusplus
// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------
extern "C" {
#endif

void wwdg_irq();
void pvd_irq();
void tamper_irq();
void rtc_irq();
void flash_irq();
void rcc_irq();
void exti0_irq();
void exti1_irq();
void exti2_irq();
void exti3_irq();
void exti4_irq();
void dma1_channel1_irq();
void dma1_channel2_irq();
void dma1_channel3_irq();
void dma1_channel4_irq();
void dma1_channel5_irq();
void dma1_channel6_irq();
void dma1_channel7_irq();
void adc1_2_irq();

#if defined(LMCU_STM32F1_CONNECTIVITY)
void can1_tx_irq();
void can1_rx0_irq();
#else
void usb_hp_can1_tx_irq();
void usb_lp_can1_rx0_irq();
#endif

void can1_rx1_irq();
void can1_sce_irq();
void exti9_5_irq();

#if defined(LMCU_STM32F1_XL_DENSITY)
void tim1_brk_tim9_irq();
void tim1_up_tim10_irq();
void tim1_trg_com_tim11_irq();
#else
void tim1_brk_irq();
void tim1_up_irq();
void tim1_trg_com_irq();
#endif

void tim1_cc_irq();
void tim2_irq();
void tim3_irq();
void tim4_irq();
void i2c1_ev_irq();
void i2c1_er_irq();
void i2c2_ev_irq();
void i2c2_er_irq();
void spi1_irq();
void spi2_irq();
void usart1_irq();
void usart2_irq();
void usart3_irq();
void exti15_10_irq();
void rtc_alarm_irq();

#if defined(LMCU_STM32F1_CONNECTIVITY)
void otg_fs_wakeup_irq();
#else
void usb_wakeup_irq();
#endif

#if !defined(LMCU_STM32F1_CONNECTIVITY)

#if defined(LMCU_STM32F1_XL_DENSITY)
void tim8_brk_tim12_irq();
void tim8_up_tim13_irq();
void tim8_trg_com_tim14_irq();
#else
void tim8_brk_irq();
void tim8_up_irq();
void tim8_trg_com_irq();
#endif // LMCU_STM32F1_XL_DENSITY

void tim8_cc_irq();
void adc3_irq();
void fsmc_irq();
void sdio_irq();

#endif // !LMCU_STM32F1_CONNECTIVITY

void tim5_irq();
void spi3_irq();
void uart4_irq();
void uart5_irq();
void tim6_irq();
void tim7_irq();
void dma2_channel1_irq();
void dma2_channel2_irq();
void dma2_channel3_irq();

#if defined(LMCU_STM32F1_CONNECTIVITY)
void dma2_channel4_irq();
void dma2_channel5_irq();
void eth_irq();
void eth_wakeup_irq();
void can2_tx_irq();
void can2_rx0_irq();
void can2_rx1_irq();
void can2_sce_irq();
void otg_fs_irq();
#else
void dma2_channel4_5_irq();
#endif

#ifdef __cplusplus
} // extern "C"
// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------
#endif
