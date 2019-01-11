#pragma once
#include <lmcu/rcc>
#include <lmcu/delay>

namespace lmcu::spi {

enum class module_id
{
#if defined(SPI1)
  spi1,
#endif

#if defined(SPI2)
  spi2,
#endif

#if defined(SPI3)
  spi3,
#endif

#if defined(SPI4)
  spi4,
#endif

#if defined(SPI5)
  spi5,
#endif

#if defined(SPI6)
  spi6
#endif
};

enum class mode { slave, master, multi_master };

enum class direction { two_lines, two_lines_rxonly, one_line };

enum class datasize { byte, word };

enum class polarity { low, high };

enum class phase { one_edge, two_edge };

enum class nss { soft, hard };

enum class baud_prediv
{
  _2   = 2,
  _4   = 4,
  _8   = 8,
  _16  = 16,
  _32  = 32,
  _64  = 64,
  _128 = 128,
  _256 = 256
};

enum class bit_order { msb, lsb };

enum class crc { enable, disable };

#include "detail/spi/spi.h"

template<
  module_id _module_id,
  mode _mode,
  direction _direction,
  datasize _datasize,
  polarity _polarity,
  phase _phase,
  nss _nss,
  baud_prediv _baud_prediv,
  bit_order _bit_order,
  uint16_t _crc_poly = 0x7
>
struct module
{
  static constexpr auto module_type = lmcu::module_type::spi;
  static constexpr auto module_id   = _module_id;
  static constexpr auto mode        = _mode;
  static constexpr auto direction   = _direction;
  static constexpr auto datasize    = _datasize;
  static constexpr auto polarity    = _polarity;
  static constexpr auto phase       = _phase;
  static constexpr auto nss         = _nss;
  static constexpr auto baud_prediv = _baud_prediv;
  static constexpr auto bit_order   = _bit_order;
  static constexpr auto crc_poly    = _crc_poly;
};

template<typename module_t, bool _en>
void enable() { detail::enable<module_t, _en>(); }

template<typename ...args>
void configure() { detail::configure<args...>(); }

template<typename ...args>
void deconfigure() { detail::deconfigure<args...>(); }

template<bool _nss, typename ...args>
void set_nss() { detail::set_nss<_nss, args...>(); }

template<typename module_t, crc _crc = crc::disable>
uint16_t rx()
{
  constexpr auto m = module_t();
  switch(m.direction) {
  case direction::two_lines: return detail::two_lines::rx<module_t, _crc>();
  case direction::two_lines_rxonly: return detail::rxonly::rx<module_t, _crc>();
  default : break;
  }
  return detail::one_line::rx<module_t, _crc>();
}

template<typename module_t, crc _crc = crc::disable>
void tx(uint16_t data)
{
  constexpr auto m = module_t();
  static_assert(m.direction != direction::two_lines_rxonly, "could not transmit in rx only mode");

  if constexpr(m.direction == direction::two_lines) {
    detail::two_lines::tx<module_t, _crc>(data);
  }
  else {
    detail::one_line::tx<module_t, _crc>(data);
  }
}

template<typename module_t, crc _crc = crc::disable>
void write(const void *data, uint32_t count)
{
  constexpr auto m = module_t();
  static_assert(m.direction != direction::two_lines_rxonly, "could not transmit in rx only mode");

  if constexpr(m.direction == direction::one_line) {
    if constexpr(module_t().datasize == datasize::word) {
      detail::one_line::write<module_t, _crc>(static_cast<const uint16_t*>(data), count);
    }
    else {
      detail::one_line::write<module_t, _crc>(static_cast<const uint8_t*>(data), count);
    }
  }
  else {
    if constexpr(module_t().datasize == datasize::word) {
      detail::two_lines::write<module_t, _crc>(static_cast<const uint16_t*>(data), count);
    }
    else {
      detail::two_lines::write<module_t, _crc>(static_cast<const uint8_t*>(data), count);
    }
  }
}

template<typename module_t, crc _crc = crc::disable>
void read(void *data, uint32_t count)
{
  constexpr auto m = module_t();
  if constexpr(m.direction == direction::one_line) {
    if constexpr(m.datasize == datasize::word) {
      detail::one_line::read<module_t, _crc>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::one_line::read<module_t, _crc>(static_cast<uint8_t*>(data), count);
    }
  }
  else
  if constexpr(m.direction == direction::two_lines_rxonly) {
    if constexpr(m.datasize == datasize::word) {
      detail::rxonly::read<module_t, _crc>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::rxonly::read<module_t, _crc>(static_cast<uint8_t*>(data), count);
    }
  }
  else {
    if constexpr(m.datasize == datasize::word) {
      detail::two_lines::read<module_t, _crc>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::two_lines::read<module_t, _crc>(static_cast<uint8_t*>(data), count);
    }
  }
}

template<typename module_t, bool _crc_en>
void crc_init() { detail::crc_init<module_t, _crc_en>(); }

template<typename module_t>
bool crc_ok() { return detail::crc_ok<module_t>(); }

template<typename module_t>
uint16_t crc_rxval() { return detail::crc_rxval<module_t>(); }

template<typename module_t>
uint16_t crc_txval() { return detail::crc_txval<module_t>(); }

template<typename module_t>
uint16_t crc_poly() { return detail::crc_poly<module_t>(); }

} // namespace lmcu::spi
