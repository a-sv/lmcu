#include <lmcu/rcc>

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

int main()
{
  // Running here at HSI, sysclk = 8MHz

  rcc::configure<clk_conf>();

  // Running here at HSE, sysclk = 72MHz

  while(true)
    ;

  return 0;
}
