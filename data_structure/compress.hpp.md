---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_segtree_2d.hpp
    title: offline 2D segtree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/compress.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/compress.hpp\"\n\nnamespace lib {\n\ntemplate <class T> struct\
    \ compress {\n  private:\n    std::vector<T> cp;\n\n  public:\n    compress()\
    \ = default;\n\n    compress(std::vector<T> cp) : cp(cp) {\n        build();\n\
    \    }\n\n    void build() {\n        std::sort(cp.begin(), cp.end());\n     \
    \   cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n    }\n\n    void\
    \ add(const T &val) {\n        cp.emplace_back(val);\n    }\n\n    int get(const\
    \ T &val) const {\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n\n    bool find(const T &val) const {\n        auto itr = std::lower_bound(cp.begin(),\
    \ cp.end(), val);\n        if (itr == cp.end())\n            return false;\n \
    \       else\n            return *itr == val;\n    }\n\n    T val(int idx) const\
    \ {\n        assert(0 <= idx && idx < (int)cp.size());\n        return cp[idx];\n\
    \    }\n};\n\n}\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class T> struct compress {\n  private:\n    std::vector<T> cp;\n\n\
    \  public:\n    compress() = default;\n\n    compress(std::vector<T> cp) : cp(cp)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy:
  - data_structure/offline_segtree_2d.hpp
  timestamp: '2023-11-14 21:20:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
title: Compress
---

## 説明

### build()

座圧を実行する。 $O(N\log N)$

### add(T val)

valを座圧の対象にする。 $O(1)$

### get(T val)

valを座圧した後の値を返す。 $O(\log N)$

### size()

座圧後の要素数を返す。 $O(1)$

### find(T val)

valが座圧対象であるか判定。 $O(\log N)$

### val(int idx)

座圧後の値がidxのものの座圧前の値を返す。 $O(1)$