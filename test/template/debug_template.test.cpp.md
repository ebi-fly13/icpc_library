---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/debug_template.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/template/debug_template.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/debug_template.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"template/debug_template.hpp\"\n\n#define debug(...)        \
    \                                             \\\n    std::cerr << \"LINE: \"\
    \ << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n\
    \nvoid debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head,\
    \ typename... Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \"\
    \ << h;\n    if (sizeof...(t) > 0) std::cerr << \",\";\n    debug_out(t...);\n\
    }\n\ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
    }\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &vec) {\n    for (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i]\
    \ << (i + 1 == vec.size() ? \"\" : \" \");\n    return os;\n}\n#line 4 \"test/template/debug_template.test.cpp\"\
    \n\n#line 6 \"test/template/debug_template.test.cpp\"\n\nint main() {\n    int\
    \ a, b;\n    std::cin >> a >> b;\n    debug(a, b, a + b);\n    std::cout << a\
    \ + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/debug_template.hpp\"\n\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    debug(a, b, a +\
    \ b);\n    std::cout << a + b << '\\n';\n}"
  dependsOn:
  - template/debug_template.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/template/debug_template.test.cpp
  requiredBy: []
  timestamp: '2023-06-17 00:35:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/template/debug_template.test.cpp
layout: document
redirect_from:
- /verify/test/template/debug_template.test.cpp
- /verify/test/template/debug_template.test.cpp.html
title: test/template/debug_template.test.cpp
---
