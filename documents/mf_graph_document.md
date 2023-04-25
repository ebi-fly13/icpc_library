---
title: FordFulkerson
documentation_of: //graph/fordfulkerson.hpp
---

## 説明

最大流を Dinic 法で求める。ACLを改変して比較的高速に書けるようにした。

### コンストラクタ

`mf_graph<Cap> graph(int n)`

n 頂点 0 辺のグラフを作る。Cap は容量の型。

### add_edge(int from, int to, Cap cap)

from→to へ最大容量 cap、流量 0 の辺を追加する。

### flow(int s, int t)

頂点 s から t へ流せる限り流し、流せた量を返す。
計算量は、m を辺数として $O(min(n^{2/3}m, m^{3/2}))$ (辺容量がすべて 1)、 $O(n^2m)$ (一般)。

`flow(int s, int t, Cap flow_limit)` で限界もつくれる。

### 注意

以下のコメントアウトされている。必要なときに取り出す。

### get_edge / edges

```cpp
mf_graph<Cap>::edge graph.get_edge(int i);
vector<mf_graph<Cap>::edge> graph.edges();
```

辺の状態を返す。

### change_edge

```cpp
void graph.change_edge(int i, Cap new_cap, Cap new_flow);
```

その辺のみの容量と流量を変えて、他は変更しない。使い所よくわからず。

### min_cut

```cpp
vector<bool> graph.min_cut(int s)
```

残余グラフに対して, 頂点 s から到達可能かどうかを返す。とくに `flow(s,t)` してから呼ぶと最小カットに対応する。

### 実装例

```cpp
int main(){
	int n, m; cin >> n >> m;
	lib::mf_graph<int> mf(n);
	for(int i=0;i<m;i++){
		int u,v,c;cin>>u>>v>>c;
		mf.add_edge(u,v,c);
	}
	cout<<mf.flow(0,n-1)<<endl;
}
```