---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT convolution
  - icon: ':heavy_check_mark:'
    path: fps/bostan_mori.hpp
    title: Bostan-Mori Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#line 2 \"convolution/ntt.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n#include\
    \ <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 2 \"utility/modint.hpp\"\
    \n\n#line 4 \"utility/modint.hpp\"\n\nnamespace lib {\n\ntemplate <ll m> struct\
    \ modint {\n    using mint = modint;\n    ll a;\n\n    modint(ll x = 0) : a((x\
    \ % m + m) % m) {}\n    static constexpr ll mod() {\n        return m;\n    }\n\
    \    ll val() const {\n        return a;\n    }\n    ll& val() {\n        return\
    \ a;\n    }\n    mint pow(ll n) const {\n        mint res = 1;\n        mint x\
    \ = a;\n        while (n) {\n            if (n & 1) res *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return res;\n    }\n    mint inv()\
    \ const {\n        return pow(m - 2);\n    }\n    mint& operator+=(const mint\
    \ rhs) {\n        a += rhs.a;\n        if (a >= m) a -= m;\n        return *this;\n\
    \    }\n    mint& operator-=(const mint rhs) {\n        if (a < rhs.a) a += m;\n\
    \        a -= rhs.a;\n        return *this;\n    }\n    mint& operator*=(const\
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
    \n}  // namespace lib\n#line 5 \"convolution/ntt.hpp\"\n\nnamespace lib {\n\n\
    using mint = modint998244353;\n\nstruct ntt_info {\n    static constexpr int rank2\
    \ = 23;\n    const int g = 3;\n    std::array<std::array<mint, rank2 + 1>, 2>\
    \ root;\n\n    ntt_info() {\n        root[0][rank2] = mint(g).pow((mint::mod()\
    \ - 1) >> rank2);\n        root[1][rank2] = root[0][rank2].inv();\n        rrep(i,\
    \ 0, rank2) {\n            root[0][i] = root[0][i + 1] * root[0][i + 1];\n   \
    \         root[1][i] = root[1][i + 1] * root[1][i + 1];\n        }\n    }\n};\n\
    \nvoid butterfly(std::vector<mint>& a, bool inverse) {\n    static ntt_info info;\n\
    \    int n = a.size();\n    int bit_size = 0;\n    while ((1 << bit_size) < n)\
    \ bit_size++;\n    assert(1 << bit_size == n);\n    for (int i = 0, j = 1; j <\
    \ n - 1; j++) {\n        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n      \
    \  if (j < i) {\n            std::swap(a[i], a[j]);\n        }\n    }\n    rep(bit,\
    \ 0, bit_size) {\n        rep(i, 0, n / (1 << (bit + 1))) {\n            mint\
    \ zeta1 = 1;\n            mint zeta2 = info.root[inverse][1];\n            mint\
    \ w = info.root[inverse][bit + 1];\n            rep(j, 0, 1 << bit) {\n      \
    \          int idx = i * (1 << (bit + 1)) + j;\n                int jdx = idx\
    \ + (1 << bit);\n                mint p1 = a[idx];\n                mint p2 =\
    \ a[jdx];\n                a[idx] = p1 + zeta1 * p2;\n                a[jdx] =\
    \ p1 + zeta2 * p2;\n                zeta1 *= w;\n                zeta2 *= w;\n\
    \            }\n        }\n    }\n    if (inverse) {\n        mint inv_n = mint(n).inv();\n\
    \        rep(i, 0, n) a[i] *= inv_n;\n    }\n}\n\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& f,\n                              const std::vector<mint>&\
    \ g) {\n    int n = 1;\n    while (n < int(f.size() + g.size() - 1)) n <<= 1;\n\
    \    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(), f.end(), a.begin());\n\
    \    std::copy(g.begin(), g.end(), b.begin());\n    butterfly(a, false);\n   \
    \ butterfly(b, false);\n    rep(i, 0, n) {\n        a[i] *= b[i];\n    }\n   \
    \ butterfly(a, true);\n    a.resize(f.size() + g.size() - 1);\n    return a;\n\
    }\n\n}  // namespace lib\n#line 2 \"fps/bostan_mori.hpp\"\n\n#line 4 \"fps/bostan_mori.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class T, std::vector<T> (*convolution)(const\
    \ std::vector<T> &,\n                                                 const std::vector<T>\
    \ &)>\nT bostan_mori_algorithm(long long n, std::vector<T> p, std::vector<T> q)\
    \ {\n    while (n > 0) {\n        auto q_neg = q;\n        for (int i = 1; i <\
    \ (int)q_neg.size(); i += 2) q_neg[i] = -q_neg[i];\n        p = convolution(p,\
    \ q_neg);\n        q = convolution(q, q_neg);\n        for (int i = (n & 1LL);\
    \ i < (int)p.size(); i += 2) p[i >> 1] = p[i];\n        p.resize(((int)p.size()\
    \ + 1 - (n & 1LL)) / 2);\n        for (int i = 0; i < (int)q.size(); i += 2) q[i\
    \ >> 1] = q[i];\n        q.resize(((int)q.size() + 1) / 2);\n        n >>= 1;\n\
    \    }\n    return p[0] / q[0];\n}\n\ntemplate <class T, std::vector<T> (*convolution)(const\
    \ std::vector<T> &,\n                                                 const std::vector<T>\
    \ &)>\nT kitamasa(std::int64_t n, std::vector<T> a, std::vector<T> c) {\n    if\
    \ (n < (int)a.size()) return a[n];\n    const int d = c.size();\n    for (auto\
    \ &val : c) val = -val;\n    c.insert(c.begin(), 1);\n    auto p = convolution(a,\
    \ c);\n    p.resize(d);\n    return bostan_mori_algorithm<T, convolution>(n, p,\
    \ c);\n}\n\n}  // namespace lib\n#line 8 \"test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp\"\
    \n\nusing namespace lib;\nusing mint = modint998244353;\n\nint main() {\n    int\
    \ d;\n    long long k;\n    std::cin >> d >> k;\n    std::vector<mint> a(d), c(d);\n\
    \    for (int i = 0; i < d; i++) {\n        int val;\n        std::cin >> val;\n\
    \        a[i] = val;\n    }\n    for (int i = 0; i < d; i++) {\n        int val;\n\
    \        std::cin >> val;\n        c[i] = val;\n    }\n    std::cout << kitamasa<mint,\
    \ convolution>(k, a, c).val() << '\\n';\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include \"../../convolution/ntt.hpp\"\n#include \"../../fps/bostan_mori.hpp\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../utility/modint.hpp\"\
    \n\nusing namespace lib;\nusing mint = modint998244353;\n\nint main() {\n    int\
    \ d;\n    long long k;\n    std::cin >> d >> k;\n    std::vector<mint> a(d), c(d);\n\
    \    for (int i = 0; i < d; i++) {\n        int val;\n        std::cin >> val;\n\
    \        a[i] = val;\n    }\n    for (int i = 0; i < d; i++) {\n        int val;\n\
    \        std::cin >> val;\n        c[i] = val;\n    }\n    std::cout << kitamasa<mint,\
    \ convolution>(k, a, c).val() << '\\n';\n}"
  dependsOn:
  - convolution/ntt.hpp
  - template/template.hpp
  - utility/modint.hpp
  - fps/bostan_mori.hpp
  isVerificationFile: true
  path: test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 20:46:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
- /verify/test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp.html
title: test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
---
