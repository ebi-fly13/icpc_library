#pragma once

#include "../../template/template.hpp"
#include "../base_arbitary.hpp"

namespace lib {

using vec = Vec<ld>;
const ld eps = 1e-7;

void ldout(int len = 20) { cout << fixed << setprecision(len); }

int sgn(ld a) { return (a < -eps) ? -1 : (a > eps) ? 1 : 0; }

ld dot(const vec &a, const vec &b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec cross(const vec &a, const vec &b){
    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

ld norm(const vec &a){
    return a.x*a.x+a.y*a.y+a.z*a.z;
}

ld abs(const vec &a){
    return sqrtl(norm(a));
}


}  // namespace lib
