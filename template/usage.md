# `compare.sh` の使い方

入力生成器と 2 つの解法を与えると、生成した入力を解法に投げて出力を比較し、違いが現れる入力を見つけることができる。

**入力生成器は実行コマンドの第 1 引数に乱数シードを受け取ること。**

実行するコマンドは `zsh compare.sh <generator> <solver1> <solver2> <number of test>` である。

- `<generator>` は入力を生成する `cpp` ファイル
- `<solver1>` は解法 1 の `cpp` ファイル
- `<solver2>` は解法 2 の `cpp` ファイル
- `<number of test>` はテストを走らせる回数

実行例は `zsh compare.sh gen.cpp sol1.cpp sol2.cpp 10` などである。

サンプルを `icpc_library/playground/` 以下に置いている。これらは [ABC328-A](https://atcoder.jp/contests/abc328/tasks/abc328_a)のデバッグを模したものである。

`icpc_library/playground` において次のコマンドを実行すると良い。

`zsh ../template/compare.sh gen.cpp sol.cpp ok.cpp 10`

`gen.cpp` は実行コマンドの第 1 引数に乱数シードを受け取る。違いが現れやすくするため、入力の範囲を小さくするなどの工夫をすると良い。

`sol.cpp` は誤りを含む可能性のあるコードで、この例では実際に誤りを含んでいる。

`ok.cpp` は正しい解法である。

`10` ケース実行する。

実行すると `differ on seed 8` と出力されるだろう。実行後は最後に走らせたテストケースが `case.txt` に、 2 つの解法の出力が `submit1.txt submit2.txt` に入っている。

これによって、違いが現れたケースを `case.txt` から確認することができる。