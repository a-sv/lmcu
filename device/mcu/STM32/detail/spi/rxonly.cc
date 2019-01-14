#include <lmcu/device>

#ifdef _LMCU_DEVICE_STM32_

#include <lmcu/delay>
#include "../../spi.h"

namespace lmcu::spi::detail::rxonly {

//
// slave rx
//

uint16_t slave_rx(SPI_TypeDef *inst)
{ return detail::slave_rx<direction::two_lines_rxonly, false>(inst); }

uint16_t slave_rx_with_crc(SPI_TypeDef *inst)
{ return detail::slave_rx<direction::two_lines_rxonly, true>(inst); }

//
// slave read
//

void slave_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines_rxonly, false>(inst, data, count); }

void slave_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines_rxonly, true>(inst, data, count); }

void slave_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines_rxonly, false>(inst, data, count); }

void slave_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::slave_read<direction::two_lines_rxonly, true>(inst, data, count); }

//
// master rx
//

uint16_t master_rx(SPI_TypeDef *inst)
{ return detail::master_rx<direction::two_lines_rxonly, false>(inst, delay_4cyc); }

uint16_t master_rx_with_crc(SPI_TypeDef *inst)
{ return detail::master_rx<direction::two_lines_rxonly, true>(inst, delay_4cyc); }

uint16_t master_rx(SPI_TypeDef *inst, uint32_t delay_val)
{
  return detail::master_rx<direction::two_lines_rxonly, false>(
    inst, [&] { delay::cyc(delay_val); }
  );
}

uint16_t master_rx_with_crc(SPI_TypeDef *inst, uint32_t delay_val)
{
  return detail::master_rx<direction::two_lines_rxonly, true>(
    inst, [&] { delay::cyc(delay_val); }
  );
}

//
// master read
//

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::master_read<direction::two_lines_rxonly, false>(inst, data, count, delay_4cyc); }

void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count)
{ detail::master_read<direction::two_lines_rxonly, true>(inst, data, count, delay_4cyc); }

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::master_read<direction::two_lines_rxonly, false>(inst, data, count, delay_4cyc); }

void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count)
{ detail::master_read<direction::two_lines_rxonly, true>(inst, data, count, delay_4cyc); }

void master_read(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::two_lines_rxonly, false>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

void master_read_with_crc(SPI_TypeDef *inst, uint16_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::two_lines_rxonly, true>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

void master_read(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::two_lines_rxonly, false>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

void master_read_with_crc(SPI_TypeDef *inst, uint8_t *data, uint32_t count, uint32_t delay_val)
{
  detail::master_read<direction::two_lines_rxonly, true>(
    inst, data, count, [&] { delay::cyc(delay_val); }
  );
}

} // namespace lmcu::spi::detail::rxonly

#endif // _LMCU_DEVICE_STM32_
