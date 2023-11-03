---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_1068.test.cpp
    title: test/data_structure/aoj_1068.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree_2d.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/segtree_2d.hpp\"\n\nnamespace lib {\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)(), class data_structure>\nstruct segtree_2d {\n  private:\n  public:\n\
    \    segtree_2d(int h, int w) : h(h), w(w), sz(1) {\n        while (sz < h) sz\
    \ <<= 1;\n        data = std::vector<data_structure>(2 * sz, data_structure(w));\n\
    \    }\n\n    void set(int i, int j, S x) {\n        assert(0 <= i && i < h &&\
    \ 0 <= j && j < w);\n        i += sz;\n        data[i].set(j, x);\n        while\
    \ (i > 1) {\n            i >>= 1;\n            S val = op(data[2 * i].get(j),\
    \ data[2 * i + 1].get(j));\n            data[i].set(j, val);\n        }\n    }\n\
    \n    S get(int i, int j) {\n        assert(0 <= i && i < h && 0 <= j && j < w);\n\
    \        return data[i + sz].get(j);\n    }\n\n    S prod(int l, int d, int r,\
    \ int u) {\n        assert(0 <= l && l <= r && r <= h);\n        assert(0 <= d\
    \ && d <= u && u <= w);\n        l += sz;\n        r += sz;\n        S res = e();\n\
    \        while (l < r) {\n            if (l & 1) res = op(res, data[l++].prod(d,\
    \ u));\n            if (r & 1) res = op(data[--r].prod(d, u), res);\n        \
    \    l >>= 1;\n            r >>= 1;\n        }\n        return res;\n    }\n\n\
    \  private:\n    int h, w;\n    int sz;\n    std::vector<data_structure> data;\n\
    };\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)(), class data_structure>\nstruct segtree_2d\
    \ {\n  private:\n  public:\n    segtree_2d(int h, int w) : h(h), w(w), sz(1) {\n\
    \        while (sz < h) sz <<= 1;\n        data = std::vector<data_structure>(2\
    \ * sz, data_structure(w));\n    }\n\n    void set(int i, int j, S x) {\n    \
    \    assert(0 <= i && i < h && 0 <= j && j < w);\n        i += sz;\n        data[i].set(j,\
    \ x);\n        while (i > 1) {\n            i >>= 1;\n            S val = op(data[2\
    \ * i].get(j), data[2 * i + 1].get(j));\n            data[i].set(j, val);\n  \
    \      }\n    }\n\n    S get(int i, int j) {\n        assert(0 <= i && i < h &&\
    \ 0 <= j && j < w);\n        return data[i + sz].get(j);\n    }\n\n    S prod(int\
    \ l, int d, int r, int u) {\n        assert(0 <= l && l <= r && r <= h);\n   \
    \     assert(0 <= d && d <= u && u <= w);\n        l += sz;\n        r += sz;\n\
    \        S res = e();\n        while (l < r) {\n            if (l & 1) res = op(res,\
    \ data[l++].prod(d, u));\n            if (r & 1) res = op(data[--r].prod(d, u),\
    \ res);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ res;\n    }\n\n  private:\n    int h, w;\n    int sz;\n    std::vector<data_structure>\
    \ data;\n};\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/segtree_2d.hpp
  requiredBy: []
  timestamp: '2023-06-26 02:49:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aoj_1068.test.cpp
documentation_of: data_structure/segtree_2d.hpp
layout: document
title: 2D segtree
---

## 説明

可換モノイドについて、1点更新、長方形領域クエリを行えるデータ構造。

```
segtree_2d<S, op, e, data_structure> seg2d(h, w)
```

とすることで $h \times w$ の単位元で初期化された長方形を作る。
`S, op, e`は可換モノイド、`data_structure`には以下を要求する

- `void set(int i, S x)`
- `S get(i)`
- `S prod(l, r)`

これを満たすデータ構造ならなんでもok (segtree、fenwick treeなどなど)

### set(i, j, x)

$(i, j)$ を $x$ に更新する。O(\log H)

### get(i, j, x)

$(i, j)$ の値を返す。 $O(1)$

### prod(l, d, r, u)

$[l, r) \times [d, u)$ の領域に対してクエリを処理する $O(\log H \log W)$