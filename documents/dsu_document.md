---
title: dsu
documentation_of: //data_structure/dsu.hpp
---

## 説明

ACL baseのdsu。別名 union find。

### leader(int a)

頂点 $a$ の連結成分の代表元を返す。$O(\alpha(N))$

### size(int a)

頂点 $a$ の連結成分のサイズを返す。$O(\alpha(N))$

### merge(int a, int b)

頂点 $a$ と $b$ をマージし、代表元を返す。$O(\alpha(N))$

### same(int a, int b)

頂点 $a$ と $b$ が同じ連結成分に属するか判定。 $O(\alpha(N))$