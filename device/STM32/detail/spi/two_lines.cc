#include <lmcu/device>
#include <lmcu/delay>
#include "../../spi.h"

namespace lmcu {
namespace spi {
namespace detail {
namespace two_lines {

//
// slave rx
//

uint16_t slave_rx(SPI_TypeDef *inst)
{ return detail::slave_rx<direction::two_lines, false>(inst); }

uint16_t slave_rx_with_crc(SPI_TypeDef *inst)
{ return detail::slave_rx<direction::two_lines, true>(inst); }

//
// slave tx
//

void slave_tx(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::two_lines, false>(inst, data); }

void slave_tx_with_crc(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::two_lines, true>(inst, data); }

//
// master rx
//

uint16_t master_rx(SPI_TypeDef *inst)
{ return detail::master_rx<direction::two_lines, false>(inst, []{}); }

uint16_t master_rx_with_crc(SPI_TypeDef *inst)
{ return detail::master_rx<direction::two_lines, true>(inst, []{}); }

//
// master tx
//

void master_tx(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::two_lines, false>(inst, data); }

void master_tx_with_crc(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::two_lines, true>(inst, data); }

//
// slave read
//

void slave_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines, false>(inst, data, count); }

void slave_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines, true>(inst, data, count); }

void slave_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines, false>(inst, data, count); }

void slave_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines, true>(inst, data, count); }

//
// slave write
//

void slave_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::two_lines, false>(inst, data, count); }

void slave_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::two_lines, true>(inst, data, count); }

void slave_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::two_lines, false>(inst, data, count); }

void slave_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::two_lines, true>(inst, data, count); }

//
// master read
//

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::master_read<direction::two_lines, false>(inst, data, count, []{}); }

void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::master_read<direction::two_lines, true>(inst, data, count, []{}); }

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::master_read<direction::two_lines, false>(inst, data, count, []{}); }

void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::master_read<direction::two_lines, true>(inst, data, count, []{}); }

//
// master write
//

void master_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::two_lines, false>(inst, data, count); }

void master_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::two_lines, true>(inst, data, count); }

void master_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::two_lines, false>(inst, data, count); }

void master_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::two_lines, true>(inst, data, count); }

} // namespace two_lines
} // namespace detail
} // namespace lmcu
} // namespace spi
