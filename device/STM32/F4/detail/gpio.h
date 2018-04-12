#pragma once

namespace detail {

template<uint32_t r, port _port, typename pin, typename ...args>
constexpr auto mode_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(pin().port != _port) { return r; }

    if constexpr(pin().mode == mode::output_open_drain || pin().mode == mode::output_push_pull) {
      return r | (0b01 << (pin().bit * 2));
    }

    if constexpr(pin().mode == mode::af_open_drain || pin().mode == mode::af_push_pull) {
      return r | (0b10 << (pin().bit * 2));
    }

    if constexpr(pin().mode == mode::analog) {
      return r | (0b11 << (pin().bit * 2));
    }

    return r; // mode::input
  };

  if constexpr(sizeof...(args) > 0) { return mode_bits<bits(), _port, args...>(); }
  return bits();
}

template<uint32_t r, port _port, typename pin, typename ...args>
constexpr auto otype_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(pin().port == _port && (pin().mode == mode::output_open_drain ||
                                         pin().mode == mode::af_open_drain)) {
      return r | pin().mask;
    }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return otype_bits<bits(), _port, args...>(); }
  return bits();
}

template<uint32_t r, port _port, typename pin, typename ...args>
constexpr auto ospeed_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(pin().port == _port) {
      if constexpr(pin().speed == speed::medium)    { return 0b01 << (pin().bit * 2); }
      if constexpr(pin().speed == speed::high)      { return 0b10 << (pin().bit * 2); }
      if constexpr(pin().speed == speed::very_high) { return 0b11 << (pin().bit * 2); }
      return 0; // speed::low
    }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return ospeed_bits<bits(), _port, args...>(); }
  return bits();
}

template<uint32_t r, port _port, typename pin, typename ...args>
constexpr auto pull_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(pin().port == _port) {
      if constexpr(pin().pull == pull::up)   { return 0b01 << (pin().bit * 2); }
      if constexpr(pin().pull == pull::down) { return 0b10 << (pin().bit * 2); }
      return 0; // pull::no_pull
    }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return pull_bits<bits(), _port, args...>(); }
  return bits();
}

template<uint32_t r, port _port, bool low, typename pin, typename ...args>
constexpr auto afr_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(pin().port == _port) {
      constexpr auto af = static_cast<uint32_t>(pin().af);

      if constexpr(low) {
        if constexpr(pin().bit < 8) { return r | (af << (pin().bit * 4)); }
      }
      else {
        if constexpr(pin().bit >= 8) { return r | (af << ((pin().bit - 8) * 4)); }
      }
    }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return afr_bits<bits(), _port, low, args...>(); }
  return bits();
}

template<port _port, typename ...args>
void configure(GPIO_TypeDef *inst)
{
  if constexpr(detail::has_port<_port, args...>()) {
    constexpr auto mask1 = ~mask<0, 1, _port, 0, 0, 15, args...>();
    constexpr auto mask2 = ~mask<0, 2, _port, 0, 0, 15, args...>();

    inst->MODER = (inst->MODER & mask2) | mode_bits<0, _port, args...>();
    inst->OTYPER = (inst->OTYPER & mask1) | otype_bits<0, _port, args...>();
    inst->OSPEEDR = (inst->OSPEEDR & mask2) | ospeed_bits<0, _port, args...>();
    inst->PUPDR = (inst->PUPDR & mask2) | pull_bits<0, _port, args...>();

    if constexpr(pin_in_range<_port, 0, 7, args...>()) {
      constexpr auto mask4 = ~mask<0, 4, _port, 0, 0, 7, args...>();
      inst->AFR[0] = (inst->AFR[0] & mask4) | afr_bits<0, _port, true, args...>();
    }

    if constexpr(pin_in_range<_port, 8, 15, args...>()) {
      constexpr auto mask4 = ~mask<0, 4, _port, 8, 8, 15, args...>();
      inst->AFR[1] = (inst->AFR[1] & mask4) | afr_bits<0, _port, false, args...>();
    }
  }
}

} // namespace detail
