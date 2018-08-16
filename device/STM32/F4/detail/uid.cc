#include "../../uid.h"
#include "../../../../common/mem_ptr.h"

constexpr auto uid_reg      = lmcu::mem_ptr<uint32_t, 0x1FFF7A10>();
constexpr auto flash_sz_reg = lmcu::mem_ptr<uint32_t, 0x1FFF7A22>();

static lmcu::uid_type device_id;
static uint32_t flash_sz;

#define STM32_UUID reinterpret_cast<volatile uint32_t*>(0x1FFF7A10)

namespace lmcu {

const uid_type &uid() { return device_id; }

uint32_t flash_size() { return flash_sz; }

namespace detail {

void read_device_signature()
{
  device_id[0] = uid_reg[0];
  device_id[1] = uid_reg[1];
  device_id[2] = uid_reg[2];

  flash_sz     = (flash_sz_reg[0] & 0xFFFF) * 1024;
}

} // namespace detail

} // namespace lmcu
