---
title: base_ld
documentation_of: //geometry/base_ld.hpp
---

## 説明

小数点を用いた平面幾何に必須なもの。小数点での平面幾何ではこれをincludeして用いる。

### ldout(int len = 20)

浮動小数点数の出力用関数。小数点以下 `len` 桁出力する。

### sgn(ld x)

$x$ の符号を返す。epsで評価する。

### dot(vec a, vec b)

ベクトル$a$, $b$ の内積を返す。

### cross(vec a, vec b)

ベクトル$a$, $b$ の外積を返す。

### isp(vec a, vec b, vec c)

点 $a$, $b$, $c$ の位置関係を返す。a->b->cの経路が

- 左に曲がる場合: $+1$ 
- 右に曲がる場合: $-1$
- c-a-bの順に並ぶ: $-2$
- a-b-cの順に並ぶ: $+2$
- a-c-bの順に並ぶ: $0$

となる。

### rot90(vec a)

点 $a$ を90度回転をする。

### rot(const &vec a, ld rad)

ベクトル `a` を `(0,0)` を中心に反時計回りに `rad[rad]` 回転させたものを返す。

### comp_for_argument_sort(vec lhs, vec rhs)

偏角ソートの比較関数。