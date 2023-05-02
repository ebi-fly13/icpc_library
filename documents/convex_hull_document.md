---
title: convex_hull
documentation_of: //geometry/convex_hull.hpp
---

## 説明

`base_ld` を基礎とした凸包ライブラリ。

`vector<vec> convex_hull(vector<vec> a)`

**重複のない** `vec` の配列 `a` に対し、それらの点が成す凸包の頂点を反時計回りに返す。(重複があってもうまく動き得るが、保証しない)

凸包が $N$ 点からなるとき、長さ $N$ の `vector` が返される。

## 使用例

```cpp
int main(){
    int n; cin >> n;
    vector<vec> a(n);
    rep(i,0,n){
        ld x, y; cin >> x >> y;
        a[i] = vec(x,y);
    }
    auto hull = convex_hull(a);
    for (vec v : hull){
        cout << v << endl;
    }
}
```

### 入力例
```
6
0 0
2 0
1 1
2 1
3 1
2 2
```

### 出力例
```
0 0
2 0
3 1
2 2
```

この出力例は正確ではなく、本当は `(0.00000,0.00000)` などと出力される。 