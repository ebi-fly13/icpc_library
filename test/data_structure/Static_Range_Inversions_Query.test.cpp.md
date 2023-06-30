---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: fenwick tree
  - icon: ':heavy_check_mark:'
    path: misc/mo_algorithm.hpp
    title: misc/mo_algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/data_structure/Static_Range_Inversions_Query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ prefix_sum(r) - prefix_sum(l);\n    }\n};\n\n}  // namespace lib\n#line 2 \"\
    misc/mo_algorithm.hpp\"\n\n#line 4 \"misc/mo_algorithm.hpp\"\n\nnamespace lib\
    \ {\n\nstruct Mo {\n    int width;\n    vector<int> left, right, order;\n\n  \
    \  Mo(int N = 1, int Q = 1) : order(Q) {\n        width = max<int>(1, 1.0 * N\
    \ / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n        iota(begin(order), end(order),\
    \ 0);\n    }\n\n    void insert(int l, int r) { /* [l, r) */\n        left.emplace_back(l);\n\
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
    \            rem(idx);\n        }\n    }\n};\n\n}  // namespace lib\n#line 6 \"\
    test/data_structure/Static_Range_Inversions_Query.test.cpp\"\n\nusing namespace\
    \ lib;\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    Mo mo(n, q);\n\
    \    std::vector<int> a(n);\n    rep(i, 0, n) std::cin >> a[i];\n    auto cp =\
    \ a;\n    std::sort(all(cp));\n    cp.erase(unique(all(cp)), cp.end());\n    rep(i,\
    \ 0, n) a[i] = std::lower_bound(all(cp), a[i]) - cp.begin();\n    rep(i, 0, q)\
    \ {\n        int l, r;\n        std::cin >> l >> r;\n        mo.insert(l, r);\n\
    \    }\n    ll ret = 0;\n    fenwick_tree<ll> fw(cp.size());\n    std::vector<ll>\
    \ ans(q);\n    const auto add_left = [&](int l) -> void {\n        ret += fw.prefix_sum(a[l]);\n\
    \        fw.add(a[l], 1);\n    };\n    const auto add_right = [&](int r) -> void\
    \ {\n        ret += fw.sum(a[r] + 1, cp.size());\n        fw.add(a[r], 1);\n \
    \   };\n    const auto delete_left = [&](int l) -> void {\n        ret -= fw.prefix_sum(a[l]);\n\
    \        fw.add(a[l], -1);\n    };\n    const auto delete_right = [&](int r) ->\
    \ void {\n        ret -= fw.sum(a[r] + 1, cp.size());\n        fw.add(a[r], -1);\n\
    \    };\n    const auto out = [&](int i) -> void { ans[i] = ret; };\n    mo.run(add_left,\
    \ add_right, delete_left, delete_right, out);\n    rep(i, 0, q) {\n        std::cout\
    \ << ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../../data_structure/fenwick_tree.hpp\"\n#include \"../../misc/mo_algorithm.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nusing namespace lib;\n\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    Mo mo(n, q);\n    std::vector<int>\
    \ a(n);\n    rep(i, 0, n) std::cin >> a[i];\n    auto cp = a;\n    std::sort(all(cp));\n\
    \    cp.erase(unique(all(cp)), cp.end());\n    rep(i, 0, n) a[i] = std::lower_bound(all(cp),\
    \ a[i]) - cp.begin();\n    rep(i, 0, q) {\n        int l, r;\n        std::cin\
    \ >> l >> r;\n        mo.insert(l, r);\n    }\n    ll ret = 0;\n    fenwick_tree<ll>\
    \ fw(cp.size());\n    std::vector<ll> ans(q);\n    const auto add_left = [&](int\
    \ l) -> void {\n        ret += fw.prefix_sum(a[l]);\n        fw.add(a[l], 1);\n\
    \    };\n    const auto add_right = [&](int r) -> void {\n        ret += fw.sum(a[r]\
    \ + 1, cp.size());\n        fw.add(a[r], 1);\n    };\n    const auto delete_left\
    \ = [&](int l) -> void {\n        ret -= fw.prefix_sum(a[l]);\n        fw.add(a[l],\
    \ -1);\n    };\n    const auto delete_right = [&](int r) -> void {\n        ret\
    \ -= fw.sum(a[r] + 1, cp.size());\n        fw.add(a[r], -1);\n    };\n    const\
    \ auto out = [&](int i) -> void { ans[i] = ret; };\n    mo.run(add_left, add_right,\
    \ delete_left, delete_right, out);\n    rep(i, 0, q) {\n        std::cout << ans[i]\
    \ << '\\n';\n    }\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  - template/template.hpp
  - misc/mo_algorithm.hpp
  isVerificationFile: true
  path: test/data_structure/Static_Range_Inversions_Query.test.cpp
  requiredBy: []
  timestamp: '2023-06-30 13:53:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Static_Range_Inversions_Query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Static_Range_Inversions_Query.test.cpp
- /verify/test/data_structure/Static_Range_Inversions_Query.test.cpp.html
title: test/data_structure/Static_Range_Inversions_Query.test.cpp
---
