#pragma once

#include "../geometry/line.hpp"



struct segment : line {};

bool intersection_segment_and_vec(const segment &a, const vec &p) {
    return isp(a.a, a.a, p) == 0;
}

bool intersection_segment(const segment &a, const segment &b) {
    if (sgn(isp(a.a, a.b, b.a) * isp(a.a, a.b, b.b)) <= 0 &&
        sgn(isp(b.a, b.b, a.a) * isp(b.a, b.b, a.b)) <= 0) {
        return true;
    } else
        return false;
}

vec cross_point(const segment &a, const segment &b) {
    assert(intersection_segment(a, b));
    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) /
                     cross(a.b - a.a, b.b - b.a);
}

ld dist(const segment &a, const vec &c) {
    if (sgn(dot(a.b - a.a, c - a.a)) <= 0) {
        return abs(c - a.a);
    } else if (sgn(dot(a.a - a.b, c - a.b)) <= 0) {
        return abs(c - a.b);
    } else {
        return abs(cross(c - a.a, a.b - a.a) / abs(a.b - a.a));
    }
}

ld dist(const segment &a, const segment &b) {
    if (intersection_segment(a, b))
        return 0;
    else
        return min(min(dist(a, b.a), dist(a, b.b)),
                   min(dist(b, a.a), dist(b, a.b)));
}


