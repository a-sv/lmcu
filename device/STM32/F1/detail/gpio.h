#pragma once

namespace detail {

template<uint32_t r, port _port, bool low, typename pin, typename ...args>
constexpr auto cr_bits()
{
  constexpr auto cr_cnf = []() -> decltype(r)
  {
    if constexpr(pin().mode == mode::analog) { return 0; }

    if constexpr(pin().mode == mode::input) {
      if constexpr(pin().pull == pull::no_pull) { return 0b01; }
      if constexpr(pin().pull == pull::down || pin().pull == pull::up) { return 0b10;}
    }

    if constexpr(pin().mode == mode::output_push_pull) { return 0; }
    if constexpr(pin().mode == mode::output_open_drain) { return 0b01; }
    if constexpr(pin().mode == mode::af_push_pull) { return 0b10; }
    if constexpr(pin().mode == mode::af_open_drain) { return 0b11; }
  };

  constexpr auto cr_mode = []() -> decltype(r)
  {
    if constexpr(pin().mode == mode::input || pin().mode == mode::analog) { return 0; }
    if constexpr(pin().speed == speed::low) { return 0b10; }
    if constexpr(pin().speed == speed::medium) { return 0b01; }
    if constexpr(pin().speed == speed::high || pin().speed == speed::very_high) { return 0b11; }
  };

  [[maybe_unused]] constexpr auto cr = (cr_cnf() << 2) | cr_mode();

  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(pin().port == _port) {
      if constexpr(low) {
        if constexpr(pin().bit < 8) { return r | (cr << (pin().bit * 4)); }
      }
      else {
        if constexpr(pin().bit >= 8) { return r | (cr << ((pin().bit - 8) * 4)); }
      }
    }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return cr_bits<bits(), _port, low, args...>(); }
  return bits();
}

template<uint32_t r, port _port, typename pin, typename ...args>
constexpr auto pull_bits()
{
  if constexpr(pin().pull != pull::no_pull) {
    static_assert(pin().mode == mode::input || pin().mode == mode::analog,
                  "pull's supported only in input pin mode");
  }

  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(pin().port == _port && pin().pull != pull::no_pull) {
      if constexpr(pin().pull == pull::up) {
        return r | (1 << pin().bit);
      }
      return r | (0x10000 << pin().bit);
    }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return pull_bits<bits(), _port, args...>(); }
  return bits();
}

template<port _port, typename ...args>
void configure(GPIO_TypeDef *inst)
{
  if constexpr(!detail::has_port<_port, args...>()) { return; }

  if constexpr(pin_in_range<_port, 0, 7, args...>()) {
    constexpr auto mask4 = ~mask<0, 4, _port, 0, 0, 7, args...>();
    inst->CRL = (inst->CRL & mask4) | cr_bits<0, _port, true, args...>();
  }

  if constexpr(pin_in_range<_port, 8, 15, args...>()) {
    constexpr auto mask4 = ~mask<0, 4, _port, 8, 8, 15, args...>();
    inst->CRH = (inst->CRH & mask4) | cr_bits<0, _port, false, args...>();
  }

  constexpr auto pb = pull_bits<0, _port, args...>();
  if constexpr(pb != 0) { inst->BSRR = pb; }
}

template<uint32_t r, port arg1, port ...args>
constexpr auto rcc_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
#if defined(RCC_APB2ENR_IOPAEN)
    if constexpr(arg1 == port::A) { return r | RCC_APB2ENR_IOPAEN; }
#endif

#if defined(RCC_APB2ENR_IOPBEN)
    if constexpr(arg1 == port::B) { return r | RCC_APB2ENR_IOPBEN; }
#endif

#if defined(RCC_APB2ENR_IOPCEN)
    if constexpr(arg1 == port::C) { return r | RCC_APB2ENR_IOPCEN; }
#endif

#if defined(RCC_APB2ENR_IOPEEN)
    if constexpr(arg1 == port::E) { return r | RCC_APB2ENR_IOPEEN; }
#endif

#if defined(RCC_APB2ENR_IOPFEN)
    if constexpr(arg1 == port::F) { return r | RCC_APB2ENR_IOPFEN; }
#endif

#if defined(RCC_APB2ENR_IOPGEN)
    if constexpr(arg1 == port::G) { return r | RCC_APB2ENR_IOPGEN; }
#endif

#if defined(RCC_APB2ENR_IOPHEN)
    if constexpr(arg1 == port::H) { return r | RCC_APB2ENR_IOPHEN; }
#endif

#if defined(RCC_APB2ENR_IOPIEN)
    if constexpr(arg1 == port::I) { return r | RCC_APB2ENR_IOPIEN; }
#endif

#if defined(RCC_APB2ENR_IOPJEN)
    if constexpr(arg1 == port::J) { return r | RCC_APB2ENR_IOPJEN; }
#endif

#if defined(RCC_APB2ENR_IOPKEN)
    if constexpr(arg1 == port::K) { return r | RCC_APB2ENR_IOPKEN; }
#endif
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return rcc_bits<bits(), args...>(); }
  return bits();
}

} // namespace detail
