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
  bundledCode: "#line 2 \"geometry/base_arbitary.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"geometry/base_arbitary.hpp\"\
    \n\nnamespace lib {\n\ntemplate <typename T> struct Vec {\n    T x, y;\n    Vec(T\
    \ _x = T(0), T _y = T(0)) : x(_x), y(_y) {}\n    Vec& operator*=(const T& a) {\n\
    \        x *= a;\n        y *= a;\n        return *this;\n    }\n    Vec& operator/=(const\
    \ T& a) {\n        x /= a;\n        y /= a;\n        return *this;\n    }\n  \
    \  Vec& operator+=(const Vec& rhs) {\n        x += rhs.x;\n        y += rhs.y;\n\
    \        return *this;\n    }\n    Vec& operator-=(const Vec& rhs) {\n       \
    \ x -= rhs.x;\n        y -= rhs.y;\n        return *this;\n    }\n    friend bool\
    \ operator==(const Vec& lhs, const Vec& rhs) {\n        return lhs.x == rhs.x\
    \ && lhs.y == rhs.y;\n    }\n    friend bool operator!=(const Vec& lhs, const\
    \ Vec& rhs) {\n        return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n    friend\
    \ Vec operator+(const Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) +=\
    \ rhs;\n    }\n    friend Vec operator-(const Vec& lhs, const Vec& rhs) {\n  \
    \      return Vec(lhs) -= rhs;\n    }\n    friend Vec operator*(const Vec& lhs,\
    \ const T& rhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend Vec operator*(const\
    \ T& rhs, const Vec& lhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend\
    \ Vec operator/(const Vec& lhs, const T& rhs) {\n        return Vec(lhs) /= rhs;\n\
    \    }\n    friend Vec operator/(const T& rhs, const Vec& lhs) {\n        return\
    \ Vec(lhs) /= rhs;\n    }\n};\n\ntemplate <typename T> T dot(const Vec<T>& a,\
    \ const Vec<T>& b) {\n    return a.x * b.x + a.y * b.y;\n}\n\n// cross > 0 : counter\
    \ clockwise a -> b\ntemplate <typename T> T cross(const Vec<T>& a, const Vec<T>&\
    \ b) {\n    return a.x * b.y - a.y * b.x;\n}\n\ntemplate <typename T> ld abs(const\
    \ Vec<T>& a) {\n    return sqrtl(a.x * a.x + a.y * a.y);\n}\n\ntemplate <typename\
    \ T> T norm(const Vec<T>& a) {\n    return a.x * a.x + a.y * a.y;\n}\n\ntemplate\
    \ <typename T> struct Line { Vec<T> p, q; };\n\ntemplate <typename T> int intersection(const\
    \ Line<T>& a, const Line<T>& b) {\n    if (cross(a.p - a.q, b.p - b.q) == 0) {\n\
    \        if (cross(a.p - b.p, a.q - b.p) == 0) return 2;\n        return 0;\n\
    \    }\n    return 1;\n}\n\n// intersection == 1 (cross(a.p-a.q,b.p-b.q) != 0)\n\
    template <typename T> Vec<T> cross_point(const Line<T>& a, const Line<T>& b) {\n\
    \    Vec<T> va = a.p - a.q, vb = b.p - b.q;\n    Vec<T> ba = b.p - a.q;\n    T\
    \ alpha = cross(ba, vb) / cross(va, vb);\n    return alpha * a.p + (1 - alpha)\
    \ * a.q;\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <typename T> struct Vec {\n    T x, y;\n    Vec(T _x = T(0), T _y =\
    \ T(0)) : x(_x), y(_y) {}\n    Vec& operator*=(const T& a) {\n        x *= a;\n\
    \        y *= a;\n        return *this;\n    }\n    Vec& operator/=(const T& a)\
    \ {\n        x /= a;\n        y /= a;\n        return *this;\n    }\n    Vec&\
    \ operator+=(const Vec& rhs) {\n        x += rhs.x;\n        y += rhs.y;\n   \
    \     return *this;\n    }\n    Vec& operator-=(const Vec& rhs) {\n        x -=\
    \ rhs.x;\n        y -= rhs.y;\n        return *this;\n    }\n    friend bool operator==(const\
    \ Vec& lhs, const Vec& rhs) {\n        return lhs.x == rhs.x && lhs.y == rhs.y;\n\
    \    }\n    friend bool operator!=(const Vec& lhs, const Vec& rhs) {\n       \
    \ return lhs.x != rhs.x || lhs.y != rhs.y;\n    }\n    friend Vec operator+(const\
    \ Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) += rhs;\n    }\n    friend\
    \ Vec operator-(const Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) -=\
    \ rhs;\n    }\n    friend Vec operator*(const Vec& lhs, const T& rhs) {\n    \
    \    return Vec(lhs) *= rhs;\n    }\n    friend Vec operator*(const T& rhs, const\
    \ Vec& lhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend Vec operator/(const\
    \ Vec& lhs, const T& rhs) {\n        return Vec(lhs) /= rhs;\n    }\n    friend\
    \ Vec operator/(const T& rhs, const Vec& lhs) {\n        return Vec(lhs) /= rhs;\n\
    \    }\n};\n\ntemplate <typename T> T dot(const Vec<T>& a, const Vec<T>& b) {\n\
    \    return a.x * b.x + a.y * b.y;\n}\n\n// cross > 0 : counter clockwise a ->\
    \ b\ntemplate <typename T> T cross(const Vec<T>& a, const Vec<T>& b) {\n    return\
    \ a.x * b.y - a.y * b.x;\n}\n\ntemplate <typename T> ld abs(const Vec<T>& a) {\n\
    \    return sqrtl(a.x * a.x + a.y * a.y);\n}\n\ntemplate <typename T> T norm(const\
    \ Vec<T>& a) {\n    return a.x * a.x + a.y * a.y;\n}\n\ntemplate <typename T>\
    \ struct Line { Vec<T> p, q; };\n\ntemplate <typename T> int intersection(const\
    \ Line<T>& a, const Line<T>& b) {\n    if (cross(a.p - a.q, b.p - b.q) == 0) {\n\
    \        if (cross(a.p - b.p, a.q - b.p) == 0) return 2;\n        return 0;\n\
    \    }\n    return 1;\n}\n\n// intersection == 1 (cross(a.p-a.q,b.p-b.q) != 0)\n\
    template <typename T> Vec<T> cross_point(const Line<T>& a, const Line<T>& b) {\n\
    \    Vec<T> va = a.p - a.q, vb = b.p - b.q;\n    Vec<T> ba = b.p - a.q;\n    T\
    \ alpha = cross(ba, vb) / cross(va, vb);\n    return alpha * a.p + (1 - alpha)\
    \ * a.q;\n}\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/base_arbitary.hpp
  requiredBy: []
  timestamp: '2023-05-14 18:25:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/base_rational.test.cpp
documentation_of: geometry/base_arbitary.hpp
layout: document
redirect_from:
- /library/geometry/base_arbitary.hpp
- /library/geometry/base_arbitary.hpp.html
title: geometry/base_arbitary.hpp
---
