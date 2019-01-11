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

template<typename _module>
inline CAN_TypeDef *master_inst()
{
#if defined(CAN1)
  if constexpr(_module::module_id == module_id::can1) { return CAN1; }
#endif

#if defined(CAN2)
  if constexpr(_module::module_id == module_id::can2) { return CAN1; }
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

template<typename _module, sleep_mode _sleep_mode>
void set_sleep_mode()
{
  auto inst = detail::inst<_module>();

  if constexpr(_sleep_mode == sleep_mode::enable) {
    inst->MCR |=  CAN_MCR_SLEEP;
  }
  else {
    inst->MCR &= ~CAN_MCR_SLEEP;
  }
}

template<typename _module, fifo _fifo>
uint32_t get_msg_pending()
{
  auto inst = detail::inst<_module>();

  if constexpr(_fifo == fifo::fifo_0) { return (inst->RF0R >> CAN_RF0R_FMP0_Pos) & 0x3; }
  if constexpr(_fifo == fifo::fifo_1) { return (inst->RF1R >> CAN_RF1R_FMP1_Pos) & 0x3; }

  return ((inst->RF0R >> CAN_RF0R_FMP0_Pos) & 0x3) + ((inst->RF1R >> CAN_RF1R_FMP1_Pos) & 0x3);
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

  set_sleep_mode<_module, sleep_mode::disable>();

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
      case mode::loopback:        return CAN_BTR_LBKM;
      case mode::silent:          return CAN_BTR_SILM;
      case mode::silent_loopback: return CAN_BTR_LBKM | CAN_BTR_SILM;
      default: return 0; // normal mode
      }
    }() |
    []() -> uint32_t
    {
      switch(_module::sjw) {
      case sjw::_2tq: return CAN_BTR_SJW_0;
      case sjw::_3tq: return CAN_BTR_SJW_1;
      case sjw::_4tq: return CAN_BTR_SJW;
      default: return 0; // 1tq
      }
    }() |
    []() -> uint32_t
    {
      switch(_module::bs1) {
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
      default: return 0; // 1tq
      }
    }() |
    []() -> uint32_t
    {
      switch(_module::bs2) {
      case bs2::_2tq: return 1 << CAN_BTR_TS2_Pos;
      case bs2::_3tq: return 2 << CAN_BTR_TS2_Pos;
      case bs2::_4tq: return 3 << CAN_BTR_TS2_Pos;
      case bs2::_5tq: return 4 << CAN_BTR_TS2_Pos;
      case bs2::_6tq: return 5 << CAN_BTR_TS2_Pos;
      case bs2::_7tq: return 6 << CAN_BTR_TS2_Pos;
      case bs2::_8tq: return 7 << CAN_BTR_TS2_Pos;
      default: return 0; // 1tq
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

  auto inst = detail::master_inst<_module>();

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
constexpr uint32_t tsr_flags_mask() { return lmcu::flags::value( (_flags + ...) ); }

template<flags _flag, flags ..._flags>
constexpr uint32_t rf0r_flags_mask()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_flag)
    {
    case flags::ff_0:  return CAN_RF0R_FULL0;
    case flags::fov_0: return CAN_RF0R_FOVR0;
    default : break;
    }
    return 0;
  };

  if constexpr(sizeof...(_flags) > 0) { return bit() | rf0r_flags_mask<_flags...>(); }
  return bit();
}

template<flags _flag, flags ..._flags>
constexpr uint32_t rf1r_flags_mask()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_flag)
    {
    case flags::ff_1:  return CAN_RF1R_FULL1;
    case flags::fov_1: return CAN_RF1R_FOVR1;
    default : break;
    }
    return 0;
  };

  if constexpr(sizeof...(_flags) > 0) { return bit() | rf1r_flags_mask<_flags...>(); }
  return bit();
}

template<flags _flag, flags ..._flags>
constexpr uint32_t msr_flags_mask()
{
  constexpr auto bit = []() -> uint32_t
  {
    switch(_flag)
    {
    case flags::erri:  return CAN_MSR_ERRI;
    case flags::wkui:  return CAN_MSR_WKUI;
    case flags::slaki: return CAN_MSR_SLAKI;
    case flags::rx:    return CAN_MSR_RX;
    case flags::samp:  return CAN_MSR_SAMP;
    case flags::rxm:   return CAN_MSR_RXM;
    case flags::txm:   return CAN_MSR_TXM;
    default : break;
    }
    return 0;
  };

  if constexpr(sizeof...(_flags) > 0) { return bit() | msr_flags_mask<_flags...>(); }
  return bit();
}

template<typename _module, flags ..._flags>
flags get_flags()
{
  auto inst = detail::inst<_module>();

  static_assert(sizeof...(_flags) > 0, "function must have at least one flag");

  auto f = lmcu::flags::from_value<flags>(0);

  if constexpr(tsr_flags_mask<_flags...>() != 0) {
    f = lmcu::flags::from_value<flags>(inst->TSR & 0xfc0f0f0f);
  }

  if constexpr(rf0r_flags_mask<_flags...>() != 0) {
    f |= lmcu::flags::from_value<flags>(((inst->RF0R >> 3) & 0x3) << 4);
  }

  if constexpr(rf1r_flags_mask<_flags...>() != 0) {
    f |= lmcu::flags::from_value<flags>(((inst->RF1R >> 3) & 0x3) << 6);
  }

  if constexpr(msr_flags_mask<_flags...>() != 0) {
    uint32_t r = inst->MSR;
    r = (((r >> 2) & 0x7) << 12) | (((r >> 8) & 0xf) << 20);
    f |= lmcu::flags::from_value<flags>(r);
  }

  return f;
}

template<typename _module, flags ..._flags>
void clear_flags()
{
  auto inst = detail::inst<_module>();

  {
    constexpr auto mask = tsr_flags_mask<_flags...>();
    if constexpr(mask != 0) { inst->TSR = mask; }
  }

  {
    constexpr auto mask = rf0r_flags_mask<_flags...>();
    if constexpr(mask != 0) { inst->RF0R = mask; }
  }

  {
    constexpr auto mask = rf1r_flags_mask<_flags...>();
    if constexpr(mask != 0) { inst->RF1R = mask; }
  }

  {
    constexpr auto mask = msr_flags_mask<_flags...>();
    if constexpr(mask != 0) { inst->MSR = mask; }
  }
}

template<typename _module>
event irq_source() { return lmcu::flags::from_value<event>(detail::inst<_module>()->IER); }

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

  uint32_t tir;

  if(ide) {
    tir = (id << CAN_TI0R_EXID_Pos) | CAN_TI0R_IDE;
  }
  else {
    tir = id << CAN_TI0R_STID_Pos;
  }

  if(rtr) {
    tir |= CAN_TI0R_RTR;
    mbox->TDTR = 0;
  }
  else {
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
  }

  mbox->TIR = tir;

  // request transmission
  mbox->TIR |= CAN_TI0R_TXRQ;

  return io::result::success;
}

template<typename _module>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len,
              const delay::expirable &t)
{
  auto rc = io::result::busy;

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

  uint32_t fifo_n = 0xff;

  if constexpr(_fifo == fifo::any) {
    if(get_msg_pending<_module, fifo::fifo_0>()) {
      fifo_n = 0;
    }
    else
    if(get_msg_pending<_module, fifo::fifo_1>()) {
      fifo_n = 1;
    }
  }
  else
  if constexpr(_fifo == fifo::fifo_0) {
    if(get_msg_pending<_module, fifo::fifo_0>()) { fifo_n = 0; }
  }
  else
  if constexpr(_fifo == fifo::fifo_1) {
    if(get_msg_pending<_module, fifo::fifo_1>()) { fifo_n = 1; }
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

  // fifo release
  if(fifo_n == 0) {
    inst->RF0R |= CAN_RF0R_RFOM0;
  }
  else {
    inst->RF1R |= CAN_RF1R_RFOM1;
  }

  return io::result::success;
}

template<typename _module, fifo _fifo>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len,
              const delay::expirable &t)
{
  auto rc = io::result::busy;

  while(rc == io::result::busy && !t.expired()) {
    rc = rx<_module, _fifo>(id, ide, rtr, fmi, data, len);
  }

  return rc;
}

} // namespace detail
