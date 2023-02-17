#pragma once
#include <lmcu/common>
#include <lmcu/dev/uart>
#include <lmcu/irq>
#include <lmcu/delay>

// ------------------------------------------------------------------------------------------------
namespace lmcu::uart {
// ------------------------------------------------------------------------------------------------
#include "../../irq_id.h"

enum class id { urt0, urt1, urt2, urt3, urt4, urt5, urt6, urt7 };

enum class data_size { _7bit, _8bit };

enum class mode { rx, tx, rxtx };

enum class stop_bits { _0_5, _1, _1_5, _2 };

enum class parity { disable, even, odd, high, space };

enum class clock { ahb, apb };

enum class baud : uint32_t { };

enum class events : uint32_t
{
  lmcu_flags,

  caltmo  = device::URT0::URT::STA::CALTMOF_HAPPENED,   // Baud rate calibration sync field receive time out flag
  bktmo   = device::URT0::URT::STA::BKTMOF_HAPPENED,    // Break receive time out flag
  idtmo   = device::URT0::URT::STA::IDTMOF_HAPPENED,    // Idle state time out flag
  rxtmo   = device::URT0::URT::STA::RXTMOF_HAPPENED,    // Receive time out flag
  txe     = device::URT0::URT::STA::TXEF_HAPPENED,      // TX error detect flag
  rovr    = device::URT0::URT::STA::ROVRF_HAPPENED,     // Receive overrun error flag
  nce     = device::URT0::URT::STA::NCEF_HAPPENED,      // Receive noised character error detect flag
  fe      = device::URT0::URT::STA::FEF_HAPPENED,       // Receive frame error detect flag
  pe      = device::URT0::URT::STA::PEF_HAPPENED,       // Receive parity error detect flag
  cts     = device::URT0::URT::STA::CTSF_HAPPENED,      // CTS change detect flag
  idl     = device::URT0::URT::STA::IDLF_HAPPENED,      // RX idle line detect flag
  bk      = device::URT0::URT::STA::BKF_HAPPENED,       // Break condition detect flag
  calov   = device::URT0::URT::STA::CALOVF_HAPPENED,    // Auto baud-rate calibration overflow status flag
  calud   = device::URT0::URT::STA::CALUDF_HAPPENED,    // Auto baud-rate calibration underflow status flag
  calc    = device::URT0::URT::STA::CALCF_HAPPENED,     // Auto baudrate calibration complete flag
  tmo     = device::URT0::URT::STA::TMOF_HAPPENED,      // Timeout timer timeout flag
  brt     = device::URT0::URT::STA::BRTF_HAPPENED,      // Baud rate generator timer timeout flag
  sadr    = device::URT0::URT::STA::SADRF_HAPPENED,     // Slave address matched flag
  tx      = device::URT0::URT::STA::TXF_HAPPENED,       // Transmit data register empty flag
  rx      = device::URT0::URT::STA::RXF_HAPPENED,       // Receive data register not empty flag
  ls      = device::URT0::URT::STA::LSF_HAPPENED,       // URT line status relationship flag
  err     = device::URT0::URT::STA::ERRF_HAPPENED,      // URT error relationship flag
  tc      = device::URT0::URT::STA::TCF_HAPPENED,       // Transmission complete flag (shadow buffer, data register, shift buffer empty)
  ug      = device::URT0::URT::STA::UGF_HAPPENED,       // URT genernal event relationship flag
  rhf     = device::URT0::URT::STA::RHF_HAPPENED,       // URT Receive Hold flag
};

template <auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();

template<id _id>
struct inst;

template<id _id>
using inst_t = typename inst<_id>::type;

template<>
struct inst<id::urt0> { using type = device::URT0; };

template<>
struct inst<id::urt1> { using type = device::URT1; };


template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::uart;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto id = option::get<uart::id, _args...>();

  static constexpr uint32_t baud = option::get_u<uart::baud, _args...>(uart::baud(9600));

  static constexpr auto mode = option::get<uart::mode, _args...>(uart::mode::rxtx);

  static constexpr auto data_size = option::get<uart::data_size, _args...>(uart::data_size::_8bit);

  static constexpr auto parity = option::get<uart::parity, _args...>(uart::parity::disable);

  static constexpr auto stop_bits = option::get<uart::stop_bits, _args...>(uart::stop_bits::_1);

  static constexpr auto clock = option::get<uart::clock, _args...>(uart::clock::apb);

  static constexpr auto events = option::get<uart::events, _args...>(uart::events(0));

  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(option::check<
    std::tuple<
      uart::id,
      uart::baud,
      uart::mode,
      uart::data_size,
      uart::parity,
      uart::stop_bits,
      uart::clock,
      uart::events,
      irq_id::_0
     >,
    _args...
  >());
};

template<typename _cfg>
lmcu_inline uint32_t get_clock_freq()
{
  if constexpr(_cfg::clock == clock::apb) { return rcc::clock::apb(); }
  else { return rcc::clock::ahb(); }
}

template<typename _cfg>
void configure()
{
  using namespace device;
  using inst = inst_t<_cfg::id>;

  CSC::KEY::set(0xA217);
  switch(_cfg::id)
  {
  case id::urt0:
    CSC::APB0::set_b(CSC::APB0::URT0_EN_ENABLE);
    if constexpr(_cfg::clock == clock::ahb) { CSC::CKS1::set_b(CSC::CKS1::URT0_CKS_CK_AHB); }
    break;
  case id::urt1:
    CSC::APB0::set_b(CSC::APB0::URT1_EN_ENABLE);
    if constexpr(_cfg::clock == clock::ahb) { CSC::CKS1::set_b(CSC::CKS1::URT1_CKS_CK_AHB); }
    break;
  default: break;
  }
  CSC::KEY::set(1111);

  // disable uart
  inst::URT::CR0::clr_b(URT0::URT::CR0::EN_MASK);

  // set communication params
  {
    inst::URT::CR1::clr_b(URT0::URT::CR1::TXSTP_LEN_MASK |
                          URT0::URT::CR1::TXPAR_STK_MASK |
                          URT0::URT::CR1::TXPAR_POL_MASK |
                          URT0::URT::CR1::TXPAR_EN_MASK |
                          URT0::URT::CR1::TXDSIZE_MASK |
                          URT0::URT::CR1::RXSTP_LEN_MASK |
                          URT0::URT::CR1::RXPAR_STK_MASK |
                          URT0::URT::CR1::RXPAR_POL_MASK |
                          URT0::URT::CR1::RXPAR_EN_MASK |
                          URT0::URT::CR1::RXDSIZE_MASK);

    if constexpr(_cfg::data_size == data_size::_7bit) { inst::URT::CR1::set_b(URT0::URT::CR1::TXDSIZE_7BIT); }

    if constexpr(_cfg::parity == parity::odd) { inst::URT::CR1::set_b(URT0::URT::CR1::RXPAR_POL_ODD); }

    switch(_cfg::stop_bits)
    {
    case stop_bits::_1: inst::URT::CR1::set_b(URT0::URT::CR1::TXSTP_LEN_1BIT); break;
    case stop_bits::_1_5: inst::URT::CR1::set_b(URT0::URT::CR1::TXSTP_LEN_1_5BIT); break;
    case stop_bits::_2: inst::URT::CR1::set_b(URT0::URT::CR1::TXSTP_LEN_2BIT); break;
    default: break;
    }
  }

  // set mode params
  {
    inst::URT::CR2::clr_b(URT0::URT::CR2::RX_EN_MASK | URT0::URT::CR2::TX_EN_MASK);
    switch(_cfg::mode)
    {
    case mode::rx: inst::URT::CR2::set_b(URT0::URT::CR2::RX_EN_ENABLE); break;
    case mode::tx: inst::URT::CR2::set_b(URT0::URT::CR2::TX_EN_ENABLE); break;
    case mode::rxtx: inst::URT::CR2::set_b(URT0::URT::CR2::RX_EN_ENABLE | URT0::URT::CR2::TX_EN_ENABLE); break;
    default: break;
    }
  }

  // hardware flow control
  {
    inst::URT::HFC::clr_b(URT0::URT::HFC::RTS_INV_MASK |
                          URT0::URT::HFC::CTS_INV_MASK |
                          URT0::URT::HFC::RTS_EN_MASK |
                          URT0::URT::HFC::CTS_EN_MASK);
    //TODO: hardware flow control
  }

  // onebit sampling method
  {
    inst::URT::CR0::clr_b(URT0::URT::CR0::OS_MDS_MASK);
    //TODO: onebit sampling method
  }

  // baud config
  {
     uint32_t uart_clk = get_clock_freq<_cfg>();
     uint32_t tmp = uart_clk / _cfg::baud; // result tmp must be >= 8
     if((uart_clk%_cfg::baud) > 4) { tmp += 1; }

     uint32_t oversampling = 0;
     uint32_t ovsmp;
     uint32_t rem;
     uint32_t sol = 0;

     /*for(ovsmp = 8; ovsmp < 32; ovsmp++) {
         rem = tmp % ovsmp;
         if(rem == 0) {
            if((tmp / ovsmp) < 4096) {
                oversampling = ovsmp;
                break;
            }
         }
         else {
             if((rem == 1)&&(ovsmp > 15)) {
                 oversampling = ovsmp;
                 sol = 48;
             }
             rem = ovsmp - rem;
             if((rem > sol)||(rem==sol)) {
                 sol = rem;
                 oversampling = ovsmp;
             }
         }
     }*/

    inst::URT::CLK::clr_b(URT0::URT::CLK::TX_CKS_MASK |
                          URT0::URT::CLK::RX_CKS_MASK |
                          URT0::URT::CLK::CK_SEL_MASK);

    //tmp = tmp / oversampling; // result tmp must be > 4096
    tmp = 13;
    inst::URT::RLR::set((tmp-1)&URT0::URT::RLR::RLRVAL_MASK);

    oversampling = 11;
    oversampling = oversampling-1;
    inst::URT::CR1::set_b((oversampling<<URT0::URT::CR1::RXOS_NUM_POS)&URT0::URT::CR1::RXOS_NUM_MASK);
    inst::URT::CR1::set_b((oversampling<<URT0::URT::CR1::TXOS_NUM_MASK)&URT0::URT::CR1::TXOS_NUM_MASK);
  }

  inst::URT::CR4::clr_b(URT0::URT::CR4::TNUM_MASK);
  inst::URT::CR4::set_b(URT0::URT::CR4::TNUM_1);

  inst::URT::CLK::set_b(URT0::URT::CLK::BR_MDS_COMBINED | URT0::URT::CLK::BR_EN_ENABLE);

  // async mode
  inst::URT::CLK::clr_b(URT0::URT::CLK::CLK_EN_ENABLE);
  inst::URT::IRDA::clr_b(URT0::URT::IRDA::IR_EN_ENABLE);
  inst::URT::CR0::clr_b(URT0::URT::CR0::MDS_MASK |
                        URT0::URT::CR0::HDX_EN_MASK |
                        URT0::URT::CR0::DAT_LINE_MASK);

  inst::URT::MUTE::clr_b(URT0::URT::MUTE::MUTE_EN_ENABLE);

  // clear TX/RX buffer
  inst::URT::CR4::set_b(URT0::URT::CR4::TDAT_CLR_MASK | URT0::URT::CR4::RDAT_CLR_MASK);
#if defined(LMCU_MG32F0_1ST)
  inst::URT::MUTE::clr_b(URT0::URT::MUTE::MUTE_EN_ENABLE);
#endif

  // clear flags
  inst::URT::STA::set_b(URT0::URT::STA::TCF_HAPPENED |
                        URT0::URT::STA::RXF_HAPPENED |
                        URT0::URT::STA::FEF_HAPPENED |
                        URT0::URT::STA::NCEF_HAPPENED |
                        URT0::URT::STA::ROVRF_HAPPENED |
                        URT0::URT::STA::RHF_HAPPENED);

  // TODO: enable events
  inst::INT::set_b(URT0::INT::IEA_ENABLE);

  if(flags::all(_cfg::events, uart::events::rx)) { inst::INT::set_b(URT0::INT::RX_IE_ENABLE); }

  // enable uart
  inst::URT::CR0::set_b(URT0::URT::CR0::EN_ENABLE);

  if constexpr(!option::is_null<_cfg::irq>()) {
    constexpr auto irqn = []
    {
      switch(_cfg::id)
      {
      case id::urt0: return device::find_irqn("urt0");
      case id::urt1: return device::find_irqn("urt123");
      case id::urt2: return device::find_irqn("urt123");
      case id::urt3: return device::find_irqn("urt123");
      case id::urt4: return device::find_irqn("urt4x");
      default: break;
      }
      return device::irqn::invalid_irqn;
    }();

    nvic::set_encoded_priority<irqn, _cfg::irq>();
    nvic::enable_irq<irqn>();
  }
}

template<typename _cfg>
lmcu_inline int tx(uint8_t data)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::TDAT8::set(data);
  while((inst::STA::get() & URT0::URT::STA::TXF_HAPPENED) == 0);
  return success;
}

/*
template<typename _cfg>
lmcu_inline int tx(uint16_t data)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::TDAT16::set(data);
  return success;
}

template<typename _cfg>
lmcu_inline int tx(uint32_t data)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::TDAT32::set(data);
  return success;
}*/

/**
 * @brief Returns occured events.
 *
 * @tparam _cfg - UART config.
*/
template<typename _cfg>
lmcu_inline events get_events()
{
  using inst = inst_t<_cfg::id>;
  return events(inst::STA::get());
}

template<typename _cfg>
lmcu_inline void clr_events(events val)
{
  using namespace device;
  using inst = inst_t<_cfg::id>;
  inst::STA::set(uint32_t(val));
}
// ------------------------------------------------------------------------------------------------
} // namespace lmcu::uart
// ------------------------------------------------------------------------------------------------
