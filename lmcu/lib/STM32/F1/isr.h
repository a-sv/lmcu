#pragma once
#include <lmcu/dev/mcu>
#include "../isr.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------

void wwdg();
void pvd();
void tamper();
void rtc();
void flash();
void rcc();
void exti0();
void exti1();
void exti2();
void exti3();
void exti4();
void dma1_channel1();
void dma1_channel2();
void dma1_channel3();
void dma1_channel4();
void dma1_channel5();
void dma1_channel6();
void dma1_channel7();
void adc1_2();

#if defined(LMCU_STM32F1_CONNECTIVITY)
void can1_tx();
void can1_rx0();
#else
void usb_hp_can1_tx();
void usb_lp_can1_rx0();
#endif

void can1_rx1();
void can1_sce();
void exti9_5();

#if defined(LMCU_STM32F1_XL_DENSITY)
void tim1_brk_tim9();
void tim1_up_tim10();
void tim1_trg_com_tim11();
#else
void tim1_brk();
void tim1_up();
void tim1_trg_com();
#endif

void tim1_cc();
void tim2();
void tim3();
void tim4();
void i2c1_ev();
void i2c1_er();
void i2c2_ev();
void i2c2_er();
void spi1();
void spi2();
void usart1();
void usart2();
void usart3();
void exti15_10();
void rtc_alarm();

#if defined(LMCU_STM32F1_CONNECTIVITY)
void otg_fs_wakeup();
#else
void usb_wakeup();
#endif

#if !defined(LMCU_STM32F1_CONNECTIVITY)

#if defined(LMCU_STM32F1_XL_DENSITY)
void tim8_brk_tim12();
void tim8_up_tim13();
void tim8_trg_com_tim14();
#else
void tim8_brk();
void tim8_up();
void tim8_trg_com();
#endif // LMCU_STM32F1_XL_DENSITY

void tim8_cc();
void adc3();
void fsmc();
void sdio();

#endif // !LMCU_STM32F1_CONNECTIVITY

void tim5();
void spi3();
void uart4();
void uart5();
void tim6();
void tim7();
void dma2_channel1();
void dma2_channel2();
void dma2_channel3();

#if defined(LMCU_STM32F1_CONNECTIVITY)
void dma2_channel4();
void dma2_channel5();
void eth();
void eth_wakeup();
void can2_tx();
void can2_rx0();
void can2_rx1();
void can2_sce();
void otg_fs();
#else
void dma2_channel4_5();
#endif

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------
