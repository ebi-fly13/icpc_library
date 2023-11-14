#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../../fps/polynomial_interpolation.hpp"

#include "../../template/template.hpp"
#include "../../utility/modint.hpp"

namespace lib {

using mint = modint998244353;

void main_() {
    int n;
    std::cin >> n;
    std::vector<mint> x(n), y(n);
    rep(i,0,n) {
        std::cin >> x[i].val();
    }
    rep(i,0,n) {
        std::cin >> y[i].val();
    }
    auto f = polynomial_interpolation<mint>(x, y);
    rep(i, 0, n) {
        std::cout << f[i].val() << " \n"[i == n - 1];
    }
}

}  // namespace ebi

int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        lib::main_();
    }
    return 0;
}