#pragma once

#if defined(__NO_INLINE__)
  #define lmcu_force_inline inline
#else
  #define lmcu_force_inline inline __attribute__((always_inline))
#endif

#define lmcu_enum_class_flags_impl(T) \
  constexpr T operator |(T lhs, T rhs) \
  { return static_cast<T>( static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs) ); } \
  \
  constexpr bool operator &(T lhs, T rhs) \
  { return (static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs)) != 0; }
