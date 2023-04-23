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

int intersection(const line &a, const line &b) {
    if(sgn(cross(a.b - a.a, b.a - b.b)) != 0) {
        if(sgn(dot(a.b - a.a, b.a - b.b)) == 0) {
            return 1;
        }
        return 0;
    }
    else if(sgn(cross(a.b - a.a, b.a - a.a)) != 0) {
        return 2;
    }
    else {
        return 3;
    }
}

}