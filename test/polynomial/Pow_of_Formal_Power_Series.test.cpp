#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using namespace lib;
using mint = modint998244353;

int main() {
    int n;
    ll m;
    std::cin >> n >> m;
    FPS<mint> a(n);
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    auto b = a.pow(m);
    for (int i = 0; i < n; ++i) {
        std::cout << b[i].val() << " ";
    }
    std::cout << std::endl;
}