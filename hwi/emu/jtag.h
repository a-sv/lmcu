#pragma once
#include <lmcu/delay>
#include <lmcu/gpio>

namespace lmcu::soft
{

template<typename _tdi, typename _tdo, typename _tms, typename _tck>
class jtag
{
public:
  enum class state
  {
    unknown,
    test_logic_reset,
    run_test_idle,
    select_dr_scan,
    capture_dr,
    shift_dr,
    exit1_dr,
    pause_dr,
    exit2_dr,
    update_dr,
    select_ir_scan,
    capture_ir,
    shift_ir,
    exit1_ir,
    pause_ir,
    exit2_ir,
    update_ir
  };

  state get_state() const { return state_; }

  /**
   * @brief Reset TAP controller
  */
  void reset()
  {
    if(state_ == state::unknown) {
      gpio::set<true, _tms>();
      for(uint32_t n = 0; n < 5; n++) { clock(); }
      gpio::set<false, _tms>();
      state_ = state::test_logic_reset;
    }
    else {
      set_state(state::test_logic_reset);
    }
    delay::us<1500>();
  }

  /**
   * @brief Set TAP controller state
   *
   * @param target - target TAP controller state
   * @return       - true if 1 on tdo signal, else false
  */
  bool set_state(state target)
  {
    if(target == state::unknown) { return false; }

    bool tdo_value = false;

    while(state_ != target) {
      switch(state_) {
      case state::test_logic_reset: {
        if(target != state::test_logic_reset) {
          gpio::set<false, _tms>();
          tdo_value = clock();
          state_ = state::run_test_idle;
        }
      } break;

      case state::run_test_idle: {
        if(target != state::run_test_idle) {
          gpio::set<true, _tms>();
          tdo_value = clock();
          state_ = state::select_dr_scan;
        }
      } break;

      case state::select_dr_scan: {
        if(target > state::select_dr_scan && target < state::select_ir_scan) {
          gpio::set<false, _tms>();
          state_ = state::capture_dr;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::select_ir_scan;
        }
        tdo_value = clock();
      } break;

      case state::capture_dr: {
        if(target == state::shift_dr) {
          gpio::set<false, _tms>();
          state_ = state::shift_dr;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::exit1_dr;
        }
        tdo_value = clock();
      } break;

      case state::shift_dr: {
        if(target != state::shift_dr) {
          gpio::set<true, _tms>();
          tdo_value = clock();
          state_ = state::exit1_dr;
        }
      } break;

      case state::exit1_dr: {
        if(target == state::pause_dr || target == state::exit2_dr || target == state::shift_dr) {
          gpio::set<false, _tms>();
          state_ = state::pause_dr;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::update_dr;
        }
        tdo_value = clock();
      } break;

      case state::pause_dr: {
        if(target != state::pause_dr) {
          gpio::set<true, _tms>();
          tdo_value = clock();
          state_ = state::exit2_dr;
        }
      } break;

      case state::exit2_dr: {
        if(target >= state::shift_dr && target < state::exit2_dr) {
          gpio::set<false, _tms>();
          state_ = state::shift_dr;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::update_dr;
        }
        tdo_value = clock();
      } break;

      case state::select_ir_scan: {
        if(target < state::select_ir_scan) {
          gpio::set<true, _tms>();
          state_ = state::test_logic_reset;
        }
        else {
          gpio::set<false, _tms>();
          state_ = state::capture_ir;
        }
        tdo_value = clock();
      } break;

      case state::capture_ir: {
        if(target == state::shift_ir) {
          gpio::set<false, _tms>();
          state_ = state::shift_ir;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::exit1_ir;
        }
        tdo_value = clock();
      } break;

      case state::shift_ir: {
        if(target != state::shift_ir) {
          gpio::set<true, _tms>();
          tdo_value = clock();
          state_ = state::exit1_ir;
        }
      } break;

      case state::exit1_ir: {
        if(target == state::pause_ir || target == state::exit2_ir || target == state::shift_ir) {
          gpio::set<false, _tms>();
          state_ = state::pause_ir;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::update_ir;
        }
        tdo_value = clock();
      } break;

      case state::pause_ir: {
        if(target != state::pause_ir) {
          gpio::set<true, _tms>();
          tdo_value = clock();
          state_ = state::exit2_ir;
        }
      } break;

      case state::exit2_ir: {
        if(target >= state::shift_ir && target < state::exit2_ir) {
          gpio::set<false, _tms>();
          state_ = state::shift_ir;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::update_ir;
        }
        tdo_value = clock();
      } break;

      case state::update_ir:
      case state::update_dr: {
        if(target == state::run_test_idle) {
          gpio::set<false, _tms>();
          state_ = state::run_test_idle;
        }
        else {
          gpio::set<true, _tms>();
          state_ = state::select_dr_scan;
        }
        tdo_value = clock();
      } break;

      default: reset(); break;
      }
    }

    return tdo_value;
  }

  /**
   * @brief Receive and transmit data into IR or DR registers
   *
   * @param in     - input data, will be shifted into TDI
   * @param out    - output data, will be shifted from TDO
   * @param bits   - count of bits to rxtx
   * @param target - target TAP controller state
   * @return       - io::result
  */
  io::result rxtx(uint32_t in, uint32_t &out, uint32_t bits, state target)
  {
    if(bits == 0) { return io::result::success; }
    if(bits > 32 || (state_ != state::shift_ir && state_ != state::shift_dr)) {
      return io::result::error;
    }
    if(state_ != target) { bits--; }

    uint32_t shr = 0;
    out = 0;

    while(bits) {
      gpio::set<_tdi>(in & 1);
      in >>= 1;
      out |= uint32_t(clock()) << shr++;
      --bits;
    }

    if(state_ != target) {
      gpio::set<_tdi>(in & 1);
      out |= uint32_t(
        set_state((state_ == state::shift_ir)? state::exit1_ir : state::exit1_dr)
      ) << shr;
    }

    set_state(target);

    return io::result::success;
  }

  /**
   * @brief Receive and transmit data into IR or DR registers
   *
   * @param in     - input data, will be shifted into TDI
   * @param out    - output data, will be shifted from TDO
   * @param bits   - count of bits to rxtx
   * @param target - target TAP controller state
   * @return       - io::result
  */
  io::result rxtx(const void *in, void *out, uint32_t bits, state target)
  {
    if(bits == 0) { return io::result::success; }
    if(state_ != state::shift_ir && state_ != state::shift_dr) { return io::result::error; }
    if(state_ != target) { bits--; }

    auto in_p  = static_cast<const uint32_t*>(in);
    auto out_p = static_cast<uint32_t*>(out);

    while(bits >= 32) {
      rxtx_word(*in_p, *out_p, 32);
      bits -= 32;
      ++in_p;
      ++out_p;
    }

    uint32_t shr = rxtx_word(*in_p, *out_p, bits);

    if(state_ != target) {
      gpio::set<_tdi>(*in_p & (1 << shr));

      *out_p |= uint32_t(
        set_state((state_ == state::shift_ir)? state::exit1_ir : state::exit1_dr)
      ) << shr;
    }

    set_state(target);

    return io::result::success;
  }

  /**
   * @brief Receive and transmit data into IR or DR registers
   *
   * @param in     - input data, will be shifted into TDI
   * @param out    - output data, will be shifted from TDO
   * @param bits   - count of bits to rxtx
   * @param target - target TAP controller state
   * @return       - io::result
  */
  io::result rxtx(uint8_t in, void *out, uint32_t bits, state target)
  {
    if(bits == 0) { return io::result::success; }
    if(state_ != state::shift_ir && state_ != state::shift_dr) { return io::result::error; }
    if(state_ != target) { bits--; }

    const union {
      uint8_t bytes[4];
      uint32_t in;
    } d{ {in, in, in, in} };

    auto out_p = static_cast<uint32_t*>(out);

    while(bits >= 32) {
      rxtx_word(d.in, *out_p, 32);
      bits -= 32;
      ++out_p;
    }

    uint32_t shr = rxtx_word(d.in, *out_p, bits);

    if(state_ != target) {
      gpio::set<_tdi>(d.in & (1 << shr));

      *out_p |= uint32_t(
        set_state((state_ == state::shift_ir)? state::exit1_ir : state::exit1_dr)
      ) << shr;
    }

    set_state(target);

    return io::result::success;
  }

  /**
   * @brief Write data into IR or DR registers
   *
   * @param in     - input data, will be shifted into TDI
   * @param bits   - count of bits to rxtx
   * @return       - io::result
  */
  io::result tx(uint32_t in, uint32_t bits)
  {
    if(bits == 0) { return io::result::success; }
    if(state_ != state::shift_ir && state_ != state::shift_dr) { return io::result::error; }

    tx_word(in, bits);

    return io::result::success;
  }

  /**
   * @brief Write data into IR or DR registers
   *
   * @param in     - input data, will be shifted into TDI
   * @param bits   - count of bits to tx
   * @param target - target TAP controller state
   * @return       - io::result
  */
  io::result tx(uint32_t in, uint32_t bits, state target)
  {
    if(bits == 0) { return io::result::success; }
    if(state_ != state::shift_ir && state_ != state::shift_dr) { return io::result::error; }
    if(state_ != target) { bits--; }

    tx_word(in, bits);

    if(state_ != target) { gpio::set<_tdi>((in >> bits) & 1); }
    set_state(target);

    return io::result::success;
  }

  /**
   * @brief Write data into IR or DR registers
   *
   * @param data   - input data, will be shifted into TDI
   * @param bits   - count of bits to tx
   * @param target - target TAP controller state
   * @return       - io::result
  */
  io::result tx(const void *data, uint32_t bits, state target)
  {
    if(bits == 0) { return io::result::success; }
    if(state_ != state::shift_ir && state_ != state::shift_dr) { return io::result::error; }
    if(state_ != target) { bits--; }

    auto p = static_cast<const uint32_t*>(data);

    while(bits >= 32) { tx_word(*p++, 32); bits -= 32; }
    tx_word(*p, bits);

    if(state_ != target) { gpio::set<_tdi>((*p >> bits) & 1); }
    set_state(target);

    return io::result::success;
  }
private:
  state state_ = state::unknown;

  bool clock()
  {
    gpio::set<true, _tck>();
    bool in = gpio::read<_tdo>();
    gpio::set<false, _tck>();
    asm volatile("nop\n");
    return in;
  }

  template<typename _in>
  void tx_word(_in in, uint32_t bits)
  {
    while(bits) {
      gpio::set<_tdi>(in & 1);
      in >>= 1;
      clock();
      --bits;
    }
  }

  template<typename _io>
  uint32_t rxtx_word(_io in, _io &out, uint32_t bits)
  {
    if(!bits) { return 0; }

    out          = 0;
    uint32_t shr = 0;

    do {
      gpio::set<_tdi>(in & 1);
      in >>= 1;
      out |= uint32_t(clock()) << shr++;
      --bits;
    } while(bits);

    return shr;
  }
};

} // lmcu::soft
