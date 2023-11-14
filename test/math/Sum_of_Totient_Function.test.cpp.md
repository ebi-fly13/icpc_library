---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/dirichlet_series.hpp
    title: math/dirichlet_series.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/math/Sum_of_Totient_Function.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\n#line 2 \"math/dirichlet_series.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"math/dirichlet_series.hpp\"\n\nnamespace lib {\n\ntemplate <class\
    \ T>\nstd::vector<T> dirichlet_convolution(const std::vector<T> &a,\n        \
    \                             const std::vector<T> &b) {\n    assert(a.size()\
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
    \ = {};\n\n}  // namespace lib\n#line 2 \"utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\
    \n\nnamespace lib {\n\ntemplate <ll m> struct modint {\n    using mint = modint;\n\
    \    ll a;\n\n    modint(ll x = 0) : a((x % m + m) % m) {}\n    static constexpr\
    \ ll mod() {\n        return m;\n    }\n    ll val() const {\n        return a;\n\
    \    }\n    ll& val() {\n        return a;\n    }\n    mint pow(ll n) const {\n\
    \        mint res = 1;\n        mint x = a;\n        while (n) {\n           \
    \ if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n        }\n\
    \        return res;\n    }\n    mint inv() const {\n        return pow(m - 2);\n\
    \    }\n    mint& operator+=(const mint rhs) {\n        a += rhs.a;\n        if\
    \ (a >= m) a -= m;\n        return *this;\n    }\n    mint& operator-=(const mint\
    \ rhs) {\n        if (a < rhs.a) a += m;\n        a -= rhs.a;\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint rhs) {\n        a = a * rhs.a\
    \ % m;\n        return *this;\n    }\n    mint& operator/=(mint rhs) {\n     \
    \   *this *= rhs.inv();\n        return *this;\n    }\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const modint &lhs, const modint &rhs) {\n        return\
    \ lhs.a == rhs.a;\n    }\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\n        return !(lhs == rhs);\n    }\n    mint operator+() const\
    \ {\n        return *this;\n    }\n    mint operator-() const {\n        return\
    \ mint() - *this;\n    }\n};\n\nusing modint998244353 = modint<998244353>;\nusing\
    \ modint1000000007 = modint<1'000'000'007>;\n\n}  // namespace lib\n#line 6 \"\
    test/math/Sum_of_Totient_Function.test.cpp\"\n\nnamespace lib {\n\nusing mint\
    \ = modint998244353;\n\nvoid main_() {\n    ll n;\n    std::cin >> n;\n    using\
    \ DirichletSeries = DirichletSeries<mint, 0>;\n    DirichletSeries::set_size(n);\n\
    \    mint ans = (DirichletSeries::zeta1() / DirichletSeries::zeta()).get_sum();\n\
    \    std::cout << ans.val() << '\\n';\n}\n\n}  // namespace ebi\n\nint main()\
    \ {\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        lib::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n#include \"../../math/dirichlet_series.hpp\"\n#include \"../../utility/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace lib {\n\nusing mint =\
    \ modint998244353;\n\nvoid main_() {\n    ll n;\n    std::cin >> n;\n    using\
    \ DirichletSeries = DirichletSeries<mint, 0>;\n    DirichletSeries::set_size(n);\n\
    \    mint ans = (DirichletSeries::zeta1() / DirichletSeries::zeta()).get_sum();\n\
    \    std::cout << ans.val() << '\\n';\n}\n\n}  // namespace ebi\n\nint main()\
    \ {\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        lib::main_();\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - math/dirichlet_series.hpp
  - template/template.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/math/Sum_of_Totient_Function.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 21:03:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Sum_of_Totient_Function.test.cpp
layout: document
redirect_from:
- /verify/test/math/Sum_of_Totient_Function.test.cpp
- /verify/test/math/Sum_of_Totient_Function.test.cpp.html
title: test/math/Sum_of_Totient_Function.test.cpp
---
