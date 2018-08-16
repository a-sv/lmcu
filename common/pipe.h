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
  /**
   * Read data from PIPE
   *
   * @param data - ptr to dst buffer
   * @param sz   - size to read
   * @param n    - size of the really readed
   *
   * @return     - io::result::busy if PIPE empty otherwise io::result::success
  */
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

  /**
   * Read data from PIPE
   *
   * @param data - ptr to dst buffer
   * @param sz   - size to read
   * @param n    - size of the really readed
   * @param t    - timeout
   *
   * @return     - io::result::busy if PIPE empty and timeout occurred otherwise io::result::success
  */
  inline io::result read(void *data, _sz_type sz, _sz_type &n, const delay::expirable &t)
  {
    auto rc = io::result::busy;
    while(!t.expired() && rc == io::result::busy) { rc = read(data, sz, n); }
    return rc;
  }

  /**
   * Fetch one byte from PIPE
   *
   * @param data - dst buffer
   *
   * @return     - io::result::busy if PIPE empty otherwise io::result::success
  */
  io::result getb(uint8_t &data)
  {
    lmcu_scoped_lock();

    if(ovf_) {
      if(r_ >= end()) { ovf_ = false; r_ = beg(); }
    }
    if(!ovf_ && (r_ >= w_)) { return io::result::busy; }

    data = *r_++;

    return io::result::success;
  }

  /**
   * Fetch one byte from PIPE
   *
   * @param data - dst buffer
   *
   * @return     - io::result::busy if PIPE empty and timeout occurred otherwise io::result::success
  */
  inline io::result getb(uint8_t &data, const delay::expirable &t)
  {
    auto rc = io::result::busy;
    while(!t.expired() && rc == io::result::busy) { rc = getb(data); }
    return rc;
  }

  /**
   * Write data to PIPE
   *
   * @param data - ptr to data
   * @param sz   - size to write
   * @param n    - size of the really writed
   *
   * @return     - io::result::busy if PIPE full otherwise io::result::success
  */
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

  /**
   * Write data to PIPE
   *
   * @param data - ptr to data
   * @param sz   - size to write
   * @param n    - size of the really writed
   *
   * @return     - io::result::busy if PIPE full and timeout occurred otherwise io::result::success
  */
  inline io::result write(void *data, _sz_type sz, _sz_type &n, const delay::expirable &t)
  {
    auto rc = io::result::busy;
    while(!t.expired() && rc == io::result::busy) { rc = write(data, sz, n); }
    return rc;
  }

  /**
   * Put one byte to PIPE
   *
   * @param data - data to write
   *
   * @return     - io::result::busy if PIPE full and otherwise io::result::success
  */
  io::result putb(uint8_t data)
  {
    lmcu_scoped_lock();

    if(!ovf_) {
      if(w_ >= end()) { ovf_ = true; w_ = beg(); }
    }
    if(ovf_ && w_ >= r_) { return io::result::busy; }

    *w_++ = data;

    return io::result::success;
  }

  /**
   * Put one byte to PIPE
   *
   * @param data - data to write
   *
   * @return     - io::result::busy if PIPE full and timeout occurred otherwise io::result::success
  */
  inline io::result putb(uint8_t data, const delay::expirable &t)
  {
    auto rc = io::result::busy;
    while(!t.expired() && rc == io::result::busy) { rc = putb(data); }
    return rc;
  }

  /**
   * Data size stored in PIPE
  */
  inline _sz_type size() const
  {
    lmcu_scoped_lock();

    if(ovf_) { return (end() - r_) + (w_ - beg()); }
    return w_ - r_;
  }

  /**
   * Maximum size of data can be stored in the PIPE
  */
  constexpr _sz_type capacity() const { return _b_sz; }

  /**
   * Return true if no data in PIPE
  */
  inline bool empty() const { return size() == 0; }
private:
  uint8_t buf_[_b_sz];
  uint8_t *r_ = beg(), *w_ = beg();
  bool ovf_ = false;

  inline const uint8_t *beg() const { return buf_; }
  inline uint8_t *beg() { return buf_; }
  inline const uint8_t *end() const { return buf_ + _b_sz; }
  inline uint8_t *end() { return buf_ + _b_sz; }
};

} // namespace lmcu
