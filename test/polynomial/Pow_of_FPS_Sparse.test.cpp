#define PROBLEM \
    "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"

#include "../../template/template.hpp"
#include "../../fps/fps_sparse.hpp"
#include "../../utility/modint.hpp"

using namespace lib;
using mint = modint998244353;

int main() {
    int n, k;
    ll m;
    std::cin >> n >> k >> m;
    std::vector<mint> f(n);
    for (int i = 0; i < k; i++) {
        int idx, a;
        std::cin >> idx >> a;
        f[idx] = a;
    }
    auto g = pow_sparse(f, m, n);
    for (int i = 0; i < n; i++) {
        std::cout << g[i].val() << " \n"[i == n - 1];
    }
}