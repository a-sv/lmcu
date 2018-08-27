#pragma once
#include <lmcu/lock>

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

    push_ref(push_ref&& rhs)
    : f_(rhs.f_)
    {
      lmcu_scoped_lock();

      reset();
      idx_     = rhs.idx_;
      rhs.idx_ = invalid_index;
    }

    inline ~push_ref() { reset(); }

    inline bool is_valid() const { return is_valid_index(idx_); }
    inline operator bool() const { return is_valid(); }
    inline auto operator ->() const { return &item(idx_).data_; }
    inline auto &operator *() const { return item(idx_).data_; }

    void reset()
    {
      lmcu_scoped_lock();
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
      lmcu_scoped_lock();

      idx_ = f_.empty_;
      if(is_valid()) {
        f_.empty_ = item(idx_).next_;
        item(idx_).next_ = invalid_index;
      }
    }

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

    pop_ref(pop_ref&& rhs)
    : f_(rhs.f_)
    {
      lmcu_scoped_lock();

      reset();
      idx_     = rhs.idx_;
      rhs.idx_ = invalid_index;
    }

    ~pop_ref() { reset(); }

    bool is_valid() const { return is_valid_index(idx_); }
    operator bool() const { return is_valid(); }
    auto operator ->() const { return &item(idx_).data_; }
    auto &operator *() const { return item(idx_).data_; }

    void reset()
    {
      lmcu_scoped_lock();

      if(!is_valid()) { return; }

      item(idx_).next_ = f_.empty_;
      f_.empty_ = idx_;

      f_.size_--;
    }
  private:
    explicit pop_ref(fifo &f)
    : f_(f)
    {
      lmcu_scoped_lock();

      idx_ = f_.first_busy_;
      if(is_valid()) {
        f_.first_busy_ = item(idx_).next_;
      }
    }

    auto &item(_idx_type idx) const { return f_.items_[idx]; }

    _idx_type idx_ = invalid_index;
    fifo &f_;
  };

  _type &first() { return items_[first_busy_].data_; }
  _type &last()  { return items_[last_busy_].data_;  }

  fifo()
  {
    lmcu_scoped_lock();

    _idx_type n = 0;
    for(auto &it : items_) { it.next_ = n + 1; ++n; }
    size_       = 0;
    first_busy_ = invalid_index;
    last_busy_  = invalid_index;
    empty_      = 0;
  }

  inline auto push() { return push_ref(*this); }
  inline auto pop() { return pop_ref(*this); }

  void clear()
  {
    lmcu_scoped_lock();

    while(is_valid_index(first_busy_)) {
      auto next = items_[first_busy_].next_;

      items_[first_busy_].next_ = empty_;
      empty_ = first_busy_;

      first_busy_ = next;
    }
  }

  inline auto empty() const { return !is_valid_index(first_busy_); }
  inline auto size() const { return size_; }
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
