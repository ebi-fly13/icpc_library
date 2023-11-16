---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/Number_of_Substrings.test.cpp
    title: test/string/Number_of_Substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/Suffix_Array.test.cpp
    title: test/string/Suffix_Array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    string/suffix_array.hpp\"\n\nnamespace lib {\n\nvector<int> suffix_array(const\
    \ string &s) {\n    int n = s.size();\n    vector<int> rnk(n, -1), sa(n);\n  \
    \  iota(all(sa), 0);\n    rep(i, 0, n) {\n        rnk[i] = s[i];\n    }\n    int\
    \ k = 1;\n    auto compare = [&](int i, int j) -> bool {\n        if (rnk[i] !=\
    \ rnk[j]) return rnk[i] < rnk[j];\n        return (i + k < n ? rnk[i + k] : -1)\
    \ < (j + k < n ? rnk[j + k] : -1);\n    };\n    while (k < n) {\n        sort(all(sa),\
    \ compare);\n        vector<int> tmp(n, 0);\n        rep(i, 1, n) {\n        \
    \    tmp[sa[i]] = tmp[sa[i - 1]] + int(compare(sa[i - 1], sa[i]));\n        }\n\
    \        swap(rnk, tmp);\n        k <<= 1;\n    }\n    return sa;\n}\n\nvector<int>\
    \ lcp_array(const string &s, const vector<int> &sa) {\n    int n = s.size();\n\
    \    vector<int> rnk(n), lcp(n - 1);\n    rep(i, 0, n) rnk[sa[i]] = i;\n    int\
    \ h = 0;\n    rep(i, 0, n) {\n        if (h > 0) h--;\n        if (rnk[i] == 0)\
    \ continue;\n        int j = sa[rnk[i] - 1];\n        while (i + h < n && j +\
    \ h < n && s[i + h] == s[j + h]) {\n            h++;\n        }\n        lcp[rnk[i]\
    \ - 1] = h;\n    }\n    return lcp;\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nvector<int> suffix_array(const string &s) {\n    int n = s.size();\n    vector<int>\
    \ rnk(n, -1), sa(n);\n    iota(all(sa), 0);\n    rep(i, 0, n) {\n        rnk[i]\
    \ = s[i];\n    }\n    int k = 1;\n    auto compare = [&](int i, int j) -> bool\
    \ {\n        if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];\n        return (i\
    \ + k < n ? rnk[i + k] : -1) < (j + k < n ? rnk[j + k] : -1);\n    };\n    while\
    \ (k < n) {\n        sort(all(sa), compare);\n        vector<int> tmp(n, 0);\n\
    \        rep(i, 1, n) {\n            tmp[sa[i]] = tmp[sa[i - 1]] + int(compare(sa[i\
    \ - 1], sa[i]));\n        }\n        swap(rnk, tmp);\n        k <<= 1;\n    }\n\
    \    return sa;\n}\n\nvector<int> lcp_array(const string &s, const vector<int>\
    \ &sa) {\n    int n = s.size();\n    vector<int> rnk(n), lcp(n - 1);\n    rep(i,\
    \ 0, n) rnk[sa[i]] = i;\n    int h = 0;\n    rep(i, 0, n) {\n        if (h > 0)\
    \ h--;\n        if (rnk[i] == 0) continue;\n        int j = sa[rnk[i] - 1];\n\
    \        while (i + h < n && j + h < n && s[i + h] == s[j + h]) {\n          \
    \  h++;\n        }\n        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n}\n\n\
    }  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy: []
  timestamp: '2023-11-17 01:51:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/Suffix_Array.test.cpp
  - test/string/Number_of_Substrings.test.cpp
documentation_of: string/suffix_array.hpp
layout: document
title: Suffix Array
---

## 説明

ダブリングによってsuffix arrayを構築する。文字列長を $N$ とする。

### suffix_array(string s)

`s` のsuffix arrayを構築する。 $O(N (\log N)^2)$

### lcp_array(string s, vector<int> sa)

`s` のlcp_arrayを構築する。 $O(N)$