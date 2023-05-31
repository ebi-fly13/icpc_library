#pragma once

#include "../template/template.hpp"

namespace lib {

template <class T> struct fenwick_tree {
  private:
    int n;
    std::vector<T> data;

  public:
    fenwick_tree(int n) : n(n), data(n + 1) {}

    void add(int p, T x) {
        assert(0 <= p && p < n);
        p++;
        for (int i = p; i <= n; i += i & -i) {
            data[i] += x;
        }
    }

    T prefix_sum(int p) const {
        assert(0 <= p && p <= n);
        T ret = 0;
        for (int i = p; i > 0; i -= i & -i) {
            ret += data[i];
        }
        return ret;
    }

    T sum(int l, int r) const {
        return prefix_sum(r) - prefix_sum(l);
    }
};

}  // namespace lib