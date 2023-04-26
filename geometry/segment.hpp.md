---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: line
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Point.test.cpp
    title: test/geometry/Cross_Point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Distance.test.cpp
    title: test/geometry/Distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Intersection.test.cpp
    title: test/geometry/Intersection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/segment.hpp\"\n\n#line 2 \"geometry/line.hpp\"\n\
    \n#line 2 \"geometry/base_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\
    \n#define rep(i,s,n) for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for\
    \ (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \ntemplate<typename T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T &a, const\
    \ T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace\
    \ lib{\n\nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n\
    #line 4 \"geometry/base_ld.hpp\"\n\nnamespace lib {\n\nusing vec = complex<ld>;\n\
    const ld eps = 1e-7;\n\nvoid ldout(int len = 20){\n    cout << fixed << setprecision(len);\n\
    }\n\nint sgn(ld a) {\n    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nld\
    \ dot(const vec &a, const vec &b){\n    return (conj(a) * b).real();\n}\n\nld\
    \ cross(const vec &a, const vec &b){\n    return (conj(a) * b).imag();\n}\n\n\
    int isp(const vec &a, const vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b\
    \ - a, c - a));\n    if(cross_sgn == 0) {\n        if(sgn(dot(b - a, c - a)) <\
    \ 0) return -2;\n        if(sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n   \
    \ return cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return {-a.imag(), a.real()};\n\
    }\n\nvec rot(const vec &a, ld rad){\n    return a * vec(cosl(rad),sinl(rad));\n\
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs))\
    \ < eps) return false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace\
    \ lib\n#line 4 \"geometry/line.hpp\"\n\nnamespace lib {\n\nstruct line {\n   \
    \ vec a, b;\n};\n\nvec proj(const line &l, const vec &p) {\n    vec ab = l.b -\
    \ l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n}\n\nvec refl(const\
    \ line &l, const vec &p) {\n    return proj(l, p) * ld(2) - p;\n}\n\nint intersection(const\
    \ line &a, const line &b) {\n    if(sgn(cross(a.b - a.a, b.a - b.b)) != 0) {\n\
    \        if(sgn(dot(a.b - a.a, b.a - b.b)) == 0) {\n            return 1;\n  \
    \      }\n        return 0;\n    }\n    else if(sgn(cross(a.b - a.a, b.a - a.a))\
    \ != 0) {\n        return 2;\n    }\n    else {\n        return 3;\n    }\n}\n\
    \nld dist(const line &a, const vec &p) {\n    return abs(cross(p - a.a, a.b -\
    \ a.a) / abs(a.b - a.a));\n}\n\nvec cross_point(const line &a, const line &b)\
    \ {\n    assert(intersection(a, b) < 2);\n    return a.a + (a.b - a.a) * cross(b.a\
    \ - a.a, b.b - b.a) / cross(a.b - a.a, b.b - b.a);\n}\n\n}\n#line 4 \"geometry/segment.hpp\"\
    \n\nnamespace lib {\n\nstruct segment : line {};\n\nbool intersection_segment(const\
    \ segment &a, const segment &b, bool bound = true) {\n    if(sgn(isp(a.a, a.b,\
    \ b.a) * isp(a.a, a.b, b.b)) < int(bound) && sgn(isp(b.a, b.b, a.a) * isp(b.a,\
    \ b.b, a.b)) < int(bound)) {\n        return true;\n    }\n    else return false;\n\
    }\n\nvec cross_point(const segment &a, const segment &b) {\n    assert(intersection_segment(a,\
    \ b, true));\n    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) / cross(a.b\
    \ - a.a, b.b - b.a);\n}\n\nld dist(const segment &a, const vec &c) {\n    if(sgn(dot(a.b\
    \ - a.a, c - a.a)) < 0) {\n        return abs(c-a.a);\n    }\n    else if(sgn(dot(a.a\
    \ - a.b, c - a.b)) < 0) {\n        return abs(c-a.b);\n    }\n    else {\n   \
    \     return abs(cross(c - a.a, a.b - a.a)/abs(a.b-a.a));\n    }\n}\n\nld dist(const\
    \ segment &a, const segment &b) {\n    if(intersection_segment(a, b, true)) return\
    \ 0;\n    else return min(min(dist(a, b.a), dist(a, b.b)), min(dist(b, a.a), dist(b,\
    \ a.b)));\n}\n\n}\n"
  code: "#pragma once\n\n#include \"../geometry/line.hpp\"\n\nnamespace lib {\n\n\
    struct segment : line {};\n\nbool intersection_segment(const segment &a, const\
    \ segment &b, bool bound = true) {\n    if(sgn(isp(a.a, a.b, b.a) * isp(a.a, a.b,\
    \ b.b)) < int(bound) && sgn(isp(b.a, b.b, a.a) * isp(b.a, b.b, a.b)) < int(bound))\
    \ {\n        return true;\n    }\n    else return false;\n}\n\nvec cross_point(const\
    \ segment &a, const segment &b) {\n    assert(intersection_segment(a, b, true));\n\
    \    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) / cross(a.b - a.a,\
    \ b.b - b.a);\n}\n\nld dist(const segment &a, const vec &c) {\n    if(sgn(dot(a.b\
    \ - a.a, c - a.a)) < 0) {\n        return abs(c-a.a);\n    }\n    else if(sgn(dot(a.a\
    \ - a.b, c - a.b)) < 0) {\n        return abs(c-a.b);\n    }\n    else {\n   \
    \     return abs(cross(c - a.a, a.b - a.a)/abs(a.b-a.a));\n    }\n}\n\nld dist(const\
    \ segment &a, const segment &b) {\n    if(intersection_segment(a, b, true)) return\
    \ 0;\n    else return min(min(dist(a, b.a), dist(a, b.b)), min(dist(b, a.a), dist(b,\
    \ a.b)));\n}\n\n}"
  dependsOn:
  - geometry/line.hpp
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: false
  path: geometry/segment.hpp
  requiredBy: []
  timestamp: '2023-04-26 17:21:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/Cross_Point.test.cpp
  - test/geometry/Distance.test.cpp
  - test/geometry/Intersection.test.cpp
documentation_of: geometry/segment.hpp
layout: document
title: segment
---

## 説明

平面での線分の各種操作

### segment

線分の端点 $a$, $b$ を持つ

### intersection_segment(segment a, segment b, bool bound = true)

線分 $a$, $b$ が交わるか判定。boundがtrueのとき端点を含む。falseのとき端点を含まない。

### cross_point(segment a, segment b)

線分 $a$, $b$ の交点を返す。

### distance(segment a, vec c)

線分 $a$ と点 $c$ の距離を返す。

### distance(segment a, segment b)

線分 $a$, $b$ の距離を返す。