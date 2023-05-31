---
title: Undo dsu
documentation_of: //data_structure/undo_dsu.hpp
---

## 説明

rollbackできるdsu。
経路圧縮をやらず、mergeするときに変更箇所をstackに入れることでundo時に $1$ つ前の状態に戻すことができる。
経路圧縮をやらないと変更箇所は高々 $2$ 箇所になるためstackには $2$ 箇所の情報を入れるだけでよくなりundoが実現できる。

### undo_dsu(int n)

頂点 n のdsuを作る。$O(N)$

### leader(int a)

頂点 $a$ の連結成分の代表元を返す。$O(\log N)$

### size(int a)

頂点 $a$ の連結成分のサイズを返す。$O(\log N)$

### merge(int a, int b)

頂点 $a$ と $b$ をマージし、代表元を返す。$O(\log N)$

### undo()

$1$ つ前の状態に戻す。$O(1)$