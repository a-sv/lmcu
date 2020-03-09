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
  jsw_start = 7 // JSWSTART
};

enum class inj_data_offset : uint32_t { defval = 0 };

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

  jeoc   = 1 << 0, // injected channels end of conversion
  awd    = 1 << 1, // analog watchdog
  eoc    = 1 << 2, // regular end of conversion
  jstart = 1 << 3, // injected channel start flag
  start  = 1 << 4  // regular channel start flag
};

template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::adc;

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
        inj_trig == adc::inj_trig::jsw_start
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
        inj_trig == adc::inj_trig::jsw_start
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

  static constexpr auto id = option::get<adc::id, _args...>();
  // Channel number
  static constexpr auto channel = option::get<adc::channel, _args...>();
  // Channel sample time
  static constexpr auto sample_time = option::get<adc::sample_time, _args...>(adc::sample_time::
                                                                              _239_5cyc);
  static_assert(!option::is_null<id>() && !option::is_null<channel>());
};

template<auto ..._args>
struct jchanel_config
{
  static constexpr auto dev_class = lmcu::dev_class::adc_injected_channel;

  static constexpr auto id = option::get<adc::id, _args...>();
  // Channel number
  static constexpr auto channel = option::get<adc::channel, _args...>();
  // Channel sample time
  static constexpr auto sample_time = option::get<adc::sample_time, _args...>(adc::sample_time::
                                                                              _239_5cyc);
  // Data offset
  static constexpr auto inj_data_offset = option::get_u<adc::inj_data_offset, _args...>(
                                            adc::inj_data_offset::defval);
  static_assert(!option::is_null<id>() && !option::is_null<channel>());
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
lmcu_inline void on()
{
  using namespace device;

  switch(_id)
  {
  case id::adc1: RCC::APB2ENR::set_b(RCC::APB2ENR::ADC1EN);  break;
  case id::adc2: RCC::APB2ENR::set_b(RCC::APB2ENR::ADC2EN);  break;
  case id::adc3: RCC::APB2ENR::set_b(RCC::APB2ENR::ADC3EN);  break;
  default: break;
  }

}

template<id _id>
lmcu_inline void off()
{
  using namespace device;

  switch(_id)
  {
  case id::adc1: RCC::APB2ENR::clr_b(RCC::APB2ENR::ADC1EN);  break;
  case id::adc2: RCC::APB2ENR::clr_b(RCC::APB2ENR::ADC2EN);  break;
  case id::adc3: RCC::APB2ENR::clr_b(RCC::APB2ENR::ADC3EN);  break;
  default: break;
  }

}

template<id _id>
lmcu_inline void reset()
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

template<typename ..._cfg>
void configure_adc()
{
  static auto _do = [](auto config)
  {
    using cfg = decltype(config);
    if constexpr(cfg::dev_class == dev_class::adc) {
      using inst = inst_t<cfg::id>;
      uint32_t r;

      r = 0;

      switch(cfg::awd_mode) {
      case awd_mode::all_injected:
        r |= inst::CR1::JAWDEN;
        break;
      case awd_mode::all_regular:
        r |= inst::CR1::AWDEN;
        break;
      case awd_mode::all_injected_and_regular:
        r |= (inst::CR1::AWDEN | inst::CR1::JAWDEN);
        break;
      case awd_mode::single_injected:
        r |= (inst::CR1::AWDSGL | inst::CR1::JAWDEN);
        break;
      case awd_mode::single_regular:
        r |= (inst::CR1::AWDSGL | inst::CR1::AWDEN);
        break;
      case awd_mode::single_regular_or_injected:
        r |= (inst::CR1::AWDSGL | inst::CR1::AWDEN | inst::CR1::JAWDEN);
        break;
      default: break;
      }

      switch(cfg::dual_mode)
      {
      case dual_mode::regular_and_injected:    r |= inst::CR1::DUALMOD_REG_INJ;        break;
      case dual_mode::regular_and_trigger:     r |= inst::CR1::DUALMOD_REG_ALT_TRIG;   break;
      case dual_mode::injected_and_fast_inter: r |= inst::CR1::DUALMOD_INJ_FAST_INTER; break;
      case dual_mode::injected_and_slow_inter: r |= inst::CR1::DUALMOD_INJ_SLOW_INTER; break;
      case dual_mode::injected_only:           r |= inst::CR1::DUALMOD_INJ_ONLY;       break;
      case dual_mode::regular_only:            r |= inst::CR1::DUALMOD_REG_ONLY;       break;
      case dual_mode::fast_inter_only:         r |= inst::CR1::DUALMOD_FAST_INTER;     break;
      case dual_mode::slow_inter_only:         r |= inst::CR1::DUALMOD_SLOW_INTER;     break;
      case dual_mode::trigger_only:            r |= inst::CR1::DUALMOD_ALT_TRIG;       break;
      default: break;
      }

      r |= uint32_t(cfg::discnum) << inst::CR1::DISCNUM_POS;

      if constexpr(cfg::disc_mode == disc_mode::regular) {
        r |= inst::CR1::DISCEN;
      }
      else
      if constexpr(cfg::disc_mode == disc_mode::injected) {
        r |= inst::CR1::JDISCEN;
      }
      else
      if constexpr(cfg::disc_mode == disc_mode::regular_injected) {
        r |= (inst::CR1::DISCEN | inst::CR1::JDISCEN);
      }

      if constexpr(cfg::inj_auto == inj_auto::enable) { r |= inst::CR1::JAUTO; }

      if constexpr(cfg::scan == scan::enable) { r |= inst::CR1::SCAN; }

      if constexpr(cfg::awd_mode != awd_mode::disable) {
        r |= uint32_t(cfg::awd_channel) << inst::CR1::AWDCH_POS;
      }

      if constexpr(!option::is_null<cfg::events>()) {
        r |= (uint32_t(cfg::events) & 7) << inst::CR1::JEOCIE_POS;
      }

      inst::CR1::set(r);

      r = 0;

      if constexpr(cfg::disc_mode == disc_mode::disable) { r |= inst::CR2::CONT; }
      if constexpr(cfg::temp_refint == temp_refint::enable) { r |= inst::CR2::TSVREFE; }

      if constexpr(cfg::reg_trig != reg_trig::disable) {
        r |= inst::CR2::EXTTRIG;
        r |= uint32_t(cfg::reg_trig) << inst::CR2::EXTSEL_POS;
      }

      if constexpr(cfg::inj_trig != inj_trig::disable) {
        r |= inst::CR2::JEXTTRIG;
        r |= uint32_t(cfg::inj_trig) << inst::CR2::JEXTSEL_POS;
      }

      if constexpr(cfg::data_align == data_align::left) { r |= inst::CR2::ALIGN; }

      if constexpr(cfg::dma == dma::enable) { r |= inst::CR2::DMA; }

      inst::CR2::set(r);

      if constexpr(cfg::awd_mode != awd_mode::disable) {
        inst::HTR::set( uint32_t(cfg::awd_hi_threshold) & inst::HTR::HTR_MASK );
        inst::LTR::set( uint32_t(cfg::awd_lo_threshold) & inst::LTR::LTR_MASK );
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
      if(r.n == 1) { r.jofr1 = cfg::inj_data_offset; } else
      if(r.n == 2) { r.jofr2 = cfg::inj_data_offset; } else
      if(r.n == 3) { r.jofr3 = cfg::inj_data_offset; } else
      if(r.n == 4) { r.jofr4 = cfg::inj_data_offset; }
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
  case 0:
    break;
    r.bits = (ch[0] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ4_MASK;
  case 1:
    r.bits = (ch[0] << ADC1::JSQR::JSQ3_POS) | (ch[1] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ3_MASK| ADC1::JSQR::JSQ4_MASK;
    break;
  case 2:
    r.bits = (ch[0] << ADC1::JSQR::JSQ2_POS) | (ch[1] << ADC1::JSQR::JSQ3_POS) |
             (ch[2] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ2_MASK | ADC1::JSQR::JSQ3_MASK | ADC1::JSQR::JSQ4_MASK;
    break;
  case 3:
    r.bits = (ch[0] << ADC1::JSQR::JSQ1_POS) | (ch[1] << ADC1::JSQR::JSQ2_POS) |
             (ch[2] << ADC1::JSQR::JSQ3_POS) | (ch[3] << ADC1::JSQR::JSQ4_POS);
    r.mask = ADC1::JSQR::JSQ1_MASK | ADC1::JSQR::JSQ2_MASK | ADC1::JSQR::JSQ3_MASK |
             ADC1::JSQR::JSQ4_MASK;
    break;
  default: break;
  }

  if(r.n > 0) {
    r.bits |= ((r.n - 1) << ADC1::JSQR::JL_POS);
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
void enable()
{
  static_assert(_cfg::dev_class == dev_class::adc);

  using inst = detail::inst_t<_cfg::id>;

  inst::CR2::set_b(inst::CR2::ADON);
  while((inst::CR2::get() & inst::CR2::ADON) == 0)
    ;

}

template<typename _cfg>
void disable()
{
  static_assert(_cfg::dev_class == dev_class::adc);

  using inst = detail::inst_t<_cfg::id>;

  inst::CR2::clr_b(inst::CR2::ADON);
  while((inst::CR2::get() & inst::CR2::ADON) != 0)
    ;
}

template<typename _cfg>
void calibrate()
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

template<typename _cfg>
void regular_soft_start()
{
  static_assert(_cfg::dev_class == dev_class::adc);
  using inst = detail::inst_t<_cfg::id>;

  inst::CR2::set_b(inst::CR2::SWSTART);
}

// ------------------------------------------------------------------------------------------------
} // namespace detail
// ------------------------------------------------------------------------------------------------

/**
 * @brief Enable clock on timer periph
 *
 * @tparam _ids - timer id list
*/
template<id ..._id>
lmcu_inline void on()
{
  static_assert(sizeof...(_id) > 0);
  (detail::on<_id>(), ...);
}

/**
 * @brief Disable clock on timer periph
 *
 * @tparam _ids - timer id list
*/
template<id ..._id>
lmcu_inline void off()
{
  static_assert(sizeof...(_id) > 0);
  (detail::off<_id>(), ...);
}

/**
 * @brief Reset adc periph
 *
 * @tparam _ids - adc id list
*/
template<id ..._id>
lmcu_inline void reset()
{
  static_assert(sizeof...(_id) > 0);
  (detail::reset<_id>(), ...);
}

template<typename ..._cfg>
void configure()
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

template<typename ..._cfg>
void enable()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::enable<_cfg>(), ...);
}

template<typename ..._cfg>
void disable()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::disable<_cfg>(), ...);
}

template<typename ..._cfg>
void calibrate()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::calibrate<_cfg>(), ...);
}

template<typename ..._cfg>
void regular_soft_start()
{
  static_assert(sizeof...(_cfg) > 0);
  (detail::regular_soft_start<_cfg>(), ...);
}

template<typename _cfg>
uint16_t read()
{
  using inst = detail::inst_t<_cfg::id>;
  return inst::DR::get();
}

} // namespace lmcu::adc
