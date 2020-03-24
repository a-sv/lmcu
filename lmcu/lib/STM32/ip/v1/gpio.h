#pragma once
#include <lmcu/dev/rcc>
#include <lmcu/dev/gpio>
#include <lmcu/dev/afio>
#include <lmcu/common>

namespace lmcu::gpio {

enum class port { A, B, C, D, E, F, G, H, I, J, K };

enum class mode
{
  input,
  output_open_drain,
  output_push_pull,
  analog,
  af_input,
  af_open_drain,
  af_push_pull
};

enum class pull { no_pull, up, down };

enum class speed { low, medium, high, very_high };

enum class pin_n : uint32_t { };

// not connected pin
struct not_connected
{
  static constexpr auto dev_class = lmcu::dev_class::gpio_pin;
  static constexpr auto nc        = true;
};

template<typename _af, auto ..._args>
struct pin
{
  static constexpr auto dev_class = lmcu::dev_class::gpio_pin;

  static constexpr auto ip_version = lmcu::ip_version::_1;

  static constexpr auto port = option::get<gpio::port, _args...>();

  static constexpr auto n = option::get_u<gpio::pin_n, _args...>();

  static constexpr auto mask = 1UL << n;

  static constexpr auto mode = option::get<gpio::mode, _args...>(gpio::mode::analog);

  static constexpr auto pull = option::get<gpio::pull, _args...>(gpio::pull::no_pull);

  static constexpr auto speed = option::get<gpio::speed, _args...>(gpio::speed::low);

  static constexpr auto af = option::get<_af, _args...>();

  static constexpr auto nc = false;

  static_assert(!option::is_null<port>() && !option::is_null<n>(), "options 'port' and 'pin_n' is "
                                                                   "required!");

  static_assert(option::check<
    std::tuple<gpio::port, gpio::pin_n, gpio::mode, gpio::pull, gpio::speed, _af>,
    _args...
  >());
};

enum class remap
{
  jtag__full_swj,
  jtag__full_swj_without_njtrst,
  jtag__dp_disabled_and_sw_dp_enabled,
  jtag__dp_and_sw_dp_disabled,

#if defined(LMCU_STM32F1_CONNECTIVITY)
  ptp_pps__not_output_on_PB5,
  ptp_pps__output_on_PB5,

  tim2_itr1__ptp,
  tim2_itr1__usb_otg_sof,

  // SPI_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3, SPI3_MISO/PB4, SPI3_MOSI-I2S3_SD/PB5
  spi3_i2s3__no_remap,
  // SPI3_NSS-I2S3_WS/PA4, SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12
  spi3_i2s3__remap,

  eth__mii_phy,
  eth__rmii_phy,

  // CAN2_RX/PB12, CAN2_TX/PB13
  can2__no_remap,
  // CAN2_RX/PB5, CAN2_TX/PB6
  can2__remap,

  // RX_DV-CRS_DV/PA7, RXD0/PC4, RXD1/PC5, RXD2/PB0, RXD3/PB1
  eth__no_remap,
  // RX_DV-CRS_DV/PD8, RXD0/PD9, RXD1/PD10, RXD2/PD11, RXD3/PD12
  eth__remap,
#else
  adc2__etrgreg_exti11,
  adc2__etrgreg_tim8_trgo,
  adc2__etrginj_exti15,
  adc2__etrginj_tim8_channel4,

  adc1__etrgreg_exti11,
  adc1__etrgreg_tim8_trgo,
  adc1__etrginj_exti15,
  adc1__etrginj_tim8_channel4,
#endif

  tim5__ch4_PA3,
  tim5__ch4_lsiclk,

  PD0_no_remap__PD1_no_remap,
  PD0_osc_in__PD1_osc_out,

  // CAN_RX/PA11, CAN_TX/PA12
  can1__rx_PA11_tx_PA12,
  // CAN_RX/PB8, CAN_TX/PB9
  can1__rx_PB8_tx_PB9,
  // CAN_RX/PD0, CAN_TX/PD1
  can1__rx_PD0_tx_PD1,

  // TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9
  tim4__no_remap,
  // TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15
  tim4__full_remap,

  // CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1
  tim3__no_remap,
  // CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1
  tim3__partial_remap,
  // CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9
  tim3__full_remap,

  // CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3
  tim2__no_remap,
  // CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3
  tim2__partial_remap_1,
  // CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11
  tim2__partial_remap_2,
  // CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11
  tim2__full_remap,

  // ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15
  tim1__no_remap,
  // ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1
  tim1__partial_remap,
  // ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12
  tim1__full_remap,

  // TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14
  usart3__no_remap,
  // TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14
  usart3__partial_remap,
  // TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12
  usart3__full_remap,

  // CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4
  usart2__no_remap,
  // CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7
  usart2__remap,

  // TX/PA9, RX/PA10
  usart1__no_remap,
  // TX/PB6, RX/PB7
  usart1__remap,

  // SCL/PB6, SDA/PB7
  i2c1__no_remap,
  // SCL/PB8, SDA/PB9
  i2c1__remap,

  // NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7
  spi1__no_remap,
  // NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5
  spi1__remap,

  fsmc__nadv_connected,
  fsmc__nadv_not_connected,

  // TIM14_CH1/PA7
  tim14__no_remap,
  // TIM14_CH1/PF9
  tim14__remap,

  // TIM13_CH1/PA6
  tim13__no_remap,
  // TIM13_CH1/PF8
  tim13__remap,

  // TIM11_CH1/PB9
  tim11__no_remap,
  // TIM11_CH1/PF7
  tim11__remap,

  // TIM10_CH1/PB8
  tim10__no_remap,
  // TIM10_CH1/PF6
  tim10__remap,

  // TIM9_CH1/PA2, TIM9_CH2/PA3
  tim9__no_remap,
  // TIM9_CH1/PE5, TIM9_CH2/PE6
  tim9__remap
};

/**
 * @brief Returns 'true' if ports exists on current device
 *
 * @tparam _ports - port list
*/
template <port ..._ports>
constexpr bool port_exists() noexcept;

// ------------------------------------------------------------------------------------------------
namespace detail {
// ------------------------------------------------------------------------------------------------

template<port _port>
struct inst;

template<>
struct inst<port::A> { using type = device::GPIOA; };

template<>
struct inst<port::B> { using type = device::GPIOB; };

template<>
struct inst<port::C> { using type = device::GPIOC; };

template<>
struct inst<port::D> { using type = device::GPIOD; };

template<>
struct inst<port::E> { using type = device::GPIOE; };

template<>
struct inst<port::F> { using type = device::GPIOF; };

template<>
struct inst<port::G> { using type = device::GPIOG; };

template<port _port>
using inst_t = typename inst<_port>::type;

template<port _port, typename ..._pins>
constexpr uint32_t pin_mask()
{
  auto bits = [](auto pin) -> uint32_t
  {
    return pin.port == _port? pin.mask : 0;
  };
  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
lmcu_inline void set([[maybe_unused]] bool val)
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    inst_t<_port>::BSRR::set(val? msk : msk << 16);
  }
}

template<port _port, typename ..._pins>
lmcu_inline void toggle()
{
  constexpr auto msk = pin_mask<_port, _pins...>();
  if constexpr(msk != 0) {
    inst_t<_port>::ODR::ref() ^= msk;
  }
}

template<typename _pin>
constexpr bool is_input(_pin&& pin) noexcept
{
  return pin.mode == mode::input || pin.mode == mode::analog || pin.mode == mode::af_input;
}

template<bool _low, port _port, typename ..._pins>
constexpr uint32_t cr_bits()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port && ((_low && p.n <= 7) || (!_low && p.n >= 8))) {
      const uint32_t
      m_ofs = (_low? p.n : p.n - 8) * 4,
      c_ofs = m_ofs + 2
      ;

      if(is_input(p)) {
        if(p.mode != mode::analog) {
          if(p.pull == pull::no_pull) {
            return 1UL << c_ofs; // floating input
          }
          return 2UL << c_ofs; // input with pull-up / pull-down
        }
      }
      else {
        uint32_t m = 0, c = 0;

        switch(p.speed)
        {
        case speed::low: m = 2; break; // 2 MHz
        case speed::medium: m = 1; break; // 10 MHz
        default: m = 3; break; // 50 Mhz
        }

        switch(p.mode)
        {
        case mode::output_open_drain: c = 1; break; // general purpose output open-drain
        case mode::af_push_pull: c = 2; break; // alternate function output push-pull
        case mode::af_open_drain: c = 3; break; // alternate function output open-drain
        default: break;
        }

        return (c << c_ofs) | (m << m_ofs);
      }
    }

    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<bool _low, port _port, typename ..._pins>
constexpr uint32_t cr_mask()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(p.port == _port && ((_low && p.n <= 7) || (!_low && p.n >= 8))) {
      const uint32_t m_ofs = (_low? p.n : p.n - 8) * 4;
      return 0xfUL << m_ofs;
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
constexpr uint32_t bsrr_bits()
{
  auto bits = [](auto&& p) -> uint32_t
  {
    if(_port == p.port && is_input(p)) {
      if(p.pull == pull::up) {
        return 1UL << p.n;
      }
      else
      if(p.pull == pull::down) {
        return 1UL << (p.n + 16);
      }
    }
    return 0;
  };

  return (bits(_pins{}) | ...);
}

template<port _port, typename ..._pins>
void configure_port()
{
  using namespace device;

  constexpr auto crl_msk = detail::cr_mask<true, _port, _pins...>();
  if constexpr(crl_msk != 0) {
    inst_t<_port>::CRL::clr_b(crl_msk);
    inst_t<_port>::CRL::set_b(detail::cr_bits<true, _port, _pins...>());
  }

  constexpr auto crh_msk = detail::cr_mask<false, _port, _pins...>();
  if constexpr(crh_msk != 0) {
    inst_t<_port>::CRH::clr_b(crh_msk);
    inst_t<_port>::CRH::set_b(detail::cr_bits<false, _port, _pins...>());
  }

  constexpr auto bsrr = bsrr_bits<_port, _pins...>();
  if constexpr(bsrr != 0) {
    inst_t<_port>::BSRR::set(bsrr);
  }
}

// ------------------------------------------------------------------------------------------------
} // namespace detail
// ------------------------------------------------------------------------------------------------

/**
 * @brief I/O ports clock enable
*/
template<port ..._ports>
void on()
{
  using namespace device;

  static_assert(port_exists<_ports...>(), "port does not exists in this device");

  auto port_on = [](auto val)
  {
    switch(val)
    {
    case port::A: RCC::APB2ENR::set_b(RCC::APB2ENR::IOPAEN); break;
    case port::B: RCC::APB2ENR::set_b(RCC::APB2ENR::IOPBEN); break;
    case port::C: RCC::APB2ENR::set_b(RCC::APB2ENR::IOPCEN); break;
    case port::D: RCC::APB2ENR::set_b(RCC::APB2ENR::IOPDEN); break;
    case port::E: RCC::APB2ENR::set_b(RCC::APB2ENR::IOPEEN); break;
#if !defined(LMCU_STM32F1_CONNECTIVITY)
    case port::F: RCC::APB2ENR::set_b(RCC::APB2ENR::IOPFEN); break;
    case port::G: RCC::APB2ENR::set_b(RCC::APB2ENR::IOPGEN); break;
#endif
    default: break;
    }
  };

  (port_on(_ports), ...);
}

/**
 * @brief I/O ports clock disable
*/
template<port ..._ports>
void off()
{
  using namespace device;

  static_assert(port_exists<_ports...>(), "port does not exists in this device");

  auto port_off = [](auto val)
  {
    switch(val)
    {
    case port::A: RCC::APB2ENR::clr_b(RCC::APB2ENR::IOPAEN); break;
    case port::B: RCC::APB2ENR::clr_b(RCC::APB2ENR::IOPBEN); break;
    case port::C: RCC::APB2ENR::clr_b(RCC::APB2ENR::IOPCEN); break;
    case port::D: RCC::APB2ENR::clr_b(RCC::APB2ENR::IOPDEN); break;
    case port::E: RCC::APB2ENR::clr_b(RCC::APB2ENR::IOPEEN); break;
#if !defined(LMCU_STM32F1_CONNECTIVITY)
    case port::F: RCC::APB2ENR::clr_b(RCC::APB2ENR::IOPFEN); break;
    case port::G: RCC::APB2ENR::clr_b(RCC::APB2ENR::IOPGEN); break;
#endif
    default: break;
    }
  };

  (port_off(_ports), ...);
}

/**
 * @brief I/O ports reset
*/
template<port ..._ports>
void reset()
{
  using namespace device;

  static_assert(port_exists<_ports...>(), "port does not exists in this device");

  auto port_rst = [](auto val)
  {
    switch(val)
    {
    case port::A:
      RCC::APB2RSTR::set_b(RCC::APB2RSTR::IOPARST);
      RCC::APB2RSTR::clr_b(RCC::APB2RSTR::IOPARST);
      break;
    case port::B:
      RCC::APB2RSTR::set_b(RCC::APB2RSTR::IOPBRST);
      RCC::APB2RSTR::clr_b(RCC::APB2RSTR::IOPBRST);
      break;
    case port::C:
      RCC::APB2RSTR::set_b(RCC::APB2RSTR::IOPCRST);
      RCC::APB2RSTR::clr_b(RCC::APB2RSTR::IOPCRST);
      break;
    case port::D:
      RCC::APB2RSTR::set_b(RCC::APB2RSTR::IOPDRST);
      RCC::APB2RSTR::clr_b(RCC::APB2RSTR::IOPDRST);
      break;
    case port::E:
      RCC::APB2RSTR::set_b(RCC::APB2RSTR::IOPERST);
      RCC::APB2RSTR::clr_b(RCC::APB2RSTR::IOPERST);
      break;
#if !defined(LMCU_STM32F1_CONNECTIVITY)
    case port::F:
      RCC::APB2RSTR::set_b(RCC::APB2RSTR::IOPFRST);
      RCC::APB2RSTR::clr_b(RCC::APB2RSTR::IOPFRST);
      break;
    case port::G:
      RCC::APB2RSTR::set_b(RCC::APB2RSTR::IOPGRST);
      RCC::APB2RSTR::clr_b(RCC::APB2RSTR::IOPGRST);
      break;
#endif
    default: break;
    }
  };

  (port_rst(_ports), ...);
}

template<typename ..._pins>
void configure()
{
  static_assert(port_exists<_pins::port...>(), "port does not exists in this device");

  detail::configure_port<port::A, _pins...>();
  detail::configure_port<port::B, _pins...>();
  detail::configure_port<port::C, _pins...>();
  detail::configure_port<port::D, _pins...>();
  detail::configure_port<port::E, _pins...>();
  detail::configure_port<port::F, _pins...>();
  detail::configure_port<port::G, _pins...>();
}

/**
 * @brief Alternate function I/O enable
*/
lmcu_static_inline void afio_on()
{
  device::RCC::APB2ENR::set_b(device::RCC::APB2ENR::AFIOEN);
}

/**
 * @brief Alternate function I/O disable
*/
lmcu_static_inline void afio_off()
{
  device::RCC::APB2ENR::clr_b(device::RCC::APB2ENR::AFIOEN);
}

/**
 * @brief Alternate function I/O reset
*/
lmcu_static_inline void afio_reset()
{
  device::RCC::APB2RSTR::set_b(device::RCC::APB2RSTR::AFIORST);
  device::RCC::APB2RSTR::clr_b(device::RCC::APB2RSTR::AFIORST);
}

/**
 * @brief Event output enable (SEV)
 *
 * @tparam _pin  - GPIO pin
*/
template<typename _pin>
lmcu_inline void eventout_on()
{
  static_assert(_pin::mode == mode::output_open_drain || _pin::mode == mode::output_push_pull,
                "for 'eventout' GPIO pin must be configured as output");

  using namespace device;

  uint32_t r = AFIO::EVCR::EVOE;

  switch(_pin::port)
  {
  case port::B: r |= AFIO::EVCR::PORT_B; break;
  case port::C: r |= AFIO::EVCR::PORT_C; break;
  case port::D: r |= AFIO::EVCR::PORT_D; break;
  case port::E: r |= AFIO::EVCR::PORT_E; break;
  default: break;
  }

  r |= (uint32_t(_pin::n) & 0xf) << AFIO::EVCR::PIN_POS;

  AFIO::EVCR::set(r);
}

/**
 * @brief Event output disable (SEV)
*/
lmcu_static_inline void eventout_off() { device::AFIO::EVCR::clr_b(device::AFIO::EVCR::EVOE); }

template<remap ..._remap>
lmcu_inline void remap()
{
  using namespace device;

  auto mapr_bits = [](bool mask, auto val) -> uint32_t
  {
    switch(val)
    {
#if defined(LMCU_STM32F1_CONNECTIVITY)
    case remap::ptp_pps__not_output_on_PB5:
      return mask? AFIO::MAPR::PTP_PPS_REMAP_MASK : 0;
    case remap::ptp_pps__output_on_PB5:
      return mask? AFIO::MAPR::PTP_PPS_REMAP_MASK : AFIO::MAPR::PTP_PPS_REMAP;
    case remap::tim2_itr1__ptp:
      return mask? AFIO::MAPR::TIM2ITR1_IREMAP_MASK : 0;
    case remap::tim2_itr1__usb_otg_sof:
      return mask? AFIO::MAPR::TIM2ITR1_IREMAP_MASK : AFIO::MAPR::TIM2ITR1_IREMAP;
    case remap::spi3_i2s3__no_remap:
      return mask? AFIO::MAPR::SPI3_REMAP_MASK : 0;
    case remap::spi3_i2s3__remap:
      return mask? AFIO::MAPR::SPI3_REMAP_MASK : AFIO::MAPR::SPI3_REMAP;
#endif

    case remap::jtag__full_swj:
      return mask? AFIO::MAPR::SWJ_CFG_MASK : AFIO::MAPR::SWJ_CFG_FULL_SWJ;
    case remap::jtag__full_swj_without_njtrst:
      return mask? AFIO::MAPR::SWJ_CFG_MASK : AFIO::MAPR::SWJ_CFG_FULL_SWJ_WITHOUT_NJTRST;
    case remap::jtag__dp_disabled_and_sw_dp_enabled:
      return mask? AFIO::MAPR::SWJ_CFG_MASK : AFIO::MAPR::SWJ_CFG_JTAG_DP_DISABLED_SW_DP_ENABLED;
    case remap::jtag__dp_and_sw_dp_disabled:
      return mask? AFIO::MAPR::SWJ_CFG_MASK : AFIO::MAPR::SWJ_CFG_JTAG_DP_DISABLED_SW_DP_DISABLED;

#if defined(LMCU_STM32F1_CONNECTIVITY)
    case remap::eth__mii_phy:
      return mask? AFIO::MAPR::MII_RMII_SEL_MASK : 0;
    case remap::eth__rmii_phy:
      return mask? AFIO::MAPR::MII_RMII_SEL_MASK : AFIO::MAPR::MII_RMII_SEL;
    case remap::can2__no_remap:
      return mask? AFIO::MAPR::CAN2_REMAP_MASK : 0;
    case remap::can2__remap:
      return mask? AFIO::MAPR::CAN2_REMAP_MASK : AFIO::MAPR::CAN2_REMAP;
    case remap::eth__no_remap:
      return mask? AFIO::MAPR::ETH_REMAP_MASK : 0;
    case remap::eth__remap:
      return mask? AFIO::MAPR::ETH_REMAP_MASK : AFIO::MAPR::ETH_REMAP;
#endif

    case remap::tim5__ch4_PA3:
      return mask? AFIO::MAPR::TIM5CH4_IREMAP_MASK : 0;
    case remap::tim5__ch4_lsiclk:
      return mask? AFIO::MAPR::TIM5CH4_IREMAP_MASK : AFIO::MAPR::TIM5CH4_IREMAP;
    case remap::PD0_no_remap__PD1_no_remap:
      return mask? AFIO::MAPR::PD01_REMAP_MASK : 0;
    case remap::PD0_osc_in__PD1_osc_out:
      return mask? AFIO::MAPR::PD01_REMAP_MASK : AFIO::MAPR::PD01_REMAP;
    case remap::can1__rx_PA11_tx_PA12:
      return mask? AFIO::MAPR::CAN1_REMAP_MASK : AFIO::MAPR::CAN1_REMAP_NO_REMAP;
    case remap::can1__rx_PB8_tx_PB9:
      return mask? AFIO::MAPR::CAN1_REMAP_MASK : AFIO::MAPR::CAN1_REMAP_FULL_REMAP1;
    case remap::can1__rx_PD0_tx_PD1:
      return mask? AFIO::MAPR::CAN1_REMAP_MASK : AFIO::MAPR::CAN1_REMAP_FULL_REMAP2;
    case remap::tim4__no_remap:
      return mask? AFIO::MAPR::TIM4_REMAP_MASK : 0;
    case remap::tim4__full_remap:
      return mask? AFIO::MAPR::TIM4_REMAP_MASK : AFIO::MAPR::TIM4_REMAP;
    case remap::tim3__no_remap:
      return mask? AFIO::MAPR::TIM3_REMAP_MASK : AFIO::MAPR::TIM3_REMAP_NO_REMAP;
    case remap::tim3__partial_remap:
      return mask? AFIO::MAPR::TIM3_REMAP_MASK : AFIO::MAPR::TIM3_REMAP_PARTIAL_REMAP;
    case remap::tim3__full_remap:
      return mask? AFIO::MAPR::TIM3_REMAP_MASK : AFIO::MAPR::TIM3_REMAP_FULL_REMAP;
    case remap::tim2__no_remap:
      return mask? AFIO::MAPR::TIM2_REMAP_MASK : AFIO::MAPR::TIM2_REMAP_NO_REMAP;
    case remap::tim2__partial_remap_1:
      return mask? AFIO::MAPR::TIM2_REMAP_MASK : AFIO::MAPR::TIM2_REMAP_PARTIAL_REMAP1;
    case remap::tim2__partial_remap_2:
      return mask? AFIO::MAPR::TIM2_REMAP_MASK : AFIO::MAPR::TIM2_REMAP_PARTIAL_REMAP2;
    case remap::tim2__full_remap:
      return mask? AFIO::MAPR::TIM2_REMAP_MASK : AFIO::MAPR::TIM2_REMAP_FULL_REMAP;
    case remap::tim1__no_remap:
      return mask? AFIO::MAPR::TIM1_REMAP_MASK : AFIO::MAPR::TIM1_REMAP_NO_REMAP;
    case remap::tim1__partial_remap:
      return mask? AFIO::MAPR::TIM1_REMAP_MASK : AFIO::MAPR::TIM1_REMAP_PARTIAL_REMAP;
    case remap::tim1__full_remap:
      return mask? AFIO::MAPR::TIM1_REMAP_MASK : AFIO::MAPR::TIM1_REMAP_FULL_REMAP;
    case remap::usart3__no_remap:
      return mask? AFIO::MAPR::USART3_REMAP_MASK : AFIO::MAPR::USART3_REMAP_NO_REMAP;
    case remap::usart3__partial_remap:
      return mask? AFIO::MAPR::USART3_REMAP_MASK : AFIO::MAPR::USART3_REMAP_PARTIAL_REMAP;
    case remap::usart3__full_remap:
      return mask? AFIO::MAPR::USART3_REMAP_MASK : AFIO::MAPR::USART3_REMAP_FULL_REMAP;
    case remap::usart2__no_remap:
      return mask? AFIO::MAPR::USART2_REMAP_MASK : 0;
    case remap::usart2__remap:
      return mask? AFIO::MAPR::USART2_REMAP_MASK : AFIO::MAPR::USART2_REMAP;
    case remap::usart1__no_remap:
      return mask? AFIO::MAPR::USART1_REMAP_MASK : 0;
    case remap::usart1__remap:
      return mask? AFIO::MAPR::USART1_REMAP_MASK : AFIO::MAPR::USART1_REMAP;
    case remap::i2c1__no_remap:
      return mask? AFIO::MAPR::I2C1_REMAP_MASK : 0;
    case remap::i2c1__remap:
      return mask? AFIO::MAPR::I2C1_REMAP_MASK : AFIO::MAPR::I2C1_REMAP;
    case remap::spi1__no_remap:
      return mask? AFIO::MAPR::SPI1_REMAP_MASK : 0;
    case remap::spi1__remap:
      return mask? AFIO::MAPR::SPI1_REMAP_MASK : AFIO::MAPR::SPI1_REMAP;

#if !defined(LMCU_STM32F1_CONNECTIVITY)
    case remap::adc2__etrgreg_exti11:
      return mask? AFIO::MAPR::ADC2_ETRGREG_REMAP_MASK : 0;
    case remap::adc2__etrgreg_tim8_trgo:
      return mask? AFIO::MAPR::ADC2_ETRGREG_REMAP_MASK : AFIO::MAPR::ADC2_ETRGREG_REMAP;
    case remap::adc2__etrginj_exti15:
      return mask? AFIO::MAPR::ADC2_ETRGINJ_REMAP_MASK : 0;
    case remap::adc2__etrginj_tim8_channel4:
      return mask? AFIO::MAPR::ADC2_ETRGINJ_REMAP_MASK : AFIO::MAPR::ADC2_ETRGINJ_REMAP;
    case remap::adc1__etrgreg_exti11:
      return mask? AFIO::MAPR::ADC1_ETRGREG_REMAP_MASK : 0;
    case remap::adc1__etrgreg_tim8_trgo:
      return mask? AFIO::MAPR::ADC1_ETRGREG_REMAP_MASK : AFIO::MAPR::ADC1_ETRGREG_REMAP;
    case remap::adc1__etrginj_exti15:
      return mask? AFIO::MAPR::ADC1_ETRGINJ_REMAP_MASK : 0;
    case remap::adc1__etrginj_tim8_channel4:
      return mask? AFIO::MAPR::ADC1_ETRGINJ_REMAP_MASK : AFIO::MAPR::ADC1_ETRGINJ_REMAP;
#endif

    default: break;
    }
    return 0;
  };

  auto mapr2_bits = [](bool mask, auto val) -> uint32_t
  {
    switch(val)
    {
    case remap::fsmc__nadv_connected:
      return mask? AFIO::MAPR2::FSMC_NADV_MASK : 0;
    case remap::fsmc__nadv_not_connected:
      return mask? AFIO::MAPR2::FSMC_NADV_MASK : AFIO::MAPR2::FSMC_NADV;
    case remap::tim14__no_remap:
      return mask? AFIO::MAPR2::TIM14_REMAP_MASK : 0;
    case remap::tim14__remap:
      return mask? AFIO::MAPR2::TIM14_REMAP_MASK : AFIO::MAPR2::TIM14_REMAP;
    case remap::tim13__no_remap:
      return mask? AFIO::MAPR2::TIM13_REMAP_MASK : 0;
    case remap::tim13__remap:
      return mask? AFIO::MAPR2::TIM13_REMAP_MASK : AFIO::MAPR2::TIM13_REMAP;
    case remap::tim11__no_remap:
      return mask? AFIO::MAPR2::TIM11_REMAP_MASK : 0;
    case remap::tim11__remap:
      return mask? AFIO::MAPR2::TIM11_REMAP_MASK : AFIO::MAPR2::TIM11_REMAP;
    case remap::tim10__no_remap:
      return mask? AFIO::MAPR2::TIM10_REMAP_MASK : 0;
    case remap::tim10__remap:
      return mask? AFIO::MAPR2::TIM10_REMAP_MASK : AFIO::MAPR2::TIM10_REMAP;
    case remap::tim9__no_remap:
      return mask? AFIO::MAPR2::TIM9_REMAP_MASK : 0;
    case remap::tim9__remap:
      return mask? AFIO::MAPR2::TIM9_REMAP_MASK : AFIO::MAPR2::TIM9_REMAP;
    default: break;
    }
    return 0;
  };

  if constexpr(constexpr auto mask = (mapr_bits(true, _remap) | ...); mask != 0) {
    auto r = AFIO::MAPR::get();
    r &= ~mask;
    r |= (mapr_bits(false, _remap) | ...);
    AFIO::MAPR::set(r);
  }

  if constexpr(constexpr auto mask = (mapr2_bits(true, _remap) | ...); mask != 0) {
    auto r = AFIO::MAPR2::get();
    r &= ~mask;
    r |= (mapr2_bits(false, _remap) | ...);
    AFIO::MAPR2::set(r);
  }
}

/**
 * @brief Set pin's output state
 *
 * @tparam _pins - list of pins
 * @param  val   - pin state (true == 1, false == 0)
*/
template<typename ..._pins>
lmcu_inline void set(bool val)
{
  detail::set<port::A, _pins...>(val);
  detail::set<port::B, _pins...>(val);
  detail::set<port::C, _pins...>(val);
  detail::set<port::D, _pins...>(val);
  detail::set<port::E, _pins...>(val);
  detail::set<port::F, _pins...>(val);
  detail::set<port::G, _pins...>(val);
  detail::set<port::H, _pins...>(val);
  detail::set<port::I, _pins...>(val);
  detail::set<port::J, _pins...>(val);
  detail::set<port::K, _pins...>(val);
}

/**
 * @brief Toggle pin's output state
 *
 * @tparam _pins - list of pins
*/
template<typename ..._pins>
lmcu_inline void toggle()
{
  detail::toggle<port::A, _pins...>();
  detail::toggle<port::B, _pins...>();
  detail::toggle<port::C, _pins...>();
  detail::toggle<port::D, _pins...>();
  detail::toggle<port::E, _pins...>();
  detail::toggle<port::F, _pins...>();
  detail::toggle<port::G, _pins...>();
  detail::toggle<port::H, _pins...>();
  detail::toggle<port::I, _pins...>();
  detail::toggle<port::J, _pins...>();
  detail::toggle<port::K, _pins...>();
}

/**
 * @brief Set port output state
 *
 * @tparam _port - GPIO port
 * @param  val   - bits to set on port
*/
template<port _port>
lmcu_inline void set(uint32_t val) { detail::inst_t<_port>::ODR::set(val); }

/**
 * @brief Toggle port output state
 *
 * @tparam _port - GPIO port
*/
template<port _port>
lmcu_inline void toggle() { detail::inst_t<_port>::ODR::ref() ^= 0xffff; }

/**
 * @brief Returns current port or pin output state (ODR).
 *
 * @tparam _p - gpio port or pin
*/
template<typename _p>
lmcu_inline auto get()
{
  if constexpr(std::is_same_v<_p, port>) {
    return detail::inst_t<_p{}>::ODR::get();
  }
  else {
    return (detail::inst_t<_p::port>::ODR::get() & _p::mask) != 0;
  }
}

/**
 * @brief Reads input signal on the port or pin (IDR).
 *
 * @tparam _p - gpio port or pin
*/
template<typename _p>
lmcu_inline auto read()
{
  if constexpr(std::is_same_v<_p, port>) {
    return detail::inst_t<_p{}>::IDR::get();
  }
  else {
    return (detail::inst_t<_p::port>::IDR::get() & _p::mask) != 0;
  }
}

} // namespace lmcu::gpio
