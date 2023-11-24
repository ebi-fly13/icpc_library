---
title: LCA based Auxiliary Tree
documentation_of: //tree/lca_based_auxiliary_tree.hpp
---

## 説明

頂点集合を与えて、それらとそれらの頂点のLCAを合わせた補助的な木を求める。
返り値ではdfs順に{頂点番号, その親}が入っている。

頂点集合の大きさを $k$ として $O(k\log k)$