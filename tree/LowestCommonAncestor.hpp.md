---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/pck2022y11.test.cpp
    title: test/data_structure/pck2022y11.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Lowest_Common_Ancestor.test.cpp
    title: test/tree/Lowest_Common_Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/aoj_0489.test.cpp
    title: test/tree/aoj_0489.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/LowestCommonAncestor.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    tree/LowestCommonAncestor.hpp\"\n\nnamespace lib {\n\nstruct LowestCommonAncestor\
    \ {\n    int n;\n    std::vector<std::vector<int>> table;\n    std::vector<int>\
    \ depth;\n    int log = 25;\n\n    LowestCommonAncestor(const std::vector<std::vector<int>>\
    \ &gh, int root = 0)\n        : n(gh.size()) {\n        table = std::vector(log,\
    \ std::vector<int>(n, -1));\n        depth.assign(n, 0);\n        auto dfs = [&](auto\
    \ &&self, int v) -> void {\n            for (auto nv : gh[v]) {\n            \
    \    if (table[0][v] == nv) continue;\n                table[0][nv] = v;\n   \
    \             depth[nv] = depth[v] + 1;\n                self(self, nv);\n   \
    \         }\n        };\n        dfs(dfs, root);\n        table[0][root] = root;\n\
    \        rep(i, 0, log - 1) {\n            rep(v, 0, n) {\n                table[i\
    \ + 1][v] = table[i][table[i][v]];\n            }\n        }\n    }\n\n    int\
    \ la(int u, int k) const {\n        if (depth[u] < k) return -1;\n        rrep(i,\
    \ 0, log) {\n            if ((k >> i) & 1) {\n                u = table[i][u];\n\
    \            }\n        }\n        return u;\n    }\n\n    int lca(int u, int\
    \ v) const {\n        if (depth[u] < depth[v]) std::swap(u, v);\n        u = la(u,\
    \ depth[u] - depth[v]);\n        if (u == v) return u;\n        rrep(i, 0, log)\
    \ {\n            if (table[i][u] != table[i][v]) {\n                u = table[i][u];\n\
    \                v = table[i][v];\n            }\n        }\n        return table[0][u];\n\
    \    }\n\n    int distance(int u, int v) const {\n        int l = lca(u, v);\n\
    \        return depth[u] + depth[v] - 2 * depth[l];\n    };\n};\n\n}  // namespace\
    \ lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nstruct LowestCommonAncestor {\n    int n;\n    std::vector<std::vector<int>>\
    \ table;\n    std::vector<int> depth;\n    int log = 25;\n\n    LowestCommonAncestor(const\
    \ std::vector<std::vector<int>> &gh, int root = 0)\n        : n(gh.size()) {\n\
    \        table = std::vector(log, std::vector<int>(n, -1));\n        depth.assign(n,\
    \ 0);\n        auto dfs = [&](auto &&self, int v) -> void {\n            for (auto\
    \ nv : gh[v]) {\n                if (table[0][v] == nv) continue;\n          \
    \      table[0][nv] = v;\n                depth[nv] = depth[v] + 1;\n        \
    \        self(self, nv);\n            }\n        };\n        dfs(dfs, root);\n\
    \        table[0][root] = root;\n        rep(i, 0, log - 1) {\n            rep(v,\
    \ 0, n) {\n                table[i + 1][v] = table[i][table[i][v]];\n        \
    \    }\n        }\n    }\n\n    int la(int u, int k) const {\n        if (depth[u]\
    \ < k) return -1;\n        rrep(i, 0, log) {\n            if ((k >> i) & 1) {\n\
    \                u = table[i][u];\n            }\n        }\n        return u;\n\
    \    }\n\n    int lca(int u, int v) const {\n        if (depth[u] < depth[v])\
    \ std::swap(u, v);\n        u = la(u, depth[u] - depth[v]);\n        if (u ==\
    \ v) return u;\n        rrep(i, 0, log) {\n            if (table[i][u] != table[i][v])\
    \ {\n                u = table[i][u];\n                v = table[i][v];\n    \
    \        }\n        }\n        return table[0][u];\n    }\n\n    int distance(int\
    \ u, int v) const {\n        int l = lca(u, v);\n        return depth[u] + depth[v]\
    \ - 2 * depth[l];\n    };\n};\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: tree/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Lowest_Common_Ancestor.test.cpp
  - test/tree/aoj_0489.test.cpp
  - test/data_structure/pck2022y11.test.cpp
documentation_of: tree/LowestCommonAncestor.hpp
layout: document
title: Lowest Common Ancestor
---

## 説明

木のLCAをダブリングで求める。

### コンストラクタ

`LowestCommonAncestor(std::vector<std::vector<int>> g, int root = 0)`

木グラフ g と root ノード番号を与えてLCAの前計算をする。デフォルトで root は頂点 0

### la(int u, int k)

頂点 u から 親方向に k だけ上った頂点を返す。

### lca(int u, int v)

頂点 u, v のLCAを返す。

### distance(int u, int v)

頂点 u, v の距離を返す。
