---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dsu.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"data_structure/dsu.hpp\"\
    \n\nnamespace lib {\n\nstruct dsu {\n  public:\n    dsu(int n = 0) : _n(n), pos(n,\
    \ -1) {}\n\n    int merge(int a, int b) {\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-pos[x] < -pos[y]) swap(x, y);\n \
    \       pos[x] += pos[y];\n        pos[y] = x;\n        return x;\n    }\n\n \
    \   bool same(int a, int b) { return leader(a) == leader(b); }\n\n    int leader(int\
    \ a) {\n        if (pos[a] < 0) return a;\n        return pos[a] = leader(pos[a]);\n\
    \    }\n\n    int size(int a) { return -pos[leader(a)]; }\n\n  private:\n    int\
    \ _n;\n    vector<int> pos;\n};\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nstruct dsu {\n  public:\n    dsu(int n = 0) : _n(n), pos(n, -1) {}\n\n    int\
    \ merge(int a, int b) {\n        int x = leader(a), y = leader(b);\n        if\
    \ (x == y) return x;\n        if (-pos[x] < -pos[y]) swap(x, y);\n        pos[x]\
    \ += pos[y];\n        pos[y] = x;\n        return x;\n    }\n\n    bool same(int\
    \ a, int b) { return leader(a) == leader(b); }\n\n    int leader(int a) {\n  \
    \      if (pos[a] < 0) return a;\n        return pos[a] = leader(pos[a]);\n  \
    \  }\n\n    int size(int a) { return -pos[leader(a)]; }\n\n  private:\n    int\
    \ _n;\n    vector<int> pos;\n};\n\n}  // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/dsu.hpp
  requiredBy: []
  timestamp: '2023-05-08 15:48:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/dsu.hpp
layout: document
redirect_from:
- /library/data_structure/dsu.hpp
- /library/data_structure/dsu.hpp.html
title: data_structure/dsu.hpp
---
