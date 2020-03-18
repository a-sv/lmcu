#pragma once

namespace lmcu::delay {

class expirable
{
public:
  virtual bool expired() const = 0;
  inline void wait() const { while(!expired()); }
};

class inf : public expirable
{
public:
  bool expired() const final { return false; }
};

} // namespace lmcu::delay