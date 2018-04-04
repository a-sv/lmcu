#pragma once
#include <lmcu/device>

namespace lmcu {

constexpr auto operator"" _MHz(long double x) { return static_cast<uint32_t>(x * 1e6); }
constexpr auto operator"" _MHz(unsigned long long int x) { return static_cast<uint32_t>(x * 1e6); }
constexpr auto operator"" _kHz(long double x) { return static_cast<uint32_t>(x * 1e3); }
constexpr auto operator"" _kHz(unsigned long long int x) { return static_cast<uint32_t>(x * 1e3); }

} // namespace lmcu
