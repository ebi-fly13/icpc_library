---
title: テンプレート
documentation_of: //template/template.hpp
---

## 説明

ICPCで用いるテンプレート。コンテスト開始時にこれを書く。

- スタック領域拡張: ```ulimit -s unlimited```
- 実行: ```g++ -std=c++17 -Wall -Wextra -Wshadow -Ofast -march=native -Wl,-stack_size,500000000```
- デバッグ: ```g++ -std=c++17 -Wall -Wextra -Wshadow -Wconversion -g -fsanitize=undefined,address```

### 入出力高速化

```
std::cin.tie(nullptr);
std::ios::sync_with_stdio(false);
```