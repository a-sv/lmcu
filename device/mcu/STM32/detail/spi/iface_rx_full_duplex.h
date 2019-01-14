template<typename _module, crc _crc>
uint16_t rx()
{
  auto inst = detail::inst<_module>();

  if constexpr(_module::mode == mode::master) {
    if constexpr(_crc == crc::enable) { return master_rx_with_crc(inst); }
    return master_rx(inst);
  }

  if constexpr(_crc == crc::enable) { return slave_rx_with_crc(inst); }
  return slave_rx(inst);
}

template<typename _module, crc _crc, typename _data>
void read(_data *data, uint32_t count)
{
  auto inst = detail::inst<_module>();

  if constexpr(_module::mode == mode::master) {
    if constexpr(_crc == crc::enable) { master_read_with_crc(inst, data, count); }
    else { master_read(inst, data, count); }
  }
  else {
    if constexpr(_crc == crc::enable) { slave_read_with_crc(inst, data, count); }
    else { slave_read(inst, data, count); }
  }
}
