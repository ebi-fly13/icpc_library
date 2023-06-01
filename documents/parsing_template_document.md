---
title: 構文解析テンプレート
documentation_of: //template/parsing_template.hpp
---

## 説明

構文解析をする際のテンプレート

### bool expect(State &begin, char expected)

現在見ている文字がexpectedと一致しているかを返す。

### consume(State &begin, char expected)

現在見ている文字がexpectedであるとして一文字進める。一致していない場合、`assert`で落ちる。

### isdigit(char c)

`c` が数値であるかを返す。

### isAlpha(char c)

`c` が大文字アルファベットかを返す。

### isalpha(char c)

`c` が小文字アルファベットかを返す。