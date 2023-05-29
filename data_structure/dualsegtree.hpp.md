---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dualsegtree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace lib {\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\n\
    struct dualsegtree {\n  public:\n    dualsegtree(int n) : n(n) {\n        sz =\
    \ 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2 * sz, e());\n  \
    \  }\n\n    dualsegtree(const std::vector<S> &vec) : n(vec.size()) {\n       \
    \ sz = 1;\n        while (sz < n) sz <<= 1;\n        data.assign(2 * sz, e());\n\
    \        std::copy(vec.begin(), vec.end(), data.begin() + sz);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < n);\n        p += sz;\n   \
    \     S val = e();\n        while (p > 0) {\n            val = op(val, data[p]);\n\
    \            p >>= 1;\n        }\n        return val;\n    }\n\n    void apply(int\
    \ l, int r, S x) {\n        assert(0 <= l && l <= r && r <= n);\n        l +=\
    \ sz;\n        r += sz;\n        while (l < r) {\n            if (l & 1) {\n \
    \               data[l] = op(data[l], x);\n                l++;\n            }\n\
    \            if (r & 1) {\n                r--;\n                data[r] = op(data[r],\
    \ x);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return;\n    }\n\n  private:\n    std::vector<S> data;\n    int n;\n\
    \    int sz;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace lib {\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct dualsegtree {\n  public:\n\
    \    dualsegtree(int n) : n(n) {\n        sz = 1;\n        while (sz < n) sz <<=\
    \ 1;\n        data.assign(2 * sz, e());\n    }\n\n    dualsegtree(const std::vector<S>\
    \ &vec) : n(vec.size()) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n\
    \        data.assign(2 * sz, e());\n        std::copy(vec.begin(), vec.end(),\
    \ data.begin() + sz);\n    }\n\n    S get(int p) const {\n        assert(0 <=\
    \ p && p < n);\n        p += sz;\n        S val = e();\n        while (p > 0)\
    \ {\n            val = op(val, data[p]);\n            p >>= 1;\n        }\n  \
    \      return val;\n    }\n\n    void apply(int l, int r, S x) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        l += sz;\n        r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                data[l] = op(data[l], x);\n\
    \                l++;\n            }\n            if (r & 1) {\n             \
    \   r--;\n                data[r] = op(data[r], x);\n            }\n         \
    \   l >>= 1;\n            r >>= 1;\n        }\n        return;\n    }\n\n  private:\n\
    \    std::vector<S> data;\n    int n;\n    int sz;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dualsegtree.hpp
  requiredBy: []
  timestamp: '2023-05-29 17:30:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/dualsegtree.hpp
layout: document
redirect_from:
- /library/data_structure/dualsegtree.hpp
- /library/data_structure/dualsegtree.hpp.html
title: data_structure/dualsegtree.hpp
---
