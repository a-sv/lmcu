#pragma once

namespace detail {

template<module_id _module_id>
DMA_TypeDef *inst()
{
  switch(_module_id) {
#if defined(DMA1)
  case module_id::dma1: return DMA1;
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
  }
}

template<module_id _module_id, channel _channel, typename _irq>
void enable_irq()
{
  constexpr auto irq = _irq();

  if constexpr(irq.irq_type != nvic::irq_type::disable) {
    const auto irqp = NVIC_EncodePriority(irq.prio_group, irq.preempt_prio, irq.sub_prio);

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
    }
  }
}

template<typename _arg1, typename ...args>
void configure()
{
  constexpr auto m = _arg1();

  switch(m.module_id) {
#if defined(DMA1)
  case module_id::dma1: RCC->AHBENR |= RCC_AHBENR_DMA1EN; break;
#endif
  }

  auto c_inst = detail::c_inst<m.module_id, m.channel>();

  {
    auto r = c_inst->CCR;

    r &= ~DMA_CCR_EN;

    if constexpr(m.mode == mode::mem_periph) {
      r &= ~DMA_CCR_MEM2MEM;
    }
    else {
      r |=  DMA_CCR_MEM2MEM;
    }

    r &= ~DMA_CCR_PL;
    r |=  uint32_t(m.prio) << DMA_CCR_PL_Pos;

    r &= ~DMA_CCR_MSIZE;
    r |=  uint32_t(m.mem_word) << DMA_CCR_MSIZE_Pos;

    r &= ~DMA_CCR_PSIZE;
    r |=  uint32_t(m.periph_word) << DMA_CCR_PSIZE_Pos;

    if constexpr(m.mem_inc == mem_inc::disable) {
      r &= ~DMA_CCR_MINC;
    }
    else {
      r |=  DMA_CCR_MINC;
    }

    if constexpr(m.periph_inc == periph_inc::disable) {
      r &= ~DMA_CCR_PINC;
    }
    else {
      r |=  DMA_CCR_PINC;
    }

    if constexpr(m.circular == circular::disable) {
      r &= ~DMA_CCR_CIRC;
    }
    else {
      r |=  DMA_CCR_CIRC;
    }

    if constexpr(m.dir == dir::read_periph) {
      r &= ~DMA_CCR_DIR;
    }
    else {
      r |=  DMA_CCR_DIR;
    }

    c_inst->CCR = r;
  }

  enable_irq<m.module_id, m.channel, decltype(m.irq)>();

  if constexpr(sizeof...(args) > 0) { configure<args...>(); }
}

template<typename _conf>
void stop()
{
  detail::c_inst<_conf().module_id, _conf().channel>()->CCR &= ~DMA_CCR_EN;;
}

template<typename _conf, typename _src_t, typename _dst_t>
void start(_src_t&& src, _dst_t&& dst, uint16_t size)
{
  constexpr auto m = _conf();
  auto c_inst = detail::c_inst<m.module_id, m.channel>();

  stop<_conf>();

  c_inst->CNDTR = size;

  if constexpr(m.dir == dir::read_periph) {
    c_inst->CPAR = uint32_t(src);
    c_inst->CMAR = uint32_t(dst);
  }
  else {
    c_inst->CPAR = uint32_t(dst);
    c_inst->CMAR = uint32_t(src);
  }

  c_inst->CCR |= DMA_CCR_EN;
}

template<event evt, event ...evts>
constexpr uint32_t event_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(evt)
    {
    case event::cct: return DMA_CCR_TCIE;
    case event::cht: return DMA_CCR_HTIE;
    case event::cte: return DMA_CCR_TEIE;
    };
    return 0;
  };

  if constexpr(sizeof...(evts) > 0) { return bit() | event_bits<evts...>(); }
  return bit();
}

template<typename _module, event ...evts>
void enable_events()
{
  detail::c_inst<_module().module_id, _module().channel>()->CCR |= event_bits<evts...>();
}

template<typename _module, event ...evts>
void disable_events()
{
  detail::c_inst<_module().module_id, _module().channel>()->CCR &= ~event_bits<evts...>();
}

template<typename _module>
event irq_source() {
  auto inst = detail::inst<_module().module_id>();

  event evt = static_cast<event>(0);

  const uint32_t r = inst->ISR;

  switch(_module().channel)
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
