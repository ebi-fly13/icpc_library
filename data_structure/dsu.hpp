#pragma once

#include "../template/template.hpp"

namespace lib {

struct dsu {
  public:
    dsu(int n = 0) : _n(n), pos(n, -1) {}

    int merge(int a, int b) {
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-pos[x] < -pos[y]) swap(x, y);
        pos[x] += pos[y];
        pos[y] = x;
        return x;
    }

    bool same(int a, int b) { return leader(a) == leader(b); }

    int leader(int a) {
        if (pos[a] < 0) return a;
        return pos[a] = leader(pos[a]);
    }

    int size(int a) { return -pos[leader(a)]; }

  private:
    int _n;
    vector<int> pos;
};

}  // namespace lib
