#pragma once
#include <lmcu/hwi/bits>
#include <lmcu/lock>
#include <lmcu/delay>
#include <lmcu/gpio>

namespace lmcu::soft::uart
{

enum class data_bits
{
  _5bit = 5,
  _6bit = 6,
  _7bit = 7,
  _8bit = 8,
  _9bit = 9
};

enum class parity { none, odd, even, one, zero };

enum class stop_bits { _0_5, _1, _1_5, _2 };

enum class bit_order { msb, lsb };

enum class invert { disable, enable };

template<
  typename _tx_pin,
  uint32_t _baud = 9600,
  data_bits _data_bits = data_bits::_8bit,
  parity _parity = parity::none,
  stop_bits _stop_bits = stop_bits::_1,
  bit_order _bit_order = bit_order::lsb,
  invert _invert = invert::disable,
  bool _disable_irq = false,
  int32_t _baud_adj = 40
>
struct module
{
  static constexpr auto dev_class   = lmcu::dev_class::soft_uart;
  static constexpr auto tx_pin      = _tx_pin();
  static constexpr auto baud        = _baud;
  static constexpr auto data_bits   = _data_bits;
  static constexpr auto parity      = _parity;
  static constexpr auto stop_bits   = _stop_bits;
  static constexpr auto bit_order   = _bit_order;
  static constexpr auto invert      = _invert;
  static constexpr auto disable_irq = _disable_irq;
  static constexpr auto baud_adj    = _baud_adj;
};

template<typename _module>
void tx(uint16_t data)
{
  using tx_pin = decltype(_module::tx_pin);

  constexpr uint32_t
    bpns   = ((10000000000 / _module::baud) + 5) / 10,
    stp_ns = []() -> uint32_t
    {
      switch(_module::stop_bits) {
      case stop_bits::_0_5: return bpns / 2;
      case stop_bits::_1:   return bpns;
      case stop_bits::_1_5: return bpns * 1.5;
      default:              return bpns * 2;
      }
    }()
  ;

  const auto
    bpc     = delay::to_cycles<delay::units::ns>(bpns)   - _module::baud_adj,
    stp_cyc = delay::to_cycles<delay::units::ns>(stp_ns) - _module::baud_adj
  ;

  if constexpr(_module::invert == invert::enable) { data = ~data; }

  if constexpr(_module::bit_order == bit_order::msb) {
    data <<= 16 - uint16_t(_module::data_bits);
  }
  else {
    data &= 0xffff >> (16 - uint16_t(_module::data_bits));
  }

  [[maybe_unused]] auto parity_bit = [&data]() -> bool
  {
    switch(_module::parity) {
    case parity::odd:  return !(__builtin_parity(data) && _module::invert == invert::disable);
    case parity::even: return  (__builtin_parity(data) && _module::invert == invert::disable);
    case parity::one:  return true;
    default: break;
    }
    return false;
  }();

  auto send_databit = [&data, bpc]
  {
    if constexpr(_module::bit_order == bit_order::msb) {
      gpio::set<tx_pin>(data & 0x8000);
      data <<= 1;
    }
    else {
      gpio::set<tx_pin>(data & 0x1);
      data >>= 1;
    }
    delay::cyc(bpc);
  };

  [[maybe_unused]] bool irqen;

  if constexpr(_module::disable_irq) {
    irqen = __get_PRIMASK() == 0;
    __disable_irq();
  }

  // start bit

  gpio::set<tx_pin>(_module::invert == invert::enable);
  delay::cyc(bpc);

  // data bits

  send_databit();
  send_databit();
  send_databit();
  send_databit();
  send_databit();

  switch(_module::data_bits) {
  case data_bits::_9bit: send_databit();
  case data_bits::_8bit: send_databit();
  case data_bits::_7bit: send_databit();
  case data_bits::_6bit: send_databit();
  default: break;
  }

  // parity bit

  if constexpr(_module::parity != parity::none) {
    gpio::set<tx_pin>(parity_bit);
    delay::cyc(bpc);
  }

  // stop bit

  gpio::set<tx_pin>(_module::invert == invert::disable);

  if constexpr(_module::disable_irq) {
    if(irqen) { __enable_irq(); }
  }

  delay::cyc(stp_cyc);
}

template<typename _module>
io::result write(const void *data, uint32_t size, uint32_t &tx_bits, const delay::expirable &t)
{
  tx_bits = 0;

  const bool res = bits::split<uint8_t(_module::data_bits)>(data, size, [&](auto&& data)
  {
    if(t.expired()) { return false; }
    tx<_module>(data);
    tx_bits += uint8_t(_module::data_bits);
    return true;
  });

  return res? io::result::success : io::result::busy;
}

template<typename _module>
io::result write(const void *data, uint32_t size, const delay::expirable &t)
{
  uint32_t tx_bits;
  return write<_module>(data, size, tx_bits, t);
}

} // namespace lmcu::soft
