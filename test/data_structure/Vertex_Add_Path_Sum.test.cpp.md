---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/data_structure/Vertex_Add_Path_Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 2 \"\
    data_structure/segtree.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"data_structure/segtree.hpp\"\
    \n\nnamespace lib {\n\nusing namespace std;\n\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct segtree {\n  private:\n    int n;\n    int sz;\n    vector<S>\
    \ data;\n\n    void update(int i) {\n        data[i] = op(data[2 * i], data[2\
    \ * i + 1]);\n    }\n\n  public:\n    segtree(int n) : segtree(vector<S>(n, e()))\
    \ {}\n    segtree(const vector<S> &v) : n((int)v.size()), sz(1) {\n        while\
    \ (sz < n) sz *= 2;\n        data = vector<S>(2 * sz, e());\n        rep(i, 0,\
    \ n) {\n            data[sz + i] = v[i];\n        }\n        rrep(i, 1, sz) update(i);\n\
    \    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < n);\n     \
    \   p += sz;\n        data[p] = x;\n        while (p > 1) {\n            p >>=\
    \ 1;\n            update(p);\n        }\n    }\n\n    S get(int p) {\n       \
    \ assert(0 <= p && p < n);\n        return data[p + sz];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        S sml = e(),\
    \ smr = e();\n        l += sz;\n        r += sz;\n        while (l < r) {\n  \
    \          if (l & 1) sml = op(sml, data[l++]);\n            if (r & 1) smr =\
    \ op(data[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() {\n        return data[1];\n\
    \    }\n\n    template <class F> int max_right(int l, F f) {\n        assert(0\
    \ <= l && l <= n);\n        assert(f(e()));\n        if (l == n) return n;\n \
    \       l += sz;\n        S sm = e();\n        do {\n            while (l % 2\
    \ == 0) l >>= 1;\n            if (!f(op(sm, data[l]))) {\n                while\
    \ (l < sz) {\n                    l = 2 * l;\n                    if (f(op(sm,\
    \ data[l]))) {\n                        sm = op(sm, data[l]);\n              \
    \          l++;\n                    }\n                }\n                return\
    \ l - sz;\n            }\n            sm = op(sm, data[l]);\n            l++;\n\
    \        } while ((l & -l) != l);\n        return n;\n    }\n\n    template <class\
    \ F> int min_left(int r, F f) {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        S sm = e();\n      \
    \  do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n   \
    \         if (!f(op(data[r], sm))) {\n                while (r < sz) {\n     \
    \               r = 2 * r + 1;\n                    if (f(op(data[r], sm))) {\n\
    \                        sm = op(data[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - sz;\n\
    \            }\n            sm = op(data[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n\n}  // namespace lib\n#line 2 \"tree/HeavyLightDecomposition.hpp\"\
    \n\n#line 4 \"tree/HeavyLightDecomposition.hpp\"\n\nnamespace lib {\n\nusing namespace\
    \ std;\n\nstruct HeavyLightDecomposition {\n  private:\n    void dfs_sz(int v)\
    \ {\n        for (auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n\
    \            par[nv] = v;\n            depth[nv] = depth[v] + 1;\n           \
    \ dfs_sz(nv);\n            sz[v] += sz[nv];\n            if (sz[nv] > sz[g[v][0]]\
    \ || g[v][0] == par[v]) swap(nv, g[v][0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ v) {\n        static int t = 0;\n        in[v] = t++;\n        for (auto nv\
    \ : g[v]) {\n            if (nv == par[v]) continue;\n            nxt[nv] = (nv\
    \ == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n        }\n        out[v]\
    \ = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\
    \u7956\u5148)\n    vector<pair<int, int>> ascend(int u, int v) const {\n     \
    \   vector<pair<int, int>> res;\n        while (nxt[u] != nxt[v]) {\n        \
    \    res.emplace_back(in[u], in[nxt[u]]);\n            u = par[nxt[u]];\n    \
    \    }\n        if (u != v) res.emplace_back(in[u], in[v] + 1);\n        return\
    \ res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\u5F97 (u \u306F v \u306E\
    \u7956\u5148)\n    vector<pair<int, int>> descend(int u, int v) const {\n    \
    \    if (u == v) return {};\n        if (nxt[u] == nxt[v]) return {{in[u] + 1,\
    \ in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]],\
    \ in[v]);\n        return res;\n    }\n\n  public:\n    HeavyLightDecomposition(const\
    \ vector<vector<int>> &gh, int root = 0)\n        : n(gh.size()),\n          g(gh),\n\
    \          sz(n, 1),\n          in(n),\n          out(n),\n          nxt(n),\n\
    \          par(n, -1),\n          depth(n, 0) {\n        dfs_sz(root);\n     \
    \   dfs_hld(root);\n    }\n\n    int idx(int u) const {\n        return in[u];\n\
    \    }\n\n    int lca(int u, int v) const {\n        while (nxt[u] != nxt[v])\
    \ {\n            if (in[u] < in[v]) swap(u, v);\n            u = par[nxt[u]];\n\
    \        }\n        return depth[u] < depth[v] ? u : v;\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    template <class F>\n    void path_noncommutative_query(int u, int\
    \ v, bool vertex,\n                                   const F &f) const {\n  \
    \      int l = lca(u, v);\n        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n\
    \        if (vertex) f(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l,\
    \ v)) f(a, b + 1);\n    }\n\n    template <class F> void subtree_query(int u,\
    \ bool vertex, const F &f) {\n        f(in[u] + int(!vertex), out[u]);\n    }\n\
    \n  private:\n    int n;\n    vector<vector<int>> g;\n    vector<int> sz, in,\
    \ out, nxt, par, depth;\n};\n\n}  // namespace lib\n#line 6 \"test/data_structure/Vertex_Add_Path_Sum.test.cpp\"\
    \n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\
    i64 e() {\n    return 0;\n}\n\nint main() {\n    int n, q;\n    std::cin >> n\
    \ >> q;\n    std::vector<i64> a(n);\n    for (int i = 0; i < n; ++i) {\n     \
    \   std::cin >> a[i];\n    }\n    std::vector g(n, std::vector<int>());\n    for\
    \ (int i = 0; i < n - 1; ++i) {\n        int u, v;\n        std::cin >> u >> v;\n\
    \        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n    }\n    lib::HeavyLightDecomposition\
    \ hld(g);\n    lib::segtree<i64, op, e> seg(n);\n    i64 ans = e();\n    auto\
    \ set = [&](int u, i64 x) {\n        int idx = hld.idx(u);\n        seg.set(idx,\
    \ seg.get(idx) + x);\n    };\n    auto f = [&](int l, int r) {\n        if (l\
    \ <= r)\n            ans = op(ans, seg.prod(l, r));\n        else\n          \
    \  ans = op(ans, seg.prod(r, l));\n    };\n    for (int i = 0; i < n; i++) {\n\
    \        set(i, a[i]);\n    }\n    while (q--) {\n        int flag;\n        std::cin\
    \ >> flag;\n        if (flag == 0) {\n            int p;\n            i64 x;\n\
    \            std::cin >> p >> x;\n            set(p, x);\n        } else {\n \
    \           int u, v;\n            std::cin >> u >> v;\n            ans = e();\n\
    \            hld.path_noncommutative_query(u, v, true, f);\n            std::cout\
    \ << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../data_structure/segtree.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../tree/HeavyLightDecomposition.hpp\"\n\nusing i64 = std::int64_t;\n\
    i64 op(i64 a, i64 b) {\n    return a + b;\n}\ni64 e() {\n    return 0;\n}\n\n\
    int main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<i64> a(n);\n\
    \    for (int i = 0; i < n; ++i) {\n        std::cin >> a[i];\n    }\n    std::vector\
    \ g(n, std::vector<int>());\n    for (int i = 0; i < n - 1; ++i) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n    lib::HeavyLightDecomposition hld(g);\n    lib::segtree<i64, op, e>\
    \ seg(n);\n    i64 ans = e();\n    auto set = [&](int u, i64 x) {\n        int\
    \ idx = hld.idx(u);\n        seg.set(idx, seg.get(idx) + x);\n    };\n    auto\
    \ f = [&](int l, int r) {\n        if (l <= r)\n            ans = op(ans, seg.prod(l,\
    \ r));\n        else\n            ans = op(ans, seg.prod(r, l));\n    };\n   \
    \ for (int i = 0; i < n; i++) {\n        set(i, a[i]);\n    }\n    while (q--)\
    \ {\n        int flag;\n        std::cin >> flag;\n        if (flag == 0) {\n\
    \            int p;\n            i64 x;\n            std::cin >> p >> x;\n   \
    \         set(p, x);\n        } else {\n            int u, v;\n            std::cin\
    \ >> u >> v;\n            ans = e();\n            hld.path_noncommutative_query(u,\
    \ v, true, f);\n            std::cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - template/template.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 22:32:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Vertex_Add_Path_Sum.test.cpp
- /verify/test/data_structure/Vertex_Add_Path_Sum.test.cpp.html
title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
---
