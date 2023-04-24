---
title: circle
documentation_of: //geometry/circle.hpp
---

## 説明

平面での円に対する各種操作

### intersection(circle a, circle b)

円 $a$, $b$ の共通接戦の数を返す。

- $4$ 本: 離れている
- $3$ 本: 外接している
- $2$ 本: 交わる
- $1$ 本: 内接している
- $0$ 本: 一方がもう一方を内包する