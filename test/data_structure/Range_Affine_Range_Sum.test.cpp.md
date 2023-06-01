---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazysegtree.hpp
    title: lazy segtree
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 2 \"data_structure/lazysegtree.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"data_structure/lazysegtree.hpp\"\n\nnamespace lib {\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\n          F\
    \ (*composition)(F, F), F (*id)()>\nstruct lazysegtree {\n  private:\n    int\
    \ n, log, sz;\n    std::vector<S> d;\n    std::vector<F> lz;\n\n    void update(int\
    \ i) {\n        d[i] = op(d[2 * i], d[2 * i + 1]);\n    }\n\n    void all_apply(int\
    \ i, F f) {\n        d[i] = mapping(f, d[i]);\n        if (i < sz) lz[i] = composition(f,\
    \ lz[i]);\n    }\n\n    void push(int i) {\n        all_apply(2 * i, lz[i]);\n\
    \        all_apply(2 * i + 1, lz[i]);\n        lz[i] = id();\n    }\n\n  public:\n\
    \    lazysegtree(int n) : n(n) {\n        lazysegtree(std::vector<S>(n, e()));\n\
    \    }\n    lazysegtree(const std::vector<S> &v) : n(v.size()) {\n        log\
    \ = 0;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n      \
    \  d = std::vector<S>(2 * sz, e());\n        lz = std::vector<F>(2 * sz, id());\n\
    \        for (int i = 0; i < n; i++) d[sz + i] = v[i];\n        for (int i = sz\
    \ - 1; i >= 1; i--) update(i);\n    }\n\n    void set(int p, S x) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        rrep(i, 1, log + 1) push(p >> i);\n\
    \        d[p] = x;\n        rep(i, 1, log + 1) update(p >> i);\n    }\n\n    S\
    \ get(int p) {\n        assert(0 <= p && p < n);\n        p += sz;\n        rrep(i,\
    \ 1, log + 1) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l,\
    \ int r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return\
    \ e();\n        l += sz;\n        r += sz;\n        rrep(i, 1, log + 1) {\n  \
    \          if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = e(), smr = e();\n\
    \        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n    \
    \        if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n           \
    \ r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ {\n        return d[1];\n    }\n\n    void apply(int p, F f) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        rrep(i, 1, log + 1) push(p >> i);\n\
    \        d[p] = mapping(f, d[p]);\n        rep(i, 1, log + 1) update(p >> i);\n\
    \    }\n\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r\
    \ && r <= n);\n        if (l == r) return;\n        l += sz;\n        r += sz;\n\
    \        rrep(i, 1, log + 1) {\n            if (((l >> i) << i) != l) push(l >>\
    \ i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n\
    \        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n   \
    \             if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        rep(i, 1, log + 1)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <class\
    \ G> int max_right(int l, G g) {\n        assert(0 <= l && l <= n);\n        assert(g(e()));\n\
    \        if (l == n) return n;\n        l += sz;\n        for (int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n               \
    \ while (l < sz) {\n                    push(l);\n                    l = (2 *\
    \ l);\n                    if (g(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - sz;\n            }\n            sm =\
    \ op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return\
    \ n;\n    }\n\n    template <class G> int min_left(int r, G g) {\n        assert(0\
    \ <= r && r <= n);\n        assert(g(e()));\n        if (r == 0) return 0;\n \
    \       r += sz;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < sz) {\n                    push(r);\n                    r = (2 * r + 1);\n\
    \                    if (g(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\n}  //\
    \ namespace lib\n#line 2 \"utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\
    \n\nnamespace lib {\n\ntemplate <ll m> struct modint {\n    using mint = modint;\n\
    \    ll a;\n\n    modint(ll x = 0) : a((x % m + m) % m) {}\n    static ll mod()\
    \ {\n        return m;\n    }\n    ll& val() {\n        return a;\n    }\n   \
    \ mint pow(ll n) {\n        mint res = 1;\n        mint x = a;\n        while\
    \ (n) {\n            if (n & 1) res *= x;\n            x *= x;\n            n\
    \ >>= 1;\n        }\n        return res;\n    }\n    mint inv() {\n        return\
    \ pow(m - 2);\n    }\n    mint& operator+=(const mint rhs) {\n        a += rhs.a;\n\
    \        if (a >= m) a -= m;\n        return *this;\n    }\n    mint& operator-=(const\
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
    \ // namespace lib\n#line 9 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n\nusing namespace lib;\n\nusing mint = modint998244353;\n\nstruct S {\n    mint\
    \ a;\n    int size;\n};\n\nstruct F {\n    mint a, b;\n    F(mint a, mint b) :\
    \ a(a), b(b) {}\n};\n\nS op(S l, S r) {\n    return S{l.a + r.a, l.size + r.size};\n\
    }\n\nS e() {\n    return S{0, 0};\n}\n\nS mapping(F l, S r) {\n    return S{r.a\
    \ * l.a + (mint)r.size * l.b, r.size};\n}\n\nF composition(F l, F r) {\n    return\
    \ F{r.a * l.a, r.b * l.a + l.b};\n}\n\nF id() {\n    return F{1, 0};\n}\n\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<S> v(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int a;\n        std::cin >> a;\n \
    \       v[i] = {a, 1};\n    }\n    lazysegtree<S, op, e, F, mapping, composition,\
    \ id> seg(v);\n    while (q--) {\n        int t;\n        std::cin >> t;\n   \
    \     if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l >>\
    \ r >> b >> c;\n            seg.apply(l, r, F(b, c));\n        } else {\n    \
    \        int l, r;\n            std::cin >> l >> r;\n            std::cout <<\
    \ seg.prod(l, r).a.val() << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../data_structure/lazysegtree.hpp\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../utility/modint.hpp\"\
    \n\nusing namespace lib;\n\nusing mint = modint998244353;\n\nstruct S {\n    mint\
    \ a;\n    int size;\n};\n\nstruct F {\n    mint a, b;\n    F(mint a, mint b) :\
    \ a(a), b(b) {}\n};\n\nS op(S l, S r) {\n    return S{l.a + r.a, l.size + r.size};\n\
    }\n\nS e() {\n    return S{0, 0};\n}\n\nS mapping(F l, S r) {\n    return S{r.a\
    \ * l.a + (mint)r.size * l.b, r.size};\n}\n\nF composition(F l, F r) {\n    return\
    \ F{r.a * l.a, r.b * l.a + l.b};\n}\n\nF id() {\n    return F{1, 0};\n}\n\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<S> v(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int a;\n        std::cin >> a;\n \
    \       v[i] = {a, 1};\n    }\n    lazysegtree<S, op, e, F, mapping, composition,\
    \ id> seg(v);\n    while (q--) {\n        int t;\n        std::cin >> t;\n   \
    \     if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l >>\
    \ r >> b >> c;\n            seg.apply(l, r, F(b, c));\n        } else {\n    \
    \        int l, r;\n            std::cin >> l >> r;\n            std::cout <<\
    \ seg.prod(l, r).a.val() << std::endl;\n        }\n    }\n}"
  dependsOn:
  - data_structure/lazysegtree.hpp
  - template/template.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 16:25:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/data_structure/Range_Affine_Range_Sum.test.cpp
---
