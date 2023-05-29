---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Add_Point_Get.test.cpp
    title: test/data_structure/Range_Add_Point_Get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dualsegtree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace lib {\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\n\
    struct dualsegtree {\n  public:\n    dualsegtree(int n) : n(n) {\n        sz =\
    \ 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2 * sz, e());\n  \
    \  }\n\n    dualsegtree(const std::vector<S> &vec) : n(vec.size()) {\n       \
    \ sz = 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2 * sz, e());\n\
    \        std::copy(vec.begin(), vec.end(), data.begin() + sz);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < n);\n        p += sz;\n   \
    \     S val = e();\n        while (p > 0) {\n            val = op(val, data[p]);\n\
    \            p >>= 1;\n        }\n        return val;\n    }\n\n    void apply(int\
    \ l, int r, S x) {\n        assert(0 <= l && l <= r && r <= n);\n        l +=\
    \ sz;\n        r += sz;\n        while (l < r) {\n            if (l & 1) {\n \
    \               data[l] = op(data[l], x);\n                l++;\n            }\n\
    \            if (r & 1) {\n                r--;\n                data[r] = op(data[r],\
    \ x);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return;\n    }\n\n  private:\n    std::vector<S> data;\n    int n;\n\
    \    int sz;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace lib {\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct dualsegtree {\n  public:\n\
    \    dualsegtree(int n) : n(n) {\n        sz = 1;\n        while (sz < n) sz <<=\
    \ 1;\n        data.assign(2 * sz, e());\n    }\n\n    dualsegtree(const std::vector<S>\
    \ &vec) : n(vec.size()) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n\
    \        data.assign(2 * sz, e());\n        std::copy(vec.begin(), vec.end(),\
    \ data.begin() + sz);\n    }\n\n    S get(int p) const {\n        assert(0 <=\
    \ p && p < n);\n        p += sz;\n        S val = e();\n        while (p > 0)\
    \ {\n            val = op(val, data[p]);\n            p >>= 1;\n        }\n  \
    \      return val;\n    }\n\n    void apply(int l, int r, S x) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        l += sz;\n        r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                data[l] = op(data[l], x);\n\
    \                l++;\n            }\n            if (r & 1) {\n             \
    \   r--;\n                data[r] = op(data[r], x);\n            }\n         \
    \   l >>= 1;\n            r >>= 1;\n        }\n        return;\n    }\n\n  private:\n\
    \    std::vector<S> data;\n    int n;\n    int sz;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dualsegtree.hpp
  requiredBy: []
  timestamp: '2023-05-29 17:30:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Range_Add_Point_Get.test.cpp
documentation_of: data_structure/dualsegtree.hpp
layout: document
title: dual segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して区間作用、 $1$ 点更新。

### コンストラクタ

`dualsegtree<S, op, e>(int n)`
`dualsegtree<S, op, e>(const std::vector<S> &v)`

-   型 `S`
-   二項演算 `S op(S, S)`
-   単位元 `S e()`

に対する双対セグ木を構築する。要素数を渡す場合、 `std::vector<S>(n, e())` に対して双対セグ木を構築する。Range Add Point Getの場合次のようになる。計算量 $O(n)$

```cpp
int op(int a, int b) { 
    return a+b; 
}

int e() { 
    return 0; 
}

dualsegtree<int, op, e> seg(n);
```

### get(int p)

v[p] を返す。

### apply(int l, int r, S s)

区間 $[l, r)$ に s を作用させる。