#pragma once

#include "../template/template.hpp"
#include "../utility/modint.hpp"

using mint = modint998244353;

struct ntt_info {
    static constexpr int rank2 = 23;
    const int g = 3;
    std::array<std::array<mint, rank2 + 1>, 2> root;

    ntt_info() {
        root[0][rank2] = mint(g).pow((mint::mod() - 1) >> rank2);
        root[1][rank2] = root[0][rank2].inv();
        rrep(i, 0, rank2) {
            root[0][i] = root[0][i + 1] * root[0][i + 1];
            root[1][i] = root[1][i + 1] * root[1][i + 1];
        }
    }
};

void butterfly(std::vector<mint>& a, bool inverse) {
    static ntt_info info;
    int n = a.size();
    int bit_size = 0;
    while ((1 << bit_size) < n) bit_size++;
    assert(1 << bit_size == n);
    for (int i = 0, j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) {
            std::swap(a[i], a[j]);
        }
    }
    rep(bit, 0, bit_size) {
        rep(i, 0, n / (1 << (bit + 1))) {
            mint zeta1 = 1;
            mint zeta2 = info.root[inverse][1];
            mint w = info.root[inverse][bit + 1];
            rep(j, 0, 1 << bit) {
                int idx = i * (1 << (bit + 1)) + j;
                int jdx = idx + (1 << bit);
                mint p1 = a[idx];
                mint p2 = a[jdx];
                a[idx] = p1 + zeta1 * p2;
                a[jdx] = p1 + zeta2 * p2;
                zeta1 *= w;
                zeta2 *= w;
            }
        }
    }
    if (inverse) {
        mint inv_n = mint(n).inv();
        rep(i, 0, n) a[i] *= inv_n;
    }
}

std::vector<mint> convolution(const std::vector<mint>& f,
                              const std::vector<mint>& g) {
    int n = 1;
    while (n < int(f.size() + g.size() - 1)) n <<= 1;
    std::vector<mint> a(n), b(n);
    std::copy(f.begin(), f.end(), a.begin());
    std::copy(g.begin(), g.end(), b.begin());
    butterfly(a, false);
    butterfly(b, false);
    rep(i, 0, n) {
        a[i] *= b[i];
    }
    butterfly(a, true);
    a.resize(f.size() + g.size() - 1);
    return a;
}

