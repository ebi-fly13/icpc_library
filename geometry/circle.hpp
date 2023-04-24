#pragma once

#include "../geometry/base_ld.hpp"

namespace lib {

struct circle {
    vec c;
    ld r;
};

int intersection(const circle &c1, const circle &c2) {
    ld d = abs(c1.c - c2.c);
    ld r1 = c1.r;
    ld r2 = c2.r;
    if(r1 < r2) std::swap(r1, r2);
    if(sgn(d - (r1 + r2)) > 0) {
        return 4;
    }
    else if(sgn(d - (r1 + r2) == 0)) {
        return 3;
    }
    else if(sgn(d - r1 + r2) > 0) {
        return 2;
    }
    else if(sgn(d - r1 + r2) == 0) {
        return 1;
    }
    else return 0;
}

}