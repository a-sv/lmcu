#pragma once
#include <cstdint>

// ------------------------------------------------------------------------------------------------
namespace lmcu::hash::dallas {
// ------------------------------------------------------------------------------------------------

class crc8
{
public:
  inline void init() { crc_ = 0; }

  void update(const void *data, uint32_t sz)
  {
    auto p = static_cast<const uint8_t*>(data), end = p + sz;

    while(p < end) {
      uint_fast8_t in = *p++;
      for(uint_fast8_t i = 0; i < 8; ++i) {
        uint_fast8_t mix = (crc_ ^ in) & 1U;
        crc_ >>= 1U;
        if(mix) { crc_ ^= 0x8CU; }
        in >>= 1U;
      }
    }
  }

  inline auto digest() const { return crc_; }
private:
  uint_fast8_t crc_ = 0;
};

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::hash::dallas
// ------------------------------------------------------------------------------------------------
