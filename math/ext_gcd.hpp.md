---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/crt.hpp
    title: math/crt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/yuki_447.test.cpp
    title: test/math/yuki_447.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/extgcd.hpp
  bundledCode: "#line 2 \"math/ext_gcd.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
    \n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i <\
    \ (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    math/ext_gcd.hpp\"\n\n// https://github.com/maspypy/library/blob/main/nt/extgcd.hpp\n\
    \nnamespace lib {\n\ntuple<ll, ll, ll, ll> Farey_lr(ll a, ll b) {\n    assert(a\
    \ > 0 && b > 0);\n    /*\n    Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\u521D\
    \u306B\u73FE\u308C\u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\u3081\
    \u308B\u3002\n    a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5)\
    \ \u3092\u8FD4\u3059\u3002\n    */\n    if (a == b) return {0, 1, 1, 0};\n   \
    \ ll q = (a - 1) / b;\n    auto [x1, y1, x2, y2] = Farey_lr(b, a - q * b);\n \
    \   return {q * x2 + y2, x2, q * x1 + y1, x1};\n}\n\ntuple<ll, ll, ll> extgcd(ll\
    \ a, ll b) {\n    // ax + by = d \u306E\u6700\u5C0F\u89E3 (x, y, d) \u3092\u8FD4\
    \u3059\u3002\n    // (|x|+|y|, x) \u306B\u95A2\u3059\u308B\u8F9E\u66F8\u9806\u6700\
    \u5C0F\u3068\u3059\u308B\u3002\n    auto [x1, y1, x2, y2] = Farey_lr(a, b);\n\
    \    tie(x1, y1) = make_pair(y1, -x1);\n    tie(x2, y2) = make_pair(-y2, x2);\n\
    \    ll g = a * x1 + b * y1;\n    pair<ll,ll> key1 = make_pair(abs(x1) + abs(y1),\
    \ x1);\n    pair<ll,ll> key2 = make_pair(abs(x2) + abs(y2), x2);\n    return (key1\
    \ < key2 ? make_tuple(x1, y1, g) : make_tuple(x2, y2, g));\n}\n\n}  // namespace\
    \ lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\n// https://github.com/maspypy/library/blob/main/nt/extgcd.hpp\n\
    \nnamespace lib {\n\ntuple<ll, ll, ll, ll> Farey_lr(ll a, ll b) {\n    assert(a\
    \ > 0 && b > 0);\n    /*\n    Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\u521D\
    \u306B\u73FE\u308C\u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\u3081\
    \u308B\u3002\n    a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5)\
    \ \u3092\u8FD4\u3059\u3002\n    */\n    if (a == b) return {0, 1, 1, 0};\n   \
    \ ll q = (a - 1) / b;\n    auto [x1, y1, x2, y2] = Farey_lr(b, a - q * b);\n \
    \   return {q * x2 + y2, x2, q * x1 + y1, x1};\n}\n\ntuple<ll, ll, ll> extgcd(ll\
    \ a, ll b) {\n    // ax + by = d \u306E\u6700\u5C0F\u89E3 (x, y, d) \u3092\u8FD4\
    \u3059\u3002\n    // (|x|+|y|, x) \u306B\u95A2\u3059\u308B\u8F9E\u66F8\u9806\u6700\
    \u5C0F\u3068\u3059\u308B\u3002\n    auto [x1, y1, x2, y2] = Farey_lr(a, b);\n\
    \    tie(x1, y1) = make_pair(y1, -x1);\n    tie(x2, y2) = make_pair(-y2, x2);\n\
    \    ll g = a * x1 + b * y1;\n    pair<ll,ll> key1 = make_pair(abs(x1) + abs(y1),\
    \ x1);\n    pair<ll,ll> key2 = make_pair(abs(x2) + abs(y2), x2);\n    return (key1\
    \ < key2 ? make_tuple(x1, y1, g) : make_tuple(x2, y2, g));\n}\n\n}  // namespace\
    \ lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy:
  - math/crt.hpp
  timestamp: '2023-06-11 02:07:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/yuki_447.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
redirect_from:
- /library/math/ext_gcd.hpp
- /library/math/ext_gcd.hpp.html
title: math/ext_gcd.hpp
---
