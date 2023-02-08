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

enum class id { uart0, uart1, uart2, uart3, uart4, uart5 };

enum class clk_mux { hirc, pll, hxt };

enum class data_size { _5bit, _6bit, _7bit, _8bit };

enum class parity { disable, even, odd, mark, space };

enum class stop_bits
{
  _1,
  _2,
  _1_5
};

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

enum class baud : uint32_t { };

enum class events : uint32_t
{
  lmcu_flags,

  rda = device::UART0::ISR::RDA_IF_1,       // Receive Data Available Interrupt
  thre = device::UART0::ISR::THRE_IF_1,     // Transmit Holding Register Empty Interrupt
  rls = device::UART0::ISR::RLS_IF_1,       // Receive Line Status interrupt (parity error or frame error or break error)
  modem = device::UART0::ISR::MODEM_IF_1,   // MODEM Status Interrupt
  tout = device::UART0::ISR::TOUT_IF_1,     // Time-Out Interrupt
  buferr = device::UART0::ISR::BUF_ERR_IF_1, // Buffer Error Interrupt
  wk = device::UART0::ISR::WKIF_1,          // Wake-up Interrupt
  lin = device::UART0::ISR::LIN_IF_1,       // LIN Bus Interrupt
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

  static constexpr auto events = option::get<uart::events, _args...>(uart::events(0));

  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(option::check<
    std::tuple<
      uart::id,
      uart::clk_mux,
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
void set_events_(events val)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  if(flags::all(val, events::rda)) { inst::IER::set_b(UART0::IER::RDA_IEN_1); }
  if(flags::all(val, events::thre)) { inst::IER::set_b(UART0::IER::THRE_IEN_1); }
  if(flags::all(val, events::tout)) { inst::IER::set_b(UART0::IER::TOUT_IEN_1); }
  if(flags::all(val, events::rls)) { inst::IER::set_b(UART0::IER::RLS_IEN_1); }
  if(flags::all(val, events::modem)) { inst::IER::set_b(UART0::IER::MODEM_IEN_1); }
  if(flags::all(val, events::buferr)) { inst::IER::set_b(UART0::IER::BUF_ERR_IEN_1); }
  if(flags::all(val, events::lin)) { inst::IER::set_b(UART0::IER::LIN_IEN_1); }
  if(flags::all(val, events::wk)) { inst::IER::set_b(UART0::IER::WKDATIEN_1); }
}

#define UART_BAUD_MODE2_DIVIDER(u32SrcFreq, u32BaudRate)    ((((u32SrcFreq) + ((u32BaudRate)/2)) / (u32BaudRate))-2)
#define UART_BAUD_MODE0_DIVIDER(u32SrcFreq, u32BaudRate)    ((((u32SrcFreq) + ((u32BaudRate)*8)) / (u32BaudRate) >> 4)-2)

template<typename _cfg>
void configure()
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  uint32_t divn = uint32_t(_cfg::div);
  uint32_t uart_clk = 0;

  {
    sys::unlock();

    switch(_cfg::id)
    {
    case id::uart0:
      CLK::APBCLK::set_b(CLK::APBCLK::UART0_EN_1);
      GCR::IPRSTC2::set_b(GCR::IPRSTC2::UART0_RST_1);
      GCR::IPRSTC2::clr_b(GCR::IPRSTC2::UART0_RST_1);
      break;
    case id::uart1:
      CLK::APBCLK::set_b(CLK::APBCLK::UART1_EN_1);
      GCR::IPRSTC2::set_b(GCR::IPRSTC2::UART1_RST_1);
      GCR::IPRSTC2::clr_b(GCR::IPRSTC2::UART1_RST_1);
      break;
    default: break;
    }

    CLK::CLKDIV::set_b(divn << CLK::CLKDIV::UART_N_POS);
    CLK::CLKSEL1::clr_b(CLK::CLKSEL1::UART_S_MASK);

    switch(_cfg::clk_mux)
    {
    case clk_mux::hirc:
      CLK::CLKSEL1::set_b(CLK::CLKSEL1::UART_S_3);
      uart_clk = rcc::clock::hirc();
      break;
    case clk_mux::pll:
      CLK::CLKSEL1::set_b(CLK::CLKSEL1::UART_S_1);
      uart_clk = rcc::clock::pll();
      break;
    case clk_mux::hxt:
      uart_clk = rcc::clock::htx();
      break;
    default: break;
    }

    sys::lock();

    // Select UART function
    inst::FUN_SEL::set_b(UART0::FUN_SEL::FUN_SELVAL_0);

    inst::LCR::clr_b(UART0::LCR::WLS_MASK | UART0::LCR::PBE_MASK | UART0::LCR::EPE_MASK | UART0::LCR::SPE_MASK | UART0::LCR::NSB_MASK);

    // Set UART line configuration
    switch(_cfg::data_size)
    {
    case data_size::_6bit: inst::LCR::set_b(UART0::LCR::WLS_1); break;
    case data_size::_7bit: inst::LCR::set_b(UART0::LCR::WLS_2); break;
    case data_size::_8bit: inst::LCR::set_b(UART0::LCR::WLS_3); break;
    default: break;
    }

    switch(_cfg::parity)
    {
    case parity::odd: inst::LCR::set_b(UART0::LCR::PBE_1); break;
    case parity::even: inst::LCR::set_b(UART0::LCR::PBE_1 | UART0::LCR::EPE_1); break;
    case parity::mark: inst::LCR::set_b(UART0::LCR::PBE_1 | UART0::LCR::SPE_1); break;
    case parity::space: inst::LCR::set_b(UART0::LCR::PBE_1 | UART0::LCR::EPE_1 | UART0::LCR::SPE_1); break;
    default: break;
    }

    static_assert(!(_cfg::data_size == data_size::_5bit && _cfg::stop_bits != stop_bits::_1_5), "for 5-bit word length, 1.5 “STOP bit” is generated only");

    static_assert(!(_cfg::data_size != data_size::_5bit && _cfg::stop_bits == stop_bits::_1_5), "for 6,7,8-bit word length, 1 or 2 “STOP bit” is generated only");

    if(_cfg::stop_bits != stop_bits::_1) {
      inst::LCR::set_b(UART0::LCR::NSB_1);
    }
  }

  uint32_t baud_div = UART_BAUD_MODE2_DIVIDER((uart_clk) / (divn + 1), _cfg::baud);
  if(baud_div > 0xFFFF) {
    inst::BAUD::set(UART_BAUD_MODE0_DIVIDER((uart_clk) / (divn + 1), _cfg::baud));
  }
  else {
    inst::BAUD::set(UART0::BAUD::DIV_X_EN_1 | UART0::BAUD::DIV_X_ONE_1 | baud_div);
  }

  set_events_<_cfg>(_cfg::events);

  if constexpr(!option::is_null<_cfg::irq>()) {
    constexpr auto irqn = []
    {
      switch(_cfg::id)
      {
      case id::uart0: return device::find_irqn("uart02");
      case id::uart1: return device::find_irqn("uart1");
      case id::uart2: return device::find_irqn("uart02");
      case id::uart3: return device::find_irqn("uart3");
      case id::uart4: return device::find_irqn("uart4");
      case id::uart5: return device::find_irqn("uart5");

      default: break;
      }
      return device::irqn::invalid_irqn;
    }();

    nvic::set_encoded_priority<irqn, _cfg::irq>();
    nvic::enable_irq<irqn>();
  }

}

template<typename _cfg>
lmcu_inline int rx(uint8_t &data)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  data = inst::RBR::get()&device::UART0::RBR::RBR_MASK;
  return success;
}

template<typename _cfg>
lmcu_inline int tx(uint8_t data)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  while(inst::FSR::is_set(UART0::FSR::TX_FULL_1));
  inst::THR::set(data);
  return success;
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
  return events(inst::ISR::get());
}


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::uart
// ------------------------------------------------------------------------------------------------

