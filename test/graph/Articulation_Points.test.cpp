#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "../../graph/low_link.hpp"
#include "../../template/template.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<int>());
    rep(i, 0, m) {
        int s, t;
        std::cin >> s >> t;
        g[s].emplace_back(t);
        g[t].emplace_back(s);
    }
    low_link lwlk(g);
    auto articulation = lwlk.articulation();
    std::sort(all(articulation));
    for (auto v : articulation) {
        std::cout << v << '\n';
    }
}