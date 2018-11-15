#include <lmcu/common>

#ifdef _LMCU_DEVICE_STM32F1_

#include "../flash.h"

namespace lmcu::flash {

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
  if(addr > FLASH_BANK1_END_ADDRESS) {
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
  if(addr > FLASH_BANK1_END_ADDRESS) {
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

void clear_status(status s)
{
#if defined(FLASH_KEYR2)
  if(s & status::eop)      { FLASH->SR2 |= FLASH_SR2_EOP;      }
  if(s & status::wrprterr) { FLASH->SR2 |= FLASH_SR2_WRPRTERR; }
  if(s & status::pgerr)    { FLASH->SR2 |= FLASH_SR2_PGERR;    }
#endif
  if(s & status::eop)      { FLASH->SR |= FLASH_SR_EOP;        }
  if(s & status::wrprterr) { FLASH->SR |= FLASH_SR_WRPRTERR;   }
  if(s & status::pgerr)    { FLASH->SR |= FLASH_SR_PGERR;      }
}

} // namespace lmcu::flash

#endif // _LMCU_DEVICE_STM32F1_
