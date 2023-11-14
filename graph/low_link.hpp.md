---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Articulation_Points.test.cpp
    title: test/graph/Articulation_Points.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Bridges.test.cpp
    title: test/graph/Bridges.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ lib\n\n// using namespace lib;\n#line 3 \"graph/low_link.hpp\"\n\nnamespace\
    \ lib {\n\nstruct low_link {\n    low_link(const std::vector<std::vector<int>>\
    \ &g) : n(g.size()), ord(n, -1), low(n), par(n,-1) {\n        int k = 0;\n   \
    \     auto dfs = [&](auto &&self, int v) -> void {\n            low[v] = ord[v]\
    \ = k++;\n            int cnt = 0;\n            bool is_arti = false, is_second\
    \ = false;\n            for(auto nv: g[v]) {\n                if(ord[nv] == -1)\
    \ {\n                    cnt++;\n                    par[nv] = v;\n          \
    \          self(self, nv);\n                    chmin(low[v], low[nv]);\n    \
    \                is_arti |= par[v] != -1 && low[nv] >= ord[v];\n             \
    \       if(ord[v] < low[nv]) {\n                        _bridge.emplace_back(std::minmax(v,\
    \ nv));\n                    }\n                }\n                else if(nv\
    \ != par[v] || is_second) {\n                    chmin(low[v], ord[nv]);\n   \
    \             }\n                else {\n                    is_second = true;\n\
    \                }\n            }\n            is_arti |= par[v] == -1 && cnt\
    \ > 1;\n            if(is_arti) _articulation.emplace_back(v);\n        };\n \
    \       dfs(dfs, 0);\n    }\n\n    bool is_bridge(int u, int v) {\n        if(par[v]\
    \ != u) std::swap(u, v);\n        if(par[v] != u) return false;\n        return\
    \ ord[u] < low[v];\n    }\n\n    std::vector<std::pair<int,int>> bridge() {\n\
    \        return _bridge;\n    }\n\n    std::vector<int> articulation() {\n   \
    \     return _articulation;\n    }\n    \n    int n;\n    std::vector<int> ord,\
    \ low, par, _articulation;\n    std::vector<std::pair<int,int>> _bridge;\n};\n\
    \n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\n\
    struct low_link {\n    low_link(const std::vector<std::vector<int>> &g) : n(g.size()),\
    \ ord(n, -1), low(n), par(n,-1) {\n        int k = 0;\n        auto dfs = [&](auto\
    \ &&self, int v) -> void {\n            low[v] = ord[v] = k++;\n            int\
    \ cnt = 0;\n            bool is_arti = false, is_second = false;\n           \
    \ for(auto nv: g[v]) {\n                if(ord[nv] == -1) {\n                \
    \    cnt++;\n                    par[nv] = v;\n                    self(self,\
    \ nv);\n                    chmin(low[v], low[nv]);\n                    is_arti\
    \ |= par[v] != -1 && low[nv] >= ord[v];\n                    if(ord[v] < low[nv])\
    \ {\n                        _bridge.emplace_back(std::minmax(v, nv));\n     \
    \               }\n                }\n                else if(nv != par[v] ||\
    \ is_second) {\n                    chmin(low[v], ord[nv]);\n                }\n\
    \                else {\n                    is_second = true;\n             \
    \   }\n            }\n            is_arti |= par[v] == -1 && cnt > 1;\n      \
    \      if(is_arti) _articulation.emplace_back(v);\n        };\n        dfs(dfs,\
    \ 0);\n    }\n\n    bool is_bridge(int u, int v) {\n        if(par[v] != u) std::swap(u,\
    \ v);\n        if(par[v] != u) return false;\n        return ord[u] < low[v];\n\
    \    }\n\n    std::vector<std::pair<int,int>> bridge() {\n        return _bridge;\n\
    \    }\n\n    std::vector<int> articulation() {\n        return _articulation;\n\
    \    }\n    \n    int n;\n    std::vector<int> ord, low, par, _articulation;\n\
    \    std::vector<std::pair<int,int>> _bridge;\n};\n\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy: []
  timestamp: '2023-11-04 02:52:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Bridges.test.cpp
  - test/graph/Articulation_Points.test.cpp
documentation_of: graph/low_link.hpp
layout: document
title: Low Link
---

## 説明

グラフを渡してlow linkを求める。 $O(N)$

### is_bridge(int u, int v)

辺 $u-v$ が橋であるか判定。そのような辺がない場合もfalseを返す。

### bridge()

橋を列挙して返す。

### articulation()

関節点を列挙して返す。
