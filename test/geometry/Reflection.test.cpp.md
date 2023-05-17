---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: line
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
    ERROR: '0.0000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
  bundledCode: "#line 1 \"test/geometry/Reflection.test.cpp\"\n#define PROBLEM \\\n\
    \    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\n#define\
    \ ERROR 0.0000001\n\n#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/base_ld.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = s; i < (int)(n); i++)\n#define rrep(i, s, n) for (int i =\
    \ (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"geometry/base_ld.hpp\"\n\nnamespace lib {\n\nusing vec = complex<ld>;\n\
    const ld eps = 1e-7;\n\nvoid ldout(int len = 20) {\n    cout << fixed << setprecision(len);\n\
    }\n\nint sgn(ld a) {\n    return (a < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nld\
    \ dot(const vec &a, const vec &b) {\n    return (conj(a) * b).real();\n}\n\nld\
    \ cross(const vec &a, const vec &b) {\n    return (conj(a) * b).imag();\n}\n\n\
    int isp(const vec &a, const vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b\
    \ - a, c - a));\n    if (cross_sgn == 0) {\n        if (sgn(dot(b - a, c - a))\
    \ < 0) return -2;\n        if (sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n\
    \    return cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return {-a.imag(),\
    \ a.real()};\n}\n\nvec rot(const vec &a, ld rad) {\n    return a * vec(cosl(rad),\
    \ sinl(rad));\n}\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs)\
    \ {\n    // if (abs(arg(lhs)-arg(rhs)) < eps) return false; // need ?\n    return\
    \ arg(lhs) < arg(rhs);\n}\n\n}  // namespace lib\n#line 4 \"geometry/line.hpp\"\
    \n\nnamespace lib {\n\nstruct line {\n    vec a, b;\n};\n\nvec proj(const line\
    \ &l, const vec &p) {\n    vec ab = l.b - l.a;\n    return l.a + ab * (dot(ab,\
    \ p - l.a) / norm(ab));\n}\n\nvec refl(const line &l, const vec &p) {\n    return\
    \ proj(l, p) * ld(2) - p;\n}\n\nint intersection(const line &a, const line &b)\
    \ {\n    if (sgn(cross(a.b - a.a, b.a - b.b)) != 0) {\n        if (sgn(dot(a.b\
    \ - a.a, b.a - b.b)) == 0) {\n            return 1;\n        }\n        return\
    \ 0;\n    } else if (sgn(cross(a.b - a.a, b.a - a.a)) != 0) {\n        return\
    \ 2;\n    } else {\n        return 3;\n    }\n}\n\nld dist(const line &a, const\
    \ vec &p) {\n    return abs(cross(p - a.a, a.b - a.a) / abs(a.b - a.a));\n}\n\n\
    vec cross_point(const line &a, const line &b) {\n    assert(intersection(a, b)\
    \ < 2);\n    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) /\n      \
    \               cross(a.b - a.a, b.b - b.a);\n}\n\n}  // namespace lib\n#line\
    \ 7 \"test/geometry/Reflection.test.cpp\"\n\nusing namespace lib;\n\nint main()\
    \ {\n    std::cout << std::fixed << std::setprecision(15);\n    line l;\n    {\n\
    \        ld x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >> y2;\n     \
    \   l.a = {x1, y1};\n        l.b = {x2, y2};\n    }\n    int q;\n    std::cin\
    \ >> q;\n    while (q--) {\n        ld x, y;\n        std::cin >> x >> y;\n  \
    \      vec p = refl(l, {x, y});\n        std::cout << p.real() << \" \" << p.imag()\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR 0.0000001\n\n#include \"../../geometry/line.hpp\"\n#include \"\
    ../../template/template.hpp\"\n\nusing namespace lib;\n\nint main() {\n    std::cout\
    \ << std::fixed << std::setprecision(15);\n    line l;\n    {\n        ld x1,\
    \ y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >> y2;\n        l.a = {x1, y1};\n\
    \        l.b = {x2, y2};\n    }\n    int q;\n    std::cin >> q;\n    while (q--)\
    \ {\n        ld x, y;\n        std::cin >> x >> y;\n        vec p = refl(l, {x,\
    \ y});\n        std::cout << p.real() << \" \" << p.imag() << '\\n';\n    }\n}"
  dependsOn:
  - geometry/line.hpp
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: true
  path: test/geometry/Reflection.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 18:25:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/Reflection.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/Reflection.test.cpp
- /verify/test/geometry/Reflection.test.cpp.html
title: test/geometry/Reflection.test.cpp
---
