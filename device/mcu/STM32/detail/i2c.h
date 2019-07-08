#pragma once

namespace detail {

enum class direction { tx, rx };

template<typename _module>
inline I2C_TypeDef *inst()
{
  switch(_module::module_id)
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
  static_assert(_module::clock <= 400_kHz, "i2c clock must be <= 400kHz");

  if constexpr(_module::addr_mode == addr_mode::_7bit) {
    static_assert(_module::own_addr_1 <= 127, "in 7bit mode own address 1 must be <= 127");
  }
  else {
    static_assert(_module::own_addr_1 <= 1023, "in 10bit mode own address 1 must be <= 1023");
  }

  static_assert(_module::own_addr_2 <= 127, "own address 2 must be <= 127");

  switch(_module::module_id)
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

  const uint32_t fr = rcc::apb1_clock() / 1_MHz;

  inst->CR2 = fr;
  inst->TRISE = (_module::clock <= 100_kHz)? fr + 1 : ((fr * 300) / 1000) + 1;

  uint32_t r = rcc::apb1_clock() / _module::clock;

  if constexpr(_module::clock <= 100_kHz) {
    // duty cycle 50% / 50%
    r /= 2;
    inst->CCR = (r < 4)? 4 : r;
  }
  else {
    if constexpr(_module::dutycycle == dutycycle::_16_9) {
      // T_high = 9 * CCR * T_pclk1
      // T_low  = 16 * CCR * T_pclk1
      r  /= 25;
      r |= I2C_CCR_DUTY;
    }
    else {
      // T_high = CCR * T_pclk1
      // T_low  = 2 * T_high
      r /= 3;
    }

    inst->CCR = I2C_CCR_FS | (r < 1? 1 : r);
  }

  inst->CR1 = (_module::general_call == general_call::enable? I2C_CR1_ENGC : 0) |
              (_module::no_stretch == no_stretch::enable? I2C_CR1_NOSTRETCH : 0) |
              []() -> uint32_t
              {
                if constexpr(_module::mode == mode::smbus_dev) {
                  return I2C_CR1_SMBUS;
                }

                if constexpr(_module::mode == mode::smbus_host) {
                  return I2C_CR1_SMBUS | I2C_CR1_SMBTYPE;
                }

                return 0;
              }();

  inst->OAR1 = (_module::addr_mode == addr_mode::_10bit? I2C_OAR1_ADDMODE : 0) |
               (_module::own_addr_1 << 1);

  inst->OAR2 = (_module::dual_addr == dual_addr::enable? I2C_OAR2_ENDUAL : 0) |
               (_module::own_addr_2 << 1);
}

template<typename _module, bool _start, direction _direction>
io::result request(uint16_t addr, const delay::expirable &t)
{
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

  if constexpr(_module::addr_mode == addr_mode::_7bit) {
    inst->DR = ((addr << 1) & 0xFE) | (_direction == direction::rx? 1 : 0);
  }
  else {
    // TODO: add read flag in 10bit mode
    inst->DR = ((addr & 0x300) >> 7) | 0xF0;

    if(auto r = f_wait(I2C_SR1_ADD10); r != io::result::success) { return r; }

    inst->DR = addr & 0xFF;
  }

  auto rc = f_wait(I2C_SR1_ADDR);

  // clear ADDR flag
  inst->SR1; inst->SR2;

  return rc;
}

template<typename _module>
io::result wait_addr(const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  while((inst->SR1 & I2C_SR1_ADDR) == 0) {
    if(t.expired()) { return io::result::busy; }
  }
  // Clear ADDR flag
  inst->SR1; inst->SR2;

  return io::result::success;
}

template<typename _module, bool _master>
io::result tx(uint16_t addr, uint8_t data, const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  if constexpr(_master) {
    while((inst->SR2 & I2C_SR2_BUSY) != 0) {
      if(t.expired()) { return io::result::busy; }
    }
  }

  inst->CR1 &= ~I2C_CR1_POS;

  if constexpr(!_master) {
    inst->CR1 |= I2C_CR1_ACK;
    if(auto r = wait_addr<_module>(t); r != io::result::success) { return r; }
  }

  lmcu_defer([inst]
  {
    if constexpr(_master) {
      inst->CR1 |= I2C_CR1_STOP;
    }
    else {
      inst->CR1 &= ~I2C_CR1_ACK;
    }
  });

  if constexpr(_master) {
    auto r = request<_module, true, direction::tx>(addr, t);
    if(r != io::result::success) { return r; }
  }

  while((inst->SR1 & I2C_SR1_TXE) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  inst->DR = data;

  if constexpr(_master) {
    while((inst->SR1 & I2C_SR1_BTF) == 0) {
      if(t.expired()) { return io::result::busy; }
    }
  }
  else {
    while((inst->SR1 & I2C_SR1_AF) == 0) {
      if(t.expired()) { return io::result::busy; }
    }
    inst->SR1 &= ~I2C_SR1_AF;
  }

  return io::result::success;
}

template<typename _module, typename _get_fn>
io::result write(uint16_t addr, const delay::expirable &t, _get_fn&& get)
{
  auto inst = detail::inst<_module>();

  while((inst->SR2 & I2C_SR2_BUSY) != 0) {
    if(t.expired()) { return io::result::busy; }
  }

  // disable pos
  inst->CR1 &= ~I2C_CR1_POS;

  lmcu_defer([inst] { inst->CR1 |= I2C_CR1_STOP; });

  auto rc = request<_module, true, direction::tx>(addr, t);
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

template<typename _module>
io::result wait_rxne(const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  while((inst->SR1 & I2C_SR1_RXNE) == 0) {
    if(t.expired()) { return io::result::busy; }
    if((inst->SR1 & I2C_SR1_STOPF) != 0) { return io::result::error; }
  }

  return io::result::success;
}

template<typename _module, bool _master>
io::result rx(uint16_t addr, uint8_t &data, const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  if constexpr(_master) {
    while((inst->SR2 & I2C_SR2_BUSY) != 0) {
      if(t.expired()) { return io::result::busy; }
    }
  }

  inst->CR1 &= ~I2C_CR1_POS;

  if constexpr(_master) {
    if(auto rc = request<_module, true, direction::rx>(addr, t); rc != io::result::success) {
      return rc;
    }
  }

  if constexpr(_master) {
    inst->CR1 &= ~I2C_CR1_ACK;
  }
  else {
    inst->CR1 |= I2C_CR1_ACK;
  }

  lmcu_defer([inst]
  {
    if constexpr(!_master) { inst->CR1 &= ~I2C_CR1_ACK; }
  });

  if constexpr(_master) {
    lmcu_critical_section();
    inst->SR1 &= ~I2C_SR1_AF;
    inst->CR1 |= I2C_CR1_STOP;
  }
  else {
    if(auto r = wait_addr<_module>(t); r != io::result::success) { return r; }
  }

  if(auto r = wait_rxne<_module>(t); r != io::result::success) { return r; }

  data = inst->DR;
  if(inst->SR1 & I2C_SR1_BTF) { inst->DR; }

  if constexpr(!_master) {
    while((inst->SR1 & I2C_SR1_STOPF) == 0) {
      if(t.expired()) { return io::result::busy; }
    }
    // Clear STOP flag
    inst->CR1 |= I2C_CR1_PE;
  }

  return io::result::success;
}

template<typename _module>
io::result read(uint16_t addr, void *data, uint16_t sz, const delay::expirable &t)
{
  auto inst      = detail::inst<_module>();
  auto p         = static_cast<uint8_t*>(data);
  const auto end = p + sz;

  while((inst->SR2 & I2C_SR2_BUSY) != 0) {
    if(t.expired()) { return io::result::busy; }
  }

  // disable pos
  inst->CR1 &= ~I2C_CR1_POS;

  if(auto rc = request<_module, true, direction::rx>(addr, t); rc != io::result::success) {
    return rc;
  }

  if(sz == 0) {
    inst->SR1 &= ~I2C_SR1_AF;
    inst->CR1 |= I2C_CR1_STOP;
  }
  else
  if(sz == 1) {
    // errata!
    inst->CR1 &= ~I2C_CR1_ACK;

    lmcu_critical_section();

    inst->SR1 &= ~I2C_SR1_AF;
    inst->CR1 |= I2C_CR1_STOP;
  }
  else
  if(sz == 2) {
    inst->CR1 |= I2C_CR1_POS;

    lmcu_critical_section();

    inst->SR1 &= ~I2C_SR1_AF;
    inst->CR1 &= ~I2C_CR1_ACK;
  }
  else {
    inst->CR1 |= I2C_CR1_ACK;
    inst->SR1 &= ~I2C_SR1_AF;
  }

  while(p < end) {
    const uint32_t remain = end - p;

    if(remain <= 3) {
      if(remain == 1) {
        while((inst->SR1 & I2C_SR1_RXNE) == 0) {
          if(t.expired()) { return io::result::busy; }
        }
        *p++ = inst->DR;
      }
      else
      if(remain == 2) {
        while((inst->SR1 & I2C_SR1_BTF) == 0) {
          if(t.expired()) { return io::result::busy; }
        }

        {
          lmcu_critical_section();
          inst->CR1 |= I2C_CR1_STOP;
          *p++ = inst->DR;
        }

        *p++ = inst->DR;
      }
      else {
        while((inst->SR1 & I2C_SR1_BTF) == 0) {
          if(t.expired()) { return io::result::busy; }
        }

        inst->CR1 &= ~I2C_CR1_ACK;

        {
          lmcu_critical_section();

          *p++ = inst->DR;

          while((inst->SR1 & I2C_SR1_BTF) == 0) {
            if(t.expired()) { return io::result::busy; }
          }

          inst->CR1 |= I2C_CR1_STOP;
          *p++ = inst->DR;
        }

        *p++ = inst->DR;
      }
    }
    else {
      while((inst->SR1 & I2C_SR1_RXNE) == 0) {
        if(t.expired()) { return io::result::busy; }
      }

      *p++ = inst->DR;

      if(inst->SR1 & I2C_SR1_BTF) { *p++ = inst->DR; }
    }
  }

  return io::result::success;
}

} // namespace detail
