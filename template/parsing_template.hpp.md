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
  bundledCode: "#line 2 \"template/parsing_template.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    template/parsing_template.hpp\"\n\nnamespace lib {\n\ntypedef std::string::const_iterator\
    \ State;\n\n// *begin == expected\u306E\u5224\u5B9A\nbool expect(State &begin,\
    \ char expected) {\n    if (*begin == expected) {\n        return true;\n    }\
    \ else {\n        return false;\n    }\n}\n\n// begin\u304Cexpected\u3092\u6307\
    \u3057\u3066\u3044\u305F\u3089begin\u3092\u4E00\u3064\u9032\u3081\u308B\u3002\n\
    void consume(State &begin, char expected) {\n    if (*begin == expected) {\n \
    \       begin++;\n    } else {\n        assert(0);\n    }\n}\n\nbool isdigit(char\
    \ c) {\n    return '0' <= c && c <= '9';\n}\n\nbool isAlpha(char c) {\n    return\
    \ 'A' <= c && c <= 'Z';\n}\n\nbool isalpha(char c) {\n    return 'a' <= c && c\
    \ <= 'z';\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntypedef std::string::const_iterator State;\n\n// *begin == expected\u306E\u5224\
    \u5B9A\nbool expect(State &begin, char expected) {\n    if (*begin == expected)\
    \ {\n        return true;\n    } else {\n        return false;\n    }\n}\n\n//\
    \ begin\u304Cexpected\u3092\u6307\u3057\u3066\u3044\u305F\u3089begin\u3092\u4E00\
    \u3064\u9032\u3081\u308B\u3002\nvoid consume(State &begin, char expected) {\n\
    \    if (*begin == expected) {\n        begin++;\n    } else {\n        assert(0);\n\
    \    }\n}\n\nbool isdigit(char c) {\n    return '0' <= c && c <= '9';\n}\n\nbool\
    \ isAlpha(char c) {\n    return 'A' <= c && c <= 'Z';\n}\n\nbool isalpha(char\
    \ c) {\n    return 'a' <= c && c <= 'z';\n}\n\n}  // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: template/parsing_template.hpp
  requiredBy: []
  timestamp: '2023-06-02 00:54:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/parsing_template.hpp
layout: document
title: "\u69CB\u6587\u89E3\u6790\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---

## 説明

構文解析をする際のテンプレート

### bool expect(State &begin, char expected)

現在見ている文字がexpectedと一致しているかを返す。

### consume(State &begin, char expected)

現在見ている文字がexpectedであるとして一文字進める。一致していない場合、`assert`で落ちる。

### isdigit(char c)

`c` が数値であるかを返す。

### isAlpha(char c)

`c` が大文字アルファベットかを返す。

### isalpha(char c)

`c` が小文字アルファベットかを返す。