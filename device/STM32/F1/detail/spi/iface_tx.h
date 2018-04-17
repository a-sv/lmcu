template<typename module_t>
void tx(uint16_t data)
{
  constexpr auto m = module_t();
  static_assert(m.direction != direction::two_lines_rxonly, "could not transmit in rx only mode");

  auto inst = detail::inst<m.module_id>();

  const uint16_t _data = (m.datasize == datasize::word)? data : (data & 0xFF);

  if constexpr(m.mode == mode::master) {
    if constexpr(m.crc == crc::enable) { master_tx_with_crc(inst, _data); }
    else { master_tx(inst, _data); }
  }
  else {
    if constexpr(m.crc == crc::enable) { slave_tx_with_crc(inst, _data); }
    else { slave_tx(inst, _data); }
  }
}

template<typename module_t, typename data_t>
void write(const data_t *data, uint32_t count)
{
  constexpr auto m = module_t();
  static_assert(m.direction != direction::two_lines_rxonly, "could not transmit in rx only mode");

  auto inst = detail::inst<m.module_id>();

  if constexpr(m.mode == mode::master) {
    if constexpr(m.crc == crc::enable) { master_write_with_crc(inst, data, count); }
    else { master_write(inst, data, count); }
  }
  else {
    if constexpr(m.crc == crc::enable) { slave_write_with_crc(inst, data, count); }
    else { slave_write(inst, data, count); }
  }
}
