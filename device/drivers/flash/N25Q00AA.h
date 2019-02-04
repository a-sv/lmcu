#pragma once
#include <array>
#include <lmcu/lock>
#include <lmcu/gpio>
#include <lmcu/spi>
#include <lmcu/delay>
#include "flash.h"

namespace lmcu::drivers::flash {

template<
  typename _spi,
  typename _nss,
  typename _wp   = gpio::not_connected,
  typename _hold = gpio::not_connected
>
class N25Q00A
{
  static_assert(_spi::module_type == module_type::spi, "_spi must have type 'spi'");
  static_assert(_nss::module_type == module_type::gpio_pin, "_nss must have type 'gpio_pin'");
  static_assert(_wp::module_type == module_type::gpio_pin, "_wp must have type 'gpio_pin'");
  static_assert(_hold::module_type == module_type::gpio_pin, "_hold must have type 'gpio_pin'");
public:
  static constexpr auto
    type = flash::type::nor
  ;

  static constexpr uint32_t
    subsector_size  = 4_Kbyte,
    sector_size     = 64_Kbyte,
    die_size        = 32_Mbyte,
    subsector_count = 32768,
    sector_count    = 2048,
    die_count       = 4,
    capacity        = subsector_size * subsector_count,
    page_size       = subsector_size,
    page_count      = subsector_count
  ;

  enum class status : uint32_t
  {
    lmcu_flags_object,

    wip    = 1 << 0, // write in progress
    wel    = 1 << 1, // write enable latch
    bp_0   = 1 << 2, //
    bp_1   = 1 << 4, // block protect bits
    bp_3   = 1 << 6, //
    bottom = 1 << 5, // top / bottom protected memory area
    srwe   = 1 << 7  // status register write enable / disable
  };

  struct dev_id
  {
    uint8_t mid;      // Manufacturer ID
    uint8_t mem_type; // Memory Type
    uint8_t capacity; // Memory Capacity
    uint8_t uid[17];  // Unique ID
  };

  enum class page_type
  {
    subsector, //  4 Kbyte
    sector,    // 64 Kbyte
    die        // 32 Mbyte
  };

  N25Q00A()
  {
    wp_enable(true);
    hold_enable(false);
  }

  N25Q00A(const N25Q00A&) = delete;
  N25Q00A &operator =(const N25Q00A&) = delete;

  /**
   * @brief Enable / disable HOLD signal. Pauses any serial communications with the device without
   *        deselecting the device.
   *
   * @param en - if 'true' HOLD will be enabled, else disabled
  */
  static inline void hold_enable(bool en)
  {
    if constexpr(!_hold::nc) { gpio::set<_hold>(!en); }
  }

  /**
   * @brief Execute RESET sequence
  */
  io::result reset(const delay::expirable &t)
  {
    if(auto r = sync(t); r != io::result::success) { return r; }

    {
      lmcu_disable_irq();

      select();
      spi::tx<_spi>(cmd_reset_enable);
      deselect();

      select();
      spi::tx<_spi>(cmd_reset_memory);
      deselect();
    }

    return delay::us(31, t)? io::result::success : io::result::busy;
  }

  /**
   * @brief Read device ID
   *
   * @param id - device id read result
  */
  io::result read_id(dev_id &id, const delay::expirable &t)
  {
    if(op_ == op::init) {
      if(auto r = sync(t); r != io::result::success) { return r; }
    }

    if(auto r = suspend<true>(t); r != io::result::success) { return r; }

    lmcu_disable_irq();

    select();
    spi::tx<_spi>(cmd_read_id);
    spi::read<_spi>(&id, sizeof(dev_id));
    deselect();

    return suspend<false>(t);
  }

  /**
   * @brief Read flash status register
   *
   * @param s - status flags
   * @param t - timeout
  */
  io::result read_status(status &s, const delay::expirable&)
  {
    lmcu_disable_irq();

    select();
    spi::tx<_spi>(cmd_read_status);
    s = flags::from_value<status>( spi::rx<_spi>() );
    deselect();

    return io::result::success;
  }

  /**
   * @brief Read data from flash
   *
   * @param addr - absolute offset from begining
   * @param data - buffer for data
   * @param sz   - size to be read
   * @param t    - timeout
  */
  io::result read(uint32_t addr, void *data, uint32_t sz, const delay::expirable &t)
  {
    if(op_ == op::init) {
      if(auto r = sync(t); r != io::result::success) { return r; }
    }

    if(auto r = suspend<true>(t); r != io::result::success) { return r; }

    auto do_read = [this, &t](uint32_t addr, uint8_t *data, uint32_t sz)
    {
      if(t.expired()) { return io::result::busy; }

      lmcu_disable_irq();

      const auto a_bytes = get_address_bytes(addr);

      select();

      if(!ex_addr_ && addr <= 0xFFFFFF) {
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
    };

    auto p = static_cast<uint8_t*>(data);

    const uint32_t n = std::min<uint32_t>(sz, die_size - (addr % die_size));
    if(n > 0) {
      if(auto res = do_read(addr, p, n); res != io::result::success) { return res; }

      addr += n;
      p    += n;
      sz   -= n;
    }

    while(sz > 0) {
      const uint32_t n = std::min<uint32_t>(sz, die_size);

      if(auto res = do_read(addr, p, n); res != io::result::success) { return res; }

      addr += n;
      p    += n;
      sz   -= n;
    }

    if(auto r = suspend<false>(t); r != io::result::success) { return r; }

    return io::result::success;
  }

  /**
   * @brief Write data to flash
   *
   * @param addr - absolute offset from begining
   * @param data - data to be writed
   * @param sz   - data size
   * @param t    - timeout
  */
  io::result write(uint32_t addr, const void *data, uint32_t sz, const delay::expirable &t)
  {
    auto do_write = [this, &t](uint32_t addr, const uint8_t *data, uint32_t sz)
    {
      if(auto res = sync(t); res != io::result::success) { return res; }
      if(auto res = exaddr_enable(t); res != io::result::success) { return res; }

      op_ = op::program;

      const auto a_bytes = get_address_bytes(addr);

      lmcu_disable_irq();

      wp_enable(false);

      select();
      spi::tx<_spi>(cmd_write_enable);
      deselect();

      select();
      spi::tx<_spi>(cmd_page_program);
      spi::write<_spi>(&a_bytes[0], 4);
      spi::write<_spi>(data, sz);
      deselect();

      wp_enable(true);

      return io::result::success;
    };

    auto p = static_cast<const uint8_t*>(data);

    const uint32_t n = std::min<uint32_t>(sz, 256 - (addr % 256));
    if(n > 0) {
      if(auto res = do_write(addr, p, n); res != io::result::success) { return res; }

      addr += n;
      p    += n;
      sz   -= n;
    }

    while(sz > 0) {
      const uint32_t n = std::min<uint32_t>(sz, 256);

      if(auto res = do_write(addr, p, n); res != io::result::success) { return res; }

      addr += n;
      p    += n;
      sz   -= n;
    }

    return io::result::success;
  }

  /**
   * @brief Erase pages sequence
   *
   * @tparam _page_type - selects flash sector type
   * @param  start      - start page index
   * @param  count      - count of pages to be erased
   * @param  t          - timeout
  */
  template<page_type _page_type = page_type::subsector>
  io::result page_erase(uint32_t start, uint32_t count, const delay::expirable &t)
  {
    constexpr uint32_t pg_size = []
    {
      if constexpr(_page_type == page_type::subsector) { return subsector_size; }
      if constexpr(_page_type == page_type::sector) { return sector_size; }
      return die_size;
    }();

    constexpr uint32_t pg_count = []
    {
      if constexpr(_page_type == page_type::subsector) { return subsector_count; }
      if constexpr(_page_type == page_type::sector) { return sector_count; }
      return die_count;
    }();

    const uint32_t end = start + count;
    if(end >= pg_count) { return io::result::error; }

    if(auto res = sync(t); res != io::result::success) { return res; }
    if(auto res = exaddr_enable(t); res != io::result::success) { return res; }

    for(; start < end; start++) {
      const auto a_bytes = get_address_bytes(start * pg_size);

      op_ = op::erase;

      {
        lmcu_disable_irq();

        wp_enable(false);

        select();
        spi::tx<_spi>(cmd_write_enable);
        deselect();

        select();
        if constexpr(_page_type == page_type::subsector) {
          spi::tx<_spi>(cmd_subsector_erase);
        }
        else
        if constexpr(_page_type == page_type::sector) {
          spi::tx<_spi>(cmd_sector_erase);
        }
        else {
          spi::tx<_spi>(cmd_die_erase);
        }
        spi::write<_spi>(&a_bytes[0], 4);
        deselect();

        wp_enable(true);
      }

      if(auto r = sync(t); r != io::result::success) { return r; }
    }

    return io::result::success;
  }

  /**
   * @brief Erase whole flash memory
   *
   * @param t - timeout
   */
  io::result mass_erase(const delay::expirable &t)
  {
    return page_erase<page_type::die>(0, die_count, t);
  }

  /**
   * @brief Wait for PROGRAM or ERASE operation finish
   *
   * @param t - timeout
   * @return 'busy' - if timeout expired, else 'success'
  */
  inline io::result sync(const delay::expirable &t)
  {
    if(op_ == op::idle) { return io::result::success; }

    do {
      if(t.expired()) { return io::result::busy; }
    }
    while(flags::none(read_flags(), state_flags::pe_controller));

    op_ = op::idle;

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
    cmd_read_status     = 0x05,
    cmd_page_program    = 0x02,
    cmd_read_flags      = 0x70,
    cmd_pe_resume       = 0x7A,
    cmd_pe_suspend      = 0x75,
    cmd_4byte_mode_on   = 0xB7,
    cmd_subsector_erase = 0x20,
    cmd_sector_erase    = 0xD8,
    cmd_die_erase       = 0xC4
  ;

  enum class state_flags : uint8_t
  {
    lmcu_flags_object,

    addressing    = 1 << 0, // 3-byte or 4-byte address mode selected
    protection    = 1 << 1, // Attempt Erase or Program protected sector
    program_susp  = 1 << 2, // Program operation suspend
    vpp           = 1 << 3, // Invalid voltage on Vpp
    program       = 1 << 4, // Program operation failed
    erase         = 1 << 5, // Erase operation failed
    erase_susp    = 1 << 6, // Erase operation suspend
    pe_controller = 1 << 7  // Program or Erase in progress
  };

  enum class op : uint32_t { init, idle, program, erase };

  op op_        = op::init;
  bool ex_addr_ = false;

  /**
   * @brief Set CS signal to low level
  */
  static inline void select() { gpio::set<false, _nss>(); }

  /**
   * @brief Set CS signal to high level
  */
  static inline void deselect() { gpio::set<true, _nss>(); delay::ns(50); }

  /**
   * @brief Hardware write protect enable / disable
   *
   * @param en - if 'true' write protection will be enabled, else disabled
  */
  static inline void wp_enable(bool en)
  {
    if constexpr(!_wp::nc) { gpio::set<_wp>(!en); }
  }

  /**
   * @brief Enable 4-byte extended address
  */
  io::result exaddr_enable(const delay::expirable &t)
  {
    if(ex_addr_) { return io::result::success; }

    lmcu_disable_irq();

    while(true) {
      if(t.expired()) { return io::result::busy; }
      if(flags::all(read_flags(), state_flags::addressing)) { break; }

      select();
      spi::tx<_spi>(cmd_write_enable);
      deselect();

      select();
      spi::tx<_spi>(cmd_4byte_mode_on);
      deselect();
    }

    ex_addr_ = true;

    return io::result::success;
  }

  /**
   * @brief Convert address to flash format
   *
   * @param addr - address
   * @return 4 address bytes
  */
  static inline auto get_address_bytes(uint32_t addr)
  {
    const union {
      uint32_t addr;
      std::array<uint8_t, 4> bytes;
    } a = { __builtin_bswap32(addr) };

    return a.bytes;
  }

  /**
   * @brief Read status flags
  */
  static inline auto read_flags()
  {
    select();
    lmcu_defer([] { deselect(); });

    spi::tx<_spi>(cmd_read_flags);
    return flags::from_value<state_flags>( spi::rx<_spi>() );
  }

  /**
   * @brief Suspend or resume PROGRAM / ERASE operations when they in progress
   *
   * @tparam _suspend - if 'true' perform SUSPEND operation, else RESUME
   * @param  t        - timeout
  */
  template<bool _suspend>
  io::result suspend(const delay::expirable &t)
  {
    if(op_ == op::idle || op_ == op::init) { return io::result::success; }

    state_flags f;

    if(op_ == op::program) {
      f = state_flags::program_susp;
    }
    else
    if(op_ == op::erase) {
      f = state_flags::erase_susp;
    }
    else {
      return io::result::error;
    }

    do {
      if(t.expired()) { return io::result::busy; }

      lmcu_disable_irq();

      const auto status = read_flags();

      if constexpr(_suspend) {
        if(flags::all(status, state_flags::pe_controller)) {
          op_ = op::idle; return io::result::success;
        }
      }

      if(flags::check<_suspend>(status, f)) { break; }

      select();
      if constexpr(_suspend) {
        spi::tx<_spi>(cmd_pe_suspend);
      }
      else {
        spi::tx<_spi>(cmd_pe_resume);
      }
      deselect();
    }
    while(true);

    if constexpr(_suspend) { return sync(t); }

    return io::result::success;
  }
};

} // namespace lmcu::drivers::flash
