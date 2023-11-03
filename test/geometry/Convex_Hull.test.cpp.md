---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':heavy_check_mark:'
    path: geometry/convex_hull.hpp
    title: convex_hull
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: line
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: segment
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
    ERROR: '0.001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2827
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2827
  bundledCode: "#line 1 \"test/geometry/Convex_Hull.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/2827\"\n#define ERROR 0.001\n\n#line\
    \ 2 \"geometry/convex_hull.hpp\"\n\n#line 2 \"geometry/base_ld.hpp\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i, s,\
    \ n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"geometry/base_ld.hpp\"\n\nnamespace lib {\n\nusing vec = complex<ld>;\n\
    \nconst ld PI = acos(-1);\n\nvoid ldout(int len = 20) {\n    cout << fixed <<\
    \ setprecision(len);\n}\n\nint sgn(ld a, const ld eps = 1e-7) {\n    return (a\
    \ < -eps) ? -1 : (a > eps) ? 1 : 0;\n}\n\nbool same_vec(vec a, vec b) {\n    a\
    \ -= b;\n    return sgn(a.real()) == 0 && sgn(a.imag()) == 0;\n}\n\nld dot(const\
    \ vec &a, const vec &b) {\n    return (conj(a) * b).real();\n}\n\nld cross(const\
    \ vec &a, const vec &b) {\n    return (conj(a) * b).imag();\n}\n\nint isp(const\
    \ vec &a, const vec &b, const vec &c) {\n    int cross_sgn = sgn(cross(b - a,\
    \ c - a));\n    if (cross_sgn == 0) {\n        if (sgn(dot(b - a, c - a)) < 0)\
    \ return -2;\n        if (sgn(dot(a - b, c - b)) < 0) return 2;\n    }\n    return\
    \ cross_sgn;\n}\n\nvec rot90(const vec &a) {\n    return {-a.imag(), a.real()};\n\
    }\n\nvec rot(const vec &a, ld rad) {\n    return a * vec(cosl(rad), sinl(rad));\n\
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs) {\n    // if\
    \ (abs(arg(lhs)-arg(rhs)) < eps) return false; // need ?\n    return arg(lhs)\
    \ < arg(rhs);\n}\n\n}  // namespace lib\n#line 5 \"geometry/convex_hull.hpp\"\n\
    \nnamespace lib {\n\nvector<vec> convex_hull(vector<vec> a) {\n    int n = a.size();\n\
    \    if (n <= 2) return a;\n    auto comp = [&](vec lhs, vec rhs) {\n        if\
    \ (lhs.real() == rhs.real()) return lhs.imag() < rhs.imag();\n        return lhs.real()\
    \ < rhs.real();\n    };\n    sort(all(a), comp);\n    stack<int> uid, did;\n \
    \   vec ri = a[n - 1];\n    auto make_half = [&](bool isupper) {\n        auto\
    \ &id = (isupper ? uid : did);\n        id.push(0);\n        rep(i, 1, n - 1)\
    \ {\n            vec le = a[id.top()];\n            auto cr = cross(ri - le, a[i]\
    \ - le);\n            if ((cr > 0 && isupper) || (cr < 0 && !isupper)) {\n   \
    \             while (id.size() >= 2) {\n                    int test = id.top();\n\
    \                    id.pop();\n                    vec from = a[id.top()];\n\
    \                    auto cr2 = cross(a[i] - from, a[test] - from);\n        \
    \            if ((cr2 > 0 && isupper) || (cr2 < 0 && !isupper)) {\n          \
    \              id.push(test);\n                        break;\n              \
    \      }\n                }\n                id.push(i);\n            }\n    \
    \    }\n    };\n    make_half(true);\n    make_half(false);\n    vector<int> ids(1,\
    \ n - 1);\n    while (!did.empty()) ids.emplace_back(did.top()), did.pop();\n\
    \    reverse(all(ids));\n    while (!uid.empty()) ids.emplace_back(uid.top()),\
    \ uid.pop();\n    ids.pop_back();\n    vector<vec> ans(ids.size());\n    rep(i,\
    \ 0, ids.size()) ans[i] = a[ids[i]];\n    return ans;\n}\n\n}  // namespace lib\n\
    #line 5 \"test/geometry/Convex_Hull.test.cpp\"\n\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\nnamespace\
    \ lib {\n\nstruct line {\n    vec a, b;\n};\n\nvec proj(const line &l, const vec\
    \ &p) {\n    vec ab = l.b - l.a;\n    return l.a + ab * (dot(ab, p - l.a) / norm(ab));\n\
    }\n\nvec refl(const line &l, const vec &p) {\n    return proj(l, p) * ld(2) -\
    \ p;\n}\n\nint intersection(const line &a, const line &b) {\n    if (sgn(cross(a.b\
    \ - a.a, b.a - b.b)) != 0) {\n        if (sgn(dot(a.b - a.a, b.a - b.b)) == 0)\
    \ {\n            return 1;\n        }\n        return 0;\n    } else if (sgn(cross(a.b\
    \ - a.a, b.a - a.a)) != 0) {\n        return 2;\n    } else {\n        return\
    \ 3;\n    }\n}\n\nld dist(const line &a, const vec &p) {\n    return abs(cross(p\
    \ - a.a, a.b - a.a) / abs(a.b - a.a));\n}\n\nvec cross_point(const line &a, const\
    \ line &b) {\n    assert(intersection(a, b) < 2);\n    return a.a + (a.b - a.a)\
    \ * cross(b.a - a.a, b.b - b.a) /\n                     cross(a.b - a.a, b.b -\
    \ b.a);\n}\n\n}  // namespace lib\n#line 4 \"geometry/segment.hpp\"\n\nnamespace\
    \ lib {\n\nstruct segment : line {};\n\nbool intersection_segment_and_vec(const\
    \ segment &a, const vec &p) {\n    return isp(a.a, a.a, p) == 0;\n}\n\nbool intersection_segment(const\
    \ segment &a, const segment &b) {\n    if (sgn(isp(a.a, a.b, b.a) * isp(a.a, a.b,\
    \ b.b)) <= 0 &&\n        sgn(isp(b.a, b.b, a.a) * isp(b.a, b.b, a.b)) <= 0) {\n\
    \        return true;\n    } else\n        return false;\n}\n\nvec cross_point(const\
    \ segment &a, const segment &b) {\n    assert(intersection_segment(a, b));\n \
    \   return a.a + (a.b - a.a) * cross(b.a - a.a, b.b - b.a) /\n               \
    \      cross(a.b - a.a, b.b - b.a);\n}\n\nld dist(const segment &a, const vec\
    \ &c) {\n    if (sgn(dot(a.b - a.a, c - a.a)) <= 0) {\n        return abs(c -\
    \ a.a);\n    } else if (sgn(dot(a.a - a.b, c - a.b)) <= 0) {\n        return abs(c\
    \ - a.b);\n    } else {\n        return abs(cross(c - a.a, a.b - a.a) / abs(a.b\
    \ - a.a));\n    }\n}\n\nld dist(const segment &a, const segment &b) {\n    if\
    \ (intersection_segment(a, b))\n        return 0;\n    else\n        return min(min(dist(a,\
    \ b.a), dist(a, b.b)),\n                   min(dist(b, a.a), dist(b, a.b)));\n\
    }\n\n}  // namespace lib\n#line 8 \"test/geometry/Convex_Hull.test.cpp\"\nusing\
    \ namespace lib;\n\nconst ld dinf = 2e12;\n\nvoid solve(int n) {\n    vector<vector<vec>>\
    \ a(n);\n    vector<ld> hs(n);\n    rep(i, 0, n) {\n        int m;\n        cin\
    \ >> m >> hs[i];\n        a[i].resize(m);\n        rep(j, 0, m) {\n          \
    \  ld x, y;\n            cin >> x >> y;\n            a[i][j] = vec(x, y);\n  \
    \      }\n    }\n    ld rad1, rad2;\n    cin >> rad1 >> rad2;\n    rad1 *= M_PI\
    \ / 180, rad2 *= M_PI / 180;\n    ld sx, sy, tx, ty;\n    cin >> sx >> sy >> tx\
    \ >> ty;\n    vec sv(sx, sy), tv(tx, ty);\n    vector<vector<vec>> hulls(n);\n\
    \    rep(i, 0, n) {\n        vec pl = rot(vec(hs[i] / tanl(rad2), 0), rad1 + M_PI);\n\
    \        vector<vec> b = a[i];\n        rep(j, 0, a[i].size()) b.emplace_back(a[i][j]\
    \ + pl);\n        hulls[i] = convex_hull(b);\n    }\n    vector<vector<ld>> ds(n\
    \ + 2, vector<ld>(n + 2, dinf));\n    rep(i, 0, n) rep(j, 0, n) {\n        if\
    \ (i >= j) {\n            ds[i][j] = ds[j][i];\n            continue;\n      \
    \  }\n        int si = hulls[i].size(), sj = hulls[j].size();\n        rep(p,\
    \ 0, si) rep(q, 0, sj) {\n            segment iseg({hulls[i][p], hulls[i][(p +\
    \ 1) % si]});\n            segment jseg({hulls[j][q], hulls[j][(q + 1) % sj]});\n\
    \            chmin(ds[i][j], dist(iseg, jseg));\n        }\n    }\n    ds[n][n\
    \ + 1] = abs(sv - tv);\n    ds[n + 1][n] = ds[n][n + 1];\n    auto dist_hull_vec\
    \ = [&](int id, vec v) {\n        bool in = true;\n        ld res = dinf;\n  \
    \      int isiz = hulls[id].size();\n        rep(i, 0, isiz) {\n            vec\
    \ iv = hulls[id][i];\n            vec jv = hulls[id][(i + 1) % isiz];\n      \
    \      chmin(res, dist(segment({iv, jv}), v));\n            if (cross(jv - iv,\
    \ v - iv) < 0) in = false;\n        }\n        if (in) return ld(0);\n       \
    \ return res;\n    };\n    rep(i, 0, n) {\n        ds[i][n] = dist_hull_vec(i,\
    \ sv);\n        ds[n][i] = ds[i][n];\n        ds[i][n + 1] = dist_hull_vec(i,\
    \ tv);\n        ds[n + 1][i] = ds[i][n + 1];\n    }\n    vector<ld> ans(n + 2,\
    \ dinf);\n    ans[n] = 0;\n    using pdi = pair<ld, int>;\n    priority_queue<pdi,\
    \ vector<pdi>, greater<pdi>> pque;\n    pque.push(pdi(ans[n], n));\n    while\
    \ (!pque.empty()) {\n        auto [idist, f] = pque.top();\n        pque.pop();\n\
    \        if (ans[f] < idist) continue;\n        rep(i, 0, n + 2) {\n         \
    \   if (chmin(ans[i], idist + ds[f][i])) {\n                pque.push(pdi(ans[i],\
    \ i));\n            }\n        }\n    }\n    cout << ans[n + 1] << endl;\n}\n\n\
    int main() {\n    ldout();\n    while (true) {\n        int n;\n        cin >>\
    \ n;\n        if (n == 0) break;\n        solve(n);\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2827\"\n#define\
    \ ERROR 0.001\n\n#include \"../../geometry/convex_hull.hpp\"\n\n#include \"../../geometry/segment.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace lib;\n\nconst ld dinf\
    \ = 2e12;\n\nvoid solve(int n) {\n    vector<vector<vec>> a(n);\n    vector<ld>\
    \ hs(n);\n    rep(i, 0, n) {\n        int m;\n        cin >> m >> hs[i];\n   \
    \     a[i].resize(m);\n        rep(j, 0, m) {\n            ld x, y;\n        \
    \    cin >> x >> y;\n            a[i][j] = vec(x, y);\n        }\n    }\n    ld\
    \ rad1, rad2;\n    cin >> rad1 >> rad2;\n    rad1 *= M_PI / 180, rad2 *= M_PI\
    \ / 180;\n    ld sx, sy, tx, ty;\n    cin >> sx >> sy >> tx >> ty;\n    vec sv(sx,\
    \ sy), tv(tx, ty);\n    vector<vector<vec>> hulls(n);\n    rep(i, 0, n) {\n  \
    \      vec pl = rot(vec(hs[i] / tanl(rad2), 0), rad1 + M_PI);\n        vector<vec>\
    \ b = a[i];\n        rep(j, 0, a[i].size()) b.emplace_back(a[i][j] + pl);\n  \
    \      hulls[i] = convex_hull(b);\n    }\n    vector<vector<ld>> ds(n + 2, vector<ld>(n\
    \ + 2, dinf));\n    rep(i, 0, n) rep(j, 0, n) {\n        if (i >= j) {\n     \
    \       ds[i][j] = ds[j][i];\n            continue;\n        }\n        int si\
    \ = hulls[i].size(), sj = hulls[j].size();\n        rep(p, 0, si) rep(q, 0, sj)\
    \ {\n            segment iseg({hulls[i][p], hulls[i][(p + 1) % si]});\n      \
    \      segment jseg({hulls[j][q], hulls[j][(q + 1) % sj]});\n            chmin(ds[i][j],\
    \ dist(iseg, jseg));\n        }\n    }\n    ds[n][n + 1] = abs(sv - tv);\n   \
    \ ds[n + 1][n] = ds[n][n + 1];\n    auto dist_hull_vec = [&](int id, vec v) {\n\
    \        bool in = true;\n        ld res = dinf;\n        int isiz = hulls[id].size();\n\
    \        rep(i, 0, isiz) {\n            vec iv = hulls[id][i];\n            vec\
    \ jv = hulls[id][(i + 1) % isiz];\n            chmin(res, dist(segment({iv, jv}),\
    \ v));\n            if (cross(jv - iv, v - iv) < 0) in = false;\n        }\n \
    \       if (in) return ld(0);\n        return res;\n    };\n    rep(i, 0, n) {\n\
    \        ds[i][n] = dist_hull_vec(i, sv);\n        ds[n][i] = ds[i][n];\n    \
    \    ds[i][n + 1] = dist_hull_vec(i, tv);\n        ds[n + 1][i] = ds[i][n + 1];\n\
    \    }\n    vector<ld> ans(n + 2, dinf);\n    ans[n] = 0;\n    using pdi = pair<ld,\
    \ int>;\n    priority_queue<pdi, vector<pdi>, greater<pdi>> pque;\n    pque.push(pdi(ans[n],\
    \ n));\n    while (!pque.empty()) {\n        auto [idist, f] = pque.top();\n \
    \       pque.pop();\n        if (ans[f] < idist) continue;\n        rep(i, 0,\
    \ n + 2) {\n            if (chmin(ans[i], idist + ds[f][i])) {\n             \
    \   pque.push(pdi(ans[i], i));\n            }\n        }\n    }\n    cout << ans[n\
    \ + 1] << endl;\n}\n\nint main() {\n    ldout();\n    while (true) {\n       \
    \ int n;\n        cin >> n;\n        if (n == 0) break;\n        solve(n);\n \
    \   }\n}"
  dependsOn:
  - geometry/convex_hull.hpp
  - geometry/base_ld.hpp
  - template/template.hpp
  - geometry/segment.hpp
  - geometry/line.hpp
  isVerificationFile: true
  path: test/geometry/Convex_Hull.test.cpp
  requiredBy: []
  timestamp: '2023-06-08 15:34:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/Convex_Hull.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/Convex_Hull.test.cpp
- /verify/test/geometry/Convex_Hull.test.cpp.html
title: test/geometry/Convex_Hull.test.cpp
---
