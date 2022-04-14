#include <nexus/test.hh>

TG_FUZZ_TEST(Triangle2, BarycoordMatrix)
{
    auto const bb = tg::aabb2(-10, 10);

    auto const p0 = uniform(rng, bb);
    auto const p1 = uniform(rng, bb);
    auto const p2 = uniform(rng, bb);

    auto const t = tg::triangle(p0, p1, p2);

    auto const M = tg::to_barycoord_matrix_of(t);

    CHECK(M * tg::vec3(p0, 1) == approx(tg::vec3(1, 0, 0), 0.001f));
    CHECK(M * tg::vec3(p1, 1) == approx(tg::vec3(0, 1, 0), 0.001f));
    CHECK(M * tg::vec3(p2, 1) == approx(tg::vec3(0, 0, 1), 0.001f));
    CHECK(M * tg::vec3(centroid_of(t), 1) == approx(tg::vec3(1 / 3.f, 1 / 3.f, 1 / 3.f), 0.001f));

    auto p = uniform(rng, t);
    auto b = M * tg::vec3(p, 1);

    CHECK(b.x >= -0.001f);
    CHECK(b.y >= -0.001f);
    CHECK(b.z >= -0.001f);
    CHECK(b.x <= 1.001f);
    CHECK(b.y <= 1.001f);
    CHECK(b.z <= 1.001f);
    CHECK(b.x + b.y + b.z == approx(1.f).epsilon(0.001f));

    auto p_recon = tg::from_barycoord_matrix_of(t) * b;
    CHECK(tg::pos2(p_recon) == approx(p, 0.001f));
    CHECK(p_recon.z == approx(1).epsilon(0.001f));
}

TG_FUZZ_TEST(Triangle3, BarycoordMatrix)
{
    auto const bb = tg::aabb3(-10, 10);

    auto const p0 = uniform(rng, bb);
    auto const p1 = uniform(rng, bb);
    auto const p2 = uniform(rng, bb);

    auto const t = tg::triangle(p0, p1, p2);

    auto const M = tg::to_barycoord_matrix_of(t);

    CHECK(M * tg::vec4(p0, 1) == approx(tg::vec4(1, 0, 0, 0), 0.001f));
    CHECK(M * tg::vec4(p1, 1) == approx(tg::vec4(0, 1, 0, 0), 0.001f));
    CHECK(M * tg::vec4(p2, 1) == approx(tg::vec4(0, 0, 1, 0), 0.001f));
    CHECK(M * tg::vec4(centroid_of(t), 1) == approx(tg::vec4(1 / 3.f, 1 / 3.f, 1 / 3.f, 0), 0.001f));

    auto p = uniform(rng, t);
    auto b = M * tg::vec4(p, 1);

    CHECK(b.x >= -0.001f);
    CHECK(b.y >= -0.001f);
    CHECK(b.z >= -0.001f);
    CHECK(b.x <= 1.001f);
    CHECK(b.y <= 1.001f);
    CHECK(b.z <= 1.001f);
    CHECK(b.w == approx(0.f).epsilon(0.001f));
    CHECK(b.x + b.y + b.z == approx(1.f).epsilon(0.001f));

    auto p_recon = tg::from_barycoord_matrix_of(t) * b;
    CHECK(tg::pos3(p_recon) == approx(p, 0.001f));
    CHECK(p_recon.w == approx(1).epsilon(0.001f));

    auto n = tg::normal_of(t);
    auto offset = uniform(rng, -10.f, 10.f);
    auto b2 = M * tg::vec4(p + n * offset, 1);

    CHECK(b2.x == approx(b.x).epsilon(0.001f));
    CHECK(b2.y == approx(b.y).epsilon(0.001f));
    CHECK(b2.z == approx(b.z).epsilon(0.001f));
    CHECK(b2.w == approx(offset).epsilon(0.001f));

    auto p_recon2 = tg::from_barycoord_matrix_of(t) * b2;
    CHECK(tg::pos3(p_recon2) == approx(p + n * offset, 0.001f));
    CHECK(p_recon.w == approx(1).epsilon(0.001f));
}

TG_FUZZ_TEST(Triangle2, TransformationFromTo)
{
    auto const bb = tg::aabb2(-10, 10);

    auto const p0 = uniform(rng, bb);
    auto const p1 = uniform(rng, bb);
    auto const p2 = uniform(rng, bb);

    auto const q0 = uniform(rng, bb);
    auto const q1 = uniform(rng, bb);
    auto const q2 = uniform(rng, bb);

    auto const t0 = tg::triangle(p0, p1, p2);
    auto const t1 = tg::triangle(q0, q1, q2);

    auto const M = tg::transformation_from_to(t0, t1);

    CHECK(M * p0 == approx(q0, 0.01f));
    CHECK(M * p1 == approx(q1, 0.01f));
    CHECK(M * p2 == approx(q2, 0.01f));

    auto const b = tg::uniform_barycoords(rng);
    auto const p = t0[b];
    auto const q = t1[b];
    CHECK(M * p == approx(q, 0.01f));
}

TG_FUZZ_TEST(Triangle3, TransformationFromTo)
{
    auto const bb = tg::aabb3(-10, 10);

    auto const p0 = uniform(rng, bb);
    auto const p1 = uniform(rng, bb);
    auto const p2 = uniform(rng, bb);

    auto const q0 = uniform(rng, bb);
    auto const q1 = uniform(rng, bb);
    auto const q2 = uniform(rng, bb);

    auto const t0 = tg::triangle(p0, p1, p2);
    auto const t1 = tg::triangle(q0, q1, q2);

    auto const M = tg::transformation_from_to(t0, t1);

    CHECK(M * p0 == approx(q0, 0.001f));
    CHECK(M * p1 == approx(q1, 0.001f));
    CHECK(M * p2 == approx(q2, 0.001f));

    auto const b = tg::uniform_barycoords(rng);
    auto const p = t0[b];
    auto const q = t1[b];
    CHECK(M * p == approx(q, 0.001f));
}
