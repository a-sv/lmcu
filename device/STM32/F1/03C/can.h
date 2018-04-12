#pragma once

namespace lmcu {
namespace can {

enum class remap
{
  none = -1,
  CAN1__rx_PB8_tx_PB9 = AFIO_MAPR_CAN_REMAP_REMAP2
};

#include "detail/can.h"

} // namespace can
} // namespace lmcu

#include "../can.h"
