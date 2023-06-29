---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_ld.hpp
    title: base_ld
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/Convex_Hull.test.cpp
    title: test/geometry/Convex_Hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/convex_hull.hpp\"\n\n#line 2 \"geometry/base_ld.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
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
    \ 0, ids.size()) ans[i] = a[ids[i]];\n    return ans;\n}\n\n}  // namespace lib\n"
  code: "#pragma once\n\n#include \"../geometry/base_ld.hpp\"\n#include \"../template/template.hpp\"\
    \n\nnamespace lib {\n\nvector<vec> convex_hull(vector<vec> a) {\n    int n = a.size();\n\
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
    \ 0, ids.size()) ans[i] = a[ids[i]];\n    return ans;\n}\n\n}  // namespace lib"
  dependsOn:
  - geometry/base_ld.hpp
  - template/template.hpp
  isVerificationFile: false
  path: geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2023-06-08 15:34:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/Convex_Hull.test.cpp
documentation_of: geometry/convex_hull.hpp
layout: document
title: convex_hull
---

## 説明

`base_ld` を基礎とした凸包ライブラリ。

`vector<vec> convex_hull(vector<vec> a)`

**重複のない** `vec` の配列 `a` に対し、それらの点が成す凸包の頂点を反時計回りに返す。(重複があってもうまく動き得るが、保証しない)

凸包が $N$ 点からなるとき、長さ $N$ の `vector` が返される。

## 使用例

```cpp
int main(){
    int n; cin >> n;
    vector<vec> a(n);
    rep(i,0,n){
        ld x, y; cin >> x >> y;
        a[i] = vec(x,y);
    }
    auto hull = convex_hull(a);
    for (vec v : hull){
        cout << v << endl;
    }
}
```

### 入力例
```
6
0 0
2 0
1 1
2 1
3 1
2 2
```

### 出力例
```
0 0
2 0
3 1
2 2
```

この出力例は正確ではなく、本当は `(0.00000,0.00000)` などと出力される。 