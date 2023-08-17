#pragma once

#include <hfpp/catchment/fwd.hpp>

namespace hf {
namespace detail {

struct catchment_proxy
{
    catchment_proxy() = delete;

    catchment_proxy(const catchment& catchment);

    const catchment& operator*() const noexcept;
    const catchment* operator->() const noexcept;

  private:
    const catchment* catchment_;
};

} // namespace detail
} // namespace hf
