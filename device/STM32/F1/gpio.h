#pragma once
#include "../gpio.h"

namespace lmcu {
namespace gpio {

#include "detail/gpio.h"

template<port ...args>
void enable(bool afio_on = true) { detail::enable<args...>(afio_on); }

template<port ...args>
void disable(bool afio_off = true) { detail::disable<args...>(afio_off); }

} // namespace gpio
} // namespace lmcu
