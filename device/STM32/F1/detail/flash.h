#pragma once

namespace detail {

static inline io::result wait_op(const delay::expirable &t)
{
  do {
    if(t.expired()) { return io::result::busy; }
  } while((FLASH->SR & FLASH_SR_BSY) != 0);

  const auto s = read_status();
  return ((s & status::pgerr) || (s & status::wrprterr))? io::result::error : io::result::success;
}

static inline io::result erase_page(uint32_t addr, const delay::expirable &t)
{
  auto res = wait_op(t);
  if(res != io::result::success) { return res; }

#if defined(FLASH_CR2_PER)
  if(addr > FLASH_BANK1_END) {
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

static inline io::result erase_all(const delay::expirable &t)
{
  auto res = wait_op(t);
  if(res != io::result::success) { return res; }

  {
    FLASH->CR |= FLASH_CR_MER;
    FLASH->CR |= FLASH_CR_STRT;
    lmcu_defer([] { FLASH->CR &= ~FLASH_CR_MER; });
    res = wait_op(t);
    if(res != io::result::success) { return res; }
  }

#if defined(FLASH_CR2_MER)
  FLASH->CR2 |= FLASH_CR2_MER;
  FLASH->CR2 |= FLASH_CR2_STRT;
  lmcu_defer([] { FLASH->CR2 &= ~FLASH_CR2_MER; });
  return wait_op(t);
#endif

  return io::result::success;
}

static inline io::result program(uint32_t addr, uint16_t data, const delay::expirable &t)
{
  auto res = wait_op(t);
  if(res != io::result::success) { return res; }

  auto pg_data = [addr, data, &t]
  {
    auto dst = reinterpret_cast<volatile uint16_t*>(addr);

    while(!t.expired()) {
      *dst = data;

      auto res = wait_op(t);
      if(res != io::result::success) { return res; }

      if(*dst == data) { return io::result::success; }
    }

    return io::result::busy;
  };

#if defined(FLASH_CR2_PG)
  if(addr > FLASH_BANK1_END) {
    FLASH->CR2 |= FLASH_CR2_PG;
    lmcu_defer([] { FLASH->CR2 &= ~FLASH_CR2_PG; });
    return pg_data();
  }
#endif

  FLASH->CR |= FLASH_CR_PG;
  lmcu_defer([] { FLASH->CR &= ~FLASH_CR_PG; });
  return pg_data();
}

template<status _status>
void clear_status()
{
  uint32_t r;

#if defined(FLASH_SR2_EOP)
  r = 0;
  if constexpr(_status & status::eop)      { r |= FLASH_SR2_EOP;      }
  if constexpr(_status & status::wrprterr) { r |= FLASH_SR2_WRPRTERR; }
  if constexpr(_status & status::pgerr)    { r |= FLASH_SR2_PGERR;    }
  FLASH->SR2 = r;
#endif

  r = 0;
  if constexpr(_status & status::eop)      { r |= FLASH_SR_EOP;       }
  if constexpr(_status & status::wrprterr) { r |= FLASH_SR_WRPRTERR;  }
  if constexpr(_status & status::pgerr)    { r |= FLASH_SR_PGERR;     }
  FLASH->SR = r;
}

static inline void halfcycle_enable() { FLASH->ACR |= FLASH_ACR_HLFCYA; }

static inline void halfcycle_disable() { FLASH->ACR &= ~FLASH_ACR_HLFCYA; }

} // namespace detail
