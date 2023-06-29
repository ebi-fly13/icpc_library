---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/others/aoj_1300.test.cpp
    title: test/others/aoj_1300.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ lib\n\n// using namespace lib;\n#line 3 \"math/gauss_jordan.hpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\n\ntemplate <typename T> vector<vector<T>> gauss_jordan(vector<vector<T>>\
    \ &a) {\n    int n = a.size();\n    int m = a[0].size();\n    vector<vector<T>>\
    \ b = a;\n    int piv = 0;\n    rep(j, 0, m) rep(i, piv, n) {\n        if (b[i][j]\
    \ != T(0)) {\n            swap(b[i], b[piv]);\n            T ip = T(1) / b[piv][j];\n\
    \            rep(l, 0, n) {\n                if (l != piv) {\n               \
    \     T tmp = ip * b[l][j];\n                    rep(k, j, m) b[l][k] -= tmp *\
    \ b[piv][k];\n                }\n            }\n            rep(k, j, m) b[piv][k]\
    \ *= ip;\n            piv++;\n            break;\n        }\n    }\n    return\
    \ b;\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    using namespace std;\n\ntemplate <typename T> vector<vector<T>> gauss_jordan(vector<vector<T>>\
    \ &a) {\n    int n = a.size();\n    int m = a[0].size();\n    vector<vector<T>>\
    \ b = a;\n    int piv = 0;\n    rep(j, 0, m) rep(i, piv, n) {\n        if (b[i][j]\
    \ != T(0)) {\n            swap(b[i], b[piv]);\n            T ip = T(1) / b[piv][j];\n\
    \            rep(l, 0, n) {\n                if (l != piv) {\n               \
    \     T tmp = ip * b[l][j];\n                    rep(k, j, m) b[l][k] -= tmp *\
    \ b[piv][k];\n                }\n            }\n            rep(k, j, m) b[piv][k]\
    \ *= ip;\n            piv++;\n            break;\n        }\n    }\n    return\
    \ b;\n}\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: math/gauss_jordan.hpp
  requiredBy: []
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/others/aoj_1300.test.cpp
documentation_of: math/gauss_jordan.hpp
layout: document
title: gauss_jordan
---

## 説明

`vector<vector<T>>` (Tは体) の行列に対して掃き出し法を適用したものを返す。
行列式などを得たい場合や、 `double` 型を扱う場合などには柔軟に実装する必要がある。