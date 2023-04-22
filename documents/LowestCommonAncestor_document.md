---
title: LowestCommonAncestor
documentation_of: //tree/LowestCommonAncestor.hpp
---

## 説明

木のLCAをダブリングで求める。

### コンストラクタ

`LowestCommonAncestor(std::vector<std::vector<int>> g, int root = 0)`

木グラフ g と root ノード番号を与えてLCAの前計算をする。デフォルトで root は頂点 0

### la(int u, int k)

頂点 u から 親方向に k だけ上った頂点を返す。

### lca(int u, int v)

頂点 u, v のLCAを返す。

### distance(int u, int v)

頂点 u, v の距離を返す。
