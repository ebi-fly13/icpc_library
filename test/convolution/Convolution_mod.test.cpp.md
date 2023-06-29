---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT convolution
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
  bundledCode: "#line 1 \"test/convolution/Convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 2 \"convolution/ntt.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ s, n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 2 \"utility/modint.hpp\"\n\n#line 4 \"utility/modint.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate <ll m> struct modint {\n    using mint = modint;\n    ll a;\n\
    \n    modint(ll x = 0) : a((x % m + m) % m) {}\n    static ll mod() {\n      \
    \  return m;\n    }\n    ll& val() {\n        return a;\n    }\n    mint pow(ll\
    \ n) {\n        mint res = 1;\n        mint x = a;\n        while (n) {\n    \
    \        if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n   \
    \     }\n        return res;\n    }\n    mint inv() {\n        return pow(m -\
    \ 2);\n    }\n    mint& operator+=(const mint rhs) {\n        a += rhs.a;\n  \
    \      if (a >= m) a -= m;\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint rhs) {\n        if (a < rhs.a) a += m;\n        a -= rhs.a;\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint rhs) {\n        a = a * rhs.a\
    \ % m;\n        return *this;\n    }\n    mint& operator/=(mint rhs) {\n     \
    \   *this *= rhs.inv();\n        return *this;\n    }\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n   \
    \ friend mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ mint operator+() const {\n        return *this;\n    }\n    mint operator-()\
    \ const {\n        return mint() - *this;\n    }\n};\n\nusing modint998244353\
    \ = modint<998244353>;\nusing modint1000000007 = modint<1'000'000'007>;\n\n} \
    \ // namespace lib\n#line 5 \"convolution/ntt.hpp\"\n\nnamespace lib {\n\nusing\
    \ mint = modint998244353;\n\nstruct ntt_info {\n    static constexpr int rank2\
    \ = 23;\n    const int g = 3;\n    std::array<std::array<mint, rank2 + 1>, 2>\
    \ root;\n\n    ntt_info() {\n        root[0][rank2] = mint(g).pow((mint::mod()\
    \ - 1) >> rank2);\n        root[1][rank2] = root[0][rank2].inv();\n        rrep(i,\
    \ 0, rank2) {\n            root[0][i] = root[0][i + 1] * root[0][i + 1];\n   \
    \         root[1][i] = root[1][i + 1] * root[1][i + 1];\n        }\n    }\n};\n\
    \nint bit_reverse(int n, int bit_size) {\n    int rev = 0;\n    rep(i, 0, bit_size)\
    \ {\n        rev |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return rev;\n\
    }\n\nvoid butterfly(std::vector<mint>& a, bool inverse) {\n    static ntt_info\
    \ info;\n    int n = a.size();\n    int bit_size = 0;\n    while ((1 << bit_size)\
    \ < n) bit_size++;\n    assert(1 << bit_size == n);\n    rep(i, 0, n) {\n    \
    \    int rev = bit_reverse(i, bit_size);\n        if (i < rev) {\n           \
    \ std::swap(a[i], a[rev]);\n        }\n    }\n    rep(bit, 0, bit_size) {\n  \
    \      rep(i, 0, n / (1 << (bit + 1))) {\n            mint zeta1 = 1;\n      \
    \      mint zeta2 = info.root[inverse][1];\n            mint w = info.root[inverse][bit\
    \ + 1];\n            rep(j, 0, 1 << bit) {\n                int idx = i * (1 <<\
    \ (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n             \
    \   mint p1 = a[idx];\n                mint p2 = a[jdx];\n                a[idx]\
    \ = p1 + zeta1 * p2;\n                a[jdx] = p1 + zeta2 * p2;\n            \
    \    zeta1 *= w;\n                zeta2 *= w;\n            }\n        }\n    }\n\
    \    if (inverse) {\n        mint inv_n = mint(n).inv();\n        rep(i, 0, n)\
    \ a[i] *= inv_n;\n    }\n}\n\nstd::vector<mint> convolution(const std::vector<mint>&\
    \ f,\n                              const std::vector<mint>& g) {\n    int n =\
    \ 1;\n    while (n < int(f.size() + g.size() - 1)) n <<= 1;\n    std::vector<mint>\
    \ a(n), b(n);\n    std::copy(f.begin(), f.end(), a.begin());\n    std::copy(g.begin(),\
    \ g.end(), b.begin());\n    butterfly(a, false);\n    butterfly(b, false);\n \
    \   rep(i, 0, n) {\n        a[i] *= b[i];\n    }\n    butterfly(a, true);\n  \
    \  a.resize(f.size() + g.size() - 1);\n    return a;\n}\n\n}  // namespace lib\n\
    #line 6 \"test/convolution/Convolution_mod.test.cpp\"\n\nusing mint = lib::modint998244353;\n\
    \nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint>\
    \ a(n), b(m);\n    rep(i, 0, n) {\n        int x;\n        std::cin >> x;\n  \
    \      a[i] = x;\n    }\n    rep(i, 0, m) {\n        int x;\n        std::cin\
    \ >> x;\n        b[i] = x;\n    }\n    auto c = lib::convolution(a, b);\n    rep(i,\
    \ 0, c.size()) {\n        std::cout << c[i].val() << \" \\n\"[i == int(c.size())\
    \ - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../convolution/ntt.hpp\"\n#include \"../../template/template.hpp\"\n#include\
    \ \"../../utility/modint.hpp\"\n\nusing mint = lib::modint998244353;\n\nint main()\
    \ {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint> a(n), b(m);\n\
    \    rep(i, 0, n) {\n        int x;\n        std::cin >> x;\n        a[i] = x;\n\
    \    }\n    rep(i, 0, m) {\n        int x;\n        std::cin >> x;\n        b[i]\
    \ = x;\n    }\n    auto c = lib::convolution(a, b);\n    rep(i, 0, c.size()) {\n\
    \        std::cout << c[i].val() << \" \\n\"[i == int(c.size()) - 1];\n    }\n\
    }"
  dependsOn:
  - convolution/ntt.hpp
  - template/template.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/convolution/Convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Convolution_mod.test.cpp
- /verify/test/convolution/Convolution_mod.test.cpp.html
title: test/convolution/Convolution_mod.test.cpp
---
