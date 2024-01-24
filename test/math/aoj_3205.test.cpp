#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3205&lang=jp"

#include "../../math/two_sat.hpp"
#include "../../template/template.hpp"

int main() {
    int n, m;
    while (std::cin >> n >> m, !(n == 0 && m == 0)) {
        std::vector<std::pair<int, int>> ab(m);
        for (auto &[a, b] : ab) {
            std::cin >> a >> b;
        }
        int ans = -1;
        int r = 1;
        rep(i, 0, m) {
            chmax(r, i + 1);
            while (r < m) {
                two_sat tsat(n);
                rep(j, i, r + 1) {
                    auto [a, b] = ab[j];
                    tsat.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1,
                                    b > 0);
                }
                if (tsat.satisfiable())
                    r++;
                else
                    break;
            }
            chmax(ans, r - i);
        }
        std::cout << ans << '\n';
    }
}