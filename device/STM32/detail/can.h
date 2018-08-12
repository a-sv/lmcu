#pragma once

namespace detail {

template<typename _module>
inline CAN_TypeDef *inst()
{
#if defined(CAN1)
  if constexpr(_module::module_id == module_id::can1) { return CAN1; }
#endif

#if defined(CAN2)
  if constexpr(_module::module_id == module_id::can2) { return CAN2; }
#endif

#if defined(CAN3)
  if constexpr(_module::module_id == module_id::can3) { return CAN3; }
#endif
}

template<module_id _module_id, typename _irq>
void enable_irq()
{
  if constexpr(_irq::irq_type != nvic::irq_type::disable) {
#if defined(CAN1)
    if constexpr(_module_id == module_id::can1) {
      switch(_irq::irq_type)
      {
      case nvic::irq_type::tx:  nvic::enable_irq<_irq, CAN1_TX_IRQn>();  break;
      case nvic::irq_type::rx0: nvic::enable_irq<_irq, CAN1_RX0_IRQn>(); break;
      case nvic::irq_type::rx1: nvic::enable_irq<_irq, CAN1_RX1_IRQn>(); break;
      case nvic::irq_type::sce: nvic::enable_irq<_irq, CAN1_SCE_IRQn>(); break;
      default : break;
      }
    }
#endif

#if defined(CAN2)
    if constexpr(_module_id == module_id::can2) {
      switch(_irq::irq_type)
      {
      case nvic::irq_type::tx:  nvic::enable_irq<_irq, CAN2_TX_IRQn>();  break;
      case nvic::irq_type::rx0: nvic::enable_irq<_irq, CAN2_RX0_IRQn>(); break;
      case nvic::irq_type::rx1: nvic::enable_irq<_irq, CAN2_RX1_IRQn>(); break;
      case nvic::irq_type::sce: nvic::enable_irq<_irq, CAN2_SCE_IRQn>(); break;
      default : break;
      }
    }
#endif

#if defined(CAN3)
    if constexpr(_module_id == module_id::can3) {
      switch(_irq::irq_type)
      {
      case nvic::irq_type::tx:  nvic::enable_irq<_irq, CAN3_TX_IRQn>();  break;
      case nvic::irq_type::rx0: nvic::enable_irq<_irq, CAN3_RX0_IRQn>(); break;
      case nvic::irq_type::rx1: nvic::enable_irq<_irq, CAN3_RX1_IRQn>(); break;
      case nvic::irq_type::sce: nvic::enable_irq<_irq, CAN3_SCE_IRQn>(); break;
      default : break;
      }
    }
#endif
  }
}

template<typename _module, typename ..._modules>
void configure()
{
  if constexpr(sizeof...(_modules) > 0) { configure<_modules...>(); }

  static_assert(_module::prediv >= 1 && _module::prediv <= 1024, "CAN prescaler must be >= 1 and "
                                                                 "<= 1024");

#if defined(CAN1)
  if constexpr(_module::module_id == module_id::can1) {
    RCC->APB1ENR  |=  RCC_APB1ENR_CAN1EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_CAN1RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST;
  }
#endif

#if defined(CAN2)
  if constexpr(_module::module_id == module_id::can2) {
    RCC->APB1ENR  |=  RCC_APB1ENR_CAN1EN | RCC_APB1ENR_CAN2EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_CAN2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST;
  }
#endif

#if defined(CAN3)
  if constexpr(_module::module_id == module_id::can3) {
    RCC->APB1ENR  |=  RCC_APB1ENR_CAN3EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_CAN3RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN3RST;
  }
#endif

  auto inst = detail::inst<_module>();

  // exit from sleep mode
  inst->MCR &= ~CAN_MCR_SLEEP;
  // request initialisation
  inst->MCR |= CAN_MCR_INRQ;
  // wait the acknowledge
  while((inst->MSR & CAN_MSR_INAK) == 0)
    ;

  {
    uint32_t r = inst->MCR;
    r &= ~(CAN_MCR_TTCM | CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_NART | CAN_MCR_RFLM | CAN_MCR_TXFP);

    if constexpr(_module::ttcm == ttcm::enable) { r |= CAN_MCR_TTCM; }
    if constexpr(_module::abom == abom::enable) { r |= CAN_MCR_ABOM; }
    if constexpr(_module::awum == awum::enable) { r |= CAN_MCR_AWUM; }
    if constexpr(_module::nart == nart::enable) { r |= CAN_MCR_NART; }
    if constexpr(_module::rflm == rflm::enable) { r |= CAN_MCR_RFLM; }
    if constexpr(_module::txfp == txfp::enable) { r |= CAN_MCR_TXFP; }

    inst->MCR = r;
  }

  inst->BTR =
    []() -> uint32_t
    {
      switch(_module::mode) {
      case mode::normal:          return 0;
      case mode::loopback:        return CAN_BTR_LBKM;
      case mode::silent:          return CAN_BTR_SILM;
      case mode::silent_loopback: return CAN_BTR_LBKM | CAN_BTR_SILM;
      }
    }() |
    []() -> uint32_t
    {
      switch(_module::sjw) {
      case sjw::_1tq: return 0;
      case sjw::_2tq: return CAN_BTR_SJW_0;
      case sjw::_3tq: return CAN_BTR_SJW_1;
      case sjw::_4tq: return CAN_BTR_SJW;
      }
    }() |
    []() -> uint32_t
    {
      switch(_module::bs1) {
      case bs1::_1tq:  return 0;
      case bs1::_2tq:  return 1  << CAN_BTR_TS1_Pos;
      case bs1::_3tq:  return 2  << CAN_BTR_TS1_Pos;
      case bs1::_4tq:  return 3  << CAN_BTR_TS1_Pos;
      case bs1::_5tq:  return 4  << CAN_BTR_TS1_Pos;
      case bs1::_6tq:  return 5  << CAN_BTR_TS1_Pos;
      case bs1::_7tq:  return 6  << CAN_BTR_TS1_Pos;
      case bs1::_8tq:  return 7  << CAN_BTR_TS1_Pos;
      case bs1::_9tq:  return 8  << CAN_BTR_TS1_Pos;
      case bs1::_10tq: return 9  << CAN_BTR_TS1_Pos;
      case bs1::_11tq: return 10 << CAN_BTR_TS1_Pos;
      case bs1::_12tq: return 11 << CAN_BTR_TS1_Pos;
      case bs1::_13tq: return 12 << CAN_BTR_TS1_Pos;
      case bs1::_14tq: return 13 << CAN_BTR_TS1_Pos;
      case bs1::_15tq: return 14 << CAN_BTR_TS1_Pos;
      case bs1::_16tq: return 15 << CAN_BTR_TS1_Pos;
      }
    }() |
    []() -> uint32_t
    {
      switch(_module::bs2) {
      case bs2::_1tq: return 0;
      case bs2::_2tq: return 1 << CAN_BTR_TS2_Pos;
      case bs2::_3tq: return 2 << CAN_BTR_TS2_Pos;
      case bs2::_4tq: return 3 << CAN_BTR_TS2_Pos;
      case bs2::_5tq: return 4 << CAN_BTR_TS2_Pos;
      case bs2::_6tq: return 5 << CAN_BTR_TS2_Pos;
      case bs2::_7tq: return 6 << CAN_BTR_TS2_Pos;
      case bs2::_8tq: return 7 << CAN_BTR_TS2_Pos;
      }
    }() |
    (_module::prediv - 1)
  ;

  // request leave initialisation
  inst->MCR &= ~CAN_MCR_INRQ;
  // wait the acknowledge
  while((inst->MSR & CAN_MSR_INAK) == 0)
    ;

  enable_irq<_module::module_id, decltype(_module::irq0)>();
  enable_irq<_module::module_id, decltype(_module::irq1)>();
  enable_irq<_module::module_id, decltype(_module::irq2)>();
  enable_irq<_module::module_id, decltype(_module::irq3)>();
}

template<typename _module, typename _filter, typename ..._filters>
void filter_enable(uint32_t id_high, uint32_t id_low, uint32_t maskid_high, uint32_t maskid_low)
{
  if constexpr(sizeof...(_filters) > 0) { filter_enable<_module, _filters...>(); }
  constexpr auto fpos = 1 << _filter::number;

  static_assert(_filter::number < 28, "filter number must be >= 0 and <= 27");
  static_assert(_filter::fifo != fifo::any, "you must select fifo for filter");

  auto inst = detail::inst<_module>();

  // enter to initialisation mode
  uint32_t r = inst->FMR;
  r &= CAN_FMR_CAN2SB;
  r |= CAN_FMR_FINIT | (_filter::bank_num << CAN_FMR_CAN2SB_Pos);
  inst->FMR = r;

  // filter deactivation
  inst->FA1R &= ~fpos;

  if constexpr(_filter::filter_scale == filter_scale::_16bit) {
    // 16-bit scale for the filter
    inst->FS1R &= ~fpos;
    inst->sFilterRegister[_filter::number].FR1 = ((maskid_low & 0xffff) << 16) | (id_low & 0xffff);
    inst->sFilterRegister[_filter::number].FR2 = ((maskid_high & 0xffff) << 16) |
                                                 (id_high & 0xffff);
  }
  else {
    // 32-bit scale for the filter
    inst->FS1R |= fpos;
    inst->sFilterRegister[_filter::number].FR1 = ((id_high & 0xffff) << 16) | (id_low & 0xffff);
    inst->sFilterRegister[_filter::number].FR2 = ((maskid_high & 0xffff) << 16) |
                                                 (maskid_low & 0xffff);
  }

  if constexpr(_filter::filter_mode == filter_mode::idmask) {
    inst->FM1R &= ~fpos;
  }
  else {
    inst->FM1R |= fpos;
  }

  if constexpr(_filter::fifo == fifo::fifo_0) {
    inst->FFA1R &= ~fpos;
  }
  else {
    inst->FFA1R |= fpos;
  }

  // filter activation
  inst->FA1R |= fpos;
  // leave the initialisation mode
  inst->FMR &= ~CAN_FMR_FINIT;
}

template<typename _module, typename _filter, typename ..._filters>
void filter_disable()
{
  if constexpr(sizeof...(_filters) > 0) { filter_enable<_module, _filters...>(); }

  static_assert(_filter::number < 28, "filter number must be >= 0 and <= 27");

  auto inst = detail::inst<_module>();

  // enter to initialisation mode
  uint32_t r = inst->FMR;
  r &= CAN_FMR_CAN2SB;
  r |= CAN_FMR_FINIT | (_filter::bank_num << CAN_FMR_CAN2SB_Pos);
  inst->FMR = r;

  // filter deactivation
  inst->FA1R &= ~(1 << _filter::number);
  // leave the initialisation mode
  inst->FMR &= ~CAN_FMR_FINIT;
}

template<event _event, event ..._events>
constexpr uint32_t event_bits()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_event)
    {
    case event::tme:   return CAN_IER_TMEIE;
    case event::fmp_0: return CAN_IER_FMPIE0;
    case event::ff_0:  return CAN_IER_FFIE0;
    case event::fov_0: return CAN_IER_FOVIE0;
    case event::fmp_1: return CAN_IER_FMPIE1;
    case event::ff_1:  return CAN_IER_FFIE1;
    case event::fov_1: return CAN_IER_FOVIE1;
    case event::wku:   return CAN_IER_WKUIE;
    case event::slk:   return CAN_IER_SLKIE;
    case event::ewg:   return CAN_IER_EWGIE;
    case event::epv:   return CAN_IER_EPVIE;
    case event::bof:   return CAN_IER_BOFIE;
    case event::lec:   return CAN_IER_LECIE;
    case event::err:   return CAN_IER_ERRIE;
    };
    return 0;
  };

  if constexpr(sizeof...(_events) > 0) { return bit() | event_bits<_events...>(); }
  return bit();
}

template<typename _module, event ..._events>
void enable_events() { detail::inst<_module>()->IER |= event_bits<_events...>(); }

template<typename _module, event ..._events>
void disable_events() { detail::inst<_module>()->IER &= ~event_bits<_events...>(); }

template<flags _flag, flags ..._flags>
inline flags get_tsr_flags(const uint32_t reg)
{
  auto flag = [=]
  {
    constexpr auto none = static_cast<flags>(0);

    switch(_flag)
    {
    case flags::rqcp_0: return (reg & CAN_TSR_RQCP0) == 0? none : flags::rqcp_0;
    case flags::rqcp_1: return (reg & CAN_TSR_RQCP1) == 0? none : flags::rqcp_1;
    case flags::rqcp_2: return (reg & CAN_TSR_RQCP2) == 0? none : flags::rqcp_2;
    case flags::txok_0: return (reg & CAN_TSR_TXOK0) == 0? none : flags::txok_0;
    case flags::txok_1: return (reg & CAN_TSR_TXOK1) == 0? none : flags::txok_1;
    case flags::txok_2: return (reg & CAN_TSR_TXOK2) == 0? none : flags::txok_2;
    case flags::tme_0:  return (reg & CAN_TSR_TME0 ) == 0? none : flags::tme_0;
    case flags::tme_1:  return (reg & CAN_TSR_TME1 ) == 0? none : flags::tme_1;
    case flags::tme_2:  return (reg & CAN_TSR_TME2 ) == 0? none : flags::tme_2;
    default : break;
    }

    return none;
  };

  if constexpr(sizeof...(_flags) > 0) { return flag() | get_tsr_flags<_flags...>(reg); }
  return flag();
}

template<flags _flag, flags ..._flags>
inline flags get_rf0r_flags(const uint32_t reg)
{
  auto flag = [=]
  {
    constexpr auto none = static_cast<flags>(0);

    switch(_flag)
    {
    case flags::fmp_0: return (reg & CAN_RF0R_FMP0 ) == 0? none : flags::fmp_0;
    case flags::ff_0:  return (reg & CAN_RF0R_FULL0) == 0? none : flags::ff_0;
    case flags::fov_0: return (reg & CAN_RF0R_FOVR0) == 0? none : flags::fov_0;
    default : break;
    }

    return none;
  };

  if constexpr(sizeof...(_flags) > 0) { return flag() | get_rf0r_flags<_flags...>(reg); }
  return flag();
}

template<flags _flag, flags ..._flags>
inline flags get_rf1r_flags(const uint32_t reg)
{
  auto flag = [=]
  {
    constexpr auto none = static_cast<flags>(0);

    switch(_flag)
    {
    case flags::fmp_1: return (reg & CAN_RF1R_FMP1 ) == 0? none : flags::fmp_1;
    case flags::ff_1:  return (reg & CAN_RF1R_FULL1) == 0? none : flags::ff_1;
    case flags::fov_1: return (reg & CAN_RF1R_FOVR1) == 0? none : flags::fov_1;
    default : break;
    }

    return none;
  };

  if constexpr(sizeof...(_flags) > 0) { return flag() | get_rf1r_flags<_flags...>(reg); }
  return flag();
}

template<flags _flag, flags ..._flags>
inline flags get_msr_flags(const uint32_t reg)
{
  auto flag = [=]
  {
    constexpr auto none = static_cast<flags>(0);

    switch(_flag)
    {
    case flags::wku:   return (reg & CAN_MSR_WKUI ) == 0? none : flags::wku;
    case flags::slaki: return (reg & CAN_MSR_SLAKI) == 0? none : flags::slaki;
    default : break;
    }

    return none;
  };

  if constexpr(sizeof...(_flags) > 0) { return flag() | get_msr_flags<_flags...>(reg); }
  return flag();
}

template<typename _module, flags ..._flags>
flags get_flags()
{
  static_assert(sizeof...(_flags) > 0, "function must have at least one flag");

  auto inst = detail::inst<_module>();
  return get_tsr_flags <_flags...>(inst->TSR)  |
         get_rf0r_flags<_flags...>(inst->RF0R) |
         get_rf1r_flags<_flags...>(inst->RF1R) |
         get_msr_flags <_flags...>(inst->MSR);
}

template<flags _flag, flags ..._flags>
constexpr uint32_t clr_tsr_flags()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_flag)
    {
    case flags::rqcp_0: return CAN_TSR_RQCP0;
    case flags::rqcp_1: return CAN_TSR_RQCP1;
    case flags::rqcp_2: return CAN_TSR_RQCP2;
    case flags::txok_0: return CAN_TSR_TXOK0;
    case flags::txok_1: return CAN_TSR_TXOK1;
    case flags::txok_2: return CAN_TSR_TXOK2;
    case flags::tme_0:  return CAN_TSR_TME0;
    case flags::tme_1:  return CAN_TSR_TME1;
    case flags::tme_2:  return CAN_TSR_TME2;
    default : break;
    }
    return 0;
  };

  if constexpr(sizeof...(_flags) > 0) { return bit() | clr_tsr_flags<_flags...>(); }
  return bit();
}

template<flags _flag, flags ..._flags>
constexpr uint32_t clr_rf0r_flags()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_flag)
    {
    case flags::fmp_0: return CAN_RF0R_RFOM0;
    case flags::ff_0:  return CAN_RF0R_FULL0;
    case flags::fov_0: return CAN_RF0R_FOVR0;
    default : break;
    }
    return 0;
  };

  if constexpr(sizeof...(_flags) > 0) { return bit() | clr_rf0r_flags<_flags...>(); }
  return bit();
}

template<flags _flag, flags ..._flags>
constexpr uint32_t clr_rf1r_flags()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_flag)
    {
    case flags::fmp_1: return CAN_RF1R_RFOM1;
    case flags::ff_1:  return CAN_RF1R_FULL1;
    case flags::fov_1: return CAN_RF1R_FOVR1;
    default : break;
    }
    return 0;
  };

  if constexpr(sizeof...(_flags) > 0) { return bit() | clr_rf1r_flags<_flags...>(); }
  return bit();
}

template<flags _flag, flags ..._flags>
constexpr uint32_t clr_msr_flags()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_flag)
    {
    case flags::wku:   return CAN_MSR_WKUI;
    case flags::slaki: return CAN_MSR_SLAKI;
    default : break;
    }
    return 0;
  };

  if constexpr(sizeof...(_flags) > 0) { return bit() | clr_msr_flags<_flags...>(); }
  return bit();
}

template<typename _module, flags ..._flags>
void clear_flags()
{
  auto inst = detail::inst<_module>();

  {
    constexpr auto mask = clr_tsr_flags<_flags...>();
    if constexpr(mask != 0) { inst->TSR = mask; }
  }

  {
    constexpr auto mask = clr_rf0r_flags<_flags...>();
    if constexpr(mask != 0) { inst->RF0R = mask; }
  }

  {
    constexpr auto mask = clr_rf1r_flags<_flags...>();
    if constexpr(mask != 0) { inst->RF1R = mask; }
  }

  {
    constexpr auto mask = clr_msr_flags<_flags...>();
    if constexpr(mask != 0) { inst->MSR = mask; }
  }
}

template<typename _module>
event irq_source()
{
  auto inst = detail::inst<_module>();

  event evt = static_cast<event>(0);

  const uint32_t r = inst->IER;
  if((r & CAN_IER_TMEIE)  != 0) { evt = evt | event::tme;   }
  if((r & CAN_IER_FMPIE0) != 0) { evt = evt | event::fmp_0; }
  if((r & CAN_IER_FFIE0)  != 0) { evt = evt | event::ff_0;  }
  if((r & CAN_IER_FOVIE0) != 0) { evt = evt | event::fov_0; }
  if((r & CAN_IER_FMPIE1) != 0) { evt = evt | event::fmp_1; }
  if((r & CAN_IER_FFIE1)  != 0) { evt = evt | event::ff_1;  }
  if((r & CAN_IER_FOVIE1) != 0) { evt = evt | event::fov_1; }
  if((r & CAN_IER_WKUIE)  != 0) { evt = evt | event::wku;   }
  if((r & CAN_IER_SLKIE)  != 0) { evt = evt | event::slk;   }
  if((r & CAN_IER_EWGIE)  != 0) { evt = evt | event::ewg;   }
  if((r & CAN_IER_EPVIE)  != 0) { evt = evt | event::epv;   }
  if((r & CAN_IER_BOFIE)  != 0) { evt = evt | event::bof;   }
  if((r & CAN_IER_LECIE)  != 0) { evt = evt | event::lec;   }
  if((r & CAN_IER_ERRIE)  != 0) { evt = evt | event::err;   }

  return evt;
}

template<typename _module>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len)
{
  if(len > 8) { return io::result::error; }

  auto inst = detail::inst<_module>();

  CAN_TxMailBox_TypeDef *mbox;

  if((inst->TSR & CAN_TSR_TME0) != 0) {
    mbox = &inst->sTxMailBox[0];
  }
  else
  if((inst->TSR & CAN_TSR_TME1) != 0) {
    mbox = &inst->sTxMailBox[1];
  }
  else
  if((inst->TSR & CAN_TSR_TME2) != 0) {
    mbox = &inst->sTxMailBox[2];
  }
  else {
    return io::result::busy;
  }

  if(ide) {
    mbox->TIR = (id << CAN_TI0R_EXID_Pos) | CAN_TI0R_IDE;
  }
  else {
    mbox->TIR = id << CAN_TI0R_STID_Pos;
  }

  mbox->TDTR = (len & 0xf);

  auto p = static_cast<const uint8_t*>(data);

  uint32_t dh = 0, dl = 0;
  switch(len)
  {
  case 8: dh |= uint32_t(p[7]) << 24;
  case 7: dh |= uint32_t(p[6]) << 16;
  case 6: dh |= uint32_t(p[5]) << 8;
  case 5: dh |= uint32_t(p[4]);
  case 4: dl |= uint32_t(p[3]) << 24;
  case 3: dl |= uint32_t(p[2]) << 16;
  case 2: dl |= uint32_t(p[1]) << 8;
  case 1: dl |= uint32_t(p[0]);
  };
  mbox->TDLR = dl;
  mbox->TDHR = dh;

  // request transmission
  mbox->TIR |= CAN_TI0R_TXRQ;

  return io::result::success;
}

template<typename _module>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len,
              const delay::expirable &t)
{
  io::result rc = io::result::busy;

  while(rc == io::result::busy && !t.expired()) {
    rc = tx<_module>(id, ide, rtr, data, len);
  }

  return rc;
}

template<typename _module>
io::result tx_wait(const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  constexpr auto flags = (CAN_TSR_TME0 | CAN_TSR_TME1 | CAN_TSR_TME2);
  while((inst->TSR & flags) != flags) {
    if(t.expired()) { return io::result::busy; }
  }

  return io::result::success;
}

template<typename _module>
void tx_abort()
{
  auto inst = detail::inst<_module>();

  if((inst->TSR & CAN_TSR_TME0) == 0) { inst->TSR |= CAN_TSR_ABRQ0; }
  if((inst->TSR & CAN_TSR_TME1) == 0) { inst->TSR |= CAN_TSR_ABRQ1; }
  if((inst->TSR & CAN_TSR_TME2) == 0) { inst->TSR |= CAN_TSR_ABRQ2; }
}

template<typename _module, fifo _fifo>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len)
{
  auto inst = detail::inst<_module>();

  uint8_t fifo_n = 0xff;

  if constexpr(_fifo == fifo::any) {
    if((inst->RF0R & 0x3) != 0) {
      fifo_n = 0;
    }
    else
    if((inst->RF1R & 0x3) != 0) {
      fifo_n = 1;
    }
  }
  else
  if constexpr(_fifo == fifo::fifo_0) {
    if((inst->RF0R & 0x3) != 0) { fifo_n = 0; }
  }
  else
  if constexpr(_fifo == fifo::fifo_1) {
    if((inst->RF1R & 0x3) != 0) { fifo_n = 1; }
  }

  if(fifo_n == 0xff) { return io::result::busy; }

  const auto &h_fifo = inst->sFIFOMailBox[fifo_n];

  ide = (h_fifo.RIR & CAN_RI0R_IDE) != 0;
  if(ide) {
    id = (h_fifo.RIR >> CAN_RI0R_EXID_Pos) & 0x1fffffff;
  }
  else {
    id = (h_fifo.RIR >> CAN_RI0R_STID_Pos) & 0x7ff;
  }
  rtr = (h_fifo.RIR & CAN_RI0R_RTR) != 0;
  fmi = (h_fifo.RDTR >> CAN_RDT0R_FMI_Pos) & 0xff;
  len = (h_fifo.RDTR >> CAN_RDT0R_DLC_Pos) & 0xf;

  auto dl = h_fifo.RDLR, dh = h_fifo.RDHR;
  switch(len)
  {
  case 8: data[7] = (dh >> 24) & 0xff;
  case 7: data[6] = (dh >> 16) & 0xff;
  case 6: data[5] = (dh >>  8) & 0xff;
  case 5: data[4] =  dh        & 0xff;
  case 4: data[3] = (dl >> 24) & 0xff;
  case 3: data[2] = (dl >> 16) & 0xff;
  case 2: data[1] = (dl >>  8) & 0xff;
  case 1: data[0] =  dl        & 0xff;
  };

  if(fifo_n == 0) {
    clear_flags<_module, can::flags::fmp_0>();
  }
  else {
    clear_flags<_module, can::flags::fmp_1>();
  }

  return io::result::success;
}

template<typename _module, fifo _fifo>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len,
              const delay::expirable &t)
{
  io::result rc = io::result::busy;

  while(rc == io::result::busy && !t.expired()) {
    rc = rx<_module, _fifo>(id, ide, rtr, fmi, data, len);
  }

  return rc;
}

} // namespace detail
