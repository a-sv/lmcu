#pragma once

namespace lmcu {

enum class dev_class
{
  usart_async,
  usart_sync,
  usart_half_duplex,
  usart_mp_comm,
  usart_irda,
  usart_lin,
  usart_smartcard,
  spi,
  i2c,
  gpio_pin,
  dma,
  can,
  adc,
  adc_reg_channel,
  adc_inj_channel,
  timer,
  timer_oc,
  mtd
};

} // namespace lmcu
