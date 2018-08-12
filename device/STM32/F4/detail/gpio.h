#pragma once

namespace detail {

template<port _port, typename _pin, typename ..._pins>
constexpr auto mode_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    if constexpr(_pin::port != _port) { return 0; }

    if constexpr(_pin::mode == mode::output_open_drain || _pin::mode == mode::output_push_pull) {
      return 0b01 << (_pin::bit * 2);
    }

    if constexpr(_pin::mode == mode::af_input || _pin::mode == mode::af_open_drain ||
                 _pin::mode == mode::af_push_pull) {
      return 0b10 << (_pin::bit * 2);
    }

    if constexpr(_pin::mode == mode::analog) { return 0b11 << (_pin::bit * 2); }

    return 0; // mode::input
  };

  if constexpr(sizeof...(_pins) > 0) { return bit() | mode_bits<_port, _pins...>(); }
  return bit();
}

template<port _port, typename _pin, typename ..._pins>
constexpr auto otype_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    if constexpr(_pin::port == _port && (_pin::mode == mode::output_open_drain ||
                                         _pin::mode == mode::af_open_drain)) {
      return _pin::mask;
    }
    return 0;
  };

  if constexpr(sizeof...(_pins) > 0) { return bit() | otype_bits<_port, _pins...>(); }
  return bit();
}

template<port _port, typename _pin, typename ..._pins>
constexpr auto ospeed_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    if constexpr(_pin::port == _port) {
      if constexpr(_pin::speed == speed::medium)    { return 0b01 << (_pin::bit * 2); }
      if constexpr(_pin::speed == speed::high)      { return 0b10 << (_pin::bit * 2); }
      if constexpr(_pin::speed == speed::very_high) { return 0b11 << (_pin::bit * 2); }
    }
    return 0;
  };

  if constexpr(sizeof...(_pins) > 0) { return bit() | ospeed_bits<_port, _pins...>(); }
  return bit();
}

template<port _port, typename _pin, typename ..._pins>
constexpr auto pull_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    if constexpr(_pin::port == _port) {
      if constexpr(_pin::pull == pull::up)   { return 0b01 << (_pin::bit * 2); }
      if constexpr(_pin::pull == pull::down) { return 0b10 << (_pin::bit * 2); }
    }
    return 0;
  };

  if constexpr(sizeof...(_pins) > 0) { return bit() | pull_bits<_port, _pins...>(); }
  return bit();
}

template<port _port, bool _low, typename _pin, typename ..._pins>
constexpr auto afr_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    if constexpr(_pin::port == _port) {
      [[maybe_unused]] constexpr auto af = static_cast<uint32_t>(_pin::af);

      if constexpr(_low) {
        if constexpr(_pin::bit < 8) { return af << (_pin::bit * 4); }
      }
      else {
        if constexpr(_pin::bit >= 8) { return af << ((_pin::bit - 8) * 4); }
      }
    }
    return 0;
  };

  if constexpr(sizeof...(_pins) > 0) { return bit() | afr_bits<_port, _low, _pins...>(); }
  return bit();
}

template<port _port, typename ..._pins>
void configure_port(GPIO_TypeDef *inst)
{
  if constexpr(detail::pins_in_port<_port, _pins...>()) {
    constexpr auto mask1 = ~mask<_port, 1, 0, 0, 15, _pins...>();
    constexpr auto mask2 = ~mask<_port, 2, 0, 0, 15, _pins...>();

    inst->MODER   = (inst->MODER & mask2)   | mode_bits<_port, _pins...>();
    inst->OTYPER  = (inst->OTYPER & mask1)  | otype_bits<_port, _pins...>();
    inst->OSPEEDR = (inst->OSPEEDR & mask2) | ospeed_bits<_port, _pins...>();
    inst->PUPDR   = (inst->PUPDR & mask2)   | pull_bits<_port, _pins...>();

    if constexpr(pin_in_range<_port, 0, 7, _pins...>()) {
      constexpr auto mask4 = ~mask<_port, 4, 0, 0, 7, _pins...>();
      inst->AFR[0] = (inst->AFR[0] & mask4) | afr_bits<_port, true, _pins...>();
    }

    if constexpr(pin_in_range<_port, 8, 15, _pins...>()) {
      constexpr auto mask4 = ~mask<_port, 4, 8, 8, 15, _pins...>();
      inst->AFR[1] = (inst->AFR[1] & mask4) | afr_bits<_port, false, _pins...>();
    }
  }
}

template<port _port, port ..._ports>
constexpr auto rcc_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
#if defined(GPIOA)
    if constexpr(_port == port::A) { return RCC_AHB1ENR_GPIOAEN; }
#endif

#if defined(GPIOB)
    if constexpr(_port == port::B) { return RCC_AHB1ENR_GPIOBEN; }
#endif

#if defined(GPIOC)
    if constexpr(_port == port::C) { return RCC_AHB1ENR_GPIOCEN; }
#endif

#if defined(GPIOD)
    if constexpr(_port == port::D) { return RCC_AHB1ENR_GPIODEN; }
#endif

#if defined(GPIOE)
    if constexpr(_port == port::E) { return RCC_AHB1ENR_GPIOEEN; }
#endif

#if defined(GPIOF)
    if constexpr(_port == port::F) { return RCC_AHB1ENR_GPIOFEN; }
#endif

#if defined(GPIOG)
    if constexpr(_port == port::G) { return RCC_AHB1ENR_GPIOGEN; }
#endif

#if defined(GPIOH)
    if constexpr(_port == port::H) { return RCC_AHB1ENR_GPIOHEN; }
#endif

#if defined(GPIOI)
    if constexpr(_port == port::I) { return RCC_AHB1ENR_GPIOIEN; }
#endif

#if defined(GPIOJ)
    if constexpr(_port == port::J) { return RCC_AHB1ENR_GPIOJEN; }
#endif

#if defined(GPIOK)
    if constexpr(_port == port::K) { return RCC_AHB1ENR_GPIOKEN; }
#endif
    return 0;
  };

  if constexpr(sizeof...(_ports) > 0) { return bit() | rcc_bits<_ports...>(); }
  return bit();
}

} // namespace detail
