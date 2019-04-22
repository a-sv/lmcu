#pragma once

namespace detail {

static inline io::result wait_op(const delay::expirable &t)
{
  do {
    if(t.expired()) { return io::result::busy; }
  } while( (FLASH->SR & FLASH_SR_BSY) != 0 );

  if( (FLASH->SR & FLASH_SR_EOP) != 0 ) { FLASH->SR |= FLASH_SR_EOP; }

  if(flags::any(read_status(), status::operr, status::wrprterr, status::pgaerr, status::pgperr,
                               status::pgserr))
  {
    return io::result::error;
  }

  return io::result::success;
}

template<pg_size _pg_size>
io::result erase_sector(uint32_t sector, const delay::expirable &t)
{
  auto res = wait_op(t);
  if(res != io::result::success) { return res; }

  uint32_t r = FLASH->CR;
  r &= ~(FLASH_CR_PSIZE | FLASH_CR_SNB);
  r |= (uint32_t(_pg_size) << FLASH_CR_PSIZE_Pos) | (sector << FLASH_CR_SNB_Pos) | FLASH_CR_SER;
  FLASH->CR = r;
  FLASH->CR |= FLASH_CR_STRT;

  lmcu_defer([] { FLASH->CR &= ~(FLASH_CR_SER | FLASH_CR_SNB); });

  return wait_op(t);
}

template<pg_size _pg_size>
io::result erase_all(const delay::expirable &t)
{
  auto res = wait_op(t);
  if(res != io::result::success) { return res; }

  uint32_t r = FLASH->CR;
  r &= ~FLASH_CR_PSIZE;
  r |=  (uint32_t(_pg_size) << FLASH_CR_PSIZE_Pos) | FLASH_CR_MER;
  FLASH->CR = r;

  FLASH->CR |= FLASH_CR_STRT;

  return wait_op(t);
}

template<pg_size _pg_size>
io::result program(uint32_t addr, uint64_t data, const delay::expirable &t)
{
  auto res = wait_op(t);
  if(res != io::result::success) { return res; }

  uint32_t r = FLASH->CR;
  r &= ~FLASH_CR_PSIZE;
  r |= (uint32_t(_pg_size) << FLASH_CR_PSIZE_Pos) | FLASH_CR_PG;
  FLASH->CR = r;
  lmcu_defer([] { FLASH->CR &= ~FLASH_CR_PG; });

  while(!t.expired()) {
    switch(_pg_size) {
    case pg_size::_8bit:  *reinterpret_cast<uint8_t*>(addr)  = data; break;
    case pg_size::_16bit: *reinterpret_cast<uint16_t*>(addr) = data; break;
    case pg_size::_32bit: *reinterpret_cast<uint32_t*>(addr) = data; break;
    case pg_size::_64bit: *reinterpret_cast<uint64_t*>(addr) = data; break;
    default: break;
    };

    res = wait_op(t);
    if(res != io::result::success) { return res; }

    switch(_pg_size) {
    case pg_size::_8bit:  if(*reinterpret_cast<uint8_t*>(addr)  == data) { return res; } break;
    case pg_size::_16bit: if(*reinterpret_cast<uint16_t*>(addr) == data) { return res; } break;
    case pg_size::_32bit: if(*reinterpret_cast<uint32_t*>(addr) == data) { return res; } break;
    case pg_size::_64bit: if(*reinterpret_cast<uint64_t*>(addr) == data) { return res; } break;
    default: break;
    };
  }

  return io::result::busy;
}

template<status _status>
void clear_status() { FLASH->SR = flags::value(_status); }

} // namespace detail
