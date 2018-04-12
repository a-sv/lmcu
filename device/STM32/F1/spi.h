#pragma once
#include "../spi.h"

namespace lmcu {
namespace spi {

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

#include "detail/spi.h"

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
    (m.bit_order == bit_order::lsb? SPI_CR1_LSBFIRST : 0) |
    (m.crc == crc::enable? SPI_CR1_CRCEN : 0)
  ;
  inst->CR2 = m.mode == mode::master? SPI_CR2_SSOE : 0;
  if constexpr(m.crc == crc::enable) { inst->CRCPR = m.crc_poly; }

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

template<typename module_t>
uint16_t rx()
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  if constexpr(m.crc == crc::enable) {
    // reset CRC
    inst->CR1 &= ~SPI_CR1_CRCEN;
    inst->CR1 |=  SPI_CR1_CRCEN;
  }

  if constexpr(m.direction == direction::one_line) { inst->CR1 &= ~SPI_CR1_BIDIOE; }

  if constexpr(m.direction == direction::one_line || m.direction == direction::two_lines_rxonly) {
    if((inst->SR & SPI_SR_RXNE) != 0) { inst->DR; inst->DR; }
  }

  detail::enable<module_t, true>();

  if constexpr(m.direction == direction::two_lines) {
    while((inst->SR & SPI_SR_TXE) == 0)
      ;
    inst->DR = 0;
  }

  if constexpr(m.crc == crc::enable) {
    // enable CRC reception
    inst->CR1 |=  SPI_CR1_CRCNEXT;
  }

  while((inst->SR & SPI_SR_RXNE) == 0)
    ;
  auto r = inst->DR;

  if constexpr(m.crc == crc::enable) {
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }

  detail::enable<module_t, false>();

  return r;
}

template<typename module_t>
void tx(uint16_t data)
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  static_assert(m.direction != direction::two_lines_rxonly, "could not transmit in rx only mode");

  if constexpr(m.crc == crc::enable) {
    // reset CRC
    inst->CR1 &= ~SPI_CR1_CRCEN;
    inst->CR1 |=  SPI_CR1_CRCEN;
  }

  if constexpr(m.direction == direction::one_line) { inst->CR1 |= SPI_CR1_BIDIOE; }

  detail::enable<module_t, true>();

  inst->DR = (m.datasize == datasize::word)? data : (data & 0xFF);

  if constexpr(m.crc == crc::enable) {
    // enable CRC transmission
    inst->CR1 |=  SPI_CR1_CRCNEXT;
  }

  while((inst->SR & SPI_SR_TXE) == 0 || (inst->SR & SPI_SR_BSY) != 0)
    ;
  inst->DR; inst->DR;

  detail::enable<module_t, false>();
}

template<typename module_t>
void rxtx(uint16_t &rx_data, uint16_t tx_data)
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  if constexpr(m.crc == crc::enable) {
    // reset CRC
    inst->CR1 &= ~SPI_CR1_CRCEN;
    inst->CR1 |=  SPI_CR1_CRCEN;
  }

  detail::enable<module_t, true>();

  static_assert(m.direction == direction::two_lines, "rxtx avail only in full duplex mode");

  inst->DR = (m.datasize == datasize::word)? tx_data : (tx_data & 0xFF);

  if constexpr(m.crc == crc::enable) {
    // enable CRC transmission
    inst->CR1 |=  SPI_CR1_CRCNEXT;
  }

  while((inst->SR & SPI_SR_RXNE) == 0)
    ;
  rx_data = inst->DR;

  if constexpr(m.crc == crc::enable) {
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }

  detail::enable<module_t, false>();
}

template<typename module_t>
void read(void *data, uint32_t count)
{
  if constexpr(module_t().datasize == datasize::word) {
    detail::read<module_t>(static_cast<uint16_t*>(data), count);
  }
  else {
    detail::read<module_t>(static_cast<uint8_t*>(data), count);
  }
}

template<typename module_t>
void fast_read(void *data, uint32_t count)
{
  if constexpr(module_t().datasize == datasize::word) {
    detail::fast_read<module_t>(static_cast<uint16_t*>(data), count);
  }
  else {
    detail::fast_read<module_t>(static_cast<uint8_t*>(data), count);
  }
}

template<typename module_t>
void write(const void *data, uint32_t count)
{
  if constexpr(module_t().datasize == datasize::word) {
    detail::write<module_t>(static_cast<const uint16_t*>(data), count);
  }
  else {
    detail::write<module_t>(static_cast<const uint8_t*>(data), count);
  }
}

template<typename module_t>
bool crc_is_valid()
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  static_assert(m.crc == crc::enable, "CRC must be enabled");

  auto r = (inst->SR & SPI_SR_CRCERR) == 0;
  inst->SR &= ~SPI_SR_CRCERR;

  return r;
}

} // namespace spi
} // namespace lmcu
