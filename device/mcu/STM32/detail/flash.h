#pragma once

namespace detail {

static constexpr uint32_t
  key1     = 0x45670123,
  key2     = 0xCDEF89AB,
  opt_key1 = 0x08192A3B,
  opt_key2 = 0x4C5D6E7F
;

static inline void lock()
{
  FLASH->CR |= FLASH_CR_LOCK;

#if defined(FLASH_KEYR2)
  FLASH->CR2 |= FLASH_CR2_LOCK;
#endif
}

static inline bool unlock()
{
  if(FLASH->CR & FLASH_CR_LOCK) {
    FLASH->KEYR = key1;
    FLASH->KEYR = key2;
  }

#if defined(FLASH_KEYR2)
  if(FLASH->CR2 & FLASH_CR2_LOCK) {
    FLASH->KEYR2 = key1;
    FLASH->KEYR2 = key2;
  }
#endif

  return
    ((FLASH->CR & FLASH_CR_LOCK) == 0)
#if defined(FLASH_KEYR2)
    &&
    ((FLASH->CR2 & FLASH_CR2_LOCK) == 0)
#endif
  ;
}

static inline void ob_lock()
{
#if defined(FLASH_CR_OPTWRE)
  FLASH->CR &= ~FLASH_CR_OPTWRE;
#elif defined(FLASH_OPTCR_OPTLOCK)
  FLASH->OPTCR |= FLASH_OPTCR_OPTLOCK;
#endif
}

static inline void ob_unlock()
{
  FLASH->OPTKEYR = opt_key1;
  FLASH->OPTKEYR = opt_key2;
}

static inline uint32_t size() { return *reinterpret_cast<volatile uint32_t*>(FLASHSIZE_BASE); }

static inline status read_status()
{
  uint32_t r = FLASH->SR;
#if defined(FLASH_SR2_BSY_Pos)
  r |= FLASH->SR2;
#endif
  return static_cast<status>(r);
}

template<status _status>
void clear_status();

} // namespace detail
