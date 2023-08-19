#pragma once

#include <string>
#include <algorithm>

#include <hfpp/detail/catchment/definition.hpp>
#include <hfpp/detail/nexus/definition.hpp>

namespace hf {
namespace factory {

struct catchment_builder
{
    catchment_builder() noexcept;

    catchment_builder& with_id(const std::string& id);
    catchment_builder& with_downstream(catchment& catchment);
    catchment_builder& with_upstream(catchment& catchment);
    catchment_builder& with_inflow(nexus& nexus);
    catchment_builder& with_outflow(nexus& nexus);

    /**
     * @brief Get a copy of the catchment this builder is creating.
     *
     * @return catchment
     */
    catchment get() const noexcept;

    /**
     * @brief Get a (const) reference to the catchment
     *        this builder is building.
     *
     * @return const catchment&
     */
    const catchment& peek() const noexcept;

    /**
     * @brief Reset the catchment this builder is building.
     *
     * @return catchment_builder&
     */
    catchment_builder& reset() noexcept;

  private:
    catchment instance_;
};

} // namespace factory
} // namespace hf
