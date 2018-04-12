#pragma once

namespace detail {

template<typename module_t, bool _en>
void enable()
{
  constexpr auto m = module_t();

  if constexpr(
    m.mode == mode::master &&
    (m.direction == direction::one_line || m.direction == direction::two_lines_rxonly)
  ) {
    spi::enable<module_t, _en>();
  }
}

template<typename module_t, typename data_t>
void read(data_t *data, volatile uint32_t count)
{
  constexpr auto m = module_t();

  if(count == 0) { return; }

  auto inst = detail::inst<m.module_id>();

  if constexpr(m.crc == crc::enable) {
    // reset CRC
    inst->CR1 &= ~SPI_CR1_CRCEN;
    inst->CR1 |=  SPI_CR1_CRCEN;
  }

  detail::enable<module_t, true>();

  if constexpr(m.mode == mode::master && m.direction == direction::two_lines) {
    inst->DR = 0;
    while(count) {
      uint32_t r = inst->SR;
      if((r & SPI_SR_TXE) != 0 && (count > 0)) { inst->DR = 0; }
      if((r & SPI_SR_RXNE) != 0) { *data++ = inst->DR; count--; }
    }
  }
  else {
    const auto end = data + count;

    while(data < end) {
      if((inst->SR & SPI_SR_RXNE) != 0) { *data++ = inst->DR; }
    }
  }

  if constexpr(m.crc == crc::enable) {
    // enable CRC reception
    inst->CR1 |=  SPI_CR1_CRCNEXT;
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }

  detail::enable<module_t, false>();

  while((inst->SR & SPI_SR_BSY) != 0)
    ;
}

template<typename module_t, typename data_t>
void fast_read(data_t *data, uint32_t count)
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  static_assert(m.mode == mode::master && m.direction == direction::two_lines);

  if constexpr(m.crc == crc::enable) {
    // reset CRC
    inst->CR1 &= ~SPI_CR1_CRCEN;
    inst->CR1 |=  SPI_CR1_CRCEN;
  }

  if((inst->SR & SPI_SR_RXNE) != 0) { inst->DR; }

  inst->CR1 |= SPI_CR1_RXONLY;

  auto       p   = data;
  const auto end = data + count;

  while(p < end) {
    if((inst->SR & SPI_SR_RXNE) != 0) { *p++ = inst->DR; }
  }

  if constexpr(m.crc == crc::enable) {
    // enable CRC reception
    inst->CR1 |=  SPI_CR1_CRCNEXT;
    // wait for CRC reception
    while((inst->SR & SPI_SR_RXNE) == 0)
      ;
    inst->DR;
  }

  inst->CR1 &= ~SPI_CR1_RXONLY;
}

template<typename module_t, typename data_t>
void write(const data_t *data, uint32_t count)
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  if constexpr(m.crc == crc::enable) {
    // reset CRC
    inst->CR1 &= ~SPI_CR1_CRCEN;
    inst->CR1 |=  SPI_CR1_CRCEN;
  }

  detail::enable<module_t, true>();

  auto       p   = data;
  const auto end = data + count;

  while(p < end) {
    while((inst->SR & SPI_SR_TXE) == 0)
      ;
    inst->DR = *p++;
  }

  if constexpr(m.crc == crc::enable) {
    // enable CRC transmission
    inst->CR1 |=  SPI_CR1_CRCNEXT;
  }

  while((inst->SR & SPI_SR_TXE) == 0 || (inst->SR & SPI_SR_BSY) != 0)
    ;
  inst->DR; inst->DR;

  detail::enable<module_t, false>();
}

} // namespace detail
