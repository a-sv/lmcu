#pragma once

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
