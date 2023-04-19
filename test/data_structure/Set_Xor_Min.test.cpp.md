---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/BinaryTrie.hpp
    title: data_structure/BinaryTrie.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/data_structure/Set_Xor_Min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\n\ntemplate<typename T> bool chmin(T &a, const T &b){\n    if (a <= b)\
    \ return false;\n    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T\
    \ &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n#line 2 \"data_structure/BinaryTrie.hpp\"\n\n#line 4 \"data_structure/BinaryTrie.hpp\"\
    \n\nnamespace lib{\n\nusing namespace std;\n\ntemplate<typename T, int MAX_LOG>\
    \ // T = int/ll, 0 <= x < 2 ^ MAX_LOG\nstruct BinaryTrie{ // set(NOT multiset)\
    \ of integer\n    struct node{\n        node *p;\n        array<node*,2> ch;\n\
    \        int exist; // number of item\n        int sz; // number of integers exist\
    \ in the subtree of this node\n        node () : p(nullptr), ch({nullptr,nullptr}),\
    \ exist(0), sz(0) {}\n    };\n    BinaryTrie () : lazy(T(0)){}\n    int size(node\
    \ *v){\n        if (v == nullptr){return 0;}\n        return v->sz;\n    }\n \
    \   int count(T x = -1) {\n        node *v = root;\n        if(x < 0) return v->sz;\n\
    \        x ^= lazy;\n        rrep(i,0,MAX_LOG) {\n            int j = x >> i &\
    \ 1;\n            if(v->ch[j] == nullptr) {\n                return 0;\n     \
    \       }\n            v = v->ch[j];\n        }\n        return v->sz;\n    }\n\
    \    void insert(T x){\n        x ^= lazy;\n        node *v = root;\n        rrep(i,0,MAX_LOG){\n\
    \            int j = x >> i & 1;\n            if (v->ch[j] == nullptr){\n    \
    \            v->ch[j] = new node();\n                v->ch[j]->p = v;\n      \
    \      }\n            v = v->ch[j];\n        }\n        v->exist++;\n        update(v);\n\
    \        rep(i,0,MAX_LOG){\n            v = v->p;\n            update(v);\n  \
    \      }\n    }\n    void erase(T x){\n        x ^= lazy;\n        node *v = root;\n\
    \        rrep(i,0,MAX_LOG){\n            int j = x >> i & 1;\n            if (v->ch[j]\
    \ == nullptr){\n                return ;\n            }\n            v = v->ch[j];\n\
    \        }\n        if (v->exist == 0) return ;\n        v->exist--;\n       \
    \ update(v);\n        rrep(i,0,MAX_LOG){\n            node *p = v->p;\n      \
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
    \    }\n};\n\n} // namespace lib\n#line 5 \"test/data_structure/Set_Xor_Min.test.cpp\"\
    \n\nint main() {\n    lib::BinaryTrie<int, 30> trie;\n    int q;\n    std::cin\
    \ >> q;\n    while(q--) {\n        int t,x;\n        std::cin >> t >> x;\n   \
    \     if(t == 0) {\n            if(trie.count(x) > 0) continue;\n            trie.insert(x);\n\
    \        }\n        else if(t == 1) {\n            if(trie.count(x) == 0) continue;\n\
    \            trie.erase(x);\n        }\n        else {\n            trie.xor_all(x);\n\
    \            std::cout << trie.get(0) << '\\n';\n            trie.xor_all(x);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../data_structure/BinaryTrie.hpp\"\
    \n\nint main() {\n    lib::BinaryTrie<int, 30> trie;\n    int q;\n    std::cin\
    \ >> q;\n    while(q--) {\n        int t,x;\n        std::cin >> t >> x;\n   \
    \     if(t == 0) {\n            if(trie.count(x) > 0) continue;\n            trie.insert(x);\n\
    \        }\n        else if(t == 1) {\n            if(trie.count(x) == 0) continue;\n\
    \            trie.erase(x);\n        }\n        else {\n            trie.xor_all(x);\n\
    \            std::cout << trie.get(0) << '\\n';\n            trie.xor_all(x);\n\
    \        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data_structure/BinaryTrie.hpp
  isVerificationFile: true
  path: test/data_structure/Set_Xor_Min.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 01:31:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Set_Xor_Min.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Set_Xor_Min.test.cpp
- /verify/test/data_structure/Set_Xor_Min.test.cpp.html
title: test/data_structure/Set_Xor_Min.test.cpp
---
