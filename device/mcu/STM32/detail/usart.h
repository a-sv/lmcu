#pragma once

namespace detail {

template<typename _module>
inline USART_TypeDef *inst()
{
  switch(_module::module_id)
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
  return nullptr;
}

template<typename _module, typename _irq>
void enable_irq()
{
  if constexpr(_irq::irq_type != nvic::irq_type::disable) {
    switch(_module::module_id)
    {
#if defined(USART1)
    case module_id::usart1: nvic::enable_irq<_irq, USART1_IRQn>(); break;
#endif

#if defined(USART2)
    case module_id::usart2: nvic::enable_irq<_irq, USART2_IRQn>(); break;
#endif

#if defined(USART3)
    case module_id::usart3: nvic::enable_irq<_irq, USART3_IRQn>(); break;
#endif

#if defined(USART4)
    case module_id::usart4: nvic::enable_irq<_irq, USART4_IRQn>(); break;
#endif

#if defined(USART5)
    case module_id::usart5: nvic::enable_irq<_irq, USART5_IRQn>(); break;
#endif

#if defined(USART6)
    case module_id::usart6: nvic::enable_irq<_irq, USART6_IRQn>(); break;
#endif

#if defined(USART7)
    case module_id::usart7: nvic::enable_irq<_irq, USART7_IRQn>(); break;
#endif

#if defined(USART8)
    case module_id::usart8: nvic::enable_irq<_irq, USART8_IRQn>(); break;
#endif
    }
  }
}

template<typename _module>
void configure_async()
{
  auto inst = detail::inst<_module>();

  {
    uint32_t r = inst->CR1;

    if constexpr(_module::data_size == data_size::_8bit) {
      r &= ~USART_CR1_M;
    }
    else {
      r |= USART_CR1_M;
    }

    if constexpr(_module::parity != parity::disable) {
      r |= USART_CR1_PCE;
      if constexpr(_module::parity == parity::even) {
        r &= ~USART_CR1_PS;
      }
      else {
        r |= USART_CR1_PS;
      }
    }
    else {
      r &= ~USART_CR1_PCE;
    }

    r |= USART_CR1_TE | USART_CR1_RE;

    inst->CR1 = r;
  }

  {
    uint32_t r = inst->CR2;

    r &= ~(USART_CR2_STOP | USART_CR2_LINEN);

    switch(_module::stop_bits)
    {
    case stop_bits::_0_5: r |= (1 << USART_CR2_STOP_Pos);
    case stop_bits::_2:   r |= (2 << USART_CR2_STOP_Pos);
    case stop_bits::_1_5: r |= (3 << USART_CR2_STOP_Pos);
    default : break;
    }

    inst->CR2 = r;
  }

  uint32_t r = inst->CR3;

  r &= ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);

  if constexpr(_module::cts == cts::enable) { r |= USART_CR3_CTSE; } else { r &= ~USART_CR3_CTSE; }
  if constexpr(_module::rts == rts::enable) { r |= USART_CR3_RTSE; } else { r &= ~USART_CR3_RTSE; }

  inst->CR3 = r;
}

template<typename ..._modules>
void enable()  { ((detail::inst<_modules>()->CR1 |=  USART_CR1_UE), ...); }

template<typename ..._modules>
void disable() { ((detail::inst<_modules>()->CR1 &= ~USART_CR1_UE), ...); }

template<typename _module, typename ..._modules>
void configure()
{
#if defined(USART4)
  if constexpr(_module::module_id == module_id::usart4) {
    static_assert(_module::stop_bits != stop_bits::_0_5 && _module::stop_bits != stop_bits::_1_5,
                  "0.5 stop bit and 1.5 stop bit are not available for USART4");
  }
#endif

#if defined(USART5)
  if constexpr(_module::module_id == module_id::usart5) {
    static_assert(_module::stop_bits != stop_bits::_0_5 && _module::stop_bits != stop_bits::_1_5,
                  "0.5 stop bit and 1.5 stop bit are not available for USART5");
  }
#endif

  auto inst = detail::inst<_module>();

  switch(_module::module_id)
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

  disable<_module>();

  {
    const uint32_t pclk = (_module::module_id == module_id::usart1)? rcc::apb2_clock() :
                                                                     rcc::apb1_clock();
    const auto d = ((uint64_t(pclk) * 1000) / (16 * _module::baud) + 5) / 10;
    const auto m = d / 100;
    const auto f = d - (m * 100);
    inst->BRR = (m << 4) | ((f * 16) / 100);
  }

  if constexpr(_module::mode == mode::async) { configure_async<_module>(); }

  {
    uint32_t r = inst->CR3;

    if constexpr(_module::dma == dma::tx || _module::dma == dma::rxtx) {
      r |=  USART_CR3_DMAT;
    }
    else {
      r &= ~USART_CR3_DMAT;
    }

    if constexpr(_module::dma == dma::rx || _module::dma == dma::rxtx) {
      r |=  USART_CR3_DMAR;
    }
    else {
      r &= ~USART_CR3_DMAR;
    }

    inst->CR3 = r;
  }

  enable_irq<_module, decltype(_module::irq)>();

  if constexpr(sizeof...(_modules) > 0) { configure<_modules...>(); }
}

template<typename _module>
io::result rx(uint16_t &data)
{
  auto inst = detail::inst<_module>();

  if((inst->SR & USART_SR_RXNE) == 0) { return io::result::busy; }
  data = inst->DR & ((_module::data_size == data_size::_8bit)? 0xff : 0x1ff);

  return io::result::success;
}

template<typename _module>
io::result tx(uint16_t data)
{
  auto inst = detail::inst<_module>();

  if((inst->SR & USART_SR_TXE) == 0 || (inst->SR & USART_SR_TC) == 0) { return io::result::busy; }
  inst->DR = data & ((_module::data_size == data_size::_8bit)? 0xff : 0x1ff);

  return io::result::success;
}

template<typename _module>
io::result write(const void *data, uint32_t size, uint32_t &tx_size, const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  auto p         = static_cast<const uint8_t*>(data);
  const auto end = p + size;

  lmcu_defer([&] { tx_size = p - static_cast<const uint8_t*>(data); });

  auto tx = [inst, &t](auto&& data)
  {
    while(!t.expired()) {
      if((inst->SR & USART_SR_TXE) != 0) { inst->DR = data; return true; }
    }
    return false;
  };

  if constexpr(_module::data_size == data_size::_8bit) {
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

  while(!t.expired()) {
    if((inst->SR & USART_SR_TC) != 0) { return io::result::success; }
  }

  return io::result::busy;
}

template<typename _module>
io::result read(void *data, uint32_t size, uint32_t &rx_size, const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  auto p         = static_cast<uint8_t*>(data);
  const auto end = p + size;

  lmcu_defer([&] { rx_size = p - static_cast<const uint8_t*>(data); });

  auto rx = [inst, &t](auto&& data)
  {
    while(!t.expired()) {
      if((inst->SR & USART_SR_RXNE) != 0) { data = inst->DR; return true; }
    }
    return false;
  };

  if constexpr(_module::data_size == data_size::_8bit) {
    while(p < end) {
      if(!rx(*p)) { return io::result::busy;}
      p++;
    }
  }
  else {
    // TODO: read in 9bit mode
  }

  return io::result::success;
}

template<event _event, event ..._events>
constexpr uint32_t event_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_event)
    {
    case event::pe:   return USART_CR1_PEIE;
    case event::txe:  return USART_CR1_TXEIE;
    case event::tc:   return USART_CR1_TCIE;
    case event::rxne: return USART_CR1_RXNEIE;
    case event::idle: return USART_CR1_IDLEIE;
    };
    return 0;
  };

  if constexpr(sizeof...(_events) > 0) { return bit() | event_bits<_events...>(); }
  return bit();
}

template<typename _module, event ..._events>
void enable_events()  { detail::inst<_module>()->CR1 |=  event_bits<_events...>(); }

template<typename _module, event ..._events>
void disable_events() { detail::inst<_module>()->CR1 &= ~event_bits<_events...>(); }

template<typename _module>
event irq_source() { return static_cast<event>(detail::inst<_module>()->SR); }

template<typename _module, event ..._events>
void irq_clear()
{
  constexpr auto events = (_events | ...);

  static_assert(!(events & event::txe), "for clear TXE flag you must use tx or write functions");

  auto inst = detail::inst<_module>();

  if constexpr((events & event::pe) || (events & event::fe) || (events & event::ne) ||
               (events & event::ore) || (events & event::idle)) {
    (void)(inst->DR);
  }

  if constexpr((events & event::rxne) || (events & event::tc) || (events & event::lbd) ||
               (events & event::cts)) {
    uint32_t r = inst->SR;
    if constexpr(events & event::rxne) { r &= ~USART_SR_RXNE; }
    if constexpr(events & event::tc)   { r &= ~USART_SR_TC;   }
    if constexpr(events & event::lbd)  { r &= ~USART_SR_LBD;  }
    if constexpr(events & event::cts)  { r &= ~USART_SR_CTS;  }
    inst->SR = r;
  }
}

template<typename _module>
uint32_t dma_address() { return uint32_t(&detail::inst<_module>()->DR); }

} // namespace detail
