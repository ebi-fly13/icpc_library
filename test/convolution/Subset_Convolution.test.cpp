#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../../convolution/subset_convolution.hpp"

#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using namespace lib;
using mint = modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<mint> a(1 << n), b(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        std::cin >> a[i].val();
    }
    for (int i = 0; i < (1 << n); i++) {
        std::cin >> b[i].val();
    }
    auto c = subset_convolution<mint, 20>(a, b);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i].val() << ((i == (1 << n) - 1) ? "\n" : " ");
    }
}