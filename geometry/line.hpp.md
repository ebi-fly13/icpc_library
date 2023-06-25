---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: circle
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: segment
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/Circumscribed_Circle_of_Triangle.test.cpp
    title: test/geometry/Circumscribed_Circle_of_Triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Common_Area_Circles.test.cpp
    title: test/geometry/Common_Area_Circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Convex_Hull.test.cpp
    title: test/geometry/Convex_Hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Point.test.cpp
    title: test/geometry/Cross_Point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Points_of_Circle_and_Line.test.cpp
    title: test/geometry/Cross_Points_of_Circle_and_Line.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Points_of_Circles.test.cpp
    title: test/geometry/Cross_Points_of_Circles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Distance.test.cpp
    title: test/geometry/Distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Incircle_of_Triangle.test.cpp
    title: test/geometry/Incircle_of_Triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Intersection.test.cpp
    title: test/geometry/Intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Intersection_Circle.test.cpp
    title: test/geometry/Intersection_Circle.test.cpp
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
    \n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"geometry/base_ld.hpp\"\n\nnamespace lib {\n\nusing vec = complex<ld>;\n\
    \nconst ld PI = acos(-1);\n\nvoid ldout(int len = 20) {\n    cout << fixed <<\
    \ setprecision(len);\n}\n\nint sgn(ld a, const ld eps = 1e-7) {\n    return (a\
    \ < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nbool same_vec(vec a, vec b) {\n    a\
    \ -= b;\n    return sgn(a.real()) == 0 && sgn(a.imag()) == 0;\n}\n\nld dot(const\
    \ vec &a, const vec &b) {\n    return (conj(a) * b).real();\n}\n\nld cross(const\
    \ vec &a, const vec &b) {\n    return (conj(a) * b).imag();\n}\n\nint isp(const\
    \ vec &a, const vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b - a,\
    \ c - a));\n    if (cross_sgn == 0) {\n        if (sgn(dot(b - a, c - a)) < 0)\
    \ return -2;\n        if (sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n    return\
    \ cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return {-a.imag(), a.real()};\n\
    }\n\nvec rot(const vec &a, ld rad) {\n    return a * vec(cosl(rad), sinl(rad));\n\
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs) {\n    // if\
    \ (abs(arg(lhs)-arg(rhs)) < eps) return false; // need ?\n    return arg(lhs)\
    \ < arg(rhs);\n}\n\n}  // namespace lib\n#line 4 \"geometry/line.hpp\"\n\nnamespace\
    \ lib {\n\nstruct line {\n    vec a, b;\n};\n\nvec proj(const line &l, const vec\
    \ &p) {\n    vec ab = l.b - l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n\
    }\n\nvec refl(const line &l, const vec &p) {\n    return proj(l, p) * ld(2) -\
    \ p;\n}\n\nint intersection(const line &a, const line &b) {\n    if (sgn(cross(a.b\
    \ - a.a, b.a - b.b)) != 0) {\n        if (sgn(dot(a.b - a.a, b.a - b.b)) == 0)\
    \ {\n            return 1;\n        }\n        return 0;\n    } else if (sgn(cross(a.b\
    \ - a.a, b.a - a.a)) != 0) {\n        return 2;\n    } else {\n        return\
    \ 3;\n    }\n}\n\nld dist(const line &a, const vec &p) {\n    return abs(cross(p\
    \ - a.a, a.b - a.a) / abs(a.b - a.a));\n}\n\nvec cross_point(const line &a, const\
    \ line &b) {\n    assert(intersection(a, b) < 2);\n    return a.a + (a.b - a.a)\
    \ * cross(b.a - a.a, b.b - b.a) /\n                     cross(a.b - a.a, b.b -\
    \ b.a);\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../geometry/base_ld.hpp\"\n\nnamespace lib {\n\
    \nstruct line {\n    vec a, b;\n};\n\nvec proj(const line &l, const vec &p) {\n\
    \    vec ab = l.b - l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n\
    }\n\nvec refl(const line &l, const vec &p) {\n    return proj(l, p) * ld(2) -\
    \ p;\n}\n\nint intersection(const line &a, const line &b) {\n    if (sgn(cross(a.b\
    \ - a.a, b.a - b.b)) != 0) {\n        if (sgn(dot(a.b - a.a, b.a - b.b)) == 0)\
    \ {\n            return 1;\n        }\n        return 0;\n    } else if (sgn(cross(a.b\
    \ - a.a, b.a - a.a)) != 0) {\n        return 2;\n    } else {\n        return\
    \ 3;\n    }\n}\n\nld dist(const line &a, const vec &p) {\n    return abs(cross(p\
    \ - a.a, a.b - a.a) / abs(a.b - a.a));\n}\n\nvec cross_point(const line &a, const\
    \ line &b) {\n    assert(intersection(a, b) < 2);\n    return a.a + (a.b - a.a)\
    \ * cross(b.a - a.a, b.b - b.a) /\n                     cross(a.b - a.a, b.b -\
    \ b.a);\n}\n\n}  // namespace lib"
  dependsOn:
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - geometry/segment.hpp
  - geometry/circle.hpp
  timestamp: '2023-06-08 15:34:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/Projection.test.cpp
  - test/geometry/Distance.test.cpp
  - test/geometry/Incircle_of_Triangle.test.cpp
  - test/geometry/Intersection.test.cpp
  - test/geometry/Convex_Hull.test.cpp
  - test/geometry/Cross_Points_of_Circle_and_Line.test.cpp
  - test/geometry/Parallel_Orthogonal.test.cpp
  - test/geometry/Reflection.test.cpp
  - test/geometry/Cross_Point.test.cpp
  - test/geometry/Circumscribed_Circle_of_Triangle.test.cpp
  - test/geometry/Intersection_Circle.test.cpp
  - test/geometry/Common_Area_Circles.test.cpp
  - test/geometry/Cross_Points_of_Circles.test.cpp
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