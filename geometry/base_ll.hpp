#pragma once

#include"../template/template.hpp"

namespace lib {

using vec = complex<ll>;

ll dot(const vec &a, const vec &b){
    return (conj(a) * b).real();
}

ll cross(const vec &a, const vec &b){
    return (conj(a) * b).imag();
}

// e : vec(OX)
// orthant k : [ pi/2 * k, pi/2 * (k+1) ) rad
// orthant 4 is NOT expected
int orthant(const vec &p, const vec &e = vec(1,0)){
    ll _dot = dot(e,p), _cross = cross(e,p);
    if (_dot >  0 && _cross >= 0) return 0;
    if (_dot <= 0 && _cross >  0) return 1;
    if (_dot <  0 && _cross <= 0) return 2;
    if (_dot >= 0 && _cross <  0) return 3;
    return 4;
}

// usage : 
//   vector<vec>> a;
//   sort(all(a),comp_for_argument_sort);
bool comp_for_argument_sort(const vec &lhs, const vec &rhs){
    int pl = orthant(lhs), pr = orthant(rhs);
    if (pl == pr){
        return cross(lhs,rhs) > 0;
    }
    return pl < pr;
}

} // namespace lib
