#pragma once
#include <cstdint>

namespace lmcu {

template<typename _type, std::intptr_t _ptr>
struct mem_ptr
{
  operator volatile _type *() const { return reinterpret_cast<volatile _type*>(addr_); }
  volatile _type *operator->() const { return operator volatile _type *(); }
private:
  std::intptr_t addr_ = _ptr;
};

} // namespace lmcu
