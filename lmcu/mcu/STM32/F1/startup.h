#pragma once
#include "isr.h"
#include "../startup.h"

#pragma weak wwdg_irq = default_handler
#pragma weak pvd_irq = default_handler
#pragma weak tamper_irq = default_handler
#pragma weak rtc_irq = default_handler
#pragma weak flash_irq = default_handler
#pragma weak rcc_irq = default_handler
#pragma weak exti0_irq = default_handler
#pragma weak exti1_irq = default_handler
#pragma weak exti2_irq = default_handler
#pragma weak exti3_irq = default_handler
#pragma weak exti4_irq = default_handler
#pragma weak dma1_channel1_irq = default_handler
#pragma weak dma1_channel2_irq = default_handler
#pragma weak dma1_channel3_irq = default_handler
#pragma weak dma1_channel4_irq = default_handler
#pragma weak dma1_channel5_irq = default_handler
#pragma weak dma1_channel6_irq = default_handler
#pragma weak dma1_channel7_irq = default_handler
#pragma weak adc1_2_irq = default_handler

#if defined(LMCU_STM32F1_CONNECTIVITY)
#pragma weak can1_tx_irq = default_handler
#pragma weak can1_rx0_irq = default_handler
#else
#pragma weak usb_hp_can1_tx_irq = default_handler
#pragma weak usb_lp_can1_rx0_irq = default_handler
#endif

#pragma weak can1_rx1_irq = default_handler
#pragma weak can1_sce_irq = default_handler
#pragma weak exti9_5_irq = default_handler

#if defined(LMCU_STM32F1_XL_DENSITY)
#pragma weak tim1_brk_tim9_irq = default_handler
#pragma weak tim1_up_tim10_irq = default_handler
#pragma weak tim1_trg_com_tim11_irq = default_handler
#else
#pragma weak tim1_brk_irq = default_handler
#pragma weak tim1_up_irq = default_handler
#pragma weak tim1_trg_com_irq = default_handler
#endif

#pragma weak tim1_cc_irq = default_handler
#pragma weak tim2_irq = default_handler
#pragma weak tim3_irq = default_handler
#pragma weak tim4_irq = default_handler
#pragma weak i2c1_ev_irq = default_handler
#pragma weak i2c1_er_irq = default_handler
#pragma weak i2c2_ev_irq = default_handler
#pragma weak i2c2_er_irq = default_handler
#pragma weak spi1_irq = default_handler
#pragma weak spi2_irq = default_handler
#pragma weak usart1_irq = default_handler
#pragma weak usart2_irq = default_handler
#pragma weak usart3_irq = default_handler
#pragma weak exti15_10_irq = default_handler
#pragma weak rtc_alarm_irq = default_handler

#if defined(LMCU_STM32F1_CONNECTIVITY)
#pragma weak otg_fs_wakeup_irq = default_handler
#else
#pragma weak usb_wakeup_irq = default_handler
#endif

#if !defined(LMCU_STM32F1_CONNECTIVITY)

#if defined(LMCU_STM32F1_XL_DENSITY)
#pragma weak tim8_brk_tim12_irq = default_handler
#pragma weak tim8_up_tim13_irq = default_handler
#pragma weak tim8_trg_com_tim14_irq = default_handler
#else
#pragma weak tim8_brk_irq = default_handler
#pragma weak tim8_up_irq = default_handler
#pragma weak tim8_trg_com_irq = default_handler
#endif // LMCU_STM32F1_XL_DENSITY

#pragma weak tim8_cc_irq = default_handler
#pragma weak adc3_irq = default_handler
#pragma weak fsmc_irq = default_handler
#pragma weak sdio_irq = default_handler

#endif // !LMCU_STM32F1_CONNECTIVITY

#pragma weak tim5_irq = default_handler
#pragma weak spi3_irq = default_handler
#pragma weak uart4_irq = default_handler
#pragma weak uart5_irq = default_handler
#pragma weak tim6_irq = default_handler
#pragma weak tim7_irq = default_handler
#pragma weak dma2_channel1_irq = default_handler
#pragma weak dma2_channel2_irq = default_handler
#pragma weak dma2_channel3_irq = default_handler

#if defined(LMCU_STM32F1_CONNECTIVITY)
#pragma weak dma2_channel4_irq = default_handler
#pragma weak dma2_channel5_irq = default_handler
#pragma weak eth_irq = default_handler
#pragma weak eth_wakeup_irq = default_handler
#pragma weak can2_tx_irq = default_handler
#pragma weak can2_rx0_irq = default_handler
#pragma weak can2_rx1_irq = default_handler
#pragma weak can2_sce_irq = default_handler
#pragma weak otg_fs_irq = default_handler
#else
#pragma weak dma2_channel4_5_irq = default_handler
#endif

namespace lmcu::isr {

__attribute__((section(".isr_vector")))
extern void(*const vectors[])() =
{                                      // POSITION
  _estack,                             //  -
  lmcu_reset_handler,                  //  -
  nmi_irq,                             //  -
  hard_fault_irq,                      //  -
  mem_manage_irq,                      //  -
  bus_fault_irq,                       //  -
  usage_fault_irq,                     //  -
  nullptr,                             //  -
  nullptr,                             //  -
  nullptr,                             //  -
  nullptr,                             //  -
  svcall_irq,                          //  -
  debug_mon_irq,                       //  -
  nullptr,                             //  -
  pend_sv_irq,                         //  -
  sys_tick_irq,                        //  -

  wwdg_irq,                            //  0
  pvd_irq,                             //  1
  tamper_irq,                          //  2
  rtc_irq,                             //  3
  flash_irq,                           //  4
  rcc_irq,                             //  5
  exti0_irq,                           //  6
  exti1_irq,                           //  7
  exti2_irq,                           //  8
  exti3_irq,                           //  9
  exti4_irq,                           // 10
  dma1_channel1_irq,                   // 11
  dma1_channel2_irq,                   // 12
  dma1_channel3_irq,                   // 13
  dma1_channel4_irq,                   // 14
  dma1_channel5_irq,                   // 15
  dma1_channel6_irq,                   // 16
  dma1_channel7_irq,                   // 17
  adc1_2_irq,                          // 18

#if defined(LMCU_STM32F1_LOW_DENSITY_VALUE_LINE) || defined(LMCU_STM32F1_MEDIUM_DENSITY_VALUE_LINE)
  usb_hp_can1_tx_irq,                  // 19
  usb_lp_can1_rx0_irq,                 // 20
  can1_rx1_irq,                        // 21
  can1_sce_irq,                        // 22
  exti9_5_irq,                         // 23
  tim1_brk_irq,                        // 24
  tim1_up_irq,                         // 25
  tim1_trg_com_irq,                    // 26
  tim1_cc_irq,                         // 27
  tim2_irq,                            // 28
  tim3_irq,                            // 29
  tim4_irq,                            // 30
  i2c1_ev_irq,                         // 31
  i2c1_er_irq,                         // 32
  i2c2_ev_irq,                         // 33
  i2c2_er_irq,                         // 34
  spi1_irq,                            // 35
  spi2_irq,                            // 36
  usart1_irq,                          // 37
  usart2_irq,                          // 38
  usart3_irq,                          // 39
  exti15_10_irq,                       // 40
  rtc_alarm_irq,                       // 41
  usb_wakeup_irq,                      // 42
  tim8_brk_irq,                        // 43
  tim8_up_irq,                         // 44
  tim8_trg_com_irq,                    // 45
  tim8_cc_irq,                         // 46
  adc3_irq,                            // 47
  fsmc_irq,                            // 48
  sdio_irq,                            // 49
  tim5_irq,                            // 50
  spi3_irq,                            // 51
  uart4_irq,                           // 52
  uart5_irq,                           // 53
  tim6_irq,                            // 54
  tim7_irq,                            // 55
  dma2_channel1_irq,                   // 56
  dma2_channel2_irq,                   // 57
  dma2_channel3_irq,                   // 58
  dma2_channel4_5_irq,                 // 59
  nullptr,                             // 60
  nullptr,                             // 61
  nullptr,                             // 62
  nullptr,                             // 63
  nullptr,                             // 64
  nullptr,                             // 65
  nullptr,                             // 66
  nullptr,                             // 67
  nullptr,                             // 68
  nullptr,                             // 69
  nullptr,                             // 70
  nullptr,                             // 71
  nullptr,                             // 72
  nullptr,                             // 73
  nullptr,                             // 74
  nullptr,                             // 75
  nullptr,                             // 76
  nullptr,                             // 77
  nullptr,                             // 78
  nullptr,                             // 79
  nullptr,                             // 80
  nullptr,                             // 81
  nullptr,                             // 82
  nullptr,                             // 83
  nullptr,                             // 84
  nullptr,                             // 85
  nullptr,                             // 86
  nullptr,                             // 87
  nullptr,                             // 88
  nullptr,                             // 89
  nullptr,                             // 90
  nullptr,                             // 91
  nullptr,                             // 92
  nullptr,                             // 93
  nullptr,                             // 94
  nullptr,                             // 95
  nullptr,                             // 96
  nullptr,                             // 97
  nullptr,                             // 98
  reinterpret_cast<void(*)()>(0xF1CCF85F)
#elif defined(LMCU_STM32F1_LOW_DENSITY) || defined(LMCU_STM32F1_MEDIUM_DENSITY)
  usb_hp_can1_tx_irq,                  // 19
  usb_lp_can1_rx0_irq,                 // 20
  can1_rx1_irq,                        // 21
  can1_sce_irq,                        // 22
  exti9_5_irq,                         // 23
  tim1_brk_irq,                        // 24
  tim1_up_irq,                         // 25
  tim1_trg_com_irq,                    // 26
  tim1_cc_irq,                         // 27
  tim2_irq,                            // 28
  tim3_irq,                            // 29
  tim4_irq,                            // 30
  i2c1_ev_irq,                         // 31
  i2c1_er_irq,                         // 32
  i2c2_ev_irq,                         // 33
  i2c2_er_irq,                         // 34
  spi1_irq,                            // 35
  spi2_irq,                            // 36
  usart1_irq,                          // 37
  usart2_irq,                          // 38
  usart3_irq,                          // 39
  exti15_10_irq,                       // 40
  rtc_alarm_irq,                       // 41
  usb_wakeup_irq,                      // 42
  tim8_brk_irq,                        // 43
  tim8_up_irq,                         // 44
  tim8_trg_com_irq,                    // 45
  tim8_cc_irq,                         // 46
  adc3_irq,                            // 47
  fsmc_irq,                            // 48
  sdio_irq,                            // 49
  reinterpret_cast<void(*)()>(0xf108f85f)
#else
#if defined(LMCU_STM32F1_CONNECTIVITY)
  can1_tx_irq,                         // 19
  can1_rx0_irq,                        // 20
#else
  usb_hp_can1_tx_irq,                  // 19
  usb_lp_can1_rx0_irq,                 // 20
#endif

  can1_rx1_irq,                        // 21
  can1_sce_irq,                        // 22
  exti9_5_irq,                         // 23

#if defined(LMCU_STM32F1_XL_DENSITY)
  tim1_brk_tim9_irq,                   // 24
  tim1_up_tim10_irq,                   // 25
  tim1_trg_com_tim11_irq,              // 26
#else
  tim1_brk_irq,                        // 24
  tim1_up_irq,                         // 25
  tim1_trg_com_irq,                    // 26
#endif

  tim1_cc_irq,                         // 27
  tim2_irq,                            // 28
  tim3_irq,                            // 29
  tim4_irq,                            // 30
  i2c1_ev_irq,                         // 31
  i2c1_er_irq,                         // 32
  i2c2_ev_irq,                         // 33
  i2c2_er_irq,                         // 34
  spi1_irq,                            // 35
  spi2_irq,                            // 36
  usart1_irq,                          // 37
  usart2_irq,                          // 38
  usart3_irq,                          // 39
  exti15_10_irq,                       // 40
  rtc_alarm_irq,                       // 41

#if defined(LMCU_STM32F1_CONNECTIVITY)
  otg_fs_wakeup_irq,                   // 42
  nullptr,                             // 43
  nullptr,                             // 44
  nullptr,                             // 45
  nullptr,                             // 46
  nullptr,                             // 47
  nullptr,                             // 48
  nullptr,                             // 49
#else
  usb_wakeup_irq,                      // 42

#if defined(LMCU_STM32F1_XL_DENSITY)
  tim8_brk_tim12_irq,                  // 43
  tim8_up_tim13_irq,                   // 44
  tim8_trg_com_tim14_irq,              // 45
#else
  tim8_brk_irq,                        // 43
  tim8_up_irq,                         // 44
  tim8_trg_com_irq,                    // 45
#endif // LMCU_STM32F1_XL_DENSITY

  tim8_cc_irq,                         // 46
  adc3_irq,                            // 47
  fsmc_irq,                            // 48
  sdio_irq,                            // 49
#endif // LMCU_STM32F1_CONNECTIVITY

  tim5_irq,                            // 50
  spi3_irq,                            // 51
  uart4_irq,                           // 52
  uart5_irq,                           // 53
  tim6_irq,                            // 54
  tim7_irq,                            // 55
  dma2_channel1_irq,                   // 56
  dma2_channel2_irq,                   // 57
  dma2_channel3_irq,                   // 58

#if defined(LMCU_STM32F1_CONNECTIVITY)
  dma2_channel4_irq,                   // 59
  dma2_channel5_irq,                   // 60
  eth_irq,                             // 61
  eth_wakeup_irq,                      // 62
  can2_tx_irq,                         // 63
  can2_rx0_irq,                        // 64
  can2_rx1_irq,                        // 65
  can2_sce_irq,                        // 66
  otg_fs_irq,                          // 67
#else
  dma2_channel4_5_irq,                 // 59
  nullptr,                             // 60
  nullptr,                             // 61
  nullptr,                             // 62
  nullptr,                             // 63
  nullptr,                             // 64
  nullptr,                             // 65
  nullptr,                             // 66
  nullptr,                             // 67
#endif

  nullptr,                             // 68
  nullptr,                             // 69
  nullptr,                             // 70
  nullptr,                             // 71
  nullptr,                             // 72
  nullptr,                             // 73
  nullptr,                             // 74
  nullptr,                             // 75
  nullptr,                             // 76
  nullptr,                             // 77
  nullptr,                             // 78
  nullptr,                             // 79
  nullptr,                             // 80
  nullptr,                             // 81
  nullptr,                             // 82
  nullptr,                             // 83
  nullptr,                             // 84
  nullptr,                             // 85
  nullptr,                             // 86
  nullptr,                             // 87
  nullptr,                             // 88
  nullptr,                             // 89
  nullptr,                             // 90
  nullptr,                             // 91
  nullptr,                             // 92
  nullptr,                             // 93
  nullptr,                             // 94
  nullptr,                             // 95
  nullptr,                             // 96
  nullptr,                             // 97
  nullptr,                             // 98
  nullptr,                             // 99
  nullptr,                             // 100
  nullptr,                             // 101
  nullptr,                             // 102
  nullptr,                             // 103
  reinterpret_cast<void(*)()>(0xF1E0F85F)
#endif
};

} // namespace lmcu::isr

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
  NVIC::VTOR::set( NVIC::VTOR::type(&lmcu::isr::vectors[0]) );
}
