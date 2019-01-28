#pragma once
#include <lmcu/delay>

namespace lmcu::hash::hw::crc32 {

#include "detail/crc32.h"

/**
 * @brief Enable CRC hardware module
*/
static inline void enable() { detail::enable(); }

/**
 * @brief Disable CRC hardware module
*/
static inline void disable() { detail::disable(); }

/**
 * @brief Reset CRC calculation
*/
static inline void reset() { detail::reset(); }

/**
 * @brief Append data to CRC calculation
 *
 * @param data - data for CRC caclulation
*/
static inline void update(uint32_t data) { detail::update(data); }

/**
 * @brief Append data to CRC calculation
 *
 * @param data - data for CRC caclulation
 * @param n    - count of elements in 'data' array
 * @param t    - timeout
 *
 * @return     - io::result::busy if timeout occured, else io::result::success
*/
static inline io::result update(const uint32_t *data, uint32_t n, const delay::expirable &t)
{
  return detail::update(data, n, t);
}

/**
 * @brief Get current CRC hash value
*/
static inline uint32_t value() { return detail::value(); }

} // namespace lmcu::hash::crc32
