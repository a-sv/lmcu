#pragma once
#include <array>
#include <lmcu/lock>
#include <lmcu/gpio>
#include <lmcu/spi>
#include <lmcu/delay>

namespace lmcu::drivers::flash {

template<
  typename _spi,
  typename _nss_pin,
  typename _wp_pin   = lmcu::gpio::not_connected,
  typename _hold_pin = lmcu::gpio::not_connected
>
class N25Q00A
{
public:
  static constexpr uint32_t
    sector_size  = 64_Kbyte,
    sector_count = 2048,
    capacity     = sector_size * sector_count,
    page_size    = 4_Kbyte,
    page_count   = capacity / page_size,
    progbuf_size = 256
  ;

  enum class status : uint8_t
  {
    wip    = 1 << 0, // Write in progress

    wel    = 1 << 1, // Write enable latch

    bp_0   = 1 << 2, // Block protect bits
    bp_1   = 1 << 4,
    bp_3   = 1 << 6,

    bottom = 1 << 5, // Top / bottom protected memory area

    srwe   = 1 << 7  // Status register write enable / disable
  };

  N25Q00A()
  {
    wp_enable(true);
    hold_enable(false);
  }

  /**
   * @brief Enable / disable HOLD signal. Pauses any serial communications with the device without
   *        deselecting the device.
   *
   * @param en - if 'true' HOLD will be enabled, else disabled
  */
  static inline void hold_enable(bool en)
  {
    if constexpr(!_hold_pin::nc) { gpio::set<_hold_pin>(!en); }
  }

  /**
   * @brief Execute RESET sequence
  */
  io::result reset(const delay::expirable &t)
  {
    if(auto r = pe_wait(t); r != io::result::success) { return r; }

    {
      lmcu_scoped_lock();

      select();
      spi::tx<_spi>(cmd_reset_enable);
      deselect();

      select();
      spi::tx<_spi>(cmd_reset_memory);
      deselect();
    }

    return delay::us(31, t)? io::result::success : io::result::busy;
  }

  struct dev_id
  {
    uint8_t mid;      // Manufacturer ID
    uint8_t mem_type; // Memory Type
    uint8_t capacity; // Memory Capacity
    uint8_t uid[17];  // Unique ID
  };

  /**
   * @brief Read device ID
   *
   * @param id - device id read result
  */
  io::result read_id(dev_id &id, const delay::expirable &t)
  {
    if(auto r = pe_wait(t); r != io::result::success) { return r; }
    lmcu_scoped_lock();

    select();
    spi::tx<_spi>(cmd_read_id);
    spi::read<_spi>(&id, sizeof(dev_id));
    deselect();

    return io::result::success;
  }

  io::result read_status(status &s, const delay::expirable &t)
  {
    if(auto r = pe_wait(t); r != io::result::success) { s = status(0); return r; }
    lmcu_scoped_lock();

    select();
    spi::tx<_spi>(cmd_read_status);
    s = status( spi::rx<_spi>() );
    deselect();

    return io::result::success;
  }

  io::result read(uint32_t addr, void *data, uint32_t sz, const delay::expirable &t)
  {
    if(auto r = pe_wait(t); r != io::result::success) { return r; }
    lmcu_scoped_lock();

    const auto a_bytes = get_address_bytes(addr);

    select();

    if(!wren_ && addr <= 0xFFFFFF) {
      spi::tx<_spi>(cmd_read3);
      spi::write<_spi>(&a_bytes[1], 3);
    }
    else {
      spi::tx<_spi>(cmd_read4);
      spi::write<_spi>(&a_bytes[0], 4);
    }

    spi::read<_spi>(data, sz);

    deselect();

    return io::result::success;
  }

  io::result write_en(bool en, const delay::expirable &t)
  {
    if(auto r = pe_wait(t); r != io::result::success) { return r; }

    lmcu_scoped_lock();

    select();
    spi::tx<_spi>(cmd_write_enable);
    deselect();

    if(en) {
      select();
      spi::tx<_spi>(cmd_4byte_mode_on);
      deselect();

      select();
      spi::tx<_spi>(cmd_write_enable);
      deselect();
    }
    else {
      select();
      spi::tx<_spi>(cmd_4byte_mode_off);
      deselect();

      select();
      spi::tx<_spi>(cmd_write_disable);
      deselect();
    }

    wp_enable(!en);
    wren_ = en;

    return io::result::success;
  }

  io::result page_program(uint32_t addr, const void *data, uint32_t sz, const delay::expirable &t)
  {
    if(!wren_ || sz < 1 || sz > progbuf_size) { return io::result::error; }

    if(auto r = pe_wait(t); r != io::result::success) { return r; }
    busy_ = true;

    lmcu_scoped_lock();

    const auto a_bytes = get_address_bytes(addr);

    select();
    spi::tx<_spi>(cmd_page_program);
    spi::write<_spi>(&a_bytes[0], 4);
    spi::write<_spi>(data, sz);
    deselect();

    return io::result::success;
  }

  io::result page_erase(uint32_t pg_start, uint32_t pg_count, const delay::expirable &t)
  {
    const uint32_t pg_end = pg_start + pg_count;

    if(pg_end >= page_count) { return io::result::error; }

    if(auto r = pe_wait(t); r != io::result::success) { return r; }
    busy_ = true;

    for(; pg_start < pg_end; pg_start++) {
      const auto a_bytes = get_address_bytes(pg_start * page_size);

      lmcu_scoped_lock();

      select();
      spi::tx<_spi>(cmd_subsector_erase);
      spi::write<_spi>(&a_bytes[0], 4);
      deselect();
    }

    return io::result::success;
  }
private:
  static constexpr uint8_t
    cmd_reset_enable    = 0x66,
    cmd_reset_memory    = 0x99,
    cmd_read_id         = 0x9E,
    cmd_read3           = 0x03, // 3-byte read
    cmd_read4           = 0x13, // 4-byte read
    cmd_write_enable    = 0x06,
    cmd_write_disable   = 0x04,
    cmd_read_status     = 0x05,
    cmd_page_program    = 0x02,
    cmd_read_flags      = 0x70,
    cmd_clear_flags     = 0x50,
    cmd_pe_resume       = 0x7A,
    cmd_pe_suspend      = 0x75,
    cmd_4byte_mode_on   = 0xB7,
    cmd_4byte_mode_off  = 0xE9,
    cmd_subsector_erase = 0x20
  ;

  enum class flags : uint8_t
  {
    addressing    = 1 << 0, // 3-byte or 4-byte address mode selected
    protection    = 1 << 1, // Attempt Erase or Program protected sector
    program_susp  = 1 << 2, // Program operation suspend
    vpp           = 1 << 3, // Invalid voltage on Vpp
    program       = 1 << 4, // Program operation failed
    erase         = 1 << 5, // Erase operation failed
    erase_susp    = 1 << 6, // Erase operation suspend
    pe_controller = 1 << 7  // Program or Erase in progress
  };

  bool busy_ = true;
  bool wren_ = false;

  static inline bool pe_busy()
  {
    return (uint8_t(read_flags()) & uint8_t(flags::pe_controller)) == 0;
  }

  /**
   * @brief Wait for PROGRAM or ERASE operation finish
   *
   * @param t - timeout
   * @return 'busy' - if timeout expired, else 'success'
  */
  inline io::result pe_wait(const delay::expirable &t)
  {
    if(!busy_) { return io::result::success; }

    do {
      if(t.expired()) { return io::result::busy; }
    }
    while(pe_busy());

    busy_ = false;

    return io::result::success;
  }

  /**
   * @brief Set CS signal to low level
  */
  static inline void select() { gpio::set<false, _nss_pin>(); }

  /**
   * @brief Set CS signal to high level
  */
  static inline void deselect() { gpio::set<true, _nss_pin>(); delay::ns(50); }

  /**
   * @brief Hardware write protect enable / disable
   *
   * @param en - if 'true' write protection will be enabled, else disabled
  */
  static inline void wp_enable(bool en)
  {
    if constexpr(!_wp_pin::nc) { gpio::set<_wp_pin>(!en); }
  }

  static inline auto get_address_bytes(uint32_t addr)
  {
    const union {
      uint32_t addr;
      std::array<uint8_t, 4> bytes;
    } a = { __builtin_bswap32(addr) };

    return a.bytes;
  }

  static inline flags read_flags()
  {
    select();
    lmcu_defer([] { deselect(); });

    spi::tx<_spi>(cmd_read_flags);
    return flags( spi::rx<_spi>() );
  }
};

} // namespace lmcu::drivers::flash
