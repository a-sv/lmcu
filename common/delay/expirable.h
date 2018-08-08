#pragma once

namespace lmcu {
namespace delay {

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

} // namespace delay
} // namespace lmcu
