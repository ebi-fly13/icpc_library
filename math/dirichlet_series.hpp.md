---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Totient_Function.test.cpp
    title: test/math/Sum_of_Totient_Function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/dirichlet_series.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    math/dirichlet_series.hpp\"\n\nnamespace lib {\n\ntemplate <class T>\nstd::vector<T>\
    \ dirichlet_convolution(const std::vector<T> &a,\n                           \
    \          const std::vector<T> &b) {\n    assert(a.size() == b.size());\n   \
    \ int n = a.size() - 1;\n    std::vector<T> c(n + 1, 0);\n    for (int i = 1;\
    \ i <= n; i++) {\n        for (int j = 1; i * j <= n; j++) {\n            c[i\
    \ * j] += a[i] * b[j];\n        }\n    }\n    return c;\n}\n\ntemplate <class\
    \ T, int id> struct DirichletSeries {\n  private:\n    using Self = DirichletSeries<T,\
    \ id>;\n\n    void set(std::function<T(ll)> f, std::function<T(ll)> F) {\n   \
    \     for (int i = 1; i <= K; i++) {\n            a[i] = f(i);\n        }\n  \
    \      for (int i = 1; i <= L; i++) {\n            A[i] = F(N / i);\n        }\n\
    \    }\n\n  public:\n    DirichletSeries() : a(K + 1), A(L + 1) {}\n\n    DirichletSeries(std::function<T(ll)>\
    \ f, std::function<T(ll)> F)\n        : a(K + 1), A(L + 1) {\n        set(f, F);\n\
    \    }\n\n    Self operator+(const Self &rhs) const noexcept {\n        return\
    \ Self(*this) += rhs;\n    }\n    Self operator-(const Self &rhs) const noexcept\
    \ {\n        return Self(*this) -= rhs;\n    }\n    Self operator*(const Self\
    \ &rhs) const noexcept {\n        return Self(*this) *= rhs;\n    }\n    Self\
    \ operator/(const Self &rhs) const noexcept {\n        return Self(*this) /= rhs;\n\
    \    }\n\n    Self operator+=(const Self &rhs) noexcept {\n        for (int i\
    \ = 1; i <= K; i++) {\n            a[i] += rhs.a[i];\n        }\n        for (int\
    \ i = 1; i <= L; i++) {\n            A[i] += rhs.A[i];\n        }\n        return\
    \ *this;\n    }\n\n    Self operator-=(const Self &rhs) noexcept {\n        for\
    \ (int i = 1; i <= K; i++) {\n            a[i] -= rhs.a[i];\n        }\n     \
    \   for (int i = 1; i <= L; i++) {\n            A[i] -= rhs.A[i];\n        }\n\
    \        return *this;\n    }\n\n    Self operator*=(const Self &rhs) noexcept\
    \ {\n        Self ret;\n        ret.a = dirichlet_convolution(a, rhs.a);\n   \
    \     std::vector<T> sum_a = a, sum_b = rhs.a;\n        for (int i = 1; i < K;\
    \ i++) {\n            sum_a[i + 1] += sum_a[i];\n            sum_b[i + 1] += sum_b[i];\n\
    \        }\n        auto get_A = [&](ll x) -> T {\n            if (x <= K) {\n\
    \                return sum_a[x];\n            } else {\n                return\
    \ A[N / x];\n            }\n        };\n        auto get_B = [&](ll x) -> T {\n\
    \            if (x <= K) {\n                return sum_b[x];\n            } else\
    \ {\n                return rhs.A[N / x];\n            }\n        };\n       \
    \ for (ll l = L, m = 1; l >= 1; l--) {\n            ll n = N / l;\n          \
    \  while (m * m <= n) m++;\n            m--;\n            for (int i = 1; i <=\
    \ m; i++) {\n                ret.A[l] +=\n                    a[i] * get_B(n /\
    \ i) + (get_A(n / i) - get_A(m)) * rhs.a[i];\n            }\n        }\n     \
    \   return ret;\n    }\n\n    // c = a / b\n    Self operator/=(const Self &b)\
    \ noexcept {\n        Self c = *this;\n        T inv_a = b.a[1].inv();\n     \
    \   for (int i = 1; i <= K; i++) {\n            c.a[i] *= inv_a;\n           \
    \ for (int j = 2; i * j <= K; j++) {\n                c.a[i * j] -= c.a[i] * b.a[j];\n\
    \            }\n        }\n        std::vector<T> sum_b = b.a, sum_c = c.a;\n\
    \        for (int i = 1; i < K; ++i) {\n            sum_b[i + 1] += sum_b[i];\n\
    \            sum_c[i + 1] += sum_c[i];\n        }\n        auto get_B = [&](ll\
    \ x) -> T {\n            if (x <= K) {\n                return sum_b[x];\n   \
    \         } else {\n                return b.A[N / x];\n            }\n      \
    \  };\n        auto get_C = [&](ll x) -> T {\n            if (x <= K) {\n    \
    \            return sum_c[x];\n            } else {\n                return c.A[N\
    \ / x];\n            }\n        };\n        for (ll l = L, m = 1; l >= 1; l--)\
    \ {\n            ll n = N / l;\n            while (m * m <= n) m++;\n        \
    \    m--;\n            for (int i = 2; i <= m; i++) {\n                c.A[l]\
    \ -= b.a[i] * get_C(n / i);\n            }\n\n            for (int i = 1; i <=\
    \ m; i++) {\n                c.A[l] -= c.a[i] * (get_B(n / i) - get_B(m));\n \
    \           }\n            c.A[l] *= inv_a;\n        }\n        return *this =\
    \ c;\n    }\n\n    Self pow(ll n) const {\n        Self res;\n        res.a[1]\
    \ = 1;\n        std::fill(res.A.begin(), res.A.end(), 1);\n        Self x = *this;\n\
    \        while (n > 0) {\n            if (n & 1) res = res * x;\n            x\
    \ = x * x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n  \
    \  T get_sum() {\n        return A[1];\n    }\n\n    static Self zeta() {\n  \
    \      Self ret;\n        std::fill(ret.a.begin(), ret.a.end(), 1);\n        for\
    \ (int i = 1; i <= L; i++) {\n            ret.A[i] = N / i;\n        }\n     \
    \   return ret;\n    }\n\n    static Self zeta1() {\n        Self ret;\n     \
    \   std::iota(ret.a.begin(), ret.a.end(), 0);\n        T inv2 = T(2).inv();\n\
    \        for (int i = 1; i <= L; i++) {\n            ll n = N / i;\n         \
    \   ret.A[i] = T(n) * T(n + 1) * inv2;\n        }\n        return ret;\n    }\n\
    \n    static Self zeta2() {\n        Self ret;\n        for (int i = 1; i <= K;\
    \ i++) {\n            ret.a[i] = i * i;\n        }\n        T inv6 = T(6).inv();\n\
    \        for (int i = 1; i <= L; i++) {\n            ll n = N / i;\n         \
    \   ret.A[i] = T(n) * T(n + 1) * T(2 * n + 1) * inv6;\n        }\n    }\n\n  \
    \  static void set_size(ll n) {\n        N = n;\n        if (N <= 10) {\n    \
    \        K = N;\n            L = 1;\n        } else if (N <= 5000) {\n       \
    \     K = 1;\n            while (K * K < N) K++;\n            L = (N + K - 1)\
    \ / K;\n        } else {\n            L = 1;\n            while (L * L * L / 50\
    \ < N) L++;\n            K = (N + L - 1) / L;\n        }\n    }\n\n    static\
    \ void set_size_multiplicative(ll n) {\n        N = n;\n        L = 1;\n     \
    \   while (L * L * L < N) L++;\n        K = L * L;\n    }\n\n  private:\n    static\
    \ ll N, K, L;\n    static std::vector<std::pair<int, int>> prime_pow_table;\n\
    \    std::vector<T> a, A;\n};\n\ntemplate <class T, int id> ll DirichletSeries<T,\
    \ id>::N = 1000000;\ntemplate <class T, int id> ll DirichletSeries<T, id>::K =\
    \ 10000;\ntemplate <class T, int id> ll DirichletSeries<T, id>::L = 100;\ntemplate\
    \ <class T, int id>\nstd::vector<std::pair<int, int>> DirichletSeries<T, id>::prime_pow_table\
    \ = {};\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class T>\nstd::vector<T> dirichlet_convolution(const std::vector<T>\
    \ &a,\n                                     const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    int n = a.size() - 1;\n    std::vector<T> c(n + 1, 0);\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; i * j <= n; j++)\
    \ {\n            c[i * j] += a[i] * b[j];\n        }\n    }\n    return c;\n}\n\
    \ntemplate <class T, int id> struct DirichletSeries {\n  private:\n    using Self\
    \ = DirichletSeries<T, id>;\n\n    void set(std::function<T(ll)> f, std::function<T(ll)>\
    \ F) {\n        for (int i = 1; i <= K; i++) {\n            a[i] = f(i);\n   \
    \     }\n        for (int i = 1; i <= L; i++) {\n            A[i] = F(N / i);\n\
    \        }\n    }\n\n  public:\n    DirichletSeries() : a(K + 1), A(L + 1) {}\n\
    \n    DirichletSeries(std::function<T(ll)> f, std::function<T(ll)> F)\n      \
    \  : a(K + 1), A(L + 1) {\n        set(f, F);\n    }\n\n    Self operator+(const\
    \ Self &rhs) const noexcept {\n        return Self(*this) += rhs;\n    }\n   \
    \ Self operator-(const Self &rhs) const noexcept {\n        return Self(*this)\
    \ -= rhs;\n    }\n    Self operator*(const Self &rhs) const noexcept {\n     \
    \   return Self(*this) *= rhs;\n    }\n    Self operator/(const Self &rhs) const\
    \ noexcept {\n        return Self(*this) /= rhs;\n    }\n\n    Self operator+=(const\
    \ Self &rhs) noexcept {\n        for (int i = 1; i <= K; i++) {\n            a[i]\
    \ += rhs.a[i];\n        }\n        for (int i = 1; i <= L; i++) {\n          \
    \  A[i] += rhs.A[i];\n        }\n        return *this;\n    }\n\n    Self operator-=(const\
    \ Self &rhs) noexcept {\n        for (int i = 1; i <= K; i++) {\n            a[i]\
    \ -= rhs.a[i];\n        }\n        for (int i = 1; i <= L; i++) {\n          \
    \  A[i] -= rhs.A[i];\n        }\n        return *this;\n    }\n\n    Self operator*=(const\
    \ Self &rhs) noexcept {\n        Self ret;\n        ret.a = dirichlet_convolution(a,\
    \ rhs.a);\n        std::vector<T> sum_a = a, sum_b = rhs.a;\n        for (int\
    \ i = 1; i < K; i++) {\n            sum_a[i + 1] += sum_a[i];\n            sum_b[i\
    \ + 1] += sum_b[i];\n        }\n        auto get_A = [&](ll x) -> T {\n      \
    \      if (x <= K) {\n                return sum_a[x];\n            } else {\n\
    \                return A[N / x];\n            }\n        };\n        auto get_B\
    \ = [&](ll x) -> T {\n            if (x <= K) {\n                return sum_b[x];\n\
    \            } else {\n                return rhs.A[N / x];\n            }\n \
    \       };\n        for (ll l = L, m = 1; l >= 1; l--) {\n            ll n = N\
    \ / l;\n            while (m * m <= n) m++;\n            m--;\n            for\
    \ (int i = 1; i <= m; i++) {\n                ret.A[l] +=\n                  \
    \  a[i] * get_B(n / i) + (get_A(n / i) - get_A(m)) * rhs.a[i];\n            }\n\
    \        }\n        return ret;\n    }\n\n    // c = a / b\n    Self operator/=(const\
    \ Self &b) noexcept {\n        Self c = *this;\n        T inv_a = b.a[1].inv();\n\
    \        for (int i = 1; i <= K; i++) {\n            c.a[i] *= inv_a;\n      \
    \      for (int j = 2; i * j <= K; j++) {\n                c.a[i * j] -= c.a[i]\
    \ * b.a[j];\n            }\n        }\n        std::vector<T> sum_b = b.a, sum_c\
    \ = c.a;\n        for (int i = 1; i < K; ++i) {\n            sum_b[i + 1] += sum_b[i];\n\
    \            sum_c[i + 1] += sum_c[i];\n        }\n        auto get_B = [&](ll\
    \ x) -> T {\n            if (x <= K) {\n                return sum_b[x];\n   \
    \         } else {\n                return b.A[N / x];\n            }\n      \
    \  };\n        auto get_C = [&](ll x) -> T {\n            if (x <= K) {\n    \
    \            return sum_c[x];\n            } else {\n                return c.A[N\
    \ / x];\n            }\n        };\n        for (ll l = L, m = 1; l >= 1; l--)\
    \ {\n            ll n = N / l;\n            while (m * m <= n) m++;\n        \
    \    m--;\n            for (int i = 2; i <= m; i++) {\n                c.A[l]\
    \ -= b.a[i] * get_C(n / i);\n            }\n\n            for (int i = 1; i <=\
    \ m; i++) {\n                c.A[l] -= c.a[i] * (get_B(n / i) - get_B(m));\n \
    \           }\n            c.A[l] *= inv_a;\n        }\n        return *this =\
    \ c;\n    }\n\n    Self pow(ll n) const {\n        Self res;\n        res.a[1]\
    \ = 1;\n        std::fill(res.A.begin(), res.A.end(), 1);\n        Self x = *this;\n\
    \        while (n > 0) {\n            if (n & 1) res = res * x;\n            x\
    \ = x * x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n  \
    \  T get_sum() {\n        return A[1];\n    }\n\n    static Self zeta() {\n  \
    \      Self ret;\n        std::fill(ret.a.begin(), ret.a.end(), 1);\n        for\
    \ (int i = 1; i <= L; i++) {\n            ret.A[i] = N / i;\n        }\n     \
    \   return ret;\n    }\n\n    static Self zeta1() {\n        Self ret;\n     \
    \   std::iota(ret.a.begin(), ret.a.end(), 0);\n        T inv2 = T(2).inv();\n\
    \        for (int i = 1; i <= L; i++) {\n            ll n = N / i;\n         \
    \   ret.A[i] = T(n) * T(n + 1) * inv2;\n        }\n        return ret;\n    }\n\
    \n    static Self zeta2() {\n        Self ret;\n        for (int i = 1; i <= K;\
    \ i++) {\n            ret.a[i] = i * i;\n        }\n        T inv6 = T(6).inv();\n\
    \        for (int i = 1; i <= L; i++) {\n            ll n = N / i;\n         \
    \   ret.A[i] = T(n) * T(n + 1) * T(2 * n + 1) * inv6;\n        }\n    }\n\n  \
    \  static void set_size(ll n) {\n        N = n;\n        if (N <= 10) {\n    \
    \        K = N;\n            L = 1;\n        } else if (N <= 5000) {\n       \
    \     K = 1;\n            while (K * K < N) K++;\n            L = (N + K - 1)\
    \ / K;\n        } else {\n            L = 1;\n            while (L * L * L / 50\
    \ < N) L++;\n            K = (N + L - 1) / L;\n        }\n    }\n\n    static\
    \ void set_size_multiplicative(ll n) {\n        N = n;\n        L = 1;\n     \
    \   while (L * L * L < N) L++;\n        K = L * L;\n    }\n\n  private:\n    static\
    \ ll N, K, L;\n    static std::vector<std::pair<int, int>> prime_pow_table;\n\
    \    std::vector<T> a, A;\n};\n\ntemplate <class T, int id> ll DirichletSeries<T,\
    \ id>::N = 1000000;\ntemplate <class T, int id> ll DirichletSeries<T, id>::K =\
    \ 10000;\ntemplate <class T, int id> ll DirichletSeries<T, id>::L = 100;\ntemplate\
    \ <class T, int id>\nstd::vector<std::pair<int, int>> DirichletSeries<T, id>::prime_pow_table\
    \ = {};\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: math/dirichlet_series.hpp
  requiredBy: []
  timestamp: '2023-11-14 21:03:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Totient_Function.test.cpp
documentation_of: math/dirichlet_series.hpp
layout: document
title: Dirichlet Series
---

## 説明

Dirichlet級数を取り扱う構造体。
$a$ に関するDirichlet級数 $D_a(s)$ は

$$D_a(s) = \sum_{n = 1}^{\infty} a_n s^{-n}$$

で表される。これを長さ $N$ で打ち切ったものについて取り扱う。

Dirichlet級数についてと実装方法について、[maspyさんの記事](https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c)を参考にした。

### コンストラクタ

$a_i$ を返す関数 $f$ とその累積和 $A_i$ を計算する関数 $F$ を引数として渡すことで、 $a$ に関するDirichlet級数を生成する。

```set_size(n)```をすることを**忘れず**にすること。

### 和・差

$O(K + L)$

### 積

$O(K\log K + (NL)^{1/2})$

### 商

$O(K\log K + (NL)^{1/2})$

### get_sum()

$sum_{n = 1}^{N} a_n$ を返す。 $O(1)$

### pow(u64 n)

Dirichlet級数 $a$ について $a^n$ を求める。繰り返し二乗法で $\log n$ 回程度の積が実行される。

### zeta()

$\zeta(s) = \sum_{n = 1}^{\infty} s^{-n}$ のDirichlet級数を返す。

### zeta1()

$\zeta(s-1) = \sum_{n = 1}^{\infty} n \times s^{-n}$ のDirichlet級数を返す。

### set_size(i64 n)

長さを $n$ にする。

### set_size_multiplicative(i64 n)

長さを $n$ として、 $a$ が乗法的関数のとき、計算量が良くなるような分割になるようにする。