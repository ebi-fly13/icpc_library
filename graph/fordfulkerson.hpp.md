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
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    #define rep(i, s, n) for (int i = s; i < (int)(n); i++)\n#define rrep(i, s, n)\
    \ for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return\
    \ false;\n    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T\
    \ &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n\nnamespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using\
    \ namespace lib;\n#line 3 \"graph/fordfulkerson.hpp\"\n\nnamespace lib {\nusing\
    \ namespace std;\n\ntemplate <typename fa> struct FordFulkerson {\n    struct\
    \ edge {\n        int to;\n        fa cap;\n        int rev;\n        bool isrev;\n\
    \    };\n\n    const fa INF;\n    vector<vector<edge>> g;\n    vector<int> used;\n\
    \    int ts;\n\n    explicit FordFulkerson(int v)\n        : INF(numeric_limits<fa>::max()),\
    \ g(v), used(v, -1), ts(0) {}\n\n    void add_edge(int from, int to, fa cap) {\n\
    \        g[from].push_back((edge){to, cap, (int)g[to].size(), false});\n     \
    \   g[to].push_back((edge){from, 0, (int)g[from].size() - 1, true});\n    }\n\
    \    fa dfs(int v, int t, fa flow) {\n        if (v == t) return flow;\n     \
    \   used[v] = ts;\n        for (auto &e : g[v]) {\n            if (e.cap > 0 &&\
    \ used[e.to] != ts) {\n                fa d = dfs(e.to, t, min(flow, e.cap));\n\
    \                if (d > 0) {\n                    e.cap -= d;\n             \
    \       g[e.to][e.rev].cap += d;\n                    return d;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\n\n    fa flow(int\
    \ s, int t) {\n        fa ret = 0;\n        for (fa f; (f = dfs(s, t, INF)) >\
    \ 0; ts++) ret += f;\n        ts++;\n        return ret;\n    }\n};\n\n}  // namespace\
    \ lib\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    using namespace std;\n\ntemplate <typename fa> struct FordFulkerson {\n    struct\
    \ edge {\n        int to;\n        fa cap;\n        int rev;\n        bool isrev;\n\
    \    };\n\n    const fa INF;\n    vector<vector<edge>> g;\n    vector<int> used;\n\
    \    int ts;\n\n    explicit FordFulkerson(int v)\n        : INF(numeric_limits<fa>::max()),\
    \ g(v), used(v, -1), ts(0) {}\n\n    void add_edge(int from, int to, fa cap) {\n\
    \        g[from].push_back((edge){to, cap, (int)g[to].size(), false});\n     \
    \   g[to].push_back((edge){from, 0, (int)g[from].size() - 1, true});\n    }\n\
    \    fa dfs(int v, int t, fa flow) {\n        if (v == t) return flow;\n     \
    \   used[v] = ts;\n        for (auto &e : g[v]) {\n            if (e.cap > 0 &&\
    \ used[e.to] != ts) {\n                fa d = dfs(e.to, t, min(flow, e.cap));\n\
    \                if (d > 0) {\n                    e.cap -= d;\n             \
    \       g[e.to][e.rev].cap += d;\n                    return d;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\n\n    fa flow(int\
    \ s, int t) {\n        fa ret = 0;\n        for (fa f; (f = dfs(s, t, INF)) >\
    \ 0; ts++) ret += f;\n        ts++;\n        return ret;\n    }\n};\n\n}  // namespace\
    \ lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/fordfulkerson.hpp
  requiredBy: []
  timestamp: '2023-05-08 15:48:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fordfulkerson.hpp
layout: document
title: FordFulkerson
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
	lib::FordFulkerson<int> mf(n);
	for(int i=0;i<m;i++){
		int u,v,c;cin>>u>>v>>c;
		mf.add_edge(u,v,c);
	}
	cout<<mf.flow(0,n-1)<<endl;
}
```