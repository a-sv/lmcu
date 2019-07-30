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

namespace nvic {

enum class irq_type { disable, evi, eri };

constexpr auto default_prio_group = 3;

} // namespace nvic
#include "../cortex/nvic.h"

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
  mode _mode = mode::i2c,
  typename _irq0 = nvic::irq<nvic::irq_type::disable>,
  typename _irq1 = nvic::irq<nvic::irq_type::disable>
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
  static constexpr auto irq0         = _irq0();
  static constexpr auto irq1         = _irq1();
};

#include "detail/i2c.h"

template<typename ..._modules>
void configure() { (detail::configure<_modules>(), ...); }

template<typename ..._modules>
void enable() { (detail::enable<_modules>(), ...); }

template<typename ..._modules>
void disable() { (detail::disable<_modules>(), ...); }

template<typename _module, typename _get_fn>
io::result write(uint16_t addr, const delay::expirable &t, _get_fn&& get)
{ return detail::write<_module, io::mode::master>(addr, t, get); }

template<typename _module, typename _get_fn>
io::result write(const delay::expirable &t, _get_fn&& get)
{ return detail::write<_module, io::mode::slave>(0, t, get); }

template<typename _module>
io::result write(uint16_t addr, const void *data, uint32_t sz, const delay::expirable &t)
{ return detail::write<_module, io::mode::master>(addr, data, sz, t); }

template<typename _module>
io::result write(const void *data, uint32_t sz, const delay::expirable &t)
{ return detail::write<_module, io::mode::slave>(0, data, sz, t); }

template<typename _module>
io::result tx(uint16_t addr, uint8_t data, const delay::expirable &t)
{
  return write<_module, io::mode::master>(addr, t, [data](auto&& r) { r = data; return false; } );
}

template<typename _module>
io::result tx(uint8_t data, const delay::expirable &t)
{
  return write<_module, io::mode::slave>(0, t, [data](auto&& r) { r = data; return false; } );
}

template<typename _module>
io::result read(uint16_t addr, void *data, uint32_t sz, const delay::expirable &t)
{
  return (sz == 0)? io::result::success :
                    detail::read<_module, io::mode::master>(addr, data, sz, t);
}

template<typename _module>
io::result read(void *data, uint32_t sz, const delay::expirable &t)
{
  return (sz == 0)? io::result::success : detail::read<_module, io::mode::slave>(0, data, sz, t);
}

template<typename _module>
io::result rx(uint16_t addr, uint8_t &data, const delay::expirable &t)
{ return detail::read<_module, io::mode::master>(addr, &data, 1, t); }

template<typename _module>
io::result rx(uint8_t &data, const delay::expirable &t)
{ return detail::read<_module, io::mode::slave>(0, &data, 1, t); }

template<typename _module>
io::result write_async(const delay::expirable &t)
{ return detail::async_run<_module, io::mode::slave, io::direction::tx>(0, t); }

template<typename _module>
io::result read_async(const delay::expirable &t)
{ return detail::async_run<_module, io::mode::slave, io::direction::rx>(0, t); }

template<typename _module>
io::result write_async(uint16_t addr, const delay::expirable &t)
{ return detail::async_run<_module, io::mode::master, io::direction::tx>(addr, t); }

template<typename _module>
io::result read_async(uint16_t addr, const delay::expirable &t)
{ return detail::async_run<_module, io::mode::master, io::direction::rx>(addr, t); }

template<typename _module>
void reset() { detail::reset<_module>(); }

template<typename _module>
void ev_irq() { detail::ev_irq<_module>(); }

template<typename _module>
void er_irq() { detail::er_irq<_module>(); }

} // namespace lmcu::i2c
