---
title: segment
documentation_of: //geometry/segment.hpp
---

## 説明

平面での線分の各種操作

### segment

線分の端点 $a$, $b$ を持つ

### intersection(segment a, segment b, bool bound = true)

線分 $a$, $b$ が交わるか判定。boundがtrueのとき端点を含む。falseのとき端点を含まない。

### cross_point(segment a, segment b)

線分 $a$, $b$ の交点を返す。