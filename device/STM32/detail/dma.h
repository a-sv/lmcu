#pragma once

namespace detail {

template<module_id _module_id>
DMA_TypeDef *inst()
{
  switch(_module_id) {
#if defined(DMA1)
  case module_id::dma1: return DMA1;
#endif

#if defined(DMA2)
  case module_id::dma2: return DMA2;
#endif
  }
}

template<module_id _module_id, channel _channel>
DMA_Channel_TypeDef *c_inst()
{
  switch(_module_id) {
#if defined(DMA1)
  case module_id::dma1:
    switch(_channel)
    {
    case channel::ch1: return DMA1_Channel1;
    case channel::ch2: return DMA1_Channel2;
    case channel::ch3: return DMA1_Channel3;
    case channel::ch4: return DMA1_Channel4;
    case channel::ch5: return DMA1_Channel5;
    case channel::ch6: return DMA1_Channel6;
    case channel::ch7: return DMA1_Channel7;
    }
#endif

#if defined(DMA2)
  case module_id::dma2:
    static_assert(_channel >= channel::ch1 && _channel <= channel::ch5,
                  "DMA2 has only 1 - 5 channel");

    switch(_channel)
    {
    case channel::ch1: return DMA2_Channel1;
    case channel::ch2: return DMA2_Channel2;
    case channel::ch3: return DMA2_Channel3;
    case channel::ch4: return DMA2_Channel4;
    case channel::ch5: return DMA2_Channel5;
    }
#endif
  }
}

template<module_id _module_id, channel _channel, typename _irq>
void enable_irq()
{
  if constexpr(_irq::irq_type != nvic::irq_type::disable) {
    const auto irqp = NVIC_EncodePriority(_irq::prio_group, _irq::preempt_prio, _irq::sub_prio);

    switch(_module_id) {
#if defined(DMA1)
    case module_id::dma1:
      switch(_channel)
      {
      case channel::ch1:
        NVIC_SetPriority(DMA1_Channel1_IRQn, irqp);
        NVIC_EnableIRQ(DMA1_Channel1_IRQn);
        break;

      case channel::ch2:
        NVIC_SetPriority(DMA1_Channel2_IRQn, irqp);
        NVIC_EnableIRQ(DMA1_Channel2_IRQn);
        break;

      case channel::ch3:
        NVIC_SetPriority(DMA1_Channel3_IRQn, irqp);
        NVIC_EnableIRQ(DMA1_Channel3_IRQn);
        break;

      case channel::ch4:
        NVIC_SetPriority(DMA1_Channel4_IRQn, irqp);
        NVIC_EnableIRQ(DMA1_Channel4_IRQn);
        break;

      case channel::ch5:
        NVIC_SetPriority(DMA1_Channel5_IRQn, irqp);
        NVIC_EnableIRQ(DMA1_Channel5_IRQn);
        break;

      case channel::ch6:
        NVIC_SetPriority(DMA1_Channel6_IRQn, irqp);
        NVIC_EnableIRQ(DMA1_Channel6_IRQn);
        break;

      case channel::ch7:
        NVIC_SetPriority(DMA1_Channel7_IRQn, irqp);
        NVIC_EnableIRQ(DMA1_Channel7_IRQn);
        break;
      }
    break;
  #endif

#if defined(DMA2)
    case module_id::dma2:
      switch(_channel)
      {
      case channel::ch1:
        NVIC_SetPriority(DMA2_Channel1_IRQn, irqp);
        NVIC_EnableIRQ(DMA2_Channel1_IRQn);
        break;

      case channel::ch2:
        NVIC_SetPriority(DMA2_Channel2_IRQn, irqp);
        NVIC_EnableIRQ(DMA2_Channel2_IRQn);
        break;

      case channel::ch3:
        NVIC_SetPriority(DMA2_Channel3_IRQn, irqp);
        NVIC_EnableIRQ(DMA2_Channel3_IRQn);
        break;

      case channel::ch4:
        NVIC_SetPriority(DMA2_Channel4_IRQn, irqp);
        NVIC_EnableIRQ(DMA2_Channel4_IRQn);
        break;

      case channel::ch5:
        NVIC_SetPriority(DMA2_Channel5_IRQn, irqp);
        NVIC_EnableIRQ(DMA2_Channel5_IRQn);
        break;
      }
    break;
  #endif
    }
  }
}

template<typename _module, typename ..._modules>
void configure()
{
  switch(_module::module_id) {
#if defined(DMA1)
  case module_id::dma1: RCC->AHBENR |= RCC_AHBENR_DMA1EN; break;
#endif

#if defined(DMA2)
  case module_id::dma2: RCC->AHBENR |= RCC_AHBENR_DMA2EN; break;
#endif
  }

  auto c_inst = detail::c_inst<_module::module_id, _module::channel>();

  {
    auto r = c_inst->CCR;

    r &= ~DMA_CCR_EN;

    if constexpr(_module::mode == mode::mem_periph) {
      r &= ~DMA_CCR_MEM2MEM;
    }
    else {
      r |=  DMA_CCR_MEM2MEM;
    }

    r &= ~DMA_CCR_PL;
    r |=  uint32_t(_module::prio) << DMA_CCR_PL_Pos;

    r &= ~DMA_CCR_MSIZE;
    r |=  uint32_t(_module::mem_word) << DMA_CCR_MSIZE_Pos;

    r &= ~DMA_CCR_PSIZE;
    r |=  uint32_t(_module::periph_word) << DMA_CCR_PSIZE_Pos;

    if constexpr(_module::mem_inc == mem_inc::disable) {
      r &= ~DMA_CCR_MINC;
    }
    else {
      r |=  DMA_CCR_MINC;
    }

    if constexpr(_module::periph_inc == periph_inc::disable) {
      r &= ~DMA_CCR_PINC;
    }
    else {
      r |=  DMA_CCR_PINC;
    }

    if constexpr(_module::circular == circular::disable) {
      r &= ~DMA_CCR_CIRC;
    }
    else {
      r |=  DMA_CCR_CIRC;
    }

    if constexpr(_module::dir == dir::read_periph) {
      r &= ~DMA_CCR_DIR;
    }
    else {
      r |=  DMA_CCR_DIR;
    }

    c_inst->CCR = r;
  }

  enable_irq<_module::module_id, _module::channel, decltype(_module::irq)>();

  if constexpr(sizeof...(_modules) > 0) { configure<_modules...>(); }
}

template<typename _module>
void stop()
{
  detail::c_inst<_module::module_id, _module::channel>()->CCR &= ~DMA_CCR_EN;;
}

template<typename _module, typename _src, typename _dst>
void start(_src&& src, _dst&& dst, uint16_t size)
{
  auto c_inst = detail::c_inst<_module::module_id, _module::channel>();

  stop<_module>();

  c_inst->CNDTR = size;

  if constexpr(_module::dir == dir::read_periph) {
    c_inst->CPAR = uint32_t(src);
    c_inst->CMAR = uint32_t(dst);
  }
  else {
    c_inst->CPAR = uint32_t(dst);
    c_inst->CMAR = uint32_t(src);
  }

  c_inst->CCR |= DMA_CCR_EN;
}

template<event _event, event ..._events>
constexpr uint32_t event_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_event)
    {
    case event::cct: return DMA_CCR_TCIE;
    case event::cht: return DMA_CCR_HTIE;
    case event::cte: return DMA_CCR_TEIE;
    };
    return 0;
  };

  if constexpr(sizeof...(_events) > 0) { return bit() | event_bits<_events...>(); }
  return bit();
}

template<typename _module, event ..._events>
void enable_events()
{
  detail::c_inst<_module::module_id, _module::channel>()->CCR |= event_bits<_events...>();
}

template<typename _module, event ..._events>
void disable_events()
{
  detail::c_inst<_module::module_id, _module::channel>()->CCR &= ~event_bits<_events...>();
}

template<typename _module>
event irq_source() {
  auto inst = detail::inst<_module::module_id>();

  event evt = static_cast<event>(0);

  const uint32_t r = inst->ISR;

  switch(_module::channel)
  {
    case channel::ch1:
      if((r & DMA_ISR_GIF1)  != 0) { evt = evt | event::cgi; }
      if((r & DMA_ISR_TCIF1) != 0) { evt = evt | event::cct; }
      if((r & DMA_ISR_HTIF1) != 0) { evt = evt | event::cht; }
      if((r & DMA_ISR_TEIF1) != 0) { evt = evt | event::cte; }
    break;

    case channel::ch2:
      if((r & DMA_ISR_GIF2)  != 0) { evt = evt | event::cgi; }
      if((r & DMA_ISR_TCIF2) != 0) { evt = evt | event::cct; }
      if((r & DMA_ISR_HTIF2) != 0) { evt = evt | event::cht; }
      if((r & DMA_ISR_TEIF2) != 0) { evt = evt | event::cte; }
    break;

    case channel::ch3:
      if((r & DMA_ISR_GIF3)  != 0) { evt = evt | event::cgi; }
      if((r & DMA_ISR_TCIF3) != 0) { evt = evt | event::cct; }
      if((r & DMA_ISR_HTIF3) != 0) { evt = evt | event::cht; }
      if((r & DMA_ISR_TEIF3) != 0) { evt = evt | event::cte; }
    break;

    case channel::ch4:
      if((r & DMA_ISR_GIF4)  != 0) { evt = evt | event::cgi; }
      if((r & DMA_ISR_TCIF4) != 0) { evt = evt | event::cct; }
      if((r & DMA_ISR_HTIF4) != 0) { evt = evt | event::cht; }
      if((r & DMA_ISR_TEIF4) != 0) { evt = evt | event::cte; }
    break;

    case channel::ch5:
      if((r & DMA_ISR_GIF5)  != 0) { evt = evt | event::cgi; }
      if((r & DMA_ISR_TCIF5) != 0) { evt = evt | event::cct; }
      if((r & DMA_ISR_HTIF5) != 0) { evt = evt | event::cht; }
      if((r & DMA_ISR_TEIF5) != 0) { evt = evt | event::cte; }
    break;

    case channel::ch6:
      if((r & DMA_ISR_GIF6)  != 0) { evt = evt | event::cgi; }
      if((r & DMA_ISR_TCIF6) != 0) { evt = evt | event::cct; }
      if((r & DMA_ISR_HTIF6) != 0) { evt = evt | event::cht; }
      if((r & DMA_ISR_TEIF6) != 0) { evt = evt | event::cte; }
    break;

    case channel::ch7:
      if((r & DMA_ISR_GIF7)  != 0) { evt = evt | event::cgi; }
      if((r & DMA_ISR_TCIF7) != 0) { evt = evt | event::cct; }
      if((r & DMA_ISR_HTIF7) != 0) { evt = evt | event::cht; }
      if((r & DMA_ISR_TEIF7) != 0) { evt = evt | event::cte; }
    break;
  }

  return evt;
}

} // namespace detail
