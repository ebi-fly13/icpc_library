---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
  bundledCode: "#line 1 \"test/geometry/Counter_Clockwise.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \n\n#line 2 \"geometry/base_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n\
    #include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 4 \"geometry/base_ld.hpp\"\
    \n\nnamespace lib {\n\nusing vec = complex<ld>;\nconst ld eps = 1e-7;\n\nvoid\
    \ ldout(int len = 20) {\n    cout << fixed << setprecision(len);\n}\n\nint sgn(ld\
    \ a) {\n    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nld dot(const vec\
    \ &a, const vec &b) {\n    return (conj(a) * b).real();\n}\n\nld cross(const vec\
    \ &a, const vec &b) {\n    return (conj(a) * b).imag();\n}\n\nint isp(const vec\
    \ &a, const vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b - a, c -\
    \ a));\n    if (cross_sgn == 0) {\n        if (sgn(dot(b - a, c - a)) < 0) return\
    \ -2;\n        if (sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n    return cross_sgn;\n\
    }\n\nvec rot90(const vec &a) {\n    return {-a.imag(), a.real()};\n}\n\nvec rot(const\
    \ vec &a, ld rad) {\n    return a * vec(cosl(rad), sinl(rad));\n}\n\nbool comp_for_argument_sort(const\
    \ vec &lhs, const vec &rhs) {\n    // if (abs(arg(lhs)-arg(rhs)) < eps) return\
    \ false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n}  // namespace lib\n\
    #line 6 \"test/geometry/Counter_Clockwise.test.cpp\"\n\nusing namespace lib;\n\
    \nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n    long\
    \ double x1, y1, x2, y2;\n    std::cin >> x1 >> y1 >> x2 >> y2;\n    vec p0(x1,\
    \ y1), p1(x2, y2);\n    int q;\n    std::cin >> q;\n    while (q--) {\n      \
    \  double x, y;\n        std::cin >> x >> y;\n        int flag = isp(p0, p1, vec(x,\
    \ y));\n        std::string ans;\n        if (flag == 1) {\n            ans =\
    \ \"COUNTER_CLOCKWISE\";\n        } else if (flag == -1) {\n            ans =\
    \ \"CLOCKWISE\";\n        } else if (flag == -2) {\n            ans = \"ONLINE_BACK\"\
    ;\n        } else if (flag == 2) {\n            ans = \"ONLINE_FRONT\";\n    \
    \    } else {\n            ans = \"ON_SEGMENT\";\n        }\n        std::cout\
    \ << ans << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \n\n#include \"../../geometry/base_ld.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    long double x1, y1, x2, y2;\n    std::cin >> x1 >> y1 >> x2 >> y2;\n    vec\
    \ p0(x1, y1), p1(x2, y2);\n    int q;\n    std::cin >> q;\n    while (q--) {\n\
    \        double x, y;\n        std::cin >> x >> y;\n        int flag = isp(p0,\
    \ p1, vec(x, y));\n        std::string ans;\n        if (flag == 1) {\n      \
    \      ans = \"COUNTER_CLOCKWISE\";\n        } else if (flag == -1) {\n      \
    \      ans = \"CLOCKWISE\";\n        } else if (flag == -2) {\n            ans\
    \ = \"ONLINE_BACK\";\n        } else if (flag == 2) {\n            ans = \"ONLINE_FRONT\"\
    ;\n        } else {\n            ans = \"ON_SEGMENT\";\n        }\n        std::cout\
    \ << ans << std::endl;\n    }\n}"
  dependsOn:
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/geometry/Counter_Clockwise.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 18:25:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/Counter_Clockwise.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/Counter_Clockwise.test.cpp
- /verify/test/geometry/Counter_Clockwise.test.cpp.html
title: test/geometry/Counter_Clockwise.test.cpp
---
