#include <nexus/test.hh>

TEST("tg::wrap")
{
    CHECK(tg::wrap(0.3f, 0.1f, 0.4f) == approx(0.3f));
    CHECK(tg::wrap(0.35f, 0.1f, 0.2f) == approx(0.15f));
    CHECK(tg::wrap(-.3f, 0.0f, 1.0f) == approx(0.7f));
}

TG_FUZZ_TEST(Wrap, Random)
{
    auto range = uniform(rng, 0.1f, 5.0f);
    auto vmin = uniform(rng, -10.f, 10.f);
    auto vmax = vmin + range;
    auto v0 = uniform(rng, vmin, vmax);
    auto v1 = v0 + uniform(rng, -10, 10) * range;
    CHECK(tg::wrap(v1, vmin, vmax) == approx(v0));
}
