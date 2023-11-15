---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    #define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i,\
    \ s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),\
    \ v.end()\n\nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned\
    \ long long;\n\ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a\
    \ <= b) return false;\n    a = b;\n    return true;\n}\ntemplate <typename T>\
    \ bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n}  // namespace\
    \ lib\n\n// using namespace lib;\n#line 3 \"graph/shobon_mcf.hpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\n\ntemplate<class Cap, class Cost> struct shobon_mcf\
    \ {\n  struct E{\n    int from;\n    int to;\n    int rev;\n    Cap cap;\n   \
    \ Cost cost;\n  };\n  \n  int n;\n  vector<E> e;\n  vector<Cost> p;\n  vector<vector<int>>\
    \ ikeru;\n  const Cost inf = numeric_limits<Cost>::max() / 4;\n\n  shobon_mcf(int\
    \ n): n(n) {\n    ikeru.resize(n);\n    p.resize(n);\n  }  \n\n  void add_edge(int\
    \ from, int to, Cap cap, Cost cost){\n    int x = e.size();\n    e.push_back({from,\
    \ to, x + 1, cap, cost});\n    e.push_back({to, from, x, 0, -cost});\n    ikeru[from].push_back(x);\n\
    \    ikeru[to].push_back(x+1);\n  }\n\n  pair<Cap, Cost> flow(int from, int to,\
    \ Cap f){\n    Cap cap = 0;\n    Cost cost = 0;\n    \n    while(f > 0){\n   \
    \   vector<Cost> d(n, inf);\n      vector<int> cf(n, -1);\n      priority_queue<pair<Cost,int>>\
    \ pq;\n      pq.push(pair(0, from));\n      d[from] = 0;\n      while(!pq.empty()){\n\
    \        auto [tmp, i] = pq.top();\n        pq.pop();\n        tmp = -tmp;\n \
    \       if (tmp > d[i]) continue;\n        for (int x: ikeru[i]){\n          int\
    \ j = e[x].to;\n          if (e[x].cap == 0) continue;\n          if (chmin(d[j],\
    \ e[x].cost + tmp + p[i] - p[j])){\n            cf[j] = x;\n            pq.push(pair(-d[j],\
    \ j));\n          }\n        }\n      }\n\n      if (d[to] == inf) break;\n  \
    \    rep(i,0,n) p[i] += d[i];\n\n      Cap z = f;\n      int nw = to;\n      while\
    \ (nw != from){\n        chmin(z, e[cf[nw]].cap);\n        nw = e[cf[nw]].from;\n\
    \      }\n\n      f -= z;\n      cap += z;\n      cost += z * p[to];\n\n     \
    \ nw = to;\n      while (nw != from){\n        e[cf[nw]].cap -= z;\n        e[e[cf[nw]].rev].cap\
    \ += z;\n        nw = e[cf[nw]].from;\n      }\n    }\n\n    return pair(cap,\
    \ cost);\n  }\n\n  pair<Cap, Cost> flow(int from, int to){\n    return flow(from,\
    \ to, numeric_limits<Cap>::max());\n  }\n\n  // Type the following code if you\
    \ need\n  // Return the edges\n\n  vector<E> edges(){\n    vector<E> ret((int)e.size()\
    \ / 2);\n    rep(i,0,(int)e.size() / 2) ret[i] = e[2*i];\n    return ret;\n  }\n\
    \n  // Init the potential with Bellman-Ford\n\n  void potential_bellman_ford(int\
    \ from){\n    int m = (int)e.size() / 2;\n    fill(all(p), inf);\n    p[from]\
    \ = 0;\n    rep(num,0,n){\n      rep(x,0,m){\n        int i = e[2*x].from;\n \
    \       int j = e[2*x].to;\n        chmin(p[j], p[i] + e[2*x].cost);\n      }\n\
    \    }\n  }\n\n  // Init the potential with DP on DAG\n\n  void potential_dag(int\
    \ from){\n    vector<int> deg(n);\n    rep(x,0,(int)e.size()){\n      if (e[x].cap\
    \ > 0){\n        deg[e[x].to]++;\n      }\n    }\n    \n    assert(deg[from] ==\
    \ 0);\n\n    fill(all(p), inf);\n    p[from] = 0;\n    vector<int> mada;\n   \
    \ rep(i,0,n){\n      if (deg[i] == 0) mada.push_back(i);\n    }\n\n    int cnt\
    \ = 0;\n    while(!mada.empty()){\n      int i = mada.back();\n      mada.pop_back();\n\
    \      cnt++;\n      for (int x: ikeru[i]){\n        if (e[x].cap == 0) continue;\n\
    \        int j = e[x].to;\n        chmin(p[j], p[i] + e[x].cost);\n        deg[j]--;\n\
    \        if (deg[j] == 0){\n          mada.push_back(j);\n        }\n      }\n\
    \    }\n    \n    assert(cnt == n);\n  }\n\n};\n\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    using namespace std;\n\ntemplate<class Cap, class Cost> struct shobon_mcf {\n\
    \  struct E{\n    int from;\n    int to;\n    int rev;\n    Cap cap;\n    Cost\
    \ cost;\n  };\n  \n  int n;\n  vector<E> e;\n  vector<Cost> p;\n  vector<vector<int>>\
    \ ikeru;\n  const Cost inf = numeric_limits<Cost>::max() / 4;\n\n  shobon_mcf(int\
    \ n): n(n) {\n    ikeru.resize(n);\n    p.resize(n);\n  }  \n\n  void add_edge(int\
    \ from, int to, Cap cap, Cost cost){\n    int x = e.size();\n    e.push_back({from,\
    \ to, x + 1, cap, cost});\n    e.push_back({to, from, x, 0, -cost});\n    ikeru[from].push_back(x);\n\
    \    ikeru[to].push_back(x+1);\n  }\n\n  pair<Cap, Cost> flow(int from, int to,\
    \ Cap f){\n    Cap cap = 0;\n    Cost cost = 0;\n    \n    while(f > 0){\n   \
    \   vector<Cost> d(n, inf);\n      vector<int> cf(n, -1);\n      priority_queue<pair<Cost,int>>\
    \ pq;\n      pq.push(pair(0, from));\n      d[from] = 0;\n      while(!pq.empty()){\n\
    \        auto [tmp, i] = pq.top();\n        pq.pop();\n        tmp = -tmp;\n \
    \       if (tmp > d[i]) continue;\n        for (int x: ikeru[i]){\n          int\
    \ j = e[x].to;\n          if (e[x].cap == 0) continue;\n          if (chmin(d[j],\
    \ e[x].cost + tmp + p[i] - p[j])){\n            cf[j] = x;\n            pq.push(pair(-d[j],\
    \ j));\n          }\n        }\n      }\n\n      if (d[to] == inf) break;\n  \
    \    rep(i,0,n) p[i] += d[i];\n\n      Cap z = f;\n      int nw = to;\n      while\
    \ (nw != from){\n        chmin(z, e[cf[nw]].cap);\n        nw = e[cf[nw]].from;\n\
    \      }\n\n      f -= z;\n      cap += z;\n      cost += z * p[to];\n\n     \
    \ nw = to;\n      while (nw != from){\n        e[cf[nw]].cap -= z;\n        e[e[cf[nw]].rev].cap\
    \ += z;\n        nw = e[cf[nw]].from;\n      }\n    }\n\n    return pair(cap,\
    \ cost);\n  }\n\n  pair<Cap, Cost> flow(int from, int to){\n    return flow(from,\
    \ to, numeric_limits<Cap>::max());\n  }\n\n  // Type the following code if you\
    \ need\n  // Return the edges\n\n  vector<E> edges(){\n    vector<E> ret((int)e.size()\
    \ / 2);\n    rep(i,0,(int)e.size() / 2) ret[i] = e[2*i];\n    return ret;\n  }\n\
    \n  // Init the potential with Bellman-Ford\n\n  void potential_bellman_ford(int\
    \ from){\n    int m = (int)e.size() / 2;\n    fill(all(p), inf);\n    p[from]\
    \ = 0;\n    rep(num,0,n){\n      rep(x,0,m){\n        int i = e[2*x].from;\n \
    \       int j = e[2*x].to;\n        chmin(p[j], p[i] + e[2*x].cost);\n      }\n\
    \    }\n  }\n\n  // Init the potential with DP on DAG\n\n  void potential_dag(int\
    \ from){\n    vector<int> deg(n);\n    rep(x,0,(int)e.size()){\n      if (e[x].cap\
    \ > 0){\n        deg[e[x].to]++;\n      }\n    }\n    \n    assert(deg[from] ==\
    \ 0);\n\n    fill(all(p), inf);\n    p[from] = 0;\n    vector<int> mada;\n   \
    \ rep(i,0,n){\n      if (deg[i] == 0) mada.push_back(i);\n    }\n\n    int cnt\
    \ = 0;\n    while(!mada.empty()){\n      int i = mada.back();\n      mada.pop_back();\n\
    \      cnt++;\n      for (int x: ikeru[i]){\n        if (e[x].cap == 0) continue;\n\
    \        int j = e[x].to;\n        chmin(p[j], p[i] + e[x].cost);\n        deg[j]--;\n\
    \        if (deg[j] == 0){\n          mada.push_back(j);\n        }\n      }\n\
    \    }\n    \n    assert(cnt == n);\n  }\n\n};\n\n}\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/shobon_mcf.hpp
  requiredBy: []
  timestamp: '2023-11-16 03:38:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shobon_mcf.hpp
layout: document
title: shobon min cost flow
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