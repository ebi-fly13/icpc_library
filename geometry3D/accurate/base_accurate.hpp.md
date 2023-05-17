---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry3D/base_arbitary.hpp
    title: geometry3D/base_arbitary.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry3D/accurate/line.hpp
    title: geometry3D/accurate/line.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/geometry3D/Worst_Picture.test.cpp
    title: test/geometry3D/Worst_Picture.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry3D/accurate/base_accurate.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 2 \"geometry3D/base_arbitary.hpp\"\
    \n\n#line 4 \"geometry3D/base_arbitary.hpp\"\n\nnamespace lib {\n\ntemplate<typename\
    \ T>\nstruct Vec {\n    T x, y, z;\n    Vec (T _x = 0, T _y = 0, T _z = 0) : x(_x),\
    \ y(_y), z(_z) {}\n    Vec& operator*=(const T& a){\n        x *= a;\n       \
    \ y *= a;\n        z *= a;\n        return *this;\n    }\n    Vec& operator/=(const\
    \ T& a){\n        x /= a;\n        y /= a;\n        z /= a;\n        return *this;\n\
    \    }\n    Vec& operator+=(const Vec& rhs) {\n        x += rhs.x;\n        y\
    \ += rhs.y;\n        z += rhs.z;\n        return *this;\n    }\n    Vec& operator-=(const\
    \ Vec& rhs) {\n        x -= rhs.x;\n        y -= rhs.y;\n        z -= rhs.z;\n\
    \        return *this;\n    }\n    friend Vec operator+(const Vec& lhs, const\
    \ Vec& rhs) {\n        return Vec(lhs) += rhs;\n    }\n    friend Vec operator-(const\
    \ Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) -= rhs;\n    }\n    friend\
    \ Vec operator*(const Vec& lhs, const T& rhs) {\n        return Vec(lhs) *= rhs;\n\
    \    }\n    friend Vec operator*(const T& rhs, const Vec& lhs) {\n        return\
    \ Vec(lhs) *= rhs;\n    }\n    friend Vec operator/(const Vec& lhs, const T& rhs)\
    \ {\n        return Vec(lhs) /= rhs;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os,const Vec&r) {\n        return os << \"(\" << r.x << \",\" << r.y << \"\
    ,\" << r.z << \")\"; \n    }\n};\n\n};\n#line 5 \"geometry3D/accurate/base_accurate.hpp\"\
    \n\nnamespace lib {\n\ntemplate<typename T>\nbool operator==(const Vec<T>& lhs,\
    \ const Vec<T>& rhs) {\n    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z ==\
    \ rhs.z;\n}\n\ntemplate<typename T>\nT dot(const Vec<T> &a, const Vec<T> &b){\n\
    \    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n\ntemplate<typename T>\nVec<T> cross(const\
    \ Vec<T> &a, const Vec<T> &b){\n    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z,\
    \ a.x*b.y-a.y*b.x);\n}\n\ntemplate<typename T>\nT norm(const Vec<T> &a){\n   \
    \ return a.x*a.x+a.y*a.y+a.z*a.z;\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../../template/template.hpp\"\n#include \"../base_arbitary.hpp\"\
    \n\nnamespace lib {\n\ntemplate<typename T>\nbool operator==(const Vec<T>& lhs,\
    \ const Vec<T>& rhs) {\n    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z ==\
    \ rhs.z;\n}\n\ntemplate<typename T>\nT dot(const Vec<T> &a, const Vec<T> &b){\n\
    \    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n\ntemplate<typename T>\nVec<T> cross(const\
    \ Vec<T> &a, const Vec<T> &b){\n    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z,\
    \ a.x*b.y-a.y*b.x);\n}\n\ntemplate<typename T>\nT norm(const Vec<T> &a){\n   \
    \ return a.x*a.x+a.y*a.y+a.z*a.z;\n}\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  - geometry3D/base_arbitary.hpp
  isVerificationFile: false
  path: geometry3D/accurate/base_accurate.hpp
  requiredBy:
  - geometry3D/accurate/line.hpp
  timestamp: '2023-05-17 17:41:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/geometry3D/Worst_Picture.test.cpp
documentation_of: geometry3D/accurate/base_accurate.hpp
layout: document
redirect_from:
- /library/geometry3D/accurate/base_accurate.hpp
- /library/geometry3D/accurate/base_accurate.hpp.html
title: geometry3D/accurate/base_accurate.hpp
---
