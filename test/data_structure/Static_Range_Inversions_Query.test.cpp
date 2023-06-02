#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../data_structure/fenwick_tree.hpp"
#include "../../misc/mo_algorithm.hpp"
#include "../../template/template.hpp"

using namespace lib;

int main() {
    int n, q;
    std::cin >> n >> q;
    Mo mo(n, q);
    std::vector<int> a(n);
    rep(i, 0, n) std::cin >> a[i];
    auto cp = a;
    std::sort(all(cp));
    cp.erase(unique(all(cp)), cp.end());
    rep(i, 0, n) a[i] = std::lower_bound(all(cp), a[i]) - cp.begin();
    rep(i, 0, q) {
        int l, r;
        std::cin >> l >> r;
        mo.insert(l, r);
    }
    ll ret = 0;
    fenwick_tree<ll> fw(cp.size());
    std::vector<ll> ans(q);
    const auto add_left = [&](int l) -> void {
        ret += fw.prefix_sum(a[l]);
        fw.add(a[l], 1);
    };
    const auto add_right = [&](int r) -> void {
        ret += fw.sum(a[r] + 1, cp.size());
        fw.add(a[r], 1);
    };
    const auto delete_left = [&](int l) -> void {
        ret -= fw.prefix_sum(a[l]);
        fw.add(a[l], -1);
    };
    const auto delete_right = [&](int r) -> void {
        ret -= fw.sum(a[r] + 1, cp.size());
        fw.add(a[r], -1);
    };
    const auto out = [&](int i) -> void { ans[i] = ret; };
    mo.run(add_left, add_right, delete_left, delete_right, out);
    rep(i, 0, q) {
        std::cout << ans[i] << '\n';
    }
}