#pragma once
#include "gpio_v.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::gpio {
// ------------------------------------------------------------------------------------------------

template <auto ..._args>
using PF0 = pin<option::null, port::F, pin_n(0), _args...>;

template <auto ..._args>
using PF1 = pin<option::null, port::F, pin_n(1), _args...>;

template <auto ..._args>
using PF2 = pin<option::null, port::F, pin_n(2), _args...>;

template <auto ..._args>
using PF3 = pin<option::null, port::F, pin_n(3), _args...>;

template <auto ..._args>
using PF4 = pin<option::null, port::F, pin_n(4), _args...>;

template <auto ..._args>
using PF5 = pin<option::null, port::F, pin_n(5), _args...>;

template <auto ..._args>
using PF6 = pin<option::null, port::F, pin_n(6), _args...>;

template <auto ..._args>
using PF7 = pin<option::null, port::F, pin_n(7), _args...>;

template <auto ..._args>
using PF8 = pin<option::null, port::F, pin_n(8), _args...>;

template <auto ..._args>
using PF9 = pin<option::null, port::F, pin_n(9), _args...>;

template <auto ..._args>
using PF10 = pin<option::null, port::F, pin_n(10), _args...>;

template <auto ..._args>
using PF11 = pin<option::null, port::F, pin_n(11), _args...>;

template <auto ..._args>
using PF12 = pin<option::null, port::F, pin_n(12), _args...>;

template <auto ..._args>
using PF13 = pin<option::null, port::F, pin_n(13), _args...>;

template <auto ..._args>
using PF14 = pin<option::null, port::F, pin_n(14), _args...>;

template <auto ..._args>
using PF15 = pin<option::null, port::F, pin_n(15), _args...>;


template <auto ..._args>
using PG0 = pin<option::null, port::G, pin_n(0), _args...>;

template <auto ..._args>
using PG1 = pin<option::null, port::G, pin_n(1), _args...>;

template <auto ..._args>
using PG2 = pin<option::null, port::G, pin_n(2), _args...>;

template <auto ..._args>
using PG3 = pin<option::null, port::G, pin_n(3), _args...>;

template <auto ..._args>
using PG4 = pin<option::null, port::G, pin_n(4), _args...>;

template <auto ..._args>
using PG5 = pin<option::null, port::G, pin_n(5), _args...>;

template <auto ..._args>
using PG6 = pin<option::null, port::G, pin_n(6), _args...>;

template <auto ..._args>
using PG7 = pin<option::null, port::G, pin_n(7), _args...>;

template <auto ..._args>
using PG8 = pin<option::null, port::G, pin_n(8), _args...>;

template <auto ..._args>
using PG9 = pin<option::null, port::G, pin_n(9), _args...>;

template <auto ..._args>
using PG10 = pin<option::null, port::G, pin_n(10), _args...>;

template <auto ..._args>
using PG11 = pin<option::null, port::G, pin_n(11), _args...>;

template <auto ..._args>
using PG12 = pin<option::null, port::G, pin_n(12), _args...>;

template <auto ..._args>
using PG13 = pin<option::null, port::G, pin_n(13), _args...>;

template <auto ..._args>
using PG14 = pin<option::null, port::G, pin_n(14), _args...>;

template <auto ..._args>
using PG15 = pin<option::null, port::G, pin_n(15), _args...>;

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::gpio
// ------------------------------------------------------------------------------------------------
