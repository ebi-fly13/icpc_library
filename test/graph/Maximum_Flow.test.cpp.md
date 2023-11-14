---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/fordfulkerson.hpp
    title: FordFulkerson
  - icon: ':heavy_check_mark:'
    path: graph/mf_graph.hpp
    title: max flow
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/graph/Maximum_Flow.test.cpp\"\n#define PROBLEM \\\n\
    \    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n\n\
    #line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 3 \"graph/fordfulkerson.hpp\"\n\nnamespace lib {\nusing namespace\
    \ std;\n\ntemplate <typename fa> struct FordFulkerson {\n    struct edge {\n \
    \       int to;\n        fa cap;\n        int rev;\n        bool isrev;\n    };\n\
    \n    const fa INF;\n    vector<vector<edge>> g;\n    vector<int> used;\n    int\
    \ ts;\n\n    explicit FordFulkerson(int v)\n        : INF(numeric_limits<fa>::max()),\
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
    \ lib\n#line 3 \"graph/mf_graph.hpp\"\n\nnamespace lib {\nusing namespace std;\n\
    \ntemplate <class Cap> struct mf_graph {\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    struct nedge {\n        int to, rev;\n\
    \        Cap cap;\n    };\n\n    int nn;\n    vector<pair<int, int>> pos;\n  \
    \  vector<vector<nedge>> g;\n\n    mf_graph() : nn(0) {}\n    explicit mf_graph(int\
    \ n) : nn(n), g(n) {}\n\n    int add_edge(int from, int to, Cap cap) {\n     \
    \   int m = pos.size();\n        pos.push_back({from, int(g[from].size())});\n\
    \        int frid = int(g[from].size());\n        int toid = int(g[to].size());\n\
    \        if (from == to) toid++;\n        g[from].push_back(nedge{to, toid, cap});\n\
    \        g[to].push_back(nedge{from, frid, 0});\n        return m;\n    }\n\n\
    \    Cap flow(int s, int t) {\n        return flow(s, t, numeric_limits<Cap>::max());\n\
    \    }\n\n    Cap flow(int s, int t, Cap flow_limit) {\n        vector<int> lv(nn),\
    \ iter(nn);\n        queue<int> q;\n\n        auto bfs = [&]() {\n           \
    \ fill(all(lv), -1);\n            lv[s] = 0;\n            queue<int>().swap(q);\n\
    \            q.push(s);\n            while (!q.empty()) {\n                int\
    \ v = q.front();\n                q.pop();\n                for (auto e : g[v])\
    \ {\n                    if (e.cap == 0 || lv[e.to] >= 0) continue;\n        \
    \            lv[e.to] = lv[v] + 1;\n                    if (e.to == t) return;\n\
    \                    q.push(e.to);\n                }\n            }\n       \
    \ };\n\n        auto dfs = [&](auto self, int v, Cap up) {\n            if (v\
    \ == s) return up;\n            Cap res = 0;\n            int lvvv = lv[v];\n\
    \            for (int& i = iter[v]; i < int(g[v].size()); i++) {\n           \
    \     nedge& e = g[v][i];\n                if (lvvv <= lv[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n                Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
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
    }\n\n    */\n};\n\n}  // namespace lib\n#line 7 \"test/graph/Maximum_Flow.test.cpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    int n, m;\n    std::cin >> n >>\
    \ m;\n    FordFulkerson<int> g1(n);\n    mf_graph<int> g2(n);\n    rep(i, 0, m)\
    \ {\n        int u, v, c;\n        std::cin >> u >> v >> c;\n        g1.add_edge(u,\
    \ v, c);\n        g2.add_edge(u, v, c);\n    }\n    int flow = g1.flow(0, n -\
    \ 1);\n    assert(flow == g2.flow(0, n - 1));\n    std::cout << flow << '\\n';\n\
    }\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../../graph/fordfulkerson.hpp\"\n#include \"../../graph/mf_graph.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nusing namespace lib;\n\nint main()\
    \ {\n    int n, m;\n    std::cin >> n >> m;\n    FordFulkerson<int> g1(n);\n \
    \   mf_graph<int> g2(n);\n    rep(i, 0, m) {\n        int u, v, c;\n        std::cin\
    \ >> u >> v >> c;\n        g1.add_edge(u, v, c);\n        g2.add_edge(u, v, c);\n\
    \    }\n    int flow = g1.flow(0, n - 1);\n    assert(flow == g2.flow(0, n - 1));\n\
    \    std::cout << flow << '\\n';\n}"
  dependsOn:
  - graph/fordfulkerson.hpp
  - template/template.hpp
  - graph/mf_graph.hpp
  isVerificationFile: true
  path: test/graph/Maximum_Flow.test.cpp
  requiredBy: []
  timestamp: '2023-06-02 01:23:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Maximum_Flow.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Maximum_Flow.test.cpp
- /verify/test/graph/Maximum_Flow.test.cpp.html
title: test/graph/Maximum_Flow.test.cpp
---
