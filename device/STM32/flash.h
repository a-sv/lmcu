#pragma once
#include <lmcu/delay>

namespace lmcu::flash {

enum class status;

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
 * Read FLASH status flags
*/
static inline status read_status() { return detail::read_status(); }

/**
 * Clear FLASH status flags
*/
template<status _status>
void clear_status() { return detail::clear_status<_status>(); }

} // namespace lmcu::flash
