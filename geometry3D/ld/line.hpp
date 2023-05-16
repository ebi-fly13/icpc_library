#pragma once

#include "base_ld.hpp"

namespace lib {

struct line {
    vec a, b;
};

vec proj(const line &l, const vec &p) {
    vec ab = l.b - l.a;
    return l.a + ab * (dot(ab, p - l.a) / norm(ab));
}

vec refl(const line &l, const vec &p) { return proj(l, p) * ld(2) - p; }

int intersection(const line &p, const line &q){
    // cross_point = alpha * p.a + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a
    // alpha * vp + beta * vq = vr
    vec vp = p.a - p.b, vq = q.a - q.b, vr = q.a - p.b;
    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq = cross(vr,vq);
    // yz projection
    if (sgn(cpq.x) != 0){
        ld alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;
        // cross
        if (sgn(abs(alpha * vp.x + beta * vq.x - vr.x)) == 0){
            return 0;
        }
        // nejire
        return 1;
    }
    // zx projection
    if (sgn(cpq.y) != 0){
        ld alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;
        // cross
        if (sgn(abs(alpha * vp.y + beta * vq.y - vr.y)) == 0){
            return 0;
        }
        // nejire
        return 1;
    }
    // xy projection
    if (sgn(cpq.z) != 0){
        ld alpha = crq.z / cpq.z, beta = cpr.z / cpq.z;
        // cross
        if (sgn(abs(alpha * vp.z + beta * vq.z - vr.z)) == 0){
            return 0;
        }
        // nejire
        return 1;
    }
    // cpq == 0  ->  parallel
    // same
    if (sgn(abs(cross(p.a - q.a, p.b - q.a))) == 0){
        return 3;
    }
    // not same
    return 2;
}

ld dist(const line &l, const vec &p){
    return abs(p - proj(l,p));
}

vec cross_point(const line &p, const line &q){
    assert(intersection(p,q) == 0);
    // cross_point = alpha * p.a + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a
    // alpha * vp + beta * vq = vr
    vec vp = p.a - p.b, vq = q.a - q.b, vr = q.a - p.b;
    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq = cross(vr,vq);
    auto res = [&](ld alpha){
        return alpha * p.a + (1-alpha) * p.b;
    };
    // yz projection
    if (sgn(cpq.x) != 0){
        ld alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;
        // cross
        if (sgn(abs(alpha * vp.x + beta * vq.x - vr.x)) == 0){
            return res(alpha);
        }
    }
    // zx projection
    if (sgn(cpq.y) != 0){
        ld alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;
        // cross
        if (sgn(abs(alpha * vp.y + beta * vq.y - vr.y)) == 0){
            return res(alpha);
        }
    }
    // xy projection
    if (sgn(cpq.z) != 0){
        ld alpha = crq.z / cpq.z, beta = cpr.z / cpq.z;
        // cross
        if (sgn(abs(alpha * vp.z + beta * vq.z - vr.z)) == 0){
            return res(alpha);
        }
    }
    // NOT expected
    return vec();
}


}  // namespace lib