---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: geometry/circle.hpp
    title: circle
  - icon: ':warning:'
    path: geometry/convex_hull.hpp
    title: geometry/convex_hull.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: line
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: segment
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/Counter_Clockwise.test.cpp
    title: test/geometry/Counter_Clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Cross_Point.test.cpp
    title: test/geometry/Cross_Point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Distance.test.cpp
    title: test/geometry/Distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Incircle_of_Triangle.test.cpp
    title: test/geometry/Incircle_of_Triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/Intersection.test.cpp
    title: test/geometry/Intersection.test.cpp
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib{\n\nusing namespace std;\n\n} // namespace\
    \ lib;\n\n//using namespace lib;\n#line 4 \"geometry/base_ld.hpp\"\n\nnamespace\
    \ lib {\n\nusing vec = complex<ld>;\nconst ld eps = 1e-7;\n\nint sgn(ld a) {\n\
    \    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nld dot(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).imag();\n}\n\nint isp(const vec &a, const\
    \ vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b - a, c - a));\n   \
    \ if(cross_sgn == 0) {\n        if(sgn(dot(b - a, c - a)) < 0) return -2;\n  \
    \      if(sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n    return cross_sgn;\n\
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs))\
    \ < eps) return false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace\
    \ lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \nusing vec = complex<ld>;\nconst ld eps = 1e-7;\n\nint sgn(ld a) {\n    return\
    \ (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nld dot(const vec &a, const vec &b){\n\
    \    return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const vec &b){\n\
    \    return (conj(a) * b).imag();\n}\n\nint isp(const vec &a, const vec &b, const\
    \ vec &c) {\n    int cross_sgn = sgn(cross(b - a, c - a));\n    if(cross_sgn ==\
    \ 0) {\n        if(sgn(dot(b - a, c - a)) < 0) return -2;\n        if(sgn(dot(a\
    \ - b, c - b)) < 0) return 2;\n    }\n    return cross_sgn;\n}\n\nbool comp_for_argument_sort(const\
    \ vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs)) < eps) return false;\
    \ // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/base_ld.hpp
  requiredBy:
  - geometry/line.hpp
  - geometry/circle.hpp
  - geometry/segment.hpp
  - geometry/convex_hull.hpp
  timestamp: '2023-04-23 19:28:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/geometry/Cross_Point.test.cpp
  - test/geometry/Parallel_Orthogonal.test.cpp
  - test/geometry/Counter_Clockwise.test.cpp
  - test/geometry/Distance.test.cpp
  - test/geometry/Incircle_of_Triangle.test.cpp
  - test/geometry/Intersection_Circle.test.cpp
  - test/geometry/Projection.test.cpp
  - test/geometry/Reflection.test.cpp
  - test/geometry/Intersection.test.cpp
documentation_of: geometry/base_ld.hpp
layout: document
title: base_ld
---

## 説明

小数点を用いた平面幾何に必須なもの。小数点での平面幾何ではこれをincludeして用いる。

### sgn(ld x)

$x$ の符号を返す。epsで評価する。

### dot(vec a, vec b)

ベクトル$a$, $b$ の内積を返す。

### cross(vec a, vec b)

ベクトル$a$, $b$ の外積を返す。

### isp(vec a, vec b, vec c)

点 $a$, $b$, $c$ の位置関係を返す。a->b->cの経路が

- 左に曲がる場合: $+1$ 
- 右に曲がる場合: $-1$
- c-a-bの順に並ぶ: $-2$
- a-b-cの順に並ぶ: $+2$
- a-c-bの順に並ぶ: $0$

となる。

### comp_for_argument_sort(vec lhs, vec rhs)

偏角ソートの比較関数。