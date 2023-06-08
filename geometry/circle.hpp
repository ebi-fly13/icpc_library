#pragma once

#include "../geometry/base_ld.hpp"
#include "../geometry/line.hpp"

namespace lib {

struct circle {
    vec c;
    ld r;
};

int intersection(const circle &c1, const circle &c2) {
    if (sgn(c1.c.real() - c2.c.real()) == 0 &&
        sgn(c1.c.imag() - c2.c.imag()) == 0 && sgn(c1.r - c2.r) == 0)
        return 5;
    ld d = abs(c1.c - c2.c);
    ld r1 = c1.r;
    ld r2 = c2.r;
    if (r1 < r2) std::swap(r1, r2);
    if (sgn(d - (r1 + r2)) > 0) {
        return 4;
    } else if (sgn(d - (r1 + r2) == 0)) {
        return 3;
    } else if (sgn(d - r1 + r2) > 0) {
        return 2;
    } else if (sgn(d - r1 + r2) == 0) {
        return 1;
    } else
        return 0;
}

circle incircle_of_triangle(const vec &a, const vec &b, const vec &c) {
    ld A = abs(b - c), B = abs(c - a), C = abs(a - b);
    vec in = A * a + B * b + C * c;
    in /= A + B + C;
    ld r = abs(cross(in - a, b - a) / abs(b - a));
    return {in, r};
}

circle circumscribed_circle_of_triangle(const vec &a, const vec &b,
                                        const vec &c) {
    line p = {(a + b) / ld(2.0), (a + b) / ld(2.0) + rot90(b - a)};
    line q = {(b + c) / ld(2.0), (b + c) / ld(2.0) + rot90(c - b)};
    vec cross = cross_point(p, q);
    return {cross, abs(a - cross)};
}

vector<vec> cross_point(const circle &c, const line &l) {
    vector<vec> ps;
    ld d = dist(l, c.c);
    if (sgn(d - c.r) == 0)
        ps.emplace_back(proj(l, c.c));
    else if (sgn(d - c.r) < 0) {
        vec p = proj(l, c.c);
        vec v = l.b - l.a;
        v *= sqrt(max(c.r * c.r - d * d, ld(0))) / abs(v);
        ps.emplace_back(p + v);
        ps.emplace_back(p - v);
    }
    return ps;
}

vector<vec> cross_point(const circle &c1, const circle &c2) {
    vector<vec> ps;
    int cnt_tangent = intersection(c1, c2);
    if (cnt_tangent == 0 || cnt_tangent == 4) return {};
    ld d = abs(c2.c - c1.c);
    ld x = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
    vec p = c1.c + (c2.c - c1.c) * x / d;
    vec v = rot90(c2.c - c1.c);
    if (cnt_tangent == 1 || cnt_tangent == 3)
        ps.emplace_back(p);
    else {
        v *= sqrt(max(c1.r * c1.r - x * x, ld(0))) / abs(v);
        ps.emplace_back(p + v);
        ps.emplace_back(p - v);
    }
    return ps;
}

ld common_area(const circle &c1, const circle &c2) {
    int flag = intersection(c1, c2);
    if (flag == 3 || flag == 4)
        return 0.0;
    else if (flag == 0 || flag == 1 || flag == 5) {
        ld r = std::min(c1.r, c2.r);
        return PI * r * r;
    } else {
        ld d = abs(c1.c - c2.c);
        ld theta1 = c1.r * c1.r + d * d - c2.r * c2.r;
        theta1 /= 2.0 * c1.r * d;
        theta1 = acos(theta1);
        ld area1 = c1.r * c1.r * theta1 - c1.r * c1.r * sin(theta1 * 2) / 2.0;
        ld theta2 = c2.r * c2.r + d * d - c1.r * c1.r;
        theta2 /= 2.0 * c2.r * d;
        theta2 = acos(theta2);
        ld area2 = c2.r * c2.r * theta2 - c2.r * c2.r * sin(theta2 * 2) / 2.0;
        return area1 + area2;
    }
}

}  // namespace lib
