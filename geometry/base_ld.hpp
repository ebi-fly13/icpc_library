#pragma once

#include "../template/template.hpp"



using vec = complex<ld>;

const ld PI = acos(-1);

void ldout(int len = 20) {
    cout << fixed << setprecision(len);
}

int sgn(ld a, const ld eps = 1e-7) {
    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;
}

bool same_vec(vec a, vec b) {
    a -= b;
    return sgn(a.real()) == 0 && sgn(a.imag()) == 0;
}

ld dot(const vec &a, const vec &b) {
    return (conj(a) * b).real();
}

ld cross(const vec &a, const vec &b) {
    return (conj(a) * b).imag();
}

int isp(const vec &a, const vec &b, const vec &c) {
    int cross_sgn = sgn(cross(b - a, c - a));
    if (cross_sgn == 0) {
        if (sgn(dot(b - a, c - a)) < 0) return -2;
        if (sgn(dot(a - b, c - b)) < 0) return 2;
    }
    return cross_sgn;
}

vec rot90(const vec &a) {
    return {-a.imag(), a.real()};
}

vec rot(const vec &a, ld rad) {
    return a * vec(cosl(rad), sinl(rad));
}

bool comp_for_argument_sort(const vec &lhs, const vec &rhs) {
    // if (abs(arg(lhs)-arg(rhs)) < eps) return false; // need ?
    return arg(lhs) < arg(rhs);
}


