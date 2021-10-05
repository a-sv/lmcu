#pragma once
#include <lmcu/gpio>
#include <lmcu/delay>

// ------------------------------------------------------------------------------------------------
namespace lmcu::drv::soft::touch_key {
// ------------------------------------------------------------------------------------------------

enum class threshold : uint16_t { defval = 30 };

enum class press_time : uint16_t { defval = 10 };

enum class long_press_time : uint16_t { defval = 1000 };

enum class release_time : uint16_t { defval = 10 };

enum class max_value : uint16_t { defval = 4096 };

enum class filter : uint16_t { defval = 180 };

enum class kstate : uint8_t
{
  not_pressed,
  pressed,
  lpressed,
  pressed_release,
  lpressed_release
};

template<typename _pin, auto ..._args>
class device
{
public:
  static constexpr auto dev_class = lmcu::dev_class::key;

  // Sensivity threshold in percent
  static constexpr auto threshold = option::get_u<touch_key::threshold, _args...>(
                                      touch_key::threshold::defval);

  // Time of key hold to switch in 'pressed' state
  static constexpr auto press_time = option::get_u<touch_key::press_time, _args...>(
                                      touch_key::press_time::defval);

  // Time of key hold to switch in 'long pressed' state
  static constexpr auto long_press_time = option::get_u<touch_key::long_press_time, _args...>(
                                            touch_key::long_press_time::defval);

  // Time of key release to switch in 'not pressed' state
  static constexpr auto release_time = option::get_u<touch_key::release_time, _args...>(
                                         touch_key::release_time::defval);

  // Max value of capacity measurement
  static constexpr auto max_value = option::get_u<touch_key::max_value, _args...>(
                                      touch_key::max_value::defval);

  static constexpr auto filter = option::get_u<touch_key::filter, _args...>(
                                   touch_key::filter::defval);

  static_assert(option::check<
    std::tuple<
      touch_key::threshold,
      touch_key::press_time,
      touch_key::long_press_time,
      touch_key::release_time,
      touch_key::max_value,
      touch_key::filter
    >,
    _args...
  >());

  static_assert(
    threshold > 0 &&
    press_time > 0 &&
    long_press_time > press_time &&
    release_time > 0 &&
    max_value > 0
  );

  inline auto state() const { return state_; }

  inline bool pressed() const { return lmcu::flags::all(flags_, flags_t::pressed); }

  inline void clr_pressed() { flags_ -= flags_t::pressed; }

  inline bool lpressed() const { return lmcu::flags::all(flags_, flags_t::lpressed); }

  inline void clr_lpressed() { flags_ -= flags_t::lpressed; }

  inline bool clicked() const { return lmcu::flags::all(flags_, flags_t::clicked); }

  inline void clr_clicked() { flags_ -= flags_t::clicked; }

  inline bool released() const { return lmcu::flags::all(flags_, flags_t::released); }

  inline void clr_released() { flags_ -= flags_t::released; }

  inline void clr_all() { flags_ = flags_t(0); }

  inline int32_t value() const { return val_ - ofs_; }

  inline int32_t raw() const { return val_; }

  inline bool fail() const { return val_ >= max_value; }

  inline void reset_calibration() { ofs_ = 0; th_ = 0; }

  void task()
  {
    using namespace lmcu;

    using in = gpio::pin<option::null, _pin::port, gpio::pin_n{_pin::n}, gpio::mode::input>;
    using out = gpio::pin<option::null, _pin::port, gpio::pin_n{_pin::n},
                          gpio::mode::output_open_drain>;

    gpio::configure<out>();
    gpio::set<out>(false);
    gpio::configure<in>();

    uint32_t start, val;

    start = delay::start();
    do {
      val = delay::elapsed(start);
    }
    while(!gpio::read<in>() && val < max_value);

    if constexpr(filter > 0) {
      avg_ += val;

      if(++avg_n_ >= filter) {
        val_ = avg_ / avg_n_;
        avg_   = 0;
        avg_n_ = 0;
      }
    }
    else {
      val_ = val;
    }

    if(ofs_ == 0) {
      ofs_ = val_;
      th_  = (val_ * threshold) / 100;
    }

    if(value() > th_) {
      //
      // KEY pressed
      //
      switch(state_)
      {
      case kstate::not_pressed:
        if(tm_.elapsed<delay::units::ms>() >= press_time) {
          state_ = kstate::pressed;
          flags_ += flags_t::pressed;
        }
        break;
      case kstate::pressed:
        if(tm_.expired()) {
          state_ = kstate::lpressed;
          flags_ += flags_t::lpressed;
        }
        break;
      case kstate::pressed_release:
        state_ = kstate::pressed;
        tm_.start<delay::units::ms>(tm_r_);
        break;
      case kstate::lpressed_release:
        state_ = kstate::lpressed;
        break;
      default:
        break;
      }
    }
    else {
      //
      // KEY released
      //
      if(state_ == kstate::not_pressed) {
        tm_.start<delay::units::ms>(long_press_time);
      }
      else {
        if(state_ == kstate::pressed) {
          state_ = kstate::pressed_release;
          tm_r_ = tm_.remaining<delay::units::ms>();
          tm_.start<delay::units::ms>(release_time);
        }
        else
        if(state_ == kstate::lpressed) {
          state_ = kstate::lpressed_release;
          tm_.start<delay::units::ms>(release_time);
        }
        else
        if(
          (state_ == kstate::pressed_release || state_ == kstate::lpressed_release) &&
          tm_.expired()
        ) {
          if(state_ == kstate::pressed_release) {
            flags_ += flags_t::clicked;
          }
          state_ = kstate::not_pressed;
          flags_ += flags_t::released;
        }
      }
    }
  }
private:
  enum class flags_t : uint8_t
  {
    lmcu_flags,
    pressed  = 1U << 0,
    lpressed = 1U << 1,
    clicked  = 1U << 2,
    released = 1U << 3
  };

  uint32_t avg_ = 0;
  uint16_t avg_n_ = 0, val_ = 0, ofs_ = 0, th_ = 0, tm_r_ = 0;
  kstate state_ = kstate::not_pressed;
  flags_t flags_ = flags_t(0);
  lmcu::delay::dwt::timer tm_;
};

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::drv::sensors::touch_key
// ------------------------------------------------------------------------------------------------
