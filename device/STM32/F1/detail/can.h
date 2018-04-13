#pragma once

namespace detail {

template<uint32_t r, typename arg1, typename ...args>
uint32_t remap_bits();

template<module_id _module_id, typename _irq>
void enable_irq()
{
  constexpr auto irq = _irq();

  if constexpr(irq.irq_type != irq_type::disable) {
    const auto irqp = NVIC_EncodePriority(irq.prio_group, irq.preempt_prio, irq.sub_prio);

#if defined(CAN1)
    if constexpr(_module_id == module_id::can1) {
      if constexpr(_irq_type == irq_type::tx) {
        NVIC_SetPriority(CAN1_TX_IRQn, irqp);
        NVIC_EnableIRQ(CAN1_TX_IRQn);
      }
      if constexpr(_irq_type == irq_type::rx0) {
        NVIC_SetPriority(CAN1_RX0_IRQn, irqp);
        NVIC_EnableIRQ(CAN1_RX0_IRQn);
      }
      if constexpr(_irq_type == irq_type::rx1) {
        NVIC_SetPriority(CAN1_RX1_IRQn, irqp);
        NVIC_EnableIRQ(CAN1_RX1_IRQn);
      }
      if constexpr(_irq_type == irq_type::sce) {
        NVIC_SetPriority(CAN1_SCE_IRQn, irqp);
        NVIC_EnableIRQ(CAN1_SCE_IRQn);
      }
    }
#endif

#if defined(CAN2)
    if constexpr(_module_id == module_id::can2) {
      if constexpr(_irq_type == irq_type::tx) {
        NVIC_SetPriority(CAN2_TX_IRQn, irqp);
        NVIC_EnableIRQ(CAN2_TX_IRQn);
      }
      if constexpr(_irq_type == irq_type::rx0) {
        NVIC_SetPriority(CAN2_RX0_IRQn, irqp);
        NVIC_EnableIRQ(CAN2_RX0_IRQn);
      }
      if constexpr(_irq_type == irq_type::rx1) {
        NVIC_SetPriority(CAN2_RX1_IRQn, irqp);
        NVIC_EnableIRQ(CAN2_RX1_IRQn);
      }
      if constexpr(_irq_type == irq_type::sce) {
        NVIC_SetPriority(CAN2_SCE_IRQn, irqp);
        NVIC_EnableIRQ(CAN2_SCE_IRQn);
      }
    }
#endif
  }
}

template<typename arg1, typename ...args>
void configure()
{
  if constexpr(sizeof...(args) > 0) { configure<args...>(); }
  constexpr auto m = arg1();

  static_assert(m.prediv >= 1 && m.prediv <= 1024, "CAN prescaler must be >= 1 and <= 1024");

#if defined(CAN1)
  if constexpr(m.module_id == module_id::can1) {
    RCC->APB1ENR  |=  RCC_APB1ENR_CAN1EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_CAN1RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST;
  }
#endif

#if defined(CAN2)
  if constexpr(m.module_id == module_id::can2) {
    RCC->APB1ENR  |=  RCC_APB1ENR_CAN2EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_CAN2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST;
  }
#endif

  auto inst = detail::inst<m.module_id>();

  // exit from sleep mode
  inst->MCR &= ~CAN_MCR_SLEEP;
  // request initialisation
  inst->MCR |= CAN_MCR_INRQ;
  // wait the acknowledge
  while((inst->MSR & CAN_MSR_INAK) == 0)
    ;

  {
    auto r = inst->MCR;
    r &= ~(CAN_MCR_TTCM | CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_NART | CAN_MCR_RFLM | CAN_MCR_TXFP);

    if constexpr(m.ttcm == ttcm::enable) { r |= CAN_MCR_TTCM; }
    if constexpr(m.abom == abom::enable) { r |= CAN_MCR_ABOM; }
    if constexpr(m.awum == awum::enable) { r |= CAN_MCR_AWUM; }
    if constexpr(m.nart == nart::enable) { r |= CAN_MCR_NART; }
    if constexpr(m.rflm == rflm::enable) { r |= CAN_MCR_RFLM; }
    if constexpr(m.txfp == txfp::enable) { r |= CAN_MCR_TXFP; }

    inst->MCR = r;
  }

  inst->BTR =
    []() -> uint32_t
    {
      switch(m.mode) {
      case mode::normal:          return 0;
      case mode::loopback:        return CAN_BTR_LBKM;
      case mode::silent:          return CAN_BTR_SILM;
      case mode::silent_loopback: return CAN_BTR_LBKM | CAN_BTR_SILM;
      }
    }() |
    []() -> uint32_t
    {
      switch(m.sjw) {
      case sjw::tq1: return 0;
      case sjw::tq2: return CAN_BTR_SJW_0;
      case sjw::tq3: return CAN_BTR_SJW_1;
      case sjw::tq4: return CAN_BTR_SJW;
      }
    }() |
    []() -> uint32_t
    {
      switch(m.bs1) {
      case bs1::tq1:  return 0;
      case bs1::tq2:  return 1  << CAN_BTR_TS1_Pos;
      case bs1::tq3:  return 2  << CAN_BTR_TS1_Pos;
      case bs1::tq4:  return 3  << CAN_BTR_TS1_Pos;
      case bs1::tq5:  return 4  << CAN_BTR_TS1_Pos;
      case bs1::tq6:  return 5  << CAN_BTR_TS1_Pos;
      case bs1::tq7:  return 6  << CAN_BTR_TS1_Pos;
      case bs1::tq8:  return 7  << CAN_BTR_TS1_Pos;
      case bs1::tq9:  return 8  << CAN_BTR_TS1_Pos;
      case bs1::tq10: return 9  << CAN_BTR_TS1_Pos;
      case bs1::tq11: return 10 << CAN_BTR_TS1_Pos;
      case bs1::tq12: return 11 << CAN_BTR_TS1_Pos;
      case bs1::tq13: return 12 << CAN_BTR_TS1_Pos;
      case bs1::tq14: return 13 << CAN_BTR_TS1_Pos;
      case bs1::tq15: return 14 << CAN_BTR_TS1_Pos;
      case bs1::tq16: return 15 << CAN_BTR_TS1_Pos;
      }
    }() |
    []() -> uint32_t
    {
      switch(m.bs2) {
      case bs2::tq1: return 0 << CAN_BTR_TS2_Pos;
      case bs2::tq2: return 1 << CAN_BTR_TS2_Pos;
      case bs2::tq3: return 2 << CAN_BTR_TS2_Pos;
      case bs2::tq4: return 3 << CAN_BTR_TS2_Pos;
      case bs2::tq5: return 4 << CAN_BTR_TS2_Pos;
      case bs2::tq6: return 5 << CAN_BTR_TS2_Pos;
      case bs2::tq7: return 6 << CAN_BTR_TS2_Pos;
      case bs2::tq8: return 7 << CAN_BTR_TS2_Pos;
      }
    }() |
    (m.prediv - 1)
  ;

  // request leave initialisation
  inst->MCR &= ~CAN_MCR_INRQ;
  // wait the acknowledge
  while((inst->MSR & CAN_MSR_INAK) == 0)
    ;

  enable_irq<m.module_id, decltype(m.irq0)>();
  enable_irq<m.module_id, decltype(m.irq1)>();
  enable_irq<m.module_id, decltype(m.irq2)>();
  enable_irq<m.module_id, decltype(m.irq3)>();
}

template<typename ...args>
void remap_configure()
{
  auto r = AFIO->MAPR;

#if defined(CAN1)
  if constexpr(has_module<module_id::can1, args...>()) {
    r &= ~AFIO_MAPR_CAN_REMAP;
  }
#endif

#if defined(CAN2)
  if constexpr(has_module<module_id::can2, args...>()) {
    r &= ~AFIO_MAPR_CAN2_REMAP;
  }
#endif

  r |= remap_bits<0, args...>();
  AFIO->MAPR = r;
}

template<typename _module, typename arg1, typename ...args>
void filter_enable()
{
  if constexpr(sizeof...(args) > 0) { filter_enable<_module, args...>(); }
  constexpr auto m    = _module();
  constexpr auto f    = arg1();
  constexpr auto fnum = f.number;
  constexpr auto fpos = 1 << fnum;

  static_assert(fnum < 28, "filter number must be >= 0 and <= 27");
  static_assert(f.fifo != fifo::any, "you must select fifo for filter");

  auto inst = detail::inst<m.module_id>();

  // enter to initialisation mode
  auto r = inst->FMR;
  r &= CAN_FMR_CAN2SB;
  r |= CAN_FMR_FINIT | (f.bank_num << CAN_FMR_CAN2SB_Pos);
  inst->FMR = r;

  // filter deactivation
  inst->FA1R &= ~fpos;

  if constexpr(f.filter_scale == filter_scale::fs16) {
    // 16-bit scale for the filter
    inst->FS1R &= ~fpos;
    inst->sFilterRegister[fnum].FR1 = ((f.maskid_low & 0xffff) << 16) | (f.id_low & 0xffff);
    inst->sFilterRegister[fnum].FR2 = ((f.maskid_high & 0xffff) << 16) | (f.id_high & 0xffff);
  }
  else {
    // 32-bit scale for the filter
    inst->FS1R |= fpos;
    inst->sFilterRegister[fnum].FR1 = ((f.id_high & 0xffff) << 16) | (f.id_low & 0xffff);
    inst->sFilterRegister[fnum].FR2 = ((f.maskid_high & 0xffff) << 16) | (f.maskid_low & 0xffff);
  }

  if constexpr(f.filter_mode == filter_mode::idmask) {
    inst->FM1R &= ~fpos;
  }
  else {
    inst->FM1R |= fpos;
  }

  if constexpr(f.fifo == fifo::fifo_0) {
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

template<typename _module, typename arg1, typename ...args>
void filter_disable()
{
  if constexpr(sizeof...(args) > 0) { filter_enable<_module, args...>(); }
  constexpr auto m    = _module();
  constexpr auto f    = arg1();
  constexpr auto fnum = f.number;
  constexpr auto fpos = 1 << fnum;

  static_assert(fnum < 28, "filter number must be >= 0 and <= 27");

  auto inst = detail::inst<m.module_id>();

  // enter to initialisation mode
  auto r = inst->FMR;
  r &= CAN_FMR_CAN2SB;
  r |= CAN_FMR_FINIT | (f.bank_num << CAN_FMR_CAN2SB_Pos);
  inst->FMR = r;

  // filter deactivation
  inst->FA1R &= ~fpos;
  // leave the initialisation mode
  inst->FMR &= ~CAN_FMR_FINIT;
}

template<typename _module, io::type _iotype>
io::result tx(uint32_t id, bool ide, bool rtr, const void *data, uint8_t len)
{
  constexpr auto m = _module();
  if(len < 1 || len > 8) { return io::result::error; }

  auto inst = detail::inst<m.module_id>();

  CAN_TxMailBox_TypeDef *mbox;

  if constexpr(_iotype == io::type::blocking) {
    while((inst->TSR & (CAN_TSR_TME0 | CAN_TSR_TME1 | CAN_TSR_TME2)) == 0)
      ;
  }

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
void abort_tx()
{
  constexpr auto m = _module();
  auto inst = detail::inst<m.module_id>();

  uint32_t rqcp = 0;
  if((inst->TSR & CAN_TSR_TME0) == 0) { rqcp |= CAN_TSR_RQCP0; }
  if((inst->TSR & CAN_TSR_TME1) == 0) { rqcp |= CAN_TSR_RQCP1; }
  if((inst->TSR & CAN_TSR_TME2) == 0) { rqcp |= CAN_TSR_RQCP2; }

  inst->TSR |= (CAN_TSR_ABRQ0 | CAN_TSR_ABRQ1 | CAN_TSR_ABRQ2);
  while((inst->TSR & rqcp) != rqcp)
    ;
}

template<typename _module, fifo _fifo, io::type _iotype>
io::result rx(uint32_t &id, bool &ide, bool &rtr, uint8_t &fmi, uint8_t data[8], uint8_t &len)
{
  constexpr auto m = _module();
  auto inst = detail::inst<m.module_id>();

  uint8_t fifo_n = 0xff;

  do {
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

    if constexpr(_iotype == io::type::nonblocking) {
      if(fifo_n == 0xff) { return io::result::busy; }
    }
  } while(fifo_n == 0xff);

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
    inst->RF0R |= CAN_RF0R_RFOM0;
  }
  else {
    inst->RF1R |= CAN_RF1R_RFOM1;
  }

  return io::result::success;
}

} // namespace detail
