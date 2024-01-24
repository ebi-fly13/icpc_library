#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0489"

#include "../../data_structure/segtree.hpp"
#include "../../tree/LowestCommonAncestor.hpp"
#include "../../tree/Mo_on_Tree.hpp"

using P = pair<int, int>;
const int geta = 1'000'000;
const int mx = geta * 2 + 10;

int op(int a, int b) {
    return a + b;
}
int e() {
    return 0;
}

using ar = array<int, 3>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ar> querys;
    vector<P> es(n - 1);
    rep(i, 0, n - 1) cin >> es[i].first >> es[i].second;
    {
        int pre = n + 1;
        while (m--) {
            int t;
            cin >> t;
            if (t == 1) {
                int u, w;
                cin >> u >> w;
                es.emplace_back(u, pre++);
                a.emplace_back(w);
            }
            if (t == 2) {
                int u, v, k;
                cin >> u >> v >> k;
                u--, v--;
                k--;
                querys.push_back({u, v, k});
            }
        }
        n = es.size() + 1;
        m = querys.size();
    }
    MoTree_vertex<int> mo(n, a);
    for (auto &[u, v] : es) {
        u--, v--;
        mo.add_edge(u, v);
    }
    LowestCommonAncestor g(mo.es);
    mo.build(querys.size());
    for (auto [u, v, k] : querys) {
        mo.insert(u, v, g.lca(u, v));
    }
    segtree<int, op, e> seg(mx);
    vector<int> ans(querys.size());
    auto get = [&](int k) {
        auto f = [&](int cnt) { return cnt <= k; };
        return seg.max_right(0, f) - geta;
    };
    auto add = [&](int v) {
        v += geta;
        seg.set(v, seg.get(v) + 1);
    };
    auto del = [&](int v) {
        v += geta;
        seg.set(v, seg.get(v) - 1);
    };
    auto ask = [&](int i) { ans[i] = get(querys[i][2]); };
    mo.run(add, del, ask);
    for (auto z : ans) cout << z << '\n';
}