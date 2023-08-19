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
