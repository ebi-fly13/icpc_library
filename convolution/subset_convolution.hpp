#pragma once

#include "../template/template.hpp"
#include "../math/ranked_subset_transform.hpp"

namespace lib {

template <class T, int LIM = 20>
std::vector<T> subset_convolution(const std::vector<T> &a,
                                  const std::vector<T> &b) {
    auto ra = ranked_zeta<T, LIM>(a);
    auto rb = ranked_zeta<T, LIM>(b);
    int n = std::bit_width(a.size()) - 1;
    for (int s = (1 << n) - 1; s >= 0; s--) {
        auto &f = ra[s];
        const auto &g = rb[s];
        for (int d = n; d >= 0; d--) {
            T x = 0;
            for (int i = 0; i <= d; i++) {
                x += f[i] * g[d - i];
            }
            f[d] = x;
        }
    }
    return ranked_mobius<T, LIM>(ra);
}

}  // namespace ebi