#include <lmcu/device>
#include <lmcu/delay>
#include "../../spi.h"

namespace lmcu {
namespace spi {
namespace detail {
namespace one_line {

//
// slave rx
//

uint16_t slave_rx(SPI_TypeDef *inst)
{ return detail::slave_rx<direction::one_line, false>(inst); }

uint16_t slave_rx_with_crc(SPI_TypeDef *inst)
{ return detail::slave_rx<direction::one_line, true>(inst); }

//
// slave tx
//

void slave_tx(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::one_line, false>(inst, data); }

void slave_tx_with_crc(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::one_line, true>(inst, data); }

//
// master rx
//

uint16_t master_rx(SPI_TypeDef *inst)
{ return detail::master_rx<direction::one_line, false>(inst, delay_4cyc); }

uint16_t master_rx_with_crc(SPI_TypeDef *inst)
{ return detail::master_rx<direction::one_line, true>(inst, delay_4cyc); }

uint16_t master_rx(SPI_TypeDef *inst, uint32_t delay_val)
{ return detail::master_rx<direction::one_line, false>(inst, [&] { delay::cyc(delay_val); }); }

uint16_t master_rx_with_crc(SPI_TypeDef *inst, uint32_t delay_val)
{ return detail::master_rx<direction::one_line, true>(inst, [&] { delay::cyc(delay_val); }); }

//
// master tx
//

void master_tx(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::one_line, false>(inst, data); }

void master_tx_with_crc(SPI_TypeDef *inst, uint16_t data)
{ detail::tx<direction::one_line, true>(inst, data); }

//
// slave read
//

void slave_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::slave_read<direction::one_line, false>(inst, data, count); }

void slave_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::slave_read<direction::one_line, true>(inst, data, count); }

void slave_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::slave_read<direction::one_line, false>(inst, data, count); }

void slave_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::slave_read<direction::one_line, true>(inst, data, count); }

//
// slave write
//

void slave_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::one_line, false>(inst, data, count); }

void slave_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::one_line, true>(inst, data, count); }

void slave_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::one_line, false>(inst, data, count); }

void slave_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::one_line, true>(inst, data, count); }

//
// master read
//

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::master_read<direction::one_line, false>(inst, data, count, delay_4cyc); }

void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::master_read<direction::one_line, true>(inst, data, count, delay_4cyc); }

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::master_read<direction::one_line, false>(inst, data, count, delay_4cyc); }

void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::master_read<direction::one_line, true>(inst, data, count, delay_4cyc); }

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::one_line, false>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::one_line, true>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::one_line, false>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::one_line, true>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

//
// master write
//

void master_write(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::one_line, false>(inst, data, count); }

void master_write_with_crc(SPI_TypeDef *inst, const uint16_t *data, uint32_t count)
{ detail::write<direction::one_line, true>(inst, data, count); }

void master_write(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::one_line, false>(inst, data, count); }

void master_write_with_crc(SPI_TypeDef *inst, const uint8_t *data, uint32_t count)
{ detail::write<direction::one_line, true>(inst, data, count); }

} // namespace one_line
} // namespace detail
} // namespace lmcu
} // namespace spi
