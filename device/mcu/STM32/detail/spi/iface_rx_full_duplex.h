template<typename _module, bool _crc_finish>
uint16_t rx()
{
  auto inst = detail::inst<_module>();

  if constexpr(_module::mode == mode::master) {
    if constexpr(_module::crc == crc::enable && _crc_finish) { return master_rx_with_crc(inst); }
    return master_rx(inst);
  }

  if constexpr(_module::crc == crc::enable && _crc_finish) { return slave_rx_with_crc(inst); }
  return slave_rx(inst);
}

template<typename _module, typename _data, bool _crc_finish>
void read(_data *data, uint32_t count)
{
  auto inst = detail::inst<_module>();

  if constexpr(_module::mode == mode::master) {
    if constexpr(_module::crc == crc::enable && _crc_finish) {
      master_read_with_crc(inst, data, count);
    }
    else { master_read(inst, data, count); }
  }
  else {
    if constexpr(_module::crc == crc::enable && _crc_finish) {
      slave_read_with_crc(inst, data, count);
    }
    else { slave_read(inst, data, count); }
  }
}
