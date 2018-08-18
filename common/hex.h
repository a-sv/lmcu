#pragma once
#include <lmcu/device>

namespace lmcu::hex {

/**
 * HEX to Decimal conversion
 *
 * @param h - HEX character
 *
 * @warning it works only for [0-9a-fA-F], other input give wrong result!
*/
constexpr uint8_t to_dec(uint8_t h)
{
  return (h & 0x18)? (h & 0xf) : (h & 0x7) + 9;
}

/**
 * Full byte HEX to Decimal conversion
 *
 * @param hi - upper half-byte
 * @param lo - lower half-byte
*/
constexpr uint8_t to_dec(uint8_t hi, uint8_t lo)
{
  return (to_dec(hi) << 4) | to_dec(lo);
}

/**
 * In-place HEX to Decimal conversion
 *
 * @param data - HEX string (will be replaced to decimal data)
 * @param sz   - size of HEX string
 *
 * @return bytes count stored in data
*/
template<typename _sz>
static inline _sz to_dec(uint8_t *data, _sz sz)
{
  const uint8_t *p = data, *end = data + sz;

  _sz i = 0;
  while((end - p) >= 2) {
    data[i++] = to_dec(p[0], p[1]);
    p += 2;
  }

  if(p < end) {
    data[i++] = to_dec(p[0]) << 4;
  }

  return i;
}

/**
 * Decimal to HEX conversion in lower case
 *
 * @param d - decimal number 0 - 15
*/
constexpr uint8_t lower(uint8_t d)
{
  d &= 0xf;
  return (d < 10)? '0' + d : '_' + (d & 0x7);
}

/**
 * Full byte Decimal to HEX conversion in lower case
 *
 * @param d   - decimal number
 * @param out - output buffer
*/
constexpr void lower(uint8_t d, uint8_t *out)
{
  out[0] = lower(d >> 4);
  out[1] = lower(d);
}

/**
 * Decimal to HEX conversion in upper case
 *
 * @param d - decimal number 0 - 15
*/
constexpr uint8_t upper(uint8_t d)
{
  d &= 0xf;
  return (d < 10)? '0' + d : '?' + (d & 0x7);
}

/**
 * Full byte Decimal to HEX conversion in upper case
 *
 * @param d   - decimal number
 * @param out - output buffer
*/
constexpr void upper(uint8_t d, uint8_t *out)
{
  out[0] = upper(d >> 4);
  out[1] = upper(d);
}

} // namespace lmcu::hex
