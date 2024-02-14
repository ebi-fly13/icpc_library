---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/Mo_on_Tree.hpp
    title: "\u6728\u4E0A\u306E Mo"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Inversions_Query.test.cpp
    title: test/data_structure/Static_Range_Inversions_Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/aoj_0489.test.cpp
    title: test/tree/aoj_0489.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo_algorithm.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    misc/mo_algorithm.hpp\"\n\nnamespace lib {\n\nstruct Mo {\n    int width;\n  \
    \  vector<int> left, right, order;\n\n    Mo(int N = 1, int Q = 1) : order(Q)\
    \ {\n        width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n\
    \        iota(begin(order), end(order), 0);\n    }\n\n    void insert(int l, int\
    \ r) { /* [l, r) */\n        left.emplace_back(l);\n        right.emplace_back(r);\n\
    \    }\n\n    template <typename AL, typename AR, typename DL, typename DR, typename\
    \ REM>\n    void run(const AL &add_left, const AR &add_right, const DL &delete_left,\n\
    \             const DR &delete_right, const REM &rem) {\n        assert(left.size()\
    \ == order.size());\n        sort(begin(order), end(order), [&](int a, int b)\
    \ {\n            int ablock = left[a] / width, bblock = left[b] / width;\n   \
    \         if (ablock != bblock) return ablock < bblock;\n            if (ablock\
    \ & 1) return right[a] < right[b];\n            return right[a] > right[b];\n\
    \        });\n        int nl = 0, nr = 0;\n        for (auto idx : order) {\n\
    \            while (nl > left[idx]) add_left(--nl);\n            while (nr < right[idx])\
    \ add_right(nr++);\n            while (nl < left[idx]) delete_left(nl++);\n  \
    \          while (nr > right[idx]) delete_right(--nr);\n            rem(idx);\n\
    \        }\n    }\n};\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nstruct Mo {\n    int width;\n    vector<int> left, right, order;\n\n    Mo(int\
    \ N = 1, int Q = 1) : order(Q) {\n        width = max<int>(1, 1.0 * N / max<double>(1.0,\
    \ sqrt(Q * 2.0 / 3.0)));\n        iota(begin(order), end(order), 0);\n    }\n\n\
    \    void insert(int l, int r) { /* [l, r) */\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void run(const AL &add_left,\
    \ const AR &add_right, const DL &delete_left,\n             const DR &delete_right,\
    \ const REM &rem) {\n        assert(left.size() == order.size());\n        sort(begin(order),\
    \ end(order), [&](int a, int b) {\n            int ablock = left[a] / width, bblock\
    \ = left[b] / width;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            if (ablock & 1) return right[a] < right[b];\n            return right[a]\
    \ > right[b];\n        });\n        int nl = 0, nr = 0;\n        for (auto idx\
    \ : order) {\n            while (nl > left[idx]) add_left(--nl);\n           \
    \ while (nr < right[idx]) add_right(nr++);\n            while (nl < left[idx])\
    \ delete_left(nl++);\n            while (nr > right[idx]) delete_right(--nr);\n\
    \            rem(idx);\n        }\n    }\n};\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: misc/mo_algorithm.hpp
  requiredBy:
  - tree/Mo_on_Tree.hpp
  timestamp: '2023-06-30 13:53:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Static_Range_Inversions_Query.test.cpp
  - test/tree/aoj_0489.test.cpp
documentation_of: misc/mo_algorithm.hpp
layout: document
redirect_from:
- /library/misc/mo_algorithm.hpp
- /library/misc/mo_algorithm.hpp.html
title: misc/mo_algorithm.hpp
---
