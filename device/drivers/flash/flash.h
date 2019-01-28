#pragma once

namespace lmcu::drivers::flash {

enum class type
{
  nor,
  nand_slc,
  nand_mlc,
  nand_tlc
};

} // namespace lmcu::drivers::flash
