---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry3D/accurate/base_accurate.hpp
    title: geometry3D/accurate/base_accurate.hpp
  - icon: ':x:'
    path: geometry3D/accurate/line.hpp
    title: geometry3D/accurate/line.hpp
  - icon: ':x:'
    path: geometry3D/base_arbitary.hpp
    title: geometry3D/base_arbitary.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: utility/rational.hpp
    title: utility/rational.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc301/tasks/abc301_g
    links:
    - https://atcoder.jp/contests/abc301/tasks/abc301_g
  bundledCode: "#line 1 \"test/geometry3D/Worst_Picture.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc301/tasks/abc301_g\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate <typename T> bool chmin(T &a, const\
    \ T &b) {\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate\
    \ <typename T> bool chmax(T &a, const T &b) {\n    if (a >= b) return false;\n\
    \    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing namespace std;\n\n\
    }  // namespace lib\n\n// using namespace lib;\n#line 2 \"geometry3D/accurate/line.hpp\"\
    \n\n#line 2 \"geometry3D/accurate/base_accurate.hpp\"\n\n#line 2 \"geometry3D/base_arbitary.hpp\"\
    \n\n#line 4 \"geometry3D/base_arbitary.hpp\"\n\nnamespace lib {\n\ntemplate<typename\
    \ T>\nstruct Vec {\n    T x, y, z;\n    Vec (T _x = 0, T _y = 0, T _z = 0) : x(_x),\
    \ y(_y), z(_z) {}\n    Vec& operator*=(const T& a){\n        x *= a;\n       \
    \ y *= a;\n        z *= a;\n        return *this;\n    }\n    Vec& operator/=(const\
    \ T& a){\n        x /= a;\n        y /= a;\n        z /= a;\n        return *this;\n\
    \    }\n    Vec& operator+=(const Vec& rhs) {\n        x += rhs.x;\n        y\
    \ += rhs.y;\n        z += rhs.z;\n        return *this;\n    }\n    Vec& operator-=(const\
    \ Vec& rhs) {\n        x -= rhs.x;\n        y -= rhs.y;\n        z -= rhs.z;\n\
    \        return *this;\n    }\n    friend Vec operator+(const Vec& lhs, const\
    \ Vec& rhs) {\n        return Vec(lhs) += rhs;\n    }\n    friend Vec operator-(const\
    \ Vec& lhs, const Vec& rhs) {\n        return Vec(lhs) -= rhs;\n    }\n    friend\
    \ Vec operator*(const Vec& lhs, const T& rhs) {\n        return Vec(lhs) *= rhs;\n\
    \    }\n    friend Vec operator*(const T& rhs, const Vec& lhs) {\n        return\
    \ Vec(lhs) *= rhs;\n    }\n    friend Vec operator/(const Vec& lhs, const T& rhs)\
    \ {\n        return Vec(lhs) /= rhs;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os,const Vec&r) {\n        return os << \"(\" << r.x << \",\" << r.y << \"\
    ,\" << r.z << \")\"; \n    }\n};\n\n};\n#line 5 \"geometry3D/accurate/base_accurate.hpp\"\
    \n\nnamespace lib {\n\ntemplate<typename T>\nbool operator==(const Vec<T>& lhs,\
    \ const Vec<T>& rhs) {\n    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z ==\
    \ rhs.z;\n}\n\ntemplate<typename T>\nT dot(const Vec<T> &a, const Vec<T> &b){\n\
    \    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n\ntemplate<typename T>\nVec<T> cross(const\
    \ Vec<T> &a, const Vec<T> &b){\n    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z,\
    \ a.x*b.y-a.y*b.x);\n}\n\ntemplate<typename T>\nT norm(const Vec<T> &a){\n   \
    \ return a.x*a.x+a.y*a.y+a.z*a.z;\n}\n\n}  // namespace lib\n#line 2 \"utility/rational.hpp\"\
    \n\n#line 4 \"utility/rational.hpp\"\n\nnamespace lib {\n\nstruct rational {\n\
    \    rational() : p(0), q(1) {}\n    rational(ll n) : p(n), q(1) {}\n    rational(ll\
    \ n, ll m) {\n        assert(m != 0);\n        if (m < 0) n = -n, m = -m;\n  \
    \      ll g = gcd(n, m);\n        p = n / g;\n        q = m / g;\n    }\n    explicit\
    \ operator const ld () const { return ld(p) / ld(q); }\n    rational& operator+=(const\
    \ rational& rhs){\n        ll g = gcd(q, rhs.q);\n        ll np = rhs.q / g *\
    \ p + q / g * rhs.p;\n        ll nq = q / g * rhs.q;\n        ll ng = gcd(np,\
    \ nq);\n        p = np / ng, q = nq / ng;\n        return *this;\n    }\n    rational&\
    \ operator-=(const rational& rhs) {\n        (*this) += rational(-rhs.p, rhs.q);\n\
    \        return *this;\n    }\n    rational& operator*=(const rational& rhs) {\n\
    \        ll g1 = gcd(q, rhs.p), g2 = gcd(p, rhs.q);\n        ll np = p / g2 *\
    \ rhs.p / g1;\n        ll nq = q / g1 * rhs.q / g2;\n        p = np, q = nq;\n\
    \        return *this;\n    }\n    rational& operator/=(const rational& rhs) {\n\
    \        (*this) *= rational(rhs.q, rhs.p);\n        return *this;\n    }\n  \
    \  rational operator+() const {\n        return *this;\n    }\n    rational operator-()\
    \ const {\n        return rational() - *this;\n    }\n    friend rational operator+(const\
    \ rational& lhs, const rational& rhs) {\n        return rational(lhs) += rhs;\n\
    \    }\n    friend rational operator-(const rational& lhs, const rational& rhs)\
    \ {\n        return rational(lhs) -= rhs;\n    }\n    friend rational operator*(const\
    \ rational& lhs, const rational& rhs) {\n        return rational(lhs) *= rhs;\n\
    \    }\n    friend rational operator/(const rational& lhs, const rational& rhs)\
    \ {\n        return rational(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ rational& lhs, const rational& rhs) {\n        return lhs.p == rhs.p && lhs.q\
    \ == rhs.q;\n    }\n    friend bool operator!=(const rational& lhs, const rational&\
    \ rhs) {\n        return lhs.p != rhs.p || lhs.q != rhs.q;\n    }\n    friend\
    \ bool operator<(const rational lhs, const rational rhs) {\n        return less_than(lhs,\
    \ rhs);\n    }\n    friend bool operator>(const rational lhs, const rational rhs)\
    \ {\n        return less_than(rhs, lhs);\n    }\n    friend bool operator<=(const\
    \ rational lhs, const rational rhs) {\n        return lhs == rhs || lhs < rhs;\n\
    \    }\n    friend bool operator>=(const rational lhs, const rational rhs) {\n\
    \        return lhs == rhs || lhs > rhs;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const rational& r) {\n        return os << r.p << \" / \" << r.q;\n    }\n\
    \n  private:\n    ll p, q;\n    static bool less_than(rational lhs, rational rhs)\
    \ {\n        __int128_t lv = __int128_t(lhs.p) * __int128_t(rhs.q);\n        __int128_t\
    \ rv = __int128_t(lhs.q) * __int128_t(rhs.p);\n        return lv < rv;\n    }\n\
    };\n\n}  // namespace lib\n#line 5 \"geometry3D/accurate/line.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate<typename T>\nstruct Line {\n    Vec<T> a, b;\n};\n\nint intersection(const\
    \ Line<rational> &p, const Line<rational> &q){\n    // cross_point = alpha * p.a\
    \ + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a\n    // alpha * vp + beta *\
    \ vq = vr\n    using vec = Vec<rational>;\n    vec vp = p.a - p.b, vq = q.a -\
    \ q.b, vr = q.a - p.b;\n    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq =\
    \ cross(vr,vq);\n    // yz projection\n    if (cpq.x != 0){\n        rational\
    \ alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;\n        // cross\n        if (alpha\
    \ * vp.x + beta * vq.x - vr.x == 0){\n            return 0;\n        }\n     \
    \   // nejire\n        return 1;\n    }\n    // zx projection\n    if (cpq.y !=\
    \ 0){\n        rational alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;\n       \
    \ // cross\n        if (alpha * vp.y + beta * vq.y - vr.y == 0){\n           \
    \ return 0;\n        }\n        // nejire\n        return 1;\n    }\n    // xy\
    \ projection\n    if (cpq.z != 0){\n        rational alpha = crq.z / cpq.z, beta\
    \ = cpr.z / cpq.z;\n        // cross\n        if (alpha * vp.z + beta * vq.z -\
    \ vr.z == 0){\n            return 0;\n        }\n        // nejire\n        return\
    \ 1;\n    }\n    // cpq == 0  ->  parallel\n    // same\n    if (cross(p.a - q.a,\
    \ p.b - q.a) == vec(0,0,0)){\n        return 3;\n    }\n    // not same\n    return\
    \ 2;\n}\n\nVec<rational> cross_point(const Line<rational> &p, const Line<rational>\
    \ &q){\n    assert(intersection(p,q) == 0);\n    // cross_point = alpha * p.a\
    \ + (1-alpha) * p.b = beta * q.b + (1-beta) * q.a\n    // alpha * vp + beta *\
    \ vq = vr\n    using vec = Vec<rational>;\n    vec vp = p.a - p.b, vq = q.a -\
    \ q.b, vr = q.a - p.b;\n    vec cpq = cross(vp,vq), cpr = cross(vp,vr), crq =\
    \ cross(vr,vq);\n    auto res = [&](rational alpha){\n        return alpha * p.a\
    \ + (1-alpha) * p.b;\n    };\n    // yz projection\n    if (cpq.x != 0){\n   \
    \     rational alpha = crq.x / cpq.x, beta = cpr.x / cpq.x;\n        // cross\n\
    \        if (alpha * vp.x + beta * vq.x - vr.x == 0){\n            return res(alpha);\n\
    \        }\n    }\n    // zx projection\n    if (cpq.y != 0){\n        rational\
    \ alpha = crq.y / cpq.y, beta = cpr.y / cpq.y;\n        // cross\n        if (alpha\
    \ * vp.y + beta * vq.y - vr.y == 0){\n            return res(alpha);\n       \
    \ }\n    }\n    // xy projection\n    if (cpq.z != 0){\n        rational alpha\
    \ = crq.z / cpq.z, beta = cpr.z / cpq.z;\n        // cross\n        if (alpha\
    \ * vp.z + beta * vq.z - vr.z == 0){\n            return res(alpha);\n       \
    \ }\n    }\n    // NOT expected\n    return vec();\n}\n\n\n}  // namespace lib\n\
    #line 5 \"test/geometry3D/Worst_Picture.test.cpp\"\n\nusing namespace lib;\nusing\
    \ rat = rational;\nusing vec = Vec<rat>;\nusing line = Line<rat>;\n\nbool same_line(const\
    \ line &a, const line &b){\n    return intersection(a,b) == 3;\n}\n\nint popc(ull\
    \ n){\n    return __builtin_popcountll(n);\n}\n\nint main(){\n    int n; cin >>\
    \ n;\n    vector<vec> a(n);\n    rep(i,0,n){\n        ll x, y, z; cin >> x >>\
    \ y >> z;\n        a[i] = vec(x,y,z);\n    }\n    bool (*comp)(vec, vec) = [](vec\
    \ lhs, vec rhs){\n        if (lhs.x == rhs.x){\n            if (lhs.y == rhs.y){\n\
    \                return lhs.z < rhs.z;\n            }\n            return lhs.y\
    \ < rhs.y;\n        }\n        return lhs.x < rhs.x;\n    };\n    set<vec, bool\
    \ (*)(vec lhs, vec rhs)> lines(comp);\n    vector<line> ls;\n    rep(i,0,n-1)\
    \ rep(j,i+1,n){\n        if (a[i].x == a[j].x) continue;\n        line cur({a[i],a[j]});\n\
    \        vec x0 = cur.a + (cur.b - cur.a) * cur.a.x / (cur.a.x - cur.b.x);\n \
    \       if (lines.find(x0) == lines.end()){\n            lines.insert(x0);\n \
    \           ls.emplace_back(cur);\n        }\n    }\n    int siz = ls.size();\n\
    \    if (siz == 0){\n        cout << n << endl;\n        return 0;\n    }\n  \
    \  if (siz == 1){\n        cout << 1 << endl;\n        return 0;\n    }\n    vector<ull>\
    \ cnt(siz,0);\n    rep(i,0,siz){\n        rep(j,0,n){\n            if (cross(ls[i].a\
    \ - a[j], ls[i].b - a[j]) == vec(0,0,0)) cnt[i] |= (1LL<<j);\n        }\n    \
    \    rep(j,0,n){\n            if (cnt[i] >> j & 1){\n                cnt[i] ^=\
    \ (1LL<<j);\n                break;\n            }\n        }\n    }\n \n    int\
    \ ans = n;\n    map<vec, ull, bool (*)(vec lhs, vec rhs)> mp(comp);\n    rep(i,0,ls.size()){\n\
    \        rep(j,i+1,ls.size()){\n            if (intersection(ls[i],ls[j]) == 0){\n\
    \                vec p = cross_point(ls[i],ls[j]);\n                if (p.x <\
    \ 0){\n                    mp[p] |= (cnt[i] | cnt[j]);\n                }\n  \
    \          }\n        }\n        chmin(ans,n-popc(cnt[i]));\n    }\n    for (auto\
    \ vi : mp) chmin(ans,n-popc(vi.second));\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc301/tasks/abc301_g\"\n\n\
    #include\"../../template/template.hpp\"\n#include\"../../geometry3D/accurate/line.hpp\"\
    \n\nusing namespace lib;\nusing rat = rational;\nusing vec = Vec<rat>;\nusing\
    \ line = Line<rat>;\n\nbool same_line(const line &a, const line &b){\n    return\
    \ intersection(a,b) == 3;\n}\n\nint popc(ull n){\n    return __builtin_popcountll(n);\n\
    }\n\nint main(){\n    int n; cin >> n;\n    vector<vec> a(n);\n    rep(i,0,n){\n\
    \        ll x, y, z; cin >> x >> y >> z;\n        a[i] = vec(x,y,z);\n    }\n\
    \    bool (*comp)(vec, vec) = [](vec lhs, vec rhs){\n        if (lhs.x == rhs.x){\n\
    \            if (lhs.y == rhs.y){\n                return lhs.z < rhs.z;\n   \
    \         }\n            return lhs.y < rhs.y;\n        }\n        return lhs.x\
    \ < rhs.x;\n    };\n    set<vec, bool (*)(vec lhs, vec rhs)> lines(comp);\n  \
    \  vector<line> ls;\n    rep(i,0,n-1) rep(j,i+1,n){\n        if (a[i].x == a[j].x)\
    \ continue;\n        line cur({a[i],a[j]});\n        vec x0 = cur.a + (cur.b -\
    \ cur.a) * cur.a.x / (cur.a.x - cur.b.x);\n        if (lines.find(x0) == lines.end()){\n\
    \            lines.insert(x0);\n            ls.emplace_back(cur);\n        }\n\
    \    }\n    int siz = ls.size();\n    if (siz == 0){\n        cout << n << endl;\n\
    \        return 0;\n    }\n    if (siz == 1){\n        cout << 1 << endl;\n  \
    \      return 0;\n    }\n    vector<ull> cnt(siz,0);\n    rep(i,0,siz){\n    \
    \    rep(j,0,n){\n            if (cross(ls[i].a - a[j], ls[i].b - a[j]) == vec(0,0,0))\
    \ cnt[i] |= (1LL<<j);\n        }\n        rep(j,0,n){\n            if (cnt[i]\
    \ >> j & 1){\n                cnt[i] ^= (1LL<<j);\n                break;\n  \
    \          }\n        }\n    }\n \n    int ans = n;\n    map<vec, ull, bool (*)(vec\
    \ lhs, vec rhs)> mp(comp);\n    rep(i,0,ls.size()){\n        rep(j,i+1,ls.size()){\n\
    \            if (intersection(ls[i],ls[j]) == 0){\n                vec p = cross_point(ls[i],ls[j]);\n\
    \                if (p.x < 0){\n                    mp[p] |= (cnt[i] | cnt[j]);\n\
    \                }\n            }\n        }\n        chmin(ans,n-popc(cnt[i]));\n\
    \    }\n    for (auto vi : mp) chmin(ans,n-popc(vi.second));\n    cout << ans\
    \ << endl;\n}"
  dependsOn:
  - template/template.hpp
  - geometry3D/accurate/line.hpp
  - geometry3D/accurate/base_accurate.hpp
  - geometry3D/base_arbitary.hpp
  - utility/rational.hpp
  isVerificationFile: true
  path: test/geometry3D/Worst_Picture.test.cpp
  requiredBy: []
  timestamp: '2023-05-17 17:41:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/geometry3D/Worst_Picture.test.cpp
layout: document
redirect_from:
- /verify/test/geometry3D/Worst_Picture.test.cpp
- /verify/test/geometry3D/Worst_Picture.test.cpp.html
title: test/geometry3D/Worst_Picture.test.cpp
---
