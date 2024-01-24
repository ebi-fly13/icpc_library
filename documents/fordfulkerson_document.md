---
title: FordFulkerson
documentation_of: //graph/fordfulkerson.hpp
---

## 説明

最大流を Ford-Fulkerson 法で求める。うしライブラリを改変して高速に書けるようにした。

### コンストラクタ

`FordFulkerson<Cap> graph(int n)`

n 頂点 0 辺のグラフを作る。Cap は容量の型。

### add_edge(int from, int to, Cap cap)

from→to へ最大容量 cap、流量 0 の辺を追加する。

### flow(int s, int t)

頂点 s から t へ流せる限り流し、流せた量を返す。計算量は、流量を F, 辺数を M として O(FM)

### 実装例

```cpp
int main(){
	int n, m; cin >> n >> m;
	FordFulkerson<int> mf(n);
	for(int i=0;i<m;i++){
		int u,v,c;cin>>u>>v>>c;
		mf.add_edge(u,v,c);
	}
	cout<<mf.flow(0,n-1)<<endl;
}
```