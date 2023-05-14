#pragma once

#include "base_ld.hpp"

namespace lib {


struct line {
    vec a, b;
};

vec proj(const line &l, const vec &p) {
    vec ab = l.b - l.a;
    return l.a + ab * (dot(ab, p - l.a) / norm(ab));
}

vec refl(const line &l, const vec &p) { return proj(l, p) * ld(2) - p; }

/*

ato de kaku

int intersection(const line &a, const line &b)

ld dist(const line &a, const vec &p)

vec cross_point(const line &a, const line &b)

*/


}  // namespace lib