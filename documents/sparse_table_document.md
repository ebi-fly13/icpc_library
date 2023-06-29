---
title: Sparse Table
documentation_of: //data_structure/sparse_table.hpp
---

## 説明

区間クエリを構築 $O(N\log N)$、クエリ $O(1)$ で処理するデータ構造

### コンストラクタ

$1$ 次元の配列を渡して、Sparse Tableを構築する。 $O(N\log N)$

### get(l, r)

$[l, r)$ のクエリを処理する。 $O(1)$