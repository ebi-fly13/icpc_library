#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../convolution/ntt4.hpp"
#include "../../template/template.hpp"

using mint = modint998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[i] = x;
    }
    rep(j, 0, m) {
        int y;
        cin >> y;
        b[j] = y;
    }
    NTT<mint> ntt;
    auto ab = ntt.multiply(a, b);
    rep(i, 0, ab.size()) {
        cout << ab[i].val() << " \n"[i + 1 == (int)(ab.size())];
    }
}