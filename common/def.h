#pragma once

#if defined(__NO_INLINE__)
  #define lmcu_force_inline inline
#else
  #define lmcu_force_inline inline __attribute__((always_inline))
#endif
