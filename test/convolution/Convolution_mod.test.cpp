#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../convolution/ntt.hpp"
#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using mint = modint998244353;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> a(n), b(m);
    rep(i, 0, n) {
        int x;
        std::cin >> x;
        a[i] = x;
    }
    rep(i, 0, m) {
        int x;
        std::cin >> x;
        b[i] = x;
    }
    auto c = convolution(a, b);
    rep(i, 0, c.size()) {
        std::cout << c[i].val() << " \n"[i == int(c.size()) - 1];
    }
}