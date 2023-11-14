#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../../math/dirichlet_series.hpp"
#include "../../utility/modint.hpp"
#include "../../template/template.hpp"

namespace lib {

using mint = modint998244353;

void main_() {
    ll n;
    std::cin >> n;
    using DirichletSeries = DirichletSeries<mint, 0>;
    DirichletSeries::set_size(n);
    mint ans = (DirichletSeries::zeta1() / DirichletSeries::zeta()).get_sum();
    std::cout << ans.val() << '\n';
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