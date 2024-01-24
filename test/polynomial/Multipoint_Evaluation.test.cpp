#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../fps/multipoint_evaluation.hpp"

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using mint = modint998244353;
using FPS = FormalPowerSeries<mint>;

void main_() {
    int n, m;
    std::cin >> n >> m;
    FPS f(n);
    rep(i, 0, n) std::cin >> f[i].val();
    std::vector<mint> p(m);
    rep(i, 0, m) std::cin >> p[i].val();
    auto fp = multipoint_evaluation<mint>(f, p);
    rep(i, 0, m) {
        std::cout << fp[i].val() << " \n"[i == m - 1];
    }
}

int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        main_();
    }
    return 0;
}