template<typename _module, crc _crc>
void tx(uint16_t data)
{
  static_assert(_module::direction != direction::two_lines_rxonly, "could not transmit in rx "
                                                                   "only mode");

  auto inst = detail::inst<_module>();

  const uint16_t _data = (_module::datasize == datasize::word)? data : (data & 0xFF);

  if constexpr(_module::mode == mode::master) {
    if constexpr(_crc == crc::enable) { master_tx_with_crc(inst, _data); }
    else { master_tx(inst, _data); }
  }
  else {
    if constexpr(_crc == crc::enable) { slave_tx_with_crc(inst, _data); }
    else { slave_tx(inst, _data); }
  }
}

template<typename _module, crc _crc, typename _data>
void write(const _data *data, uint32_t count)
{
  static_assert(_module::direction != direction::two_lines_rxonly, "could not transmit in rx only "
                                                                   "mode");

  auto inst = detail::inst<_module>();

  if constexpr(_module::mode == mode::master) {
    if constexpr(_crc == crc::enable) { master_write_with_crc(inst, data, count); }
    else { master_write(inst, data, count); }
  }
  else {
    if constexpr(_crc == crc::enable) { slave_write_with_crc(inst, data, count); }
    else { slave_write(inst, data, count); }
  }
}
