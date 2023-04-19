---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.hpp
    title: RollingHash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aoj_2444.test.cpp
    title: test/string/aoj_2444.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n#line\
    \ 5 \"template/template.hpp\"\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const T &b){\n\
    \    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\n#include<iostream>\n#define rep(i,s,n)\
    \ for (int i = s; i < (int)(n); i++)\n#define all(v) v.begin(),v.end()\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\n\ntemplate<typename T> bool\
    \ chmin(T &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate<typename T> bool chmax(T &a, const T &b){\n    if (a >= b)\
    \ return false;\n    a = b;\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - string/RollingHash.hpp
  timestamp: '2023-04-20 00:09:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aoj_2444.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
