#include <lmcu/delay>
#include <lmcu/rcc>
#include <lmcu/gpio>

using namespace lmcu;

using clk_conf = rcc::config<
  rcc::hse_freq(8_MHz),
  rcc::osc_type::hse,
  rcc::pll_mux::hse,
  rcc::pll_mul::_9,
  rcc::sysclk_mux::pllclk,
  rcc::ahb_div::_1,
  rcc::apb1_div::_2,
  rcc::apb2_div::_1
>;

// Led on 'blue pill' board.
using led = gpio::PC13<gpio::mode::output_push_pull>;

// You need connect tactile button on PA8 pin and GND.
using key = gpio::PA8<gpio::mode::input, gpio::pull::up>;

int main()
{
  constexpr uint32_t filter_val = 5;

  rcc::configure<clk_conf>();

  // Running here at HSE, sysclk = 72MHz

  // Enable clock on GPIOA and GPIOC
  gpio::on<gpio::port::A, gpio::port::C>();
  // Configure GPIO pins
  gpio::configure<led, key>();

  uint32_t low_cnt = 0;

  while(true) {
    if(gpio::read<key>()) {
      // High level on 'key' pin.
      low_cnt = 0;
    }
    else {
      // Low level on 'key' pin.
      if(low_cnt < filter_val) {
        low_cnt++;
      }
    }

    if(low_cnt >= filter_val) {
      // Key pressed!
      gpio::set<led>(false); // Set low level on 'led' pin. (led on)
    }
    else {
      gpio::set<led>(true); // Set high level on 'led' pin. (led off)
    }

    delay::ms(20);
  }

  return 0;
}
