#pragma once

namespace detail {

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
}

template<uint32_t r, typename arg1, typename ...args>
uint32_t remap_bits();

} // namespace detail
