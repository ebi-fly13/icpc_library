---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/BinaryTrie.hpp
    title: BinaryTrie
  - icon: ':x:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: eratosthenes sieve
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.hpp
    title: RollingHash
  - icon: ':warning:'
    path: string/parsing_template.hpp
    title: string/parsing_template.hpp
  - icon: ':warning:'
    path: tree/HeavyLightDecomposition.hpp
    title: HeavyLightDecomposition
  - icon: ':heavy_check_mark:'
    path: tree/LowestCommonAncestor.hpp
    title: LowestCommonAncestor
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/Point_Add_Range_Sum.test.cpp
    title: test/data_structure/Point_Add_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Set_Xor_Min.test.cpp
    title: test/data_structure/Set_Xor_Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_primes.test.cpp
    title: test/math/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/aoj_2444.test.cpp
    title: test/string/aoj_2444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Lowest_Common_Ancestor.test.cpp
    title: test/tree/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - string/parsing_template.hpp
  - string/RollingHash.hpp
  - tree/HeavyLightDecomposition.hpp
  - tree/LowestCommonAncestor.hpp
  - math/eratosthenes_sieve.hpp
  - data_structure/segtree.hpp
  - data_structure/BinaryTrie.hpp
  timestamp: '2023-04-20 01:31:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/string/aoj_2444.test.cpp
  - test/tree/Lowest_Common_Ancestor.test.cpp
  - test/math/enumerate_primes.test.cpp
  - test/data_structure/Set_Xor_Min.test.cpp
  - test/data_structure/Point_Add_Range_Sum.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
