---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ranked_subset_transform.hpp
    title: Ranked Subset Transform (Zeta / Mobius)
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Subset_Convolution.test.cpp
    title: test/convolution/Subset_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/subset_convolution.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
    math/ranked_subset_transform.hpp\"\n\n#line 4 \"math/ranked_subset_transform.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class T, int LIM = 20>\nstd::vector<std::array<T,\
    \ LIM + 1>> ranked_zeta(const std::vector<T> &f) {\n    int n = std::bit_width(f.size())\
    \ - 1;\n    assert(n <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++)\n        rf[s][std::popcount((unsigned\
    \ int)(s))] = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n\
    \        for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s =\
    \ p; s < p + w; s++) {\n                int t = s | (1 << i);\n              \
    \  for (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n       \
    \ }\n    }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T>\
    \ ranked_mobius(std::vector<std::array<T, LIM + 1>> rf) {\n    int n = std::bit_width(rf.size())\
    \ - 1;\n    assert((int)rf.size() == (1 << n));\n    for (int i = 0; i < n; i++)\
    \ {\n        int w = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w)\
    \ {\n            for (int s = p; s < p + w; s++) {\n                int t = s\
    \ | (1 << i);\n                for (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n\
    \            }\n        }\n    }\n    std::vector<T> f(1 << n);\n    for (int\
    \ s = 0; s < (1 << n); s++) {\n        f[s] = rf[s][std::popcount((unsigned int)(s))];\n\
    \    }\n    return f;\n}\n\n}  // namespace ebi\n#line 5 \"convolution/subset_convolution.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\n                                  const std::vector<T> &b)\
    \ {\n    auto ra = ranked_zeta<T, LIM>(a);\n    auto rb = ranked_zeta<T, LIM>(b);\n\
    \    int n = std::bit_width(a.size()) - 1;\n    for (int s = (1 << n) - 1; s >=\
    \ 0; s--) {\n        auto &f = ra[s];\n        const auto &g = rb[s];\n      \
    \  for (int d = n; d >= 0; d--) {\n            T x = 0;\n            for (int\
    \ i = 0; i <= d; i++) {\n                x += f[i] * g[d - i];\n            }\n\
    \            f[d] = x;\n        }\n    }\n    return ranked_mobius<T, LIM>(ra);\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"../math/ranked_subset_transform.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\n                                  const std::vector<T> &b)\
    \ {\n    auto ra = ranked_zeta<T, LIM>(a);\n    auto rb = ranked_zeta<T, LIM>(b);\n\
    \    int n = std::bit_width(a.size()) - 1;\n    for (int s = (1 << n) - 1; s >=\
    \ 0; s--) {\n        auto &f = ra[s];\n        const auto &g = rb[s];\n      \
    \  for (int d = n; d >= 0; d--) {\n            T x = 0;\n            for (int\
    \ i = 0; i <= d; i++) {\n                x += f[i] * g[d - i];\n            }\n\
    \            f[d] = x;\n        }\n    }\n    return ranked_mobius<T, LIM>(ra);\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - template/template.hpp
  - math/ranked_subset_transform.hpp
  isVerificationFile: false
  path: convolution/subset_convolution.hpp
  requiredBy: []
  timestamp: '2023-11-15 02:05:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Subset_Convolution.test.cpp
documentation_of: convolution/subset_convolution.hpp
layout: document
title: Subset Convolution
---

## 説明

長さ $2^N$ の整数列 $a$ と $b$ について、 $c_k = \sum_{i\& j=0, i|j=k} a_i b_j$ を求める。
$O(N^2 2^N)$