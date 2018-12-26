#pragma once

namespace lmcu {

template<typename result_t, typename float_t>
constexpr result_t round(float_t x)
{
  return (x >= 0.0)? result_t(x + 0.5) : result_t(x - 0.5);
}

} // namespace lmcu
