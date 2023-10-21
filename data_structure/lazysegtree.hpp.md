---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/lazysegtree.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/lazysegtree.hpp\"\n\nnamespace lib {\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)(), class F, S (*mapping)(F, S),\n          F (*composition)(F, F),\
    \ F (*id)()>\nstruct lazysegtree {\n  private:\n    int n, lg2, sz;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int i) {\n        d[i] = op(d[2\
    \ * i], d[2 * i + 1]);\n    }\n\n    void all_apply(int i, F f) {\n        d[i]\
    \ = mapping(f, d[i]);\n        if (i < sz) lz[i] = composition(f, lz[i]);\n  \
    \  }\n\n    void push(int i) {\n        all_apply(2 * i, lz[i]);\n        all_apply(2\
    \ * i + 1, lz[i]);\n        lz[i] = id();\n    }\n\n  public:\n    lazysegtree(int\
    \ _n) : lazysegtree(std::vector<S>(_n, e())) {}\n\n    lazysegtree(const std::vector<S>\
    \ &v) : n(v.size()) {\n        lg2 = 0;\n        while ((1 << lg2) < n) lg2++;\n\
    \        sz = 1 << lg2;\n        d = std::vector<S>(2 * sz, e());\n        lz\
    \ = std::vector<F>(2 * sz, id());\n        for (int i = 0; i < n; i++) d[sz +\
    \ i] = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        rrep(i, 1, lg2 + 1) push(p >> i);\n        d[p] = x;\n        rep(i,\
    \ 1, lg2 + 1) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <=\
    \ p && p < n);\n        p += sz;\n        rrep(i, 1, lg2 + 1) push(p >> i);\n\
    \        return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        if (l == r) return e();\n        l += sz;\n\
    \        r += sz;\n        rrep(i, 1, lg2 + 1) {\n            if (((l >> i) <<\
    \ i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >>\
    \ i);\n        }\n\n        S sml = e(), smr = e();\n        while (l < r) {\n\
    \            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() {\n        return d[1];\n    }\n\n\
    \    void apply(int p, F f) {\n        assert(0 <= p && p < n);\n        p +=\
    \ sz;\n        rrep(i, 1, lg2 + 1) push(p >> i);\n        d[p] = mapping(f, d[p]);\n\
    \        rep(i, 1, lg2 + 1) update(p >> i);\n    }\n\n    void apply(int l, int\
    \ r, F f) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r)\
    \ return;\n        l += sz;\n        r += sz;\n        rrep(i, 1, lg2 + 1) {\n\
    \            if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int l2\
    \ = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ f);\n                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        rep(i, 1, lg2 + 1) {\n            if (((l >> i) <<\
    \ i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r -\
    \ 1) >> i);\n        }\n    }\n\n    template <class G> int max_right(int l, G\
    \ g) {\n        assert(0 <= l && l <= n);\n        assert(g(e()));\n        if\
    \ (l == n) return n;\n        l += sz;\n        for (int i = lg2; i >= 1; i--)\
    \ push(l >> i);\n        S sm = e();\n        do {\n            while (l % 2 ==\
    \ 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while (l <\
    \ sz) {\n                    push(l);\n                    l = (2 * l);\n    \
    \                if (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - sz;\n            }\n            sm = op(sm, d[l]);\n \
    \           l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\
    \n    template <class G> int min_left(int r, G g) {\n        assert(0 <= r &&\
    \ r <= n);\n        assert(g(e()));\n        if (r == 0) return 0;\n        r\
    \ += sz;\n        for (int i = lg2; i >= 1; i--) push((r - 1) >> i);\n       \
    \ S sm = e();\n        do {\n            r--;\n            while (r > 1 && (r\
    \ % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while (r\
    \ < sz) {\n                    push(r);\n                    r = (2 * r + 1);\n\
    \                    if (g(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\n}  //\
    \ namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n \
    \         F (*composition)(F, F), F (*id)()>\nstruct lazysegtree {\n  private:\n\
    \    int n, lg2, sz;\n    std::vector<S> d;\n    std::vector<F> lz;\n\n    void\
    \ update(int i) {\n        d[i] = op(d[2 * i], d[2 * i + 1]);\n    }\n\n    void\
    \ all_apply(int i, F f) {\n        d[i] = mapping(f, d[i]);\n        if (i < sz)\
    \ lz[i] = composition(f, lz[i]);\n    }\n\n    void push(int i) {\n        all_apply(2\
    \ * i, lz[i]);\n        all_apply(2 * i + 1, lz[i]);\n        lz[i] = id();\n\
    \    }\n\n  public:\n    lazysegtree(int _n) : lazysegtree(std::vector<S>(_n,\
    \ e())) {}\n\n    lazysegtree(const std::vector<S> &v) : n(v.size()) {\n     \
    \   lg2 = 0;\n        while ((1 << lg2) < n) lg2++;\n        sz = 1 << lg2;\n\
    \        d = std::vector<S>(2 * sz, e());\n        lz = std::vector<F>(2 * sz,\
    \ id());\n        for (int i = 0; i < n; i++) d[sz + i] = v[i];\n        for (int\
    \ i = sz - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int p, S x) {\n \
    \       assert(0 <= p && p < n);\n        p += sz;\n        rrep(i, 1, lg2 + 1)\
    \ push(p >> i);\n        d[p] = x;\n        rep(i, 1, lg2 + 1) update(p >> i);\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        rrep(i, 1, lg2 + 1) push(p >> i);\n        return d[p];\n    }\n\n  \
    \  S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n     \
    \   if (l == r) return e();\n        l += sz;\n        r += sz;\n        rrep(i,\
    \ 1, lg2 + 1) {\n            if (((l >> i) << i) != l) push(l >> i);\n       \
    \     if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml\
    \ = e(), smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n  \
    \  S all_prod() {\n        return d[1];\n    }\n\n    void apply(int p, F f) {\n\
    \        assert(0 <= p && p < n);\n        p += sz;\n        rrep(i, 1, lg2 +\
    \ 1) push(p >> i);\n        d[p] = mapping(f, d[p]);\n        rep(i, 1, lg2 +\
    \ 1) update(p >> i);\n    }\n\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) return;\n        l += sz;\n\
    \        r += sz;\n        rrep(i, 1, lg2 + 1) {\n            if (((l >> i) <<\
    \ i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >>\
    \ i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n            while\
    \ (l < r) {\n                if (l & 1) all_apply(l++, f);\n                if\
    \ (r & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>=\
    \ 1;\n            }\n            l = l2;\n            r = r2;\n        }\n\n \
    \       rep(i, 1, lg2 + 1) {\n            if (((l >> i) << i) != l) update(l >>\
    \ i);\n            if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n\
    \    }\n\n    template <class G> int max_right(int l, G g) {\n        assert(0\
    \ <= l && l <= n);\n        assert(g(e()));\n        if (l == n) return n;\n \
    \       l += sz;\n        for (int i = lg2; i >= 1; i--) push(l >> i);\n     \
    \   S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n     \
    \       if (!g(op(sm, d[l]))) {\n                while (l < sz) {\n          \
    \          push(l);\n                    l = (2 * l);\n                    if\
    \ (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n          \
    \              l++;\n                    }\n                }\n              \
    \  return l - sz;\n            }\n            sm = op(sm, d[l]);\n           \
    \ l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\n    template\
    \ <class G> int min_left(int r, G g) {\n        assert(0 <= r && r <= n);\n  \
    \      assert(g(e()));\n        if (r == 0) return 0;\n        r += sz;\n    \
    \    for (int i = lg2; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(op(d[r], sm))) {\n                while (r < sz) {\n     \
    \               push(r);\n                    r = (2 * r + 1);\n             \
    \       if (g(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n \
    \                       r--;\n                    }\n                }\n     \
    \           return r + 1 - sz;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\n}  // namespace\
    \ lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/lazysegtree.hpp
  requiredBy: []
  timestamp: '2023-10-21 23:41:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
documentation_of: data_structure/lazysegtree.hpp
layout: document
title: lazy segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して各種区間操作ができるデータ構造である。インターフェースはすべてACLと同様。

### コンストラクタ

`lazysegtree<S, op, e, F, mapping, composition, id>(int n)`
`lazysegtree<S, op, e, F, mapping, composition, id>(const std::vector<S> &v)`

-   型 `S`
-   二項演算 `S op(S, S)`
-   単位元 `S e()`
-   写像の型 `F`
-   $f(x)$ を返す関数 `S mapping(F f, S x)`
-   $f(g)$ を返す関数 `F composition(F f, F g)`
-   $id(x) = x$ となる $id$ を返す関数 `F id()`

に対する遅延セグ木を構築する。要素数を渡す場合、 `std::vector<S>(n, e())` に対して遅延セグ木を構築する。Range add Range Sumの場合次のようになる。計算量 $O(n)$

```cpp
struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
```

### get(int p)

v[p] を返す。

### set(int p, S x)

v[p] = x とする。

### prod(int l, int r)

op(v[l], ..., a[r-1]) を返す。

### all_prod()

op(v[0], ..., v[n-1]) を返す。

### apply(int p, F f)

v[p] に、写像 $f$ を作用させる。

### apply(int l, int r, F f)

v[l], ... v[r-1] に、写像 $f$ を作用させる。

### max_right(int l, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最大の $r$ を返す。

### min_left(int r, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最小の $l$ を返す。
