---
data:
  _extendedDependsOn: []
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
    \ <cassert>\n\nstruct eratosthenes_sieve {\n  private:\n    int n;\n    std::vector<bool>\
    \ table;\n  public:\n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n+1,\
    \ true)) {\n        table[1] = false;\n        for(int i = 2; i*i<=n; i++) {\n\
    \            if(!table[i]) continue;\n            for(int j = i; i*j <= n; j++)\
    \ {\n                table[i*j] = false;\n            }\n        }\n    }\n\n\
    \    bool is_prime(int p) {\n        return table[p];\n    }\n\n    std::vector<int>\
    \ prime_table(int m = -1) {\n        if(m < 0) m = n;\n        std::vector<int>\
    \ prime;\n        for(int i = 2; i<=m; i++) {\n            if(table[i]) prime.emplace_back(i);\n\
    \        }\n        return prime;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nstruct eratosthenes_sieve\
    \ {\n  private:\n    int n;\n    std::vector<bool> table;\n  public:\n    eratosthenes_sieve(int\
    \ n) : n(n), table(std::vector<bool>(n+1, true)) {\n        table[1] = false;\n\
    \        for(int i = 2; i*i<=n; i++) {\n            if(!table[i]) continue;\n\
    \            for(int j = i; i*j <= n; j++) {\n                table[i*j] = false;\n\
    \            }\n        }\n    }\n\n    bool is_prime(int p) {\n        return\
    \ table[p];\n    }\n\n    std::vector<int> prime_table(int m = -1) {\n       \
    \ if(m < 0) m = n;\n        std::vector<int> prime;\n        for(int i = 2; i<=m;\
    \ i++) {\n            if(table[i]) prime.emplace_back(i);\n        }\n       \
    \ return prime;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes_sieve.hpp
  requiredBy: []
  timestamp: '2023-04-19 14:28:50+09:00'
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
