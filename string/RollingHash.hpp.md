---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aoj_2444.test.cpp
    title: test/string/aoj_2444.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/RollingHash.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i,s,n) for (int i = s; i < (int)(n);\
    \ i++)\n#define rrep(i,s,n) for (int i = (int)(n)-1; i >= (int)(s); i--)\n#define\
    \ all(v) v.begin(),v.end()\n\nusing ll = long long;\nusing ld = long double;\n\
    using ull = unsigned long long;\n\ntemplate<typename T> bool chmin(T &a, const\
    \ T &b){\n    if (a <= b) return false;\n    a = b;\n    return true;\n}\ntemplate<typename\
    \ T> bool chmax(T &a, const T &b){\n    if (a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\nnamespace lib{\n\nusing namespace std;\n\n} // namespace\
    \ lib;\n\n//using namespace lib;\n#line 4 \"string/RollingHash.hpp\"\n\n\nnamespace\
    \ lib{\n\nusing namespace std;\n\nstruct RollingHash {\n    using ull = unsigned\
    \ long long;\n    RollingHash(const string &s = \"\"){ build(s);}\n    ull get(int\
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
    \ = pow_base.size();\n        if (nlen > len) return ;\n        pow_base.resize(len+1);\n\
    \        rep(i,nlen,len+1) pow_base[i] = cal(mul(pow_base[i-1],BASE));\n    }\n\
    \    string str;\n    int n;\n    vector<ull> inner_hash;\n    void build(const\
    \ string &s){\n        set_hash();\n        str = s;\n        n = s.size();\n\
    \        extend_pow_base(n);\n        inner_hash.resize(n+1);\n        inner_hash[0]\
    \ = 0;\n        rep(i,0,n) inner_hash[i+1] = cal(mul(inner_hash[i],BASE) + s[i]);\n\
    \    }\n};\null RollingHash::BASE = 0;\nvector<ull> RollingHash::pow_base = vector<ull>(1,1);\n\
    using roriha = RollingHash;\n\n} // namespace lib\n"
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
    \ = pow_base.size();\n        if (nlen > len) return ;\n        pow_base.resize(len+1);\n\
    \        rep(i,nlen,len+1) pow_base[i] = cal(mul(pow_base[i-1],BASE));\n    }\n\
    \    string str;\n    int n;\n    vector<ull> inner_hash;\n    void build(const\
    \ string &s){\n        set_hash();\n        str = s;\n        n = s.size();\n\
    \        extend_pow_base(n);\n        inner_hash.resize(n+1);\n        inner_hash[0]\
    \ = 0;\n        rep(i,0,n) inner_hash[i+1] = cal(mul(inner_hash[i],BASE) + s[i]);\n\
    \    }\n};\null RollingHash::BASE = 0;\nvector<ull> RollingHash::pow_base = vector<ull>(1,1);\n\
    using roriha = RollingHash;\n\n} // namespace lib"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2023-04-23 15:49:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aoj_2444.test.cpp
documentation_of: string/RollingHash.hpp
layout: document
title: RollingHash
---

## 説明

以下、文字列の長さを $N$ とする。

### コンストラクタ

`roriha (string s)`

`s` から $\bmod (2^{61}-1)$ のローリングハッシュを構築します。計算量は $\Theta(N)$ です。

### get 

`ull get(int l, int r)`

0_indexed で `s[l,r)` のハッシュを取得します。計算量は $\Theta(1)$ です。

### get_hash

`ull get_hash(string s)`

`s` 全体のハッシュを取得します。ローリングハッシュの構築を行う必要がない場合に使います。計算量は $\Theta(N)$ です。

### concat

`ull concat(ull hash1, ull hash2, int len2)`

`string s, t` について `s+t` のハッシュを取得します。`hash1` は `s` のハッシュ、`hash2` と `len2` はそれぞれ `t` のハッシュおよび長さです。計算量は $\Theta(1)$ です。

## 使い方

```cpp
int main(){
    string s; cin >> s;
    roriha hs(s);
    int l, r; cin >> l >> r;
    ull lrhash = hs.get(l,r); // [l,r), 0_indexed
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    ull hash1 = hs.get(l1,r1), hash2 = hs.get(l2,r2);
    ull hash12 = roriha::concat(hash1,hash2,r2-l2); // s[l1,r1)+s[l2,r2) のハッシュを取得する
}

```
