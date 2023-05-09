---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/RerootingDP_LC.test.cpp
    title: test/tree/RerootingDP_LC.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    #define rep(i, s, n) for (int i = s; i < (int)(n); i++)\n#define rrep(i, s, n)\
    \ for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return\
    \ false;\n    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T\
    \ &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n\nnamespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using\
    \ namespace lib;\n#line 2 \"utility/modint.hpp\"\n\nnamespace lib {\n\ntemplate\
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
    \ = modint<1'000'000'007>;\n\n}  // namespace lib\n"
  code: "#include \"../template/template.hpp\"\n\nnamespace lib {\n\ntemplate <ll\
    \ mod> struct modint {\n    ll a;\n\n    modint(ll x = 0) : a((x % mod + mod)\
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
    \ = modint<1'000'000'007>;\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: utility/modint.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:25:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/RerootingDP_LC.test.cpp
  - test/data_structure/Point_Set_Range_Composite.test.cpp
documentation_of: utility/modint.hpp
layout: document
title: modint
---

## 説明

modを自動で取ってくれる構造体。割り算は素数の場合のみ正常に動作。
