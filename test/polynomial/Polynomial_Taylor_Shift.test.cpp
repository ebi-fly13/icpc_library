#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../../template/template.hpp"
#include "../../fps/fps.hpp"
#include "../../fps/taylor_shift.hpp"
#include "../../utility/modint.hpp"

using namespace lib;
using mint = modint998244353;

int main() {
    int n, c;
    std::cin >> n >> c;
    FormalPowerSeries<mint> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].val();
    }
    auto b = taylor_shift<mint>(a, c);
    for (int i = 0; i < n; i++) {
        std::cout << b[i].val() << " \n"[i == n - 1];
    }
}