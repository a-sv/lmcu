#pragma once
#include <lmcu/gpio>
#include <lmcu/delay>

// ------------------------------------------------------------------------------------------------
namespace lmcu::drv::soft::touch_key {
// ------------------------------------------------------------------------------------------------

enum class threshold : uint16_t { defval = 15 };

enum class press_time : uint16_t { defval = 10 };

enum class long_press_time : uint16_t { defval = 1000 };

enum class release_time : uint16_t { defval = 10 };

enum class max_value : uint16_t { defval = 4096 };

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

  static_assert(option::check<
    std::tuple<
      touch_key::threshold,
      touch_key::press_time,
      touch_key::long_press_time,
      touch_key::release_time,
      touch_key::max_value
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

  inline bool pressed() const { return state_ >= state_t::pressed; }

  inline bool long_pressed() const { return state_ >= state_t::lpressed; }

  bool changed()
  {
    if(state_ != p_state_ && state_ <= state_t::lpressed) {
      p_state_ = state_;
      return true;
    }
    return false;
  }

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

    uint32_t start = delay::start();
    do {
      val_ = delay::elapsed(start);
    }
    while(!gpio::read<in>() && val_ < max_value);


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
      case state_t::not_pressed:
        if(tm_.elapsed<delay::units::ms>() >= press_time) { state_ = state_t::pressed; }
        break;
      case state_t::pressed:
        if(tm_.expired()) { state_ = state_t::lpressed; }
        break;
      case state_t::pressed_release:
        state_ = state_t::pressed;
        tm_.start<delay::units::ms>(tm_r_);
        break;
      case state_t::lpressed_release:
        state_ = state_t::lpressed;
        break;
      default:
        break;
      }
    }
    else {
      //
      // KEY released
      //
      if(state_ == state_t::not_pressed) {
        tm_.start<delay::units::ms>(long_press_time);
      }
      else {
        if(state_ == state_t::pressed) {
          state_ = state_t::pressed_release;
          tm_r_ = tm_.remaining<delay::units::ms>();
          tm_.start<delay::units::ms>(release_time);
        }
        else
        if(state_ == state_t::lpressed) {
          state_ = state_t::lpressed_release;
          tm_.start<delay::units::ms>(release_time);
        }
        else
        if(
          (state_ == state_t::pressed_release || state_ == state_t::lpressed_release) &&
          tm_.expired()
        ) { state_ = state_t::not_pressed; }
      }
    }
  }
private:
  enum class state_t : uint8_t
  {
    not_pressed,
    pressed,
    lpressed,
    pressed_release,
    lpressed_release
  };

  uint16_t val_ = 0, ofs_ = 0, th_ = 0, tm_r_ = 0;
  state_t state_ = state_t::not_pressed, p_state_ = state_;
  lmcu::delay::dwt::timer tm_;
};

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::drv::sensors::touch_key
// ------------------------------------------------------------------------------------------------
