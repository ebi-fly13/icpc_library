#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../template/template.hpp"
#include "../../tree/LowestCommonAncestor.hpp"

int main() {
    int n,q;
    std::cin >> n >> q;
    std::vector g(n, std::vector<int>());
    rep(i,1,n) {
        int p;
        std::cin >> p;
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    lib::LowestCommonAncestor lca(g, 0);
    while(q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca.lca(u, v) << '\n';
    }
}