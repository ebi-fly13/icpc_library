---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp
    title: test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Inversions_Query.test.cpp
    title: test/data_structure/Static_Range_Inversions_Query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/fenwick_tree.hpp\"\n\nnamespace lib {\n\ntemplate <class T> struct\
    \ fenwick_tree {\n  private:\n    int n;\n    std::vector<T> data;\n\n  public:\n\
    \    fenwick_tree(int n) : n(n), data(n + 1) {}\n\n    void add(int p, T x) {\n\
    \        assert(0 <= p && p < n);\n        p++;\n        for (int i = p; i <=\
    \ n; i += i & -i) {\n            data[i] += x;\n        }\n    }\n\n    T prefix_sum(int\
    \ p) const {\n        assert(0 <= p && p <= n);\n        T ret = 0;\n        for\
    \ (int i = p; i > 0; i -= i & -i) {\n            ret += data[i];\n        }\n\
    \        return ret;\n    }\n\n    T sum(int l, int r) const {\n        return\
    \ prefix_sum(r) - prefix_sum(l);\n    }\n};\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class T> struct fenwick_tree {\n  private:\n    int n;\n    std::vector<T>\
    \ data;\n\n  public:\n    fenwick_tree(int n) : n(n), data(n + 1) {}\n\n    void\
    \ add(int p, T x) {\n        assert(0 <= p && p < n);\n        p++;\n        for\
    \ (int i = p; i <= n; i += i & -i) {\n            data[i] += x;\n        }\n \
    \   }\n\n    T prefix_sum(int p) const {\n        assert(0 <= p && p <= n);\n\
    \        T ret = 0;\n        for (int i = p; i > 0; i -= i & -i) {\n         \
    \   ret += data[i];\n        }\n        return ret;\n    }\n\n    T sum(int l,\
    \ int r) const {\n        return prefix_sum(r) - prefix_sum(l);\n    }\n};\n\n\
    }  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2023-05-31 14:09:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp
  - test/data_structure/Static_Range_Inversions_Query.test.cpp
documentation_of: data_structure/fenwick_tree.hpp
layout: document
title: fenwick tree
---

## 説明

配列 $a$ に対して、$1$ 点加算、区間和が $O(\log N)$ でできるデータ構造。

### add(int p, T x)

a[p] に $x$ を加算

### prefix_sum(int p)

sum(a[0], ..., a[p-1]) を返す。

### sum(int l, int r)

sum(a[l], ..., a[r-1]) を返す。