#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../../template/template.hpp"
#include "../../tree/RerootingDP.hpp"
#include "../../utility/modint.hpp"

using namespace lib;
using mint = modint998244353;
using pmm = pair<mint, mint>;

pmm merge(pmm a, pmm b) {
    return pmm(a.first + b.first, a.second + b.second);
}
pmm e() {
    return pmm(0, 0);
}

vector<mint> a, b, c;
pmm pute(pmm x, int e) {
    return pmm(b[e] * x.first + c[e] * x.second, x.second);
}
pmm putv(pmm x, int v) {
    return pmm(x.first + a[v], x.second + 1);
}

int main() {
    int n;
    cin >> n;
    a.resize(n), b.resize(n - 1), c.resize(n - 1);
    rep(i, 0, n) {
        ll x;
        cin >> x;
        a[i] = x;
    }
    RerootingDP<pmm, pmm, merge, e, pute, putv> g(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v, i, i);
        ll y, z;
        cin >> y >> z;
        b[i] = y, c[i] = z;
    }
    g.build();
    auto ans = g.reroot();
    rep(i, 0, n) cout << ans[i].first.val() << " \n"[i == n - 1];
}