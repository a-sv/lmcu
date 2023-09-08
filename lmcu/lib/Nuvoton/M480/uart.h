#pragma once
#include <lmcu/common>
#include <lmcu/dev/uart>
#include <lmcu/irq>
#include <lmcu/delay>

#include "sys.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::uart {
// ------------------------------------------------------------------------------------------------
#include "../../irq_id.h"

enum class id { uart0, uart1, uart2, uart3, uart4, uart5, uart6, uart7 };

enum class clk_mux { hirc, lxt, pll, hxt };

enum class div
{
  _0   = 0,
  _1   = 1,
  _2   = 2,
  _3   = 3,
  _4   = 4,
  _5   = 5,
  _6   = 6,
  _7   = 7,
  _8   = 8,
  _9   = 9,
  _10  = 10,
  _11  = 11,
  _12  = 12,
  _13  = 13,
  _14  = 14,
  _15  = 15
};

enum class data_size { _5bit, _6bit, _7bit, _8bit };

enum class parity { disable, even, odd, mark, space };

enum class stop_bits
{
  _1,
  _2,
  _1_5
};

enum class dma { disable, rx, tx, rxtx };

enum class baud : uint32_t { };

enum class events : uint32_t
{
  lmcu_flags,

  rda = device::UART0::INTSTS::RDAIF_1,       // Receive Data Available Interrupt
  ther = device::UART0::INTSTS::THREIF_1,     // Transmit Holding Register Empty Interrupt
  txend = device::UART0::INTSTS::TXENDIF_1,   // Transmitter Empty Interrupt
  rls = device::UART0::INTSTS::RLSIF_1,       // Receive Line Status interrupt (parity error or frame error or break error)
  modem = device::UART0::INTSTS::MODEMIF_1,   // MODEM Status Interrupt
  rxto = device::UART0::INTSTS::RXTOIF_1,     // Receiver Buffer Time-out Interrupt
  buferr = device::UART0::INTSTS::BUFERRIF_1, // Buffer Error Interrupt
  lin = device::UART0::INTSTS::LINIF_1,       // LIN Bus Interrupt
  wk = device::UART0::INTSTS::WKIF_1,         // Wake-up Interrupt
  abr = device::UART0::INTSTS::ABRINT_1,      // Auto-Baud Rate Interrupt
  swbe = device::UART0::INTSTS::SWBEINT_1     // Single-wire Bit Error Detect Interrupt
};

enum class status : uint32_t
{
  lmcu_flags,

  rxov = device::UART0::FIFOSTS::RXOVIF_1, // RX Overflow Error Interrupt Flag
  abdr = device::UART0::FIFOSTS::ABRDIF_1,  // Auto-baud Rate Detect Interrupt Flag
  abtdto = device::UART0::FIFOSTS::ABRDTOIF_1, // Auto-baud Rate Detect Time-out Interrupt Flag This bit is set to logic '1' in Auto-baud Rate Detect mode when the baud rate counter is overflow. Note: This bit can be cleared by writing '1' to it. (bits: 2)
  addrdet = device::UART0::FIFOSTS::ADDRDETF_1,// RS-485 Address Byte Detect Flag
  pef = device::UART0::FIFOSTS::PEF_1, // Parity Error Flag
  fef = device::UART0::FIFOSTS::FEF_1, // Framing Error Flag
  bif = device::UART0::FIFOSTS::BIF_1, // Break Interrupt Flag
  rxempty = device::UART0::FIFOSTS::RXEMPTY_1,  // Receiver FIFO Empty (Read Only)
  rxfull = device::UART0::FIFOSTS::RXFULL_1,  // Receiver FIFO Full (Read Only)
  txempty = device::UART0::FIFOSTS::TXEMPTY_1,  // Transmitter FIFO Empty (Read Only)
  txfull = device::UART0::FIFOSTS::TXFULL_1,  // Transmitter FIFO Full (Read Only)
  txov = device::UART0::FIFOSTS::TXOVIF_1,  // TX Overflow Error Interrupt Flag
  txextyf = device::UART0::FIFOSTS::TXEMPTYF_1,  // Transmitter Empty Flag (Read Only)
  rxidle = device::UART0::FIFOSTS::RXIDLE_1,  // RX Idle Status (Read Only)
  txrxact = device::UART0::FIFOSTS::TXRXACT_1  // TX and RX Active Status (Read Only)
};

template <auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();

template<id _id>
struct inst;

template<id _id>
using inst_t = typename inst<_id>::type;

template<>
struct inst<id::uart0> { using type = device::UART0; };

template<>
struct inst<id::uart1> { using type = device::UART1; };

template<>
struct inst<id::uart2> { using type = device::UART2; };

template<>
struct inst<id::uart3> { using type = device::UART3; };

template<>
struct inst<id::uart4> { using type = device::UART4; };

template<>
struct inst<id::uart5> { using type = device::UART5; };

template<>
struct inst<id::uart6> { using type = device::UART6; };

template<>
struct inst<id::uart7> { using type = device::UART7; };

template<typename _cfg>
lmcu_inline void set_baud(uint32_t val)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;

  uint32_t clock = 0;
  switch(_cfg::clk_mux)
  {
  case clk_mux::hirc: clock = rcc::clock::hirc(); break;
  case clk_mux::lxt: clock = rcc::clock::lxt(); break;
  case clk_mux::pll: clock = rcc::clock::pll(); break;
  case clk_mux::hxt: clock = rcc::clock::hxt(); break;
  default: break;
  }

  uint32_t src_freq = clock / (uint32_t(_cfg::div) + 1);
  uint32_t baud_div = ((src_freq + (val/2)) / val) - 2;
  if(baud_div > 0xFFFF) {
    baud_div = (((src_freq) + (val*8)) / val >> 4)-2;
    inst::BAUD::set(baud_div | UART0::BAUD::BAUDM0);
  }
  else {
    inst::BAUD::set(baud_div | UART0::BAUD::BAUDM1 | UART0::BAUD::BAUDM0);
  }

}

template<typename _cfg>
void set_events_(events val)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  if(flags::all(val, events::rda)) { inst::INTEN::set_b(UART0::INTEN::RDAIEN_1); }
  if(flags::all(val, events::ther)) { inst::INTEN::set_b(UART0::INTEN::THREIEN_1); }
  if(flags::all(val, events::txend)) { inst::INTEN::set_b(UART0::INTEN::TXENDIEN_1); }
  if(flags::all(val, events::rls)) { inst::INTEN::set_b(UART0::INTEN::RLSIEN_1); }
  if(flags::all(val, events::modem)) { inst::INTEN::set_b(UART0::INTEN::MODEMIEN_1); }
  if(flags::all(val, events::rxto)) { inst::INTEN::set_b(UART0::INTEN::RXTOIEN_1); }
  if(flags::all(val, events::buferr)) { inst::INTEN::set_b(UART0::INTEN::BUFERRIEN_1); }
  if(flags::all(val, events::lin)) { inst::INTEN::set_b(UART0::INTEN::LINIEN_1); }
  if(flags::all(val, events::wk)) { inst::INTEN::set_b(UART0::INTEN::WKIEN_1); }
  if(flags::all(val, events::abr)) { inst::INTEN::set_b(UART0::INTEN::ABRIEN_1); }
  if(flags::all(val, events::swbe)) { inst::INTEN::set_b(UART0::INTEN::SWBEIEN_1); }

/*  switch (val) {
    case events::rda: inst::INTEN::set_b(UART0::INTEN::RDAIEN_1); break;
    case events::ther: inst::INTEN::set_b(UART0::INTEN::THREIEN_1); break;
    case events::txend: inst::INTEN::set_b(UART0::INTEN::TXENDIEN_1); break;
    case events::rls: inst::INTEN::set_b(UART0::INTEN::RLSIEN_1); break;
    case events::modem: inst::INTEN::set_b(UART0::INTEN::MODEMIEN_1); break;
    case events::rxto: inst::INTEN::set_b(UART0::INTEN::RXTOIEN_1); break;
    case events::buferr: inst::INTEN::set_b(UART0::INTEN::BUFERRIEN_1); break;
    case events::lin: inst::INTEN::set_b(UART0::INTEN::LINIEN_1); break;
    case events::wk: inst::INTEN::set_b(UART0::INTEN::WKIEN_1); break;
    case events::abr: inst::INTEN::set_b(UART0::INTEN::ABRIEN_1); break;
    case events::swbe: inst::INTEN::set_b(UART0::INTEN::SWBEIEN_1); break;
    default: break;
  }*/
}

/**
 * @brief Enable / disable events.
 *
 * @tparam _cfg - list of UART configs.
*/
template<typename ..._cfg>
lmcu_inline void set_events(events val)
{
  static_assert(sizeof...(_cfg) > 0);
  (set_events_<_cfg>(val), ...);
}

/**
 * @brief Returns occured events.
 *
 * @tparam _cfg - UART config.
*/
template<typename _cfg>
lmcu_inline events get_events()
{
  using inst = inst_t<_cfg::id>;
  return events(inst::INTSTS::get());
}


template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::uart;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto id = option::get<uart::id, _args...>();

  static constexpr auto clk_mux = option::get<uart::clk_mux, _args...>(uart::clk_mux::hirc);

  static constexpr auto div = option::get<uart::div, _args...>(uart::div(0));

  static constexpr uint32_t baud = option::get_u<uart::baud, _args...>(uart::baud(9600));

  static constexpr auto data_size = option::get<uart::data_size, _args...>(uart::data_size::_8bit);

  static constexpr auto parity = option::get<uart::parity, _args...>(uart::parity::disable);

  static constexpr auto stop_bits = option::get<uart::stop_bits, _args...>(uart::stop_bits::_1);

  //static constexpr auto dma = option::get<uart::dma, _args...>(uart::dma::disable);

  static constexpr auto events = option::get<uart::events, _args...>(uart::events(0));

  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(option::check<
    std::tuple<
      uart::id,
      uart::clk_mux,
      uart::div,
      uart::baud,
      uart::data_size,
      uart::parity,
      uart::stop_bits,
      uart::events,
      irq_id::_0
     >,
    _args...
  >());
};

template<typename _cfg>
void configure()
{
  using namespace device;
  uint32_t divn = uint32_t(_cfg::div);

  {
    uint32_t cm = 0;

    switch(_cfg::clk_mux)
    {
    case clk_mux::hirc: cm = 3; break;
    case clk_mux::lxt:  cm = 2; break;
    case clk_mux::pll:  cm = 1; break;
    default: break;
    }

    switch(_cfg::id)
    {
    case id::uart0:
      CLK::CLKSEL1::clr_b(0x3<<CLK::CLKSEL1::UART0SEL_POS);
      CLK::CLKSEL1::set_b(cm<<CLK::CLKSEL1::UART0SEL_POS);
      CLK::CLKDIV0::set_b(divn<<CLK::CLKDIV0::UART0DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART0CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART0RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART0RST_1);
      break;
    case id::uart1:
      CLK::CLKSEL1::clr_b(0x3<<CLK::CLKSEL1::UART1SEL_POS);
      CLK::CLKSEL1::set_b(cm<<CLK::CLKSEL1::UART1SEL_POS);
      CLK::CLKDIV0::set_b(divn<<CLK::CLKDIV0::UART1DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART1CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART1RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART1RST_1);
      break;
    case id::uart2:
      CLK::CLKSEL3::clr_b(0x3<<CLK::CLKSEL3::UART2SEL_POS);
      CLK::CLKSEL3::set_b(cm<<CLK::CLKSEL3::UART2SEL_POS);
      CLK::CLKDIV4::set_b(divn<<CLK::CLKDIV4::UART2DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART2CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART2RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART2RST_1);
      break;
    case id::uart3:
      CLK::CLKSEL3::clr_b(0x3<<CLK::CLKSEL3::UART3SEL_POS);
      CLK::CLKSEL3::set_b(cm<<CLK::CLKSEL3::UART3SEL_POS);
      CLK::CLKDIV4::set_b(divn<<CLK::CLKDIV4::UART3DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART3CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART3RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART3RST_1);
      break;
    case id::uart4:
      CLK::CLKSEL3::clr_b(0x3<<CLK::CLKSEL3::UART4SEL_POS);
      CLK::CLKSEL3::set_b(cm<<CLK::CLKSEL3::UART4SEL_POS);
      CLK::CLKDIV4::set_b(divn<<CLK::CLKDIV4::UART4DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART4CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART4RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART4RST_1);
      break;
    case id::uart5:
      CLK::CLKSEL3::clr_b(0x3<<CLK::CLKSEL3::UART5SEL_POS);
      CLK::CLKSEL3::set_b(cm<<CLK::CLKSEL3::UART5SEL_POS);
      CLK::CLKDIV4::set_b(divn<<CLK::CLKDIV4::UART5DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART5CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART5RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART5RST_1);
      break;
    case id::uart6:
      CLK::CLKSEL3::clr_b(0x3<<CLK::CLKSEL3::UART6SEL_POS);
      CLK::CLKSEL3::set_b(cm<<CLK::CLKSEL3::UART6SEL_POS);
      CLK::CLKDIV4::set_b(divn<<CLK::CLKDIV4::UART6DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART6CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART6RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART6RST_1);
      break;
    case id::uart7:
      CLK::CLKSEL3::clr_b(0x3<<CLK::CLKSEL3::UART7SEL_POS);
      CLK::CLKSEL3::set_b(cm<<CLK::CLKSEL3::UART7SEL_POS);
      CLK::CLKDIV4::set_b(divn<<CLK::CLKDIV4::UART7DIV_POS);
      CLK::APBCLK0::set_b(CLK::APBCLK0::UART7CKEN_1);
      SYS::IPRST1::set_b(SYS::IPRST1::UART7RST_1);
      SYS::IPRST1::clr_b(SYS::IPRST1::UART7RST_1);
      break;
    default: break;
    }
  }

  {
    using inst = inst_t<_cfg::id>;

    // Select UART function
    inst::FUNCSEL::set(UART0::FUNCSEL::FUNCSELVAL_0);

    // Set UART line configuration
    switch(_cfg::data_size)
    {
    case data_size::_6bit: inst::LINE::set_b(UART0::LINE::WLS_1); break;
    case data_size::_7bit: inst::LINE::set_b(UART0::LINE::WLS_2); break;
    case data_size::_8bit: inst::LINE::set_b(UART0::LINE::WLS_3); break;
    default: break;
    }

    switch(_cfg::parity)
    {
    case parity::odd: inst::LINE::set_b(UART0::LINE::PBE_1); break;
    case parity::even: inst::LINE::set_b(UART0::LINE::PBE_1 | UART0::LINE::EPE_1); break;
    case parity::mark: inst::LINE::set_b(UART0::LINE::PBE_1 | UART0::LINE::SPE_1); break;
    case parity::space: inst::LINE::set_b(UART0::LINE::PBE_1 | UART0::LINE::EPE_1 | UART0::LINE::SPE_1); break;
    default: break;
    }

    static_assert(!(_cfg::data_size == data_size::_5bit && _cfg::stop_bits != stop_bits::_1_5), "for 5-bit word length, 1.5 “STOP bit” is generated only");

    static_assert(!(_cfg::data_size != data_size::_5bit && _cfg::stop_bits == stop_bits::_1_5), "for 6,7,8-bit word length, 1 or 2 “STOP bit” is generated only");

    if(_cfg::stop_bits != stop_bits::_1) {
      inst::LINE::set_b(UART0::LINE::NSB_1);
    }

    // set UART Rx and RTS trigger level
    inst::FIFO::clr_b(UART0::FIFO::RFITL_MASK | UART0::FIFO::RTSTRGLV_MASK);

    set_baud<_cfg>(_cfg::baud);
  }

  set_events_<_cfg>(_cfg::events);

  if constexpr(!option::is_null<_cfg::irq>()) {
    constexpr auto irqn = []
    {
      switch(_cfg::id)
      {
      case id::uart0: return device::find_irqn("uart0");
      case id::uart1: return device::find_irqn("uart1");
      case id::uart2: return device::find_irqn("uart2");
      case id::uart3: return device::find_irqn("uart3");
      case id::uart4: return device::find_irqn("uart4");
      case id::uart5: return device::find_irqn("uart5");
      case id::uart6: return device::find_irqn("uart6");
      case id::uart7: return device::find_irqn("uart7");
      default: break;
      }
      return device::irqn::invalid_irqn;
    }();

    nvic::set_encoded_priority<irqn, _cfg::irq>();
    nvic::enable_irq<irqn>();
  }
}


// ------------------------------------------------------------------------------------------------

template<typename _cfg>
lmcu_inline void enable()
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::uart);

  //sys::unlock();

  switch(_cfg::id)
  {
  case id::uart0: CLK::APBCLK0::set_b(CLK::APBCLK0::UART0CKEN_1); break;
  case id::uart1: CLK::APBCLK0::set_b(CLK::APBCLK0::UART1CKEN_1); break;
  case id::uart2: CLK::APBCLK0::set_b(CLK::APBCLK0::UART2CKEN_1); break;
  case id::uart3: CLK::APBCLK0::set_b(CLK::APBCLK0::UART3CKEN_1); break;
  case id::uart4: CLK::APBCLK0::set_b(CLK::APBCLK0::UART4CKEN_1); break;
  case id::uart5: CLK::APBCLK0::set_b(CLK::APBCLK0::UART5CKEN_1); break;
  case id::uart6: CLK::APBCLK0::set_b(CLK::APBCLK0::UART6CKEN_1); break;
  case id::uart7: CLK::APBCLK0::set_b(CLK::APBCLK0::UART7CKEN_1); break;
  default: break;
  }

  //sys::lock();
}

template<typename _cfg>
lmcu_inline void disable()
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::uart);

  //sys::unlock();

  switch(_cfg::id)
  {
  case id::uart0: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART0CKEN_1); break;
  case id::uart1: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART1CKEN_1); break;
  case id::uart2: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART2CKEN_1); break;
  case id::uart3: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART3CKEN_1); break;
  case id::uart4: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART4CKEN_1); break;
  case id::uart5: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART5CKEN_1); break;
  case id::uart6: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART6CKEN_1); break;
  case id::uart7: CLK::APBCLK0::clr_b(CLK::APBCLK0::UART7CKEN_1); break;
  default: break;
  }

  //sys::lock();
}

template<typename _cfg>
lmcu_inline void break_ctrl(bool b)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  if(b) { inst::LINE::set_b(UART0::LINE::BCB_1); }
  else { inst::LINE::clr_b(UART0::LINE::BCB_1); }
}

template<typename _cfg>
lmcu_inline void dma_mode(dma d)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  if(d == dma::rx) { inst::INTEN::set_b(UART0::INTEN::RXPDMAEN_1); }
  else if(d == dma::tx) { inst::INTEN::set_b(UART0::INTEN::TXPDMAEN_1); }
  else if(d == dma::rxtx) {
    inst::INTEN::set_b(UART0::INTEN::RXPDMAEN_1);
    inst::INTEN::set_b(UART0::INTEN::TXPDMAEN_1);
  }
  else {
    inst::INTEN::clr_b(UART0::INTEN::RXPDMAEN_1);
    inst::INTEN::clr_b(UART0::INTEN::TXPDMAEN_1);
  }
}

template<typename _cfg>
lmcu_inline uint32_t data_addr()
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  return inst::DAT::base; // DAT::base
}

template<typename _cfg>
lmcu_inline int rx(uint8_t &data)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  data = inst::DAT::get()&device::UART0::DAT::DATVAL_MASK;
  return success;
}

template<typename _cfg>
lmcu_inline int rx(uint8_t &data, const delay::expirable &t)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  data = inst::DAT::get()&&device::UART0::DAT::DATVAL_MASK;
  return success;
}

template<typename _cfg>
lmcu_inline int tx(uint16_t data)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::DAT::set(data);
  return success;
}

template<typename _cfg>
lmcu_inline int tx(uint16_t data, const delay::expirable &t)
{
  using inst = inst_t<_cfg::id>;
  inst::DAT::set(data);
  return success;
}

//lmcu_inline int write(const void *data, uint32_t size, uint32_t &tx_size, const delay::expirable &t)

template<typename _cfg>
lmcu_inline int write(const void *data, uint32_t size, const delay::expirable &t)
{
  //using inst = inst_t<_cfg::id>;

  return success;
}

//read(void *data, uint32_t size, uint32_t &rx_size, const delay::expirable &t)

template<typename _cfg>
lmcu_inline int read(void *data, uint32_t size, const delay::expirable &t)
{
  return success;
}

/**
 * @brief Clear occured events.
 *
 * @tparam _cfg - list of UART configs.

template<typename ..._cfg>
lmcu_inline void clr_events(events val)
{
  //static_assert(sizeof...(_cfg) > 0);
  //(detail::clr_events<_cfg>(val), ...);
}*/

template<typename _cfg>
void clr_status_(status val)
{
  using inst = inst_t<_cfg::id>;
  inst::FIFOSTS::clr_b(uint32_t(val));
  inst::FIFOSTS::set(uint32_t(val));
}

template<typename ..._cfg>
lmcu_inline void clr_status(status val)
{
  static_assert(sizeof...(_cfg) > 0);
  (clr_status_<_cfg>(val), ...);
}

template<typename _cfg>
lmcu_inline status get_status()
{
  using inst = inst_t<_cfg::id>;
  return status(inst::FIFOSTS::get());
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::uart
// ------------------------------------------------------------------------------------------------


