## coding: utf-8
#pragma once
#include <cstdint>
#include <cstddef>
#include <utility>

namespace lmcu::device {

enum class arch
{
  CM0, // Arm Cortex-M0
  CM3, // Arm Cortex-M3
  CM4  // Arm Cortex-M4
};

enum class endian { little, big, selectable, other };

// Internal peripheral version
enum class ip_version
{
  none,
  _1
};

template<uint32_t _sz>
struct reg_size { };

template<>
struct reg_size<8>
{
  using type = uint8_t;
  static constexpr type maxval = 0xFFUL;
  static constexpr type bytes = 1;
};

template<>
struct reg_size<16>
{
  using type = uint16_t;
  static constexpr type maxval = 0xFFFFUL;
  static constexpr type bytes = 2;
};

template<>
struct reg_size<32>
{
  using type = uint32_t;
  static constexpr type maxval = 0xFFFFFFFFUL;
  static constexpr type bytes = 4;
};

template<>
struct reg_size<64>
{
  using type = uint64_t;
  static constexpr type maxval = 0xFFFFFFFFFFFFFFFFULL;
  static constexpr type bytes = 8;
};

template<
  // IP version
  ip_version _ip_ver,
  // register base address
  std::uintptr_t _base,
  // register reset value
  uint64_t _reset_val = 0,
  // count of registers in array
  uint32_t _count = 1,
  // register bit width
  uint32_t _size = 32,
  // register struct size
  uint32_t _s_size = (_count > 1? reg_size<_size>::bytes : 0)
>
struct reg
{
  using type = typename reg_size<_size>::type;

  static constexpr ip_version
  ip_ver = _ip_ver
  ;

  static constexpr type
  maxval = reg_size<_size>::maxval,
  reset_value = _reset_val
  ;

  static constexpr std::uintptr_t
  base = _base
  ;

  static constexpr uint32_t
  count = _count
  ;

  __attribute__((always_inline)) static inline void set(type val) noexcept
  {
    *reinterpret_cast<volatile type*>(_base) = val;
  }

  __attribute__((always_inline)) static inline void set(uint32_t i, type val) noexcept
  {
    *reinterpret_cast<volatile type*>(_base + (i * _s_size)) = val;
  }

  __attribute__((always_inline)) static inline type get() noexcept
  {
    return *reinterpret_cast<volatile type*>(_base);
  }

  __attribute__((always_inline)) static inline type get(uint32_t i) noexcept
  {
    return *reinterpret_cast<volatile type*>(_base + (i * _s_size));
  }

  __attribute__((always_inline)) static inline void set_b(type val) noexcept
  {
    set(get() | val);
  }

  __attribute__((always_inline)) static inline void set_b(uint32_t i, type val) noexcept
  {
    set(i, get(i) | val);
  }

  __attribute__((always_inline)) static inline void clr_b(type val) noexcept
  {
    set(get() & ~val);
  }

  __attribute__((always_inline)) static inline void clr_b(uint32_t i, type val) noexcept
  {
    set(i, get(i) & ~val);
  }

  __attribute__((always_inline)) static inline void set_m(type mask, type val) noexcept
  {
    set((get() & ~mask) | (val & mask));
  }

  __attribute__((always_inline)) static inline void set_m(uint32_t i, type mask, type val) noexcept
  {
    set(i, (get(i) & ~mask) | (val & mask));
  }

  __attribute__((always_inline)) static inline bool is_set(type val) noexcept
  {
    return (get() & val) != 0;
  }

  __attribute__((always_inline)) static inline bool is_set(uint32_t i, type val) noexcept
  {
    return (get(i) & val) != 0;
  }

  __attribute__((always_inline)) static inline void reset() noexcept
  {
    set(reset_value);
  }

  __attribute__((always_inline)) static inline void reset(uint32_t i) noexcept
  {
    set(i, reset_value);
  }
};

} // namespace lmcu::device
