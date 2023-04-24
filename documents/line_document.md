---
title: line
documentation_of: //geometry/line.hpp
---

## 説明

平面での直線の各種操作

### line

直線の2点を持つ

### proj(line l, vec p)

直線 $l$ に点 $p$ から垂線を引いたときの交点 $x$ を返す。

### refl(line l, vec p)

直線 $l$ を対象軸として点 $p$ を線対象に移動させた点 $x$ を返す。

### intersection(line a, line b)

直線 $a$, $b$ の関係を返す。

- 交差 $0$
- 垂直 $1$
- 平行 $2$
- 同一直線 $3$

### distance(line a, vec p)

直線 $a$ と点 $p$ の距離を返す。

### cross_point(line a, line b)

直線 $a$, $b$ の交点を返す。