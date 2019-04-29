#pragma once
#include <lmcu/gpio>
#include <lmcu/delay>

namespace lmcu::soft::one_wire
{

template<
  typename _dq_tx,
  typename _dq_rx,
  uint32_t _time_slot    = 60,
  uint32_t _reset_time   = 480,
  uint32_t _smpr_time    = 15,
  uint32_t _min_low_time = 1,
  uint32_t _rec_time     = 1
>
struct module
{
  static constexpr auto dev_class    = lmcu::dev_class::soft_one_wire;
  static constexpr auto dq_tx        = _dq_tx();
  static constexpr auto dq_rx        = _dq_rx();
  static constexpr auto time_slot    = _time_slot;
  static constexpr auto reset_time   = _reset_time;
  static constexpr auto smpr_time    = _smpr_time;
  static constexpr auto min_low_time = _min_low_time;
  static constexpr auto rec_time     = _rec_time;
};

template<typename _module>
bool start()
{
  using dq_tx = decltype(_module::dq_tx);
  using dq_rx = decltype(_module::dq_rx);

  gpio::configure<dq_tx>();

  gpio::set<false, dq_tx>();
  delay::us(_module::reset_time);

  gpio::configure<dq_rx>();

  delay::dwt::timer t;
  t.start<delay::units::us>(_module::reset_time);

  // wait for line set to high
  while(!gpio::read<dq_rx>() && !t.expired())
    ;

  if(t.expired()) {
    // short circuit DQ to GND
    return false;
  }

  // wait for presence pulse start
  while(gpio::read<dq_rx>() && !t.expired())
    ;

  if(t.expired()) {
    // presence pulse start not detected
    return false;
  }

  // wait for presence pulse end
  while(!gpio::read<dq_rx>() && !t.expired())
    ;

  if(t.expired()) {
    // presence pulse end is not detected
    return false;
  }

  // wait for device init
  while(!t.expired())
    ;

  return true;
}

template<typename _module, typename _data>
io::result tx(_data data)
{
  using dq_tx = decltype(_module::dq_tx);
  using dq_rx = decltype(_module::dq_rx);

  delay::dwt::timer t;

  for(uint_fast8_t n = 0; n < (sizeof(_data) * 8); n++) {
    gpio::configure<dq_tx>();
    gpio::set<false, dq_tx>();

    if(data & 1) {
      delay::us(_module::min_low_time);
      gpio::configure<dq_rx>();

      t.start<delay::units::us>(_module::time_slot - _module::min_low_time);

      while(!gpio::read<dq_rx>()) {
        if(t.expired()) { return io::result::error; }
      }

      t.wait();
    }
    else {
      delay::us(_module::time_slot);
      gpio::configure<dq_rx>();
    }
    data >>= 1;

    t.start<delay::units::us>(_module::rec_time);

    while(!gpio::read<dq_rx>()) {
      if(t.expired()) { return io::result::error; }
    }

    t.wait();
  }

  return io::result::success;
}

template<typename _module, typename _data>
io::result rx(_data&& data)
{
  using dq_tx = decltype(_module::dq_tx);
  using dq_rx = decltype(_module::dq_rx);

  data = 0;

  for(uint_fast8_t n = 0; n < (sizeof(_data) * 8); n++) {
    gpio::configure<dq_tx>();

    gpio::set<false, dq_tx>();
    delay::us(_module::min_low_time);

    gpio::configure<dq_rx>();
    delay::us(_module::smpr_time - _module::min_low_time - 1);

    data |= (gpio::read<dq_rx>() << n);

    delay::us(_module::time_slot - _module::smpr_time);
  }

  return io::result::success;
}

template<typename _module>
io::result write(const void *data, uint32_t sz, const delay::expirable &t)
{
  auto p = static_cast<const uint8_t*>(data), end = p + sz;

  for(; p < end; ++p) {
    if(t.expired()) { return io::result::busy; }
    if(auto r = tx<_module>(*p); r != io::result::success) { return r; }
  }

  return io::result::success;
}

template<typename _module>
io::result read(void *data, uint32_t sz, const delay::expirable &t)
{
  auto p = static_cast<uint8_t*>(data), end = p + sz;

  for(; p < end; ++p) {
    if(t.expired()) { return io::result::busy; }
    if(auto r = rx<_module>(*p); r != io::result::success) { return r; }
  }

  return io::result::success;
}

} // namespace lmcu::soft::one_wire