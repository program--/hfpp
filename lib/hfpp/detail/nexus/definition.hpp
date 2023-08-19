#pragma once

#include <string>

#include <immer/vector_transient.hpp>
#include <immer/box.hpp>

#include <hfpp/detail/catchment/fwd.hpp>

#include "fwd.hpp"

namespace hf {

/**
 * @brief Represents a conceptual nexus
 */
struct nexus
{
    using catchment_list = immer::vector_transient<immer::box<catchment>>;

    const std::string&    id() const noexcept;
    const catchment_list& downstream() const noexcept;
    const catchment_list& upstream() const noexcept;

    bool                  operator==(const nexus& nex) const noexcept;
    bool                  operator!=(const nexus& nex) const noexcept;
    bool                  operator==(const std::string& id) const noexcept;
    bool                  operator!=(const std::string& id) const noexcept;

  private:
    friend factory::nexus_builder;

    std::string    id_;
    catchment_list downstream_;
    catchment_list upstream_;
};

} // namespace hf

namespace std {

template<>
struct hash<hf::nexus>
{
    inline size_t operator()(const hf::nexus& cat)
    {
        return hash<std::string>{}(cat.id());
    }
};

} // namespace std
