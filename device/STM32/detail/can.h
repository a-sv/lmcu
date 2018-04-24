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

template<typename arg1, typename ...args>
void configure();

template<typename ...args>
void remap_configure();

template<typename _module, typename arg1, typename ...args>
void filter_enable();

template<typename _module, typename arg1, typename ...args>
void filter_disable();

template<typename _module>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len);

template<typename _module, typename abort_fn>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len, abort_fn&& abort);

template<typename _module, typename abort_fn>
io::result tx_wait(abort_fn&& abort);

template<typename _module>
void tx_abort();

template<typename _module, fifo _fifo>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len);

template<typename _module, fifo _fifo, typename abort_fn>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len,
              abort_fn&& abort);

template<typename _module, event ...evts>
void enable_events();

template<typename _module, event ...evts>
void disable_events();

template<typename _module, flags ..._flags>
flags get_flags();

template<typename _module, flags ..._flags>
void clear_flags();

template<typename _module>
event irq_source();

} // namespace detail
