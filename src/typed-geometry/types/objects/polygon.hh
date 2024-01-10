#pragma once
#include "./polyline.hh"
#include <clean-core/vector.hh>
#include <vector>

namespace tg
{
template <int D, class ScalarT>
struct pgon;

using pgon1 = pgon<1, f32>;
using pgon2 = pgon<2, f32>;
using pgon3 = pgon<3, f32>;
using pgon4 = pgon<4, f32>;

using fpgon1 = pgon<1, f32>;
using fpgon2 = pgon<2, f32>;
using fpgon3 = pgon<3, f32>;
using fpgon4 = pgon<4, f32>;

using dpgon1 = pgon<1, f64>;
using dpgon2 = pgon<2, f64>;
using dpgon3 = pgon<3, f64>;
using dpgon4 = pgon<4, f64>;

using ipgon1 = pgon<1, i32>;
using ipgon2 = pgon<2, i32>;
using ipgon3 = pgon<3, i32>;
using ipgon4 = pgon<4, i32>;

using upgon1 = pgon<1, u32>;
using upgon2 = pgon<2, u32>;
using upgon3 = pgon<3, u32>;
using upgon4 = pgon<4, u32>;

// ======== IMPLEMENTATION ========
// a polygon is a polyline that is assumed to be closed with a segment 
// from the last point to the first point
template <int D, class ScalarT>
struct pgon : public pline<D, ScalarT>
{
    using scalar_t = ScalarT;
    using pos_t = pos<D, ScalarT>;
    using pline_t = pline<D, ScalarT>;

};
} // namespace tg