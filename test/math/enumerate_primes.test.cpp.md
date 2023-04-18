---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: math/eratosthenes_sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/math/enumerate_primes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <iostream>\n\n\
    #line 2 \"math/eratosthenes_sieve.hpp\"\n\n#include <vector>\n#include <cassert>\n\
    \nstruct eratosthenes_sieve {\nprivate:\n    int n;\n    std::vector<bool> table;\n\
    public:\n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n+1, true))\
    \ {\n        table[1] = false;\n        for(int i = 2; i*i<=n; i++) {\n      \
    \      if(!table[i]) continue;\n            for(int j = i; i*j <= n; j++) {\n\
    \                table[i*j] = false;\n            }\n        }\n    }\n\n    bool\
    \ is_prime(int p) {\n        return table[p];\n    }\n\n    std::vector<int> prime_table(int\
    \ m = -1) {\n        if(m < 0) m = n;\n        std::vector<int> prime;\n     \
    \   for(int i = 2; i<=m; i++) {\n            if(table[i]) prime.emplace_back(i);\n\
    \        }\n        return prime;\n    }\n};\n#line 6 \"test/math/enumerate_primes.test.cpp\"\
    \n\nint main() {\n    int n,a,b;\n    std::cin >> n >> a >> b;\n    eratosthenes_sieve\
    \ sieve(n);\n    auto p = sieve.prime_table();\n    int sz = p.size();\n    int\
    \ x = (sz-b+a-1)/a;\n    std::cout << sz << \" \" << x << '\\n';\n    for(int\
    \ i = b; i<sz; i += a) {\n        std::cout << p[i] << \" \";\n    }\n    std::cout\
    \ << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n\n#include \"../../math/eratosthenes_sieve.hpp\"\n\nint main()\
    \ {\n    int n,a,b;\n    std::cin >> n >> a >> b;\n    eratosthenes_sieve sieve(n);\n\
    \    auto p = sieve.prime_table();\n    int sz = p.size();\n    int x = (sz-b+a-1)/a;\n\
    \    std::cout << sz << \" \" << x << '\\n';\n    for(int i = b; i<sz; i += a)\
    \ {\n        std::cout << p[i] << \" \";\n    }\n    std::cout << \"\\n\";\n}"
  dependsOn:
  - math/eratosthenes_sieve.hpp
  isVerificationFile: true
  path: test/math/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2023-04-18 21:56:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_primes.test.cpp
- /verify/test/math/enumerate_primes.test.cpp.html
title: test/math/enumerate_primes.test.cpp
---
