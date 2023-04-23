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
  bundledCode: "#line 2 \"geometry/geometry2D_ld.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib{\n\nusing namespace std;\n\n} // namespace\
    \ lib;\n\n//using namespace lib;\n#line 4 \"geometry/geometry2D_ld.hpp\"\n\nnamespace\
    \ lib {\n\nvoid ldout(){\n    cout << fixed << setprecision(20);\n}\n\nusing vec\
    \ = complex<ld>;\nconst ld eps = 1e-7;\n\nld dot(const vec &a, const vec &b){\n\
    \    return (conj(a) * b).real();\n}\n\nld cross(const vec &a, const vec &b){\n\
    \    return (conj(a) * b).imag();\n}\n\nvoid rot(vec &a, ld rad){\n    a *= vec(cosl(rad),sinl(rad));\n\
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs))\
    \ < eps) return false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\nvector<vec>\
    \ convex_hull(vector<vec> a){\n    int n = a.size();\n    if (n <= 2) return a;\n\
    \    auto comp = [&](vec lhs, vec rhs){\n        if (lhs.real() == rhs.real())\
    \ return lhs.imag() < rhs.imag();\n        return lhs.real() < rhs.real();\n \
    \   };\n    sort(all(a),comp);\n    stack<int> uid, did;\n    uid.push(0);\n \
    \   vec ri = a[n-1];\n    rep(i,1,n-1) {\n        vec le = a[uid.top()];\n   \
    \     if (cross(ri-le,a[i]-le) > 0){\n            while (uid.size() >= 2){\n \
    \               int test = uid.top(); uid.pop();\n                vec from = a[uid.top()];\n\
    \                if (cross(a[i]-from,a[test]-from) > 0){\n                   \
    \ uid.push(test);\n                    break;\n                }\n           \
    \ }\n            uid.push(i);\n        }\n    }\n    did.push(0);\n    rep(i,1,n-1){\n\
    \        vec le = a[did.top()];\n        if (cross(ri-le,a[i]-le) < 0){\n    \
    \        while (did.size() >= 2){\n                int test = did.top(); did.pop();\n\
    \                vec from = a[did.top()];\n                if (cross(a[i]-from,a[test]-from)\
    \ < 0){\n                    did.push(test);\n                    break;\n   \
    \             }\n            }\n            did.push(i);\n        }\n    }\n \
    \   vector<int> ids(1,n-1);\n    while (!uid.empty()) ids.emplace_back(uid.top()),\
    \ uid.pop();\n    reverse(all(ids));\n    while (!did.empty()) ids.emplace_back(did.top()),\
    \ did.pop();\n    vector<vec> ans(ids.size());\n    rep(i,0,ids.size()) ans[i]\
    \ = a[ids[i]];\n    return ans;\n}\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \nvoid ldout(){\n    cout << fixed << setprecision(20);\n}\n\nusing vec = complex<ld>;\n\
    const ld eps = 1e-7;\n\nld dot(const vec &a, const vec &b){\n    return (conj(a)\
    \ * b).real();\n}\n\nld cross(const vec &a, const vec &b){\n    return (conj(a)\
    \ * b).imag();\n}\n\nvoid rot(vec &a, ld rad){\n    a *= vec(cosl(rad),sinl(rad));\n\
    }\n\nbool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n    //if (abs(arg(lhs)-arg(rhs))\
    \ < eps) return false; // need ?\n    return arg(lhs) < arg(rhs);\n}\n\nvector<vec>\
    \ convex_hull(vector<vec> a){\n    int n = a.size();\n    if (n <= 2) return a;\n\
    \    auto comp = [&](vec lhs, vec rhs){\n        if (lhs.real() == rhs.real())\
    \ return lhs.imag() < rhs.imag();\n        return lhs.real() < rhs.real();\n \
    \   };\n    sort(all(a),comp);\n    stack<int> uid, did;\n    uid.push(0);\n \
    \   vec ri = a[n-1];\n    rep(i,1,n-1) {\n        vec le = a[uid.top()];\n   \
    \     if (cross(ri-le,a[i]-le) > 0){\n            while (uid.size() >= 2){\n \
    \               int test = uid.top(); uid.pop();\n                vec from = a[uid.top()];\n\
    \                if (cross(a[i]-from,a[test]-from) > 0){\n                   \
    \ uid.push(test);\n                    break;\n                }\n           \
    \ }\n            uid.push(i);\n        }\n    }\n    did.push(0);\n    rep(i,1,n-1){\n\
    \        vec le = a[did.top()];\n        if (cross(ri-le,a[i]-le) < 0){\n    \
    \        while (did.size() >= 2){\n                int test = did.top(); did.pop();\n\
    \                vec from = a[did.top()];\n                if (cross(a[i]-from,a[test]-from)\
    \ < 0){\n                    did.push(test);\n                    break;\n   \
    \             }\n            }\n            did.push(i);\n        }\n    }\n \
    \   vector<int> ids(1,n-1);\n    while (!uid.empty()) ids.emplace_back(uid.top()),\
    \ uid.pop();\n    reverse(all(ids));\n    while (!did.empty()) ids.emplace_back(did.top()),\
    \ did.pop();\n    vector<vec> ans(ids.size());\n    rep(i,0,ids.size()) ans[i]\
    \ = a[ids[i]];\n    return ans;\n}\n\n} // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/geometry2D_ld.hpp
  requiredBy: []
  timestamp: '2023-04-23 18:12:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry2D_ld.hpp
layout: document
redirect_from:
- /library/geometry/geometry2D_ld.hpp
- /library/geometry/geometry2D_ld.hpp.html
title: geometry/geometry2D_ld.hpp
---
