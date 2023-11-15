---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://codeforces.com/contest/893/submission/125531718
    - https://blog.hamayanhamayan.com/entry/2017/12/09/015937
  bundledCode: "#line 2 \"data_structure/offline_segtree_2d.hpp\"\n\n/*\n    reference:\
    \ https://blog.hamayanhamayan.com/entry/2017/12/09/015937\n    verify   : http://codeforces.com/contest/893/submission/125531718\n\
    */\n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define\
    \ rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n)\
    \ for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return\
    \ false;\n    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T\
    \ &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n\nnamespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using\
    \ namespace lib;\n#line 2 \"data_structure/compress.hpp\"\n\n#line 4 \"data_structure/compress.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp)\
    \ : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}\n#line 10 \"data_structure/offline_segtree_2d.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class data_structure>\n\
    struct offline_segtree_2d {\n    offline_segtree_2d() = default;\n\n    void pre_set(std::pair<int,\
    \ int> p) {\n        ps.emplace_back(p);\n    }\n\n    void build() {\n      \
    \  for (auto [x, y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n\
    \        while (sz < xs.size()) sz <<= 1;\n        ys.resize(2 * sz);\n      \
    \  for (auto [x, y] : ps) {\n            int i = xs.get(x) + sz;\n           \
    \ ys[i].add(y);\n            while (i > 1) {\n                i >>= 1;\n     \
    \           ys[i].add(y);\n            }\n        }\n        for (int i = 0; i\
    \ < 2 * sz; i++) {\n            ys[i].build();\n            data.emplace_back(data_structure(ys[i].size()));\n\
    \        }\n    }\n\n    void set(int i, int j, S val) {\n        i = xs.get(i);\n\
    \        i += sz;\n        data[i].set(ys[i].get(j), val);\n        while (i >\
    \ 1) {\n            i >>= 1;\n            S res = e();\n            if (ys[2 *\
    \ i].find(j)) {\n                res = op(res, data[2 * i].get(ys[2 * i].get(j)));\n\
    \            }\n            if (ys[2 * i + 1].find(j)) {\n                res\
    \ = op(res, data[2 * i + 1].get(ys[2 * i + 1].get(j)));\n            }\n     \
    \       data[i].set(ys[i].get(j), res);\n        }\n    }\n\n    S get(int i,\
    \ int j) {\n        i = xs.get(i) + sz;\n        return data[i].get(ys[i].get(j));\n\
    \    }\n\n    S prod(int l, int d, int r, int u) {\n        l = xs.get(l) + sz;\n\
    \        r = xs.get(r) + sz;\n        S res = e();\n        while (l < r) {\n\
    \            if (l & 1) {\n                res = op(res, data[l].prod(ys[l].get(d),\
    \ ys[l].get(u)));\n                l++;\n            }\n            if (r & 1)\
    \ {\n                r--;\n                res = op(data[r].prod(ys[r].get(d),\
    \ ys[r].get(u)), res);\n            }\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return res;\n    }\n\n  private:\n    int sz = 1;\n \
    \   std::vector<std::pair<int, int>> ps;\n    compress<int> xs;\n    std::vector<compress<int>>\
    \ ys;\n    std::vector<data_structure> data;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n/*\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\n\
    \    verify   : http://codeforces.com/contest/893/submission/125531718\n*/\n\n\
    #include \"../template/template.hpp\"\n#include \"../data_structure/compress.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class data_structure>\n\
    struct offline_segtree_2d {\n    offline_segtree_2d() = default;\n\n    void pre_set(std::pair<int,\
    \ int> p) {\n        ps.emplace_back(p);\n    }\n\n    void build() {\n      \
    \  for (auto [x, y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n\
    \        while (sz < xs.size()) sz <<= 1;\n        ys.resize(2 * sz);\n      \
    \  for (auto [x, y] : ps) {\n            int i = xs.get(x) + sz;\n           \
    \ ys[i].add(y);\n            while (i > 1) {\n                i >>= 1;\n     \
    \           ys[i].add(y);\n            }\n        }\n        for (int i = 0; i\
    \ < 2 * sz; i++) {\n            ys[i].build();\n            data.emplace_back(data_structure(ys[i].size()));\n\
    \        }\n    }\n\n    void set(int i, int j, S val) {\n        i = xs.get(i);\n\
    \        i += sz;\n        data[i].set(ys[i].get(j), val);\n        while (i >\
    \ 1) {\n            i >>= 1;\n            S res = e();\n            if (ys[2 *\
    \ i].find(j)) {\n                res = op(res, data[2 * i].get(ys[2 * i].get(j)));\n\
    \            }\n            if (ys[2 * i + 1].find(j)) {\n                res\
    \ = op(res, data[2 * i + 1].get(ys[2 * i + 1].get(j)));\n            }\n     \
    \       data[i].set(ys[i].get(j), res);\n        }\n    }\n\n    S get(int i,\
    \ int j) {\n        i = xs.get(i) + sz;\n        return data[i].get(ys[i].get(j));\n\
    \    }\n\n    S prod(int l, int d, int r, int u) {\n        l = xs.get(l) + sz;\n\
    \        r = xs.get(r) + sz;\n        S res = e();\n        while (l < r) {\n\
    \            if (l & 1) {\n                res = op(res, data[l].prod(ys[l].get(d),\
    \ ys[l].get(u)));\n                l++;\n            }\n            if (r & 1)\
    \ {\n                r--;\n                res = op(data[r].prod(ys[r].get(d),\
    \ ys[r].get(u)), res);\n            }\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return res;\n    }\n\n  private:\n    int sz = 1;\n \
    \   std::vector<std::pair<int, int>> ps;\n    compress<int> xs;\n    std::vector<compress<int>>\
    \ ys;\n    std::vector<data_structure> data;\n};\n\n}  // namespace ebi"
  dependsOn:
  - template/template.hpp
  - data_structure/compress.hpp
  isVerificationFile: false
  path: data_structure/offline_segtree_2d.hpp
  requiredBy: []
  timestamp: '2023-11-14 21:20:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
documentation_of: data_structure/offline_segtree_2d.hpp
layout: document
title: offline 2D segtree
---

## 説明

可換モノイドについて、1点更新、長方形領域クエリを行えるデータ構造。クエリ先読みにより、必要な部分だけ作ることでメモリ使用量を減らして点の座標が$10^9$とかでも使える。

```
segtree_2d<S, op, e, data_structure> seg2d(h, w)
```

とすることで $h \times w$ の単位元で初期化された長方形を作る。
`S, op, e`は可換モノイド、`data_structure`には以下を要求する

- `void set(int i, S x)`
- `S get(i)`
- `S prod(l, r)`

これを満たすデータ構造ならなんでもok (segtree、fenwick treeなどなど)

### pre_set(i, j)

$(i,j)$ を追加する。

### build()

クエリ先読み後（pre_set後）、セグ木を構築する。

### set(i, j, x)

$(i, j)$ を $x$ に更新する。O(\log H)

### get(i, j, x)

$(i, j)$ の値を返す。 $O(1)$

### prod(l, d, r, u)

$[l, r) \times [d, u)$ の領域に対してクエリを処理する $O(\log H \log W)$