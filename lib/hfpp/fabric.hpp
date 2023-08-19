#pragma once

#include <stdexcept>

#include <immer/set.hpp>

#include "detail/catchment/definition.hpp"

namespace hf {

/**
 * A hydrofabric singleton containing the registry
 * of catchments loaded into this process.
 *
 * This object has two primary responsibilities:
 * - Loading hydrofabric data into memory
 * - Providing catchment lookup
 *
 * @note From the scope of the HY_Features specification,
 *       this fabric object is *similar* to a conceptual
 *       hydrologic complex, i.e. a group of hydrologically
 *       connected components.
 */
struct fabric
{
    // Prevent copy construction
    fabric(const fabric&) = delete;

    // Prevent copy assignment
    fabric& operator=(const fabric&) = delete;

    // Prevent move construction
    fabric(fabric&&) = delete;

    // Prevent move assignment
    fabric& operator=(fabric&&) = delete;

    /**
     * @brief Create or get the fabric instance
     * @throws std::runtime_error if instance is a dead reference
     * @return fabric& reference to the fabric
     */
    static fabric& instance()
    {
        if (instance_ == nullptr) {
            if (destroyed_) {
                handle_dead_ref();
            } else {
                create();
            }
        }

        return *instance_;
    }

  private:
    static fabric* instance_;
    static bool    destroyed_;

    // Set of catchments contained within this fabric
    immer::set<catchment> catchments_;
    immer::set<nexus>     nexuses_;

    // Prevent public default construction
    fabric() = default;

    // Destructor
    ~fabric()
    {
        instance_  = nullptr;
        destroyed_ = true;
    }

    // Create a new instance of this object
    static void create() noexcept
    {
        static fabric obj_;
        instance_ = &obj_;
    }

    // Handle a dead reference to this object when instance() is called
    static void handle_dead_ref()
    {
        throw std::runtime_error("dead hydrofabric reference detected");
    }
};

} // namespace hf
