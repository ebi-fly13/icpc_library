#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../../graph/fordfulkerson.hpp"
#include "../../graph/mf_graph.hpp"
#include "../../template/template.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    FordFulkerson<int> g1(n);
    mf_graph<int> g2(n);
    rep(i, 0, m) {
        int u, v, c;
        std::cin >> u >> v >> c;
        g1.add_edge(u, v, c);
        g2.add_edge(u, v, c);
    }
    int flow = g1.flow(0, n - 1);
    assert(flow == g2.flow(0, n - 1));
    std::cout << flow << '\n';
}