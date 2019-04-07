template<typename _module>
inline uint32_t one_cycle_delay()
{
  return (rcc::hardware_clock() / (rcc::apb2_clock() / uint32_t(_module::baud_prediv)));
}

template<typename _module, crc _crc>
uint16_t rx()
{
  auto inst = detail::inst<_module>();

  if constexpr(_module::mode == mode::master) {
    // one SPI cycle in system clocks
    const uint32_t delay_val = one_cycle_delay<_module>();
    if constexpr(_crc == crc::enable) {
      if(delay_val <= 8) { return master_rx_with_crc(inst); }
      return master_rx_with_crc(inst, delay_val - 8);
    }
    if(delay_val <= 8) { return master_rx(inst); }
    return master_rx(inst, delay_val - 8);
  }

  if constexpr(_crc == crc::enable) { return slave_rx_with_crc(inst); }
  return slave_rx(inst);
}

template<typename _module, crc _crc, typename _data>
void read(_data *data, uint32_t count)
{
  auto inst = detail::inst<_module>();

  if constexpr(_module::mode == mode::master) {
    // one SPI cycle in system clocks
    const uint32_t delay_val = one_cycle_delay<_module>();
    if constexpr(_crc == crc::enable) {
      if(delay_val <= 8) { master_read_with_crc(inst, data, count); }
      else { master_read_with_crc(inst, data, count, delay_val - 8); }
    }
    else {
      if(delay_val <= 8) { master_read(inst, data, count); }
      else { master_read(inst, data, count, delay_val - 8); }
    }
  }
  else {
    if constexpr(_crc == crc::enable) { slave_read_with_crc(inst, data, count); }
    else { slave_read(inst, data, count); }
  }
}
