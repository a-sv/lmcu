#pragma once
#include "isr.h"
#include "../startup.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::isr {
// ------------------------------------------------------------------------------------------------

ISR_VECTOR(wwdg)
ISR_VECTOR(pvd)
ISR_VECTOR(tamper)
ISR_VECTOR(rtc)
ISR_VECTOR(flash)
ISR_VECTOR(rcc)
ISR_VECTOR(exti0)
ISR_VECTOR(exti1)
ISR_VECTOR(exti2)
ISR_VECTOR(exti3)
ISR_VECTOR(exti4)
ISR_VECTOR(dma1_channel1)
ISR_VECTOR(dma1_channel2)
ISR_VECTOR(dma1_channel3)
ISR_VECTOR(dma1_channel4)
ISR_VECTOR(dma1_channel5)
ISR_VECTOR(dma1_channel6)
ISR_VECTOR(dma1_channel7)
ISR_VECTOR(adc1_2)

#if defined(LMCU_STM32F1_CONNECTIVITY)
ISR_VECTOR(can1_tx)
ISR_VECTOR(can1_rx0)
#else
ISR_VECTOR(usb_hp_can1_tx)
ISR_VECTOR(usb_lp_can1_rx0)
#endif

ISR_VECTOR(can1_rx1)
ISR_VECTOR(can1_sce)
ISR_VECTOR(exti9_5)

#if defined(LMCU_STM32F1_XL_DENSITY)
ISR_VECTOR(tim1_brk_tim9)
ISR_VECTOR(tim1_up_tim10)
ISR_VECTOR(tim1_trg_com_tim11)
#else
ISR_VECTOR(tim1_brk)
ISR_VECTOR(tim1_up)
ISR_VECTOR(tim1_trg_com)
#endif

ISR_VECTOR(tim1_cc)
ISR_VECTOR(tim2)
ISR_VECTOR(tim3)
ISR_VECTOR(tim4)
ISR_VECTOR(i2c1_ev)
ISR_VECTOR(i2c1_er)
ISR_VECTOR(i2c2_ev)
ISR_VECTOR(i2c2_er)
ISR_VECTOR(spi1)
ISR_VECTOR(spi2)
ISR_VECTOR(usart1)
ISR_VECTOR(usart2)
ISR_VECTOR(usart3)
ISR_VECTOR(exti15_10)
ISR_VECTOR(rtc_alarm)

#if defined(LMCU_STM32F1_CONNECTIVITY)
ISR_VECTOR(otg_fs_wakeup)
#else
ISR_VECTOR(usb_wakeup)
#endif

#if !defined(LMCU_STM32F1_CONNECTIVITY)

#if defined(LMCU_STM32F1_XL_DENSITY)
ISR_VECTOR(tim8_brk_tim12)
ISR_VECTOR(tim8_up_tim13)
ISR_VECTOR(tim8_trg_com_tim14)
#else
ISR_VECTOR(tim8_brk)
ISR_VECTOR(tim8_up)
ISR_VECTOR(tim8_trg_com)
#endif // LMCU_STM32F1_XL_DENSITY

ISR_VECTOR(tim8_cc)
ISR_VECTOR(adc3)
ISR_VECTOR(fsmc)
ISR_VECTOR(sdio)

#endif // !LMCU_STM32F1_CONNECTIVITY

ISR_VECTOR(tim5)
ISR_VECTOR(spi3)
ISR_VECTOR(uart4)
ISR_VECTOR(uart5)
ISR_VECTOR(tim6)
ISR_VECTOR(tim7)
ISR_VECTOR(dma2_channel1)
ISR_VECTOR(dma2_channel2)
ISR_VECTOR(dma2_channel3)

#if defined(LMCU_STM32F1_CONNECTIVITY)
ISR_VECTOR(dma2_channel4)
ISR_VECTOR(dma2_channel5)
ISR_VECTOR(eth)
ISR_VECTOR(eth_wakeup)
ISR_VECTOR(can2_tx)
ISR_VECTOR(can2_rx0)
ISR_VECTOR(can2_rx1)
ISR_VECTOR(can2_sce)
ISR_VECTOR(otg_fs)
#else
ISR_VECTOR(dma2_channel4_5)
#endif

__attribute__((section(".isr_vector")))
extern void(*const vectors[])() =
{                                  // POSITION
  _estack,                         //  -
  lmcu_reset_handler,              //  -
  nmi,                             //  -
  hard_fault,                      //  -
  mem_manage,                      //  -
  bus_fault,                       //  -
  usage_fault,                     //  -
  nullptr,                         //  -
  nullptr,                         //  -
  nullptr,                         //  -
  nullptr,                         //  -
  svcall,                          //  -
  debug_mon,                       //  -
  nullptr,                         //  -
  pend_sv,                         //  -
  sys_tick,                        //  -

  wwdg,                            //  0
  pvd,                             //  1
  tamper,                          //  2
  rtc,                             //  3
  flash,                           //  4
  rcc,                             //  5
  exti0,                           //  6
  exti1,                           //  7
  exti2,                           //  8
  exti3,                           //  9
  exti4,                           // 10
  dma1_channel1,                   // 11
  dma1_channel2,                   // 12
  dma1_channel3,                   // 13
  dma1_channel4,                   // 14
  dma1_channel5,                   // 15
  dma1_channel6,                   // 16
  dma1_channel7,                   // 17
  adc1_2,                          // 18

#if defined(LMCU_STM32F1_LOW_DENSITY_VALUE_LINE) || defined(LMCU_STM32F1_MEDIUM_DENSITY_VALUE_LINE)
  usb_hp_can1_tx,                  // 19
  usb_lp_can1_rx0,                 // 20
  can1_rx1,                        // 21
  can1_sce,                        // 22
  exti9_5,                         // 23
  tim1_brk,                        // 24
  tim1_up,                         // 25
  tim1_trg_com,                    // 26
  tim1_cc,                         // 27
  tim2,                            // 28
  tim3,                            // 29
  tim4,                            // 30
  i2c1_ev,                         // 31
  i2c1_er,                         // 32
  i2c2_ev,                         // 33
  i2c2_er,                         // 34
  spi1,                            // 35
  spi2,                            // 36
  usart1,                          // 37
  usart2,                          // 38
  usart3,                          // 39
  exti15_10,                       // 40
  rtc_alarm,                       // 41
  usb_wakeup,                      // 42
  tim8_brk,                        // 43
  tim8_up,                         // 44
  tim8_trg_com,                    // 45
  tim8_cc,                         // 46
  adc3,                            // 47
  fsmc,                            // 48
  sdio,                            // 49
  tim5,                            // 50
  spi3,                            // 51
  uart4,                           // 52
  uart5,                           // 53
  tim6,                            // 54
  tim7,                            // 55
  dma2_channel1,                   // 56
  dma2_channel2,                   // 57
  dma2_channel3,                   // 58
  dma2_channel4_5,                 // 59
  nullptr,                         // 60
  nullptr,                         // 61
  nullptr,                         // 62
  nullptr,                         // 63
  nullptr,                         // 64
  nullptr,                         // 65
  nullptr,                         // 66
  nullptr,                         // 67
  nullptr,                         // 68
  nullptr,                         // 69
  nullptr,                         // 70
  nullptr,                         // 71
  nullptr,                         // 72
  nullptr,                         // 73
  nullptr,                         // 74
  nullptr,                         // 75
  nullptr,                         // 76
  nullptr,                         // 77
  nullptr,                         // 78
  nullptr,                         // 79
  nullptr,                         // 80
  nullptr,                         // 81
  nullptr,                         // 82
  nullptr,                         // 83
  nullptr,                         // 84
  nullptr,                         // 85
  nullptr,                         // 86
  nullptr,                         // 87
  nullptr,                         // 88
  nullptr,                         // 89
  nullptr,                         // 90
  nullptr,                         // 91
  nullptr,                         // 92
  nullptr,                         // 93
  nullptr,                         // 94
  nullptr,                         // 95
  nullptr,                         // 96
  nullptr,                         // 97
  nullptr,                         // 98
  reinterpret_cast<void(*)()>(0xF1CCF85F)
#elif defined(LMCU_STM32F1_LOW_DENSITY) || defined(LMCU_STM32F1_MEDIUM_DENSITY)
  usb_hp_can1_tx,                  // 19
  usb_lp_can1_rx0,                 // 20
  can1_rx1,                        // 21
  can1_sce,                        // 22
  exti9_5,                         // 23
  tim1_brk,                        // 24
  tim1_up,                         // 25
  tim1_trg_com,                    // 26
  tim1_cc,                         // 27
  tim2,                            // 28
  tim3,                            // 29
  tim4,                            // 30
  i2c1_ev,                         // 31
  i2c1_er,                         // 32
  i2c2_ev,                         // 33
  i2c2_er,                         // 34
  spi1,                            // 35
  spi2,                            // 36
  usart1,                          // 37
  usart2,                          // 38
  usart3,                          // 39
  exti15_10,                       // 40
  rtc_alarm,                       // 41
  usb_wakeup,                      // 42
  tim8_brk,                        // 43
  tim8_up,                         // 44
  tim8_trg_com,                    // 45
  tim8_cc,                         // 46
  adc3,                            // 47
  fsmc,                            // 48
  sdio,                            // 49
  reinterpret_cast<void(*)()>(0xf108f85f)
#else
#if defined(LMCU_STM32F1_CONNECTIVITY)
  can1_tx,                         // 19
  can1_rx0,                        // 20
#else
  usb_hp_can1_tx,                  // 19
  usb_lp_can1_rx0,                 // 20
#endif

  can1_rx1,                        // 21
  can1_sce,                        // 22
  exti9_5,                         // 23

#if defined(LMCU_STM32F1_XL_DENSITY)
  tim1_brk_tim9,                   // 24
  tim1_up_tim10,                   // 25
  tim1_trg_com_tim11,              // 26
#else
  tim1_brk,                        // 24
  tim1_up,                         // 25
  tim1_trg_com,                    // 26
#endif

  tim1_cc,                         // 27
  tim2,                            // 28
  tim3,                            // 29
  tim4,                            // 30
  i2c1_ev,                         // 31
  i2c1_er,                         // 32
  i2c2_ev,                         // 33
  i2c2_er,                         // 34
  spi1,                            // 35
  spi2,                            // 36
  usart1,                          // 37
  usart2,                          // 38
  usart3,                          // 39
  exti15_10,                       // 40
  rtc_alarm,                       // 41

#if defined(LMCU_STM32F1_CONNECTIVITY)
  otg_fs_wakeup,                   // 42
  nullptr,                         // 43
  nullptr,                         // 44
  nullptr,                         // 45
  nullptr,                         // 46
  nullptr,                         // 47
  nullptr,                         // 48
  nullptr,                         // 49
#else
  usb_wakeup,                      // 42

#if defined(LMCU_STM32F1_XL_DENSITY)
  tim8_brk_tim12,                  // 43
  tim8_up_tim13,                   // 44
  tim8_trg_com_tim14,              // 45
#else
  tim8_brk,                        // 43
  tim8_up,                         // 44
  tim8_trg_com,                    // 45
#endif // LMCU_STM32F1_XL_DENSITY

  tim8_cc,                         // 46
  adc3,                            // 47
  fsmc,                            // 48
  sdio,                            // 49
#endif // LMCU_STM32F1_CONNECTIVITY

  tim5,                            // 50
  spi3,                            // 51
  uart4,                           // 52
  uart5,                           // 53
  tim6,                            // 54
  tim7,                            // 55
  dma2_channel1,                   // 56
  dma2_channel2,                   // 57
  dma2_channel3,                   // 58

#if defined(LMCU_STM32F1_CONNECTIVITY)
  dma2_channel4,                   // 59
  dma2_channel5,                   // 60
  eth,                             // 61
  eth_wakeup,                      // 62
  can2_tx,                         // 63
  can2_rx0,                        // 64
  can2_rx1,                        // 65
  can2_sce,                        // 66
  otg_fs,                          // 67
#else
  dma2_channel4_5,                 // 59
  nullptr,                         // 60
  nullptr,                         // 61
  nullptr,                         // 62
  nullptr,                         // 63
  nullptr,                         // 64
  nullptr,                         // 65
  nullptr,                         // 66
  nullptr,                         // 67
#endif

  nullptr,                         // 68
  nullptr,                         // 69
  nullptr,                         // 70
  nullptr,                         // 71
  nullptr,                         // 72
  nullptr,                         // 73
  nullptr,                         // 74
  nullptr,                         // 75
  nullptr,                         // 76
  nullptr,                         // 77
  nullptr,                         // 78
  nullptr,                         // 79
  nullptr,                         // 80
  nullptr,                         // 81
  nullptr,                         // 82
  nullptr,                         // 83
  nullptr,                         // 84
  nullptr,                         // 85
  nullptr,                         // 86
  nullptr,                         // 87
  nullptr,                         // 88
  nullptr,                         // 89
  nullptr,                         // 90
  nullptr,                         // 91
  nullptr,                         // 92
  nullptr,                         // 93
  nullptr,                         // 94
  nullptr,                         // 95
  nullptr,                         // 96
  nullptr,                         // 97
  nullptr,                         // 98
  nullptr,                         // 99
  nullptr,                         // 100
  nullptr,                         // 101
  nullptr,                         // 102
  nullptr,                         // 103
  reinterpret_cast<void(*)()>(0xF1E0F85F)
#endif
};

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::isr
// ------------------------------------------------------------------------------------------------

lmcu_inline void device_init()
{
  using namespace lmcu::device;

  // Enable and wait for HSI start
  RCC::CR::set_b(RCC::CR::HSION);
  while(!RCC::CR::is_set(RCC::CR::HSIRDY))
    ;
  // Switch SYSCLK to HSI and reset PLL's configuration
  RCC::CFGR::reset();
  while(RCC::CFGR::is_set(RCC::CFGR::SWS_MASK))
    ;
#if defined(LMCU_STM32F1_CONNECTIVITY)
  RCC::CFGR2::reset();
#endif
  // Reset other clocks configuration to default values
  RCC::CR::reset();
  RCC::CIR::reset();
  RCC::APB1RSTR::reset();
  RCC::APB2RSTR::reset();
  RCC::AHBENR::reset();
  RCC::APB1ENR::reset();
  RCC::APB2ENR::reset();
  RCC::CSR::reset();
  // Set vector table relocation
  NVIC::VTOR::set( NVIC::VTOR::type(lmcu::isr::vectors) );
}
