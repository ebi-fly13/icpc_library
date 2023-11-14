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
    path: geometry/line.hpp
    title: line
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
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I
  bundledCode: "#line 1 \"test/geometry/Common_Area_Circles.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I\"\
    \n#define ERROR 0.00000001\n\n#line 2 \"geometry/base_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    geometry/base_ld.hpp\"\n\nnamespace lib {\n\nusing vec = complex<ld>;\n\nconst\
    \ ld PI = acos(-1);\n\nvoid ldout(int len = 20) {\n    cout << fixed << setprecision(len);\n\
    }\n\nint sgn(ld a, const ld eps = 1e-7) {\n    return (a < -eps) ? -1 : (a > eps)\
    \ ? 1 : 0;\n}\n\nbool same_vec(vec a, vec b) {\n    a -= b;\n    return sgn(a.real())\
    \ == 0 && sgn(a.imag()) == 0;\n}\n\nld dot(const vec &a, const vec &b) {\n   \
    \ return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const vec &b) {\n\
    \    return (conj(a) * b).imag();\n}\n\nint isp(const vec &a, const vec &b, const\
    \ vec &c) {\n    int cross_sgn = sgn(cross(b - a, c - a));\n    if (cross_sgn\
    \ == 0) {\n        if (sgn(dot(b - a, c - a)) < 0) return -2;\n        if (sgn(dot(a\
    \ - b, c - b)) < 0) return 2;\n    }\n    return cross_sgn;\n}\n\nvec rot90(const\
    \ vec &a) {\n    return {-a.imag(), a.real()};\n}\n\nvec rot(const vec &a, ld\
    \ rad) {\n    return a * vec(cosl(rad), sinl(rad));\n}\n\nbool comp_for_argument_sort(const\
    \ vec &lhs, const vec &rhs) {\n    // if (abs(arg(lhs)-arg(rhs)) < eps) return\
    \ false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\n}  // namespace lib\n\
    #line 2 \"geometry/circle.hpp\"\n\r\n#line 2 \"geometry/line.hpp\"\n\n#line 4\
    \ \"geometry/line.hpp\"\n\nnamespace lib {\n\nstruct line {\n    vec a, b;\n};\n\
    \nvec proj(const line &l, const vec &p) {\n    vec ab = l.b - l.a;\n    return\
    \ l.a + ab * (dot(ab, p - l.a) / norm(ab));\n}\n\nvec refl(const line &l, const\
    \ vec &p) {\n    return proj(l, p) * ld(2) - p;\n}\n\nint intersection(const line\
    \ &a, const line &b) {\n    if (sgn(cross(a.b - a.a, b.a - b.b)) != 0) {\n   \
    \     if (sgn(dot(a.b - a.a, b.a - b.b)) == 0) {\n            return 1;\n    \
    \    }\n        return 0;\n    } else if (sgn(cross(a.b - a.a, b.a - a.a)) !=\
    \ 0) {\n        return 2;\n    } else {\n        return 3;\n    }\n}\n\nld dist(const\
    \ line &a, const vec &p) {\n    return abs(cross(p - a.a, a.b - a.a) / abs(a.b\
    \ - a.a));\n}\n\nvec cross_point(const line &a, const line &b) {\n    assert(intersection(a,\
    \ b) < 2);\n    return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) /\n   \
    \                  cross(a.b - a.a, b.b - b.a);\n}\n\n}  // namespace lib\n#line\
    \ 5 \"geometry/circle.hpp\"\n\r\nnamespace lib {\r\n\r\nstruct circle {\r\n  \
    \  vec c;\r\n    ld r;\r\n};\r\n\r\nint intersection(const circle &c1, const circle\
    \ &c2) {\r\n    if (sgn(c1.c.real() - c2.c.real()) == 0 &&\r\n        sgn(c1.c.imag()\
    \ - c2.c.imag()) == 0 && sgn(c1.r - c2.r) == 0)\r\n        return 5;\r\n    ld\
    \ d = abs(c1.c - c2.c);\r\n    ld r1 = c1.r;\r\n    ld r2 = c2.r;\r\n    if (r1\
    \ < r2) std::swap(r1, r2);\r\n    if (sgn(d - (r1 + r2)) > 0) {\r\n        return\
    \ 4;\r\n    } else if (sgn(d - (r1 + r2)) == 0) {\r\n        return 3;\r\n   \
    \ } else if (sgn(d - r1 + r2) > 0) {\r\n        return 2;\r\n    } else if (sgn(d\
    \ - r1 + r2) == 0) {\r\n        return 1;\r\n    } else\r\n        return 0;\r\
    \n}\r\n\r\ncircle incircle_of_triangle(const vec &a, const vec &b, const vec &c)\
    \ {\r\n    ld A = abs(b - c), B = abs(c - a), C = abs(a - b);\r\n    vec in =\
    \ A * a + B * b + C * c;\r\n    in /= A + B + C;\r\n    ld r = abs(cross(in -\
    \ a, b - a) / abs(b - a));\r\n    return {in, r};\r\n}\r\n\r\ncircle circumscribed_circle_of_triangle(const\
    \ vec &a, const vec &b,\r\n                                        const vec &c)\
    \ {\r\n    line p = {(a + b) / ld(2.0), (a + b) / ld(2.0) + rot90(b - a)};\r\n\
    \    line q = {(b + c) / ld(2.0), (b + c) / ld(2.0) + rot90(c - b)};\r\n    vec\
    \ cross = cross_point(p, q);\r\n    return {cross, abs(a - cross)};\r\n}\r\n\r\
    \nvector<vec> cross_point(const circle &c, const line &l) {\r\n    vector<vec>\
    \ ps;\r\n    ld d = dist(l, c.c);\r\n    if (sgn(d - c.r) == 0)\r\n        ps.emplace_back(proj(l,\
    \ c.c));\r\n    else if (sgn(d - c.r) < 0) {\r\n        vec p = proj(l, c.c);\r\
    \n        vec v = l.b - l.a;\r\n        v *= sqrt(max(c.r * c.r - d * d, ld(0)))\
    \ / abs(v);\r\n        ps.emplace_back(p + v);\r\n        ps.emplace_back(p -\
    \ v);\r\n    }\r\n    return ps;\r\n}\r\n\r\nvector<vec> cross_point(const circle\
    \ &c1, const circle &c2) {\r\n    vector<vec> ps;\r\n    int cnt_tangent = intersection(c1,\
    \ c2);\r\n    if (cnt_tangent == 0 || cnt_tangent == 4) return {};\r\n    ld d\
    \ = abs(c2.c - c1.c);\r\n    ld x = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 *\
    \ d);\r\n    vec p = c1.c + (c2.c - c1.c) * x / d;\r\n    vec v = rot90(c2.c -\
    \ c1.c);\r\n    if (cnt_tangent == 1 || cnt_tangent == 3)\r\n        ps.emplace_back(p);\r\
    \n    else {\r\n        v *= sqrt(max(c1.r * c1.r - x * x, ld(0))) / abs(v);\r\
    \n        ps.emplace_back(p + v);\r\n        ps.emplace_back(p - v);\r\n    }\r\
    \n    return ps;\r\n}\r\n\r\nld common_area(const circle &c1, const circle &c2)\
    \ {\r\n    int flag = intersection(c1, c2);\r\n    if (flag == 3 || flag == 4)\r\
    \n        return 0.0;\r\n    else if (flag == 0 || flag == 1 || flag == 5) {\r\
    \n        ld r = std::min(c1.r, c2.r);\r\n        return PI * r * r;\r\n    }\
    \ else {\r\n        ld d = abs(c1.c - c2.c);\r\n        ld theta1 = c1.r * c1.r\
    \ + d * d - c2.r * c2.r;\r\n        theta1 /= 2.0 * c1.r * d;\r\n        theta1\
    \ = acos(theta1);\r\n        ld area1 = c1.r * c1.r * theta1 - c1.r * c1.r * sin(theta1\
    \ * 2) / 2.0;\r\n        ld theta2 = c2.r * c2.r + d * d - c1.r * c1.r;\r\n  \
    \      theta2 /= 2.0 * c2.r * d;\r\n        theta2 = acos(theta2);\r\n       \
    \ ld area2 = c2.r * c2.r * theta2 - c2.r * c2.r * sin(theta2 * 2) / 2.0;\r\n \
    \       return area1 + area2;\r\n    }\r\n}\r\n\r\n}  // namespace lib\r\n#line\
    \ 8 \"test/geometry/Common_Area_Circles.test.cpp\"\n\nusing namespace lib;\n\n\
    namespace ebi {\n\nvoid main_() {\n    circle c1, c2;\n    auto input = [](circle\
    \ &c) -> void {\n        ld x, y, r;\n        std::cin >> x >> y >> r;\n     \
    \   c.c = {x, y};\n        c.r = r;\n    };\n    input(c1);\n    input(c2);\n\
    \    std::cout << common_area(c1, c2) << '\\n';\n}\n\n}  // namespace ebi\n\n\
    int main() {\n    std::cout << std::fixed << std::setprecision(15);\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    ebi::main_();\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I\"\
    \n#define ERROR 0.00000001\n\n#include \"../../geometry/base_ld.hpp\"\n#include\
    \ \"../../geometry/circle.hpp\"\n#include \"../../template/template.hpp\"\n\n\
    using namespace lib;\n\nnamespace ebi {\n\nvoid main_() {\n    circle c1, c2;\n\
    \    auto input = [](circle &c) -> void {\n        ld x, y, r;\n        std::cin\
    \ >> x >> y >> r;\n        c.c = {x, y};\n        c.r = r;\n    };\n    input(c1);\n\
    \    input(c2);\n    std::cout << common_area(c1, c2) << '\\n';\n}\n\n}  // namespace\
    \ ebi\n\nint main() {\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    ebi::main_();\n\
    }"
  dependsOn:
  - geometry/base_ld.hpp
  - template/template.hpp
  - geometry/circle.hpp
  - geometry/line.hpp
  isVerificationFile: true
  path: test/geometry/Common_Area_Circles.test.cpp
  requiredBy: []
  timestamp: '2023-06-27 22:44:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/Common_Area_Circles.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/Common_Area_Circles.test.cpp
- /verify/test/geometry/Common_Area_Circles.test.cpp.html
title: test/geometry/Common_Area_Circles.test.cpp
---
