---
title: eratosthenes sieve
documentation_of: //math/eratosthenes_sieve.hpp
---

## 説明

エラトステネスの篩

### コンストラクタ

`eratosthenes_sieve(int n)`

上限値を $n$ としてエラトステネスの篩を実行。

### is_prime(int p)

`bool is_prime(int p)`

$p$ が素数であるか判定

### prime_table(int m = -1)

`std::vector<int> prime_table(int m = -1)`

$m$ 以下の素数を格納した配列を返す。 $m = -1$ のときは $m = n$ として実行

