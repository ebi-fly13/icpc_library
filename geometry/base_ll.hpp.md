---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/base_ll.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"geometry/base_ll.hpp\"\
    \n\nnamespace lib {\n\nusing vec = complex<ll>;\n\nll dot(const vec &a, const\
    \ vec &b) { return (conj(a) * b).real(); }\n\nll cross(const vec &a, const vec\
    \ &b) { return (conj(a) * b).imag(); }\n\n// e : vec(OX)\n// orthant k : [ pi/2\
    \ * k, pi/2 * (k+1) ) rad\n// orthant 4 is NOT expected\nint orthant(const vec\
    \ &p, const vec &e = vec(1, 0)) {\n    ll _dot = dot(e, p), _cross = cross(e,\
    \ p);\n    if (_dot > 0 && _cross >= 0) return 0;\n    if (_dot <= 0 && _cross\
    \ > 0) return 1;\n    if (_dot < 0 && _cross <= 0) return 2;\n    if (_dot >=\
    \ 0 && _cross < 0) return 3;\n    return 4;\n}\n\n// usage :\n//   vector<vec>>\
    \ a;\n//   sort(all(a),comp_for_argument_sort);\nbool comp_for_argument_sort(const\
    \ vec &lhs, const vec &rhs) {\n    int pl = orthant(lhs), pr = orthant(rhs);\n\
    \    if (pl == pr) {\n        return cross(lhs, rhs) > 0;\n    }\n    return pl\
    \ < pr;\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nusing vec = complex<ll>;\n\nll dot(const vec &a, const vec &b) { return (conj(a)\
    \ * b).real(); }\n\nll cross(const vec &a, const vec &b) { return (conj(a) * b).imag();\
    \ }\n\n// e : vec(OX)\n// orthant k : [ pi/2 * k, pi/2 * (k+1) ) rad\n// orthant\
    \ 4 is NOT expected\nint orthant(const vec &p, const vec &e = vec(1, 0)) {\n \
    \   ll _dot = dot(e, p), _cross = cross(e, p);\n    if (_dot > 0 && _cross >=\
    \ 0) return 0;\n    if (_dot <= 0 && _cross > 0) return 1;\n    if (_dot < 0 &&\
    \ _cross <= 0) return 2;\n    if (_dot >= 0 && _cross < 0) return 3;\n    return\
    \ 4;\n}\n\n// usage :\n//   vector<vec>> a;\n//   sort(all(a),comp_for_argument_sort);\n\
    bool comp_for_argument_sort(const vec &lhs, const vec &rhs) {\n    int pl = orthant(lhs),\
    \ pr = orthant(rhs);\n    if (pl == pr) {\n        return cross(lhs, rhs) > 0;\n\
    \    }\n    return pl < pr;\n}\n\n}  // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/base_ll.hpp
  requiredBy: []
  timestamp: '2023-05-08 15:48:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/base_ll.hpp
layout: document
redirect_from:
- /library/geometry/base_ll.hpp
- /library/geometry/base_ll.hpp.html
title: geometry/base_ll.hpp
---
