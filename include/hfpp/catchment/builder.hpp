#pragma once

#include "definition.hpp"

namespace hf {
namespace factory {

struct catchment_builder
{
    void      with_id();
    void      with_lower();
    void      with_upper();
    void      with_inflow();
    void      with_outflow();
    void      with_realization();

    catchment get() const noexcept;
};

} // namespace factory
} // namespace hf
