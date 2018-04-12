#pragma once

namespace lmcu {
namespace can {

enum class remap
{
  none = -1,
  CAN1__rx_PB8_tx_PB9 = AFIO_MAPR_CAN_REMAP_REMAP2,
  CAN1__rx_PD0_tx_PD1 = AFIO_MAPR_CAN_REMAP_REMAP3,
  CAN2__rx_PB5_tx_PB6 = AFIO_MAPR_CAN2_REMAP
};

#include "detail/can.h"

} // namespace can
} // namespace lmcu


#include "../can.h"
