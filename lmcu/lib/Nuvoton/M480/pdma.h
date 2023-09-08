#pragma once
#include <lmcu/dev/dma>
#include <lmcu/dev/rcc>
#include <lmcu/irq>
#include <lmcu/common>

// ------------------------------------------------------------------------------------------------
namespace lmcu::dma {
// ------------------------------------------------------------------------------------------------
#include "../../irq_id.h"

enum class channel { _0 = 0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15 };

enum class sar { fix, inc };

enum class dar { fix, inc };

enum class width { _8, _16, _32 };

enum class request { single, burst };

enum class periph {
  mem          = 0,
  usb_tx       = 2,
  usb_rx       = 3,
  uart0_tx     = 4,
  uart0_rx     = 5,
  uart1_tx     = 6,
  uart1_rx     = 7,
  uart2_tx     = 8,
  uart2_rx     = 9,
  uart3_tx     = 10,
  uart3_rx     = 11,
  uart4_tx     = 12,
  uart4_rx     = 13,
  uart5_tx     = 14,
  uart5_rx     = 15,
  usci0_tx     = 16,
  usci0_rx     = 17,
  usci1_tx     = 18,
  usci1_rx     = 19,
  qspi0_tx     = 20,
  qspi0_rx     = 21,
  spi0_tx      = 22,
  spi0_rx      = 23,
  spi1_tx      = 24,
  spi1_rx      = 25,
  spi2_tx      = 26,
  spi2_rx      = 27,
  spi3_tx      = 28,
  spi3_rx      = 29,
  qspi1_tx     = 30,
  qspi1_rx     = 31,
  epwm0_p1_rx  = 32,
  epwm0_p2_rx  = 33,
  epwm0_p3_rx  = 34,
  epwm1_p1_rx  = 35,
  epwm1_p2_rx  = 36,
  epwm1_p3_rx  = 37,
  i2c0_tx      = 38,
  i2c0_rx      = 39,
  i2c1_tx      = 40,
  i2c1_rx      = 41,
  i2c2_tx      = 42,
  i2c2_rx      = 43,
  i2s0_tx      = 44,
  i2s0_rx      = 45,
  tmr0         = 46,
  tmr1         = 47,
  tmr2         = 48,
  tmr3         = 49,
  eadc0_rx     = 50,
  dac0_tx      = 51,
  dac1_tx      = 52,
  epwm0_ch0_tx = 53,
  epwm0_ch1_tx = 54,
  epwm0_ch2_tx = 55,
  epwm0_ch3_tx = 56,
  epwm0_ch4_tx = 57,
  epwm0_ch5_tx = 58,
  epwm1_ch0_tx = 59,
  epwm1_ch1_tx = 60,
  epwm1_ch2_tx = 61,
  epwm1_ch3_tx = 62,
  epwm1_ch4_tx = 63,
  epwm1_ch5_tx = 64,
  uart6_tx     = 66,
  uart6_rx     = 67,
  uart7_tx     = 68,
  uart7_rx     = 69,
  eadc1_rx     = 70
};

enum class count : uint16_t { };

enum class events : uint32_t
{
  lmcu_flags,

  td = device::PDMA::INTSTS::TDIF_1, // Transfer Done Interrupt
  abt = device::PDMA::INTSTS::ABTIF_1,
  to0 = device::PDMA::INTSTS::REQTOF0_1, // Timeout Interrupt
  to1 = device::PDMA::INTSTS::REQTOF1_1 // Timeout Interrupt
};


template <auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();

template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::dma;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto channel = option::get<dma::channel, _args...>();

  //static constexpr auto count = option::get_u<dma::count, _args...>();
  // Peripheral word size
  //static constexpr auto width = option::get<dma::width, _args...>(dma::width::_8);
  // Memory increment mode
  //static constexpr auto sar = option::get<dma::sar, _args...>(dma::sar::fix);
  // Peripheral increment mode
  //static constexpr auto dar = option::get<dma::dar, _args...>(dma::dar::fix);

  //static constexpr auto mode = option::get<dma::mode, _args...>(dma::mode::single);

  static constexpr auto periph = option::get<dma::periph, _args...>(dma::periph::mem);
  // DMA interrupt events
  static constexpr auto events = option::get<dma::events, _args...>(dma::events(0));
  // DMA channel IRQ
  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(option::check<
    std::tuple<
        dma::channel,
        //dma::count,
        //dma::width,
        //dma::sar,
        //dma::dar,
        //dma::mode,
        dma::periph,
        dma::events,
        irq_id::_0
    >,
    _args...
  >());
};

template<typename _cfg>
void configure()
{
  using namespace device;

  constexpr uint8_t ch = uint8_t(_cfg::channel);
  //uint8_t p = uint8_t(_cfg::periph);

  CLK::AHBCLK::set_b(CLK::AHBCLK::PDMACKEN_1);

  // open
  PDMA::CHRST::set_b(0x01<<ch);
  PDMA::CHRST::set(0);

  PDMA::DSCT_CTL::set(ch, 0);
  PDMA::CHCTL::set_b(0x01<<ch);

  // transfer count & mode
/*  {
    PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::TXCNT_MASK | PDMA::DSCT_CTL::TXWIDTH_MASK);

    uint32_t txwidth_mask = 0;
    switch(_cfg::width)
    {
    case width::_8:  txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_0; break;
    case width::_16: txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_1; break;
    case width::_32: txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_2; break;
    default: break;
    }
    PDMA::DSCT_CTL::set_b(ch, (txwidth_mask | (_cfg::count-1)) << PDMA::DSCT_CTL::TXCNT_POS);

//    PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::SAINC_MASK | PDMA::DSCT_CTL::DAINC_MASK);
//    if(_cfg::sar == sar::fix) { PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::SAINC_3); }
//    if(_cfg::dar == dar::fix) { PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::DAINC_3); }
  }

  {
    switch(_cfg::channel)
    {
    case channel::_0:
      PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC0_MASK);
      PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC1_POS);
      break;
    case channel::_1:
      PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC1_MASK);
      PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC1_POS);
      break;
    case channel::_2:
      PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC2_MASK);
      PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC2_POS);
      break;
    case channel::_3:
      PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC3_MASK);
      PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC3_POS);
      break;
    case channel::_4:
      PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC4_MASK);
      PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC4_POS);
      break;
    case channel::_5:
      PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC5_MASK);
      PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC5_POS);
      break;
    case channel::_6:
      PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC6_MASK);
      PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC6_POS);
      break;
    case channel::_7:
      PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC7_MASK);
      PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC7_POS);
      break;
    case channel::_8:
      PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC8_MASK);
      PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC8_POS);
      break;
    case channel::_9:
      PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC9_MASK);
      PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC9_POS);
      break;
    case channel::_10:
      PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC10_MASK);
      PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC10_POS);
      break;
    case channel::_11:
      PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC11_MASK);
      PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC11_POS);
      break;
    case channel::_12:
      PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC12_MASK);
      PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC12_POS);
      break;
    case channel::_13:
      PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC13_MASK);
      PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC13_POS);
      break;
    case channel::_14:
      PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC14_MASK);
      PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC14_POS);
      break;
    case channel::_15:
      PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC15_MASK);
      PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC15_POS);
      break;
    default: break;
    }

    // TODO: config Scatter-gather Mode
    PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::OPMODE_MASK);
    PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::OPMODE_1);
  }

  // burst type and size
  {
    PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::TXTYPE_MASK | PDMA::DSCT_CTL::BURSIZE_MASK);

    uint32_t bursttype_mask = 0;
    switch(_cfg::mode)
    {
    case mode::burst: bursttype_mask = PDMA::DSCT_CTL::TXTYPE_0; break;
    case mode::single: bursttype_mask = PDMA::DSCT_CTL::TXTYPE_1; break;
    }

    PDMA::DSCT_CTL::set_b(ch, (bursttype_mask)); // | TODO: BURST SIZE
  }*/

  if(_cfg::events != dma::events(0)) {
      PDMA::INTEN::set_b(0x01<<ch);
  }

  if constexpr(!option::is_null<_cfg::irq>()) {
    constexpr auto irqn = []
    {
      return device::find_irqn("pdma");
    }();

    nvic::set_encoded_priority<irqn, _cfg::irq>();
    nvic::enable_irq<irqn>();
  }

/*  {

    switch(_cfg::periph)
    {
    case periph::mem: break;
    case periph::usb_tx: break;
    case periph::usb_rx: break;
    case periph::uart0_tx:
    case periph::uart0_rx:

      break;
    case periph::uart1_tx:
    case periph::uart1_rx:

      break;
    case periph::uart2_tx:
    case periph::uart2_rx:

      break;
    case periph::uart3_tx:
    case periph::uart3_rx:

      break;
    case periph::uart4_tx:
    case periph::uart4_rx:
      //UART4::DAT
      break;
    case periph::uart5_tx:
    case periph::uart5_rx:
      break;
    case periph::usci0_tx: break;
    case periph::usci0_rx: break;
    case periph::usci1_tx: break;
    case periph::usci1_rx: break;
    case periph::qspi0_tx: break;
    case periph::qspi0_rx: break;
    case periph::spi0_tx: break;
    case periph::spi0_rx: break;
    case periph::spi1_tx: break;
    case periph::spi1_rx: break;
    case periph::spi2_tx: break;
    case periph::spi2_rx: break;
    case periph::spi3_tx: break;
    case periph::spi3_rx: break;
    case periph::qspi1_tx: break;
    case periph::qspi1_rx: break;
    case periph::epwm0_p1_rx: break;
    case periph::epwm0_p2_rx: break;
    case periph::epwm0_p3_rx: break;
    case periph::epwm1_p1_rx: break;
    case periph::epwm1_p2_rx: break;
    case periph::epwm1_p3_rx: break;
    case periph::i2c0_tx: break;
    case periph::i2c0_rx: break;
    case periph::i2c1_tx: break;
    case periph::i2c1_rx: break;
    case periph::i2c2_tx: break;
    case periph::i2c2_rx: break;
    case periph::i2s0_tx: break;
    case periph::i2s0_rx: break;
    case periph::tmr0: break;
    case periph::tmr1: break;
    case periph::tmr2: break;
    case periph::tmr3: break;
    case periph::eadc0_rx: break;
    case periph::dac0_tx: break;
    case periph::dac1_tx: break;
    case periph::epwm0_ch0_tx: break;
    case periph::epwm0_ch1_tx: break;
    case periph::epwm0_ch2_tx: break;
    case periph::epwm0_ch3_tx: break;
    case periph::epwm0_ch4_tx: break;
    case periph::epwm0_ch5_tx: break;
    case periph::epwm1_ch0_tx: break;
    case periph::epwm1_ch1_tx: break;
    case periph::epwm1_ch2_tx: break;
    case periph::epwm1_ch3_tx: break;
    case periph::epwm1_ch4_tx: break;
    case periph::epwm1_ch5_tx: break;
    case periph::uart6_tx:
    case periph::uart6_rx:
      break;
    case periph::uart7_tx:
    case periph::uart7_rx:
      break;
    case periph::eadc1_rx: break;
    default: break;
    }
  }

  {
    switch(_cfg::sar)
    {
    case sar::inc: break;
    case sar::fix: break;
    }

    switch(_cfg::dar)
    {
    case dar::inc: break;
    case dar::fix: break;
    }
  }*/
}

template<typename _cfg>
void enable()
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
    //uint8_t p = uint8_t(_cfg::periph);
  PDMA::CHCTL::set_b(0x01<<ch);

  //CLK::AHBCLK::set_b(CLK::AHBCLK::PDMACKEN_1);
}

template<typename _cfg>
void disable()
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
      //uint8_t p = uint8_t(_cfg::periph);
  PDMA::CHCTL::clr_b(0x01<<ch);

  //CLK::AHBCLK::clr_b(CLK::AHBCLK::PDMACKEN_1);
}

template<typename _cfg>
void idle()
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
  PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::OPMODE_MASK);
}

template<typename _cfg>
uint8_t ch()
{
  constexpr uint8_t ch = uint8_t(_cfg::channel);
  return ch;
}

template<typename _cfg>
void reset() {
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
   PDMA::PAUSE::set_b(1<<ch);
   PDMA::CHRST::set_b(1<<ch);
   PDMA::CHCTL::set_b(0x01<<ch);
}

template<typename _cfg>
uint16_t elapsed() {
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
  return static_cast<uint16_t>((PDMA::DSCT_CTL::get(ch)&PDMA::DSCT_CTL::TXCNT_MASK) >> PDMA::DSCT_CTL::TXCNT_POS);
}

template<typename _cfg>
void count(width w, uint16_t count)
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
  PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::TXCNT_MASK | PDMA::DSCT_CTL::TXWIDTH_MASK);

  uint32_t txwidth_mask = 0;
  switch(w)
  {
  //case width::_8:  txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_0; break;
  case width::_16: txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_1; break;
  case width::_32: txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_2; break;
  default: break;
  }

  PDMA::DSCT_CTL::set_b(ch, (txwidth_mask | ((count-1) << PDMA::DSCT_CTL::TXCNT_POS)));
}

template<typename _cfg>
void address(uint32_t srcAddr, sar s, uint32_t dstAddr, dar d)
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
  PDMA::DSCT_SA::set(ch, srcAddr);
  PDMA::DSCT_DA::set(ch, dstAddr);

  PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::SAINC_MASK | PDMA::DSCT_CTL::DAINC_MASK);
  if(s == sar::fix) { PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::SAINC_3); }
  if(d == dar::fix) { PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::DAINC_3); }
}


template<typename _cfg>
void mode(periph m)
{
  using namespace device;

  constexpr uint8_t ch = uint8_t(_cfg::channel);
  const uint8_t p = uint8_t(m);

  switch(_cfg::channel)
  {
  case channel::_0:
    PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC0_MASK);
    PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC1_POS);
    break;
  case channel::_1:
    PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC1_MASK);
    PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC1_POS);
    break;
  case channel::_2:
    PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC2_MASK);
    PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC2_POS);
    break;
  case channel::_3:
    PDMA::REQSEL0_3::clr_b(PDMA::REQSEL0_3::REQSRC3_MASK);
    PDMA::REQSEL0_3::set_b(p<<PDMA::REQSEL0_3::REQSRC3_POS);
    break;
  case channel::_4:
    PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC4_MASK);
    PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC4_POS);
    break;
  case channel::_5:
    PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC5_MASK);
    PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC5_POS);
    break;
  case channel::_6:
    PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC6_MASK);
    PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC6_POS);
    break;
  case channel::_7:
    PDMA::REQSEL4_7::clr_b(PDMA::REQSEL4_7::REQSRC7_MASK);
    PDMA::REQSEL4_7::set_b(p<<PDMA::REQSEL4_7::REQSRC7_POS);
    break;
  case channel::_8:
    PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC8_MASK);
    PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC8_POS);
    break;
  case channel::_9:
    PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC9_MASK);
    PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC9_POS);
    break;
  case channel::_10:
    PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC10_MASK);
    PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC10_POS);
    break;
  case channel::_11:
    PDMA::REQSEL8_11::clr_b(PDMA::REQSEL8_11::REQSRC11_MASK);
    PDMA::REQSEL8_11::set_b(p<<PDMA::REQSEL8_11::REQSRC11_POS);
    break;
  case channel::_12:
    PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC12_MASK);
    PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC12_POS);
    break;
  case channel::_13:
    PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC13_MASK);
    PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC13_POS);
    break;
  case channel::_14:
    PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC14_MASK);
    PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC14_POS);
    break;
  case channel::_15:
    PDMA::REQSEL12_15::clr_b(PDMA::REQSEL12_15::REQSRC15_MASK);
    PDMA::REQSEL12_15::set_b(p<<PDMA::REQSEL12_15::REQSRC15_POS);
    break;
  default: break;
  }

  // TODO: config Scatter-gather Mode
  PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::OPMODE_MASK);
  PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::OPMODE_1);
}

template<typename _cfg>
void mode()
{
    using namespace device;
    mode<_cfg>(_cfg::periph);
}

template<typename _cfg>
void burst(request m, uint16_t size)
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);

  PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::TXTYPE_MASK | PDMA::DSCT_CTL::BURSIZE_MASK);
  uint32_t type_mask = 0;
  if(m == request::single) { type_mask = PDMA::DSCT_CTL::TXTYPE_1; }
  PDMA::DSCT_CTL::set_b(ch, type_mask | size);
}

template<typename _cfg>
void test()
{
    using namespace device;
    constexpr uint8_t ch = uint8_t(_cfg::channel);
    PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::TBINTDIS_1);
}

template<typename _cfg>
void transfer(uint32_t srcAddr, sar s, uint32_t dstAddr, dar d, uint16_t count)
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);

  // transfer count & mode
/*  {
    PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::TXCNT_MASK | PDMA::DSCT_CTL::TXWIDTH_MASK);

    uint32_t txwidth_mask = 0;
    switch(_cfg::width)
    {
    //case width::_8:  txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_0; break;
    case width::_16: txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_1; break;
    case width::_32: txwidth_mask = PDMA::DSCT_CTL::TXWIDTH_2; break;
    default: break;
    }

    PDMA::DSCT_CTL::set_b(ch, txwidth_mask | ((count-1) << PDMA::DSCT_CTL::TXCNT_POS));
  }*/

  PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::TBINTDIS_1);

  {
  //if(_cfg::periph == periph::mem) {
    PDMA::DSCT_SA::set(ch, srcAddr);
    PDMA::DSCT_DA::set(ch, dstAddr);

    PDMA::DSCT_CTL::clr_b(ch, PDMA::DSCT_CTL::SAINC_MASK | PDMA::DSCT_CTL::DAINC_MASK);
    if(s == sar::fix) { PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::SAINC_3); }
    if(d == dar::fix) { PDMA::DSCT_CTL::set_b(ch, PDMA::DSCT_CTL::DAINC_3); }
/*  }
  else {

    switch(_cfg::periph)
    {
    case periph::mem: break;
    case periph::usb_tx: break;
    case periph::usb_rx: break;
    case periph::uart0_tx:
      PDMA::DSCT_SA::set(srcAddr);

      PDMA::DSCT_CTL::set_b(PDMA::DSCT_CTL::DAINC_3); // fix addr
      break;
    case periph::uart0_rx:
      break;
    case periph::uart1_tx:
    case periph::uart1_rx:

      break;
    case periph::uart2_tx:
    case periph::uart2_rx:

      break;
    case periph::uart3_tx:
    case periph::uart3_rx:

      break;
    case periph::uart4_tx:
    case periph::uart4_rx:
        //UART4::DAT
      break;
    case periph::uart5_tx:
    case periph::uart5_rx:
      break;
    case periph::usci0_tx: break;
    case periph::usci0_rx: break;
    case periph::usci1_tx: break;
    case periph::usci1_rx: break;
    case periph::qspi0_tx: break;
    case periph::qspi0_rx: break;
    case periph::spi0_tx: break;
    case periph::spi0_rx: break;
    case periph::spi1_tx: break;
    case periph::spi1_rx: break;
    case periph::spi2_tx: break;
    case periph::spi2_rx: break;
    case periph::spi3_tx: break;
    case periph::spi3_rx: break;
    case periph::qspi1_tx: break;
    case periph::qspi1_rx: break;
    case periph::epwm0_p1_rx: break;
    case periph::epwm0_p2_rx: break;
    case periph::epwm0_p3_rx: break;
    case periph::epwm1_p1_rx: break;
    case periph::epwm1_p2_rx: break;
    case periph::epwm1_p3_rx: break;
    case periph::i2c0_tx: break;
    case periph::i2c0_rx: break;
    case periph::i2c1_tx: break;
    case periph::i2c1_rx: break;
    case periph::i2c2_tx: break;
    case periph::i2c2_rx: break;
    case periph::i2s0_tx: break;
    case periph::i2s0_rx: break;
    case periph::tmr0: break;
    case periph::tmr1: break;
    case periph::tmr2: break;
    case periph::tmr3: break;
    case periph::eadc0_rx: break;
      case periph::dac0_tx: break;
      case periph::dac1_tx: break;
      case periph::epwm0_ch0_tx: break;
      case periph::epwm0_ch1_tx: break;
      case periph::epwm0_ch2_tx: break;
      case periph::epwm0_ch3_tx: break;
      case periph::epwm0_ch4_tx: break;
      case periph::epwm0_ch5_tx: break;
      case periph::epwm1_ch0_tx: break;
      case periph::epwm1_ch1_tx: break;
      case periph::epwm1_ch2_tx: break;
      case periph::epwm1_ch3_tx: break;
      case periph::epwm1_ch4_tx: break;
      case periph::epwm1_ch5_tx: break;
      case periph::uart6_tx:
      case periph::uart6_rx:
        break;
      case periph::uart7_tx:
      case periph::uart7_rx:
        break;
      case periph::eadc1_rx: break;
      default: break;
      } */

  }

}

template<typename _cfg>
void wait_complete()
{
    using namespace device;
    constexpr uint8_t ch = uint8_t(_cfg::channel);
    while(!PDMA::TDSTS::is_set(0x01<<ch));

    PDMA::TDSTS::set(0x01<<ch);
}

template<typename _cfg>
lmcu_inline events get_events()
{
  using namespace device;
  uint32_t ev = 0;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
  if(PDMA::INTSTS::is_set(PDMA::INTSTS::ABTIF_0)) {
    if(PDMA::ABTSTS::is_set(0x01<<ch)) { ev = uint32_t(events::abt); }
  }
  else if(PDMA::INTSTS::is_set(PDMA::INTSTS::TDIF_1)) {
    if(PDMA::TDSTS::is_set(0x01<<ch)) { ev = uint32_t(events::td); }
  }

  return events(ev);
}

template<typename _cfg>
lmcu_inline void clr_events(events val)
{
  using namespace device;
  constexpr uint8_t ch = uint8_t(_cfg::channel);
  switch (val) {
    case events::abt: PDMA::ABTSTS::set(0x01<<ch); break;
    case events::td: PDMA::TDSTS::set(0x01<<ch); break;
    default: break;
  }
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::dma
// ------------------------------------------------------------------------------------------------
