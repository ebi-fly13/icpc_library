---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/aoj_1645.test.cpp
    title: test/data_structure/aoj_1645.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/undo_dsu.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    data_structure/undo_dsu.hpp\"\n\nnamespace lib {\n\nstruct undo_dsu {\n  public:\n\
    \    undo_dsu(int n) : n(n), data(n, -1) {}\n\n    int leader(int a) const {\n\
    \        if (data[a] < 0) return a;\n        return leader(data[a]);\n    }\n\n\
    \    int size(int a) const {\n        int x = leader(a);\n        return -data[x];\n\
    \    }\n\n    int merge(int a, int b) {\n        int x = leader(a);\n        int\
    \ y = leader(b);\n        stack.push({x, data[x]});\n        stack.push({y, data[y]});\n\
    \        if (x == y) return x;\n        if (size(x) < size(y)) std::swap(x, y);\n\
    \        data[x] += data[y];\n        data[y] = x;\n        return x;\n    }\n\
    \n    void undo() {\n        assert(stack.size() >= 2);\n        auto [x, xval]\
    \ = stack.top();\n        data[x] = xval;\n        stack.pop();\n        auto\
    \ [y, yval] = stack.top();\n        data[y] = yval;\n        stack.pop();\n  \
    \  }\n\n  private:\n    int n;\n    std::vector<int> data;\n    std::stack<std::pair<int,\
    \ int>> stack;\n};\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \nstruct undo_dsu {\n  public:\n    undo_dsu(int n) : n(n), data(n, -1) {}\n\n\
    \    int leader(int a) const {\n        if (data[a] < 0) return a;\n        return\
    \ leader(data[a]);\n    }\n\n    int size(int a) const {\n        int x = leader(a);\n\
    \        return -data[x];\n    }\n\n    int merge(int a, int b) {\n        int\
    \ x = leader(a);\n        int y = leader(b);\n        stack.push({x, data[x]});\n\
    \        stack.push({y, data[y]});\n        if (x == y) return x;\n        if\
    \ (size(x) < size(y)) std::swap(x, y);\n        data[x] += data[y];\n        data[y]\
    \ = x;\n        return x;\n    }\n\n    void undo() {\n        assert(stack.size()\
    \ >= 2);\n        auto [x, xval] = stack.top();\n        data[x] = xval;\n   \
    \     stack.pop();\n        auto [y, yval] = stack.top();\n        data[y] = yval;\n\
    \        stack.pop();\n    }\n\n  private:\n    int n;\n    std::vector<int> data;\n\
    \    std::stack<std::pair<int, int>> stack;\n};\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: data_structure/undo_dsu.hpp
  requiredBy: []
  timestamp: '2023-05-31 11:32:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/aoj_1645.test.cpp
documentation_of: data_structure/undo_dsu.hpp
layout: document
title: Undo dsu
---

## 説明

rollbackできるdsu。
経路圧縮をやらず、mergeするときに変更箇所をstackに入れることでundo時に $1$ つ前の状態に戻すことができる。
経路圧縮をやらないと変更箇所は高々 $2$ 箇所になるためstackには $2$ 箇所の情報を入れるだけでよくなりundoが実現できる。

### undo_dsu(int n)

頂点 n のdsuを作る。$O(N)$

### leader(int a)

頂点 $a$ の連結成分の代表元を返す。$O(\log N)$

### size(int a)

頂点 $a$ の連結成分のサイズを返す。$O(\log N)$

### merge(int a, int b)

頂点 $a$ と $b$ をマージし、代表元を返す。$O(\log N)$

### undo()

$1$ つ前の状態に戻す。$O(1)$