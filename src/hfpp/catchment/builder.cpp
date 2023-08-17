#include <hfpp/catchment/builder.hpp>
#include <hfpp/catchment/proxy.hpp>

using builder = hf::factory::catchment_builder;

builder::catchment_builder() noexcept
  : instance_(catchment{}){};

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
    instance_.downstream_.emplace_back(catchment);
    return *this;
}

builder& builder::with_upstream(catchment& catchment)
{
    instance_.upstream_.emplace_back(catchment);
    return *this;
}

builder& builder::with_inflow(nexus& nexus)
{
    instance_.inflow_.emplace_back(nexus);
    return *this;
}

builder& builder::with_outflow(nexus& nexus)
{
    instance_.outflow_.emplace_back(nexus);
    return *this;
}
