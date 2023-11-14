---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT convolution
  - icon: ':heavy_check_mark:'
    path: convolution/ntt4.hpp
    title: convolution/ntt4.hpp
  - icon: ':heavy_check_mark:'
    path: fps/composition_of_fps.hpp
    title: $f(g(x))$
  - icon: ':heavy_check_mark:'
    path: fps/compositional_inverse_of_fps.hpp
    title: "$f(x)$ \u306E\u9006\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: fps/multipoint_evaluation.hpp
    title: Multipoint Evaluation
  - icon: ':heavy_check_mark:'
    path: fps/polynomial_interpolation.hpp
    title: Polynomial Interpolation
  - icon: ':heavy_check_mark:'
    path: fps/taylor_shift.hpp
    title: $f(x + c)$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_mod.test.cpp
    title: test/convolution/Convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_mod_ntt4.test.cpp
    title: test/convolution/Convolution_mod_ntt4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_FPS_Sparse.test.cpp
    title: test/polynomial/Exp_of_FPS_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_FPS_Sparse.test.cpp
    title: test/polynomial/Inv_of_FPS_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_FPS_Sparse.test.cpp
    title: test/polynomial/Log_of_FPS_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Multipoint_Evaluation.test.cpp
    title: test/polynomial/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Interpolation.test.cpp
    title: test/polynomial/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_FPS_Sparse.test.cpp
    title: test/polynomial/Pow_of_FPS_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/tree/Tree_Path_Composite_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/modint.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    utility/modint.hpp\"\n\nnamespace lib {\n\ntemplate <ll m> struct modint {\n \
    \   using mint = modint;\n    ll a;\n\n    modint(ll x = 0) : a((x % m + m) %\
    \ m) {}\n    static constexpr ll mod() {\n        return m;\n    }\n    ll val()\
    \ const {\n        return a;\n    }\n    ll& val() {\n        return a;\n    }\n\
    \    mint pow(ll n) const {\n        mint res = 1;\n        mint x = a;\n    \
    \    while (n) {\n            if (n & 1) res *= x;\n            x *= x;\n    \
    \        n >>= 1;\n        }\n        return res;\n    }\n    mint inv() const\
    \ {\n        return pow(m - 2);\n    }\n    mint& operator+=(const mint rhs) {\n\
    \        a += rhs.a;\n        if (a >= m) a -= m;\n        return *this;\n   \
    \ }\n    mint& operator-=(const mint rhs) {\n        if (a < rhs.a) a += m;\n\
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
    \n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <ll m> struct modint {\n    using mint = modint;\n    ll a;\n\n   \
    \ modint(ll x = 0) : a((x % m + m) % m) {}\n    static constexpr ll mod() {\n\
    \        return m;\n    }\n    ll val() const {\n        return a;\n    }\n  \
    \  ll& val() {\n        return a;\n    }\n    mint pow(ll n) const {\n       \
    \ mint res = 1;\n        mint x = a;\n        while (n) {\n            if (n &\
    \ 1) res *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return res;\n    }\n    mint inv() const {\n        return pow(m - 2);\n   \
    \ }\n    mint& operator+=(const mint rhs) {\n        a += rhs.a;\n        if (a\
    \ >= m) a -= m;\n        return *this;\n    }\n    mint& operator-=(const mint\
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
    \ modint1000000007 = modint<1'000'000'007>;\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: utility/modint.hpp
  requiredBy:
  - fps/composition_of_fps.hpp
  - fps/polynomial_interpolation.hpp
  - fps/compositional_inverse_of_fps.hpp
  - fps/fps.hpp
  - fps/multipoint_evaluation.hpp
  - fps/taylor_shift.hpp
  - convolution/ntt4.hpp
  - convolution/ntt.hpp
  timestamp: '2023-11-14 18:27:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Tree_Path_Composite_Sum.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/convolution/Convolution_mod.test.cpp
  - test/convolution/Convolution_mod_ntt4.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - test/polynomial/Inv_of_FPS_Sparse.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - test/polynomial/Polynomial_Interpolation.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_FPS_Sparse.test.cpp
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/polynomial/Pow_of_FPS_Sparse.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/polynomial/Log_of_FPS_Sparse.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
documentation_of: utility/modint.hpp
layout: document
title: modint
---

## 説明

modを自動で取ってくれる構造体。割り算は素数の場合のみ正常に動作。
