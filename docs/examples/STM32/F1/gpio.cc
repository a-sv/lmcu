#include <lmcu/gpio>
#include <lmcu/rcc>
#include <lmcu/delay>

using namespace lmcu;

using led_pin = gpio::PC13<gpio::mode::output_push_pull, gpio::pull::no_pull, gpio::speed::high>;

using key_pin = gpio::PB8<gpio::mode::input>;

int main()
{
  //
  // Configure clocks:
  //   HSE   : 8MHz
  //   SYSCLK: 72MHz
  //   HCLK  : 72Mhz
  //   APB1  : 36MHz
  //   APB2  : 72Mhz
  //

  rcc::configure<
    rcc::apb1_prediv::_2,
    rcc::apb2_prediv::_1,
    rcc::ahb_prediv::_1,
    rcc::sysclk_mux::pllclk,
    rcc::css::disable,
    rcc::pll_mul::_9,
    rcc::pll_mux::hse,
    rcc::osc_type::hse
  >();

  // Enable GPIO ports
  gpio::enable<gpio::port::B, gpio::port::C>();
  // Configure PIN's
  gpio::configure<led_pin, key_pin>();

  while(true) {
    // Read GPIO pin state
    if(gpio::read<key_pin>()) {
      gpio::toggle<led_pin>(); // Blink led
    }
    else {
      // Set `led_pin` to high state (turn off led on 'blue pill' board)
      gpio::set<true, led_pin>();
    }
    delay::ms(100);
  }
}
