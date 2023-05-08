---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/data_structure/Point_Set_Range_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#line 2 \"data_structure/segtree.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
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
    \ namespace lib\n#line 2 \"utility/modint.hpp\"\n\nnamespace lib {\n\ntemplate\
    \ <ll mod> struct modint {\n    ll a;\n\n    modint(ll x = 0) : a((x % mod + mod)\
    \ % mod) {}\n    ll& val() {\n        return a;\n    }\n    modint pow(ll n) {\n\
    \        modint res = 1;\n        modint x = a;\n        while (n) {\n       \
    \     if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n      \
    \  }\n        return res;\n    }\n    modint inv() {\n        return pow(mod -\
    \ 2);\n    }\n    modint& operator+=(const modint rhs) {\n        a += rhs.a;\n\
    \        if (a >= mod) a -= mod;\n        return *this;\n    }\n    modint& operator-=(const\
    \ modint rhs) {\n        if (a < rhs.a) a += mod;\n        a -= rhs.a;\n     \
    \   return *this;\n    }\n    modint& operator*=(const modint rhs) {\n       \
    \ a = a * rhs.a % mod;\n        return *this;\n    }\n    modint& operator/=(modint\
    \ rhs) {\n        *this *= rhs.inv();\n        return *this;\n    }\n    friend\
    \ modint operator+(const modint& lhs, const modint& rhs) {\n        return modint(lhs)\
    \ += rhs;\n    }\n    friend modint operator-(const modint& lhs, const modint&\
    \ rhs) {\n        return modint(lhs) -= rhs;\n    }\n    friend modint operator*(const\
    \ modint& lhs, const modint& rhs) {\n        return modint(lhs) *= rhs;\n    }\n\
    \    friend modint operator/(const modint& lhs, const modint& rhs) {\n       \
    \ return modint(lhs) /= rhs;\n    }\n    modint operator+() const {\n        return\
    \ *this;\n    }\n    modint operator-() const {\n        return modint() - *this;\n\
    \    }\n};\n\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n\n}  // namespace lib\n#line 6 \"test/data_structure/Point_Set_Range_Composite.test.cpp\"\
    \n\nusing mint = lib::modint998244353;\n\nstruct F {\n    mint a, b;\n};\n\nF\
    \ op(F a, F b) { return {b.a * a.a, b.b + b.a * a.b}; }\n\nF e() { return {1,\
    \ 0}; }\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<F>\
    \ f(n);\n    rep(i, 0, n) {\n        ll a, b;\n        std::cin >> a >> b;\n \
    \       f[i] = {a, b};\n    }\n    lib::segtree<F, op, e> seg(f);\n    while (q--)\
    \ {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n         \
    \   int p;\n            ll c, d;\n            std::cin >> p >> c >> d;\n     \
    \       seg.set(p, {c, d});\n        } else {\n            int l, r;\n       \
    \     ll x;\n            std::cin >> l >> r >> x;\n            F prod = seg.prod(l,\
    \ r);\n            mint ans = prod.a * x + prod.b;\n            std::cout << ans.val()\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../data_structure/segtree.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../utility/modint.hpp\"\n\nusing mint = lib::modint998244353;\n\
    \nstruct F {\n    mint a, b;\n};\n\nF op(F a, F b) { return {b.a * a.a, b.b +\
    \ b.a * a.b}; }\n\nF e() { return {1, 0}; }\n\nint main() {\n    int n, q;\n \
    \   std::cin >> n >> q;\n    std::vector<F> f(n);\n    rep(i, 0, n) {\n      \
    \  ll a, b;\n        std::cin >> a >> b;\n        f[i] = {a, b};\n    }\n    lib::segtree<F,\
    \ op, e> seg(f);\n    while (q--) {\n        int t;\n        std::cin >> t;\n\
    \        if (t == 0) {\n            int p;\n            ll c, d;\n           \
    \ std::cin >> p >> c >> d;\n            seg.set(p, {c, d});\n        } else {\n\
    \            int l, r;\n            ll x;\n            std::cin >> l >> r >> x;\n\
    \            F prod = seg.prod(l, r);\n            mint ans = prod.a * x + prod.b;\n\
    \            std::cout << ans.val() << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - data_structure/segtree.hpp
  - template/template.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 16:25:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Set_Range_Composite.test.cpp
- /verify/test/data_structure/Point_Set_Range_Composite.test.cpp.html
title: test/data_structure/Point_Set_Range_Composite.test.cpp
---
