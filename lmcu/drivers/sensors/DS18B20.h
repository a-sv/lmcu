#pragma once
#include <lmcu/drivers/soft/one_wire>

// ------------------------------------------------------------------------------------------------
namespace lmcu::drv::sensors::temp::DS18B20 {
// ------------------------------------------------------------------------------------------------

enum class resolution
{
  _9bit,
  _10bit,
  _11bit,
  _12bit
};

template <typename _1wire_cfg, bool _use_id = false>
class device
{
  static constexpr uint8_t
  cmd_read_scratchpad  = 0xBE,
  cmd_write_scratchpad = 0x4E,
  cmd_conv_t           = 0x44
  ;
public:
  static constexpr auto dev_class = lmcu::dev_class::temp_sensor;

  using bus_config = _1wire_cfg;

  void set_id(const uint8_t id[8])
  {
    static_assert(_use_id, "use id must be enabled!");
    if constexpr(_use_id) { memcpy(st_.id, id, sizeof(st_.id)); }
  }

  io::result start_conversion(const delay::expirable &t)
  {
    using namespace drv::soft;

    scratchpad sp;
    if(auto r = read_scratchpad(sp, t); r != io::result::success) { return r; }

    if(!scratchpad_cmp(sp)) {
      if(auto r = write_scratchpad(t); r != io::result::success) { return r; }
    }

    if(auto r = select<!_use_id>(t); r != io::result::success) { return r; }
    if(auto r = one_wire::tx<_1wire_cfg>(cmd_conv_t, t); r != io::result::success) { return r; }


    delay::dwt::timer &tim = st_.t;

    switch(get_resolution())
    {
    case resolution::_9bit:  tim.start<delay::units::ms>(94);  break;
    case resolution::_10bit: tim.start<delay::units::ms>(188); break;
    case resolution::_11bit: tim.start<delay::units::ms>(375); break;
    case resolution::_12bit: tim.start<delay::units::ms>(750); break;
    }

    return io::result::success;
  }

  io::result read_temp(int32_t &temp, const delay::expirable &t)
  {
    if(!st_.t.expired()) { return io::result::again; }

    scratchpad sp;
    if(auto r = read_scratchpad(sp, t); r != io::result::success) { return r; }

    if(!scratchpad_cmp(sp)) { return io::result::error; }

    if((sp.temp & 0xF800) != 0) {
      sp.temp = ~sp.temp + 1;
    }

    temp  = (sp.temp >> 4) & 0x7F;
    temp *= 10000;
    temp += (sp.temp & 0xF) * 625;

    return io::result::success;
  }

  inline void set_resolution(resolution val) { st_.cfg = (st_.cfg & 0x60) | (uint8_t(val) << 5); }

  inline resolution get_resolution() { return resolution((st_.cfg >> 5) & 2); }

  io::result read_config(const delay::expirable &t)
  {
    scratchpad sp;
    if(auto r = read_scratchpad(sp, t); r != io::result::success) { return r; }

    st_.th  = sp.th;
    st_.tl  = sp.tl;
    st_.cfg = sp.cfg;

    return io::result::success;
  }
private:
  struct scratchpad
  {
    uint16_t temp;
    uint8_t th, tl;
    uint8_t cfg;
    uint8_t reserved[3];
    uint8_t crc;
  } __attribute__((packed));

  struct state
  {
    delay::dwt::timer t;
    uint8_t th, tl;
    uint8_t cfg = 0x7F; // R0 = 1, R1 = 1
  };

  struct state_with_id : state
  {
    uint8_t id[8];
  };

  using state_t = std::conditional_t<_use_id, state_with_id, state>;

  state_t st_;

  template<bool _all>
  io::result select(const delay::expirable &t)
  {
    using namespace drv::soft;

    if constexpr(_all) {
      return one_wire::select_all<_1wire_cfg>(t);
    }
    else {
      return one_wire::select<_1wire_cfg>(st_.id, t);
    }
  }

  io::result read_scratchpad(scratchpad &sp, const delay::expirable &t)
  {
    using namespace drv::soft;

    if(auto r = select<!_use_id>(t); r != io::result::success) {
      return r;
    }
    if(auto r = one_wire::tx<_1wire_cfg>(cmd_read_scratchpad, t); r != io::result::success) {
      return r;
    }
    if(auto r = one_wire::read<_1wire_cfg>(&sp, sizeof(sp), t); r != io::result::success) {
      return r;
    }

    hash::dallas::crc8 crc;
    crc.update(&sp, sizeof(sp) - 1);
    if(sp.crc != crc.digest()) { return io::result::error; }

    return io::result::success;
  }

  io::result write_scratchpad(const delay::expirable &t)
  {
    using namespace drv::soft;

    if(auto r = select<!_use_id>(t); r != io::result::success) {
      return r;
    }
    if(auto r = one_wire::tx<_1wire_cfg>(cmd_write_scratchpad, t); r != io::result::success) {
      return r;
    }

    const uint8_t sp[] = {st_.th, st_.tl, st_.cfg};

    if(auto r = one_wire::write<_1wire_cfg>(sp, sizeof(sp), t); r != io::result::success) {
      return r;
    }

    return io::result::success;
  }

  inline bool scratchpad_cmp(const scratchpad &sp)
  {
    return sp.th == st_.th && sp.tl == st_.tl && sp.cfg == st_.cfg;
  }
};

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::drv::sensors::temp::DS18B20
// ------------------------------------------------------------------------------------------------
