---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/RerootingDP.test.cpp
    title: test/tree/RerootingDP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/tree/Tree_Path_Composite_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/RerootingDP.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#define rep(i, s, n) for (int i = (int)(s); i\
    \ < (int)(n); i++)\n#define rrep(i, s, n) for (int i = (int)(n)-1; i >= (int)(s);\
    \ i--)\n#define all(v) v.begin(), v.end()\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\n\ntemplate <typename T> bool\
    \ chmin(T &a, const T &b) {\n    if (a <= b) return false;\n    a = b;\n    return\
    \ true;\n}\ntemplate <typename T> bool chmax(T &a, const T &b) {\n    if (a >=\
    \ b) return false;\n    a = b;\n    return true;\n}\n\nnamespace lib {\n\nusing\
    \ namespace std;\n\n}  // namespace lib\n\n// using namespace lib;\n#line 4 \"\
    tree/RerootingDP.hpp\"\n\nnamespace lib {\n\ntemplate <class E, class V, E (*merge)(E,\
    \ E), E (*e)(), E (*put_edge)(V, int),\n          V (*put_vertex)(E, int)>\nstruct\
    \ RerootingDP {\n    struct edge {\n        int to, idx, xdi;\n    };\n    RerootingDP(int\
    \ _n = 0) : n(_n) {\n        es.resize(n);\n    }\n    void add_edge(int u, int\
    \ v, int idx1, int idx2) {\n        es[u].push_back({v, idx1, idx2});\n      \
    \  es[v].push_back({u, idx2, idx1});\n    }\n    vector<V> build(int v = 0) {\n\
    \        root = v;\n        outs.resize(n);\n        subdp.resize(n);\n      \
    \  in.resize(n), up.resize(n);\n        int tnow = 0;\n        dfs(root, -1, tnow);\n\
    \        return subdp;\n    }\n    vector<V> reroot() {\n        reverse_edge.resize(n);\n\
    \        reverse_edge[root] = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n\
    \        bfs(root);\n        return answers;\n    }\n    V get(int r, int v) {\n\
    \        if (r == v) return answers[r];\n        if (!(in[v] < in[r] && up[r]\
    \ <= up[v])) return subdp[v];\n        int le = 0, ri = outs[v].size();\n    \
    \    while (ri - le > 1) {\n            int md = (le + ri) / 2;\n            if\
    \ (in[es[v][md].to] <= in[r])\n                le = md;\n            else\n  \
    \              ri = md;\n        }\n        return reverse_dp[es[v][le].to];\n\
    \    }\n    const vector<edge> &operator[](int idx) const {\n        return es[idx];\n\
    \    }\n\n  private:\n    int n, root;\n    vector<vector<edge>> es;\n    vector<vector<E>>\
    \ outs;\n    vector<E> reverse_edge;\n    vector<V> subdp, reverse_dp, answers;\n\
    \    vector<int> in, up;\n    void dfs(int v, int p, int &t) {\n        E val\
    \ = e();\n        in[v] = t++;\n        for (auto &u : es[v]) {\n            if\
    \ (u.to == p && u.to != es[v].back().to) swap(u, es[v].back());\n            if\
    \ (u.to == p) continue;\n            dfs(u.to, v, t);\n            E nval = put_edge(subdp[u.to],\
    \ u.idx);\n            outs[v].emplace_back(nval);\n            val = merge(val,\
    \ nval);\n        }\n        subdp[v] = put_vertex(val, v);\n        up[v] = t;\n\
    \    }\n    void bfs(int v) {\n        int siz = outs[v].size();\n        vector<E>\
    \ lui(siz + 1), rui(siz + 1);\n        lui[0] = e(), rui[siz] = e();\n       \
    \ for (int i = 0; i < siz; i++) lui[i + 1] = merge(lui[i], outs[v][i]);\n    \
    \    for (int i = siz - 1; i >= 0; i--)\n            rui[i] = merge(outs[v][i],\
    \ rui[i + 1]);\n        for (int i = 0; i < siz; i++) {\n            reverse_dp[es[v][i].to]\
    \ = put_vertex(\n                merge(merge(lui[i], rui[i + 1]), reverse_edge[v]),\
    \ v);\n            reverse_edge[es[v][i].to] =\n                put_edge(reverse_dp[es[v][i].to],\
    \ es[v][i].xdi);\n            bfs(es[v][i].to);\n        }\n        answers[v]\
    \ = put_vertex(merge(lui[siz], reverse_edge[v]), v);\n    }\n};\n\n}  // namespace\
    \ lib\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace lib {\n\
    \ntemplate <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int),\n\
    \          V (*put_vertex)(E, int)>\nstruct RerootingDP {\n    struct edge {\n\
    \        int to, idx, xdi;\n    };\n    RerootingDP(int _n = 0) : n(_n) {\n  \
    \      es.resize(n);\n    }\n    void add_edge(int u, int v, int idx1, int idx2)\
    \ {\n        es[u].push_back({v, idx1, idx2});\n        es[v].push_back({u, idx2,\
    \ idx1});\n    }\n    vector<V> build(int v = 0) {\n        root = v;\n      \
    \  outs.resize(n);\n        subdp.resize(n);\n        in.resize(n), up.resize(n);\n\
    \        int tnow = 0;\n        dfs(root, -1, tnow);\n        return subdp;\n\
    \    }\n    vector<V> reroot() {\n        reverse_edge.resize(n);\n        reverse_edge[root]\
    \ = e();\n        reverse_dp.resize(n);\n        answers.resize(n);\n        bfs(root);\n\
    \        return answers;\n    }\n    V get(int r, int v) {\n        if (r == v)\
    \ return answers[r];\n        if (!(in[v] < in[r] && up[r] <= up[v])) return subdp[v];\n\
    \        int le = 0, ri = outs[v].size();\n        while (ri - le > 1) {\n   \
    \         int md = (le + ri) / 2;\n            if (in[es[v][md].to] <= in[r])\n\
    \                le = md;\n            else\n                ri = md;\n      \
    \  }\n        return reverse_dp[es[v][le].to];\n    }\n    const vector<edge>\
    \ &operator[](int idx) const {\n        return es[idx];\n    }\n\n  private:\n\
    \    int n, root;\n    vector<vector<edge>> es;\n    vector<vector<E>> outs;\n\
    \    vector<E> reverse_edge;\n    vector<V> subdp, reverse_dp, answers;\n    vector<int>\
    \ in, up;\n    void dfs(int v, int p, int &t) {\n        E val = e();\n      \
    \  in[v] = t++;\n        for (auto &u : es[v]) {\n            if (u.to == p &&\
    \ u.to != es[v].back().to) swap(u, es[v].back());\n            if (u.to == p)\
    \ continue;\n            dfs(u.to, v, t);\n            E nval = put_edge(subdp[u.to],\
    \ u.idx);\n            outs[v].emplace_back(nval);\n            val = merge(val,\
    \ nval);\n        }\n        subdp[v] = put_vertex(val, v);\n        up[v] = t;\n\
    \    }\n    void bfs(int v) {\n        int siz = outs[v].size();\n        vector<E>\
    \ lui(siz + 1), rui(siz + 1);\n        lui[0] = e(), rui[siz] = e();\n       \
    \ for (int i = 0; i < siz; i++) lui[i + 1] = merge(lui[i], outs[v][i]);\n    \
    \    for (int i = siz - 1; i >= 0; i--)\n            rui[i] = merge(outs[v][i],\
    \ rui[i + 1]);\n        for (int i = 0; i < siz; i++) {\n            reverse_dp[es[v][i].to]\
    \ = put_vertex(\n                merge(merge(lui[i], rui[i + 1]), reverse_edge[v]),\
    \ v);\n            reverse_edge[es[v][i].to] =\n                put_edge(reverse_dp[es[v][i].to],\
    \ es[v][i].xdi);\n            bfs(es[v][i].to);\n        }\n        answers[v]\
    \ = put_vertex(merge(lui[siz], reverse_edge[v]), v);\n    }\n};\n\n}  // namespace\
    \ lib\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: tree/RerootingDP.hpp
  requiredBy: []
  timestamp: '2023-05-17 22:41:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Tree_Path_Composite_Sum.test.cpp
  - test/tree/RerootingDP.test.cpp
documentation_of: tree/RerootingDP.hpp
layout: document
title: RerootingDP
---

## RerootingDP

木に対して全方位木DPを行います。次の問題を解きます。

> 頂点 $0,1,\dots,n-1$ からなる $n$ 頂点の木 $T$ が与えられます。
> 有向グラフ $G=(\mathbb{V},\mathbb{E})$ は以下を満たします。
> - $\mathbb{V}=\lbrace 0,1,\dots, n-1 \rbrace$ である。
> - $\mathbb{E}\subset \mathbb{V}\times \mathbb{V}$ である。辺 $(a,b)$ は頂点 $a$ から頂点 $b$ への**有向辺**。 $T$ において頂点 $a,b$ の間に辺が張られているとき, またそのときに限り $(a,b),(b,a)\in \mathbb{E}$ である。
> 
> また、各有向辺には整数値の番号が割り当てられていて、 $\mathrm{idx}:\mathbb{E}\to \mathbb{Z}$ によって定められます。ここで $\mathbb{E}_\mathrm{idx}=\lbrace \mathrm{idx}(e)\ \mid\ e\in \mathbb{E} \rbrace$ としておきます。
> 
> **可換**モノイド $(E,\oplus : E\times E\to E,e\in E)$ と集合 $V$ および $\mathrm{put \_ edge}:V\times \mathbb{E}_\mathrm{idx}\to E,\ \mathrm{put \_ vertex}:E\times \mathbb{V}\to V$ が与えられます。次の擬似コードに従って計算される値 <code>dfs(0,0), dfs(1,1),...,dfs(n-1,n-1)</code> を求めてください。ただし、頂点 $r$ を根と見たときの頂点 $v$ の子の頂点の集合を $\mathrm{child}(r,v)$ とします。
>```
>V dfs(vertex r, vertex v){
>    E prod = e();
>    for ( (v, c) in E, c in child(r,v) ){
>        prod = merge(prod, put_edge(dfs(r,c),idx(v,c)));
>    }
>    return put_vertex(prod, v);
>}
>```

この問題を時間計算量 $\mathrm{O}(n)$ で解くことができます。

また、このライブラリはオラクルとして <code>merge, e, put_edge, put_vertex</code> を使用しますが、これらが定数時間で動くものと仮定したときの計算量を記述します。オラクル内部の計算量が $\mathrm{O}(f(n))$ である場合はすべての計算量が $\mathrm{O}(f(n))$ 倍となります。

### コンストラクタ

```
RerootingDP<E, V, merge, e, put_edge, put_vertex> g(int n);
```

- 可換モノイドの型 <code>E</code>
- DPの値の型 <code>V</code>
- $\oplus : E\times E\to E$ を計算する関数 <code>E merge(E a, E b)</code>
- $e$ を返す関数 <code>E e()</code>
- 辺番号 $i$ の辺を付加する関数 <code>E put_edge(V x, int i)</code>
- 頂点番号 $v$ の頂点を付加する関数 <code>V put_vertex(E x, int v)</code>

を定義する必要があります。

- 頂点数 <code>n</code> の木を作る準備をします。<code>n</code> 頂点 $0$ 辺のグラフを作ります。
- デフォルトでは <code>n = 0</code> です。
  
#### 制約

- $0\le n\le 10^8$

#### 計算量
- $\mathrm{O}(n)$

### add_edge

```
void g.add_edge(int u, int v, int idx1, int idx2)
```

- 頂点 <code>u</code> から頂点 <code>v</code> への辺番号が <code>idx1</code> である辺を追加します。
- 頂点 <code>v</code> から頂点 <code>u</code> への辺番号が <code>idx2</code> である辺を追加します。
  
#### 制約

- $0\le u,v\lt n$
- ちょうど $n-1$ 回 <code>add_edge</code> を呼んでできるグラフは連結（どの $2$ 頂点間にもパスが存在する）であり、その後 <code>add_edge</code> は呼ばれない。

#### 計算量

- ならし $\mathrm{O}(1)$

### build

```
vector<V> g.build(int r)
```

- 長さ $n$ の配列 <code>subdp</code> を返します。<code>subdp[v]</code> は上述した問題における <code>dfs(r,r)</code> を計算する過程で `dfs` が返す値 `dfs(r,v)` です。
- 頂点 `r` を根とする木DPのすべての結果を取得することができます。
  
#### 制約

- <code>build</code> を呼ぶ前にちょうど $n-1$ 回 <code>add_edge</code> を呼んでいる。
- <code>build</code> は $1$ 回までしか呼ばれない。

#### 計算量

- $\mathrm{O}(n)$

### reroot

```
vector<V> g.reroot()
```

- 長さ $n$ の配列 <code>answers</code> を返します。<code>answers[v]</code> は上述した問題における <code>dfs(v,v)</code> です。
  
#### 制約

- <code>reroot</code> を呼ぶ前にちょうど $1$ 回 <code>bulid</code> を呼んでいる。
- <code>reroot</code> は $1$ 回までしか呼ばれない。

#### 計算量

- $\mathrm{O}(n)$
  
### get

```
V get g.get(int r, int v)
```

- 上述した問題における <code>dfs(r,r)</code> を計算する過程で `dfs` が返す値 `dfs(r,v)` を返します。
- 頂点 `r` を根とする木DPをしたときの頂点 `v` の部分木に対するDPの値を得ることができます。

#### 制約

- `get` を呼ぶ前にちょうど $1$ 回 `reroot` を呼んでいる。

#### 計算量

- $\mathrm{O}(\log n)$
  
### 使用例

AC code of https://atcoder.jp/contests/dp/tasks/dp_v

submission https://atcoder.jp/contests/dp/submissions/36003936

``` cpp
#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using mint = atcoder::modint;

#include"RerootingDP"

mint merge(mint a, mint b){
    return a * b;
}
mint e(){
    return mint(1);
}
mint put_edge(mint v, int i){
    return v + 1;
}
mint put_vertex(mint e, int v){
    return e;
}

int main(){
    int n, m; cin >> n >> m;
    mint::set_mod(m);
    RerootingDP<mint,mint,merge,e,put_edge,put_vertex> g(n);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g.add_edge(u-1,v-1,i,i);
    }
    g.build();
    for (auto ans : g.reroot()) cout << ans.val() << endl;
}
```

## 設計の意図

全方位木DPはすべての部分木 $t$ に対する答え $dp(t)$ を高速に求めるアルゴリズムで、 $t$ に含まれるさらに小さい部分木 $s$ に対する答え $dp(s)$ から $dp(t)$ を計算していきます。 $r$ を全体の根としたときの木DPの値を求める際、$v$ の部分木を有向辺 $(par(v),v)$ に対応させると理解しやすい、という話があります。（ $par(v)$ は $r$ を根としたときの $v$ の親です。 $v=r$ のときは $par(v)$ は仮想的な頂点であり、有向辺 $(par(v),v)$ は仮想的な辺です。 ）これに基づいて、有向辺 $(u,v)$ に対応する答えを $f(u,v)$ と書くことにしましょう。 $u=-1$ のときは仮想的な有向辺を考えており、対応する部分木は $v$ を根とする根付き木です。さて、このライブラリの設計では、

$$
f(u,v)=\bigoplus_{c\in \mathrm{child}(u,v)}f(v,c)
$$

のような遷移式では考慮されない「辺の重み」を取り入れるため、補助的な関数 $g(u,v)$ を定義しています。 $g(u,v)$ は $(u,v)$ に対応する部分木に辺 $(u,v)$ を付加するが頂点 $u$ はまだ付加しないみたいな（雰囲気で感じ取ってください）部分木もどきに対する答えっぽいもの（雰囲気で感じ取ってください）です。要点は次のとおりです。

- 部分木に辺を付加すると、部分木もどきになる。( $\mathrm{put \\_ edge}$ )
- 部分木もどきをマージして頂点を付加すると、部分木になる。( $\mathrm{put \\_ vertex}$ )
- $\displaystyle f(u,v)=\mathrm{put \_ vertex}\left(\bigoplus_{c\in \mathrm{child}(u,v)} \mathrm{put \_ edge}(f(v,c),\mathrm{idx}(v,c)) ,\ v\right)$

ライブラリ内で辺に重み <code>E e</code> 、頂点に重み <code>V v</code> を持つような設計もあり得ると思ったのですが、できるだけライブラリの外側で問題依存パートを扱いたいのと、 <code>put_vertex</code> には単位元のようなものを要求しないため初期値の設定に困ったので、頂点・辺番号を引数に渡す関数を要求するライブラリの設計にしました。