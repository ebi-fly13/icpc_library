---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: circle
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
    ERROR: '0.0000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B
  bundledCode: "#line 1 \"test/geometry/Incircle_of_Triangle.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B\"\r\n#define\
    \ ERROR 0.0000001\r\n\r\n#line 2 \"template/template.hpp\"\n\n#include<bits/stdc++.h>\n\
    \n#define rep(i,s,n) for (int i = s; i < (int)(n); i++)\n#define rrep(i,s,n) for\
    \ (int i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(),v.end()\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    \ntemplate<typename T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate<typename T> bool chmax(T &a, const\
    \ T &b){\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\nnamespace\
    \ lib{\n\nusing namespace std;\n\n} // namespace lib;\n\n//using namespace lib;\n\
    #line 2 \"geometry/base_ld.hpp\"\n\n#line 4 \"geometry/base_ld.hpp\"\n\nnamespace\
    \ lib {\n\nusing vec = complex<ld>;\nconst ld eps = 1e-7;\n\nint sgn(ld a) {\n\
    \    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nld dot(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).imag();\n}\n\nint isp(const vec &a, const\
    \ vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b - a, c - a));\n   \
    \ if(cross_sgn == 0) {\n        if(sgn(dot(b - a, c - a)) < 0) return -2;\n  \
    \      if(sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n    return cross_sgn;\n\
    }\n\nvec rot90(const vec &a) {\n    return {-a.imag(), a.real()};\n}\n\nbool comp_for_argument_sort(const\
    \ vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs)) < eps) return false;\
    \ // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace lib\n#line 2\
    \ \"geometry/circle.hpp\"\n\r\n#line 4 \"geometry/circle.hpp\"\n\r\nnamespace\
    \ lib {\r\n\r\nstruct circle {\r\n    vec c;\r\n    ld r;\r\n};\r\n\r\nint intersection(const\
    \ circle &c1, const circle &c2) {\r\n    ld d = abs(c1.c - c2.c);\r\n    ld r1\
    \ = c1.r;\r\n    ld r2 = c2.r;\r\n    if(r1 < r2) std::swap(r1, r2);\r\n    if(sgn(d\
    \ - (r1 + r2)) > 0) {\r\n        return 4;\r\n    }\r\n    else if(sgn(d - (r1\
    \ + r2) == 0)) {\r\n        return 3;\r\n    }\r\n    else if(sgn(d - r1 + r2)\
    \ > 0) {\r\n        return 2;\r\n    }\r\n    else if(sgn(d - r1 + r2) == 0) {\r\
    \n        return 1;\r\n    }\r\n    else return 0;\r\n}\r\n\r\ncircle incircle_of_triangle(const\
    \ vec &a, const vec &b, const vec &c) {\r\n    ld A = abs(b - c), B = abs(c -\
    \ a), C = abs(a - b);\r\n    vec in = A * a + B * b + C * c;\r\n    in /= A +\
    \ B + C;\r\n    ld r = abs(cross(in - a, b - a) / abs(b - a));\r\n    return {in,\
    \ r};\r\n}\r\n\r\n}\n#line 7 \"test/geometry/Incircle_of_Triangle.test.cpp\"\n\
    \r\nusing namespace lib;\r\n\r\nint main() {\r\n    std::cout << std::fixed <<\
    \ std::setprecision(15);\r\n    auto input = [](vec &a) {\r\n        ld x,y;\r\
    \n        std::cin >> x >> y;\r\n        a = {x, y};\r\n    };\r\n    vec a,b,c;\r\
    \n    input(a);\r\n    input(b);\r\n    input(c);\r\n    circle in = incircle_of_triangle(a,\
    \ b, c);\r\n    std::cout << in.c.real() << \" \" << in.c.imag() << \" \" << in.r\
    \ << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B\"\
    \r\n#define ERROR 0.0000001\r\n\r\n#include \"../../template/template.hpp\"\r\n\
    #include \"../../geometry/base_ld.hpp\"\r\n#include \"../../geometry/circle.hpp\"\
    \r\n\r\nusing namespace lib;\r\n\r\nint main() {\r\n    std::cout << std::fixed\
    \ << std::setprecision(15);\r\n    auto input = [](vec &a) {\r\n        ld x,y;\r\
    \n        std::cin >> x >> y;\r\n        a = {x, y};\r\n    };\r\n    vec a,b,c;\r\
    \n    input(a);\r\n    input(b);\r\n    input(c);\r\n    circle in = incircle_of_triangle(a,\
    \ b, c);\r\n    std::cout << in.c.real() << \" \" << in.c.imag() << \" \" << in.r\
    \ << '\\n';\r\n}"
  dependsOn:
  - template/template.hpp
  - geometry/base_ld.hpp
  - geometry/circle.hpp
  isVerificationFile: true
  path: test/geometry/Incircle_of_Triangle.test.cpp
  requiredBy: []
  timestamp: '2023-04-24 18:42:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/Incircle_of_Triangle.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/Incircle_of_Triangle.test.cpp
- /verify/test/geometry/Incircle_of_Triangle.test.cpp.html
title: test/geometry/Incircle_of_Triangle.test.cpp
---