---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/BinaryTrie.hpp
    title: data_structure/BinaryTrie.hpp
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: math/eratosthenes_sieve.hpp
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.hpp
    title: RollingHash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Set_Xor_Min.test.cpp
    title: test/data_structure/Set_Xor_Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_primes.test.cpp
    title: test/math/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/aoj_2444.test.cpp
    title: test/string/aoj_2444.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define\
    \ rep(i,s,n) for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\n\ntemplate<typename T> bool\
    \ chmin(T &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate<typename T> bool chmax(T &a, const T &b){\n    if (a >= b)\
    \ return false;\n    a = b;\n    return true;\n}\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i\
    \ = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const T &b){\n\
    \    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - string/RollingHash.hpp
  - math/eratosthenes_sieve.hpp
  - data_structure/BinaryTrie.hpp
  timestamp: '2023-04-20 01:31:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aoj_2444.test.cpp
  - test/math/enumerate_primes.test.cpp
  - test/data_structure/Set_Xor_Min.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
