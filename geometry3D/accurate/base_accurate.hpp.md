---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry3D/base_arbitary.hpp
    title: geometry3D/base_arbitary.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry3D/accurate/line.hpp
    title: geometry3D/accurate/line.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry3D/accurate/base_accurate.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
    geometry3D/base_arbitary.hpp\"\n\n#line 4 \"geometry3D/base_arbitary.hpp\"\n\n\
    namespace lib {\n\ntemplate<typename T>\nstruct Vec {\n    T x, y, z;\n    Vec\
    \ (T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {}\n    Vec& operator*=(const\
    \ T& a){\n        x *= a;\n        y *= a;\n        z *= a;\n        return *this;\n\
    \    }\n    Vec& operator/=(const T& a){\n        x /= a;\n        y /= a;\n \
    \       z /= a;\n        return *this;\n    }\n    Vec& operator+=(const Vec&\
    \ rhs) {\n        x += rhs.x;\n        y += rhs.y;\n        z += rhs.z;\n    \
    \    return *this;\n    }\n    Vec& operator-=(const Vec& rhs) {\n        x -=\
    \ rhs.x;\n        y -= rhs.y;\n        z -= rhs.z;\n        return *this;\n  \
    \  }\n    friend Vec operator+(const Vec& lhs, const Vec& rhs) {\n        return\
    \ Vec(lhs) += rhs;\n    }\n    friend Vec operator-(const Vec& lhs, const Vec&\
    \ rhs) {\n        return Vec(lhs) -= rhs;\n    }\n    friend Vec operator*(const\
    \ Vec& lhs, const T& rhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend\
    \ Vec operator*(const T& rhs, const Vec& lhs) {\n        return Vec(lhs) *= rhs;\n\
    \    }\n    friend Vec operator/(const Vec& lhs, const T& rhs) {\n        return\
    \ Vec(lhs) /= rhs;\n    }\n    friend std::ostream &operator<<(std::ostream &os,const\
    \ Vec&r) {\n        return os << \"(\" << r.x << \",\" << r.y << \",\" << r.z\
    \ << \")\"; \n    }\n};\n\n};\n#line 5 \"geometry3D/accurate/base_accurate.hpp\"\
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
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry3D/accurate/base_accurate.hpp
layout: document
title: base_accurate
---

3次元幾何を整数で正確に扱うためのライブラリです。

## コンストラクタ

`Vec<T>`

3次元の点やベクトルを表す構造体です。点の座標は `T = ll,int,lib::rational` などの型で保持します。

## cross(外積)

`Vec<T> cross(const Vec<T> &a, const Vec<T> &b)`

外積 $a\times b$ を返します。

## dot(内積)

`T dot(const Vec<T> &a, const Vec<T> &b)`

内積 $a\cdot b$ を返します。

## norm(ノルム)

`T norm(const Vec<T> &a)`

$a$ のノルムを返します。

- `return a.x*a.x + a.y*a.y + a.z*a.z`

## Line (直線)

`Line<T>`

3次元上の直線をそれが通る異なる $2$ 点を保持して管理します。

## intersection

`int intersection(const Line<rational> &p, const Line<rational> &q)`

有理数型で管理されている直線を $2$ つ受け取り、それらの関係を返します。

- $p,q$ が唯一の交点を持つとき `0`
- $p,q$ が平行でないとき `1`
- $p,q$ が一致するとき `2`
- $p,q$ が平行であって一致しないとき `3`

をそれぞれ返します。

## cross_point

`Vec<rational> cross_point(const Line<rational> &p, const Line<rational> &q)`

有理数型で管理されている直線が唯一の交点を持つとき、その交点を返します。

- `assert(intersection(p,q) == 0)` つまり、唯一の交点を持つことを要請します。


## 使用例

[AtCoder301-G Worst Picture への提出](https://atcoder.jp/contests/abc301/submissions/41476430)
