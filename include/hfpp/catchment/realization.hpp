#pragma once

#include <hfpp/realization/definition.hpp>

namespace hf {

namespace detail {

struct catchment_realization : public realization
{
    enum class topology_type
    {
        divide,
        area,
        flowpath
    };

    const topology_type& type() const noexcept;

  private:
    topology_type type_;
};

} // namespace detail
} // namespace hf
