---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: tree/LowestCommonAncestor.hpp
    title: LowestCommonAncestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/tree/Lowest_Common_Ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
    tree/LowestCommonAncestor.hpp\"\n\n#line 4 \"tree/LowestCommonAncestor.hpp\"\n\
    \nnamespace lib {\n\nstruct LowestCommonAncestor {\n    int n;\n    std::vector<std::vector<int>>\
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
    \ - 2 * depth[l];\n    };\n};\n\n}  // namespace lib\n#line 5 \"test/tree/Lowest_Common_Ancestor.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector g(n,\
    \ std::vector<int>());\n    rep(i, 1, n) {\n        int p;\n        std::cin >>\
    \ p;\n        g[p].emplace_back(i);\n        g[i].emplace_back(p);\n    }\n  \
    \  lib::LowestCommonAncestor lca(g, 0);\n    while (q--) {\n        int u, v;\n\
    \        std::cin >> u >> v;\n        std::cout << lca.lca(u, v) << '\\n';\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template/template.hpp\"\
    \n#include \"../../tree/LowestCommonAncestor.hpp\"\n\nint main() {\n    int n,\
    \ q;\n    std::cin >> n >> q;\n    std::vector g(n, std::vector<int>());\n   \
    \ rep(i, 1, n) {\n        int p;\n        std::cin >> p;\n        g[p].emplace_back(i);\n\
    \        g[i].emplace_back(p);\n    }\n    lib::LowestCommonAncestor lca(g, 0);\n\
    \    while (q--) {\n        int u, v;\n        std::cin >> u >> v;\n        std::cout\
    \ << lca.lca(u, v) << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - tree/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: test/tree/Lowest_Common_Ancestor.test.cpp
  requiredBy: []
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Lowest_Common_Ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Lowest_Common_Ancestor.test.cpp
- /verify/test/tree/Lowest_Common_Ancestor.test.cpp.html
title: test/tree/Lowest_Common_Ancestor.test.cpp
---
