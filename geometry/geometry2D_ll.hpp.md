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
  bundledCode: "#line 2 \"geometry/geometry2D_ll.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib{\n\nusing namespace std;\n\n} // namespace\
    \ lib;\n\n//using namespace lib;\n#line 4 \"geometry/geometry2D_ll.hpp\"\n\nnamespace\
    \ lib {\n\nusing vec = complex<ll>;\n\nll dot(const vec &a, const vec &b){\n \
    \   return (conj(a) * b).real();\n}\n\nll cross(const vec &a, const vec &b){\n\
    \    return (conj(a) * b).imag();\n}\n\n// e : vec(OX)\n// orthant k : [ pi/2\
    \ * k, pi/2 * (k+1) ) rad\n// orthant 4 is NOT expected\nint orthant(const vec\
    \ &p, const vec &e = vec(1,0)){\n    ll _dot = dot(e,p), _cross = cross(e,p);\n\
    \    if (_dot >  0 && _cross >= 0) return 0;\n    if (_dot <= 0 && _cross >  0)\
    \ return 1;\n    if (_dot <  0 && _cross <= 0) return 2;\n    if (_dot >= 0 &&\
    \ _cross <  0) return 3;\n    return 4;\n}\n\n// usage : \n//   vector<vec>> a;\n\
    //   sort(all(a),comp_for_argument_sort);\nbool comp_for_argument_sort(const vec\
    \ &lhs, const vec &rhs){\n    int pl = orthant(lhs), pr = orthant(rhs);\n    if\
    \ (pl == pr){\n        return cross(lhs,rhs) > 0;\n    }\n    return pl < pr;\n\
    }\n\nvector<vec> convex_hull(vector<vec> a){\n    int n = a.size();\n    if (n\
    \ <= 2) return a;\n    auto comp = [&](vec lhs, vec rhs){\n        if (lhs.real()\
    \ == rhs.real()) return lhs.imag() < rhs.imag();\n        return lhs.real() <\
    \ rhs.real();\n    };\n    sort(all(a),comp);\n    stack<int> uid, did;\n    uid.push(0);\n\
    \    vec ri = a[n-1];\n    rep(i,1,n-1) {\n        vec le = a[uid.top()];\n  \
    \      if (cross(ri-le,a[i]-le) > 0){\n            while (uid.size() >= 2){\n\
    \                int test = uid.top(); uid.pop();\n                vec from =\
    \ a[uid.top()];\n                if (cross(a[i]-from,a[test]-from) > 0){\n   \
    \                 uid.push(test);\n                    break;\n              \
    \  }\n            }\n            uid.push(i);\n        }\n    }\n    did.push(0);\n\
    \    rep(i,1,n-1){\n        vec le = a[did.top()];\n        if (cross(ri-le,a[i]-le)\
    \ < 0){\n            while (did.size() >= 2){\n                int test = did.top();\
    \ did.pop();\n                vec from = a[did.top()];\n                if (cross(a[i]-from,a[test]-from)\
    \ < 0){\n                    did.push(test);\n                    break;\n   \
    \             }\n            }\n            did.push(i);\n        }\n    }\n \
    \   vector<int> ids(1,n-1);\n    while (!uid.empty()) ids.emplace_back(uid.top()),\
    \ uid.pop();\n    reverse(all(ids));\n    while (!did.empty()) ids.emplace_back(did.top()),\
    \ did.pop();\n    vector<vec> ans(ids.size());\n    rep(i,0,ids.size()) ans[i]\
    \ = a[ids[i]];\n    return ans;\n}\n\n} // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \nusing vec = complex<ll>;\n\nll dot(const vec &a, const vec &b){\n    return\
    \ (conj(a) * b).real();\n}\n\nll cross(const vec &a, const vec &b){\n    return\
    \ (conj(a) * b).imag();\n}\n\n// e : vec(OX)\n// orthant k : [ pi/2 * k, pi/2\
    \ * (k+1) ) rad\n// orthant 4 is NOT expected\nint orthant(const vec &p, const\
    \ vec &e = vec(1,0)){\n    ll _dot = dot(e,p), _cross = cross(e,p);\n    if (_dot\
    \ >  0 && _cross >= 0) return 0;\n    if (_dot <= 0 && _cross >  0) return 1;\n\
    \    if (_dot <  0 && _cross <= 0) return 2;\n    if (_dot >= 0 && _cross <  0)\
    \ return 3;\n    return 4;\n}\n\n// usage : \n//   vector<vec>> a;\n//   sort(all(a),comp_for_argument_sort);\n\
    bool comp_for_argument_sort(const vec &lhs, const vec &rhs){\n    int pl = orthant(lhs),\
    \ pr = orthant(rhs);\n    if (pl == pr){\n        return cross(lhs,rhs) > 0;\n\
    \    }\n    return pl < pr;\n}\n\nvector<vec> convex_hull(vector<vec> a){\n  \
    \  int n = a.size();\n    if (n <= 2) return a;\n    auto comp = [&](vec lhs,\
    \ vec rhs){\n        if (lhs.real() == rhs.real()) return lhs.imag() < rhs.imag();\n\
    \        return lhs.real() < rhs.real();\n    };\n    sort(all(a),comp);\n   \
    \ stack<int> uid, did;\n    uid.push(0);\n    vec ri = a[n-1];\n    rep(i,1,n-1)\
    \ {\n        vec le = a[uid.top()];\n        if (cross(ri-le,a[i]-le) > 0){\n\
    \            while (uid.size() >= 2){\n                int test = uid.top(); uid.pop();\n\
    \                vec from = a[uid.top()];\n                if (cross(a[i]-from,a[test]-from)\
    \ > 0){\n                    uid.push(test);\n                    break;\n   \
    \             }\n            }\n            uid.push(i);\n        }\n    }\n \
    \   did.push(0);\n    rep(i,1,n-1){\n        vec le = a[did.top()];\n        if\
    \ (cross(ri-le,a[i]-le) < 0){\n            while (did.size() >= 2){\n        \
    \        int test = did.top(); did.pop();\n                vec from = a[did.top()];\n\
    \                if (cross(a[i]-from,a[test]-from) < 0){\n                   \
    \ did.push(test);\n                    break;\n                }\n           \
    \ }\n            did.push(i);\n        }\n    }\n    vector<int> ids(1,n-1);\n\
    \    while (!uid.empty()) ids.emplace_back(uid.top()), uid.pop();\n    reverse(all(ids));\n\
    \    while (!did.empty()) ids.emplace_back(did.top()), did.pop();\n    vector<vec>\
    \ ans(ids.size());\n    rep(i,0,ids.size()) ans[i] = a[ids[i]];\n    return ans;\n\
    }\n\n} // namespace lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/geometry2D_ll.hpp
  requiredBy: []
  timestamp: '2023-04-23 17:46:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry2D_ll.hpp
layout: document
redirect_from:
- /library/geometry/geometry2D_ll.hpp
- /library/geometry/geometry2D_ll.hpp.html
title: geometry/geometry2D_ll.hpp
---
