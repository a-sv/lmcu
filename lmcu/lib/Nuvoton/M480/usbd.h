#pragma once
#include <lmcu/common>
#include <lmcu/dev/usb>
#include <lmcu/dev/rcc>
#include <lmcu/irq>

#include "sys.h"

// ------------------------------------------------------------------------------------------------
namespace lmcu::usb {
// ------------------------------------------------------------------------------------------------
#include "../../irq_id.h"

enum class mode { device, host, id, otg };

template <auto ..._args>
constexpr auto irq = nvic::encode_irq_conf<irq_id::_0, _args...>();


template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::usb;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto mode = option::get<usb::mode, _args...>(usb::mode::device);

  static constexpr auto irq = option::get<irq_id::_0, _args...>();

  static_assert(option::check<
    std::tuple<
      usb::mode,
      irq_id::_0
      >,
    _args...
  >());
};

template<typename _cfg>
void configure()
{
  using namespace device;

  sys::unlock();

  SYS::USBPHY::clr_b(SYS::USBPHY::USBROLE_MASK); // device
  switch(_cfg::mode)
  {
  case mode::host: SYS::USBPHY::set_b(SYS::USBPHY::USBROLE_1); break;
  case mode::id:   SYS::USBPHY::set_b(SYS::USBPHY::USBROLE_2); break;
  case mode::otg:  SYS::USBPHY::set_b(SYS::USBPHY::USBROLE_3); break;
  default: break;
  }

  // enable USB PHY
  SYS::USBPHY::set_b(SYS::USBPHY::USBEN_1 | SYS::USBPHY::SBO);

  if constexpr(!option::is_null<_cfg::irq>()) {
    constexpr auto irqn = device::find_irqn("usbd");
    nvic::set_encoded_priority<irqn, _cfg::irq>();
    nvic::enable_irq<irqn>();
  }
}

template<typename _cfg>
lmcu_inline void enable()
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::usb);

  CLK::APBCLK0::set_b(CLK::APBCLK0::USBDCKEN_1);
}

template<typename _cfg>
lmcu_inline void disable()
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::usb);

  CLK::APBCLK0::clr_b(CLK::APBCLK0::USBDCKEN_1);

  if constexpr(!option::is_null<_cfg::irq>()) {
    constexpr auto irqn = device::find_irqn("usbd");
    nvic::set_encoded_priority<irqn, _cfg::irq>();
    nvic::disable_irq<irqn>();
  }
}

// ------------------------------------------------------------------------------------------------
} // namespace lmcu::usb
// ------------------------------------------------------------------------------------------------
