#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../../data_structure/li_chao_tree.hpp"
#include "../../template/template.hpp"

using namespace lib;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<ll, ll>> lr(n);
    std::vector<std::pair<ll, ll>> y(n);
    std::vector<ll> x;
    for (int i = 0; i < n; i++) {
        std::cin >> lr[i].first >> lr[i].second;
        std::cin >> y[i].first >> y[i].second;
    }
    std::vector<std::vector<ll>> query(q);
    for (int i = 0; i < q; i++) {
        ll t;
        std::cin >> t;
        query[i].emplace_back(t);
        if (t == 0) {
            ll l, r, a, b;
            std::cin >> l >> r >> a >> b;
            query[i].emplace_back(l);
            query[i].emplace_back(r);
            query[i].emplace_back(a);
            query[i].emplace_back(b);
        } else {
            ll p;
            std::cin >> p;
            query[i].emplace_back(p);
            x.emplace_back(p);
        }
    }
    if (x.size() == 0) return 0;
    std::sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    x.emplace_back(1e9 + 10);
    li_chao_tree<ll> seg(x);
    for (int i = 0; i < n; i++) {
        auto [l, r] = lr[i];
        auto [a, b] = y[i];
        seg.add_segment(a, b, l, r);
    }
    for (int i = 0; i < q; i++) {
        if (query[i][0] == 0) {
            ll l = query[i][1];
            ll r = query[i][2];
            ll a = query[i][3];
            ll b = query[i][4];
            seg.add_segment(a, b, l, r);
        } else {
            ll ret = seg.min(query[i][1]);
            if (ret == std::numeric_limits<ll>::max()) {
                std::cout << "INFINITY" << std::endl;
            } else {
                std::cout << ret << std::endl;
            }
        }
    }
}