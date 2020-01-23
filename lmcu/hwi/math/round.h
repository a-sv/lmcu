#pragma once

namespace lmcu {

template<typename _result, typename _float>
static constexpr inline _result round(_float x) noexcept
{
  return (x >= 0.0)? _result(x + 0.5) : _result(x - 0.5);
}

} // namespace lmcu
