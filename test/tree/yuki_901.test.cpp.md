---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: tree/lca_based_auxiliary_tree.hpp
    title: LCA based Auxiliary Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/901
    links:
    - https://yukicoder.me/problems/no/901
  bundledCode: "#line 1 \"test/tree/yuki_901.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/901\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"tree/HeavyLightDecomposition.hpp\"\n\n#line 4 \"tree/HeavyLightDecomposition.hpp\"\
    \n\nnamespace lib {\n\nusing namespace std;\n\nstruct HeavyLightDecomposition\
    \ {\n  private:\n    void dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n \
    \           if (nv == par[v]) continue;\n            par[nv] = v;\n          \
    \  depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n            sz[v] += sz[nv];\n\
    \            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v]) swap(nv, g[v][0]);\n\
    \        }\n    }\n\n    void dfs_hld(int v) {\n        in[v] = t++;\n       \
    \ for (auto nv : g[v]) {\n            if (nv == par[v]) continue;\n          \
    \  nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n      \
    \  }\n        out[v] = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\u5F97\
    \ (v \u306F u \u306E\u7956\u5148)\n    vector<pair<int, int>> ascend(int u, int\
    \ v) const {\n        vector<pair<int, int>> res;\n        while (nxt[u] != nxt[v])\
    \ {\n            res.emplace_back(in[u], in[nxt[u]]);\n            u = par[nxt[u]];\n\
    \        }\n        if (u != v) res.emplace_back(in[u], in[v] + 1);\n        return\
    \ res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\u5F97 (u \u306F v \u306E\
    \u7956\u5148)\n    vector<pair<int, int>> descend(int u, int v) const {\n    \
    \    if (u == v) return {};\n        if (nxt[u] == nxt[v]) return {{in[u] + 1,\
    \ in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]],\
    \ in[v]);\n        return res;\n    }\n\n  public:\n    HeavyLightDecomposition(const\
    \ vector<vector<int>> &gh, int root = 0)\n        : n(gh.size()),\n          g(gh),\n\
    \          sz(n, 1),\n          in(n),\n          out(n),\n          nxt(n),\n\
    \          par(n, -1),\n          depth(n, 0) {\n        nxt[root] = root;\n \
    \       dfs_sz(root);\n        dfs_hld(root);\n    }\n\n    int idx(int u) const\
    \ {\n        return in[u];\n    }\n\n    int lca(int u, int v) const {\n     \
    \   while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v]) swap(u, v);\n \
    \           u = par[nxt[u]];\n        }\n        return depth[u] < depth[v] ?\
    \ u : v;\n    }\n\n    int distance(int u, int v) const {\n        return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    template <class F>\n    void\
    \ path_noncommutative_query(int u, int v, bool vertex,\n                     \
    \              const F &f) const {\n        int l = lca(u, v);\n        for (auto\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l], in[l] + 1);\n\
    \        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template\
    \ <class F> void subtree_query(int u, bool vertex, const F &f) {\n        f(in[u]\
    \ + int(!vertex), out[u]);\n    }\n\n    int parent(int v) {\n        return par[v];\n\
    \    }\n\n    std::vector<std::pair<int,int>> lca_based_auxiliary_tree(std::vector<int>);\n\
    \n  private:\n    int n, t = 0;\n    vector<vector<int>> g;\n    vector<int> sz,\
    \ in, out, nxt, par, depth;\n};\n\n}  // namespace lib\n#line 2 \"tree/lca_based_auxiliary_tree.hpp\"\
    \n\n#line 4 \"tree/lca_based_auxiliary_tree.hpp\"\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\nvector<pair<int, int>> HeavyLightDecomposition::lca_based_auxiliary_tree(\n\
    \    vector<int> vs) {\n    if (vs.empty()) return {};\n    sort(all(vs), [&](int\
    \ u, int v) { return in[u] < in[v]; });\n    auto s = vs;\n    for (int i = 1;\
    \ i < int(vs.size()); i++) {\n        s.emplace_back(lca(vs[i - 1], vs[i]));\n\
    \    }\n    std::sort(all(s), [&](int u, int v) { return in[u] < in[v]; });\n\
    \    s.erase(unique(all(s)), s.end());\n    stack<int> st;\n    st.push(s[0]);\n\
    \    int sz = s.size();\n    std::vector<std::pair<int, int>> dfs_order(sz);\n\
    \    dfs_order[0] = {s[0], -1};\n    rep(i, 1, sz) {\n        int v = s[i];\n\
    \        while (!st.empty()) {\n            int u = st.top();\n            if\
    \ (in[u] <= in[v] && in[v] < out[u]) {\n                break;\n            }\
    \ else {\n                st.pop();\n            }\n        }\n        assert(!st.empty());\n\
    \        int par = st.top();\n        dfs_order[i] = {v, par};\n        st.push(v);\n\
    \    }\n    return dfs_order;\n}\n\n}  // namespace lib\n#line 6 \"test/tree/yuki_901.test.cpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    int n;\n    std::cin >> n;\n   \
    \ std::vector g(n, std::vector<int>());\n    std::vector<std::tuple<int, int,\
    \ ll>> edges(n - 1);\n    for (auto &[u, v, w] : edges) {\n        std::cin >>\
    \ u >> v >> w;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n    HeavyLightDecomposition hld(g);\n    std::vector<ll> sum(n + 1, 0);\n\
    \    for (auto [u, v, w] : edges) {\n        if (hld.parent(v) == u) std::swap(u,\
    \ v);\n        sum[hld.idx(u) + 1] += w;\n    }\n    rep(i, 0, n) {\n        sum[i\
    \ + 1] += sum[i];\n    }\n    auto path_sum = [&](int u, int v) -> ll {\n    \
    \    ll ret = 0;\n        auto f = [&](int l, int r) -> void {\n            if\
    \ (l > r) std::swap(l, r);\n            ret += sum[r] - sum[l];\n        };\n\
    \        hld.path_noncommutative_query(u, v, false, f);\n        return ret;\n\
    \    };\n    int q;\n    std::cin >> q;\n    while (q--) {\n        int k;\n \
    \       std::cin >> k;\n        std::vector<int> vs(k);\n        for (auto &v\
    \ : vs) std::cin >> v;\n        ll ans = 0;\n        auto auxiliary_tree = hld.lca_based_auxiliary_tree(vs);\n\
    \        for (auto [v, par] : auxiliary_tree) {\n            if (par != -1) {\n\
    \                ans += path_sum(v, par);\n            }\n        }\n        std::cout\
    \ << ans << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/901\"\n\n#include \"../../template/template.hpp\"\
    \n#include \"../../tree/HeavyLightDecomposition.hpp\"\n#include \"../../tree/lca_based_auxiliary_tree.hpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    int n;\n    std::cin >> n;\n   \
    \ std::vector g(n, std::vector<int>());\n    std::vector<std::tuple<int, int,\
    \ ll>> edges(n - 1);\n    for (auto &[u, v, w] : edges) {\n        std::cin >>\
    \ u >> v >> w;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n    HeavyLightDecomposition hld(g);\n    std::vector<ll> sum(n + 1, 0);\n\
    \    for (auto [u, v, w] : edges) {\n        if (hld.parent(v) == u) std::swap(u,\
    \ v);\n        sum[hld.idx(u) + 1] += w;\n    }\n    rep(i, 0, n) {\n        sum[i\
    \ + 1] += sum[i];\n    }\n    auto path_sum = [&](int u, int v) -> ll {\n    \
    \    ll ret = 0;\n        auto f = [&](int l, int r) -> void {\n            if\
    \ (l > r) std::swap(l, r);\n            ret += sum[r] - sum[l];\n        };\n\
    \        hld.path_noncommutative_query(u, v, false, f);\n        return ret;\n\
    \    };\n    int q;\n    std::cin >> q;\n    while (q--) {\n        int k;\n \
    \       std::cin >> k;\n        std::vector<int> vs(k);\n        for (auto &v\
    \ : vs) std::cin >> v;\n        ll ans = 0;\n        auto auxiliary_tree = hld.lca_based_auxiliary_tree(vs);\n\
    \        for (auto [v, par] : auxiliary_tree) {\n            if (par != -1) {\n\
    \                ans += path_sum(v, par);\n            }\n        }\n        std::cout\
    \ << ans << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - template/template.hpp
  - tree/HeavyLightDecomposition.hpp
  - tree/lca_based_auxiliary_tree.hpp
  isVerificationFile: true
  path: test/tree/yuki_901.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 15:39:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/yuki_901.test.cpp
layout: document
redirect_from:
- /verify/test/tree/yuki_901.test.cpp
- /verify/test/tree/yuki_901.test.cpp.html
title: test/tree/yuki_901.test.cpp
---
