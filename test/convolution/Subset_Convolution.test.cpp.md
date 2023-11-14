---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: math/ranked_subset_transform.hpp
    title: Ranked Subset Transform (Zeta / Mobius)
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
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/convolution/Subset_Convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#line 2 \"\
    convolution/subset_convolution.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n\
    #include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 2 \"math/ranked_subset_transform.hpp\"\
    \n\n#line 4 \"math/ranked_subset_transform.hpp\"\n\nnamespace lib {\n\ntemplate\
    \ <class T, int LIM = 20>\nstd::vector<std::array<T, LIM + 1>> ranked_zeta(const\
    \ std::vector<T> &f) {\n    int n = std::bit_width(f.size()) - 1;\n    assert(n\
    \ <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++)\n        rf[s][std::popcount((unsigned\
    \ int)(s))] = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n\
    \        for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s =\
    \ p; s < p + w; s++) {\n                int t = s | (1 << i);\n              \
    \  for (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n       \
    \ }\n    }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T>\
    \ ranked_mobius(std::vector<std::array<T, LIM + 1>> rf) {\n    int n = std::bit_width(rf.size())\
    \ - 1;\n    assert((int)rf.size() == (1 << n));\n    for (int i = 0; i < n; i++)\
    \ {\n        int w = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w)\
    \ {\n            for (int s = p; s < p + w; s++) {\n                int t = s\
    \ | (1 << i);\n                for (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n\
    \            }\n        }\n    }\n    std::vector<T> f(1 << n);\n    for (int\
    \ s = 0; s < (1 << n); s++) {\n        f[s] = rf[s][std::popcount((unsigned int)(s))];\n\
    \    }\n    return f;\n}\n\n}  // namespace ebi\n#line 5 \"convolution/subset_convolution.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\n                                  const std::vector<T> &b)\
    \ {\n    auto ra = ranked_zeta<T, LIM>(a);\n    auto rb = ranked_zeta<T, LIM>(b);\n\
    \    int n = std::bit_width(a.size()) - 1;\n    for (int s = (1 << n) - 1; s >=\
    \ 0; s--) {\n        auto &f = ra[s];\n        const auto &g = rb[s];\n      \
    \  for (int d = n; d >= 0; d--) {\n            T x = 0;\n            for (int\
    \ i = 0; i <= d; i++) {\n                x += f[i] * g[d - i];\n            }\n\
    \            f[d] = x;\n        }\n    }\n    return ranked_mobius<T, LIM>(ra);\n\
    }\n\n}  // namespace ebi\n#line 4 \"test/convolution/Subset_Convolution.test.cpp\"\
    \n\n#line 2 \"utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate <ll m> struct modint {\n    using mint = modint;\n    ll a;\n\
    \n    modint(ll x = 0) : a((x % m + m) % m) {}\n    static constexpr ll mod()\
    \ {\n        return m;\n    }\n    ll val() const {\n        return a;\n    }\n\
    \    ll& val() {\n        return a;\n    }\n    mint pow(ll n) const {\n     \
    \   mint res = 1;\n        mint x = a;\n        while (n) {\n            if (n\
    \ & 1) res *= x;\n            x *= x;\n            n >>= 1;\n        }\n     \
    \   return res;\n    }\n    mint inv() const {\n        return pow(m - 2);\n \
    \   }\n    mint& operator+=(const mint rhs) {\n        a += rhs.a;\n        if\
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
    \ modint1000000007 = modint<1'000'000'007>;\n\n}  // namespace lib\n#line 7 \"\
    test/convolution/Subset_Convolution.test.cpp\"\n\nusing namespace lib;\nusing\
    \ mint = modint998244353;\n\nint main() {\n    int n;\n    std::cin >> n;\n  \
    \  std::vector<mint> a(1 << n), b(1 << n);\n    for (int i = 0; i < (1 << n);\
    \ i++) {\n        std::cin >> a[i].val();\n    }\n    for (int i = 0; i < (1 <<\
    \ n); i++) {\n        std::cin >> b[i].val();\n    }\n    auto c = subset_convolution<mint,\
    \ 20>(a, b);\n    for (int i = 0; i < (1 << n); i++) {\n        std::cout << c[i].val()\
    \ << ((i == (1 << n) - 1) ? \"\\n\" : \" \");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"../../convolution/subset_convolution.hpp\"\n\n#include \"../../template/template.hpp\"\
    \n#include \"../../utility/modint.hpp\"\n\nusing namespace lib;\nusing mint =\
    \ modint998244353;\n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint>\
    \ a(1 << n), b(1 << n);\n    for (int i = 0; i < (1 << n); i++) {\n        std::cin\
    \ >> a[i].val();\n    }\n    for (int i = 0; i < (1 << n); i++) {\n        std::cin\
    \ >> b[i].val();\n    }\n    auto c = subset_convolution<mint, 20>(a, b);\n  \
    \  for (int i = 0; i < (1 << n); i++) {\n        std::cout << c[i].val() << ((i\
    \ == (1 << n) - 1) ? \"\\n\" : \" \");\n    }\n}"
  dependsOn:
  - convolution/subset_convolution.hpp
  - template/template.hpp
  - math/ranked_subset_transform.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/convolution/Subset_Convolution.test.cpp
  requiredBy: []
  timestamp: '2023-11-15 02:05:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Subset_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Subset_Convolution.test.cpp
- /verify/test/convolution/Subset_Convolution.test.cpp.html
title: test/convolution/Subset_Convolution.test.cpp
---
