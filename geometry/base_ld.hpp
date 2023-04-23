#pragma once

#include"../template/template.hpp"

namespace lib {

using vec = complex<ld>;
const ld eps = 1e-7;

ld dot(const vec &a, const vec &b){
    return (conj(a) * b).real();
}

ld cross(const vec &a, const vec &b){
    return (conj(a) * b).imag();
}

bool comp_for_argument_sort(const vec &lhs, const vec &rhs){
    //if (abs(arg(lhs)-arg(rhs)) < eps) return false; // need ?
    return arg(lhs) < arg(rhs);
}

} // namespace lib
