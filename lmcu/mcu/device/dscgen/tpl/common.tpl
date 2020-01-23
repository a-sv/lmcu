## coding: utf-8
#pragma once
#include <cstdint>
#include <cstddef>

namespace lmcu::device {

enum class arch
{
  CM3, // Arm Cortex-M3
  CM4  // Arm Cortex-M4
};

enum class endian { little, big, selectable, other };

template<uint32_t _sz>
struct reg_size { };

template<>
struct reg_size<8>
{
  using type = uint8_t;
  static constexpr type maxval = 0xFF;
};

template<>
struct reg_size<16>
{
  using type = uint16_t;
  static constexpr type maxval = 0xFFFF;
};

template<>
struct reg_size<32>
{
  using type = uint32_t;
  static constexpr type maxval = 0xFFFFFFFF;
};

template<>
struct reg_size<64>
{
  using type = uint64_t;
  static constexpr type maxval = 0xFFFFFFFFFFFFFFFF;
};

template<
  uint32_t _size,
  std::uintptr_t _base,
  typename reg_size<_size>::type _reset_mask,
  typename reg_size<_size>::type _reset_val
>
struct reg
{
  using type = typename reg_size<_size>::type;

  static constexpr type
  maxval = reg_size<_size>::maxval,
  reset_mask = _reset_mask,
  reset_value = _reset_val
  ;

  static constexpr std::uintptr_t
  base = _base
  ;

  __attribute__((always_inline)) static inline void set(type val) noexcept
  {
    *reinterpret_cast<volatile type*>(_base) = val;
  }

  __attribute__((always_inline)) static inline type get() noexcept
  {
    return *reinterpret_cast<volatile type*>(_base);
  }

  __attribute__((always_inline)) static inline volatile type &ref() noexcept
  {
    return *reinterpret_cast<volatile type*>(_base);
  }

  __attribute__((always_inline)) static inline void set_b(type val) noexcept
  {
    *reinterpret_cast<volatile type*>(_base) |= val;
  }

  __attribute__((always_inline)) static inline void clr_b(type val) noexcept
  {
    *reinterpret_cast<volatile type*>(_base) &= ~val;
  }

  __attribute__((always_inline)) static inline bool is_set(type val) noexcept
  {
    return (get() & val) != 0;
  }

  __attribute__((always_inline)) static inline void reset() noexcept
  {
    *reinterpret_cast<volatile type*>(_base) = reset_value;
  }
};

} // namespace lmcu::device
