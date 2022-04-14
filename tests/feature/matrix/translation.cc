#include <nexus/test.hh>

TG_FUZZ_TEST(TypedGeometry, Translation)
{
    const auto min = -10.0f;
    const auto max = 10.0f;

    // 1D
    {
        auto box1 = tg::aabb1(tg::pos1(min), tg::pos1(max));

        auto v = uniform(rng, box1);

        auto s = tg::vec1(uniform(rng, box1));
        auto tra = tg::translation(s);

        auto w = tra * v;

        CHECK(w.x - v.x == approx(s.x));
    }

    // 2D
    {
        auto box2 = tg::aabb2(tg::pos2(min), tg::pos2(max));

        auto v = uniform(rng, box2);

        auto s = tg::vec2(uniform(rng, box2));
        auto tra = tg::translation(s);

        auto w = tra * v;

        auto res = w - v;
        CHECK(res == approx(s, 1e-5f));
    }

    // 3D
    {
        auto box3 = tg::aabb3(tg::pos3(min), tg::pos3(max));

        auto v = uniform(rng, box3);

        auto s = tg::vec3(uniform(rng, box3));
        auto tra = tg::translation(s);

        auto w = tra * v;

        auto res = w - v;
        CHECK(res == approx(s, 1e-5f));
    }
}
