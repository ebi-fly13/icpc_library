#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>

#include "../../data_structure/lazysegtree.hpp"
#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using namespace lib;

using mint = modint998244353;

struct S {
    mint a;
    int size;
};

struct F {
    mint a, b;
    F(mint a, mint b) : a(a), b(b) {}
};

S op(S l, S r) {
    return S{l.a + r.a, l.size + r.size};
}

S e() {
    return S{0, 0};
}

S mapping(F l, S r) {
    return S{r.a * l.a + (mint)r.size * l.b, r.size};
}

F composition(F l, F r) {
    return F{r.a * l.a, r.b * l.a + l.b};
}

F id() {
    return F{1, 0};
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<S> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        v[i] = {a, 1};
    }
    lazysegtree<S, op, e, F, mapping, composition, id> seg(v);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            seg.apply(l, r, F(b, c));
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r).a.val() << std::endl;
        }
    }
}