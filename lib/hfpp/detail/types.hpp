#pragma once

#include <memory>

#include <immer/box.hpp>
#include <immer/vector.hpp>
#include <immer/set.hpp>
#include <immer/set_transient.hpp>

namespace hf {

template<typename Tp>
using box = immer::box<Tp>;

template<typename Tp, typename... Args>
inline Tp make_box(Args&&... args)
{
    return box<Tp>{ std::forward<Args>(args)... };
}

template<typename Tp>
using vector = immer::vector<Tp>;

template<typename Tp>
using proxy_vector = vector<box<Tp>>;

using immer::set;
using immer::set_transient;

template<typename Tp>
using proxy_set = immer::set<box<Tp>>;

template<typename Tp>
using polymorphic_set = set<std::unique_ptr<Tp>>;

} // namespace hf
