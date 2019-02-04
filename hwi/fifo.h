#pragma once
#include <lmcu/lock>
#include "delay/expirable.h"

namespace lmcu {

template <typename _type, auto _count, typename _idx_type = uint8_t>
class fifo
{
  static constexpr auto invalid_index = _count;

  static inline bool is_valid_index(_idx_type idx) { return idx < invalid_index; }
public:
  class push_ref
  {
    friend class fifo;
  public:
    push_ref(const push_ref &rhs) = delete;
    void operator =(const push_ref &rhs) = delete;

    void operator =(push_ref&& rhs)
    {
      lmcu_disable_irq();

      reset();
      f_       = rhs.f_;
      idx_     = rhs.idx_;
      rhs.idx_ = invalid_index;
    }

    push_ref(push_ref&& rhs)
    : f_(rhs.f_)
    {
      lmcu_disable_irq();

      reset();
      idx_     = rhs.idx_;
      rhs.idx_ = invalid_index;
    }

    inline ~push_ref() { reset(); }

    inline bool is_valid() const { return is_valid_index(idx_); }
    inline operator bool() const { return is_valid(); }
    inline auto operator ->() const { return &item(idx_).data_; }
    inline auto &operator *() const { return item(idx_).data_; }

    /**
     * Release the element held by a reference
    */
    void reset()
    {
      lmcu_disable_irq();
      if(!is_valid()) { return; }

      if(is_valid_index(f_.first_busy_)) {
        item(f_.last_busy_).next_ = idx_;
        f_.last_busy_ = idx_;
      }
      else {
        f_.first_busy_ = f_.last_busy_ = idx_;
      }
      f_.size_++;

      idx_ = invalid_index;
    }
  private:
    explicit push_ref(fifo &f)
    : f_(f)
    {
      lmcu_disable_irq();

      idx_ = f_.empty_;
      if(is_valid()) {
        f_.empty_ = item(idx_).next_;
        item(idx_).next_ = invalid_index;
      }
    }

    explicit push_ref(fifo &f, bool)
    : f_(f)
    { }

    inline auto &item(_idx_type idx) const { return f_.items_[idx]; }

    _idx_type idx_ = invalid_index;
    fifo &f_;
  };

  class pop_ref
  {
    friend class fifo;
  public:
    pop_ref(const pop_ref &rhs) = delete;
    void operator =(const pop_ref &rhs) = delete;

    void operator =(pop_ref&& rhs)
    {
      lmcu_disable_irq();

      reset();
      f_       = rhs.f_;
      idx_     = rhs.idx_;
      rhs.idx_ = invalid_index;
    }

    pop_ref(pop_ref&& rhs)
    : f_(rhs.f_)
    {
      lmcu_disable_irq();

      reset();
      idx_     = rhs.idx_;
      rhs.idx_ = invalid_index;
    }

    ~pop_ref() { reset(); }

    bool is_valid() const { return is_valid_index(idx_); }
    operator bool() const { return is_valid(); }
    auto operator ->() const { return &item(idx_).data_; }
    auto &operator *() const { return item(idx_).data_; }

    /**
     * Release the element held by a reference
    */
    void reset()
    {
      lmcu_disable_irq();

      if(!is_valid()) { return; }

      item(idx_).next_ = f_.empty_;
      f_.empty_ = idx_;

      f_.size_--;
    }
  private:
    explicit pop_ref(fifo &f)
    : f_(f)
    {
      lmcu_disable_irq();

      idx_ = f_.first_busy_;
      if(is_valid()) {
        f_.first_busy_ = item(idx_).next_;
      }
    }

    explicit pop_ref(fifo &f, bool)
    : f_(f)
    { }

    auto &item(_idx_type idx) const { return f_.items_[idx]; }

    _idx_type idx_ = invalid_index;
    fifo &f_;
  };

  fifo()
  {
    lmcu_disable_irq();

    _idx_type n = 0;
    for(auto&& it : items_) { it.next_ = n + 1; ++n; }
  }

  /**
   * Return reference to first element in fifo
   *
   * @return  - reference to _type
   * @warning - Unsafe function! Interrupt may overwrite data. Protect result by lmcu_disable_irq
   *            if you using FIFO with interrupts.
  */
  _type &first() { return items_[first_busy_].data_; }

  /**
   * Return reference to last element in fifo
   *
   * @return  - reference to _type
   * @warning - Unsafe function! Interrupt may overwrite data. Protect result by lmcu_disable_irq
   *            if you using FIFO with interrupts.
  */
  _type &last()  { return items_[last_busy_].data_; }

  /**
   * Fetch an empty element in the push_ref constructor and puts it to FIFO in the destructor.
   *
   * @return - push_ref
  */
  inline auto push() { return push_ref(*this); }

  /**
   * Fetch an empty element in the push_ref constructor and puts it to FIFO in the destructor.
   *
   * @param t - timeout
   * @return - push_ref
  */
  auto push(const delay::expirable &t)
  {
    while(!t.expired()) {
      auto ref = push();
      if(ref) { return ref; }
    }
    return push_ref(*this, true);
  }

  /**
   * Fetch busy element from FIFO in the pop_ref constructor and puts it to empty list in the
   * destructor.
   *
   * @return - pop_ref
  */
  inline auto pop() { return pop_ref(*this); }

  /**
   * Fetch busy element from FIFO in the pop_ref constructor and puts it to empty list in the
   * destructor.
   *
   * @param t - timeout
   * @return - pop_ref
  */
  auto pop(const delay::expirable &t)
  {
    while(!t.expired()) {
      auto ref = pop();
      if(ref) { return ref; }
    }
    return pop_ref(*this, true);
  }

  /**
   * Remove all elements from FIFO.
  */
  void clear()
  {
    lmcu_disable_irq();

    while(is_valid_index(first_busy_)) {
      auto next = items_[first_busy_].next_;

      items_[first_busy_].next_ = empty_;
      empty_ = first_busy_;

      first_busy_ = next;
    }
  }

  /**
   * Return true if FIFO empty.
  */
  inline auto empty() const { return !is_valid_index(first_busy_); }

  /**
   * Return FIFO size.
  */
  inline auto size() const { return size_; }

  /**
   * Return max count of elements may stored in FIFO.
  */
  inline auto capacity() const { return _count; }
private:
  struct item
  {
    _type data_;
    _idx_type next_;
  };

  _idx_type size_       = 0;
  _idx_type first_busy_ = invalid_index; // first busy
  _idx_type last_busy_  = invalid_index; // last busy
  _idx_type empty_      = 0;             // first empty

  item items_[_count];
};

} // namespace lmcu
