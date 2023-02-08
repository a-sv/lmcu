#pragma once

#include <lmcu/common>
#include <lmcu/dev/rcc>

// ------------------------------------------------------------------------------------------------
namespace lmcu::sys {
// ------------------------------------------------------------------------------------------------

lmcu_inline void unlock()
{
  using namespace device;

  while(GCR::REGWRPROT::get() != GCR::REGWRPROT::REGPROTDIS_MASK) {
    GCR::REGWRPROT::set(0x59);
    GCR::REGWRPROT::set(0x16);
    GCR::REGWRPROT::set(0x88);
  }
}

lmcu_inline void lock()
{
  using namespace device;
  GCR::REGWRPROT::set(0x0);
}


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::sys
// ------------------------------------------------------------------------------------------------
