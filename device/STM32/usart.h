#pragma once
#include <lmcu/rcc>
#include <lmcu/delay>
#include "../../common/io.h"

namespace lmcu {
namespace usart {

enum class module_id
{
#if defined(USART1)
  usart1,
#endif

#if defined(USART2)
  usart2,
#endif

#if defined(USART3)
  usart3,
#endif

#if defined(USART4)
  usart4,
#endif

#if defined(USART5)
  usart5,
#endif

#if defined(USART6)
  usart6,
#endif

#if defined(USART7)
  usart7,
#endif

#if defined(USART8)
  usart8
#endif
};

enum class mode { async, sync, half_duplex, mp_comm, irda, lin, smartcard };

// word length with parity (bits)
enum class data_size { ds_8, ds_9 };

enum class parity { disable, even, odd };

enum class stop_bits
{
  sb_1,
  sb_0_5,
  sb_2,
  sb_1_5
};

enum class cts { enable, disable };

enum class rts { enable, disable };

template<
  module_id _module_id,
  uint32_t _baud,
  data_size _data_size = data_size::ds_8,
  parity _parity = parity::disable,
  stop_bits _stop_bits = stop_bits::sb_1,
  cts _cts = cts::disable,
  rts _rts = rts::disable
>
struct module
{
  static constexpr auto mode      = usart::mode::async;
  static constexpr auto module_id = _module_id;
  static constexpr auto baud      = _baud;
  static constexpr auto data_size = _data_size;
  static constexpr auto parity    = _parity;
  static constexpr auto stop_bits = _stop_bits;
  static constexpr auto cts       = _cts;
  static constexpr auto rts       = _rts;
};

#include "detail/usart.h"

template<typename ...args>
void configure() { detail::configure<args...>(); }

template<typename _module, io::type _iotype = io::type::blocking>
io::result rx(uint16_t &data) { return detail::rx<_module, _iotype>(data); }

template<typename _module>
io::result rx(uint16_t &data, const delay::timer &t)
{
  while(!t.expired()) {
    auto iores = detail::rx<_module, io::type::nonblocking>(data);
    if(iores != io::result::busy) { return iores; }
  }
  return io::result::busy;
}

template<typename _module, io::type _iotype = io::type::blocking>
io::result tx(uint16_t data) { return detail::tx<_module, _iotype>(data); }

template<typename _module>
io::result tx(uint16_t data, const delay::timer &t)
{
  while(!t.expired()) {
    auto iores = detail::tx<_module, io::type::nonblocking>(data);
    if(iores != io::result::busy) { return iores; }
  }
  return io::result::busy;
}

template<typename _module>
io::result write(const void *data, uint32_t size)
{
  return detail::write<_module>(data, size, [] { return false; });
}

template<typename _module>
io::result write(const void *data, uint32_t size, const delay::timer &t)
{
  return detail::write<_module>(data, size, [&] { return t.expired(); });
}

template<typename _module>
io::result read(void *data, uint32_t size, uint32_t &rx_size)
{
  return detail::read<_module>(data, size, rx_size, [] { return false; });
}

template<typename _module>
io::result read(void *data, uint32_t size, uint32_t &rx_size, const delay::timer &t)
{
  return detail::read<_module>(data, size, rx_size, [&] { return t.expired(); });
}

} // namespace usart
} // namespace lmcu
