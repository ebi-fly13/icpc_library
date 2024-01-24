#define PROBLEM "https://yukicoder.me/problems/447"

#include "../../math/crt.hpp"
#include "../../template/template.hpp"

int main() {
    std::vector<ll> x(3), y(3);
    rep(i, 0, 3) {
        std::cin >> x[i] >> y[i];
    }
    auto [r, m] = crt(x, y);
    if (m < 0) {
        std::cout << -1 << '\n';
    } else {
        if (r == 0) r += m;
        std::cout << r << '\n';
    }
}