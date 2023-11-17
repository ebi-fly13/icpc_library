---
title: Floor Sum
documentation_of: //math/floor_sum.hpp
---

## 説明

次を求める.
$$f(n, m, a, b) = \sum^{n-1}_{i=0} \left\lfloor \frac{ai + b}{m} \right\rfloor$$
$a, b$ が負であってもよい. $a, b$ が非負であることが保証されている場合, コードを短縮できる.