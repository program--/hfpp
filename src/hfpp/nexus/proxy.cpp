#include <hfpp/nexus/proxy.hpp>

using proxy = hf::detail::nexus_proxy;

proxy::nexus_proxy(const nexus& nexus)
  : nexus_(&nexus){};

const hf::nexus& proxy::operator*() const noexcept
{
    return *nexus_;
}

const hf::nexus* proxy::operator->() const noexcept
{
    return nexus_;
}
