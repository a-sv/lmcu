#pragma once

namespace detail {

template<typename _module>
constexpr I2C_TypeDef *inst()
{
  switch(_module().module_id)
  {
#if defined(I2C1)
  case module_id::i2c1: return I2C1;
#endif

#if defined(I2C2)
  case module_id::i2c2: return I2C2;
#endif

#if defined(I2C3)
  case module_id::i2c3: return I2C3;
#endif
  }

  return nullptr;
}

template<typename _module>
void enable() { detail::inst<_module>()->CR1 |= I2C_CR1_PE; }

template<typename _module>
void disable() { detail::inst<_module>()->CR1 &= ~I2C_CR1_PE; }

template<typename _module>
void configure()
{
  constexpr auto m = _module();

  static_assert(m.clock <= 400_kHz, "i2c clock must be <= 400kHz");

  if constexpr(m.addr_mode == addr_mode::_7bit) {
    static_assert(m.own_addr_1 <= 127, "in 7bit mode own address 1 must be <= 127");
  }
  else {
    static_assert(m.own_addr_1 <= 1023, "in 10bit mode own address 1 must be <= 1023");
  }

  static_assert(m.own_addr_2 <= 127, "own address 2 must be <= 127");

  switch(m.module_id)
  {
#if defined(I2C1)
  case module_id::i2c1:
    RCC->APB1ENR  |=  RCC_APB1ENR_I2C1EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_I2C1RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST;
    break;
#endif

#if defined(I2C2)
  case module_id::i2c2:
    RCC->APB1ENR  |=  RCC_APB1ENR_I2C2EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_I2C2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST;
    break;
#endif

#if defined(I2C3)
  case module_id::i2c3:
    RCC->APB1ENR  |=  RCC_APB1ENR_I2C3EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_I2C3RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C3RST;
    break;
#endif
  }

  disable<_module>();

  auto inst = detail::inst<_module>();

  const auto fr = rcc::apb1_clock() / 1_MHz;

  inst->CR2   = fr;
  inst->TRISE = (m.clock <= 100_kHz)? fr + 1 : ((fr * 300) / 1000) + 1;

  if constexpr(m.clock <= 100_kHz) {
    auto r = (rcc::apb1_clock() / m.clock) >> 1;
    inst->CCR = ((r & I2C_CCR_CCR) < 4)? 4 : r;
  }
  else {
    auto r = rcc::apb1_clock() / (m.clock * (m.dutycycle == dutycycle::_2? 3 : 25));
    if constexpr(m.dutycycle == dutycycle::_16_9) { r |= I2C_CCR_DUTY; }
    inst->CCR = (r & I2C_CCR_CCR) == 0? 1 : (r | I2C_CCR_FS);
  }

  inst->CR1 = (m.general_call == general_call::enable? I2C_CR1_ENGC : 0) |
              (m.no_stretch == no_stretch::enable? I2C_CR1_NOSTRETCH : 0);

  inst->OAR1 = (m.addr_mode == addr_mode::_10bit? I2C_OAR1_ADDMODE : 0) | m.own_addr_1;
  inst->OAR2 = (m.dual_addr == dual_addr::enable? I2C_OAR2_ENDUAL : 0) | (m.own_addr_2 << 1);

  enable<_module>();
}

template<typename _module, bool _start>
io::result req_tx(uint16_t addr, const delay::timer &t)
{
  constexpr auto m = _module();

  auto inst = detail::inst<_module>();

  if constexpr(_start) { inst->CR1 |= I2C_CR1_START; }

  while((inst->SR1 & I2C_SR1_SB) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  auto f_wait = [&](auto&& flag)
  {
    while((inst->SR1 & flag) == 0) {
      if(t.expired()) { return io::result::busy; }

      if((inst->SR1 & I2C_SR1_AF) != 0) {
        // generate stop
        inst->CR1 |=  I2C_CR1_STOP;
        // clear AF flag
        inst->SR1 &= ~I2C_SR1_AF;
        return io::result::error;
      }
    }
    return io::result::success;
  };

  if constexpr(m.addr_mode == addr_mode::_7bit) {
    inst->DR = (addr << 1) & 0xFE;
  }
  else {
    inst->DR = ((addr & 0x300) >> 7) | 0xF0;

    auto res = f_wait(I2C_SR1_ADD10);
    if(res != io::result::success) { return res; }

    inst->DR = addr & 0xFF;
  }

  auto rc = f_wait(I2C_SR1_ADDR);

  // clear ADDR flag
  (void)inst->SR1; (void)inst->SR2;

  return rc;
}

template<typename _module>
io::result tx(uint16_t addr, uint8_t data, const delay::timer &t)
{
  auto inst = detail::inst<_module>();

  while((inst->SR2 & I2C_SR2_BUSY) != 0) {
    if(t.expired()) { return io::result::busy; }
  }

  // disable pos
  inst->CR1 &= ~I2C_CR1_POS;

  lmcu_defer([inst] { inst->CR1 |= I2C_CR1_STOP; });

  auto rc = req_tx<_module, true>(addr, t);
  if(rc != io::result::success) { return rc; }

  while((inst->SR1 & I2C_SR1_TXE) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  inst->DR = data;

  while((inst->SR1 & I2C_SR1_BTF) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  return io::result::success;
}

template<typename _module, typename _get_fn>
io::result write(uint16_t addr, const delay::timer &t, _get_fn&& get)
{
  auto inst = detail::inst<_module>();

  while((inst->SR2 & I2C_SR2_BUSY) != 0) {
    if(t.expired()) { return io::result::busy; }
  }

  // disable pos
  inst->CR1 &= ~I2C_CR1_POS;

  lmcu_defer([inst] { inst->CR1 |= I2C_CR1_STOP; });

  auto rc = req_tx<_module, true>(addr, t);
  if(rc != io::result::success) { return rc; }

  do {
    while((inst->SR1 & I2C_SR1_TXE) == 0) {
      if(t.expired()) { return io::result::busy; }
    }
  } while( get(inst->DR) );

  while((inst->SR1 & I2C_SR1_BTF) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  return io::result::success;
}

} // namespace detail
