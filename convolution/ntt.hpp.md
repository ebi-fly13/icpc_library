---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_mod.test.cpp
    title: test/convolution/Convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Multipoint_Evaluation.test.cpp
    title: test/polynomial/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/ntt.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
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
    }\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"../utility/modint.hpp\"\
    \n\nnamespace lib {\n\nusing mint = modint998244353;\n\nstruct ntt_info {\n  \
    \  static constexpr int rank2 = 23;\n    const int g = 3;\n    std::array<std::array<mint,\
    \ rank2 + 1>, 2> root;\n\n    ntt_info() {\n        root[0][rank2] = mint(g).pow((mint::mod()\
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
    }\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  - utility/modint.hpp
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy: []
  timestamp: '2023-11-14 18:27:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Convolution_mod.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - test/polynomial/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
documentation_of: convolution/ntt.hpp
layout: document
title: NTT convolution
---

## 説明

$\mod 998244353$ でのみ動作する $O(N\log N)$ の畳み込み。

## ntt_info

NTTをするために必要なデータを格納している。

## bit_reverse(int n, int bit_size)

$n$ を ビット幅 bit_size でビットリバースする。

## butterfly(std::vector<mint> &a, bool inverse)

配列 $a$ をFFTする。inverse = true のときinvFFTをする。
invFFTでは割る $n$ をする。
$a$ の配列の大きさは $2$ 冪でないとダメ。

## convolution(std::vector<mint> a, std::vector<mint> b)

$a$ と $b$ を畳み込みその配列を返す。 $O(N\log N)$
