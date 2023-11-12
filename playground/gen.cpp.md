---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"playground/gen.cpp\"\n#include <bits/stdc++.h>\n\n#define\
    \ rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n)\
    \ for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return\
    \ false;\n    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T\
    \ &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n\nusing namespace std;\n\nmt19937_64 mt;\nll rnd(ll l, ll r){\n    assert(l\
    \ <= r);\n    return mt() % (r-l+1) + l;\n}\n\nint main(int argc, char* argv[]){\n\
    \    mt.seed(stoi(argv[1]));\n    ll n = rnd(4,8);\n    ll x = rnd(1,100); //\
    \ [100,675] \u306E\u3068\u3053\u308D\u3092 [1,100] \u306B\u3059\u308B\u3053\u3068\
    \u3067\u3001 diff \u3092\u898B\u3064\u3051\u3084\u3059\u304F\u3059\u308B\n   \
    \ cout << n << \" \" << x << endl;\n    rep(i,0,n){\n        ll s = rnd(1,100);\
    \ // \u3053\u3053\u3082\n        cout << s << \" \\n\"[i == n-1];\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nusing namespace std;\n\n\
    mt19937_64 mt;\nll rnd(ll l, ll r){\n    assert(l <= r);\n    return mt() % (r-l+1)\
    \ + l;\n}\n\nint main(int argc, char* argv[]){\n    mt.seed(stoi(argv[1]));\n\
    \    ll n = rnd(4,8);\n    ll x = rnd(1,100); // [100,675] \u306E\u3068\u3053\u308D\
    \u3092 [1,100] \u306B\u3059\u308B\u3053\u3068\u3067\u3001 diff \u3092\u898B\u3064\
    \u3051\u3084\u3059\u304F\u3059\u308B\n    cout << n << \" \" << x << endl;\n \
    \   rep(i,0,n){\n        ll s = rnd(1,100); // \u3053\u3053\u3082\n        cout\
    \ << s << \" \\n\"[i == n-1];\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: playground/gen.cpp
  requiredBy: []
  timestamp: '2023-11-13 01:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: playground/gen.cpp
layout: document
redirect_from:
- /library/playground/gen.cpp
- /library/playground/gen.cpp.html
title: playground/gen.cpp
---
