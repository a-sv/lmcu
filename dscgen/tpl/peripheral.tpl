## coding: utf-8
#pragma once
#include "../ip/${D.ip}.h"
<% ip_ver, ip_name = D.ip.split('/') %>\

namespace lmcu::device {

using ${E.name} = ip::${ip_ver}::${ip_name}<${D.base | addr32}>;

} // namespace lmcu::device
