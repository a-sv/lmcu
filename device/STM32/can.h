#pragma once
#include <lmcu/device>
#include "../../common/delay/expirable.h"
#include "../../common/def.h"
#include "../../common/io.h"

namespace lmcu::can {

enum class module_id
{
#if defined(CAN1)
  can1,
#endif

#if defined(CAN2)
  can2,
#endif

#if defined(CAN3)
  can3
#endif
};

enum class mode
{
  normal,
  loopback,
  silent,
  silent_loopback
};

enum class sjw
{
  _1tq,
  _2tq,
  _3tq,
  _4tq
};

enum class bs1
{
  _1tq,
  _2tq,
  _3tq,
  _4tq,
  _5tq,
  _6tq,
  _7tq,
  _8tq,
  _9tq,
  _10tq,
  _11tq,
  _12tq,
  _13tq,
  _14tq,
  _15tq,
  _16tq
};

enum class bs2
{
  _1tq,
  _2tq,
  _3tq,
  _4tq,
  _5tq,
  _6tq,
  _7tq,
  _8tq
};

enum class ttcm { enable, disable };
enum class abom { enable, disable };
enum class awum { enable, disable };
enum class nart { enable, disable };
enum class rflm { enable, disable };
enum class txfp { enable, disable };

namespace nvic {

enum class irq_type { disable, tx, rx0, rx1, sce };

constexpr auto default_prio_group = 3;

} // namespace nvic
#include "../cortex/nvic.h"

template<
  module_id _module_id,
  uint32_t _prediv,
  sjw _sjw,
  bs1 _bs1,
  bs2 _bs2,
  ttcm _ttcm,
  abom _abom,
  awum _awum,
  nart _nart,
  rflm _rflm,
  txfp _txfp,
  mode _mode = mode::normal,
  typename _irq0 = nvic::irq<nvic::irq_type::disable>,
  typename _irq1 = nvic::irq<nvic::irq_type::disable>,
  typename _irq2 = nvic::irq<nvic::irq_type::disable>,
  typename _irq3 = nvic::irq<nvic::irq_type::disable>
>
struct module
{
  static constexpr auto module_id = _module_id;
  static constexpr auto prediv    = _prediv;
  static constexpr auto sjw       = _sjw;
  static constexpr auto bs1       = _bs1;
  static constexpr auto bs2       = _bs2;
  static constexpr auto ttcm      = _ttcm;
  static constexpr auto abom      = _abom;
  static constexpr auto awum      = _awum;
  static constexpr auto nart      = _nart;
  static constexpr auto rflm      = _rflm;
  static constexpr auto txfp      = _txfp;
  static constexpr auto mode      = _mode;
  static constexpr auto irq0      = _irq0();
  static constexpr auto irq1      = _irq1();
  static constexpr auto irq2      = _irq2();
  static constexpr auto irq3      = _irq3();
};

enum class fifo { any, fifo_0, fifo_1 };

enum class filter_mode { idmask, idlist };
enum class filter_scale { _16bit, _32bit };

template<
  uint32_t _number,
  filter_mode _filter_mode,
  filter_scale _filter_scale,
  fifo _fifo,
  uint32_t _bank_num
>
struct filter
{
  static constexpr auto number       = _number;
  static constexpr auto filter_mode  = _filter_mode;
  static constexpr auto filter_scale = _filter_scale;
  static constexpr auto fifo         = _fifo;
  static constexpr auto bank_num     = _bank_num;
};

enum class event
{
  tme   = 1 << 0,  // transmit mailbox empty
  fmp_0 = 1 << 1,  // FIFO 0 message pending
  ff_0  = 1 << 2,  // FIFO 0 full
  fov_0 = 1 << 3,  // FIFO 0 overrun
  fmp_1 = 1 << 4,  // FIFO 1 message pending
  ff_1  = 1 << 5,  // FIFO 1 full
  fov_1 = 1 << 6,  // FIFO 1 overrun
  wku   = 1 << 7,  // wake-up
  slk   = 1 << 8,  // sleep acknowledge
  ewg   = 1 << 9,  // error warning
  epv   = 1 << 10, // error passive
  bof   = 1 << 11, // bus-off
  lec   = 1 << 12, // last error code
  err   = 1 << 13  // error
};
lmcu_enum_class_flags_impl(event)

enum class flags : uint32_t
{
  rqcp_0 = 1 << 0,  // request MailBox0 Flag
  rqcp_1 = 1 << 1,  // request MailBox1 Flag
  rqcp_2 = 1 << 2,  // request MailBox2 Flag
  txok_0 = 1 << 3,  // transmission OK MailBox0 Flag
  txok_1 = 1 << 4,  // transmission OK MailBox1 Flag
  txok_2 = 1 << 5,  // transmission OK MailBox2 Flag
  tme_0  = 1 << 6,  // transmit mailbox 0 empty Flag
  tme_1  = 1 << 7,  // transmit mailbox 1 empty Flag
  tme_2  = 1 << 8,  // transmit mailbox 2 empty Flag
  fmp_0  = 1 << 9,  // FIFO 0 Message Pending Flag
  ff_0   = 1 << 10, // FIFO 0 Full Flag
  fov_0  = 1 << 11, // FIFO 0 Overrun Flag
  fmp_1  = 1 << 12, // FIFO 1 Message Pending Flag
  ff_1   = 1 << 13, // FIFO 1 Full Flag
  fov_1  = 1 << 14, // FIFO 1 Overrun Flag
  wku    = 1 << 15, // wake up Flag
  slaki  = 1 << 16  // sleep acknowledge Flag
};
lmcu_enum_class_flags_impl(flags)

#include "detail/can.h"

template<typename ..._modules>
void configure() { detail::configure<_modules...>(); }

template<typename _module, typename ..._filters>
void filter_enable(uint32_t id_high, uint32_t id_low, uint32_t maskid_high, uint32_t maskid_low)
{
  detail::filter_enable<_module, _filters...>(id_high, id_low, maskid_high, maskid_low);
}

template<typename _module, typename ..._filters>
void filter_disable() { detail::filter_disable<_module, _filters...>(); }

template<typename _module>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len)
{
  return detail::tx<_module>(id, ide, rtr, data, len);
}

template<typename _module>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len,
              const delay::expirable &t)
{
  return detail::tx<_module>(id, ide, rtr, data, len, t);
}

template<typename _module>
io::result tx_wait(const delay::expirable &t)
{
  return detail::tx_wait<_module>(t);
}

template<typename _module>
void tx_abort() { detail::tx_abort<_module>(); }

template<typename _module, fifo _fifo = fifo::any>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len)
{
  return detail::rx<_module, _fifo>(id, ide, rtr, fmi, data, len);
}

template<typename _module, fifo _fifo = fifo::any>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len,
              const delay::expirable &t)
{
  return detail::rx<_module, _fifo>(id, ide, rtr, fmi, data, len, t);
}

template<typename _module, event ..._events>
void enable_events() { detail::enable_events<_module, _events...>(); }

template<typename _module, event ..._events>
void disable_events() { detail::disable_events<_module, _events...>(); }

template<typename _module, flags ..._flags>
flags get_flags() { return detail::get_flags<_module, _flags...>(); }

template<typename _module, flags ..._flags>
void clear_flags() { detail::clear_flags<_module, _flags...>(); }

template<typename _module>
event irq_source() { return detail::irq_source<_module>(); }

} // namespace lmcu::can
