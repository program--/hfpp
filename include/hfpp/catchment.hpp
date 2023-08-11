#pragma once

#include <vector>

namespace hf {

struct nexus;

struct realization;

struct catchment
{

    /**
     * Returns whether this catchment is an interior catchment.
     *
     * @note This is determined by whether the catchment has a null
     *       outflow, since an internal catchment is defined by whether
     *       it is endorheic or not.
     *
     * @return true
     * @return false
     */
    bool is_interior() const noexcept;

  private:
    catchment*               lower_;
    catchment*               upper_;
    nexus*                   inflow_;
    nexus*                   outflow_;

    std::vector<realization> realizations_;
};

} // namespace hf
