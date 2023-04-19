---
title: RollingHash
documentation_of: ./RollingHash.hpp
---

## 説明

### コンストラクタ

`roriha (string s)`

`s` から $\bmod (2^{61}-1)$ のローリングハッシュを構築します。計算量は $\Theta(|s|)$ です。

### get 

`ull get(int l, int r)`

0_indexed で `s[l,r)` のハッシュを取得します。計算量は $\Theta(1)$ です。

### get_hash

`ull get_hash(string s)`

`s` 全体のハッシュを取得します。ローリングハッシュの構築を行う必要がない場合に使います。計算量は $\Theta(|s|)$ です。

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