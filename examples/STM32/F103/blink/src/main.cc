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

int main()
{
  rcc::configure<clk_conf>();

  // Running here at HSE, sysclk = 72MHz

  // Enable clock on GPIOC
  gpio::on<gpio::port::C>();
  // Configure GPIO pins
  gpio::configure<led>();

  while(true) {
    gpio::toggle<led>();
    delay::ms(500);
  }

  return 0;
}
