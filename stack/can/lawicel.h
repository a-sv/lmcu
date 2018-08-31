#pragma once
#include <lmcu/device>
#include <lmcu/common>
#include <lmcu/delay>

namespace lmcu::stack::can {

template<typename _iface, uint16_t _rx_timeout, uint8_t _rx_pipe_sz>
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

  enum class open_mode { closed, normal, listen_only };

  enum class filter_mode { single, dual };

  static constexpr uint32_t std_id_mask = 0x7FF;
  static constexpr uint32_t ext_id      = 0x80000000;
  static constexpr uint32_t ext_id_mask = 0x1FFFFFFF;

  inline void run()
  {
    while(true) {
      task();
      if(auto_poll_) { rx_frame(); }
    }
  }

  inline io::result in(const void *data, uint8_t sz) { return rx_pipe_.write(data, sz); }
  inline io::result in(uint8_t data) { return rx_pipe_.putb(data); }
private:
  bool auto_poll_ = false;
  bool ts_en_     = false;
  pipe<uint8_t, _rx_pipe_sz> rx_pipe_;

  io::result rxcmd(void *data, uint8_t sz, const delay::expirable &t)
  {
    auto poll = [this]
    {
      if(auto_poll_) { rx_frame(); }
    };

    auto b = static_cast<uint8_t*>(data), e = b + sz;
    while(b < e) {
      if(rx_pipe_.getb(*b, t, poll) != io::result::success) { return io::result::error; }

      if(*b == '\r') {
        if((e - b) == 1) { return io::result::success; }
        break;
      }
      ++b;
    }
    return io::result::error;
  }

  enum class status { ok, z, Z, fmt_err, err };

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
    case status::fmt_err:
      rx_pipe_.clear();
    case status::err:
      iface()->out(0x7);
      break;
    };
  };

  bool rx_frame()
  {
    uint32_t id = 0;
    bool rtr = false;
    uint8_t data[8];
    uint8_t len = 0;
    uint16_t ts = 0;

    if(ts_en_) {
      if(!iface()->rx(id, rtr, data, len, ts) || len > 8) { return false; }
    }
    else {
      if(!iface()->rx(id, rtr, data, len) || len > 8) { return false; }
    }

    if(id & ext_id) {
      iface()->out(rtr? 'R' : 'T');
    }
    else {
      iface()->out(rtr? 'r' : 't');
    }

    for(uint8_t i = (id & ext_id)? 8 : 3; i > 0; --i) {
      iface()->out(hex::upper(id >> 28)); id <<= 4;
    }

    iface()->out(hex::upper(len));

    for(uint8_t i = 0; i < len; ++i) {
      iface()->out(hex::upper(data[i] >> 4));
      iface()->out(hex::upper(data[i]));
    }

    send_status(status::ok);
    return true;
  }

  template<bool _eid>
  void tx_frame(bool rtr, uint8_t *data, const delay::expirable &t)
  {
    auto poll = [this]
    {
      if(auto_poll_) { rx_frame(); }
    };

    if(rx_pipe_.read(data, _eid? 9 : 4, t, poll) != io::result::success) {
      send_status(status::fmt_err); return;
    }

    uint32_t id;
    uint8_t len;

    if constexpr(_eid) {
      hex::to_dec(data, 9);
      id = *reinterpret_cast<uint32_t*>(data);
      len = data[4];
    }
    else {
      id = hex::to_dec(data[0]);
      id <<= 8;
      id |= hex::to_dec(data[1], data[2]);
      len = hex::to_dec(data[3]);
    }

    if(id > (_eid? ext_id_mask : std_id_mask) || len > 8) { send_status(status::fmt_err); return; }

    if(rtr) {
      if(rxcmd(data, 1, t) != io::result::success) { send_status(status::fmt_err); return; }
    }
    else {
      const uint8_t n = len * 2;
      if(rxcmd(data, n + 1, t) != io::result::success) { send_status(status::fmt_err); return; }
      hex::to_dec(data, n);
    }

    if(iface()->tx(id | (_eid? ext_id : 0), rtr, data, len)) {
      send_status(auto_poll_? (_eid? status::Z : status::z) : status::ok);
    }
    else {
      send_status(status::err);
    }
  }

  void task()
  {
    uint8_t data[17];

    uint8_t c = 0;
    if(rx_pipe_.getb(c) != io::result::success) { return; }

    bool err = false;

    delay::dwt::timer t;
    t.start<delay::dwt::timer::ms>(_rx_timeout);

    switch(c) {
    // set standard CAN bit-rates
    case 'S': {
      if(rxcmd(data, 2, t) != io::result::success) { send_status(status::fmt_err); return; }

      switch(data[0]) {
      case '0': err = iface()->set_baudrate(can_baud::_10Kbit);   break;
      case '1': err = iface()->set_baudrate(can_baud::_20Kbit);   break;
      case '2': err = iface()->set_baudrate(can_baud::_50Kbit);   break;
      case '3': err = iface()->set_baudrate(can_baud::_100Kbit);  break;
      case '4': err = iface()->set_baudrate(can_baud::_125Kbit);  break;
      case '5': err = iface()->set_baudrate(can_baud::_250Kbit);  break;
      case '6': err = iface()->set_baudrate(can_baud::_500Kbit);  break;
      case '7': err = iface()->set_baudrate(can_baud::_800Kbit);  break;
      case '8': err = iface()->set_baudrate(can_baud::_1000Kbit); break;
      default : err = true; break;
      }

      if(err) { send_status(status::err); } else { send_status(status::ok); }
    } break;

    // set CAN bit-rate
    case 's': {
      if(rxcmd(data, 5, t) != io::result::success) { send_status(status::fmt_err); return; }

      err = iface()->set_baudrate(
        hex::to_dec(data[0], data[1]), // BTR0
        hex::to_dec(data[2], data[3])  // BTR1
      );

      if(err) { send_status(status::err); } else { send_status(status::ok); }
    } break;

    // open CAN channel
    case 'O':
    case 'L': {
      if(rxcmd(data, 1, t) != io::result::success) { send_status(status::fmt_err); return; }

      if(iface()->open_channel(c == 'O'? open_mode::normal : open_mode::listen_only)) {
        send_status(status::ok);
      }
      else {
        send_status(status::err);
      }
    } break;

    // close CAN channel
    case 'C': {
      if(rxcmd(data, 1, t) != io::result::success) { send_status(status::fmt_err); return; }
      send_status(iface()->close_channel()? status::ok : status::err);
    } break;

    // tx frame with standard id
    case 't':
    case 'r': { tx_frame<false>(c == 'r', data, t); } break;

    // tx frame with extend id
    case 'T':
    case 'R': { tx_frame<true>(c == 'R', data, t); } break;

    case 'P':
    case 'A': {
      if(rxcmd(data, 1, t) != io::result::success) { send_status(status::fmt_err); return; }

      if(auto_poll_) { send_status(status::err); return; }

      rx_frame();
      if(c == 'A') { while(rx_frame()); }
    } break;

    case 'F': {
      if(rxcmd(data, 1, t) != io::result::success) { send_status(status::fmt_err); return; }

      uint8_t s = 0;
      if(iface()->status(s)) {
        uint8_t data[2];
        hex::upper(s, data);
        iface()->out(data, sizeof(data));
        send_status(status::ok);
      }
      else {
        send_status(status::err);
      }
    } break;

    case 'X':
    case 'W':
    case 'Z': {
      if(rxcmd(data, 2, t) != io::result::success) { send_status(status::fmt_err); return; }

      if(c == 'X') {
        bool en = data[0] == '1';
        if(iface()->auto_poll_enable(en)) {
          auto_poll_ = en;
          send_status(status::ok);
        }
        else {
          send_status(status::err);
        }
      }
      else
      if(c == 'W') {
        send_status(
          iface()->set_filter_mode(data[0] == '0'? filter_mode::dual : filter_mode::single)?
              status::ok : status::err
        );
      }
      else {
        bool en = data[0] == '1';
        if(iface()->enable_timestamp(en)) {
          ts_en_ = en;
          send_status(status::ok);
        }
        else {
          send_status(status::err);
        }
      }
    } break;

    case 'M':
    case 'm': {
      if(rxcmd(data, 9, t) != io::result::success) { send_status(status::fmt_err); return; }

      hex::to_dec(data, 8);

      if(c == 'M') {
        send_status(
          iface()->set_accept_code(*reinterpret_cast<uint32_t*>(&data[0]))?
            status::ok : status::err
        );
      }
      else {
        send_status(
          iface()->set_accept_mask(*reinterpret_cast<uint32_t*>(&data[0]))?
            status::ok : status::err
        );
      }
    } break;

    case 'U': {
      if(rxcmd(data, 2, t) != io::result::success) { send_status(status::fmt_err); return; }

      switch(data[0]) {
      case '0': err = iface()->set_baudrate(uart_baud::_230400); break;
      case '1': err = iface()->set_baudrate(uart_baud::_115200); break;
      case '2': err = iface()->set_baudrate(uart_baud::_57600 ); break;
      case '3': err = iface()->set_baudrate(uart_baud::_38400 ); break;
      case '4': err = iface()->set_baudrate(uart_baud::_19200 ); break;
      case '5': err = iface()->set_baudrate(uart_baud::_9600  ); break;
      case '6': err = iface()->set_baudrate(uart_baud::_2400  ); break;
      default : err = true; break;
      }

      send_status(err? status::ok : status::err);
    } break;

    case 'V':
    case 'N': {
      if(rxcmd(data, 1, t) != io::result::success) { send_status(status::fmt_err); return; }

      uint16_t val = 0;

      if(c == 'V') {
        iface()->get_version(val);
      }
      else {
        iface()->get_serial(val);
      }

      data[0] = c;
      hex::upper(val >> 8,   &data[1]);
      hex::upper(val & 0xFF, &data[3]);

      iface()->out(data, 5);
      send_status(status::ok);
    } break;

    case 'Q': {
      if(rxcmd(data, 2, t) != io::result::success) { send_status(status::fmt_err); return; }

      switch(data[0]) {
      case '0': err = iface()->set_auto_startup(auto_startup::off);         break;
      case '1': err = iface()->set_auto_startup(auto_startup::normal);      break;
      case '2': err = iface()->set_auto_startup(auto_startup::listen_only); break;
      default : err = true; break;
      }

      send_status(err? status::ok : status::err);
    } break;

    default: return;
    }
  }

  inline auto iface() { return static_cast<_iface*>(this); }
};

} // lmcu::stack::can::lawicel
