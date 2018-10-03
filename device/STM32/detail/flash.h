#pragma once

namespace detail {

static inline void halfcycle_enable()  { FLASH->ACR |= FLASH_ACR_HLFCYA;  }
static inline void halfcycle_disable() { FLASH->ACR &= ~FLASH_ACR_HLFCYA; }

} // namespace detail
