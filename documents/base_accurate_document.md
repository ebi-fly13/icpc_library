---
title: base_accurate
documentation_of: //geometry3D/accurate/base_accurate.hpp
---

3次元幾何を整数で正確に扱うためのライブラリです。

## コンストラクタ

`Vec<T>`

3次元の点やベクトルを表す構造体です。点の座標は `T = ll,int,lib::rational` などの型で保持します。

## cross(外積)

`Vec<T> cross(const Vec<T> &a, const Vec<T> &b)`

外積 $a\times b$ を返します。

## dot(内積)

`T dot(const Vec<T> &a, const Vec<T> &b)`

内積 $a\cdot b$ を返します。

## norm(ノルム)

`T norm(const Vec<T> &a)`

$a$ のノルムを返します。

- `return a.x*a.x + a.y*a.y + a.z*a.z`

## Line (直線)

`Line<T>`

3次元上の直線をそれが通る異なる $2$ 点を保持して管理します。

## intersection

`int intersection(const Line<rational> &p, const Line<rational> &q)`

有理数型で管理されている直線を $2$ つ受け取り、それらの関係を返します。

- $p,q$ が唯一の交点を持つとき `0`
- $p,q$ が平行でないとき `1`
- $p,q$ が一致するとき `2`
- $p,q$ が平行であって一致しないとき `3`

をそれぞれ返します。

## cross_point

`Vec<rational> cross_point(const Line<rational> &p, const Line<rational> &q)`

有理数型で管理されている直線が唯一の交点を持つとき、その交点を返します。

- `assert(intersection(p,q) == 0)` つまり、唯一の交点を持つことを要請します。


## 使用例

[AtCoder301-G Worst Picture への提出](https://atcoder.jp/contests/abc301/submissions/41476430)
