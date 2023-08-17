#pragma once

#include <string>
#include <vector>

#include <hfpp/nexus/fwd.hpp>

#include <hfpp/catchment/proxy.hpp>

namespace hf {

/**
 * @brief Represents a conceptual nexus
 */
struct nexus
{
    using catchment_list = std::vector<detail::catchment_proxy>;

    const std::string&    id() const noexcept;
    const catchment_list& downstream() const noexcept;
    const catchment_list& upstream() const noexcept;

  private:
    friend factory::nexus_builder;

    std::string    id_;
    catchment_list downstream_;
    catchment_list upstream_;
};

} // namespace hf
