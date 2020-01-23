#pragma once
#include <lmcu/hwi/common>
#include <lmcu/dev/mcu>
#include <lmcu/dev/nvic>

namespace lmcu::irq {

/**
 * @brief Enable global interrupts
*/
lmcu_static_inline void enable() noexcept { asm volatile("cpsie i" ::: "memory"); }

/**
 * @brief Disable global interrupts
*/
lmcu_static_inline void disable() noexcept { asm volatile("cpsid i" ::: "memory"); }

/**
 * @brief Return interrupt priority mask
*/
lmcu_static_inline uint32_t primask() noexcept
{
  uint32_t r;
  asm volatile("MRS %0, primask" : "=r" (r));
  return r;
}

class ctl
{
  ctl(const ctl&) = delete;
  ctl &operator =(const ctl&) = delete;
public:
  lmcu_inline ctl() noexcept { }

  /**
   * @brief Force enable global interrupts
  */
  lmcu_inline void enable() noexcept
  {
    irqen_ = false; irq::enable();
  }

  /**
   * @brief Enables global interrupts if them been enabled, before call 'ctl::disable'
  */
  lmcu_inline void enable_if_needed() noexcept
  {
    if(irqen_) { irqen_ = false; irq::enable(); }
  }

  /**
   * @brief Disable global interrupts
  */
  lmcu_inline void disable() noexcept
  {
    irqen_ = irq::primask() == 0;
    irq::disable();
  }

  lmcu_inline ~ctl() noexcept
  {
    enable_if_needed();
  }
private:
  bool irqen_ = false;
};

} // namespace lmcu::irq

namespace lmcu::nvic {

enum class preempt_prio : uint32_t { defval = 14 };
enum class sub_prio : uint32_t { defval = 0 };
enum class group_prio : uint32_t { defval = 0 };

struct irq_config
{
  // Preempt priority
  preempt_prio preempt = preempt_prio::defval;
  // Sub priority
  sub_prio sub = sub_prio::defval;
  // Priority group
  group_prio group = group_prio::defval;
};

/**
 * @brief Enable IRQ vectors
 *
 * @tparam _irq_n - IRQ numbers
*/
template<device::irqn ..._irq_n>
void enable_irq()
{
  using namespace device;

  auto ISER = reinterpret_cast<volatile NVIC::ISER0::type*>(NVIC::ISER0::base);

  auto irq_e = [ISER](auto irq)
  {
    ISER[irq >> 5UL] = (1UL << (irq & 0x1fUL));
  };

  (irq_e(uint32_t(_irq_n)), ...);
}

/**
 * @brief Disable IRQ vectors
 *
 * @tparam _irq_n - IRQ numbers
*/
template<device::irqn ..._irq_n>
void disable_irq()
{
  using namespace device;

  auto ICER = reinterpret_cast<volatile NVIC::ICER0::type*>(NVIC::ICER0::base);

  auto irq_d = [ICER](auto irq)
  {
    ICER[irq >> 5UL] = (1UL << (irq & 0x1fUL));
  };

  (irq_d(uint32_t(_irq_n)), ...);
}

/**
 * @brief Set IRQ priority
 *
 * @tparam _irq_n      - IRQ number
 * @tparam _irq_config - IRQ priority config
*/
template<device::irqn _irq_n, auto _irq_config>
void set_priority()
{
  using namespace device;

  constexpr uint32_t priority_group = uint32_t(_irq_config.group) & 0x7UL;

  constexpr uint32_t preempt_prio_bits =
    ((7 - priority_group) > nvic_prio_bits)? nvic_prio_bits : 7 - priority_group
  ;

  constexpr uint32_t sub_prio_bits =
    ((priority_group + nvic_prio_bits) < 7)? 0 : (priority_group - 7) + nvic_prio_bits
  ;

  constexpr auto priority =
    ((uint32_t(_irq_config.preempt) & ((1UL << preempt_prio_bits) - 1UL)) <<  sub_prio_bits) |
    (uint32_t(_irq_config.sub) & ((1UL << sub_prio_bits) - 1UL))
  ;

  if constexpr(int32_t(_irq_n) < 0) {
    auto SHP = reinterpret_cast<volatile uint8_t*>(NVIC::SHPR0::base);
    SHP[(uint32_t(_irq_n) & 0xfUL) - 4UL] = (priority << (8UL - nvic_prio_bits)) & 0xffUL;
  }
  else {
    auto IP = reinterpret_cast<volatile uint8_t*>(NVIC::IPR0::base);
    IP[uint32_t(_irq_n)] = (priority << (8UL - nvic_prio_bits)) & 0xffUL;
  }
}

} // namespace lmcu::nvic
