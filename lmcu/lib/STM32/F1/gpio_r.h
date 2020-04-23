#pragma once
#include "gpio_c.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::gpio {
// ------------------------------------------------------------------------------------------------

template <auto ..._args>
using PC0 = pin<option::null, port::C, pin_n(0), _args...>;

template <auto ..._args>
using PC1 = pin<option::null, port::C, pin_n(1), _args...>;

template <auto ..._args>
using PC2 = pin<option::null, port::C, pin_n(2), _args...>;

template <auto ..._args>
using PC3 = pin<option::null, port::C, pin_n(3), _args...>;

template <auto ..._args>
using PC4 = pin<option::null, port::C, pin_n(4), _args...>;

template <auto ..._args>
using PC5 = pin<option::null, port::C, pin_n(5), _args...>;

template <auto ..._args>
using PC6 = pin<option::null, port::C, pin_n(6), _args...>;

template <auto ..._args>
using PC7 = pin<option::null, port::C, pin_n(7), _args...>;

template <auto ..._args>
using PC8 = pin<option::null, port::C, pin_n(8), _args...>;

template <auto ..._args>
using PC9 = pin<option::null, port::C, pin_n(9), _args...>;

template <auto ..._args>
using PC10 = pin<option::null, port::C, pin_n(10), _args...>;

template <auto ..._args>
using PC11 = pin<option::null, port::C, pin_n(11), _args...>;

template <auto ..._args>
using PC12 = pin<option::null, port::C, pin_n(12), _args...>;

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::gpio
// ------------------------------------------------------------------------------------------------
