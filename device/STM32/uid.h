#pragma once
#include <lmcu/device>

namespace lmcu {

using uid_type = uint32_t[3];

const uid_type &uid();

uint32_t flash_size();

} // namespace lmcu::detail
