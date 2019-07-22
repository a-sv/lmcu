#include "../i2c.h"

namespace lmcu::io {
using namespace i2c;

#if defined(I2C1)

template<>
buf<module_id::i2c1> *buf<module_id::i2c1>::get()
{
  static buf<module_id::i2c1> buf;
  return &buf;
}

#endif

#if defined(I2C2)

template<>
buf<module_id::i2c2> *buf<module_id::i2c2>::get()
{
  static buf<module_id::i2c2> buf;
  return &buf;
}

#endif

#if defined(I2C3)

template<>
buf<module_id::i2c3> *buf<module_id::i2c3>::get()
{
  static buf<module_id::i2c3> buf;
  return &buf;
}

#endif

} // namespace lmcu::io

namespace lmcu::i2c::detail {

#if defined(I2C1)

template<>
state<module_id::i2c1> *state<module_id::i2c1>::get()
{
  static state<module_id::i2c1> s;
  return &s;
}

#endif

#if defined(I2C2)

template<>
state<module_id::i2c2> *state<module_id::i2c2>::get()
{
  static state<module_id::i2c2> s;
  return &s;
}

#endif

#if defined(I2C3)

template<>
state<module_id::i2c3> *state<module_id::i2c3>::get()
{
  static state<module_id::i2c3> s;
  return &s;
}

#endif

} // namespace lmcu::i2c::detail
