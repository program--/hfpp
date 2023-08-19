#include "builder.hpp"

using builder = hf::factory::catchment_builder;

hf::catchment builder::get() const noexcept
{
    return instance_;
}

const hf::catchment& builder::peek() const noexcept
{
    return instance_;
}

builder& builder::reset() noexcept
{
    instance_ = catchment{};
    return *this;
}

builder& builder::with_id(const std::string& id)
{
    instance_.id_ = id;
    return *this;
}

builder& builder::with_downstream(catchment& catchment)
{
    instance_.downstream_.push_back(catchment);
    return *this;
}

builder& builder::with_upstream(catchment& catchment)
{
    instance_.upstream_.push_back(catchment);
    return *this;
}

builder& builder::with_inflow(nexus& nexus)
{
    instance_.inflow_.push_back(nexus);
    return *this;
}

builder& builder::with_outflow(nexus& nexus)
{
    instance_.outflow_.push_back(nexus);
    return *this;
}
