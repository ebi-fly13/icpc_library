---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc_graph.hpp
    title: SCC Graph
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: Two SAT
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/math/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"math/two_sat.hpp\"\n\n#line 2 \"graph/scc_graph.hpp\"\n\n#line\
    \ 4 \"graph/scc_graph.hpp\"\n\nnamespace lib {\n\nstruct scc_graph {\n    vector<vector<int>>\
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
    \ t[i].end());\n        }\n        return t;\n    }\n};\n\n}\n#line 5 \"math/two_sat.hpp\"\
    \n\nnamespace lib {\n\nstruct two_sat {\n    two_sat(int n) : n(n), scc(2 * n),\
    \ _ans(n) {}\n\n    void add_clause(int i, bool f, int j, bool g) {\n        assert(0\
    \ <= i && i < n);\n        assert(0 <= j && j < n);\n        scc.add_edge(2 *\
    \ i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n        scc.add_edge(2 * j + (g ? 0\
    \ : 1), 2 * i + (f ? 1 : 0));\n    }\n\n    bool satisfiable() {\n        scc.scc();\n\
    \        auto id = scc.scc_id();\n        rep(i, 0, n) {\n            if (scc.same(2\
    \ * i, 2 * i + 1)) return false;\n            _ans[i] = id[2 * i] < id[2 * i +\
    \ 1];\n        }\n        return true;\n    }\n\n    vector<bool> ans() {\n  \
    \      return _ans;\n    }\n    int n;\n    scc_graph scc;\n    vector<bool> _ans;\n\
    };\n\n}  // namespace lib\n#line 5 \"test/math/two_sat.test.cpp\"\n\nusing namespace\
    \ lib;\n\nint main() {\n    char p;\n    std::string cnf;\n    std::cin >> p >>\
    \ cnf;\n    int n, m;\n    std::cin >> n >> m;\n    two_sat ts(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int a, b, c;\n        std::cin >> a >> b >> c;\n\
    \        ts.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);\n    }\n\
    \    bool flag = ts.satisfiable();\n    std::cout << \"s \" << (flag ? \"SATISFIABLE\"\
    \ : \"UNSATISFIABLE\") << std::endl;\n    if (flag) {\n        std::cout << \"\
    v\";\n        auto ans = ts.ans();\n        for (int i = 0; i < n; i++) {\n  \
    \          std::cout << \" \" << (ans[i] ? i + 1 : -(i + 1));\n        }\n   \
    \     std::cout << \" 0\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../template/template.hpp\"\n#include \"../../math/two_sat.hpp\"\n\nusing namespace\
    \ lib;\n\nint main() {\n    char p;\n    std::string cnf;\n    std::cin >> p >>\
    \ cnf;\n    int n, m;\n    std::cin >> n >> m;\n    two_sat ts(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int a, b, c;\n        std::cin >> a >> b >> c;\n\
    \        ts.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);\n    }\n\
    \    bool flag = ts.satisfiable();\n    std::cout << \"s \" << (flag ? \"SATISFIABLE\"\
    \ : \"UNSATISFIABLE\") << std::endl;\n    if (flag) {\n        std::cout << \"\
    v\";\n        auto ans = ts.ans();\n        for (int i = 0; i < n; i++) {\n  \
    \          std::cout << \" \" << (ans[i] ? i + 1 : -(i + 1));\n        }\n   \
    \     std::cout << \" 0\\n\";\n    }\n}"
  dependsOn:
  - template/template.hpp
  - math/two_sat.hpp
  - graph/scc_graph.hpp
  isVerificationFile: true
  path: test/math/two_sat.test.cpp
  requiredBy: []
  timestamp: '2023-05-26 21:39:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/math/two_sat.test.cpp
- /verify/test/math/two_sat.test.cpp.html
title: test/math/two_sat.test.cpp
---