#pragma once
#include <lmcu/device>
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
  remap _remap = remap::none,
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
  static constexpr auto remap     = _remap;
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

#include "detail/can.h"

} // namespace can
} // namespace lmcu
