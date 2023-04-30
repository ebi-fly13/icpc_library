---
title: circle
documentation_of: //geometry/circle.hpp
---

## 説明

平面での円に対する各種操作

### intersection(circle a, circle b)

円 $a$, $b$ の共通接戦の数を返す。

- $5$ 本: 同一円 (本当は無限本) 
- $4$ 本: 離れている
- $3$ 本: 外接している
- $2$ 本: 交わる
- $1$ 本: 内接している
- $0$ 本: 一方がもう一方を内包する

### incircle_of_triangle(vec a, vec b, vec c)

三角形abcの内接円を返す。

### circumscribed_circle_of_triangle(vec a, vec b, vec c)

depends on line.hpp (cross_point)
三角形abcの外接円を返す。

### cross_point(circle c, line l)

円 $c$ と直線 $l$ の交点をvectorに格納して返す。

### cross_point(cirle c1, circle c2)

円 $c1$と $c2$ の交点をvectorに格納して返す。
