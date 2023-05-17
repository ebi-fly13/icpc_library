#pragma once

#include "base_accurate.hpp"
#include "../../utility/rational.hpp"

namespace lib {

template<typename T>
struct Line {
    Vec<T> a, b;
};

int intersection(const Line<rational> &p, const Line<rational> &q){
    // cross_point = alpha * p.a + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a
    // alpha * vp + beta * vq = vr
    using vec = Vec<rational>;
    vec vp = p.a - p.b, vq = q.a - q.b, vr = q.a - p.b;
    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq = cross(vr,vq);
    // yz projection
    if (cpq.x != 0){
        rational alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;
        // cross
        if (alpha * vp.x + beta * vq.x - vr.x == 0){
            return 0;
        }
        // nejire
        return 1;
    }
    // zx projection
    if (cpq.y != 0){
        rational alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;
        // cross
        if (alpha * vp.y + beta * vq.y - vr.y == 0){
            return 0;
        }
        // nejire
        return 1;
    }
    // xy projection
    if (cpq.z != 0){
        rational alpha = crq.z / cpq.z, beta = cpr.z / cpq.z;
        // cross
        if (alpha * vp.z + beta * vq.z - vr.z == 0){
            return 0;
        }
        // nejire
        return 1;
    }
    // cpq == 0  ->  parallel
    // same
    if (cross(p.a - q.a, p.b - q.a) == vec(0,0,0)){
        return 3;
    }
    // not same
    return 2;
}

Vec<rational> cross_point(const Line<rational> &p, const Line<rational> &q){
    assert(intersection(p,q) == 0);
    // cross_point = alpha * p.a + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a
    // alpha * vp + beta * vq = vr
    using vec = Vec<rational>;
    vec vp = p.a - p.b, vq = q.a - q.b, vr = q.a - p.b;
    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq = cross(vr,vq);
    auto res = [&](rational alpha){
        return alpha * p.a + (1-alpha) * p.b;
    };
    // yz projection
    if (cpq.x != 0){
        rational alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;
        // cross
        if (alpha * vp.x + beta * vq.x - vr.x == 0){
            return res(alpha);
        }
    }
    // zx projection
    if (cpq.y != 0){
        rational alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;
        // cross
        if (alpha * vp.y + beta * vq.y - vr.y == 0){
            return res(alpha);
        }
    }
    // xy projection
    if (cpq.z != 0){
        rational alpha = crq.z / cpq.z, beta = cpr.z / cpq.z;
        // cross
        if (alpha * vp.z + beta * vq.z - vr.z == 0){
            return res(alpha);
        }
    }
    // NOT expected
    return vec();
}


}  // namespace lib