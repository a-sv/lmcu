#pragma once
#include <lmcu/hwi/common>
#include <lmcu/rcc>
#include <lmcu/delay>

namespace lmcu::usart {

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

// word length with parity
enum class data_size { _8bit, _9bit };

enum class parity { disable, even, odd };

enum class stop_bits
{
  _1,
  _0_5,
  _2,
  _1_5
};

enum class cts { disable, enable };

enum class rts { disable, enable };

enum class dma { disable, rx, tx, rxtx };

namespace nvic {

enum class irq_type { disable, usi };

constexpr auto default_prio_group = 3;

} // namespace nvic
#include "../cortex/nvic.h"

template<
  module_id _module_id,
  uint32_t _baud,
  data_size _data_size = data_size::_8bit,
  parity _parity = parity::disable,
  stop_bits _stop_bits = stop_bits::_1,
  cts _cts = cts::disable,
  rts _rts = rts::disable,
  dma _dma = dma::disable,
  typename _irq = nvic::irq<nvic::irq_type::disable>
>
struct module_async
{
  static constexpr auto module_type = lmcu::module_type::usart_async;
  static constexpr auto module_id   = _module_id;
  static constexpr auto baud        = _baud;
  static constexpr auto data_size   = _data_size;
  static constexpr auto parity      = _parity;
  static constexpr auto stop_bits   = _stop_bits;
  static constexpr auto cts         = _cts;
  static constexpr auto rts         = _rts;
  static constexpr auto dma         = _dma;
  static constexpr auto irq         = _irq();
};

enum class event
{
  pe   = 1 << 0, // Parity error
  fe   = 1 << 1, // Framing error
  ne   = 1 << 2, // Noise error
  ore  = 1 << 3, // Overrun error
  idle = 1 << 4, // IDLE line detected
  rxne = 1 << 5, // Read data register not empty
  tc   = 1 << 6, // Transmission complete
  txe  = 1 << 7, // Transmit data register empty
  lbd  = 1 << 8, // LIN break detection
  cts  = 1 << 9  // CTS
};
lmcu_enum_class_flags_impl(event)

#include "detail/usart.h"

template<typename ..._modules>
void configure() { detail::configure<_modules...>(); }

template<typename ..._modules>
void enable() { detail::enable<_modules...>(); }

template<typename ..._modules>
void disable() { detail::disable<_modules...>(); }

template<typename _module>
io::result rx(uint16_t &data) { return detail::rx<_module>(data); }

template<typename _module>
io::result rx(uint16_t &data, const delay::expirable &t)
{
  io::result rc = io::result::busy;
  while(rc == io::result::busy && !t.expired()) { rc = detail::rx<_module>(data); }
  return rc;
}

template<typename _module>
io::result tx(uint16_t data) { return detail::tx<_module>(data); }

template<typename _module>
io::result tx(uint16_t data, const delay::expirable &t)
{
  io::result rc = io::result::busy;
  while(rc == io::result::busy && !t.expired()) { rc = detail::tx<_module>(data); }
  return rc;
}

template<typename _module>
io::result write(const void *data, uint32_t size, uint32_t &tx_size, const delay::expirable &t)
{
  return detail::write<_module>(data, size, tx_size, t);
}

template<typename _module>
io::result write(const void *data, uint32_t size, const delay::expirable &t)
{
  uint32_t tx_size;
  return detail::write<_module>(data, size, tx_size, t);
}

template<typename _module>
io::result read(void *data, uint32_t size, uint32_t &rx_size, const delay::expirable &t)
{
  return detail::read<_module>(data, size, rx_size, t);
}

template<typename _module>
io::result read(void *data, uint32_t size, const delay::expirable &t)
{
  uint32_t rx_size;
  return detail::read<_module>(data, size, rx_size, t);
}

template<typename _module>
uint32_t dma_address() { return detail::dma_address<_module>(); }

template<typename _module, event ..._events>
void enable_events() { detail::enable_events<_module, _events...>(); }

template<typename _module, event ..._events>
void disable_events() { detail::disable_events<_module, _events...>(); }

template<typename _module>
event irq_source() { return detail::irq_source<_module>(); }

template<typename _module, event ..._events>
void irq_clear() { detail::irq_clear<_module, _events...>(); }

} // namespace lmcu::usart
