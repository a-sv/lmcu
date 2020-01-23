#pragma once
#include <lmcu/hwi/common>
#include <lmcu/dev/pwr>
#include <lmcu/dev/rcc>

namespace lmcu::pwr {

enum class bkp_wp { disable, enable };

/**
 * @brief Enable PWR clocks
*/
lmcu_static_inline void on() { device::RCC::APB1ENR::set_b(device::RCC::APB1ENR::PWREN); }

/**
 * @brief Disable PWR clocks
*/
lmcu_static_inline void off() { device::RCC::APB1ENR::clr_b(device::RCC::APB1ENR::PWREN); }

/**
 * @brief Return true if PWR clocks is enabled
*/
lmcu_static_inline bool is_on()
{
  return device::RCC::APB1ENR::is_set(device::RCC::APB1ENR::PWREN);
}

/**
 * @brief Return BKP domain write protection status
*/
lmcu_static_inline bkp_wp get_bkp_write_protect()
{
  return device::PWR::CR::is_set(device::PWR::CR::DBP)? bkp_wp::enable : bkp_wp::disable;
}

/**
 * @brief Enable / Disable BKP domain write protection
*/
template <bkp_wp _bkp_wp>
void set_bkp_write_protect()
{
  using namespace device;

  if constexpr(_bkp_wp == bkp_wp::enable) {
    PWR::CR::clr_b(PWR::CR::DBP);
  }
  else {
    PWR::CR::set_b(PWR::CR::DBP);
  }

  while(PWR::CR::is_set(PWR::CR::DBP) == (_bkp_wp == bkp_wp::enable))
    ;
}

/**
 * @brief Disables BKP write protection and call 'fn', after 'fn' finish restores write protection
 *        mode.
 *
 * @param fn - callable object
*/
template <typename _fn>
void bkp_write(_fn&& fn)
{
  const auto pwr_en = is_on();

  if(!pwr_en) { on(); }

  // Disable BKP write protection
  const auto wp = get_bkp_write_protect();
  set_bkp_write_protect<bkp_wp::disable>();

  fn();

  if(pwr_en) {
    // Enable BKP write protection
    if(wp == bkp_wp::enable) { set_bkp_write_protect<bkp_wp::enable>(); }
  }
  else {
    // Enable BKP write protection and disable PWR clocks
    set_bkp_write_protect<bkp_wp::enable>();
    off();
  }
}

} // namespace lmcu::pwr
