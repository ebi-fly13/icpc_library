#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../data_structure/sparse_table.hpp"
#include "../../template/template.hpp"

using namespace lib;

int op(int a, int b) {
    return min(a, b);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    SparseTable<int, op> spt(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << spt.get(l, r) << '\n';
    }
}