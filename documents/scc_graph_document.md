---
title: SCC Graph
documentation_of: //graph/scc_graph.hpp
---

## 説明

強連結成分分解をする。 $O(N + M)$

### コンストラクタ

`scc_graph(int n)` $n$ 頂点のグラフを定義

### add_edge(int from, int to)

from から to に辺を貼る

### scc()

強連結成分分解をする。 $1$ 回しか読んだらダメ

### same(int u, int v)

u と v が強連結成分分解後に同一の成分にあるか判定。

### scc_id()

各頂点の強連結成分分解後の属する頂点番号の配列を返す。

### create_graph()

強連結成分分解後のグラフを陽に構築