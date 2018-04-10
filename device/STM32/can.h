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
  remap _remap = can::remap::none,
  mode _mode = mode::normal
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
};

namespace detail {

template<module_id _module_id>
CAN_TypeDef *inst()
{
#if defined(CAN1)
  if constexpr(_module_id == module_id::can1) { return CAN1; }
#endif

#if defined(CAN2)
  if constexpr(_module_id == module_id::can2) { return CAN2; }
#endif

#if defined(CAN3)
  if constexpr(_module_id == module_id::can3) { return CAN3; }
#endif
}

template<module_id _module_id, typename arg1, typename ...args>
constexpr bool has_module()
{
  if constexpr(sizeof...(args) > 0) { return has_module<_module_id, args...>(); }
  return arg1().module_id == _module_id;
}

} // namespace detail

} // namespace can
} // namespace lmcu
