#pragma once
#include <lmcu/device>
#include <lmcu/hwi/common>
#include <lmcu/delay>

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
  static constexpr auto module_type = lmcu::module_type::can;
  static constexpr auto module_id   = _module_id;
  static constexpr auto prediv      = _prediv;
  static constexpr auto sjw         = _sjw;
  static constexpr auto bs1         = _bs1;
  static constexpr auto bs2         = _bs2;
  static constexpr auto ttcm        = _ttcm;
  static constexpr auto abom        = _abom;
  static constexpr auto awum        = _awum;
  static constexpr auto nart        = _nart;
  static constexpr auto rflm        = _rflm;
  static constexpr auto txfp        = _txfp;
  static constexpr auto mode        = _mode;
  static constexpr auto irq0        = _irq0();
  static constexpr auto irq1        = _irq1();
  static constexpr auto irq2        = _irq2();
  static constexpr auto irq3        = _irq3();
};

enum class fifo { any, fifo_0, fifo_1 };
enum class filter_mode { idmask, idlist };
enum class filter_scale { _16bit, _32bit };
enum class sleep_mode { enable, disable };

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

enum class event : uint32_t
{
  lmcu_flags_object,

  tme   = CAN_IER_TMEIE,  // transmit mailbox empty
  fmp_0 = CAN_IER_FMPIE0, // FIFO 0 message pending
  ff_0  = CAN_IER_FFIE0,  // FIFO 0 full
  fov_0 = CAN_IER_FOVIE0, // FIFO 0 overrun
  fmp_1 = CAN_IER_FMPIE1, // FIFO 1 message pending
  ff_1  = CAN_IER_FFIE1,  // FIFO 1 full
  fov_1 = CAN_IER_FOVIE1, // FIFO 1 overrun
  wku   = CAN_IER_WKUIE,  // wake-up
  slk   = CAN_IER_SLKIE,  // sleep acknowledge
  ewg   = CAN_IER_EWGIE,  // error warning
  epv   = CAN_IER_EPVIE,  // error passive
  bof   = CAN_IER_BOFIE,  // bus-off
  lec   = CAN_IER_LECIE,  // last error code
  err   = CAN_IER_ERRIE   // error
};

enum class flags : uint32_t
{
  lmcu_flags_object,

  // TSR flags
  low_2  = CAN_TSR_LOW2,  // lowest priority flag for mailbox 2
  low_1  = CAN_TSR_LOW1,  // lowest priority flag for mailbox 1
  low_0  = CAN_TSR_LOW0,  // lowest priority flag for mailbox 0
  tme_2  = CAN_TSR_TME2,  // transmit mailbox 2 empty Flag
  tme_1  = CAN_TSR_TME1,  // transmit mailbox 1 empty Flag
  tme_0  = CAN_TSR_TME0,  // transmit mailbox 0 empty Flag

  terr_2 = CAN_TSR_TERR2, // transmission error of mailbox 2
  alst_2 = CAN_TSR_ALST2, // arbitration lost for mailbox 2
  txok_2 = CAN_TSR_TXOK2, // transmission OK for mailbox 2
  rqcp_2 = CAN_TSR_RQCP2, // request completed mailbox 2

  terr_1 = CAN_TSR_TERR1, // transmission error of mailbox 1
  alst_1 = CAN_TSR_ALST1, // arbitration lost for mailbox 1
  txok_1 = CAN_TSR_TXOK1, // transmission OK for mailbox 1
  rqcp_1 = CAN_TSR_RQCP1, // request completed for mailbox 1

  terr_0 = CAN_TSR_TERR0, // transmission error of mailbox 0
  alst_0 = CAN_TSR_ALST0, // arbitration lost for mailbox 0
  txok_0 = CAN_TSR_TXOK0, // transmission OK for mailbox 0
  rqcp_0 = CAN_TSR_RQCP0, // request for mailbox 0

  // RF0R flags
  ff_0   = 1 << 4,        // FIFO 0 full flag
  fov_0  = 1 << 5,        // FIFO 0 overrun flag

  //  RF1R flags
  ff_1   = 1 << 6,        // FIFO 1 full flag
  fov_1  = 1 << 7,        // FIFO 1 overrun flag

  // MSR flags
  erri   = 1 << 12,       //  error interrupt
  wkui   = 1 << 13,       //  wakeup interrupt
  slaki  = 1 << 14,       //  sleep acknowledge interrupt

  rx     = 1 << 20,       // CAN RX signal
  samp   = 1 << 21,       // the value of RX on the last sample point (current received bit value)
  rxm    = 1 << 22,       // the CAN hardware is currently receiver
  txm    = 1 << 23        // the CAN hardware is currently transmitter
};

#include "detail/can.h"

template<typename _module, sleep_mode _sleep_mode>
void set_sleep_mode() { detail::set_sleep_mode<_module, _sleep_mode>(); }

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

template<typename _module, fifo _fifo>
uint32_t get_msg_pending() { return detail::get_msg_pending<_module, _fifo>(); }

template<typename _module, fifo _fifo>
void fifo_release() { detail::fifo_release<_module, _fifo>(); }

} // namespace lmcu::can
