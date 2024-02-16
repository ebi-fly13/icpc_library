#pragma once

#include "../fps/fps.hpp"
#include "../math/factorial.hpp"
#include "../template/template.hpp"

namespace lib {

template <class mint>
FormalPowerSeries<mint> taylor_shift(FormalPowerSeries<mint> f, mint a) {
    int d = f.deg();
    Binom<mint> binom(d);
    for (int i = 0; i < d; i++) f[i] *= binom.fact(i);
    std::reverse(f.begin(), f.end());
    FormalPowerSeries<mint> g(d, 1);
    mint pow_a = a;
    for (int i = 1; i < d; i++) {
        g[i] = pow_a * binom.ifact(i);
        pow_a *= a;
    }
    f = (f * g).pre(d);
    std::reverse(f.begin(), f.end());
    for (int i = 0; i < d; i++) f[i] *= binom.ifact(i);
    return f;
}

}  // namespace lib