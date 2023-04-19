---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_primes.test.cpp
    title: test/math/enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/eratosthenes_sieve.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\n#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\
    #line 5 \"template/template.hpp\"\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const T &b){\n\
    \    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n#line 7 \"math/eratosthenes_sieve.hpp\"\n\nnamespace lib\
    \ {\n\nusing namespace std;\n\nstruct eratosthenes_sieve {\n  private:\n    int\
    \ n;\n    vector<bool> table;\n  public:\n    eratosthenes_sieve(int n) : n(n),\
    \ table(vector<bool>(n+1, true)) {\n        table[1] = false;\n        for(int\
    \ i = 2; i*i<=n; i++) {\n            if(!table[i]) continue;\n            for(int\
    \ j = i; i*j <= n; j++) {\n                table[i*j] = false;\n            }\n\
    \        }\n    }\n\n    bool is_prime(int p) {\n        return table[p];\n  \
    \  }\n\n    vector<int> prime_table(int m = -1) {\n        if(m < 0) m = n;\n\
    \        std::vector<int> prime;\n        rep(i,2,m+1) {\n            if(table[i])\
    \ prime.emplace_back(i);\n        }\n        return prime;\n    }\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\n#include \"../template/template.hpp\"\
    \n\nnamespace lib {\n\nusing namespace std;\n\nstruct eratosthenes_sieve {\n \
    \ private:\n    int n;\n    vector<bool> table;\n  public:\n    eratosthenes_sieve(int\
    \ n) : n(n), table(vector<bool>(n+1, true)) {\n        table[1] = false;\n   \
    \     for(int i = 2; i*i<=n; i++) {\n            if(!table[i]) continue;\n   \
    \         for(int j = i; i*j <= n; j++) {\n                table[i*j] = false;\n\
    \            }\n        }\n    }\n\n    bool is_prime(int p) {\n        return\
    \ table[p];\n    }\n\n    vector<int> prime_table(int m = -1) {\n        if(m\
    \ < 0) m = n;\n        std::vector<int> prime;\n        rep(i,2,m+1) {\n     \
    \       if(table[i]) prime.emplace_back(i);\n        }\n        return prime;\n\
    \    }\n};\n\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: math/eratosthenes_sieve.hpp
  requiredBy: []
  timestamp: '2023-04-20 00:24:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_primes.test.cpp
documentation_of: math/eratosthenes_sieve.hpp
layout: document
redirect_from:
- /library/math/eratosthenes_sieve.hpp
- /library/math/eratosthenes_sieve.hpp.html
title: math/eratosthenes_sieve.hpp
---
