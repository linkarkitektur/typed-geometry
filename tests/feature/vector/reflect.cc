#include <nexus/fuzz_test.hh>

TG_FUZZ_TEST(TypedGeometry, Reflect)
{
    auto d = tg::uniform<tg::dir3>(rng);
    auto v = uniform_vec(rng, tg::sphere3({0, 0, 0}, 3.0f));
    auto n = tg::uniform<tg::dir3>(rng);

    if (dot(d, n) == 0)
        return;
    if (dot(v, n) == 0)
        return;

    auto dr = reflect(d, n);
    auto dv = reflect(v, n);
    CHECK(tg::sign(dot(d, n)) != tg::sign(dot(dr, n)));
    CHECK(tg::sign(dot(v, n)) != tg::sign(dot(dv, n)));
    CHECK(length(dv) == approx(length(v)));
}
