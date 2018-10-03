#pragma once

namespace detail {

static inline void lock()
{
  FLASH->CR |= FLASH_CR_LOCK;

#if defined(FLASH_KEYR2)
  FLASH->CR2 |= FLASH_CR2_LOCK;
#endif
}

static inline void unlock()
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

static inline void ob_lock()
{
#if defined(FLASH_CR_OPTWRE)
  FLASH->CR &= ~FLASH_CR_OPTWRE;
#endif
}

static inline void ob_unlock()
{
#if defined(FLASH_CR_OPTWRE)
  FLASH->OPTKEYR = FLASH_OPTKEY1;
  FLASH->OPTKEYR = FLASH_OPTKEY1;
#endif
}

static inline status read_status()
{
  uint32_t r = FLASH->SR;
#if defined(FLASH_KEYR2)
  r |= FLASH->SR2;
#endif
  return static_cast<status>(r);
}

static inline void halfcycle_enable()  { FLASH->ACR |= FLASH_ACR_HLFCYA;  }
static inline void halfcycle_disable() { FLASH->ACR &= ~FLASH_ACR_HLFCYA; }
static inline uint32_t size() { return *reinterpret_cast<volatile uint32_t*>(FLASHSIZE_BASE); }

} // namespace detail
