---
title: Suffix Array
documentation_of: //string/suffix_array.hpp
---

## 説明

ダブリングによってsuffix arrayを構築する。文字列長を $N$ とする。

### suffix_array(string s)

`s` のsuffix arrayを構築する。 $O(N (\log N)^2)$

### lcp_array(string s, vector<int> sa)

`s` のlcp_arrayを構築する。 $O(N)$