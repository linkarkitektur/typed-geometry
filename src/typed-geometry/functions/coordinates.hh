#pragma once

#include <typed-geometry/detail/operators/ops_vec.hh>
#include <typed-geometry/types/array.hh>
#include <typed-geometry/types/objects/segment.hh>
#include <typed-geometry/types/objects/triangle.hh>
#include <typed-geometry/types/pos.hh>

#include "length.hh"

// For a given primitive and a position, return the position's relative coordinates

// Contained functions:
// - coords
//      - triangle (barycoords)
//      - segment (t-parameter)

// Note: Passing a position that does not lie inside the given primitive,
// the behavior is (yet) undefined
namespace tg
{
template <class ScalarT>
TG_NODISCARD constexpr array<ScalarT, 3> coordinates(triangle<2, ScalarT> const& t, pos<2, ScalarT> const& p)
{
    auto pv0 = t.pos0 - p;
    auto pv1 = t.pos1 - p;
    auto pv2 = t.pos2 - p;
    auto A = cross(t.pos1 - t.pos0, t.pos2 - t.pos0);
    auto A0 = cross(pv1, pv2);
    auto A1 = cross(pv2, pv0);
    auto A2 = cross(pv0, pv1);

    auto A_inv = ScalarT(1) / A;
    return {{A0 * A_inv, A1 * A_inv, A2 * A_inv}};
}

template <class ScalarT>
TG_NODISCARD constexpr array<ScalarT, 3> coordinates(triangle<3, ScalarT> const& t, pos<3, ScalarT> const& p)
{
    auto pv0 = t.pos0 - p;
    auto pv1 = t.pos1 - p;
    auto pv2 = t.pos2 - p;
    auto n = cross(t.pos1 - t.pos0, t.pos2 - t.pos0);
    auto A = length(n);
    n /= A;
    auto A0 = dot(cross(pv1, pv2), n);
    auto A1 = dot(cross(pv2, pv0), n);
    auto A2 = dot(cross(pv0, pv1), n);

    auto A_inv = ScalarT(1) / A;
    return {{A0 * A_inv, A1 * A_inv, A2 * A_inv}};
}

template <int D, class ScalarT>
TG_NODISCARD constexpr ScalarT coordinates(segment<D, ScalarT> const& s, pos<D, ScalarT> const& p)
{
    auto d = s.pos1 - s.pos0;
    auto t = dot(p - s.pos0, d) / dot(d, d);
    return t;
}


} // namespace tg
