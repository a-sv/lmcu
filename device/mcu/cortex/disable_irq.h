#pragma once
#include <lmcu/hwi/common>

class __disable_irq_9ec0ab5f
{
  __disable_irq_9ec0ab5f(const __disable_irq_9ec0ab5f&) = delete;
  __disable_irq_9ec0ab5f &operator =(const __disable_irq_9ec0ab5f&) = delete;
public:
  lmcu_force_inline __disable_irq_9ec0ab5f()
  : irqen_(__get_PRIMASK() == 0)
  {
    __disable_irq();
  }

  lmcu_force_inline ~__disable_irq_9ec0ab5f()
  {
    if(irqen_) { __enable_irq(); }
  }
private:
  const bool irqen_;
};

#define __unique_name_9ec0ab5f_1(line) __lock_9ec0ab5f_obj_##line
#define __unique_name_9ec0ab5f_2(line) __unique_name_9ec0ab5f_1(line)

#define lmcu_critical_section() __disable_irq_9ec0ab5f __unique_name_9ec0ab5f_2(__LINE__)
