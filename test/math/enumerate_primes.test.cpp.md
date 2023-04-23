---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: eratosthenes sieve
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
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
    \n#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n)\
    \ for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1;\
    \ i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
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
    \ prime.emplace_back(i);\n        }\n        return prime;\n    }\n};\n\n}\n#line\
    \ 6 \"test/math/enumerate_primes.test.cpp\"\n\nint main() {\n    int n,a,b;\n\
    \    std::cin >> n >> a >> b;\n    lib::eratosthenes_sieve sieve(n);\n    auto\
    \ p = sieve.prime_table();\n    int sz = p.size();\n    int x = (sz-b+a-1)/a;\n\
    \    std::cout << sz << \" \" << x << '\\n';\n    for(int i = b; i<sz; i += a)\
    \ {\n        std::cout << p[i] << \" \";\n    }\n    std::cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n\n#include \"../../math/eratosthenes_sieve.hpp\"\n\nint main()\
    \ {\n    int n,a,b;\n    std::cin >> n >> a >> b;\n    lib::eratosthenes_sieve\
    \ sieve(n);\n    auto p = sieve.prime_table();\n    int sz = p.size();\n    int\
    \ x = (sz-b+a-1)/a;\n    std::cout << sz << \" \" << x << '\\n';\n    for(int\
    \ i = b; i<sz; i += a) {\n        std::cout << p[i] << \" \";\n    }\n    std::cout\
    \ << \"\\n\";\n}"
  dependsOn:
  - math/eratosthenes_sieve.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/math/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 01:31:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_primes.test.cpp
- /verify/test/math/enumerate_primes.test.cpp.html
title: test/math/enumerate_primes.test.cpp
---
