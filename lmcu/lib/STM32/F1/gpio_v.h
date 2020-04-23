#pragma once
#include "gpio_r.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::gpio {
// ------------------------------------------------------------------------------------------------

template <auto ..._args>
using PD2 = pin<option::null, port::D, pin_n(2), _args...>;

template <auto ..._args>
using PD3 = pin<option::null, port::D, pin_n(3), _args...>;

template <auto ..._args>
using PD4 = pin<option::null, port::D, pin_n(4), _args...>;

template <auto ..._args>
using PD5 = pin<option::null, port::D, pin_n(5), _args...>;

template <auto ..._args>
using PD6 = pin<option::null, port::D, pin_n(6), _args...>;

template <auto ..._args>
using PD7 = pin<option::null, port::D, pin_n(7), _args...>;

template <auto ..._args>
using PD8 = pin<option::null, port::D, pin_n(8), _args...>;

template <auto ..._args>
using PD9 = pin<option::null, port::D, pin_n(9), _args...>;

template <auto ..._args>
using PD10 = pin<option::null, port::D, pin_n(10), _args...>;

template <auto ..._args>
using PD11 = pin<option::null, port::D, pin_n(11), _args...>;

template <auto ..._args>
using PD12 = pin<option::null, port::D, pin_n(12), _args...>;

template <auto ..._args>
using PD13 = pin<option::null, port::D, pin_n(13), _args...>;

template <auto ..._args>
using PD14 = pin<option::null, port::D, pin_n(14), _args...>;

template <auto ..._args>
using PD15 = pin<option::null, port::D, pin_n(15), _args...>;


template <auto ..._args>
using PE0 = pin<option::null, port::E, pin_n(0), _args...>;

template <auto ..._args>
using PE1 = pin<option::null, port::E, pin_n(1), _args...>;

template <auto ..._args>
using PE2 = pin<option::null, port::E, pin_n(2), _args...>;

template <auto ..._args>
using PE3 = pin<option::null, port::E, pin_n(3), _args...>;

template <auto ..._args>
using PE4 = pin<option::null, port::E, pin_n(4), _args...>;

template <auto ..._args>
using PE5 = pin<option::null, port::E, pin_n(5), _args...>;

template <auto ..._args>
using PE6 = pin<option::null, port::E, pin_n(6), _args...>;

template <auto ..._args>
using PE7 = pin<option::null, port::E, pin_n(7), _args...>;

template <auto ..._args>
using PE8 = pin<option::null, port::E, pin_n(8), _args...>;

template <auto ..._args>
using PE9 = pin<option::null, port::E, pin_n(9), _args...>;

template <auto ..._args>
using PE10 = pin<option::null, port::E, pin_n(10), _args...>;

template <auto ..._args>
using PE11 = pin<option::null, port::E, pin_n(11), _args...>;

template <auto ..._args>
using PE12 = pin<option::null, port::E, pin_n(12), _args...>;

template <auto ..._args>
using PE13 = pin<option::null, port::E, pin_n(13), _args...>;

template <auto ..._args>
using PE14 = pin<option::null, port::E, pin_n(14), _args...>;

template <auto ..._args>
using PE15 = pin<option::null, port::E, pin_n(15), _args...>;

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::gpio
// ------------------------------------------------------------------------------------------------
