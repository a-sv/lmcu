#pragma once
#include <lmcu/device>

namespace lmcu {

constexpr auto operator"" _MHz(long double x) { return static_cast<uint32_t>(x * 1e6); }
constexpr auto operator"" _MHz(unsigned long long int x) { return static_cast<uint32_t>(x * 1e6); }
constexpr auto operator"" _kHz(long double x) { return static_cast<uint32_t>(x * 1e3); }
constexpr auto operator"" _kHz(unsigned long long int x) { return static_cast<uint32_t>(x * 1e3); }

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

} // namespace lmcu
