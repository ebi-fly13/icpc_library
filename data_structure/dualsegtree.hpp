#pragma once

#include <cassert>
#include <vector>

namespace lib {

template <class S, S (*op)(S, S), S (*e)()>
struct dualsegtree {
  public:
    dualsegtree(int n) : n(n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, e());
    }

    dualsegtree(const std::vector<S> &vec) : n(vec.size()) {
        sz = 1;
        while (sz < n) sz <<= 1;
        data.assign(2 * sz, e());
        std::copy(vec.begin(), vec.end(), data.begin() + sz);
    }

    S get(int p) const {
        assert(0 <= p && p < n);
        p += sz;
        S val = e();
        while (p > 0) {
            val = op(val, data[p]);
            p >>= 1;
        }
        return val;
    }

    void apply(int l, int r, S x) {
        assert(0 <= l && l <= r && r <= n);
        l += sz;
        r += sz;
        while (l < r) {
            if (l & 1) {
                data[l] = op(data[l], x);
                l++;
            }
            if (r & 1) {
                r--;
                data[r] = op(data[r], x);
            }
            l >>= 1;
            r >>= 1;
        }
        return;
    }

  private:
    std::vector<S> data;
    int n;
    int sz;
};

}  // namespace ebi