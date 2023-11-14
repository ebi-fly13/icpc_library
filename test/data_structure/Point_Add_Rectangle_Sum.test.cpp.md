---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_segtree_2d.hpp
    title: offline 2D segtree
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/data_structure/Point_Add_Rectangle_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n\
    #line 2 \"data_structure/offline_segtree_2d.hpp\"\n\n/*\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\n\
    \    verify   : http://codeforces.com/contest/893/submission/125531718\n*/\n\n\
    #line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"data_structure/compress.hpp\"\n\n#line 4 \"data_structure/compress.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp)\
    \ : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}\n#line 10 \"data_structure/offline_segtree_2d.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class data_structure>\n\
    struct offline_segtree_2d {\n    offline_segtree_2d() = default;\n\n    void pre_set(std::pair<int,\
    \ int> p) {\n        ps.emplace_back(p);\n    }\n\n    void build() {\n      \
    \  for (auto [x, y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n\
    \        while (sz < xs.size()) sz <<= 1;\n        ys.resize(2 * sz);\n      \
    \  for (auto [x, y] : ps) {\n            int i = xs.get(x) + sz;\n           \
    \ ys[i].add(y);\n            while (i > 1) {\n                i >>= 1;\n     \
    \           ys[i].add(y);\n            }\n        }\n        for (int i = 0; i\
    \ < 2 * sz; i++) {\n            ys[i].build();\n            data.emplace_back(data_structure(ys[i].size()));\n\
    \        }\n    }\n\n    void set(int i, int j, S val) {\n        i = xs.get(i);\n\
    \        i += sz;\n        data[i].set(ys[i].get(j), val);\n        while (i >\
    \ 1) {\n            i >>= 1;\n            S res = e();\n            if (ys[2 *\
    \ i].find(j)) {\n                res = op(res, data[2 * i].get(ys[2 * i].get(j)));\n\
    \            }\n            if (ys[2 * i + 1].find(j)) {\n                res\
    \ = op(res, data[2 * i + 1].get(ys[2 * i + 1].get(j)));\n            }\n     \
    \       data[i].set(ys[i].get(j), res);\n        }\n    }\n\n    S get(int i,\
    \ int j) {\n        i = xs.get(i) + sz;\n        return data[i].get(ys[i].get(j));\n\
    \    }\n\n    S prod(int l, int d, int r, int u) {\n        l = xs.get(l) + sz;\n\
    \        r = xs.get(r) + sz;\n        S res = e();\n        while (l < r) {\n\
    \            if (l & 1) {\n                res = op(res, data[l].prod(ys[l].get(d),\
    \ ys[l].get(u)));\n                l++;\n            }\n            if (r & 1)\
    \ {\n                r--;\n                res = op(data[r].prod(ys[r].get(d),\
    \ ys[r].get(u)), res);\n            }\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return res;\n    }\n\n  private:\n    int sz = 1;\n \
    \   std::vector<std::pair<int, int>> ps;\n    compress<int> xs;\n    std::vector<compress<int>>\
    \ ys;\n    std::vector<data_structure> data;\n};\n\n}  // namespace ebi\n#line\
    \ 2 \"data_structure/segtree.hpp\"\n\n#line 4 \"data_structure/segtree.hpp\"\n\
    \nnamespace lib {\n\nusing namespace std;\n\ntemplate <class S, S (*op)(S, S),\
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
    \ r);\n        return 0;\n    }\n};\n\n}  // namespace lib\n#line 6 \"test/data_structure/Point_Add_Rectangle_Sum.test.cpp\"\
    \n\nusing namespace lib;\n\nll op(ll a, ll b) {\n    return a + b;\n}\n\nll e()\
    \ {\n    return 0;\n}\n\nstruct Query {\n    ll x, y, w;\n    ll l, d, r, u;\n\
    \    int flag;\n};\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n \
    \   std::vector<ll> x(n), y(n), w(n);\n    for (int i = 0; i < n; i++) {\n   \
    \     std::cin >> x[i] >> y[i] >> w[i];\n    }\n    std::vector<Query> query(q);\n\
    \    for (int i = 0; i < q; i++) {\n        std::cin >> query[i].flag;\n     \
    \   if (query[i].flag == 0) {\n            std::cin >> query[i].x >> query[i].y\
    \ >> query[i].w;\n        } else {\n            std::cin >> query[i].l >> query[i].d\
    \ >> query[i].r >> query[i].u;\n        }\n    }\n    offline_segtree_2d<ll, op,\
    \ e, segtree<ll, op, e>> seg2d;\n    for (int i = 0; i < n; i++) {\n        seg2d.pre_set({x[i],\
    \ y[i]});\n    }\n    for (int i = 0; i < q; i++) {\n        if (query[i].flag\
    \ == 0) {\n            seg2d.pre_set({query[i].x, query[i].y});\n        }\n \
    \   }\n    seg2d.build();\n    for (int i = 0; i < n; i++) {\n        seg2d.set(x[i],\
    \ y[i], seg2d.get(x[i], y[i]) + w[i]);\n    }\n    for (int i = 0; i < q; i++)\
    \ {\n        if (query[i].flag == 0) {\n            seg2d.set(query[i].x, query[i].y,\n\
    \                      seg2d.get(query[i].x, query[i].y) + query[i].w);\n    \
    \    } else {\n            std::cout << seg2d.prod(query[i].l, query[i].d, query[i].r,\n\
    \                                    query[i].u)\n                      << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../data_structure/offline_segtree_2d.hpp\"\n#include \"../../data_structure/segtree.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nusing namespace lib;\n\nll op(ll\
    \ a, ll b) {\n    return a + b;\n}\n\nll e() {\n    return 0;\n}\n\nstruct Query\
    \ {\n    ll x, y, w;\n    ll l, d, r, u;\n    int flag;\n};\n\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<ll> x(n), y(n), w(n);\n\
    \    for (int i = 0; i < n; i++) {\n        std::cin >> x[i] >> y[i] >> w[i];\n\
    \    }\n    std::vector<Query> query(q);\n    for (int i = 0; i < q; i++) {\n\
    \        std::cin >> query[i].flag;\n        if (query[i].flag == 0) {\n     \
    \       std::cin >> query[i].x >> query[i].y >> query[i].w;\n        } else {\n\
    \            std::cin >> query[i].l >> query[i].d >> query[i].r >> query[i].u;\n\
    \        }\n    }\n    offline_segtree_2d<ll, op, e, segtree<ll, op, e>> seg2d;\n\
    \    for (int i = 0; i < n; i++) {\n        seg2d.pre_set({x[i], y[i]});\n   \
    \ }\n    for (int i = 0; i < q; i++) {\n        if (query[i].flag == 0) {\n  \
    \          seg2d.pre_set({query[i].x, query[i].y});\n        }\n    }\n    seg2d.build();\n\
    \    for (int i = 0; i < n; i++) {\n        seg2d.set(x[i], y[i], seg2d.get(x[i],\
    \ y[i]) + w[i]);\n    }\n    for (int i = 0; i < q; i++) {\n        if (query[i].flag\
    \ == 0) {\n            seg2d.set(query[i].x, query[i].y,\n                   \
    \   seg2d.get(query[i].x, query[i].y) + query[i].w);\n        } else {\n     \
    \       std::cout << seg2d.prod(query[i].l, query[i].d, query[i].r,\n        \
    \                            query[i].u)\n                      << '\\n';\n  \
    \      }\n    }\n}"
  dependsOn:
  - data_structure/offline_segtree_2d.hpp
  - template/template.hpp
  - data_structure/compress.hpp
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 21:20:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Add_Rectangle_Sum.test.cpp
- /verify/test/data_structure/Point_Add_Rectangle_Sum.test.cpp.html
title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
---
