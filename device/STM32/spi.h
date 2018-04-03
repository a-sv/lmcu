#pragma once
#include <lmcu/device>

namespace lmcu {
namespace spi {

enum class module_id
{
#if defined(SPI1)
  spi1,
#endif

#if defined(SPI2)
  spi2,
#endif

#if defined(SPI3)
  spi3,
#endif

#if defined(SPI4)
  spi4,
#endif

#if defined(SPI5)
  spi5,
#endif

#if defined(SPI6)
  spi6
#endif
};

enum class mode { slave, master, multi_master };

enum class direction { two_lines, two_lines_rxonly, one_line };

enum class datasize { byte, word };

enum class polarity { low, high };

enum class phase { one_edge, two_edge };

enum class nss { soft, hard };

enum class baud_prediv
{
  div_2   = 2,
  div_4   = 4,
  div_8   = 8,
  div_16  = 16,
  div_32  = 32,
  div_64  = 64,
  div_128 = 128,
  div_256 = 256
};

enum class bit_order { msb, lsb };

enum class crc { enable, disable };

namespace detail {

template<module_id _module_id>
SPI_TypeDef *inst()
{
#if defined(SPI1)
  if constexpr(_module_id == module_id::spi1) { return SPI1; }
#endif

#if defined(SPI2)
  if constexpr(_module_id == module_id::spi2) { return SPI2; }
#endif

#if defined(SPI3)
  if constexpr(_module_id == module_id::spi3) { return SPI3; }
#endif

#if defined(SPI4)
  if constexpr(_module_id == module_id::spi4) { return SPI4; }
#endif

#if defined(SPI5)
  if constexpr(_module_id == module_id::spi5) { return SPI5; }
#endif

#if defined(SPI6)
  if constexpr(_module_id == module_id::spi6) { return SPI6; }
#endif
}

} // namespace detail

template<
  module_id _module_id,
  mode _mode,
  direction _direction,
  datasize _datasize,
  polarity _polarity,
  phase _phase,
  nss _nss,
  baud_prediv _baud_prediv,
  bit_order _bit_order,
  crc _crc = crc::disable,
  uint32_t _crc_poly = 0x7
>
struct module
{
  static constexpr auto module_id   = _module_id;
  static constexpr auto mode        = _mode;
  static constexpr auto direction   = _direction;
  static constexpr auto datasize    = _datasize;
  static constexpr auto polarity    = _polarity;
  static constexpr auto phase       = _phase;
  static constexpr auto nss         = _nss;
  static constexpr auto baud_prediv = _baud_prediv;
  static constexpr auto bit_order   = _bit_order;
  static constexpr auto crc         = _crc;
  static constexpr auto crc_poly    = _crc_poly;
};

} // namespace spi
} // namespace lmcu
