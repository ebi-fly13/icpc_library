---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/RollingHash.hpp
    title: string/RollingHash.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n#line\
    \ 5 \"template/template.hpp\"\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define all(v) v.begin(),v.end()\n\ntemplate<typename T> bool chmin(T\
    \ &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n\
    }\ntemplate<typename T> bool chmax(T &a, const T &b){\n    if (a >= b) return\
    \ false;\n    a = b;\n    return true;\n}\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\n#include<iostream>\n#define rep(i,s,n)\
    \ for (int i = s; i < (int)(n); i++)\n#define all(v) v.begin(),v.end()\n\ntemplate<typename\
    \ T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n\
    \    return true;\n}\ntemplate<typename T> bool chmax(T &a, const T &b){\n   \
    \ if (a >= b) return false;\n    a = b;\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - string/RollingHash.hpp
  timestamp: '2023-04-19 19:08:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
