#pragma once
#include <lmcu/rcc>
#include <lmcu/delay>
#include "../spi.h"

namespace lmcu {
namespace spi {

#include "detail/spi/spi.h"

template<typename module_t, bool _en>
void enable() { detail::enable<module_t, _en>(); }

template<typename ...args>
void configure() { detail::configure<args...>(); }

template<typename ...args>
void deconfigure() { detail::deconfigure<args...>(); }

template<bool _nss, typename ...args>
void set_nss() { detail::set_nss<_nss, args...>(); }

template<typename module_t>
uint16_t rx()
{
  constexpr auto m = module_t();
  switch(m.direction) {
  case direction::two_lines: return detail::two_lines::rx<module_t>();
  case direction::two_lines_rxonly: return detail::rxonly::rx<module_t>();
  default : break;
  }
  return detail::one_line::rx<module_t>();
}

template<typename module_t>
void tx(uint16_t data)
{
  constexpr auto m = module_t();
  static_assert(m.direction != direction::two_lines_rxonly, "could not transmit in rx only mode");

  if constexpr(m.direction == direction::two_lines) {
    detail::two_lines::tx<module_t>(data);
  }
  else {
    detail::one_line::tx<module_t>(data);
  }
}

template<typename module_t>
void write(const void *data, uint32_t count)
{
  constexpr auto m = module_t();
  static_assert(m.direction != direction::two_lines_rxonly, "could not transmit in rx only mode");

  if constexpr(m.direction == direction::one_line) {
    if constexpr(module_t().datasize == datasize::word) {
      detail::one_line::write<module_t>(static_cast<const uint16_t*>(data), count);
    }
    else {
      detail::one_line::write<module_t>(static_cast<const uint8_t*>(data), count);
    }
  }
  else {
    if constexpr(module_t().datasize == datasize::word) {
      detail::two_lines::write<module_t>(static_cast<const uint16_t*>(data), count);
    }
    else {
      detail::two_lines::write<module_t>(static_cast<const uint8_t*>(data), count);
    }
  }
}

template<typename module_t>
void read(void *data, uint32_t count)
{
  constexpr auto m = module_t();
  if constexpr(m.direction == direction::one_line) {
    if constexpr(m.datasize == datasize::word) {
      detail::one_line::read<module_t>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::one_line::read<module_t>(static_cast<uint8_t*>(data), count);
    }
  }
  else
  if constexpr(m.direction == direction::two_lines_rxonly) {
    if constexpr(m.datasize == datasize::word) {
      detail::rxonly::read<module_t>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::rxonly::read<module_t>(static_cast<uint8_t*>(data), count);
    }
  }
  else {
    if constexpr(m.datasize == datasize::word) {
      detail::two_lines::read<module_t>(static_cast<uint16_t*>(data), count);
    }
    else {
      detail::two_lines::read<module_t>(static_cast<uint8_t*>(data), count);
    }
  }
}

template<typename module_t>
bool crc_ok() { return detail::crc_ok<module_t>(); }

} // namespace spi
} // namespace lmcu
