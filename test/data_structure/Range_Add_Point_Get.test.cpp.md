---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dualsegtree.hpp
    title: dual segtree
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/data_structure/Range_Add_Point_Get.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"data_structure/dualsegtree.hpp\"\n\n#line 5 \"data_structure/dualsegtree.hpp\"\
    \n\nnamespace lib {\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct dualsegtree\
    \ {\n  public:\n    dualsegtree(int n) : n(n) {\n        sz = 1;\n        while\
    \ (sz < n) sz <<= 1;\n        data.assign(2 * sz, e());\n    }\n\n    dualsegtree(const\
    \ std::vector<S> &vec) : n(vec.size()) {\n        sz = 1;\n        while (sz <\
    \ n) sz <<= 1;\n        data.assign(2 * sz, e());\n        std::copy(vec.begin(),\
    \ vec.end(), data.begin() + sz);\n    }\n\n    S get(int p) const {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        S val = e();\n        while (p >\
    \ 0) {\n            val = op(val, data[p]);\n            p >>= 1;\n        }\n\
    \        return val;\n    }\n\n    void apply(int l, int r, S x) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        l += sz;\n        r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                data[l] = op(data[l], x);\n\
    \                l++;\n            }\n            if (r & 1) {\n             \
    \   r--;\n                data[r] = op(data[r], x);\n            }\n         \
    \   l >>= 1;\n            r >>= 1;\n        }\n        return;\n    }\n\n  private:\n\
    \    std::vector<S> data;\n    int n;\n    int sz;\n};\n\n}  // namespace ebi\n\
    #line 5 \"test/data_structure/Range_Add_Point_Get.test.cpp\"\n\nusing namespace\
    \ lib;\n\nint op(int a, int b) {\n    return a + b;\n}\n\nint e() {\n    return\
    \ 0;\n}\n\nint main() {\n    int n,q;\n    std::cin >> n >> q;\n    dualsegtree<int,\
    \ op, e> seg(n);\n    while(q--) {\n        int flag;\n        std::cin >> flag;\n\
    \        if(flag == 0) {\n            int s,t,x;\n            std::cin >> s >>\
    \ t >> x;\n            s--;\n            seg.apply(s, t, x);\n        }\n    \
    \    else {\n            int t;\n            std::cin >> t;\n            t--;\n\
    \            std::cout << seg.get(t) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../data_structure/dualsegtree.hpp\"\
    \n\nusing namespace lib;\n\nint op(int a, int b) {\n    return a + b;\n}\n\nint\
    \ e() {\n    return 0;\n}\n\nint main() {\n    int n,q;\n    std::cin >> n >>\
    \ q;\n    dualsegtree<int, op, e> seg(n);\n    while(q--) {\n        int flag;\n\
    \        std::cin >> flag;\n        if(flag == 0) {\n            int s,t,x;\n\
    \            std::cin >> s >> t >> x;\n            s--;\n            seg.apply(s,\
    \ t, x);\n        }\n        else {\n            int t;\n            std::cin\
    \ >> t;\n            t--;\n            std::cout << seg.get(t) << '\\n';\n   \
    \     }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/dualsegtree.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Add_Point_Get.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 18:38:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Add_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Add_Point_Get.test.cpp
- /verify/test/data_structure/Range_Add_Point_Get.test.cpp.html
title: test/data_structure/Range_Add_Point_Get.test.cpp
---
