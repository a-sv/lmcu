#pragma once

namespace detail {

template<module_id _module_id>
inline USART_TypeDef *inst()
{
  switch(_module_id)
  {
#if defined(USART1)
  case module_id::usart1: return USART1;
#endif

#if defined(USART2)
  case module_id::usart2: return USART2;
#endif

#if defined(USART3)
  case module_id::usart3: return USART3;
#endif

#if defined(USART4)
  case module_id::usart4: return USART4;
#endif

#if defined(USART5)
  case module_id::usart5: return USART5;
#endif

#if defined(USART6)
  case module_id::usart6: return USART6;
#endif

#if defined(USART7)
  case module_id::usart7: return USART7;
#endif

#if defined(USART8)
  case module_id::usart8: return USART8;
#endif
  }
}

template<typename _module>
void configure_async()
{
  constexpr auto m = _module();
  auto inst = detail::inst<m.module_id>();

  {
    auto r = inst->CR1;

    if constexpr(m.data_size == data_size::ds_8) { r &= ~USART_CR1_M; } else { r |= USART_CR1_M; }

    if constexpr(m.parity != parity::disable) {
      r |= USART_CR1_PCE;
      if constexpr(m.parity == parity::even) { r &= ~USART_CR1_PS; } else { r |= USART_CR1_PS; }
    }
    else { r &= ~USART_CR1_PCE; }

    r |= USART_CR1_TE | USART_CR1_RE;

    inst->CR1 = r;
  }

  {
    auto r = inst->CR2;

    r &= ~USART_CR2_LINEN;

    r &= ~USART_CR2_STOP;
    switch(m.stop_bits)
    {
    case stop_bits::sb_0_5: r |= (1 << USART_CR2_STOP_Pos);
    case stop_bits::sb_2:   r |= (2 << USART_CR2_STOP_Pos);
    case stop_bits::sb_1_5: r |= (3 << USART_CR2_STOP_Pos);
    default : break;
    }

    inst->CR2 = r;
  }

  auto r = inst->CR3;

  r &= ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);

  if constexpr(m.cts == cts::enable) { r |= USART_CR3_CTSE; } else { r &= ~USART_CR3_CTSE; }
  if constexpr(m.rts == rts::enable) { r |= USART_CR3_RTSE; } else { r &= ~USART_CR3_RTSE; }

  inst->CR3 = r;

  // enable USART
  inst->CR1 |= USART_CR1_UE;
}

template<typename _module, typename ...args>
void configure()
{
  if constexpr(sizeof ...(args) > 0) { configure<args...>(); }

  constexpr auto m = _module();

#if defined(USART4)
  if constexpr(m.module_id == module_id::usart4) {
    static_assert((m.stop_bits != stop_bits::sb_0_5) && (m.stop_bits != stop_bits::sb_1_5),
                  "0.5 stop bit and 1.5 stop bit are not available for USART4");
  }
#endif

#if defined(USART5)
  if constexpr(m.module_id == module_id::usart5) {
    static_assert((m.stop_bits != stop_bits::sb_0_5) && (m.stop_bits != stop_bits::sb_1_5),
                  "0.5 stop bit and 1.5 stop bit are not available for USART5");
  }
#endif

  auto inst = detail::inst<m.module_id>();

  switch(m.module_id)
  {
#if defined(USART1)
  case module_id::usart1:
    RCC->APB2ENR  |=  RCC_APB2ENR_USART1EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_USART1RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST;
    break;
#endif

#if defined(USART2)
  case module_id::usart2:
    RCC->APB1ENR  |=  RCC_APB1ENR_USART2EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_USART2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST;
    break;
#endif

#if defined(USART3)
  case module_id::usart3:
    RCC->APB1ENR  |=  RCC_APB1ENR_USART3EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_USART3RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST;
    break;
#endif

#if defined(USART4)
  case module_id::usart4:
    RCC->APB1ENR  |=  RCC_APB1ENR_USART4EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_USART4RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART4RST;
    break;
#endif

#if defined(USART5)
  case module_id::usart5:
    RCC->APB1ENR  |=  RCC_APB1ENR_USART5EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_USART5RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART5RST;
    break;
#endif

#if defined(USART6)
  case module_id::usart6:
    RCC->APB2ENR  |=  RCC_APB2ENR_USART6EN;
    RCC->APB2RSTR |=  RCC_APB2RSTR_USART6RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST;
    break;
#endif

#if defined(USART7)
  case module_id::usart7:
    RCC->APB1ENR  |=  RCC_APB1ENR_USART7EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_USART7RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART7RST;
    break;
#endif

#if defined(USART8)
  case module_id::usart8:
    RCC->APB1ENR  |=  RCC_APB1ENR_USART8EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_USART8RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_USART8RST;
    break;
#endif
  }

  inst->CR1 &= ~USART_CR1_UE;

  {
    const uint32_t pclk = (m.module_id == module_id::usart1)? rcc::detail::apb2_clock :
                                                              rcc::detail::apb1_clock;
    const auto d = ((uint64_t(pclk) * 1000) / (16 * m.baud) + 5) / 10;
    const auto m = d / 100;
    const auto f = d - (m * 100);
    inst->BRR = (m << 4) | ((f * 16) / 100);
  }

  if constexpr(m.mode == mode::async) { configure_async<_module>(); }
}

template<typename _module, io::type _iotype>
io::result rx(uint16_t &data)
{
  constexpr auto m = _module();
  auto inst = detail::inst<m.module_id>();

  while((inst->SR & USART_SR_RXNE) == 0) {
    if constexpr(_iotype != io::type::blocking) { return io::result::busy; }
  }

  data = inst->DR & ((m.data_size == data_size::ds_8)? 0xff : 0x1ff);
  return io::result::success;
}

template<typename _module, io::type _iotype>
io::result tx(uint16_t data)
{
  constexpr auto m = _module();
  auto inst = detail::inst<m.module_id>();

  while((inst->SR & USART_SR_TXE) == 0) {
    if constexpr(_iotype != io::type::blocking) { return io::result::busy; }
  }

  inst->DR = data & ((m.data_size == data_size::ds_8)? 0xff : 0x1ff);

  if constexpr(_iotype == io::type::blocking) {
    while((inst->SR & USART_SR_TC) == 0)
      ;
  }

  return io::result::success;
}

template<typename _module, typename abort_fn>
io::result write(const void *data, uint32_t size, abort_fn&& abort)
{
  constexpr auto m = _module();
  auto inst = detail::inst<m.module_id>();

  auto p         = static_cast<const uint8_t*>(data);
  const auto end = p + size;

  auto tx = [=](auto&& data)
  {
    bool abrt;
    while(!(abrt = abort()) && (inst->SR & USART_SR_TXE) == 0)
      ;
    if(abrt) { return false; }

    inst->DR = data;
    return true;
  };

  if constexpr(m.data_size == data_size::ds_8) {
    while(p < end) {
      if(!tx(*p++)) { return io::result::busy; }
    }
  }
  else {
    uint_fast8_t shr = 0;
    auto word = [&] { return *reinterpret_cast<const uint16_t*>(p) >> shr; };

    while(p < end - 1) {
      if(!tx(word() & 0x1ff) ) { return io::result::busy; }
      p++;
      if(++shr == 8) { shr = 0; p++; }
    }

    if(p < end) { tx(word() & (0xff >> shr)); }
  }

  bool abrt;
  while(!(abrt = abort()) && (inst->SR & USART_SR_TC) == 0)
    ;
  if(abrt) { return io::result::busy; }

  return io::result::success;
}

template<typename _module, typename abort_fn>
io::result read(void *data, uint32_t size, uint32_t &rx_size, abort_fn&& abort)
{
  constexpr auto m = _module();
  auto inst = detail::inst<m.module_id>();

  auto p         = static_cast<uint8_t*>(data);
  const auto end = p + size;

  auto rx = [=](auto&& data)
  {
    bool abrt;
    while(!(abrt = abort()) && (inst->SR & USART_SR_RXNE) == 0)
      ;
    if(abrt) { return false; }

    data = inst->DR;
    return true;
  };

  auto iores = io::result::success;

  if constexpr(m.data_size == data_size::ds_8) {
    while(p < end) {
      if(!rx(*p)) { iores = io::result::busy; break; }
      p++;
    }
  }
  else {
    // TODO: read in 9bit mode
  }

  rx_size = p - static_cast<uint8_t*>(data);

  return iores;
}

} // namespace detail
