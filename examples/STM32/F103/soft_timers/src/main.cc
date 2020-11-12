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
>;

using stk = systick::config<
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

  //
  // Software timer uses 32-bit unsigned static variable as counter.
  //
  delay::timer32 tim;
  tim.start(500); // Starts a timer with 500 ticks.

  //
  // Software timer uses 32-bit hardware counter from CORTEX-M DWT module.
  //
  // IMPORTANT: max delay in microseconds = (0xffffffff / HCLK) * 1e6
  //
  delay::dwt::timer dwttim;
  dwttim.start<delay::units::ms>(500); // Starts a timer with 500 milliseconds.

  while(true) {
    if(tim.expired()) {
      tim.start(500);
      gpio::toggle<led>();
    }

    //
    // Same with DWT timer:
    //
    //if(dwttim.expired()) {
    //  dwttim.start<delay::units::ms>(500);
    //  gpio::toggle<led>();
    //}
  }

  return 0;
}

void isr::sys_tick()
{
  // Increment timer counter every millisecond.
  delay::timer32::tick();
}
