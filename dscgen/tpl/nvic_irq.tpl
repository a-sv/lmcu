## coding: utf-8
namespace lmcu::device {

enum class irqn : int32_t
{
  invalid_irqn = -15,
% for irq, n in D:
  ${irq} = ${n},
% endfor
};

constexpr irqn find_irqn(const char *name) noexcept
{
  constexpr std::pair<const char*, irqn> irqlst[] =
  {
% for irq, n in D:
    {"${irq}", irqn::${irq}},
% endfor
  };

  auto cmp = [](const char *a, const char *b)
  {
    while(*a && *b) {
      if(*a++ != *b++) { return false; }
    }
    return *a == *b;
  };

  for(auto irq : irqlst) {
    if(cmp(name, irq.first)) { return irq.second; }
  }

  return irqn::invalid_irqn;
}

} // namespace lmcu::device
