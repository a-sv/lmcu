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

/**
 * Lock the FLASH control register access
*/
static inline void lock() { detail::lock(); }

/**
 * Unlock the FLASH control register access
*/
static inline void unlock() { detail::unlock(); }

/**
 * Lock the FLASH option control registers access.
*/
static inline void ob_lock() { detail::ob_lock(); }

/**
 * Unlock the FLASH option control registers access.
*/
static inline void ob_unlock() { detail::ob_unlock(); }

/**
 * Return FLASH size in Kbytes
*/
static inline uint32_t size() { return detail::size(); }

/**
 * Erase FLASH page
 *
 * @param addr - page address
 * @param t    - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
io::result erase_page(uint32_t addr, const delay::expirable &t);

/**
 * FLASH mass erase
 *
 * @param t - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
io::result erase_all(const delay::expirable &t);

/**
 * Program half-word at specified address
 *
 * @param addr - address to be programmed
 * @param data - data to be programmed
 * @param t    - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
io::result program(uint32_t addr, uint16_t data, const delay::expirable &t);

/**
 * Read FLASH status register
*/
static inline status read_status() { return detail::read_status(); }

/**
 * Clear selected FLASH status flags
*/
void clear_status(status);

/**
 * Enable power saving read access
*/
static inline void halfcycle_enable() { detail::halfcycle_enable(); }

/**
 * Disable power saving read access
*/
static inline void halfcycle_disable() { detail::halfcycle_disable(); }

} // namespace lmcu::flash
