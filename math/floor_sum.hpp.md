---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Floor_of_Linear.test.cpp
    title: test/math/Sum_of_Floor_of_Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    #define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i,\
    \ s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),\
    \ v.end()\n\nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned\
    \ long long;\n\ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a\
    \ <= b) return false;\n    a = b;\n    return true;\n}\ntemplate <typename T>\
    \ bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n}  // namespace\
    \ lib\n\n// using namespace lib;\n#line 3 \"math/floor_sum.hpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\n\nll floor_sum(ll n, ll m, ll a, ll b){\n\tif (n\
    \ == 0) return 0;\n\tll ret = 0;\n\t\n\t/* if [a >= 0 and b >= 0] is guaranteed,\
    \ ignore from here */\n\tif (a < 0){\n\t\tll a2 = a % m;\n\t\tif (a2 < 0) a2 +=\
    \ m;\n\t\tret -= (ll)n * (n-1) / 2 * ((a2 - a) / m);\n\t\ta = a2;\n\t}\n\tif (b\
    \ < 0){\n\t\tll b2 = b % m;\n\t\tif (b2 < 0) b2 += m;\n\t\tret -= (ll)n * ((b2\
    \ - b) / m);\n\t\tb = b2;\n\t}\n\t/* till here */\n\n\tif (a >= m){\n\t\tret +=\
    \ n * (n-1) / 2 * (a / m);\n\t\ta %= m;\n\t}\n\tif (b >= m){\n\t\tret += n * (b\
    \ / m);\n\t\tb %= m;\n\t}\n\tll y = (a * n + b) / m;\n\tll z = (a * n + b) % m;\n\
    \treturn ret + floor_sum(y, a, m, z);\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    using namespace std;\n\nll floor_sum(ll n, ll m, ll a, ll b){\n\tif (n == 0) return\
    \ 0;\n\tll ret = 0;\n\t\n\t/* if [a >= 0 and b >= 0] is guaranteed, ignore from\
    \ here */\n\tif (a < 0){\n\t\tll a2 = a % m;\n\t\tif (a2 < 0) a2 += m;\n\t\tret\
    \ -= (ll)n * (n-1) / 2 * ((a2 - a) / m);\n\t\ta = a2;\n\t}\n\tif (b < 0){\n\t\t\
    ll b2 = b % m;\n\t\tif (b2 < 0) b2 += m;\n\t\tret -= (ll)n * ((b2 - b) / m);\n\
    \t\tb = b2;\n\t}\n\t/* till here */\n\n\tif (a >= m){\n\t\tret += n * (n-1) /\
    \ 2 * (a / m);\n\t\ta %= m;\n\t}\n\tif (b >= m){\n\t\tret += n * (b / m);\n\t\t\
    b %= m;\n\t}\n\tll y = (a * n + b) / m;\n\tll z = (a * n + b) % m;\n\treturn ret\
    \ + floor_sum(y, a, m, z);\n}\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: math/floor_sum.hpp
  requiredBy: []
  timestamp: '2023-11-18 01:32:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Floor_of_Linear.test.cpp
documentation_of: math/floor_sum.hpp
layout: document
title: Floor Sum
---

## 説明

次を求める.

$\displaystyle f(n, m, a, b) = \sum^{n-1}_{i=0} \left\lfloor \frac{ai + b}{m} \right\rfloor$

$a, b$ が負でもよい. ただし, $a, b$ が非負であることが保証されている場合は, コードを短縮できる.