#pragma once

namespace detail {

template<module_id _module_id>
SPI_TypeDef *inst()
{
#if defined(SPI1)
  if constexpr(_module_id == module_id::spi1) { return SPI1; }
#endif

#if defined(SPI2)
  if constexpr(_module_id == module_id::spi2) { return SPI2; }
#endif

#if defined(SPI3)
  if constexpr(_module_id == module_id::spi3) { return SPI3; }
#endif

#if defined(SPI4)
  if constexpr(_module_id == module_id::spi4) { return SPI4; }
#endif

#if defined(SPI5)
  if constexpr(_module_id == module_id::spi5) { return SPI5; }
#endif

#if defined(SPI6)
  if constexpr(_module_id == module_id::spi6) { return SPI6; }
#endif
}

template<typename module_t, bool _en>
void enable()
{
  auto inst = detail::inst<module_t().module_id>();
  if constexpr(_en) {
    inst->CR1 |= SPI_CR1_SPE;
  }
  else {
    inst->CR1 &= ~SPI_CR1_SPE;
  }
}

template<typename arg1, typename ...args>
void configure()
{
  if constexpr(sizeof...(args) > 0) { configure<args...>(); }
  constexpr auto m = arg1();

#if defined(SPI1)
  if constexpr(m.module_id == module_id::spi1) {
    RCC->APB2ENR  |=  RCC_APB2ENR_SPI1EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_SPI1RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST;
  }
#endif

#if defined(SPI2)
  if constexpr(m.module_id == module_id::spi2) {
    RCC->APB1ENR  |=  RCC_APB1ENR_SPI2EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_SPI2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI2RST;
  }
#endif

#if defined(SPI3)
  if constexpr(m.module_id == module_id::spi3) {
    RCC->APB1ENR  |=  RCC_APB1ENR_SPI3EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_SPI3RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI3RST;
  }
#endif

  enable<arg1, false>();

  auto inst = detail::inst<m.module_id>();
  inst->CR1 =
    ((m.mode == mode::master || m.mode == mode::multi_master)? SPI_CR1_MSTR : 0) |
    []() -> uint32_t
    {
      switch(m.direction) {
      case direction::one_line: return SPI_CR1_BIDIMODE;
      case direction::two_lines_rxonly: return SPI_CR1_RXONLY;
      default: return 0;
      }
    }() |
    (m.datasize == datasize::word? SPI_CR1_DFF : 0) |
    (m.polarity == polarity::high? SPI_CR1_CPOL : 0) |
    (m.phase == phase::two_edge? SPI_CR1_CPHA : 0) |
    []() -> uint32_t
    {
      if constexpr(m.mode == mode::slave) {
        if constexpr(m.nss == nss::soft) { return SPI_CR1_SSM; }
        return 0;
      }
      return m.mode == mode::master? (SPI_CR1_SSM | SPI_CR1_SSI) : 0;
    }() |
    []() -> uint32_t
    {
      switch(m.baud_prediv) {
      case baud_prediv::div_4:   return 1 << SPI_CR1_BR_Pos;
      case baud_prediv::div_8:   return 2 << SPI_CR1_BR_Pos;
      case baud_prediv::div_16:  return 3 << SPI_CR1_BR_Pos;
      case baud_prediv::div_32:  return 4 << SPI_CR1_BR_Pos;
      case baud_prediv::div_64:  return 5 << SPI_CR1_BR_Pos;
      case baud_prediv::div_128: return 6 << SPI_CR1_BR_Pos;
      case baud_prediv::div_256: return 7 << SPI_CR1_BR_Pos;
      default: return 0;
      }
    }() |
    (m.bit_order == bit_order::lsb? SPI_CR1_LSBFIRST : 0)
  ;
  inst->CR2   = m.mode == mode::master? SPI_CR2_SSOE : 0;
  inst->CRCPR = m.crc_poly;

  if constexpr(
    m.mode == mode::slave || (m.mode == mode::master && m.direction == direction::two_lines)
  ) { enable<arg1, true>(); }
}

template<typename arg1, typename ...args>
void deconfigure()
{
  if constexpr(sizeof...(args) > 0) { deconfigure<args...>(); }
  constexpr auto m = arg1();

#if defined(SPI1)
  if constexpr(m.module_id == module_id::spi1) { RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN; }
#endif

#if defined(SPI2)
  if constexpr(m.module_id == module_id::spi2) { RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN; }
#endif

#if defined(SPI3)
  if constexpr(m.module_id == module_id::spi3) { RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN; }
#endif
}

template<bool _nss, typename arg1, typename ...args>
void set_nss()
{
  if constexpr(sizeof...(args) > 0) { set_nss<_nss, args...>(); }
  constexpr auto m = arg1();

  static_assert(m.nss == nss::soft || m.mode == mode::master);

  if constexpr(_nss) {
    detail::inst<m.module_id>()->CR1 |= SPI_CR1_SSI;
  }
  else {
    detail::inst<m.module_id>()->CR1 &= ~SPI_CR1_SSI;
  }
}

template<typename module_t, bool _crc_en>
void crc_init()
{
  auto inst = detail::inst<module_t().module_id>();

  inst->CR1 &= ~SPI_CR1_CRCEN;
  if constexpr(_crc_en) { inst->CR1 |= SPI_CR1_CRCEN; }
}

template<typename module_t>
bool crc_ok()
{
  auto inst = detail::inst<module_t().module_id>();

  auto r = (inst->SR & SPI_SR_CRCERR) == 0;
  inst->SR &= ~SPI_SR_CRCERR;

  return r;
}

template<typename module_t>
uint16_t crc_rxval() { return detail::inst<module_t().module_id>()->RXCRCR; }

template<typename module_t>
uint16_t crc_txval() { return detail::inst<module_t().module_id>()->TXCRCR; }

template<typename module_t>
uint16_t crc_poly() { return detail::inst<module_t().module_id>()->CRCPR; }

template<bool _master, direction _direction, bool _crc_send>
lmcu_force_inline void rx_begin(SPI_TypeDef *inst)
{
  if constexpr(_direction == direction::one_line) {
    // turn on bidirectional RX mode
    inst->CR1 &= ~SPI_CR1_BIDIOE;
  }

  if constexpr(_master && _direction != direction::two_lines) {
    // enable SPI module
    inst->CR1 |= SPI_CR1_SPE;
  }
}

template<direction _direction, bool _crc_send>
lmcu_force_inline uint16_t slave_rx(SPI_TypeDef *inst)
{
  rx_begin<false, _direction, _crc_send>(inst);

  while((inst->SR & SPI_SR_RXNE) == 0)
    ;
  if constexpr(_crc_send) {
    // enable CRC reception
    inst->CR1 |= SPI_CR1_CRCNEXT;
  }

  auto data = inst->DR;

  if constexpr(_crc_send) {
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }

  return data;
}

template<direction _direction, bool _crc_send, typename data_t>
lmcu_force_inline void slave_read(SPI_TypeDef *inst, data_t *data, uint32_t count)
{
  rx_begin<false, _direction, _crc_send>(inst);

  const auto end = data + count;
  while(data < end - 1) {
    if((inst->SR & SPI_SR_RXNE) != 0) { *data++ = inst->DR; }
  }

  while((inst->SR & SPI_SR_RXNE) == 0)
    ;

  if constexpr(_crc_send) {
    // enable CRC reception
    inst->CR1 |= SPI_CR1_CRCNEXT;
  }

  *data = inst->DR;

  if constexpr(_crc_send) {
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }
}

template<direction _direction, bool _crc_send, typename delay_fn>
lmcu_force_inline uint16_t master_rx(SPI_TypeDef *inst, delay_fn&& dfn)
{
  rx_begin<true, _direction, _crc_send>(inst);

  if constexpr(_direction == direction::two_lines) {
    inst->DR = 0;

    if constexpr(_crc_send) {
      // enable CRC reception
      inst->CR1 |= SPI_CR1_CRCNEXT;
    }

    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    auto data = inst->DR;

    if constexpr(_crc_send) {
      // wait for CRC reception
      while((inst->SR & SPI_SR_RXNE) == 0)
        ;
      inst->DR;
    }

    while((inst->SR & SPI_SR_TXE) == 0 || (inst->SR & SPI_SR_BSY) != 0)
      ;
    return data;
  }

  if constexpr(!_crc_send) {
    // wait 1 SPI cycle for begining clocks transmision
    dfn();
    // disable SPI module
    inst->CR1 &= ~SPI_CR1_SPE;
  }

  // wait for first data recived
  while((inst->SR & SPI_SR_RXNE) == 0)
    ;

  if constexpr(_crc_send) {
    // wait 1 SPI cycle for begining clocks transmision
    dfn();
    // disable SPI module
    inst->CR1 &= ~SPI_CR1_SPE;
  }

  auto data = inst->DR;

  if constexpr(_crc_send) {
    // enable CRC reception
    inst->CR1 |= SPI_CR1_CRCNEXT;
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }

  return data;
}

template<direction _direction, bool _crc_send, typename data_t, typename delay_fn>
lmcu_force_inline void master_read(SPI_TypeDef *inst, data_t *data, uint32_t count, delay_fn&& dfn)
{
  if(!count) { return; }

  rx_begin<true, _direction, _crc_send>(inst);

  const auto end = data + count;

  if constexpr(_direction == direction::two_lines) {
    auto rx_next = [inst](bool last)
    {
      inst->DR = 0;

      if constexpr(_crc_send) {
        // enable CRC reception
        if(last) { inst->CR1 |= SPI_CR1_CRCNEXT; }
      }

      while((inst->SR & SPI_SR_RXNE) == 0)
        ;
    };

    while(data < end - 1) { rx_next(false); *data++ = inst->DR; }

    rx_next(true);

    *data = inst->DR;

    if constexpr(_crc_send) {
      // wait for CRC reception
      while((inst->SR & SPI_SR_RXNE) == 0)
        ;
      inst->DR;
    }

    while((inst->SR & SPI_SR_TXE) == 0 || (inst->SR & SPI_SR_BSY) != 0)
      ;

    return;
  }

  if constexpr(_crc_send) {
    while(data < end) {
      if((inst->SR & SPI_SR_RXNE) != 0) { *data++ = inst->DR; }
    }
  }
  else {
    while(data < end - 1) {
      if((inst->SR & SPI_SR_RXNE) != 0) { *data++ = inst->DR; }
    }
  }

  // wait 1 SPI cycle for begining clocks transmision
  dfn();
  // disable SPI module
  inst->CR1 &= ~SPI_CR1_SPE;

  if constexpr(_crc_send) {
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }
  else {
    // wait for last data recived
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    *data++ = inst->DR;
  }
}

template<direction _direction>
lmcu_force_inline void tx_begin(SPI_TypeDef *inst)
{
  if constexpr(_direction == direction::one_line) {
    // turn on bidirectional TX mode and enable SPI module
    inst->CR1 |= SPI_CR1_BIDIOE | SPI_CR1_SPE;
  }
}

template<direction _direction, bool _crc_send>
lmcu_force_inline void tx_finish(SPI_TypeDef *inst)
{
  if constexpr(_crc_send) {
    // enable CRC transmission
    inst->CR1 |=  SPI_CR1_CRCNEXT;
  }

  while((inst->SR & SPI_SR_TXE) == 0 || (inst->SR & SPI_SR_BSY) != 0)
    ;

  if constexpr(_direction == direction::one_line) {
    // disable SPI module
    inst->CR1 &= ~SPI_CR1_SPE;
  }

  if constexpr(_direction == direction::two_lines) {
    // clear OVF flag in full-duplex mode
    inst->DR; inst->DR;
  }
}

template<direction _direction, bool _crc_send>
lmcu_force_inline void tx(SPI_TypeDef *inst, uint16_t data)
{
  tx_begin<_direction>(inst);
  inst->DR = data;
  tx_finish<_direction, _crc_send>(inst);
}

template<direction _direction, bool _crc_send, typename data_t>
lmcu_force_inline void write(SPI_TypeDef *inst, const data_t *data, uint32_t count)
{
  if(!count) { return; }

  tx_begin<_direction>(inst);

  const auto end = data + count;
  while(data < end) {
    if((inst->SR & SPI_SR_TXE) != 0) { inst->DR = *data++; }
  }

  tx_finish<_direction, _crc_send>(inst);
}

lmcu_force_inline void delay_4cyc() { asm volatile("nop\n nop\n nop\n nop\n"); }

namespace one_line {

uint16_t slave_rx(SPI_TypeDef *inst);
uint16_t slave_rx_with_crc(SPI_TypeDef *inst);

// ---

void slave_tx(SPI_TypeDef *inst, uint16_t data);
void slave_tx_with_crc(SPI_TypeDef *inst, uint16_t data);

// ---

uint16_t master_rx(SPI_TypeDef *inst);
uint16_t master_rx_with_crc(SPI_TypeDef *inst);

uint16_t master_rx(SPI_TypeDef *inst, uint32_t delay_val);
uint16_t master_rx_with_crc(SPI_TypeDef *inst, uint32_t delay_val);

// ---

void master_tx(SPI_TypeDef *inst, uint16_t data);
void master_tx_with_crc(SPI_TypeDef *inst, uint16_t data);

// ---

void slave_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count);
void slave_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count);

void slave_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count);
void slave_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count);

// ---

void slave_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);
void slave_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);

void slave_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);
void slave_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);

// ---

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count);
void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count);

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count);
void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count);

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val);
void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val);

void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val);
void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val);

// ---

void master_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);
void master_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);

void master_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);
void master_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);


#include "iface_tx.h"
#include "iface_rx_half_duplex.h"

} // namespace one_line

namespace rxonly {

uint16_t slave_rx(SPI_TypeDef *inst);
uint16_t slave_rx_with_crc(SPI_TypeDef *inst);

// ---

void slave_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count);
void slave_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count);

void slave_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count);
void slave_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count);

// ---

uint16_t master_rx(SPI_TypeDef *inst);
uint16_t master_rx_with_crc(SPI_TypeDef *inst);

uint16_t master_rx(SPI_TypeDef *inst, uint32_t delay_val);
uint16_t master_rx_with_crc(SPI_TypeDef *inst, uint32_t delay_val);

// ---

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count);
void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count);

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count);
void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count);

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val);
void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val);

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val);
void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val);

#include "iface_rx_half_duplex.h"

} // namespace rxonly

namespace two_lines {

uint16_t slave_rx(SPI_TypeDef *inst);
uint16_t slave_rx_with_crc(SPI_TypeDef *inst);

// ---

void slave_tx(SPI_TypeDef *inst, uint16_t data);
void slave_tx_with_crc(SPI_TypeDef *inst, uint16_t data);

// ---

uint16_t master_rx(SPI_TypeDef *inst);
uint16_t master_rx_with_crc(SPI_TypeDef *inst);

void master_tx(SPI_TypeDef *inst, uint16_t data);
void master_tx_with_crc(SPI_TypeDef *inst, uint16_t data);

// ---

void slave_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count);
void slave_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count);

void slave_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count);
void slave_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count);

// ---

void slave_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);
void slave_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);

void slave_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);
void slave_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);

// ---

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count);
void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count);

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count);
void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count);

// ---

void master_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);
void master_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count);

void master_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);
void master_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count);

#include "iface_tx.h"
#include "iface_rx_full_duplex.h"

} // namespace two_lines

} // namespace detail
