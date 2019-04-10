#pragma once
#include <type_traits>
#include <lmcu/device>

namespace lmcu::bits {

template<uint32_t _bits, typename _cb>
bool split(const void *data, uint32_t sz, _cb&& cb)
{
  static_assert(_bits <= 64, "_bits must be <= 64");

  auto b = static_cast<const uint8_t*>(data), e = b + sz;

  if constexpr(_bits == 1 || _bits == 2 || _bits == 4) {
    auto put = [&]
    {
      if constexpr(_bits == 1) {
        return [&](auto&& buf)
        {
          if(!cb((buf & 0x80) != 0)) { return false; }
          buf <<= 1;
          return true;
        };
      }
      else
      if constexpr(_bits == 2) {
        return [&](auto&& buf)
        {
          if(!cb((buf & 0xC0) >> 6)) { return false; }
          buf <<= 2;
          return true;
        };
      }
      else {
        return [&](auto&& buf)
        {
          if(!cb((buf & 0xf0) >> 4)) { return false; }
          buf <<= 4;
          return true;
        };
      }
    }();

    while(b < e) {
      uint_fast8_t buf = *b++;
      if(!put(buf)) { return false; }
    }

    return true;
  }
  else
  if constexpr(_bits == 8) {
    while(b < e) {
      if(!cb(*b++)) { return false; }
    }
    return true;
  }
  else
  if constexpr((_bits % 8) != 0) {
    using buffer_t = std::conditional_t<_bits <= 24, uint32_t, uint64_t>;

    constexpr uint32_t
      bufsz = sizeof(buffer_t) * 8,
      shift = bufsz - _bits
    ;
    constexpr buffer_t
      mask  = (bufsz == 32)? (0xffffffff << shift) : (0xffffffffffffffff << shift)
    ;

    uint32_t avail = bufsz;
    buffer_t buf   = 0;

    auto put = [&]
    {
      if(!cb((buf & mask) >> shift)) { return false; }
      buf  <<= _bits;
      avail += _bits;
      return true;
    };

    while(b < e) {
      if((bufsz - avail) >= _bits) {
        if(!put()) { return false; }
      }
      else {
        avail -= 8;
        buf   |= buffer_t(*b++) << avail;
      }
    }

    while(avail < bufsz) {
      if(!put()) { return false; }
    }

    return true;
  }
  else {
    using buffer_t = std::conditional_t<_bits <= 32, uint32_t, uint64_t>;

    constexpr uint32_t
      bufsz = sizeof(buffer_t) * 8,
      shift = bufsz - _bits
    ;
    constexpr buffer_t
      mask  = (bufsz == 32)? (0xffffffff >> shift) : (0xffffffffffffffff >> shift)
    ;

    while(size_t(e - b) >= sizeof(buffer_t)) {
      auto p = reinterpret_cast<const buffer_t*>(b);

      if constexpr(bufsz == 32) {
        if(!cb(__builtin_bswap32(*p) & mask)) { return false; }
      }
      else {
        if(!cb(__builtin_bswap64(*p) & mask)) { return false; }
      }

      b += _bits / 8;
    }

    buffer_t buf = 0;
    memcpy(&buf, b, e - b);

    if constexpr(bufsz == 32) {
      if(!cb(__builtin_bswap32(buf) & mask)) { return false; }
    }
    else {
      if(!cb(__builtin_bswap64(buf) & mask)) { return false; }
    }

    return true;
  }
}

} // namespace lmcu::bits
