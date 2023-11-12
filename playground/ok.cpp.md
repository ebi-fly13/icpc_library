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
  bundledCode: "#line 1 \"playground/ok.cpp\"\n#include <bits/stdc++.h>\n\n#define\
    \ rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n)\
    \ for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \ntemplate <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return\
    \ false;\n    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T\
    \ &a, const T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n\nusing namespace std;\n\nint main(){\n    int n, x; cin >> n >> x;\n    int\
    \ ans = 0;\n    rep(i,0,n){\n        int s; cin >> s;\n        if (s <= x) ans\
    \ += s; // \u4EE5\u4E0B\n    }\n    cout << ans << endl;\n}\n"
  code: "#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nusing namespace std;\n\n\
    int main(){\n    int n, x; cin >> n >> x;\n    int ans = 0;\n    rep(i,0,n){\n\
    \        int s; cin >> s;\n        if (s <= x) ans += s; // \u4EE5\u4E0B\n   \
    \ }\n    cout << ans << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: playground/ok.cpp
  requiredBy: []
  timestamp: '2023-11-13 01:31:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: playground/ok.cpp
layout: document
redirect_from:
- /library/playground/ok.cpp
- /library/playground/ok.cpp.html
title: playground/ok.cpp
---
