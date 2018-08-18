#pragma once
#include <lmcu/common>

class __lock_9ec0ab5f
{
  __lock_9ec0ab5f(const __lock_9ec0ab5f&) = delete;
  __lock_9ec0ab5f &operator =(const __lock_9ec0ab5f&) = delete;
public:
  lmcu_force_inline __lock_9ec0ab5f()
  : irqen_(__get_PRIMASK() == 0)
  {
    __disable_irq();
  }

  lmcu_force_inline ~__lock_9ec0ab5f()
  {
    if(irqen_) { __enable_irq(); }
  }
private:
  const bool irqen_;
};

#define __lock_9ec0ab5f_1(line) __lock_9ec0ab5f_obj_##line
#define __lock_9ec0ab5f_2(line) __lock_9ec0ab5f_1(line)

#define lmcu_scoped_lock() __lock_9ec0ab5f __lock_9ec0ab5f_2(__LINE__)()
