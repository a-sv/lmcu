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
  crc _crc = crc::disable,
  uint16_t _crc_poly = 0x7,
  bool _enable = true
>
struct module
{
  static constexpr auto dev_class   = lmcu::dev_class::spi;
  static constexpr auto module_id   = _module_id;
  static constexpr auto mode        = _mode;
  static constexpr auto direction   = _direction;
  static constexpr auto datasize    = _datasize;
  static constexpr auto polarity    = _polarity;
  static constexpr auto phase       = _phase;
  static constexpr auto nss         = _nss;
  static constexpr auto baud_prediv = _baud_prediv;
  static constexpr auto bit_order   = _bit_order;
  static constexpr auto crc         = _crc;
  static constexpr auto crc_poly    = _crc_poly;
  static constexpr auto enable      = _enable;
};

template<typename _module>
void enable() { detail::enable<_module>(); }

template<typename _module>
void disable() { detail::disable<_module>(); }

template<typename ..._modules>
void configure() { detail::configure<_modules...>(); }

template<typename ..._modules>
void deconfigure() { detail::deconfigure<_modules...>(); }

template<bool _nss, typename ..._modules>
void set_nss() { detail::set_nss<_nss, _modules...>(); }

template<typename _module, bool _crc_finish = false>
uint16_t rx()
{
  switch(_module::direction) {
  case direction::two_lines: return detail::two_lines::rx<_module, _crc_finish>();
  case direction::two_lines_rxonly: return detail::rxonly::rx<_module, _crc_finish>();
  default : break;
  }
  return detail::one_line::rx<_module, _crc_finish>();
}

template<typename _module, bool _crc_finish = false>
void tx(uint16_t data)
{
  static_assert(_module::direction != direction::two_lines_rxonly, "could not transmit in rx only "
                                                                   "mode");
  if constexpr(_module::direction == direction::two_lines) {
    detail::two_lines::tx<_module, _crc_finish>(data);
  }
  else {
    detail::one_line::tx<_module, _crc_finish>(data);
  }
}

template<typename _module, bool _crc_finish = false>
void write(const void *data, uint32_t count)
{
  static_assert(_module::direction != direction::two_lines_rxonly, "could not transmit in rx only "
                                                                   "mode");
  if constexpr(_module::direction == direction::one_line) {
    if constexpr(_module::datasize == datasize::word) {
      detail::one_line::write<_module, uint16_t, _crc_finish>(static_cast<const uint16_t*>(data),
                                                              count);
    }
    else {
      detail::one_line::write<_module, uint8_t, _crc_finish>(static_cast<const uint8_t*>(data),
                                                             count);
    }
  }
  else {
    if constexpr(_module::datasize == datasize::word) {
      detail::two_lines::write<_module, uint16_t, _crc_finish>(static_cast<const uint16_t*>(data),
                                                               count);
    }
    else {
      detail::two_lines::write<_module, uint8_t, _crc_finish>(static_cast<const uint8_t*>(data),
                                                              count);
    }
  }
}

template<typename _module, bool _crc_finish = false>
void read(void *data, uint32_t count)
{
  if constexpr(_module::direction == direction::one_line) {
    if constexpr(_module::datasize == datasize::word) {
      detail::one_line::read<_module, uint16_t, _crc_finish>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::one_line::read<_module, uint8_t, _crc_finish>(static_cast<uint8_t*>(data), count);
    }
  }
  else
  if constexpr(_module::direction == direction::two_lines_rxonly) {
    if constexpr(_module::datasize == datasize::word) {
      detail::rxonly::read<_module, uint16_t, _crc_finish>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::rxonly::read<_module, uint8_t, _crc_finish>(static_cast<uint8_t*>(data), count);
    }
  }
  else {
    if constexpr(_module::datasize == datasize::word) {
      detail::two_lines::read<_module, uint16_t, _crc_finish>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::two_lines::read<_module, uint8_t, _crc_finish>(static_cast<uint8_t*>(data), count);
    }
  }
}

template<typename _module>
void crc_reset() { detail::crc_reset<_module>(); }

template<typename _module>
bool crc_ok() { return detail::crc_ok<_module>(); }

template<typename _module>
uint16_t crc_rxval() { return detail::crc_rxval<_module>(); }

template<typename _module>
uint16_t crc_txval() { return detail::crc_txval<_module>(); }

template<typename _module>
uint16_t crc_poly() { return detail::crc_poly<_module>(); }

} // namespace lmcu::spi
