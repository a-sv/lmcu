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

} // namespace detail
