---
title: dual segtree
documentation_of: //data_structure/dualsegtree.hpp
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