---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/HeavyLightDecomposition.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"tree/HeavyLightDecomposition.hpp\"\
    \n\nnamespace lib {\n\nusing namespace std;\n\nstruct HeavyLightDecomposition\
    \ {\n  private:\n    void dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n \
    \           if (nv == par[v]) continue;\n            par[nv] = v;\n          \
    \  depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n            sz[v] += sz[nv];\n\
    \            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v]) swap(nv, g[v][0]);\n\
    \        }\n    }\n\n    void dfs_hld(int v) {\n        static int t = 0;\n  \
    \      in[v] = t++;\n        for (auto nv : g[v]) {\n            if (nv == par[v])\
    \ continue;\n            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n          \
    \  dfs_hld(nv);\n        }\n        out[v] = t;\n    }\n\n    // [u, v) \u30D1\
    \u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n        vector<pair<int, int>> res;\n  \
    \      while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n\
    \            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    vector<pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    HeavyLightDecomposition(const vector<vector<int>> &gh, int root\
    \ = 0)\n        : n(gh.size()),\n          g(gh),\n          sz(n, 1),\n     \
    \     in(n),\n          out(n),\n          nxt(n),\n          par(n, -1),\n  \
    \        depth(n, 0) {\n        dfs_sz(root);\n        dfs_hld(root);\n    }\n\
    \n    int idx(int u) const {\n        return in[u];\n    }\n\n    int lca(int\
    \ u, int v) const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u]\
    \ < in[v]) swap(u, v);\n            u = par[nxt[u]];\n        }\n        return\
    \ depth[u] < depth[v] ? u : v;\n    }\n\n    int distance(int u, int v) const\
    \ {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n   \
    \ template <class F>\n    void path_noncommutative_query(int u, int v, bool vertex,\n\
    \                                   const F &f) const {\n        int l = lca(u,\
    \ v);\n        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex)\
    \ f(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n\
    \    }\n\n    template <class F> void subtree_query(int u, bool vertex, const\
    \ F &f) {\n        f(in[u] + int(!vertex), out[u]);\n    }\n\n  private:\n   \
    \ int n;\n    vector<vector<int>> g;\n    vector<int> sz, in, out, nxt, par, depth;\n\
    };\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nusing namespace std;\n\nstruct HeavyLightDecomposition {\n  private:\n    void\
    \ dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n            if (nv == par[v])\
    \ continue;\n            par[nv] = v;\n            depth[nv] = depth[v] + 1;\n\
    \            dfs_sz(nv);\n            sz[v] += sz[nv];\n            if (sz[nv]\
    \ > sz[g[v][0]] || g[v][0] == par[v]) swap(nv, g[v][0]);\n        }\n    }\n\n\
    \    void dfs_hld(int v) {\n        static int t = 0;\n        in[v] = t++;\n\
    \        for (auto nv : g[v]) {\n            if (nv == par[v]) continue;\n   \
    \         nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n\
    \        }\n        out[v] = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\
    \u5F97 (v \u306F u \u306E\u7956\u5148)\n    vector<pair<int, int>> ascend(int\
    \ u, int v) const {\n        vector<pair<int, int>> res;\n        while (nxt[u]\
    \ != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n           \
    \ u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u], in[v]\
    \ + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\u5F97\
    \ (u \u306F v \u306E\u7956\u5148)\n    vector<pair<int, int>> descend(int u, int\
    \ v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v]) return\
    \ {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n       \
    \ res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n  public:\n\
    \    HeavyLightDecomposition(const vector<vector<int>> &gh, int root = 0)\n  \
    \      : n(gh.size()),\n          g(gh),\n          sz(n, 1),\n          in(n),\n\
    \          out(n),\n          nxt(n),\n          par(n, -1),\n          depth(n,\
    \ 0) {\n        dfs_sz(root);\n        dfs_hld(root);\n    }\n\n    int idx(int\
    \ u) const {\n        return in[u];\n    }\n\n    int lca(int u, int v) const\
    \ {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v]) swap(u,\
    \ v);\n            u = par[nxt[u]];\n        }\n        return depth[u] < depth[v]\
    \ ? u : v;\n    }\n\n    int distance(int u, int v) const {\n        return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    template <class F>\n    void\
    \ path_noncommutative_query(int u, int v, bool vertex,\n                     \
    \              const F &f) const {\n        int l = lca(u, v);\n        for (auto\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l], in[l] + 1);\n\
    \        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template\
    \ <class F> void subtree_query(int u, bool vertex, const F &f) {\n        f(in[u]\
    \ + int(!vertex), out[u]);\n    }\n\n  private:\n    int n;\n    vector<vector<int>>\
    \ g;\n    vector<int> sz, in, out, nxt, par, depth;\n};\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2023-05-14 18:25:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Vertex_Add_Path_Sum.test.cpp
documentation_of: tree/HeavyLightDecomposition.hpp
layout: document
title: HeavyLightDecomposition
---

## 説明

木をHLDする。パスクエリ、部分木クエリを処理することができる。

### コンストラクタ

`HeavyLightDecomposition(std::vector<std::vector<int>> g, int root = 0)`

木グラフ g と root ノード番号を与えてHLDする。デフォルトで root は頂点 0

### idx(int u)

頂点 u のDFS行きがけ順の番号を返す。このidxの位置にデータ構造のインデックスを対応させればパスクエリや部分木クエリを処理することができる。具体的には使い方を参照。

### lca(int u, int v)

頂点 u, v のLCAを返す。

### distance(int u, int v)

頂点 u, v の距離を返す。

### path_noncommutative_query(int u, int v, bool vertex, const F &f)

パス u-v にクエリ`f`を適用する。非可換。vertexがtrueのとき、頂点に属性がある。vertexがfalseのとき、辺に属性がある。親-子間の辺属性は子のidxに持つ。

### subtree_query(int u, bool vertex, const F &f)

頂点 u の部分木にクエリ`f`を適用する。vertexがtrueのとき、根頂点である u にもクエリを適用する。

## 使い方

```
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    rep(i,0,m) {
        int u,v;
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    lib::HeavyLightDecomposition hld(g);
    segtree<S, op, e> seg1(n) 
    segtree<S, op_rev, e> seg2(n);
    auto set = [&](int u, S x) {
        int idx = hld.idx(u);
        seg1.set(idx, x);
        seg2.set(idx, x);
    };
    S ans = e();
    auto f = [&](int l, int r) {
        if(l <= r) ans = op(ans, seg1.prod(l, r));
        else ans = op(ans, seg2.prod(r, l)); 
    };
    int u,v;
    std::cin >> u >> v;
    ans = e();
    hld.path_noncommutative_query(u, v, true, f);
    std::cout << ans << '\n';
}
```
