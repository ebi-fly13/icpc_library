---
title: segment
documentation_of: //geometry/segment.hpp
---

## 説明

平面での線分の各種操作

### segment

線分の端点 $a$, $b$ を持つ

### intersection_segment_and_vec(segment a, vec p)

線分 $a$ 上に点 $p$ が存在するか判定。

### intersection_segment(segment a, segment b)

線分 $a$, $b$ が交わるか判定。端点も含む。

### cross_point(segment a, segment b)

線分 $a$, $b$ の交点を返す。

### distance(segment a, vec c)

線分 $a$ と点 $c$ の距離を返す。

### distance(segment a, segment b)

線分 $a$, $b$ の距離を返す。