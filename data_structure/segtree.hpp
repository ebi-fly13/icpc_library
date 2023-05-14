#pragma once

#include "../template/template.hpp"

namespace lib {

using namespace std;

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  private:
    int n;
    int sz;
    vector<S> data;

    void update(int i) {
        data[i] = op(data[2 * i], data[2 * i + 1]);
    }

  public:
    segtree(int n) : segtree(vector<S>(n, e())) {}
    segtree(const vector<S> &v) : n((int)v.size()), sz(1) {
        while (sz < n) sz *= 2;
        data = vector<S>(2 * sz, e());
        rep(i, 0, n) {
            data[sz + i] = v[i];
        }
        rrep(i, 1, sz) update(i);
    }

    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += sz;
        data[p] = x;
        while (p > 1) {
            p >>= 1;
            update(p);
        }
    }

    S get(int p) {
        assert(0 <= p && p < n);
        return data[p + sz];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        S sml = e(), smr = e();
        l += sz;
        r += sz;
        while (l < r) {
            if (l & 1) sml = op(sml, data[l++]);
            if (r & 1) smr = op(data[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() {
        return data[1];
    }

    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l < n);
        assert(f(e()));
        if (l == n) return n;
        l += sz;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, data[l]))) {
                while (l < sz) {
                    l = 2 * l;
                    if (f(op(sm, data[l]))) {
                        sm = op(sm, data[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            sm = op(sm, data[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= n);
        assert(f(e()));
        if (r == 0) return 0;
        r += sz;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(data[r], sm))) {
                while (r < sz) {
                    r = 2 * r + 1;
                    if (f(op(data[r], sm))) {
                        sm = op(data[r], sm);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            sm = op(data[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

}  // namespace lib