---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry3D/accurate/base_accurate.hpp
    title: base_accurate
  - icon: ':warning:'
    path: geometry3D/accurate/line.hpp
    title: geometry3D/accurate/line.hpp
  - icon: ':warning:'
    path: geometry3D/ld/base_ld.hpp
    title: geometry3D/ld/base_ld.hpp
  - icon: ':warning:'
    path: geometry3D/ld/line.hpp
    title: geometry3D/ld/line.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry3D/base_arbitary.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    geometry3D/base_arbitary.hpp\"\n\nnamespace lib {\n\ntemplate<typename T>\nstruct\
    \ Vec {\n    T x, y, z;\n    Vec (T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y),\
    \ z(_z) {}\n    Vec& operator*=(const T& a){\n        x *= a;\n        y *= a;\n\
    \        z *= a;\n        return *this;\n    }\n    Vec& operator/=(const T& a){\n\
    \        x /= a;\n        y /= a;\n        z /= a;\n        return *this;\n  \
    \  }\n    Vec& operator+=(const Vec& rhs) {\n        x += rhs.x;\n        y +=\
    \ rhs.y;\n        z += rhs.z;\n        return *this;\n    }\n    Vec& operator-=(const\
    \ Vec& rhs) {\n        x -= rhs.x;\n        y -= rhs.y;\n        z -= rhs.z;\n\
    \        return *this;\n    }\n    friend Vec operator+(const Vec& lhs, const\
    \ Vec& rhs) {\n        return Vec(lhs) += rhs;\n    }\n    friend Vec operator-(const\
    \ Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) -= rhs;\n    }\n    friend\
    \ Vec operator*(const Vec& lhs, const T& rhs) {\n        return Vec(lhs) *= rhs;\n\
    \    }\n    friend Vec operator*(const T& rhs, const Vec& lhs) {\n        return\
    \ Vec(lhs) *= rhs;\n    }\n    friend Vec operator/(const Vec& lhs, const T& rhs)\
    \ {\n        return Vec(lhs) /= rhs;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os,const Vec&r) {\n        return os << \"(\" << r.x << \",\" << r.y << \"\
    ,\" << r.z << \")\"; \n    }\n};\n\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate<typename T>\nstruct Vec {\n    T x, y, z;\n    Vec (T _x = 0, T _y\
    \ = 0, T _z = 0) : x(_x), y(_y), z(_z) {}\n    Vec& operator*=(const T& a){\n\
    \        x *= a;\n        y *= a;\n        z *= a;\n        return *this;\n  \
    \  }\n    Vec& operator/=(const T& a){\n        x /= a;\n        y /= a;\n   \
    \     z /= a;\n        return *this;\n    }\n    Vec& operator+=(const Vec& rhs)\
    \ {\n        x += rhs.x;\n        y += rhs.y;\n        z += rhs.z;\n        return\
    \ *this;\n    }\n    Vec& operator-=(const Vec& rhs) {\n        x -= rhs.x;\n\
    \        y -= rhs.y;\n        z -= rhs.z;\n        return *this;\n    }\n    friend\
    \ Vec operator+(const Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) +=\
    \ rhs;\n    }\n    friend Vec operator-(const Vec& lhs, const Vec& rhs) {\n  \
    \      return Vec(lhs) -= rhs;\n    }\n    friend Vec operator*(const Vec& lhs,\
    \ const T& rhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend Vec operator*(const\
    \ T& rhs, const Vec& lhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend\
    \ Vec operator/(const Vec& lhs, const T& rhs) {\n        return Vec(lhs) /= rhs;\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os,const Vec&r) {\n\
    \        return os << \"(\" << r.x << \",\" << r.y << \",\" << r.z << \")\"; \n\
    \    }\n};\n\n};"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry3D/base_arbitary.hpp
  requiredBy:
  - geometry3D/accurate/line.hpp
  - geometry3D/accurate/base_accurate.hpp
  - geometry3D/ld/line.hpp
  - geometry3D/ld/base_ld.hpp
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry3D/base_arbitary.hpp
layout: document
redirect_from:
- /library/geometry3D/base_arbitary.hpp
- /library/geometry3D/base_arbitary.hpp.html
title: geometry3D/base_arbitary.hpp
---
