---
title: Two SAT
documentation_of: //math/two_sat.hpp
---

## 説明

Two SATを解く。

### コンストラクタ

`two_sat(int n)` $n$ 変数のTwo SAT

### add_clause(int i, bool f, int j, bool g)

$i \lor j$ を追加。
f が false のときは i が否定に、 g が false のときは j が否定となる。

### satisfiable()

与えられたTwo SATを満たす変数の割り当てがあるかどうか判定

### ans()

変数の割り当てを返す。事前にsatisfiableを実行しておくことが必要。
