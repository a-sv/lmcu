#pragma once
#include <utility>
#include <lmcu/device>
#include <lmcu/hwi/common>
#include <lmcu/delay>

namespace lmcu::stack::can {

template<typename _iface, uint32_t _rx_fifo_sz>
class lawicel
{
public:
  enum class can_baud
  {
    _10Kbit,
    _20Kbit,
    _50Kbit,
    _100Kbit,
    _125Kbit,
    _250Kbit,
    _500Kbit,
    _800Kbit,
    _1000Kbit
  };

  enum class uart_baud
  {
    _230400,
    _115200,
    _57600,
    _38400,
    _19200,
    _9600,
    _2400
  };

  enum class auto_startup { off, normal, listen_only };

  enum class channel_state { closed, normal, listen_only };

  enum class filter_mode { single, dual };

  static constexpr uint32_t
    std_id_mask = 0x7FF,
    ext_id      = 0x80000000,
    ext_id_mask = 0x1FFFFFFF
  ;

  inline void run()
  {
    while(true) {
      task();
      if(iface()->auto_poll_active()) { rx_frame(); }
      if(rx_fifo_.empty()) { iface()->idle(); }
    }
  }

  inline io::result in(uint8_t data)
  {
    if(uint8_t(in_ref_->len_ + 1) > sizeof(in_ref_->data_)) {
      // command too long
      in_ref_->len_ = 0; return io::result::error;
    }

    if(data == '\r') {
      auto ref = rx_fifo_.push();

      if(ref) {
        in_ref_       = std::move(ref);
        in_ref_->len_ = 0;
        return io::result::success;
      }

      in_ref_->len_ = 0;
      return io::result::busy;
    }

    in_ref_->data_[in_ref_->len_++] = data;

    return io::result::success;
  }

  void tick()
  {
    if(++ts_ > 0xEA5F) { ts_ = 0; }
  }
private:
  struct pkt
  {
    uint8_t len_ = 0;
    uint8_t data_[32];
  };

  using fifo_type = fifo<pkt, _rx_fifo_sz, decltype(_rx_fifo_sz)>;

  fifo_type rx_fifo_;
  typename fifo_type::push_ref in_ref_ = rx_fifo_.push();

  uint16_t ts_ = 0;

  inline auto iface() { return static_cast<_iface*>(this); }
  inline auto iface() const { return static_cast<const _iface*>(this); }

  enum class status { ok, z, Z, err };

  void send_status(status s)
  {
    switch(s)
    {
    case status::ok:
      iface()->out('\r');
      break;
    case status::z:
      iface()->out("z\r", 2);
      break;
    case status::Z:
      iface()->out("Z\r", 2);
      break;
    case status::err:
      iface()->out(0x7);
      break;
    };
  };

  bool rx_frame()
  {
    if(!channel_is_open()) { return false; }

    uint32_t id = 0;
    bool rtr = false;
    uint8_t data[8] = {0}, len = 0;

    if(!iface()->rx(id, rtr, data, len) || len > 8) { return false; }

    const bool ide = id & ext_id;

    if(ide) {
      id &= ~ext_id;
      iface()->out(rtr? 'R' : 'T');
    }
    else {
      iface()->out(rtr? 'r' : 't');
    }

    for(uint8_t i = ide? 8 : 3; i > 0; --i) {
      iface()->out(hex::upper(id >> 28)); id <<= 4;
    }

    iface()->out(hex::upper(len));

    for(uint8_t i = 0; i < len; ++i) {
      iface()->out(hex::upper(data[i] >> 4));
      iface()->out(hex::upper(data[i]));
    }

    if(iface()->timestamp_active()) {
      const auto ts = ts_;
      hex::upper(ts >> 8,   &data[0]);
      hex::upper(ts & 0xFF, &data[2]);
      iface()->out(data, 4);
    }

    send_status(status::ok);
    return true;
  }

  template<bool _eid, typename _ref>
  void tx_frame(bool rtr, _ref&& ref)
  {
    if(
      iface()->get_channel_state() != channel_state::normal ||
      _eid? (ref->len_ < 10 || ref->len_ > 30) : (ref->len_ < 5 || ref->len_ > 21)
    ) {
      send_status(status::err); return;
    }

    uint32_t id, len;

    if constexpr(_eid) {
      hex::to_dec(&ref->data_[1], 9);
      id  = __builtin_bswap32(*reinterpret_cast<uint32_t*>(&ref->data_[1]));
      len = ref->data_[5] >> 4;
    }
    else {
      hex::to_dec(&ref->data_[1], 4);
      id  = __builtin_bswap16(*reinterpret_cast<uint16_t*>(&ref->data_[1]));
      len = id & 0xF;
      id >>= 4;
    }

    if(id > (_eid? ext_id_mask : std_id_mask) || len > 8) { send_status(status::err); return; }

    if(rtr) {
      if(ref->len_ > 10) { send_status(status::err); return; }
    }
    else {
      const uint8_t n = len * 2;

      if constexpr(_eid) {
        hex::to_dec(&ref->data_[10], n);
      }
      else {
        hex::to_dec(&ref->data_[5], n);
      }
    }

    if(iface()->tx(id | (_eid? ext_id : 0), rtr, _eid? &ref->data_[10] : &ref->data_[5], len)) {
      send_status(iface()->auto_poll_active()? (_eid? status::Z : status::z) : status::ok);
    }
    else {
      send_status(status::err);
    }
  }

  void task()
  {
    auto ref = rx_fifo_.pop();
    if(!ref || ref->len_ == 0) { return; }

    bool ok = false;
    const auto c = ref->data_[0];

    switch(c) {
    // tx frame with standard id
    case 't':
    case 'r': { tx_frame<false>(c == 'r', ref); } break;

    // tx frame with extend id
    case 'T':
    case 'R': { tx_frame<true>(c == 'R', ref); } break;

    // poll frames
    case 'P':
    case 'A': {
      if(ref->len_ != 1 || iface()->auto_poll_active() || !channel_is_open()) {
        send_status(status::err); return;
      }

      if(c == 'A') {
        while(rx_frame())
          ;
        iface()->out('A');
        send_status(status::ok);
      }
      else {
        rx_frame();
      }
    } break;

      // set standard CAN bit-rates
    case 'S': {
      if(ref->len_ != 2 || channel_is_open()) { send_status(status::err); return; }

      switch(ref->data_[1]) {
      case '0': ok = iface()->set_baudrate(can_baud::_10Kbit);   break;
      case '1': ok = iface()->set_baudrate(can_baud::_20Kbit);   break;
      case '2': ok = iface()->set_baudrate(can_baud::_50Kbit);   break;
      case '3': ok = iface()->set_baudrate(can_baud::_100Kbit);  break;
      case '4': ok = iface()->set_baudrate(can_baud::_125Kbit);  break;
      case '5': ok = iface()->set_baudrate(can_baud::_250Kbit);  break;
      case '6': ok = iface()->set_baudrate(can_baud::_500Kbit);  break;
      case '7': ok = iface()->set_baudrate(can_baud::_800Kbit);  break;
      case '8': ok = iface()->set_baudrate(can_baud::_1000Kbit); break;
      default : break;
      }

      send_status(ok? status::ok : status::err);
    } break;

    // set CAN bit-rate
    case 's': {
      if(ref->len_ != 5 || channel_is_open()) { send_status(status::err); return; }

      ok = iface()->set_baudrate(
        hex::to_dec(ref->data_[1], ref->data_[2]), // BTR0
        hex::to_dec(ref->data_[3], ref->data_[4])  // BTR1
      );

      send_status(ok? status::ok : status::err);
    } break;

    // open CAN channel
    case 'O':
    case 'L': {
      ok = ref->len_ == 1 &&
           !channel_is_open() &&
           iface()->set_channel_state((c == 'O')? channel_state::normal :
                                                  channel_state::listen_only)
      ;
      send_status(ok? status::ok : status::err);
    } break;

    // close CAN channel
    case 'C': {
      ok = ref->len_ == 1 && channel_is_open() && iface()->set_channel_state(channel_state::closed);
      send_status(ok? status::ok : status::err);
    } break;

    // read status flags
    case 'F': {
      if(ref->len_ != 1 || !channel_is_open()) { send_status(status::err); return; }

      hex::upper(iface()->get_status(), &ref->data_[1]);
      iface()->out(ref->data_, 3);
      send_status(status::ok);
    } break;

    case 'X': // auto poll on|off
    case 'W': // filter mode
    case 'Z': { // timestamp on/off
      if(ref->len_ != 2 || channel_is_open()) { send_status(status::err); return; }

      if(c == 'X') {
        ok = iface()->auto_poll_enable(ref->data_[1] == '1');
      }
      else
      if(c == 'W') {
        ok = iface()->set_filter_mode((ref->data_[1] == '0')? filter_mode::dual :
                                                              filter_mode::single);
      }
      else {
        ok = iface()->timestamp_enable(ref->data_[1] == '1');
      }

      send_status(ok? status::ok : status::err);
    } break;

    case 'M': // set acceptance code
    case 'm': { // set acceptance mask
      if(ref->len_ != 9 || channel_is_open()) { send_status(status::err); return; }

      hex::to_dec(&ref->data_[1], 8);
      const auto val = *reinterpret_cast<uint32_t*>(&ref->data_[1]);

      ok = (c == 'M')? iface()->set_accept_code(val) : iface()->set_accept_mask(val);
      send_status(ok? status::ok : status::err);
    } break;

    case 'U': { // set UART baud rate
      if(ref->len_ != 2 || channel_is_open()) { send_status(status::err); return; }

      switch(ref->data_[1]) {
      case '0': ok = iface()->set_baudrate(uart_baud::_230400); break;
      case '1': ok = iface()->set_baudrate(uart_baud::_115200); break;
      case '2': ok = iface()->set_baudrate(uart_baud::_57600 ); break;
      case '3': ok = iface()->set_baudrate(uart_baud::_38400 ); break;
      case '4': ok = iface()->set_baudrate(uart_baud::_19200 ); break;
      case '5': ok = iface()->set_baudrate(uart_baud::_9600  ); break;
      case '6': ok = iface()->set_baudrate(uart_baud::_2400  ); break;
      default : break;
      }

      send_status(ok? status::ok : status::err);
    } break;

    case 'V': // get version
    case 'N': { // get serial number
      if(ref->len_ != 1) { send_status(status::err); return; }

      const uint16_t val = (c == 'V')? iface()->get_version() : iface()->get_serial();

      hex::upper(val >> 8,   &ref->data_[1]);
      hex::upper(val & 0xFF, &ref->data_[3]);

      iface()->out(ref->data_, 5);
      send_status(status::ok);
    } break;

    case 'Q': { // set auto startup mode
      if(ref->len_ != 2 || !channel_is_open()) { send_status(status::err); return; }

      switch(ref->data_[1]) {
      case '0': ok = iface()->set_auto_startup(auto_startup::off);         break;
      case '1': ok = iface()->set_auto_startup(auto_startup::normal);      break;
      case '2': ok = iface()->set_auto_startup(auto_startup::listen_only); break;
      default : break;
      }

      send_status(ok? status::ok : status::err);
    } break;

    default: break;
    }
  }

  inline bool channel_is_open() const
  {
    return iface()->get_channel_state() != channel_state::closed;
  }
};

} // lmcu::stack::can
