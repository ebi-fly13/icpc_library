---
title: Low Link
documentation_of: //graph/low_link.hpp
---

## 説明

グラフを渡してlow linkを求める。 $O(N)$

### is_bridge(int u, int v)

辺 $u-v$ が橋であるか判定。そのような辺がない場合もfalseを返す。

### bridge()

橋を列挙して返す。

### articulation()

関節点を列挙して返す。
