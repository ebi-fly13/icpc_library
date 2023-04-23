---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Set_Xor_Min.test.cpp
    title: test/data_structure/Set_Xor_Min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/BinaryTrie.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\n\ntemplate<typename T> bool chmin(T &a, const T &b){\n    if (a <= b)\
    \ return false;\n    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T\
    \ &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n\
    }\n#line 4 \"data_structure/BinaryTrie.hpp\"\n\nnamespace lib{\n\nusing namespace\
    \ std;\n\ntemplate<typename T, int MAX_LOG> // T = int/ll, 0 <= x < 2 ^ MAX_LOG\n\
    struct BinaryTrie{ // set(multiset) of integer\n    struct node{\n        node\
    \ *p;\n        array<node*,2> ch;\n        int exist; // number of item\n    \
    \    int sz; // number of integers exist in the subtree of this node\n       \
    \ node () : p(nullptr), ch({nullptr,nullptr}), exist(0), sz(0) {}\n    };\n  \
    \  BinaryTrie () : lazy(T(0)){}\n    int size(node *v){\n        if (v == nullptr){return\
    \ 0;}\n        return v->sz;\n    }\n    int count(T x = -1) {\n        node *v\
    \ = root;\n        if(x < 0) return v->sz;\n        x ^= lazy;\n        rrep(i,0,MAX_LOG)\
    \ {\n            int j = x >> i & 1;\n            if(v->ch[j] == nullptr) {\n\
    \                return 0;\n            }\n            v = v->ch[j];\n       \
    \ }\n        return v->sz;\n    }\n    void insert(T x){\n        x ^= lazy;\n\
    \        node *v = root;\n        rrep(i,0,MAX_LOG){\n            int j = x >>\
    \ i & 1;\n            if (v->ch[j] == nullptr){\n                v->ch[j] = new\
    \ node();\n                v->ch[j]->p = v;\n            }\n            v = v->ch[j];\n\
    \        }\n        v->exist++;\n        update(v);\n        rep(i,0,MAX_LOG){\n\
    \            v = v->p;\n            update(v);\n        }\n    }\n    void erase(T\
    \ x){\n        x ^= lazy;\n        node *v = root;\n        rrep(i,0,MAX_LOG){\n\
    \            int j = x >> i & 1;\n            if (v->ch[j] == nullptr){\n    \
    \            return ;\n            }\n            v = v->ch[j];\n        }\n \
    \       if (v->exist == 0) return ;\n        v->exist--;\n        update(v);\n\
    \        rrep(i,0,MAX_LOG){\n            node *p = v->p;\n            if (size(v)\
    \ == 0){\n                if (v == p->ch[0]) p->ch[0] = nullptr;\n           \
    \     else p->ch[1] = nullptr;\n                delete v;\n            }\n   \
    \         v = p;\n            update(v);\n        }\n    }\n    int order(T x){\
    \ // number of element which is less than x\n        node *v = root;\n       \
    \ int res = 0;\n        rrep(i,0,MAX_LOG){\n            int j = lazy >> i & 1;\n\
    \            if ((x >> i & 1) == 0){\n                v = v->ch[j];\n        \
    \    }\n            else {\n                res += size(v->ch[j]);\n         \
    \       v = v->ch[j^1];\n            }\n            if (v == nullptr){\n     \
    \           break;\n            }\n        }\n        return res;\n    }\n   \
    \ T get(int k){ // value of kth(0_indexed) element, order(get(k)) = k\n      \
    \  node *v = root;\n        T ans = T(0);\n        rrep(i,0,MAX_LOG){\n      \
    \      int j = lazy >> i & 1;\n            if (k < size(v->ch[j])){\n        \
    \        v = v->ch[j];\n            }\n            else {\n                k -=\
    \ size(v->ch[j]);\n                v = v->ch[j^1];\n                ans |= T(1)\
    \ << i;\n            }\n        }\n        return ans;\n    }\n    void xor_all(T\
    \ x){lazy ^= x;}\n  private:\n    T lazy;\n    node *root = new node();\n    void\
    \ update(node *v){\n        v->sz = v->exist + size(v->ch[0]) + size(v->ch[1]);\n\
    \    }\n};\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib{\n\n\
    using namespace std;\n\ntemplate<typename T, int MAX_LOG> // T = int/ll, 0 <=\
    \ x < 2 ^ MAX_LOG\nstruct BinaryTrie{ // set(multiset) of integer\n    struct\
    \ node{\n        node *p;\n        array<node*,2> ch;\n        int exist; // number\
    \ of item\n        int sz; // number of integers exist in the subtree of this\
    \ node\n        node () : p(nullptr), ch({nullptr,nullptr}), exist(0), sz(0) {}\n\
    \    };\n    BinaryTrie () : lazy(T(0)){}\n    int size(node *v){\n        if\
    \ (v == nullptr){return 0;}\n        return v->sz;\n    }\n    int count(T x =\
    \ -1) {\n        node *v = root;\n        if(x < 0) return v->sz;\n        x ^=\
    \ lazy;\n        rrep(i,0,MAX_LOG) {\n            int j = x >> i & 1;\n      \
    \      if(v->ch[j] == nullptr) {\n                return 0;\n            }\n \
    \           v = v->ch[j];\n        }\n        return v->sz;\n    }\n    void insert(T\
    \ x){\n        x ^= lazy;\n        node *v = root;\n        rrep(i,0,MAX_LOG){\n\
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
    \    }\n};\n\n} // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2023-04-20 21:35:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Set_Xor_Min.test.cpp
documentation_of: data_structure/BinaryTrie.hpp
layout: document
title: BinaryTrie
---

## 実装の際に省略できるもの

`count` , `erase` , `order` , `get` , `xor_all` の実装は他の機能と独立であり、省略できます。

## 説明

この BinaryTrie は非負整数の**多重集合**を管理します。

### コンストラクタ

`BinrayTrie<T, MAX_LOG> ()`

型 `T` でbit長が `MAX_LOG` であるBinaryTrieを構築します。

`T` は `int` または `ll` が想定されています。

多重集合で扱われる値 `x` は `0 <= x < (1 << MAX_LOG)` が満たされている必要があります。
ただし、 `MAX_LOG` 桁以上の桁が $0$ であるという過程で動作するため、正確には非負整数 `x` は $\bmod$ `1 << MAX_LOG` で扱われます。

### insert

`void insert(T x)`

多重集合に $x$ を $1$ つ挿入します。既にその要素が存在する場合でも、重複をカウントします。

### erase

`void erase(T x)`

多重集合から $x$ を $1$ つ削除します。 $x$ が存在しない場合は何も起こりません。特にエラーを起こしません。

### count

`int count(T x = -1)`

`count()` と呼んだ、あるいは `x = -1` のとき、多重集合の要素数を返します。

そうでないとき、多重集合に含まれる `x` の個数を返します。

### order

`int order(T x)`

多重集合に含まれる $x$ より小さい要素の個数を返します。

### get

`T get(int k)`

0_indexed で $k$ 番目に小さい値を返します。 $k$ が多重集合の要素数以上である場合は最大値を返します。多重集合が空の場合は $0$ を返します。

### xor_all

`void xor_all(T x)`

多重集合の要素をすべて $x$ との XOR をとった値に置き換えます。


## 使い方

```cpp
int main(){
    BinaryTrie<int,31> bt;
    bt.insert(1);
    bt.insert(2); // multiset mst = {1,2}
    cout << bt.get(0) << endl; // 1
    bt.xor_all(2); // mst = {0,3}
    cout << bt.get(0) << endl; // 0
    bt.erase(2); // NO change
    cout << bt.count() << endl; // 2
    cout << bt.get(1) << endl; // 3
    bt.erase(0); // mst = {3}
}

```