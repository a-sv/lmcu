template<typename module_t>
uint16_t rx()
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  if constexpr(m.mode == mode::master) {
    if constexpr(m.crc == crc::enable) { return master_rx_with_crc(inst); }
    return master_rx(inst);
  }

  if constexpr(m.crc == crc::enable) { return slave_rx_with_crc(inst); }
  return slave_rx(inst);
}

template<typename module_t, typename data_t>
void read(data_t *data, uint32_t count)
{
  constexpr auto m = module_t();
  auto inst = detail::inst<m.module_id>();

  if constexpr(m.mode == mode::master) {
    if constexpr(m.crc == crc::enable) { master_read_with_crc(inst, data, count); }
    else { master_read(inst, data, count); }
  }
  else {
    if constexpr(m.crc == crc::enable) { slave_read_with_crc(inst, data, count); }
    else { slave_read(inst, data, count); }
  }
}
