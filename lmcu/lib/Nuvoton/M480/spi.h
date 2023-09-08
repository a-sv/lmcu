#pragma once
#include <lmcu/common>
#include <lmcu/dev/spi>
#include <lmcu/irq>
#include <lmcu/delay>

// ------------------------------------------------------------------------------------------------
namespace lmcu::spi {
// ------------------------------------------------------------------------------------------------
#include "../../irq_id.h"

enum class id { spi0, spi1, spi2, spi3 };

enum class clk_mux { hirc, pclk, pll, hxt };

enum class type { master, slave };

enum class mode { _0, _1, _2, _3 };

enum class width {
  _8   = 8,
  _9   = 9,
  _10  = 10,
  _11  = 11,
  _12  = 12,
  _13  = 13,
  _14  = 14,
  _15  = 15,
  _16  = 16,
  _17  = 17,
  _18  = 18,
  _19  = 19,
  _20  = 20,
  _21  = 21,
  _22  = 22,
  _23  = 23,
  _24  = 24,
  _25  = 25,
  _26  = 26,
  _27  = 27,
  _28  = 28,
  _29  = 29,
  _30  = 30,
  _31  = 31,
  _32  = 32
};

enum class events : uint32_t
{
  lmcu_flags,

/*  unit      = 0x0001, // Unit transfer interrupt
  ssact     = 0x0002, // Slave selection signal active interrupt
  ssinact   = 0x0004, // Slave selection signal inactive interrupt
  slvur     = 0x0008, // Slave TX under run interrupt
  slvbe     = 0x0010, // Slave bit count error interrupt
  txuf      = 0x0040, // Slave TX underflow interrupt
  fifo_txth = 0x0080, // TX threshold interrupt
  fifo_rxth = 0x0100, // RX threshold interrupt
  fifo_rxov = 0x0200, // RX overrun interrupt
  fifo_rxto = 0x0400, // RX time-out interrupt*/

  unit      = device::SPI0::STATUS::UNITIF_1,  // Unit transfer interrupt
  ssact     = device::SPI0::STATUS::SSACTIF_1, // Slave selection signal active interrupt
  ssinact   = device::SPI0::STATUS::SSINAIF_1, // Slave selection signal inactive interrupt
  slvur     = device::SPI0::STATUS::SLVURIF_1, // Slave TX under run interrupt
  slvbe     = device::SPI0::STATUS::SLVBEIF_1, // Slave bit count error interrupt
  txuf      = device::SPI0::STATUS::TXUFIF_1,  // Slave TX underflow interrupt
  fifo_txth = device::SPI0::STATUS::TXTHIF_1,  // TX threshold interrupt
  fifo_rxth = device::SPI0::STATUS::RXTHIF_1,  // RX threshold interrupt
  fifo_rxov = device::SPI0::STATUS::RXOVIF_1,  // RX overrun interrupt
  fifo_rxto = device::SPI0::STATUS::RXTOIF_1,  // RX time-out interrupt
};

enum class dma { disable, rx, tx, rxtx };


template <auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();

template<id _id>
struct inst;

template<id _id>
using inst_t = typename inst<_id>::type;

template<>
struct inst<id::spi0> { using type = device::SPI0; };

template<>
struct inst<id::spi1> { using type = device::SPI1; };

template<>
struct inst<id::spi2> { using type = device::SPI2; };

template<>
struct inst<id::spi3> { using type = device::SPI3; };


template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::spi;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto id = option::get<spi::id, _args...>();

  static constexpr auto clk_mux = option::get<spi::clk_mux, _args...>(spi::clk_mux::hirc);

  static constexpr auto type = option::get<spi::type, _args...>(spi::type::master);

  static constexpr auto mode = option::get<spi::mode, _args...>(spi::mode::_0);

  static constexpr auto width = option::get<spi::width, _args...>(spi::width::_8);

  static constexpr auto events = option::get<spi::events, _args...>(spi::events(0));

  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(option::check<
    std::tuple<
      spi::id,
      spi::clk_mux,
      spi::type,
      spi::mode,
      spi::width,
      spi::events,
      irq_id::_0>,
    _args...
  >());
};

template<typename _cfg>
void configure()
{
  using namespace device;
  using inst = inst_t<_cfg::id>;

  {
    switch(_cfg::id)
    {
    case id::spi0: CLK::APBCLK0::set_b(CLK::APBCLK0::SPI0CKEN_1); break;
    case id::spi1: CLK::APBCLK0::set_b(CLK::APBCLK0::SPI1CKEN_1); break;
    case id::spi2: CLK::APBCLK0::set_b(CLK::APBCLK0::SPI2CKEN_1); break;
    case id::spi3: CLK::APBCLK1::set_b(CLK::APBCLK1::SPI3CKEN_1); break;
    default: break;
    }

    // disable I2S mode
    inst::I2SCTL::clr_b(SPI0::I2SCTL::I2SEN_1);
  }

  {
    if(_cfg::type == type::master) {

    }
    else { // slave
      inst::SSCTL::set(0);

      uint32_t mode_mask = 0;
      switch(_cfg::mode)
      {
      case mode::_0: mode_mask = SPI0::CTL::TXNEG_1; break; // CLKPOL=0; RXNEG=0; TXNEG=1
      case mode::_1: mode_mask = SPI0::CTL::RXNEG_1; break; // CLKPOL=0; RXNEG=1; TXNEG=0
      case mode::_2: mode_mask = SPI0::CTL::CLKPOL_1 | SPI0::CTL::RXNEG_1; break; // CLKPOL=1; RXNEG=1; TXNEG=0
      case mode::_3: mode_mask = SPI0::CTL::CLKPOL_1 | SPI0::CTL::TXNEG_1; break; // CLKPOL=1; RXNEG=0; TXNEG=1
      default: break;
      }

      inst::CTL::set(SPI0::CTL::SLAVE_1 | (uint8_t(_cfg::width) << SPI0::CTL::DWIDTH_POS) | mode_mask | SPI0::CTL::SPIEN_1);

      inst::CLKDIV::set(0); // Set DIVIDER = 0

      // Select the clock source
      uint32_t cm = 0;
      switch(_cfg::clk_mux)
      {
      case clk_mux::hirc: cm = 3; break;
      case clk_mux::pclk: cm = 2; break;
      case clk_mux::pll:  cm = 1; break;
      default: break;
      }

      if(_cfg::id == id::spi0) {
        uint32_t t = (CLK::CLKSEL2::get() & ~CLK::CLKSEL2::SPI0SEL_MASK) | (cm << CLK::CLKSEL2::SPI0SEL_POS);
        CLK::CLKSEL2::set(t);
      }
      else if(_cfg::id == id::spi1) {
        uint32_t t = (CLK::CLKSEL2::get() & ~CLK::CLKSEL2::SPI1SEL_MASK) | (cm << CLK::CLKSEL2::SPI1SEL_POS);
        CLK::CLKSEL2::set(t);
      }
      else if(_cfg::id == id::spi2) {
        uint32_t t = (CLK::CLKSEL2::get() & ~CLK::CLKSEL2::SPI2SEL_MASK) | (cm << CLK::CLKSEL2::SPI2SEL_POS);
        CLK::CLKSEL2::set(t);
      }
      else if(_cfg::id == id::spi3) {
        uint32_t t = (CLK::CLKSEL2::get() & ~CLK::CLKSEL2::SPI3SEL_MASK) | (cm << CLK::CLKSEL2::SPI3SEL_POS);
        CLK::CLKSEL2::set(t);
      }
    }
  }

  inst::FIFOCTL::clr_b(SPI0::FIFOCTL::TXTH_MASK);


  // int
  {
    if(flags::all(_cfg::events, spi::events::unit)) {
      inst::CTL::set_b(SPI0::CTL::UNITIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::ssact)) {
      inst::SSCTL::set_b(SPI0::SSCTL::SSACTIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::ssinact)) {
      inst::SSCTL::set_b(SPI0::SSCTL::SSINAIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::slvur)) {
      inst::SSCTL::set_b(SPI0::SSCTL::SLVURIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::slvbe)) {
      inst::SSCTL::set_b(SPI0::SSCTL::SLVBEIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::txuf)) {
      inst::FIFOCTL::set_b(SPI0::FIFOCTL::TXUFIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::fifo_txth)) {
      inst::FIFOCTL::set_b(SPI0::FIFOCTL::TXTHIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::fifo_rxth)) {
      inst::FIFOCTL::set_b(SPI0::FIFOCTL::RXTHIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::fifo_rxov)) {
      inst::FIFOCTL::set_b(SPI0::FIFOCTL::RXOVIEN_MASK);
    }

    if(flags::all(_cfg::events, spi::events::fifo_rxto)) {
      inst::FIFOCTL::set_b(SPI0::FIFOCTL::RXTOIEN_MASK);
    }
  }

  // irq
  {
    if constexpr(!option::is_null<_cfg::irq>()) {
      constexpr auto irqn = []
      {
        switch(_cfg::id)
        {
        case id::spi0: return device::find_irqn("spi0");
        case id::spi1: return device::find_irqn("spi1");
        case id::spi2: return device::find_irqn("spi2");
        case id::spi3: return device::find_irqn("spi3");
        default: break;
        }
        return device::irqn::invalid_irqn;
      }();

      nvic::set_encoded_priority<irqn, _cfg::irq>();
      nvic::enable_irq<irqn>();
    }
  }
}

template<typename _cfg>
lmcu_inline void dma_reset()
{
  using namespace device;
  //using inst = inst_t<_cfg::id>;
  //inst::PDMACTL::set_b(SPI0::PDMACTL::PDMARST_1);
  //inst::PDMACTL::CHRST =
}

template<typename _cfg>
lmcu_inline void dma_mode(dma d)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::PDMACTL::set_b(SPI0::PDMACTL::PDMARST_1);

  if(d == dma::rx) { inst::PDMACTL::set_b(SPI0::PDMACTL::RXPDMAEN_1); }
  else if(d == dma::tx) { inst::PDMACTL::set_b(SPI0::PDMACTL::TXPDMAEN_1); }
  else if(d == dma::rxtx) {
    inst::PDMACTL::set_b(SPI0::PDMACTL::RXPDMAEN_1 | SPI0::PDMACTL::TXPDMAEN_1);
  }
  else {
    inst::PDMACTL::clr_b(SPI0::PDMACTL::RXPDMAEN_1 | SPI0::PDMACTL::TXPDMAEN_1);
  }


}

template<typename _cfg>
lmcu_inline uint32_t tx_data_addr()
{
  //using namespace device;
  using inst = inst_t<_cfg::id>;
  return inst::TX::base;
}

template<typename _cfg>
lmcu_inline uint32_t rx_data_addr()
{
  //using namespace device;
  using inst = inst_t<_cfg::id>;
  return inst::RX::base;
}

template<typename _cfg>
lmcu_inline void tx_reset()
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::FIFOCTL::set_b(SPI0::FIFOCTL::TXRST_1);
  while(inst::FIFOCTL::is_set(SPI0::FIFOCTL::TXRST_1));
}

template<typename _cfg>
lmcu_inline int rx(uint32_t &data)
{
  using inst = inst_t<_cfg::id>;
  data = inst::RX::get();
  return success;
}

template<typename _cfg>
lmcu_inline int tx(uint32_t data)
{
  using inst = inst_t<_cfg::id>;
  inst::TX::set(data);
  return success;
}

template<typename _cfg>
lmcu_inline events get_events()
{
  //using namespace device;
  using inst = inst_t<_cfg::id>;
  //uint32_t ev = 0;

  return events(inst::STATUS::get());
}

template<typename _cfg>
lmcu_inline void clr_events(events val)
{
  //using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::STATUS::set(uint32_t(val));
}

// ------------------------------------------------------------------------------------------------




// ------------------------------------------------------------------------------------------------
} // namespace lmcu::spi
// ------------------------------------------------------------------------------------------------

