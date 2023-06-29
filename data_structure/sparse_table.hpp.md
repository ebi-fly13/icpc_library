---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/StaticRMQ.test.cpp
    title: test/data_structure/StaticRMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/sparse_table.hpp\"\n\nnamespace lib{\n\ntemplate<class S, S (*op)(S,\
    \ S)>\nstruct SparseTable{\n    vector<vector<S>> table;\n    vector<int> clz;\n\
    \    SparseTable (const vector<S> &vec){\n        int n = vec.size(), n2 = 0;\n\
    \        while ((1<<n2) < n) n2++;\n        table.resize(n2+1);\n        rep(i,0,n2+1){\n\
    \            table[i].resize(n);\n            if (i == 0){\n                rep(j,0,n)\
    \ table[i][j] = vec[j];\n            }\n            else {\n                rep(j,0,n){\n\
    \                    if (j + (1<<(i-1)) < n) table[i][j] = op(table[i-1][j],table[i-1][j\
    \ + (1<<(i-1))]);\n                    else table[i][j] = table[i-1][j];\n   \
    \             }\n            }\n        }\n        clz.resize(n+1);\n        rep(i,0,n2+1){\n\
    \            for (int j = (1<<i); j < (2<<i) && j <= n; j++){\n              \
    \  clz[j] = i;\n            }\n        }\n    }\n    // \u5358\u4F4D\u5143\u3092\
    \u8981\u6C42\u3057\u306A\u3044\u306E\u3067 if (l >= r) return e() \u307F\u305F\
    \u3044\u306A\u3053\u3068\u3092\u3057\u3066\u3044\u306A\u3044\u3001\u6CE8\u610F\
    \u3059\u308B\u3053\u3068\uFF01\uFF01\n    S get(int l, int r){\n        assert(r\
    \ - l > 0);\n        //int lgs = 31 - __builtin_clz((unsigned int)(r-l));\n  \
    \      int lgs = clz[r-l];\n        return op(table[lgs][l], table[lgs][r - (1\
    \ << lgs)]);\n    }\n};\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib{\n\n\
    template<class S, S (*op)(S, S)>\nstruct SparseTable{\n    vector<vector<S>> table;\n\
    \    vector<int> clz;\n    SparseTable (const vector<S> &vec){\n        int n\
    \ = vec.size(), n2 = 0;\n        while ((1<<n2) < n) n2++;\n        table.resize(n2+1);\n\
    \        rep(i,0,n2+1){\n            table[i].resize(n);\n            if (i ==\
    \ 0){\n                rep(j,0,n) table[i][j] = vec[j];\n            }\n     \
    \       else {\n                rep(j,0,n){\n                    if (j + (1<<(i-1))\
    \ < n) table[i][j] = op(table[i-1][j],table[i-1][j + (1<<(i-1))]);\n         \
    \           else table[i][j] = table[i-1][j];\n                }\n           \
    \ }\n        }\n        clz.resize(n+1);\n        rep(i,0,n2+1){\n           \
    \ for (int j = (1<<i); j < (2<<i) && j <= n; j++){\n                clz[j] = i;\n\
    \            }\n        }\n    }\n    // \u5358\u4F4D\u5143\u3092\u8981\u6C42\u3057\
    \u306A\u3044\u306E\u3067 if (l >= r) return e() \u307F\u305F\u3044\u306A\u3053\
    \u3068\u3092\u3057\u3066\u3044\u306A\u3044\u3001\u6CE8\u610F\u3059\u308B\u3053\
    \u3068\uFF01\uFF01\n    S get(int l, int r){\n        assert(r - l > 0);\n   \
    \     //int lgs = 31 - __builtin_clz((unsigned int)(r-l));\n        int lgs =\
    \ clz[r-l];\n        return op(table[lgs][l], table[lgs][r - (1 << lgs)]);\n \
    \   }\n};\n\n} // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2023-06-29 12:22:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/StaticRMQ.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
title: Sparse Table
---

## 説明

区間クエリを構築 $O(N\log N)$、クエリ $O(1)$ で処理するデータ構造

### コンストラクタ

$1$ 次元の配列を渡して、Sparse Tableを構築する。 $O(N\log N)$

### get(l, r)

$[l, r)$ のクエリを処理する。 $O(1)$