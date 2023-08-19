#pragma once

#include <immer/memory_policy.hpp>
#include <string>

#include <hfpp/detail/types.hpp>

#include <hfpp/detail/catchment/fwd.hpp>
#include <hfpp/detail/nexus/fwd.hpp>

#include <hfpp/detail/catchment/realization.hpp>

namespace hf {

/**
 * @brief Represents a holistic conceptual catchment.
 */
struct catchment
{
    using catchment_list  = hf::proxy_set<catchment>;
    using nexus_list      = hf::proxy_set<nexus>;
    using realization_set = hf::polymorphic_set<realization>;

    catchment()           = default;

    /**
     * @brief Get the ID of this catchment.
     *
     * @return const std::string&
     */
    const std::string& id() const noexcept;

    /**
     * @brief Get a list of downstream catchments.
     *
     * @return const catchment_list&
     */
    const catchment_list& downstream() const noexcept;

    /**
     * @brief Get a list of upstream catchments.
     *
     * @return const catchment_list&
     */
    const catchment_list& upstream() const noexcept;

    /**
     * @brief Get a list of all contributing/inflow nexuses.
     *
     * @return const nexus_list&
     */
    const nexus_list& inflow() const noexcept;

    /**
     * @brief Get a list of all receiving/outflow nexuses.
     *
     * @return const nexus_list&
     */
    const nexus_list& outflow() const noexcept;

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

    bool operator==(const catchment& cat) const noexcept;
    bool operator!=(const catchment& cat) const noexcept;

    bool operator==(const std::string& id) const noexcept;
    bool operator!=(const std::string& id) const noexcept;

  private:
    friend factory::catchment_builder;

    std::string    id_;
    catchment_list downstream_;
    catchment_list upstream_;
    nexus_list     inflow_;
    nexus_list     outflow_;
    // realization_set realizations_;
};

} // namespace hf

namespace std {

template<>
struct hash<hf::catchment>
{
    inline size_t operator()(const hf::catchment& cat)
    {
        return hash<std::string>{}(cat.id());
    }
};

} // namespace std
