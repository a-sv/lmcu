## coding: utf-8
${D.header}
namespace lmcu::device {

static constexpr auto name = "${D.name}";

static constexpr auto cpu_arch = arch::${D.arch};

static constexpr auto cpu_endian = endian::${D.endian};

static constexpr uint32_t rom_size = ${D.rom_size};

static constexpr uint32_t ram_size = ${D.ram_size};

static constexpr uint32_t pins = ${D.pins};

static constexpr uint32_t nvic_prio_bits = ${D.nvic_prio_bits};

} // namespace lmcu::device
