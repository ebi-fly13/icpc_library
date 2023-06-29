---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/Partition_by_Circles.hpp
    title: geometry/Partition_by_Circles.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Unionfind.test.cpp
    title: test/data_structure/Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/aoj_1198.test.cpp
    title: test/geometry/aoj_1198.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dsu.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/dsu.hpp\"\n\nnamespace lib {\n\nstruct dsu {\n  public:\n    dsu(int\
    \ n = 0) : _n(n), data(n, -1) {}\n\n    int leader(int a) {\n        if (data[a]\
    \ < 0) return a;\n        return data[a] = leader(data[a]);\n    }\n\n    int\
    \ merge(int a, int b) {\n        int x = leader(a), y = leader(b);\n        if\
    \ (x == y) return x;\n        if (-data[x] < -data[y]) swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return x;\n    }\n\n    bool same(int\
    \ a, int b) {\n        return leader(a) == leader(b);\n    }\n\n    int size(int\
    \ a) {\n        return -data[leader(a)];\n    }\n\n  private:\n    int _n;\n \
    \   vector<int> data;\n};\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nstruct dsu {\n  public:\n    dsu(int n = 0) : _n(n), data(n, -1) {}\n\n    int\
    \ leader(int a) {\n        if (data[a] < 0) return a;\n        return data[a]\
    \ = leader(data[a]);\n    }\n\n    int merge(int a, int b) {\n        int x =\
    \ leader(a), y = leader(b);\n        if (x == y) return x;\n        if (-data[x]\
    \ < -data[y]) swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n\
    \        return x;\n    }\n\n    bool same(int a, int b) {\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int size(int a) {\n        return -data[leader(a)];\n\
    \    }\n\n  private:\n    int _n;\n    vector<int> data;\n};\n\n}  // namespace\
    \ lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/dsu.hpp
  requiredBy:
  - geometry/Partition_by_Circles.hpp
  timestamp: '2023-06-02 01:02:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/aoj_1198.test.cpp
  - test/data_structure/Unionfind.test.cpp
documentation_of: data_structure/dsu.hpp
layout: document
title: dsu
---

## 説明

ACL baseのdsu。別名 union find。

### leader(int a)

頂点 $a$ の連結成分の代表元を返す。$O(\alpha(N))$

### size(int a)

頂点 $a$ の連結成分のサイズを返す。$O(\alpha(N))$

### merge(int a, int b)

頂点 $a$ と $b$ をマージし、代表元を返す。$O(\alpha(N))$

### same(int a, int b)

頂点 $a$ と $b$ が同じ連結成分に属するか判定。 $O(\alpha(N))$