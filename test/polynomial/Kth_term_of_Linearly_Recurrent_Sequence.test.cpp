#define PROBLEM \
    "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../../convolution/ntt.hpp"
#include "../../fps/bostan_mori.hpp"
#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

using mint = modint998244353;

int main() {
    int d;
    long long k;
    std::cin >> d >> k;
    std::vector<mint> a(d), c(d);
    for (int i = 0; i < d; i++) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    for (int i = 0; i < d; i++) {
        int val;
        std::cin >> val;
        c[i] = val;
    }
    std::cout << kitamasa<mint, convolution>(k, a, c).val() << '\n';
}