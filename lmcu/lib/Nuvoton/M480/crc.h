#pragma once
#include <lmcu/dev/crc>
#include <lmcu/dev/rcc>
#include <lmcu/common>


// ------------------------------------------------------------------------------------------------
namespace lmcu::crc {
// ------------------------------------------------------------------------------------------------

enum class mode {
  _ccitt, //CRC-CCITT
  _8,  // CRC-8
  _16, // CRC-16
  _32  // CRC-32
};

enum class lenght {
  _8,
  _16,
  _32
};

enum class seed : uint32_t { };

template<auto ..._args>
struct config
{
  static constexpr auto dev_class = lmcu::dev_class::crc;

  static constexpr auto ip_ver = device::ip_version::_1;

  static constexpr auto mode = option::get<crc::mode, _args...>(crc::mode::_32);

  static constexpr auto lenght = option::get<crc::lenght, _args...>(crc::lenght::_32);

  static constexpr uint32_t seed = option::get_u<crc::seed, _args...>(crc::seed(0xFFFF));

  static_assert(option::check<
    std::tuple<
      crc::mode,
      crc::lenght,
      crc::seed
    >,
    _args...
  >());
};

template<typename _cfg>
void configure()
{
  using namespace device;

    CLK::AHBCLK::set_b(CLK::AHBCLK::CRCCKEN_1);

    CRC::SEED::set(_cfg::seed);

    uint32_t mode_mask = 0;
    switch(_cfg::mode)
    {
    case mode::_8: mode_mask = CRC::CTL::CRCMODE_1; break;
    case mode::_16: mode_mask = CRC::CTL::CRCMODE_2; break;
    case mode::_32: mode_mask = CRC::CTL::CRCMODE_3; break;
    default: break;
    }

    uint32_t data_len_mask = 0;
    switch(_cfg::lenght)
    {
    case lenght::_16: data_len_mask = CRC::CTL::DATLEN_1; break;
    case lenght::_32: data_len_mask = CRC::CTL::DATLEN_2; break;
    default: break;
    }

    uint32_t attr_mask = 0;


    CRC::CTL::set(mode_mask | attr_mask | data_len_mask | CRC::CTL::CRCEN_MASK);

    // setting CHKSINIT bit will reload the initial seed value(CRC_SEED register) to CRC controller
    CRC::CTL::set_b(CRC::CTL::CHKSINIT_MASK);

    CRC::CTL::set_b(CRC::CTL::DATREV_1);
    //CRC::CTL::set_b(CRC::CTL::CHKSREV_1);
}

template<typename _cfg>
lmcu_inline void reload()
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::crc);
  CRC::CTL::set_b(CRC::CTL::CHKSINIT_MASK);
}

template<typename _cfg>
lmcu_inline void seed(uint32_t s)
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::crc);
  CRC::SEED::set(s);
}

template<typename _cfg>
lmcu_inline void enable()
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::crc);
  CLK::AHBCLK::set_b(CLK::AHBCLK::CRCCKEN_1);
}

template<typename _cfg>
lmcu_inline void disable()
{
  using namespace device;
  static_assert(_cfg::dev_class == dev_class::crc);
  CLK::AHBCLK::clr_b(CLK::AHBCLK::CRCCKEN_1);
}

template<typename _cfg>
lmcu_inline uint32_t data_addr()
{
  using namespace device;
  return CRC::DAT::base;
}

template<typename _cfg>
lmcu_inline void data(uint32_t d)
{
  using namespace device;
  switch(_cfg::mode)
  {
  case mode::_8:
    CRC::DAT::set(d&0xFF);
    break;
  case mode::_ccitt:
  case mode::_16:
    CRC::DAT::set(d&0xFFFF);
    break;
  case mode::_32:
    CRC::DAT::set(d);
    break;
  default: break;
  }
}

template<typename _cfg>
lmcu_inline uint32_t get()
{
  using namespace device;
  uint32_t crc = 0;
  switch(_cfg::mode)
  {
  case mode::_8:
    crc = CRC::CHECKSUM::get() & 0xFF;
    break;
  case mode::_ccitt:
  case mode::_16:
    crc = CRC::CHECKSUM::get() & 0xFFFF;
    break;
  case mode::_32:
    crc = CRC::CHECKSUM::get();
    break;
  default: break;
  }

  return crc;
}


// ------------------------------------------------------------------------------------------------
} // namespace lmcu::crc
// ------------------------------------------------------------------------------------------------
