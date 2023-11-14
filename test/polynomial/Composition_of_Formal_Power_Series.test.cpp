#define PROBLEM \
    "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

#include <iostream>

#include "../../convolution/ntt.hpp"
#include "../../fps/composition_of_fps.hpp"
#include "../../utility/modint.hpp"

using namespace lib;
using mint = modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    int n;
    std::cin >> n;
    FPS f(n), g(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f[i].val();
    }
    for (int i = 0; i < n; i++) {
        std::cin >> g[i].val();
    }
    FPS h = composition_of_fps(f, g);
    for (int i = 0; i < n; i++) {
        std::cout << h[i].val() << " \n"[i == n - 1];
    }
}