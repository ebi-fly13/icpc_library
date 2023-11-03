---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt4.hpp
    title: convolution/ntt4.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/convolution/Convolution_mod_ntt4.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 2 \"\
    convolution/ntt4.hpp\"\n\n#line 2 \"utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\
    \n\nnamespace lib {\n\ntemplate <ll m> struct modint {\n    using mint = modint;\n\
    \    ll a;\n\n    modint(ll x = 0) : a((x % m + m) % m) {}\n    static constexpr\
    \ ll mod() {\n        return m;\n    }\n    ll& val() {\n        return a;\n \
    \   }\n    mint pow(ll n) {\n        mint res = 1;\n        mint x = a;\n    \
    \    while (n) {\n            if (n & 1) res *= x;\n            x *= x;\n    \
    \        n >>= 1;\n        }\n        return res;\n    }\n    mint inv() {\n \
    \       return pow(m - 2);\n    }\n    mint& operator+=(const mint rhs) {\n  \
    \      a += rhs.a;\n        if (a >= m) a -= m;\n        return *this;\n    }\n\
    \    mint& operator-=(const mint rhs) {\n        if (a < rhs.a) a += m;\n    \
    \    a -= rhs.a;\n        return *this;\n    }\n    mint& operator*=(const mint\
    \ rhs) {\n        a = a * rhs.a % m;\n        return *this;\n    }\n    mint&\
    \ operator/=(mint rhs) {\n        *this *= rhs.inv();\n        return *this;\n\
    \    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    mint operator+() const {\n        return\
    \ *this;\n    }\n    mint operator-() const {\n        return mint() - *this;\n\
    \    }\n};\n\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n\n}  // namespace lib\n#line 4 \"convolution/ntt4.hpp\"\
    \n\nnamespace lib {\n\n// only for modint998244353\ntemplate<typename mint>\n\
    struct NTT {\n    using uint = unsigned int;\n    static constexpr uint mod =\
    \ mint::mod();\n    static constexpr ull mod2 = (ull)mod * mod;\n    static constexpr\
    \ uint pr  = 3; // for modint998244353\n    static constexpr int level = 23; //\
    \ for modint998244353\n    array<mint,level+1> wp, wm;\n    void set_ws(){\n \
    \       mint r = mint(pr).pow((mod-1) >> level);\n        wp[level] = r, wm[level]\
    \ = r.inv();\n        for (int i = level-1; i >= 0; i--){\n            wp[i] =\
    \ wp[i+1] * wp[i+1];\n            wm[i] = wm[i+1] * wm[i+1];\n        }\n    }\n\
    \    NTT () { set_ws(); }\n    void fft4(vector<mint> &a, int k){\n        uint\
    \ im = wm[2].val();\n        uint n = 1<<k;\n        uint len = n;\n        int\
    \ l = k;\n        while (len > 1){\n            if (l == 1){\n               \
    \ for (int i = 0; i < (1<<(k-1)); i++){\n                    a[i*2+0] += a[i*2+1];\n\
    \                    a[i*2+1]  = a[i*2+0] - a[i*2+1] * 2;\n                }\n\
    \                len >>= 1;\n                l -= 1;\n            }\n        \
    \    else {\n                int len4 = len/4;\n                int nlen = n/len;\n\
    \                ull r1 = 1, r2 = 1, r3 = 1, imr1 = im, imr3 = im;\n         \
    \       for (int i = 0; i < len4; i++){\n                    for (int j = 0; j\
    \ < nlen; j++){\n                        uint a0 = a[len4*0+i + len*j].val();\n\
    \                        uint a1 = a[len4*1+i + len*j].val();\n              \
    \          uint a2 = a[len4*2+i + len*j].val();\n                        uint\
    \ a3 = a[len4*3+i + len*j].val();\n                        uint a0p2 = a0 + a2;\n\
    \                        uint a1p3 = a1 + a3;\n                        ull b0m2\
    \ = (a0 + mod - a2) * r1;\n                        ull b1m3 = (a1 + mod - a3)\
    \ * imr1;\n                        ull c0m2 = (a0 + mod - a2) * r3;\n        \
    \                ull c1m3 = (a1 + mod - a3) * imr3;\n                        a[len4*0+i\
    \ + len*j] = a0p2 + a1p3;\n                        a[len4*1+i + len*j] = b0m2\
    \ + b1m3;\n                        a[len4*2+i + len*j] = (a0p2 + mod*2 - a1p3)\
    \ * r2;\n                        a[len4*3+i + len*j] = c0m2 + mod2*2 - c1m3;\n\
    \                    }\n                    r1 = r1 * wm[l].val() % mod;\n   \
    \                 r2 = r1 * r1 % mod;\n                    r3 = r1 * r2 % mod;\n\
    \                    imr1 = im * r1 % mod;\n                    imr3 = im * r3\
    \ % mod;\n                }\n                len >>= 2;\n                l -=\
    \ 2;\n            }\n        }\n    }\n    void ifft4(vector<mint> &a, int k){\n\
    \        uint im = wp[2].val();\n        uint n = 1<<k;\n        uint len = (k\
    \ & 1 ? 2 : 4);\n        int l = (k & 1 ? 1 : 2);\n        while (len <= n){\n\
    \            if (l == 1){\n                for (int i = 0; i < (1<<(k-1)); i++){\n\
    \                    a[i*2+0] += a[i*2+1];\n                    a[i*2+1]  = a[i*2+0]\
    \ - a[i*2+1] * 2;\n                }\n                len <<= 2;\n           \
    \     l += 2;\n            }\n            else {\n                int len4 = len/4;\n\
    \                int nlen = n/len;\n                ull r1 = 1, r2 = 1, r3 = 1,\
    \ imr1 = im, imr3 = im;\n                for (int i = 0; i < len4; i++){\n   \
    \                 for (int j = 0; j < nlen; j++){\n                        ull\
    \ a0 = a[len4*0+i + len*j].val();\n                        ull a1 = a[len4*1+i\
    \ + len*j].val() * r1;\n                        ull a2 = a[len4*2+i + len*j].val()\
    \ * r2;\n                        ull a3 = a[len4*3+i + len*j].val() * r3;\n  \
    \                      ull b1 = a[len4*1+i + len*j].val() * imr1;\n          \
    \              ull b3 = a[len4*3+i + len*j].val() * imr3;\n                  \
    \      ull a0p2 = a0 + a2;\n                        ull a1p3 = a1 + a3;\n    \
    \                    ull a0m2 = a0 + mod2 - a2;\n                        ull b1m3\
    \ = b1 + mod2 - b3;\n                        a[len4*0+i + len*j] = a0p2 + a1p3;\n\
    \                        a[len4*1+i + len*j] = a0m2 + b1m3;\n                \
    \        a[len4*2+i + len*j] = a0p2 + mod2*2 - a1p3;\n                       \
    \ a[len4*3+i + len*j] = a0m2 + mod2*2 - b1m3;\n                    }\n       \
    \             r1 = r1 * wp[l].val() % mod;\n                    r2 = r1 * r1 %\
    \ mod;\n                    r3 = r1 * r2 % mod;\n                    imr1 = im\
    \ * r1 % mod;\n                    imr3 = im * r3 % mod;\n                }\n\
    \                len <<= 2;\n                l += 2;\n            }\n        }\n\
    \    }\n    vector<mint> multiply(const vector<mint> &a, const vector<mint> &b){\n\
    \        if (a.empty() || b.empty()) return {};\n        int l = a.size() + b.size()\
    \ - 1;\n        if (min<int>(a.size(), b.size()) <= 40){\n            vector<mint>\
    \ s(l);\n            rep(i,0,a.size()) rep(j,0,b.size()) s[i+j] += a[i]*b[j];\n\
    \            return s;\n        }\n        int k = 2, M = 4;\n        while (M\
    \ < l) M <<= 1, ++k;\n        vector<mint> s(M), t(M);\n        rep(i,0,a.size())\
    \ s[i] = a[i];\n        rep(i,0,b.size()) t[i] = b[i];\n        fft4(s,k);\n \
    \       fft4(t,k);\n        rep(i,0,M) s[i] *= t[i];\n        ifft4(s, k);\n \
    \       s.resize(l);\n        mint invm = mint(M).inv();\n        rep(i,0,l) s[i]\
    \ *= invm;\n        return s;\n    }\n};\n\n} // namespace lib\n#line 5 \"test/convolution/Convolution_mod_ntt4.test.cpp\"\
    \n\nusing namespace lib;\nusing mint = modint998244353;\n\nint main(){\n    int\
    \ n, m; cin >> n >> m;\n    vector<mint> a(n), b(m);\n    rep(i,0,n){\n      \
    \  int x; cin >> x;\n        a[i] = x;\n    }\n    rep(j,0,m){\n        int y;\
    \ cin >> y;\n        b[j] = y;\n    }\n    NTT<mint> ntt;\n    auto ab = ntt.multiply(a,b);\n\
    \    rep(i,0,ab.size()){\n        cout << ab[i].val() << \" \\n\"[i+1 == (int)(ab.size())];\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\"\
    ../../template/template.hpp\"\n#include\"../../convolution/ntt4.hpp\"\n\nusing\
    \ namespace lib;\nusing mint = modint998244353;\n\nint main(){\n    int n, m;\
    \ cin >> n >> m;\n    vector<mint> a(n), b(m);\n    rep(i,0,n){\n        int x;\
    \ cin >> x;\n        a[i] = x;\n    }\n    rep(j,0,m){\n        int y; cin >>\
    \ y;\n        b[j] = y;\n    }\n    NTT<mint> ntt;\n    auto ab = ntt.multiply(a,b);\n\
    \    rep(i,0,ab.size()){\n        cout << ab[i].val() << \" \\n\"[i+1 == (int)(ab.size())];\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - convolution/ntt4.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/convolution/Convolution_mod_ntt4.test.cpp
  requiredBy: []
  timestamp: '2023-11-03 23:34:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Convolution_mod_ntt4.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Convolution_mod_ntt4.test.cpp
- /verify/test/convolution/Convolution_mod_ntt4.test.cpp.html
title: test/convolution/Convolution_mod_ntt4.test.cpp
---
