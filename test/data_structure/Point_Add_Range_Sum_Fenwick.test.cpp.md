---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: fenwick tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 2 \"data_structure/fenwick_tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/fenwick_tree.hpp\"\n\nnamespace lib {\n\ntemplate <class T> struct\
    \ fenwick_tree {\n  private:\n    int n;\n    std::vector<T> data;\n\n  public:\n\
    \    fenwick_tree(int n) : n(n), data(n + 1) {}\n\n    void add(int p, T x) {\n\
    \        assert(0 <= p && p < n);\n        p++;\n        for (int i = p; i <=\
    \ n; i += i & -i) {\n            data[i] += x;\n        }\n    }\n\n    T prefix_sum(int\
    \ p) const {\n        assert(0 <= p && p <= n);\n        T ret = 0;\n        for\
    \ (int i = p; i > 0; i -= i & -i) {\n            ret += data[i];\n        }\n\
    \        return ret;\n    }\n\n    T sum(int l, int r) const {\n        return\
    \ prefix_sum(r) - prefix_sum(l);\n    }\n};\n\n}  // namespace lib\n#line 5 \"\
    test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp\"\n\nusing namespace\
    \ lib;\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    fenwick_tree<ll>\
    \ fw(n);\n    rep(i, 0, n) {\n        ll a;\n        std::cin >> a;\n        fw.add(i,\
    \ a);\n    }\n    while (q--) {\n        int t;\n        std::cin >> t;\n    \
    \    if (t == 0) {\n            int p;\n            ll x;\n            std::cin\
    \ >> p >> x;\n            fw.add(p, x);\n        } else {\n            int l,\
    \ r;\n            std::cin >> l >> r;\n            std::cout << fw.sum(l, r) <<\
    \ '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../data_structure/fenwick_tree.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    int n, q;\n    std::cin >> n >>\
    \ q;\n    fenwick_tree<ll> fw(n);\n    rep(i, 0, n) {\n        ll a;\n       \
    \ std::cin >> a;\n        fw.add(i, a);\n    }\n    while (q--) {\n        int\
    \ t;\n        std::cin >> t;\n        if (t == 0) {\n            int p;\n    \
    \        ll x;\n            std::cin >> p >> x;\n            fw.add(p, x);\n \
    \       } else {\n            int l, r;\n            std::cin >> l >> r;\n   \
    \         std::cout << fw.sum(l, r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp
  requiredBy: []
  timestamp: '2023-05-31 14:09:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp
- /verify/test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp.html
title: test/data_structure/Point_Add_Range_Sum_Fenwick.test.cpp
---
