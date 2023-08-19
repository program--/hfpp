#include "definition.hpp"

#include <hfpp/detail/nexus/definition.hpp>

using catchment = hf::catchment;

bool catchment::is_interior() const noexcept
{
    return outflow_.empty();
}

bool catchment::is_dendritic() const noexcept
{
    return outflow_.size() == 1 && downstream_.size() == 1 &&
           outflow_.begin()->get().downstream().size() == 1;
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

bool catchment::operator==(const catchment& cat) const noexcept
{
    return id_ == cat.id_;
}

bool catchment::operator!=(const catchment& cat) const noexcept
{
    return id_ != cat.id_;
}

bool catchment::operator==(const std::string& id) const noexcept
{
    return id_ == id;
}

bool catchment::operator!=(const std::string& id) const noexcept
{
    return id_ != id;
}
