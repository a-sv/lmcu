#pragma once

namespace detail {

enum class addr_component { _7bit, _10bit_head, _10bit_body };

template<module_id _module_id>
struct state
{
  io::mode mode;
  uint16_t addr;

  static state *get();
};

template<typename _module>
static inline I2C_TypeDef *inst()
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

template<module_id _module_id, typename _irq>
static void enable_irq()
{
  if constexpr(_irq::irq_type != nvic::irq_type::disable) {
#if defined(I2C1)
    if constexpr(_module_id == module_id::i2c1) {
      switch(_irq::irq_type)
      {
      case nvic::irq_type::evi: nvic::enable_irq<_irq, I2C1_EV_IRQn>(); break;
      case nvic::irq_type::eri: nvic::enable_irq<_irq, I2C1_ER_IRQn>(); break;
      default : break;
      }
    }
#endif

#if defined(I2C2)
    if constexpr(_module_id == module_id::i2c2) {
      switch(_irq::irq_type)
      {
      case nvic::irq_type::evi: nvic::enable_irq<_irq, I2C2_EV_IRQn>(); break;
      case nvic::irq_type::eri: nvic::enable_irq<_irq, I2C2_ER_IRQn>(); break;
      default : break;
      }
    }
#endif

#if defined(I2C3)
    if constexpr(_module_id == module_id::i2c3) {
      switch(_irq::irq_type)
      {
      case nvic::irq_type::evi: nvic::enable_irq<_irq, I2C3_EV_IRQn>(); break;
      case nvic::irq_type::eri: nvic::enable_irq<_irq, I2C3_ER_IRQn>(); break;
      default : break;
      }
    }
#endif
  }
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
      r /= 25;
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

  enable_irq<_module::module_id, decltype(_module::irq0)>();
  enable_irq<_module::module_id, decltype(_module::irq1)>();
}

static inline io::direction direction(uint32_t sr2)
{
  return ((sr2 & I2C_SR2_TRA) == 0)? io::direction::rx : io::direction::tx;
}

template<typename _module>
static inline void clear_addr_flag()
{
  auto inst = detail::inst<_module>();
  inst->SR1; inst->SR2;
}

template<typename _module>
static inline void clear_stop_flag()
{
  auto inst = detail::inst<_module>();
  inst->SR1;
  inst->CR1 |= I2C_CR1_PE;
}


template<typename _module>
static inline void generate_start() { detail::inst<_module>()->CR1 |= I2C_CR1_START; }

template<typename _module>
static inline void generate_stop() { detail::inst<_module>()->CR1 |= I2C_CR1_STOP; }

template<typename _module>
static inline void ack_enable() { detail::inst<_module>()->CR1 |= I2C_CR1_ACK; }

template<typename _module>
static inline void ack_disable() { detail::inst<_module>()->CR1 &= ~I2C_CR1_ACK; }

template<typename _module>
static inline void evt_enable()
{
  detail::inst<_module>()->CR2 |= I2C_CR2_ITBUFEN | I2C_CR2_ITEVTEN | I2C_CR2_ITERREN;
}

template<typename _module>
static inline void evt_disable()
{
  detail::inst<_module>()->CR2 &= ~(I2C_CR2_ITBUFEN | I2C_CR2_ITEVTEN | I2C_CR2_ITERREN);
}

template<typename _module>
static inline io::result wait_addr_flag(const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  while((inst->SR1 & I2C_SR1_ADDR) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  clear_addr_flag<_module>();

  return io::result::success;
}

template<typename _module>
static inline io::result wait_rxne_flag(const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  while((inst->SR1 & I2C_SR1_RXNE) == 0) {
    if(t.expired()) { return io::result::busy; }
    if((inst->SR1 & I2C_SR1_STOPF) != 0) { return io::result::error; }
  }

  return io::result::success;
}

template<typename _module>
static inline io::result wait_bus_ready(const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  while((inst->SR2 & I2C_SR2_BUSY) != 0) {
    if(t.expired()) { return io::result::busy; }
  }

  return io::result::success;
}

template<typename _module>
static inline bool ack_failure()
{
  auto inst = detail::inst<_module>();

  if((inst->SR1 & I2C_SR1_AF) != 0) {
    inst->SR1 &= ~I2C_SR1_AF;
    return true;
  }

  return false;
}

template<typename _module, io::direction _io_direction, addr_component _addr_component>
static inline void tx_address(uint16_t addr)
{
  auto inst = detail::inst<_module>();

  if constexpr(_addr_component == addr_component::_7bit) {
    inst->DR = ((addr << 1) & 0xFE) | (_io_direction == io::direction::rx? 1 : 0);
  }
  else
  if constexpr(_addr_component == addr_component::_10bit_head) {
    inst->DR = ((addr & 0x300) >> 7) | (_io_direction == io::direction::rx? 0xF0 : 0xF1);
  }
  else {
    inst->DR = addr & 0xFF;
  }
}

template<typename _module, bool _start, io::direction _io_direction>
static io::result request(uint16_t addr, const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  if constexpr(_io_direction == io::direction::rx) {
    ack_enable<_module>();
  }

  if constexpr(_start) { generate_start<_module>(); }

  while((inst->SR1 & I2C_SR1_SB) == 0) {
    if(t.expired()) { return io::result::busy; }
  }

  auto f_wait = [inst, &t](auto&& flag)
  {
    while((inst->SR1 & flag) == 0) {
      if(t.expired()) { return io::result::busy; }

      if(ack_failure<_module>()) {
        generate_stop<_module>();
        return io::result::error;
      }
    }
    return io::result::success;
  };

  if constexpr(_module::addr_mode == addr_mode::_7bit) {
    tx_address<_module, _io_direction, addr_component::_7bit>(addr);
  }
  else {
    tx_address<_module, _io_direction, addr_component::_10bit_head>(addr);

    if(auto r = f_wait(I2C_SR1_ADD10); r != io::result::success) { return r; }

    tx_address<_module, _io_direction, addr_component::_10bit_body>(addr);
  }

  auto rc = f_wait(I2C_SR1_ADDR);

  clear_addr_flag<_module>();

  return rc;
}

template<typename _module, io::mode _io_mode, typename _get_fn>
io::result write(uint16_t addr, const delay::expirable &t, _get_fn&& get)
{
  auto inst = detail::inst<_module>();

  if constexpr(_io_mode == io::mode::master) {
    if(auto r = wait_bus_ready<_module>(t); r != io::result::success) { return r; }
  }

  inst->CR1 &= ~I2C_CR1_POS;

  if constexpr(_io_mode == io::mode::master) {
    ack_disable<_module>();
  }
  else {
    ack_enable<_module>();

    if(auto r = wait_addr_flag<_module>(t); r != io::result::success) { return r; }

    if constexpr(_module::addr_mode == addr_mode::_10bit) {
      if(auto r = wait_addr_flag<_module>(t); r != io::result::success) { return r; }
    }
  }

  lmcu_defer([]
  {
    if constexpr(_io_mode == io::mode::master) {
      generate_stop<_module>();
    }
    else {
      ack_disable<_module>();
    }
  });

  if constexpr(_io_mode == io::mode::master) {
    auto r = request<_module, true, io::direction::tx>(addr, t);
    if(r != io::result::success) { return r; }
  }

  while(!t.expired()) {
    do {
      if(ack_failure<_module>()) { return io::result::error; }
      if(t.expired()) { return io::result::busy; }
    } while((inst->SR1 & I2C_SR1_TXE) == 0);

    if(!get(inst->DR)) { break; }
  }

  if constexpr(_io_mode == io::mode::master) {
    do {
      if(ack_failure<_module>()) { return io::result::error; }
      if(t.expired()) { return io::result::busy; }
    } while((inst->SR1 & I2C_SR1_BTF) == 0);
  }
  else {
    while((inst->SR1 & I2C_SR1_AF) == 0) {
      if(t.expired()) { return io::result::busy; }
    }
    inst->SR1 &= ~I2C_SR1_AF;
  }

  return io::result::success;
}

template<typename _module, io::mode _io_mode>
inline io::result write(uint16_t addr, const void *data, uint32_t sz, const delay::expirable &t)
{
  if(sz == 0) {
    return io::result::success;
  }
  auto b = static_cast<const uint8_t*>(data), e = b + sz;
  return detail::write<_module, _io_mode>(addr, t, [&b, e](auto&& r) { r = *b++; return b < e; });
}

template<typename _module, io::mode _io_mode>
io::result read(uint16_t addr, void *data, uint32_t sz, const delay::expirable &t)
{
  auto inst = detail::inst<_module>();

  auto p = static_cast<uint8_t*>(data), end = p + sz;

  if constexpr(_io_mode == io::mode::master) {
    if(auto r = wait_bus_ready<_module>(t); r != io::result::success) { return r; }
  }

  inst->CR1 &= ~I2C_CR1_POS;

  lmcu_defer([] { ack_disable<_module>(); });

  if constexpr(_io_mode == io::mode::master) {
    if(auto r = request<_module, true, io::direction::rx>(addr, t); r != io::result::success) {
      return r;
    }

    lmcu_defer([] { generate_stop<_module>(); });

    if(sz == 1) {
      ack_disable<_module>();

#ifdef _LMCU_DEVICE_STM32F1_
      lmcu_critical_section();
#endif

      clear_addr_flag<_module>();
    }
    else
    if(sz == 2) {
      inst->CR1 |= I2C_CR1_POS;

#ifdef _LMCU_DEVICE_STM32F1_
      lmcu_critical_section();
#endif

      clear_addr_flag<_module>();
      ack_disable<_module>();
    }
    else {
      ack_enable<_module>();
      clear_addr_flag<_module>();
    }

    while((end - p) > 3) {
      if(auto r = wait_rxne_flag<_module>(t); r != io::result::success) { return r; }
      *p++ = inst->DR;
      if((inst->SR1 & I2C_SR1_BTF) != 0) { *p++ = inst->DR; }
    }

    if((end - p) == 1) {
      if(auto r = wait_rxne_flag<_module>(t); r != io::result::success) { return r; }
      *p++ = inst->DR;
    }
    else
    if((end - p) == 2) {
      while((inst->SR1 & I2C_SR1_BTF) == 0) {
        if(t.expired()) { return io::result::busy; }
      }

      {
#ifdef _LMCU_DEVICE_STM32F1_
      lmcu_critical_section();
#endif

        generate_stop<_module>();
        *p++ = inst->DR;
      }

      *p++ = inst->DR;
    }
    else {
      // last 3 bytes

      while((inst->SR1 & I2C_SR1_BTF) == 0) {
        if(t.expired()) { return io::result::busy; }
      }

      ack_disable<_module>();

      {
#ifdef _LMCU_DEVICE_STM32F1_
      lmcu_critical_section();
#endif

        *p++ = inst->DR;

        while((inst->SR1 & I2C_SR1_BTF) == 0) {
          if(t.expired()) { return io::result::busy; }
        }

        generate_stop<_module>();

        *p++ = inst->DR;
      }

      *p++ = inst->DR;
    }
  }
  else {
    ack_enable<_module>();
    if(auto r = wait_addr_flag<_module>(t); r != io::result::success) { return r; }

    while(p < end) {
      if(auto r = wait_rxne_flag<_module>(t); r != io::result::success) { return r; }
      *p++ = inst->DR;
      if((p < end) && ((inst->SR1 & I2C_SR1_BTF) != 0)) { *p++ = inst->DR; }
    }

    while((inst->SR1 & I2C_SR1_STOPF) == 0) {
      if(t.expired()) { return io::result::busy; }
    }

    clear_stop_flag<_module>();

    if(ack_failure<_module>()) { return io::result::error; }
  }

  return io::result::success;
}

template<typename _module, io::mode _io_mode, io::direction _io_direction>
io::result async_run(uint16_t addr, const delay::expirable &t)
{
  auto buf = io::buf<_module::module_id>::get();

  if(buf->rx_state == io::result::busy || buf->tx_state == io::result::busy) {
    return io::result::busy;
  }

  if constexpr(_io_direction == io::direction::rx) {
    if(!buf->rxbuf || !buf->rx_n) { return io::result::error; }
    buf->rx_state = io::result::busy;
  }
  else {
    if(!buf->txbuf || !buf->tx_n) { return io::result::error; }
    buf->tx_state = io::result::busy;
  }

  auto inst = detail::inst<_module>();
  auto st = state<_module::module_id>::get();

  st->mode = _io_mode;

  uint32_t r = inst->CR1;

  r &= ~I2C_CR1_POS;

  if constexpr(_io_mode == io::mode::master) {
    st->addr = addr;

    if(auto r = wait_bus_ready<_module>(t); r != io::result::success) {
      if constexpr(_io_direction == io::direction::rx) {
        buf->rx_state = io::result::error;
      }
      else {
        buf->tx_state = io::result::error;
      }
      return r;
    }

    if constexpr(_io_direction == io::direction::rx) {
      if(buf->tx_n > 1) {
        r |= I2C_CR1_ACK;
      }
      else {
        r &= ~I2C_CR1_ACK;
      }
    }
    r |= I2C_CR1_START;
    inst->CR1 = r;

  }
  else {
    uint32_t r = inst->CR1;
    r |= I2C_CR1_ACK;
    inst->CR1 = r;
  }

  evt_enable<_module>();

  return io::result::success;
}

template<typename _module>
void reset()
{
  auto inst = detail::inst<_module>();

  lmcu_critical_section();

  const uint32_t
    cr1   = inst->CR1,
    cr2   = inst->CR2,
    oar1  = inst->OAR1,
    oar2  = inst->OAR2,
    ccr   = inst->CCR,
    trise = inst->TRISE,
    fltr  = inst->FLTR;
  ;

  inst->CR1 |= I2C_CR1_SWRST;
  inst->CR1 &= ~I2C_CR1_SWRST;

  inst->TRISE = trise;
  inst->CR2   = cr2;
  inst->OAR1  = oar1;
  inst->OAR2  = oar2;
  inst->CCR   = ccr;
  inst->FLTR  = fltr;
  inst->CR1   = cr1;
}

template<typename _module, typename _buf_t, typename _st_t>
static void ev_irq_master(_buf_t&& buf, _st_t&& st)
{
  auto inst = detail::inst<_module>();

  const uint32_t sr1 = inst->SR1, sr2 = inst->SR2;

  if((sr1 & I2C_SR1_SB) != 0) {
    if constexpr(_module::addr_mode == addr_mode::_7bit) {
      if(direction(sr2) == io::direction::rx) {
        tx_address<_module, io::direction::rx, addr_component::_7bit>(st->addr);
      }
      else {
        tx_address<_module, io::direction::tx, addr_component::_7bit>(st->addr);
      }
    }
    else {
      // TODO: 10 bit addr
    }
  }
  else
  if((sr1 & I2C_SR1_ADD10) != 0) {
    tx_address<_module, io::direction::tx, addr_component::_10bit_body>(3);
  }
  else
  if((sr1 & I2C_SR1_ADDR) != 0) {
    if(buf->rx_state == io::result::busy) {
      if(buf->rx_n == 1) {
        clear_addr_flag<_module>();
        generate_stop<_module>();
      }
      else
      if(buf->rx_n == 2) {
        inst->CR1 |= I2C_CR1_POS;
        clear_addr_flag<_module>();
        ack_disable<_module>();
      }
      else {
        ack_enable<_module>();
        clear_addr_flag<_module>();
      }
    }
    else {
      clear_addr_flag<_module>();
    }
  }

  auto master_finish = [inst, buf](io::direction direction)
  {
    evt_disable<_module>();

    if(direction == io::direction::tx) {
      buf->tx_state = io::result::success;
    }
    else {
      buf->rx_state = io::result::success;
    }

    if(buf->complete) { buf->complete(direction, buf->usrptr); }
  };

  if(direction(sr2) == io::direction::tx) {
    if((sr1 & (I2C_SR1_TXE | I2C_SR1_BTF)) != 0) {
      if(buf->tx_n) {
        inst->DR = *buf->txbuf++;
        buf->tx_n--;
      }
      else {
        inst->CR2 &= ~I2C_CR2_ITBUFEN;

        generate_stop<_module>();

        if((sr1 & I2C_SR1_BTF) != 0) { master_finish(io::direction::tx); }
      }
    }
  }
  else {
    if((sr1 & I2C_SR1_RXNE) != 0) {
      *buf->rxbuf++ = inst->DR;
      --buf->rx_n;

      if(buf->rx_n == 1) {
        ack_disable<_module>();
        generate_stop<_module>();
      }
      else
      if(buf->rx_n == 0) {
        master_finish(io::direction::rx);
      }
    }
  }
}

template<typename _module, typename _buf_t, typename _st_t>
static void ev_irq_slave(_buf_t&& buf, _st_t&& st)
{
  auto inst = detail::inst<_module>();

  const uint32_t sr1 = inst->SR1, sr2 = inst->SR2, cr2 = inst->CR2;

  if(direction(sr2) == io::direction::rx) {
    if((sr1 & I2C_SR1_RXNE) != 0 && (cr2 & I2C_CR2_ITBUFEN) != 0) {
      if(buf->rx_n) {
        *buf->rxbuf++ = inst->DR;

        if(--buf->rx_n == 0) {
          inst->CR2 &= ~I2C_CR2_ITBUFEN;
          ack_disable<_module>();
        }
      }
    }
  }
  else {
    if((sr1 & I2C_SR1_TXE) != 0 && (cr2 & I2C_CR2_ITBUFEN) != 0) {
      if(buf->tx_n) {
        inst->DR = *buf->txbuf++;
        if(--buf->tx_n == 0) { inst->CR2 &= ~I2C_CR2_ITBUFEN; }
      }
    }
    else
    if((sr1 & I2C_SR1_BTF) != 0) { inst->DR = 0; }
  }

  if((sr1 & I2C_SR1_STOPF) != 0) {
    evt_disable<_module>();
    clear_stop_flag<_module>();

    if(direction(sr2) == io::direction::rx) {
      ack_disable<_module>();

      if((sr1 & I2C_SR1_RXNE) != 0) { inst->DR; }

      buf->rx_state = buf->rx_n? io::result::error : io::result::success;
      if(buf->complete) { buf->complete(io::direction::rx, buf->usrptr); }
    }
  }
}

template<typename _module>
void ev_irq()
{
  auto buf = io::buf<_module::module_id>::get();
  auto st = state<_module::module_id>::get();

  if(st->mode == io::mode::master) {
    ev_irq_master<_module>(buf, st);
  }
  else {
    ev_irq_slave<_module>(buf, st);
  }
}

template<typename _module>
void er_irq()
{
  auto inst = detail::inst<_module>();

  auto buf = io::buf<_module::module_id>::get();
  auto st = state<_module::module_id>::get();

  const uint32_t sr1 = inst->SR1, sr2 = inst->SR2;

  if((sr1 & I2C_SR1_BERR) != 0) { inst->SR1 &= ~I2C_SR1_BERR; }

  if((sr1 & I2C_SR1_ARLO) != 0) { inst->SR1 &= ~I2C_SR1_ARLO; }

  if((sr1 & I2C_SR1_AF) != 0) {
    inst->SR1 &= ~I2C_SR1_AF;

    if(st->mode == io::mode::master) {
      generate_stop<_module>();
    }
    else {
      if(direction(sr2) == io::direction::tx) {
        evt_disable<_module>();

        ack_disable<_module>();

        buf->tx_state = buf->tx_n? io::result::error : io::result::success;
        if(buf->complete) { buf->complete(io::direction::tx, buf->usrptr); }
      }
    }
  }
}

} // namespace detail
