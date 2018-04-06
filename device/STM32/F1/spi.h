#pragma once
#include "../spi.h"

namespace lmcu {
namespace spi {

namespace detail {

template<module_id _id, bool _en>
void spi_enable()
{
  auto inst = detail::inst<_id>();

  if constexpr(_en) {
    inst->CR1 |= SPI_CR1_SPE;
  }
  else {
    inst->CR1 &= ~SPI_CR1_SPE;
  }
}

} // namespace detail

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

  detail::spi_enable<m.module_id, false>();

  auto inst = detail::inst<m.module_id>();
  inst->CR1 =
    ((m.mode == mode::master || m.mode == mode::multi_master)? SPI_CR1_MSTR : 0) |
    []() -> uint32_t
    {
      switch(m.direction) {
      case direction::one_line: SPI_CR1_BIDIMODE; break;
      case direction::two_lines_rxonly: SPI_CR1_RXONLY; break;
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

} // namespace spi
} // namespace lmcu
