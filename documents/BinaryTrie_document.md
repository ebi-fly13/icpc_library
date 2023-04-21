---
title: BinaryTrie
documentation_of: //data_structure/BinaryTrie.hpp
---

## 実装の際に省略できるもの

`count` , `erase` , `order` , `get` , `xor_all` の実装は他の機能と独立であり、省略できます。

## 説明

この BinaryTrie は非負整数の**多重集合**を管理します。

### コンストラクタ

`BinrayTrie<T, MAX_LOG> ()`

型 `T` でbit長が `MAX_LOG` であるBinaryTrieを構築します。

`T` は `int` または `ll` が想定されています。

多重集合で扱われる値 `x` は `0 <= x < (1 << MAX_LOG)` が満たされている必要があります。
ただし、 `MAX_LOG` 桁以上の桁が $0$ であるという過程で動作するため、正確には非負整数 `x` は $\bmod$ `1 << MAX_LOG` で扱われます。

### insert

`void insert(T x)`

多重集合に $x$ を $1$ つ挿入します。既にその要素が存在する場合でも、重複をカウントします。

### erase

`void erase(T x)`

多重集合から $x$ を $1$ つ削除します。 $x$ が存在しない場合は何も起こりません。特にエラーを起こしません。

### count

`int count(T x = -1)`

`count()` と呼んだ、あるいは `x = -1` のとき、多重集合の要素数を返します。

そうでないとき、多重集合に含まれる `x` の個数を返します。

### order

`int order(T x)`

多重集合に含まれる $x$ より小さい要素の個数を返します。

### get

`T get(int k)`

0_indexed で $k$ 番目に小さい値を返します。 $k$ が多重集合の要素数以上である場合は最大値を返します。多重集合が空の場合は $0$ を返します。

### xor_all

`void xor_all(T x)`

多重集合の要素をすべて $x$ との XOR をとった値に置き換えます。


## 使い方

```cpp
int main(){
    BinaryTrie<int,31> bt;
    bt.insert(1);
    bt.insert(2); // multiset mst = {1,2}
    cout << bt.get(0) << endl; // 1
    bt.xor_all(2); // mst = {0,3}
    cout << bt.get(0) << endl; // 0
    bt.erase(2); // NO change
    cout << bt.count() << endl; // 2
    cout << bt.get(1) << endl; // 3
    bt.erase(0); // mst = {3}
}

```