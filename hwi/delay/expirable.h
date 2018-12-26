#pragma once

namespace lmcu::delay {

class expirable
{
public:
  virtual ~expirable() = default;
  virtual bool expired() const = 0;
};

class inf : public expirable
{
public:
  bool expired() const final { return false; }
};

} // namespace lmcu::delay
