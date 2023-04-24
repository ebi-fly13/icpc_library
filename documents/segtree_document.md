---
title: segtree
documentation_of: //data_structure/segtree.hpp
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
