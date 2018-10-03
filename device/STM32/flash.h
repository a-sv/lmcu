#pragma once
#include <lmcu/delay>

namespace lmcu::flash {

enum class status
{
  eop      = 1 << 5, // end of operation
  wrprterr = 1 << 4, // write protection error
  pgerr    = 1 << 2, // programming error
  busy     = 1 << 0  // busy flag
};
lmcu_enum_class_flags_impl(status)

#include "detail/flash.h"

void lock();
void unlock();
void ob_lock();
void ob_unlock();
uint32_t size();
io::result erase_page(uint32_t addr, const delay::expirable&);
io::result erase_all(const delay::expirable&);
io::result program(uint32_t addr, uint16_t data, const delay::expirable&);
status read_status();
void clear_status(status);
static inline void halfcycle_enable() { detail::halfcycle_enable(); }
static inline void halfcycle_disable() { detail::halfcycle_disable(); }

} // namespace lmcu::flash
