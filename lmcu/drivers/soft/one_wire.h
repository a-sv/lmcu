#pragma once
#include <lmcu/gpio>
#include <lmcu/delay>
#include <lmcu/hash>

// ------------------------------------------------------------------------------------------------
namespace lmcu::drv::soft::one_wire {
// ------------------------------------------------------------------------------------------------

enum class time_slot { defval = 60 };

enum class reset_time { defval = 480 };

enum class smpr_time { defval = 15 };

enum class min_low_time { defval = 1 };

enum class rec_time { defval = 1 };

template<typename _dq_pin, auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::one_wire;

  static constexpr auto time_slot = option::get_u<one_wire::time_slot, _args...>(
                                      one_wire::time_slot::defval);

  static constexpr auto reset_time = option::get_u<one_wire::reset_time, _args...>(
                                      one_wire::reset_time::defval);

  static constexpr auto smpr_time = option::get_u<one_wire::smpr_time, _args...>(
                                      one_wire::smpr_time::defval);

  static constexpr auto min_low_time = option::get_u<one_wire::min_low_time, _args...>(
                                         one_wire::min_low_time::defval);

  static constexpr auto rec_time = option::get_u<one_wire::rec_time, _args...>(
                                     one_wire::rec_time::defval);

  using dq_tx_pin = typename gpio::pin<option::null, _dq_pin::port, gpio::pin_n(_dq_pin::n),
                                       gpio::mode::output_open_drain>;

  using dq_rx_pin = typename gpio::pin<option::null, _dq_pin::port, gpio::pin_n(_dq_pin::n),
                                       gpio::mode::input>;

  static_assert(option::check<
    std::tuple<
      one_wire::time_slot,
      one_wire::reset_time,
      one_wire::smpr_time,
      one_wire::min_low_time,
      one_wire::rec_time
    >,
    _args...
  >());
};

// ------------------------------------------------------------------------------------------------
namespace detail {
// ------------------------------------------------------------------------------------------------

template<typename _cfg>
static io::result rx_bit(bool &b)
{
  delay::dwt::timer t;

  using dq_tx_pin = typename _cfg::dq_tx_pin;
  using dq_rx_pin = typename _cfg::dq_rx_pin;

  gpio::configure<dq_tx_pin>();

  gpio::set<dq_tx_pin>(false);
  delay::us(_cfg::min_low_time);

  gpio::configure<dq_rx_pin>();
  delay::us(_cfg::smpr_time - _cfg::min_low_time - 1);

  b = gpio::read<dq_rx_pin>();

  delay::us(_cfg::time_slot - _cfg::smpr_time);

  t.start<delay::units::us>(_cfg::rec_time);
  while(!gpio::read<dq_rx_pin>()) {
    if(t.expired()) { return io::result::error; }
  }
  t.wait();

  return io::result::success;
}

template<typename _cfg>
static io::result tx_bit(bool b)
{
  using dq_tx_pin = typename _cfg::dq_tx_pin;
  using dq_rx_pin = typename _cfg::dq_rx_pin;

  delay::dwt::timer t;

  gpio::configure<dq_tx_pin>();
  gpio::set<dq_tx_pin>(false);

  if(b) {
    delay::us(_cfg::min_low_time);
    gpio::configure<dq_rx_pin>();

    t.start<delay::units::us>(_cfg::time_slot - _cfg::min_low_time);
    while(!gpio::read<dq_rx_pin>()) {
      if(t.expired()) { return io::result::error; }
    }
    t.wait();
  }
  else {
    delay::us(_cfg::time_slot);
    gpio::configure<dq_rx_pin>();
  }

  t.start<delay::units::us>(_cfg::rec_time);
  while(!gpio::read<dq_rx_pin>()) {
    if(t.expired()) { return io::result::error; }
  }
  t.wait();

  return io::result::success;
}

template<typename _cfg>
bool presence()
{
  using dq_tx_pin = typename _cfg::dq_tx_pin;
  using dq_rx_pin = typename _cfg::dq_rx_pin;

  gpio::configure<dq_tx_pin>();

  gpio::set<dq_tx_pin>(false);
  delay::us(_cfg::reset_time);

  gpio::configure<dq_rx_pin>();

  delay::dwt::timer t;
  t.start<delay::units::us>(_cfg::reset_time);

  // wait for line set to high
  while(!gpio::read<dq_rx_pin>() && !t.expired())
    ;

  if(t.expired()) {
    // short circuit DQ to GND
    return false;
  }

  // wait for presence pulse start
  while(gpio::read<dq_rx_pin>() && !t.expired())
    ;

  if(t.expired()) {
    // presence pulse start not detected
    return false;
  }

  // wait for presence pulse end
  while(!gpio::read<dq_rx_pin>() && !t.expired())
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
  hash::dallas::crc8 crc;
  crc.update(rom, 7);
  return rom[7] == crc.digest();
}

// ------------------------------------------------------------------------------------------------
} // namespace detail
// ------------------------------------------------------------------------------------------------

/**
 * @brief Receive word from bus
 *
 * @tparam _cfg  - 1-wire config
 * @tparam _data - word data type
 *
 * @param  data  - data word
 * @param  t     - timeout
 */
template<typename _cfg, typename _data>
io::result rx(_data&& data, const delay::expirable &t)
{
  data = 0;

  for(uint_fast8_t n = 0; n < (sizeof(_data) * 8); n++) {
    if(t.expired()) { return io::result::busy; }
    bool b;
    if(auto r = detail::rx_bit<_cfg>(b); r != io::result::success) { return r; }
    data |= static_cast<std::remove_reference_t<_data>>(b) << n;
  }

  return io::result::success;
}

/**
 * @brief Transmit word to bus
 *
 * @tparam _cfg  - 1-wire config
 * @tparam _data - word data type
 *
 * @param  data  - data word
 * @param  t     - timeout
 */
template<typename _cfg, typename _data>
io::result tx(_data data, const delay::expirable &t)
{
  for(uint_fast8_t n = 0; n < (sizeof(_data) * 8); n++) {
    if(t.expired()) { return io::result::busy; }
    if(auto r = detail::tx_bit<_cfg>((data & 1) != 0); r != io::result::success) { return r; }
    data >>= 1;
  }

  return io::result::success;
}

/**
 * @brief Read data from bus
 *
 * @tparam _cfg - 1-wire config
 *
 * @param  data - data buffer
 * @param  sz   - data size to read
 * @param  t    - timeout
 */
template<typename _cfg>
io::result read(void *data, uint32_t sz, const delay::expirable &t)
{
  auto p = static_cast<uint8_t*>(data), end = p + sz;

  for(; p < end; ++p) {
    if(auto r = rx<_cfg>(*p, t); r != io::result::success) { return r; }
  }

  return io::result::success;
}

/**
 * @brief Write data to bus
 *
 * @tparam _cfg - 1-wire config
 *
 * @param  data - data buffer
 * @param  sz   - data size to write
 * @param  t    - timeout
 */
template<typename _cfg>
io::result write(const void *data, uint32_t sz, const delay::expirable &t)
{
  auto p = static_cast<const uint8_t*>(data), end = p + sz;

  for(; p < end; ++p) {
    if(auto r = tx<_cfg>(*p, t); r != io::result::success) { return r; }
  }

  return io::result::success;
}

/**
 * @brief Read ROM from device
 *
 * @tparam _cfg - 1-wire config
 *
 * @param  data - data buffer
 * @param  sz   - data size to read
 * @param  t    - timeout
 */
template<typename _cfg>
io::result read_rom(uint8_t rom[8], const delay::expirable &t)
{
  constexpr uint8_t read_rom_cmd = 0x33;

  if(!detail::presence<_cfg>()) { return io::result::error; }
  if(auto r = tx<_cfg>(read_rom_cmd, t); r != io::result::success) { return r; }
  if(auto r = read<_cfg>(rom, 8, t); r != io::result::success) { return r; }

  return detail::check_rom(rom)? io::result::success : io::result::error;
}

/**
 * @brief Search all ROM's on bus
 *
 * @tparam _cfg      - 1-wire config
 * @tparam _alarm    - if 'true' search devices in alarm state only, else all devices
 *
 * @param  rom_found - callback function (called on every device found)
 * @param  t         - timeout
 */
template<typename _cfg, bool _alarm, typename _rom_found>
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

    if(!detail::presence<_cfg>()) { return io::result::error; }
    if(auto r = tx<_cfg>(search_rom_cmd, t); r != io::result::success) { return r; }

    do {
      if(t.expired()) { return io::result::busy; }

      bool bit_a, bit_b;

      if(
        detail::rx_bit<_cfg>(bit_a) != io::result::success ||
        detail::rx_bit<_cfg>(bit_b) != io::result::success
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
      if(detail::tx_bit<_cfg>(rom_bit) != io::result::success) { return io::result::error; }
    } while(++bit_index <= 64);

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
 * @tparam _cfg - 1-wire config
 *
 * @param  rom  - device ROM
 * @param  t    - timeout
 */
template<typename _cfg>
io::result select(const uint8_t rom[8], const delay::expirable &t)
{
  constexpr uint8_t match_rom_cmd = 0x55;

  if(!detail::presence<_cfg>()) { return io::result::error; }
  if(auto r = tx<_cfg>(match_rom_cmd, t); r != io::result::success) { return r; }
  if(auto r = write<_cfg>(rom, 8, t); r != io::result::success) { return r; }

  return io::result::success;
}

/**
 * @brief Select all devices
 *
 * @tparam _cfg - 1-wire config
 * @param  t    - timeout
 */
template<typename _cfg>
io::result select_all(const delay::expirable &t)
{
  constexpr uint8_t skip_rom_cmd = 0xCC;

  if(!detail::presence<_cfg>()) { return io::result::error; }
  if(auto r = tx<_cfg>(skip_rom_cmd, t); r != io::result::success) { return r; }

  return io::result::success;
}

/**
 * @brief Verifies device with match ROM is connected to the bus
 *
 * @tparam _cfg   - 1-wire config
 *
 * @param  rom    - device ROM
 * @tparam _alarm - if 'true' search devices in alarm state only, else all devices
 * @param  t      - timeout
 */
template<typename _cfg, bool _alarm = false>
io::result present(const uint8_t rom[8], const delay::expirable &t)
{
  constexpr uint8_t search_rom_cmd = _alarm? 0xEC : 0xF0;

  auto bit = [&rom](uint_fast8_t n)
  {
    const uint_fast8_t idx = n / 8, shr = n % 8;
    return (rom[idx] & (1U << shr)) != 0;
  };

  if(!detail::presence<_cfg>()) { return io::result::error; }
  if(auto r = tx<_cfg>(search_rom_cmd, t); r != io::result::success) { return r; }

  for(uint_fast8_t n = 0; n < 64; n++) {
    if(t.expired()) { return io::result::busy; }

    bool bit_a, bit_b;

    if(
      detail::rx_bit<_cfg>(bit_a) != io::result::success ||
      detail::rx_bit<_cfg>(bit_b) != io::result::success
    ) { return io::result::error; }

    if(bit_a == bit_b) {
      if(bit_a) { return io::result::error; }
      bit_a = bit(n);
    }
    else {
      if(bit_a != bit(n)) { return io::result::error; }
    }

    if(detail::tx_bit<_cfg>(bit_a) != io::result::success) { return io::result::error; }
  }

  return io::result::success;
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::drv::soft::one_wire
// ------------------------------------------------------------------------------------------------
