---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':question:'
    path: geometry/circle.hpp
    title: circle
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
  bundledCode: "#line 1 \"test/geometry/Intersection_Circle.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\"\r\n\r\n\
    #line 2 \"geometry/circle.hpp\"\n\r\n#line 2 \"geometry/base_ld.hpp\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n)\
    \ for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1;\
    \ i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\nusing ll = long long;\n\
    using ld = long double;\nusing ull = unsigned long long;\n\ntemplate<typename\
    \ T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n\
    \    return true;\n}\ntemplate<typename T> bool chmax(T &a, const T &b){\n   \
    \ if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib{\n\
    \nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n#line\
    \ 4 \"geometry/base_ld.hpp\"\n\nnamespace lib {\n\nusing vec = complex<ld>;\n\
    const ld eps = 1e-7;\n\nint sgn(ld a) {\n    return (a < -eps) ? -1 : (a > eps)\
    \ ? 1 : 0;\n}\n\nld dot(const vec &a, const vec &b){\n    return (conj(a) * b).real();\n\
    }\n\nld cross(const vec &a, const vec &b){\n    return (conj(a) * b).imag();\n\
    }\n\nint isp(const vec &a, const vec &b, const vec &c) {\n    int cross_sgn =\
    \ sgn(cross(b - a, c - a));\n    if(cross_sgn == 0) {\n        if(sgn(dot(b -\
    \ a, c - a)) < 0) return -2;\n        if(sgn(dot(a - b, c - b)) < 0) return 2;\n\
    \    }\n    return cross_sgn;\n}\n\nbool comp_for_argument_sort(const vec &lhs,\
    \ const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs)) < eps) return false; // need\
    \ ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace lib\n#line 4 \"geometry/circle.hpp\"\
    \n\r\nnamespace lib {\r\n\r\nstruct circle {\r\n    vec c;\r\n    ld r;\r\n};\r\
    \n\r\nint intersection(const circle &c1, const circle &c2) {\r\n    ld d = abs(c1.c\
    \ - c2.c);\r\n    ld r1 = c1.r;\r\n    ld r2 = c2.r;\r\n    if(r1 < r2) std::swap(r1,\
    \ r2);\r\n    if(sgn(d - (r1 + r2)) > 0) {\r\n        return 4;\r\n    }\r\n \
    \   else if(sgn(d - (r1 + r2) == 0)) {\r\n        return 3;\r\n    }\r\n    else\
    \ if(sgn(d - r1 + r2) > 0) {\r\n        return 2;\r\n    }\r\n    else if(sgn(d\
    \ - r1 + r2) == 0) {\r\n        return 1;\r\n    }\r\n    else return 0;\r\n}\r\
    \n\r\ncircle incircle_of_triangle(const vec &a, const vec &b, const vec &c) {\r\
    \n    ld A = abs(b - c), B = abs(c - a), C = abs(a - b);\r\n    vec in = A * a\
    \ + B * b + C * c;\r\n    in /= A + B + C;\r\n    ld r = abs(cross(in - a, b -\
    \ a) / abs(b - a));\r\n    return {in, r};\r\n}\r\n\r\n}\n#line 4 \"test/geometry/Intersection_Circle.test.cpp\"\
    \n\r\nusing namespace lib;\r\n\r\nint main() {\r\n    ld c1x, c1y, c1r;\r\n  \
    \  ld c2x, c2y, c2r;\r\n    std::cin >> c1x >> c1y >> c1r;\r\n    std::cin >>\
    \ c2x >> c2y >> c2r;\r\n    circle c1 = {{c1x, c1y}, c1r};\r\n    circle c2 =\
    \ {{c2x, c2y}, c2r};\r\n    std::cout << intersection(c1, c2) << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\"\
    \r\n\r\n#include \"../../geometry/circle.hpp\"\r\n\r\nusing namespace lib;\r\n\
    \r\nint main() {\r\n    ld c1x, c1y, c1r;\r\n    ld c2x, c2y, c2r;\r\n    std::cin\
    \ >> c1x >> c1y >> c1r;\r\n    std::cin >> c2x >> c2y >> c2r;\r\n    circle c1\
    \ = {{c1x, c1y}, c1r};\r\n    circle c2 = {{c2x, c2y}, c2r};\r\n    std::cout\
    \ << intersection(c1, c2) << '\\n';\r\n}"
  dependsOn:
  - geometry/circle.hpp
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/geometry/Intersection_Circle.test.cpp
  requiredBy: []
  timestamp: '2023-04-24 18:34:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/geometry/Intersection_Circle.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/Intersection_Circle.test.cpp
- /verify/test/geometry/Intersection_Circle.test.cpp.html
title: test/geometry/Intersection_Circle.test.cpp
---
