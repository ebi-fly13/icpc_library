---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: segment
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
  - icon: ':heavy_check_mark:'
    path: test/geometry/Parallel_Orthogonal.test.cpp
    title: test/geometry/Parallel_Orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Projection.test.cpp
    title: test/geometry/Projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Reflection.test.cpp
    title: test/geometry/Reflection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/base_ld.hpp\"\n\
    \n#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n)\
    \ for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1;\
    \ i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\n\
    using ld = long double;\nusing ull = unsigned long long;\n\ntemplate<typename\
    \ T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n\
    \    return true;\n}\ntemplate<typename T> bool chmax(T &a, const T &b){\n   \
    \ if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib{\n\
    \nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n#line\
    \ 4 \"geometry/base_ld.hpp\"\n\nnamespace lib {\n\nusing vec = complex<ld>;\n\
    const ld eps = 1e-7;\n\nint sgn(ld a) {\n    return (a < -eps) ? -1 : (a > eps)\
    \ ? 1 : 0;\n}\n\nld dot(const vec &a, const vec &b){\n    return (conj(a) * b).real();\n\
    }\n\nld cross(const vec &a, const vec &b){\n    return (conj(a) * b).imag();\n\
    }\n\nint isp(const vec &a, const vec &b, const vec &c) {\n    int cross_sgn =\
    \ sgn(cross(b - a, c - a));\n    if(cross_sgn == 0) {\n        if(sgn(dot(b -\
    \ a, c - a)) < 0) return -2;\n        if(sgn(dot(a - b, c - b)) < 0) return 2;\n\
    \    }\n    return cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return {-a.imag(),\
    \ a.real()};\n}\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n\
    \    //if (abs(arg(lhs)-arg(rhs)) < eps) return false; // need ?\n    return arg(lhs)\
    \ < arg(rhs);\n}\n\n} // namespace lib\n#line 4 \"geometry/line.hpp\"\n\nnamespace\
    \ lib {\n\nstruct line {\n    vec a, b;\n};\n\nvec proj(const line &l, const vec\
    \ &p) {\n    vec ab = l.b - l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n\
    }\n\nvec refl(const line &l, const vec &p) {\n    return proj(l, p) * ld(2) -\
    \ p;\n}\n\nint intersection(const line &a, const line &b) {\n    if(sgn(cross(a.b\
    \ - a.a, b.a - b.b)) != 0) {\n        if(sgn(dot(a.b - a.a, b.a - b.b)) == 0)\
    \ {\n            return 1;\n        }\n        return 0;\n    }\n    else if(sgn(cross(a.b\
    \ - a.a, b.a - a.a)) != 0) {\n        return 2;\n    }\n    else {\n        return\
    \ 3;\n    }\n}\n\nld distance(const line &a, const vec &p) {\n    return abs(cross(p\
    \ - a.a, a.b - a.a) / abs(a.b - a.a));\n}\n\nvec cross_point(const line &a, const\
    \ line &b) {\n    assert(intersection(a, b) < 2);\n    return a.a + (a.b - a.a)\
    \ * cross(b.a - a.a, b.b - b.a) / cross(a.b - a.a, b.b - b.a);\n}\n\n}\n"
  code: "#pragma once\n\n#include \"../geometry/base_ld.hpp\"\n\nnamespace lib {\n\
    \nstruct line {\n    vec a, b;\n};\n\nvec proj(const line &l, const vec &p) {\n\
    \    vec ab = l.b - l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n\
    }\n\nvec refl(const line &l, const vec &p) {\n    return proj(l, p) * ld(2) -\
    \ p;\n}\n\nint intersection(const line &a, const line &b) {\n    if(sgn(cross(a.b\
    \ - a.a, b.a - b.b)) != 0) {\n        if(sgn(dot(a.b - a.a, b.a - b.b)) == 0)\
    \ {\n            return 1;\n        }\n        return 0;\n    }\n    else if(sgn(cross(a.b\
    \ - a.a, b.a - a.a)) != 0) {\n        return 2;\n    }\n    else {\n        return\
    \ 3;\n    }\n}\n\nld distance(const line &a, const vec &p) {\n    return abs(cross(p\
    \ - a.a, a.b - a.a) / abs(a.b - a.a));\n}\n\nvec cross_point(const line &a, const\
    \ line &b) {\n    assert(intersection(a, b) < 2);\n    return a.a + (a.b - a.a)\
    \ * cross(b.a - a.a, b.b - b.a) / cross(a.b - a.a, b.b - b.a);\n}\n\n}"
  dependsOn:
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - geometry/segment.hpp
  timestamp: '2023-04-24 18:42:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/Cross_Point.test.cpp
  - test/geometry/Parallel_Orthogonal.test.cpp
  - test/geometry/Distance.test.cpp
  - test/geometry/Projection.test.cpp
  - test/geometry/Reflection.test.cpp
  - test/geometry/Intersection.test.cpp
documentation_of: geometry/line.hpp
layout: document
title: line
---

## 説明

平面での直線の各種操作

### line

直線の2点を持つ

### proj(line l, vec p)

直線 $l$ に点 $p$ から垂線を引いたときの交点 $x$ を返す。

### refl(line l, vec p)

直線 $l$ を対象軸として点 $p$ を線対象に移動させた点 $x$ を返す。

### intersection(line a, line b)

直線 $a$, $b$ の関係を返す。

- 交差 $0$
- 垂直 $1$
- 平行 $2$
- 同一直線 $3$

### distance(line a, vec p)

直線 $a$ と点 $p$ の距離を返す。

### cross_point(line a, line b)

直線 $a$, $b$ の交点を返す。