#pragma once
#include <cstring>
#include <lmcu/lock>
#include "io.h"
#include "delay/expirable.h"

namespace lmcu {

template<typename _sz_type, _sz_type _b_sz>
class pipe
{
public:
  io::result read(void *data, _sz_type sz, _sz_type &n)
  {
    auto rc = io::result::success;
    auto b = static_cast<uint8_t*>(data), e = b + sz;

    _sz_type avail;

    lmcu_scoped_lock();

    while(b < e) {
      if(ovf_) {
        avail = end() - r_;
        if(avail == 0) {
          ovf_ = false;
          r_   = beg();
          if(r_ >= w_) { rc = io::result::busy; break; }
          avail = w_ - r_;
        }
      }
      else {
        if(r_ >= w_) { rc = io::result::busy; break; }
        avail = w_ - r_;
      }

      _sz_type total = e - b;

      avail = (total < avail)? total : avail;
      memcpy(b, r_, avail);

      r_ += avail;
      b  += avail;
    }

    n = b - static_cast<const uint8_t*>(data);
    return rc;
  }

  io::result read(void *data, _sz_type sz, _sz_type &n, const delay::expirable &t)
  {
    auto rc = io::result::busy;
    while(!t.expired() && rc == io::result::busy) { rc = read(data, sz, n); }
    return rc;
  }

  io::result write(const void *data, _sz_type sz, _sz_type &n)
  {
    auto rc = io::result::success;
    auto b = static_cast<const uint8_t*>(data), e = b + sz;

    _sz_type avail;

    lmcu_scoped_lock();

    while(b < e) {
      if(ovf_) {
        if(w_ >= r_) { rc = io::result::busy; break; }
        avail = r_ - w_;
      }
      else {
        avail = end() - w_;
        if(avail == 0) {
          ovf_ = true;
          w_   = beg();
          if(w_ >= r_) { rc = io::result::busy; break; }
          avail = r_ - w_;
        }
      }

      _sz_type total = e - b;

      avail = (total < avail)? total : avail;
      memcpy(w_, b, avail);

      w_ += avail;
      b  += avail;
    }

    n = b - static_cast<const uint8_t*>(data);
    return rc;
  }

  io::result write(void *data, _sz_type sz, _sz_type &n, const delay::expirable &t)
  {
    auto rc = io::result::busy;
    while(!t.expired() && rc == io::result::busy) { rc = write(data, sz, n); }
    return rc;
  }
private:
  uint8_t buf_[_b_sz];
  uint8_t *r_ = beg(), *w_ = beg();
  bool ovf_ = false;

  inline const uint8_t *beg() const { return buf_; };
  inline uint8_t *beg() { return buf_; };
  inline const uint8_t *end() const { return buf_ + _b_sz; }
  inline uint8_t *end() { return buf_ + _b_sz; }
};

} // namespace lmcu
