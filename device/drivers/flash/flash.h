#pragma once

namespace lmcu::drivers::flash {

enum class type
{
  nor,
  nand_slc,
  nand_mlc,
  nand_tlc
};

template<type _type>
constexpr bool is_nand()
{
  return (_type == type::nand_slc) || (_type == type::nand_mlc) || (_type == type::nand_tlc);
}

} // namespace lmcu::drivers::flash
