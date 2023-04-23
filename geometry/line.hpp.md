---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/base_ld.hpp
    title: geometry/base_ld.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/geometry/Projection.cpp
    title: test/geometry/Projection.cpp
  - icon: ':warning:'
    path: test/geometry/Reflection.cpp
    title: test/geometry/Reflection.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs))\
    \ < eps) return false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace\
    \ lib\n#line 4 \"geometry/line.hpp\"\n\nnamespace lib {\n\nstruct line {\n   \
    \ vec a, b;\n};\n\nvec proj(const line &l, const vec &p) {\n    vec ab = l.b -\
    \ l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n}\n\nvec refl(const\
    \ line &l, const vec &p) {\n    return proj(l, p) * ld(2) - p;\n}\n\n}\n"
  code: "#pragma once\n\n#include \"../geometry/base_ld.hpp\"\n\nnamespace lib {\n\
    \nstruct line {\n    vec a, b;\n};\n\nvec proj(const line &l, const vec &p) {\n\
    \    vec ab = l.b - l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n\
    }\n\nvec refl(const line &l, const vec &p) {\n    return proj(l, p) * ld(2) -\
    \ p;\n}\n\n}"
  dependsOn:
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - test/geometry/Reflection.cpp
  - test/geometry/Projection.cpp
  timestamp: '2023-04-23 19:01:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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