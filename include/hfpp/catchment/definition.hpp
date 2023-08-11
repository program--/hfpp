#pragma once

#include <vector>
#include <unordered_set>
#include <memory>

#include "realization.hpp"

namespace hf {

struct nexus;

struct catchment_proxy;
struct nexus_proxy;

/**
 * @brief Represents a holistic conceptual catchment.
 */
struct catchment
{
    /**
     * @brief Returns whether this catchment is an interior catchment.
     *
     * @note This is determined by whether it
     *       is endorheic or not, i.e. does this
     *       catchment have an outflow, or does it
     *       contribute to an outlet?
     *
     * @return true
     * @return false
     */
    bool is_interior() const noexcept;

    /**
     * @brief Returns whether this catchment is dendritic.
     *
     * @note This is determined by whether this catchment
     *       conforms to the following constraints:
     *       - Does this catchment have a single outflow?
     *       - Does this catchment have a single downstream catchment?
     *       - Does this catchment's outflow have a single downstream catchment?
     *
     * @return true
     * @return false
     */
    bool is_dendritic() const noexcept;

  private:
    std::vector<catchment_proxy>    downstream_;
    std::vector<catchment_proxy>    upstream_;
    std::vector<nexus_proxy>        inflow_;
    std::vector<nexus_proxy>        outflow_;

    std::unordered_set<realization> realizations_;
};

struct catchment_proxy
{
    catchment_proxy();

    catchment* operator*() const noexcept { return catchment_; }
    catchment& operator->() const noexcept { return *catchment_; }

  private:
    catchment* const catchment_;
};

} // namespace hf
