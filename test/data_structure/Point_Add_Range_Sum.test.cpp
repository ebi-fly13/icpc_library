#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../data_structure/segtree.hpp"
#include "../../template/template.hpp"

ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<ll> a(n);
    rep(i, 0, n) {
        std::cin >> a[i];
    }
    segtree<ll, op, e> seg(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            ll x;
            std::cin >> p >> x;
            seg.set(p, seg.get(p) + x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r) << '\n';
        }
    }
}