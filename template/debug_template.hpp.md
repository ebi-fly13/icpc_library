---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/debug_template.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    template/debug_template.hpp\"\n\n#define debug(...)                          \
    \                           \\\n    std::cerr << \"LINE: \" << __LINE__ << \"\
    \ [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n\nvoid debug_out()\
    \ {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename... Tail>\
    \ void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t)\
    \ > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\n#define debug(...)\
    \                                                     \\\n    std::cerr << \"\
    LINE: \" << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n\
    \nvoid debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head,\
    \ typename... Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \"\
    \ << h;\n    if (sizeof...(t) > 0) std::cerr << \" :\";\n    debug_out(t...);\n\
    }"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: template/debug_template.hpp
  requiredBy: []
  timestamp: '2023-06-14 12:39:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/debug_template.hpp
layout: document
title: "\u30C7\u30D0\u30C3\u30B0\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---

## 説明

デバッグのテンプレート。標準エラー出力にdebugの引数を出力する。下のように動作する。

```
debug(a, b, c)
> LINE: xx [a, b, c]: aの中身 : bの中身 : cの中身
```
