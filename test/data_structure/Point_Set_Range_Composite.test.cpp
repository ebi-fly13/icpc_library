#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../data_structure/segtree.hpp"
#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using mint = lib::modint998244353;

struct F {
    mint a, b;
};

F op(F a, F b) {
    return {b.a * a.a, b.b + b.a * a.b};
}

F e() {
    return {1, 0};
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<F> f(n);
    rep(i, 0, n) {
        ll a, b;
        std::cin >> a >> b;
        f[i] = {a, b};
    }
    lib::segtree<F, op, e> seg(f);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            ll c, d;
            std::cin >> p >> c >> d;
            seg.set(p, {c, d});
        } else {
            int l, r;
            ll x;
            std::cin >> l >> r >> x;
            F prod = seg.prod(l, r);
            mint ans = prod.a * x + prod.b;
            std::cout << ans.val() << '\n';
        }
    }
}
