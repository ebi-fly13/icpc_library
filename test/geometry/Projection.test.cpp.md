---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':question:'
    path: geometry/line.hpp
    title: line
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
  bundledCode: "#line 1 \"test/geometry/Projection.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A\"\n\n#line 2\
    \ \"geometry/line.hpp\"\n\n#line 2 \"geometry/base_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib{\n\nusing namespace std;\n\n} // namespace\
    \ lib;\n\n//using namespace lib;\n#line 4 \"geometry/base_ld.hpp\"\n\nnamespace\
    \ lib {\n\nusing vec = complex<ld>;\nconst ld eps = 1e-7;\n\nint sgn(ld a) {\n\
    \    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nld dot(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const\
    \ vec &b){\n    return (conj(a) * b).imag();\n}\n\nint isp(const vec &a, const\
    \ vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b - a, c - a));\n   \
    \ if(cross_sgn == 0) {\n        if(sgn(dot(b - a, c - a)) < 0) return -2;\n  \
    \      if(sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n    return cross_sgn;\n\
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs))\
    \ < eps) return false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n} // namespace\
    \ lib\n#line 4 \"geometry/line.hpp\"\n\nnamespace lib {\n\nstruct line {\n   \
    \ vec a, b;\n};\n\nvec proj(const line &l, const vec &p) {\n    vec ab = l.b -\
    \ l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n}\n\nvec refl(const\
    \ line &l, const vec &p) {\n    return proj(l, p) * ld(2) - p;\n}\n\nint intersection(const\
    \ line &a, const line &b) {\n    if(sgn(cross(a.b - a.a, b.a - b.b)) != 0) {\n\
    \        if(sgn(dot(a.b - a.a, b.a - b.b)) == 0) {\n            return 1;\n  \
    \      }\n        return 0;\n    }\n    else if(sgn(cross(a.b - a.a, b.a - a.a))\
    \ != 0) {\n        return 2;\n    }\n    else {\n        return 3;\n    }\n}\n\
    \n}\n#line 5 \"test/geometry/Projection.test.cpp\"\n\nusing namespace lib;\n\n\
    int main() {\n    std::cout << std::fixed << std::setprecision(15);\n    line\
    \ l;\n    {\n        ld x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >>\
    \ y2;\n        l.a = {x1, y1};\n        l.b = {x2, y2};\n    }\n    int q;\n \
    \   std::cin >> q;\n    while(q--) {\n        ld x,y;\n        std::cin >> x >>\
    \ y;\n        vec p = proj(l, {x, y});\n        std::cout << p.real() << \" \"\
    \ << p.imag() << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A\"\
    \n\n#include \"../../geometry/line.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nusing namespace lib;\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    line l;\n    {\n        ld x1, y1, x2, y2;\n        std::cin >> x1 >> y1\
    \ >> x2 >> y2;\n        l.a = {x1, y1};\n        l.b = {x2, y2};\n    }\n    int\
    \ q;\n    std::cin >> q;\n    while(q--) {\n        ld x,y;\n        std::cin\
    \ >> x >> y;\n        vec p = proj(l, {x, y});\n        std::cout << p.real()\
    \ << \" \" << p.imag() << '\\n';\n    }\n}"
  dependsOn:
  - geometry/line.hpp
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/geometry/Projection.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 19:45:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/geometry/Projection.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/Projection.test.cpp
- /verify/test/geometry/Projection.test.cpp.html
title: test/geometry/Projection.test.cpp
---