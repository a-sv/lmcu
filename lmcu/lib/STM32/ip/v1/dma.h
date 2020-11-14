#pragma once
#include <lmcu/dev/dma>
#include <lmcu/dev/rcc>
#include <lmcu/irq>
#include <lmcu/common>

// ------------------------------------------------------------------------------------------------
namespace lmcu::dma {
// ------------------------------------------------------------------------------------------------
#include "../../../irq_id.h"

enum class id { dma1, dma2 };

enum class channel { _1,  _2,  _3,  _4,  _5,  _6,  _7 };

enum class direction
{
  mem_mem,    // Memory to memory
  mem_periph, // Memory to periph
  periph_mem  // Periph to memory
};

enum class priority { low, medium, high, very_high };

enum class msize { _8bit, _16bit, _32bit };

enum class psize { _8bit, _16bit, _32bit };

enum class minc { disable, enable };

enum class pinc { disable, enable };

enum class circ { disable, enable };

enum class periph_address : std::uintptr_t { };

enum class mem_address : std::uintptr_t { };

enum class count : uint16_t { };

enum class events : uint32_t
{
  lmcu_flags,

  tc = device::DMA1::ISR::TCIF1, // Transfer error interrupt
  ht = device::DMA1::ISR::HTIF1, // Half transfer interrupt
  te = device::DMA1::ISR::TEIF1, // Transfer complete interrupt
  gb = device::DMA1::ISR::GIF1   // Global interrupt
};

template <auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();

template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::dma;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto id = option::get<dma::id, _args...>();

  // DMA channel number
  static constexpr auto channel = option::get<dma::channel, _args...>();
  // Number of data to transfer
  static constexpr auto count = option::get_u<dma::count, _args...>();
  // DMA transfer direction
  static constexpr auto direction = option::get<dma::direction, _args...>(dma::direction::
                                                                          periph_mem);
  // Channel priority level
  static constexpr auto priority = option::get<dma::priority, _args...>(dma::priority::low);
  // Memory word size
  static constexpr auto msize = option::get<dma::msize, _args...>(dma::msize::_8bit);
  // Peripheral word size
  static constexpr auto psize = option::get<dma::psize, _args...>(dma::psize::_8bit);
  // Memory increment mode
  static constexpr auto minc = option::get<dma::minc, _args...>(dma::minc::disable);
  // Peripheral increment mode
  static constexpr auto pinc = option::get<dma::pinc, _args...>(dma::pinc::disable);
  // Circular mode
  static constexpr auto circ = option::get<dma::circ, _args...>(dma::circ::disable);
  // Periph address
  static constexpr auto periph_address = option::get_u<dma::periph_address, _args...>();
  // Memory address
  static constexpr auto mem_address = option::get_u<dma::mem_address, _args...>();
  // DMA interrupt events
  static constexpr auto events = option::get<dma::events, _args...>(dma::events(0));
  // DMA channel IRQ
  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(!(option::is_null<id>() || option::is_null<channel>()));

  static_assert(!(id == dma::id::dma2 && channel > dma::channel::_5), "DMA2 have only 5 channels");

  static_assert(option::check<
    std::tuple<
      dma::id,
      dma::channel,
      dma::count,
      dma::direction,
      dma::priority,
      dma::msize,
      dma::psize,
      dma::minc,
      dma::pinc,
      dma::circ,
      dma::periph_address,
      dma::mem_address,
      dma::events,
      irq_id::_0
    >,
    _args...
  >());
};

// ------------------------------------------------------------------------------------------------
namespace detail {
// ------------------------------------------------------------------------------------------------

template<id _id>
struct inst;

template<id _id>
using inst_t = typename inst<_id>::type;

template<>
struct inst<id::dma1> { using type = device::DMA1; };

template<>
struct inst<id::dma2> { using type = device::DMA2; };

template<id _id>
inline void on()
{
  using namespace device;

  switch(_id)
  {
  case id::dma1: RCC::AHBENR::set_b(RCC::AHBENR::DMA1EN); break;
  case id::dma2: RCC::AHBENR::set_b(RCC::AHBENR::DMA2EN); break;
  default: break;
  }
}

template<id _id>
inline void off()
{
  using namespace device;

  switch(_id)
  {
  case id::dma1: RCC::AHBENR::clr_b(RCC::AHBENR::DMA1EN); break;
  case id::dma2: RCC::AHBENR::clr_b(RCC::AHBENR::DMA2EN); break;
  default: break;
  }
}

template<typename _cfg>
inline void enable()
{
  static_assert(_cfg::dev_class == dev_class::dma);

  using inst = inst_t<_cfg::id>;
  inst::CCR::set_b(uint32_t(_cfg::channel), inst::CCR::EN);
}

template<typename _cfg>
inline void disable()
{
  static_assert(_cfg::dev_class == dev_class::dma);

  using inst = inst_t<_cfg::id>;
  inst::CCR::clr_b(uint32_t(_cfg::channel), inst::CCR::EN);
}

template<typename _cfg>
void configure()
{
  using inst = inst_t<_cfg::id>;

  constexpr uint32_t r = (
    (_cfg::direction == direction::mem_mem? inst::CCR::MEM2MEM | inst::CCR::DIR : 0) |
    (_cfg::direction == direction::mem_periph? inst::CCR::DIR : 0) |
    (uint32_t(_cfg::priority) << inst::CCR::PL_POS) |
    (uint32_t(_cfg::msize) << inst::CCR::MSIZE_POS) |
    (uint32_t(_cfg::psize) << inst::CCR::PSIZE_POS) |
    (_cfg::minc == minc::enable? inst::CCR::MINC : 0) |
    (_cfg::pinc == pinc::enable? inst::CCR::PINC : 0) |
    (_cfg::circ == circ::enable? inst::CCR::CIRC : 0) |
    (uint32_t(_cfg::events) & (inst::CCR::TEIE | inst::CCR::HTIE | inst::CCR::TCIE))
  );

  inst::CCR::set(uint32_t(_cfg::channel), r);

  if constexpr(!option::is_null<_cfg::count>()) {
    inst::CNDTR::set(_cfg::count);
  }

  if constexpr(!option::is_null<_cfg::periph_address>()) {
    inst::CPAR::set(uint32_t(_cfg::channel), _cfg::periph_address);
  }

  if constexpr(!option::is_null<_cfg::mem_address>()) {
    inst::CMAR::set(uint32_t(_cfg::channel), _cfg::mem_address);
  }

  if constexpr(!option::is_null<_cfg::irq>()) {
    constexpr auto irqn = []
    {
      if constexpr(_cfg::id == id::dma1) {
        switch(_cfg::channel)
        {
        case channel::_1: return device::find_irqn("dma1_channel1");
        case channel::_2: return device::find_irqn("dma1_channel2");
        case channel::_3: return device::find_irqn("dma1_channel3");
        case channel::_4: return device::find_irqn("dma1_channel4");
        case channel::_5: return device::find_irqn("dma1_channel5");
        case channel::_6: return device::find_irqn("dma1_channel6");
        case channel::_7: return device::find_irqn("dma1_channel7");
        default: break;
        }
      }
      else
      if constexpr(_cfg::id == id::dma2) {
        switch(_cfg::channel)
        {
        case channel::_1: return device::find_irqn("dma2_channel1");
        case channel::_2: return device::find_irqn("dma2_channel2");
        case channel::_3: return device::find_irqn("dma2_channel3");
        case channel::_4: return device::find_irqn("dma2_channel4");
        case channel::_5: return device::find_irqn("dma2_channel5");
        default: break;
        }
      }

      return device::irqn::invalid_irqn;
    }();

    nvic::set_encoded_priority<irqn, _cfg::irq>();
    nvic::enable_irq<irqn>();
  }
}

template<typename _cfg>
void set_events(events val)
{
  using inst = inst_t<_cfg::id>;
  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::TEIE | inst::CCR::HTIE | inst::CCR::TCIE,
                   uint32_t(val));
}

template<typename _cfg>
void clr_events(events val)
{
  using inst = inst_t<_cfg::id>;
  inst::IFCR::set(uint32_t(val) << (4 * uint32_t(_cfg::channel)));
}

template<typename _cfg>
void set_direction(direction val)
{
  using inst = inst_t<_cfg::id>;

  uint32_t r = 0;

  if(val == direction::mem_mem) {
    r |= inst::CCR::MEM2MEM | inst::CCR::DIR;
  }
  else
  if(val == direction::mem_periph) {
    r |= inst::CCR::DIR;
  }

  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::MEM2MEM | inst::CCR::DIR, r);
}

template<typename _cfg>
void set_count(uint16_t val)
{
  using inst = detail::inst_t<_cfg::id>;
  inst::CNDTR::set(uint32_t(_cfg::channel), val);
}

template<typename _cfg>
void set_priority(priority val)
{
  using inst = inst_t<_cfg::id>;
  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::PL_MASK, uint32_t(val) << inst::CCR::PL_POS);
}

template<typename _cfg>
void set_msize(msize val)
{
  using inst = inst_t<_cfg::id>;
  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::MSIZE_MASK, uint32_t(val) << inst::CCR::
                                                                                    MSIZE_POS);
}

template<typename _cfg>
void set_psize(psize val)
{
  using inst = inst_t<_cfg::id>;
  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::PSIZE_MASK, uint32_t(val) << inst::CCR::
                                                                                    PSIZE_POS);
}

template<typename _cfg>
void set_minc(minc val)
{
  using inst = inst_t<_cfg::id>;
  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::MINC_MASK,
                   val == minc::enable? inst::CCR::MINC : 0);
}

template<typename _cfg>
void set_pinc(pinc val)
{
  using inst = inst_t<_cfg::id>;
  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::PINC_MASK,
                   val == pinc::enable? inst::CCR::PINC : 0);
}

template<typename _cfg>
void set_circ(circ val)
{
  using inst = inst_t<_cfg::id>;
  inst::CCR::set_m(uint32_t(_cfg::channel), inst::CCR::CIRC_MASK,
                   val == circ::enable? inst::CCR::CIRC : 0);
}

// ------------------------------------------------------------------------------------------------
} // namespace detail
// ------------------------------------------------------------------------------------------------

/**
 * @brief Enable clock on periph.
 *
 * @tparam _id - periph id list.
*/
template<id ..._id>
lmcu_inline void on()
{
  static_assert(sizeof...(_id) > 0);
  (detail::on<_id>(), ...);
}

/**
 * @brief Disable clock on periph.
 *
 * @tparam _id - periph id list.
*/
template<id ..._id>
lmcu_inline void off()
{
  static_assert(sizeof...(_id) > 0);
  (detail::off<_id>(), ...);
}

/**
 * @brief Enable DMA channels.
 *
 * @tparam _cfg - list of DMA channels.
*/
template<typename ..._cfg>
lmcu_inline void enable()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::enable<_cfg>(), ...);
}

/**
 * @brief Disable DMA channels.
 *
 * @tparam _cfg - list of DMA channels.
*/
template<typename ..._cfg>
lmcu_inline void disable()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::disable<_cfg>(), ...);
}

/**
 * @brief Configure DMA channels.
 *
 * @tparam _cfg - list of DMA channel configs.
*/
template<typename ..._cfg>
lmcu_inline void configure()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::configure<_cfg>(), ...);
}

/**
 * @brief Set DMA transfer direction.
 *
 * @tparam _cfg - list of DMA channel configs.
 * @param val - transfer direction.
*/
template<typename ..._cfg>
lmcu_inline void set_direction(direction val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_direction<_cfg>(val), ...);
}

/**
 * @brief Get current DMA transfer direction.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline direction get_direction()
{
  using inst = detail::inst_t<_cfg::id>;

  uint32_t r = inst::CCR::get(uint32_t(_cfg::channel));

  if((r & inst::CCR::MEM2MEM) != 0) {
    return direction::mem_mem;
  }

  if((r & inst::CCR::DIR) != 0) {
    return direction::mem_periph;
  }

  return direction::periph_mem;
}

/**
 * @brief Set DMA transfer count.
 *
 * @tparam _cfg - list of DMA channel configs.
 * @param val - transfer count.
*/
template<typename ..._cfg>
lmcu_inline void set_count(uint16_t val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_count<_cfg>(val), ...);
}

/**
 * @brief Get current DMA transfer count.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline uint16_t get_count()
{
  using inst = detail::inst_t<_cfg::id>;
  return inst::CNDTR::get(uint32_t(_cfg::channel));;
}

/**
 * @brief Set DMA channel priority.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void set_priority(priority val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_priority<_cfg>(val), ...);
}

/**
 * @brief Get DMA channel priority.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline priority get_priority()
{
  using inst = detail::inst_t<_cfg::id>;
  return priority( (inst::CCR::get(uint32_t(_cfg::channel)) & inst::CCR::PL_MASK) >> inst::CCR::
                                                                                     PL_POS );
}

/**
 * @brief Set DMA memory word size.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void set_msize(msize val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_msize<_cfg>(val), ...);
}

/**
 * @brief Get DMA memory word size.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline msize get_msize()
{
  using inst = detail::inst_t<_cfg::id>;
  return msize( (inst::CCR::get(uint32_t(_cfg::channel)) & inst::CCR::MSIZE_MASK) >> inst::CCR::
                                                                                     MSIZE_POS );
}

/**
 * @brief Set DMA periph word size.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void set_psize(psize val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_psize<_cfg>(val), ...);
}

/**
 * @brief Get DMA periph word size.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline psize get_psize()
{
  using inst = detail::inst_t<_cfg::id>;
  return psize( (inst::CCR::get(uint32_t(_cfg::channel)) & inst::CCR::PSIZE_MASK) >> inst::CCR::
                                                                                     PSIZE_POS );
}

/**
 * @brief Set DMA memory increment.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void set_minc(minc val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_minc<_cfg>(val), ...);
}

/**
 * @brief Get DMA memory increment.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline minc get_minc()
{
  using inst = detail::inst_t<_cfg::id>;
  return inst::CCR::is_set(uint32_t(_cfg::channel), inst::CCR::MINC)? minc::enable : minc::disable;
}

/**
 * @brief Set DMA periph increment.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void set_pinc(pinc val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_pinc<_cfg>(val), ...);
}

/**
 * @brief Get DMA periph increment.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline pinc get_pinc()
{
  using inst = detail::inst_t<_cfg::id>;
  return inst::CCR::is_set(uint32_t(_cfg::channel), inst::CCR::PINC)? pinc::enable : pinc::disable;
}

/**
 * @brief Set DMA circular mode.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void set_circ(circ val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_circ<_cfg>(val), ...);
}

/**
 * @brief Get DMA circular mode.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline circ get_circ()
{
  using inst = detail::inst_t<_cfg::id>;
  return inst::CCR::is_set(uint32_t(_cfg::channel), inst::CCR::CIRC)? circ::enable : circ::disable;
}

/**
 * @brief Set DMA periph addres.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline void set_periph_address(std::uintptr_t val)
{
  using inst = detail::inst_t<_cfg::id>;
  inst::CPAR::set(uint32_t(_cfg::channel), val);
}

/**
 * @brief Get DMA periph addres.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline auto get_periph_address()
{
  using inst = detail::inst_t<_cfg::id>;
  return inst::CPAR::get(uint32_t(_cfg::channel));
}

/**
 * @brief Set DMA memory addres.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline void set_mem_address(std::uintptr_t val)
{
  using inst = detail::inst_t<_cfg::id>;
  inst::CMAR::set(uint32_t(_cfg::channel), val);
}

/**
 * @brief Get DMA memory addres.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline auto get_mem_address()
{
  using inst = detail::inst_t<_cfg::id>;
  return inst::CMAR::get(uint32_t(_cfg::channel));
}

/**
 * @brief Enable / disable events.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void set_events(events val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_events<_cfg>(val), ...);
}

/**
 * @brief Returns occured events.
 *
 * @tparam _cfg - DMA config.
*/
template<typename _cfg>
lmcu_inline events get_events()
{
  using inst = detail::inst_t<_cfg::id>;
  return events( (inst::ISR::get() >> (4 * uint32(_cfg::channel))) & 0xf );
}

/**
 * @brief Clear occured events.
 *
 * @tparam _cfg - list of DMA configs.
*/
template<typename ..._cfg>
lmcu_inline void clr_events(events val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::clr_events<_cfg>(val), ...);
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::dma
// ------------------------------------------------------------------------------------------------
