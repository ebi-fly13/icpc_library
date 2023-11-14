---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/factorial.hpp
    title: misc/factorial.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: utility/dynamic_modint.hpp
    title: utility/dynamic_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/misc/Binomial_Coefficient.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#define rep(i, s,\
    \ n) for (int i = (int)(s); i < (int)(n); i++)\n#define rrep(i, s, n) for (int\
    \ i = (int)(n)-1; i >= (int)(s); i--)\n#define all(v) v.begin(), v.end()\n\nusing\
    \ ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\n\
    template <typename T> bool chmin(T &a, const T &b) {\n    if (a <= b) return false;\n\
    \    a = b;\n    return true;\n}\ntemplate <typename T> bool chmax(T &a, const\
    \ T &b) {\n    if (a >= b) return false;\n    a = b;\n    return true;\n}\n\n\
    namespace lib {\n\nusing namespace std;\n\n}  // namespace lib\n\n// using namespace\
    \ lib;\n#line 4 \"test/misc/Binomial_Coefficient.test.cpp\"\n\n#line 2 \"utility/dynamic_modint.hpp\"\
    \n\n#line 4 \"utility/dynamic_modint.hpp\"\n\nnamespace lib {\n\ntemplate <int\
    \ id> struct dynamic_modint {\n    using mint = dynamic_modint;\n    ll a;\n \
    \   static ll m;\n    dynamic_modint (ll x = 0) : a((x % m + m) % m) {}\n    static\
    \ ll mod() {\n        return m;\n    }\n    static void set_mod(ll mod){\n   \
    \     assert(1 <= mod);\n        m = mod;\n    }\n    ll& val() {\n        return\
    \ a;\n    }\n    mint pow(ll n) {\n        mint res = 1;\n        mint x = a;\n\
    \        while (n) {\n            if (n & 1) res *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n    mint inv() {\n\
    \        return pow(m - 2);\n    }\n    mint& operator+=(const mint rhs) {\n \
    \       a += rhs.a;\n        if (a >= m) a -= m;\n        return *this;\n    }\n\
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
    \    }\n};\n\ntemplate<int id>\nll dynamic_modint<id>::m = 2;\n\n} // namespace\
    \ lib\n#line 2 \"misc/factorial.hpp\"\n\n#line 4 \"misc/factorial.hpp\"\n\nnamespace\
    \ lib {\n\ntemplate<typename T>\nstruct Binom{\n    Binom(int lim = 300000){\n\
    \        if (kaijo.empty()){\n            kaijo = {1,1};\n            kainv =\
    \ {1,1};\n        }\n        kaijo.resize(lim+1), kainv.resize(lim+1);\n     \
    \   for (int i = 2; i <= lim; i++) kaijo[i] = kaijo[i-1] * T(i);\n        kainv[lim]\
    \ = kaijo[lim].inv();\n        for (int i = lim-1; i >= 2; i--) kainv[i] = kainv[i+1]\
    \ * T(i+1);\n    }\n    static T fact(int x) {\n        if (x < 0) return T(0);\n\
    \        return kaijo[x];\n    }\n    static T ifact(int x){\n        if (x <\
    \ 0) return T(0);\n        return kainv[x];\n    }\n    static T C(int n, int\
    \ r){\n        if (n < 0 || n < r || r < 0) return T(0);\n        return kaijo[n]\
    \ * kainv[r] * kainv[n-r];\n    }\n    static T P(int n, int r){\n        if (n\
    \ < 0 || n < r || r < 0) return T(0);\n        return kaijo[n] * kainv[n-r];\n\
    \    }\n    static T Inv(int n){\n        assert(0 < n);\n        return ifact(n)\
    \ * fact(n-1);\n    }\n    T operator()(int n, int r){ return C(n,r); }\n  private:\n\
    \    static vector<T> kaijo, kainv;\n};\ntemplate<typename T>\nvector<T>Binom<T>::kaijo\
    \ = vector<T>(2,T(1));\ntemplate<typename T>\nvector<T>Binom<T>::kainv = vector<T>(2,T(1));\n\
    \n} // namespace lib\n#line 7 \"test/misc/Binomial_Coefficient.test.cpp\"\n\n\
    using namespace lib;\n\nusing mint = dynamic_modint<-1>;\nconst int mx = 10'000'000;\n\
    \nint main(){\n    int t, m; cin >> t >> m;\n    mint::set_mod(m);\n    Binom<mint>\
    \ bnm(min(m-1,mx));\n    while (t--){\n        int n, k; cin >> n >> k;\n    \
    \    cout << bnm(n,k).val() << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include\"../../template/template.hpp\"\n\n#include\"../../utility/dynamic_modint.hpp\"\
    \n#include\"../../misc/factorial.hpp\"\n\nusing namespace lib;\n\nusing mint =\
    \ dynamic_modint<-1>;\nconst int mx = 10'000'000;\n\nint main(){\n    int t, m;\
    \ cin >> t >> m;\n    mint::set_mod(m);\n    Binom<mint> bnm(min(m-1,mx));\n \
    \   while (t--){\n        int n, k; cin >> n >> k;\n        cout << bnm(n,k).val()\
    \ << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - utility/dynamic_modint.hpp
  - misc/factorial.hpp
  isVerificationFile: true
  path: test/misc/Binomial_Coefficient.test.cpp
  requiredBy: []
  timestamp: '2023-06-10 00:47:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/Binomial_Coefficient.test.cpp
layout: document
redirect_from:
- /verify/test/misc/Binomial_Coefficient.test.cpp
- /verify/test/misc/Binomial_Coefficient.test.cpp.html
title: test/misc/Binomial_Coefficient.test.cpp
---
