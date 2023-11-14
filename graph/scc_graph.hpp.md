---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: Two SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/aoj_3205.test.cpp
    title: test/math/aoj_3205.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/two_sat.test.cpp
    title: test/math/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/scc_graph.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    graph/scc_graph.hpp\"\n\nnamespace lib {\n\nstruct scc_graph {\n    vector<vector<int>>\
    \ g, rg;\n    int n, k;\n\n    vector<int> vs, cmp;\n    vector<int> seen;\n\n\
    \    void dfs(int v) {\n        seen[v] = 1;\n        for (auto &nv : g[v]) {\n\
    \            if (seen[nv] < 0) dfs(nv);\n        }\n        vs.emplace_back(v);\n\
    \    }\n\n    void rdfs(int v) {\n        cmp[v] = k;\n        for (auto nv :\
    \ rg[v]) {\n            if (cmp[nv] < 0) rdfs(nv);\n        }\n    }\n\n    scc_graph(int\
    \ n) : n(n) {\n        g.resize(n);\n        rg.resize(n);\n    }\n\n    void\
    \ add_edge(int from, int to) {\n        g[from].emplace_back(to);\n        rg[to].emplace_back(from);\n\
    \    }\n\n    void scc() {\n        seen.assign(n, -1);\n        rep(i, 0, n)\
    \ {\n            if (seen[i] < 0) dfs(i);\n        }\n        reverse(all(vs));\n\
    \        cmp.assign(n, -1);\n        k = 0;\n        for (auto &v : vs) {\n  \
    \          if (cmp[v] < 0) {\n                rdfs(v);\n                k++;\n\
    \            }\n        }\n    }\n\n    bool same(int u, int v) {\n        return\
    \ cmp[u] == cmp[v];\n    }\n\n    vector<int> scc_id() {\n        return cmp;\n\
    \    }\n\n    vector<vector<int>> create_graph() {\n        vector<vector<int>>\
    \ t(k);\n        rep(i, 0, n) {\n            int v = cmp[i];\n            for\
    \ (auto to : g[i]) {\n                int nv = cmp[to];\n                if (v\
    \ == nv) continue;\n                t[v].emplace_back(nv);\n            }\n  \
    \      }\n        rep(i, 0, k) {\n            sort(all(t[i]));\n            t[i].erase(unique(all(t[i])),\
    \ t[i].end());\n        }\n        return t;\n    }\n};\n\n}\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nstruct scc_graph {\n    vector<vector<int>> g, rg;\n    int n, k;\n\n    vector<int>\
    \ vs, cmp;\n    vector<int> seen;\n\n    void dfs(int v) {\n        seen[v] =\
    \ 1;\n        for (auto &nv : g[v]) {\n            if (seen[nv] < 0) dfs(nv);\n\
    \        }\n        vs.emplace_back(v);\n    }\n\n    void rdfs(int v) {\n   \
    \     cmp[v] = k;\n        for (auto nv : rg[v]) {\n            if (cmp[nv] <\
    \ 0) rdfs(nv);\n        }\n    }\n\n    scc_graph(int n) : n(n) {\n        g.resize(n);\n\
    \        rg.resize(n);\n    }\n\n    void add_edge(int from, int to) {\n     \
    \   g[from].emplace_back(to);\n        rg[to].emplace_back(from);\n    }\n\n \
    \   void scc() {\n        seen.assign(n, -1);\n        rep(i, 0, n) {\n      \
    \      if (seen[i] < 0) dfs(i);\n        }\n        reverse(all(vs));\n      \
    \  cmp.assign(n, -1);\n        k = 0;\n        for (auto &v : vs) {\n        \
    \    if (cmp[v] < 0) {\n                rdfs(v);\n                k++;\n     \
    \       }\n        }\n    }\n\n    bool same(int u, int v) {\n        return cmp[u]\
    \ == cmp[v];\n    }\n\n    vector<int> scc_id() {\n        return cmp;\n    }\n\
    \n    vector<vector<int>> create_graph() {\n        vector<vector<int>> t(k);\n\
    \        rep(i, 0, n) {\n            int v = cmp[i];\n            for (auto to\
    \ : g[i]) {\n                int nv = cmp[to];\n                if (v == nv) continue;\n\
    \                t[v].emplace_back(nv);\n            }\n        }\n        rep(i,\
    \ 0, k) {\n            sort(all(t[i]));\n            t[i].erase(unique(all(t[i])),\
    \ t[i].end());\n        }\n        return t;\n    }\n};\n\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/scc_graph.hpp
  requiredBy:
  - math/two_sat.hpp
  timestamp: '2023-05-26 21:39:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/two_sat.test.cpp
  - test/math/aoj_3205.test.cpp
documentation_of: graph/scc_graph.hpp
layout: document
title: SCC Graph
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