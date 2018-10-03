#include <lmcu/common>
#include "../flash.h"

#ifdef _LMCU_DEVICE_STM32_

namespace lmcu::flash {

void lock()
{
  FLASH->CR |= FLASH_CR_LOCK;

#if defined(FLASH_KEYR2)
  FLASH->CR2 |= FLASH_CR2_LOCK;
#endif
}

void unlock()
{
  if(FLASH->CR & FLASH_CR_LOCK) {
    FLASH->KEYR = FLASH_KEY1;
    FLASH->KEYR = FLASH_KEY2;
  }

#if defined(FLASH_KEYR2)
  if(FLASH->CR2 & FLASH_CR2_LOCK) {
    FLASH->KEYR2 = FLASH_KEY1;
    FLASH->KEYR2 = FLASH_KEY2;
  }
#endif
}

void ob_lock()
{
#if defined(FLASH_CR_OPTWRE)
  FLASH->CR &= ~FLASH_CR_OPTWRE;
#endif
}

void ob_unlock()
{
#if defined(FLASH_CR_OPTWRE)
  FLASH->OPTKEYR = FLASH_OPTKEY1;
  FLASH->OPTKEYR = FLASH_OPTKEY1;
#endif
}

uint32_t size() { return *reinterpret_cast<volatile uint32_t*>(FLASHSIZE_BASE); }

static io::result wait_op(const delay::expirable &t)
{
  while(!t.expired()) {
    if((FLASH->SR & FLASH_SR_BSY) == 0) { return io::result::success; }
  }
  return io::result::busy;
}

io::result erase_page(uint32_t addr, const delay::expirable &t)
{
  if(wait_op(t) != io::result::success) { return io::result::busy; }

#if defined(FLASH_KEYR2)
  if(size() > 512 && addr >= FLASH_BASE + (512 * 1024)) {
    FLASH->CR2 |= FLASH_CR2_PER;
    FLASH->AR2  = addr;
    FLASH->CR2 |= FLASH_CR2_STRT;
    lmcu_defer([] { FLASH->CR2 &= ~FLASH_CR2_PER; });
    return wait_op(t);
  }
#endif
  FLASH->CR |= FLASH_CR_PER;
  FLASH->AR  = addr;
  FLASH->CR |= FLASH_CR_STRT;
  lmcu_defer([] { FLASH->CR &= ~FLASH_CR_PER; });
  return wait_op(t);
}

io::result erase_all(const delay::expirable &t)
{
  if(wait_op(t) != io::result::success) { return io::result::busy; }

  {
    FLASH->CR |= FLASH_CR_MER;
    FLASH->CR |= FLASH_CR_STRT;
    lmcu_defer([] { FLASH->CR &= ~FLASH_CR_MER; });
    if(wait_op(t) != io::result::success) { return io::result::busy; }
  }

#if defined(FLASH_KEYR2)
  FLASH->CR2 |= FLASH_CR2_MER;
  FLASH->CR2 |= FLASH_CR2_STRT;
  lmcu_defer([] { FLASH->CR2 &= ~FLASH_CR2_MER; });
  return wait_op(t);
#endif

  return io::result::success;
}

io::result program(uint32_t addr, uint16_t data, const delay::expirable &t)
{
  if(wait_op(t) != io::result::success) { return io::result::busy; }

#if defined(FLASH_KEYR2)
  if(size() > 512 && addr >= FLASH_BASE + (512 * 1024)) {
    FLASH->CR2 |= FLASH_CR2_PG;
    lmcu_defer([] { FLASH->CR2 &= ~FLASH_CR2_PG; });
    *reinterpret_cast<volatile uint16_t*>(addr) = data;
    return wait_op(t);
  }
#endif
  FLASH->CR |= FLASH_CR_PG;
  lmcu_defer([] { FLASH->CR &= ~FLASH_CR_PG; });
  *reinterpret_cast<volatile uint16_t*>(addr) = data;
  return wait_op(t);
}

status read_status()
{
  uint32_t r = FLASH->SR;
#if defined(FLASH_KEYR2)
  r |= FLASH->SR2;
#endif
  return static_cast<status>(r);
}

void clear_status(status s)
{
#if defined(FLASH_KEYR2)
  if(size() > 512) {
    if(s & status::eop)      { FLASH->SR2 |= FLASH_SR2_EOP;      }
    if(s & status::wrprterr) { FLASH->SR2 |= FLASH_SR2_WRPRTERR; }
    if(s & status::pgerr)    { FLASH->SR2 |= FLASH_SR2_PGERR;    }
  }
#endif
  if(s & status::eop)      { FLASH->SR |= FLASH_SR_EOP;      }
  if(s & status::wrprterr) { FLASH->SR |= FLASH_SR_WRPRTERR; }
  if(s & status::pgerr)    { FLASH->SR |= FLASH_SR_PGERR;    }
}

} // namespace lmcu::flash

#endif // _LMCU_DEVICE_STM32_
