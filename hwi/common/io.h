#pragma once
#include <lmcu/device>

namespace lmcu::io {

enum class result { success, busy, error, again, eof };

enum class direction
{
  lmcu_flags_object,

  rx = 1 << 0,
  tx = 1 << 1
};

enum class mode { master, slave };

template<auto _id, typename _word_t = uint8_t>
struct buf
{
  _word_t *rxbuf = nullptr;
  uint32_t rx_n = 0;
  result rx_state = result::success;

  const _word_t *txbuf = nullptr;
  uint32_t tx_n = 0;
  result tx_state = result::success;

  void *usrptr = nullptr;

  void (*complete)(direction, void *usrptr) = nullptr;

  static volatile buf *get();
};

} // namespace lmcu::io
