---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Range_Sum.test.cpp
    title: test/data_structure/Point_Add_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/segtree.hpp\"\n\nnamespace lib {\n\nusing namespace std;\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> struct segtree {\n  private:\n    int n;\n\
    \    int sz;\n    vector<S> data;\n\n    void update(int i) {\n        data[i]\
    \ = op(data[2 * i], data[2 * i + 1]);\n    }\n\n  public:\n    segtree(int n)\
    \ : segtree(vector<S>(n, e())) {}\n    segtree(const vector<S> &v) : n((int)v.size()),\
    \ sz(1) {\n        while (sz < n) sz *= 2;\n        data = vector<S>(2 * sz, e());\n\
    \        rep(i, 0, n) {\n            data[sz + i] = v[i];\n        }\n       \
    \ rrep(i, 1, sz) update(i);\n    }\n\n    void set(int p, S x) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        data[p] = x;\n        while (p >\
    \ 1) {\n            p >>= 1;\n            update(p);\n        }\n    }\n\n   \
    \ S get(int p) {\n        assert(0 <= p && p < n);\n        return data[p + sz];\n\
    \    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        S sml = e(), smr = e();\n        l += sz;\n        r += sz;\n \
    \       while (l < r) {\n            if (l & 1) sml = op(sml, data[l++]);\n  \
    \          if (r & 1) smr = op(data[--r], smr);\n            l >>= 1;\n      \
    \      r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ {\n        return data[1];\n    }\n\n    template <class F> int max_right(int\
    \ l, F f) {\n        assert(0 <= l && l < n);\n        assert(f(e()));\n     \
    \   if (l == n) return n;\n        l += sz;\n        S sm = e();\n        do {\n\
    \            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, data[l])))\
    \ {\n                while (l < sz) {\n                    l = 2 * l;\n      \
    \              if (f(op(sm, data[l]))) {\n                        sm = op(sm,\
    \ data[l]);\n                        l++;\n                    }\n           \
    \     }\n                return l - sz;\n            }\n            sm = op(sm,\
    \ data[l]);\n            l++;\n        } while ((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <class F> int min_left(int r, F f) {\n        assert(0\
    \ <= r && r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n \
    \       r += sz;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(data[r], sm)))\
    \ {\n                while (r < sz) {\n                    r = 2 * r + 1;\n  \
    \                  if (f(op(data[r], sm))) {\n                        sm = op(data[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\n}  //\
    \ namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nusing namespace std;\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree\
    \ {\n  private:\n    int n;\n    int sz;\n    vector<S> data;\n\n    void update(int\
    \ i) {\n        data[i] = op(data[2 * i], data[2 * i + 1]);\n    }\n\n  public:\n\
    \    segtree(int n) : segtree(vector<S>(n, e())) {}\n    segtree(const vector<S>\
    \ &v) : n((int)v.size()), sz(1) {\n        while (sz < n) sz *= 2;\n        data\
    \ = vector<S>(2 * sz, e());\n        rep(i, 0, n) {\n            data[sz + i]\
    \ = v[i];\n        }\n        rrep(i, 1, sz) update(i);\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < n);\n        p += sz;\n        data[p]\
    \ = x;\n        while (p > 1) {\n            p >>= 1;\n            update(p);\n\
    \        }\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < n);\n  \
    \      return data[p + sz];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        S sml = e(), smr = e();\n        l += sz;\n\
    \        r += sz;\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ data[l++]);\n            if (r & 1) smr = op(data[--r], smr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\
    \n    S all_prod() {\n        return data[1];\n    }\n\n    template <class F>\
    \ int max_right(int l, F f) {\n        assert(0 <= l && l < n);\n        assert(f(e()));\n\
    \        if (l == n) return n;\n        l += sz;\n        S sm = e();\n      \
    \  do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, data[l])))\
    \ {\n                while (l < sz) {\n                    l = 2 * l;\n      \
    \              if (f(op(sm, data[l]))) {\n                        sm = op(sm,\
    \ data[l]);\n                        l++;\n                    }\n           \
    \     }\n                return l - sz;\n            }\n            sm = op(sm,\
    \ data[l]);\n            l++;\n        } while ((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <class F> int min_left(int r, F f) {\n        assert(0\
    \ <= r && r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n \
    \       r += sz;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(data[r], sm)))\
    \ {\n                while (r < sz) {\n                    r = 2 * r + 1;\n  \
    \                  if (f(op(data[r], sm))) {\n                        sm = op(data[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\n}  //\
    \ namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Range_Sum.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/Vertex_Add_Path_Sum.test.cpp
documentation_of: data_structure/segtree.hpp
layout: document
title: segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して各種操作ができるデータ構造である。インターフェースはすべてACLと同様。

### コンストラクタ

`segtree<S, op, e>(int n)`
`segtree<S, op, e>(const std::vector<S> &v)`

-   型 `S`
-   二項演算 `S op(S, S)`
-   単位元 `S e()`

に対するセグ木を構築する。要素数を渡す場合、 `std::vector<S>(n, e())` に対してセグ木を構築する。Range Sumの場合次のようになる。計算量 $O(n)$

```cpp
int op(int a, int b) { 
    return a+b; 
}

int e() { 
    return 0; 
}

segtree<int, op, e> seg(n);
```

### get(int p)

v[p] を返す。

### set(int p, S x)

v[p] = x とする。

### prod(int l, int r)

op(v[l], ..., a[r-1]) を返す。

### all_prod()

op(v[0], ..., v[n-1]) を返す。

### max_right(int l, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最大の $r$ を返す。

### min_left(int r, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最小の $l$ を返す。
