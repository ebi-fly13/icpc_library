---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/z_algorithm.test.cpp
    title: test/string/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    string/z_algorithm.hpp\"\n\nnamespace lib {\n\ntemplate <class T> std::vector<int>\
    \ z_algorithm(const std::vector<T>& s) {\n    int n = int(s.size());\n    if (n\
    \ == 0) return {};\n    std::vector<int> z(n);\n    z[0] = 0;\n    for (int i\
    \ = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n        k = (j + z[j] <=\
    \ i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n        while (i + k < n && s[k]\
    \ == s[i + k]) k++;\n        if (j + z[j] < i + z[i]) j = i;\n    }\n    z[0]\
    \ = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const std::string& s)\
    \ {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n}\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {\n\
    \    int n = int(s.size());\n    if (n == 0) return {};\n    std::vector<int>\
    \ z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i\
    \ + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2023-06-06 22:09:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/z_algorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
title: Z Algorithm
---

## 説明

$S$ と $S[i, n)$ のLCP (longest common prefix) を計算する。 $O(N)$