---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry3D/accurate/base_accurate.hpp
    title: base_accurate
  - icon: ':warning:'
    path: geometry3D/base_arbitary.hpp
    title: geometry3D/base_arbitary.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: utility/rational.hpp
    title: utility/rational.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry3D/accurate/line.hpp\"\n\n#line 2 \"geometry3D/accurate/base_accurate.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"geometry3D/base_arbitary.hpp\"\n\n#line 4 \"geometry3D/base_arbitary.hpp\"\
    \n\nnamespace lib {\n\ntemplate<typename T>\nstruct Vec {\n    T x, y, z;\n  \
    \  Vec (T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {}\n    Vec& operator*=(const\
    \ T& a){\n        x *= a;\n        y *= a;\n        z *= a;\n        return *this;\n\
    \    }\n    Vec& operator/=(const T& a){\n        x /= a;\n        y /= a;\n \
    \       z /= a;\n        return *this;\n    }\n    Vec& operator+=(const Vec&\
    \ rhs) {\n        x += rhs.x;\n        y += rhs.y;\n        z += rhs.z;\n    \
    \    return *this;\n    }\n    Vec& operator-=(const Vec& rhs) {\n        x -=\
    \ rhs.x;\n        y -= rhs.y;\n        z -= rhs.z;\n        return *this;\n  \
    \  }\n    friend Vec operator+(const Vec& lhs, const Vec& rhs) {\n        return\
    \ Vec(lhs) += rhs;\n    }\n    friend Vec operator-(const Vec& lhs, const Vec&\
    \ rhs) {\n        return Vec(lhs) -= rhs;\n    }\n    friend Vec operator*(const\
    \ Vec& lhs, const T& rhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend\
    \ Vec operator*(const T& rhs, const Vec& lhs) {\n        return Vec(lhs) *= rhs;\n\
    \    }\n    friend Vec operator/(const Vec& lhs, const T& rhs) {\n        return\
    \ Vec(lhs) /= rhs;\n    }\n    friend std::ostream &operator<<(std::ostream &os,const\
    \ Vec&r) {\n        return os << \"(\" << r.x << \",\" << r.y << \",\" << r.z\
    \ << \")\"; \n    }\n};\n\n};\n#line 5 \"geometry3D/accurate/base_accurate.hpp\"\
    \n\nnamespace lib {\n\ntemplate<typename T>\nbool operator==(const Vec<T>& lhs,\
    \ const Vec<T>& rhs) {\n    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z ==\
    \ rhs.z;\n}\n\ntemplate<typename T>\nT dot(const Vec<T> &a, const Vec<T> &b){\n\
    \    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n\ntemplate<typename T>\nVec<T> cross(const\
    \ Vec<T> &a, const Vec<T> &b){\n    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z,\
    \ a.x*b.y-a.y*b.x);\n}\n\ntemplate<typename T>\nT norm(const Vec<T> &a){\n   \
    \ return a.x*a.x+a.y*a.y+a.z*a.z;\n}\n\n}  // namespace lib\n#line 2 \"utility/rational.hpp\"\
    \n\n#line 4 \"utility/rational.hpp\"\n\nnamespace lib {\n\nstruct rational {\n\
    \    rational() : p(0), q(1) {}\n    rational(ll n) : p(n), q(1) {}\n    rational(ll\
    \ n, ll m) {\n        assert(m != 0);\n        if (m < 0) n = -n, m = -m;\n  \
    \      ll g = gcd(n, m);\n        p = n / g;\n        q = m / g;\n    }\n    explicit\
    \ operator const ld () const { return ld(p) / ld(q); }\n    rational& operator+=(const\
    \ rational& rhs){\n        ll g = gcd(q, rhs.q);\n        ll np = rhs.q / g *\
    \ p + q / g * rhs.p;\n        ll nq = q / g * rhs.q;\n        ll ng = gcd(np,\
    \ nq);\n        p = np / ng, q = nq / ng;\n        return *this;\n    }\n    rational&\
    \ operator-=(const rational& rhs) {\n        (*this) += rational(-rhs.p, rhs.q);\n\
    \        return *this;\n    }\n    rational& operator*=(const rational& rhs) {\n\
    \        ll g1 = gcd(q, rhs.p), g2 = gcd(p, rhs.q);\n        ll np = p / g2 *\
    \ rhs.p / g1;\n        ll nq = q / g1 * rhs.q / g2;\n        p = np, q = nq;\n\
    \        return *this;\n    }\n    rational& operator/=(const rational& rhs) {\n\
    \        (*this) *= rational(rhs.q, rhs.p);\n        return *this;\n    }\n  \
    \  rational operator+() const {\n        return *this;\n    }\n    rational operator-()\
    \ const {\n        return rational() - *this;\n    }\n    friend rational operator+(const\
    \ rational& lhs, const rational& rhs) {\n        return rational(lhs) += rhs;\n\
    \    }\n    friend rational operator-(const rational& lhs, const rational& rhs)\
    \ {\n        return rational(lhs) -= rhs;\n    }\n    friend rational operator*(const\
    \ rational& lhs, const rational& rhs) {\n        return rational(lhs) *= rhs;\n\
    \    }\n    friend rational operator/(const rational& lhs, const rational& rhs)\
    \ {\n        return rational(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ rational& lhs, const rational& rhs) {\n        return lhs.p == rhs.p && lhs.q\
    \ == rhs.q;\n    }\n    friend bool operator!=(const rational& lhs, const rational&\
    \ rhs) {\n        return lhs.p != rhs.p || lhs.q != rhs.q;\n    }\n    friend\
    \ bool operator<(const rational lhs, const rational rhs) {\n        return less_than(lhs,\
    \ rhs);\n    }\n    friend bool operator>(const rational lhs, const rational rhs)\
    \ {\n        return less_than(rhs, lhs);\n    }\n    friend bool operator<=(const\
    \ rational lhs, const rational rhs) {\n        return lhs == rhs || lhs < rhs;\n\
    \    }\n    friend bool operator>=(const rational lhs, const rational rhs) {\n\
    \        return lhs == rhs || lhs > rhs;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const rational& r) {\n        return os << r.p << \" / \" << r.q;\n    }\n\
    \    std::pair<ll,ll> val() const {\n        return {p, q};\n    }\n\n  private:\n\
    \    ll p, q;\n    static bool less_than(rational lhs, rational rhs) {\n     \
    \   __int128_t lv = __int128_t(lhs.p) * __int128_t(rhs.q);\n        __int128_t\
    \ rv = __int128_t(lhs.q) * __int128_t(rhs.p);\n        return lv < rv;\n    }\n\
    };\n\n}  // namespace lib\n#line 5 \"geometry3D/accurate/line.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate<typename T>\nstruct Line {\n    Vec<T> a, b;\n};\n\nint intersection(const\
    \ Line<rational> &p, const Line<rational> &q){\n    // cross_point = alpha * p.a\
    \ + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a\n    // alpha * vp + beta *\
    \ vq = vr\n    using vec = Vec<rational>;\n    vec vp = p.a - p.b, vq = q.a -\
    \ q.b, vr = q.a - p.b;\n    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq =\
    \ cross(vr,vq);\n    // yz projection\n    if (cpq.x != 0){\n        rational\
    \ alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;\n        // cross\n        if (alpha\
    \ * vp.x + beta * vq.x - vr.x == 0){\n            return 0;\n        }\n     \
    \   // nejire\n        return 1;\n    }\n    // zx projection\n    if (cpq.y !=\
    \ 0){\n        rational alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;\n       \
    \ // cross\n        if (alpha * vp.y + beta * vq.y - vr.y == 0){\n           \
    \ return 0;\n        }\n        // nejire\n        return 1;\n    }\n    // xy\
    \ projection\n    if (cpq.z != 0){\n        rational alpha = crq.z / cpq.z, beta\
    \ = cpr.z / cpq.z;\n        // cross\n        if (alpha * vp.z + beta * vq.z -\
    \ vr.z == 0){\n            return 0;\n        }\n        // nejire\n        return\
    \ 1;\n    }\n    // cpq == 0  ->  parallel\n    // same\n    if (cross(p.a - q.a,\
    \ p.b - q.a) == vec(0,0,0)){\n        return 3;\n    }\n    // not same\n    return\
    \ 2;\n}\n\nVec<rational> cross_point(const Line<rational> &p, const Line<rational>\
    \ &q){\n    assert(intersection(p,q) == 0);\n    // cross_point = alpha * p.a\
    \ + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a\n    // alpha * vp + beta *\
    \ vq = vr\n    using vec = Vec<rational>;\n    vec vp = p.a - p.b, vq = q.a -\
    \ q.b, vr = q.a - p.b;\n    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq =\
    \ cross(vr,vq);\n    auto res = [&](rational alpha){\n        return alpha * p.a\
    \ + (1-alpha) * p.b;\n    };\n    // yz projection\n    if (cpq.x != 0){\n   \
    \     rational alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;\n        // cross\n\
    \        if (alpha * vp.x + beta * vq.x - vr.x == 0){\n            return res(alpha);\n\
    \        }\n    }\n    // zx projection\n    if (cpq.y != 0){\n        rational\
    \ alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;\n        // cross\n        if (alpha\
    \ * vp.y + beta * vq.y - vr.y == 0){\n            return res(alpha);\n       \
    \ }\n    }\n    // xy projection\n    if (cpq.z != 0){\n        rational alpha\
    \ = crq.z / cpq.z, beta = cpr.z / cpq.z;\n        // cross\n        if (alpha\
    \ * vp.z + beta * vq.z - vr.z == 0){\n            return res(alpha);\n       \
    \ }\n    }\n    // NOT expected\n    return vec();\n}\n\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"base_accurate.hpp\"\n#include \"../../utility/rational.hpp\"\
    \n\nnamespace lib {\n\ntemplate<typename T>\nstruct Line {\n    Vec<T> a, b;\n\
    };\n\nint intersection(const Line<rational> &p, const Line<rational> &q){\n  \
    \  // cross_point = alpha * p.a + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a\n\
    \    // alpha * vp + beta * vq = vr\n    using vec = Vec<rational>;\n    vec vp\
    \ = p.a - p.b, vq = q.a - q.b, vr = q.a - p.b;\n    vec cpq = cross(vp,vq), cpr\
    \ = cross(vp,vr), crq = cross(vr,vq);\n    // yz projection\n    if (cpq.x !=\
    \ 0){\n        rational alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;\n       \
    \ // cross\n        if (alpha * vp.x + beta * vq.x - vr.x == 0){\n           \
    \ return 0;\n        }\n        // nejire\n        return 1;\n    }\n    // zx\
    \ projection\n    if (cpq.y != 0){\n        rational alpha = crq.y / cpq.y, beta\
    \ = cpr.y / cpq.y;\n        // cross\n        if (alpha * vp.y + beta * vq.y -\
    \ vr.y == 0){\n            return 0;\n        }\n        // nejire\n        return\
    \ 1;\n    }\n    // xy projection\n    if (cpq.z != 0){\n        rational alpha\
    \ = crq.z / cpq.z, beta = cpr.z / cpq.z;\n        // cross\n        if (alpha\
    \ * vp.z + beta * vq.z - vr.z == 0){\n            return 0;\n        }\n     \
    \   // nejire\n        return 1;\n    }\n    // cpq == 0  ->  parallel\n    //\
    \ same\n    if (cross(p.a - q.a, p.b - q.a) == vec(0,0,0)){\n        return 3;\n\
    \    }\n    // not same\n    return 2;\n}\n\nVec<rational> cross_point(const Line<rational>\
    \ &p, const Line<rational> &q){\n    assert(intersection(p,q) == 0);\n    // cross_point\
    \ = alpha * p.a + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a\n    // alpha\
    \ * vp + beta * vq = vr\n    using vec = Vec<rational>;\n    vec vp = p.a - p.b,\
    \ vq = q.a - q.b, vr = q.a - p.b;\n    vec cpq = cross(vp,vq), cpr = cross(vp,vr),\
    \ crq = cross(vr,vq);\n    auto res = [&](rational alpha){\n        return alpha\
    \ * p.a + (1-alpha) * p.b;\n    };\n    // yz projection\n    if (cpq.x != 0){\n\
    \        rational alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;\n        // cross\n\
    \        if (alpha * vp.x + beta * vq.x - vr.x == 0){\n            return res(alpha);\n\
    \        }\n    }\n    // zx projection\n    if (cpq.y != 0){\n        rational\
    \ alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;\n        // cross\n        if (alpha\
    \ * vp.y + beta * vq.y - vr.y == 0){\n            return res(alpha);\n       \
    \ }\n    }\n    // xy projection\n    if (cpq.z != 0){\n        rational alpha\
    \ = crq.z / cpq.z, beta = cpr.z / cpq.z;\n        // cross\n        if (alpha\
    \ * vp.z + beta * vq.z - vr.z == 0){\n            return res(alpha);\n       \
    \ }\n    }\n    // NOT expected\n    return vec();\n}\n\n\n}  // namespace lib"
  dependsOn:
  - geometry3D/accurate/base_accurate.hpp
  - template/template.hpp
  - geometry3D/base_arbitary.hpp
  - utility/rational.hpp
  isVerificationFile: false
  path: geometry3D/accurate/line.hpp
  requiredBy: []
  timestamp: '2023-06-29 23:31:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry3D/accurate/line.hpp
layout: document
redirect_from:
- /library/geometry3D/accurate/line.hpp
- /library/geometry3D/accurate/line.hpp.html
title: geometry3D/accurate/line.hpp
---
