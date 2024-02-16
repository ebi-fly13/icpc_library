---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':heavy_check_mark:'
    path: math/factorial.hpp
    title: math/factorial.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/polynomial/Log_of_FPS_Sparse.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"fps/fps_sparse.hpp\"\n\n#line 2 \"math/factorial.hpp\"\n\n#line\
    \ 4 \"math/factorial.hpp\"\n\nnamespace lib {\n\ntemplate<typename T>\nstruct\
    \ Binom{\n    Binom(int lim = 300000){\n        if (kaijo.empty()){\n        \
    \    kaijo = {1,1};\n            kainv = {1,1};\n        }\n        extend(lim);\n\
    \    }\n    static T fact(int x) {\n        if (x < 0) return T(0);\n        return\
    \ kaijo[x];\n    }\n    static T ifact(int x){\n        if (x < 0) return T(0);\n\
    \        return kainv[x];\n    }\n    static T C(int n, int r){\n        if (n\
    \ < 0 || n < r || r < 0) return T(0);\n        return kaijo[n] * kainv[r] * kainv[n-r];\n\
    \    }\n    static T P(int n, int r){\n        if (n < 0 || n < r || r < 0) return\
    \ T(0);\n        return kaijo[n] * kainv[n-r];\n    }\n    static T Inv(int n){\n\
    \        assert(0 < n);\n        return ifact(n) * fact(n-1);\n    }\n    T operator()(int\
    \ n, int r){ return C(n,r); }\n  private:\n    static vector<T> kaijo, kainv;\n\
    \    static void extend(int lim){\n        if ((int)kaijo.size() > lim) return\
    \ ;\n        int pre = kaijo.size();\n        kaijo.resize(lim+1);\n        kainv.resize(lim+1);\n\
    \        for (int i = pre; i <= lim; i++) kaijo[i] = kaijo[i-1] * T(i);\n    \
    \    kainv[lim] = kaijo[lim].inv();\n        for (int i = lim-1; i >= pre; i--)\
    \ kainv[i] = kainv[i+1] * T(i+1);\n    }\n};\ntemplate<typename T>\nvector<T>Binom<T>::kaijo\
    \ = vector<T>(2,T(1));\ntemplate<typename T>\nvector<T>Binom<T>::kainv = vector<T>(2,T(1));\n\
    \n} // namespace lib\n#line 5 \"fps/fps_sparse.hpp\"\n\nnamespace lib {\n\ntemplate\
    \ <class mint>\nstd::vector<mint> mul_sparse(const std::vector<mint> &f,\n   \
    \                          const std::vector<mint> &g) {\n    int n = f.size();\n\
    \    int m = g.size();\n    std::vector<std::pair<int, mint>> cf, cg;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (f[i] != 0) cf.emplace_back(i, f[i]);\n\
    \    }\n    for (int i = 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i,\
    \ g[i]);\n    }\n    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf)\
    \ {\n        for (auto [j, q] : cg) {\n            h[i + j] += p * q;\n      \
    \  }\n    }\n    return h;\n}\n\ntemplate <class mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    template <class mint>\nstd::vector<mint> exp_sparse(const std::vector<mint> &f,\
    \ int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) {\n \
    \           ret.emplace_back(i - 1, f[i] * i);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    Binom<mint> binom(d);\n    for (int i = 0; i < d -\
    \ 1; i++) {\n        for (auto [k, p] : ret) {\n            if (i - k < 0) break;\n\
    \            g[i + 1] += g[i - k] * p;\n        }\n        g[i + 1] *= binom.Inv(i\
    \ + 1);\n    }\n    return g;\n}\n\ntemplate <class mint>\nstd::vector<mint> log_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    int n = f.size();\n    if (d < 0) d\
    \ = n;\n    std::vector<mint> df(d);\n    for (int i = 0; i < std::min(d, n -\
    \ 1); i++) {\n        df[i] = f[i + 1] * (i + 1);\n    }\n    auto dg = mul_sparse(df,\
    \ inv_sparse(f));\n    dg.resize(d);\n    std::vector<mint> g(d);\n    Binom<mint>\
    \ binom(d);\n    for (int i = 0; i < d - 1; i++) {\n        g[i + 1] = dg[i] *\
    \ binom.Inv(i + 1);\n    }\n    return g;\n}\n\ntemplate <class mint>\nstd::vector<mint>\
    \ pow_sparse_1(const std::vector<mint> &f, long long k,\n                    \
    \           int d = -1) {\n    int n = f.size();\n    assert(n == 0 || f[0] ==\
    \ 1);\n    std::vector<std::pair<int, mint>> ret;\n    for (int i = 1; i < n;\
    \ i++) {\n        if (f[i] != 0) ret.emplace_back(i, f[i]);\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    Binom<mint> binom(d);\n    for (int i = 0; i < d -\
    \ 1; i++) {\n        for (const auto &[j, cf] : ret) {\n            if (i + 1\
    \ - j < 0) break;\n            g[i + 1] +=\n                (mint(k) * mint(j)\
    \ - mint(i - j + 1)) * cf * g[i + 1 - j];\n        }\n        g[i + 1] *= binom.Inv(i\
    \ + 1);\n    }\n    return g;\n}\n\ntemplate <class mint>\nstd::vector<mint> pow_sparse(const\
    \ std::vector<mint> &f, long long k,\n                             int d = -1)\
    \ {\n    int n = f.size();\n    if (d < 0) d = n;\n    assert(k >= 0);\n    if\
    \ (k == 0) {\n        std::vector<mint> g(d);\n        if (d > 0) g[0] = 1;\n\
    \        return g;\n    }\n    for (int i = 0; i < n; i++) {\n        if (f[i]\
    \ != 0) {\n            mint rev = f[i].inv();\n            std::vector<mint> f2(n\
    \ - i);\n            for (int j = i; j < n; j++) {\n                f2[j - i]\
    \ = f[j] * rev;\n            }\n            f2 = pow_sparse_1(f2, k, d);\n   \
    \         mint fk = f[i].pow(k);\n            std::vector<mint> g(d);\n      \
    \      for (int j = 0; j < int(f2.size()); j++) {\n                if (j + i *\
    \ k >= d) break;\n                g[j + i * k] = f2[j] * fk;\n            }\n\
    \            return g;\n        }\n        if (i >= (d + k - 1) / k) break;\n\
    \    }\n    return std::vector<mint>(d);\n}\n\n}  // namespace lib\n#line 2 \"\
    utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\n\nnamespace lib {\n\n\
    template <ll m> struct modint {\n    using mint = modint;\n    ll a;\n\n    modint(ll\
    \ x = 0) : a((x % m + m) % m) {}\n    static constexpr ll mod() {\n        return\
    \ m;\n    }\n    ll val() const {\n        return a;\n    }\n    ll& val() {\n\
    \        return a;\n    }\n    mint pow(ll n) const {\n        mint res = 1;\n\
    \        mint x = a;\n        while (n) {\n            if (n & 1) res *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return res;\n \
    \   }\n    mint inv() const {\n        return pow(m - 2);\n    }\n    mint& operator+=(const\
    \ mint rhs) {\n        a += rhs.a;\n        if (a >= m) a -= m;\n        return\
    \ *this;\n    }\n    mint& operator-=(const mint rhs) {\n        if (a < rhs.a)\
    \ a += m;\n        a -= rhs.a;\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint rhs) {\n        a = a * rhs.a % m;\n        return *this;\n    }\n    mint&\
    \ operator/=(mint rhs) {\n        *this *= rhs.inv();\n        return *this;\n\
    \    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const modint &lhs,\
    \ const modint &rhs) {\n        return lhs.a == rhs.a;\n    }\n    friend bool\
    \ operator!=(const modint &lhs, const modint &rhs) {\n        return !(lhs ==\
    \ rhs);\n    }\n    mint operator+() const {\n        return *this;\n    }\n \
    \   mint operator-() const {\n        return mint() - *this;\n    }\n};\n\nusing\
    \ modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1'000'000'007>;\n\
    \n}  // namespace lib\n#line 7 \"test/polynomial/Log_of_FPS_Sparse.test.cpp\"\n\
    \nusing namespace lib;\nusing mint = modint998244353;\n\nint main() {\n    int\
    \ n, k;\n    std::cin >> n >> k;\n    std::vector<mint> f(n);\n    for (int i\
    \ = 0; i < k; i++) {\n        int idx, a;\n        std::cin >> idx >> a;\n   \
    \     f[idx] = a;\n    }\n    auto g = log_sparse(f, n);\n    for (int i = 0;\
    \ i < n; i++) {\n        std::cout << g[i].val() << \" \\n\"[i == n - 1];\n  \
    \  }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../fps/fps_sparse.hpp\"\
    \n#include \"../../utility/modint.hpp\"\n\nusing namespace lib;\nusing mint =\
    \ modint998244353;\n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n \
    \   std::vector<mint> f(n);\n    for (int i = 0; i < k; i++) {\n        int idx,\
    \ a;\n        std::cin >> idx >> a;\n        f[idx] = a;\n    }\n    auto g =\
    \ log_sparse(f, n);\n    for (int i = 0; i < n; i++) {\n        std::cout << g[i].val()\
    \ << \" \\n\"[i == n - 1];\n    }\n}"
  dependsOn:
  - template/template.hpp
  - fps/fps_sparse.hpp
  - math/factorial.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/polynomial/Log_of_FPS_Sparse.test.cpp
  requiredBy: []
  timestamp: '2024-02-16 18:48:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polynomial/Log_of_FPS_Sparse.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Log_of_FPS_Sparse.test.cpp
- /verify/test/polynomial/Log_of_FPS_Sparse.test.cpp.html
title: test/polynomial/Log_of_FPS_Sparse.test.cpp
---
