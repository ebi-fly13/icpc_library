---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: tree/RerootingDP.hpp
    title: RerootingDP
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/tree/Tree_Path_Composite_Sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
    tree/RerootingDP.hpp\"\n\n#line 4 \"tree/RerootingDP.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int),\n\
    \          V (*put_vertex)(E, int)>\nstruct RerootingDP {\n    struct edge {\n\
    \        int to, idx, xdi;\n    };\n    RerootingDP(int _n = 0) : n(_n) {\n  \
    \      es.resize(n);\n    }\n    void add_edge(int u, int v, int idx1, int idx2)\
    \ {\n        es[u].push_back({v, idx1, idx2});\n        es[v].push_back({u, idx2,\
    \ idx1});\n    }\n    vector<V> build(int v = 0) {\n        root = v;\n      \
    \  outs.resize(n);\n        subdp.resize(n);\n        in.resize(n), up.resize(n);\n\
    \        int tnow = 0;\n        dfs(root, -1, tnow);\n        return subdp;\n\
    \    }\n    vector<V> reroot() {\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n        bfs(root);\n\
    \        return answers;\n    }\n    V get(int r, int v) {\n        if (r == v)\
    \ return answers[r];\n        if (!(in[v] < in[r] && up[r] <= up[v])) return subdp[v];\n\
    \        int le = 0, ri = outs[v].size();\n        while (ri - le > 1) {\n   \
    \         int md = (le + ri) / 2;\n            if (in[es[v][md].to] <= in[r])\n\
    \                le = md;\n            else\n                ri = md;\n      \
    \  }\n        return reverse_dp[es[v][le].to];\n    }\n    const vector<edge>\
    \ &operator[](int idx) const {\n        return es[idx];\n    }\n\n  private:\n\
    \    int n, root;\n    vector<vector<edge>> es;\n    vector<vector<E>> outs;\n\
    \    vector<E> reverse_edge;\n    vector<V> subdp, reverse_dp, answers;\n    vector<int>\
    \ in, up;\n    void dfs(int v, int p, int &t) {\n        E val = e();\n      \
    \  in[v] = t++;\n        for (auto &u : es[v]) {\n            if (u.to == p &&\
    \ u.to != es[v].back().to) swap(u, es[v].back());\n            if (u.to == p)\
    \ continue;\n            dfs(u.to, v, t);\n            E nval = put_edge(subdp[u.to],\
    \ u.idx);\n            outs[v].emplace_back(nval);\n            val = merge(val,\
    \ nval);\n        }\n        subdp[v] = put_vertex(val, v);\n        up[v] = t;\n\
    \    }\n    void bfs(int v) {\n        int siz = outs[v].size();\n        vector<E>\
    \ lui(siz + 1), rui(siz + 1);\n        lui[0] = e(), rui[siz] = e();\n       \
    \ for (int i = 0; i < siz; i++) lui[i + 1] = merge(lui[i], outs[v][i]);\n    \
    \    for (int i = siz - 1; i >= 0; i--)\n            rui[i] = merge(outs[v][i],\
    \ rui[i + 1]);\n        for (int i = 0; i < siz; i++) {\n            reverse_dp[es[v][i].to]\
    \ = put_vertex(\n                merge(merge(lui[i], rui[i + 1]), reverse_edge[v]),\
    \ v);\n            reverse_edge[es[v][i].to] =\n                put_edge(reverse_dp[es[v][i].to],\
    \ es[v][i].xdi);\n            bfs(es[v][i].to);\n        }\n        answers[v]\
    \ = put_vertex(merge(lui[siz], reverse_edge[v]), v);\n    }\n};\n\n}  // namespace\
    \ lib\n#line 2 \"utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate <ll m> struct modint {\n    using mint = modint;\n    ll a;\n\
    \n    modint(ll x = 0) : a((x % m + m) % m) {}\n    static ll mod() {\n      \
    \  return m;\n    }\n    ll& val() {\n        return a;\n    }\n    mint pow(ll\
    \ n) {\n        mint res = 1;\n        mint x = a;\n        while (n) {\n    \
    \        if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n   \
    \     }\n        return res;\n    }\n    mint inv() {\n        return pow(m -\
    \ 2);\n    }\n    mint& operator+=(const mint rhs) {\n        a += rhs.a;\n  \
    \      if (a >= m) a -= m;\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint rhs) {\n        if (a < rhs.a) a += m;\n        a -= rhs.a;\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint rhs) {\n        a = a * rhs.a\
    \ % m;\n        return *this;\n    }\n    mint& operator/=(mint rhs) {\n     \
    \   *this *= rhs.inv();\n        return *this;\n    }\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ mint operator+() const {\n        return *this;\n    }\n    mint operator-()\
    \ const {\n        return mint() - *this;\n    }\n};\n\nusing modint998244353\
    \ = modint<998244353>;\nusing modint1000000007 = modint<1'000'000'007>;\n\n} \
    \ // namespace lib\n#line 6 \"test/tree/Tree_Path_Composite_Sum.test.cpp\"\n\n\
    using namespace lib;\nusing mint = modint998244353;\nusing pmm = pair<mint, mint>;\n\
    \npmm merge(pmm a, pmm b) {\n    return pmm(a.first + b.first, a.second + b.second);\n\
    }\npmm e() {\n    return pmm(0, 0);\n}\n\nvector<mint> a, b, c;\npmm pute(pmm\
    \ x, int e) {\n    return pmm(b[e] * x.first + c[e] * x.second, x.second);\n}\n\
    pmm putv(pmm x, int v) {\n    return pmm(x.first + a[v], x.second + 1);\n}\n\n\
    int main() {\n    int n;\n    cin >> n;\n    a.resize(n), b.resize(n - 1), c.resize(n\
    \ - 1);\n    rep(i, 0, n) {\n        ll x;\n        cin >> x;\n        a[i] =\
    \ x;\n    }\n    RerootingDP<pmm, pmm, merge, e, pute, putv> g(n);\n    rep(i,\
    \ 0, n - 1) {\n        int u, v;\n        cin >> u >> v;\n        g.add_edge(u,\
    \ v, i, i);\n        ll y, z;\n        cin >> y >> z;\n        b[i] = y, c[i]\
    \ = z;\n    }\n    g.build();\n    auto ans = g.reroot();\n    rep(i, 0, n) cout\
    \ << ans[i].first.val() << \" \\n\"[i == n - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../tree/RerootingDP.hpp\"\
    \n#include \"../../utility/modint.hpp\"\n\nusing namespace lib;\nusing mint =\
    \ modint998244353;\nusing pmm = pair<mint, mint>;\n\npmm merge(pmm a, pmm b) {\n\
    \    return pmm(a.first + b.first, a.second + b.second);\n}\npmm e() {\n    return\
    \ pmm(0, 0);\n}\n\nvector<mint> a, b, c;\npmm pute(pmm x, int e) {\n    return\
    \ pmm(b[e] * x.first + c[e] * x.second, x.second);\n}\npmm putv(pmm x, int v)\
    \ {\n    return pmm(x.first + a[v], x.second + 1);\n}\n\nint main() {\n    int\
    \ n;\n    cin >> n;\n    a.resize(n), b.resize(n - 1), c.resize(n - 1);\n    rep(i,\
    \ 0, n) {\n        ll x;\n        cin >> x;\n        a[i] = x;\n    }\n    RerootingDP<pmm,\
    \ pmm, merge, e, pute, putv> g(n);\n    rep(i, 0, n - 1) {\n        int u, v;\n\
    \        cin >> u >> v;\n        g.add_edge(u, v, i, i);\n        ll y, z;\n \
    \       cin >> y >> z;\n        b[i] = y, c[i] = z;\n    }\n    g.build();\n \
    \   auto ans = g.reroot();\n    rep(i, 0, n) cout << ans[i].first.val() << \"\
    \ \\n\"[i == n - 1];\n}"
  dependsOn:
  - template/template.hpp
  - tree/RerootingDP.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/tree/Tree_Path_Composite_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Tree_Path_Composite_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Tree_Path_Composite_Sum.test.cpp
- /verify/test/tree/Tree_Path_Composite_Sum.test.cpp.html
title: test/tree/Tree_Path_Composite_Sum.test.cpp
---
