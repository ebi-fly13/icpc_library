---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorial.hpp
    title: math/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_FPS_Sparse.test.cpp
    title: test/polynomial/Exp_of_FPS_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_FPS_Sparse.test.cpp
    title: test/polynomial/Inv_of_FPS_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_FPS_Sparse.test.cpp
    title: test/polynomial/Log_of_FPS_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_FPS_Sparse.test.cpp
    title: test/polynomial/Pow_of_FPS_Sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps_sparse.hpp\"\n\n#line 2 \"math/factorial.hpp\"\n\
    \n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"math/factorial.hpp\"\n\nnamespace lib {\n\ntemplate<typename\
    \ T>\nstruct Binom{\n    Binom(int lim = 300000){\n        if (kaijo.empty()){\n\
    \            kaijo = {1,1};\n            kainv = {1,1};\n        }\n        extend(lim);\n\
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
    \    }\n    return std::vector<mint>(d);\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../math/factorial.hpp\"\n#include \"../template/template.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class mint>\nstd::vector<mint> mul_sparse(const\
    \ std::vector<mint> &f,\n                             const std::vector<mint>\
    \ &g) {\n    int n = f.size();\n    int m = g.size();\n    std::vector<std::pair<int,\
    \ mint>> cf, cg;\n    for (int i = 0; i < n; i++) {\n        if (f[i] != 0) cf.emplace_back(i,\
    \ f[i]);\n    }\n    for (int i = 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i,\
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
    \    }\n    return std::vector<mint>(d);\n}\n\n}  // namespace lib"
  dependsOn:
  - math/factorial.hpp
  - template/template.hpp
  isVerificationFile: false
  path: fps/fps_sparse.hpp
  requiredBy: []
  timestamp: '2024-02-16 18:48:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Pow_of_FPS_Sparse.test.cpp
  - test/polynomial/Inv_of_FPS_Sparse.test.cpp
  - test/polynomial/Log_of_FPS_Sparse.test.cpp
  - test/polynomial/Exp_of_FPS_Sparse.test.cpp
documentation_of: fps/fps_sparse.hpp
layout: document
title: Formal Power Series (Sparse)
---

## 説明

疎な形式的べき級数に対する処理を集めたもの。

### mul_sparse(std::vector<mint> f, std::vector<mint> g)

ナイーブな多項式積。$f$ の非ゼロの項を $N$ 個、$g$ の非ゼロの項を $M$ 個として $O(NM)$。

### inv_sparse(std::vector<mint> f, int d)

$f^{-1} \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### exp_sparse(std::vector<mint> f, int d)

$\exp(f) \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### log_sparse(std::vector<mint> f, int d)

$\log{f} \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### pow_sparse(std::vector<mint> f, long long k, int d)

$f^k \mod x^d$ を求める。$k$ は非負整数のみ正常に動作する。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### pow_sparse_1(std::vector<mint> f, long long k, int d)

$[x^0]f = 1$ であるような $f$ に対して $f^k \mod x^d$ を求める。 $k$ が負でも有理数でも動作する。 $f$ の非ゼロの項を $M$ 個として $O(NM)$