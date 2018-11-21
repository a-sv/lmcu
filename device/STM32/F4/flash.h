#pragma once
#include "../flash.h"

namespace lmcu::flash {

enum class status
{
  eop      = 1 << 0, // end of operation
  operr    = 1 << 1, // operation error
  wrprterr = 1 << 4, // write protection error
  pgaerr   = 1 << 5, // programming alignment error
  pgperr   = 1 << 6, // programming parallelism error
  pgserr   = 1 << 7, // programming sequence error
  busy     = 1 << 16 // busy flag
};
lmcu_enum_class_flags_impl(status)

// program size
enum class pg_size { _8bit, _16bit, _32bit, _64bit };

#include "detail/flash.h"

/**
 * Erase FLASH sector
 *
 * @tparam _pg_size - program parallelism size
 * @param  sector   - sector index
 * @param  t        - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
template<pg_size _pg_size>
io::result erase_sector(uint32_t sector, const delay::expirable &t)
{
  return detail::erase_sector<_pg_size>(sector, t);
}

/**
 * FLASH mass erase
 *
 * @tparam _pg_size - program parallelism size
 * @param t         - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/

template<pg_size _pg_size>
io::result erase_all(const delay::expirable &t) { return detail::erase_all<_pg_size>(t); }

/**
 * Program half-word at specified address
 *
 * @tparam _pg_size - program parallelism size
 * @param addr      - address to be programmed
 * @param data      - data to be programmed
 * @param t         - timeout
 *
 * @return io::result::sucess on operation done, or io::result::busy at timeout exceed
*/
template<pg_size _pg_size>
io::result program(uint32_t addr, uint64_t data, const delay::expirable &t)
{
  return detail::program<_pg_size>(addr, data, t);
}

} // namespace lmcu::flash
