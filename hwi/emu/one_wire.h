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

namespace detail
{

template<typename _module>
static io::result rx_bit(bool &b)
{
  using dq_tx = decltype(_module::dq_tx);
  using dq_rx = decltype(_module::dq_rx);

  delay::dwt::timer t;

  gpio::configure<dq_tx>();

  gpio::set<false, dq_tx>();
  delay::us(_module::min_low_time);

  gpio::configure<dq_rx>();
  delay::us(_module::smpr_time - _module::min_low_time - 1);

  b = gpio::read<dq_rx>();

  delay::us(_module::time_slot - _module::smpr_time);

  t.start<delay::units::us>(_module::rec_time);
  while(!gpio::read<dq_rx>()) {
    if(t.expired()) { return io::result::error; }
  }
  t.wait();

  return io::result::success;
}

template<typename _module>
static io::result tx_bit(bool b)
{
  using dq_tx = decltype(_module::dq_tx);
  using dq_rx = decltype(_module::dq_rx);

  delay::dwt::timer t;

  gpio::configure<dq_tx>();
  gpio::set<false, dq_tx>();

  if(b) {
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

  t.start<delay::units::us>(_module::rec_time);
  while(!gpio::read<dq_rx>()) {
    if(t.expired()) { return io::result::error; }
  }
  t.wait();

  return io::result::success;
}

template<typename _module>
bool presence()
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

static inline bool check_rom(const uint8_t rom[8])
{
  uint_fast8_t crc = 0, in, mix;

  for(uint_fast8_t n = 0; n < 7; ++n) {
    in = rom[n];
    for(uint_fast8_t i = 0; i < 8; ++i) {
      mix = (crc ^ in) & 1;
      crc >>= 1U;
      if(mix) { crc ^= 0x8CU; }
      in  >>= 1U;
    }
  }

  return rom[7] == crc;
}

} // namespace detail

/**
 * @brief Receive word from bus
 *
 * @tparam _module - 1-wire module struct
 * @tparam _data   - word data type
 *
 * @param  data    - data word
 */
template<typename _module, typename _data>
io::result rx(_data&& data)
{
  data = 0;

  for(uint_fast8_t n = 0; n < (sizeof(_data) * 8); n++) {
    bool b;
    if(auto r = detail::rx_bit<_module>(b); r != io::result::success) { return r; }
    data |= static_cast<std::remove_reference_t<_data>>(b) << n;
  }

  return io::result::success;
}

/**
 * @brief Transmit word to bus
 *
 * @tparam _module - 1-wire module struct
 * @tparam _data   - word data type
 *
 * @param  data    - data word
 */
template<typename _module, typename _data>
io::result tx(_data data)
{
  for(uint_fast8_t n = 0; n < (sizeof(_data) * 8); n++) {
    if(auto r = detail::tx_bit<_module>((data & 1) != 0); r != io::result::success) { return r; }
    data >>= 1;
  }

  return io::result::success;
}

/**
 * @brief Read data from bus
 *
 * @tparam _module - 1-wire module struct
 *
 * @param  data    - data buffer
 * @param  sz      - data size to read
 * @param  t       - timeout
 */
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

/**
 * @brief Write data to bus
 *
 * @tparam _module - 1-wire module struct
 *
 * @param  data    - data buffer
 * @param  sz      - data size to write
 * @param  t       - timeout
 */
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

/**
 * @brief Read ROM from device
 *
 * @tparam _module - 1-wire module struct
 *
 * @param  data    - data buffer
 * @param  sz      - data size to read
 * @param  t       - timeout
 */
template<typename _module>
io::result read_rom(uint8_t rom[8], const delay::expirable &t)
{
  constexpr uint8_t read_rom_cmd = 0x33;

  return (
    detail::presence<_module>() &&
    tx<_module>(read_rom_cmd) == io::result::success &&
    read<_module>(rom, 8, t) == io::result::success &&
    detail::check_rom(rom)
  )? io::result::success : io::result::error;
}

/**
 * @brief Search all ROM's on bus
 *
 * @tparam _module   - 1-wire module struct
 * @tparam _alarm    - if 'true' search devices in alarm state only, else all devices
 *
 * @param  rom_found - callback function (called on every device found)
 * @param  t         - timeout
 */
template<typename _module, bool _alarm, typename _rom_found>
io::result search(_rom_found&& rom_found, const delay::expirable &t)
{
  class rom_id
  {
  public:
    inline const auto &value() const { return bits_; }

    inline void set(uint_fast8_t n, bool val)
    {
      const uint_fast8_t idx = n / 8, shr = n % 8;
      bits_[idx] &= ~(1U << shr);
      bits_[idx] |= uint_fast8_t(val) << shr;
    }

    inline bool get(uint_fast8_t n) const
    {
      const uint_fast8_t idx = n / 8, shr = n % 8;
      return (bits_[idx] & (1U << shr)) != 0;
    }

    inline bool is_valid() const { return detail::check_rom(bits_); }
  private:
    uint8_t bits_[8];
  };

  constexpr uint8_t search_rom_cmd = _alarm? 0xEC : 0xF0;

  bool done_flag = false, rom_bit;
  uint_fast8_t last_discrepancy = 0;
  rom_id rom_id;

  while(!done_flag) {
    uint_fast8_t bit_index = 1, discrepancy_marker = 0;

    if(!detail::presence<_module>() || tx<_module>(search_rom_cmd) != io::result::success) {
      return io::result::error;
    }

    do {
      if(t.expired()) { return io::result::busy; }

      bool bit_a, bit_b;

      if(
        detail::rx_bit<_module>(bit_a) != io::result::success ||
        detail::rx_bit<_module>(bit_b) != io::result::success
      ) { return io::result::error; }

      if(bit_a == bit_b) {
        if(bit_a) { return io::result::error; }

        if(bit_index == last_discrepancy) {
          rom_bit = true;
        }
        else
        if(bit_index > last_discrepancy) {
          rom_bit = false;
        }
        else {
          rom_bit = rom_id.get(bit_index - 1);
        }

        if(!rom_bit) { discrepancy_marker = bit_index; }
      }
      else {
        rom_bit = bit_a;
      }

      rom_id.set(bit_index - 1, rom_bit);
      if(detail::tx_bit<_module>(rom_bit) != io::result::success) { return io::result::error; }
      ++bit_index;
    } while(bit_index <= 64);

    if(rom_id.is_valid()) {
      if(!(last_discrepancy = discrepancy_marker)) { done_flag = true; }
      rom_found(rom_id.value());
    }
    else {
      last_discrepancy = 0;
      done_flag = false;
    }
  }

  return io::result::success;
}

/**
 * @brief Select device with match ROM
 *
 * @tparam _module - 1-wire module struct
 *
 * @param  rom     - device ROM
 * @param  t       - timeout
 */
template<typename _module>
io::result select(const uint8_t rom[8], const delay::expirable &t)
{
  constexpr uint8_t match_rom_cmd = 0x55;
  return (
    detail::presence<_module>() &&
    tx<_module>(match_rom_cmd) == io::result::success &&
    write<_module>(rom, 8, t) == io::result::success
  )? io::result::success : io::result::error;
}

/**
 * @brief Select all devices
 *
 * @tparam _module - 1-wire module struct
 */
template<typename _module>
io::result select_all()
{
  constexpr uint8_t skip_rom_cmd = 0xCC;
  return (detail::presence<_module>() && tx<_module>(skip_rom_cmd) == io::result::success)?
          io::result::success : io::result::error;
}


/**
 * @brief Verifies device with match ROM is connected to the bus
 *
 * @tparam _module - 1-wire module struct
 *
 * @param  rom     - device ROM
 * @tparam _alarm  - if 'true' search devices in alarm state only, else all devices
 * @param  t       - timeout
 */
template<typename _module, bool _alarm = false>
io::result present(const uint8_t rom[8], const delay::expirable &t)
{
  constexpr uint8_t search_rom_cmd = _alarm? 0xEC : 0xF0;

  auto bit = [&rom](uint_fast8_t n)
  {
    const uint_fast8_t idx = n / 8, shr = n % 8;
    return (rom[idx] & (1U << shr)) != 0;
  };

  if(!detail::presence<_module>() || tx<_module>(search_rom_cmd) != io::result::success) {
    return io::result::error;
  }

  for(uint_fast8_t n = 0; n < 64; n++) {
    if(t.expired()) { return io::result::busy; }

    bool bit_a, bit_b;

    if(
      detail::rx_bit<_module>(bit_a) != io::result::success ||
      detail::rx_bit<_module>(bit_b) != io::result::success
    ) { return io::result::error; }

    if(bit_a == bit_b) {
      if(bit_a) { return io::result::error; }
      bit_a = bit(n);
    }
    else {
      if(bit_a != bit(n)) { return io::result::error; }
    }

    if(detail::tx_bit<_module>(bit_a) != io::result::success) { return io::result::error; }
  }

  return io::result::success;
}

} // namespace lmcu::soft::one_wire
