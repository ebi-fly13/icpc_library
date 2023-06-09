---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/Binomial_Coefficient.test.cpp
    title: test/misc/Binomial_Coefficient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/dynamic_modint.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    utility/dynamic_modint.hpp\"\n\nnamespace lib {\n\ntemplate <int id> struct dynamic_modint\
    \ {\n    using mint = dynamic_modint;\n    ll a;\n    static ll m;\n    dynamic_modint\
    \ (ll x = 0) : a((x % m + m) % m) {}\n    static ll mod() {\n        return m;\n\
    \    }\n    static void set_mod(ll mod){\n        assert(1 <= mod);\n        m\
    \ = mod;\n    }\n    ll& val() {\n        return a;\n    }\n    mint pow(ll n)\
    \ {\n        mint res = 1;\n        mint x = a;\n        while (n) {\n       \
    \     if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n      \
    \  }\n        return res;\n    }\n    mint inv() {\n        return pow(m - 2);\n\
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
    \ mint operator+() const {\n        return *this;\n    }\n    mint operator-()\
    \ const {\n        return mint() - *this;\n    }\n};\n\ntemplate<int id>\nll dynamic_modint<id>::m\
    \ = 2;\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <int id> struct dynamic_modint {\n    using mint = dynamic_modint;\n\
    \    ll a;\n    static ll m;\n    dynamic_modint (ll x = 0) : a((x % m + m) %\
    \ m) {}\n    static ll mod() {\n        return m;\n    }\n    static void set_mod(ll\
    \ mod){\n        assert(1 <= mod);\n        m = mod;\n    }\n    ll& val() {\n\
    \        return a;\n    }\n    mint pow(ll n) {\n        mint res = 1;\n     \
    \   mint x = a;\n        while (n) {\n            if (n & 1) res *= x;\n     \
    \       x *= x;\n            n >>= 1;\n        }\n        return res;\n    }\n\
    \    mint inv() {\n        return pow(m - 2);\n    }\n    mint& operator+=(const\
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
    \  return mint(lhs) /= rhs;\n    }\n    mint operator+() const {\n        return\
    \ *this;\n    }\n    mint operator-() const {\n        return mint() - *this;\n\
    \    }\n};\n\ntemplate<int id>\nll dynamic_modint<id>::m = 2;\n\n} // namespace\
    \ lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: utility/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2023-06-10 00:47:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/Binomial_Coefficient.test.cpp
documentation_of: utility/dynamic_modint.hpp
layout: document
redirect_from:
- /library/utility/dynamic_modint.hpp
- /library/utility/dynamic_modint.hpp.html
title: utility/dynamic_modint.hpp
---
