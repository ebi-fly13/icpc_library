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
    \ namespace lib;\n#line 3 \"graph/mf_graph.hpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\n\ntemplate <class Cap> struct mf_graph {\n    struct edge {\n        int\
    \ from, to;\n        Cap cap, flow;\n    };\n\n    struct nedge {\n        int\
    \ to, rev;\n        Cap cap;\n    };\n\n    int nn;\n    vector<pair<int, int>>\
    \ pos;\n    vector<vector<nedge>> g;\n\n    mf_graph() : nn(0) {}\n    explicit\
    \ mf_graph(int n) : nn(n), g(n) {}\n\n    int add_edge(int from, int to, Cap cap)\
    \ {\n        int m = pos.size();\n        pos.push_back({from, int(g[from].size())});\n\
    \        int frid = int(g[from].size());\n        int toid = int(g[to].size());\n\
    \        if (from == to) toid++;\n        g[from].push_back(nedge{to, toid, cap});\n\
    \        g[to].push_back(nedge{from, frid, 0});\n        return m;\n    }\n\n\
    \    Cap flow(int s, int t) { return flow(s, t, numeric_limits<Cap>::max()); }\n\
    \n    Cap flow(int s, int t, Cap flow_limit) {\n        vector<int> lv(nn), iter(nn);\n\
    \        queue<int> q;\n\n        auto bfs = [&]() {\n            fill(all(lv),\
    \ -1);\n            lv[s] = 0;\n            queue<int>().swap(q);\n          \
    \  q.push(s);\n            while (!q.empty()) {\n                int v = q.front();\n\
    \                q.pop();\n                for (auto e : g[v]) {\n           \
    \         if (e.cap == 0 || lv[e.to] >= 0) continue;\n                    lv[e.to]\
    \ = lv[v] + 1;\n                    if (e.to == t) return;\n                 \
    \   q.push(e.to);\n                }\n            }\n        };\n\n        auto\
    \ dfs = [&](auto self, int v, Cap up) {\n            if (v == s) return up;\n\
    \            Cap res = 0;\n            int lvvv = lv[v];\n            for (int&\
    \ i = iter[v]; i < int(g[v].size()); i++) {\n                nedge& e = g[v][i];\n\
    \                if (lvvv <= lv[e.to] || g[e.to][e.rev].cap == 0) continue;\n\
    \                Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
    \                if (d <= 0) continue;\n                g[v][i].cap += d;\n  \
    \              g[e.to][e.rev].cap -= d;\n                res += d;\n         \
    \       if (res == up) return res;\n            }\n            lv[v] = nn;\n \
    \           return res;\n        };\n\n        Cap flow = 0;\n        while (flow\
    \ < flow_limit) {\n            bfs();\n            if (lv[t] == -1) break;\n \
    \           fill(all(iter), 0);\n            Cap f = dfs(dfs, t, flow_limit -\
    \ flow);\n            if (!f) break;\n            flow += f;\n        }\n    \
    \    return flow;\n    }\n\n    /*\n\nif you want other functions, take from here\n\
    NOT VERIFIED.\n\nedge get_edge(int i) {\n    int m = int(pos.size());\n    auto\
    \ _e = g[pos[i].first][pos[i].second];\n    auto _re = g[_e.to][_e.rev];\n   \
    \ return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};\n}\n\nvector<edge>\
    \ edges() {\n    int m = int(pos.size());\n    vector<edge> result;\n    for (int\
    \ i = 0; i < m; i++) {\n        result.push_back(get_edge(i));\n    }\n    return\
    \ result;\n}\n\nvoid change_edge(int i, Cap new_cap, Cap new_flow) {\n    int\
    \ m = int(pos.size());\n    auto& _e = g[pos[i].first][pos[i].second];\n    auto&\
    \ _re = g[_e.to][_e.rev];\n    _e.cap = new_cap - new_flow;\n    _re.cap = new_flow;\n\
    }\n\nstd::vector<bool> min_cut(int s) {\n    vector<bool> visited(_n);\n    queue<int>\
    \ q;\n    q.push(s);\n    while (!q.empty()) {\n        int p = q.front();\n \
    \       q.pop();\n        visited[p] = true;\n        for (auto e : g[p]) {\n\
    \            if (e.cap && !visited[e.to]) {\n                visited[e.to] = true;\n\
    \                q.push(e.to);\n            }\n        }\n    }\n    return visited;\n\
    }\n\n    */\n};\n\n}  // namespace lib\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    using namespace std;\n\ntemplate <class Cap> struct mf_graph {\n    struct edge\
    \ {\n        int from, to;\n        Cap cap, flow;\n    };\n\n    struct nedge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n\n    int nn;\n    vector<pair<int,\
    \ int>> pos;\n    vector<vector<nedge>> g;\n\n    mf_graph() : nn(0) {}\n    explicit\
    \ mf_graph(int n) : nn(n), g(n) {}\n\n    int add_edge(int from, int to, Cap cap)\
    \ {\n        int m = pos.size();\n        pos.push_back({from, int(g[from].size())});\n\
    \        int frid = int(g[from].size());\n        int toid = int(g[to].size());\n\
    \        if (from == to) toid++;\n        g[from].push_back(nedge{to, toid, cap});\n\
    \        g[to].push_back(nedge{from, frid, 0});\n        return m;\n    }\n\n\
    \    Cap flow(int s, int t) { return flow(s, t, numeric_limits<Cap>::max()); }\n\
    \n    Cap flow(int s, int t, Cap flow_limit) {\n        vector<int> lv(nn), iter(nn);\n\
    \        queue<int> q;\n\n        auto bfs = [&]() {\n            fill(all(lv),\
    \ -1);\n            lv[s] = 0;\n            queue<int>().swap(q);\n          \
    \  q.push(s);\n            while (!q.empty()) {\n                int v = q.front();\n\
    \                q.pop();\n                for (auto e : g[v]) {\n           \
    \         if (e.cap == 0 || lv[e.to] >= 0) continue;\n                    lv[e.to]\
    \ = lv[v] + 1;\n                    if (e.to == t) return;\n                 \
    \   q.push(e.to);\n                }\n            }\n        };\n\n        auto\
    \ dfs = [&](auto self, int v, Cap up) {\n            if (v == s) return up;\n\
    \            Cap res = 0;\n            int lvvv = lv[v];\n            for (int&\
    \ i = iter[v]; i < int(g[v].size()); i++) {\n                nedge& e = g[v][i];\n\
    \                if (lvvv <= lv[e.to] || g[e.to][e.rev].cap == 0) continue;\n\
    \                Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
    \                if (d <= 0) continue;\n                g[v][i].cap += d;\n  \
    \              g[e.to][e.rev].cap -= d;\n                res += d;\n         \
    \       if (res == up) return res;\n            }\n            lv[v] = nn;\n \
    \           return res;\n        };\n\n        Cap flow = 0;\n        while (flow\
    \ < flow_limit) {\n            bfs();\n            if (lv[t] == -1) break;\n \
    \           fill(all(iter), 0);\n            Cap f = dfs(dfs, t, flow_limit -\
    \ flow);\n            if (!f) break;\n            flow += f;\n        }\n    \
    \    return flow;\n    }\n\n    /*\n\nif you want other functions, take from here\n\
    NOT VERIFIED.\n\nedge get_edge(int i) {\n    int m = int(pos.size());\n    auto\
    \ _e = g[pos[i].first][pos[i].second];\n    auto _re = g[_e.to][_e.rev];\n   \
    \ return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};\n}\n\nvector<edge>\
    \ edges() {\n    int m = int(pos.size());\n    vector<edge> result;\n    for (int\
    \ i = 0; i < m; i++) {\n        result.push_back(get_edge(i));\n    }\n    return\
    \ result;\n}\n\nvoid change_edge(int i, Cap new_cap, Cap new_flow) {\n    int\
    \ m = int(pos.size());\n    auto& _e = g[pos[i].first][pos[i].second];\n    auto&\
    \ _re = g[_e.to][_e.rev];\n    _e.cap = new_cap - new_flow;\n    _re.cap = new_flow;\n\
    }\n\nstd::vector<bool> min_cut(int s) {\n    vector<bool> visited(_n);\n    queue<int>\
    \ q;\n    q.push(s);\n    while (!q.empty()) {\n        int p = q.front();\n \
    \       q.pop();\n        visited[p] = true;\n        for (auto e : g[p]) {\n\
    \            if (e.cap && !visited[e.to]) {\n                visited[e.to] = true;\n\
    \                q.push(e.to);\n            }\n        }\n    }\n    return visited;\n\
    }\n\n    */\n};\n\n}  // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: graph/mf_graph.hpp
  requiredBy: []
  timestamp: '2023-05-08 15:48:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/mf_graph.hpp
layout: document
redirect_from:
- /library/graph/mf_graph.hpp
- /library/graph/mf_graph.hpp.html
title: graph/mf_graph.hpp
---
