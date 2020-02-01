#pragma once

#include <typed-geometry/functions/basic/scalar_math.hh>
#include <typed-geometry/functions/vector/distance.hh>
#include <typed-geometry/detail/operators/ops_pos.hh>
#include <typed-geometry/detail/operators/ops_vec.hh>
#include <typed-geometry/detail/special_values.hh>
#include <typed-geometry/detail/tg_traits.hh>
#include <typed-geometry/types/objects/line.hh>
#include <typed-geometry/types/objects/plane.hh>
#include <typed-geometry/types/objects/segment.hh>
#include <typed-geometry/types/pos.hh>
#include <typed-geometry/types/quadric.hh>
#include <typed-geometry/types/vec.hh>

#include "closest_points.hh"

namespace tg
{
// Default implementation of distance as abs(signed_distance)
// TODO: FIXME via priority_tag<>
// template <class A, class B>
// [[nodiscard]] constexpr auto distance(A const& a, B const& b) -> decltype(abs(signed_distance(a, b)))
// {
//     return abs(signed_distance(a, b));
// }

// Default implementation of distance_sqr as distance_sqr(ca, cb) for closest points ca and cb
template <class A, class B>
[[nodiscard]] constexpr auto distance_sqr(A const& a, B const& b) -> decltype(length_sqr(closest_points(a, b).first - closest_points(a, b).second))
{
    auto cp = closest_points(a, b);
    return length_sqr(cp.first - cp.second);
}

// Convenience for distance to (0,0,0)
template <class Obj>
[[nodiscard]] constexpr auto distance_to_origin(Obj const& o) -> decltype(distance(o, pos_type_for<Obj>::zero))
{
    return distance(o, pos_type_for<Obj>::zero);
}
template <class Obj>
[[nodiscard]] constexpr auto distance_sqr_to_origin(Obj const& o) -> decltype(distance(o, pos_type_for<Obj>::zero))
{
    return distance_sqr(o, pos_type_for<Obj>::zero);
}


// =========== Object Implementations ===========

// signed distance is positive if p lies above pl, 0 if it lies on the plane and negative if below pl
template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> signed_distance(pos<3, ScalarT> const& p, hyperplane<D, ScalarT> const& pl)
{
    return dot(p - pos<D, ScalarT>::zero, pl.normal) - pl.dis;
}

template <int D, class ScalarT>
[[nodiscard]] constexpr fractional_result<ScalarT> distance(pos<3, ScalarT> const& p, hyperplane<D, ScalarT> const& pl)
{
    return abs(signed_distance(p, pl));
}


// =========== Other Implementations ===========

template <class ScalarT, class = enable_if<is_scalar<ScalarT>>>
[[nodiscard]] constexpr ScalarT distance_sqr(ScalarT a, ScalarT b)
{
    auto const d = a - b;
    return d * d;
}

template <class ScalarT>
[[nodiscard]] constexpr ScalarT distance_sqr(pos<2, ScalarT> const& p, quadric<2, ScalarT> const& q)
{
    return q(p);
}

template <class ScalarT>
[[nodiscard]] constexpr ScalarT distance_sqr(pos<3, ScalarT> const& p, quadric<3, ScalarT> const& q)
{
    return q(p);
}

template <int D, class ScalarT>
[[nodiscard]] constexpr ScalarT distance_sqr(quadric<D, ScalarT> const& q, pos<D, ScalarT> const& p)
{
    return distance_sqr(p, q);
}

} // namespace tg
