#pragma once

#include "../template/template.hpp"

namespace lib {

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazysegtree {
  private:
    int n, lg2, sz;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int i) {
        d[i] = op(d[2 * i], d[2 * i + 1]);
    }

    void all_apply(int i, F f) {
        d[i] = mapping(f, d[i]);
        if (i < sz) lz[i] = composition(f, lz[i]);
    }

    void push(int i) {
        all_apply(2 * i, lz[i]);
        all_apply(2 * i + 1, lz[i]);
        lz[i] = id();
    }

  public:
    lazysegtree(int _n) : lazysegtree(std::vector<S>(_n, e())) {}

    lazysegtree(const std::vector<S> &v) : n(v.size()) {
        lg2 = 0;
        while ((1 << lg2) < n) lg2++;
        sz = 1 << lg2;
        d = std::vector<S>(2 * sz, e());
        lz = std::vector<F>(2 * sz, id());
        for (int i = 0; i < n; i++) d[sz + i] = v[i];
        for (int i = sz - 1; i >= 1; i--) update(i);
    }

    void set(int p, S x) {
        assert(0 <= p && p < n);
        p += sz;
        rrep(i, 1, lg2 + 1) push(p >> i);
        d[p] = x;
        rep(i, 1, lg2 + 1) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < n);
        p += sz;
        rrep(i, 1, lg2 + 1) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return e();
        l += sz;
        r += sz;
        rrep(i, 1, lg2 + 1) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() {
        return d[1];
    }

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += sz;
        rrep(i, 1, lg2 + 1) push(p >> i);
        d[p] = mapping(f, d[p]);
        rep(i, 1, lg2 + 1) update(p >> i);
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;
        l += sz;
        r += sz;
        rrep(i, 1, lg2 + 1) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        rep(i, 1, lg2 + 1) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= n);
        assert(g(e()));
        if (l == n) return n;
        l += sz;
        for (int i = lg2; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < sz) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= n);
        assert(g(e()));
        if (r == 0) return 0;
        r += sz;
        for (int i = lg2; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < sz) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

}  // namespace lib