#include <lmcu/device>

#if defined(_LMCU_DEVICE_STM32_)

#include "../uid.h"
#include "../../../common/mem_ptr.h"

#if defined(_LMCU_DEVICE_STM32F4_)
constexpr auto uid_reg      = lmcu::mem_ptr<uint32_t, 0x1FFF7A10>();
constexpr auto flash_sz_reg = lmcu::mem_ptr<uint32_t, 0x1FFF7A22>();
#endif // _LMCU_DEVICE_STM32F4_

#if defined(_LMCU_DEVICE_STM32F1_)
constexpr auto uid_reg      = lmcu::mem_ptr<uint32_t, 0x1FFFF7E8>();
constexpr auto flash_sz_reg = lmcu::mem_ptr<uint32_t, 0x1FFFF7E0>();
#endif // _LMCU_DEVICE_STM32F1_

static lmcu::uid_type device_id;
static uint32_t flash_sz;

namespace lmcu {

const uid_type &uid() { return device_id; }

uint32_t flash_size() { return flash_sz; }

namespace detail {

void read_device_signature()
{
  device_id[0] = uid_reg[0];
  device_id[1] = uid_reg[1];
  device_id[2] = uid_reg[2];

  flash_sz = (flash_sz_reg[0] & 0xFFFF) * 1024;
}

} // namespace detail

} // namespace lmcu

#endif // _LMCU_DEVICE_STM32_
