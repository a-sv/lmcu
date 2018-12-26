#pragma once
#include "../flash.h"

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

/**
 * Erase FLASH page
 *
 * @param addr - page address
 * @param t    - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
static inline io::result erase_page(uint32_t addr, const delay::expirable &t)
{
  return detail::erase_page(addr, t);
}

/**
 * FLASH mass erase
 *
 * @param t - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
static inline io::result erase_all(const delay::expirable &t) { return detail::erase_all(t); }

/**
 * Program half-word at specified address
 *
 * @param addr - address to be programmed
 * @param data - data to be programmed
 * @param t    - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
static inline io::result program(uint32_t addr, uint16_t data, const delay::expirable &t)
{
  return detail::program(addr, data, t);
}

/**
 * Enable power saving read access
*/
static inline void halfcycle_enable() { detail::halfcycle_enable(); }

/**
 * Disable power saving read access
*/
static inline void halfcycle_disable() { detail::halfcycle_disable(); }

} // namespace lmcu::flash
