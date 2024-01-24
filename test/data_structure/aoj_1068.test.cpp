#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include "../../data_structure/segtree.hpp"
#include "../../data_structure/segtree_2d.hpp"
#include "../../template/template.hpp"

int op(int a, int b) {
    return a < b ? a : b;
}

int e() {
    return std::numeric_limits<int>::max();
}

int main() {
    int r, c, q;
    while (std::cin >> r >> c >> q, !(r == 0 && c == 0 && q == 0)) {
        segtree_2d<int, op, e, segtree<int, op, e>> seg2d(r, c);
        rep(i, 0, r) {
            rep(j, 0, c) {
                int grid;
                std::cin >> grid;
                seg2d.set(i, j, grid);
            }
        }
        while (q--) {
            int l, d, r, u;
            std::cin >> l >> d >> r >> u;
            r++;
            u++;
            std::cout << seg2d.prod(l, d, r, u) << '\n';
        }
    }
}