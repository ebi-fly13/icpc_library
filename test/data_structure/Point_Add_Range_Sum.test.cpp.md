---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/data_structure/Point_Add_Range_Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 2 \"\
    data_structure/segtree.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n); i++)\n\
    #define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v)\
    \ v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\nusing\
    \ ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const T\
    \ &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"data_structure/segtree.hpp\"\
    \n\nnamespace lib {\n\nusing namespace std;\n\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct segtree {\n  private:\n    int n;\n    int sz;\n    vector<S>\
    \ data;\n\n    void update(int i) { data[i] = op(data[2 * i], data[2 * i + 1]);\
    \ }\n\n  public:\n    segtree(int n) : segtree(vector<S>(n, e())) {}\n    segtree(const\
    \ vector<S> &v) : n((int)v.size()), sz(1) {\n        while (sz < n) sz *= 2;\n\
    \        data = vector<S>(2 * sz, e());\n        rep(i, 0, n) { data[sz + i] =\
    \ v[i]; }\n        rrep(i, 1, sz) update(i);\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < n);\n        p += sz;\n        data[p] = x;\n\
    \        while (p > 1) {\n            p >>= 1;\n            update(p);\n     \
    \   }\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < n);\n       \
    \ return data[p + sz];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        S sml = e(), smr = e();\n        l += sz;\n\
    \        r += sz;\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ data[l++]);\n            if (r & 1) smr = op(data[--r], smr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\
    \n    S all_prod() { return data[1]; }\n\n    template <class F> int max_right(int\
    \ l, F f) {\n        assert(0 <= l && l < n);\n        assert(f(e()));\n     \
    \   if (l == n) return n;\n        l += sz;\n        S sm = e();\n        do {\n\
    \            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, data[l])))\
    \ {\n                while (l < sz) {\n                    l = 2 * l;\n      \
    \              if (f(op(sm, data[l]))) {\n                        sm = op(sm,\
    \ data[l]);\n                        l++;\n                    }\n           \
    \     }\n                return l - sz;\n            }\n            sm = op(sm,\
    \ data[l]);\n            l++;\n        } while ((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <class F> int min_left(int r, F f) {\n        assert(0\
    \ <= r && r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n \
    \       r += sz;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(data[r], sm)))\
    \ {\n                while (r < sz) {\n                    r = 2 * r + 1;\n  \
    \                  if (f(op(data[r], sm))) {\n                        sm = op(data[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\n}  //\
    \ namespace lib\n#line 5 \"test/data_structure/Point_Add_Range_Sum.test.cpp\"\n\
    \nll op(ll a, ll b) { return a + b; }\n\nll e() { return 0; }\n\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<ll> a(n);\n    rep(i,\
    \ 0, n) { std::cin >> a[i]; }\n    lib::segtree<ll, op, e> seg(a);\n    while\
    \ (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n   \
    \         int p;\n            ll x;\n            std::cin >> p >> x;\n       \
    \     seg.set(p, seg.get(p) + x);\n        } else {\n            int l, r;\n \
    \           std::cin >> l >> r;\n            std::cout << seg.prod(l, r) << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../data_structure/segtree.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nll op(ll a, ll b) { return a + b; }\n\nll e() { return 0; }\n\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<ll> a(n);\n    rep(i,\
    \ 0, n) { std::cin >> a[i]; }\n    lib::segtree<ll, op, e> seg(a);\n    while\
    \ (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n   \
    \         int p;\n            ll x;\n            std::cin >> p >> x;\n       \
    \     seg.set(p, seg.get(p) + x);\n        } else {\n            int l, r;\n \
    \           std::cin >> l >> r;\n            std::cout << seg.prod(l, r) << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 15:48:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Add_Range_Sum.test.cpp
- /verify/test/data_structure/Point_Add_Range_Sum.test.cpp.html
title: test/data_structure/Point_Add_Range_Sum.test.cpp
---
