#pragma once

#include "../geometry/base_ld.hpp"

namespace lib {

struct line {
    vec a, b;
};

vec proj(const line &l, const vec &p) {
    vec ab = l.b - l.a;
    return l.a + ab * (dot(ab, p - l.a) / norm(ab));
}

vec refl(const line &l, const vec &p) {
    return proj(l, p) * ld(2) - p;
}

}