---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/base_rational.test.cpp
    title: test/geometry/base_rational.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rational.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"utility/rational.hpp\"\
    \n\nnamespace lib {\n\nstruct rational {\n    rational() : p(0), q(1) {}\n   \
    \ rational(ll n) : p(n), q(1) {}\n    rational(ll n, ll m) {\n        assert(m\
    \ != 0);\n        if (m < 0) n = -n, m = -m;\n        ll g = gcd(n, m);\n    \
    \    p = n / g;\n        q = m / g;\n    }\n    ld val() {\n        return ld(p)\
    \ / ld(q);\n    }\n    rational& operator+=(const rational& rhs) {\n        ll\
    \ g = gcd(q, rhs.q);\n        ll np = rhs.q / g * p + q / g * rhs.p;\n       \
    \ ll nq = q / g * rhs.q;\n        ll ng = gcd(np, nq);\n        p = np / ng, q\
    \ = nq / ng;\n        return *this;\n    }\n    rational& operator-=(const rational&\
    \ rhs) {\n        (*this) += rational(-rhs.p, rhs.q);\n        return *this;\n\
    \    }\n    rational& operator*=(const rational& rhs) {\n        ll g1 = gcd(q,\
    \ rhs.p), g2 = gcd(p, rhs.q);\n        ll np = p / g2 * rhs.p / g1;\n        ll\
    \ nq = q / g1 * rhs.q / g2;\n        p = np, q = nq;\n        return *this;\n\
    \    }\n    rational& operator/=(const rational& rhs) {\n        (*this) *= rational(rhs.q,\
    \ rhs.p);\n        return *this;\n    }\n    rational operator+() const {\n  \
    \      return *this;\n    }\n    rational operator-() const {\n        return\
    \ rational() - *this;\n    }\n    friend rational operator+(const rational& lhs,\
    \ const rational& rhs) {\n        return rational(lhs) += rhs;\n    }\n    friend\
    \ rational operator-(const rational& lhs, const rational& rhs) {\n        return\
    \ rational(lhs) -= rhs;\n    }\n    friend rational operator*(const rational&\
    \ lhs, const rational& rhs) {\n        return rational(lhs) *= rhs;\n    }\n \
    \   friend rational operator/(const rational& lhs, const rational& rhs) {\n  \
    \      return rational(lhs) /= rhs;\n    }\n    friend bool operator==(const rational&\
    \ lhs, const rational& rhs) {\n        return lhs.p == rhs.p && lhs.q == rhs.q;\n\
    \    }\n    friend bool operator!=(const rational& lhs, const rational& rhs) {\n\
    \        return lhs.p != rhs.p || lhs.q != rhs.q;\n    }\n    friend bool operator<(const\
    \ rational lhs, const rational rhs) {\n        return less_than(lhs, rhs);\n \
    \   }\n    friend bool operator>(const rational lhs, const rational rhs) {\n \
    \       return less_than(rhs, lhs);\n    }\n    friend bool operator<=(const rational\
    \ lhs, const rational rhs) {\n        return lhs == rhs || lhs < rhs;\n    }\n\
    \    friend bool operator>=(const rational lhs, const rational rhs) {\n      \
    \  return lhs == rhs || lhs > rhs;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const rational& r) {\n        return os << r.p << \" / \" << r.q;\n    }\n\
    \n  private:\n    ll p, q;\n    static bool less_than(rational lhs, rational rhs)\
    \ {\n        __int128_t lv = __int128_t(lhs.p) * __int128_t(rhs.q);\n        __int128_t\
    \ rv = __int128_t(lhs.q) * __int128_t(rhs.p);\n        return lv < rv;\n    }\n\
    };\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nstruct rational {\n    rational() : p(0), q(1) {}\n    rational(ll n) : p(n),\
    \ q(1) {}\n    rational(ll n, ll m) {\n        assert(m != 0);\n        if (m\
    \ < 0) n = -n, m = -m;\n        ll g = gcd(n, m);\n        p = n / g;\n      \
    \  q = m / g;\n    }\n    ld val() {\n        return ld(p) / ld(q);\n    }\n \
    \   rational& operator+=(const rational& rhs) {\n        ll g = gcd(q, rhs.q);\n\
    \        ll np = rhs.q / g * p + q / g * rhs.p;\n        ll nq = q / g * rhs.q;\n\
    \        ll ng = gcd(np, nq);\n        p = np / ng, q = nq / ng;\n        return\
    \ *this;\n    }\n    rational& operator-=(const rational& rhs) {\n        (*this)\
    \ += rational(-rhs.p, rhs.q);\n        return *this;\n    }\n    rational& operator*=(const\
    \ rational& rhs) {\n        ll g1 = gcd(q, rhs.p), g2 = gcd(p, rhs.q);\n     \
    \   ll np = p / g2 * rhs.p / g1;\n        ll nq = q / g1 * rhs.q / g2;\n     \
    \   p = np, q = nq;\n        return *this;\n    }\n    rational& operator/=(const\
    \ rational& rhs) {\n        (*this) *= rational(rhs.q, rhs.p);\n        return\
    \ *this;\n    }\n    rational operator+() const {\n        return *this;\n   \
    \ }\n    rational operator-() const {\n        return rational() - *this;\n  \
    \  }\n    friend rational operator+(const rational& lhs, const rational& rhs)\
    \ {\n        return rational(lhs) += rhs;\n    }\n    friend rational operator-(const\
    \ rational& lhs, const rational& rhs) {\n        return rational(lhs) -= rhs;\n\
    \    }\n    friend rational operator*(const rational& lhs, const rational& rhs)\
    \ {\n        return rational(lhs) *= rhs;\n    }\n    friend rational operator/(const\
    \ rational& lhs, const rational& rhs) {\n        return rational(lhs) /= rhs;\n\
    \    }\n    friend bool operator==(const rational& lhs, const rational& rhs) {\n\
    \        return lhs.p == rhs.p && lhs.q == rhs.q;\n    }\n    friend bool operator!=(const\
    \ rational& lhs, const rational& rhs) {\n        return lhs.p != rhs.p || lhs.q\
    \ != rhs.q;\n    }\n    friend bool operator<(const rational lhs, const rational\
    \ rhs) {\n        return less_than(lhs, rhs);\n    }\n    friend bool operator>(const\
    \ rational lhs, const rational rhs) {\n        return less_than(rhs, lhs);\n \
    \   }\n    friend bool operator<=(const rational lhs, const rational rhs) {\n\
    \        return lhs == rhs || lhs < rhs;\n    }\n    friend bool operator>=(const\
    \ rational lhs, const rational rhs) {\n        return lhs == rhs || lhs > rhs;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const rational&\
    \ r) {\n        return os << r.p << \" / \" << r.q;\n    }\n\n  private:\n   \
    \ ll p, q;\n    static bool less_than(rational lhs, rational rhs) {\n        __int128_t\
    \ lv = __int128_t(lhs.p) * __int128_t(rhs.q);\n        __int128_t rv = __int128_t(lhs.q)\
    \ * __int128_t(rhs.p);\n        return lv < rv;\n    }\n};\n\n}  // namespace\
    \ lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: utility/rational.hpp
  requiredBy: []
  timestamp: '2023-05-14 18:25:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/base_rational.test.cpp
documentation_of: utility/rational.hpp
layout: document
redirect_from:
- /library/utility/rational.hpp
- /library/utility/rational.hpp.html
title: utility/rational.hpp
---
