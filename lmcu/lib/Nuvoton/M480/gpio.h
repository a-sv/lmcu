#pragma once
#include "ip/v1/gpio.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::gpio {
// ------------------------------------------------------------------------------------------------

template <port ..._ports>
constexpr bool port_exists() noexcept
{
  auto check = [](auto val)
  {
    return
      val == port::A ||
      val == port::B ||
      val == port::C ||
      val == port::D ||
      val == port::E ||
      val == port::F ||
      val == port::G ||
      val == port::H
    ;
  };
  return (check(_ports) && ...);
}


template <auto ..._args>
using PA0 = pin<option::null, port::A, pin_n(0), _args...>;

template <auto ..._args>
using PA1 = pin<option::null, port::A, pin_n(1), _args...>;

template <auto ..._args>
using PA2 = pin<option::null, port::A, pin_n(2), _args...>;

template <auto ..._args>
using PA3 = pin<option::null, port::A, pin_n(3), _args...>;

template <auto ..._args>
using PA4 = pin<option::null, port::A, pin_n(4), _args...>;

template <auto ..._args>
using PA5 = pin<option::null, port::A, pin_n(5), _args...>;

template <auto ..._args>
using PA6 = pin<option::null, port::A, pin_n(6), _args...>;

template <auto ..._args>
using PA7 = pin<option::null, port::A, pin_n(7), _args...>;

template <auto ..._args>
using PA8 = pin<option::null, port::A, pin_n(8), _args...>;

template <auto ..._args>
using PA9 = pin<option::null, port::A, pin_n(9), _args...>;

template <auto ..._args>
using PA10 = pin<option::null, port::A, pin_n(10), _args...>;

template <auto ..._args>
using PA11 = pin<option::null, port::A, pin_n(11), _args...>;

template <auto ..._args>
using PA12 = pin<option::null, port::A, pin_n(12), _args...>;

template <auto ..._args>
using PA13 = pin<option::null, port::A, pin_n(13), _args...>;

template <auto ..._args>
using PA14 = pin<option::null, port::A, pin_n(14), _args...>;

template <auto ..._args>
using PA15 = pin<option::null, port::A, pin_n(15), _args...>;



template <auto ..._args>
using PB0 = pin<option::null, port::B, pin_n(0), _args...>;

template <auto ..._args>
using PB1 = pin<option::null, port::B, pin_n(1), _args...>;

template <auto ..._args>
using PB2 = pin<option::null, port::B, pin_n(2), _args...>;

template <auto ..._args>
using PB3 = pin<option::null, port::B, pin_n(3), _args...>;

template <auto ..._args>
using PB4 = pin<option::null, port::B, pin_n(4), _args...>;

template <auto ..._args>
using PB5 = pin<option::null, port::B, pin_n(5), _args...>;

template <auto ..._args>
using PB6 = pin<option::null, port::B, pin_n(6), _args...>;

template <auto ..._args>
using PB7 = pin<option::null, port::B, pin_n(7), _args...>;

template <auto ..._args>
using PB8 = pin<option::null, port::B, pin_n(8), _args...>;

template <auto ..._args>
using PB9 = pin<option::null, port::B, pin_n(9), _args...>;

template <auto ..._args>
using PB10 = pin<option::null, port::B, pin_n(10), _args...>;

template <auto ..._args>
using PB11 = pin<option::null, port::B, pin_n(11), _args...>;

template <auto ..._args>
using PB12 = pin<option::null, port::B, pin_n(12), _args...>;

template <auto ..._args>
using PB13 = pin<option::null, port::B, pin_n(13), _args...>;

template <auto ..._args>
using PB14 = pin<option::null, port::B, pin_n(14), _args...>;

template <auto ..._args>
using PB15 = pin<option::null, port::B, pin_n(15), _args...>;



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

template <auto ..._args>
using PC13 = pin<option::null, port::C, pin_n(13), _args...>;

template <auto ..._args>
using PC14 = pin<option::null, port::C, pin_n(14), _args...>;



template <auto ..._args>
using PD0 = pin<option::null, port::D, pin_n(0), _args...>;

template <auto ..._args>
using PD1 = pin<option::null, port::D, pin_n(1), _args...>;

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
using PH0 = pin<option::null, port::H, pin_n(0), _args...>;

template <auto ..._args>
using PH1 = pin<option::null, port::H, pin_n(1), _args...>;

template <auto ..._args>
using PH2 = pin<option::null, port::H, pin_n(2), _args...>;

template <auto ..._args>
using PH3 = pin<option::null, port::H, pin_n(3), _args...>;

template <auto ..._args>
using PH4 = pin<option::null, port::H, pin_n(4), _args...>;

template <auto ..._args>
using PH5 = pin<option::null, port::H, pin_n(5), _args...>;

template <auto ..._args>
using PH6 = pin<option::null, port::H, pin_n(6), _args...>;

template <auto ..._args>
using PH7 = pin<option::null, port::H, pin_n(7), _args...>;

template <auto ..._args>
using PH8 = pin<option::null, port::H, pin_n(8), _args...>;

template <auto ..._args>
using PH9 = pin<option::null, port::H, pin_n(9), _args...>;

template <auto ..._args>
using PH10 = pin<option::null, port::H, pin_n(10), _args...>;

template <auto ..._args>
using PH11 = pin<option::null, port::H, pin_n(11), _args...>;


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::gpio
// ------------------------------------------------------------------------------------------------
