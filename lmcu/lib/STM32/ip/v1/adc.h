#pragma once
#include <lmcu/dev/adc>
#include <lmcu/dev/rcc>
#include <lmcu/irq>
#include <lmcu/common>
#include <lmcu/delay>

namespace lmcu::adc {

enum class id { adc1, adc2, adc3 };

enum class awd_mode
{
  disable,
  all_injected,
  all_regular,
  all_injected_and_regular,
  single_injected,
  single_regular,
  single_regular_or_injected
};

enum class channel {
  _0,  _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,
  _9, _10, _11, _12, _13, _14, _15, _16, _17
};

enum class dual_mode
{
  independent,
  regular_and_injected,
  regular_and_trigger,
  injected_and_fast_inter,
  injected_and_slow_inter,
  injected_only,
  regular_only,
  fast_inter_only,
  slow_inter_only,
  trigger_only
};

enum class disc_mode { disable, single, regular, injected, regular_injected };

enum class discnum { _1, _2, _3, _4, _5, _6, _7, _8 };

enum class inj_auto { disable, enable };

enum class scan { disable, enable };

enum class temp_refint { disable, enable };

enum class reg_trig
{
  disable  = 8,
  tim1_cc1 = 0, // Timer 1 CC1 event
  tim1_cc2 = 1, // Timer 1 CC2 event
  tim1_cc3 = 2, // Timer 1 CC3 event
  tim2_cc2 = 3, // Timer 2 CC2 event
  tim3_trgo = 4, // Timer 3 TRGO event
  tim4_cc4 = 5, // Timer 4 CC4 event
  exti11__tim8_trgo = 6, // EXTI line 11/TIM8_TRGO event
  tim3_cc1 = 0, // Timer 3 CC1 event
  tim2_cc3 = 1, // Timer 2 CC3 event
  tim8_cc1 = 3, // Timer 8 CC1 event
  tim8_trgo = 4, // Timer 8 TRGO event
  tim5_cc1 = 5, // Timer 5 CC1 event
  tim5_cc3 = 6, // Timer 5 CC3 event
  sw_start = 7 // SWSTART
};

enum class inj_trig
{
  disable = 8,
  tim1_trgo = 0, // Timer 1 TRGO event
  tim1_cc4 = 1, // Timer 1 CC4 event
  tim2_trgo = 2, // Timer 2 TRGO event
  tim2_cc1 = 3, // Timer 2 CC1 event
  tim3_cc4 = 4, // Timer 3 CC4 event
  tim4_trgo = 5, // Timer 4 TRGO event
  exti15__tim8_cc4 = 6, // EXTI line15/TIM8_CC4 event
  tim4_cc3 = 2, // Timer 4 CC3 event
  tim8_cc2 = 3, //  Timer 8 CC2 event
  tim8_cc4 = 4, // Timer 8 CC4 event
  tim5_trgo = 5, // Timer 5 TRGO event
  tim5_cc4 = 6, // Timer 5 CC4 event
  sw_start = 7 // JSWSTART
};

enum class data_offset : uint32_t { defval = 0 };

enum class data_align { left, right };

enum class dma { disable, enable };

enum class awd_lo_threshold { defval = 0x0 };

enum class awd_hi_threshold { defval = 0xfff };

enum class sample_time
{
  _1_5cyc,
  _7_5cyc,
  _13_5cyc,
  _28_5cyc,
  _41_5cyc,
  _55_5cyc,
  _71_5cyc,
  _239_5cyc
};

enum class events : uint32_t
{
  lmcu_flags,

  awd    = 1 << 0, // analog watchdog
  eoc    = 1 << 1, // regular end of conversion
  jeoc   = 1 << 2, // injected channels end of conversion
  jstart = 1 << 3, // injected channel start flag
  start  = 1 << 4  // regular channel start flag
};

template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::adc;

  static constexpr auto ip_version = lmcu::ip_version::_1;

  static constexpr auto id = option::get<adc::id, _args...>();

  // Analog wachdog config
  static constexpr auto awd_mode = option::get<adc::awd_mode, _args...>(adc::awd_mode::disable);
  // Analog watchdog channel
  static constexpr auto awd_channel = option::get<adc::channel, _args...>(adc::channel::_0);
  // Analog watchdog low threshold
  static constexpr auto awd_lo_threshold = option::get<adc::awd_lo_threshold, _args...>(
                                             adc::awd_lo_threshold::defval);
  // Analog watchdog high threshold
  static constexpr auto awd_hi_threshold = option::get<adc::awd_hi_threshold, _args...>(
                                             adc::awd_hi_threshold::defval);
  // Dual mode selection
  static constexpr auto dual_mode = option::get<adc::dual_mode, _args...>(adc::dual_mode::
                                                                          independent);
  // Discontinuous mode config
  static constexpr auto disc_mode = option::get<adc::disc_mode, _args...>(adc::disc_mode::disable);
  // Discontinuous mode channel count
  static constexpr auto discnum = option::get<adc::discnum, _args...>(adc::discnum::_1);
  // Automatic injected group conversion
  static constexpr auto inj_auto = option::get<adc::inj_auto, _args...>(adc::inj_auto::disable);
  // Scan mode
  static constexpr auto scan = option::get<adc::scan, _args...>(adc::scan::disable);
  // Temperature sensor and VREFINT enable
  static constexpr auto temp_refint = option::get<adc::temp_refint, _args...>(adc::temp_refint::
                                                                              disable);
  // External trigger select for regular group
  static constexpr auto reg_trig = option::get<adc::reg_trig, _args...>(adc::reg_trig::sw_start);
  // External trigger event for injected group
  static constexpr auto inj_trig = option::get<adc::inj_trig, _args...>(adc::inj_trig::disable);
    // Data alignment
  static constexpr auto data_align = option::get<adc::data_align, _args...>(adc::data_align::right);
  // DMA enable
  static constexpr auto dma = option::get<adc::dma, _args...>(adc::dma::disable);
  // Events config
  static constexpr auto events = option::get<adc::events, _args...>(adc::events(0));

  static_assert(!option::is_null<id>());

  static_assert([]
  {
    if constexpr(id == adc::id::adc3) {
      // External events for ADC3
      return
        reg_trig == adc::reg_trig::disable ||
        reg_trig == adc::reg_trig::tim3_cc1 ||
        reg_trig == adc::reg_trig::tim2_cc3 ||
        reg_trig == adc::reg_trig::tim1_cc3 ||
        reg_trig == adc::reg_trig::tim8_cc1 ||
        reg_trig == adc::reg_trig::tim8_trgo ||
        reg_trig == adc::reg_trig::tim5_cc1 ||
        reg_trig == adc::reg_trig::tim5_cc3 ||
        reg_trig == adc::reg_trig::sw_start
      ;
    }
    else {
      // External events for ADC1, ADC2
      return
        reg_trig == adc::reg_trig::disable ||
        reg_trig == adc::reg_trig::tim1_cc1 ||
        reg_trig == adc::reg_trig::tim1_cc2 ||
        reg_trig == adc::reg_trig::tim1_cc3 ||
        reg_trig == adc::reg_trig::tim2_cc2 ||
        reg_trig == adc::reg_trig::tim3_trgo ||
        reg_trig == adc::reg_trig::tim4_cc4 ||
        reg_trig == adc::reg_trig::exti11__tim8_trgo ||
        reg_trig == adc::reg_trig::sw_start
      ;
    }
  }());

  static_assert([]
  {
    if constexpr(id == adc::id::adc3) {
      // External events for ADC3
      return
        inj_trig == adc::inj_trig::disable ||
        inj_trig == adc::inj_trig::tim1_trgo ||
        inj_trig == adc::inj_trig::tim1_cc4 ||
        inj_trig == adc::inj_trig::tim4_cc3 ||
        inj_trig == adc::inj_trig::tim8_cc2 ||
        inj_trig == adc::inj_trig::tim8_cc4 ||
        inj_trig == adc::inj_trig::tim5_trgo ||
        inj_trig == adc::inj_trig::tim5_cc4 ||
        inj_trig == adc::inj_trig::sw_start
      ;
    }
    else {
      // External events for ADC1, ADC2
      return
        inj_trig == adc::inj_trig::disable ||
        inj_trig == adc::inj_trig::tim1_trgo ||
        inj_trig == adc::inj_trig::tim1_cc4 ||
        inj_trig == adc::inj_trig::tim2_trgo ||
        inj_trig == adc::inj_trig::tim2_cc1 ||
        inj_trig == adc::inj_trig::tim3_cc4 ||
        inj_trig == adc::inj_trig::tim4_trgo ||
        inj_trig == adc::inj_trig::exti15__tim8_cc4 ||
        inj_trig == adc::inj_trig::sw_start
      ;
    }
  }());

  static_assert(option::check<
    std::tuple<
      adc::id,
      adc::awd_mode,
      adc::channel,
      adc::awd_lo_threshold,
      adc::awd_hi_threshold,
      adc::dual_mode,
      adc::disc_mode,
      adc::discnum,
      adc::inj_auto,
      adc::scan,
      adc::temp_refint,
      adc::reg_trig,
      adc::inj_trig,
      adc::data_align,
      adc::dma,
      adc::events
    >,
    _args...
  >());
};

template<auto ..._args>
struct rchanel_config
{
  static constexpr auto dev_class = lmcu::dev_class::adc_regular_channel;

  static constexpr auto ip_version = lmcu::ip_version::_1;

  static constexpr auto id = option::get<adc::id, _args...>();
  // Channel number
  static constexpr auto channel = option::get<adc::channel, _args...>();
  // Channel sample time
  static constexpr auto sample_time = option::get<adc::sample_time, _args...>(adc::sample_time::
                                                                              _239_5cyc);
  static_assert(!option::is_null<id>() && !option::is_null<channel>());

  static_assert(option::check<
    std::tuple<
      adc::id,
      adc::channel,
      adc::sample_time
    >,
  _args...
  >());
};

template<auto ..._args>
struct jchanel_config
{
  static constexpr auto dev_class = lmcu::dev_class::adc_injected_channel;

  static constexpr auto ip_version = lmcu::ip_version::_1;

  static constexpr auto id = option::get<adc::id, _args...>();
  // Channel number
  static constexpr auto channel = option::get<adc::channel, _args...>();
  // Channel sample time
  static constexpr auto sample_time = option::get<adc::sample_time, _args...>(adc::sample_time::
                                                                              _239_5cyc);
  // Data offset
  static constexpr auto data_offset = option::get_u<adc::data_offset, _args...>(adc::data_offset::
                                                                                defval);
  static_assert(!option::is_null<id>() && !option::is_null<channel>());

  static_assert(option::check<
    std::tuple<
      adc::id,
      adc::channel,
      adc::sample_time,
      adc::data_offset
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
struct inst<id::adc1> { using type = device::ADC1; };

template<>
struct inst<id::adc2> { using type = device::ADC2; };

template<>
struct inst<id::adc3> { using type = device::ADC3; };

template<id _id>
inline void on()
{
  using namespace device;

  switch(_id)
  {
  case id::adc1: RCC::APB2ENR::set_b(RCC::APB2ENR::ADC1EN); break;
  case id::adc2: RCC::APB2ENR::set_b(RCC::APB2ENR::ADC2EN); break;
  case id::adc3: RCC::APB2ENR::set_b(RCC::APB2ENR::ADC3EN); break;
  default: break;
  }
}

template<id _id>
inline void off()
{
  using namespace device;

  switch(_id)
  {
  case id::adc1: RCC::APB2ENR::clr_b(RCC::APB2ENR::ADC1EN); break;
  case id::adc2: RCC::APB2ENR::clr_b(RCC::APB2ENR::ADC2EN); break;
  case id::adc3: RCC::APB2ENR::clr_b(RCC::APB2ENR::ADC3EN); break;
  default: break;
  }
}

template<id _id>
inline void reset()
{
  using namespace device;

  switch(_id)
  {
  case id::adc1:
    RCC::APB2RSTR::set_b(RCC::APB2RSTR::ADC1RST);
    RCC::APB2RSTR::clr_b(RCC::APB2RSTR::ADC1RST);
    break;
  case id::adc2:
    RCC::APB2RSTR::set_b(RCC::APB2RSTR::ADC2RST);
    RCC::APB2RSTR::clr_b(RCC::APB2RSTR::ADC2RST);
    break;
  case id::adc3:
    RCC::APB2RSTR::set_b(RCC::APB2RSTR::ADC3RST);
    RCC::APB2RSTR::clr_b(RCC::APB2RSTR::ADC3RST);
    break;
  default: break;
  }
}

template<typename _inst, typename _reg>
constexpr inline void awd_mode_conf(awd_mode val, _reg&& r)
{
  r &= ~(_inst::CR1::JAWDEN | _inst::CR1::AWDEN | _inst::CR1::AWDSGL);

  switch(val) {
  case awd_mode::all_injected:
    r |= _inst::CR1::JAWDEN;
    break;
  case awd_mode::all_regular:
    r |= _inst::CR1::AWDEN;
    break;
  case awd_mode::all_injected_and_regular:
    r |= (_inst::CR1::AWDEN | _inst::CR1::JAWDEN);
    break;
  case awd_mode::single_injected:
    r |= (_inst::CR1::AWDSGL | _inst::CR1::JAWDEN);
    break;
  case awd_mode::single_regular:
    r |= (_inst::CR1::AWDSGL | _inst::CR1::AWDEN);
    break;
  case awd_mode::single_regular_or_injected:
    r |= (_inst::CR1::AWDSGL | _inst::CR1::AWDEN | _inst::CR1::JAWDEN);
    break;
  default: break;
  }
}

template<typename _inst, typename _reg>
constexpr inline void awd_channel_conf(channel val, _reg&& r)
{
  r &= ~_inst::CR1::AWDCH_MASK;
  r |= uint32_t(val) << _inst::CR1::AWDCH_POS;
}

template<typename _inst>
constexpr inline void awd_lo_threshold_conf(uint32_t val)
{ _inst::LTR::set(val & _inst::LTR::LTR_MASK); }

template<typename _inst>
constexpr inline void awd_hi_threshold_conf(uint32_t val)
{ _inst::HTR::set(val & _inst::HTR::HTR_MASK); }

template<typename _inst, typename _reg>
constexpr inline void dual_mode_conf(dual_mode val, _reg&& r)
{
  r &= ~_inst::CR1::DUALMOD_MASK;
  r |= uint32_t(val) << _inst::CR1::DUALMOD_POS;
}

template<typename _inst, typename _reg>
constexpr inline void disc_mode_conf(disc_mode val, _reg&& cr1, _reg&& cr2)
{
  cr1 &= ~(_inst::CR1::DISCEN | _inst::CR1::JDISCEN);
  cr2 &= ~_inst::CR2::CONT;

  if(val == disc_mode::regular) {
    cr1 |= _inst::CR1::DISCEN;
  }
  else
  if(val == disc_mode::injected) {
    cr1 |= _inst::CR1::JDISCEN;
  }
  else
  if(val == disc_mode::regular_injected) {
    cr1 |= (_inst::CR1::DISCEN | _inst::CR1::JDISCEN);
  }
  else
  if(val == disc_mode::disable) {
    cr2 |= _inst::CR2::CONT;
  }
}

template<typename _inst, typename _reg>
constexpr inline void discnum_conf(discnum val, _reg&& r)
{
  r &= ~_inst::CR1::DISCNUM_MASK;
  r |= uint32_t(val) << _inst::CR1::DISCNUM_POS;
}

template<typename _inst, typename _reg>
constexpr inline void inj_auto_conf(inj_auto val, _reg&& r)
{
  if(val == inj_auto::enable) {
    r |= _inst::CR1::JAUTO;
  }
  else {
    r &= ~_inst::CR1::JAUTO;
  }
}

template<typename _inst, typename _reg>
constexpr inline void scan_conf(scan val, _reg&& r)
{
  if(val == scan::enable) {
    r |= _inst::CR1::SCAN;
  }
  else {
    r &= ~_inst::CR1::SCAN;
  }
}

template<typename _inst, typename _reg>
constexpr inline void reg_trig_conf(reg_trig val, _reg&& r)
{
  if(val == reg_trig::disable) {
    r &= ~_inst::CR2::EXTTRIG;
  }
  else {
    r |= _inst::CR2::EXTTRIG;
    r &= ~_inst::CR2::EXTSEL_MASK;
    r |= uint32_t(val) << _inst::CR2::EXTSEL_POS;
  }
}

template<typename _inst, typename _reg>
constexpr inline void inj_trig_conf(inj_trig val, _reg&& r)
{
  if(val == inj_trig::disable) {
    r &= ~_inst::CR2::JEXTTRIG;
  }
  else {
    r |= _inst::CR2::JEXTTRIG;
    r &= ~_inst::CR2::JEXTSEL_MASK;
    r |= uint32_t(val) << _inst::CR2::JEXTSEL_POS;
  }
}

template<typename _inst, typename _reg>
constexpr inline void temp_refint_conf(temp_refint val, _reg&& r)
{
  if(val == temp_refint::enable) {
    r |= _inst::CR2::TSVREFE;
  }
  else {
    r &= ~_inst::CR2::TSVREFE;
  }
}

template<typename _inst, typename _reg>
constexpr inline void data_align_conf(data_align val, _reg&& r)
{
  if(val == data_align::left) {
    r |= _inst::CR2::ALIGN;
  }
  else {
    r &= ~_inst::CR2::ALIGN;
  }
}

template<typename _inst, typename _reg>
constexpr inline void dma_conf(dma val, _reg&& r)
{
  if(val == dma::enable) {
    r |= _inst::CR2::DMA;
  }
  else {
    r &= ~_inst::CR2::DMA;
  }
}

template<typename _inst, typename _reg>
constexpr inline void events_conf(events val, _reg&& r)
{
  uint32_t evt = 0;

  if(flags::all(val, events::jeoc)) { evt |= _inst::CR1::JEOCIE; }
  if(flags::all(val, events::awd))  { evt |= _inst::CR1::AWDIE;  }
  if(flags::all(val, events::eoc))  { evt |= _inst::CR1::EOCIE;  }

  r &= ~_inst::CR1::JEOCIE_MASK;
  r |= evt;
}

template<typename ..._cfg>
void configure_adc()
{
  static auto _do = [](auto config)
  {
    using cfg = decltype(config);
    if constexpr(cfg::dev_class == dev_class::adc) {
      using inst = inst_t<cfg::id>;

      constexpr auto r = []
      {
        struct
        {
          uint32_t cr1 = 0, cr2 = 0;
        } r;

        awd_mode_conf<inst>(cfg::awd_mode, r.cr1);
        dual_mode_conf<inst>(cfg::dual_mode, r.cr1);
        disc_mode_conf<inst>(cfg::disc_mode, r.cr1, r.cr2);
        discnum_conf<inst>(cfg::discnum, r.cr1);
        inj_auto_conf<inst>(cfg::inj_auto, r.cr1);
        scan_conf<inst>(cfg::scan, r.cr1);
        awd_channel_conf<inst>(cfg::awd_channel, r.cr1);

        if constexpr(!option::is_null<cfg::events>()) {
          events_conf<inst>(cfg::events, r.cr1);
        }

        reg_trig_conf<inst>(cfg::reg_trig, r.cr2);
        inj_trig_conf<inst>(cfg::inj_trig, r.cr2);
        temp_refint_conf<inst>(cfg::temp_refint, r.cr2);
        data_align_conf<inst>(cfg::data_align, r.cr2);
        dma_conf<inst>(cfg::dma, r.cr2);

        return r;
      }();

      inst::CR1::set(r.cr1);
      inst::CR2::set(r.cr2);

      if constexpr(cfg::awd_mode != awd_mode::disable) {
        awd_hi_threshold_conf<inst>(uint32_t(cfg::awd_hi_threshold));
        awd_lo_threshold_conf<inst>(uint32_t(cfg::awd_lo_threshold));
      }
    }
  };

  (_do(_cfg{}), ...);
}

template<id _id, uint32_t _lo, uint32_t _hi, typename ..._cfg>
constexpr auto smpr()
{
  struct
  {
    uint32_t mask = 0, bits = 0;
  } r;

  auto _do = [&](auto config)
  {
    using cfg = decltype(config);
    if constexpr(
      cfg::dev_class == dev_class::adc_regular_channel ||
      cfg::dev_class == dev_class::adc_injected_channel
    ) {
      auto ch_n = uint32_t(cfg::channel);

      if(_id == cfg::id && ch_n >= _lo && ch_n <= _hi) {
        auto ofs = (ch_n - _lo) * 3;
        r.bits |= uint32_t(cfg::sample_time) << ofs;
        r.mask |= 0b111UL << ofs;
      }
    }
  };

  (_do(_cfg{}), ...);
  return r;
}

template<id _id, typename ..._cfg>
constexpr auto jofr()
{
  struct
  {
    uint32_t jofr1 = 0, jofr2 = 0, jofr3 = 0, jofr4 = 0, n = 0;
  } r;

  auto _do = [&](auto config)
  {
    using cfg  = decltype(config);

    if constexpr(_id == cfg::id && cfg::dev_class == dev_class::adc_injected_channel) {
      r.n++;
      if(r.n == 1) { r.jofr1 = cfg::data_offset; } else
      if(r.n == 2) { r.jofr2 = cfg::data_offset; } else
      if(r.n == 3) { r.jofr3 = cfg::data_offset; } else
      if(r.n == 4) { r.jofr4 = cfg::data_offset; }
    }
  };

  (_do(_cfg{}), ...);
  return r;
}

template<id _id, typename ..._cfg>
constexpr auto sqr()
{
  struct
  {
    uint32_t
    sqr1 = 0,
    sqr1_mask = 0,
    sqr2 = 0,
    sqr2_mask = 0,
    sqr3 = 0,
    sqr3_mask = 0,
    n = 0
    ;
  } r;

  auto _do = [&](auto config)
  {
    using cfg  = decltype(config);

    if constexpr(_id == cfg::id && cfg::dev_class == dev_class::adc_regular_channel) {
      auto ch_n = uint32_t(cfg::channel);
      r.n++;
      if(r.n >= 1 && r.n <= 6) {
        auto ofs     = (r.n - 1) * 5;
        r.sqr3      |= ch_n << ofs;
        r.sqr3_mask |= 0b11111UL << ofs;
      }
      else
      if(r.n >= 7 && r.n <= 12) {
        auto ofs     = (r.n - 7) * 5;
        r.sqr2      |= ch_n << ofs;
        r.sqr2_mask |= 0b11111UL << ofs;
      }
      else
      if(r.n >= 13 && r.n <= 16) {
        auto ofs     = (r.n - 13) * 5;
        r.sqr1      |= ch_n << ofs;
        r.sqr1_mask |= 0b11111UL << ofs;
      }
    }
  };

  if(r.n > 0) {
    r.sqr1      |= (r.n - 1) << device::ADC1::SQR1::L_POS;
    r.sqr1_mask |= device::ADC1::SQR1::L_MASK;
  }

  (_do(_cfg{}), ...);
  return r;
}

template<id _id, typename ..._cfg>
constexpr auto jsqr()
{
  using namespace device;

  struct
  {
    uint32_t mask = 0, bits = 0, n = 0;
  } r;

  uint32_t ch[4] = {0, 0, 0, 0};

  auto _do = [&](auto config)
  {
    using cfg  = decltype(config);

    if constexpr(_id == cfg::id && cfg::dev_class == dev_class::adc_injected_channel) {
      if(r.n < 4) { ch[r.n] = uint32_t(cfg::channel); }
      r.n++;
    }
  };

  (_do(_cfg{}), ...);

  switch(r.n)
  {
  case 1:
    r.bits = (ch[0] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ4_MASK;
    break;
  case 2:
    r.bits = (ch[0] << ADC1::JSQR::JSQ3_POS) | (ch[1] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ3_MASK| ADC1::JSQR::JSQ4_MASK;
    break;
  case 3:
    r.bits = (ch[0] << ADC1::JSQR::JSQ2_POS) | (ch[1] << ADC1::JSQR::JSQ3_POS) |
             (ch[2] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ2_MASK | ADC1::JSQR::JSQ3_MASK | ADC1::JSQR::JSQ4_MASK;
    break;
  case 4:
    r.bits = (ch[0] << ADC1::JSQR::JSQ1_POS) | (ch[1] << ADC1::JSQR::JSQ2_POS) |
             (ch[2] << ADC1::JSQR::JSQ3_POS) | (ch[3] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ1_MASK | ADC1::JSQR::JSQ2_MASK | ADC1::JSQR::JSQ3_MASK |
             ADC1::JSQR::JSQ4_MASK;
    break;
  default: break;
  }

  if(r.n > 0) {
    r.bits |= (r.n - 1) << ADC1::JSQR::JL_POS;
    r.mask |= ADC1::JSQR::JL_MASK;
  }

  return r;
}

template<id _id, typename ..._cfg>
void configure_reg_channel()
{
  using inst = inst_t<_id>;

  {
    constexpr auto r = smpr<_id, 10, 17, _cfg...>();
    if constexpr(r.mask != 0) { inst::SMPR1::set(r.bits); }
  }

  {
    constexpr auto r = smpr<_id, 0, 9, _cfg...>();
    if constexpr(r.mask != 0) { inst::SMPR2::set(r.bits); }
  }

  {
    constexpr auto r = sqr<_id, _cfg...>();
    static_assert(r.n < 16, "regular sequence must not be longer than 16 channels");

    if constexpr(r.sqr1_mask != 0) { inst::SQR1::set(r.sqr1); }
    if constexpr(r.sqr2_mask != 0) { inst::SQR2::set(r.sqr2); }
    if constexpr(r.sqr3_mask != 0) { inst::SQR3::set(r.sqr3); }
  }
}

template<id _id, typename ..._cfg>
void configure_inj_channel()
{
  using inst = inst_t<_id>;

  {
    constexpr auto r = jofr<_id, _cfg...>();
    static_assert(r.n < 5, "injected sequence must not have more than 4 channels");

    if constexpr(r.n == 4) { inst::JOFR4::set(r.jofr4); }
    if constexpr(r.n == 3) { inst::JOFR3::set(r.jofr3); }
    if constexpr(r.n == 2) { inst::JOFR2::set(r.jofr2); }
    if constexpr(r.n == 1) { inst::JOFR1::set(r.jofr1); }
  }

  {
    constexpr auto r = jsqr<_id, _cfg...>();
    if constexpr(r.mask != 0) { inst::JSQR::set(r.bits); }
  }
}

template<typename _cfg>
inline void enable()
{
  static_assert(_cfg::dev_class == dev_class::adc);

  using inst = detail::inst_t<_cfg::id>;

  inst::CR2::set_b(inst::CR2::ADON);
  while((inst::CR2::get() & inst::CR2::ADON) == 0)
    ;

}

template<typename _cfg>
inline void disable()
{
  static_assert(_cfg::dev_class == dev_class::adc);

  using inst = detail::inst_t<_cfg::id>;

  inst::CR2::clr_b(inst::CR2::ADON);
  while((inst::CR2::get() & inst::CR2::ADON) != 0)
    ;
}

template<typename _cfg>
inline void calibrate()
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  disable<_cfg>();

  // wait 2 ADC cycles
  delay::cyc((rcc::clock::hardware() / rcc::clock::adc()) * 2);

  enable<_cfg>();

  // reset calibration
  inst::CR2::clr_b(inst::CR2::RSTCAL);
  while((inst::CR2::get() & inst::CR2::RSTCAL) != 0)
    ;

  // start calibration
  inst::CR2::set_b(inst::CR2::CAL);
  while((inst::CR2::get() & inst::CR2::CAL) != 0)
    ;
}

template<typename _cfg, bool _inj>
inline void soft_start()
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  if constexpr(_inj) {
    inst::CR2::set_b(inst::CR2::JSWSTART);
  }
  else {
    inst::CR2::set_b(inst::CR2::SWSTART);
  }
}

template<typename _cfg>
inline void set_awd_mode(awd_mode val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  awd_mode_conf<inst>(val, inst::CR1::ref());
}

template<typename _cfg>
inline void set_awd_channel(channel val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  awd_channel_conf(val, inst::CR1::ref());
}

template<typename _cfg>
inline void set_awd_lo_threshold(uint32_t val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  awd_lo_threshold_conf<inst>(val);
}

template<typename _cfg>
inline void set_awd_hi_threshold(uint32_t val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  awd_hi_threshold_conf<inst>(val);
}

template<typename _cfg>
inline void set_dual_mode(dual_mode val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  dual_mode_conf<inst>(val, inst::CR1::ref());
}

template<typename _cfg>
inline void set_disc_mode(disc_mode val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  disc_mode_conf<inst>(val);
}

template<typename _cfg>
inline void set_discnum(discnum val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  discnum_conf<inst>(val, inst::CR1::ref());
}

template<typename _cfg>
inline void set_inj_auto(inj_auto val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  inj_auto_conf<inst>(val, inst::CR1::ref());
}

template<typename _cfg>
inline void set_temp_refint(temp_refint val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  temp_refint_conf<inst>(val, inst::CR2::ref());
}

template<typename _cfg>
inline void set_scan(scan val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  scan_conf<inst>(val, inst::CR1::ref());
}

template<typename _cfg>
inline void set_reg_trig(reg_trig val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  reg_trig_conf<inst>(val, inst::CR2::ref());
}

template<typename _cfg>
inline void set_inj_trig(inj_trig val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  inj_trig_conf<inst>(val, inst::CR2::ref());
}

template<typename _cfg>
inline void set_data_align(data_align val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  data_align_conf<inst>(val, inst::CR2::ref());
}

template<typename _cfg>
inline void set_dma(dma val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  dma_conf<inst>(val, inst::CR2::ref());
}

template<typename _cfg>
inline void set_events(events val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  events_conf<inst>(val, inst::CR1::ref());
}

template<typename _cfg>
inline void clr_events(events val)
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  inst::SR::set( (~uint32_t(val)) & 0x1f );
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
 * @brief Reset periph.
 *
 * @tparam _id - periph id list.
*/
template<id ..._id>
lmcu_inline void reset()
{
  static_assert(sizeof...(_id) > 0);
  (detail::reset<_id>(), ...);
}

/**
 * @brief Configure ADC and channels.
 *
 * @tparam _cfg - list of ADC and channel configs.
*/
template<typename ..._cfg>
lmcu_inline void configure()
{
  static_assert(sizeof...(_cfg) > 0);
  detail::configure_adc<_cfg...>();
  detail::configure_reg_channel<id::adc1, _cfg...>();
  detail::configure_reg_channel<id::adc2, _cfg...>();
  detail::configure_reg_channel<id::adc3, _cfg...>();
  detail::configure_inj_channel<id::adc1, _cfg...>();
  detail::configure_inj_channel<id::adc2, _cfg...>();
  detail::configure_inj_channel<id::adc3, _cfg...>();
}

/**
 * @brief Enable A/D converter.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
lmcu_inline void enable()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::enable<_cfg>(), ...);
}

/**
 * @brief Disable A/D converter.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
lmcu_inline void disable()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::disable<_cfg>(), ...);
}

/**
 * @brief Perform A/D converter calibration.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
lmcu_inline void calibrate()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::calibrate<_cfg>(), ...);
}

/**
 * @brief Starts A/D conversion on regular channels if 'reg_trig' parameter is 'sw_start'.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
lmcu_inline void regular_soft_start()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::soft_start<_cfg, false>(), ...);
}

/**
 * @brief Starts A/D conversion on injected channels if 'inj_trig' parameter is 'sw_start'.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
lmcu_inline void injected_soft_start()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::soft_start<_cfg, true>(), ...);
}

/**
 * @brief Reads value from ADC data register (first regular channel).
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline uint16_t read() { return detail::inst_t<_cfg::id>::DR::get(); }

/**
 * @brief Reads value from ADC injected data register 1.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline uint16_t jread_1() { return detail::inst_t<_cfg::id>::JDR1::get(); }

/**
 * @brief Reads value from ADC injected data register 2.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline uint16_t jread_2() { return detail::inst_t<_cfg::id>::JDR2::get(); }

/**
 * @brief Reads value from ADC injected data register 3.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline uint16_t jread_3() { return detail::inst_t<_cfg::id>::JDR3::get(); }

/**
 * @brief Reads value from ADC injected data register 4.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline uint16_t jread_4() { return detail::inst_t<_cfg::id>::JDR4::get(); }

/**
 * @brief Returns address of data register for DMA.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline auto dma_address() { return detail::inst_t<_cfg::id>::DR::base; }

/**
 * @brief Set analog wachdog mode.
 *
 * @tparam _cfg - list of ADC configs.
 * @param val   - analog wachdog mode.
*/
template<typename ..._cfg>
lmcu_inline void set_awd_mode(awd_mode val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_awd_mode<_cfg>(val), ...);
}

/**
 * @brief Get analog wachdog mode.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
awd_mode get_awd_mode()
{
  using inst = detail::inst_t<_cfg::id>;

  auto r = inst::CR1::get() & (inst::CR1::JAWDEN | inst::CR1::AWDEN | inst::CR1::AWDSGL);

  if(r == inst::CR1::JAWDEN) { return awd_mode::all_injected; }

  if(r == inst::CR1::AWDEN) { return awd_mode::all_regular; }

  if(r == (inst::CR1::AWDEN | inst::CR1::JAWDEN)) { return awd_mode::all_injected_and_regular; }

  if(r == (inst::CR1::AWDSGL | inst::CR1::JAWDEN)) { return awd_mode::single_injected; }

  if(r == (inst::CR1::AWDSGL | inst::CR1::AWDEN)) { return awd_mode::single_regular; }

  if(r == (inst::CR1::AWDSGL | inst::CR1::AWDEN | inst::CR1::JAWDEN)) {
    return awd_mode::single_regular_or_injected;
  }

  return awd_mode::disable;
}

/**
 * @brief Set analog wachdog channel.
 *
 * @tparam _cfg - list of ADC configs.
 * @param val   - channel number.
*/
template<typename ..._cfg>
lmcu_inline void set_awd_channel(channel val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_awd_channel<_cfg>(val), ...);
}

/**
 * @brief Get analog wachdog channel.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
channel get_awd_channel()
{
  using inst = detail::inst_t<_cfg::id>;
  return channel((inst::CR1::get() & inst::CR1::AWDCH_MASK) >> inst::CR1::AWDCH_POS);
}

/**
 * @brief Set analog wachdog low threshold.
 *
 * @tparam _cfg - list of ADC configs.
 * @param val   - threshold.
*/
template<typename ..._cfg>
lmcu_inline void set_awd_lo_threshold(uint32_t val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_awd_lo_threshold<_cfg>(val), ...);
}

/**
 * @brief Returns analog wachdog low threshold.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename _cfg>
lmcu_inline uint32_t get_awd_lo_threshold() { return detail::inst_t<_cfg::id>::LTR::get(); }

/**
 * @brief Set analog wachdog high threshold.
 *
 * @tparam _cfg - list of ADC configs.
 * @param val   - threshold.
*/
template<typename ..._cfg>
lmcu_inline void set_awd_hi_threshold(uint32_t val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_awd_hi_threshold<_cfg>(val), ...);
}

/**
 * @brief Returns analog wachdog high threshold.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename _cfg>
lmcu_inline uint32_t get_awd_hi_threshold() { return detail::inst_t<_cfg::id>::HTR::get(); }

/**
 * @brief Set ADC dual mode.
 *
 * @tparam _cfg - list of ADC configs.
 * @param val   - dual mode.
*/
template<typename ..._cfg>
lmcu_inline void set_dual_mode(dual_mode val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_dual_mode<_cfg>(val), ...);
}

/**
 * @brief Returns ADC dual mode.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline dual_mode get_dual_mode()
{
  using inst = detail::inst_t<_cfg::id>;
  return dual_mode((inst::CR1::get() & inst::CR1::DUALMOD_MASK) >> inst::CR1::DUALMOD_POS);
}

/**
 * @brief Set ADC discontinuous mode.
 *
 * @tparam _cfg - list of ADC configs.
 * @param val   - discontinuous mode.
*/
template<typename ..._cfg>
lmcu_inline void set_disc_mode(disc_mode val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_disc_mode<_cfg>(val), ...);
}

/**
 * @brief Returns ADC discontinuous mode.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
lmcu_inline disc_mode get_disc_mode()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR1::get() & (inst::CR1::DISCEN | inst::CR1::JDISCEN);

  if(r == inst::CR1::DISCEN) { return disc_mode::regular; }
  if(r == inst::CR1::JDISCEN) { return disc_mode::injected; }
  if(r == (inst::CR1::DISCEN | inst::CR1::JDISCEN)) { return disc_mode::regular_injected; }
}

/**
 * @brief Set discontinuous mode channel count.
 *
 * @tparam _cfg - list of ADC configs.
 * @param val   - channel count.
*/
template<typename ..._cfg>
void set_discnum(discnum val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_discnum<_cfg>(val), ...);
}

/**
 * @brief Returns discontinuous mode channel count.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
discnum get_discnum()
{
  using inst = detail::inst_t<_cfg::id>;
  return discnum((inst::CR1::get() & inst::CR1::DISCNUM_MASK) >> inst::CR1::DISCNUM_POS);
}

/**
 * @brief Set automatic injected group conversion.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_inj_auto(inj_auto val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_inj_auto<_cfg>(val), ...);
}

/**
 * @brief Returns automatic injected group conversion status.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
inj_auto get_inj_auto()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR1::get() & inst::CR1::JAUTO;
  return r == 0? inj_auto::disable : inj_auto::enable;
}

/**
 * @brief Set scan mode.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_scan(scan val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_scan<_cfg>(val), ...);
}

/**
 * @brief Returns scan mode.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
scan get_scan()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR1::get() & inst::CR1::SCAN;
  return r == 0? scan::disable : scan::enable;
}

/**
 * @brief Temperature sensor and VREFINT enable.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_temp_refint(temp_refint val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_temp_refint<_cfg>(val), ...);
}

/**
 * @brief Returns temperature sensor and VREFINT status.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
temp_refint get_temp_refint()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR2::get() & inst::CR2::TSVREFE;
  return r == 0? temp_refint::disable : temp_refint::enable;
}

/**
 * @brief External trigger select for regular group.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_reg_trig(reg_trig val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_reg_trig<_cfg>(val), ...);
}

/**
 * @brief Returns external trigger for regular group.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
reg_trig get_reg_trig()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR2::get() & inst::CR2::EXTSEL_MASK;
  return reg_trig(r >> inst::CR2::EXTSEL_POS);
}

/**
 * @brief External trigger select for injected group.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_inj_trig(inj_trig val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_inj_trig<_cfg>(val), ...);
}

/**
 * @brief Returns external trigger for injected group.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
inj_trig get_inj_trig()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR2::get() & inst::CR2::JEXTSEL_MASK;
  return inj_trig(r >> inst::CR2::JEXTSEL_POS);
}

/**
 * @brief Set data align for conversion result.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_data_align(data_align val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_data_align<_cfg>(val), ...);
}

/**
 * @brief Returns data align of conversion result.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
data_align get_data_align()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR2::get() & inst::CR2::ALIGN;
  return r == 0? data_align::right : data_align::left;
}

/**
 * @brief Enable / disable dma.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_dma(dma val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_dma<_cfg>(val), ...);
}

/**
 * @brief Returns dma enable status.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
dma get_dma()
{
  using inst = detail::inst_t<_cfg::id>;
  auto r = inst::CR2::get() & inst::CR2::DMA;
  return r == 0? dma::disable : dma::enable;
}

/**
 * @brief Enable / disable events.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void set_events(events val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::set_events<_cfg>(val), ...);
}

/**
 * @brief Returns occured events.
 *
 * @tparam _cfg - ADC config.
*/
template<typename _cfg>
events get_events()
{
  using inst = detail::inst_t<_cfg::id>;
  return events(inst::SR);
}

/**
 * @brief Clear occured events.
 *
 * @tparam _cfg - list of ADC configs.
*/
template<typename ..._cfg>
void clr_events(events val)
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::clr_events<_cfg>(val), ...);
}

} // namespace lmcu::adc
