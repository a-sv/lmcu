#pragma once
#include <cstdint>

// ------------------------------------------------------------------------------------------------
namespace lmcu {
// ------------------------------------------------------------------------------------------------

constexpr auto operator"" _GHz(long double x) { return static_cast<uint64_t>(x * 1e9L); }
constexpr auto operator"" _GHz(unsigned long long int x) { return static_cast<uint64_t>(x * 1e9L); }
constexpr auto operator"" _MHz(long double x) { return static_cast<uint64_t>(x * 1e6L); }
constexpr auto operator"" _MHz(unsigned long long int x) { return static_cast<uint64_t>(x * 1e6L); }
constexpr auto operator"" _kHz(long double x) { return static_cast<uint64_t>(x * 1e3L); }
constexpr auto operator"" _kHz(unsigned long long int x) { return static_cast<uint64_t>(x * 1e3L); }

constexpr auto operator"" _Mbyte(long double x) { return static_cast<uint64_t>(x * 1024 * 1024); }

constexpr auto operator"" _Mbyte(unsigned long long int x)
{
  return static_cast<uint64_t>(x * 1024 * 1024);
}

constexpr auto operator"" _Kbyte(long double x) { return static_cast<uint64_t>(x * 1024); }

constexpr auto operator"" _Kbyte(unsigned long long int x)
{
  return static_cast<uint64_t>(x * 1024);
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu
// ------------------------------------------------------------------------------------------------
