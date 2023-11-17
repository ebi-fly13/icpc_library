---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor_sum.hpp
    title: Floor Sum
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/Sum_of_Floor_of_Linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 3 \"\
    math/floor_sum.hpp\"\n\nnamespace lib {\nusing namespace std;\n\nll floor_sum(ll\
    \ n, ll m, ll a, ll b){\n\tif (n == 0) return 0;\n\tll ret = 0;\n\t\n\t/* if [a\
    \ >= 0 and b >= 0] is guaranteed, ignore from here */\n\tif (a < 0){\n\t\tll a2\
    \ = a % m;\n\t\tif (a2 < 0) a2 += m;\n\t\tret -= (ll)n * (n-1) / 2 * ((a2 - a)\
    \ / m);\n\t\ta = a2;\n\t}\n\tif (b < 0){\n\t\tll b2 = b % m;\n\t\tif (b2 < 0)\
    \ b2 += m;\n\t\tret -= (ll)n * ((b2 - b) / m);\n\t\tb = b2;\n\t}\n\t/* till here\
    \ */\n\n\tif (a >= m){\n\t\tret += n * (n-1) / 2 * (a / m);\n\t\ta %= m;\n\t}\n\
    \tif (b >= m){\n\t\tret += n * (b / m);\n\t\tb %= m;\n\t}\n\tll y = (a * n + b)\
    \ / m;\n\tll z = (a * n + b) % m;\n\treturn ret + floor_sum(y, a, m, z);\n}\n\n\
    }  // namespace lib\n#line 5 \"test/math/Sum_of_Floor_of_Linear.test.cpp\"\n\n\
    using namespace lib;\n\nint main(){\n\tint t; cin >> t;\n\twhile(t--){\n\t\tll\
    \ n,m,a,b;\n\t\tcin >> n >> m >> a >> b;\n\t\tcout << floor_sum(n, m, a, b) <<\
    \ '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../math/floor_sum.hpp\"\
    \n\nusing namespace lib;\n\nint main(){\n\tint t; cin >> t;\n\twhile(t--){\n\t\
    \tll n,m,a,b;\n\t\tcin >> n >> m >> a >> b;\n\t\tcout << floor_sum(n, m, a, b)\
    \ << '\\n';\n\t}\n}"
  dependsOn:
  - template/template.hpp
  - math/floor_sum.hpp
  isVerificationFile: true
  path: test/math/Sum_of_Floor_of_Linear.test.cpp
  requiredBy: []
  timestamp: '2023-11-18 01:32:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Sum_of_Floor_of_Linear.test.cpp
layout: document
redirect_from:
- /verify/test/math/Sum_of_Floor_of_Linear.test.cpp
- /verify/test/math/Sum_of_Floor_of_Linear.test.cpp.html
title: test/math/Sum_of_Floor_of_Linear.test.cpp
---
