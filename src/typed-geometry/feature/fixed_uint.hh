#pragma once

#include <immintrin.h>

#include <typed-geometry/functions/minmax.hh>
#include <typed-geometry/types/scalars/fixed_uint.hh>

#include "fixed_uint_gen.hh"

// todo: guard from msvc, or alternative implementation there!
// todo: division and modulo are essentially the same code, put into detail maybe
// todo: gcc does not seem to produce optimal code gen
// todo: float conversion is quite limited
// todo: all arithmetic operations with u64: definition done, implementation!

namespace tg
{
// comparison

template <int w0, int w1>
constexpr bool operator==(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr bool operator!=(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr bool operator<(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr bool operator>(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr bool operator<=(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr bool operator>=(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;

template <int w>
constexpr bool operator==(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr bool operator!=(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr bool operator<(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr bool operator>(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr bool operator<=(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr bool operator>=(u64 lhs, fixed_uint<w> const& rhs) noexcept;

template <int w>
constexpr bool operator==(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr bool operator!=(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr bool operator<(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr bool operator>(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr bool operator<=(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr bool operator>=(fixed_uint<w> const& lhs, u64 rhs) noexcept;

// standard arithmetics

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator+(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator-(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator*(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator/(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator%(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;

template <int w>
constexpr fixed_uint<w> operator+(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator-(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator*(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator/(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator%(u64 lhs, fixed_uint<w> const& rhs) noexcept;

template <int w>
constexpr fixed_uint<w> operator+(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator-(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator*(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator/(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator%(fixed_uint<w> const& lhs, u64 rhs) noexcept;

// assignment arithmetics

template <int w0, int w1>
constexpr fixed_uint<w0>& operator+=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<w0>& operator-=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<w0>& operator*=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<w0>& operator/=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<w0>& operator%=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;

template <int w>
constexpr fixed_uint<w>& operator+=(fixed_uint<w>& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w>& operator-=(fixed_uint<w>& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w>& operator*=(fixed_uint<w>& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w>& operator/=(fixed_uint<w>& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w>& operator%=(fixed_uint<w>& lhs, u64 rhs) noexcept;

// increment / decrement

template <int w>
constexpr fixed_uint<w>& operator++(fixed_uint<w>& lhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator++(fixed_uint<w>& lhs, int) noexcept;
template <int w>
constexpr fixed_uint<w>& operator--(fixed_uint<w>& lhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator--(fixed_uint<w>& lhs, int) noexcept;

// bitwise logic

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator|(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator&(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator^(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator~(fixed_uint<w> const& lhs) noexcept;

template <int w>
constexpr fixed_uint<w> operator|(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator&(u64 lhs, fixed_uint<w> const& rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator^(u64 lhs, fixed_uint<w> const& rhs) noexcept;

template <int w>
constexpr fixed_uint<w> operator|(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator&(fixed_uint<w> const& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w> operator^(fixed_uint<w> const& lhs, u64 rhs) noexcept;

// assignment bit ops

template <int w0, int w1>
constexpr fixed_uint<w0>& operator|=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<w0>& operator&=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;
template <int w0, int w1>
constexpr fixed_uint<w0>& operator^=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept;

template <int w>
constexpr fixed_uint<w>& operator|=(fixed_uint<w>& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w>& operator&=(fixed_uint<w>& lhs, u64 rhs) noexcept;
template <int w>
constexpr fixed_uint<w>& operator^=(fixed_uint<w>& lhs, u64 rhs) noexcept;

// shift

template <int w>
constexpr fixed_uint<w> operator>>(fixed_uint<w> const& lhs, int shift) noexcept;
template <int w>
constexpr fixed_uint<w> operator<<(fixed_uint<w> const& lhs, int shift) noexcept;

// assignment shift

template <int w>
constexpr fixed_uint<w>& operator>>=(fixed_uint<w>& lhs, int shift) noexcept;
template <int w>
constexpr fixed_uint<w>& operator<<=(fixed_uint<w>& lhs, int shift) noexcept;

// muliplication specializations

namespace detail
{
template <int w_res, class T0, class T1>
fixed_uint<w_res> mul(T0 const& lhs, T1 const& rhs);
}

//#############################################################################
//#                             implemenation                                 #
//#############################################################################

template <int words>
template <int rhs_words, class, class>
constexpr fixed_uint<words>::fixed_uint(fixed_uint<rhs_words> rhs)
{
    // explicit from larger type
    static_assert(words < rhs_words);
    d[0] = rhs.d[0];
    if constexpr (words > 1)
        d[1] = rhs.d[1];
    if constexpr (words > 2)
        d[2] = rhs.d[2];
    // not needed:
    //    if constexpr (words > 3)
    //        d[3] = rhs.d[3];
    static_assert(words <= 3, "should only cast down");
}

template <int words>
template <int rhs_words, class>
constexpr fixed_uint<words>::fixed_uint(fixed_uint<rhs_words> rhs)
{
    // implicit from smaller type
    static_assert(rhs_words < words);
    d[0] = rhs.d[0];
    if constexpr (rhs_words > 1)
        d[1] = rhs.d[1];
    if constexpr (rhs_words > 2)
        d[2] = rhs.d[2];

    // not needed:
    //    if constexpr (rhs_words > 3)
    //        d[3] = rhs.d[3];
    static_assert(rhs_words <= 3, "should only cast up");
}

template <int words>
constexpr fixed_uint<words>::operator float()
{
    float res = float(d[0]);
    if constexpr (words > 1)
        res += float(d[1]) * 0x1p64f;
    if constexpr (words > 2)
        res += float(d[2]) * float(0x1p128);
    if constexpr (words > 3)
        res += float(d[3]) * float(0x1p192);
    return res;
}

template <int words>
constexpr fixed_uint<words>::operator double()
{
    double res = double(d[0]);
    if constexpr (words > 1)
        res += double(d[1]) * 0x1p64;
    if constexpr (words > 2)
        res += double(d[2]) * 0x1p128;
    if constexpr (words > 3)
        res += double(d[3]) * 0x1p192;
    return res;
}

//
// comparison
//

template <int w0, int w1>
constexpr bool operator==(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    bool eq = true;

    eq &= lhs.d[0] == rhs.d[0];
    if constexpr (w0 > 1 && w1 > 1)
        eq &= lhs.d[1] == rhs.d[1];
    if constexpr (w0 > 2 && w1 > 2)
        eq &= lhs.d[2] == rhs.d[2];
    if constexpr (w0 > 3 && w1 > 3)
        eq &= lhs.d[3] == rhs.d[3];

    if constexpr (w0 >= w1 + 1)
        eq &= lhs.d[w1 + 0] == 0;
    if constexpr (w0 >= w1 + 2)
        eq &= lhs.d[w1 + 1] == 0;
    if constexpr (w0 >= w1 + 3)
        eq &= lhs.d[w1 + 2] == 0;

    if constexpr (w0 + 1 <= w1)
        eq &= rhs.d[w0 + 0] == 0;
    if constexpr (w0 + 2 <= w1)
        eq &= rhs.d[w0 + 1] == 0;
    if constexpr (w0 + 3 <= w1)
        eq &= rhs.d[w0 + 2] == 0;

    return eq;
}

template <int w0, int w1>
constexpr bool operator!=(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    bool neq = false;

    neq |= lhs.d[0] != rhs.d[0];
    if constexpr (w0 > 1 && w1 > 1)
        neq |= lhs.d[1] != rhs.d[1];
    if constexpr (w0 > 2 && w1 > 2)
        neq |= lhs.d[2] != rhs.d[2];
    if constexpr (w0 > 3 && w1 > 3)
        neq |= lhs.d[3] != rhs.d[3];

    if constexpr (w0 >= w1 + 1)
        neq |= lhs.d[w1 + 0] != 0;
    if constexpr (w0 >= w1 + 2)
        neq |= lhs.d[w1 + 1] != 0;
    if constexpr (w0 >= w1 + 3)
        neq |= lhs.d[w1 + 2] != 0;

    if constexpr (w0 + 1 <= w1)
        neq |= rhs.d[w0 + 0] != 0;
    if constexpr (w0 + 2 <= w1)
        neq |= rhs.d[w0 + 1] != 0;
    if constexpr (w0 + 3 <= w1)
        neq |= rhs.d[w0 + 2] != 0;

    return neq;
}

template <int w0, int w1>
constexpr bool operator<(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    if constexpr (w0 > w1 + 0)
        if (lhs.d[w1 + 0] != 0)
            return false;
    if constexpr (w0 > w1 + 1)
        if (lhs.d[w1 + 1] != 0)
            return false;
    if constexpr (w0 > w1 + 2)
        if (lhs.d[w1 + 2] != 0)
            return false;

    if constexpr (w0 + 0 < w1)
        if (rhs.d[w0 + 0] != 0)
            return true;
    if constexpr (w0 + 1 < w1)
        if (rhs.d[w0 + 1] != 0)
            return true;
    if constexpr (w0 + 2 < w1)
        if (rhs.d[w0 + 2] != 0)
            return true;

    if constexpr (w0 > 3 && w1 > 3)
        if (lhs.d[3] < rhs.d[3])
            return true;
    if constexpr (w0 > 2 && w1 > 2)
        if (lhs.d[2] < rhs.d[2])
            return true;
    if constexpr (w0 > 1 && w1 > 1)
        if (lhs.d[1] < rhs.d[1])
            return true;
    if (lhs.d[0] < rhs.d[0])
        return true;
}

template <int w0, int w1>
constexpr bool operator>(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    return rhs < lhs;
}

template <int w0, int w1>
constexpr bool operator<=(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    if constexpr (w0 > w1 + 0)
        if (lhs.d[w1 + 0] != 0)
            return false;
    if constexpr (w0 > w1 + 1)
        if (lhs.d[w1 + 1] != 0)
            return false;
    if constexpr (w0 > w1 + 2)
        if (lhs.d[w1 + 2] != 0)
            return false;

    if constexpr (w0 + 0 < w1)
        if (rhs.d[w0 + 0] != 0)
            return true;
    if constexpr (w0 + 1 < w1)
        if (rhs.d[w0 + 1] != 0)
            return true;
    if constexpr (w0 + 2 < w1)
        if (rhs.d[w0 + 2] != 0)
            return true;

    if constexpr (w0 > 3 && w1 > 3)
        if (lhs.d[3] > rhs.d[3])
            return false;
    if constexpr (w0 > 2 && w1 > 2)
        if (lhs.d[2] > rhs.d[2])
            return false;
    if constexpr (w0 > 1 && w1 > 1)
        if (lhs.d[1] > rhs.d[1])
            return false;
    if (lhs.d[0] > rhs.d[0])
        return false;

    return true;
}

template <int w0, int w1>
constexpr bool operator>=(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    return rhs <= lhs;
}

//
//  standard arithmetics
//

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator+(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    constexpr int w_out = max(w0, w1);
    fixed_uint<w_out> res;
    fixed_uint<w_out> l = lhs;
    fixed_uint<w_out> r = rhs;
    decltype(_addcarry_u64(0, 0, 0, nullptr)) c = 0;

    c = _addcarry_u64(c, l.d[0], r.d[0], &res.d[0]);
    if constexpr (w_out > 1)
        c = _addcarry_u64(c, l.d[1], r.d[1], &res.d[1]);
    if constexpr (w_out > 2)
        c = _addcarry_u64(c, l.d[2], r.d[2], &res.d[2]);
    if constexpr (w_out > 3)
        c = _addcarry_u64(c, l.d[3], r.d[3], &res.d[3]);

    return res;
}

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator-(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    constexpr int w_out = max(w0, w1);
    fixed_uint<w_out> res;
    fixed_uint<w_out> l = lhs;
    fixed_uint<w_out> r = rhs;
    decltype(_addcarry_u64(0, 0, 0, nullptr)) c = 0;

    c = _subborrow_u64(c, l.d[0], r.d[0], &res.d[0]);
    if constexpr (w_out > 1)
        c = _subborrow_u64(c, l.d[1], r.d[1], &res.d[1]);
    if constexpr (w_out > 2)
        c = _subborrow_u64(c, l.d[2], r.d[2], &res.d[2]);
    if constexpr (w_out > 3)
        c = _subborrow_u64(c, l.d[3], r.d[3], &res.d[3]);

    return res;
}

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator*(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    constexpr int w_out = max(w0, w1);
    fixed_uint<w_out> l = lhs;
    fixed_uint<w_out> r = rhs;
    return mul<w_out>(l, r);
}

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator/(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    TG_ASSERT(rhs != 0 && "division by zero!");

    constexpr int w_out = max(w0, w1);
    fixed_uint<w_out> l = lhs;
    fixed_uint<w_out> r = rhs;

    /// see https://en.wikipedia.org/wiki/Division_algorithm#Integer_division_(unsigned)_with_remainder
    fixed_uint<w_out> quotient = 0;
    fixed_uint<w_out> remainder = 0;
    for (auto i = (w_out * 64) - 1; i >= 0; --i)
    {
        remainder <<= 1;
        auto const word = i / 64;
        auto const idx = i % 64;
        remainder.d[0] |= (l.d[word] & (1 << idx)) >> idx;
        if (remainder >= r)
        {
            remainder -= r;
            quotient = 1;
        }
    }
    return quotient;
}

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator%(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    TG_ASSERT(rhs != 0 && "division by zero!");
    constexpr int w_out = max(w0, w1);
    fixed_uint<w_out> l = lhs;
    fixed_uint<w_out> r = rhs;

    /// see https://en.wikipedia.org/wiki/Division_algorithm#Integer_division_(unsigned)_with_remainder
    fixed_uint<w_out> quotient = 0;
    fixed_uint<w_out> remainder = 0;
    for (auto i = (w_out * 64) - 1; i >= 0; --i)
    {
        remainder <<= 1;
        auto const word = i / 64;
        auto const idx = i % 64;
        remainder.d[0] |= (l.d[word] & (1 << idx)) >> idx;
        if (remainder >= r)
        {
            remainder -= r;
            quotient = 1;
        }
    }
    return remainder;
}

// assignment arithmetics

template <int w0, int w1>
constexpr fixed_uint<w0>& operator+=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    lhs = lhs + rhs;
    return lhs;
}
template <int w0, int w1>
constexpr fixed_uint<w0>& operator-=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    lhs = lhs - rhs;
    return lhs;
}
template <int w0, int w1>
constexpr fixed_uint<w0>& operator*=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    lhs = lhs * rhs;
    return lhs;
}
template <int w0, int w1>
constexpr fixed_uint<w0>& operator/=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    lhs = lhs / rhs;
    return lhs;
}
template <int w0, int w1>
constexpr fixed_uint<w0>& operator%=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    lhs = lhs % rhs;
    return lhs;
}

// increment / decrement

template <int w>
constexpr fixed_uint<w>& operator++(fixed_uint<w>& lhs) noexcept
{
    u64 c0 = 0;
    u64 c1 = 0;
    u64 c2 = 0;

    ++lhs.d[0];
    if constexpr (w > 1)
    {
        c0 = lhs.d[0] == 0;
        lhs.d[1] += c0;
    }
    if constexpr (w > 2)
    {
        c1 = lhs.d[1] == 0 & c0;
        lhs.d[2] += c1;
    }
    if constexpr (w > 3)
    {
        c2 = lhs.d[2] == 0 & c1;
        lhs.d[3] += c2;
    }
    return lhs;
}
template <int w>
constexpr fixed_uint<w> operator++(fixed_uint<w>& lhs, int) noexcept
{
    fixed_uint<w> cpy = lhs;
    ++lhs;
    return cpy;
}
template <int w>
constexpr fixed_uint<w>& operator--(fixed_uint<w>& lhs) noexcept
{
    u64 c0 = 0;
    u64 c1 = 0;
    u64 c2 = 0;

    --lhs.d[0];
    if constexpr (w > 1)
    {
        c0 = lhs.d[0] == -1;
        lhs.d[1] -= c0;
    }
    if constexpr (w > 2)
    {
        c1 = lhs.d[1] == -1 & c0;
        lhs.d[2] -= c1;
    }
    if constexpr (w > 3)
    {
        c2 = lhs.d[2] == -1 & c1;
        lhs.d[3] -= c2;
    }
    return lhs;
}
template <int w>
constexpr fixed_uint<w> operator--(fixed_uint<w>& lhs, int) noexcept
{
    fixed_uint<w> cpy = lhs;
    --lhs;
    return cpy;
}

// bitwise logic

template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator|(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    fixed_uint<max(w0, w1)> res;
    fixed_uint<max(w0, w1)> l = lhs;
    fixed_uint<max(w0, w1)> r = rhs;

    res.d[0] = l.d[0] | r.d[0];
    if constexpr (max(w0, w1) > 1)
        res.d[1] = l.d[1] | r.d[1];
    if constexpr (max(w0, w1) > 2)
        res.d[2] = l.d[2] | r.d[2];
    if constexpr (max(w0, w1) > 3)
        res.d[3] = l.d[3] | r.d[3];

    return res;
}
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator&(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    fixed_uint<max(w0, w1)> res;
    fixed_uint<max(w0, w1)> l = lhs;
    fixed_uint<max(w0, w1)> r = rhs;

    res.d[0] = l.d[0] & r.d[0];
    if constexpr (max(w0, w1) > 1)
        res.d[1] = l.d[1] & r.d[1];
    if constexpr (max(w0, w1) > 2)
        res.d[2] = l.d[2] & r.d[2];
    if constexpr (max(w0, w1) > 3)
        res.d[3] = l.d[3] & r.d[3];

    return res;
}
template <int w0, int w1>
constexpr fixed_uint<max(w0, w1)> operator^(fixed_uint<w0> const& lhs, fixed_uint<w1> const& rhs) noexcept
{
    fixed_uint<max(w0, w1)> res;
    fixed_uint<max(w0, w1)> l = lhs;
    fixed_uint<max(w0, w1)> r = rhs;

    res.d[0] = l.d[0] ^ r.d[0];
    if constexpr (max(w0, w1) > 1)
        res.d[1] = l.d[1] ^ r.d[1];
    if constexpr (max(w0, w1) > 2)
        res.d[2] = l.d[2] ^ r.d[2];
    if constexpr (max(w0, w1) > 3)
        res.d[3] = l.d[3] ^ r.d[3];

    return res;
}
template <int w>
constexpr fixed_uint<w> operator~(fixed_uint<w> const& lhs) noexcept
{
    fixed_uint<w> res;

    res.d[0] = ~lhs.d[0];
    if constexpr (w > 1)
        res.d[1] = ~lhs.d[1];
    if constexpr (w > 2)
        res.d[2] = ~lhs.d[2];
    if constexpr (w > 3)
        res.d[3] = ~lhs.d[3];

    return res;
}

// assignment bit ops

template <int w0, int w1>
constexpr fixed_uint<w0>& operator|=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    fixed_uint<w0> r = fixed_uint<w0>(rhs);

    lhs.d[0] |= r.d[0];
    if constexpr (w0 > 1)
        lhs.d[1] |= r.d[1];
    if constexpr (w0 > 2)
        lhs.d[2] |= r.d[2];
    if constexpr (w0 > 3)
        lhs.d[3] |= r.d[3];

    return lhs;
}
template <int w0, int w1>
constexpr fixed_uint<w0>& operator&=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    fixed_uint<w0> r = fixed_uint<w0>(rhs);

    lhs.d[0] &= r.d[0];
    if constexpr (w0 > 1)
        lhs.d[1] &= r.d[1];
    if constexpr (w0 > 2)
        lhs.d[2] &= r.d[2];
    if constexpr (w0 > 3)
        lhs.d[3] &= r.d[3];

    return lhs;
}
template <int w0, int w1>
constexpr fixed_uint<w0>& operator^=(fixed_uint<w0>& lhs, fixed_uint<w1> const& rhs) noexcept
{
    fixed_uint<w0> r = fixed_uint<w0>(rhs);

    lhs.d[0] ^= r.d[0];
    if constexpr (w0 > 1)
        lhs.d[1] ^= r.d[1];
    if constexpr (w0 > 2)
        lhs.d[2] ^= r.d[2];
    if constexpr (w0 > 3)
        lhs.d[3] ^= r.d[3];

    return lhs;
}

// shift

template <int w>
constexpr fixed_uint<w> operator>>(fixed_uint<w> const& lhs, int shift) noexcept
{
    TG_ASSERT(0 <= shift && shift < (w * 64)); // similar to default types this would be UB

    if (shift == 0)
        return lhs;

    const int mod_shift = shift % 64;     // avoid ub
    const int skip = shift / 64;          // count skipped words
    const int inv_shift = 64 - mod_shift; // inverted shift

    fixed_uint<w> res;

#if 1
    if (skip == 0)
    {
        res.d[0] = lhs.d[0] >> mod_shift;
        if constexpr (w > 1)
        {
            res.d[0] |= lhs.d[1] << inv_shift;
            res.d[1] = lhs.d[1] >> mod_shift;
        }
        if constexpr (w > 2)
        {
            res.d[1] |= lhs.d[2] << inv_shift;
            res.d[2] = lhs.d[2] >> mod_shift;
        }
        if constexpr (w > 3)
        {
            res.d[2] |= lhs.d[3] << inv_shift;
            res.d[3] = lhs.d[3] >> mod_shift;
        }
    }
    else if (skip == 1)
    {
        if constexpr (w > 1)
        {
            res.d[0] = lhs.d[1] >> mod_shift;
        }
        if constexpr (w > 2)
        {
            res.d[0] |= lhs.d[2] << inv_shift;
            res.d[1] = lhs.d[2] >> mod_shift;
        }
        if constexpr (w > 3)
        {
            res.d[1] |= lhs.d[3] << inv_shift;
            res.d[2] = lhs.d[3] >> mod_shift;
        }
    }
    else if (skip == 2)
    {
        if constexpr (w > 2)
        {
            res.d[0] = lhs.d[2] >> mod_shift;
        }
        if constexpr (w > 3)
        {
            res.d[0] |= lhs.d[3] << inv_shift;
            res.d[1] = lhs.d[3] >> mod_shift;
        }
    }
    else if (skip == 3)
    {
        if constexpr (w > 3)
        {
            res.d[0] = lhs.d[3] >> mod_shift;
        }
    }
#else
    if constexpr (w == 2)
    {
        if (skip == 0)
        {
            res.d[0] = lhs.d[0] >> mod_shift;
            res.d[0] |= lhs.d[1] << inv_shift;
            res.d[1] = lhs.d[1] >> mod_shift;
        }
        else // if (skip >= 1)
        {
            res.d[0] = lhs.d[1] >> mod_shift;
        }
    }
    if constexpr (w == 3)
    {
        if (skip == 0)
        {
            res.d[0] = lhs.d[0] >> mod_shift;
            res.d[0] |= lhs.d[1] << inv_shift;
            res.d[1] = lhs.d[1] >> mod_shift;
            res.d[1] |= lhs.d[2] << inv_shift;
            res.d[2] = lhs.d[2] >> mod_shift;
        }
        if (skip == 1)
        {
            res.d[0] = lhs.d[1] >> mod_shift;
            res.d[0] |= lhs.d[2] << inv_shift;
            res.d[1] = lhs.d[2] >> mod_shift;
        }
        else // if (skip == 2)
        {
            res.d[0] = lhs.d[2] >> mod_shift;
        }
    }
    if constexpr (w == 4)
    {
        if (skip == 0)
        {
            res.d[0] = lhs.d[0] >> mod_shift;
            res.d[0] |= lhs.d[1] << inv_shift;
            res.d[1] = lhs.d[1] >> mod_shift;
            res.d[1] |= lhs.d[2] << inv_shift;
            res.d[2] = lhs.d[2] >> mod_shift;
            res.d[2] |= lhs.d[3] << inv_shift;
            res.d[3] = lhs.d[3] >> mod_shift;
        }
        if (skip == 1)
        {
            res.d[0] = lhs.d[1] >> mod_shift;
            res.d[0] |= lhs.d[2] << inv_shift;
            res.d[1] = lhs.d[2] >> mod_shift;
            res.d[1] |= lhs.d[3] << inv_shift;
            res.d[2] = lhs.d[3] >> mod_shift;
        }
        else if (skip == 2)
        {
            res.d[0] = lhs.d[2] >> mod_shift;
            res.d[0] |= lhs.d[3] << inv_shift;
            res.d[1] = lhs.d[3] >> mod_shift;
        }
        else // if (skip == 3)
        {
            res.d[0] = lhs.d[3] >> mod_shift;
        }
    }
#endif
    return res;
}

template <int w>
constexpr fixed_uint<w> operator<<(fixed_uint<w> const& lhs, int shift) noexcept
{
    TG_ASSERT(0 <= shift && shift < (w * 64)); // similar to default types this would be UB

    if (shift == 0)
        return lhs;

    const int mod_shift = shift % 64;     // avoid ub
    const int skip = shift / 64;          // count skipped words
    const int inv_shift = 64 - mod_shift; // inverted shift

    fixed_uint<w> res;

#if 1
    if (skip == 0)
    {
        res.d[0] = lhs.d[0] << mod_shift;
        if constexpr (w > 1)
        {
            res.d[1] = lhs.d[1] << mod_shift;
            res.d[1] |= lhs.d[0] >> inv_shift;
        }
        if constexpr (w > 2)
        {
            res.d[2] = lhs.d[2] << mod_shift;
            res.d[2] |= lhs.d[1] >> inv_shift;
        }
        if constexpr (w > 3)
        {
            res.d[3] = lhs.d[3] << mod_shift;
            res.d[3] |= lhs.d[2] >> inv_shift;
        }
    }
    else if (skip == 1)
    {
        if constexpr (w > 1)
        {
            res.d[1] = lhs.d[0] << mod_shift;
        }
        if constexpr (w > 2)
        {
            res.d[2] = lhs.d[1] << mod_shift;
            res.d[2] |= lhs.d[0] >> inv_shift;
        }
        if constexpr (w > 3)
        {
            res.d[3] = lhs.d[2] << mod_shift;
            res.d[3] |= lhs.d[1] >> inv_shift;
        }
    }
    else if (skip == 2)
    {
        if constexpr (w > 2)
        {
            res.d[2] = lhs.d[0] << mod_shift;
        }
        if constexpr (w > 3)
        {
            res.d[3] = lhs.d[1] << mod_shift;
            res.d[3] |= lhs.d[0] >> inv_shift;
        }
    }
    else if (skip == 3)
    {
        if constexpr (w > 3)
        {
            res.d[3] = lhs.d[0] << mod_shift;
        }
    }
#else

    if constexpr (w == 2)
    {
        if (skip == 0)
        {
            res.d[1] = lhs.d[1] << mod_shift;
            res.d[1] |= lhs.d[0] >> inv_shift;
            res.d[0] = lhs.d[0] << mod_shift;
        }
        else // if (skip >= 1)
        {
            res.d[1] = lhs.d[0] << mod_shift;
        }
    }
    if constexpr (w == 3)
    {
        if (skip == 0)
        {
            res.d[2] = lhs.d[2] << mod_shift;
            res.d[2] |= lhs.d[1] >> inv_shift;
            res.d[1] = lhs.d[1] << mod_shift;
            res.d[1] |= lhs.d[0] >> inv_shift;
            res.d[0] = lhs.d[0] << mod_shift;
        }
        if (skip == 1)
        {
            res.d[2] = lhs.d[1] << mod_shift;
            res.d[2] |= lhs.d[0] >> inv_shift;
            res.d[1] = lhs.d[0] << mod_shift;
        }
        else // if (skip == 2)
        {
            res.d[2] = lhs.d[0] << mod_shift;
        }
    }
    if constexpr (w == 4)
    {
        if (skip == 0)
        {
            res.d[3] = lhs.d[3] << mod_shift;
            res.d[3] |= lhs.d[2] >> inv_shift;
            res.d[2] = lhs.d[2] << mod_shift;
            res.d[2] |= lhs.d[1] >> inv_shift;
            res.d[1] = lhs.d[1] << mod_shift;
            res.d[1] |= lhs.d[0] >> inv_shift;
            res.d[0] = lhs.d[0] << mod_shift;
        }
        if (skip == 1)
        {
            res.d[3] = lhs.d[2] << mod_shift;
            res.d[3] |= lhs.d[1] >> inv_shift;
            res.d[2] = lhs.d[1] << mod_shift;
            res.d[2] |= lhs.d[0] >> inv_shift;
            res.d[1] = lhs.d[0] << mod_shift;
        }
        else if (skip == 2)
        {
            res.d[3] = lhs.d[1] << mod_shift;
            res.d[3] |= lhs.d[0] >> inv_shift;
            res.d[2] = lhs.d[0] << mod_shift;
        }
        else // if (count == 3)
        {
            res.d[3] = lhs.d[0] << mod_shift;
        }
    }
#endif
    return res;
}

// assignment shift

template <int w>
constexpr fixed_uint<w>& operator>>=(fixed_uint<w>& lhs, int shift) noexcept
{
    lhs = lhs >> shift;
    return lhs;
}
template <int w>
constexpr fixed_uint<w>& operator<<=(fixed_uint<w>& lhs, int shift) noexcept
{
    lhs = lhs << shift;
    return lhs;
}

} // namespace tg
