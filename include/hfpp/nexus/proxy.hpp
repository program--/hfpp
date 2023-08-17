#pragma once

#include <hfpp/nexus/fwd.hpp>

namespace hf {
namespace detail {

struct nexus_proxy
{
    nexus_proxy() = delete;

    nexus_proxy(const nexus& nexus);

    const nexus& operator*() const noexcept;
    const nexus* operator->() const noexcept;

  private:
    const nexus* nexus_;
};

} // namespace detail
} // namespace hf
