#pragma once

namespace detail {

template<module_id _module_id>
SPI_TypeDef *inst()
{
#if defined(SPI1)
  if constexpr(_module_id == module_id::spi1) { return SPI1; }
#endif

#if defined(SPI2)
  if constexpr(_module_id == module_id::spi2) { return SPI2; }
#endif

#if defined(SPI3)
  if constexpr(_module_id == module_id::spi3) { return SPI3; }
#endif

#if defined(SPI4)
  if constexpr(_module_id == module_id::spi4) { return SPI4; }
#endif

#if defined(SPI5)
  if constexpr(_module_id == module_id::spi5) { return SPI5; }
#endif

#if defined(SPI6)
  if constexpr(_module_id == module_id::spi6) { return SPI6; }
#endif
}

} // namespace detail
