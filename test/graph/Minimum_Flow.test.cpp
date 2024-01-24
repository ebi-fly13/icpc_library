#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "../../graph/mcf_graph.hpp"
#include "../../template/template.hpp"

int main() {
    int v, e, f;
    std::cin >> v >> e >> f;
    MinCostFlow mcf(v);
    for (int i = 0; i < e; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        mcf.add_edge(a, b, c, d);
    }
    ll ans = mcf.flow(0, v - 1, f);
    std::cout << ans << std::endl;
}