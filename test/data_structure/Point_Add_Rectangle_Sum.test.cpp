#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../data_structure/offline_segtree_2d.hpp"
#include "../../data_structure/segtree.hpp"
#include "../../template/template.hpp"

ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

struct Query {
    ll x, y, w;
    ll l, d, r, u;
    int flag;
};

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<ll> x(n), y(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i] >> w[i];
    }
    std::vector<Query> query(q);
    for (int i = 0; i < q; i++) {
        std::cin >> query[i].flag;
        if (query[i].flag == 0) {
            std::cin >> query[i].x >> query[i].y >> query[i].w;
        } else {
            std::cin >> query[i].l >> query[i].d >> query[i].r >> query[i].u;
        }
    }
    offline_segtree_2d<ll, op, e, segtree<ll, op, e>> seg2d;
    for (int i = 0; i < n; i++) {
        seg2d.pre_set({x[i], y[i]});
    }
    for (int i = 0; i < q; i++) {
        if (query[i].flag == 0) {
            seg2d.pre_set({query[i].x, query[i].y});
        }
    }
    seg2d.build();
    for (int i = 0; i < n; i++) {
        seg2d.set(x[i], y[i], seg2d.get(x[i], y[i]) + w[i]);
    }
    for (int i = 0; i < q; i++) {
        if (query[i].flag == 0) {
            seg2d.set(query[i].x, query[i].y,
                      seg2d.get(query[i].x, query[i].y) + query[i].w);
        } else {
            std::cout << seg2d.prod(query[i].l, query[i].d, query[i].r,
                                    query[i].u)
                      << '\n';
        }
    }
}