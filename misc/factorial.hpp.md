---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/Binomial_Coefficient.test.cpp
    title: test/misc/Binomial_Coefficient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/factorial.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    misc/factorial.hpp\"\n\nnamespace lib {\n\ntemplate<typename T>\nstruct Binom{\n\
    \    Binom(int lim = 300000){\n        if (kaijo.empty()){\n            kaijo\
    \ = {1,1};\n            kainv = {1,1};\n        }\n        kaijo.resize(lim+1),\
    \ kainv.resize(lim+1);\n        for (int i = 2; i <= lim; i++) kaijo[i] = kaijo[i-1]\
    \ * T(i);\n        kainv[lim] = kaijo[lim].inv();\n        for (int i = lim-1;\
    \ i >= 2; i--) kainv[i] = kainv[i+1] * T(i+1);\n    }\n    static T fact(int x)\
    \ {\n        if (x < 0) return T(0);\n        return kaijo[x];\n    }\n    static\
    \ T ifact(int x){\n        if (x < 0) return T(0);\n        return kainv[x];\n\
    \    }\n    static T C(int n, int r){\n        if (n < 0 || n < r || r < 0) return\
    \ T(0);\n        return kaijo[n] * kainv[r] * kainv[n-r];\n    }\n    static T\
    \ P(int n, int r){\n        if (n < 0 || n < r || r < 0) return T(0);\n      \
    \  return kaijo[n] * kainv[n-r];\n    }\n    static T Inv(int n){\n        assert(0\
    \ < n);\n        return ifact(n) * fact(n-1);\n    }\n    T operator()(int n,\
    \ int r){ return C(n,r); }\n  private:\n    static vector<T> kaijo, kainv;\n};\n\
    template<typename T>\nvector<T>Binom<T>::kaijo = vector<T>(2,T(1));\ntemplate<typename\
    \ T>\nvector<T>Binom<T>::kainv = vector<T>(2,T(1));\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate<typename T>\nstruct Binom{\n    Binom(int lim = 300000){\n        if\
    \ (kaijo.empty()){\n            kaijo = {1,1};\n            kainv = {1,1};\n \
    \       }\n        kaijo.resize(lim+1), kainv.resize(lim+1);\n        for (int\
    \ i = 2; i <= lim; i++) kaijo[i] = kaijo[i-1] * T(i);\n        kainv[lim] = kaijo[lim].inv();\n\
    \        for (int i = lim-1; i >= 2; i--) kainv[i] = kainv[i+1] * T(i+1);\n  \
    \  }\n    static T fact(int x) {\n        if (x < 0) return T(0);\n        return\
    \ kaijo[x];\n    }\n    static T ifact(int x){\n        if (x < 0) return T(0);\n\
    \        return kainv[x];\n    }\n    static T C(int n, int r){\n        if (n\
    \ < 0 || n < r || r < 0) return T(0);\n        return kaijo[n] * kainv[r] * kainv[n-r];\n\
    \    }\n    static T P(int n, int r){\n        if (n < 0 || n < r || r < 0) return\
    \ T(0);\n        return kaijo[n] * kainv[n-r];\n    }\n    static T Inv(int n){\n\
    \        assert(0 < n);\n        return ifact(n) * fact(n-1);\n    }\n    T operator()(int\
    \ n, int r){ return C(n,r); }\n  private:\n    static vector<T> kaijo, kainv;\n\
    };\ntemplate<typename T>\nvector<T>Binom<T>::kaijo = vector<T>(2,T(1));\ntemplate<typename\
    \ T>\nvector<T>Binom<T>::kainv = vector<T>(2,T(1));\n\n} // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: misc/factorial.hpp
  requiredBy: []
  timestamp: '2023-06-09 15:23:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/Binomial_Coefficient.test.cpp
documentation_of: misc/factorial.hpp
layout: document
redirect_from:
- /library/misc/factorial.hpp
- /library/misc/factorial.hpp.html
title: misc/factorial.hpp
---
