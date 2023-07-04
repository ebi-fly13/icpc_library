#pragma once

#include "../math/ext_gcd.hpp"
#include "../template/template.hpp"

namespace lib {

std::pair<ll, ll> crt(const std::vector<ll> &b, const std::vector<ll> &m) {
    ll r = 0, mod = 1;
    rep(i, 0, int(b.size())) {
        assert(m[i] > 0);
        auto [p, q, d] = extgcd(mod, m[i]);
        if ((b[i] - r) % d != 0) return {0, -1};
        ll ret = (b[i] - r) / d * p % (m[i] / d);
        r += ret * mod;
        mod *= m[i] / d;
        if (r < 0) r += mod;
    }
    return {(r % mod + mod) % mod, mod};
}

}  // namespace lib