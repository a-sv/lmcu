#pragma once
#include <lmcu/hwi/common>
#include <lmcu/rcc>
#include <lmcu/delay>
#include <lmcu/lock>

namespace lmcu::i2c {

enum class module_id
{
#if defined(I2C1)
  i2c1,
#endif

#if defined(I2C2)
  i2c2,
#endif

#if defined(I2C3)
  i2c3
#endif
};

enum class mode { i2c, smbus_dev, smbus_host };

enum class dutycycle { _2, _16_9 };

enum class addr_mode { _7bit, _10bit };

enum class dual_addr { enable, disable };

enum class general_call { enable, disable };

enum class no_stretch { enable, disable };

enum class io_mode { master, slave };

template<
  module_id _module_id,
  uint32_t _clock = 100_kHz,
  addr_mode _addr_mode = addr_mode::_7bit,
  dutycycle _dutycycle = dutycycle::_2,
  uint32_t _own_addr_1 = 0,
  dual_addr _dual_addr = dual_addr::disable,
  uint32_t _own_addr_2 = 0,
  general_call _general_call = general_call::disable,
  no_stretch _no_stretch = no_stretch::disable,
  mode _mode = mode::i2c
>
struct module
{
  static constexpr auto dev_class    = lmcu::dev_class::i2c;
  static constexpr auto module_id    = _module_id;
  static constexpr auto clock        = _clock;
  static constexpr auto addr_mode    = _addr_mode;
  static constexpr auto dutycycle    = _dutycycle;
  static constexpr auto own_addr_1   = _own_addr_1;
  static constexpr auto dual_addr    = _dual_addr;
  static constexpr auto own_addr_2   = _own_addr_2;
  static constexpr auto general_call = _general_call;
  static constexpr auto no_stretch   = _no_stretch;
  static constexpr auto mode         = _mode;
};

#include "detail/i2c.h"

template<typename ..._modules>
void configure() { (detail::configure<_modules>(), ...); }

template<typename ..._modules>
void enable() { (detail::enable<_modules>(), ...); }

template<typename ..._modules>
void disable() { (detail::disable<_modules>(), ...); }

template<typename _module, io_mode _io_mode, typename _get_fn>
io::result write(uint16_t addr, const delay::expirable &t, _get_fn&& get)
{ return detail::write<_module, _io_mode>(addr, t, get); }

template<typename _module, io_mode _io_mode>
io::result write(uint16_t addr, const void *data, uint32_t sz, const delay::expirable &t)
{
  if(sz == 0) {
    return io::result::success;
  }
  auto b = static_cast<const uint8_t*>(data), e = b + sz;
  return write<_module, _io_mode>(addr, t, [&b, e](auto&& r) { r = *b++; return b < e; } );
}

template<typename _module, io_mode _io_mode>
io::result tx(uint16_t addr, uint8_t data, const delay::expirable &t)
{
  return write<_module, _io_mode>(addr, t, [data](auto&& r) { r = data; return false; } );
}

template<typename _module, io_mode _io_mode>
io::result read(uint16_t addr, void *data, uint32_t sz, const delay::expirable &t)
{
  if(sz == 0) {
    return io::result::success;
  }
  return detail::read<_module, _io_mode>(addr, data, sz, t);
}

template<typename _module, io_mode _io_mode>
io::result rx(uint16_t addr, uint8_t &data, const delay::expirable &t)
{ return detail::read<_module, _io_mode>(addr, &data, 1, t); }

template<typename _module>
void reset() { detail::reset<_module>(); }

} // namespace lmcu::i2c
