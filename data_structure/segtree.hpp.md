---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Range_Sum.test.cpp
    title: test/data_structure/Point_Add_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\n\ntemplate<typename T> bool chmin(T &a, const T &b){\n    if (a <= b)\
    \ return false;\n    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T\
    \ &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n#line 4 \"data_structure/segtree.hpp\"\n\nnamespace lib {\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n   private:\n    int n;\n   \
    \ int sz;\n    std::vector<S> data;\n\n    void update(int i) { data[i] = op(data[2\
    \ * i], data[2 * i + 1]); }\n\n   public:\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\n\
    \        while (sz < n) sz *= 2;\n        data = std::vector<S>(2 * sz, e());\n\
    \        rep(i, 0, n) { data[sz + i] = v[i]; }\n        rrep(i, 1, sz) update(i);\n\
    \    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < n);\n     \
    \   p += sz;\n        data[p] = x;\n        while (p > 1) {\n            p >>=\
    \ 1;\n            update(p);\n        }\n    }\n\n    S get(int p) {\n       \
    \ assert(0 <= p && p < n);\n        return data[p + sz];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        S sml = e(),\
    \ smr = e();\n        l += sz;\n        r += sz;\n        while (l < r) {\n  \
    \          if (l & 1) sml = op(sml, data[l++]);\n            if (r & 1) smr =\
    \ op(data[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() { return data[1]; }\n\
    \n    template <class F>\n    int max_right(int l, F f) {\n        assert(0 <=\
    \ l && l < n);\n        assert(f(e()));\n        if (l == n) return n;\n     \
    \   l += sz;\n        S sm = e();\n        do {\n            while (l % 2 == 0)\
    \ l >>= 1;\n            if (!f(op(sm, data[l]))) {\n                while (l <\
    \ sz) {\n                    l = 2 * l;\n                    if (f(op(sm, data[l])))\
    \ {\n                        sm = op(sm, data[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - sz;\n  \
    \          }\n            sm = op(sm, data[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return n;\n    }\n\n    template <class F>\n    int\
    \ min_left(int r, F f) {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        S sm = e();\n      \
    \  do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n   \
    \         if (!f(op(data[r], sm))) {\n                while (r < sz) {\n     \
    \               r = 2 * r + 1;\n                    if (f(op(data[r], sm))) {\n\
    \                        sm = op(data[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - sz;\n\
    \            }\n            sm = op(data[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n   private:\n\
    \    int n;\n    int sz;\n    std::vector<S> data;\n\n    void update(int i) {\
    \ data[i] = op(data[2 * i], data[2 * i + 1]); }\n\n   public:\n    segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S> &v)\
    \ : n((int)v.size()), sz(1) {\n        while (sz < n) sz *= 2;\n        data =\
    \ std::vector<S>(2 * sz, e());\n        rep(i, 0, n) { data[sz + i] = v[i]; }\n\
    \        rrep(i, 1, sz) update(i);\n    }\n\n    void set(int p, S x) {\n    \
    \    assert(0 <= p && p < n);\n        p += sz;\n        data[p] = x;\n      \
    \  while (p > 1) {\n            p >>= 1;\n            update(p);\n        }\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ data[p + sz];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        S sml = e(), smr = e();\n        l += sz;\n    \
    \    r += sz;\n        while (l < r) {\n            if (l & 1) sml = op(sml, data[l++]);\n\
    \            if (r & 1) smr = op(data[--r], smr);\n            l >>= 1;\n    \
    \        r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return data[1]; }\n\n    template <class F>\n    int max_right(int l, F f)\
    \ {\n        assert(0 <= l && l < n);\n        assert(f(e()));\n        if (l\
    \ == n) return n;\n        l += sz;\n        S sm = e();\n        do {\n     \
    \       while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, data[l]))) {\n\
    \                while (l < sz) {\n                    l = 2 * l;\n          \
    \          if (f(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - sz;\n            }\n            sm = op(sm, data[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\
    \n    template <class F>\n    int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n    \
    \    r += sz;\n        S sm = e();\n        do {\n            r--;\n         \
    \   while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(data[r], sm))) {\n\
    \                while (r < sz) {\n                    r = 2 * r + 1;\n      \
    \              if (f(op(data[r], sm))) {\n                        sm = op(data[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\n}  //\
    \ namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-04-23 15:23:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Point_Add_Range_Sum.test.cpp
documentation_of: data_structure/segtree.hpp
layout: document
redirect_from:
- /library/data_structure/segtree.hpp
- /library/data_structure/segtree.hpp.html
title: data_structure/segtree.hpp
---
