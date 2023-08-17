#include <hfpp/catchment/proxy.hpp>

using proxy = hf::detail::catchment_proxy;

proxy::catchment_proxy(const catchment& catchment)
  : catchment_(&catchment){};

const hf::catchment& proxy::operator*() const noexcept
{
    return *catchment_;
}

const hf::catchment* proxy::operator->() const noexcept
{
    return catchment_;
}
