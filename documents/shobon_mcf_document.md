---
title: shobon min cost flow
documentation_of: //graph/shobon_mcf.hpp
---

## 説明

最小費用流を最短路反復法で求める。ネットワークに負閉路があるときは機能しない。

Cap, Cost はコンストラクタで指定する。

### コンストラクタ

`MinCostFlow<Cap,Cost> graph(int n)`

n 頂点 0 辺のグラフを作る。

### add_edge(int from, int to, Cap cap, Cost cost)

from→to へ最大容量 cap、流量 0、コスト cost の辺を追加する。

### flow(int from, int to, Cost f)

頂点 from から to へ流量 f 流したときの最小コストを求める。(流量, コスト) の組で返される。

`flow(int from, int to)` で最大流最小費用流を求めることも可能。

計算量は、流量を $F$, 頂点数を $V$, 辺の数を $E$ として $O(F(V+E)\log(V+E))$ である。

### edges()

ネットワークの辺に関する情報を返すが、add_edge で追加した辺のみが返される。構造体 E は `{from, to, rev, cap, cost}` が入っている。

### potential_bellman_ford(int from)

ポテンシャルを Bellman-Ford 法によって初期化する。負閉路があると機能しないが、負辺があるときに使える。計算量は $O(VE)$ 。

### potential_dag(int from)

ポテンシャルを DAG 上の DP によって初期化する。計算量は $O(V+E)$ 。必ずしもトポロジカル順でなくてもよい。

### 実装例

```cpp
int main(){
  int v,e,f; cin>>v>>e>>f;
  lib::shobon_mcf<int,int> mcf(v);
  rep(i,0,e){
    int u,v,c,d;cin>>u>>v>>c>>d;
    mcf.add_edge(u,v,c,d);
  }
  auto[flow,cost]=mcf.flow(0,v-1,f);
  if (flow!=f)cout<<-1<<'\n';
  else cout<<cost<<'\n';
}
```