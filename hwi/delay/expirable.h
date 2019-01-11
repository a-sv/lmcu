#pragma once

namespace lmcu::delay {

class expirable
{
public:
  virtual bool expired() const = 0;
};

class inf : public expirable
{
public:
  bool expired() const final { return false; }
};

} // namespace lmcu::delay
