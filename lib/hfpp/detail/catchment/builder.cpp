#include "builder.hpp"

using builder = hf::factory::catchment_builder;

builder& builder::with_id(const std::string& id)
{
    instance_.id_ = id;
    return *this;
}

builder& builder::with_downstream(catchment& catchment)
{
    instance_.downstream_ =
      instance_.downstream_.insert(make_box<hf::catchment>(catchment));
    return *this;
}

builder& builder::with_upstream(catchment& catchment)
{
    instance_.upstream_ =
      instance_.upstream_.insert(make_box<hf::catchment>(catchment));
    return *this;
}

builder& builder::with_inflow(nexus& nexus)
{
    instance_.inflow_ = instance_.inflow_.insert(make_box<hf::nexus>(nexus));
    return *this;
}

builder& builder::with_outflow(nexus& nexus)
{
    instance_.outflow_ = instance_.outflow_.insert(make_box<hf::nexus>(nexus));
    return *this;
}

hf::catchment builder::get() noexcept
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
