#pragma once
#include "../can.h"

namespace lmcu {
namespace can {

#include "detail/can.h"

template<typename ...args>
void configure()
{
  detail::configure<args...>();
  detail::remap_configure<args...>();
}

template<typename _module, typename ...args>
void filter_enable() { detail::filter_enable<_module, args...>(); }

template<typename _module, typename ...args>
void filter_disable() { detail::filter_disable<_module, args...>(); }

template<typename _module, io::type _iotype = io::type::blocking>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len)
{
  return detail::tx<_module, _iotype>(id, ide, rtr, data, len);
}

template<typename _module>
void abort_tx() { detail::abort_tx<_module>(); }

template<typename _module, fifo _fifo = fifo::any, io::type _iotype = io::type::blocking>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len)
{
  return detail::rx<_module, _fifo, _iotype>(id, ide, rtr, fmi, data, len);
}

} // namespace can
} // namespace lmcu
