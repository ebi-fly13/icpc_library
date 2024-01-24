#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../data_structure/dsu.hpp"
#include "../../template/template.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    dsu uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        } else {
            std::cout << (int)uf.same(u, v) << '\n';
        }
    }
}