## coding: utf-8
${D.header}
namespace lmcu::device {

enum class irqn : int32_t
{
% for irq, n in D:
  ${irq} = ${n},
% endfor
};

} // namespace lmcu::device
