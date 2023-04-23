#pragma once

#include "../geometry/line.hpp"

namespace lib {

struct segment : line {};

bool intersection(const segment &a, const segment &b, bool bound = true) {
    if(sgn(isp(a.a, a.b, b.a) * isp(a.a, a.b, b.b)) < int(bound) && sgn(isp(b.a, b.b, a.a) * isp(b.a, b.b, a.b)) < int(bound)) {
        return true;
    }
    else return false;
}

vec cross_point(const segment &a, const segment &b) {
    assert(intersection(a, b, true));
    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) / cross(a.b - a.a, b.b - b.a);
}

}