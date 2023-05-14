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
  bundledCode: "#line 2 \"string/parsing_template.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"string/parsing_template.hpp\"\
    \n\nnamespace lib {\n\ntypedef std::string::const_iterator State;\n\n// *begin\
    \ == expected\u306E\u5224\u5B9A\nbool expect(State &begin, char expected) {\n\
    \    if (*begin == expected) {\n        return true;\n    } else {\n        return\
    \ false;\n    }\n}\n\n// begin\u304Cexpected\u3092\u6307\u3057\u3066\u3044\u305F\
    \u3089begin\u3092\u4E00\u3064\u9032\u3081\u308B\u3002\nvoid consume(State &begin,\
    \ char expected) {\n    if (*begin == expected) {\n        begin++;\n    } else\
    \ {\n        assert(0);\n    }\n}\n\nbool isdigit(char c) {\n    return '0' <=\
    \ c && c <= '9';\n}\n\nbool isAlpha(char c) {\n    return 'A' <= c && c <= 'Z';\n\
    }\n\nbool isalpha(char c) {\n    return 'a' <= c && c <= 'z';\n}\n\n}  // namespace\
    \ lib\n"
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
  path: string/parsing_template.hpp
  requiredBy: []
  timestamp: '2023-05-14 18:25:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/parsing_template.hpp
layout: document
redirect_from:
- /library/string/parsing_template.hpp
- /library/string/parsing_template.hpp.html
title: string/parsing_template.hpp
---
