#define PROBLEM "https://yukicoder.me/problems/no/901"

#include "../../template/template.hpp"
#include "../../tree/HeavyLightDecomposition.hpp"
#include "../../tree/lca_based_auxiliary_tree.hpp"

using namespace lib;

int main() {
    int n;
    std::cin >> n;
    std::vector g(n, std::vector<int>());
    std::vector<std::tuple<int, int, ll>> edges(n - 1);
    for (auto &[u, v, w] : edges) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    HeavyLightDecomposition hld(g);
    std::vector<ll> sum(n + 1, 0);
    for (auto [u, v, w] : edges) {
        if (hld.parent(v) == u) std::swap(u, v);
        sum[hld.idx(u) + 1] += w;
    }
    rep(i, 0, n) {
        sum[i + 1] += sum[i];
    }
    auto path_sum = [&](int u, int v) -> ll {
        ll ret = 0;
        auto f = [&](int l, int r) -> void {
            if (l > r) std::swap(l, r);
            ret += sum[r] - sum[l];
        };
        hld.path_noncommutative_query(u, v, false, f);
        return ret;
    };
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        std::vector<int> vs(k);
        for (auto &v : vs) std::cin >> v;
        ll ans = 0;
        auto auxiliary_tree = hld.lca_based_auxiliary_tree(vs);
        for (auto [v, par] : auxiliary_tree) {
            if (par != -1) {
                ans += path_sum(v, par);
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}