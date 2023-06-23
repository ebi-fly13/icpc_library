---
title: サイコロライブラリ
documentation_of: //misc/dice.hpp
---

## 説明

サイコロを転がします。ころころ

### set_val(std::vector<int> _val)

`val`を`_val`に更新

### roll(c)

`c` の方向に回転する。`rollc()`と同じ動作 (`c`には`NSFWRL`のいずれかが入る)

### ~_val()

`~`のvalを返す。`~`にはtop, right, left, front, back, downが入る。

### makeDice()

サイコロを全通り (24通り)列挙する。