---
title: NTT convolution
documentation_of: //convolution/ntt.hpp
---

## 説明

$\mod 998244353$ でのみ動作する $O(N\log N)$ の畳み込み。

## ntt_info

NTTをするために必要なデータを格納している。

## bit_reverse(int n, int bit_size)

$n$ を ビット幅 $bit_size$ でビットリバースする。

## butterfly(std::vector<mint> &a, bool inverse)

配列 $a$ をFFTする。inverse = true のときinvFFTをする。
invFFTでは割る $n$ をする。
$a$ の配列の大きさは $2$ 冪でないとダメ。

## convolution(std::vector<mint> a, std::vector<mint> b)

$a$ と $b$ を畳み込みその配列を返す。 $O(N\log N)$