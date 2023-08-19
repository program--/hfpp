#include "definition.hpp"

using nexus = hf::nexus;

const std::string& nexus::id() const noexcept
{
    return id_;
}

const nexus::catchment_list& nexus::downstream() const noexcept
{
    return downstream_;
}

const nexus::catchment_list& nexus::upstream() const noexcept
{
    return upstream_;
}

bool nexus::operator==(const nexus& nex) const noexcept
{
    return id_ == nex.id_;
}

bool nexus::operator!=(const nexus& nex) const noexcept
{
    return id_ != nex.id_;
}

bool nexus::operator==(const std::string& id) const noexcept
{
    return id_ == id;
}

bool nexus::operator!=(const std::string& id) const noexcept
{
    return id_ != id;
}
