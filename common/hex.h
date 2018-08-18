#pragma once
#include <lmcu/device>

namespace lmcu::hex {

/**
 * HEX to Decimal conversion
 *
 * @param h - HEX character
 *
 * @warning - it works only for [0-9a-fA-F], other input give wrong result!
*/
constexpr uint8_t to_dec(uint8_t h)
{
  return (h & 0x18)? (h & 0xf) : (h & 0x7) + 9;
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
 * Decimal to HEX conversion in upper case
 *
 * @param d - decimal number 0 - 15
*/
constexpr uint8_t upper(uint8_t d)
{
  d &= 0xf;
  return (d < 10)? '0' + d : '?' + (d & 0x7);
}

} // namespace lmcu::hex
