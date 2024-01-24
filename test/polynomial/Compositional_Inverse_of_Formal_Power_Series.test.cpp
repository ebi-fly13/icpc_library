#define PROBLEM                        \
    "https://judge.yosupo.jp/problem/" \
    "compositional_inverse_of_formal_power_series"

#include <iostream>

#include "../../convolution/ntt.hpp"
#include "../../fps/compositional_inverse_of_fps.hpp"
#include "../../utility/modint.hpp"

using mint = modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    int n;
    std::cin >> n;
    FPS f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f[i].val();
    }
    FPS g = compositional_inverse_of_fps(f);
    for (int i = 0; i < n; i++) {
        std::cout << g[i].val() << " \n"[i == n - 1];
    }
}