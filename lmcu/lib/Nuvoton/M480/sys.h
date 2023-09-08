#pragma once

#include <lmcu/common>
#include <lmcu/dev/rcc>

// ------------------------------------------------------------------------------------------------
namespace lmcu::sys {
// ------------------------------------------------------------------------------------------------

lmcu_inline void unlock()
{
  using namespace device;

  do {
    SYS::REGLCTL::set(0x59);
    SYS::REGLCTL::set(0x16);
    SYS::REGLCTL::set(0x88);
  }
  while(SYS::REGLCTL::get() == 0);
}

lmcu_inline void lock()
{
  using namespace device;
  SYS::REGLCTL::set(0x0);
}


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::sys
// ------------------------------------------------------------------------------------------------
