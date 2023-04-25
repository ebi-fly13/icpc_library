---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define\
    \ rep(i,s,n) for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template<typename T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T &a, const\
    \ T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace\
    \ lib{\n\nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n\
    #line 3 \"graph/fordfulkerson.hpp\"\n\nnamespace lib{\nusing namespace std;\n\n\
    template<typename fa>\nstruct FordFulkerson{\n    struct edge {int to; fa cap;\
    \ int rev; bool isrev;};\n    \n    const fa INF;\n    vector<vector<edge>> g;\n\
    \    vector<int> used;\n    int ts;\n    \n    explicit FordFulkerson(int v):\
    \ INF(numeric_limits<fa>::max()), g(v), used(v, -1), ts(0) {}\n    \n    void\
    \ add_edge(int from ,int to, fa cap){\n        g[from].push_back((edge){to, cap,\
    \ (int)g[to].size(), false});\n        g[to].push_back((edge){from, 0, (int)g[from].size()-1,\
    \ true});\n        \n    }\n    fa dfs(int v, int t, fa flow){\n        if (v==t)\
    \ return flow;\n        used[v] = ts;\n        for(auto &e : g[v]){\n        \
    \    if(e.cap > 0 && used[e.to] != ts){\n                fa d = dfs(e.to, t, min(flow,\
    \ e.cap));\n                if(d > 0){\n                    e.cap -= d;\n    \
    \                g[e.to][e.rev].cap += d;\n                    return d;\n   \
    \             }\n            }\n        }\n        return 0;\n    }\n\n    fa\
    \ flow(int s, int t){\n        fa ret = 0;\n        for (fa f; (f = dfs(s, t,\
    \ INF)) > 0; ts++) ret += f;\n        ts++;\n        return ret;\n    }\n};\n\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib{\nusing\
    \ namespace std;\n\ntemplate<typename fa>\nstruct FordFulkerson{\n    struct edge\
    \ {int to; fa cap; int rev; bool isrev;};\n    \n    const fa INF;\n    vector<vector<edge>>\
    \ g;\n    vector<int> used;\n    int ts;\n    \n    explicit FordFulkerson(int\
    \ v): INF(numeric_limits<fa>::max()), g(v), used(v, -1), ts(0) {}\n    \n    void\
    \ add_edge(int from ,int to, fa cap){\n        g[from].push_back((edge){to, cap,\
    \ (int)g[to].size(), false});\n        g[to].push_back((edge){from, 0, (int)g[from].size()-1,\
    \ true});\n        \n    }\n    fa dfs(int v, int t, fa flow){\n        if (v==t)\
    \ return flow;\n        used[v] = ts;\n        for(auto &e : g[v]){\n        \
    \    if(e.cap > 0 && used[e.to] != ts){\n                fa d = dfs(e.to, t, min(flow,\
    \ e.cap));\n                if(d > 0){\n                    e.cap -= d;\n    \
    \                g[e.to][e.rev].cap += d;\n                    return d;\n   \
    \             }\n            }\n        }\n        return 0;\n    }\n\n    fa\
    \ flow(int s, int t){\n        fa ret = 0;\n        for (fa f; (f = dfs(s, t,\
    \ INF)) > 0; ts++) ret += f;\n        ts++;\n        return ret;\n    }\n};\n\n\
    }\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/fordfulkerson.hpp
  requiredBy: []
  timestamp: '2023-04-26 00:18:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fordfulkerson.hpp
layout: document
title: FordFulkerson
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
	lib::FordFulkerson<int> mf(n);
	for(int i=0;i<m;i++){
		int u,v,c;cin>>u>>v>>c;
		mf.add_edge(u,v,c);
	}
	cout<<mf.flow(0,n-1)<<endl;
}
```