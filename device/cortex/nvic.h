namespace nvic {

template<
  irq_type _irq_type,
  uint32_t _prio_group = default_prio_group,
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

template<typename _irq, uint32_t _n>
void enable_irq()
{
  NVIC_SetPriority(_n, NVIC_EncodePriority(_irq::prio_group, _irq::preempt_prio, _irq::sub_prio));
  NVIC_EnableIRQ(_n);
}

} // namespace nvic
