#pragma once

namespace detail {

static inline void enable() { RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN; }

static inline void disable() { RCC->AHB1ENR &= ~RCC_AHB1ENR_CRCEN; }

static inline void reset() { CRC->CR |= CRC_CR_RESET; }

static inline void update(const uint32_t data) { CRC->DR = data; }

static inline io::result update(const uint32_t *data, uint32_t n, const delay::expirable &t)
{
  for(uint32_t i = 0; i < n; i++) {
    if(t.expired()) { return io::result::busy; }
    CRC->DR = data[i];
  }
  return io::result::success;
}

static inline uint32_t value() { return CRC->DR; }

} // namespace detail