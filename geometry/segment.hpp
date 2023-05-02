#pragma once

#include "../geometry/line.hpp"

namespace lib {

struct segment : line {};

bool intersection_segment(const segment &a, const segment &b, bool bound = true) {
    if(sgn(isp(a.a, a.b, b.a) * isp(a.a, a.b, b.b)) < int(bound) && sgn(isp(b.a, b.b, a.a) * isp(b.a, b.b, a.b)) < int(bound)) {
        return true;
    }
    else return false;
}

vec cross_point(const segment &a, const segment &b) {
    assert(intersection_segment(a, b, true));
    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) / cross(a.b - a.a, b.b - b.a);
}

ld dist(const segment &a, const vec &c) {
    if(sgn(dot(a.b - a.a, c - a.a)) <= 0) {
        return abs(c-a.a);
    }
    else if(sgn(dot(a.a - a.b, c - a.b)) <= 0) {
        return abs(c-a.b);
    }
    else {
        return abs(cross(c - a.a, a.b - a.a)/abs(a.b-a.a));
    }
}

ld dist(const segment &a, const segment &b) {
    if(intersection_segment(a, b, true)) return 0;
    else return min(min(dist(a, b.a), dist(a, b.b)), min(dist(b, a.a), dist(b, a.b)));
}

}