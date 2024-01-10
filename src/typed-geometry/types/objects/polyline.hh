#pragma once

#include "../pos.hh"
// #include "traits.hh"
#include <clean-core/vector.hh>
#include <vector>

namespace tg
{
template <int D, class ScalarT>
struct pline;

// Common polyline types
using pline1 = pline<1, f32>;
using pline2 = pline<2, f32>;
using pline3 = pline<3, f32>;
using pline4 = pline<4, f32>;

using fpline1 = pline<1, f32>;
using fpline2 = pline<2, f32>;
using fpline3 = pline<3, f32>;
using fpline4 = pline<4, f32>;

using dpline1 = pline<1, f64>;
using dpline2 = pline<2, f64>;
using dpline3 = pline<3, f64>;
using dpline4 = pline<4, f64>;

using ipline1 = pline<1, i32>;
using ipline2 = pline<2, i32>;
using ipline3 = pline<3, i32>;
using ipline4 = pline<4, i32>;

using upline1 = pline<1, u32>;
using upline2 = pline<2, u32>;
using upline3 = pline<3, u32>;
using upline4 = pline<4, u32>;

// ======== IMPLEMENTATION ========
template <int D, class ScalarT>
struct pline
{
    using scalar_t = ScalarT;
    using pos_t = pos<D, ScalarT>;

    cc::vector<pos_t> pts;

    constexpr pline() = default;
    constexpr pline(cc::vector<pos_t> const& pts_) : pts(pts_) {}
    constexpr pline(std::vector<pos_t> const& pts_) {
        pts = cc::vector<pos_t>(pts_.size());
        for (int i = 0; i < pts.size(); i++){
            pts[i] = pts_[i];
        }

    }


    template <class OtherT>
    explicit constexpr pline(pline<D, OtherT> const& v) : pts(v.pts)
    {
    }

    [[nodiscard]] bool operator==(pline const& rhs) const { 
        bool equal = true;

        if (pts.size() != rhs.size()) return false;

        for (int i = 0; i < pts.size(); i++){
            equal = equal && (pts[i] == rhs[i]);
        }
        return equal;
    }
    [[nodiscard]] bool operator!=(pline const& rhs) const { return !operator==(rhs); }
    [[nodiscard]] pos_t operator[](size_t i) const { return pts[i];}

    size_t size() const { return pts.size(); }
};

template <class I, int D, class ScalarT>
constexpr void introspect(I&& i, pline<D, ScalarT>& v)
{
    i(v.pts, "pts");
}
} // namespace tg