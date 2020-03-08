#include <lmcu/delay>
#include <lmcu/rcc>
#include <lmcu/gpio>
#include <lmcu/systick>

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
  // You may use this parameter to reduce SysTick input clock
  // ,rcc::systick_div::_8
>;

using stk = systick::config<
  // frequency: 10.000Hz (if this parameter is not set, SysTick will be
  //                      configured at 1000.000Hz)
  // NOTICE:
  //   (systick_clock * 1000) / (freq.ip * 1000 + freq.fp) - 1 must be <= 0xffffff
  systick::freq{10,000},

  // Enable SysTick IRQ
  systick::irq<>
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

  // Enable SysTick
  systick::on();
  // Configure SysTick module
  systick::configure<stk>();

  irq::enable();

  while(true)
    ;

  return 0;
}

void isr::sys_tick_irq()
{
  gpio::toggle<led>();
}
