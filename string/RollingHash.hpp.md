---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/RollingHash.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n#line 5 \"template/template.hpp\"\n#define rep(i,s,n)\
    \ for (int i = s; i < (int)(n); i++)\n#define all(v) v.begin(),v.end()\n\ntemplate<typename\
    \ T> bool chmin(T &a, const T &b){\n    if (a <= b) return false;\n    a = b;\n\
    \    return true;\n}\ntemplate<typename T> bool chmax(T &a, const T &b){\n   \
    \ if (a >= b) return false;\n    a = b;\n    return true;\n}\n#line 4 \"string/RollingHash.hpp\"\
    \n\n\nnamespace lib{\n\nusing namespace std;\n\nstruct RollingHash {\n    using\
    \ ull = unsigned long long;\n    RollingHash(const string &s = \"\"){ build(s);}\n\
    \    ull get(int l, int r){\n        assert(0 <= l && l <= r && r <= n);\n   \
    \     return cal(inner_hash[r] + buf - mul(inner_hash[l], pow_base[r-l]));\n \
    \   }\n    static ull get_hash(const string &s){\n        int len = s.size();\n\
    \        set_hash();\n        extend_pow_base(len);\n        ull res = 0;\n  \
    \      rep(i,0,len) res = cal(mul(res,BASE) + s[i]);\n        return res;\n  \
    \  }\n    static ull concat(const ull& hash1, const ull& hash2, const int& len2){\n\
    \        return cal(cal(mul(hash1,pow_base[len2]))+hash2);\n    }\n  private:\n\
    \    static constexpr ull MASK30 = (1ULL << 30) - 1;\n    static constexpr ull\
    \ MASK31 = (1ULL << 31) - 1;\n    static constexpr ull MASK61 = (1ULL << 61) -\
    \ 1;\n    static constexpr ull MOD = (1ULL << 61) - 1;\n    static constexpr ull\
    \ buf = MOD * 4;\n    static ull BASE;\n    static vector<ull> pow_base;\n   \
    \ static ull mul(ull a, ull b){\n        ull au = a >> 31, ad = a & MASK31;\n\
    \        ull bu = b >> 31, bd = b & MASK31;\n        ull mid = ad * bu + au *\
    \ bd;\n        ull midu = mid >> 30, midd = mid & MASK30;\n        return (au\
    \ * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n    static ull cal(ull x){\n\
    \        ull xu = x >> 61;\n        ull xd = x & MASK61;\n        ull res = xu\
    \ + xd;\n        if (res >= MOD) res -= MOD;\n        return res;\n    }\n   \
    \ static void set_hash(){\n        if (BASE == 0) BASE = (1UL<<31) + (random_device()()\
    \ & MASK31);\n    }\n    static void extend_pow_base(int len){\n        int nlen\
    \ = pow_base.size();\n        if (nlen > len) return ;\n        len = 2*nlen;\n\
    \        pow_base.resize(len+1);\n        rep(i,nlen,len+1) pow_base[i] = cal(mul(pow_base[i-1],BASE));\n\
    \    }\n    string str;\n    int n;\n    vector<ull> inner_hash;\n    void build(const\
    \ string &s){\n        set_hash();\n        str = s;\n        n = s.size();\n\
    \        extend_pow_base(n);\n        inner_hash.resize(n+1);\n        inner_hash[0]\
    \ = 0;\n        rep(i,0,n) inner_hash[i+1] = cal(mul(inner_hash[i],BASE) + s[i]);\n\
    \    }\n};\nusing ull = unsigned long long;\null RollingHash::BASE = 0;\nvector<ull>\
    \ RollingHash::pow_base = vector<ull>(1,1);\nusing roriha = RollingHash;\n\n}\
    \ // namespace lib\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\n\nnamespace lib{\n\
    \nusing namespace std;\n\nstruct RollingHash {\n    using ull = unsigned long\
    \ long;\n    RollingHash(const string &s = \"\"){ build(s);}\n    ull get(int\
    \ l, int r){\n        assert(0 <= l && l <= r && r <= n);\n        return cal(inner_hash[r]\
    \ + buf - mul(inner_hash[l], pow_base[r-l]));\n    }\n    static ull get_hash(const\
    \ string &s){\n        int len = s.size();\n        set_hash();\n        extend_pow_base(len);\n\
    \        ull res = 0;\n        rep(i,0,len) res = cal(mul(res,BASE) + s[i]);\n\
    \        return res;\n    }\n    static ull concat(const ull& hash1, const ull&\
    \ hash2, const int& len2){\n        return cal(cal(mul(hash1,pow_base[len2]))+hash2);\n\
    \    }\n  private:\n    static constexpr ull MASK30 = (1ULL << 30) - 1;\n    static\
    \ constexpr ull MASK31 = (1ULL << 31) - 1;\n    static constexpr ull MASK61 =\
    \ (1ULL << 61) - 1;\n    static constexpr ull MOD = (1ULL << 61) - 1;\n    static\
    \ constexpr ull buf = MOD * 4;\n    static ull BASE;\n    static vector<ull> pow_base;\n\
    \    static ull mul(ull a, ull b){\n        ull au = a >> 31, ad = a & MASK31;\n\
    \        ull bu = b >> 31, bd = b & MASK31;\n        ull mid = ad * bu + au *\
    \ bd;\n        ull midu = mid >> 30, midd = mid & MASK30;\n        return (au\
    \ * bu * 2 + midu + (midd << 31) + ad * bd);\n    }\n    static ull cal(ull x){\n\
    \        ull xu = x >> 61;\n        ull xd = x & MASK61;\n        ull res = xu\
    \ + xd;\n        if (res >= MOD) res -= MOD;\n        return res;\n    }\n   \
    \ static void set_hash(){\n        if (BASE == 0) BASE = (1UL<<31) + (random_device()()\
    \ & MASK31);\n    }\n    static void extend_pow_base(int len){\n        int nlen\
    \ = pow_base.size();\n        if (nlen > len) return ;\n        len = 2*nlen;\n\
    \        pow_base.resize(len+1);\n        rep(i,nlen,len+1) pow_base[i] = cal(mul(pow_base[i-1],BASE));\n\
    \    }\n    string str;\n    int n;\n    vector<ull> inner_hash;\n    void build(const\
    \ string &s){\n        set_hash();\n        str = s;\n        n = s.size();\n\
    \        extend_pow_base(n);\n        inner_hash.resize(n+1);\n        inner_hash[0]\
    \ = 0;\n        rep(i,0,n) inner_hash[i+1] = cal(mul(inner_hash[i],BASE) + s[i]);\n\
    \    }\n};\nusing ull = unsigned long long;\null RollingHash::BASE = 0;\nvector<ull>\
    \ RollingHash::pow_base = vector<ull>(1,1);\nusing roriha = RollingHash;\n\n}\
    \ // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2023-04-19 23:15:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/RollingHash.hpp
layout: document
redirect_from:
- /library/string/RollingHash.hpp
- /library/string/RollingHash.hpp.html
title: string/RollingHash.hpp
---
