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
  bundledCode: "#line 2 \"data_structure/BinaryTrie.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n#line 5 \"template/template.hpp\"\n#define rep(i,s,n)\
    \ for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1;\
    \ i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n#line 4 \"data_structure/BinaryTrie.hpp\"\n\nnamespace lib{\n\
    \nusing namespace std;\n\ntemplate<typename T, int MAX_LOG> // T = int/ll, 0 <=\
    \ x < 2 ^ MAX_LOG\nstruct BinaryTrie{ // set(NOT multiset) of integer\n    struct\
    \ node{\n        node *p;\n        array<node*,2> ch;\n        int exist; // number\
    \ of item\n        int sz; // number of integers exist in the subtree of this\
    \ node\n        node () : p(nullptr), ch({nullptr,nullptr}), exist(0), sz(0) {}\n\
    \    };\n    BinaryTrie () : lazy(T(0)){}\n    int size(node *v){\n        if\
    \ (v == nullptr){return 0;}\n        return v->sz;\n    }\n    void insert(T x){\n\
    \        x ^= lazy;\n        node *v = root;\n        rrep(i,0,MAX_LOG){\n   \
    \         int j = x >> i & 1;\n            if (v->ch[j] == nullptr){\n       \
    \         v->ch[j] = new node();\n                v->ch[j]->p = v;\n         \
    \   }\n            v = v->ch[j];\n        }\n        v->exist++;\n        update(v);\n\
    \        rep(i,0,MAX_LOG){\n            v = v->p;\n            update(v);\n  \
    \      }\n    }\n    void erase(T x){\n        x ^= lazy;\n        node *v = root;\n\
    \        rrep(i,0,MAX_LOG){\n            int j = x >> i & 1;\n            if (v->ch[j]\
    \ == nullptr){\n                return ;\n            }\n            v = v->ch[j];\n\
    \        }\n        if (v->exist == 0) return ;\n        v->exist--;\n       \
    \ update(v);\n        repp(i,0,MAX_LOG){\n            node *p = v->p;\n      \
    \      if (size(v) == 0){\n                if (v == p->ch[0]) p->ch[0] = nullptr;\n\
    \                else p->ch[1] = nullptr;\n                delete v;\n       \
    \     }\n            v = p;\n            update(v);\n        }\n    }\n    int\
    \ order(T x){ // number of element which is less than x\n        node *v = root;\n\
    \        int res = 0;\n        rrep(i,0,MAX_LOG){\n            int j = lazy >>\
    \ i & 1;\n            if ((x >> i & 1) == 0){\n                v = v->ch[j];\n\
    \            }\n            else {\n                res += size(v->ch[j]);\n \
    \               v = v->ch[j^1];\n            }\n            if (v == nullptr){\n\
    \                break;\n            }\n        }\n        return res;\n    }\n\
    \    T get(int k){ // value of kth(0_indexed) element, order(get(k)) = k\n   \
    \     node *v = root;\n        T ans = T(0);\n        rrep(i,0,MAX_LOG){\n   \
    \         int j = lazy >> i & 1;\n            if (k < size(v->ch[j])){\n     \
    \           v = v->ch[j];\n            }\n            else {\n               \
    \ k -= size(v->ch[j]);\n                v = v->ch[j^1];\n                ans |=\
    \ T(1) << i;\n            }\n        }\n        return ans;\n    }\n    void xor_all(T\
    \ x){lazy ^= x;}\n  private:\n    T lazy;\n    node *root = new node();\n    void\
    \ update(node *v){\n        v->sz = v->exist + size(v->ch[0]) + size(v->ch[1]);\n\
    \    }\n};\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib{\n\n\
    using namespace std;\n\ntemplate<typename T, int MAX_LOG> // T = int/ll, 0 <=\
    \ x < 2 ^ MAX_LOG\nstruct BinaryTrie{ // set(NOT multiset) of integer\n    struct\
    \ node{\n        node *p;\n        array<node*,2> ch;\n        int exist; // number\
    \ of item\n        int sz; // number of integers exist in the subtree of this\
    \ node\n        node () : p(nullptr), ch({nullptr,nullptr}), exist(0), sz(0) {}\n\
    \    };\n    BinaryTrie () : lazy(T(0)){}\n    int size(node *v){\n        if\
    \ (v == nullptr){return 0;}\n        return v->sz;\n    }\n    void insert(T x){\n\
    \        x ^= lazy;\n        node *v = root;\n        rrep(i,0,MAX_LOG){\n   \
    \         int j = x >> i & 1;\n            if (v->ch[j] == nullptr){\n       \
    \         v->ch[j] = new node();\n                v->ch[j]->p = v;\n         \
    \   }\n            v = v->ch[j];\n        }\n        v->exist++;\n        update(v);\n\
    \        rep(i,0,MAX_LOG){\n            v = v->p;\n            update(v);\n  \
    \      }\n    }\n    void erase(T x){\n        x ^= lazy;\n        node *v = root;\n\
    \        rrep(i,0,MAX_LOG){\n            int j = x >> i & 1;\n            if (v->ch[j]\
    \ == nullptr){\n                return ;\n            }\n            v = v->ch[j];\n\
    \        }\n        if (v->exist == 0) return ;\n        v->exist--;\n       \
    \ update(v);\n        repp(i,0,MAX_LOG){\n            node *p = v->p;\n      \
    \      if (size(v) == 0){\n                if (v == p->ch[0]) p->ch[0] = nullptr;\n\
    \                else p->ch[1] = nullptr;\n                delete v;\n       \
    \     }\n            v = p;\n            update(v);\n        }\n    }\n    int\
    \ order(T x){ // number of element which is less than x\n        node *v = root;\n\
    \        int res = 0;\n        rrep(i,0,MAX_LOG){\n            int j = lazy >>\
    \ i & 1;\n            if ((x >> i & 1) == 0){\n                v = v->ch[j];\n\
    \            }\n            else {\n                res += size(v->ch[j]);\n \
    \               v = v->ch[j^1];\n            }\n            if (v == nullptr){\n\
    \                break;\n            }\n        }\n        return res;\n    }\n\
    \    T get(int k){ // value of kth(0_indexed) element, order(get(k)) = k\n   \
    \     node *v = root;\n        T ans = T(0);\n        rrep(i,0,MAX_LOG){\n   \
    \         int j = lazy >> i & 1;\n            if (k < size(v->ch[j])){\n     \
    \           v = v->ch[j];\n            }\n            else {\n               \
    \ k -= size(v->ch[j]);\n                v = v->ch[j^1];\n                ans |=\
    \ T(1) << i;\n            }\n        }\n        return ans;\n    }\n    void xor_all(T\
    \ x){lazy ^= x;}\n  private:\n    T lazy;\n    node *root = new node();\n    void\
    \ update(node *v){\n        v->sz = v->exist + size(v->ch[0]) + size(v->ch[1]);\n\
    \    }\n};\n\n} // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2023-04-20 00:34:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/data_structure/BinaryTrie.hpp
- /library/data_structure/BinaryTrie.hpp.html
title: data_structure/BinaryTrie.hpp
---
