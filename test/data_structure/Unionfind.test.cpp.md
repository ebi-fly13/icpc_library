---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: data_structure/dsu.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/data_structure/Unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"data_structure/dsu.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = s; i < (int)(n); i++)\n#define rrep(i, s, n) for (int i =\
    \ (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"data_structure/dsu.hpp\"\n\nnamespace lib {\n\nstruct dsu {\n\
    \  public:\n    dsu(int n = 0) : _n(n), pos(n, -1) {}\n\n    int merge(int a,\
    \ int b) {\n        int x = leader(a), y = leader(b);\n        if (x == y) return\
    \ x;\n        if (-pos[x] < -pos[y]) swap(x, y);\n        pos[x] += pos[y];\n\
    \        pos[y] = x;\n        return x;\n    }\n\n    bool same(int a, int b)\
    \ {\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a) {\n\
    \        if (pos[a] < 0) return a;\n        return pos[a] = leader(pos[a]);\n\
    \    }\n\n    int size(int a) {\n        return -pos[leader(a)];\n    }\n\n  private:\n\
    \    int _n;\n    vector<int> pos;\n};\n\n}  // namespace lib\n#line 5 \"test/data_structure/Unionfind.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    lib::dsu uf(n);\n\
    \    while (q--) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n \
    \       if (t == 0) {\n            uf.merge(u, v);\n        } else {\n       \
    \     std::cout << (int)uf.same(u, v) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../data_structure/dsu.hpp\"\n#include \"../../template/template.hpp\"\n\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    lib::dsu uf(n);\n\
    \    while (q--) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n \
    \       if (t == 0) {\n            uf.merge(u, v);\n        } else {\n       \
    \     std::cout << (int)uf.same(u, v) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/dsu.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/data_structure/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 18:25:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Unionfind.test.cpp
- /verify/test/data_structure/Unionfind.test.cpp.html
title: test/data_structure/Unionfind.test.cpp
---
