#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../data_structure/fenwick_tree.hpp"
#include "../../template/template.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep(i, 0, n) {
        ll a;
        std::cin >> a;
        fw.add(i, a);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            ll x;
            std::cin >> p >> x;
            fw.add(p, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << fw.sum(l, r) << '\n';
        }
    }
}