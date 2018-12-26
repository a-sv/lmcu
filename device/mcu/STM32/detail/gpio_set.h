#if defined(GPIOA)
  if constexpr(pins_in_port<port::A, _pins...>()) {
    GPIOA->BSRR = mask<port::A, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOB)
  if constexpr(pins_in_port<port::B, _pins...>()) {
    GPIOB->BSRR = mask<port::B, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOC)
  if constexpr(pins_in_port<port::C, _pins...>()) {
    GPIOC->BSRR = mask<port::C, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOD)
  if constexpr(pins_in_port<port::D, _pins...>()) {
    GPIOD->BSRR = mask<port::D, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOE)
  if constexpr(pins_in_port<port::E, _pins...>()) {
    GPIOE->BSRR = mask<port::E, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOF)
  if constexpr(pins_in_port<port::F, _pins...>()) {
    GPIOF->BSRR = mask<port::F, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOG)
  if constexpr(pins_in_port<port::G, _pins...>()) {
    GPIOG->BSRR = mask<port::G, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOH)
  if constexpr(pins_in_port<port::H, _pins...>()) {
    GPIOH->BSRR = mask<port::H, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOI)
  if constexpr(pins_in_port<port::I, _pins...>()) {
    GPIOI->BSRR = mask<port::I, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOJ)
  if constexpr(pins_in_port<port::J, _pins...>()) {
    GPIOJ->BSRR = mask<port::J, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif

#if defined(GPIOK)
  if constexpr(pins_in_port<port::K, _pins...>()) {
    GPIOK->BSRR = mask<port::K, 1, 0, 0, 15, _pins...>() << (val? 0 : 16);
  }
#endif
