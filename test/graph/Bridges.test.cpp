#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../graph/low_link.hpp"
#include "../../template/template.hpp"

using namespace lib;

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
    auto bridge = lwlk.bridge();
    std::sort(all(bridge));
    for (auto [u, v] : bridge) {
        std::cout << u << " " << v << '\n';
    }
}