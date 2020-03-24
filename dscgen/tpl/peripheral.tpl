## coding: utf-8
${D.header}
namespace lmcu::device {

// ------------------------------------------------------------------------------------------------
// ${D.desc}
// ------------------------------------------------------------------------------------------------
struct ${D.name}
{
  static constexpr std::uintptr_t base = ${D.base | addr32}UL;

  % for reg_name, reg in D.registers:
<%
  reg_size = reg.size or 32

  if reg.struct:
    s_size = reg.struct
    if s_size < 1:
      s_size = 0
  else:
    s_size = 0

  reg_count = reg.count or 1
  if reg_count < 1:
    reg_count = 1

  va = [(addr32(reg.reset_val), addr32(0)), (reg_count, 1), (reg_size, 32), (s_size, 0)]
%>\
    % if reg.desc:
  ${reg.desc | comment}
    % endif
    % if reg.fields:
  struct ${reg_name} : reg<base + ${'0x%X' % reg.offset}${va | n,varargs}>
  {
<%  line = 0; fields_mask = 0 %>\
    static constexpr type
      % for field_name, field in reg.fields:
<%
    field_valname = upper(field_name if field_name != reg_name else field_name + 'VAL')
    bits = str(field.bits).split('-')

    if len(bits) > 1:
      bit_offset = int(bits[1])
      bit_width  = int(bits[0]) - bit_offset + 1
    else:
      bit_offset = int(bits[0])
      bit_width  = 1

    field_mask   = (0xFFFFFFFF >> (32 - bit_width)) << bit_offset
    fields_mask |= field_mask
%>\
    ${field.desc | comment} (bits: ${field.bits})
    ${',' if line > 0 else ' '}${field_valname | upper}_MASK = ${field_mask | addr32}
    ,${field_valname | upper}_POS = ${bit_offset}
    % if len(field.enum) > 0:
      % for enum_name, enum in field.enum:
    ,${field_valname | upper}_${enum_name | upper} = ${int(enum.val) << bit_offset | addr32} ${enum.desc | comment}
      % endfor
    % elif bit_width == 1:
    ,${field_valname} = ${field_mask | addr32}
    % endif
<% line += 1 %>\
      % endfor
    ,${reg_name}_MASK = ${fields_mask | addr32}
    ;
  };
    % else:
  using ${reg_name} = reg<base + ${'0x%X' % reg.offset}${va | n,varargs}>;
    % endif
  % endfor
}; // struct ${D.name}

} // namespace lmcu::device
