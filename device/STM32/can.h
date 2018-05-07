#pragma once
#include <lmcu/delay>
#include "../../common/def.h"
#include "../../common/io.h"

namespace lmcu {
namespace can {

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
  tq1,
  tq2,
  tq3,
  tq4
};

enum class bs1
{
  tq1,
  tq2,
  tq3,
  tq4,
  tq5,
  tq6,
  tq7,
  tq8,
  tq9,
  tq10,
  tq11,
  tq12,
  tq13,
  tq14,
  tq15,
  tq16
};

enum class bs2
{
  tq1,
  tq2,
  tq3,
  tq4,
  tq5,
  tq6,
  tq7,
  tq8
};

enum class ttcm { enable, disable };
enum class abom { enable, disable };
enum class awum { enable, disable };
enum class nart { enable, disable };
enum class rflm { enable, disable };
enum class txfp { enable, disable };

enum class irq_type { disable, tx, rx0, rx1, sce };

template<
  irq_type _irq_type,
  uint32_t _prio_group = 3,
  uint32_t _preempt_prio = 0,
  uint32_t _sub_prio = 0
>
struct irq
{
  static constexpr auto irq_type     = _irq_type;
  static constexpr auto prio_group   = _prio_group;
  static constexpr auto preempt_prio = _preempt_prio;
  static constexpr auto sub_prio     = _sub_prio;
};

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
  typename _irq0 = irq<irq_type::disable>,
  typename _irq1 = irq<irq_type::disable>,
  typename _irq2 = irq<irq_type::disable>,
  typename _irq3 = irq<irq_type::disable>
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
enum class filter_scale { fs16, fs32 };

template<
  uint32_t _number,
  filter_mode _filter_mode,
  filter_scale _filter_scale,
  uint32_t _id_high,
  uint32_t _id_low,
  uint32_t _maskid_high,
  uint32_t _maskid_low,
  fifo _fifo,
  uint32_t _bank_num
>
struct filter
{
  static constexpr auto number       = _number;
  static constexpr auto filter_mode  = _filter_mode;
  static constexpr auto filter_scale = _filter_scale;
  static constexpr auto id_high      = _id_high;
  static constexpr auto id_low       = _id_low;
  static constexpr auto maskid_high  = _maskid_high;
  static constexpr auto maskid_low   = _maskid_low;
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

template<typename ...args>
void configure() { detail::configure<args...>(); }

template<typename _module, typename ...args>
void filter_enable() { detail::filter_enable<_module, args...>(); }

template<typename _module, typename ...args>
void filter_disable() { detail::filter_disable<_module, args...>(); }

template<typename _module, io::type _iotype = io::type::blocking>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len)
{
  if constexpr(_iotype == io::type::blocking) {
    return detail::tx<_module>(id, ide, rtr, data, len, [] { return false; });
  }
  return detail::tx<_module>(id, ide, rtr, data, len);
}

template<typename _module>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len, const delay::timer &t)
{
  return detail::tx<_module>(id, ide, rtr, data, len, [&] { return t.expired(); });
}

template<typename _module>
void tx_wait() { detail::tx_wait<_module>([] { return false; }); }

template<typename _module>
io::result tx_wait(const delay::timer &t)
{
  return detail::tx_wait<_module>([&] { return t.expired(); });
}

template<typename _module>
void tx_abort() { detail::tx_abort<_module>(); }

template<typename _module, fifo _fifo = fifo::any, io::type _iotype = io::type::blocking>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len)
{
  if constexpr(_iotype == io::type::blocking) {
    return detail::rx<_module, _fifo>(id, ide, rtr, fmi, data, len, [] { return false; });
  }
  return detail::rx<_module, _fifo>(id, ide, rtr, fmi, data, len);
}

template<typename _module, fifo _fifo = fifo::any>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len,
              const delay::timer &t)
{
  return detail::rx<_module, _fifo>(id, ide, rtr, fmi, data, len, [&] { return t.expired(); });
}

template<typename _module, event ...evts>
void enable_events() { detail::enable_events<_module, evts...>(); }

template<typename _module, event ...evts>
void disable_events() { detail::disable_events<_module, evts...>(); }

template<typename _module, flags ..._flags>
flags get_flags() { return detail::get_flags<_module, _flags...>(); }

template<typename _module, flags ..._flags>
void clear_flags() { detail::clear_flags<_module, _flags...>(); }

template<typename _module>
event irq_source() { return detail::irq_source<_module>(); }

} // namespace can
} // namespace lmcu
