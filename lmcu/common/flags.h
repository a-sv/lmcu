#pragma once
#include <type_traits>

template<typename _flags, typename _type>
using lmcu_flags_t = std::enable_if_t<
  std::is_enum_v<_flags> && std::underlying_type_t<_flags>(_flags::lmcu_flags) == 0,
  _type
>;

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator |(const _flags a, const _flags b) noexcept
{
  return static_cast<_flags>( std::underlying_type_t<_flags>(a) |
                              std::underlying_type_t<_flags>(b) );
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator &(const _flags a, const _flags b) noexcept
{
  return static_cast<_flags>( std::underlying_type_t<_flags>(a) &
                              std::underlying_type_t<_flags>(b) );
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator ^(const _flags a, const _flags b) noexcept
{
  return static_cast<_flags>( std::underlying_type_t<_flags>(a) ^
                              std::underlying_type_t<_flags>(b) );
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator ~(const _flags a) noexcept
{
  return static_cast<_flags>( ~std::underlying_type_t<_flags>(a) );
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator +(const _flags a, const _flags b) noexcept
{
  return a | b;
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator -(const _flags a, const _flags b) noexcept
{
  return a & (~b);
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator |=(_flags &a, const _flags b) noexcept
{
  return (a = a | b);
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator &=(_flags &a, const _flags b) noexcept
{
  return (a = a & b);
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator ^=(_flags &a, const _flags b) noexcept
{
  return (a = a ^ b);
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator +=(_flags &a, const _flags b) noexcept
{
  return (a = a + b);
}

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, _flags> operator -=(_flags &a, const _flags b) noexcept
{
  return (a = a - b);
}

namespace lmcu::flags {

template<typename _flags>
constexpr inline lmcu_flags_t<_flags, std::underlying_type_t<_flags>> value(_flags f) noexcept
{
  return std::underlying_type_t<_flags>(f);
}

template<typename _flags, typename _bits>
constexpr inline lmcu_flags_t<_flags, _flags> from_value(const _bits bits) noexcept
{
  return static_cast< lmcu_flags_t<_flags, _flags> >(bits);
}

template<typename _flags, typename ..._bits>
constexpr inline lmcu_flags_t<_flags, bool> all(const _flags f, const _bits ...bits) noexcept
{
  static_assert(sizeof...(_bits) > 0, "must have at least one flag argument");
  const auto mask = (bits + ...);
  return value(f & mask) == value(mask);
}

template<typename _flags, typename ..._bits>
constexpr inline lmcu_flags_t<_flags, bool> any(const _flags f, const _bits ...bits) noexcept
{
  if constexpr(sizeof...(_bits) > 0) {
    const auto mask = (bits + ...);
    return value(f & mask) != 0;
  }
  return value(f) != 0;
}

template<typename _flags, typename ..._bits>
constexpr inline lmcu_flags_t<_flags, bool> none(const _flags f, const _bits ...bits) noexcept
{
  return !any(f, bits...);
}

} // namespace lmcu::flags
