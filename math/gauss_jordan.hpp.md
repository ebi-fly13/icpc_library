---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define\
    \ rep(i,s,n) for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template<typename T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T &a, const\
    \ T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace\
    \ lib{\n\nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n\
    #line 3 \"math/gauss_jordan.hpp\"\n\nnamespace lib{\nusing namespace std;\n\n\
    template <typename T>\nvector<vector<T>> gauss_jordan(vector<vector<T>> &a){\n\
    \    int n = a.size();\n    int m = a[0].size();\n    vector<vector<T>> b = a;\n\
    \    int piv = 0;\n    rep(j,0,m) rep(i,piv,n){\n        if (b[i][j] != T(0)){\n\
    \            swap(b[i], b[piv]);\n            T ip = T(1) / b[piv][j];\n     \
    \       rep(l,0,n){\n                if (l != piv){\n                    T tmp\
    \ = ip * b[l][j];\n                    rep(k,j,m) b[l][k] -= tmp * b[piv][k];\n\
    \                }\n            }\n            rep(k,j,m) b[piv][k] *= ip;\n \
    \           piv++;\n            break;\n        }\n    }\n    return b;\n}\n\n\
    }\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nnamespace lib{\nusing\
    \ namespace std;\n\ntemplate <typename T>\nvector<vector<T>> gauss_jordan(vector<vector<T>>\
    \ &a){\n    int n = a.size();\n    int m = a[0].size();\n    vector<vector<T>>\
    \ b = a;\n    int piv = 0;\n    rep(j,0,m) rep(i,piv,n){\n        if (b[i][j]\
    \ != T(0)){\n            swap(b[i], b[piv]);\n            T ip = T(1) / b[piv][j];\n\
    \            rep(l,0,n){\n                if (l != piv){\n                   \
    \ T tmp = ip * b[l][j];\n                    rep(k,j,m) b[l][k] -= tmp * b[piv][k];\n\
    \                }\n            }\n            rep(k,j,m) b[piv][k] *= ip;\n \
    \           piv++;\n            break;\n        }\n    }\n    return b;\n}\n\n\
    }"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: math/gauss_jordan.hpp
  requiredBy: []
  timestamp: '2023-04-25 22:24:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/gauss_jordan.hpp
layout: document
redirect_from:
- /library/math/gauss_jordan.hpp
- /library/math/gauss_jordan.hpp.html
title: math/gauss_jordan.hpp
---
