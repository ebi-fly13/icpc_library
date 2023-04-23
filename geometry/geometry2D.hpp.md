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
  bundledCode: "#line 2 \"geometry/geometry2D.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib{\n\nusing namespace std;\n\n} // namespace\
    \ lib;\n\n//using namespace lib;\n#line 4 \"geometry/geometry2D.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate<typename T>\nstruct Vec {\n    T x, y;\n    Vec (T _x = T(0),\
    \ T _y = T(0)) : x(_x), y(_y) {}\n    Vec& operator*=(const T& a){\n        x\
    \ *= a;\n        y *= a;\n        return *this;\n    }\n    Vec& operator/=(const\
    \ T& a){\n        x /= a;\n        y /= a;\n        return *this;\n    }\n   \
    \ Vec& operator+=(const Vec& rhs) {\n        x += rhs.x;\n        y += rhs.y;\n\
    \        return *this;\n    }\n    Vec& operator-=(const Vec& rhs) {\n       \
    \ x -= rhs.x;\n        y -= rhs.y;\n        return *this;\n    }\n    friend Vec\
    \ operator+(const Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) += rhs;\n\
    \    }\n    friend Vec operator-(const Vec& lhs, const Vec& rhs) {\n        return\
    \ Vec(lhs) -= rhs;\n    }\n    friend Vec operator*(const Vec& lhs, const T& rhs)\
    \ {\n        return Vec(lhs) *= rhs;\n    }\n    friend Vec operator*(const T&\
    \ rhs, const Vec& lhs) {\n        return Vec(lhs) *= rhs;\n    }\n    friend Vec\
    \ operator/(const Vec& lhs, const T& rhs) {\n        return Vec(lhs) /= rhs;\n\
    \    }\n    friend Vec operator/(const T& rhs, const Vec& lhs) {\n        return\
    \ Vec(lhs) /= rhs;\n    }\n    ld norm(){\n        return sqrtl(ld(x*x+y*y));\n\
    \    }\n    T norm2(){\n        return x*x+y*y;\n    }\n};\n\ntemplate<typename\
    \ T>\nT dot(const Vec<T> &a, const Vec<T> &b){\n    return a.x * b.x + a.y * b.y;\n\
    }\n\n// cross > 0 : counter clockwise a -> b\ntemplate<typename T>\nT cross(const\
    \ Vec<T> &a, const Vec<T> &b){\n    return a.x * b.y - a.y * b.x;\n}\n\n// e :\
    \ vec(OX)\n// orthant k : [ pi/2 * k, pi/2 * (k+1) ) rad\n// orthant 4 is NOT\
    \ expected\ntemplate<typename T>\nint orthant(const Vec<T> &e, const Vec<T> &p){\n\
    \    T _dot = dot(e,p), _cross = cross(e,p);\n    if (_dot >  0 && _cross >= 0)\
    \ return 0;\n    if (_dot <= 0 && _cross >  0) return 1;\n    if (_dot <  0 &&\
    \ _cross <= 0) return 2;\n    if (_dot >= 0 && _cross <  0) return 3;\n    return\
    \ 4;\n}\n\n// usage : \n//   vector<Vec<ll>> vec;\n//   sort(vec.begin(),vec.end(),comp_for_argument_sort<ll>);\n\
    template<typename T>\nbool comp_for_argument_sort(const Vec<T> &lhs, const Vec<T>\
    \ &rhs){\n    int pl = orthant(Vec<T>(1,0),lhs), pr = orthant(Vec<T>(1,0),rhs);\n\
    \    if (pl == pr){\n        return cross(lhs,rhs) > 0;\n    }\n    return pl\
    \ < pr;\n}\n\n// DISTINCT points are given\n// ans[0] --- ans[1] --- ... --- ans[k-1]\
    \ --- ans[k] --- ans[0]\n// upper_hull --- lower_hull\n// upper_hull : x is from\
    \ small to large\n// lower hull : x is from large to small\n// points rearranged\
    \ clockwise\ntemplate<typename T>\nvector<Vec<T>> convex_hull(vector<Vec<T>> a){\n\
    \    int n = a.size();\n    if (n <= 2) return a;\n    using vec = Vec<T>;\n \
    \   auto comp = [&](vec lhs, vec rhs){\n        if (lhs.x == rhs.x) return lhs.y\
    \ < rhs.y;\n        return lhs.x < rhs.x;\n    };\n    sort(all(a),comp);\n  \
    \  stack<int> uid, did;\n    uid.push(0);\n    vec ri = a[n-1];\n    rep(i,1,n-1)\
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
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate<typename T>\nstruct Vec {\n    T x, y;\n    Vec (T _x = T(0), T _y\
    \ = T(0)) : x(_x), y(_y) {}\n    Vec& operator*=(const T& a){\n        x *= a;\n\
    \        y *= a;\n        return *this;\n    }\n    Vec& operator/=(const T& a){\n\
    \        x /= a;\n        y /= a;\n        return *this;\n    }\n    Vec& operator+=(const\
    \ Vec& rhs) {\n        x += rhs.x;\n        y += rhs.y;\n        return *this;\n\
    \    }\n    Vec& operator-=(const Vec& rhs) {\n        x -= rhs.x;\n        y\
    \ -= rhs.y;\n        return *this;\n    }\n    friend Vec operator+(const Vec&\
    \ lhs, const Vec& rhs) {\n        return Vec(lhs) += rhs;\n    }\n    friend Vec\
    \ operator-(const Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) -= rhs;\n\
    \    }\n    friend Vec operator*(const Vec& lhs, const T& rhs) {\n        return\
    \ Vec(lhs) *= rhs;\n    }\n    friend Vec operator*(const T& rhs, const Vec& lhs)\
    \ {\n        return Vec(lhs) *= rhs;\n    }\n    friend Vec operator/(const Vec&\
    \ lhs, const T& rhs) {\n        return Vec(lhs) /= rhs;\n    }\n    friend Vec\
    \ operator/(const T& rhs, const Vec& lhs) {\n        return Vec(lhs) /= rhs;\n\
    \    }\n    ld norm(){\n        return sqrtl(ld(x*x+y*y));\n    }\n    T norm2(){\n\
    \        return x*x+y*y;\n    }\n};\n\ntemplate<typename T>\nT dot(const Vec<T>\
    \ &a, const Vec<T> &b){\n    return a.x * b.x + a.y * b.y;\n}\n\n// cross > 0\
    \ : counter clockwise a -> b\ntemplate<typename T>\nT cross(const Vec<T> &a, const\
    \ Vec<T> &b){\n    return a.x * b.y - a.y * b.x;\n}\n\n// e : vec(OX)\n// orthant\
    \ k : [ pi/2 * k, pi/2 * (k+1) ) rad\n// orthant 4 is NOT expected\ntemplate<typename\
    \ T>\nint orthant(const Vec<T> &e, const Vec<T> &p){\n    T _dot = dot(e,p), _cross\
    \ = cross(e,p);\n    if (_dot >  0 && _cross >= 0) return 0;\n    if (_dot <=\
    \ 0 && _cross >  0) return 1;\n    if (_dot <  0 && _cross <= 0) return 2;\n \
    \   if (_dot >= 0 && _cross <  0) return 3;\n    return 4;\n}\n\n// usage : \n\
    //   vector<Vec<ll>> vec;\n//   sort(vec.begin(),vec.end(),comp_for_argument_sort<ll>);\n\
    template<typename T>\nbool comp_for_argument_sort(const Vec<T> &lhs, const Vec<T>\
    \ &rhs){\n    int pl = orthant(Vec<T>(1,0),lhs), pr = orthant(Vec<T>(1,0),rhs);\n\
    \    if (pl == pr){\n        return cross(lhs,rhs) > 0;\n    }\n    return pl\
    \ < pr;\n}\n\n// DISTINCT points are given\n// ans[0] --- ans[1] --- ... --- ans[k-1]\
    \ --- ans[k] --- ans[0]\n// upper_hull --- lower_hull\n// upper_hull : x is from\
    \ small to large\n// lower hull : x is from large to small\n// points rearranged\
    \ clockwise\ntemplate<typename T>\nvector<Vec<T>> convex_hull(vector<Vec<T>> a){\n\
    \    int n = a.size();\n    if (n <= 2) return a;\n    using vec = Vec<T>;\n \
    \   auto comp = [&](vec lhs, vec rhs){\n        if (lhs.x == rhs.x) return lhs.y\
    \ < rhs.y;\n        return lhs.x < rhs.x;\n    };\n    sort(all(a),comp);\n  \
    \  stack<int> uid, did;\n    uid.push(0);\n    vec ri = a[n-1];\n    rep(i,1,n-1)\
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
    }\n\n} // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: geometry/geometry2D.hpp
  requiredBy: []
  timestamp: '2023-04-23 15:50:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry2D.hpp
layout: document
redirect_from:
- /library/geometry/geometry2D.hpp
- /library/geometry/geometry2D.hpp.html
title: geometry/geometry2D.hpp
---
