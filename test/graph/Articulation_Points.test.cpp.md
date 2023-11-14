---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: Low Link
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/graph/Articulation_Points.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 3 \"graph/low_link.hpp\"\n\nnamespace lib {\n\nstruct low_link {\n\
    \    low_link(const std::vector<std::vector<int>> &g) : n(g.size()), ord(n, -1),\
    \ low(n), par(n,-1) {\n        int k = 0;\n        auto dfs = [&](auto &&self,\
    \ int v) -> void {\n            low[v] = ord[v] = k++;\n            int cnt =\
    \ 0;\n            bool is_arti = false, is_second = false;\n            for(auto\
    \ nv: g[v]) {\n                if(ord[nv] == -1) {\n                    cnt++;\n\
    \                    par[nv] = v;\n                    self(self, nv);\n     \
    \               chmin(low[v], low[nv]);\n                    is_arti |= par[v]\
    \ != -1 && low[nv] >= ord[v];\n                    if(ord[v] < low[nv]) {\n  \
    \                      _bridge.emplace_back(std::minmax(v, nv));\n           \
    \         }\n                }\n                else if(nv != par[v] || is_second)\
    \ {\n                    chmin(low[v], ord[nv]);\n                }\n        \
    \        else {\n                    is_second = true;\n                }\n  \
    \          }\n            is_arti |= par[v] == -1 && cnt > 1;\n            if(is_arti)\
    \ _articulation.emplace_back(v);\n        };\n        dfs(dfs, 0);\n    }\n\n\
    \    bool is_bridge(int u, int v) {\n        if(par[v] != u) std::swap(u, v);\n\
    \        if(par[v] != u) return false;\n        return ord[u] < low[v];\n    }\n\
    \n    std::vector<std::pair<int,int>> bridge() {\n        return _bridge;\n  \
    \  }\n\n    std::vector<int> articulation() {\n        return _articulation;\n\
    \    }\n    \n    int n;\n    std::vector<int> ord, low, par, _articulation;\n\
    \    std::vector<std::pair<int,int>> _bridge;\n};\n\n}\n#line 6 \"test/graph/Articulation_Points.test.cpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    int n, m;\n    std::cin >> n >>\
    \ m;\n    std::vector g(n, std::vector<int>());\n    rep(i, 0, m) {\n        int\
    \ s, t;\n        std::cin >> s >> t;\n        g[s].emplace_back(t);\n        g[t].emplace_back(s);\n\
    \    }\n    low_link lwlk(g);\n    auto articulation = lwlk.articulation();\n\
    \    std::sort(all(articulation));\n    for (auto v : articulation) {\n      \
    \  std::cout << v << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include \"../../graph/low_link.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    int n, m;\n    std::cin >> n >>\
    \ m;\n    std::vector g(n, std::vector<int>());\n    rep(i, 0, m) {\n        int\
    \ s, t;\n        std::cin >> s >> t;\n        g[s].emplace_back(t);\n        g[t].emplace_back(s);\n\
    \    }\n    low_link lwlk(g);\n    auto articulation = lwlk.articulation();\n\
    \    std::sort(all(articulation));\n    for (auto v : articulation) {\n      \
    \  std::cout << v << '\\n';\n    }\n}"
  dependsOn:
  - graph/low_link.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/graph/Articulation_Points.test.cpp
  requiredBy: []
  timestamp: '2023-11-04 02:52:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Articulation_Points.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Articulation_Points.test.cpp
- /verify/test/graph/Articulation_Points.test.cpp.html
title: test/graph/Articulation_Points.test.cpp
---
