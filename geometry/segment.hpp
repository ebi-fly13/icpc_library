#pragma once

#include "../geometry/line.hpp"

namespace lib {

struct segment : line {};

bool intersection(const segment &a, const segment &b, bool bound) {
    if(sgn(isp(a.a, a.b, b.a) * isp(a.a, a.b, b.b)) < int(bound) && sgn(isp(b.a, b.b, a.a) * isp(b.a, b.b, a.b)) < int(bound)) {
        return true;
    }
    else return false;
}

}