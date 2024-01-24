#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using mint = modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    int n;
    std::cin >> n;
    FPS a(n);
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    auto b = a.exp();
    for (int i = 0; i < n; ++i) {
        std::cout << b[i].val() << " ";
    }
    std::cout << std::endl;
}