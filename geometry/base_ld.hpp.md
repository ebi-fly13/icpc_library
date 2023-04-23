---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/convex_hull.hpp
    title: geometry/convex_hull.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ lib {\n\nusing vec = complex<ld>;\nconst ld eps = 1e-7;\n\nld dot(const vec\
    \ &a, const vec &b){\n    return (conj(a) * b).real();\n}\n\nld cross(const vec\
    \ &a, const vec &b){\n    return (conj(a) * b).imag();\n}\n\nbool comp_for_argument_sort(const\
    \ vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs)) < eps) return false;\
    \ // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \nusing vec = complex<ld>;\nconst ld eps = 1e-7;\n\nld dot(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).imag();\n}\n\nbool comp_for_argument_sort(const\
    \ vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs)) < eps) return false;\
    \ // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/base_ld.hpp
  requiredBy:
  - geometry/convex_hull.hpp
  timestamp: '2023-04-23 18:25:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/base_ld.hpp
layout: document
redirect_from:
- /library/geometry/base_ld.hpp
- /library/geometry/base_ld.hpp.html
title: geometry/base_ld.hpp
---
