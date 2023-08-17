#include <hfpp/catchment/definition.hpp>
#include <hfpp/catchment/proxy.hpp>

#include <hfpp/nexus/definition.hpp>
#include <hfpp/nexus/proxy.hpp>

using catchment = hf::catchment;

bool catchment::is_interior() const noexcept
{
    return outflow_.empty();
}

bool catchment::is_dendritic() const noexcept
{
    return outflow_.size() == 1 && downstream_.size() == 1 &&
           outflow_[0]->downstream().size() == 1;
}

const std::string& catchment::id() const noexcept
{
    return id_;
}

const catchment::catchment_list& catchment::downstream() const noexcept
{
    return downstream_;
}

const catchment::catchment_list& catchment::upstream() const noexcept
{
    return upstream_;
}

const catchment::nexus_list& catchment::inflow() const noexcept
{
    return inflow_;
}

const catchment::nexus_list& catchment::outflow() const noexcept
{
    return outflow_;
}
