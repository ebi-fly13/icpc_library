#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../../math/floor_sum.hpp"
#include "../../template/template.hpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << floor_sum(n, m, a, b) << '\n';
    }
}