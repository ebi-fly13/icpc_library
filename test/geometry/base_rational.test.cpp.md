---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/base_arbitary.hpp
    title: geometry/base_arbitary.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: utility/rational.hpp
    title: utility/rational.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1623&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1623&lang=jp
  bundledCode: "#line 1 \"test/geometry/base_rational.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1623&lang=jp\"\n\
    \n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = s; i < (int)(n); i++)\n#define rrep(i, s, n) for (int i =\
    \ (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"utility/rational.hpp\"\n\n#line 4 \"utility/rational.hpp\"\n\
    \nnamespace lib{\n\nstruct rational{\n    rational() : p(0), q(1) {}\n    rational(ll\
    \ n) : p(n), q(1) {}\n    rational(ll n, ll m){\n        assert(m != 0);\n   \
    \     if (m < 0) n = -n, m = -m;\n        ll g = gcd(n,m);\n        p = n / g;\
    \ q = m / g;\n    }\n    ld val(){\n        return ld(p) / ld(q);\n    }\n   \
    \ rational& operator+=(const rational& rhs){\n        ll g = gcd(q,rhs.q);\n \
    \       ll np = rhs.q / g * p + q / g * rhs.p;\n        ll nq = q / g * rhs.q;\n\
    \        ll ng = gcd(np,nq);\n        p = np/ng, q = nq/ng;\n        return *this;\
    \ \n    }\n    rational& operator-=(const rational& rhs){\n        (*this) +=\
    \ rational(-rhs.p,rhs.q);\n        return *this;\n    }\n    rational& operator*=(const\
    \ rational& rhs){\n        ll g1 = gcd(q,rhs.p), g2 = gcd(p,rhs.q);\n        ll\
    \ np = p / g2 * rhs.p / g1;\n        ll nq = q / g1 * rhs.q / g2;\n        p =\
    \ np, q = nq;\n        return *this;\n    }\n    rational& operator/=(const rational&\
    \ rhs){\n        (*this) *= rational(rhs.q,rhs.p);\n        return *this;\n  \
    \  }\n    rational operator+() const {return *this;}\n    rational operator-()\
    \ const {return rational() - *this;}\n    friend rational operator+(const rational&\
    \ lhs, const rational& rhs) {\n        return rational(lhs) += rhs;\n    }\n \
    \   friend rational operator-(const rational& lhs, const rational& rhs) {\n  \
    \      return rational(lhs) -= rhs;\n    }\n    friend rational operator*(const\
    \ rational& lhs, const rational& rhs) {\n        return rational(lhs) *= rhs;\n\
    \    }\n    friend rational operator/(const rational& lhs, const rational& rhs)\
    \ {\n        return rational(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ rational& lhs, const rational& rhs) {\n        return lhs.p == rhs.p && lhs.q\
    \ == rhs.q;\n    }\n    friend bool operator!=(const rational& lhs, const rational&\
    \ rhs) {\n        return lhs.p != rhs.p || lhs.q != rhs.q;\n    }\n    friend\
    \ bool operator< (const rational lhs, const rational rhs) {\n        return less_than(lhs,rhs);\n\
    \    }\n    friend bool operator> (const rational lhs, const rational rhs) {\n\
    \        return less_than(rhs,lhs);\n    }\n    friend bool operator<= (const\
    \ rational lhs, const rational rhs) {\n        return lhs == rhs || lhs < rhs;\n\
    \    }\n    friend bool operator>= (const rational lhs, const rational rhs) {\n\
    \        return lhs == rhs || lhs > rhs;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os,const rational&r) {\n        return os << r.p << \" / \" << r.q;\n    }\n\
    \  private:\n    ll p, q;\n    static bool less_than(rational lhs, rational rhs){\n\
    \        __int128_t lv = __int128_t(lhs.p) * __int128_t(rhs.q);\n        __int128_t\
    \ rv = __int128_t(lhs.q) * __int128_t(rhs.p);\n        return lv < rv;\n    }\n\
    };\n\n\n} // namespace lib\n#line 2 \"geometry/base_arbitary.hpp\"\n\n#line 4\
    \ \"geometry/base_arbitary.hpp\"\n\nnamespace lib {\n\ntemplate<typename T>\n\
    struct Vec {\n    T x, y;\n    Vec (T _x = T(0), T _y = T(0)) : x(_x), y(_y) {}\n\
    \    Vec& operator*=(const T& a){\n        x *= a;\n        y *= a;\n        return\
    \ *this;\n    }\n    Vec& operator/=(const T& a){\n        x /= a;\n        y\
    \ /= a;\n        return *this;\n    }\n    Vec& operator+=(const Vec& rhs) {\n\
    \        x += rhs.x;\n        y += rhs.y;\n        return *this;\n    }\n    Vec&\
    \ operator-=(const Vec& rhs) {\n        x -= rhs.x;\n        y -= rhs.y;\n   \
    \     return *this;\n    }\n    friend bool operator==(const Vec& lhs, const Vec&\
    \ rhs) {\n        return lhs.x == rhs.x && lhs.y == rhs.y;\n    }\n    friend\
    \ bool operator!=(const Vec& lhs, const Vec& rhs) {\n        return lhs.x != rhs.x\
    \ || lhs.y != rhs.y;\n    }\n    friend Vec operator+(const Vec& lhs, const Vec&\
    \ rhs) {\n        return Vec(lhs) += rhs;\n    }\n    friend Vec operator-(const\
    \ Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) -= rhs;\n    }\n    friend\
    \ Vec operator*(const Vec& lhs, const T& rhs) {\n        return Vec(lhs) *= rhs;\n\
    \    }\n    friend Vec operator*(const T& rhs, const Vec& lhs) {\n        return\
    \ Vec(lhs) *= rhs;\n    }\n    friend Vec operator/(const Vec& lhs, const T& rhs)\
    \ {\n        return Vec(lhs) /= rhs;\n    }\n    friend Vec operator/(const T&\
    \ rhs, const Vec& lhs) {\n        return Vec(lhs) /= rhs;\n    }\n};\n\ntemplate<typename\
    \ T>\nT dot(const Vec<T> &a, const Vec<T> &b){\n    return a.x * b.x + a.y * b.y;\n\
    }\n\n// cross > 0 : counter clockwise a -> b\ntemplate<typename T>\nT cross(const\
    \ Vec<T> &a, const Vec<T> &b){\n    return a.x * b.y - a.y * b.x;\n}\n\ntemplate<typename\
    \ T>\nld abs(const Vec<T> &a){\n    return sqrtl(a.x*a.x+a.y*a.y);\n}\n\ntemplate<typename\
    \ T>\nT norm(const Vec<T> &a){\n    return a.x*a.x+a.y*a.y;\n}\n\ntemplate<typename\
    \ T>\nstruct Line {\n    Vec<T> p, q;\n};\n\ntemplate<typename T>\nint intersection(const\
    \ Line<T> &a, const Line<T> &b){\n    if (cross(a.p-a.q,b.p-b.q) == 0){\n    \
    \    if (cross(a.p-b.p,a.q-b.p) == 0) return 2;\n        return 0;\n    }\n  \
    \  return 1;\n}\n\n// intersection == 1 (cross(a.p-a.q,b.p-b.q) != 0)\ntemplate<typename\
    \ T>\nVec<T> cross_point(const Line<T> &a, const Line<T> &b){\n    Vec<T> va =\
    \ a.p-a.q, vb = b.p-b.q;\n    Vec<T> ba = b.p-a.q;\n    T alpha = cross(ba,vb)\
    \ / cross(va,vb);\n    return alpha * a.p + (1 - alpha) * a.q;\n}\n\n\n} // namespace\
    \ lib\n#line 6 \"test/geometry/base_rational.test.cpp\"\n\nusing namespace lib;\n\
    using vec = Vec<rational>;\nusing line = Line<rational>;\n\nconst vector<vector<int>>\
    \ order = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};\n\nint main(){\n\
    \    while (true){\n        vector<vec> ia(3), b(3);\n        rep(i,0,6){\n  \
    \          ll x, y; cin >> x >> y;\n            if (!cin) return 0;\n        \
    \    (i < 3 ? ia[i] : b[i-3]) = vec(x,y);\n        }\n        int ans = 5;\n \
    \       for (auto fid : order) for (auto tid : order) rep(j,0,2){\n          \
    \  auto a = ia;\n            int cur = 0;\n            rep(i,0,3){\n         \
    \       int f = fid[i], t = tid[i];\n                if (a[f] == b[t]) continue;\n\
    \                cur++;\n                int p = (f+1)%3, q = (f+2)%3;\n     \
    \           if (cross(a[p]-a[q],b[t]-a[f]) == 0){\n                    a[f] =\
    \ b[t];\n                    continue;\n                }\n                cur++;\n\
    \                if (j == 1) swap(p,q);\n                line l1({a[p],a[p]+a[f]-b[t]}),\
    \ l2({a[q],a[q]+a[f]-a[p]});\n                if (intersection(l1,l2) == 1){\n\
    \                    a[q] = cross_point(l1,l2);\n                    a[f] = b[t];\n\
    \                }\n                else {\n                    cur = 5;\n   \
    \                 break;\n                }\n            }\n            chmin(ans,cur);\n\
    \        }\n        if (ans == 5) cout << \"Many\" << endl;\n        else cout\
    \ << ans << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1623&lang=jp\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../utility/rational.hpp\"\
    \n#include\"../../geometry/base_arbitary.hpp\"\n\nusing namespace lib;\nusing\
    \ vec = Vec<rational>;\nusing line = Line<rational>;\n\nconst vector<vector<int>>\
    \ order = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};\n\nint main(){\n\
    \    while (true){\n        vector<vec> ia(3), b(3);\n        rep(i,0,6){\n  \
    \          ll x, y; cin >> x >> y;\n            if (!cin) return 0;\n        \
    \    (i < 3 ? ia[i] : b[i-3]) = vec(x,y);\n        }\n        int ans = 5;\n \
    \       for (auto fid : order) for (auto tid : order) rep(j,0,2){\n          \
    \  auto a = ia;\n            int cur = 0;\n            rep(i,0,3){\n         \
    \       int f = fid[i], t = tid[i];\n                if (a[f] == b[t]) continue;\n\
    \                cur++;\n                int p = (f+1)%3, q = (f+2)%3;\n     \
    \           if (cross(a[p]-a[q],b[t]-a[f]) == 0){\n                    a[f] =\
    \ b[t];\n                    continue;\n                }\n                cur++;\n\
    \                if (j == 1) swap(p,q);\n                line l1({a[p],a[p]+a[f]-b[t]}),\
    \ l2({a[q],a[q]+a[f]-a[p]});\n                if (intersection(l1,l2) == 1){\n\
    \                    a[q] = cross_point(l1,l2);\n                    a[f] = b[t];\n\
    \                }\n                else {\n                    cur = 5;\n   \
    \                 break;\n                }\n            }\n            chmin(ans,cur);\n\
    \        }\n        if (ans == 5) cout << \"Many\" << endl;\n        else cout\
    \ << ans << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - utility/rational.hpp
  - geometry/base_arbitary.hpp
  isVerificationFile: true
  path: test/geometry/base_rational.test.cpp
  requiredBy: []
  timestamp: '2023-05-11 16:06:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/base_rational.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/base_rational.test.cpp
- /verify/test/geometry/base_rational.test.cpp.html
title: test/geometry/base_rational.test.cpp
---
