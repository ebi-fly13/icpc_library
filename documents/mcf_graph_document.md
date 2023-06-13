---
title: min cost flow
documentation_of: //graph/mcf_graph.hpp
---

## 説明

最小費用流を最短路反復法で求める。YNU ICPC Library を改変してより高速に書けるようにした。

Cap, Cost はともに `long long` 型である。

### コンストラクタ

`MinCostFlow graph(int n)`

n 頂点 0 辺のグラフを作る。

### add_edge(int from, int to, ll cap, ll cost)

from→to へ最大容量 cap、流量 0、コスト cost の辺を追加する。

### flow(int s, int t, ll u)

頂点 s から t へ流量 u 流したときの最小コストを求める。流れない場合は -1 が返される。

計算量は、流量を $F$, 頂点数を $V$, 辺の数を $E$ として $O(F(V+E)\log(V+E))$ である。

### 実装例

```cpp
int main(){
	int v,e,f;
	cin >> v >> e >> f;
	lib::MinCostFlow mcf(v);
	for (int i=0;i<e;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		mcf.add_edge(a,b,c,d);
	}
	ll ans = mcf.flow(0,v-1,f);
	cout << ans << endl;
}
```