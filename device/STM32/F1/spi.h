#pragma once
#include "../spi.h"

namespace lmcu {
namespace spi {

#include "detail/spi.h"

template<typename module_t, bool _en>
void enable() { detail::enable<module_t, _en>(); }

template<typename ...args>
void configure() { detail::configure<args...>(); }

template<typename ...args>
void deconfigure() { detail::deconfigure<args...>(); }

template<bool _nss, typename ...args>
void set_nss() { detail::set_nss<_nss, args...>(); }

template<typename module_t>
uint16_t rx() { return detail::rx<module_t>(); }

template<typename module_t>
void tx(uint16_t data) { detail::tx<module_t>(data); }

template<typename module_t>
void rxtx(uint16_t &rx_data, uint16_t tx_data) { detail::rxtx<module_t>(rx_data, tx_data); }

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
bool crc_ok() { return detail::crc_ok<module_t>(); }

} // namespace spi
} // namespace lmcu
