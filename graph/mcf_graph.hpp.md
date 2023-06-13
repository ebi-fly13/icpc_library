---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Minimum_Flow.test.cpp
    title: test/graph/Minimum_Flow.test.cpp
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
    \ lib\n\n// using namespace lib;\n#line 3 \"graph/mcf_graph.hpp\"\n\nnamespace\
    \ lib {\nusing namespace std;\n\nstruct MinCostFlow {\n    int n;\n    vector<vector<vector<ll>>>\
    \ g;\n    vector<ll> h, dis;\n    vector<int> pv, pe;\n\n    MinCostFlow(int v)\
    \ : n(v), g(v), dis(v), pv(v), pe(v) {}\n\n    void add_edge(int from, int to,\
    \ ll cap, ll cost) {\n        g[from].push_back({to, cap, cost, (int)g[to].size()});\n\
    \        g[to].push_back({from, 0, -cost, (int)g[from].size()-1});\n    }\n\n\
    \    ll flow(int s, int t, ll f) {\n        ll res = 0;\n        h.assign(n, 0);\n\
    \        using Q = pair<ll, int>;\n        while (f > 0) {\n            priority_queue<Q,\
    \ vector<Q>, greater<Q>> que;\n            dis.assign(n, LLONG_MAX);\n       \
    \     dis[s] = 0;\n            que.push({0, s});\n            while (que.size())\
    \ {\n                Q q = que.top();\n                int v = q.second;\n   \
    \             que.pop();\n                if (dis[v] < q.first) continue;\n\t\t\
    \t\trep(i,0,g[v].size()){\n                    auto edge = g[v][i];\n        \
    \            int to = edge[0];\n                    ll cap = edge[1], cost = edge[2];\n\
    \                    if (cap > 0 and dis[to] > dis[v] + cost + h[v] - h[to]) {\n\
    \                        dis[to] = dis[v] + cost + h[v] - h[to];\n           \
    \             pv[to] = v;\n                        pe[to] = i;\n             \
    \           que.push({dis[to], to});\n                    }\n                }\n\
    \            }\n            if (dis[t] == LLONG_MAX) return -1;\n            rep(i,0,n)\
    \ h[i] += dis[i];\n            ll d = f;\n            for (int i=t; i!=s; i=pv[i])\
    \ d = min(d, g[pv[i]][pe[i]][1]);\n            f -= d;\n            res += d *\
    \ h[t];\n            for (int i=t; i!=s; i=pv[i]) {\n                auto& edge\
    \ = g[pv[i]][pe[i]];\n                edge[1] -= d;\n                g[i][edge[3]][1]\
    \ += d;\n            }\n        }\n        return res;\n    }\n};\n\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    using namespace std;\n\nstruct MinCostFlow {\n    int n;\n    vector<vector<vector<ll>>>\
    \ g;\n    vector<ll> h, dis;\n    vector<int> pv, pe;\n\n    MinCostFlow(int v)\
    \ : n(v), g(v), dis(v), pv(v), pe(v) {}\n\n    void add_edge(int from, int to,\
    \ ll cap, ll cost) {\n        g[from].push_back({to, cap, cost, (int)g[to].size()});\n\
    \        g[to].push_back({from, 0, -cost, (int)g[from].size()-1});\n    }\n\n\
    \    ll flow(int s, int t, ll f) {\n        ll res = 0;\n        h.assign(n, 0);\n\
    \        using Q = pair<ll, int>;\n        while (f > 0) {\n            priority_queue<Q,\
    \ vector<Q>, greater<Q>> que;\n            dis.assign(n, LLONG_MAX);\n       \
    \     dis[s] = 0;\n            que.push({0, s});\n            while (que.size())\
    \ {\n                Q q = que.top();\n                int v = q.second;\n   \
    \             que.pop();\n                if (dis[v] < q.first) continue;\n\t\t\
    \t\trep(i,0,g[v].size()){\n                    auto edge = g[v][i];\n        \
    \            int to = edge[0];\n                    ll cap = edge[1], cost = edge[2];\n\
    \                    if (cap > 0 and dis[to] > dis[v] + cost + h[v] - h[to]) {\n\
    \                        dis[to] = dis[v] + cost + h[v] - h[to];\n           \
    \             pv[to] = v;\n                        pe[to] = i;\n             \
    \           que.push({dis[to], to});\n                    }\n                }\n\
    \            }\n            if (dis[t] == LLONG_MAX) return -1;\n            rep(i,0,n)\
    \ h[i] += dis[i];\n            ll d = f;\n            for (int i=t; i!=s; i=pv[i])\
    \ d = min(d, g[pv[i]][pe[i]][1]);\n            f -= d;\n            res += d *\
    \ h[t];\n            for (int i=t; i!=s; i=pv[i]) {\n                auto& edge\
    \ = g[pv[i]][pe[i]];\n                edge[1] -= d;\n                g[i][edge[3]][1]\
    \ += d;\n            }\n        }\n        return res;\n    }\n};\n\n}\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/mcf_graph.hpp
  requiredBy: []
  timestamp: '2023-06-02 02:20:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Minimum_Flow.test.cpp
documentation_of: graph/mcf_graph.hpp
layout: document
redirect_from:
- /library/graph/mcf_graph.hpp
- /library/graph/mcf_graph.hpp.html
title: graph/mcf_graph.hpp
---
