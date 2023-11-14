---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/bostan_mori.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    fps/bostan_mori.hpp\"\n\nnamespace lib {\n\ntemplate <class T, std::vector<T>\
    \ (*convolution)(const std::vector<T> &,\n                                   \
    \              const std::vector<T> &)>\nT bostan_mori_algorithm(long long n,\
    \ std::vector<T> p, std::vector<T> q) {\n    while (n > 0) {\n        auto q_neg\
    \ = q;\n        for (int i = 1; i < (int)q_neg.size(); i += 2) q_neg[i] = -q_neg[i];\n\
    \        p = convolution(p, q_neg);\n        q = convolution(q, q_neg);\n    \
    \    for (int i = (n & 1LL); i < (int)p.size(); i += 2) p[i >> 1] = p[i];\n  \
    \      p.resize(((int)p.size() + 1 - (n & 1LL)) / 2);\n        for (int i = 0;\
    \ i < (int)q.size(); i += 2) q[i >> 1] = q[i];\n        q.resize(((int)q.size()\
    \ + 1) / 2);\n        n >>= 1;\n    }\n    return p[0] / q[0];\n}\n\ntemplate\
    \ <class T, std::vector<T> (*convolution)(const std::vector<T> &,\n          \
    \                                       const std::vector<T> &)>\nT kitamasa(std::int64_t\
    \ n, std::vector<T> a, std::vector<T> c) {\n    if (n < (int)a.size()) return\
    \ a[n];\n    const int d = c.size();\n    for (auto &val : c) val = -val;\n  \
    \  c.insert(c.begin(), 1);\n    auto p = convolution(a, c);\n    p.resize(d);\n\
    \    return bostan_mori_algorithm<T, convolution>(n, p, c);\n}\n\n}  // namespace\
    \ lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class T, std::vector<T> (*convolution)(const std::vector<T> &,\n \
    \                                                const std::vector<T> &)>\nT bostan_mori_algorithm(long\
    \ long n, std::vector<T> p, std::vector<T> q) {\n    while (n > 0) {\n       \
    \ auto q_neg = q;\n        for (int i = 1; i < (int)q_neg.size(); i += 2) q_neg[i]\
    \ = -q_neg[i];\n        p = convolution(p, q_neg);\n        q = convolution(q,\
    \ q_neg);\n        for (int i = (n & 1LL); i < (int)p.size(); i += 2) p[i >> 1]\
    \ = p[i];\n        p.resize(((int)p.size() + 1 - (n & 1LL)) / 2);\n        for\
    \ (int i = 0; i < (int)q.size(); i += 2) q[i >> 1] = q[i];\n        q.resize(((int)q.size()\
    \ + 1) / 2);\n        n >>= 1;\n    }\n    return p[0] / q[0];\n}\n\ntemplate\
    \ <class T, std::vector<T> (*convolution)(const std::vector<T> &,\n          \
    \                                       const std::vector<T> &)>\nT kitamasa(std::int64_t\
    \ n, std::vector<T> a, std::vector<T> c) {\n    if (n < (int)a.size()) return\
    \ a[n];\n    const int d = c.size();\n    for (auto &val : c) val = -val;\n  \
    \  c.insert(c.begin(), 1);\n    auto p = convolution(a, c);\n    p.resize(d);\n\
    \    return bostan_mori_algorithm<T, convolution>(n, p, c);\n}\n\n}  // namespace\
    \ lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: fps/bostan_mori.hpp
  requiredBy: []
  timestamp: '2023-11-14 20:46:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
documentation_of: fps/bostan_mori.hpp
layout: document
title: Bostan-Mori Algorithm
---

## 説明

$P(x)$ を高々 $d-1$ 次の多項式、 $Q(x)$ を $d$ 次の多項式とし、 $[x^0]Q(x) = 1$ とする。

$[x^N] \frac{P(x)}{Q(x)}$

を求める。$d$ 次の多項式積を $M(d)$ でできるとすると、計算量は $O(M(d) \log N)$ となる。

### bostan_mori_algorithm(std::int64_t n, std::vector<T> p, std::vector<T> q)

$[x^N] \frac{P(x)}{Q(x)}$ を求める。

### kitamasa(std::int64_t n, std::vector<T> a, std::vector<T> c) 

$a$ を 数列の先頭 $d$ 項として、線形漸化式 $a_i = \sum_{j = 1}^d c_j a_{i-j}$ を満たす数列の第 $n$ 項を求める。 $O(M(d) \log N)$