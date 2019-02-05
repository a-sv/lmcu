#pragma once
#include <initializer_list>
#include <lmcu/i2c>

namespace lmcu::drivers::display {

template <
  typename _module,
  uint8_t  _width    = 128,
  uint8_t  _height   = 64,
  uint8_t  _i2c_addr = 0x3C
>
class SSD1306
{
  static_assert(_module::dev_class == lmcu::dev_class::i2c, "only I2C interface supported for now");
  static_assert(_width > 0 && _width <= 128, "display width must be > 0 and <= 128");
  static_assert(_height > 0 && _height <= 64, "display height must be > 0 and <= 64");
public:
  static constexpr uint8_t
    width  = _width,
    height = _height
  ;

  static void init(const delay::expirable &t)
  {
    send_cmds(t, {
      cmd_displayoff,
      cmd_setdisplayclockdiv, 0x80,

      cmd_setmultiplex, uint8_t(_height - 1),

      cmd_setdisplayoffset, 0x0,
      cmd_setstartline,
      cmd_chargepump, 0x14,
      cmd_memorymode, 0x0,
      cmd_segremap,
      cmd_comscandec,

      cmd_setcompins, 0x12,
      cmd_setcontrast, 0x7f,

      cmd_setprecharge, 0x22,
      cmd_setvcomdetect, 0x40,
      cmd_displayallon_resume,
      cmd_normaldisplay,
      cmd_deactivate_scroll,

      cmd_scan_dir_left_to_right,

      cmd_columnaddr, 0x0, uint8_t(_width - 1),
      cmd_pageaddr, 0x0, uint8_t(_height / 8 - 1)
    });
  }

  static io::result on(const delay::expirable &t)
  {
    return send_cmds(t, {
      cmd_chargepump, 0x14,
      cmd_displayon
    });
  }

  static io::result off(const delay::expirable &t)
  {
    return send_cmds(t, { cmd_displayoff });
  }

  static io::result set_contrast(uint8_t val, const delay::expirable &t)
  {
    return send_cmds(t, { cmd_setcontrast, val });
  }

  static io::result set_startline(uint8_t val, const delay::expirable &t)
  {
    return send_cmds(t, { uint8_t( cmd_setstartline | (val & 63) ) });
  }

  static io::result write(const void *data, uint32_t sz, const delay::expirable &t)
  {
    if(sz == 0) { return io::result::success; }
    auto b = static_cast<const uint8_t*>(data), e = b + sz;
    bool start = true;

    return lmcu::i2c::write<_module>(_i2c_addr, t, [&start, &b, e](auto&& r)
    {
      if(start) {
        r = 0x40; start = false;
      }
      else {
        r = *b++;
      }
      return b < e;
    });
  }
private:
  static constexpr uint8_t
    cmd_setcontrast                          = 0x81,
    cmd_scan_dir_right_to_left               = 0xA0,
    cmd_scan_dir_left_to_right               = 0xA1,
    cmd_displayallon_resume                  = 0xA4,
    cmd_displayallon                         = 0xA5,
    cmd_normaldisplay                        = 0xA6,
    cmd_invertdisplay                        = 0xA7,
    cmd_displayoff                           = 0xAE,
    cmd_displayon                            = 0xAF,

    cmd_setdisplayoffset                     = 0xD3,
    cmd_setcompins                           = 0xDA,

    cmd_setvcomdetect                        = 0xDB,

    cmd_setdisplayclockdiv                   = 0xD5,
    cmd_setprecharge                         = 0xD9,

    cmd_setmultiplex                         = 0xA8,

    cmd_setlowcolumn                         = 0x00,
    cmd_sethighcolumn                        = 0x10,

    cmd_setstartline                         = 0x40,

    cmd_memorymode                           = 0x20,
    cmd_columnaddr                           = 0x21,
    cmd_pageaddr                             = 0x22,

    cmd_comscaninc                           = 0xC0,
    cmd_comscandec                           = 0xC8,

    cmd_segremap                             = 0xA0,

    cmd_chargepump                           = 0x8D,

    cmd_externalvcc                          = 0x01,
    cmd_switchcapvcc                         = 0x02,

    // scrolling
    cmd_activate_scroll                      = 0x2F,
    cmd_deactivate_scroll                    = 0x2E,
    cmd_set_vertical_scroll_area             = 0xA3,
    cmd_right_horizontal_scroll              = 0x26,
    cmd_left_horizontal_scroll               = 0x27,
    cmd_vertical_and_right_horizontal_scroll = 0x29,
    cmd_vertical_and_left_horizontal_scroll  = 0x2A
  ;

  static inline io::result send_cmds(const delay::expirable &t, std::initializer_list<uint8_t> cmds)
  {
    uint8_t data[2] = {0, 0};

    for(auto cmd : cmds) {
      data[1] = uint8_t(cmd);
      lmcu::i2c::write<_module>(_i2c_addr, data, sizeof(data), t);
    }

    return io::result::success;
  }
};

} // namespace lmcu::drivers::display
